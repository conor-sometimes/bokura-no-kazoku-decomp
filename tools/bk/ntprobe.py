#!/usr/bin/env python3
"""ntprobe.py SNIP ADDR: does a callee's nothrow-ness explain the remaining diff?

EE-GCC 2.96 treats a function it has already compiled in the same .cpp as nothrow, and nothrow
calls change reorg's delay-slot choices (likely vs plain branches, docs/lessons.md "nm"). For each
callee in the retail asm that the snippet or its unit declares as a free / extern "C" function,
this re-tests the snippet (in its unit, like utest) with that declaration repeated as `throw()`,
then with all of them. A drop in DIFF names the callee to declare `throw()` (or, if the drop comes
from making it nothrow where retail did not, a hint about translation-unit boundaries).
Member functions are not probed: put `throw()` on their in-class declaration by hand.
Run inside bokura-env from the repo root.
"""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import bk  # noqa: E402

R = bk.R


def diff_of(snip, addr):
    r = subprocess.run([sys.executable, '-I', os.path.join(R, 'tools/bk/ushow.py'), '-q', snip, hex(addr)],
                       capture_output=True, text=True, cwd=R)
    out = [l for l in (r.stdout + r.stderr).splitlines() if 'DIFF' in l]
    return out[0].split(': ', 1)[-1] if out else 'error: ' + (r.stdout + r.stderr).strip()[-120:]


def main(snip, addr):
    addr = int(addr, 16)
    c = bk.ctx[hex(addr)]
    asm = open(f"{R}/asm/nonmatchings/{c['unit']}/{c['name']}.s").read()
    callees = sorted(set(re.findall(r'\bjal\s+([A-Za-z_]\w*)', asm)))
    text = open(snip).read() + open(f"{R}/src/{c['unit']}.cpp").read()
    redecl = {}
    for x in callees:
        base = x.split('__')[0]
        m = re.search(r'extern\s+"C"\s+([^;{}()]*?)\b' + re.escape(x) + r'\s*\(([^()]*)\)\s*(throw\s*\(\s*\))?\s*;', text)
        if m:
            if not m.group(3):
                redecl[x] = f'extern "C" {m.group(1).strip()} {x}({m.group(2)}) throw();'
            continue
        if '__F' in x:   # a mangled free function: redeclare it by its C++ name
            m = re.search(r'^\s*(?:extern\s+)?([A-Za-z_][\w\s\*&]*?[\s\*&])' + re.escape(base) +
                          r'\s*\(([^()]*)\)\s*(throw\s*\(\s*\))?\s*;', text, re.M)
            if m and not m.group(3) and not m.group(1).strip().startswith(('return', 'else')):
                redecl[x] = f'{m.group(1).strip()} {base}({m.group(2)}) throw();'
    base_text = open(snip).read()
    tmp = os.path.join(bk.W, f'ntprobe_{os.getpid()}.snip')

    def run(lines, tag):
        open(tmp, 'w').write(base_text.replace('//@func', '//@decl\n' + '\n'.join(lines) + '\n//@func', 1))
        print(f'{tag:34s} {diff_of(tmp, addr)}')

    run([], '(as is)')
    for x, l in redecl.items():
        run([l], x)
    if len(redecl) > 1:
        run(list(redecl.values()), '(all of them)')
    os.remove(tmp)
    rest = [x for x in callees if x not in redecl]
    if rest:
        print('not probed (members, undeclared or already throw()):', ' '.join(rest))


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2])
