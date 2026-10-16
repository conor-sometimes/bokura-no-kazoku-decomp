#!/usr/bin/env python3
"""hardretry.py [-j N] [--port] [PATH...]: re-test every saved stuck function with today's tools.

Stuck functions keep their best attempt as a bk snippet in `docs/hard/<lane>/hard_<ADDR>.snip`
(one `//@func 0xADDR` section, plus the `//@decl` it needs). After any discovery (a compiler flag,
a header fix, a trick in docs/lessons.md), run this: each snippet whose function is still
INCLUDE_ASM'd is tested the way the build sees it (tools/bk/utest.py), and the ones that now
match are listed (`--port` ports them; run tools/bk/mk.sh afterwards). Snippets whose function is
already matched are listed too, to delete.
"""
import argparse
import glob
import os
import re
import sys
from multiprocessing import Pool

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import bk  # noqa: E402
import utest  # noqa: E402


def one(path):
    m = re.search(r'hard_([0-9A-Fa-f]{6,8})\.snip$', path)
    addr = int(m.group(1), 16) if m else None
    if addr is not None and hex(addr) not in bk.ctx:
        return path, 'done', None
    try:
        res = utest.utest(path, quiet=True)
    except SystemExit:
        return path, 'error', None
    except Exception as e:   # a stale snippet (unit renamed, function moved)
        return path, 'error', str(e)[:80]
    bad = sum(r[2] for r in res)
    return path, 'match' if not bad else 'diff', bad


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__.split('\n\n')[0])
    p.add_argument('paths', nargs='*')
    p.add_argument('-j', type=int, default=max(1, (os.cpu_count() or 2) // 2))
    p.add_argument('--port', action='store_true')
    a = p.parse_args(argv)
    paths = a.paths or sorted(glob.glob(os.path.join(bk.R, 'docs/hard/**/hard_*.snip'), recursive=True))
    with Pool(a.j) as pool:
        results = pool.map(one, paths)
    by = {}
    for path, kind, info in results:
        by.setdefault(kind, []).append((path, info))
    rel = lambda x: os.path.relpath(x, bk.R)
    for path, _ in by.get('match', []):
        print(f'MATCH  {rel(path)}')
    for path, _ in by.get('done', []):
        print(f'done   {rel(path)} (already matched: delete the snippet)')
    for path, info in by.get('error', []):
        print(f'error  {rel(path)}' + (f': {info}' if info else ' (does not compile any more)'))
    diffs = sorted(by.get('diff', []), key=lambda x: x[1])
    print(f"{len(paths)} snippets: {len(by.get('match', []))} now match, {len(diffs)} still differ "
          f"(closest: {', '.join(f'{os.path.basename(p)} {d}' for p, d in diffs[:5])}), "
          f"{len(by.get('done', []))} already done, {len(by.get('error', []))} errors")
    if a.port:
        for path, _ in by.get('match', []):
            try:
                bk.port(path)
            except SystemExit:
                print(f'port refused for {rel(path)}')
        if by.get('match'):
            print('ported; now run tools/bk/mk.sh')


if __name__ == '__main__':
    main()
