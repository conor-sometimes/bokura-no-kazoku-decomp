#!/usr/bin/env python3
"""Copy the boot ELF out of a Bokura no Kazoku disc image and check its SHA-1.

Usage: extract_elf.py ISO OUT

Reads ISO9660 directly (plain 2048-byte ISO or raw 2352-byte sectors), finds
the boot ELF named by SYSTEM.CNF's BOOT2 line, and refuses anything whose
SHA-1 is not the retail SCPS_150.88.
"""
import hashlib
import re
import struct
import sys
from pathlib import Path

EXPECTED_NAME = "SCPS_150.88"
EXPECTED_SHA1 = "621ffd58de52794eaa3d33885ba1288f36e19365"


class Disc:
    def __init__(self, path):
        self.f = open(path, "rb")
        head = self.f.read(16)
        if head[:12] == b"\x00" + b"\xff" * 10 + b"\x00":
            self.sector, self.offset = 2352, 24 if head[15] == 2 else 16
        else:
            self.sector, self.offset = 2048, 0

    def read(self, lba, size):
        out = bytearray()
        while len(out) < size:
            self.f.seek(lba * self.sector + self.offset)
            out += self.f.read(2048)
            lba += 1
        return bytes(out[:size])


def root_files(disc):
    pvd = disc.read(16, 2048)
    if pvd[1:6] != b"CD001":
        sys.exit("not an ISO9660 image (no CD001 at sector 16)")
    root = pvd[156:190]
    lba, size = struct.unpack_from("<I", root, 2)[0], struct.unpack_from("<I", root, 10)[0]
    data, off, files = disc.read(lba, size), 0, {}
    while off < len(data):
        n = data[off]
        if n == 0:
            off = (off // 2048 + 1) * 2048
            continue
        rec = data[off:off + n]
        name = rec[33:33 + rec[32]].decode("latin1").split(";")[0]
        if not rec[25] & 2:
            files[name.upper()] = (struct.unpack_from("<I", rec, 2)[0], struct.unpack_from("<I", rec, 10)[0])
        off += n
    return files


def main():
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    iso, out = Path(sys.argv[1]), Path(sys.argv[2])
    disc = Disc(iso)
    files = root_files(disc)
    if "SYSTEM.CNF" not in files:
        sys.exit("no SYSTEM.CNF in the disc root")
    cnf = disc.read(*files["SYSTEM.CNF"]).decode("latin1")
    m = re.search(r"BOOT2\s*=\s*cdrom0:\\([^;\s]+)", cnf)
    name = m.group(1).upper() if m else EXPECTED_NAME
    if name != EXPECTED_NAME or name not in files:
        sys.exit(f"boot ELF is {name!r}, expected {EXPECTED_NAME} (wrong disc?)")
    elf = disc.read(*files[name])
    digest = hashlib.sha1(elf).hexdigest()
    if digest != EXPECTED_SHA1:
        sys.exit(f"{name}: SHA-1 {digest}, expected {EXPECTED_SHA1}")
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_bytes(elf)
    print(f"{out}: {len(elf)} bytes, SHA-1 OK")


if __name__ == "__main__":
    main()
