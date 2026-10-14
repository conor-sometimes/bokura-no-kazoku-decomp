# Bokura no Kazoku decomp (private)

<!-- progress:start -->
**Progress** (functions in C++ (of all .text), 2026-10-14):

`█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░` **4.68%** of code bytes (79,536 / 1,700,400)  
`████░░░░░░░░░░░░░░░░░░░░░░░░░░` **13.57%** of functions (980 / 7,223)  
Game code alone (the 2,303 functions in the C++ units): 980 matched, 8.34% of its bytes.
<!-- progress:end -->

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
| Compiler | Sony EE-GCC 2.96 (`2.96-ee-001003-1`), `-O2 -G0 -fno-strict-aliasing`: confirmed on 8 functions (docs/compiler.md) |
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

## Plan

See GOALS.md.

## Lessons learned

Project gotchas live in [docs/lessons.md](docs/lessons.md): read it before matching, and add to it
whenever something here takes more than a few minutes to figure out.

## Licence

Our code (sources, scripts, tooling) is licensed under the GNU General Public License v3.0 or later (see [LICENSE](LICENSE)). The game itself, and anything extracted from the disc, belongs to its owners and is never part of this repository: you supply your own copy.
