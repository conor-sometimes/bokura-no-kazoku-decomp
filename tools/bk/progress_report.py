#!/usr/bin/env python3
"""progress_report.py: the progress report in objdiff's report format (version 2), from the tree alone.

bytematch.dev reads report.json from the CI artifact SCPS_150.88_report (.github/workflows/progress.yml).
No build and no game data: the build matches retail byte for byte by rule (`make` checks the SHA-1),
so a function written in C is matched and a function still INCLUDE_ASM'd is not. Inputs, all committed:
- config/SCPS_150.88.yaml: the .text units ([0xOFFSET, cpp|asm, Name] rows up to .data), in link order;
- config/functions.txt: every function start in .text; a function's size runs to the next start
  (alignment padding included, as in tools/bk/progress.py);
- src/*.cpp: the INCLUDE_ASM lines, the functions not matched yet;
- config/symbol_addrs.txt, config/vtables.txt: names for the addresses (func_XXXXXXXX otherwise).
crt0 (handwritten asm, never C) is a unit with its functions pending, so the totals are all of .text
and the matched percentage is progress.py's "% of .text".
Categories: game (C++ units: game_cpp; C-style units from CAppMain on: game_c), dklib (Dk*),
libs (Lib*); crt0 counts in the totals only. The report holds unit and function names, addresses, sizes and percentages only.

    python3 tools/bk/progress_report.py [-o build/progress/report.json]
Stock Python 3.8+, run from anywhere.
"""
import argparse, json, os, re, sys

R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
TARGET = 'SCPS_150.88'
VRAM_OFFSET = 0xFF000          # vram = file offset + 0xFF000 for the main segment
TEXT_END = 0x29F230            # .text ends where .ctors (the first data piece) starts

CATEGORIES = [
    ('game', 'Game code'),
    ('game_cpp', 'Game code, C++ units'),
    ('game_c', 'Game code, C-style units (CAppMain on)'),
    ('dklib', 'dklib engine library'),
    ('libs', 'Libraries (libgcc, newlib, Sony SDK)'),
]


def read(path):
    with open(os.path.join(R, path), encoding='utf-8', errors='replace') as f:
        return f.read()


def text_units():
    """[(name, kind, start vram, end vram)] of the .text units in link order."""
    rows = []
    for m in re.finditer(r'^\s*- \[(0x[0-9A-Fa-f]+),\s*(\w+)\s*(?:,\s*(\w+))?\s*\]', read(f'config/{TARGET}.yaml'), re.M):
        vram = int(m.group(1), 16) + VRAM_OFFSET
        rows.append((vram, m.group(2), m.group(3)))
    rows.sort()
    units = []
    for i, (vram, kind, name) in enumerate(rows):
        if vram >= TEXT_END:
            break
        if kind not in ('asm', 'cpp', 'c', 'hasm'):
            sys.exit(f'progress_report.py: unexpected {kind} piece {name} in .text')
        end = rows[i + 1][0] if i + 1 < len(rows) else TEXT_END
        units.append((name, kind, vram, min(end, TEXT_END)))
    return units


def symbol_names():
    names = {}
    for path in ('config/symbol_addrs.txt', 'config/vtables.txt'):
        for m in re.finditer(r'^\s*([\w$.]+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;', read(path), re.M):
            names.setdefault(m.group(1), int(m.group(2), 16))
    return names


def pending_addresses(names):
    """Addresses of the INCLUDE_ASM'd functions, from src/*.cpp."""
    pending = set()
    for f in sorted(os.listdir(os.path.join(R, 'src'))):
        if not f.endswith('.cpp'):
            continue
        for m in re.finditer(r'^\s*INCLUDE_ASM\(\s*"[^"]*"\s*,\s*([\w$.]+)\s*\)', read('src/' + f), re.M):
            sym = m.group(1)
            fm = re.fullmatch(r'func_([0-9A-Fa-f]{8})', sym)
            addr = int(fm.group(1), 16) if fm else names.get(sym)
            if addr is None:
                sys.exit(f'progress_report.py: src/{f}: INCLUDE_ASM of {sym}, not in config/symbol_addrs.txt')
            pending.add(addr)
    return pending


def categories_of(name, game_c):
    if name.startswith('Dk'):
        return ['dklib']
    if name == 'crt0':
        return []      # in the totals only, like the README's table
    if name.startswith('Lib'):
        return ['libs']
    return ['game', 'game_c' if game_c else 'game_cpp']


def measures(funcs, units_complete):
    total = sum(f['size'] for f in funcs)
    matched = sum(f['size'] for f in funcs if f['matched'])
    complete = sum(f['size'] for f in funcs if f['complete'])
    nm = sum(1 for f in funcs if f['matched'])
    pct = lambda x: round(100.0 * x / total, 6) if total else 0.0
    return {
        'fuzzy_match_percent': pct(matched),
        'total_code': str(total), 'matched_code': str(matched), 'matched_code_percent': pct(matched),
        'total_functions': len(funcs), 'matched_functions': nm,
        'matched_functions_percent': round(100.0 * nm / len(funcs), 6) if funcs else 0.0,
        'complete_code': str(complete), 'complete_code_percent': pct(complete),
        'total_units': len(units_complete), 'complete_units': sum(units_complete),
    }


def build_report():
    names = symbol_names()
    by_addr = {}
    for n, a in names.items():
        by_addr.setdefault(a, n)
    starts = sorted(int(l, 16) for l in read('config/functions.txt').splitlines() if l.startswith('0x'))
    starts = [a for a in starts if a < TEXT_END]
    pending = pending_addresses(names)
    stray = pending - set(starts)
    if stray:
        sys.exit('progress_report.py: INCLUDE_ASM functions missing from config/functions.txt: '
                 + ' '.join(f'0x{a:X}' for a in sorted(stray)))
    units = text_units()
    if units[0][2] != starts[0]:
        sys.exit('progress_report.py: config/functions.txt and the yaml disagree on where .text starts')

    report_units, allf, cat_funcs, cat_units = [], [], {c: [] for c, _ in CATEGORIES}, {c: [] for c, _ in CATEGORIES}
    game_c = False
    ends = starts[1:] + [TEXT_END]
    i = 0
    for name, kind, lo, hi in units:
        game_c = game_c or name == 'CAppMain'
        funcs = []
        while i < len(starts) and starts[i] < hi:
            a = starts[i]
            funcs.append({'name': by_addr.get(a, f'func_{a:08X}'), 'addr': a, 'size': min(ends[i], hi) - a,
                          'matched': kind != 'asm' and a not in pending})
            i += 1
        complete = bool(funcs) and all(f['matched'] for f in funcs)
        for f in funcs:
            f['complete'] = complete
        cats = categories_of(name, game_c)
        unit = {
            'name': name,
            'measures': measures(funcs, [complete]),
            'functions': [{'name': f['name'], 'size': str(f['size']),
                           'fuzzy_match_percent': 100.0 if f['matched'] else 0.0,
                           'address': str(f['addr'] - lo),
                           'metadata': {'virtual_address': str(f['addr'])}} for f in funcs],
            'metadata': {'complete': complete, 'progress_categories': cats},
        }
        if kind == 'cpp':
            unit['metadata']['source_path'] = f'src/{name}.cpp'
        report_units.append(unit)
        allf += funcs
        for c in cats:
            cat_funcs[c] += funcs
            cat_units[c].append(complete)
    if i != len(starts):
        sys.exit(f'progress_report.py: {len(starts) - i} functions past the last unit')
    return {
        'measures': measures(allf, [u['metadata']['complete'] for u in report_units]),
        'units': report_units,
        'version': 2,
        'categories': [{'id': c, 'name': n, 'measures': measures(cat_funcs[c], cat_units[c])}
                       for c, n in CATEGORIES],
    }


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('-o', '--output', default=os.path.join(R, 'build', 'progress', 'report.json'))
    args = ap.parse_args()
    report = build_report()
    os.makedirs(os.path.dirname(os.path.abspath(args.output)), exist_ok=True)
    with open(args.output, 'w') as f:
        json.dump(report, f, indent=1)
        f.write('\n')
    m = report['measures']
    print(f"{args.output}: matched {m['matched_code']} / {m['total_code']} bytes ({m['matched_code_percent']:.2f}%), "
          f"{m['matched_functions']} / {m['total_functions']} functions, {m['complete_units']} / {m['total_units']} units complete")
    for c in report['categories']:
        cm = c['measures']
        print(f"  {c['id']:9} {cm['matched_code_percent']:6.2f}%  {cm['matched_functions']} / {cm['total_functions']} functions")


if __name__ == '__main__':
    main()
