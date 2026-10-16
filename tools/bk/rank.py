#!/usr/bin/env python3
"""rank.py [--units U1,U2|--prefix P] [--skip-hard] [-n N]: the INCLUDE_ASM'd functions to try
next, best first, as TSV (rank, score, addr, unit, insns, ready, fanin, flags).

Smallest-first stops paying once the small ones are gone. This ranks by readiness instead: a
function whose callees are already C (`ready` = share of its distinct callees matched) has known
signatures, types and struct layouts to write against, so it is the cheapest to match next. Size
and blockers (vtable stores, virtual calls, jump tables, floats, VU0, unaligned loads, HARD.md)
still count, and `fanin` (other unmatched functions calling it) breaks ties: matching it unlocks
those. Needs build/bk/ctx.json (tools/bk/mk.sh).
"""
import argparse
import glob
import json
import os
import re

R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
VT_LO, VT_HI = 0x2BFA40, 0x2C2C98
PEN = {'vtable': 30, 'vcall': 30, 'HARD': 2000, 'switch': 40, 'float': 10, 'unaligned': 200, 'vu0': 100,
       'jalr': 15}


def main():
    p = argparse.ArgumentParser(description=__doc__.split('\n\n')[0])
    p.add_argument('--units', help='comma-separated unit names')
    p.add_argument('--prefix', help='unit name prefix (Unit, Dk, Lib, C...)')
    p.add_argument('--skip-hard', action='store_true')
    p.add_argument('-n', type=int, default=0)
    a = p.parse_args()
    ctx = json.load(open(f'{R}/build/bk/ctx.json'))
    hard = open(f'{R}/HARD.md').read()
    remaining = {c['name'] for c in ctx.values()}
    by_name = {c['name']: int(k, 16) for k, c in ctx.items()}
    calls, text = {}, {}
    for k, c in ctx.items():
        path = f"{R}/asm/nonmatchings/{c['unit']}/{c['name']}.s"
        if not os.path.exists(path):
            continue
        ins = [re.sub(r'\s+', ' ', l.split('*/', 1)[1].strip()) for l in open(path) if re.search(r'/\* \w+ [0-9A-F]{8} ', l)]
        text[k] = '\n'.join(ins)
        calls[k] = set(re.findall(r'\bjal (\w+)', text[k]))
    fanin = {}
    for k, cs in calls.items():
        for callee in cs:
            if callee in by_name:
                fanin[callee] = fanin.get(callee, 0) + 1
    want = set(a.units.split(',')) if a.units else None
    rows = []
    for k, c in ctx.items():
        if not 0x100000 <= int(k, 16) < 0x29F230 or c['name'].startswith(('D_', 'jtbl_')):
            continue   # .rodata pieces (INCLUDE_RODATA) are in ctx.json too
        if k not in text or (want and c['unit'] not in want) or (a.prefix and not c['unit'].startswith(a.prefix)):
            continue
        addr, t = int(k, 16), text[k]
        flags = []
        if any(VT_LO <= r < VT_HI for r in c['refs']):
            flags.append('vtable')
        if 'jalr' in t:
            flags.append('vcall' if re.search(r'\blh ', t) else 'jalr')
        if 'jtbl' in t:
            flags.append('switch')
        if re.search(r'\b(lwc1|swc1|mtc1|add\.s|mul\.s|cvt)', t):
            flags.append('float')
        if re.search(r'\b(ldl|ldr|sdl|sdr)\b', t):
            flags.append('unaligned')
        if re.search(r'\bv\w+\.\w+|\bqmfc2|\bqmtc2|\blqc2|\bsqc2', t):
            flags.append('vu0')
        if f'0x{addr:X}' in hard or f'0x{addr:x}' in hard:
            flags.append('HARD')
            if a.skip_hard:
                continue
        cs = calls[k]
        ready = 1.0 if not cs else sum(1 for x in cs if x not in remaining) / len(cs)
        n = c['n']
        # readiness halves the cost of a big function; blockers add on top
        score = n * (1.5 - ready) + sum(PEN.get(f, 0) for f in flags) - min(fanin.get(c['name'], 0), 10)
        rows.append((score, addr, c['unit'], n, ready, fanin.get(c['name'], 0), ','.join(flags) or '-'))
    rows.sort()
    if a.n:
        rows = rows[:a.n]
    print('rank\tscore\taddr\tunit\tinsns\tready\tfanin\tflags')
    for i, (score, addr, unit, n, ready, fi, flags) in enumerate(rows, 1):
        print(f'{i}\t{score:.0f}\t0x{addr:X}\t{unit}\t{n}\t{ready:.2f}\t{fi}\t{flags}')


if __name__ == '__main__':
    main()
