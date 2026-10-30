# Bokura no Kazoku decomp

<!-- status:begin -->
![functions](https://img.shields.io/badge/functions-6404%2F7223-blue) ![bytes](https://img.shields.io/badge/bytes-50.1%25-orange) ![build](https://img.shields.io/badge/build-byte--for--byte-brightgreen)

Progress, 2026-10-16 (functions in C; the rest is still INCLUDE_ASM):

| | Progress | |
|---|---|---|
| **Functions** | `██████████████████████░░░` | 6,404 / 7,223 (88.7%) |
| **Code bytes** (`.text`, 1.70 MB) | `█████████████░░░░░░░░░░░░` | 851.6 KB / 1700.4 KB (50.1%) |
| &nbsp;&nbsp;Game code, C++ units (954 KB, classes found from vtables and RTTI) | `██████████░░░░░░░░░░░░░░░` | 1,979 / 2,303 functions, 40.3% of bytes |
| &nbsp;&nbsp;Game code, C-style units (378 KB, CAppMain on: renderer, files, sound, IOP) | `█████████████░░░░░░░░░░░░` | 1,960 / 2,264 functions, 52.2% of bytes |
| &nbsp;&nbsp;dklib engine library (254 KB, heap, tasks, resources, scripts; part Sony SDK) | `████████████████░░░░░░░░░` | 1,318 / 1,483 functions, 65.4% of bytes |
| &nbsp;&nbsp;Libraries (113 KB, libgcc, newlib, Sony SDK, linkonce code) | `███████████████████████░░` | 1,147 / 1,169 functions, 91.2% of bytes |
| Stuck ([HARD.md](HARD.md), with their exact diffs) | | 819 |

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

## Disc (recon)

| | |
| --- | --- |
| Serial / boot ELF | `SCPS_150.88` (SYSTEM.CNF: `cdrom0:\SCPS_150.88;1`, VER 1.00, NTSC) |
| ELF | 2,018,020 bytes, statically linked, stripped, built 2005-01-28 (file dates) |
| SDK | 2.8 era (`MODULES/IOPRP280.IMG`), Sony libraries (libsd, libmc, libpad, libmtap, libmpeg, libgraph) |
| Language | C++: GCC 2.9x name mangling, `.eh_frame` + `.gcc_except_table` |
| Compiler | Sony EE-GCC 2.96 (`2.96-ee-001003-1`), `-O2 -G0 -fno-strict-aliasing -fno-exceptions`, `as -g` for the C++ units and dklib; the C-style units without `as -g`; parts of dklib and the Sony SDK with ee-gcc 2.9-991111 / -01 ([docs/compiler.md](docs/compiler.md)) |
| VU code | `.vutext` / `.vudata` (VU microcode, `dvp-as`): stays assembly |
| Game data | `DATA/*.XAP` archives (MAP 140 MB, CHR 86 MB, ENV 33 MB, MENU 18 MB, ...) |

`.text` starts at 0x100000 (~1.6 MB of code); no debug info is left (`.mdebug.eabi64` is empty).

## Environment

`bokura-env` from [workbench](https://github.com/conor-sometimes/workbench):
[projects/bokura-no-kazoku/default.nix](https://github.com/conor-sometimes/workbench/blob/main/projects/bokura-no-kazoku/default.nix),
built on the shared [lib/mkDecompEnv.nix](https://github.com/conor-sometimes/workbench/blob/main/lib/mkDecompEnv.nix):
an FHS environment with gcc multilib, Python and the permuter's packages.

## Build

You need your own disc image; nothing from it is committed.

```sh
.bokura-env/bin/bokura-env -c './setup.sh path/to/bokura.iso'   # venv, ELF from the ISO (SHA-1 checked)
.bokura-env/bin/bokura-env -c 'make -j'                          # split, assemble, link, compare
```

`make` ends with `OK: build/SCPS_150.88 matches (...)` or a `FAIL:` line. Python tools are pinned
in `requirements.txt`; the R5900 binutils (decompals v0.10) come from bokura-env. The flat image
from the linker is wrapped in the retail ELF container by `scripts/mkelf.py`.

## Two builds

1. **Matching**: rebuilds the main ELF byte-for-byte. The reference.
2. **Mod**: a shiftable build from the same sources, for tweaks.

## Roadmap

Tracked with done-signals in GOALS.md. Each phase builds on the one before.

1. **Matching decompilation** (in progress — see the status above). Every function as C that rebuilds the original executable byte for byte. What is left is the large game code, units whose data still comes from assembly, and the stuck tail in HARD.md.
2. **Mod build.** The same sources built without the byte-for-byte constraint — every pointer a symbol, so code and data can move. The base for everything below.
3. **English translation patch.** Strings are mapped and extracted per file (`tools/strings.py`, `translation/en/`, [docs/translation.md](docs/translation.md)); still needs an archive repacker, a font/width pass, and the translation itself. Ships as a delta against your own disc.
4. **Native PC port** (long term). With the logic in C and the Sony SDK layers already isolated, the game can target PC with the GS/VIF/VU, SPU2/IOP and pad layers swapped out. Needs the mod build first.

None of this ships game code or assets: every build and patch starts from your own disc.

## Lessons learned

Project gotchas live in [docs/lessons.md](docs/lessons.md): read it before matching, and add to it
whenever something takes more than a few minutes to figure out.

## Licence

Our code (sources, scripts, tooling) is licensed under the GNU General Public License v3.0 or later (see [LICENSE](LICENSE)). The game itself, and anything extracted from the disc, belongs to its owners and is never part of this repository: you supply your own copy.
