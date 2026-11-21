# Code rules: the checker and where the tree stands

The rules themselves are [code-rules.md](code-rules.md), with the default style tables in
[style-defaults.md](style-defaults.md). The project's profile for them is [AGENTS.md](../AGENTS.md).
This page is the project's own part: what `tools/bk/rules.py` tests, what it found, and the order of
work.

## What the checker tests

`python3 -I tools/bk/rules.py` reads `src/*.cpp`, `include/*.h` and the symbol files. No build. Its rows are
the table at the end of [code-rules.md](code-rules.md) ("Making [match] mechanical"), as this project tests
them; [AGENTS.md](../AGENTS.md), "Rule changes", gives the reason for each difference.

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

## Where the tree stands (2026-11-20)

| | functions |
|---|---:|
| in `.text` (crt0's 4 are `ORIGINAL-ASM`, in neither count) | 7,219 |
| bytes matched | 6,429 (89.1%) |
| **matched under the rules** | **1,691 (23.4%)** |
| MATCH-PENDING | 4,745 |

| [match] rule | functions it holds back | by this rule alone | what it is, mostly |
|---|---:|---:|---|
| R2 | 2,861 | 1,753 | 3,167 `extern` globals declared in units |
| R1 | 2,226 | 470 | 604 definitions of classes that another file defines differently |
| R17 | 1,851 | 244 | 921 `pad` members, 126 `do { } while (0)`, 49 unused locals, 33 `volatile` carriers |
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
