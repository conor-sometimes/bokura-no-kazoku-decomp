# Text and translation notes

Groundwork for an eventual English patch. `tools/strings.py` pulls every piece of Japanese text
into `strings/` (gitignored: it is game text), one TSV per source file with an empty `en` column to
translate line by line:

    python3 -I tools/xap.py extract DATA/*.XAP -o EXTRACTED      # unpack the archives first
    python3 -I tools/strings.py EXTRACTED disc/SCPS_150.88       # writes strings/

Translations are kept in git under `translation/en/` (same paths as `strings/`, columns
`key  jp_sha1  en`): no Japanese, just the label (or line number / address), the first 8 hex digits
of the Japanese text's SHA-1, so a changed source line is noticed, and the English. Translate in
`strings/`, then `python3 -I tools/strings.py save` writes `translation/en/`; commit that.
Extraction fills `en` back in from `translation/en/`.

Conventions for `en`: `@n` for each line break the window should make (re-wrap freely; the
Japanese breaks are only a guide), keep `$MAIN$`/`$USER$`/`$OTO$` as they are, speaker lines as
`Chiko: "..."`, `...` for 「…」 pauses, plain ASCII quotes.

`strings/INDEX.tsv` lists every file with its string count and how many are translated. Re-running
keeps filled-in `en` cells (matched by label / line number / address and the Japanese), and lists
any translated row whose Japanese changed. Counts from the retail disc:

| Source | Strings | Files | What |
|---|---:|---:|---|
| `*.mes` message files | 4,538 | 1,510 | all dialogue and event text, plus `gamemes` (outcome messages) |
| `*.txt` text files | 4,833 lines | 60 | menus and windows (`menures/`, `menu/`), the name-entry kanji list, quiz data (`minig/`), the game databases (`gamedb/`: per-character event lines, books, schools), the name database |
| boot ELF | 11 | 1 | the title, stat abbreviations, a default name, the name-entry kana grid |

## Formats

- **`.mes`** (Shift-JIS text): an entry is a label line (`<event>_<nn>`, optionally followed by
  `, <seconds>` for voiced lines), then tab-indented text lines. `@n` is a line break inside the
  window, `$MAIN$` and `$USER$` are names substituted at runtime, a line holding only `,` marks a
  voice timing split. `#` starts a comment. One `.mes` sits next to each event script.
- **`.scb`** (compiled event scripts, `GSCD` header): refer to message labels by name, not by
  offset, so translated text can be any length. The opcode table is `sysinc/system.inc`.
- **`.txt`**: Shift-JIS, `#` comments; layouts vary per file (key=value, CSV-like tables,
  `[section]` blocks).
- **ELF**: almost no Japanese in code; the few strings are in `.data`/`.rodata` with fixed sizes
  (`bytes_with_nul` in `elf.tsv`), so a longer English string has to move.

## What limits an English patch

- **Font**: `font/font20.moj` ("MOJI" header, 0xE61 = 3,681 glyphs, 20 px) plus the glyph texture
  `font20.xim`. Still to check: whether it has half-width Latin letters and how wide each glyph is
  drawn (a fixed full-width advance would make English look spaced out; the usual fix is a
  variable-width or half-width table in the text renderer).
- **Vertical text**: `font/vcode.txt` maps punctuation to vertical-writing forms, so some windows
  draw text top to bottom; English there needs those windows switched to horizontal.
- **Window size**: message windows wrap at `@n` by hand; English lines need re-wrapping to the
  window width.
- **Text in images**: some of the 4,797 `.tm2` textures probably carry drawn Japanese (title,
  menu and minigame screens; not checked yet); those need image edits, not string edits.
- **Repacking**: `tools/xap.py` extracts but does not yet rebuild archives; a packer (with the
  game's LZ compression or stored uncompressed, if the loader allows) is the first tool to write.
