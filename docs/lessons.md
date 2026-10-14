# Lessons: Bokura no Kazoku

Things that took more than a few minutes to figure out on this project. Add to it as you go.
Cross-project lessons (other decomps, the method) also go to the `decomp` skill's lessons file.

## 2026-10-13: Nix environments, PS2 round-trip, tooling (Lombyte + Bokura + Crash Bash)

- **PS2 ELF round-trip with splat** (Bokura, done in under 10 minutes): use `splat64[mips]`
  (plain `splat64` can't import n64img); set `ld_align_section_vram_end: False` and
  `ld_align_segment_vram_end: False` (default ALIGN(64) padding breaks the layout); turn raw
  bins (VU microcode) into objects with `.incbin` through the same assembler, not
  `objcopy -I binary` (32/64-bit mismatch at link); rebuild the ELF container from a table of the
  retail section headers (stripped files keep odd entries: .shstrtab still names .symtab, .bss
  offsets that don't follow addresses, .DVP.ovlytab type 0x7FFFF420). *(bokura)*
- **spimdisasm vs Ghidra** for function discovery on a stripped PS2 ELF: spimdisasm 7228, Ghidra
  5911, only 7 of Ghidra's missing from spimdisasm. Ghidra is for understanding and naming; it
  isn't needed for the round-trip. *(bokura)*

## 2026-10-13: Bokura (PS2, EE-GCC 2.96 C++)

- **EE-GCC 2.96 sibling calls in C++ only for value-returning tail calls**: `void f(){ g(); }` keeps
  `jal` + `jr $ra`; `int f(){ return g(); }` becomes "frame kept, `ld $ra`, `j g`". So a retail
  `j callee` after a dead `sd/ld $ra` tells you the caller returns the callee's value (C compiles
  both as sibcalls). *(bokura)*
- **Translation units from vtable order**: GCC 2.x emits each unit's vtables into its .data in link
  order and in reverse class order within a unit; key each vtable by its lowest referencing function,
  start a unit at each new high-water mark, and name it from RTTI (vtable word 1 = typeinfo function,
  which loads the mangled name into `$a1`). 192 vtables gave 127 units, agreeing with .rodata order at
  all but three boundaries; inline-header `__FILE__` strings (`../dklib/include/state.h`) duplicated per
  unit confirm them and reveal units hidden inside one (scripts/find_units.py). *(bokura)*
- **Mixed C++/INCLUDE_ASM objects on EE-GCC 2.96**: assemble with the compiler's own GNU as 2.10-ee
  (modern gas encodes `move` as `or` and adds COP1 hazard nops). It only knows numeric registers, so
  set splat `named_regs_for_c_funcs: False`; it rejects spimdisasm's VU0 macro mnemonics (`vmulaw`...).
  Its `.L` labels made `.global` still link jump tables fine. *(bokura)*
- **`$v1` instead of `$v0` for a lone `lui` in a setter** = the function is non-void without a
  return statement (v0 is live at exit). *(bokura)*
- **GCC 2.96 has no empty-base optimisation**: an empty base class takes 1 byte and shifts the
  derived class's fields (saw `addiu a0, a0, 33` for a member at 0x20). Give the base its real size. *(bokura)*
- **Don't declare classes `virtual` in a partially split unit**: the first non-inline virtual
  defined in the unit makes GCC emit the vtable/typeinfo into the object's .data/.rodata and breaks
  the layout. Leave vptr-storing constructors and virtual calls until the unit's data is split. *(bokura)*
- **Store order of field clears is not source order**: brute-force permutations of the statements
  (tools/bk `perm`); natural order matched about half the time. *(bokura)*
- **Retail was built with `-fno-strict-aliasing`**: with strict aliasing (GCC 2.96's -O2 default)
  stores and loads through different types get reordered and globals are not re-read after a store;
  retail keeps them in source order. The flag changes no already-matched function. Found by a lane
  worker on 0x121A78 / 0x1253D0 / 0x1087F8. *(bokura)*

## 2026-10-14: lane 2 (CSvmWork, CMenuMgr, CGameDBMgr)

- **Debug prints take the bad value**: range checks print through `Func235DE0(fmt, ...)` with `%d` in the
  format; leaving the argument out keeps the parameter in a1, while retail copies it away first
  (`daddu $3,$5,$0` at entry) because a1 is needed for the print. Read the format string from the ROM and
  pass its arguments: fixed about 15 functions. *(bokura)*
- **`return f();` in a void function gives the "frame kept, `j callee`" sibcall**; with a value-returning
  callee write `return (void)f();`. A non-void function ending in a void call also tail-calls, which
  retail doesn't, so those are void. *(bokura)*
- **Record-table lookups are an inlined template**: `template<class T> inline T *FindById(T *tbl, s32 n,
  s32 id) { for (i=0;i<n;i++,tbl++) if (tbl->m_id==id) return tbl; return 0; }` matched all 9 CGameDBMgr
  Finds; the same loop written in the method is 1 insn short (CFaceRes 0x10F8F0 is the plain loop). *(bokura)*
- **`new T`** here is `__builtin_new(size)` (0x245648) then an explicit `Init()`/ctor call, no EH code. *(bokura)*
- **Pointer arithmetic order shows**: `p = src + y*stride + x` matches; `&src[y*stride+x]` and
  `src + (y*stride+x)` don't. *(bokura)*
- **Callees in another unit**: naming one `FuncXXXXXX` in a snippet makes `bk port`/`fix_includes`
  rename its INCLUDE_ASM in that unit (a file another worker owns); in parallel lanes declare
  `extern "C" func_XXXXXXXX` instead. `testall.sh` prints nothing when a snippet fails to compile,
  which looks like "all matched": check the match count. *(bokura)*

## 2026-10-14: lane 3 (CFlagWork, CCharaObj, CMapEffObjRes, CStatusWin, factories)

- **`new X` with exceptions on needs `X() throw();`**, or GCC emits a cleanup and landing pad. Inside a
  call argument (`list->Add(new X, 0)`) a `__rethrow` region appears even with throw(): split it into
  `X *t = new X; list->Add(t, 0);`. *(bokura)*
- **Class-specific `operator new` is non-inline** (`static void *operator new(unsigned)` in a base:
  CTask = 0x24F2E8, CHeapObj = 0x245D20). *(bokura)*
- **`delete[]` cookie is 0x10 for 16-byte-aligned element types**, 8 otherwise. *(bokura)*
- **Loops over arrays usually want the `&e[i]` index form**; pointer walks strength-reduce differently.
  Try the natural source first. *(bokura)*
- **A dead store kept in retail is a load-order clue**: in 0x128ED0 `n->next = n` survives because
  `h->prev` is loaded first; write the load before the stores. *(bokura)*
- **Error macro**: `if (bad) return printf(fmt, this, i);` is a sibcall `j 0x235DE0`, so these functions
  return int with no final return. *(bokura)*
- **`bk show` prints our offsets in decimal, retail's in hex**: easy to miss a layout error. *(bokura)*
- **Same class under several names**: CStatusItem, CMenuRecordWin and CStatusWinSub1A40B8 are one class
  (0x1A3xxx); CCharaObjPart24 is CFaceObj. Unify when the header is shared. *(bokura)*
- **Parallel lanes and names**: when one lane calls `extern "C" func_XXXXXXXX` and another names that
  address, the merge leaves an undefined `func_` reference; `config/aliases.ld` keeps the old names
  linking until the callers are cleaned up. *(bokura)*

## 2026-10-14: lane 1 (CUserFlagMgr, CMenuLoadMemorial, CEventObj, ISysFlag, CStatusBase, ...)

- **Explicit `return;` after a final void call gives the sibcall** ("ld ra; j callee"); without it,
  `jal` + `jr`. An if/else whose branches end in calls sibcalls too (0x1883D0, 0x144A58). *(bokura)*
- **Clamp to [0,1] is an inline function**: `inline f32 Clamp01(f32 v){ return (v<1.0f?v:1.0f)<0.0f?0.0f:(v<1.0f?v:1.0f); }`;
  the same expression open-coded duplicates the store per path. *(bokura)*
- **Float 0.0f stored from an FPU register** (`mtc1 $0` + `swc1`, not `sw $0`) = chained `a = b = c = 0.0f`. *(bokura)*
- **No stdarg.h with the compiler**: `typedef __builtin_va_list va_list;` with `__builtin_stdarg_start` /
  `__builtin_va_end` (the EABI spill of a1-t3 and f12-f19 matches). *(bokura)*
- **Class by value mangles as `G<len><name>`** (`Func140088__12CUserFlagMgrG15CUserFlagWriterPCc`). *(bokura)*
- **Intrusive list unlink/insert only matched through inline helpers**; open-coded, the stores reorder (0x13DFB8). *(bokura)*
- **Bounds checks are written `n - 1 < i`** (`addiu -1; slt`). *(bokura)*
- **`bk show` hides nop runs** (objdump without `-z`), so loop padding is invisible. *(bokura)*

## 2026-10-14: lane 2 round 2 (larger functions across 34 units)

- **Non-void callees change register choice**: a `lui`/`lw` into `$3` right after a call whose result is
  ignored means the callee returns a value (GCC 2.x constructors return `this`). Fixed 0x18D838 and ~8 more. *(bokura)*
- **Inline getters change register allocation** where a return-type fix didn't (`f32 GetUnk34() { return m_unk34; }`, 0x193D68). *(bokura)*
- **LCG seeds are a sub-object**: `struct CRand { u32 m_seed; u32 Next(); }` with the range in an inline
  helper fixed 0x130718 and 0x1BDB38. *(bokura)*
- **Single exit**: several functions only matched with one `return ok;` at the end (retail keeps `ok` in
  a saved register) instead of early returns. *(bokura)*
- **Branch order**: constant-case `switch` fixed 0x198128 and 0x18CE28; bottom-tested loops with the call
  in the condition matched `while ((p = f(...), *p) || buf[0])`. *(bokura)*
- **Float parameter position** changes argument setup order (EABI floats in `$f12`, 0x171378). *(bokura)*
- **Unused stack buffers**: window draw functions have dead stack space; an unused `char buf[N]` matches
  the frame size. *(bokura)*
- **`bk test` can pass while the unit differs**: codegen depends on what precedes the function in the
  unit; trust `mk.sh` (lane 2 used a local `ctxtest.py` that swaps the function into the unit). *(bokura)*

## 2026-10-14: per-unit data, vtables from C++ (data worker)

- **GCC 2.96 vtables are linkonce**: `_vt$<class>` goes to `.gnu.linkonce.d._vt$<class>` (weak),
  `__tf<class>` to `.gnu.linkonce.t.__tf<class>`, `__ti<class>` is `.comm`, the RTTI name string
  goes to the unit's .rodata after all its literals. The linker puts every linkonce section after
  every `.data`, which is why all vtables sit together at the end of .data in unit order. *(bokura)*
- **Only the key method emits a vtable**: the first virtual a class declares that is neither inline
  nor pure (here nearly always the destructor). Constructors, virtual calls and other virtuals can
  be matched with the vtable still in asm if the asm label has the compiler's name
  (`_vt$13CMenuSysscr23` via config/vtables.txt). Only the key method needs the unit's data split
  out: 105 of 614 vtable-blocked functions. *(bokura)*
- **splat `linker_section`** on a dot-subsegment places one object's other sections:
  `{start: X, type: .data, name: U, linker_section: .gnu.linkonce.d.*}` puts the unit's vtables at
  its piece; the compiled `__tf` copies fall to `/DISCARD/` and the vtable links to the retail
  ones by name. splat leaves symbols of C-owned pieces out of undefined_syms_auto.txt:
  scripts/data_syms.py defines the asm references by address. *(bokura)*
- **Literal order in a converted unit follows the first user in the source, not in .text**: an
  inline helper writes its literals where it is defined (CUserFlagMgr's `" \t"`, `","`). Keep C++
  `extern D_X` references, list the symbol with `force_not_migration:True` and INCLUDE_RODATA it;
  turning it into a literal moved it. *(bokura)*
- **splat's per-symbol rodata files carry no `.align`**: add the one the address implies
  (scripts/rodata_align.py), or a symbol after a shorter compiler-written string lands early. *(bokura)*
- **A per-piece byte check finds every bad conversion in one build** (tools/bk/rocheck.py: object's
  linked section vs retail at the piece's own address), where the image diff only shows the first
  shift. It converted 47 units' .rodata in three builds. *(bokura)*
- **Text boundaries from vtable keys start late**: units begin with functions that use no vtable
  (factories `CreateX` for the next menu screen, helpers), which the yaml puts at the end of the
  previous file; their literals sit after the previous unit's RTTI name. Lanes named several
  constructors after the wrong class this way (`Init174138__9CMenuNews` is CMenuExGetMoney's). *(bokura)*
- **Constructor store order**: the last field assignment in the source often comes out first (before
  the vptr store); `bk perm` found both orders in a few seconds. *(bokura)*
