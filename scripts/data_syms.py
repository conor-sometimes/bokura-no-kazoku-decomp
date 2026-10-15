#!/usr/bin/env python3
"""Address definitions for asm references into data that a C++ unit now emits itself.

When a unit's vtables or .rodata come from its object (`.data`/`.rodata` subsegments in the
yaml, docs/units.md), splat counts the symbols in those pieces as defined by the C++ and leaves
them out of undefined_syms_auto.txt. But the compiler names them differently (`_vt$12CMenuProcess`)
or not at all (`$LC0` for an RTTI name), so asm that still uses `D_002DFDA0` (a typeinfo function,
another unit's inlined constructor) would not link. This writes `D_X = 0xX;` for every such
reference that no asm file defines. Run after splat:

  python3 -I scripts/data_syms.py config/SCPS_150.88.yaml asm > build/data_syms_auto.txt
"""
import glob
import os
import re
import sys


def c_data_ranges(yaml_path):
    """vram ranges of the yaml's `.data`/`.rodata` (C-owned) subsegments of segment main."""
    subs, vram_off = [], None
    for line in open(yaml_path):
        m = re.match(r"\s*vram: 0x([0-9A-Fa-f]+)", line)
        if m and vram_off is None:
            vram_off = int(m.group(1), 16) - 0x1000
        m = re.match(r"\s*- \[0x([0-9A-Fa-f]+), ([.\w]+)", line) or \
            re.match(r"\s*- \{start: 0x([0-9A-Fa-f]+), type: ([.\w]+)", line)
        if m:
            subs.append((int(m.group(1), 16), m.group(2)))
    out = []
    for (a, t), (b, _) in zip(subs, subs[1:]):
        if t in (".data", ".rodata"):
            out.append((a + vram_off, b + vram_off))
    return out


def main():
    ranges = c_data_ranges(sys.argv[1])
    refs, defs = set(), set()
    for p in glob.glob(os.path.join(sys.argv[2], "**", "*.s"), recursive=True):
        for line in open(p):
            m = re.match(r"\s*(?:glabel|dlabel|alabel)\s+((?:D|jtbl)_[0-9A-F]+)|\s*((?:D|jtbl)_[0-9A-F]+):", line)
            if m:
                defs.add(m.group(1) or m.group(2))
                continue
            refs.update(re.findall(r"\b((?:D|jtbl)_[0-9A-F]{6,8})\b", line.split("*/")[-1]))
    # C++ references too (lane L2: the typeinfo functions pass RTTI names that live in converted
    # units' .rodata, and once matched no asm mentions them any more)
    for p in glob.glob("src/**/*.cpp", recursive=True):
        refs.update(re.findall(r"\b((?:D|jtbl)_[0-9A-F]{6,8})\b", open(p).read()))
    for name in sorted(refs - defs):
        a = int(name.split("_")[-1], 16)
        if any(lo <= a < hi for lo, hi in ranges):
            print(f"{name} = 0x{a:X};")


if __name__ == "__main__":
    main()
