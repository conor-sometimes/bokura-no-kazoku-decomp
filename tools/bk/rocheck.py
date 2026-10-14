#!/usr/bin/env python3
# rocheck.py [UNIT...] : for units whose .rodata / vtables come from their object (yaml `.rodata` /
# `.data` pieces), compare what the object put there (linked image, build/SCPS_150.88.map) with
# the retail bytes at the piece's own address. Works even when an earlier unit is wrong and shifts
# the rest, so one build tells which conversions to fix. Prints only bad units unless -v.
import os, re, sys
R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
OFF = 0xFF000
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from dataconv import subsegments  # noqa: E402

ret = open(R + '/disc/SCPS_150.88', 'rb').read()
img = open(R + '/build/SCPS_150.88.img', 'rb').read()


def placed():
    """(object, section) -> (address, size) from the map; vtable sections summed per object."""
    out, cur = {}, None
    for line in open(R + '/build/SCPS_150.88.map'):
        m = re.match(r'\s*(\.rodata|\.gnu\.linkonce\.d\.\S+)\s*$', line)
        if m:
            cur = m.group(1)
            continue
        m = re.match(r'\s*(\.rodata|\.gnu\.linkonce\.d\.\S+)?\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+build/src/(\w+)\.cpp\.o', line)
        if m:
            sec = m.group(1) or cur
            cur = None
            if not sec:
                continue
            key = (m.group(4), '.rodata' if sec == '.rodata' else 'vt')
            a, n = int(m.group(2), 16), int(m.group(3), 16)
            if n == 0:
                continue
            if key in out:                      # several vtables: from the first to the end of the last
                a0, n0 = out[key]
                out[key] = (min(a0, a), max(a0 + n0, a + n) - min(a0, a))
            else:
                out[key] = (a, n)
        else:
            cur = None
    return out


def main():
    want = set(a for a in sys.argv[1:] if not a.startswith('-'))
    verbose = '-v' in sys.argv
    subs = subsegments()
    pl = placed()
    bad = []
    for k, (a, t, n, i) in enumerate(subs):
        if t not in ('.rodata', '.data') or (want and n not in want):
            continue
        end = subs[k + 1][0]
        key = (n, '.rodata' if t == '.rodata' else 'vt')
        at, size = pl.get(key, (None, 0))
        if at is None:
            ok, why = False, 'nothing placed'
        else:
            ours = img[at - 0x100000:at - 0x100000 + size]
            theirs = ret[a - OFF:a - OFF + size]
            gap = ret[a - OFF + size:end - OFF]
            if size > end - a:
                ok, why = False, f'{size:#x} bytes, piece is {end - a:#x}'
            elif ours != theirs:
                d = next(j for j in range(size) if ours[j] != theirs[j])
                ok, why = False, f'differs at {a + d:#x} (+{d:#x}): ours {ours[d:d + 8].hex()} retail {theirs[d:d + 8].hex()}'
            elif any(gap):
                ok, why = False, f'{size:#x} bytes, retail has {end - a - size:#x} more nonzero bytes after'
            else:
                ok, why = True, f'{size:#x} bytes ok'
        if not ok:
            bad.append(n)
        if verbose or not ok:
            print(f'{n:22} {key[1]:7} {a:#x}-{end:#x}: {why}')
    if bad:
        print('bad:', ' '.join(sorted(set(bad))))


if __name__ == '__main__':
    main()
