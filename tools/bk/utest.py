#!/usr/bin/env python3
"""utest.py SNIP: test a snippet the way the real build sees it.

`bk test` compiles the snippet alone and masks relocated fields, so it misses two things the full
build catches (and lanes kept tripping over):
- the rest of the unit: functions before it in the same .cpp change delay-slot filling and where
  GNU as 2.10's lui->lw bug strikes;
- what each relocation points at: two stores to different globals in swapped order look identical
  once the address bits are masked.
utest splices the snippet into a copy of its unit (replacing the INCLUDE_ASMs, adding the decls),
compiles the whole unit with the unit's own flags, and compares each function at its real offset:
the words with relocated fields masked, plus the address every relocation resolves to against the
symbol the retail asm uses there. MATCH here means the full build will match too (barring
cross-unit effects such as a name clash).
"""
import os
import re
import struct
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import bk  # noqa: E402  (loads ctx.json and the retail image)

R, W = bk.R, bk.W


def unit_starts():
    out = {}
    for m in re.finditer(r'\[0x([0-9A-Fa-f]+), (?:cpp|c), (\w+)\]', open(R + '/config/SCPS_150.88.yaml').read()):
        out[m.group(2)] = int(m.group(1), 16) + 0xFF000
    return out


def symbol_table():
    """name -> address, from every symbol file the link uses."""
    t = {}
    for p in ('config/symbol_addrs.txt', 'config/aliases.ld', 'config/vtables.txt', 'build/data_syms_auto.txt',
              'build/undefined_syms_auto.txt', 'build/undefined_funcs_auto.txt'):
        p = os.path.join(R, p)
        if os.path.exists(p):
            for m in re.finditer(r'^\s*([A-Za-z_.$][\w.$]*)\s*=\s*(0x[0-9A-Fa-f]+)', open(p).read(), re.M):
                t.setdefault(m.group(1), int(m.group(2), 16))
    return t


def addr_of(name, table):
    if name in table:
        return table[name]
    m = re.match(r'^(?:func|D|jtbl|L)_([0-9A-Fa-f]{8})$', name)
    return int(m.group(1), 16) if m else None


def target_refs(c):
    """instruction index -> symbol the retail asm names there (from splat's .s)."""
    p = f"{R}/asm/nonmatchings/{c['unit']}/{c['name']}.s"
    refs, i, text = {}, -1, True
    for line in open(p):
        if line.startswith('.section'):
            text = line.split()[1] == '.text'
        # instructions only: not a migrated .asciz or a jump table in the .s's own .rodata section
        if not text or not re.search(r'/\* \w+ [0-9A-F]{8} [0-9A-F]{8} \*/', line):
            continue
        i += 1
        m = re.search(r'%(?:hi|lo)\(([A-Za-z_.$][\w.$]*)\)|\bjal\s+([A-Za-z_.$][\w.$]*)', line)
        if m:
            refs[i] = m.group(1) or m.group(2)
    return refs


def read_obj_full(path):
    """.text bytes and {offset: (reloc type, symbol name or None for section symbols)}."""
    b = open(path, 'rb').read()
    shoff, = struct.unpack_from('<I', b, 0x20)
    shnum, shstrndx = struct.unpack_from('<HH', b, 0x30)
    sh = [struct.unpack_from('<10I', b, shoff + 40 * i) for i in range(shnum)]
    nm = lambda tab, o: b[sh[tab][4] + o:b.index(b'\0', sh[tab][4] + o)].decode()
    names = [nm(shstrndx, s[0]) for s in sh]
    ti = names.index('.text')
    text = b[sh[ti][4]:sh[ti][4] + sh[ti][5]]
    symtab = next(i for i, s in enumerate(sh) if s[1] == 2)
    syms = []
    for k in range(sh[symtab][5] // 16):
        st_name, val, size, info, _, shndx = struct.unpack_from('<IIIBBH', b, sh[symtab][4] + 16 * k)
        syms.append((nm(sh[symtab][6], st_name) if st_name else None, info & 0xF))
    relocs = {}
    for s in sh:
        if s[1] == 9 and s[7] == ti:
            for k in range(s[5] // 8):
                off, info = struct.unpack_from('<II', b, s[4] + 8 * k)
                name, typ = syms[info >> 8]
                relocs[off] = (info & 0xFF, None if typ == 3 else name)   # STT_SECTION: local data
    return text, relocs


def splice(unit, decl, funcs):
    p = f'{R}/src/{unit}.cpp'
    s = open(p).read()
    for addr, body in funcs:
        old = bk.ctx[hex(addr)]['name']
        pat = re.compile(r'^INCLUDE_ASM\("[^"]+", %s\);\n' % re.escape(old), re.M)
        if not pat.search(s):
            raise SystemExit(f'{unit}.cpp has no INCLUDE_ASM for {old}')
        s = pat.sub(lambda m: body, s)
    if decl.strip():
        m = re.search(r'^// @decl-end\n', s, re.M)
        if m:
            s = s[:m.start()] + decl.strip() + '\n' + s[m.start():]
        else:
            i = s.index('#include "common.h"\n') + len('#include "common.h"\n')
            s = s[:i] + decl + s[i:]
    return s


def utest(path, quiet=False):
    decl, funcs = bk.parse(path)
    units = {bk.ctx[hex(a)]['unit'] for a, _ in funcs if hex(a) in bk.ctx}
    if len(units) != 1:
        raise SystemExit(f'snippet functions must be INCLUDE_ASM\'d in one unit: {units}')
    unit = next(iter(units))
    src = os.path.join(W, f'ut_{unit}_{os.getpid()}.cpp')
    open(src, 'w').write(splice(unit, decl, funcs))
    cc, base, asg = bk.flags_for(funcs)
    obj = os.path.join(W, f'ut_{os.getpid()}.o')
    r = subprocess.run([cc] + base + ['-I' + R + '/include', '-Wa,-I' + R + '/include'] + asg + ['-c', '-o', obj, src],
                       capture_output=True, text=True, cwd=R)
    if r.returncode:
        if not quiet:
            print(r.stderr)
        os.remove(src)
        raise SystemExit(1)
    text, relocs = read_obj_full(obj)
    start = unit_starts()[unit]
    table = symbol_table()
    res = []
    for addr, _ in funcs:
        c = bk.ctx[hex(addr)]
        n = c['n']
        off = addr - start
        mine = bk.words(text, off, n)
        theirs = bk.words(bk.rom, addr - 0xFF000, n)
        tref = target_refs(c)
        bad, notes = 0, []
        for i, (x, y) in enumerate(zip(mine, theirs)):
            rel = relocs.get(off + 4 * i)
            m = 0xFFFFFFFF
            if rel and rel[0] in (5, 6):
                m = 0xFFFF0000
            elif rel and rel[0] == 4:
                m = 0xFC000000
            if (x & m) != (y & m):
                bad += 1
                continue
            if rel and rel[0] == 4:
                # calls: retail's target is in its own instruction; ours is the symbol's address,
                # or (a call inside this unit goes through the .text section symbol) the in-place
                # word offset from the unit's start
                a_theirs = ((y & 0x03FFFFFF) << 2) | (addr & 0xF0000000)
                a_ours = addr_of(rel[1], table) if rel[1] else start + ((x & 0x03FFFFFF) << 2)
                if a_ours is not None and a_ours != a_theirs:
                    bad += 1
                    notes.append(f'insn {i}: ours calls {rel[1] or "a local function"} (0x{a_ours:X}), '
                                 f'retail 0x{a_theirs:X} ({tref.get(i, "?")})')
            elif rel and rel[1] and i in tref:
                a_ours, a_theirs = addr_of(rel[1], table), addr_of(tref[i], table)
                # REL objects keep the addend in place: `sym+off` (D_338390.active) can be retail's
                # own label at that address (D_33A5A0). LO16 exact; HI16 only its half (the low
                # part of the addend sits in the paired LO16)
                if a_ours is not None and a_theirs is not None and a_ours != a_theirs:
                    lo = x & 0xFFFF
                    if rel[0] == 6 and a_ours + (lo - 0x10000 if lo & 0x8000 else lo) == a_theirs:
                        a_ours = a_theirs
                    elif rel[0] == 5 and -0x8000 < a_ours + (lo << 16) - a_theirs <= 0x8000:
                        a_ours = a_theirs
                if a_ours is not None and a_theirs is not None and a_ours != a_theirs:
                    bad += 1
                    notes.append(f'insn {i}: ours {rel[1]} (0x{a_ours:X}), retail {tref[i]} (0x{a_theirs:X})')
        res.append((addr, c['name'], bad, notes))
        if not quiet:
            print(f"{addr:#x} {c['name']}: " + ('MATCH (in unit)' if not bad else f'DIFF {bad} (in unit)'))
            for note in notes[:6]:
                print('    ' + note)
    # the rest of the unit must not move: a function that came out longer or shorter shifts
    # everything after it (relocated fields masked as above)
    mine_all = bk.words(text, 0, len(text) // 4)
    theirs_all = bk.words(bk.rom, start - 0xFF000, len(text) // 4)
    inside = set()
    for addr, _ in funcs:
        o = (addr - start) // 4
        inside.update(range(o, o + bk.ctx[hex(addr)]['n']))
    for i, (x, y) in enumerate(zip(mine_all, theirs_all)):
        if i in inside:
            continue
        rel = relocs.get(4 * i)
        m = 0xFFFF0000 if rel and rel[0] in (5, 6) else 0xFC000000 if rel and rel[0] == 4 else 0xFFFFFFFF
        if (x & m) != (y & m):
            res.append((start + 4 * i, 'rest of unit', 1, []))
            if not quiet:
                print(f'{start + 4 * i:#x}: the rest of {unit} differs from here (a function above changed size, or a same-unit side effect)')
            break
    if os.environ.get('BK_UT_KEEP'):   # keep the unit object for objdump (lane w2)
        import shutil
        shutil.copy(obj, os.path.join(W, 'ut.o'))
    os.remove(obj)
    os.remove(src)
    return res


if __name__ == '__main__':
    r = utest(sys.argv[1])
    sys.exit(1 if any(x[2] for x in r) else 0)
