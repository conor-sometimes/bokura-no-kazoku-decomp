# Code rules

What reconstructed source must look like here, and which of it a function must pass before it counts
as matched. The project's own choices (compiler dialect, naming, layout, evidence, every rule this
project tests differently) are in [AGENTS.md](../AGENTS.md), which wins where the two disagree.
`tools/bk/rules.py` checks the mechanical part.

## Why

A matching decompilation exists so people can understand the original program. Identical bytes prove
the source is faithful; readable source is the point. Every rule serves one test, **the reader test**:

> Would a programmer on the original team, writing in that codebase's style and dialect, have typed
> this? And can a reader see what it does, and why, without opening the disassembly?

A **fakematch** produces the right bytes and fails that test: a dummy local, a `volatile` carrier, an
empty block, a reused variable, an offset cast, a statement that exists only to steer the compiler. It
is a clue to the real source, not a match.

The test also protects real code. `*dst++ = *src++`, `while (--n)`, `goto fail` with one cleanup
label, a 250-line function, a bug the original shipped: all of these are what the original programmers
wrote, and none needs an excuse.

## The two laws

1. **The bytes win.** A change made for style never changes what the compiler emits. Where a rule and
   the bytes disagree, keep the bytes and write `// RULE-EXCEPTION: <rule>, <reason the bytes give>`
   at the code. An exception bends a style rule. It never licenses fake code.
2. **Identical bytes alone are not a match.** A function counts as matched only when its bytes match
   and it passes every **[match]** rule: R1, R2, R4, R13, R17, R18. Byte-identical but failing is
   **MATCH-PENDING**: reported, not counted. Names are not part of this: a match with placeholder
   names is a real match whose naming is open work.

## Tiers

| tag | before applying |
|---|---|
| [free] | nothing: it cannot change the output. Run `make` once per batch anyway. |
| [checked] | the per-function check and `make` after the change |
| [evidence] | evidence for the name or signature (RTTI, strings, published library source) |
| [match] | required before the function counts; also [checked] when you fix it |

## The rules

Numbers are stable: other tools cite them, new rules take the next free number.

**A. Declarations and types**

- **R1 [match]. Declare each type once, in a shared header.** No local copy, no partial view of another
  unit's class. A type only one unit uses may be defined at the top of that unit.
- **R2 [match]. Declare each global once, as `extern` in a header; define it once.** Never an `extern`
  in a `.cpp`.
- **R3. Headers have a fixed shape:** guard, includes, constants, enums and typedefs, classes,
  `extern` globals, prototypes grouped by the unit that defines them. Reordering is [checked].
- **R4 [match]. Typed members, never fixed offsets.** `*(s32 *)((u8 *)p + 0x58)` is `p->radius`. Byte
  arithmetic is fine where the data has no fixed struct (a file parser walking a buffer).
- **R5 [evidence]. An enum for a proven finite set of values.**
- **R6 [evidence]. The original's own types and APIs:** upstream's and the SDK's types in library
  units, `bool` only where the evidence shows `bool`.
- **R25 [checked]. Every function has a prototype in scope, with its real types,** in a header.
  Old-style definitions in C library units keep their style.
- **R26 [checked]. Keep pointers typed;** `void *` only at a real boundary (callbacks, allocators).
- **R27. Struct and class layouts read as documentation:** one member per line, comments for units
  and owners, unknown ranges as `unk_<OFFSET>`. Member order, virtual order and access level never
  move.

**B. Names**

- **R7 [checked; evidence for recorded names]. Name things for what they mean; no placeholders.**
  Recorded names are kept verbatim. An invented name is recorded as invented. Unknown purpose keeps
  the placeholder: never a confident guess.
- **R8. Follow the original's naming style, unit by unit.** Library units keep upstream's.
- **R28 [checked]. Free functions carry their module's prefix,** where the original's style has one.
- **R29. Each kind of thing is named by one pattern** (types, enum values, constants, flags,
  accessors, booleans).
- **R30 [checked]. One local, one meaning, one name.** Split a variable the decompiler merged.

**C. Literals and operations**

- **R9. Numbers in the base that fits:** decimal for counts and sizes, hex for masks and addresses,
  never a float as raw bits.
- **R10 [checked]. Name bit operations; don't replace them.**
- **R11. Name meaningful constants** (`#define` or enum in C; a named `const float` is [checked]).
- **R31. Macros are hygienic and named for what they do;** keep the macro-or-function form the
  original had.

**D. Structure**

- **R12 [evidence]. Functions live where the original put them:** a method stays a method of its
  class. Declaring one as a free function with an `asm("mangled")` label hides that.
- **R13 [match]. Vtables are recovered from evidence.** Every declared virtual is a slot of the
  binary's vtable; no padding virtual, no virtual the vtable lacks.
- **R14 [checked]. `goto` only where the original's control flow needs it.**
- **R15 [checked]. Keep the original's function order and unit boundaries.**
- **R16 [checked]. Restore helpers instead of open-coding them,** on evidence (published source, the
  same shape in several functions, an out-of-line copy).
- **R32. Each unit opens the same way:** a purpose line, includes, unit data, functions in binary
  order.
- **R33 [free]. Every function has a header comment** (name only when the purpose is unknown).
- **R34 [checked]. Don't split or merge functions for readability.**
- **R35. Statements read top to bottom:** one per line, braces on every block, no hidden state
  changes outside the era's idioms.

**E. Honesty of the source**

- **R17 [match]. No fake code:** no probes, unused or dummy locals, `volatile` carriers, padding
  members, arbitrary blocks, or statements that only steer the compiler.
- **R18 [match]. Assembly is not source.** A function whose body is assembly is not matched. Two
  exceptions: an original inline-asm helper inside an otherwise-C function, and a function the
  original wrote in assembly (`ORIGINAL-ASM`: listed apart, counted neither way).
- **R19. Casts only where the meaning needs them.** A cast is a symptom: fix the declared type.
- **R20 [evidence]. `const` and references as the evidence shows them.**
- **R21 [free]. Comments say what the code means and why the bytes need it.** No history, scores,
  dates or lane notes: those belong in version control and `HARD.md`.
- **R22. Write the compiler's dialect only.**
- **R23. Formatting is free, but gets its own commits.**
- **R24. Never edit generated material** (`asm/`, `build/`, reports).
- **R36 [free]. Label the original's quirks; don't fix them:** `// BUG:`, `// NOTE:`, with `guess:`
  when unsure. A quirk label needs bytes that simpler source cannot explain.
- **R37 [checked]. Conditional compilation models real builds only.** No `#if 0` attempts in a unit.

## Fakematches and what they hide

| fakematch | what it usually hides |
|---|---|
| `volatile` on a local or on ordinary data | a wrong type, an aliasing pointer, a missing call |
| a local assigned and never read | a value the original kept; a missing inline helper |
| an empty `{ }` or a bare `;` | a scoped local, a macro's expansion, a removed debug call |
| `do { … } while (0)` in a function body | a macro the original called |
| `x = x;`, `x + 0`, `x * 1`, `if (x) { }` | a sequence point, a type width, a missing helper |
| one variable reused for unrelated values | separate variables sharing a slot |
| arithmetic on `(u8 *)p + N` | a struct member |
| `__asm__("")`, `asm(".set noreorder\n.set reorder")` | a different last statement; a wrong flag for the unit |
| `register T x asm("$n")` to place a value | a different declaration order or type |
| a padding member or padding virtual | unknown members; a wrong base class |
| `goto` into a loop, a label that only reorders blocks | a `continue`, a `do`/`while`, a different condition |

Dense, and human: `*dst++ = *src++`; `while (--n)`; `for (; *s; s++)`; `if (!(p = Find()))` in a search;
`goto fail`; a long `switch`; `x = y = 0` for related state; the same check twice because the
original had a merge leftover (R36).

## What the checker tests

`python3 -I tools/bk/rules.py` reads `src/*.cpp`, `include/*.h` and the symbol files. No build.

| rule | the row |
|---|---|
| R1 | one type name defined in two files with different bodies |
| R2 | an `extern` of a global in a `.cpp`; it also says when the units disagree on the global's type |
| R4 | a dereference (or `->`) of a cast of `(char * / u8 *)x ± constant`; `(u8 *)this` or `(s32)this` in arithmetic; a macro whose body is such a dereference (`FLD`, `M4D8`) |
| R13 | a class with more declared virtuals (its bases' included) than its vtable has slots; a virtual named `pad…`/`dummy…` |
| R17 | `volatile` on a local, member or global without a `// volatile:` note; a `volatile` cast on anything but a literal hardware address; a local never named again (unless `// R36:`); an empty `if`/`else`; a bare `;` (empty loop bodies, `case X: ;` and `label: ;` pass); `do { } while (0)` outside a macro; self-assignment; `+ 0` and `* 1` as whole tokens; a member named `pad…`; an `asm` statement without an instruction; a comment marking a probe |
| R18 | an `asm` statement in a body that is not a hardware helper (AGENTS.md, "Rule changes") |

A finding in a declaration counts against every function that names the type, global, macro or
inline helper, through helpers and base classes; a method also answers for its own class.

Advisory rows never block a match: placeholder names (R7), methods declared under another name
(R12), `goto` (R14), campaign notes in comments (R21), prototypes outside headers (R25), missing
header comments (R33), braceless bodies and assignments in conditions (R35), `#if 0` blocks (R37),
classes that declare fewer virtuals than their vtable has (R13), typed dereferences of `pointer +
constant` (R4), file-scope `asm` directives, `!!x` and register-pinned locals.

Limits. The checker reads tokens, not types:

- it does not follow `p->q->r` into a type the function never names, so a function can pass while a
  class it reaches only through a member chain has a finding;
- R13 is tested only where every base class is declared in the unit or its headers;
- the "partial copy read through a cast" form of R1 and same-type casts (R19) are left to review;
- a local read only through a macro is recognised by the macro's identifiers, not by expansion.

Each can only make the checker miss a finding, never invent one. `rules.py --selftest` runs every row
against cases that must fire and era idioms that must not.

## Where the tree stands (2026-11-20, at 9bfc11f)

| | functions |
|---|---:|
| in `.text` (crt0's 4 are `ORIGINAL-ASM`, in neither count) | 7,219 |
| bytes matched | 6,429 (89.1%) |
| **matched under the rules** | **1,687 (23.4%)** |
| MATCH-PENDING | 4,749 |

| [match] rule | functions it holds back | by this rule alone | what it is, mostly |
|---|---:|---:|---|
| R2 | 2,903 | 1,757 | 3,230 `extern` globals declared in units |
| R1 | 2,226 | 469 | 604 definitions of classes that another file defines differently |
| R17 | 1,851 | 240 | 921 `pad` members, 126 `do { } while (0)`, 49 unused locals, 33 `volatile` carriers |
| R4 | 360 | 249 | 87 offset casts, 26 offset macros (`FLD` in 21 library units) |
| R18 | 22 | 12 | assembly bodies in the SDK vector and math units, a few game helpers (`sqrt.s`) |
| R13 | 2 | 0 | `CBoneDupMap::KeyStub`, a virtual the vtable does not have |

329 more functions use a hardware-assembly helper: listed, and counted.

## Order of work

The order that clears the most MATCH-PENDING functions per change. Every step is [checked]: per-function
check, then `make`.

1. **Globals into headers (R2).** Move each `extern` from the units' declaration blocks into the
   header of the unit that owns the address, with one type. Where units disagree on the type, the
   owner's uses decide. String literals reached through `extern const char D_…[]` become literals
   as their unit's `.rodata` is converted (docs/units.md, level 2).
2. **Classes into headers (R1).** `tools/bk/hoist.py` moves a class into `include/`; the partial views
   then have to be merged into one declaration that every unit accepts. Each merge also shows which
   `pad` ranges another unit already knows.
3. **`pad` to `unk_` (R17), class by class, after step 2.** With one declaration, a range nothing
   touches is an honest unknown: rename it `unk_<OFFSET>`. `tools/bk/bk.py`'s snippet classes should
   write that name from then on.
4. **Library types (R4).** `FLD(T, p, off)` in the newlib and libgcc units stands for members of
   `struct _reent`, `FILE` and libgcc's frame objects. The published headers give the real structs.
5. **State machines (R17, R31).** The `do { case -0x30F: … } while (0)` blocks are the expansion of
   the yield macro of `state.h`. Restoring the macro removes them, and puts the yields back on the
   original line numbers.
6. **The rest of R17 and R18:** each `volatile` carrier, unused local and empty `asm` is a clue to a
   wrong type, a missing helper or a wrong flag (the table above); library functions that upstream
   wrote in assembly go on the `ORIGINAL-ASM` list by name.

The advisory rows ([free]: header comments, braces, notes in comments) go in formatting-only
commits, any time, one unit per commit.
