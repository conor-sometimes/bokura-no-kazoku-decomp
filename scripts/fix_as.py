#!/usr/bin/env python3
"""fix_as.py: make tools/as/as, a fixed copy of EE-GCC 2.96's GNU as 2.10-ee.

The bug: md_convert_frag (gas/config/tc-mips.c) moves a relaxed frag's bytes down with memcpy()
over overlapping memory. That is undefined behaviour: glibc picks a memcpy variant per CPU, and
some variants depend on the addresses, so on some hosts and process environments a `lui` came
out as a copy of the instruction after it. The build only matched on one machine, with
`asm(".p2align 3")` lines placed by trial to dodge it (lemiur, PR #2; docs/lessons.md "## as").

The fix replaces the 12 bytes that push memcpy's arguments and call it with an inline forward
copy of the same length (the destination is always below the source, so a forward copy is
overlap-safe):
    mov %edx,%edi; sub %esi,%edi; mov %ebx,%ecx; push %esi; mov %edx,%esi; rep movsb; pop %esi
Both the input and the output are checked by SHA-256. Every compile uses the result through
`-B tools/as/` (Makefile).

  python3 -I scripts/fix_as.py      (setup.sh and make run it; it does nothing when up to date)
"""
import hashlib
import os
import sys

R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(R, 'tools/compilers/ee-gcc2.96/ee/bin/as')
DST = os.path.join(R, 'tools/as/as')
SHA_IN = 'b8cfdb6ecb6931642914020f92a62e653378f57230eed4895f69afa050d47b5e'
SHA_OUT = '888c60a931b12639aa5c446d7effba30874d115ee471c06b75601194e7641866'
OFFSET = 0x31DCC                                   # vaddr 0x8079DCC in md_convert_frag
OLD = bytes.fromhex('89d029f0535250e8d8f7fcff')    # mov %edx,%eax; sub %esi,%eax; push x3; call memcpy@plt
NEW = bytes.fromhex('89d729f789d95689d6f3a45e')    # the inline forward copy above


def sha(b):
    return hashlib.sha256(b).hexdigest()


def main():
    if os.path.exists(DST) and sha(open(DST, 'rb').read()) == SHA_OUT:
        return
    if not os.path.exists(SRC):
        sys.exit('fix_as: %s missing; run scripts/fetch_compilers.sh first' % SRC)
    b = bytearray(open(SRC, 'rb').read())
    if sha(b) != SHA_IN:
        sys.exit('fix_as: %s is not the pinned GNU as 2.10-ee (sha256 %s)' % (SRC, sha(b)))
    if b[OFFSET:OFFSET + len(OLD)] != OLD:
        sys.exit('fix_as: unexpected bytes at 0x%X' % OFFSET)
    b[OFFSET:OFFSET + len(NEW)] = NEW
    if sha(b) != SHA_OUT:
        sys.exit('fix_as: patched assembler has sha256 %s, expected %s' % (sha(b), SHA_OUT))
    os.makedirs(os.path.dirname(DST), exist_ok=True)
    tmp = DST + '.tmp'
    open(tmp, 'wb').write(b)
    os.chmod(tmp, 0o755)
    os.replace(tmp, DST)
    print('fix_as: tools/as/as written (GNU as 2.10-ee with the overlapping-memcpy fix)')


if __name__ == '__main__':
    main()
