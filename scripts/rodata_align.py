#!/usr/bin/env python3
"""Give splat's per-symbol .rodata files (INCLUDE_RODATA, docs/units.md) their alignment.

splat writes asm/nonmatchings/<unit>/D_XXXXXXXX.s without the `.align` that preceded the symbol in
the original compile; when the literal before it now comes from the compiler (a string ends where
it ends, not padded), the symbol would land too early. Every such file gets `.align N` for the
largest power of two up to 8 that divides its address: a no-op when the previous bytes already end
there. Run after splat: python3 -I scripts/rodata_align.py asm
"""
import glob
import os
import re
import sys

for p in glob.glob(os.path.join(sys.argv[1], "nonmatchings", "*", "*.s")):
    m = re.fullmatch(r"(?:D|jtbl)_([0-9A-F]{8})\.s", os.path.basename(p))
    if not m:
        continue
    a = int(m.group(1), 16)
    n = 3 if a % 8 == 0 else 2 if a % 4 == 0 else 1 if a % 2 == 0 else 0
    s = open(p).read()
    if ".align" in s.split("glabel", 1)[0]:
        continue
    s = s.replace(".section .rodata\n", f".section .rodata\n.align {n}\n", 1)
    open(p, "w").write(s)
