#!/usr/bin/env python3
"""ushow.py SNIP [ADDR]: utest's in-unit compile, shown side by side (ours | retail) with `!!` on
differing words (relocated fields masked). BK_EXTRA="-flag ..." adds compiler flags (experiments),
BK_CC=path swaps the compiler driver. `-q` prints only the diff count per function (for sweeps)."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import bk  # noqa: E402
import utest  # noqa: E402

R, W = bk.R, bk.W


def compile_unit(path, extra=None):
    decl, funcs = bk.parse(path)
    unit = next(iter({bk.ctx[hex(a)]['unit'] for a, _ in funcs if hex(a) in bk.ctx}))
    src = os.path.join(W, f'us_{unit}_{os.getpid()}.cpp')
    open(src, 'w').write(utest.splice(unit, decl, funcs))
    cc, base, asg = bk.flags_for(funcs)
    cc = os.environ.get('BK_CC', cc)
    if extra is None:
        extra = os.environ.get('BK_EXTRA', '').split()
    obj = os.path.join(W, f'us_{os.getpid()}_{len(extra)}.o')
    r = subprocess.run([cc] + base + extra + ['-I' + R + '/include', '-Wa,-I' + R + '/include'] + asg +
                       ['-c', '-o', obj, src], capture_output=True, text=True, cwd=R)
    if os.environ.get('BK_KEEP'):
        print('kept', src)
    else:
        os.remove(src)
    if r.returncode:
        print(r.stderr[-3000:])
        raise SystemExit(1)
    return unit, funcs, obj


def main(argv):
    quiet = '-q' in argv
    argv = [a for a in argv if a != '-q']
    path = argv[0]
    only = int(argv[1], 16) if len(argv) > 1 else None
    unit, funcs, obj = compile_unit(path)
    text, relocs = utest.read_obj_full(obj)
    start = utest.unit_starts()[unit]
    moved = {}
    if os.environ.get('BK_EXTRA', '').strip():
        # flags can change the size of earlier functions: find each function by its symbol name
        # (taken from a compile without the extra flags) instead of its retail offset
        _, _, obj0 = compile_unit(path, [])
        syms0 = {v: n for v, sz, n in bk.read_obj(obj0)[0]}
        syms1 = {n: v for v, sz, n in bk.read_obj(obj)[0]}
        os.remove(obj0)
        for addr, _ in funcs:
            nm = syms0.get(addr - start)
            if nm in syms1:
                moved[addr] = syms1[nm]
    for addr, _ in funcs:
        if only is not None and addr != only:
            continue
        c = bk.ctx[hex(addr)]
        n = c['n']
        off = moved.get(addr, addr - start)
        mw = bk.words(text, off, n)
        tw = bk.words(bk.rom, addr - 0xFF000, n)
        d = subprocess.run([bk.OD, '-d', '-z', '-r', '--start-address=%d' % off, '--stop-address=%d' % (off + 4 * n), obj],
                           capture_output=True, text=True).stdout
        mine = [l.split('\t', 2)[-1] for l in d.splitlines() if re.match(r'\s+[0-9a-f]+:\t', l)]
        p = f"{R}/asm/nonmatchings/{c['unit']}/{c['name']}.s"
        theirs, text = [], True
        for l in open(p):
            if l.startswith('.section'):
                text = l.split()[1] == '.text'
            if text and re.search(r'/\* \w+ [0-9A-F]{8} [0-9A-F]{8} \*/', l):
                theirs.append(re.sub(r'\s+', ' ', l.split('*/', 1)[1].strip()))
        bad = 0
        rows = []
        for i in range(n):
            rel = relocs.get(off + 4 * i)
            m = 0xFFFFFFFF
            if rel and rel[0] in (5, 6):
                m = 0xFFFF0000
            elif rel and rel[0] == 4:
                m = 0xFC000000
            flag = '!!' if (mw[i] & m) != (tw[i] & m) else '  '
            bad += flag == '!!'
            a = mine[i] if i < len(mine) else ''
            b = theirs[i] if i < len(theirs) else ''
            rows.append(f'{flag}{i:4d} {a:<44} | {b}')
        print(f'{addr:#x} {c["name"]}: DIFF {bad}')
        if not quiet:
            print('\n'.join(rows))
    os.remove(obj)


if __name__ == '__main__':
    main(sys.argv[1:])
