#!/usr/bin/env python3
"""objdiff.py: objdiff objects and objdiff.json for `make objdiff` (docs: tools/bk/README.md).

One objdiff unit per src/*.cpp, plus crt0 (handwritten asm, target only):
- target: the unit's object from the normal build, build/src/<unit>.cpp.o. The linked ELF matches
  retail byte for byte (`make check`), so each object is what the unit compiles to in the original:
  matched functions from C, the rest INCLUDE_ASM'd from splat's asm, with the same symbol names.
- base: the same compile with -DSKIP_ASM (include/include_asm.h), so it holds the C functions only
  and objdiff counts every INCLUDE_ASM'd function as missing, i.e. unmatched (sly1-decomp's way).
  Caveat: without the asm the C functions sit at other offsets, and GNU as 2.10's lui bug depends on
  alignment, so a few matched functions show as 9x% in base (3 on 2026-10-16); tools/bk utest is
  the authoritative in-unit test.
  The compile command is the Makefile's own (`make -n`), so per-unit compilers and flags carry over.
Run inside bokura-env after `make`. Writes build/objdiff/base/ and objdiff.json (both gitignored).
"""
import json, os, re, shlex, subprocess, sys
from concurrent.futures import ThreadPoolExecutor

R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(R)
BASE = 'build/objdiff/base'

CATEGORIES = [
    ('game', 'Game code (C++ units and the C-style units, CAppMain on)'),
    ('dklib', 'dklib engine library (Dk*)'),
    ('libs', 'Libraries (libgcc, newlib, Sony SDK, crt0; Lib*)'),
]


def category(name):
    if name.startswith('Dk'):
        return 'dklib'
    if name.startswith('Lib') or name == 'crt0':
        return 'libs'
    return 'game'


def compile_commands(units):
    """The Makefile's compile command for each unit's object (make -n -B), keyed by unit."""
    env = {k: v for k, v in os.environ.items() if k not in ('MAKEFLAGS', 'MAKELEVEL', 'MFLAGS')}
    objs = [f'build/src/{u}.cpp.o' for u in units]
    out = subprocess.run(['make', '--no-print-directory', '-n', '-B', *objs], env=env,
                         capture_output=True, text=True, check=True).stdout
    cmds = {}
    for line in out.splitlines():
        m = re.search(r' -o build/src/(\S+)\.cpp\.o ', line)
        if m and ' -c ' in line:
            cmds[m.group(1)] = line
    missing = set(units) - set(cmds)
    if missing:
        sys.exit(f'objdiff.py: no compile command for {sorted(missing)}')
    return cmds


def build_base(unit, cmd):
    src, out = f'src/{unit}.cpp', f'{BASE}/{unit}.cpp.o'
    ref = f'build/src/{unit}.cpp.o'
    if os.path.exists(out) and os.path.getmtime(out) >= max(os.path.getmtime(ref), os.path.getmtime(src)):
        return unit, None
    args = shlex.split(cmd)
    i = args.index('-o')
    args[i + 1] = out
    args.insert(1, '-DSKIP_ASM')
    r = subprocess.run(args, capture_output=True, text=True)
    return unit, (r.stderr if r.returncode else None)


def main():
    units = sorted(f[:-4] for f in os.listdir('src') if f.endswith('.cpp'))
    for u in units:
        if not os.path.exists(f'build/src/{u}.cpp.o'):
            sys.exit(f'objdiff.py: build/src/{u}.cpp.o missing: run make first')
    os.makedirs(BASE, exist_ok=True)
    cmds = compile_commands(units)
    errors = []
    with ThreadPoolExecutor(os.cpu_count() or 4) as ex:
        for unit, err in ex.map(lambda u: build_base(u, cmds[u]), units):
            if err:
                errors.append(f'{unit}:\n{err}')
    if errors:
        sys.exit('objdiff.py: base compile failed\n' + '\n'.join(errors))

    out_units = []
    for u in units:
        src = open(f'src/{u}.cpp', encoding='utf-8', errors='replace').read()
        complete = not re.search(r'^\s*INCLUDE_ASM\(', src, re.M)
        out_units.append({
            'name': u,
            'target_path': f'build/src/{u}.cpp.o',
            'base_path': f'{BASE}/{u}.cpp.o',
            'metadata': {'source_path': f'src/{u}.cpp', 'complete': complete,
                         'progress_categories': [category(u)]},
        })
    # crt0: handwritten startup asm, never C; counted in the total as unmatched (as progress.py does).
    out_units.insert(0, {'name': 'crt0', 'target_path': 'build/asm/crt0.s.o',
                         'metadata': {'progress_categories': ['libs']}})
    cfg = {
        '$schema': 'https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json',
        'min_version': '3.0.0',
        'custom_make': 'make',
        'custom_args': ['objdiff'],
        'build_target': False,
        'build_base': False,
        'watch_patterns': ['*.c', '*.cpp', '*.h', '*.s', '*.inc'],
        'units': out_units,
        'progress_categories': [{'id': i, 'name': n} for i, n in CATEGORIES],
    }
    with open('objdiff.json', 'w') as f:
        json.dump(cfg, f, indent=2)
        f.write('\n')
    print(f'objdiff.py: {len(out_units)} units, {sum(u["metadata"].get("complete", False) for u in out_units)} complete')


if __name__ == '__main__':
    main()
