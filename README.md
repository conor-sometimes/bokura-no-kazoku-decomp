# Bokura no Kazoku decomp (private)

<!-- status:begin -->
![functions](https://img.shields.io/badge/functions-6173%2F7223-blue) ![bytes](https://img.shields.io/badge/bytes-45.5%25-orange) ![build](https://img.shields.io/badge/build-byte--for--byte-brightgreen)

Progress, 2026-10-16 (functions in C; the rest is still INCLUDE_ASM):

| | Progress | |
|---|---|---|
| **Functions** | `█████████████████████░░░░` | 6,173 / 7,223 (85.5%) |
| **Code bytes** (`.text`, 1.70 MB) | `███████████░░░░░░░░░░░░░░` | 773.0 KB / 1700.4 KB (45.5%) |
| &nbsp;&nbsp;Game code, C++ units (954 KB, classes found from vtables and RTTI) | `█████████░░░░░░░░░░░░░░░░` | 1,918 / 2,303 functions, 36.2% of bytes |
| &nbsp;&nbsp;Game code, C-style units (378 KB, CAppMain on: renderer, files, sound, IOP) | `████████████░░░░░░░░░░░░░` | 1,871 / 2,264 functions, 47.4% of bytes |
| &nbsp;&nbsp;dklib engine library (254 KB, heap, tasks, resources, scripts; part Sony SDK) | `███████████████░░░░░░░░░░` | 1,267 / 1,483 functions, 60.7% of bytes |
| &nbsp;&nbsp;Libraries (113 KB, libgcc, newlib, Sony SDK, linkonce code) | `█████████████████████░░░░` | 1,117 / 1,169 functions, 83.4% of bytes |
| Stuck ([HARD.md](HARD.md), with their exact diffs) | | 1,042 |

Build: Sony EE-GCC 2.96 for the game; parts of dklib and the Sony SDK were built with older
SDK compilers (ee-gcc 2.9-991111 and -01), set per unit ([docs/compiler.md](docs/compiler.md)).
<!-- status:end -->

Target: **Bokura no Kazoku - My Family Growing Up in the 21st Century (Japan)**,
Redump dump. PS2 (Emotion Engine, MIPS R5900).

## Disc image

Check your dump against these (Redump's formats plus SHA-256); `setup.sh` itself verifies the boot executable it extracts:

| File | Size | CRC32 | MD5 | SHA-1 | SHA-256 |
| --- | ---: | --- | --- | --- | --- |
| `Bokura no Kazoku - My Family Growing Up in the 21st Century (Japan).iso` | 2,091,941,888 | `9d389b7c` | `ab2edd392d190f21b2112d67219d4ea5` | `f2a8187457148a66fbbb3841032fe430cb5572d4` | `b9b5d3a131bfd6fab9a718b5875e504e014cc52287db9d68d44947e930ae9fca` |

The boot executable inside it, `SCPS_150.88`: SHA-1 `621ffd58de52794eaa3d33885ba1288f36e19365`.

## Disc (recon, 2026-10-13)

| | |
| --- | --- |
| Serial / boot ELF | `SCPS_150.88` (SYSTEM.CNF: `cdrom0:\SCPS_150.88;1`, VER 1.00, NTSC) |
| ISO | 2,091,941,888 bytes, SHA-1 `f2a8187457148a66fbbb3841032fe430cb5572d4` (check against Redump) |
| ELF | 2,018,020 bytes, SHA-1 `621ffd58de52794eaa3d33885ba1288f36e19365`, statically linked, stripped |
| Built | 2005-01-28 (file dates) |
| SDK | 2.8 era (`MODULES/IOPRP280.IMG`), Sony libraries (libsd, libmc, libpad, libmtap, libmpeg, libgraph) |
| Language | C++: GCC 2.9x name mangling (`t6TArray3Z14CSceneCharaSeti_16_Z...`), `.eh_frame` + `.gcc_except_table` |
| Compiler | Sony EE-GCC 2.96 (`2.96-ee-001003-1`), `-O2 -G0 -fno-strict-aliasing -fno-exceptions`, `as -g` for the C++ units and dklib; the C-style units without `as -g`; parts of dklib and the Sony SDK with ee-gcc 2.9-991111 / 2.9-991111-01 (docs/compiler.md) |
| VU code | `.vutext` / `.vudata` (VU microcode, `dvp-as`): stays assembly |
| Game data | `DATA/*.XAP` archives (MAP 140 MB, CHR 86 MB, ENV 33 MB, MENU 18 MB, ...) |

ELF sections: `.text` from 0x100000 (about 1.6 MB of code), `.data`, `.rodata`,
`.sbss`, `.bss`. No debug info left (`.mdebug.eabi64` is empty); worth a ccc
`stdump` pass anyway, and on any other ELF/IRX.

## Environment

`bokura-env` from [decomp-nix](https://github.com/conor-sometimes/decomp-nix):
[projects/bokura-no-kazoku/default.nix](https://github.com/conor-sometimes/decomp-nix/blob/main/projects/bokura-no-kazoku/default.nix),
built on the shared [lib/mkDecompEnv.nix](https://github.com/conor-sometimes/decomp-nix/blob/main/lib/mkDecompEnv.nix):
an FHS environment with gcc multilib, Python and the permuter's packages. Builds run on hokkaido.
Recon came from the `decomp-recon` skill.

## Build

You need your own disc image; nothing from it is committed.

```sh
.bokura-env/bin/bokura-env -c './setup.sh path/to/bokura.iso'   # venv, ELF from the ISO (SHA-1 checked)
.bokura-env/bin/bokura-env -c 'make -j'                          # split, assemble, link, compare
```

`make` ends with `OK: build/SCPS_150.88 matches (...)` or a `FAIL:` line. Python tools are pinned
in `requirements.txt`; the R5900 binutils (decompals v0.10) come from bokura-env. The flat image
from the linker is wrapped in the retail ELF container by `scripts/mkelf.py` (header values from
`readelf -lS`).

## Two builds

1. **Matching**: rebuilds the main ELF byte-for-byte. The reference.
2. **Mod**: shiftable build from the same sources for tweaks.

## Roadmap

Where this is going, in order. Phases overlap; each builds on the one before. Milestones and
their done-signals are tracked in GOALS.md.

1. **Matching decompilation** (in progress, see the status above). Every function as C that
   rebuilds the original executable byte for byte. The whole of `.text` after crt0 is already
   split into source units; what is left is the large game code (menus and screens built on the
   `state.h` state machines, draw routines, minigames), units whose data still comes from
   assembly, and a tail of stuck functions recorded in HARD.md with their exact diffs.
2. **Mod build.** The same sources built without the byte-for-byte constraint: every pointer a
   symbol, so code and data can grow and move. Needs most functions in C and the data
   (vtables, .rodata, tables) described in C, not complete matching. This is the base for
   everything below.
3. **English translation patch.** Groundwork is done: all ~9,400 strings (~280k Japanese
   characters) are mapped, `tools/strings.py` extracts them per file for line-by-line
   translation, and translations are kept in `translation/en/` without any Japanese
   ([docs/translation.md](docs/translation.md)). The dialogue lives in plain-text message files
   that scripts look up by label, so English can be any length. Still needed:
   - an archive repacker (`tools/xap.py` extracts; it doesn't rebuild yet);
   - a font check (Latin glyphs, glyph widths, how the renderer advances) and a fix if needed;
   - message window widths and a re-wrap rule; vertical-text windows switched to horizontal;
   - textures with drawn-in Japanese, edited;
   - the ISO rebuilt with the patched archives;
   - then the translation itself, file by file, with a shared glossary.
   The patch ships as a delta against the user's own disc, never as game data.
4. **Native PC port** (long term). With the game logic in C, it can be compiled for a PC instead
   of the PS2, with the hardware layers replaced: the GS/VIF/VU graphics path by a modern
   renderer, the SPU2/IOP sound and file I/O by host equivalents, pads by SDL. The Sony SDK
   code (already isolated in its own units) is exactly what a port swaps out. Prior art: the
   PS1/N64/PS2 decomps that grew PC ports. Requires the mod build first, and likely widescreen
   and higher resolution as early wins.

Like the decomp itself, none of this ships game code or assets: every build and patch starts
from your own disc.

## Lessons learned

Project gotchas live in [docs/lessons.md](docs/lessons.md): read it before matching, and add to it
whenever something here takes more than a few minutes to figure out.

## Licence

Our code (sources, scripts, tooling) is licensed under the GNU General Public License v3.0 or later (see [LICENSE](LICENSE)). The game itself, and anything extracted from the disc, belongs to its owners and is never part of this repository: you supply your own copy.
