#!/usr/bin/env python3
"""status.py: refresh the README's status block (badges + a table, one bar per code region).

Needs a built tree (build/bk/ctx.json lists the functions still in asm). Run from the repo root:
  python3 -I tools/bk/status.py          (prints the block and rewrites README.md between the markers)
"""
import datetime
import json
import os
import re

R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
TEXT_LO, TEXT_HI = 0x1002A8, 0x29F230   # .text after crt0; everything here is in units
TEXT_BYTES = 0x19F230                    # all of .text, crt0 included

# Code regions in link order (docs/units.md).
REGIONS = [
    (0x1002A8, 0x1E91B8, 'Game code, C++ units', 'classes found from vtables and RTTI'),
    (0x1E91B8, 0x245648, 'Game code, C-style units', 'CAppMain on: renderer, files, sound, IOP'),
    (0x245648, 0x283858, 'dklib engine library', 'heap, tasks, resources, scripts; part Sony SDK'),
    (0x283858, 0x29F230, 'Libraries', 'libgcc, newlib, Sony SDK, linkonce code'),
]


def bar(pct, width=25):
    filled = round(width * pct / 100)
    return '█' * filled + '░' * (width - filled)


def main():
    ctx = json.load(open(f'{R}/build/bk/ctx.json'))
    remaining = {int(k, 16) for k in ctx}
    funcs = sorted(int(l, 16) for l in open(f'{R}/config/functions.txt') if l.startswith('0x'))
    size = {a: e - a for a, e in zip(funcs, funcs[1:] + [TEXT_HI])}
    hard_text = open(f'{R}/HARD.md').read()
    hard_addrs = {int(m, 16) for m in re.findall(r'0x([0-9A-Fa-f]{6})\b', hard_text)}

    rows = []
    for lo, hi, name, what in REGIONS:
        fs = [a for a in funcs if lo <= a < hi]
        done = [a for a in fs if a not in remaining]
        b = sum(size[a] for a in done)
        rows.append((name, what, len(done), len(fs), b, hi - lo))
    nf = sum(r[2] for r in rows)
    tf = len(funcs)
    nb = sum(r[4] for r in rows)
    fpct, bpct = 100 * nf / tf, 100 * nb / TEXT_BYTES
    stuck = len([a for a in remaining if a in hard_addrs])

    badge = 'https://img.shields.io/badge/{}-{}-{}'
    lines = [
        '<!-- status:begin -->',
        f"![functions]({badge.format('functions', f'{nf}%2F{tf}', 'blue')}) "
        f"![bytes]({badge.format('bytes', f'{bpct:.1f}%25', 'orange')}) "
        f"![build]({badge.format('build', 'byte--for--byte', 'brightgreen')})",
        '',
        f'Progress, {datetime.date.today().isoformat()} (functions in C; the rest is still INCLUDE_ASM):',
        '',
        '| | Progress | |',
        '|---|---|---|',
        f'| **Functions** | `{bar(fpct)}` | {nf:,} / {tf:,} ({fpct:.1f}%) |',
        f'| **Code bytes** (`.text`, {TEXT_BYTES / 1e6:.2f} MB) | `{bar(bpct)}` | '
        f'{nb / 1000:.1f} KB / {TEXT_BYTES / 1000:.1f} KB ({bpct:.1f}%) |',
    ]
    for name, what, d, t, b, total in rows:
        p = 100 * b / total
        lines.append(f'| &nbsp;&nbsp;{name} ({total / 1000:.0f} KB, {what}) | `{bar(p)}` | '
                     f'{d:,} / {t:,} functions, {p:.1f}% of bytes |')
    lines += [
        f'| Stuck ([HARD.md](HARD.md), with their exact diffs) | | {stuck:,} |',
        '',
        'Build: Sony EE-GCC 2.96 for the game; parts of dklib and the Sony SDK were built with older',
        'SDK compilers (ee-gcc 2.9-991111 and -01), set per unit ([docs/compiler.md](docs/compiler.md)).',
        '<!-- status:end -->',
    ]
    block = '\n'.join(lines)
    p = f'{R}/README.md'
    text = open(p).read()
    text = re.sub(r'<!-- (status:begin|progress:start) -->.*?<!-- (status:end|progress:end) -->',
                  lambda m: block, text, count=1, flags=re.S)
    open(p, 'w').write(text)
    print(block)


if __name__ == '__main__':
    main()
