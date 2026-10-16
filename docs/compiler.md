# Compiler

**Sony EE-GCC 2.96 (`gcc version 2.96-ee-001003-1`), C++, `-O2 -G0 -fno-strict-aliasing -fno-exceptions`, assembled with `as -g` (`-Wa,-g`); the C-style units from CAppMain on (0x1E91B8-0x245648) without `as -g`.**

`-fno-exceptions` added 2026-10-14 (vtables lane 1): with exceptions on, a constructor that
builds a member or base with a constructor gets an EH cleanup region (`__rethrow`,
`terminate__Fv`), and a constructor ending in a call keeps `jal` + `jr` where retail has the
sibcall (`j Clear` in CResNameMgr's 0x145BD0). With the flag, both match, and the whole tree
still matches. The `X() throw();` declarations added earlier for `new X` are no longer needed.

`-Wa,-g` added 2026-10-15 (lane g2): retail was assembled without the assembler's own delay-slot
filling. When GCC leaves a branch or call in `.set reorder` mode (it could not fill the slot itself,
e.g. after a macro such as `la $4,0xCEB0($16)` or `sw $2,0xFC60($16)` for offsets >= 0x8000, or a
`cvt.s.w` before a `b`), our GNU as 2.10 moved the previous instruction into the slot; retail has a
`nop` there. `as -g` turns that reordering off (so does the driver's `-g`, but that also changes the
objects). The whole tree still matches with it, and it fixed CMenuMgr 0x1B5FE0. GAS parses `-O1` as
`-O2` here (`-O00` would also work).

`-fno-strict-aliasing` added 2026-10-14: functions that store through one type and load through
another (0x121A78, 0x1253D0, 0x1087F8), or re-read a global after a store, only match with it,
and the whole tree still matches with it on.
Confirmed 2026-10-13 on eight small functions: all eight match byte for byte with this
compiler and flag set, and no other candidate matches all of them.

The compiler is decomp.me's `ee-gcc2.96` (github.com/decompme/compilers, release
`compilers`), fetched by `scripts/fetch_compilers.sh` into `tools/compilers/ee-gcc2.96/`
and pinned by SHA-256 (`0590d2ca...fd0a`). It is a Linux i386 build: run it inside
bokura-env, which has the 32-bit loader and libraries. The driver runs `cc1plus` and its
own GNU as 2.10-ee, as the original build did.

## dklib's SDK-built units (0x262D28-0x26CFB0): the Sony libraries

Lane d3 (2026-10-15): from 0x262D28 the "dklib" range holds Sony SDK libraries (libcdvd, libmc,
libmtap, libmpeg/libipu: their error strings sit in ro_tail at 0x2E9048-0x2E9900). They were built with
**ee-gcc 2.9-991111** (the SDK compiler, `scripts/fetch_compilers.sh ee-gcc2.9-991111`), `-O2 -G0`
(`-fno-exceptions` for the .cpp front end), strict aliasing on (its -O2 default), as `-g`. The Makefile
builds Dk262D28, Dk2631E0, Dk265918, Dk268138 and Dk26A870 with it (`SDK_OBJS`), and tools/bk/bk.py
follows by address (`SDK_RANGES`; `BK_SDK=<compiler>` overrides it for experiments). Evidence:
- a void function ending in a call is a **frameless** `j callee` (2.96 always keeps the frame:
  `sd ra; ld ra; j`), while `return f();` keeps `jal` + `jr`;
- callee-saved registers go to 16-byte slots (`sd $16,0; sd $31,0x10`); 2.96 packs them 8 bytes apart.
  scripts can classify a whole range by that stride: 2.96 up to 0x262CA0, 991111 from 0x262D28 to
  0x27FBC8, 2.96 again from 0x27FC30;
- an empty `f(const char *, ...)` spills a1-t3 at sp+0x48 in a 0x80 frame and no FPRs (2.96: 0x60 frame
  with FPR spills);
- a pointer loaded once and used for two stores of different types only matches with strict aliasing.
Dk260A60 (the MPEG audio decoder before it) is 2.96 code; it was split at 0x262D28 (new unit
Dk262D28, libcdvd's start) because one object can only have one compiler. INCLUDE_ASM'd functions
assemble the same with 991111's GNU as. The other lanes' units up to 0x27FC30 (Dk26CFB0 ... Dk27DBB8)
show the same 991111 signature; they will need the same switch.
Alignment: library objects start at 16-byte boundaries (0x268D00 after padding nops); a matched
function before one needs `asm(".space 8")`, since `.p2align 4` raises the whole object's alignment.

## libgcc and newlib (0x283858-0x292E20): ee-gcc 2.96 with strict aliasing

Lane w2 (2026-10-16): libgcc (`__pure_virtual`, eh, frame.c, fp-bit) and newlib (stdio, stdlib, math,
mprec) are ee-gcc 2.96 code built **without** `-fno-strict-aliasing` (the game's 2.96 units use it).
The Makefile builds Lib283858, Lib285F80, Lib2888C0, Lib28AE50, Lib28D8B0 and Lib290990 with
`-O2 -G0 -fno-exceptions` (`LIBC_OBJS`), and tools/bk/bk.py follows by address (`LIBC_RANGES`).
Evidence: __register_frame_info (mutex load hoisted above the list stores) and _init_signal_r (table
pointer hoisted out of the clear loop) only match with strict aliasing; everything else in the range
matches either way. The sources stay .cpp (C++ with `return;` after a final void call gives the C
sibcall). Lib290990's tail from 0x292E20 (0x292E20-0x2930A0) is 991111 SDK C and needs its own unit.

Later the same day the C units moved to the C front end (`-x c`, Makefile `LIBC_C_OBJS`: Lib283858,
Lib2888C0, Lib28AE50, Lib28D8B0, Lib290990; bk.py `LIBC_C_RANGES`). Evidence: libgcc2's __throw and
__rethrow use `__builtin_dwarf_cfa`/`__builtin_eh_return`, which cc1plus does not know; and several
newlib/fp-bit functions that were stuck one instruction off as C++ (`bnez` vs `bnezl` after a call:
dpdiv, lo0bits) match as C. Every already-matched function stayed identical except three whose last
statement is a call that retail does not turn into a sibcall (__register_frame_info,
__register_frame_info_table, abort with its noreturn exit): those end in `__asm__("");` after the call.
Lib285F80 stays C++: it mixes frame.c with tinfo.cc (C++ classes) and fp-bit.
Dk280098 (newlib libm float functions plus libgcc2's __muldi3 at 0x281B20) joined `LIBC_C_OBJS`
too (bk.py `LIBC_C_RANGES` 0x280098-0x2828C0): __muldi3 matches only as C (head's upstream match:
libgcc2.c L_muldi3), and all the already-matched libm functions stayed identical as C with strict
aliasing.

Dk260A60 (the MPEG audio decoder, 2.96) is assembled without `as -g` too (Makefile ASG, bk.py asg):
0x262B18 ends with a 24-byte unaligned struct copy, and retail has its last `sdr` in the `jr` delay slot,
which only gas's own reordering produces (GCC emits the sdl/sdr pair as one insn). All other matched
Dk260A60 functions are identical either way.

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
- `.eh_frame` is only 0x904 bytes and `.gcc_except_table` 0x7C: the game units were built
  with `-fno-exceptions` (confirmed by constructors, see above); the build discards
  `.eh_frame` in the linker script.

## Assembler

Units are assembled by ee-gcc's own GNU as 2.10-ee, including the INCLUDE_ASM'd
functions. That assembler only knows numeric register names, so the splat yaml sets
`named_regs_for_c_funcs: False`. Checked on the whole of `.text` (split into chunks):
identical output to decompals' binutils except for VU0 macro-mode instructions
(`vmulaw`, `vmadda`, `vopmula`, `vmulax`, `vmadday`, ...), whose spimdisasm syntax it
rejects. A unit containing such a function needs those instructions as `.word`s or a
syntax rewrite (not needed yet). Modern GNU as is not a drop-in replacement: it encodes
`move` as `or` (retail: `daddu`) and adds COP1 hazard `nop`s.
