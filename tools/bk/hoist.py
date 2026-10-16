#!/usr/bin/env python3
"""hoist.py: move classes that units declare locally into shared headers.

  python3 -I tools/bk/hoist.py list [-n 30]       classes declared in more than one unit
  python3 -I tools/bk/hoist.py CLASS [CLASS...]   hoist them, build, back out what breaks

Lanes declare only the methods they call (`class CFlagWork { public: int Func1091B0(s32); };`),
so the same class ends up in up to 19 units with slightly different signatures: merge conflicts
and cc1plus crashes. For each CLASS, every *method-only* local copy (no fields, no virtuals, no
base) is merged into include/CLASS.h (created if missing; methods the header lacks are added,
a non-void return wins over void), replaced by `#include "CLASS.h"`, and `extern` lines the header
already declares are dropped. Then the tree is built (tools/bk/mk.sh); a unit that no longer
compiles (EE-GCC 2.96 sometimes dies with "Internal error" on a header) gets its own version
back, until the build matches again. Copies with fields or virtuals are listed for a human.
"""
import collections
import glob
import os
import re
import subprocess
import sys

R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def blocks(cls=None):
    """{class: [(file, start line, end line, method_only)]} for top-level class/struct blocks."""
    out = collections.defaultdict(list)
    for f in sorted(glob.glob(f'{R}/src/*.cpp')):
        L = open(f).read().split('\n')
        i = 0
        while i < len(L):
            m = re.match(r'(class|struct) (\w+)\b(.*)$', L[i])
            if m and not m.group(3).rstrip().endswith(';') and (cls is None or m.group(2) == cls):
                j = i
                while j < len(L) and not L[j].startswith('};'):
                    j += 1
                body = [l for l in L[i + 1:j] if l.strip() and l.strip() != 'public:' and not l.strip().startswith('//')]
                simple = ':' not in m.group(3) and '{' in m.group(3) and all(
                    '(' in l and 'virtual' not in l and l.rstrip().endswith(';') for l in body)
                out[m.group(2)].append((f, i, j, simple))
                i = j
            i += 1
    return out


def norm(sig):
    m = re.match(r'\s*(.*?)\b(\w+)\s*\((.*)\)\s*(const)?\s*;', sig)
    if not m:
        return None
    ret, name, params, const = m.groups()
    ps = []
    for p in params.split(','):
        p = re.sub(r'\s*=.*$', '', p.strip())
        if not p or p == 'void':
            continue
        p = re.sub(r'\b\w+$', '', p) if re.search(r'[\w*&]\s+\**\w+$', p) else p
        ps.append(p.replace('s32', 'int').replace('u32', 'unsigned int').replace(' ', ''))
    return name, tuple(ps), const or '', ret.strip()


def hoist(cls):
    copies = [b for b in blocks(cls)[cls] if b[3]]
    if not copies:
        print(f'{cls}: no method-only local copies')
        return {}
    methods, order = {}, []
    for f, i, j, _ in copies:
        for l in open(f).read().split('\n')[i + 1:j]:
            if '(' not in l:
                continue
            k = norm(l)
            if not k:
                continue
            key = k[:3]
            if key not in methods:
                methods[key] = (l.strip(), k[3])
                order.append(key)
            elif methods[key][1] == 'void' and k[3] != 'void':
                methods[key] = (l.strip(), k[3])
    hdr = f'{R}/include/{cls}.h'
    if os.path.exists(hdr):
        text = open(hdr).read()
        m = re.search(rf'^class {cls}\b[^\n]*\{{\n(.*?)^\}};', text, re.S | re.M)
        if not m:
            print(f'{cls}: {hdr} has no plain `class {cls} {{` block; skipped')
            return {}
        have = set(re.findall(r'\b(\w+)\s*\(', m.group(1)))
        add = [methods[k][0] for k in order if k[0] not in have]
        if add:
            body = m.group(1).split('\n')
            last = max((n for n, l in enumerate(body) if '(' in l), default=0)
            body[last + 1:last + 1] = ['    ' + x for x in add]
            text = text[:m.start(1)] + '\n'.join(body) + text[m.end(1):]
            open(hdr, 'w').write(text)
    else:
        g = cls.upper() + '_H'
        open(hdr, 'w').write(f'#ifndef {g}\n#define {g}\n\n#include "common.h"\n\n'
                             f'// Hoisted from the units that declared it locally (tools/bk/hoist.py).\n'
                             f'class {cls} {{\npublic:\n' + ''.join(f'    {methods[k][0]}\n' for k in order) +
                             '};\n\n#endif\n')
    hsyms = set(re.findall(r'^extern [^;(]*?\b(\w+)(?:\[\])?;', open(hdr).read(), re.M))
    touched = {}
    for f in sorted({c[0] for c in copies}):
        orig = open(f).read()
        L = orig.split('\n')
        mine = sorted([(i, j) for ff, i, j, _ in copies if ff == f], reverse=True)
        inc = f'#include "{cls}.h"'
        for n, (i, j) in enumerate(mine):
            L[i:j + 1] = [inc] if n == len(mine) - 1 and inc not in L else []
        L = [l for l in L if not ((m := re.match(r'extern [^;(]*?\b(\w+)(\[\])?;', l)) and m.group(1) in hsyms)]
        open(f, 'w').write('\n'.join(L))
        touched[f] = orig
    others = [b for b in blocks(cls)[cls] if not b[3]]
    print(f'{cls}: {len(copies)} copies in {len(touched)} units -> include/{cls}.h'
          + (f'; {len(others)} copies with fields/virtuals left for a human' if others else ''))
    return touched


def build():
    out = subprocess.run([f'{R}/tools/bk/mk.sh'], capture_output=True, text=True, cwd=R).stdout
    if 'OK:' in out:
        return None
    log = open(f'{R}/build/bk/build.log').read()
    bad = re.findall(r'\*\*\* \[[^\]]*build/src/(\w+)\.cpp\.o\] Error', log) or \
        re.findall(r'^src/(\w+)\.cpp:\d+: Internal error', log, re.M)
    return bad[0] if bad else 'link'


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return
    if sys.argv[1] == 'list':
        n = int(sys.argv[3]) if len(sys.argv) > 3 else 30
        rows = sorted(((len(v), sum(b[3] for b in v), k) for k, v in blocks().items() if len(v) > 1), reverse=True)
        for total, simple, k in rows[:n]:
            hdr = ' (has include/%s.h)' % k if os.path.exists(f'{R}/include/{k}.h') else ''
            print(f'{total:3} copies, {simple:3} method-only  {k}{hdr}')
        return
    for cls in sys.argv[1:]:
        touched = hoist(cls)
        while touched:
            bad = build()
            if bad is None:
                print(f'{cls}: build matches')
                break
            f = f'{R}/src/{bad}.cpp'
            if f not in touched:
                print(f'{cls}: build fails in {bad} (not a unit this touched): stopping, fix by hand')
                sys.exit(1)
            open(f, 'w').write(touched.pop(f))   # its own version back
            print(f'{cls}: {bad} keeps its own copy (fails with the header)')


if __name__ == '__main__':
    main()
