# Compiler

**Sony EE-GCC 2.96 (`gcc version 2.96-ee-001003-1`), C++, `-O2 -G0`.**
Confirmed 2026-10-13 on eight small functions: all eight match byte for byte with this
compiler and flag set, and no other candidate matches all of them.

The compiler is decomp.me's `ee-gcc2.96` (github.com/decompme/compilers, release
`compilers`), fetched by `scripts/fetch_compilers.sh` into `tools/compilers/ee-gcc2.96/`
and pinned by SHA-256 (`0590d2ca...fd0a`). It is a Linux i386 build: run it inside
bokura-env, which has the 32-bit loader and libraries. The driver runs `cc1plus` and its
own GNU as 2.10-ee, as the original build did.

## Evidence

Each function was written as C++, compiled with each candidate, and compared with the
retail bytes (relocated fields masked). Test sources lived in /tmp; the eight functions
were:

| Address  | Function                                  | What it tests |
| -------- | ----------------------------------------- | ------------- |
| 0x1300E8 | `return m_field5F0;`                      | leaf getter, load in `jr` delay slot |
| 0x145698 | `return a == 9;`                          | `xori` + `sltiu` |
| 0x178928 | `x = nx; y = ny;` (two float members)     | store scheduling (second store first) |
| 0x10CDA8 | `return D_002A0398;`                      | global via `lui`/`lw`, so `-G0` |
| 0x1438D8 | `r = v < hi ? v : hi; return r < lo ? lo : r;` | `movn`, `daddu` for `move` |
| 0x1300F0 | `return m_value.AsInt();`                 | sibling call with the frame left in place |
| 0x143910 | `return x < 0 ? -x : x;`                  | branch shape |
| 0x1439E0 | `return x >= 0.0f ? x : -x;`              | float compare + `bc1fl` |

| Compiler                               | -O2 -G0 | -O1 -G0 | -O3 -G0 | -O2 -G8 | -Os -G0 |
| -------------------------------------- | ------- | ------- | ------- | ------- | ------- |
| **ee-gcc2.96** (2.96-ee-001003-1)      | **8/8** | 4/8     | 8/8     | 7/8     | 6/8     |
| ee-gcc2.9-991111 / -991111a / -991111-01 | 5/8   | 3/8     | 5/8     | 4/8     | 4/8     |
| ee-gcc2.9-990721                       | 5/8     | 3/8     | 5/8     | 4/8     | 4/8     |
| SN ee-gcc 2.95.2-273a/274, 2.95.3-107/114/136 (Wine) | 6/8 | 4/8 | 6/8 | - | - |
| ee-gcc3.2-040921                       | 2/8     | 2/8     | 2/8     | 2/8     | 2/8     |

Notes:
- `-O3` also matches these eight; it only differs by inlining (`-finline-functions`).
  `-O2 -G0` is also what Sony's SDK sample makefiles are remembered to use (not checked
  against an SDK copy), so it is the working assumption until a function shows otherwise.
- Game globals are reached with `lui`/`lw`, never `$gp`, so the game code is `-G0`
  (the SDK libraries may differ; they are not decompiled).
- gcc 3.2 is out anyway: the RTTI names in the binary use the GCC 2.x mangling
  (`t6TArray3Z14CSceneCharaSeti_16_Z...`).
- 2.96 makes sibling calls in C++ only when the callee's value is returned: a `void`
  function ending in a call keeps `jal` + `jr $ra`, a value-returning one becomes the
  "frame kept, `j callee`" shape. That is a matching hint for the return types.
- `.eh_frame` is only 0x904 bytes and `.gcc_except_table` 0x7C, so most game units were
  probably built with `-fno-exceptions`. The build currently uses the default
  (exceptions on) and discards `.eh_frame` in the linker script; revisit when a unit with
  EH data is decompiled.

## Assembler

Units are assembled by ee-gcc's own GNU as 2.10-ee, including the INCLUDE_ASM'd
functions. That assembler only knows numeric register names, so the splat yaml sets
`named_regs_for_c_funcs: False`. Checked on the whole of `.text` (split into chunks):
identical output to decompals' binutils except for VU0 macro-mode instructions
(`vmulaw`, `vmadda`, `vopmula`, `vmulax`, `vmadday`, ...), whose spimdisasm syntax it
rejects. A unit containing such a function needs those instructions as `.word`s or a
syntax rewrite (not needed yet). Modern GNU as is not a drop-in replacement: it encodes
`move` as `or` (retail: `daddu`) and adds COP1 hazard `nop`s.
