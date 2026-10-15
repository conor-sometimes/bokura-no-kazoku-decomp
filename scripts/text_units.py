#!/usr/bin/env python3
"""Cut the C-style game code (CAppMain 0x1E91B8 up to dklib at 0x245648) into units.

This code has no vtables to find units by (scripts/find_units.py), but each unit's literals are
contiguous in .rodata and in unit order. So a cut between two functions is only allowed where
no literal is shared across it: every .rodata address referenced after the cut is above every one
referenced before it. Cuts are taken greedily once a unit holds ~2500 instructions or 60
functions. The result is a plausible split for INCLUDE_ASM and matching (functions keep their
addresses either way); the real file boundaries may differ and can be refined later.

  python3 -I scripts/text_units.py asm/text_1e91b8.s

Run it on the single asm file of the range from before the split (yaml piece
`[0xEA1B8, asm, text_1e91b8]`): after the split, splat's empty functions are C bodies, not asm,
so the counts and some cuts come out different.
"""
import re
import sys

LO, HI = 0x1E91B8, 0x245648
RODATA = (0x2D1800, 0x2EAE00)    # below the SDK's .rodata


def funcs(paths):
    out = {}
    for p in paths:
        for part in re.split(r'\nglabel ', '\n' + open(p).read())[1:]:
            name, body = part.split('\n', 1)
            addrs = re.findall(r'/\* \w+ ([0-9A-F]{8}) ', body)
            if not addrs:
                continue
            a = int(addrs[0], 16)
            if LO <= a < HI:
                ro = [int(x, 16) for x in re.findall(r'%(?:hi|lo)\((?:D|jtbl)_([0-9A-F]{8})\)', body)]
                out[a] = (name.strip(), len(addrs), [r for r in ro if RODATA[0] <= r < RODATA[1]])
    return [out[a] for a in sorted(out)], sorted(out)


def main():
    global LO, HI
    args = sys.argv[1:]
    prefix = 'Unit'
    if args[:1] == ['--range']:      # --range LO HI PREFIX: another region (dklib: 0x245648 0x283858 Dk)
        LO, HI, prefix = int(args[1], 16), int(args[2], 16), args[3]
        args = args[4:]
    f, addrs = funcs(args)
    sufmin = [1 << 32] * (len(f) + 1)
    for i in range(len(f) - 1, -1, -1):
        sufmin[i] = min([sufmin[i + 1]] + f[i][2])
    cuts, mx, n, ins = [addrs[0]], 0, 0, 0
    for i, (name, size, ro) in enumerate(f):
        n += 1
        ins += size
        mx = max([mx] + ro)
        if i + 1 < len(f) and (ins >= 2500 or n >= 60) and sufmin[i + 1] > mx:
            cuts.append(addrs[i + 1])
            n = ins = 0
    for a in cuts:
        name = 'CAppMain' if a == 0x1E91B8 else f'{prefix}{a:06X}'
        print(f'      - [0x{a - 0xFF000:X}, cpp, {name}]')


if __name__ == '__main__':
    main()
