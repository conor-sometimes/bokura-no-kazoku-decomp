#!/usr/bin/env python3
"""Per-unit data of the C++ units: vtables, RTTI names, .rodata range, .data refs (docs/units.md).

Reads a full disassembly (every unit as asm, so matched functions' xrefs are seen too) and the
yaml's unit list. Prints one line per unit:

  unit  text-start  vtables (addr..end, classes)  rodata range  .data refs  todo  blocked

`todo` counts the unit's functions still INCLUDE_ASM'd (asm/nonmatchings/<unit>), `blocked` those
of them that store a vtable pointer or call through one (an `lh` of the {delta, index, pfn} entry
then `jalr`). With --yaml it prints the per-unit vtable subsegments for config/SCPS_150.88.yaml.

Full disassembly, once (scratch, not committed):
  sed -e 's/, cpp, /, asm, /' -e 's#base_path: ..#base_path: ../..#' -e 's#asm_path: asm#asm_path: build/full/asm#' \\
      -e 's#ld_script_path: build/#ld_script_path: build/full/#' -e 's#build/undefined_#build/full/undefined_#' \\
      -e 's#asset_path: assets#asset_path: build/full/assets#' config/SCPS_150.88.yaml > build/full/full.yaml
  .venv/bin/python -m splat split build/full/full.yaml
  python3 -I scripts/data_units.py disc/SCPS_150.88 build/full/asm [--yaml]
"""
import glob
import os
import re
import struct
import sys

VT = (0x2BFA40, 0x2C2C98)        # vtables: tail of .data (the .gnu.linkonce.d sections)
DATA = (0x29F280, 0x2BFA40)      # the rest of .data
RODATA = (0x2D1800, 0x2EB680)
RODATA_GAME_END = 0x2E1F60       # C-style code and libraries from here on
TEXT_END = 0x1E91B8              # end of the C++ units
OFF = 0xFF000                    # file offset = vram - OFF


def load_units(yaml_path):
    units = []
    for line in open(yaml_path):
        m = re.match(r"\s*- \[0x([0-9A-F]+), (cpp|asm), (\w+)\]", line)
        if m and m.group(3) not in ("crt0",):
            units.append((int(m.group(1), 16) + OFF, m.group(3), m.group(2)))
    return units


SYMS = {}   # named symbols (vtables: _vt$<class>) -> address
for _p in ("config/symbol_addrs.txt", "config/vtables.txt"):
    for _l in open(_p):
        _m = re.match(r"\s*([\w$.]+)\s*=\s*0x([0-9A-Fa-f]+)", _l)
        if _m:
            SYMS[_m.group(1)] = int(_m.group(2), 16)


def load_funcs(asm_dir):
    """name -> (addr, refs, lines) for every function in the full disassembly."""
    funcs = {}
    for p in glob.glob(os.path.join(asm_dir, "*.s")):
        cur = None
        for line in open(p):
            m = re.match(r"glabel (\S+)", line)
            if m and not m.group(1).startswith(".L"):
                cur = [None, set(), []]
                funcs[m.group(1)] = cur
                continue
            if cur is None:
                continue
            m = re.search(r"/\* \w+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+(\S.*)", line)
            if not m:
                continue
            if cur[0] is None:
                cur[0] = int(m.group(1), 16)
            cur[2].append(m.group(2))
            for s in re.findall(r"%lo\(([\w$]+)\)", line):
                mm = re.search(r"([0-9A-F]{6,8})$", s)
                a = SYMS.get(s, int(mm.group(1), 16) if mm else None)
                if a is not None:
                    cur[1].add(a)
    return {n: f for n, f in funcs.items() if f[0] is not None}


def is_vcall(lines):
    for i, l in enumerate(lines):
        if l.startswith("jalr") and any(x.startswith("lh ") for x in lines[max(0, i - 6):i]):
            return True
    return False


def main():
    rom = open(sys.argv[1], "rb").read()
    w = lambda va: struct.unpack_from("<I", rom, va - OFF)[0]
    funcs = load_funcs(sys.argv[2])
    units = load_units("config/SCPS_150.88.yaml")
    starts = [u[0] for u in units] + [TEXT_END]

    def unit_of(a):
        for i in range(len(units)):
            if starts[i] <= a < starts[i + 1]:
                return i
        return None

    byaddr = {f[0]: (n, f) for n, f in funcs.items()}

    # Vtables, structurally: {0, __tf}, entries {delta|index, pfn}, null entry.
    vts, a = [], VT[0]
    while a < VT[1]:
        assert w(a) == 0 and w(a + 4) in byaddr, hex(a)
        b = a + 8
        while w(b) or w(b + 4):
            b += 8
        vts.append((a, b + 8))
        a = b + 8

    def rtti(tf):
        for l in byaddr[tf][1][2]:
            mm = re.match(r"addiu\s+\$(?:a1|5), \$(?:a1|5), %lo\(D_0*([0-9A-F]+)\)", l)
            if mm:
                s = int(mm.group(1), 16)
                return s, rom[s - OFF:rom.index(b"\0", s - OFF)].decode("latin1")
        return None, None

    # Owner unit of each vtable: the unit named after its class (or listing it in the yaml
    # comment), else the unit of the lowest game function that uses it (ctor/dtor/virtual).
    also = {}
    for line in open("config/SCPS_150.88.yaml"):
        m = re.match(r"\s*- \[0x[0-9A-F]+, cpp, (\w+)\]\s*#\s*also (.*)", line)
        if m:
            for c in m.group(2).split():
                also[c] = m.group(1)
    uidx = {u[1]: i for i, u in enumerate(units)}
    vt_unit = {}
    for v, e in vts:
        n = rtti(w(v + 4))[1]
        cls = re.sub(r"^\d+", "", n) if n and not n.startswith("t") else n
        if cls in uidx:
            vt_unit[v] = uidx[cls]
            continue
        if cls in also:
            vt_unit[v] = uidx[also[cls]]
            continue
        c = [f[0] for f in funcs.values() if v in f[1] and f[0] < TEXT_END]
        c += [w(x + 4) for x in range(v + 8, e, 8) if w(x + 4) < TEXT_END and w(x + 4) in byaddr]
        c = [x for x in c if x >= starts[0]]
        vt_unit[v] = unit_of(min(c)) if c else None

    # The tail (C-style code and libraries from CAppMain on) is one block: everything after the
    # last game unit's vtables (CSndWorkReal's own vtable is out there too, emitted by a library).
    last_unit = len(units) - 2
    tail_start = max(e for v, e in vts if vt_unit[v] == last_unit)

    # Blocks: vtables are in unit order, so a unit's block starts where the minimum unit of all
    # later vtables rises (an out-of-place attribution joins the block around it).
    block_of, cur, sufmin, m = {}, None, {}, len(units)
    for v, _ in reversed(vts):
        if v < tail_start and vt_unit[v] is not None:
            m = min(m, vt_unit[v])
            sufmin[v] = m
    for v, _ in vts:
        if v >= tail_start:
            block_of[v] = "tail"
            continue
        if v in sufmin and (cur is None or sufmin[v] > cur):
            cur = sufmin[v]
        block_of[v] = cur

    if "--syms" in sys.argv:
        # config/vtables.txt: _vt$<class> for each vtable, __tf<class> for its typeinfo function.
        print("// Vtables and typeinfo functions, named from their RTTI names (scripts/data_units.py --syms).")
        print("// With these, C++ can store a vptr or call through one before the unit's data comes from")
        print("// its object (docs/units.md).")
        seen = {}
        for v, e in vts:
            n = rtti(w(v + 4))[1]
            seen.setdefault(n, []).append(v)
        for v, e in vts:
            n = rtti(w(v + 4))[1]
            tf = w(v + 4)
            if not n or len(seen[n]) > 1:
                print(f"// {v:#x}: {n} has {len(seen.get(n, []))} vtables, not named")
                continue
            print(f"_vt${n} = 0x{v:08x}; // size:0x{e - v:X}")
            print(f"__tf{n} = 0x{tf:08x}; // type:func")
        return

    todo = {}
    for p in glob.glob("asm/nonmatchings/*/*.s"):
        todo.setdefault(os.path.basename(os.path.dirname(p)), []).append(os.path.basename(p)[:-2])

    # Every RTTI name: a string that a typeinfo function (linkonce code) passes to __rtti_*.
    rtti_names = {}
    for f in funcs.values():
        if f[0] >= TEXT_END:
            for r in f[1]:
                if RODATA[0] <= r < RODATA_GAME_END:
                    t = rom[r - OFF:rom.index(b"\0", r - OFF)].decode("latin1")
                    if re.fullmatch(r"\d+[A-Za-z_]\w*|t\d+\w+", t):
                        rtti_names[r] = t
    for v, _ in vts:                       # keep only classes without a vtable
        rtti_names.pop(rtti(w(v + 4))[0], None)

    vtset = {v for v, _ in vts}
    rows, ro_end = [], RODATA[0]
    for i, (st, name, kind) in enumerate(units[:-1]):
        fs = [f for f in funcs.values() if starts[i] <= f[0] < starts[i + 1]]
        my_vts = [(v, e) for v, e in vts if block_of[v] == i]
        strs = [(s_, n) for s_, n in (rtti(w(v + 4)) for v, _ in my_vts) if s_ and s_ < RODATA_GAME_END]
        names = [n for _, n in strs]
        # .rodata: from the first item after the previous unit's last RTTI name to the end of
        # this unit's last RTTI name (GCC writes the RTTI names last, at the end of the unit).
        # A unit whose RTTI names lie inside the previous unit's literals is part of that
        # object (the I* interface units, CMapEffObj, ...): merged into the previous row.
        merged = bool(rows) and bool(strs) and min(s_ for s_, _ in strs) < ro_end
        ro_start = (ro_end + 7) & ~7
        if any(rom[ro_end - OFF:ro_start - OFF]):
            print(f"# {name}: nonzero bytes between {ro_end:#x} and {ro_start:#x}", file=sys.stderr)
        for s_, n in strs:
            ro_end = max(ro_end, s_ + len(n) + 1)
        # Typeinfo names of classes without a vtable of their own (bases named by a derived
        # class's typeinfo function) follow the unit's last RTTI name.
        while strs and ((ro_end + 7) & ~7) in rtti_names:
            x = (ro_end + 7) & ~7
            ro_end = x + len(rtti_names[x]) + 1
        dr = sorted({r for f in fs for r in f[1] if DATA[0] <= r < DATA[1]})
        blocked = [fn for fn in todo.get(name, [])
                   if funcs.get(fn) and (funcs[fn][1] & vtset or is_vcall(funcs[fn][2]))]
        if merged:
            p = rows[-1]
            p[1] += "+" + name
            p[2] += my_vts
            p[3] += names
            p[5] = ro_end
            p[6] = sorted(set(p[6]) | set(dr))
            p[7] += len(todo.get(name, []))
            p[8] += blocked
            continue
        rows.append([st, name, my_vts, names, ro_start, ro_end, dr, len(todo.get(name, [])), blocked])

    if "--yaml" in sys.argv:
        for st, name, my_vts, *_ in rows:
            if my_vts:
                n = name.split("+")
                c = f"   # also {' '.join(n[1:])}" if n[1:] else ""
                print(f"      - [0x{my_vts[0][0] - OFF:X}, data, vt_{n[0]}]{c}")
        tail = [v for v, _ in vts if block_of[v] == "tail"]
        print(f"      - [0x{tail[0] - OFF:X}, data, vt_tail]   # C-style code and libraries")
        for st, name, my_vts, names, ro_start, *_ in rows:
            n = name.split("+")
            c = f"   # also {' '.join(n[1:])}" if n[1:] else ""
            print(f"      - [0x{ro_start - OFF:X}, rodata, ro_{n[0]}]{c}")
        print(f"      - [0x{(ro_end + 7 & ~7) - OFF:X}, rodata, ro_tail]   # C-style code and libraries, .gcc_except_table")
        return
    total = 0
    for st, name, my_vts, names, ro_start, ro_e, dr, nt, blocked in rows:
        vt = f"{my_vts[0][0]:X}-{my_vts[-1][1]:X}" if my_vts else "-"
        dd = f"{len(dr)}@{min(dr):X}-{max(dr):X}" if dr else "-"
        total += len(blocked)
        print(f"{name:20} {st:06X} vt {vt} ({' '.join(names)}) ro {ro_start:X}-{ro_e:X} "
              f"data {dd} todo {nt} blocked {len(blocked)}")
        if "-v" in sys.argv and blocked:
            print("    " + " ".join(blocked))
    print(f"# {total} INCLUDE_ASM'd functions store or call through a vtable")
    for v, _ in vts:
        if block_of[v] not in ("tail", None) and vt_unit[v] not in (None, block_of[v]):
            print(f"# vtable {v:#x} ({rtti(w(v + 4))[1]}) attributed to {units[vt_unit[v]][1]}, "
                  f"placed in {units[block_of[v]][1]}'s block")
        if vt_unit[v] is None and block_of[v] != "tail":
            print(f"# vtable {v:#x} ({rtti(w(v + 4))[1]}) has no game user, in {units[block_of[v]][1]}'s block")

if __name__ == "__main__":
    main()
