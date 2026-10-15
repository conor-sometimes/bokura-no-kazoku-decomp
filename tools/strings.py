#!/usr/bin/env python3
"""strings.py: pull every piece of Japanese text out of the game, one TSV per source file, ready to
translate line by line.

  python3 -I tools/strings.py EXTRACTED ELF [OUT]      (OUT defaults to strings/, gitignored)
  python3 -I tools/strings.py save [OUT]               (copy the en column into translation/en/)

EXTRACTED is the folder tools/xap.py extracted the archives into; ELF is disc/SCPS_150.88.
The output is game text, so it never goes into git.

Layout of OUT (UTF-8, tab-separated, one row per string):
- `<path>.mes.tsv` for each message file: `label  timing  jp  en`. All dialogue and event text.
  In `jp`, `@n` is a line break in the window, `$MAIN$` / `$USER$` are names filled in at runtime,
  and ` / ` joins the source lines of one entry. The .scb scripts look messages up by label, so a
  translation can be any length.
- `<path>.txt.tsv` for each other text file with Japanese in it (menus, windows, databases):
  `line  jp  en`, `line` being the line number in the original file.
- `elf.tsv`: the few Shift-JIS strings in the boot ELF: `address  bytes  jp  en`; `bytes` is the
  space the string has (with its NUL), so a longer translation has to move.
- `INDEX.tsv`: every file with its string count and how many have an `en` filled in.

Translations live in git under `translation/en/<path>.tsv` (`key  jp_sha1  en`): no Japanese, only
the key, the first 8 hex digits of the Japanese text's SHA-1 (to notice when it changes) and the
English. `save` writes them from strings/; extraction fills `en` back in from them.
In `en`, use `@n` for line breaks and keep `$MAIN$`/`$USER$`/`$OTO$` names; speakers as
`Name: "..."`.

Re-running keeps translations: an `en` cell already filled in is carried over when its key
(label, line number or address) and `jp` text are unchanged; changed rows are listed at the end.
"""
import hashlib
import os
import re
import struct
import sys

KANA = re.compile(r'[ぁ-ヺ]')
JP = re.compile(r'[぀-ヿ㐀-鿿＀-￯　-〿]')


def sjis(b):
    return b.decode('cp932', 'replace')


def mes_entries(text):
    label, timing, lines = None, '', []
    for raw in text.split('\n'):
        line = raw.rstrip('\r')
        if not line.strip() or line.startswith('#'):
            continue
        if line[0] in '\t ':
            lines.append(line.strip())
            continue
        if label is not None:
            yield label, timing, lines
        head = [p.strip() for p in line.split(',', 1)]
        label, timing, lines = head[0], head[1] if len(head) > 1 else '', []
    if label is not None:
        yield label, timing, lines


def elf_strings(path):
    d = open(path, 'rb').read()
    shoff, = struct.unpack_from('<I', d, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from('<HHH', d, 0x2E)
    secs = [struct.unpack_from('<IIIIII', d, shoff + i * shentsize) for i in range(shnum)]
    names = secs[shstrndx]
    for s in secs:
        name = d[names[4] + s[0]:].split(b'\0', 1)[0].decode()
        if name not in ('.rodata', '.data', '.sdata'):
            continue
        addr, off, size = s[3], s[4], s[5]
        blob = d[off:off + size]
        for m in re.finditer(rb'(?:[\x81-\x9f\xe0-\xfc][\x40-\xfc]|[\x09\x0a\x20-\x7e\xa1-\xdf]){2,}\x00', blob):
            t = sjis(m.group()[:-1])
            # real text has full-width kana and no stray half-width kana (those are float/pointer bytes)
            if ('�' not in t and KANA.search(t) and len(JP.findall(t)) >= 2
                    and not re.search('[｡-ﾟ]', t)):
                yield addr + m.start(), len(m.group()), t


# Plain TSV: one row per line, tab-separated, no quoting (the text never contains tabs or newlines),
# so `"` stays `"` and diffs stay readable.
class TsvWriter:
    def __init__(self, f):
        self.f = f

    def writerow(self, r):
        self.f.write('\t'.join(str(c) for c in r) + '\n')

    def writerows(self, rows):
        for r in rows:
            self.writerow(r)


def read_tsv(path):
    if not os.path.exists(path):
        return []
    with open(path) as f:
        return [l.rstrip('\n').split('\t') for l in f][1:]


TRANS = 'translation/en'


def jp_hash(t):
    return hashlib.sha1(t.encode()).hexdigest()[:8]


def write_tsv(path, header, rows, old_rows, changed, git_rows=()):
    """rows: (key, ..., jp); keeps the old `en` (last column) where key and jp are unchanged,
    from strings/ first, then from translation/en/ (key, jp hash, en)."""
    old = {(r[0], r[-2]): r[-1] for r in old_rows if len(r) >= 2 and r[-1]}
    saved = {(r[0], r[1]): r[2] for r in git_rows if len(r) >= 3}
    for r in rows:
        if (r[0], r[-1]) not in old and (r[0], jp_hash(r[-1])) in saved:
            old[(r[0], r[-1])] = saved[(r[0], jp_hash(r[-1]))]
    old_keys = {r[0]: r[-2] for r in old_rows if r and r[-1]}
    saved_keys = {k for k, _ in saved}
    os.makedirs(os.path.dirname(path) or '.', exist_ok=True)
    done = 0
    with open(path, 'w', newline='') as f:
        w = TsvWriter(f)
        w.writerow(header)
        for r in rows:
            en = old.get((r[0], r[-1]), '')
            if not en and ((r[0] in old_keys and old_keys[r[0]] != r[-1]) or r[0] in saved_keys):
                changed.append(f'{path}: {r[0]}')
            done += bool(en)
            w.writerow(list(r) + [en])
    return done


def git_path(out, dst):
    return os.path.join(TRANS, os.path.relpath(dst, out))


def save(out):
    n = files = 0
    for dp, _, fs in os.walk(out):
        for fn in sorted(fs):
            if not fn.endswith('.tsv') or fn == 'INDEX.tsv':
                continue
            src = os.path.join(dp, fn)
            rows = [(r[0], jp_hash(r[-2]), r[-1]) for r in read_tsv(src) if len(r) >= 2 and r[-1]]
            dst = git_path(out, src)
            if not rows:
                if os.path.exists(dst):
                    os.remove(dst)
                continue
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            with open(dst, 'w', newline='') as f:
                w = TsvWriter(f)
                w.writerow(['key', 'jp_sha1', 'en'])
                w.writerows(rows)
            n += len(rows)
            files += 1
    print(f'saved {n} translations in {files} files under {TRANS}/')


def main():
    if sys.argv[1] == 'save':
        return save(sys.argv[2] if len(sys.argv) > 2 else 'strings')
    root, elf = sys.argv[1], sys.argv[2]
    out = sys.argv[3] if len(sys.argv) > 3 else 'strings'
    index, changed = [], []

    for dp, _, fs in sorted(os.walk(root)):
        for fn in sorted(fs):
            p = os.path.join(dp, fn)
            rel = os.path.relpath(p, root)
            if fn.endswith('.mes'):
                rows = []
                for label, timing, lines in mes_entries(sjis(open(p, 'rb').read())):
                    rows.append((label, timing, ' / '.join(l for l in lines if l != ',')))
                if not rows:
                    continue
                dst = os.path.join(out, rel + '.tsv')
                rows2 = [(r[0], r[1], r[2]) for r in rows]
                done = write_tsv(dst, ['label', 'timing', 'jp', 'en'],
                                 [(a, b, c) for a, b, c in rows2], read_tsv(dst), changed, read_tsv(git_path(out, dst)))
                index.append((rel, 'mes', len(rows), done))
            elif fn.endswith('.txt') and not fn.endswith('.utf8.txt'):
                rows = []
                for i, line in enumerate(sjis(open(p, 'rb').read()).split('\n'), 1):
                    line = line.rstrip('\r')
                    if JP.search(line) and not line.lstrip().startswith(('#', '//')):
                        rows.append((str(i), line))
                if not rows:
                    continue
                dst = os.path.join(out, rel + '.tsv')
                done = write_tsv(dst, ['line', 'jp', 'en'], rows, read_tsv(dst), changed, read_tsv(git_path(out, dst)))
                index.append((rel, 'txt', len(rows), done))

    dst = os.path.join(out, 'elf.tsv')
    rows = [(f'0x{a:06X}', str(n), t.replace('\n', '\\n')) for a, n, t in elf_strings(elf)]
    done = write_tsv(dst, ['address', 'bytes', 'jp', 'en'], rows, read_tsv(dst), changed, read_tsv(git_path(out, dst)))
    index.append(('SCPS_150.88', 'elf', len(rows), done))

    with open(os.path.join(out, 'INDEX.tsv'), 'w', newline='') as f:
        w = TsvWriter(f)
        w.writerow(['file', 'kind', 'strings', 'translated'])
        w.writerows(index)
    for kind in ('mes', 'txt', 'elf'):
        rows = [r for r in index if r[1] == kind]
        print(f'{kind}: {sum(r[2] for r in rows):,} strings in {len(rows):,} files, '
              f'{sum(r[3] for r in rows):,} translated')
    if changed:
        print(f'{len(changed)} translated rows whose Japanese changed (kept out, re-check):')
        for c in changed[:20]:
            print('  ' + c)


if __name__ == '__main__':
    main()
