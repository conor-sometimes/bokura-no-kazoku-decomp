#!/usr/bin/env python3
"""xap.py: list or extract Bokura no Kazoku .XAP archives.

  tools/xap.py list ARCHIVE...
  tools/xap.py extract ARCHIVE... -o OUTDIR [--sjis]

Layout (little-endian), from the game's loader (0x249BF0) and decompressor (0x249958):
  0x00 "XAPF", file size, offset of the BODY chunk minus 0x10, BODY size
  0x10 "FILE", chunk size, ?, entry count, then per entry (0x20 bytes):
       name offset (from 0x18), type (1 = compressed file), data offset (absolute),
       unpacked size, packed size, timestamp: day u8, month u8, year u16, sec*1000+ms u16,
       minute u8, hour u8
  names (NUL-terminated), then "BODY" and the packed data.
Nested archives (entries that are XAPF themselves) become folders.
--sjis also writes NAME.utf8.txt next to each .txt/.mes file (text is Shift-JIS).
"""
import argparse, os, struct, sys


def unpack(src, pos, size):
    """The game's LZ: MSB-first flag bits. 0 = literal; 10 = short match, offset byte
    (0 ends the stream); 11 = long match, offset byte plus 4 bits. Length 2+ in gamma code."""
    out = bytearray()
    flags = mask = 0

    def bit():
        nonlocal flags, mask, pos
        if mask == 0:
            flags, mask, pos = src[pos], 0x80, pos + 1
        b = flags & mask
        mask >>= 1
        return 1 if b else 0

    while len(out) < size:
        if not bit():
            out.append(src[pos])
            pos += 1
            continue
        if bit():
            off = src[pos] - 256
            pos += 1
            for _ in range(4):
                off = off * 2 + bit()
            off -= 0xFF
        else:
            if src[pos] == 0:
                break
            off = src[pos] - 256
            pos += 1
        n = 1
        while bit():
            n = n * 2 + bit()
        for _ in range(n + 1):
            out.append(out[off])  # off is negative: relative to the end
    return bytes(out)


def entries(b):
    if b[:4] != b"XAPF" or b[0x10:0x14] != b"FILE":
        raise ValueError("not an XAPF archive")
    count, = struct.unpack_from("<I", b, 0x1C)
    for i in range(count):
        e = 0x20 + 0x20 * i
        noff, typ, doff, usize, psize = struct.unpack_from("<5I", b, e)
        day, mon, year, ms, mi, hr = struct.unpack_from("<BBHHBB", b, e + 0x14)
        name = b[0x18 + noff:b.index(b"\0", 0x18 + noff)].decode("ascii", "replace")
        stamp = f"{year:04d}-{mon:02d}-{day:02d} {hr:02d}:{mi:02d}:{ms // 1000:02d}"
        yield name, typ, doff, usize, psize, stamp


def main():
    p = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    p.add_argument("cmd", choices=["list", "extract"])
    p.add_argument("archives", nargs="+")
    p.add_argument("-o", "--out", default="xap-out")
    p.add_argument("--sjis", action="store_true")
    a = p.parse_args()
    bad = 0

    def walk(b, base):
        nonlocal bad
        for name, typ, doff, usize, psize, stamp in entries(b):
            data = unpack(b, doff, usize) if typ == 1 else b[doff:doff + usize]
            if len(data) != usize:
                print(f"{base}/{name}: got {len(data)} of {usize} bytes", file=sys.stderr)
                bad += 1
            if data[:4] == b"XAPF":  # nested archive: a folder
                if a.cmd == "list":
                    print(f"{base}/{name}/\t{typ}\t{usize}\t{psize}\t{stamp}")
                walk(data, f"{base}/{os.path.splitext(name)[0]}")
                continue
            if a.cmd == "list":
                print(f"{base}/{name}\t{typ}\t{usize}\t{psize}\t{stamp}")
                continue
            dst = os.path.join(a.out, base, name)
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            open(dst, "wb").write(data)
            if a.sjis and name.lower().endswith((".txt", ".mes")):
                open(dst + ".utf8.txt", "w").write(data.decode("cp932", "replace"))

    for path in a.archives:
        walk(open(path, "rb").read(), os.path.splitext(os.path.basename(path))[0].lower())
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
