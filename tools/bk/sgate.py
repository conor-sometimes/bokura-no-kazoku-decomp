#!/usr/bin/env python3
"""sgate.py: the compiler-output gate for changes that must not change code (docs/code-rules.md, [checked]).

Compiles every unit of two revisions to assembly (`ee-gcc -S`, the unit's own compiler and flags
from the Makefile) and compares the compiler's output text. Identical text means the assembler gets
the same input, so the object and the ELF are the same: a declaration moved into a header, a
rename that reaches no symbol, a reformatted function. It needs the compilers only, not the disc:
INCLUDE_ASM is a top-level `__asm__(".include ...")` that -S copies through without reading the file.

    python3 -I tools/bk/sgate.py [BASE [NEW]] [-u UNIT ...] [-j N] [--keep]

BASE defaults to HEAD; NEW defaults to the working tree (as `git stash create` sees it: tracked
files, with their changes). Both are read through git, so line endings are the repository's.
Run inside bokura-env (the compilers are Linux i386 binaries). Compilers come from
tools/compilers/<name> (scripts/fetch_compilers.sh), or $BK_COMPILERS/<name>; a unit whose compiler
is not there is skipped and named.

Not covered: a change that is meant to change code (use `bk utest` and `make`), and anything in
config/ or the Makefile. `make` stays the gate of record; this one says the same thing sooner for
source-only changes, and without the ELF.
"""
import argparse
import concurrent.futures
import io
import os
import subprocess
import sys
import tarfile
import tempfile

R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

# The Makefile's per-unit compilers and flags (-Wa options left out: -S does not assemble).
GAME = ('ee-gcc2.96', '-O2 -G0 -fno-strict-aliasing -fno-exceptions')
SDK = ('ee-gcc2.9-991111', '-O2 -G0 -fno-exceptions')
SDKC = ('ee-gcc2.9-991111-01', '-x c -O2 -G0')
LIBC = ('ee-gcc2.96', '-O2 -G0 -fno-exceptions')
LIBC_EXC = ('ee-gcc2.96', '-O2 -G0 -fexceptions')
LIBC_C = ('ee-gcc2.96', '-x c -O2 -G0 -fno-exceptions')
LIBC_C_G = ('ee-gcc2.96', '-x c -O2 -G0 -g -fno-exceptions')
UNITS = {}
for names, how in (
        ('Dk262D28 Dk2631E0 Dk265918 Dk268138 Dk26A870', SDK),
        ('Dk26CFB0 Dk26EDE8 Dk26FC10 Dk271AF8 Dk272E50 Dk273210 Dk2735D0 Dk2752B8 Dk2779D8 Dk27A100 Dk27C020 '
         'Dk27DBB8 Lib292E20', SDKC),
        ('Lib283858 Lib285F80 Lib286B20 Lib287920 Lib287F98 Lib288388 Lib2888C0 Lib28AE50 Lib28D8B0 Lib28F4F8 '
         'Lib290990', LIBC),
        ('Lib287920', LIBC_EXC),
        ('Dk280098 Lib283858 Lib285F80 Lib287F98 Lib2888C0 Lib28AE50 Lib28D8B0 Lib28F4F8 Lib290990', LIBC_C),
        ('Lib28AE50 Lib28D8B0 Lib28F4F8', LIBC_C_G)):
    for n in names.split():
        UNITS[n] = how                      # later rows override, as the Makefile's later rules do


def git(*args, **kw):
    return subprocess.run(('git', '-c', 'safe.directory=*', '-C', R) + args, check=True, stdout=subprocess.PIPE, **kw).stdout


def export(rev, dest):
    tarfile.open(fileobj=io.BytesIO(git('archive', rev, 'src', 'include'))).extractall(dest)


def compiler(name):
    for base in (os.environ.get('BK_COMPILERS'), os.path.join(R, 'tools', 'compilers')):
        if base and os.path.exists(os.path.join(base, name, 'bin', 'ee-gcc')):
            return os.path.join(base, name, 'bin', 'ee-gcc')
    return None


def compile_unit(tree, unit):
    name, flags = UNITS.get(unit, GAME)
    cc = compiler(name)
    if cc is None:
        return None, 'no compiler ' + name
    p = subprocess.run([cc] + flags.split() + ['-Iinclude', '-S', '-o', '-', 'src/%s.cpp' % unit],
                       cwd=tree, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if p.returncode or not p.stdout:
        return None, p.stderr.decode('utf-8', 'replace').strip().splitlines()[-1:] or 'no output'
    # cc1 -g records the directory it ran in: the two trees differ in nothing else
    return p.stdout.replace(os.path.realpath(tree).encode(), b'<tree>'), None


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('base', nargs='?', default='HEAD')
    ap.add_argument('new', nargs='?', help='default: the working tree')
    ap.add_argument('-u', '--unit', action='append', help='only this unit (repeatable)')
    ap.add_argument('-j', type=int, default=os.cpu_count() or 4)
    ap.add_argument('--keep', action='store_true', help='keep the two exported trees and the differing .s files')
    args = ap.parse_args()

    new = args.new or git('stash', 'create').decode().strip() or 'HEAD'
    tmp = tempfile.mkdtemp(prefix='sgate.')
    a, b = os.path.join(tmp, 'base'), os.path.join(tmp, 'new')
    export(args.base, a)
    export(new, b)
    units = sorted(f[:-4] for f in os.listdir(os.path.join(b, 'src')) if f.endswith('.cpp'))
    if args.unit:
        units = [u for u in units if u in args.unit]

    def one(unit):
        if not os.path.exists(os.path.join(a, 'src', unit + '.cpp')):
            return unit, 'new', 'not in ' + args.base
        x, ex = compile_unit(a, unit)
        y, ey = compile_unit(b, unit)
        if ex or ey:
            why = ex or ey
            return unit, 'skipped' if 'no compiler' in str(why) else 'error', why
        if x != y:
            if args.keep:
                for tree, s in ((a, x), (b, y)):
                    with open(os.path.join(tree, unit + '.s'), 'wb') as f:
                        f.write(s)
            return unit, 'differs', None
        return unit, 'same', None

    with concurrent.futures.ThreadPoolExecutor(args.j) as pool:
        results = list(pool.map(one, units))
    count = {}
    for unit, state, why in results:
        count[state] = count.get(state, 0) + 1
        if state != 'same':
            print('%-8s %s%s' % (state, unit, ': %s' % (why,) if why else ''))
    print('sgate: %s vs %s: %s' % (args.base, args.new or 'working tree',
                                    ', '.join('%d %s' % (n, s) for s, n in sorted(count.items()))))
    if args.keep:
        print('kept: ' + tmp)
    else:
        subprocess.run(['rm', '-rf', tmp])
    sys.exit(1 if any(s in count for s in ('differs', 'error')) else 0)


if __name__ == '__main__':
    main()
