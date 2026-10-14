#!/usr/bin/env python3
# dataconv.py UNIT [apply|revert] : a unit's data from its object (docs/units.md "Converting a unit").
#   (no verb)  vtables of the unit slot by slot, and its .rodata symbols with their status
#   apply      switch the unit's vt_/ro_ pieces in the yaml to come from build/src/UNIT.cpp.o
#   apply ro   only the .rodata piece (the key method is not C++ yet: the RTTI names then need
#              INCLUDE_RODATA too, which `fix` adds)
#   revert     back to asm pieces
#   fix        add INCLUDE_RODATA lines for the .rodata symbols no asm defines, each right after the
#              INCLUDE_ASM of the one function that uses it (others are listed for you to place)
# Run from the repo root on the build host, after a split (tools/bk/mk.sh) for the rodata status.
import glob, os, re, struct, sys
R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
Y = R + '/config/SCPS_150.88.yaml'
OFF = 0xFF000
rom = open(R + '/disc/SCPS_150.88', 'rb').read()
w = lambda va: struct.unpack_from('<I', rom, va - OFF)[0]


def sa(name):
    """Address of a D_XXXXXXXX / jtbl_XXXXXXXX symbol."""
    return int(name.split('_')[-1], 16)


def syms():
    names = {}
    for p in ('config/symbol_addrs.txt', 'config/vtables.txt'):
        for line in open(R + '/' + p):
            m = re.match(r'\s*([\w$.]+)\s*=\s*0x([0-9A-Fa-f]+)', line)
            if m:
                names.setdefault(int(m.group(2), 16), m.group(1))
    return names


def subsegments():
    out = []
    for i, line in enumerate(open(Y)):
        m = re.match(r'\s*- \[0x([0-9A-F]+), ([.\w]+), (\w+)\]', line) or \
            re.match(r'\s*- \{start: 0x([0-9A-F]+), type: ([.\w]+), name: (\w+)', line)
        if m:
            out.append((int(m.group(1), 16) + OFF, m.group(2), m.group(3), i))
        elif re.match(r'\s*- \[0x[0-9A-F]+\]', line):
            out.append((int(re.search(r'0x([0-9A-F]+)', line).group(1), 16) + OFF, 'end', '', i))
    return out


def find(subs, unit):
    """(text, vt, ro) as (start, end, type, line) for the unit; None where missing."""
    res = {}
    for k, (a, t, n, i) in enumerate(subs):
        e = subs[k + 1][0] if k + 1 < len(subs) else None
        if t == 'cpp' and n == unit: res['text'] = (a, e, t, i)
        if (t == 'data' and n == 'vt_' + unit) or (t == '.data' and n == unit): res['vt'] = (a, e, t, i)
        if (t == 'rodata' and n == 'ro_' + unit) or (t == '.rodata' and n == unit): res['ro'] = (a, e, t, i)
    return res


def unit_at(subs, a):
    for k, (s, t, n, i) in enumerate(subs):
        if t == 'cpp' and s <= a < subs[k + 1][0]:
            return n
    return None


def show(unit):
    subs, names = subsegments(), syms()
    u = find(subs, unit)
    if 'vt' not in u:
        sys.exit(f'{unit}: no vt_{unit} piece in the yaml (merged into another unit, see the yaml comments)')
    print(f'{unit}: text {u["text"][0]:#x}-{u["text"][1]:#x}, vtables {u["vt"][0]:#x}-{u["vt"][1]:#x} '
          f'({u["vt"][2]}), rodata {u["ro"][0]:#x}-{u["ro"][1]:#x} ({u["ro"][2]})')
    v = u['vt'][0]
    rtti = []
    while v < u['vt'][1]:
        tf = w(v + 4)
        n = names.get(v, f'D_{v:08X}')
        print(f'\n  {n} at {v:#x}, typeinfo function {names.get(tf, hex(tf))}')
        k, a = 1, v + 8
        while w(a) or w(a + 4):
            t = w(a + 4)
            where = unit_at(subs, t)
            tag = ('this unit' if where == unit else f'unit {where}' if where else
                   'pure virtual' if names.get(t) == '__pure_virtual' else 'inline/library (asm)')
            print(f'    [{k - 1}] +{8 * k:#04x} {t:#x} {names.get(t, "func_%08X" % t):40} {tag}')
            k, a = k + 1, a + 8
        m = re.match(r'_vt\$(\S+)', n)
        if m:
            rtti.append(m.group(1))
        v = a + 8
    print('\n  The key method (first non-inline virtual the class declares, usually the destructor) '
          'emits the vtable:\n  define it in C++ only together with `apply`. Every slot target must link: '
          'name this unit\'s\n  functions in symbol_addrs.txt with their mangled names.')
    ro_status(unit, u, names, rtti)


def ro_status(unit, u, names, rtti, quiet=False):
    lo, hi = u['ro'][0], u['ro'][1]
    defined, refs = {}, {}
    cpp = open(f'{R}/src/{unit}.cpp').read()
    for p in glob.glob(R + '/asm/**/*.s', recursive=True):
        if 'nonmatchings' in p and os.path.basename(p).startswith('D_'):
            continue        # INCLUDE_RODATA files: counted from the .cpp below (may be stale)
        for line in open(p):
            m = re.match(r'\s*glabel ((?:D|jtbl)_[0-9A-F]+)', line)
            if m:
                defined[m.group(1)] = os.path.relpath(p, R)
            for s in re.findall(r'%lo\(((?:D|jtbl)_[0-9A-F]+)\)|\.word ((?:D|jtbl)_[0-9A-F]+)', line):
                s = s[0] or s[1]
                if lo <= sa(s) < hi:
                    refs.setdefault(s, set()).add(os.path.basename(p)[:-2])
    if not quiet:
        print(f'\n  .rodata symbols {lo:#x}-{hi:#x}:')
    missing = []
    piece = R + f'/asm/data/ro_{unit}.rodata.s'
    for p in glob.glob(R + '/src/*.cpp'):
        code = '\n'.join(l for l in open(p).read().split('\n') if not l.startswith('INCLUDE_'))
        for s in re.findall(r'\b(D_[0-9A-F]{8})\b', code):
            if lo <= sa(s) < hi:
                refs.setdefault(s, set()).add(os.path.basename(p)[:-4] + '.cpp')
    rec = R + f'/build/bk/ro_labels/{unit}.txt'
    recorded = set(open(rec).read().split()) if os.path.exists(rec) else set()
    labels = set(refs) | recorded | {s for s in defined if lo <= sa(s) < hi}
    for s in sorted(labels, key=sa):
        a = sa(s)
        txt = rom[a - OFF:rom.index(b'\0', a - OFF)][:40]
        isrtti = txt.decode('latin1') in rtti
        where = defined.get(s)
        if isrtti and u['vt'][2] == '.data':
            st = 'RTTI name (the compiler writes it)'
        elif isrtti and f'INCLUDE_RODATA("asm/nonmatchings/{unit}", {s});' in cpp:
            st = 'RTTI name, INCLUDE_RODATA while the vtable is asm (delete it when you `apply` the vtable)'
        elif f'INCLUDE_RODATA("asm/nonmatchings/{unit}", {s});' in cpp:
            st = 'INCLUDE_RODATA'
        elif where and 'nonmatchings' in where:
            st = f'in {where}'
        elif where:
            st = f'asm piece {where}'
        else:
            st = 'NOT DEFINED: add INCLUDE_RODATA (or the C++ that emits it)'
            missing.append((s, sorted(refs.get(s, []))))
        if not quiet:
            print(f'    {s} {txt!r:44} used by {",".join(sorted(refs.get(s, []))) or "-"}: {st}')
    return missing


def switch(unit, to_obj, only=None):
    subs = subsegments()
    u = find(subs, unit)
    piece = R + f'/asm/data/ro_{unit}.rodata.s'
    if to_obj and only != 'vt' and os.path.exists(piece):
        # remember every label of the asm piece (fix needs the unreferenced ones too)
        os.makedirs(R + '/build/bk/ro_labels', exist_ok=True)
        open(R + f'/build/bk/ro_labels/{unit}.txt', 'w').write(
            '\n'.join(re.findall(r'glabel ((?:D|jtbl)_[0-9A-F]+)', open(piece).read())) + '\n')
    lines = open(Y).read().split('\n')
    for key, asm, obj in (('vt', f'      - [0x{{:X}}, data, vt_{unit}]',
                           f'      - {{{{start: 0x{{:X}}, type: .data, name: {unit}, linker_section: .gnu.linkonce.d.*}}}}'),
                          ('ro', f'      - [0x{{:X}}, rodata, ro_{unit}]', f'      - [0x{{:X}}, .rodata, {unit}]')):
        if only and key != only:
            continue
        a, e, t, i = u[key]
        lines[i] = (obj if to_obj else asm).format(a - OFF) + (' ' + lines[i].split(']', 1)[1].strip() if '#' in lines[i] else '')
    open(Y, 'w').write('\n'.join(lines))
    what = {'ro': '.rodata piece', 'vt': 'vtable piece'}.get(only, 'vtable and .rodata pieces')
    print(f'{unit}: {what} now from', f'build/src/{unit}.cpp.o' if to_obj else 'asm')


NOMIG = R + '/config/rodata_syms.txt'


def no_migration(sym):
    """List sym in config/rodata_syms.txt with force_not_migration, so that splat writes it as
    its own file for INCLUDE_RODATA instead of giving it to the C++ function that uses it."""
    have = open(NOMIG).read() if os.path.exists(NOMIG) else ''
    if re.search(r'^%s\b' % sym, have, re.M):
        return False
    lines = [l for l in have.split('\n') if l.strip()]
    hdr = [l for l in lines if l.startswith('//')]
    ent = sorted([l for l in lines if not l.startswith('//')] +
                 [f'{sym} = 0x{sa(sym):08X}; // force_not_migration:True'])
    open(NOMIG, 'w').write('\n'.join(hdr + ent) + '\n')
    return True


def fix(unit):
    subs, names = subsegments(), syms()
    u = find(subs, unit)
    if u['ro'][2] != '.rodata':
        sys.exit(f'{unit}: .rodata is still asm (run apply first)')
    rtti, v = [], u['vt'][0]
    while v < u['vt'][1]:
        m = re.match(r'_vt\$(\S+)', names.get(v, ''))
        if m:
            rtti.append(m.group(1))
        a = v + 8
        while w(a) or w(a + 4):
            a += 8
        v = a + 8
    vt_obj = u['vt'][2] == '.data'
    missing = ro_status(unit, u, names, rtti if vt_obj else [], quiet=True)
    path = f'{R}/src/{unit}.cpp'
    lines = open(path).read().split('\n')
    inc = lambda l, kind: l is not None and l.startswith(kind)
    incsym = lambda l: re.search(r', ((?:D|jtbl)_[0-9A-F]+)\);', l).group(1)

    def fstart(i):
        """First line of the top-level definition containing line i."""
        while i > 0 and not re.match(r'[A-Za-z_~][^;]*\(', lines[i] or ''):
            i -= 1
        return i

    def fend(i):
        """Closing brace (column 0) of the definition containing line i."""
        while i < len(lines) - 1 and (lines[i] or '') != '}':
            i += 1
        return i

    # 1. literals that matched C++ refers to by name (extern char D_X[]): splat would give them
    #    to that function (no file); with force_not_migration they get a file like the rest.
    pseudo, rest, resplit = [], [], False
    for sym, users in sorted(missing, key=lambda x: sa(x[0])):
        if any(us.endswith('.cpp') for us in users) and sym.startswith('D_') and not sa(sym) & 3:
            resplit |= no_migration(sym)
        rest.append((sym, users))

    # 2. where everything else goes: emitters are INCLUDE_ASMs with literals splat moved into
    #    their .s, INCLUDE_RODATAs, and the C++ functions from step 1.
    em = list(pseudo)
    for i, l in enumerate(lines):
        if inc(l, 'INCLUDE_ASM'):
            fs = R + f'/asm/nonmatchings/{unit}/{l.split(", ")[1].rstrip(");")}.s'
            mig = [int(x, 16) for x in re.findall(r'glabel (?:D|jtbl)_([0-9A-F]+)', open(fs).read())] if os.path.exists(fs) else []
            if mig:
                em.append((i, i, min(mig), max(mig)))
        elif inc(l, 'INCLUDE_RODATA'):
            em.append((i, i, sa(incsym(l)), sa(incsym(l))))
    top = [k for k, l in enumerate(lines) if inc(l, '// @decl-end')] or \
          [k for k, l in enumerate(lines) if inc(l, '#include')][-1:]
    inserts = []
    for sym, users in rest:
        a = sa(sym)
        if a & 3:
            continue                    # unaligned (ldl/ldr) label: inside the previous symbol's file
        if rom[a - OFF:rom.index(b'\0', a - OFF)].decode('latin1') in rtti:
            inserts.append((len(lines) - (lines[-1] == ''), a, sym, 'at the end (RTTI name)'))
            continue
        inside = [e for e in em if e[2] < a < e[3]]
        if inside:
            print(f'{sym}: between the literals splat moved into {lines[inside[0][0]]}: place it by hand')
            continue
        # pending inserts sit at p - 0.5 (before line p); several at one place are sorted by address
        ok = lambda p: all(e[3] < a for e in em if e[1] < p and e[1] != p - 0.5) and \
            all(e[2] > a for e in em if e[0] >= p) and not any(e[0] < p <= e[1] for e in em)
        p, how = None, ''
        # GCC writes a literal where the first function using it is compiled
        ui = sorted(i for i, l in enumerate(lines) for us in users
                    if l is not None and re.match(r'INCLUDE_ASM\("asm/nonmatchings/%s", %s\);' % (unit, re.escape(us)), l))
        if ui:
            f = ui[0]
            fm = [e for e in em if e[0] == f]
            q = f + 1 if fm and fm[0][3] < a else f
            if ok(q):
                p, how = q, f'at its first user {lines[f]}'
        if p is None:
            before = [e for e in em if e[3] < a]
            after = [e for e in em if e[2] > a]
            if before:
                e = max(before, key=lambda e: e[3])
                p = int(e[1] + 0.5) if e[1] != int(e[1]) else e[1] + 1
                how = f'after {lines[p - 1]}'
            elif after:
                e = min(after, key=lambda e: e[2])
                p = int(e[0] + 0.5) if e[0] != int(e[0]) else e[0]
                how = f'before {lines[p]}'
            else:
                p, how = top[0] + 1, 'at the top'
        inserts.append((p, a, sym, how))
        em.append((p - 0.5, p - 0.5, a, a))
    for p, a, sym, how in sorted(inserts, key=lambda x: (-x[0], -x[1])):
        lines.insert(p, f'INCLUDE_RODATA("asm/nonmatchings/{unit}", {sym});')
    for p, a, sym, how in sorted(inserts, key=lambda x: x[1]):
        print(f'{sym}: {how}')
    open(path, 'w').write('\n'.join(l for l in lines if l is not None))
    if resplit:
        print('config/rodata_syms.txt changed: run tools/bk/mk.sh (re-split) before building')

if __name__ == '__main__':
    unit, verb = sys.argv[1], (sys.argv[2] if len(sys.argv) > 2 else 'show')
    if verb == 'apply': switch(unit, True, sys.argv[3] if len(sys.argv) > 3 else None)
    elif verb == 'revert': switch(unit, False)
    elif verb == 'fix': fix(unit)
    else: show(unit)
