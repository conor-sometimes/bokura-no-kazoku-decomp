#!/usr/bin/env python3
"""status.py: refresh the README's status block (badges + a table, one row per code region).

Two numbers per row:
  - matched under the rules (the headline): the bytes match and the function passes every [match]
    rule of docs/code-rules.md, as tools/bk/rules.py computes it;
  - bytes matched: the function is written in C (no INCLUDE_ASM), so `make` proves its bytes.

Tree only, like progress_report.py and rules.py: no build needed. Run from the repo root:
  python3 -I tools/bk/status.py          (prints the block and rewrites README.md between the markers)
"""
import datetime
import json
import os
import re
import subprocess
import sys
import tempfile

R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(R, 'tools', 'bk'))
import progress_report  # noqa: E402

TEXT_LO, TEXT_HI = 0x1002A8, 0x29F230   # .text after crt0; everything here is in units
TEXT_BYTES = 0x19F230                    # all of .text, crt0 included

# Code regions in link order (docs/units.md).
REGIONS = [
    (0x1002A8, 0x1E91B8, 'Game code, C++ units', 'classes found from vtables and RTTI'),
    (0x1E91B8, 0x245648, 'Game code, C-style units', 'CAppMain on: renderer, files, sound, IOP'),
    (0x245648, 0x283858, 'dklib engine library', 'heap, tasks, resources, scripts; part Sony SDK'),
    (0x283858, 0x29F230, 'Libraries', 'libgcc, newlib, Sony SDK, linkonce code'),
]


def bar(pct, width=20):
    filled = round(width * pct / 100)
    return '█' * filled + '░' * (width - filled)


def rules_findings():
    """(addresses held back by a [match] rule, count of held-back definitions with no address)."""
    with tempfile.TemporaryDirectory() as d:
        out = os.path.join(d, 'rules.json')
        subprocess.run([sys.executable, '-I', os.path.join(R, 'tools', 'bk', 'rules.py'), '--json', out],
                       check=True, stdout=subprocess.DEVNULL, cwd=R)
        data = json.load(open(out))
    held = {f['address'] for f in data['functions'] if f['match_pending'] and f['address'] is not None}
    return held, data['matched_under_rules']


def main():
    funcs = sorted(int(l, 16) for l in open(f'{R}/config/functions.txt') if l.startswith('0x'))
    funcs = [a for a in funcs if TEXT_LO <= a < TEXT_HI]
    size = {a: e - a for a, e in zip(funcs, funcs[1:] + [TEXT_HI])}
    remaining = progress_report.pending_addresses(progress_report.symbol_names())
    held, rules_total = rules_findings()
    hard_text = open(f'{R}/HARD.md').read()
    hard_addrs = {int(m, 16) for m in re.findall(r'0x([0-9A-Fa-f]{6})\b', hard_text)}

    rows = []
    for lo, hi, name, what in REGIONS:
        fs = [a for a in funcs if lo <= a < hi]
        done = [a for a in fs if a not in remaining]
        clean = [a for a in done if a not in held]
        rows.append((name, what, len(fs), hi - lo,
                     len(clean), sum(size[a] for a in clean),
                     len(done), sum(size[a] for a in done)))
    tf = len(funcs)
    nf = sum(r[6] for r in rows)
    nb = sum(r[7] for r in rows)
    rf = rules_total                    # rules.py's own count (also drops held-back defs with no address)
    rb = sum(r[5] for r in rows)
    pct = lambda a, b: 100 * a / b
    stuck = len([a for a in remaining if a in hard_addrs])

    badge = 'https://img.shields.io/badge/{}-{}-{}'
    lines = [
        '<!-- status:begin -->',
        f"![matched under the rules]({badge.format('matched%20under%20the%20rules', f'{rf}%2F{tf}', 'blue')}) "
        f"![bytes matched]({badge.format('bytes%20matched', f'{nf}%2F{tf}', 'lightgrey')}) "
        f"![build]({badge.format('build', 'byte--for--byte', 'brightgreen')})",
        '',
        f'Progress, {datetime.date.today().isoformat()}. Two numbers: **matched under the rules** (the '
        'headline) means the function',
        'rebuilds retail\'s bytes *and* passes the [match] rules of [docs/code-rules.md](docs/code-rules.md) '
        '(one declaration per',
        'type and global, typed members, real vtables, no fake code, no assembly bodies); **bytes matched** '
        'means it is written',
        'in C and `make` proves its bytes. The rest is still INCLUDE_ASM.',
        '',
        '| | Matched under the rules | | Bytes matched |',
        '|---|---|---|---|',
        f'| **Functions** | `{bar(pct(rf, tf))}` | **{rf:,} / {tf:,} ({pct(rf, tf):.1f}%)** | '
        f'{nf:,} ({pct(nf, tf):.1f}%) |',
        f'| **Code** (`.text`, {TEXT_BYTES / 1e6:.2f} MB) | `{bar(pct(rb, TEXT_BYTES))}` | '
        f'**{rb / 1000:.1f} KB ({pct(rb, TEXT_BYTES):.1f}%)** | {nb / 1000:.1f} KB ({pct(nb, TEXT_BYTES):.1f}%) |',
    ]
    for name, what, t, total, cf, cb, df, db in rows:
        lines.append(f'| &nbsp;&nbsp;{name} ({total / 1000:.0f} KB, {what}) | `{bar(pct(cb, total))}` | '
                     f'{cf:,} / {t:,} functions, {pct(cb, total):.1f}% of code | '
                     f'{df:,} functions, {pct(db, total):.1f}% |')
    lines += [
        f'| Stuck ([HARD.md](HARD.md), with their exact diffs) | | {stuck:,} | |',
        '',
        'Refresh with `python3 -I tools/bk/status.py` (tree only). What holds functions back, rule by rule:',
        '`python3 -I tools/bk/rules.py`, and [docs/code-rules-status.md](docs/code-rules-status.md) for the '
        'order of work.',
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
