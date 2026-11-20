#!/usr/bin/env python3
"""rules.py: the code-rule checker (docs/code-rules.md, profile in AGENTS.md).

A function written in C rebuilds retail's bytes (`make` proves the whole ELF), but it only counts
as matched when it also passes every [match] rule: R1 (one declaration per type), R2 (one
declaration per global), R4 (no offset casts), R13 (real vtables), R17 (no fake code) and R18 (no
assembly bodies). Byte-identical but failing is MATCH-PENDING. This script computes that from the
tree alone (no build, no ELF, stock Python 3.8+), like tools/bk/progress_report.py:

    python3 -I tools/bk/rules.py                      summary: both progress numbers, counts per rule
    python3 -I tools/bk/rules.py -v [UNIT...]         one line per finding (file:line: rule [tier] function: text)
    python3 -I tools/bk/rules.py --rule R17 -v        only that rule's findings
    python3 -I tools/bk/rules.py --pending [UNIT...]  the MATCH-PENDING functions with the rules they break
    python3 -I tools/bk/rules.py --json build/rules/report.json   everything, for other tools
    python3 -I tools/bk/rules.py --md                 the summary as Markdown (CI step summary)
    python3 -I tools/bk/rules.py --selftest           each row against built-in cases (fakes that must
                                                      fire, era idioms that must not)

What each row tests is listed in docs/code-rules.md ("What the checker tests"); the rows are narrow on
purpose, so a finding is a fact about the text, not an opinion. Findings in a declaration (a type,
a global, a macro, an inline helper) count against every function that names it, through helpers
and base classes. Limits, also listed there: the checker reads tokens, not types, so it does not
follow `p->q->r` into a type the function never names.
"""
import argparse
import copy
import json
import os
import re
import sys

R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
TEXT_END = 0x29F230            # .text ends where .ctors starts (tools/bk/progress_report.py)
ORIGINAL_ASM_UNITS = {'crt0'}  # handwritten assembly in retail: listed apart, counted neither way (R18)

MATCH_RULES = ('R1', 'R2', 'R4', 'R13', 'R17', 'R18')

# --- project profile (AGENTS.md "Rule changes" explains each) ---------------------------------

# R17, volatile: a cast to a volatile pointer is genuine on a literal EE hardware address
# (0x10000000-0x1FFFFFFF: timers, IPU, GIF, VIF, DMAC, INTC, SIO, GS privileged; kseg1 mirrors).
HW_RANGES = ((0x10000000, 0x20000000), (0xA0000000, 0xC0000000))

# R18, original helpers: an asm statement made only of instructions the compiler cannot emit from
# C is an original helper by necessity (COP0, COP2/VU0 macro mode, the EE's 128-bit multimedia
# set, sync). Functions using one are listed, but counted.
HW_MNEMONICS = set('''
mfc0 mtc0 sync sync.p sync.l ei di eret syscall break cache tlbwi tlbwr tlbr tlbp
qmfc2 qmtc2 cfc2 ctc2 lqc2 sqc2 qmfc2.i qmfc2.ni qmtc2.i qmtc2.ni cfc2.i cfc2.ni ctc2.i ctc2.ni
bc2f bc2t bc2fl bc2tl mfsa mtsa mtsab mtsah mfhi1 mflo1 mthi1 mtlo1 lq sq pref
'''.split())
HW_MNEMONIC_RE = re.compile(r'''^(?:
    v[a-z][a-z0-9.]*                      # VU0 macro instructions: vadd.xyz, vcallms, vwaitq, vnop
  | p(?:add|sub|ext|cpy|mf|mt|and|or|xor|nor|sll|srl|sra|max|min|abs|ceq|cgt|pac|int|exe|exc|rev|rot|mul|mad|msu|div|hma|hms|lzc)[a-z0-9]*
  )$''', re.X)
# register glue allowed beside a hardware instruction, never alone: moves, immediates, bit operations
HW_GLUE = set('mfc1 mtc1 nop move li dli la lui ori andi and or addiu daddu addu'.split())
# one or two instructions on a register C has no name for ($gp, $sp, $ra): thread and callback glue
FIXED_REG_RE = re.compile(r'\$(?:28|29|31|gp|sp|ra)\b')

# R17, padding members. The SDK and the file formats name none here.
PAD_RE = re.compile(r'^_*(?:pad|padding|dummy|filler)_?[0-9A-Fa-f]*$', re.I)

# R7, placeholders (advisory): the project's own patterns plus the catalogue's address-like test.
PLACEHOLDER_RES = [re.compile(p) for p in (
    r'^func_[0-9A-Fa-f]{8}$', r'^(?:D|jtbl)_[0-9A-Fa-f]{6,8}\w*$', r'^[A-Z][a-z]\w*?[0-9A-F]{5,6}\w*$',
    r'^(?:FUN|DAT|sub|unk|local|param|field)_', r'^m_?[Uu]nk\w*$', r'^m_?[0-9A-F]{1,4}$',
    r'^(?:temp|tmp|ptr|result|var|v|iVar|uVar|uStack)\d+$',
)]
ADDRESS_LIKE = re.compile(r'\b[A-Za-z_]*?_?(?=[0-9a-fA-F]*[0-9])[0-9a-fA-F]{6,8}\b')

# R21, campaign notes in comments (advisory): lanes, scores, dates.
NOTE_RE = re.compile(r'\(lane \w+\)|\blane [a-z]\d\b|\bDIFF \d+|\b20\d\d-\d\d-\d\d\b|\(\w\d[,)]| vs \d+ insns')

# ---------------------------------------------------------------------------------------------

TOKEN = re.compile(r'''
  (?P<ws>[ \t\r\f\v]+|\\\r?\n)
 |(?P<nl>\n)
 |(?P<lc>//[^\n]*)
 |(?P<bc>/\*.*?\*/)
 |(?P<str>"(?:\\.|[^"\\\n])*")
 |(?P<chr>'(?:\\.|[^'\\\n])+')
 |(?P<num>\.?\d(?:[eEpP][+-]|[\w.])*)
 |(?P<id>[A-Za-z_$][\w$]*)
 |(?P<p>->\*|\.\.\.|<<=|>>=|::|->|\+\+|--|<<|>>|<=|>=|==|!=|&&|\|\||[-+*/%&|^]=|[{}()\[\];,.<>+\-*/%&|^!~?:=\#])
 |(?P<other>.)
''', re.S | re.X)

ASM_KW = {'asm', '__asm__', '__asm'}
TYPE_KW = {'class', 'struct', 'union', 'enum'}
SPEC_KW = {'typedef', 'static', 'extern', 'const', 'volatile', 'inline', '__inline__', '__inline',
           'register', 'unsigned', 'signed', 'virtual', 'friend', 'explicit', 'mutable'}
STMT_KW = {'return', 'goto', 'case', 'default', 'delete', 'new', 'else', 'do', 'typedef', 'sizeof',
           'throw', 'break', 'continue', 'if', 'for', 'while', 'switch', 'using', 'operator',
           'public', 'private', 'protected', 'this', 'template'} | ASM_KW
BYTE_T = r'(?:(?:unsigned|signed) )?(?:char|u8|s8|BYTE|byte|uint8_t|int8_t)'
INT_T = r'(?:(?:unsigned|signed) )?(?:char|short|int|long|u8|s8|u16|s16|u32|s32|u64|s64|uintptr_t|size_t)'
NUM = r'(?:0[xX][0-9A-Fa-f]+|\d+)[uUlL]*'

# R4 rows, on a function's tokens joined by single spaces.
R4_DEREF = re.compile(
    r'(?:\* \( [\w ]+ \*+ \)|\( \( [\w ]+ \*+ \)) \( \( ' + BYTE_T + r' \*+ \) (?:\( [^()]* \)|[\w.>:\-\[\] ]+?) [+-] ' + NUM + r' \)')
R4_THIS = re.compile(r'\( (?:' + BYTE_T + r' \*+|' + INT_T + r') \) this (?:\) )?[+-] ')
R4_MACRO = re.compile(
    r'\* \( [\w ]+ \*+ \) \( \( ' + BYTE_T + r' \*+ \) (?:\( [^()]* \)|[\w.>:\-\[\] ]+?) [+-] ')
R4_PLAIN = re.compile(r'\* \( [\w ]+ \*+ \) \( \w+ [+-] ' + NUM + r' \)')


class Tok(object):
    __slots__ = ('kind', 'text', 'line')

    def __init__(self, kind, text, line):
        self.kind, self.text, self.line = kind, text, line

    def __repr__(self):
        return self.text


def read(path):
    with open(os.path.join(R, path), encoding='utf-8', errors='replace') as f:
        return f.read()


class Source(object):
    """One file, lexed: tokens (preprocessor lines taken out), comments, macros, includes, #if 0 blocks."""

    def __init__(self, rel, text=None):
        self.rel = rel
        self.is_header = rel.endswith('.h')
        self.toks, self.comments, self.macros, self.includes, self.ifzero = [], [], {}, [], []
        self._lex(read(rel) if text is None else text)

    def _lex(self, text):
        pos, line, bol, n = 0, 1, True, len(text)
        while pos < n:
            m = TOKEN.match(text, pos)
            kind, s = m.lastgroup, m.group()
            if kind == 'p' and s == '#' and bol:
                end = pos
                while True:                                  # the logical line, continuations included
                    end = text.find('\n', end)
                    if end < 0:
                        end = n
                        break
                    if text[max(pos, end - 2):end].rstrip('\r').endswith('\\'):
                        end += 1
                        continue
                    break
                pos, line = self._directive(text, pos, end, line)
                continue
            if kind == 'nl':
                line += 1
                bol = True
            elif kind in ('lc', 'bc'):
                self.comments.append((line, line + s.count('\n'), s))
                line += s.count('\n')
            elif kind == 'ws':
                line += s.count('\n')
            else:
                self.toks.append(Tok(kind, s, line))
                bol = False
            pos = m.end()

    def _directive(self, text, pos, end, line):
        body = text[pos:end]
        toks, sub_line = [], line
        for m in TOKEN.finditer(body):
            kind, s = m.lastgroup, m.group()
            if kind in ('lc', 'bc'):
                self.comments.append((sub_line, sub_line + s.count('\n'), s))
            elif kind not in ('ws', 'nl'):
                toks.append(Tok(kind, s, sub_line))
            sub_line += s.count('\n')
        nlines = body.count('\n')
        name = toks[1].text if len(toks) > 1 else ''
        if name == 'define' and len(toks) > 2:
            params, k = None, 3
            # function-like only when '(' touches the name
            at = body.find(toks[2].text, body.find('define') + 6) + len(toks[2].text)
            if at < len(body) and body[at] == '(':
                params = []
                while k < len(toks) and toks[k].text != ')':
                    if toks[k].kind == 'id' or toks[k].text == '...':
                        params.append(toks[k].text)
                    k += 1
                k += 1
            self.macros[toks[2].text] = (line, params, toks[k:])
        elif name == 'include' and len(toks) > 2 and toks[2].kind == 'str':
            self.includes.append(toks[2].text.strip('"'))
        elif name == 'if' and [t.text for t in toks[2:]] == ['0']:
            # skip to the matching #else/#elif/#endif; nothing in between is source (R37)
            depth, p, cur = 0, end, line + nlines
            while p < len(text):
                nl = text.find('\n', p + 1)
                nl = len(text) if nl < 0 else nl
                ln = text[p + 1:nl].strip()
                cur += 1
                if ln.startswith('#'):
                    d = ln[1:].strip()
                    if re.match(r'(if|ifdef|ifndef)\b', d):
                        depth += 1
                    elif re.match(r'endif\b', d):
                        if depth == 0:
                            self.ifzero.append((line, cur))
                            return nl, cur
                        depth -= 1
                    elif re.match(r'(else|elif)\b', d) and depth == 0:
                        self.ifzero.append((line, cur))
                        return nl, cur
                p = nl
            self.ifzero.append((line, cur))
            return len(text), cur
        return end, line + nlines


def match(toks, i, open_='{', close='}'):
    depth = 0
    for j in range(i, len(toks)):
        t = toks[j].text
        if t == open_:
            depth += 1
        elif t == close:
            depth -= 1
            if depth == 0:
                return j
    return len(toks) - 1


def depth0(toks):
    """(index, token) of the tokens outside (), [] and {}; an opening bracket at depth 0 is included."""
    d = 0
    for i, t in enumerate(toks):
        if t.kind == 'p' and t.text in ('(', '[', '{'):
            if d == 0:
                yield i, t
            d += 1
        elif t.kind == 'p' and t.text in (')', ']', '}'):
            d -= 1
        elif d == 0:
            yield i, t


def norm(toks):
    return ' '.join(t.text for t in toks)


def split0(toks, sep=','):
    out, cur, d = [], [], 0
    for t in toks:
        x = t.text
        if t.kind == 'p' and x in '([{':
            d += 1
        elif t.kind == 'p' and x in ')]}':
            d -= 1
        if d == 0 and x == sep and t.kind == 'p':
            out.append(cur)
            cur = []
        else:
            cur.append(t)
    out.append(cur)
    return out


def declarator_name(toks):
    """Name of one data declarator: the identifier before [, =, :, asm or the end; `(*name)` inside parens."""
    stop = len(toks)
    for i, t in depth0(toks):
        if t.text in ('[', '=', ':') or t.text in ASM_KW or t.text == '__attribute__':
            stop = i
            break
    head = toks[:stop]
    for i, t in enumerate(head):
        if t.text == '(' and i + 1 < len(head) and head[i + 1].text in ('*', '&'):
            for u in head[i + 1:]:
                if u.kind == 'id' and u.text not in SPEC_KW:
                    return u.text
    for t in reversed(head):
        if t.kind == 'id' and t.text not in SPEC_KW:
            return t.text
    return None


class Finding(object):
    __slots__ = ('rule', 'tier', 'file', 'line', 'text')

    def __init__(self, rule, tier, file, line, text):
        self.rule, self.tier, self.file, self.line, self.text = rule, tier, file, line, text

    def key(self):
        return (self.file, self.line, self.rule, self.text)


class Entity(object):
    """Something that can carry findings and name other things: a function, type, macro or global."""

    def __init__(self, kind, name, src, line):
        self.kind, self.name, self.src, self.line = kind, name, src, line
        self.findings, self.refs = [], set()

    def add(self, rule, tier, line, text):
        # `// upstream: <file>` on the line (or the one above): the published library source this unit
        # is rebuilt from has the pattern itself, so an R17 row passes there (AGENTS.md, evidence)
        if rule == 'R17' and has_note(self.src, line, 'upstream:'):
            return
        self.findings.append(Finding(rule, tier, self.src.rel, line, text))

    macro_idents = set()     # identifiers macros of the unit use (a local may be read through one)
    ctor_types = set()       # types of the unit with a constructor or destructor


class Func(Entity):
    def __init__(self, name, cls, src, line, header, body, inline, c_linkage):
        Entity.__init__(self, 'func', name, src, line)
        self.cls, self.header, self.body, self.inline, self.c_linkage = cls, header, body, inline, c_linkage
        self.end = body[-1].line if body else line
        self.addr = None

    @property
    def full(self):
        return (self.cls + '::' if self.cls else '') + self.name


class Type(Entity):
    def __init__(self, keyword, name, src, line, bases, body):
        Entity.__init__(self, 'type', name, src, line)
        self.keyword, self.bases, self.body = keyword, bases, body
        self.virtuals, self.methods = [], set()      # [(name, params)] in declaration order


class Unit(object):
    """A parsed file: its functions, types, externs, prototypes and pending INCLUDE_ASMs."""

    def __init__(self, src):
        self.src = src
        self.name = os.path.splitext(os.path.basename(src.rel))[0]
        self.funcs, self.types, self.fwd = [], {}, {}
        self.externs, self.protos, self.data = {}, {}, set()
        self.pending, self.file_asm = [], []
        self.macros = {}
        self.unit_findings = Entity('unit', self.name, src, 1)
        self.globals = {}
        self._scope(src.toks)
        for name, (line, params, body) in src.macros.items():
            e = Entity('macro', name, src, line)
            e.refs = {t.text for t in body if t.kind == 'id'} - set(params or ())
            self.macros[name] = e
            check_macro(e, params, body)

    # --- file scope ---
    def _scope(self, toks):
        i, n = 0, len(toks)
        while i < n:
            t = toks[i]
            x = t.text
            if x in ('}', ';'):
                i += 1
                continue
            if x == 'extern' and i + 2 < n and toks[i + 1].kind == 'str' and toks[i + 2].text == '{':
                i += 3
                continue
            if x == 'namespace':
                while i < n and toks[i].text != '{':
                    i += 1
                i += 1
                continue
            if x in ('INCLUDE_ASM', 'INCLUDE_RODATA') and i + 1 < n and toks[i + 1].text == '(':
                j = match(toks, i + 1, '(', ')')
                if x == 'INCLUDE_ASM':
                    self.pending.append((toks[j - 1].text, t.line))
                i = j + 1
                continue
            mac = self.src.macros.get(x)
            if mac and mac[1] and i + 1 < n and toks[i + 1].text == '(' and any(u.text == '{' for u in mac[2]):
                # a function defined through a macro: SYSCALL(func_00272E50, 0xD)
                j = match(toks, i + 1, '(', ')')
                args = split0(toks[i + 2:j])
                brace = next(k for k, u in enumerate(mac[2]) if u.text == '{')
                name = next((a[0].text for prm, a in zip(mac[1], args) if a and any(u.text == prm for u in mac[2][:brace])), None)
                if name:
                    body = [Tok(u.kind, u.text, t.line) for u in mac[2][brace:match(mac[2], brace) + 1]]
                    f = Func(name, None, self.src, t.line, toks[i:j + 1], body, False, True)
                    f.refs = {u.text for u in body if u.kind == 'id'} | {x}
                    self.funcs.append(f)
                i = j + 1
                continue
            if x in ASM_KW and i + 1 < n and toks[i + 1].text in ('(', 'volatile'):
                j = match(toks, i + (1 if toks[i + 1].text == '(' else 2), '(', ')')
                self.file_asm.append((t.line, ''.join(u.text.strip('"') for u in toks[i:j] if u.kind == 'str')))
                i = j + 1
                continue
            j, d = i, 0
            while j < n:
                y = toks[j]
                if y.kind == 'p':
                    if y.text in '([':
                        d += 1
                    elif y.text in ')]':
                        d -= 1
                    elif d == 0 and y.text in (';', '{'):
                        break
                j += 1
            header = toks[i:j]
            if j >= n:
                break
            if toks[j].text == ';' and self._old_style(header):
                # an old-style (K&R) definition: `int f(a, b) int a; char *b; { ... }`
                while j < n and toks[j].text != '{':
                    j += 1
                if j >= n:
                    break
                k = match(toks, j)
                self._func(header, toks[j:k + 1])
                i = k + 1
                continue
            if toks[j].text == ';':
                self._decl(header)
                i = j + 1
                continue
            k = match(toks, j)
            kind = self._classify(header)
            if kind == 'func':
                self._func(header, toks[j:k + 1])
                i = k + 1
            elif kind == 'init' and not any(t.text == '=' for t in header):
                i = k + 1                                    # not understood: step over the braces only
            else:
                semi = k + 1
                d = 0
                while semi < n and not (toks[semi].text == ';' and d == 0):
                    if toks[semi].kind == 'p' and toks[semi].text in '([{':
                        d += 1
                    elif toks[semi].kind == 'p' and toks[semi].text in ')]}':
                        d -= 1
                    semi += 1
                if kind == 'type':
                    self._type(header, toks[j:k + 1], toks[k + 1:semi])
                else:
                    name = declarator_name(header)
                    if name:
                        self.data.add(name)
                i = semi + 1

    @staticmethod
    def _old_style(header):
        """`name ( identifiers ) type ...` up to a ';': the parameter declarations of a K&R definition."""
        for i, t in depth0(header):
            if t.text == '(' and i > 0 and header[i - 1].kind == 'id':
                q = match(header, i, '(', ')')
                inside = header[i + 1:q]
                return (q + 1 < len(header) and header[q + 1].kind == 'id'
                        and header[q + 1].text not in ('const', 'throw', '__attribute__') and header[q + 1].text not in ASM_KW
                        and bool(inside) and all(u.kind == 'id' or u.text == ',' for u in inside))
        return False

    @staticmethod
    def _strip_template(header):
        if header and header[0].text == 'template':
            d = 0
            for i, t in enumerate(header):
                if t.text == '<':
                    d += 1
                elif t.text == '>':
                    d -= 1
                    if d == 0:
                        return header[i + 1:], True
                elif t.text == '>>':
                    d -= 2
                    if d <= 0:
                        return header[i + 1:], True
        return header, False

    def _classify(self, header):
        header, _ = self._strip_template(header)
        texts = [t.text for t in header]
        for i, t in depth0(header):
            if t.text == '=' and (i == 0 or texts[i - 1] != 'operator'):
                return 'init'
        lead = [x for x in texts if x not in SPEC_KW and not x.startswith('"')]
        paren = any(t.text == '(' and (i == 0 or texts[i - 1] != '__attribute__') for i, t in depth0(header))
        if lead and lead[0] in TYPE_KW and not paren:
            return 'type'
        if paren:
            return 'func'
        return 'type' if lead and lead[0] in TYPE_KW else 'init'

    def _func(self, header, body):
        header, templ = self._strip_template(header)
        texts = [t.text for t in header]
        p = None
        for i, t in depth0(header):
            if t.text == '(' and i > 0 and texts[i - 1] not in ('__attribute__',) + tuple(ASM_KW):
                p = i
                break
        if p is None:
            return
        k = p - 1
        name = texts[k]
        if 'operator' in texts[:p]:
            k = texts.index('operator')
            name = ''.join(texts[k:p])
        elif k > 0 and texts[k - 1] == '~':
            k -= 1
            name = '~' + name
        if name in ('_DEFUN', '_DEFUN_VOID') and header[p + 1].kind == 'id':
            name = texts[p + 1]                              # newlib's definition macro: the name is its first argument
        cls = texts[k - 2] if k >= 2 and texts[k - 1] == '::' else None
        inline = templ or any(x in ('inline', '__inline__', '__inline') for x in texts[:p])
        c_link = 'extern' in texts[:p] and any(t.kind == 'str' for t in header[:p])
        f = Func(name, cls, self.src, header[0].line, header, body, inline, c_link)
        f.refs = {t.text for t in header + body if t.kind == 'id'}
        self.funcs.append(f)

    def _type(self, header, body, tail):
        texts = [t.text for t in header]
        kw = next((x for x in texts if x in TYPE_KW), 'struct')
        i = texts.index(kw) if kw in texts else 0
        name, bases = None, []
        if i + 1 < len(texts) and header[i + 1].kind == 'id':
            name = texts[i + 1]
        if ':' in texts:
            bases = [t.text for t in header[texts.index(':') + 1:]
                     if t.kind == 'id' and t.text not in ('public', 'private', 'protected', 'virtual')]
        tail_name = declarator_name(tail) if tail else None
        if 'typedef' in texts and tail_name:
            name = name or tail_name
            if tail_name != name:
                self.fwd.setdefault(tail_name, set())
        elif tail_name:
            self.data.add(tail_name)
        if not name:
            return
        ty = Type(kw, name, self.src, header[0].line, bases, body)
        ty.refs = {t.text for t in body if t.kind == 'id'} | set(bases)
        self._members(ty, body[1:-1])
        self.types.setdefault(name, ty)

    def _members(self, ty, toks):
        if ty.keyword == 'enum':
            return
        i, n = 0, len(toks)
        while i < n:
            j, d, stmt_paren = i, 0, False
            while j < n:
                y = toks[j]
                if y.kind == 'p':
                    if y.text in '([':
                        if d == 0 and y.text == '(' and not (j + 1 < n and toks[j + 1].text in ('*', '&')):
                            stmt_paren = True
                        d += 1
                    elif y.text in ')]':
                        d -= 1
                    elif d == 0 and y.text in (';', '{'):
                        break
                j += 1
            stmt = toks[i:j]
            while len(stmt) >= 2 and stmt[0].text in ('public', 'private', 'protected') and stmt[1].text == ':':
                stmt = stmt[2:]
            if j < n and toks[j].text == '{':
                k = match(toks, j)
                if stmt_paren:                               # a method defined in the class
                    self._member_fn(ty, stmt)
                    f = Func(self._member_name(stmt) or '?', ty.name, self.src, stmt[0].line, stmt, toks[j:k + 1], True, False)
                    f.refs = {t.text for t in stmt + toks[j:k + 1] if t.kind == 'id'}
                    self.funcs.append(f)
                    i = k + 1
                    continue
                j = k + 1                                    # a nested type: on to its ';'
                while j < n and toks[j].text != ';':
                    j += 1
                i = j + 1
                continue
            if stmt:
                if stmt_paren:
                    self._member_fn(ty, stmt)
                elif stmt[0].text not in ('friend', 'typedef', 'enum', 'using') and ty.keyword != 'enum':
                    for seg in split0(stmt):
                        name = declarator_name(seg)
                        if name and PAD_RE.match(name):
                            ty.add('R17', 'match', seg[0].line, 'padding member `%s` in %s' % (name, ty.name))
                    if any(t.text == 'volatile' for t in stmt) and not has_note(self.src, stmt[0].line, 'volatile:'):
                        ty.add('R17', 'match', stmt[0].line, '`volatile` member in %s without a `// volatile: <evidence>` note' % ty.name)
            i = j + 1

    @staticmethod
    def _member_name(stmt):
        texts = [t.text for t in stmt]
        for i, t in depth0(stmt):
            if t.text == '(' and i > 0:
                if 'operator' in texts[:i]:
                    return ''.join(texts[texts.index('operator'):i])
                return ('~' if i > 1 and texts[i - 2] == '~' else '') + texts[i - 1]
        return None

    def _member_fn(self, ty, stmt):
        name = self._member_name(stmt)
        if not name:
            return
        ty.methods.add(name)
        if any(t.text == 'virtual' for t in stmt):
            texts = [t.text for t in stmt]
            p = texts.index('(')
            inner = stmt[p + 1:match(stmt, p, '(', ')')]
            params = 0 if not inner or [t.text for t in inner] == ['void'] else len(split0(inner))
            ty.virtuals.append((name, params, stmt[0].line))
            if re.match(r'^(?:pad|dummy|unused_?slot|slot_?pad)\w*$', name, re.I):
                ty.add('R13', 'match', stmt[0].line, 'padding virtual `%s` in %s' % (name, ty.name))

    # --- declarations ending in ';' ---
    def _decl(self, header):
        header, _ = self._strip_template(header)
        if not header:
            return
        texts = [t.text for t in header]
        line = header[0].line
        if texts[0] in TYPE_KW and len(texts) == 2 and header[1].kind == 'id':
            self.fwd.setdefault(texts[1], set()).add((texts[0], line))
            return
        if texts[0] in ('typedef', 'using', 'friend'):
            return
        is_extern = texts[0] == 'extern'
        body = [t for t in header if t.text not in SPEC_KW and t.kind != 'str']
        fn = None
        for i, t in depth0(header):
            if t.text == '(' and i > 0:
                prev = texts[i - 1]
                if header[i - 1].kind == 'id' and prev not in ASM_KW and prev not in ('__attribute__', 'throw'):
                    fn = prev
                break
        if fn:
            self.protos.setdefault(fn, []).append((line, norm(body), any(x in ASM_KW for x in texts)))
            return
        if not is_extern:
            for seg in split0(header):
                name = declarator_name(seg)
                if name:
                    self.data.add(name)
            return
        segs = split0(header)
        base = norm([t for t in segs[0] if t.text not in ('extern',) and t.kind != 'str'])
        for seg in segs:
            name = declarator_name(seg)
            if name:
                shape = re.sub(r'\b%s\b' % re.escape(name), '@', base if seg is segs[0] else norm(seg))
                self.externs.setdefault(name, []).append((line, shape))


def has_note(src, line, tag):
    """A comment carrying `tag` on the line or on the line above."""
    return any(tag in c and (a <= line <= b + 1) for a, b, c in src.comments)


def literal_value(text):
    try:
        return int(re.sub(r'[uUlL]+$', '', text), 0)
    except ValueError:
        return None


def asm_statement(toks, i):
    """toks[i] is asm/__asm__: (end index, assembly text, is a register/symbol label)."""
    j = i + 1
    if j < len(toks) and toks[j].text == 'volatile':
        j += 1
    if j >= len(toks) or toks[j].text != '(':
        return i, None, False
    k = match(toks, j, '(', ')')
    text, d = [], 0
    for u in toks[j + 1:k]:
        if u.text == ':' and d == 0:
            break                                   # operands follow
        if u.kind == 'p' and u.text in '([':
            d += 1
        elif u.kind == 'p' and u.text in ')]':
            d -= 1
        if u.kind == 'str':
            text.append(u.text[1:-1])
    label = i > 0 and (toks[i - 1].kind == 'id' or toks[i - 1].text in (')', ']'))
    return k, ''.join(text), label


def classify_asm(text):
    """'empty', 'hardware' (only instructions C cannot express) or 'code'."""
    ops = [s.strip().split()[0].lower() for s in re.split(r'\\n|\\t(?=\.)|;|\n', text.replace('\\t', ' ')) if s.strip()]
    if not ops:
        return 'empty'
    if all(o.startswith('.') for o in ops):
        return 'directive'
    if FIXED_REG_RE.search(text) and len(ops) <= 2:
        return 'hardware'
    ops = [o for o in ops if not o.startswith('.')]
    hw = [o for o in ops if o in HW_MNEMONICS or HW_MNEMONIC_RE.match(o)]
    rest = [o for o in ops if o not in hw]
    if hw and all(o in HW_GLUE for o in rest):
        return 'hardware'
    return 'code'


def check_macro(e, params, body):
    text = norm(body)
    if R4_MACRO.search(text) and 'offsetof' not in e.name.lower() and 'FOFS' not in e.name:
        e.add('R4', 'match', e.line, 'offset macro `%s`: a typed dereference of a byte pointer plus an offset' % e.name)
    i = 0
    while i < len(body):
        if body[i].text in ASM_KW:
            k, asm, label = asm_statement(body, i)
            if asm is not None and not label:
                kind = classify_asm(asm)
                if kind == 'hardware':
                    e.add('R18', 'listed', e.line, 'hardware assembly in macro `%s` (original helper by necessity)' % e.name)
                elif kind in ('empty', 'directive'):
                    e.add('R17', 'match', e.line, 'macro `%s` is an asm statement without instructions: exists only to steer' % e.name)
                elif kind == 'code':
                    e.add('R18', 'match', e.line, 'assembly in macro `%s`' % e.name)
            i = max(k, i) + 1
            continue
        if body[i].text == 'volatile' and not (i and body[i - 1].text in ASM_KW):
            if not volatile_ok(body, i, e.src, e.line, set(params or ())):
                e.add('R17', 'match', e.line, '`volatile` in macro `%s` on something other than a hardware address' % e.name)
        i += 1


def volatile_ok(toks, i, src, line, params=()):
    """A volatile cast is genuine on a literal hardware address (or a macro parameter, checked at the
    macro's uses by review), or with a `// volatile: <evidence>` note."""
    if has_note(src, line, 'volatile:'):
        return True
    # inside a cast: find the ')' closing the cast, then the operand
    d, j = 0, i
    while j < len(toks):
        x = toks[j].text
        if x == '(':
            d += 1
        elif x == ')':
            if d == 0:
                break
            d -= 1
        j += 1
    if j + 1 >= len(toks):
        return False
    k = j + 1
    while k < len(toks) and toks[k].text == '(':
        k += 1
    if k < len(toks):
        if toks[k].kind == 'num':
            v = literal_value(toks[k].text)
            return v is not None and any(lo <= v < hi for lo, hi in HW_RANGES)
        if toks[k].text in params and (k + 1 >= len(toks) or toks[k + 1].text == ')'):
            return True
    return False


def check_body(ent, fname, body, src):
    """The in-body rows of R4, R17 and R18, plus the advisory readability rows. `body` is `{ ... }`."""
    n = len(body)
    text = norm(body)
    lines = [0]
    for t in body:
        lines.append(lines[-1] + len(t.text) + 1)

    def line_at(pos):
        lo, hi = 0, n
        while lo < hi:
            mid = (lo + hi) // 2
            if lines[mid + 1] <= pos:
                lo = mid + 1
            else:
                hi = mid
        return body[min(lo, n - 1)].line

    for m in R4_DEREF.finditer(text):
        ent.add('R4', 'match', line_at(m.start()), 'offset cast: `%s`' % m.group()[:70])
    for m in R4_THIS.finditer(text):
        ent.add('R4', 'match', line_at(m.start()), '`this` in offset arithmetic: `%s`' % text[m.start():m.start() + 50])
    for m in R4_PLAIN.finditer(text):
        ent.add('R4', 'advisory', line_at(m.start()), 'typed dereference of a pointer plus a constant: `%s`' % m.group()[:60])

    idents = {}
    for t in body:
        if t.kind == 'id':
            idents[t.text] = idents.get(t.text, 0) + 1

    # brace kinds, so a ';' after a block's '}' can be told from one after an initializer or a type
    kinds, stack, paren_kw, pstack = {}, [], {}, []
    stmt_start = 0
    for i, t in enumerate(body):
        x = t.text
        if t.kind != 'p':
            continue
        if x == '{':
            prev = body[i - 1].text if i else ''
            first = body[stmt_start].text if stmt_start < i else ''
            k = 'init' if prev in ('=', ',', '{', '(', ']') and i else 'type' if first in TYPE_KW or first == 'typedef' else 'block'
            if stack and stack[-1][1] == 'init':
                k = 'init'
            stack.append((i, k))
            stmt_start = i + 1
        elif x == '}':
            if stack:
                o, k = stack.pop()
                kinds[i] = k
            stmt_start = i + 1
        elif x == ';':
            stmt_start = i + 1
        elif x == '(':
            pstack.append(i)
        elif x == ')':
            if pstack:
                o = pstack.pop()
                paren_kw[i] = body[o - 1].text if o else ''

    i = 1
    start = 1                                  # index of the current statement's first token
    pdepth = 0
    while i < n - 1:
        t = body[i]
        x = t.text
        prev = body[i - 1]
        if t.kind == 'p':
            if x in '([':
                pdepth += 1
            elif x in ')]':
                pdepth -= 1
        # --- R18 / R17: assembly statements ---
        if x in ASM_KW:
            k, asm, label = asm_statement(body, i)
            if asm is not None:
                if label:
                    if not re.search(r'\$(28|gp)\b', asm):
                        ent.add('F', 'advisory', t.line, 'local pinned to a register with asm("%s") (Section F: register steering)' % asm)
                else:
                    kind = classify_asm(asm)
                    if kind == 'empty':
                        ent.add('R17', 'match', t.line, 'empty asm statement: exists only to steer the compiler')
                    elif kind == 'directive':
                        ent.add('R17', 'match', t.line, 'asm statement of directives only (`%s`): exists only to steer the assembler' % asm[:40])
                    elif kind == 'hardware':
                        ent.add('R18', 'listed', t.line, 'hardware assembly (original helper by necessity): `%s`' % asm[:50])
                    else:
                        ent.add('R18', 'match', t.line, 'assembly in a C body: `%s`' % asm[:50])
                i = k + 1
                continue
        # --- R17: volatile ---
        if x == 'volatile' and prev.text not in ASM_KW:
            if pdepth == 0:
                # `volatile T *p` points at something volatile (the cast that fills it is tested where
                # it is written); the local itself is volatile only without the `*`, or after it
                j, star = i + 1, False
                while j < n and body[j].text not in (';', '=', ',', '[', '('):
                    star = star or body[j].text == '*'
                    j += 1
                own = not star or prev.text == '*'
                if own and not has_note(src, t.line, 'volatile:'):
                    ent.add('R17', 'match', t.line, '`volatile` on a local')
            elif not volatile_ok(body, i, src, t.line):
                ent.add('R17', 'match', t.line, '`volatile` cast on ordinary data (a carrier to force a load or store)')
        # --- R17: do { } while (0) outside a macro ---
        if x == 'while' and i + 3 < n and body[i + 1].text == '(' and body[i + 2].text in ('0', 'false') \
                and body[i + 3].text == ')' and prev.text == '}':
            ent.add('R17', 'match', t.line, '`do { } while (0)` outside a macro (usually a macro the original called: R31)')
        # --- R17: empty if / else, bare ';' ---
        if x == '{' and i + 1 < n and body[i + 1].text == '}':
            if prev.text == 'else' or (prev.text == ')' and paren_kw.get(i - 1) == 'if'):
                ent.add('R17', 'match', t.line, 'empty `%s` block' % ('else' if prev.text == 'else' else 'if'))
        if x == ';' and pdepth == 0:
            if prev.text == 'else' or (prev.text == ')' and paren_kw.get(i - 1) == 'if'):
                ent.add('R17', 'match', t.line, 'empty `%s` statement' % ('else' if prev.text == 'else' else 'if'))
            elif prev.text in (';', '{') or (prev.text == '}' and kinds.get(i - 1) == 'block'):
                ent.add('R17', 'match', t.line, 'bare `;` statement')
        # --- R17: + 0 and * 1 ---
        if t.kind == 'num' and prev.kind == 'p' and ((x == '0' and prev.text == '+') or (x == '1' and prev.text == '*')):
            before = body[i - 2] if i >= 2 else None
            binary = before is not None and (before.kind in ('id', 'num') or before.text in (')', ']'))
            nxt = body[i + 1].text
            if binary and nxt not in ('.', '*', '/', '%', '<<', '>>') and before.text not in ('return', 'case'):
                ent.add('R17', 'match', t.line, 'arithmetic no-op `%s %s`' % (prev.text, x))
        # --- statement-level rows ---
        if x in (';', '{', '}') and pdepth == 0:
            stmt = body[start:i]
            if x == ';' and stmt:
                check_statement(ent, stmt, idents, body, src)
            start = i + 1
        elif x == ':' and pdepth == 0 and start < n and (
                body[start].text in ('case', 'default') or (i == start + 1 and body[start].kind == 'id')):
            start = i + 1
        # --- advisory: readability ---
        if x in ('if', 'for', 'while', 'else') and t.kind == 'id':
            j = i + 1
            if x != 'else' and j < n and body[j].text == '(':
                j = match(body, j, '(', ')') + 1
                if x == 'if' or x == 'while':
                    cond = body[i + 2:j - 1]
                    if any(u.text == '=' for u in cond):
                        ent.add('R35', 'advisory', t.line, 'assignment inside a condition')
            if j < n and body[j].text not in ('{', ';') and not (x == 'else' and body[j].text == 'if') \
                    and not (x == 'while' and prev.text == '}'):
                ent.add('R35', 'advisory', t.line, '`%s` body without braces' % x)
        if x == 'goto':
            ent.add('R14', 'advisory', t.line, '`goto %s`' % body[i + 1].text)
        if x == '!' and body[i + 1].text == '!':
            ent.add('F', 'advisory', t.line, '`!!x` (Section F: sometimes human, needs a look)')
        if x == 'extern' and pdepth == 0:
            ent.add('R25', 'advisory', t.line, 'local `extern` declaration inside a function')
        i += 1

    for a, b, c in src.comments:
        if body[0].line <= a <= body[-1].line and re.search(r'\bprobe\b', c, re.I):
            ent.add('R17', 'match', a, 'statement marked as a probe')


def check_statement(ent, stmt, idents, body, src):
    texts = [t.text for t in stmt]
    # self-assignment
    if '=' in texts:
        e = texts.index('=')
        if e and texts[:e] == texts[e + 1:] and not any(x in ('(', '++', '--') for x in texts):
            ent.add('R17', 'match', stmt[0].line, 'self-assignment `%s`' % ' '.join(texts))
    # a local nothing reads: declared (with or without a value) and never named again
    first = texts[0]
    if first in STMT_KW or stmt[0].kind != 'id' or any(x in ASM_KW for x in texts):
        return
    k = 0
    while k < len(stmt) and (texts[k] in SPEC_KW or texts[k] in TYPE_KW):
        k += 1
    if k >= len(stmt) or stmt[k].kind != 'id':
        return
    if texts[k] in ent.ctor_types:
        return                                          # an object whose constructor may be the point
    k += 1                                              # the type name
    while k < len(stmt) and texts[k] == '::':
        k += 2
    if k < len(stmt) and texts[k] == '<':
        return                                          # templates: not worth guessing
    rest = stmt[k:]
    if not rest:
        return
    for seg in split0(rest):
        j = 0
        while j < len(seg) and seg[j].text in ('*', '&', 'const', 'volatile'):
            j += 1
        if j >= len(seg) or seg[j].kind != 'id' or seg[j].text in STMT_KW:
            return
        after = seg[j + 1].text if j + 1 < len(seg) else ';'
        if after not in (';', '=', '['):
            return
        name = seg[j].text
        if idents.get(name, 0) == 1 and name not in ent.macro_idents and not has_note(src, seg[j].line, 'R36'):
            ent.add('R17', 'match', seg[j].line, 'local `%s` is never used' % name)


# ---------------------------------------------------------------------------------------------

def symbol_table():
    names = {}
    for path in ('config/symbol_addrs.txt', 'config/vtables.txt'):
        for m in re.finditer(r'^\s*([\w$.]+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;(.*)$', read(path), re.M):
            names.setdefault(m.group(1), (int(m.group(2), 16), m.group(3)))
    return names


def vtable_slots(names):
    """class -> number of virtual slots, from `_vt$<len><Class> ... size:0xNN` (docs/units.md: entry 0
    is the typeinfo function, the last entry is null)."""
    out = {}
    for sym, (addr, rest) in names.items():
        m = re.fullmatch(r'_vt\$(\d+)(\w+)', sym)
        s = re.search(r'size:(0x[0-9A-Fa-f]+)', rest)
        if m and s and int(m.group(1)) == len(m.group(2)):
            out[m.group(2)] = int(s.group(1), 16) // 8 - 2
    return out


def text_units():
    rows = []
    for m in re.finditer(r'^\s*- \[(0x[0-9A-Fa-f]+),\s*(\w+)\s*(?:,\s*(\w+))?\s*\]', read('config/SCPS_150.88.yaml'), re.M):
        rows.append((int(m.group(1), 16) + 0xFF000, m.group(2), m.group(3)))
    rows.sort()
    units = []
    for i, (vram, kind, name) in enumerate(rows):
        if vram >= TEXT_END:
            break
        end = rows[i + 1][0] if i + 1 < len(rows) else TEXT_END
        units.append((name, kind, vram, min(end, TEXT_END)))
    return units


def function_address(f, names, by_prefix):
    """Best effort: the address of a definition, from its name (func_XXXXXXXX, an address in the
    name, or the one GCC 2.9x mangled symbol that fits)."""
    m = re.fullmatch(r'func_([0-9A-Fa-f]{8})', f.name)
    if m:
        return int(m.group(1), 16)
    if f.c_linkage and f.name in names:
        return names[f.name][0]
    if f.cls:
        if f.name.startswith('~'):
            key = '_$_%d%s' % (len(f.cls), f.cls)
            return names[key][0] if key in names else None
        key = ('__%d%s' if f.name == f.cls else f.name + '__%d%s') % (len(f.cls), f.cls)
    else:
        key = f.name + '__F'
    cands = by_prefix.get(key, ())
    if len(cands) == 1:
        return cands[0]
    if f.name in names:
        return names[f.name][0]
    m = re.search(r'([0-9A-F]{6})$', f.name)
    if m and not cands:
        return int(m.group(1), 16)
    return None


class Project(object):
    def __init__(self, sources=None, names=None):
        """The tree, or (for the self-test) `sources`: {path: text} with the symbols in `names`."""
        self.headers = {}
        if sources is None:
            for h in sorted(os.listdir(os.path.join(R, 'include'))):
                if h.endswith('.h'):
                    self.headers[h] = self._unit('include/' + h)
            self.units = [self._unit('src/' + f) for f in sorted(os.listdir(os.path.join(R, 'src'))) if f.endswith('.cpp')]
        else:
            for rel, text in sources.items():
                if rel.endswith('.h'):
                    self.headers[os.path.basename(rel)] = Unit(Source(rel, text))
            self.units = [Unit(Source(rel, text)) for rel, text in sources.items() if not rel.endswith('.h')]
        self.names = symbol_table() if names is None else names
        self.slots = vtable_slots(self.names)
        self.shapes = {}
        for v in self.units:
            for name, decls in v.externs.items():
                self.shapes.setdefault(name, set()).update(s for _, s in decls)
        self._r1()
        for u in list(self.headers.values()) + self.units:
            self._unit_rows(u)
        self._resolve()

    @staticmethod
    def _unit(rel):
        return Unit(Source(rel))

    def tu_headers(self, u, seen=None):
        seen = seen if seen is not None else []
        for inc in u.src.includes:
            h = self.headers.get(os.path.basename(inc))
            if h and h not in seen:
                seen.append(h)
                self.tu_headers(h, seen)
        return seen

    # R1: one name, two files, different bodies; class/struct keyword mismatches (advisory here)
    def _r1(self):
        defs = {}
        for u in list(self.headers.values()) + self.units:
            for name, ty in u.types.items():
                defs.setdefault(name, []).append((u, ty))
        self.type_defs = defs
        for name, lst in defs.items():
            bodies = {norm(ty.body) for _, ty in lst}
            if len(lst) > 1 and len(bodies) > 1:
                files = sorted({u.src.rel for u, _ in lst})
                for u, ty in lst:
                    others = [f for f in files if f != u.src.rel]
                    ty.add('R1', 'match', ty.line, '`%s %s` is defined with %d different bodies in %d files (also %s%s)' % (
                        ty.keyword, name, len(bodies), len(files), ', '.join(os.path.basename(f) for f in others[:3]),
                        ', ...' if len(others) > 3 else ''))
        for u in list(self.headers.values()) + self.units:
            for name, kws in u.fwd.items():
                for kw, line in kws:
                    for _, ty in defs.get(name, ()):
                        if ty.keyword in ('class', 'struct') and kw in ('class', 'struct') and kw != ty.keyword:
                            u.unit_findings.add('R1', 'advisory', line, 'forward declaration `%s %s`, defined as `%s`' % (kw, name, ty.keyword))
                            break

    def _unit_rows(self, u):
        src = u.src
        tu = [u] + self.tu_headers(u)
        if not src.is_header:
            # R2: extern data outside a header; one global with two types
            for name, decls in u.externs.items():
                e = Entity('global', name, src, decls[0][0])
                kinds = self.shapes.get(name, ())
                e.add('R2', 'match', decls[0][0], '`extern %s` declared in the unit, not in a shared header%s' % (
                    name, ' (%d different types across units)' % len(kinds) if len(kinds) > 1 else ''))
                u.globals[name] = e
            # R25 (advisory): prototypes of other units' functions written in the unit
            own = {f.name for f in u.funcs}
            n = sum(1 for name in u.protos if name not in own)
            if n:
                u.unit_findings.add('R25', 'advisory', 1, "%d prototypes of other units' functions declared in the unit, not in a header" % n)
            aliases = sum(1 for name, lst in u.protos.items() if any(a for _, _, a in lst))
            if aliases:
                u.unit_findings.add('R12', 'advisory', 1, '%d functions declared under another name with an asm("symbol") label' % aliases)
        # R37 (advisory): #if 0 blocks
        for a, b in src.ifzero:
            u.unit_findings.add('R37', 'advisory', a, '`#if 0` block (%d lines): a parked attempt belongs in docs/hard/, not in the unit' % (b - a + 1))
        # file-scope assembly that is not INCLUDE_ASM/INCLUDE_RODATA: alignment workarounds
        for line, text in u.file_asm:
            u.unit_findings.add('R18', 'advisory', line, 'file-scope asm("%s")' % text[:40])
        # R21 (advisory)
        notes = sum(1 for a, b, c in src.comments if NOTE_RE.search(c))
        if notes:
            u.unit_findings.add('R21', 'advisory', 1, '%d comments carry campaign notes (lanes, scores, dates)' % notes)
        # R13: declared virtuals against the binary's vtable
        types = {}
        for v in reversed(tu):
            types.update(v.types)
        for name, ty in u.types.items():
            if name in self.slots:
                decl = self._virtuals(ty, types, set())
                if decl is not None and len(decl) > self.slots[name]:
                    ty.add('R13', 'match', ty.line, '%s declares %d virtuals, its vtable has %d slots' % (name, len(decl), self.slots[name]))
                elif decl is not None and len(decl) < self.slots[name] and ty.virtuals:
                    ty.add('R13', 'advisory', ty.line, '%s declares %d of its vtable\'s %d slots' % (name, len(decl), self.slots[name]))
        # in-body rows
        macro_ids = set()
        for v in tu:
            for m in v.macros.values():
                macro_ids |= m.refs
        Entity.macro_idents = macro_ids
        Entity.ctor_types = {n for n, ty in types.items() if any(m.lstrip('~') == n for m in ty.methods)}
        comment_ends = {b for a, b, c in src.comments}
        for f in u.funcs:
            check_body(f, f.full, f.body, src)
            if not f.inline:
                if not (f.line - 1 in comment_ends or f.line - 2 in comment_ends):
                    f.add('R33', 'advisory', f.line, 'no header comment')
                if any(p.match(f.name) for p in PLACEHOLDER_RES) or ADDRESS_LIKE.search(f.name):
                    f.add('R7', 'advisory', f.line, 'placeholder name `%s`' % f.full)

    def _virtuals(self, ty, types, seen):
        """Slot list of a class with its bases', or None when a base is not declared in the unit."""
        if ty.name in seen:
            return None
        seen.add(ty.name)
        slots = []
        for b in ty.bases:
            if b not in types:
                return None
            base = self._virtuals(types[b], types, seen)
            if base is None:
                return None
            slots += base
        have = {('~', 0) if n.startswith('~') else (n, p) for n, p in slots}
        for n, p, _ in ty.virtuals:
            key = ('~', 0) if n.startswith('~') else (n, p)
            if key not in have:
                have.add(key)
                slots.append((n, p))
        return slots

    # every function gets the findings of what it names
    def _resolve(self):
        by_prefix = {}
        for sym, (addr, _) in self.names.items():
            for cut in range(len(sym), 0, -1):
                by_prefix.setdefault(sym[:cut], [])
                if len(by_prefix[sym[:cut]]) < 3:
                    by_prefix[sym[:cut]].append(addr)
        self.functions = []
        for u in self.units:
            tu = [u] + self.tu_headers(u)
            macros, types, inlines, globs = {}, {}, {}, dict(u.globals)
            for v in reversed(tu):
                macros.update(v.macros)
                types.update(v.types)
                for f in v.funcs:
                    if f.inline or v.src.is_header:
                        inlines.setdefault(f.name, []).append(f)
            # a function a header defines out of line is compiled into every unit that includes it
            shared = [copy.copy(f) for v in tu[1:] for f in v.funcs if not f.inline]
            for f in u.funcs + shared:
                if f.inline:
                    continue
                found, seen, stack = {}, set(), [f]
                if f.cls and f.cls in types:
                    stack.append(types[f.cls])
                while stack:
                    e = stack.pop()
                    if id(e) in seen:
                        continue
                    seen.add(id(e))
                    for x in e.findings:
                        if e is f or x.tier != 'advisory':
                            found.setdefault(x.key(), (x, None if e is f else e))
                    if e.kind == 'type':
                        stack += [types[b] for b in e.bases if b in types]
                        continue
                    for name in e.refs:
                        if name in macros:
                            stack.append(macros[name])
                        if name in types:
                            stack.append(types[name])
                        if name in globs:
                            stack.append(globs[name])
                        for g in inlines.get(name, ()):
                            if g is not f:
                                stack.append(g)
                f.unit = u
                f.all = [x for x, _ in found.values()]
                f.via = {x.key(): e for x, e in found.values() if e is not None}
                f.broken = sorted({x.rule for x in f.all if x.tier == 'match'}, key=MATCH_RULES.index)
                f.addr = function_address(f, self.names, by_prefix)
                self.functions.append(f)


def tree_progress(proj):
    """(matched addresses, sizes, ORIGINAL-ASM addresses, all starts): tools/bk/progress_report.py's count."""
    names = {n: a for n, (a, _) in proj.names.items()}
    starts = sorted(int(l, 16) for l in read('config/functions.txt').splitlines() if l.startswith('0x'))
    starts = [a for a in starts if a < TEXT_END]
    size = {a: e - a for a, e in zip(starts, starts[1:] + [TEXT_END])}
    pending = set()
    for u in proj.units:
        for sym, _ in u.pending:
            m = re.fullmatch(r'func_([0-9A-Fa-f]{8})', sym)
            a = int(m.group(1), 16) if m else names.get(sym)
            if a is not None:
                pending.add(a)
    asm_only, original = set(), set()
    for name, kind, lo, hi in text_units():
        inside = {a for a in starts if lo <= a < hi}
        if kind == 'asm' or name in ORIGINAL_ASM_UNITS:
            asm_only |= inside
        if name in ORIGINAL_ASM_UNITS:
            original |= inside
    matched = [a for a in starts if a not in pending and a not in asm_only]
    return matched, size, original, starts


def summarise(proj):
    matched, size, original, starts = tree_progress(proj)
    funcs = proj.functions
    pend = [f for f in funcs if f.broken]
    per_rule = {r: 0 for r in MATCH_RULES}
    for f in pend:
        for r in f.broken:
            per_rule[r] += 1
    only = {r: sum(1 for f in pend if f.broken == [r]) for r in MATCH_RULES}
    listed = sum(1 for f in funcs if any(x.rule == 'R18' and x.tier == 'listed' for x in f.all))
    adv = {}
    for f in funcs:
        for x in f.all:
            if x.tier == 'advisory':
                adv[x.rule] = adv.get(x.rule, 0) + 1
    unit_adv = {}
    for u in proj.units:
        for x in u.unit_findings.findings:
            unit_adv.setdefault(x.rule, []).append(x)
    mapped = {f.addr for f in pend if f.addr in size}
    matched_set = set(matched)
    pend_bytes = sum(size[a] for a in mapped if a in matched_set)
    total = len(starts) - len(original)
    units = {}
    for f in funcs:
        d = units.setdefault(f.unit.name, [0, 0])
        d[0] += 1
        d[1] += bool(f.broken)
    return {
        'functions_total': total, 'original_asm': len(original),
        'bytes_matched_functions': len(matched),
        'bytes_matched_code': sum(size[a] for a in matched),
        'definitions_checked': len(funcs),
        'match_pending': len(pend),
        'match_pending_code': pend_bytes, 'match_pending_with_address': len(mapped & matched_set),
        'matched_under_rules': len(matched) - sum(1 for f in pend if f.addr is None or f.addr in matched_set),
        'total_code': sum(size[a] for a in starts if a not in original),
        'per_rule': per_rule, 'only_rule': only, 'listed_asm_helpers': listed,
        'advisory': adv, 'unit_advisory': {r: len(v) for r, v in unit_adv.items()},
        'units': {k: {'checked': v[0], 'match_pending': v[1]} for k, v in sorted(units.items())},
    }


RULE_TITLES = {
    'R1': 'one declaration per type', 'R2': 'one declaration per global', 'R4': 'no offset casts',
    'R13': 'real vtables', 'R17': 'no fake code', 'R18': 'no assembly bodies',
    'R7': 'placeholder names', 'R12': 'functions under another name', 'R14': '`goto`',
    'R21': 'campaign notes in comments', 'R25': 'prototypes outside headers', 'R33': 'no header comment',
    'R35': 'braceless bodies, assignments in conditions', 'R37': '`#if 0` blocks', 'F': 'Section F patterns to review',
}


def print_summary(s, md=False):
    pct = lambda a, b: 100.0 * a / b if b else 0.0
    if md:
        print('## Code rules\n')
        print('| | functions | |')
        print('|---|---:|---|')
        print('| Bytes matched | %d / %d | %.1f%% |' % (s['bytes_matched_functions'], s['functions_total'], pct(s['bytes_matched_functions'], s['functions_total'])))
        print('| **Matched under the rules** | **%d / %d** | **%.1f%%** |' % (s['matched_under_rules'], s['functions_total'], pct(s['matched_under_rules'], s['functions_total'])))
        print('| MATCH-PENDING (bytes match, a [match] rule fails) | %d | |' % s['match_pending'])
        print('\n| [match] rule | functions it holds back | of them, by this rule alone |')
        print('|---|---:|---:|')
        for r in MATCH_RULES:
            print('| %s %s | %d | %d |' % (r, RULE_TITLES[r], s['per_rule'][r], s['only_rule'][r]))
        print('\nAdvisory (never blocks a match): ' + ', '.join(
            '%s %s: %d' % (r, RULE_TITLES.get(r, ''), n) for r, n in sorted(s['advisory'].items())) + '.')
        return
    print('functions in .text: %d (+ %d ORIGINAL-ASM in crt0, counted neither way)' % (s['functions_total'], s['original_asm']))
    print('bytes matched:              %5d  %5.1f%%   (%d bytes of code)' % (
        s['bytes_matched_functions'], pct(s['bytes_matched_functions'], s['functions_total']), s['bytes_matched_code']))
    print('matched under the rules:    %5d  %5.1f%%   <- the headline figure' % (
        s['matched_under_rules'], pct(s['matched_under_rules'], s['functions_total'])))
    print('MATCH-PENDING:              %5d           (%d with a known address: %d bytes)' % (
        s['match_pending'], s['match_pending_with_address'], s['match_pending_code']))
    print('definitions checked:        %5d           (out-of-line function definitions in src/*.cpp)' % s['definitions_checked'])
    print('\n[match] rule                        functions held back   by this rule alone')
    for r in MATCH_RULES:
        print('  %-4s %-28s %10d %20d' % (r, RULE_TITLES[r], s['per_rule'][r], s['only_rule'][r]))
    print('  functions using a listed hardware-asm helper (R18, counted): %d' % s['listed_asm_helpers'])
    print('\nadvisory (never blocks a match), findings in checked functions:')
    for r, n in sorted(s['advisory'].items()):
        print('  %-4s %-45s %6d' % (r, RULE_TITLES.get(r, ''), n))
    print('advisory, per unit:')
    for r, n in sorted(s['unit_advisory'].items()):
        print('  %-4s %-45s %6d' % (r, RULE_TITLES.get(r, ''), n))


SELFTEST = [
    # (rule expected to hold the function back, or None; source of one unit; optional header)
    ('R4', 'struct A { int x; }; int f(A *p) { return *(int *)((char *)p + 0x58); }'),
    ('R4', 'struct A { int x; int g(); }; int A::g() { return *(int *)((u8 *)this + 0x10); }'),
    ('R4', '#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))\nint f(void *p) { return FLD(int, p, 8); }'),
    (None, 'int f(char *buf, int n) { char *end = buf + n; while (buf < end) { if (*buf++ == 0) { return 1; } } return 0; }'),
    ('R2', 'extern int g_frameCount;\nint f(void) { return g_frameCount; }'),
    (None, '#include "frame.h"\nint f(void) { return g_frameCount; }', 'extern int g_frameCount;'),
    ('R1', 'struct Foo { int count; };\nint f(Foo *p) { return p->count; }', 'struct Foo { int count; float scale; };'),
    (None, 'struct Mine { int count; };\nint f(Mine *p) { return p->count; }'),
    ('R13', 'class B { public: virtual ~B(); virtual void Update(); virtual void Stub(); };\nvoid B::Update() { }'),
    (None, 'class B { public: virtual ~B(); virtual void Update(); };\nvoid B::Update() { }'),
    ('R17', 'int f(int *p) { return *(volatile int *)(p + 2); }'),
    (None, 'void f(void) { *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 | 0x10000; }'),
    (None, 'void f(void) { volatile unsigned int *r = (volatile unsigned int *)0x10002010; *r = 1; }'),
    ('R17', 'int f(int a) { volatile int flag; flag = a; return flag; }'),
    ('R17', 'int g(void);\nint f(void) { int dummy; return g(); }'),
    (None, 'int g(void);\nint f(void) { int unused; // R36: retail reserves this slot\n return g(); }'),
    ('R17', 'int f(int a) { if (a) { } else { a = 1; } return a; }'),
    ('R17', 'int f(int a) { ; return a; }'),
    (None, 'int f(char *s) { int n = 0; for (;;) { if (!*s) break; s++; n++; } while (*s++) ; return n; }'),
    (None, 'int f(int a) { switch (a) { case 1: ; } goto done; done: ; return a; }'),
    ('R17', 'int f(int a) { do { a++; } while (0); return a; }'),
    (None, '#define SWAP(a, b) do { int t = (a); (a) = (b); (b) = t; } while (0)\nint f(int a, int b) { SWAP(a, b); return a; }'),
    ('R17', 'int f(int a) { a = a; return a; }'),
    ('R17', 'int f(int *p, int i) { return p[i + 0]; }'),
    (None, 'int f(int *p, int i) { return p[i + 0x10] * 10 + 1; }'),
    ('R17', 'struct P { int a; char pad4[12]; int b; };\nint f(P *p) { return p->b; }'),
    (None, 'struct P { int a; char unk_4[12]; int b; };\nint f(P *p) { return p->b; }'),
    ('R17', 'int g(void);\nint f(void) { int r = g(); __asm__(""); return r; }'),
    ('R18', 'int f(int a) { __asm__("addu $2, $4, $4"); }'),
    (None, 'unsigned int f(void) { unsigned int r; __asm__ volatile("mfc0 %0, $12" : "=r"(r)); return r; }'),
    (None, 'void f(char *dst, const char *src, int n) { while (--n) { *dst++ = *src++; } }'),
    (None, 'int g(int);\nint f(int a) { int r; if (!(r = g(a))) { goto fail; } return r;\nfail:\n return -1; }'),
]


def selftest():
    names = {'_vt$1B': (0x2C0000, ' // size:0x20'), 'Update__1B': (0x100400, '')}
    bad = 0
    for case in SELFTEST:
        want, text = case[0], case[1]
        sources = {'src/T.cpp': 'typedef unsigned char u8;\n' + text}
        if len(case) > 2:
            sources['include/frame.h'] = case[2]
            if '#include' not in text:
                sources['src/U.cpp'] = '#include "frame.h"\n'
        proj = Project(sources, names)
        got = sorted({r for f in proj.functions if f.src.rel == 'src/T.cpp' for r in f.broken})
        if got != ([want] if want else []):
            bad += 1
            print('selftest: expected %s, got %s: %s' % (want, got or None, text.replace('\n', ' / ')))
    print('selftest: %d cases, %d wrong' % (len(SELFTEST), bad))
    return bad


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('units', nargs='*', help='unit names (src/<UNIT>.cpp); default all')
    ap.add_argument('-v', '--verbose', action='store_true', help='one line per finding')
    ap.add_argument('--rule', action='append', help='only this rule (repeatable)')
    ap.add_argument('--match-only', action='store_true', help='with -v: leave out the advisory findings')
    ap.add_argument('--pending', action='store_true', help='list the MATCH-PENDING functions')
    ap.add_argument('--json', metavar='FILE', help='write everything as JSON')
    ap.add_argument('--md', action='store_true', help='print the summary as Markdown')
    ap.add_argument('--selftest', action='store_true', help='run the rows against built-in cases and exit')
    args = ap.parse_args()
    if args.selftest:
        sys.exit(1 if selftest() else 0)

    proj = Project()
    want = set(args.units)
    unknown = want - {u.name for u in proj.units}
    if unknown:
        sys.exit('rules.py: no such unit: ' + ' '.join(sorted(unknown)))
    funcs = [f for f in proj.functions if not want or f.unit.name in want]
    rules = set(args.rule or ())

    def keep(x):
        return (not rules or x.rule in rules) and not (args.match_only and x.tier == 'advisory')

    if args.verbose:
        rows, shared = set(), {}
        for f in funcs:
            for x in f.all:
                if keep(x):
                    if x.key() in f.via:            # a finding in a declaration: once, with its reach
                        shared.setdefault(x.key(), [x, 0])[1] += 1
                    else:
                        rows.add((x.file, x.line, x.rule, x.tier, f.full, x.text))
        for x, count in shared.values():
            rows.add((x.file, x.line, x.rule, x.tier, '%d function%s' % (count, 's' if count > 1 else ''), x.text))
        for u in proj.units:
            if not want or u.name in want:
                for x in u.unit_findings.findings:
                    if keep(x):
                        rows.add((x.file, x.line, x.rule, x.tier, '-', x.text))
        for file, line, rule, tier, fn, text in sorted(rows):
            print('%s:%d: %s [%s] %s: %s' % (file, line, rule, tier, fn, text))
    if args.pending:
        for f in funcs:
            if f.broken and (not rules or rules & set(f.broken)):
                print('%s:%d: MATCH-PENDING %s%s: %s' % (f.src.rel, f.line, f.full, ' (0x%X)' % f.addr if f.addr else '', ' '.join(f.broken)))
    s = summarise(proj)
    if args.json:
        out = dict(s)
        out['functions'] = [{
            'unit': f.unit.name, 'name': f.full, 'line': f.line, 'address': f.addr, 'match_pending': bool(f.broken),
            'rules': f.broken,
            'findings': [{'rule': x.rule, 'tier': x.tier, 'file': x.file, 'line': x.line, 'text': x.text} for x in sorted(f.all, key=lambda x: (x.file, x.line))],
        } for f in proj.functions]
        out['unit_findings'] = [{'unit': u.name, 'rule': x.rule, 'tier': x.tier, 'line': x.line, 'text': x.text}
                                for u in proj.units for x in u.unit_findings.findings]
        os.makedirs(os.path.dirname(os.path.abspath(args.json)), exist_ok=True)
        with open(args.json, 'w') as fp:
            json.dump(out, fp, indent=1)
            fp.write('\n')
    if not (args.verbose or args.pending) or args.md:
        print_summary(s, md=args.md)


if __name__ == '__main__':
    main()
