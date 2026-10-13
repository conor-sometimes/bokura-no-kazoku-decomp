#!/usr/bin/env python3
"""Guess the game's C++ translation units from vtable order (evidence for the splat split).

GCC 2.96 writes each unit's vtables into its .data, units in link order, and the vtables of
one unit in reverse order of their classes. So, walking the vtables (0x2BFA40 to the end of
.data) in address order and taking for each the lowest game function that uses it (ctor,
dtor or a virtual method), a new unit starts only at a new high-water mark; lower values
belong to the current unit and can lower its start. The class names come from RTTI: word 1
of a vtable is the typeinfo function, which passes the mangled name string in $a1.

Limits: a unit can begin before its first class's lowest function (free functions, statics),
and units without vtables (the C-style code from CAppMain on) are not found. A cross-check
against .rodata order (each unit's literals are contiguous) is printed at the end.

  python3 -I scripts/find_units.py disc/SCPS_150.88 asm/text.s [more .s ...]
"""
import re
import struct
import sys

DATA_VT = (0x2BFA40, 0x2C2C98)   # vtable area: tail of .data
RODATA = (0x2D1800, 0x2EB680)
GAME_END = 0x260000              # linkonce code (inline ctors, typeinfo functions) lies beyond


def main():
    rom = open(sys.argv[1], "rb").read()
    w = lambda va: struct.unpack_from("<I", rom, va - 0xFF000)[0]
    text = "".join(open(p).read() for p in sys.argv[2:])
    funcs, cur = [], None
    for line in text.split("\n"):
        m = re.match(r"glabel (\S+)", line)
        if m and not m.group(1).startswith(".L"):
            cur = [m.group(1), None, set()]
            funcs.append(cur)
            continue
        if cur is None:
            continue
        m = re.search(r"/\* \w+ ([0-9A-F]{8}) ", line)
        if m and cur[1] is None:
            cur[1] = int(m.group(1), 16)
        for s in re.findall(r"%lo\((\w+)\)", line):
            mm = re.search(r"([0-9A-F]{6,8})$", s)
            if mm:
                cur[2].add(int(mm.group(1), 16))
    funcs = [f for f in funcs if f[1] is not None]
    starts = {f[1] for f in funcs}

    vts = sorted({r for f in funcs for r in f[2] if DATA_VT[0] <= r < DATA_VT[1]})
    key = {}
    for i, v in enumerate(vts):
        end = vts[i + 1] if i + 1 < len(vts) else DATA_VT[1]
        c = [f[1] for f in funcs if v in f[2] and f[1] < GAME_END]
        c += [w(a) for a in range(v, end, 4) if w(a) in starts and w(a) < GAME_END]
        if c:
            key[v] = min(c)

    tus, hw = [], -1
    for v in vts:
        if v not in key:
            continue
        a = key[v]
        if a > hw:
            tus.append(a)
            hw = a
        elif len(tus) < 2 or a >= tus[-2]:
            tus[-1] = min(tus[-1], a)
            while len(tus) >= 2 and tus[-1] <= tus[-2]:
                tus[-2] = tus[-1]
                tus.pop()
        else:
            print(f"# outlier vtable {v:#x} (key {a:#x}) ignored", file=sys.stderr)

    def unit_of(a):
        k = -1
        for i, t in enumerate(tus):
            if a >= t:
                k = i
        return k

    def tf_name(tf):
        m = re.search(r"glabel func_%08X\n(.*?)\.size" % tf, text, re.S)
        if not m:
            return None
        mm = re.search(r"addiu\s+\$a1, \$a1, %lo\((?:D_)?0*([0-9A-F]+)\)", m.group(1))
        if not mm:
            return None
        off = int(mm.group(1), 16) - 0xFF000
        return rom[off:rom.index(b"\0", off)].decode("latin1")

    names = {}
    for v in vts:
        if v in key:
            n = tf_name(w(v + 4))
            names.setdefault(unit_of(key[v]), []).append((key[v], n))

    for i, t in enumerate(tus):
        cls = [n for _, n in sorted(names.get(i, [])) if n]
        print(f"{t:#08x} {' '.join(cls)}")

    # Cross-check: .rodata refs of consecutive units must not interleave.
    units = {}
    for f in sorted(funcs, key=lambda f: f[1]):
        u = unit_of(f[1])
        if u >= 0 and f[1] < GAME_END:
            units.setdefault(u, []).append((f[1], [r for r in f[2] if RODATA[0] <= r < RODATA[1]]))
    for u in sorted(units):
        nxt = [r for _, rr in units.get(u + 1, []) for r in rr]
        if nxt:
            late = [hex(a) for a, rr in units[u] if rr and max(rr) > min(nxt)]
            if late:
                print(f"# rodata overlap: unit {tus[u]:#x} funcs {late} use the next unit's literals", file=sys.stderr)


if __name__ == "__main__":
    main()
