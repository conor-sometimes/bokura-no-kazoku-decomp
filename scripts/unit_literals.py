#!/usr/bin/env python3
"""Functions whose .rodata literals sit in another unit's .rodata piece (lane cv, docs/units.md).

Needs the full disassembly of scripts/data_units.py (build/full/asm). Prints, per (text unit, piece),
the functions of the first that use literals of the second: a file tail that belongs to the next unit
(move it there, or into a unit of its own), or a merged `# also` pair. Library linkonce users
(Lib29xxxx typeinfo functions) are expected.

  python3 -I scripts/unit_literals.py [FUNCTIONS-OF-UNIT]
With a unit name, lists that unit's functions and the literal addresses each references instead.
"""
import re, os, glob, sys
R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
A = R + '/build/full/asm'
texts, pieces = [], []
for line in open(R + '/config/SCPS_150.88.yaml'):
    m = re.match(r"\s*- \[0x([0-9A-F]+), (cpp|asm|c), (\w+)\]", line)
    if m: texts.append((int(m.group(1), 16) + 0xFF000, m.group(3)))
    m = re.match(r"\s*- \[0x([0-9A-F]+), (\.?rodata), (\w+)\]", line)
    if m:
        n = m.group(3); n = n[3:] if n.startswith('ro_') else n
        pieces.append((int(m.group(1), 16) + 0xFF000, n))
pieces.sort()
def piece(a):
    r = None
    for s, n in pieces:
        if s <= a: r = n
    return r
def tunit(a):
    r = None
    for s, n in texts:
        if s <= a: r = n
    return r
from collections import defaultdict
if len(sys.argv) > 1:
    fn = None; rows = []
    for line in open(A + '/' + sys.argv[1] + '.s'):
        m = re.match(r'glabel (\w+)', line)
        if m: fn = [m.group(1), None, []]; rows.append(fn); continue
        m = re.match(r'\s*/\* \w+ ([0-9A-F]{8}) ', line)
        if m and fn and fn[1] is None: fn[1] = m.group(1)
        for s in re.findall(r'\b((?:D|jtbl)_002[DE][0-9A-F]{4})\b', line):
            if s not in fn[2]: fn[2].append(s)
    for n, a, r in rows:
        print(a, n, ' '.join(x.split('_')[1][2:] for x in r))
    sys.exit(0)
out = defaultdict(list)
for p in sorted(glob.glob(A + '/*.s')):
    fn = None; fa = None
    for line in open(p):
        m = re.match(r'glabel (\w+)', line)
        if m: fn = m.group(1); fa = None; continue
        m = re.match(r'\s*/\* \w+ ([0-9A-F]{8}) ', line)
        if m and fa is None and fn: fa = int(m.group(1), 16)
        for s in re.findall(r'%lo\(((?:D|jtbl)_002[DE][0-9A-F]{4})\)', line):
            a = int(s.split('_')[1], 16)
            if not (0x2D1800 <= a < 0x2EAB80) or fa is None: continue
            u = tunit(fa); pc = piece(a)
            if pc and pc != u and pc != 'tail':
                out[(u, pc)].append((fa, fn, s))
for (u, pc), l in sorted(out.items()):
    fs = sorted(set((a, n) for a, n, s in l))
    print(f'{u} -> {pc}: ' + ' '.join(f'{a:X}:{n}' for a, n in fs[:6]) + (f' (+{len(fs)-6})' if len(fs) > 6 else ''))

