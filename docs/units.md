# Translation units

The game's .text from 0x1002A8 to 0x1E91B8 is split into 127 C++ units (`src/<Class>.cpp`),
one per guessed original translation unit; the rest of .text stays assembly for now
(`asm/crt0.s`, and `asm/text_1e91b8.s` from CAppMain on: C-style code without vtables, then
the Sony SDK libraries and the linkonce code).

## Evidence (scripts/find_units.py)

- **Vtable order.** GCC 2.96 puts each unit's vtables in that unit's .data, so the vtables
  (0x2BFA40 to the end of .data) come in link order, and within one unit in reverse order of
  their classes. For each vtable, take the lowest game function that uses it (ctor, dtor or a
  virtual method): a unit starts at each new high-water mark, lower values join the current
  unit. 192 vtables give 150 units; one vtable (key 0x128870, near the end) is an outlier.
- **RTTI names** name the units: word 1 of a vtable is the typeinfo function, which passes the
  mangled class name (`9CBootMain`) in `$a1`. A unit is named after its first class; the other
  classes are listed in the yaml comment.
- **Cross-check with .rodata**: each unit's literals are contiguous, in unit order. In the
  converted range only three functions use the next unit's literals (0x143A30, 0x196C70,
  0x1A4AE0), so those boundaries may sit a little earlier.

Limits: a unit may begin before its first class's lowest function (free functions or statics
defined first); those functions are in the previous file for now. Interface classes
(`IPadMgr`, `IFadeMgr`, ...) got units of their own and may belong with their `C` class.
Units with no vtables are not found at all.

## Build

Each unit is compiled by EE-GCC 2.96 and assembled by its own GNU as 2.10-ee, which
assembles the INCLUDE_ASM'd functions too (numeric registers, see docs/compiler.md).
splat writes empty functions as C bodies; they are `extern "C"` until their real names
and classes are known.
