#!/usr/bin/env python3
"""Wrap the linked, flat memory image in SCPS_150.88's ELF container.

Usage: mkelf.py IMAGE OUT

IMAGE is `objcopy -O binary` of the linked build: every loaded byte from
0x100000 (.text) to the end of .gcc_except_table, padding included. This
script writes the ELF header, program headers, the empty non-loaded sections
(.mdebug.eabi64, .DVP.ovlytab/.ovlystrtab), .shstrtab and the section header
table exactly where Sony's linker put them. The tables below are the retail
ELF's own header values (readelf -lS), not its contents.
"""
import struct
import sys

IMAGE_VRAM = 0x100000
IMAGE_OFFSET = 0x1000          # file offset of 0x100000; every loaded section has off = vram - 0xFF000
ENTRY = 0x100008
E_FLAGS = 0x20924001           # noreorder, 5900, eabi64, mips3

SHT_PROGBITS, SHT_STRTAB, SHT_NOBITS = 1, 3, 8
SHT_MIPS_REGINFO = 0x70000006
SHT_DVP_OVERLAY_TABLE = 0x7FFFF420
W, A, X, GPREL = 0x1, 0x2, 0x4, 0x10000000

# name, type, flags, addr, offset, size, link, info, align, entsize
SECTIONS = [
    ("",                  0,                     0,         0,        0,        0,        0,  0, 0,     0),
    (".text",             SHT_PROGBITS,          A | X,     0x100000, 0x001000, 0x19F230, 0,  0, 0x40,  0),
    (".vutext",           SHT_PROGBITS,          A | X,     0x29F230, 0x1A0230, 0,        0,  0, 1,     0),
    (".ctors",            SHT_PROGBITS,          W | A,     0x29F230, 0x1A0230, 0x10,     0,  0, 4,     0),
    (".dtors",            SHT_PROGBITS,          W | A,     0x29F240, 0x1A0240, 0xC,      0,  0, 4,     0),
    (".reginfo",          SHT_MIPS_REGINFO,      A,         0x29F24C, 0x1A024C, 0x18,     0,  0, 4,     1),
    (".data",             SHT_PROGBITS,          W | A,     0x29F280, 0x1A0280, 0x23A18,  0,  0, 0x40,  0),
    (".eh_frame",         SHT_PROGBITS,          W | A,     0x2C2C98, 0x1C3C98, 0x904,    0,  0, 8,     0),
    (".vudata",           SHT_PROGBITS,          W | A,     0x2C3600, 0x1C4600, 0xE200,   0,  0, 0x100, 0),
    (".rodata",           SHT_PROGBITS,          A,         0x2D1800, 0x1D2800, 0x19E30,  0,  0, 0x10,  0),
    (".gcc_except_table", SHT_PROGBITS,          W | A,     0x2EB680, 0x1EC680, 0x7C,     0,  0, 4,     0),
    (".sbss",             SHT_NOBITS,            W | A | GPREL, 0x2EB700, 0x1EC700, 0x224, 0, 0, 8,     0),
    (".bss",              SHT_NOBITS,            W | A,     0x2EB980, 0x1EC75C, 0x139B2C, 0,  0, 0x40,  0),
    (".vubss",            SHT_NOBITS,            W | A,     0x4254AC, 0x1EC75C, 0,        0,  0, 1,     0),
    (".mdebug.eabi64",    SHT_PROGBITS,          0,         0,        0x1EC75C, 0,        0,  0, 1,     0),
    (".DVP.ovlytab",      SHT_DVP_OVERLAY_TABLE, W,         0,        0x1EC75C, 0,        16, 0, 4,     0xC),
    (".DVP.ovlystrtab",   SHT_STRTAB,            W,         0,        0x1EC75C, 7,        0,  0, 1,     0),
    (".shstrtab",         SHT_STRTAB,            0,         0,        0x1EC763, None,     0,  0, 1,     0),
]
# Sony's ld keeps the names of the stripped .symtab/.strtab in .shstrtab.
SHSTRTAB_NAMES = [".symtab", ".strtab", ".shstrtab"] + [s[0] for s in SECTIONS[1:-1]]

PT_LOAD, PT_MIPS_REGINFO = 1, 0x70000000
PF_X, PF_W, PF_R = 1, 2, 4
# type, offset, vaddr, filesz, memsz, flags, align
SEGMENTS = [
    (PT_MIPS_REGINFO, 0x1A024C, 0x29F24C, 0x18,     0x18,     PF_R,               4),
    (PT_LOAD,         0x001000, 0x100000, 0x19F264, 0x19F264, PF_R | PF_W | PF_X, 0x1000),
    (PT_LOAD,         0x1A0280, 0x29F280, 0x4C47C,  0x18622C, PF_R | PF_W,        0x1000),
]
SHDR_ALIGN = 4


def main():
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    image = open(sys.argv[1], "rb").read()
    loaded = [s for s in SECTIONS if s[1] not in (0, SHT_NOBITS) and s[3]]
    image_end = max(s[3] + s[5] for s in loaded)
    if len(image) != image_end - IMAGE_VRAM:
        sys.exit(f"mkelf: image is 0x{len(image):X} bytes, expected 0x{image_end - IMAGE_VRAM:X} "
                 f"(0x{IMAGE_VRAM:X}-0x{image_end:X}); check the linker script layout")

    shstrtab = bytearray(b"\0")
    name_off = {}
    for n in SHSTRTAB_NAMES:
        name_off[n] = len(shstrtab)
        shstrtab += n.encode() + b"\0"
    name_off[""] = 0

    out = bytearray(IMAGE_OFFSET)
    out += image
    shstr_off = SECTIONS[-1][4]
    out += bytes(shstr_off - len(out))   # .DVP.ovlystrtab's 7 bytes are zero too
    out += shstrtab
    shoff = (len(out) + SHDR_ALIGN - 1) & -SHDR_ALIGN
    out += bytes(shoff - len(out))
    for name, typ, flags, addr, off, size, link, info, align, ent in SECTIONS:
        if size is None:
            size = len(shstrtab)
        out += struct.pack("<10I", name_off[name], typ, flags, addr, off, size, link, info, align, ent)

    phoff = 0x34
    ehdr = struct.pack("<16sHHIIIIIHHHHHH",
                       b"\x7fELF\x01\x01\x01" + bytes(9), 2, 8, 1, ENTRY, phoff, shoff, E_FLAGS,
                       0x34, 0x20, len(SEGMENTS), 0x28, len(SECTIONS), len(SECTIONS) - 1)
    phdrs = b"".join(struct.pack("<8I", t, o, v, v, fs, ms, fl, al) for t, o, v, fs, ms, fl, al in SEGMENTS)
    out[0:len(ehdr) + len(phdrs)] = ehdr + phdrs
    open(sys.argv[2], "wb").write(out)


if __name__ == "__main__":
    main()
