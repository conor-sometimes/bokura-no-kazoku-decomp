# Project profile

This file is the project's profile for the code rules in [docs/code-rules.md](docs/code-rules.md). The
rules say what reconstructed source must look like before a function counts as matched; this file fills
in what they leave to the project. Where the two disagree, this file wins.

Read [docs/lessons.md](docs/lessons.md) before matching and [docs/units.md](docs/units.md) before
touching a unit's data.

## What counts as matched

`make` proves the bytes: the rebuilt `SCPS_150.88` has retail's SHA-1, so every function written in C
is byte-identical. That is necessary, not sufficient. A function counts as **matched** when its bytes
match **and** it passes every [match] rule (R1, R2, R4, R13, R17, R18). Byte-identical but failing is
**MATCH-PENDING**: it is reported, and not counted.

```sh
python3 -I tools/bk/rules.py             # both numbers, and what each rule holds back
python3 -I tools/bk/rules.py --pending UNIT   # the MATCH-PENDING functions of a unit
python3 -I tools/bk/rules.py -v UNIT     # every finding in a unit, one per line
```

The headline figure is **matched under the rules**. Bytes matched is reported beside it.

## Compilers and dialect (R22)

Per unit, as the Makefile sets them ([docs/compiler.md](docs/compiler.md) has the evidence):

| units | compiler | language |
|---|---|---|
| game code (`C*.cpp`, `I*.cpp`, `Unit*.cpp`), most of dklib (`Dk*.cpp`) | Sony EE-GCC 2.96 (`2.96-ee-001003-1`), `-O2 -G0 -fno-strict-aliasing -fno-exceptions` | C++ |
| `SDK_OBJS` (dklib from 0x262D28) | ee-gcc 2.9-991111 | C++ |
| `SDKC_OBJS` (Sony SDK libraries) | ee-gcc 2.9-991111-01, `-x c` | C |
| `LIBC_OBJS` (libgcc, tinfo) | EE-GCC 2.96, strict aliasing on | C++ |
| `LIBC_C_OBJS` (libgcc2, newlib) | EE-GCC 2.96, `-x c` | C |

Every source file is named `.cpp`; the Makefile decides the front end. Write only what that front end
accepts:

- C++ units are pre-standard g++ 2.9x: no `nullptr`, `auto`, `enum class`, range `for`, `override`, or
  anything from C++11 on. No exceptions in game code (`-fno-exceptions`).
- C units (`-x c`) are C89 with the GNU extensions the upstream library source already uses.
  Old-style (K&R) definitions stay old-style where upstream has them: the style decides how the
  callee reads `float` and `char` parameters (R25).
- No `stdint.h` or `stdbool.h`: the fixed-width names are `s8`…`u64`, `f32` from `include/common.h`
  (`long` is 64 bits on the EE). Use `bool` only where the evidence shows `bool` (R6).
- GNU extensions the tree relies on: `asm("symbol")` labels on declarations, `__asm__` statements, and
  `register T x asm("$n")`. Each is a finding to justify, not a tool to reach for (see "Rule changes").

## Annotations and parking

- **Not matched yet:** `INCLUDE_ASM("asm/nonmatchings/<Unit>", <symbol>);` at the function's place in
  its unit. It is the project's parking mechanism: the function is not counted, and R18 does not apply
  to it.
- **Data still in assembly:** `INCLUDE_RODATA("asm/nonmatchings/<Unit>", <symbol>);`
  ([docs/units.md](docs/units.md)).
- **Names:** every renamed function is in `config/symbol_addrs.txt` (`Name__mangled = 0xADDR; //
  type:func`); vtables and typeinfo functions are in `config/vtables.txt`.
- **Stuck functions:** the best attempt goes to `docs/hard/<lane>/hard_<ADDR>.snip`, its diff to
  `HARD.md`. An attempt is never parked in the unit behind `#if 0` (R37): the twelve `#if 0 // DIFF`
  blocks still in `src/` are reported by the checker and move to `docs/hard/` when their unit is
  next touched.
- **Declaration blocks:** `// @decl-begin … // @decl-end` at the top of a unit is scaffolding that
  the `tools/bk` scripts maintain. What it holds today (other units' classes, `extern` globals, prototypes)
  belongs in shared headers under `include/` (R1, R2, R25); only types that one unit alone uses may
  stay at the top of that unit.
- **Rule exceptions:** `// RULE-EXCEPTION: <rule>, <why retail's bytes need this>` at the code. An
  exception bends a style rule; it never licenses fake code.
- **Evidence notes the checker reads** (each on the line, or the line above):
  - `// volatile: <evidence>` on a `volatile` local, member, global or cast that is genuinely shared
    with an interrupt handler or a hardware register the checker cannot see;
  - `// R36: <what retail does>` on a local the binary reserves but nothing reads;
  - `// upstream: <file>` on a line of a library unit where the published source itself has the
    pattern a row tests (GCC's `tinfo.cc` writes `if (…) ;` with an empty statement).

## Naming style (R7, R8, R28, R29)

No original source survives, and the ELF is stripped. What the binary does record decides the style;
the rest is the tree's own choice, recorded here as invented.

| entity | style | examples | source |
|---|---|---|---|
| class | `CPascalCase`; interface `IPascalCase` | `CFadeMgr`, `IFadeMgr`, `CMenuProcess` | RTTI names: recorded, kept verbatim |
| template | `TPascalCase` | `TArray`, `TAllocator` | RTTI names |
| implementation of an interface | the interface's name with `C` for `I` | `IPadMgr` / `CPadMgr` | RTTI names |
| method | `PascalCase`, verb first | `Start`, `Update`, `Draw`, `Push` | invented |
| data member | `m_lowerCamel` | `m_state`, `m_depth`, `m_flags` | invented (the tree's choice) |
| free function, game code | `PascalCase` | `AddSnapMgr` | invented |
| library function | upstream's own name and style, as each is identified (most are still `func_XXXXXXXX`) | `__register_frame_info`, `_vfprintf_r` | published source: recorded |
| struct, enum type | as the class style in C++ units; upstream's in library units | | |
| enum value, constant, flag | `UPPER_SNAKE`, a shared prefix per set, flags in hex | | default ([style-defaults.md](docs/style-defaults.md), table 2) |
| local, parameter | short `lowerCamel` | `i`, `type`, `dur`, `owner` | default |
| unit | named after its first class (`CFadeMgr.cpp`); `Unit<addr>`, `Dk<addr>`, `Lib<addr>` until the original file is known | | RTTI; placeholders otherwise |

Follow the style of the unit you are in. Library units keep upstream's GNU or Sony style and are never
normalized into the game's (R8).

**Placeholders** (open naming work, never a failed match; the checker lists them under R7):

- splat's `func_XXXXXXXX`, `D_XXXXXXXX`, `jtbl_XXXXXXXX`;
- names that carry an address: `Func270C50`, `Init143A30`, `CMenuMgrSub1B4768`, `CTaskList24F5C0`;
- offset-named members `m8`, `m4C`, `m_unk78`;
- lane tags inside names (`W2FpNum2`, `Y1mchunkptr`): where upstream names the thing, use upstream's
  name (`fp_number_type`, `mchunkptr`).

A placeholder stays until there is evidence or a meaning. Never replace one with a confident guess.

**Unknown members** are `unk_<OFFSET>` (`u8 unk_58[12];`) for a range no recovered code touches. `pad<OFFSET>`,
which `tools/bk/bk.py` still writes for snippets, is a padding member under R17: it is only honest once
the class has one shared declaration, so that "nothing touches this range" is a fact about the whole
tree rather than about one unit's view.

## Layout style (R23, R32, R33, R35)

The tree's existing layout is kept: 4-space indent, K&R braces, `if (cond)` without inner spaces, one
statement per line. Library units keep upstream's layout. For what the tree has not fixed, the defaults
of the rules apply: braces on every block, a header comment on every function in the form

```cpp
/*
================
CFadeMgr::Start

Begins a fade of the given type over dur frames.
================
*/
```

with the name only (or a `guess:` line) when the purpose is unknown. Most of the tree predates these
two defaults, so the checker reports them as advisory; they are applied in formatting-only commits,
unit by unit.

## Evidence sources

- **RTTI:** class names, and through the typeinfo functions the base of every class
  (`config/vtables.txt`, `scripts/data_units.py`).
- **Vtables:** slot counts and order (`tools/bk/dataconv.py UNIT`). `config/vtables.txt` records each
  vtable's size; slots = size / 8 − 2.
- **Strings:** debug-print and assert text, which names functions, flags and files. The asserts of the
  state machine name their own source file and lines (`../dklib/include/state.h`, lines 68, 70, 72, 76:
  `include/state.h` rebuilds it).
- **State numbers:** an `Update` state machine's states are `-__LINE__` of the line that yields, so the
  constants in a matched `switch` (`case -0x30F:` is line 783) are the original source's line numbers.
- **Published source:** libgcc and libstdc++ of GCC 2.96 (`libgcc2.c`, `frame.c`, `tinfo.cc`,
  `exception.cc`) and newlib (stdio, stdlib, `mprec`, `dtoa`). For a library unit this is the
  original source: names, macros and layout come from it. Sony's SDK libraries count the same way
  where a contributor has their headers or source; the project has not checked any claim against an
  SDK copy yet, so say which file a name comes from.
- **The compiler:** an instruction the compiler cannot emit from C (COP0, COP2/VU0 macro mode, the
  128-bit multimedia set) is evidence of an assembly helper in the original.

## Line information (R23)

Retail records no source lines: the ELF is stripped and `.mdebug.eabi64` is empty. Layout changes are
free, with three exceptions:

1. `Lib28AE50`, `Lib28D8B0` and `Lib28F4F8` are compiled with cc1's `-g`, which changes delay-slot
   filling ([docs/compiler.md](docs/compiler.md)). Moving a statement to another line there is
   [checked].
2. A unit whose state machine is written with the yield macro restored (`-__LINE__`) has its line
   numbers in the code. No unit is in that form yet; once one is, its layout is [checked] and its
   yields sit on the original lines.
3. `as -g` on the C++ units does not record C lines, but it is why a batch of formatting changes still
   gets one `make` before it is committed.

## Commands

| what | command |
|---|---|
| per-function check | `tools/bk/bk utest SNIP` (the unit's own compiler and flags, relocations included); `tools/bk/ushow.py SNIP [ADDR]` for the side-by-side |
| byte gate | `.bokura-env/bin/bokura-env -c 'make -j'` → `OK: build/SCPS_150.88 matches (…)` |
| data gate | `python3 -I tools/bk/rocheck.py`, `python3 -I tools/bk/imgdiff.py` |
| gate for changes that must not change code | `python3 -I tools/bk/sgate.py [BASE]` (compiler output of every unit, both revisions; no disc needed) |
| rule checker | `python3 -I tools/bk/rules.py` (no build needed); `--selftest` checks the checker |
| progress | `python3 -I tools/bk/progress_report.py` (bytes), `python3 -I tools/bk/rules.py` (rules) |

A change is finished when `make` says `OK` and `rules.py --pending` no longer lists the function.

## Working order

New and touched source applies every rule as it is written: no new `extern` in a unit, no new local
copy of a class, no `pad`, no offset cast. Existing source is brought up in tiers, never mixed in one
commit:

1. [free] changes (comments, banners, braces, layout), one `make` per batch;
2. each [checked] or [evidence] change with its per-function check and `make`;
3. a change that breaks the match is reverted or reshaped, never kept.

[docs/code-rules-status.md](docs/code-rules-status.md) ends with the order that clears the most MATCH-PENDING
functions per change.

## Rule changes

Each is a change to how a rule is tested here, with the reason.

| rule | change | reason |
|---|---|---|
| R1 | A forward declaration whose `class`/`struct` keyword differs from the definition is advisory, not [match]. | GCC 2.9x does not mangle the class key (that is MSVC), so the mismatch cannot hide a wrong symbol here. |
| R1 | The "struct that copies a prefix of another struct, read through a cast" row is review-only. | Members are still named by offset (`m0`, `m4`), so every struct looks like a prefix of every other; the row would fire on noise. It becomes mechanical once R7 has named the members. |
| R2 | Not relaxed: an `extern` in a unit is a finding. | No surviving source shows the original declaring globals in its `.cpp` files. |
| R17 | Tightened: a cast to a `volatile` pointer is a finding unless its operand is a literal EE hardware address (0x10000000–0x1FFFFFFF, kseg1 mirrors) or carries a `// volatile:` note. | The catalogue's row covers locals, members and globals; the carrier this tree actually uses is `*(volatile s32 *)(base + 8)`. |
| R17 | `// upstream: <file>` passes an R17 row on that line in a library unit. | The published library source is the original; a pattern it contains is not fake. The note names where to check. |
| R18 | Computed helper list: an `asm` statement made only of instructions the compiler cannot emit from C (COP0, COP2/VU0 macro instructions, `sync`, 128-bit `lq`/`sq` and multimedia instructions, or at most two instructions on `$gp`/`$sp`/`$ra`), with register glue around them, is an original helper. Functions using one are listed, and counted. | Necessity is the evidence: no C spelling produces those instructions. Any other assembly in a body is R18. |
| R18 | `crt0` is `ORIGINAL-ASM`: listed apart, in neither the matched count nor the total. | Handwritten startup code. Library functions that published source shows as assembly (libkernel's syscall stubs, parts of libvu0) join the list by name as they are identified; until then the checker reports the ones with non-helper assembly as R18. |
| R18 | An `asm` statement with no instruction (`__asm__("")`, directives only) is R17, not R18. | It emits nothing; it exists to steer the compiler or the assembler. |
| R33, R35 | Advisory: missing header comments, braceless bodies. | The tree predates both defaults; they are [free] and applied unit by unit. |

Add a row here, and update `tools/bk/rules.py` in the same change, to tighten or relax anything else. A
rule moves into [match] only if the checker can test it.
