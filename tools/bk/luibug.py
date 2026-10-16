#!/usr/bin/env python3
"""luibug.py: after a build that does not match, look for GNU as 2.10's lui bug and say where.

GNU as 2.10 (in the EE-GCC builds) sometimes assembles a `lui` as a copy of the `lw` that follows
it, depending on where the function lands in its section; a C function that matched can break
after an unrelated change earlier in the same .cpp. The fix is `asm(".p2align 3");` right before
the function (it is 8-aligned anyway, so it emits nothing). This compares the built image with
retail, finds words where retail has a `lui` and ours a load/store to the same register, and
prints the function and unit to fix. tools/bk/mk.sh runs it when the build fails.
"""
import bisect
import os
import re
import struct

R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
TEXT_LO, TEXT_HI = 0x100000, 0x29F230


def main():
    retail = open(f'{R}/disc/SCPS_150.88', 'rb').read()
    built_path = f'{R}/build/SCPS_150.88'
    if not os.path.exists(built_path):
        return
    built = open(built_path, 'rb').read()
    syms = []
    for line in open(f'{R}/build/SCPS_150.88.map', errors='replace'):
        m = re.match(r'\s+0x0*([0-9a-fA-F]+)\s+([A-Za-z_.$][\w.$]*)\s*$', line)
        if m:
            syms.append((int(m.group(1), 16), m.group(2)))
    unit_of = []
    for line in open(f'{R}/build/SCPS_150.88.map', errors='replace'):
        m = re.match(r'\s*\.text\s+0x0*([0-9a-fA-F]+)\s+0x[0-9a-fA-F]+\s+build/src/(\w+)\.cpp\.o', line)
        if m:
            unit_of.append((int(m.group(1), 16), m.group(2)))
    syms.sort()
    unit_of.sort()
    keys, ukeys = [a for a, _ in syms], [a for a, _ in unit_of]
    hits = []
    for va in range(TEXT_LO, TEXT_HI, 4):
        o = va - 0xFF000
        if o + 4 > min(len(retail), len(built)):
            break
        x, y = struct.unpack_from('<I', retail, o)[0], struct.unpack_from('<I', built, o)[0]
        if x == y:
            continue
        # retail lui rt; ours a load/store (lw, sw, lwc1, ld, lq, ...) whose rt is the same register number
        if x >> 26 == 0x0F and (y >> 26) in (0x1E, 0x1F, 0x20, 0x21, 0x23, 0x24, 0x25, 0x27, 0x28, 0x29, 0x2B, 0x31, 0x35, 0x37, 0x39, 0x3D, 0x3F) \
                and ((x >> 16) & 31) == ((y >> 16) & 31):
            j = bisect.bisect_right(keys, va) - 1
            u = bisect.bisect_right(ukeys, va) - 1
            hits.append((va, syms[j][1] if j >= 0 else '?', unit_of[u][1] if u >= 0 else '?'))
    for va, name, unit in hits:
        print(f'GNU as lui bug at 0x{va:X} in {name} ({unit}.cpp): put asm(".p2align 3"); right before it')
    if not hits:
        print('luibug: no lui->load pattern among the differing words')


if __name__ == '__main__':
    main()
