#!/usr/bin/env python3
"""structs.py: recover class layouts from how the code uses `this`.

  tools/bk/structs.py [--elf build/SCPS_150.88.elf] [--out build/bk/structs] [CLASS...]

Decodes every function of the built ELF (bytes identical to retail; its symbol table gives the
names) and follows `this` ($a0 on entry, through moves, s-registers, stack spills and
`addiu rX, this, k` sub-objects) with a linear pass. Each load or store through it is a field
access: offset, width, kind (int, float, 64-bit, 128-bit), signed or unsigned, read or written,
and by which method. Also:
  - vptr offset: a store of a `_vt$Class` address through `this` (constructors);
  - sizeof: `new(N)` whose result goes straight into a constructor;
  - pointer fields: a field later used as a base address; a virtual call through it records the
    slot (vtable entries are 8 bytes: delta, function; slot n is at 8 + 8n).
Methods are assigned to classes by mangled name (`F__6CClass...`, `_$_6CClass`) and, for unnamed
`func_` entries, by vtable membership (the class with the smallest vtable that lists it).
The pass ignores control flow, so a register reused on another path can add a stray access;
accesses seen in several methods are the reliable ones.

Writes OUT/<Class>.txt (field table and a C++ skeleton) and OUT/index.txt.
"""
import argparse, collections, os, re, struct, sys

LOADS = {0x20: (1, "s"), 0x21: (2, "s"), 0x23: (4, "s"), 0x24: (1, "u"), 0x25: (2, "u"),
         0x27: (4, "u"), 0x37: (8, ""), 0x1E: (16, ""), 0x31: (4, "f"),
         0x22: (4, "l"), 0x26: (4, "l"), 0x1A: (8, "l"), 0x1B: (8, "l")}
STORES = {0x28: 1, 0x29: 2, 0x2B: 4, 0x3F: 8, 0x1F: 16, 0x39: (4, "f"),
          0x2A: 4, 0x2E: 4, 0x2C: 8, 0x2D: 8}
CALLER_SAVED = set(range(1, 16)) | {24, 25}
SP, RA = 29, 31


def s16(x):
    return x - 0x10000 if x & 0x8000 else x


def read_elf(path):
    b = open(path, "rb").read()
    shoff, = struct.unpack_from("<I", b, 0x20)
    shnum, = struct.unpack_from("<H", b, 0x30)
    sh = [struct.unpack_from("<10I", b, shoff + 40 * i) for i in range(shnum)]
    secs = [(s[3], s[4], s[5], s[1]) for s in sh]  # addr, offset, size, type
    syms = []
    for s in sh:
        if s[1] != 2:
            continue
        strtab = sh[s[6]]
        for k in range(s[5] // 16):
            nm, val, size, info, _, ndx = struct.unpack_from("<IIIBBH", b, s[4] + 16 * k)
            if not nm or ndx == 0 or ndx >= len(sh):
                continue
            o = strtab[4] + nm
            name = b[o:b.index(b"\0", o)].decode("latin1")
            syms.append((val, size, info & 0xF, name, ndx))

    def word(addr):
        for a, off, size, typ in secs:
            if typ != 8 and a <= addr < a + size and a:
                return struct.unpack_from("<I", b, off + addr - a)[0]
        return None
    return syms, word


def demangle_class(name):
    """Class of a GCC 2.x mangled member name, or None."""
    m = re.match(r"_\$_(\d+)", name)
    if m:
        n = int(m.group(1))
        return name[m.end():m.end() + n]
    m = re.search(r"__(\d+)([A-Za-z_])", name)
    if m:
        n = int(m.group(1))
        start = m.start(2)
        return name[start:start + n]
    return None


def is_ctor(name):
    return re.match(r"__\d+[A-Za-z_]", name) is not None


class Facts:
    def __init__(self):
        self.fields = collections.defaultdict(lambda: collections.defaultdict(set))  # cls -> (off,w,kind,rw) -> fns
        self.ptrs = collections.defaultdict(lambda: collections.defaultdict(set))    # cls -> off -> notes
        self.subobj = collections.defaultdict(lambda: collections.defaultdict(set))  # cls -> off -> fns
        self.vptr = collections.defaultdict(set)   # cls -> (off, vtable)
        self.size = collections.defaultdict(set)   # cls -> sizes
        self.methods = collections.defaultdict(set)
        self.bases = collections.defaultdict(set)    # cls -> (offset, base or member class)


def analyse(fn, cls, addr, words, symat, vtables, facts, ctors):
    """One linear pass over a function. State per register: ('this', k) | ('fld', k) |
    ('vt', k) | ('vslot', k, slot_off) | ('const', v) | ('new', size)."""
    reg = {4: ("this", 0)} if cls else {}
    stack = {}
    pending_clobber = False
    hi = {}
    for i, w in enumerate(words):
        pc = addr + 4 * i
        op, rs, rt, rd = w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
        imm = s16(w & 0xFFFF)
        dest, newstate = None, None
        base = reg.get(rs)
        if op in LOADS or op in STORES:
            if op in LOADS:
                width, sg = LOADS[op]
                kind = {"f": "float", "l": "unaligned"}.get(sg, {8: "dword", 16: "qword"}.get(width, "int"))
                if base and base[0] == "this" and cls:
                    off = base[1] + imm
                    facts.fields[cls][(off, width, kind, sg if sg in "su" else "", "r")].add(fn)
                    if op == 0x23 or op == 0x27:
                        newstate = ("fld", off)
                elif base and base[0] == "fld" and imm == 0 and op == 0x23:
                    newstate = ("vt", base[1])
                elif base and base[0] == "vslot" and op in (0x21, 0x23):
                    newstate = base if op == 0x23 else None
                    if op == 0x23 and imm == 4:
                        newstate = ("vfn",) + base[1:]
                elif rs == SP and op in (0x23, 0x37) and imm in stack:
                    newstate = stack[imm]
                if base and base[0] == "fld" and cls:
                    facts.ptrs[cls][base[1]].add(f"deref +{imm:#x}" if imm >= 0 else f"deref {imm:#x}")
                if op != 0x31:
                    dest = rt
            else:
                sz = STORES[op]
                width, kind = (sz if isinstance(sz, int) else sz[0]), ("float" if isinstance(sz, tuple) else None)
                kind = kind or {8: "dword", 16: "qword"}.get(width, "int")
                if op in (0x2A, 0x2E, 0x2C, 0x2D):
                    kind = "unaligned"
                if base and base[0] == "this" and cls:
                    off = base[1] + imm
                    src = reg.get(rt)
                    if op == 0x2B and src and src[0] == "const" and src[1] in vtables:
                        facts.vptr[cls].add((off, vtables[src[1]]))
                    else:
                        facts.fields[cls][(off, width, kind, "", "w")].add(fn)
                elif base and base[0] == "fld" and cls:
                    facts.ptrs[cls][base[1]].add(f"store +{imm:#x}")
                if rs == SP and rt in reg and op in (0x2B, 0x3F, 0x1F):
                    stack[imm] = reg[rt]
        elif op == 0x0F:  # lui
            dest, hi[rt] = rt, (w & 0xFFFF) << 16
            newstate = ("const", hi[rt])
        elif op in (0x09, 0x19):  # addiu / daddiu
            dest = rt
            if base and base[0] == "this":
                newstate = ("this", base[1] + imm)
                if cls and rs != rt and imm:
                    facts.subobj[cls][base[1] + imm].add(fn)
            elif base and base[0] == "const":
                newstate = ("const", (base[1] + imm) & 0xFFFFFFFF)
            elif base and base[0] == "vt":
                newstate = ("vslot", base[1], imm)
            elif rs == 0:
                newstate = ("const", imm & 0xFFFFFFFF)
        elif op == 0 and (w & 63) in (0x21, 0x25, 0x2D):  # addu / or / daddu: moves
            dest = rd
            if rt == 0:
                newstate = reg.get(rs)
            elif rs == 0:
                newstate = reg.get(rt)
        elif op == 3:  # jal: handled after its delay slot, which may set up the arguments
            pending_clobber = ("call", ((pc + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2))
            continue
        elif op == 0 and (w & 63) == 0x09:  # jalr
            fnreg = reg.get(rs)
            if fnreg and fnreg[0] == "vfn" and cls:
                facts.ptrs[cls][fnreg[1]].add(f"vcall slot {(fnreg[2] - 8) // 8}")
            pending_clobber = True
            continue
        else:
            if op == 0 or op == 0x1C:
                dest = rd
            elif op == 0x11 and rs in (0, 1, 2):
                dest = rt
            elif op in (0x08, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x18):
                dest = rt
            if op == 0x0D and base and base[0] == "const":  # ori
                newstate = ("const", base[1] | (w & 0xFFFF))
        if dest:
            if newstate is None:
                reg.pop(dest, None)
            else:
                reg[dest] = newstate
        if pending_clobber:
            # the delay slot has executed: look at the arguments, then clobber caller-saved regs
            result = None
            if isinstance(pending_clobber, tuple):
                target = pending_clobber[1]
                tname = symat.get(target, "")
                a0 = reg.get(4)
                if tname.startswith(("__nw__", "__builtin_new")):
                    result = ("new", a0[1] if a0 and a0[0] == "const" else None)
                elif a0 and a0[0] == "new" and a0[1] and (is_ctor(tname) or target in ctors):
                    c = demangle_class(tname) if is_ctor(tname) else ctors[target]
                    if c:
                        facts.size[c].add(a0[1])
                elif cls and a0 and a0[0] == "this" and (is_ctor(tname) or target in ctors) \
                        and (is_ctor(fn) or addr in ctors):
                    c = demangle_class(tname) if is_ctor(tname) else ctors[target]
                    if c and c != cls:
                        facts.bases[cls].add((a0[1], c))
            for r in CALLER_SAVED:
                reg.pop(r, None)
            if result:
                reg[2] = result
            pending_clobber = False
        if op == 0 and (w & 63) == 0x08 and rs == RA:
            pass  # jr ra: keep going (code after may be another path)


def main():
    p = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    p.add_argument("classes", nargs="*")
    p.add_argument("--elf", default="build/SCPS_150.88.elf")
    p.add_argument("--out", default="build/bk/structs")
    a = p.parse_args()
    syms, word = read_elf(a.elf)
    funcs = sorted({(v, s, n) for v, s, t, n, _ in syms if t == 2})
    symat = {}
    for v, s, t, n, _ in syms:
        symat.setdefault(v, n)
    starts = sorted({v for v, _, _ in funcs})
    vtables = {v: re.sub(r"^\d+", "", n[4:]) for v, s, t, n, _ in syms if n.startswith("_vt$")}
    # vtable membership: function address -> classes whose vtable lists it
    vtsize = {}
    owner = collections.defaultdict(list)
    vtsyms = sorted((v, n) for v, n in ((v, n) for v, s, t, n, _ in syms if n.startswith("_vt$")))
    allstarts = sorted({v for v, *_ in syms})
    for v, n in vtsyms:
        cls = re.sub(r"^\d+", "", n[4:])
        nxt = next((x for x in allstarts if x > v), v + 0x400)
        k, slots = 8, 0
        while v + k + 4 < nxt:
            fnaddr = word(v + k + 4)
            if not fnaddr or fnaddr == 0:
                break
            owner[fnaddr].append(cls)
            slots += 1
            k += 8
        vtsize[cls] = slots
    def body(v, size):
        if size == 0:
            k = starts.index(v)
            size = (starts[k + 1] - v) if k + 1 < len(starts) else 0
        if size <= 0 or size > 0x10000:
            return None
        return [word(v + 4 * i) or 0 for i in range(size // 4)]

    # pass 1: an unnamed function that stores a vtable address through `this` is that class's
    # constructor (or destructor); with several stores (base first) take the biggest vtable
    ctors = {}
    for v, size, name in funcs:
        words = body(v, size)
        if not words:
            continue
        probe = Facts()
        analyse(name, "?", v, words, symat, vtables, probe, {})
        if probe.vptr["?"]:
            ctors[v] = max((t for _, t in probe.vptr["?"]), key=lambda c: vtsize.get(c, 0))
    facts = Facts()
    for v, size, name in funcs:
        words = body(v, size)
        if not words:
            continue
        cls = demangle_class(name)
        how = "name"
        if not cls and v in ctors:
            cls, how = ctors[v], "vptr store"
        if not cls and owner.get(v):
            cls = min(owner[v], key=lambda c: vtsize.get(c, 999))
            how = "vtable"
        if cls and re.match(r"t\d", cls):
            cls = None  # templates: skip
        if cls:
            facts.methods[cls].add((name, how))
        analyse(name, cls, v, words, symat, vtables, facts, ctors)
    os.makedirs(a.out, exist_ok=True)
    want = set(a.classes)
    index = []
    for cls in sorted(set(facts.fields) | set(facts.vptr) | set(facts.size)):
        if want and cls not in want:
            continue
        lines = [f"# {cls}"]
        sizes = sorted(facts.size.get(cls, ()))
        vp = sorted(facts.vptr.get(cls, ()))
        nm = facts.methods.get(cls, set())
        lines.append(f"sizeof: {', '.join(hex(s) for s in sizes) or '?'}   vptr: "
                     f"{', '.join(f'{o:#x} ({t})' for o, t in vp) or '?'}   vtable slots: {vtsize.get(cls, '-')}   "
                     f"methods: {len(nm)} ({sum(1 for _, h in nm if h != 'name')} unnamed, placed by vtable or vptr store)")
        bases = sorted(facts.bases.get(cls, ()))
        if bases:
            lines.append("bases / members built by the constructor: " + ", ".join(f"{c} at {o:#x}" for o, c in bases))
        odd = sorted(n for v, n in ((v, n) for v, _, n in funcs) if ctors.get(v) == cls and demangle_class(n) == cls
                     and not is_ctor(n) and not n.startswith("_$_"))
        if odd:
            lines.append("named methods that store the vptr (constructor or destructor under another name): " + ", ".join(odd))
        lines.append("")
        lines.append("  off  size kind       r/w  methods")
        byoff = collections.defaultdict(list)
        for (off, width, kind, sg, rw), fns in facts.fields[cls].items():
            byoff[off].append((width, kind, sg, rw, fns))
        seen, todo = {cls}, [(o, c) for o, c in bases]
        while todo:  # fields the bases' own methods touch, shifted to where the base sits
            bo, b = todo.pop()
            if b in seen:
                continue
            seen.add(b)
            for (off, width, kind, sg, rw), fns in facts.fields[b].items():
                byoff[bo + off].append((width, kind, sg, rw, {f"[{b}] " + f for f in fns}))
            todo += [(bo + o, c) for o, c in facts.bases.get(b, ())]
        for off in sorted(byoff):
            for width, kind, sg, rw, fns in sorted(byoff[off], key=lambda x: (x[0], x[3])):
                notes = ""
                if off in facts.ptrs[cls]:
                    notes = "  ptr: " + ", ".join(sorted(facts.ptrs[cls][off])[:4])
                lines.append(f"{off:#6x} {width:4d} {kind + ('/' + sg if sg else ''):10s} {rw}  "
                             f"{len(fns):3d}  {', '.join(sorted(fns)[:3])}{' ...' if len(fns) > 3 else ''}{notes}")
        if facts.subobj[cls]:
            lines.append("")
            lines.append("sub-objects / arrays (address taken): " +
                         ", ".join(f"{o:#x}({len(f)})" for o, f in sorted(facts.subobj[cls].items())))
        # skeleton
        lines.append("")
        lines.append(f"// skeleton (types from the widest access; check against the C)")
        lines.append(f"class {cls} {{")
        pos = 0
        vpo = vp[0][0] if vp else None
        end = max([s for s in sizes] + [o + w for o, ws in byoff.items() for w, *_ in ws] + [0])
        for off in sorted(set(byoff) | ({vpo} if vpo is not None else set())):
            if off < pos:
                continue
            if off > pos:
                lines.append(f"    u8 pad{pos:X}[{off - pos:#x}];")
            if off == vpo:
                lines.append(f"    void *__vptr;            // {off:#x}")
                pos = off + 4
                continue
            width, kind, sg, rw, fns = max(byoff[off], key=lambda x: (x[0], len(x[4])))
            ptr = off in facts.ptrs[cls]
            ty = {"float": "f32", "dword": "s64", "qword": "u128", "unaligned": "u32"}.get(kind) or \
                ("void *" if ptr and width == 4 else {1: "s8", 2: "s16", 4: "s32"}[width])
            if kind == "int" and sg == "u":
                ty = "u" + ty[1:]
            lines.append(f"    {ty} m_unk{off:X};{' ' * max(1, 14 - len(ty) - len(f'{off:X}'))}// {off:#x}")
            pos = off + width
        if end > pos:
            lines.append(f"    u8 pad{pos:X}[{end - pos:#x}];")
        lines.append("};")
        open(os.path.join(a.out, cls + ".txt"), "w").write("\n".join(lines) + "\n")
        index.append(f"{cls}\tbases {','.join(c for _, c in bases) or '-'}\tsizeof {','.join(hex(s) for s in sizes) or '?'}\tvptr "
                     f"{','.join(hex(o) for o, _ in vp) or '?'}\tfields {len(byoff)}\tmethods {len(nm)}")
        if want:
            print("\n".join(lines))
    if not want:
        open(os.path.join(a.out, "index.txt"), "w").write("\n".join(index) + "\n")
        print(f"{len(index)} classes -> {a.out}/ (index.txt)")


if __name__ == "__main__":
    sys.exit(main())
