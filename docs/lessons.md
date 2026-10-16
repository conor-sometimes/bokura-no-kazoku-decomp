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

## 2026-10-14: vtables lane 1 (menu screens, DB managers)

- **Retail was built with `-fno-exceptions`**: with EH on, constructors that build a member or base
  object get a cleanup region (`__rethrow`, `terminate__Fv`) and a final call is not a sibcall;
  with the flag both match and nothing else changes. *(bokura)*
- **Vptr at 0 in a class with fields = a field-less interface base**: the vptr goes after the
  fields of the class that introduces the virtuals, so `IResNameMgr` (all pure, no dtor, RTTI
  name only) must introduce them. Giving the interface an inline virtual dtor adds a second vptr
  store in the derived dtor; leave the dtor to the derived class (it lands in the last slot). *(bokura)*
- **Key method is not always the destructor**: the DB managers' slot 0 is an inline
  `Release() { delete this; }` (linkonce, emitted elsewhere), so the key method is slot 1 and the
  destructor can be matched with the vtable still in asm. *(bokura)*
- **GNU as 2.10 can corrupt a macro expansion**: `lw $19, D_X($2)` assembled its `lui` as a copy of
  the following `lw` once code before it changed (position-dependent). A file-scope
  `asm(".p2align 3");` before the (already aligned) function fixed it (CNameDBMgr). *(bokura)*
- **`bk`-style checks per unit**: compiling the whole unit and comparing its .text with retail at
  the unit address (masking relocations) catches context-dependent codegen without a full link. *(bokura)*
- **Template members and linkonce code**: classes whose virtuals are all inline (TArray<>,
  CListTag) make a unit emit their vtables as linkonce sections when it constructs or destroys
  them inline; constructors and destructors of classes holding them were left in asm. Calling
  their inline members through `extern "C" func_XXXXXXXX(arr, ...)` matches. *(bokura)*
- **Interface vtables without a key method**: when a field-less base is all pure, declare one
  slot non-pure in the unit that only uses it, so the unit emits no vtable/typeinfo for it. *(bokura)*
- **A value-returning virtual shows in the next call's registers**: `$3`/`$2` swapped around the
  following vcall means the previous callee returns a value (3 cases, also for virtuals). *(bokura)*
- **Lookup loops in CResortDBMgr wanted the index form** (`if (tbl[i].m_id == id) return &tbl[i];`);
  the FindById inline template lesson did not apply there. *(bokura)*
- **Pointer-to-member calls** (`(obj->*pmf)(args)`) compile to GCC 2.96's index/delta/pfn
  sequence; two in CEventObj (large this offsets) keep an empty `b` delay slot that ours fills. *(bokura)*
## 2026-10-14: vtables lane 2 (menu screens, task classes, CGameDBMgr)
- **Task classes derive from the library CProcess/CTask** (include/CProcess.h): CTask has one field and its
  vptr at 4; the library constructor, destructor, operator new/delete and the empty slot functions get
  names in config/aliases.ld, so a unit whose vtable mixes its own and library slots can go to level 3. *(bokura)*
- **Interfaces need a declared (undefined) virtual destructor**, or an inline base constructor makes the
  unit emit the interface's vtable as linkonce data (ISnapMgr, IFadeMgr). For CGameDBMgr (slot 0 is an
  inline "delete this", destructor last) the class declares an undefined `Release` first. *(bokura)*
- **A base without a vtable of its own adds its RTTI name to the unit's .rodata**: CMotionRes holds
  CMotionTbl as a member, not a base. *(bokura)*
- **A 0..1 clamp then multiply only matches with the clamped value in a local** (`f32 r = Clamp01(v);
  m = (s32)(n * r);`); the four HARD.md clamp setters match this way. *(bokura)*
- **Empty `case` labels shape the switch tree**: `case 0: case 2: break;` next to the real cases (and
  `case END: goto out;` in the menu state machines) give retail's compare order. *(bokura)*
- **Void virtual callees**: a `lui $3`/v0 slot address around a virtual call means the slot returns void;
  a callee returning a value shows up as `lui $3` after a plain call (func_0010BF88). *(bokura)*
- **Position of a local object's declaration changes scheduling** (CEndingMain: `CEndingDate date;`
  between two statements matched where top-of-block did not). *(bokura)*
- **`(y << 5) * w / 8` keeps retail's sll+mult**; `y * 32 * w / 8` folds to `y * w * 4`. *(bokura)*
- **Member objects whose constructor/destructor live in another lane's unit**: either alias the ctor name
  in aliases.ld or keep the member POD and call `func_X(&m, ...)` / `func_X(&m, 2)` explicitly in the body;
  the code is the same. *(bokura)*
## 2026-10-14: lane vt3 (vtable functions: ctors, dtors, virtual calls)
- **Member vs base shows in the destructor's in_chrg**: a member's dtor is called with 2, a base's
  with 0 (CLayoutRes destroys its CPushBuf with 2, so CPushBuf is a member, not a base). *(bokura)*
- **A vtable-less base adds its RTTI name to the unit's .rodata**: when a level-3 unit's .rodata
  grows by a name's length, the class has no such base; use a member or a cast instead. *(bokura)*
- **The vptr goes after all of the introducing class's own fields** (checked: `{int x; virtual;
  int y;}` puts x, y, then the vptr). A class whose vptr is at 0 but has fields gets a field-less
  interface base (CMenuMgr, CUserFlagMgr, CMapEffWork). *(bokura)*
- **Declare a class's destructor (non-inline) in every TU that constructs it**, or GCC treats it
  as having no key method and emits a linkonce vtable, implicit dtor and typeinfo function. *(bokura)*
- **Calls into other lanes' units by mangled name go through config/aliases.ld** (`__8CPushBuf`,
  `__9CEventRes`, `_$_8CProcess`...); bk port now accepts names defined there. *(bokura)*
- **A key method in a snippet can't go through `bk port`** (the snippet object references
  `__rtti_user`): paste it into the .cpp, name it in symbol_addrs.txt, then `dataconv apply/fix`. *(bokura)*
- **Forward loops `for (i = 0; i < n; i++) a[i] = -1;` come out as retail's count-down loops**;
  writing the count-down by hand changed the constant order. *(bokura)*
- **`&m_ids[k]` at a large offset**: retail computes `this + (k*4 + 0xFF30)`, which only matched
  through a helper doing that sum in a local (CGameEventObj IdPtr). *(bokura)*
- **A compiled jump table can land 8 bytes later than retail** after an INCLUDE_RODATA block
  (CMovieObj 0x13EC28); check rocheck after porting a switch. *(bokura)*
- **CDemoMain's constructor leaves member-ctor delay slots empty** from the third member on while
  ours fills them: maybe that unit was built with exceptions (retail has 0x7C of .gcc_except_table). *(bokura)*
## r2
- **Unnamed .bss words**: spimdisasm leaves some `lui 0x31; sw -0x1E80` pairs as raw constants (no
  `D_` in undefined_syms_auto.txt, also positive-`%lo` ones like 0x310D9C). A constant address in C
  compiles through `$at`, not retail's `$2`, so name the word and define it in config/aliases.ld
  (adding it to symbol_addrs.txt does not get it defined). Often a struct member works instead:
  `D_30F580.m1820[i]` emits `D_30F580+0x1820` and links to the same bytes. *(bokura)*
- **newlib `tolower` keeps the `lui` in the loop**: `(_ctype_+1)[(unsigned)c]` with `_ctype_` at
  0x2EAE78 matched; indexing `D_002EAE79` directly hoists the address out of the loop. *(bokura)*
- **Clamps**: `v = v < lo ? lo : (v > hi ? hi : v);` gives retail's branchy shape (bltz/beql);
  if/else-if chains and inline Clamp helpers if-convert to `movz`. Storing the clamp to a
  global matched only through a temp (`s32 t = ...; g.m510 = t;`). *(bokura)*
- **"if (ok) return x; return 0;" with retail's bnez-to-return layout** matched only as
  `if (cond) goto found; return 0; found: return e->x;` (about 15 slot getters). *(bokura)*
- **List init loops want pointer walks**: `for (i = 0, n = tbl; i < N; i++, n++)` matched the
  free-list builders where `&tbl[i]` did not (0x20D6E0, 0x20B9F0). *(bokura)*
- **Unlink-by-id loops**: `pp = &head; for (;;) { e = *pp; if (!e) return; if (e->id == id) {...; return;} pp = &e->next; }`
  keeps retail's top-tested loop; a `for (...; (e = *pp) != 0; ...)` gets rotated. Inside it,
  `if (flag) p->x = 1; else p->x = 2;` (not `?:`) keeps the movz in the loop. *(bokura)*
- **Range switch trees**: `case 0: break;` before `case 1: case 2:` reproduced retail's
  `t < 3` then `t > 0` order (0x20C280). *(bokura)*
- **Callee arity from pass-through registers**: a wrapper that leaves $a1/$a2 untouched before a
  `j` passes extra arguments; when a later function calls it with more args, widen the
  extern "C" prototype (func_0020E470, func_0020E808). *(bokura)*
## g2

- **Retail's assembler did not reorder delay slots: build with `-Wa,-g`** (Makefile and bk.py). GNU
  as 2.10 otherwise moves the last instruction of a macro (`la $4,0xCEB0($16)`, `sw $2,0xFC60($16)`,
  any offset >= 0x8000) or of an inline asm into the following `jal`/branch delay slot; retail keeps
  it before the call with a `nop` in the slot. The whole tree still matches with it, and it fixed a
  dozen old HARD entries (docs/compiler.md). *(bokura)*
- **Branch-likely vs branch is decided by the code after the branch**: several `bnezl`/`blezl` vs
  `bnez`/`blez` DIFF-1s went away once the code *after* the loop or test had retail's shape (an early
  `return 0` instead of an if-block around the tail, CGameSchedule 0x15E2F8). Fix the rest first. *(bokura)*
- **Loops with no loop notes**: a list-draining loop only matched written with `goto` (no `while`):
  loop.c otherwise hoists `this+0xBC` out of the body and adds a zero-init (CGameSchedule 0x159C50). *(bokura)*
- **Pointer-to-member constants come from the compiler**: `Func1092B0(&CFlagWork::Func108AA8, name)`
  emits the 8-byte `{0, -1, pfn}` constant in .rodata and loads it with `ldl/ldr`; delete the
  INCLUDE_RODATA of the constant (old HARD 0x108E10/0x108E38). *(bokura)*
- **A void-declared callee used as a value**: when one unit's declaration of Func235DE0 is void but a
  function needs the int-returning call shape (`lui $3` after the call), call it through
  `((int (*)(const char *, ...))Func235DE0)(...)`; the call stays a direct `jal`. *(bokura)*
- **Value-returning virtual slots show in their own call**: `lw v1,0(obj); addiu v1,slot; lw v0,4(v1); jalr v0`
  (v1 for the slot address) means that slot returns a value; void slots use v0/v1 the other way. *(bokura)*
- **Literal or extern**: in a level-2/3 unit, a string that dataconv lists as "in asm/.../func.s" must
  become a C++ literal when the function is matched (the label disappears), one listed as INCLUDE_RODATA
  stays an extern. A literal shared with an INCLUDE_ASM'd function can't move. *(bokura)*
- **The 0x170-byte CLayoutObj is 16-byte aligned**: vptr at 0x164 after its fields, size rounded up to
  0x170 (`__attribute__((aligned(16)))` on the class); the hourglass object (0x1BD188) holds one as its
  first member, not as a base (no vptr store in its ctor). *(bokura)*
- **Struct copies of 5 bytes, `char` vs `u8`**: a `lbu` in retail where ours has `lb` means the buffer
  or the copied byte is unsigned (CEventMesRes Load: `u8 line[]` made the alnum tests match). *(bokura)*
## g4
- **Retail's assembler ran with `-g` (`-Wa,-g`)**: GCC leaves calls whose delay slot it cannot fill
  (the soft-double libcalls after the first, `move $a0,$v0` before a call) to the assembler in
  `.set reorder` mode; GNU as 2.10-ee swaps the previous instruction into the slot unless `-g` is on.
  Retail always has `jal; nop` there. Found by lanes g2 and g4; main uses `-Wa,-g` (cc `-g` also works
  but stops the bare `return;` sibcall trick). *(bokura)*
- **Float literals go through decimal text**: GCC prints `li.s` with 21 digits and gas re-parses it, so
  `0.1f` assembles to 0x3DCCCCCC and `-0.93f` to 0xBF6E147A; a constant like 0xBF6E147B comes from a
  folded expression (`0.07f - 1.0f`, a lerp macro `x * (hi - lo) / 100 + lo`). *(bokura)*
- **Loops not touched by loop.c**: no strength reduction and no invariant hoisting (index recomputed
  every iteration, `base * 23` inside the loop) point at a loop written with `goto` labels; GCC 2.96
  only optimizes loops that carry loop notes (0x150EA8 got within one branch this way). *(bokura)*
- **`&a[i].f` vs `(a + i)->f`, and `(u8 *)p + o` with `s32 o = k * 16 + 4`**: the operand order of the
  final `addu` follows the expression form; when retail adds the scaled index first and the base
  last, a local offset variable reproduces it (0x124000, 0x123F40). *(bokura)*
- **Retail reloads a member pointer after a store through another pointer** (`lw $5, 4($16)` after
  writing the rect): the source used `m_param->...` each time, not a cached local; with the local
  the registers also come out swapped (0x121AD0). *(bokura)*
- **A function that passes a float through `$f12` untouched takes it as a parameter**:
  CCharaObj::Func114050 only matched once it took the `f32` its callers leave in `$f12`; three
  signatures gained it (old mangled names in aliases.ld). *(bokura)*
- **A compiled string loses the padding splat kept after it**: moving `"*** failed to regist XMN"` from
  a function `.s` into C++ dropped the 12 zero bytes before a 16-byte vector constant; keep it as
  `extern` + INCLUDE_RODATA (force_not_migration). Do not add `.balign 16`: it raises the object's
  .rodata alignment and moves the whole piece. *(bokura)*
- **`bk show` with a match marker**: comparing the instruction words (relocations masked) and printing
  `!!` on differing lines finds the real differences at once; text comparison of the two disassemblies
  drowns in syntax noise (numeric vs named registers, hidden nops). *(bokura)*
## r1 (goal 6b: XMN / rx* middleware after CAppMain)
- **Short-loop padding counts asm() statements as one insn**: EE-GCC pads loops shorter than 6 insns
  with nops (R5900 short-loop erratum). A CP0 poll loop written as one multi-line asm() got 3 extra
  nops; one instruction per asm() (`sync.p` / `mfc0 %0,$12` / `sync.p`) matched (0x1F1610 and the
  other DI/EI loops). *(bokura)*
- **Volatile shows in the delay slots**: retail `lw old; bnel; sw (likely slot)` and `sw r; bgezl`
  where ours filled the slot: the memory-card slot pointers shared with the worker thread are
  pointer-to-volatile (`extern volatile CRxMcSlot *D_2ED200`); a struct-wide volatile also forced the
  store order in a plain init function, so only the shared pointers are volatile (0x1ED830, 0x1ED908,
  0x1ED978). *(bokura)*
- **Full-address `lui; addiu; lw 0(r)` for a global used once = volatile global** (combine does not
  fold %lo into a volatile access): the rxThread queue indices and flags (0x1EF0D8, 0x1EF140). *(bokura)*
- **A run-time `divu` of two constants** (li 0x600; li 6; divu) is an inline helper taking both as
  parameters; a clear loop whose counter runs 30..0 by 2 is a pointer walk with `i += 2` (0x1F23E8). *(bokura)*
- **`lui $3` vs `lui $2` after a call/virtual call is the callee's return type** (again): fixed the
  CAppMain constructor's 6 diffs by making the callees non-void one by one. *(bokura)*
- **GNU as 2.10 macro bug hit again**: `lw $2, D_X+off($2)` assembled its `lui` as a copy of the lw
  after an unrelated change earlier in the file; `asm(".p2align 3");` before the function fixed it
  (0x1F1870). *(bokura)*
- **bk test masks relocations**: two stores to different globals in swapped order pass `bk test` and
  only fail in mk.sh (0x1EF5C8, 0x1F0CF8); check relocs with `objdump -dr` when a function writes
  several globals. *(bokura)*
- **splat merged three functions** into func_001F0AF0 (glabels D_001F0BB0, func_001F0C08 inside):
  replace the INCLUDE_ASM by all three C functions; the old glabel names keep linking. *(bokura)*
- **A function returning a found index that is always -1** (0x1F1088) is a real bug in the original:
  write it as `return -1` in both places, don't fix it. *(bokura)*

## head (merges, 2026-10-15)
- Lanes g2 and g4 each found that retail's unfilled delay slots after `.set reorder` calls need
  `as -g` (one as `-Wa,-g`, one as `-g`, which also changes sibcalls); the C-style units after
  CAppMain match only without it. The Makefile sets `-Wa,-g` per unit (ASG); bk.py follows the
  function address. A flag that "keeps the whole tree matching" in one lane can still break code
  another lane matched meanwhile: rebuild the merged tree before trusting it.
- Merges: a renamed function breaks other units' INCLUDE_ASM lines and old-name callers.
  `fixnames.py` (INCLUDE_ASM from symbol_addrs) plus aliases for each undefined func_ fix both.
## g1 (overnight grind 2026-10-15: CSvmRes, CFaceObj, ISysFlag, CSndWorkReal, mini-games, menus)
- **Switch jump tables are `.align 4` (16) in .rodata**, so a converted unit with a compiled switch gets a 16-aligned .rodata section. Where retail's piece starts at an 8-aligned address, the first 8 zero bytes were padding after the previous unit: move the yaml piece start up 8 and drop that INCLUDE_RODATA (CUserFlagMgr 0x2D5EE0, CMovieObj 0x2D5D60); the linker pads. *(bokura)*
- **GNU as 2.10 corrupted a jump table's `lui`** (assembled as a copy of the following `lw` with a HI16 reloc) in CMovieObj; a file-scope `asm(".p2align 3");` before the function fixed it, as in CNameDBMgr. *(bokura)*
- **Member-function-pointer constants**: `return SaveWith(&CMapSndRes::Save, name);` emits the 8-byte {0, -1, pfn} constant into .rodata and loads it with ldl/ldr, exactly retail's shape; mind the INCLUDE_RODATA order around it. A PMF field call `(m_obj->*m_log)(buf)` matched CUserFlagMgr's log hook. *(bokura)*
- **Error-print guards are void**: `if (bad) return (void)Func235DE0(fmt, x);` gives the sibcall and leaves a stored constant in `$v0` (with an int return it lands in `$v1`). Fixed 0x1845F8, 0x1829A0, 0x1827E8. *(bokura)*
- **Int clamps as a nested ternary** (`v < lo ? lo : (v > hi ? hi : v)`) keep retail's branches; if-statements become movz/movn. A range check written as nested ifs keeps two signed compares (`&&`/`||` folds them into one unsigned compare). A constant upper bound becomes `slti hi+1`; retail's `li hi; slt` comes from a variable bound. *(bokura)*
- **`this + (i * size + off)` helpers** (the CGameEventObj IdPtr trick) also fixed CMiniGame3's entry setters; a value written through `CRand::Rand(n) { return ((Next() << 16) | Next()) % n; }` keeps retail's real `divu` because the divisor is an inline parameter. *(bokura)*
- **Chained float assignment `a = b = c = d = 1.0f`** gives the "copy of a copy" base registers some retail stores show. *(bokura)*
- **A callee's return type shows after the call**: `lui $3` (not `$2`) for the next global means the callee returns a value (CUnk237E90::Func237E90, func_0024B298). *(bokura)*
- **Struct alignment changes inline strcpy**: an 8-aligned destination (`__attribute__((aligned(8)))` on the record) turns the ldl/sdl copy of a literal into ld/sd + lhu/lbu. *(bokura)*
- **Several "unit text starts late" functions** in my units belong to the next class (CMiniGame2/3 task code in the Res files, CMenuSave code at the end of CMenuSysscr00.cpp): matched in place with their real class names. *(bokura)*
## 2026-10-15: g3 (overnight grind: menu draws, CTitleMain and CMenuSysscr27 to level 3)
- **Key methods in merged units without a vptr store** (CCommandIncDec::Update): write them as plain members of a non-virtual class in the TU; the asm vtable links to the mangled name.
- **A class whose retail destructor is inline**: the real key method is the next virtual (CMiniGame4Res::Load). Declaring the destructor non-inline (and never defining it) makes it the key method in this TU, so Load can be defined without emitting the vtable.
- **Inline strcpy of a short literal while the unit's .rodata is asm**: `struct CStr6 { char c[6]; }; extern CStr6 D_X; *(CStr6 *)dst = D_X;` gives the same lwl/lwr/lb/sb (or lbu/sb) copy (0x16DEE8, 0x169340, 0x1693B0).
- **`strcpy(buf + strlen(buf), "lit")` as calls**: written directly GCC inlines the copy; an inline helper `StrAdd(d, s) { strcpy(d + strlen(d), s); }` keeps the strlen/strcpy calls (0x10FFE8).
- **Float constants are truncated by the compiler**: 0x3F599999 / 0x3F4CCCCC are just `0.85f` / `0.8f`; writing the exact value (0.84999996f) gives one ulp less.
- **Clamps that keep retail's branches**: `n = n < 0 ? 0 : (n > 16 ? 16 : n);` (0x196B50, 0x110178) where if/else-if if-converts to movz.
- **Members with constructors vs explicit calls**: CSceneSet's constructor only matched with real member objects (`CDkArr m_arr;` with the TArray constructor named in aliases.ld); explicit `func_X(&m)` calls schedule the vptr store differently.
- **A later store through a sub-object pointer**: `CInterfTimer *t = &m_timer; t->Reset(); t->m_unk4 = m_unkC4;` stores through the timer register as retail does (0x169340, 0x169450).
- **`bk show` hides the two nops the assembler puts before div.s**: not a diff.
- **Separate loop counters**: several loops sharing one `s32 i` got different registers from retail; `for (s32 i = 0; ...)` per loop matched (0x1789B8, 0x1795F8).
- **Out-parameter float pairs are scalars**: `f32 x, y; f(&x, (s32 *)&y, k)` packs them 4-aligned like retail; `f32 v[2]` or a struct gets a 16-aligned slot (0x197950).
- **`case 0: break;`** in a two-case switch gives retail's `slti`/`bnel` default test when the decision tree has it (0x1789B8, 0x1795F8), but not where retail tests only 1 and 2 (0x1787E8).
- **`t->s[i]` vs `t[i + 1]`**: indexing a struct's array member puts the pointer first in the `addu` (retail order); `t[i + 1]` on a `char **` puts the index first (0x186198).
- **A temp for a call argument read from memory** moves its load before the constant float args (0x1974F8: `f32 w = m_win->m_unk34; SetUnk40(1.0f, 1.0f, 1.0f, w);`).
- **Re-writing `(T *)(p + 0x10)` at each use instead of a local** matched where the local got its own saved register (0x17B4D8).
- **Menu state machines (state.h)**: a `goto loop` loop (`loop: if (done) goto out; if ((flags >> 7) & 1) goto out; switch (m_sm.m_state) {...}`) keeps the `done` flag in a register like retail; a `for`/`while` lets GCC thread `done = 1` straight to the exit. Each yield written as `m_state = X; done = 1; goto loop;` gets cross-jumped into retail's shared `li a0,1; b loop; sw $2,4(this)` tail. The busy test needs `u32 fl = flags; if ((fl >> 7) & 1)` (srl/andi, no extra andi 0xffff). 0x1AC200 got from DIFF 1100 to 30 this way; what is left is the placement of the last wait's "then" block (retail has it before the test).
- **A struct's array member vs a separate local pointer**: using `p->m_name` at each use instead of `char *pname = p->m_name;` put the pointer in retail's register order (0x12C8D0); same for `(T *)(p + 0x10)` (0x17B4D8).
- **Hidden extra arguments**: a call that sets f12 = 0.0f before `jal CallFunc114050__9CCharaObji` means the callee also takes a float; add an alias with the full signature (`CallFunc114050__9CCharaObjif`) in config/aliases.ld instead of renaming.
- **`new X` of a class whose vptr follows a base's fields** (CCharaObj, vptr 0xC): declaring extra fields after the vptr moves the vptr (GCC puts it after all of the introducing class's own fields); allocate with `operator new(size)` and call the constructor through an extern "C" alias, and read later fields through a separate view struct.
- **Constant multipliers kept as `mult` with a register operand** (0x16E960 `k * 0xF1`): retail did not strength-reduce one of them while ours turns it into shifts; not solved (an inline helper changes the whole schedule).
## r3
2026-10-15, lane r3 (rxsnd/rxsndstr/rxsndut C units, Unit20E938..Unit215A38).
2026-10-15, lane r3 (rxsnd/rxsndstr/rxsndut C units and the GS packet units, Unit20E938..Unit21F250).

- **rxsnd request functions are protothreads**: a header {u8 flags; u8 depth; u16 lc; u16 stack[]}
  at +0x1C, `switch (lc)` with `__LINE__` case labels (0x476, 0x4C5, ...), `flags & 0x80` aborts.
  The wait macro is a loop: `while (cond) { lc = LINE; goto yield; case LINE:; }` (GCC rotates it, so
  the store/yield block sits before the test). Two macro flavours exist in one unit: some functions
  store `lc` in each wait block (`li; b; sh`), others set a local and share one `h->m2 = _nlc` at the
  yield label (`b; li` + common `sh`). Read the lc before the flags test. *(bokura)*
- **Calls that are never sibcalls**: rxsnd dispatchers (`switch (type) { case 0: A(h); break; case 1:
  B(h); break; }`) end in `jal` + `b epilogue`; GCC 2.96 makes those `break` calls sibcalls unless the
  switch sits in a loop (`do { switch ... } while (0)`, i.e. a macro), since expand_call refuses tail
  calls inside loops. *(bokura)*
- **`if (p) { for (; p; p = p->next) ... }`**: a redundant guard before a list loop gives retail's
  duplicated test layout (0x210BD8, 0x211260, the free-list drains). *(bokura)*
- **`MIN`/`CLAMPZ` macros that call a function twice**: retail calls `func(x)` 2-4 times inside
  nested `?:` (0x210498, 0x210C58); write the macro, not a temporary. *(bokura)*
- **Parameter registers that stay live**: a callee getting `fn(s->m18, a)` with `a` passed through
  keeps `$5` busy, which moves the other temporaries (0x20FE20: fn in $7, mask in $6). *(bokura)*
- **EE short-loop nops count asm statements**: inline-asm loops (mtc0/mfc0 status spins) only match
  with one `asm volatile` per instruction; one multi-line asm statement counts as one insn and gets
  extra nop padding. *(bokura)*
- **Same-unit splat stubs fix the prototype**: `extern "C" void func_X(void) {}` bodies in the unit
  (empty functions) clash with a snippet declaring `func_X(void *)`; bk test passes, the build fails.
  Declare them as `(void)` and call through a cast. *(bokura)*
- **Store order of init functions**: GCC 2.96 emits some stores of a run of constant field
  stores earlier than written. The source order that matched was the struct's natural field order
  with the `-1`/odd-valued stores last and the protothread header as `m0 = 0; m2 = 0; m1 = 6;`
  (0x216FA0, 0x217678, 0x213C98, 0x214180, 0x214610); bk perm (7-8 lines) finds these quickly, and
  for longer runs try inserting the early-emitted stores near the end of the natural order (0x214F70,
  0x216230). Hill-climbing perm from the natural order solved a 27-store init (0x20F0D8) that
  never converged from the as-disassembled order. *(bokura)*
- **Loads hoisted above stores to a stack array**: a store to a local array whose address escaped
  does not block loads through an argument pointer (different base), but does block loads through a
  pointer loaded from memory; the reload pattern tells you the statement order (0x215A68). *(bokura)*
- **Temporary before advancing a list pointer**: `do { f = w->m9; w = w->parent; v |= f; } while (w);`
  matched where `v |= w->m9; w = w->parent;` swapped the `or` operands (0x2159D8 and 4 clones). *(bokura)*
- **Separate variable for a drain loop**: reusing the insertion loop's pointer variable for the
  free-list drain changed every temp register (0x210E70, 0x211078). *(bokura)*
- **One counter per loop in pool-init functions**: free-list init functions with two or three
  loops matched only with a separate counter variable per loop (0x219AA0, 0x210958); sharing `i`
  shifted every register. *(bokura)*
- **GNU as 2.10 corrupted a `lui` again** (0x220FB8, `lw $2, %lo(D)($2)` after `lui $2, %hi(D)`):
  bk test passed, the full build did not; `asm(".p2align 3");` before the function fixed it. Always
  check mk.sh before committing a batch. *(bokura)*
## r4
- **VU1 packet writes are an inline function, not a macro**: `inline u32 *PUT(u32 v) { u32 *p = PKT; PKT = p + 1; *p = v; return p; }` gives retail's "load ptr, bump, store ptr, store value" order with the pointer reloaded every time (-fno-strict-aliasing); `*PKT++ = v` and value-first macros reorder. Returning `p` lets callers keep the slot (`D_x = PUT(...)`). 128-bit pieces are a `PutQ(hi, lo)` inline with four `sw`. *(bokura)*
- **Retail asm blocks name their scratch register**: a `mfc1 $8, $f20` before `qmtc2.ni $8` is part of the asm (`"mfc1 $8, %0"` with an `"f"` input and `"$8"` clobber); an `"r"` input lets GCC pick another register. *(bokura)*
- **Debug-alloc wrappers store the return address with asm**: `addiu $8,$31,-8; sw $8,0(sp)` right after copying a const `Loc` template matched only as one `asm volatile("addiu $8,$31,-8\n\tsw $8,0(%0)" :: "r"(&l) : "$8","memory")`; `__builtin_return_address` reads the saved slot and gets scheduled. Copy the template with `Loc l = D_x;` (extern const struct), not an initializer, or GCC emits its own .rodata copy. *(bokura)*
- **IOP-shared descriptor fields are volatile**: fd status words polled in loops (`mC8`, `mCC`) only matched as `volatile`; a load that stays out of a delay slot (`lw` before `jal` + `nop`) is the hint. *(bokura)*
- **Loop counter reused after the loop**: `D_33FE80 = 2` after two `for (port...)` loops was `D_33FE80 = port;` (register $18 = 2); reusing `port` for the second loop also fixed its register. *(bokura)*
- **`left -= r; buf += r;`**: retail adds to the buffer first; the source had the subtraction first (scheduler order is reversed). *(bokura)*
- **Constants combined across `|`**: `(x | 0x8000) | (n << 16) | 0x68000000` folds the two constants unless the first OR goes into a local (`a = x | 0x8000;`); same for 64-bit GIF tags (`t = (u64)d | ((u64)a << 32);` then the rest). *(bokura)*
- **`if (c) PUT(a); else PUT(b);`** matched where `PUT(c ? a : b)` made a movz. *(bokura)*
- **Two symbols at one address** (`D_x - D_x` not folded): declare a second name for the same label with `__asm__("D_x")`. *(bokura)*
- **GNU as macro bug again** in a short getter (`lw v1,0(v1)` in place of `lui`): `asm(".p2align 3");` before the function. *(bokura)*
- **`as -g` fixed old delay-slot near misses**: after the head switched the C++ units to `-Wa,-g`, 0x1698A0 (sibcall layout) and 0x196FF8 matched with the obvious C; retry delay-slot HARD entries after build flag changes.
- **A value parked in t0 before a varargs debug print is a 5th argument** (EE passes args 5-8 in t0-t3): 0x185FD8 matched once the fourth flag was added to the print.
- **Untested-at-top search loops**: `for (k = 0; k < j; k++) if (match) { x = y[k]; break; }` followed by `if (k < j) continue;` gives GCC's unrotated loop (jump to the test, `k++` in the exit branch's delay slot), 0x1B96F0.
- **Float select through a local** (`f32 v = 1.0f; if (!on) v = 0.0f; m = v;`) keeps `mtc1 $0` + `swc1`; a ternary stores integer zero (0x16B178).
- **Callee float parameters first**: if f12/f13 are set before a1 for a call, try the callee with its float parameters before the int ones (0x16A998 `func_0016A650(p, x, y, a, w, h)`).
- **CTextBuf (0x90-byte font text object)**: declare it with `CTextBuf() { func_0010BF88(this); }` and `void Clear() { m0 = 0; }`; the `m0 = 0` store through the inline's `this` keeps its place ahead of later `this->field` loads, and Draw17D3B0 constructs it at the top but clears it later.
- **Block-scoped loop counters**: giving each loop its own `{ s32 j; for (...) }` counter fixed s-register numbering in five functions (0x17A968, 0x17A370, 0x17D3B0, 0x197AE0, 0x17BDF0). A function-scope `i` shared by several loops becomes one long-lived pseudo; retail even keeps a counter in a0/a2 when the loop's calls are only on its exit path. Arrays stay at function scope (stack layout follows outer declaration order).
- **Struct copy of a rodata table** (`CMemorialIds ids = D_002DA980;`) is the ldl/ldr/sdl/sdr unaligned copy.
- **Brute-force store order**: for runs of field stores (text object colour/position), generate all statement permutations and test them with `bk vtest` (192 variants take about three minutes); 0x17D3B0 needed `m3C` first and chained `m18 = m10 = x`.
- **Loop condition operand order**: `i < a + b` vs `i < b + a` decides the `addu` operand order (0x197AE0).
- **Member-function-pointer index = vtable slot + 2** in EE-GCC 2.96 ({delta, index, delta2}); `&CUserFlagMgr::Dispatch1411B8` (slot 19) is {0, 0x15, 0}. The compiler emits the PMF constant into .rodata at the function's position in the file, so move the surrounding INCLUDE_RODATA lines until it lands where retail has it (CUserFlagMgr 0x13F488: the static table's strings had to move above the function). *(bokura)*
- **Constructors with member objects** match without converting the unit: give each member a tiny struct whose inline ctor calls the unmatched ctor (`CMgLayout() { func_001B9D40(this); }`), keep the CStateMachine/CRand inline ctors, and call it from the factory as `new X(a, b)` (CTask::operator new). The register choice for the following constant depended on a member ctor's return type: `extern "C" void *func_001BD188(void *)` matched, `void` did not (CMiniGame3 0x1C9D70). *(bokura)*
- **Line-reader loops** in CUserFlagMgr/CMiniGame2 are `while (s = Read(s, line, 1, 0x100), *s || line[0]) { if (!line[0]) continue; ... continue; }`, with tables written as `tbl[n].x` (strength-reduced pointer plus a separate null test of the original). Assign `s = text` right before the loop when retail reloads `text` from the stack. *(bokura)*
- **`__builtin_alloca(n)`, not a VLA**: a VLA saves and restores sp around its block, alloca doesn't (CUserFlagMgr 0x13F948). *(bokura)*
- **Loop pointer based on the last field**: when retail's loop pointer sits on the second field with a negative offset for the first (`swc1 -0x4($6)` / `0x0($6)`), write `f32 *p = &e[i].m14; p[-1] = ...; p[0] = ...` (CMiniGame3 Layout). *(bokura)*
- **VU0 macros** (CSndWorkReal 0x129EB0): rotations are `qmtc2.i cos,$vf4; qmtc2.ni sin,$vf5; vnop; vnop; vcallms N` with sin/cos from the D_002A6800 table (cos index +0x1000); the matrix store is one asm with `la $2, %0` on an `"=m"(mat)` operand, which assembles to retail's `addiu $2,$sp,N` and keeps the call argument a separate `addiu a1,sp,N`. A `"r"` pointer operand gets CSE'd with the call argument. Existing helpers: FracVu0/Ftoi15 (CSwingBoneObj), VuSqrt (CMapEffObjRes); a VuSqrt user matched only with a single-exit `r` result. *(bokura)*
- **Float args copied from block locals**: retail's `(a, a, b, b, a, a)` argument copies from callee-saved f20/f21 come from `f32 a = 1.0f, b = 0.0f;` locals passed repeatedly (CMiniGame3 Draw); inside loops our build still rematerializes the constants. *(bokura)*
- **Stale mangled names of other lanes' functions**: when main has corrected a callee's signature (CLayoutObj::Draw1BA1D0), declare main's signature and, if your tree still has the old name, add an address alias line; don't rename the other lane's symbol. *(bokura)*
- **GS packet builders** (fade/tutorial/sound draws) are still open: the content decodes cleanly (see CSndWorkReal 0x12A6B0's note) but `*D_2EBF8C++ = v` stores the packet pointer after every word, where retail skips some of those stores. *(bokura)*
## d1 (goal 6b: dklib memheap, CBgMgr, CPushBuf, XAP archives, tokenizer, CExpr values, CTask tree)
- **bk test assembled dklib snippets without `-Wa,-g`** while the Makefile assembles the Dk units with
  it (bk.py only checked `addr < 0x1E91B8`); a local fix (`or addr >= 0x245648`) made bk test agree
  with mk.sh. *(bokura)*
- **An inline function stops GCC from reassociating pointer arithmetic**: `(u8 *)b + 16 + size` came
  out as `b + size + 16`; `inline u8 *BlkData(CMemBlk *b) { return (u8 *)(b + 1); }` then `+ size`
  kept retail's `addiu 16 ; addu size` (memheap split 0x2466E8). *(bokura)*
- **A branch target 4 bytes later than ours means a store retail does only on one path**: 0x2466E8's
  `nb->m_node = nn` belonged to the else branch only (the other branch's `b` skipped it). *(bokura)*
- **`if (m == 0) A; else if (m != 1) A; else B;`** (identical A blocks, cross-jumped) gives retail's
  "test 0, test 1, fall into A" layout that neither `switch` nor `if/else if` produced. *(bokura)*
- **Key method trick for a class whose retail slot 0 is an inline function**: declare slot 0 as a
  non-inline virtual in the TU and never define it (CBgMgr, CDebOut); then the other slots, the
  constructor and the destructor can be defined with the vtable still in asm. A vptr at 0 with fields
  needs a field-less base declaring the virtuals (IBgMgr, IDebOut); no extra vptr store appeared. *(bokura)*
- **PMF members**: `(obj->*f)(arg)` reproduces GCC 2.96's index/delta/pfn call sequence; a PMF passed
  by value travels in one 64-bit register (`sd $6`/`ld $6` spills). GCC 2.96 mangles the implicit
  `this` into the PMF's parameter list (`PM5CExprFP5CExprPCcPv_i` is `int (CExpr::*)(const char *,
  void *)`). *(bokura)*
- **Local declaration order sets the stack layout**: `const char *p = s; CValue v;` put `p` at sp+0
  and the 0x104-byte value at sp+0x10 like retail (and kept `&v` in a saved register). *(bokura)*
- **`__builtin_alloca(size)` with `size` in a local** reproduced the `$30` frame-pointer ini lookup
  (0x24B190); a copy of the source pointer param (`const char *p = src;`) fixed its register order. *(bokura)*
- **Raw constant addresses that lie inside a known object** (`lui 0x39 ; sw 0x35E8`): reference them
  as a field of a struct declared over the named symbol (`D_38F2D8.m_unk4310`, a `CGsGlobal` over
  `D_393910`); the relocation `sym + off` links to the same bytes. *(bokura)*
- **for-loop with the advance in the increment** (`for (n = first; n != end; n = n->next) {...; if (n
  == last) break; }`) matched retail's rotated memheap walks where `while`/`goto` versions did not. *(bokura)*
- **Mis-named callees keep their names via asm labels**: `extern "C" s32 FileSize(const char *)
  asm("Func248EB0__8CPushBuf");` calls a free function another lane named as a CPushBuf method without
  renaming it; same for defining `Func247B00__13CMiniGame6Obj` (a heap dump). *(bokura)*
- **`char` vs `u8`**: a `lbu` in retail where ours has `lb` means the buffer or the copied byte is
  unsigned (CEventMesRes Load: `u8 line[]` fixed the alnum tests, the rest of Load still differs). *(bokura)*
- **`case 0: default:` makes a compare tree**: a two-value switch whose zero case shares the default
  (`switch (v & 0xF0) { case 0: default: return 0; case 0x10: return 1; case 0x20: return 2; }`)
  compiles to retail's `beq 0x10 / slti 0x11 / beq 0x20` tree; without `case 0` GCC if-converts
  (CLayoutObj LayoutFlagX/Y). Same for the default arm of a bigger switch (0x1BC6A8). *(bokura)*
- **A loop whose exit test is in the middle**: `while (*s) { ...; s = next; ...; if (*s) h += gap; }`
  gives retail's "test at the bottom, add, jump back" (GCC threads the duplicated test); `for (;;)`
  with `break` is laid out differently (CLayoutObj 0x1BC6A8). A flag test as part of the loop
  condition (`for (i = 0; i < 16 && f(id = ...); i++)`) keeps retail's jump-to-test loop with no
  strength reduction (CGameResort 0x167A48). *(bokura)*
- **Strength-reduced output pointers**: `CFaceTex *o = &out[k]` computed at the top of the inner loop
  body (unconditionally) becomes retail's preheader `o = out + k*16` with `o++` next to `k++`; the same
  expression inside the `if` that uses it is not reduced (CFaceRes 0x10ED30). *(bokura)*
- **`m = m + 1` vs `m++` on a field**: `m_num++` gave an address temp (`addiu a0,s2,0x18`), retail
  loads, adds and stores (`m_num = m_num + n`) (CEventObj queue writers). *(bokura)*
- **Constants the compiler did not CSE**: a store value 1 kept in a callee-saved register next to a
  compare with 1 in v1 means the source assigned through a variable (`s32 open = 1; ... if (!(x &
  bit)) open = 0;`), not two literal 1s (CGameSchedule 0x15DAB0). *(bokura)*
- **Dead-code literals and RTTI names after the last function**: when the last function before a unit's
  RTTI names is matched, the names (`8CListTag`, `5CList`) that splat had put into its .s must become an
  INCLUDE_RODATA (add the label to config/rodata_syms.txt); `dataconv.py UNIT fix` does not catch it
  (CGameSchedule D_002D9508). *(bokura)*
- **VU0 macro-mode inline asm**: `vftoi15`/`vftoi0` helpers are inline asm with the `mfc1`/`mtc1`
  inside the asm text and hard-coded `$2`/`$8` (clobbers), `ACC` written without `$` for our as;
  the sine table is indexed as `*(f32 *)(tbl + ((i << 1) & 0xFFFC))` with `tbl` a local (CSwingBoneObj,
  CMenuMgr 0x1B6570, CMenuSysscr01 0x1AE3F8). *(bokura)*
- **Pointers to member in .rodata of an unconverted unit**: pass the asm label as an extern
  `const PMF` (`extern const CExprAccessFn D_002DA200;`) instead of `&Class::Method`, or the compiler
  emits a second copy (CMapDBExpr ctor). *(bokura)*
- **Struct copies with `ld`/`sd`**: a 0x40-byte struct copied with aligned `ld`/`sd` needs
  `__attribute__((aligned(8)))`; with 4-byte alignment GCC uses `ldl/ldr` (CLayoutObjSub1BC320). *(bokura)*
- **A callee already compiled in the same .cpp changes delay-slot filling**: CLayoutHourglass 0x1BD420
  matched in a bk snippet but not in the unit: with `CLayoutObjSub1BA0A0::Reset()` defined earlier in
  CLayoutObj.cpp, GCC filled a `beqz` delay slot that retail left empty. Calling it through an
  `extern "C" func_001BA0A0` alias (config/aliases.ld) restored retail's code. When bk says MATCH and
  mk.sh doesn't, bisect the earlier definitions in the unit. *(bokura)*
- **A converted unit's first compiled jump table moves its .rodata start**: jump tables are 16-aligned,
  so CLayoutObj's .rodata piece (0x2E0BE8, 8 bytes of padding first) had to start at 0x2E0BF0 with the
  padding INCLUDE_RODATA dropped (same as the CUserFlagMgr lesson); and the case blocks must be written
  in retail's code order, not case order (0x1BA210: case 2's block comes first). *(bokura)*
- **The last function of a unit**: retail's .text ends 8-aligned; a C function that ends 4 bytes short
  of an 8-byte boundary gets the padding from the linker, so nothing extra is needed (check the yaml
  start of the next unit before adding `.space`). *(bokura)*

## r6
2026-10-15, lane r6 (Unit230578, Unit232B78: CD/host file wrappers, ISO9660 path table and directory walk, sector cache, worker-thread request queues).
- **Callee return type decides a temp register**: 0x230638 matched only when `func_00230928` (a strcpy+strcat path builder) is declared `void` at the call site (ours used v1 for a `?:` temp while the call "returned" a value in v0). The builder itself is `void` with `return (void)strcpy(...)` for the `j strcpy`. *(bokura)*
- **`strcat` is an inline `strcpy(d + strlen(d), s)`**: the source argument is evaluated before strlen (the suffix pointer load sits in strlen's delay slot). A tail `j strcpy` needs a plain `return strcpy(dst + strlen(dst), ext);` with `ext` loaded into a local first; returning the inline's result doesn't sibcall. *(bokura)*
- **Switch case order shows in the layout**: `switch (cb()) { case 1: return b; case -3: return -2; case -2: f(); case -1: default: return -1; }` (fallthrough, default sharing -1's body) matched 0x230FE8; a result check that tests `< -2`, `< 0`, `== 1` was a nested `switch (n) { case -2: case -1: break; case 1: return size; } return -1;`. *(bokura)*
- **Two copies of the same switch body cross-jump**: when one switch's leaf jumps into another switch's code, write both switches with identical full case bodies (not gotos to shared labels) and order the bodies as retail lays them out (0x2315B0). *(bokura)*
- **`li $7,1` in a delay slot before any use = an initialised result** (`s32 r = 1;`); adding it fixed the instruction count of 0x231268. *(bokura)*
- **Field-wise copy vs struct assignment**: an 8-byte `u8` clock copied with eight lbu/sb pairs was eight field assignments; the same struct copied into `*this` with ldl/ldr was a struct assignment (0x230B30 vs CUnk2320F8::Func2320F8). *(bokura)*
- **Only the thread-shared field is volatile**: `Req::m0` (request state polled by the worker) as `volatile` kept a store out of a likely delay slot in 0x233AA8; making the whole struct volatile is wrong. *(bokura)*
- **Retry macro** `while ((r = f(buf, pos, n)) != 1) if (r == -2) return r;` matched both ISO9660 walkers (0x2319F8, 0x231BC8) with the constants hoisted into s-registers; `do { ... } while (off < total)` with `idx++` inside matched the path-table scan, and `if (len == 0 || ...) next sector; else off += len;` (inverted) gave the retail block order. *(bokura)*
- **`if (f(q) > 0) return x; return 0;`** matched where `if (f(q) <= 0) return 0; return x;` gave the opposite branch (0x2339B8). *(bokura)*
- **A found block after the function's infinite exit loop** = `goto found;` to a label after `for (;;) yield();`, ending in `goto loop;` (worker thread 0x2334B0). *(bokura)*
- **bk perm on tails and prologues**: 3-5 store lines after a loop (0x231850, 0x2320A0) and the 7 initialiser statements of 0x231268 (5040 orders, DIFF 35 -> 11) are cheap to brute-force once the control flow matches. *(bokura)*
- **Assembler limit**: retail sometimes has the last instruction of a `sw $5, D($4)` macro expansion in a `jr` delay slot (0x233D28, 0x233D40); GNU as 2.10 never does that, so these can't match with the current toolchain. *(bokura)*
- **splat merged D_00233808** (a 6-insn `j func_00230B30` wrapper used as a thread callback by 0x2331B8) into func_002334B0; it stays referenced as `extern "C" void D_00233808(s32);`. *(bokura)*
## r5
- **Volatile stores before a call or branch**: retail's assembler did not swap a volatile `sw` into the
  following `jal`/`b` delay slot (GCC prints `#.set volatile` as a comment for our gas, retail's gas
  honoured it). `asm volatile(".set noreorder\n.set reorder")` right after the store resets gas's
  previous-insn memory and reproduces it (0x244928); it also blocks GCC's own scheduling, so it does not
  always help (0x244860). *(bokura)*
- **Five-nop busy wait in SIF RPC binds**: `j = 9999; do { j -= 25; nop x5 } while (j >= 0);` with one
  `asm volatile("nop")` per nop matched the sceSifBindRpc retry loops (0x235718, 0x236010); an empty loop
  is deleted. *(bokura)*
- **`bk perm` can't see swapped globals with the same %hi**: perm (like bk test) masks relocations, so
  stores to D_38F078/D_38F07C or D_38F070/D_38F074 in either order score the same; the full build
  catches it (0x244178, 0x244198, 0x2449A8). *(bokura)*
- **Global packet pointers updated through a local copy**: `p = D; *p = tag; p++; D = p; p[0] = x;
  D = p + 1; ...` gave retail's single load and `p+8/+16/+24` constants (0x242408, 0x242098); `*D++ = x`
  reloads the global after every store under -fno-strict-aliasing. *(bokura)*
- **Store-to-load forwarding shows the source**: `g->mF = g->mD + s->m9` reuses the register just stored
  to `g->mD`, while `g->mE = g->mC + s->m8` after an if/else reloads `g->mC` (0x23FEE8). *(bokura)*
- **Return variables**: a `$2 = 0`/`-1` preset before the first branch with the value flowing to one
  epilogue is `r = 0; if (...) r = ...; return r;`, but where retail reuses the parameter register for a
  looked-up handle (`lh $4, tbl($4)`) the form is `if (i < 0) return 0; i = tbl[i]; if (i < 0) return 0;
  return ...` (0x23AA40, 0x23AB88, 0x23ABC8). *(bokura)*
- **Same-mask DImode ANDs**: two `(u64 >> k) & 0x3F` extractions in one function load 0x3F into a
  register in ours (`li; and`), retail keeps two `andi`; not solved (0x23A1D8, 0x23B948). *(bokura)*
- **Stack buffer address in a saved register**: retail keeps `daddu $17, $29, $0` for a local buffer
  passed once after a call; ours rematerialises `move a0, sp` (0x239BD8, 0x23A0F8), unsolved. *(bokura)*
- **Shared scratchpad**: lanes running from one parent session share the scratchpad; generic snippet
  names (s_a1.snip, s_a2.snip, t.sh) collide between lanes. Keep per-lane files in a lane subdirectory
  with lane-prefixed snippet names. *(bokura)*
- **Literal order shows duplicated source calls**: a string used at two error sites that the compiler
  cross-jumped into one call is still emitted where its first use sits in the source; when retail's
  .rodata has it earlier than a `goto fail` version produces, write the print twice (0x112710). *(bokura)*
- **`strcpy(d + strlen(d), s)` with `s` loaded before the strlen call** is an inline strcat helper
  (arguments are evaluated before the inline body) (0x112710). *(bokura)*
- **A dead high half kept in `(hi | lo) & 0xFFFF`** means the value was built in one variable assigned
  twice (`r = Next() << 16; r |= Next();`): combine only trusts the known-zero bits of a pseudo set
  once, so `return (Next() << 16) | Next();` folds the high draw away (CMapEffObjRes LCG, 0x123850). *(bokura)*
- Array of structs reached through a pointer to a struct that contains the array (`t->st[i].a`, with `struct { u8 pad[0x5C]; Stat st[6]; }`) gives GCC's mixed address bases (`this+0xC` hoisted for some fields, `this` for others); a cast `(Stat *)((u8 *)this + 0x5C)` or a 2-D `s32 (*)[5]` does not (CChrBodyWin 0x1870B8/0x1871D0). *(bokura)*
- A loop that starts from the original pointer (`for (p = Next(file, ...); cond; p = Next(p, ...))`) instead of copying `p = file;` first changes the register allocation (CChrBodyWin 0x1884F0). A call whose result looks used may really be discarded: check that the return register is read. *(bokura)*
- Two-value range checks that GCC folds into one `sltu` (`a < 0 || a >= 2`) come out as signed `slti`+`bgez` when written as a `switch` with `case 0: case 1: break; default:` (0x189348). *(bokura)*
- Load/save wrappers: `if ((buf = Load(path)) == 0 || !Parse(buf)) { if (buf) Free(buf); Error(); return 0; } Free(buf); return 1;` keeps the redundant `if (buf)` test after a failed parse; `buf = Load(path); if (!buf || !Parse(buf))` lets CSE drop it (CMapAttr 0x119BE0). Failure path first, success at the end. *(bokura)*
- VU0 float-to-int (`mfc1; qmtc2.ni; vftoi15.x; qmfc2.ni`, 41 functions in the game) is inline asm with the mfc1 inside it: `asm volatile("mfc1 %0, %1\n\tqmtc2.ni %0, $vf2\n\tvftoi15.x $vf2, $vf2\n\tqmfc2.ni %0, $vf2" : "=r"(r) : "f"(f));`. With an "r"(f) input GCC CSEs the mfc1 between two uses. Sin/cos table: `D_002A6800[(FtoI15(a) >> 1) & 0x3FFF]`, cos adds 0x1000 before the mask (CMapEffObjRes 0x1235E8, 0x126068, 0x121C18, 0x121810). *(bokura)*
- The volatile asm is a scheduling barrier: stores land on the same side of it as in the source, so the order of `d->x = ...sin...; d->y = ...;` matters. *(bokura)*
- VU0 sqrt is inline asm on a fixed $8: `asm volatile("mfc1 $8, %1\n\tqmtc2.ni $8, $vf2\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "f"(x) : "$8");` (gas accepts `vsqrt`; CMapEffLeafWork 0x11F660). *(bokura)*
- Loop-invariant float constants get f25, f24, ... in the order the source mentions them; a random offset written as `Range(-0.5f, 1.2f)` (lo first) instead of `t * 1.7f - 0.5f` puts -0.5 in the first register. *(bokura)*
- LCG draws store the seed, so later loads that may alias it stay after the store: where a field load sits between two seed stores in retail tells you where that statement was in the source (CMapEffLeafWork 0x11F390: `p.y` between the two draws). *(bokura)*
- VU0 micro-program calls (CCharaObj 0x117898) are one inline asm per step: `vcallms N`; load a vector `qmfc2.i $0,$vf0; lqc2 $vf4,0(p); vnop; vnop; vcallms N`; rotation from the sin table as ints `qmtc2.i cos,$vf4; qmtc2.ni sin,$vf5; vnop; vnop; vcallms N`; matrix load (4 lqc2) and store. The store asm moves the pointer into $2 itself (`move $2, %0` with a "$2" clobber), which is where retail's `daddu $2, $18, $0` comes from. *(bokura)*
- VU0 frac (`vftoi0; vmulaw; vaddw; vitof0; bgez; vmadda; vmsubw`) is one asm with a local label and no explicit nop (gas fills the bgez slot): `asm volatile("mfc1 $2, %1\n\tqmtc2.ni $2, $vf2\n\tvftoi0.x $vf3, $vf2\n\tvmulaw.x ACC, $vf2, $vf0w\n\tvaddw.x $vf2, $vf0, $vf0w\n\tvitof0.x $vf3, $vf3\n\tbgez $2, 1f\n\tvmadda.x ACC, $vf2, $vf2\n1:\n\tvmsubw.x $vf2, $vf3, $vf0w\n\tqmfc2.ni $8, $vf2\n\tmtc1 $8, %0" : "=f"(r) : "f"(x) : "$2", "$8");`. `sqrt.s` (disassembled as `c1 0x4`) is a plain `asm("sqrt.s %0, %1")`. VU dot3 likewise (CCharaObj 0x114828). *(bokura)*
- Passing `this` to a free `void f()` defined later in the same file: an `extern "C" void f__Fv(void *)` alias crashes cc1plus (Internal error #378) once the real definition follows; `((void (*)(CGameMain *))f)(this)` compiles to the same direct `jal` (CGameMain ctor 0x150A70). *(bokura)*
- Constructors with members whose ctors are unnamed in other lanes: declare the member as raw bytes (or a class without a ctor) and call `func_XXXXXXXX(&member)` first thing in the body; the order matches the implicit member construction when those members are the last ones (CGameMain 0x150A70, CMapAttr 0x118210). *(bokura)*
- Level 3 for a unit whose matched slot functions carry placeholder class names: keep the old bodies as `inline` methods of the placeholder class and define the real overrides as one-line calls to them; the inlined code is identical (CGameMain Func4/Draw). Member objects whose dtors live in other lanes' units become raw storage with explicit `func_XXXXXXXX(&m, 2)` calls at the end of the destructor body, before the implicit member and base destructors (0x150C30). *(bokura)*
- Tooling: `bk port` stops with `AssertionError: no address for __ti8CProcess` for a key method (the compiled snippet carries typeinfo symbols); port by hand (replace the INCLUDE_ASM, add the `_$_` name to symbol_addrs.txt), then `dataconv apply`, mk, delete the RTTI-name INCLUDE_RODATA, mk, rocheck. *(bokura)*
- Pointer-to-member arguments: a PMF literal (`&C::F`, and `0` for none) is an 8-byte .rodata constant GCC writes with the function (loaded with ldl/ldr because it is only 4-aligned); `extern const PMF D_X` reproduces the load but in the wrong argument order. Needs the unit at level 2+, the target methods named in the PMF's class (aliases.ld for ones matched under other class names), and the INCLUDE_RODATA lines of the literals before that function moved above it so the constants land after them (CPhotoDBMgr 0x170B18). *(bokura)*
- A PMF parameter of a callback that returns int gives `slt $3` after the `jalr`; with a void callback GCC uses $2 (0x170CD8). *(bokura)*
- A redundant two-step test that retail keeps (`beqz f -> A; beq f,1 -> B; A:`) comes from gotos: `if (f == 0) goto draw; if (f != 1) { draw: ... }`; a switch or `||` form gets folded to one compare (CCharaObj 0x117468). *(bokura)*
- `x = 0; if (c) x = f();` and `if (c) x = f(); else x = 0;` allocate differently: the if/else form puts the 0 in the branch delay slot and gives x an earlier s-register (CCharaObj 0x117198). *(bokura)*
- Angle deltas `WrapDelta(VuFrac(a) - VuFrac(b))` go through an inline helper taking both floats: retail loads both operands before the first asm, which only happens when they are arguments of an inline call (CCharaObj 0x114958). The wrap itself is `[-0.5,0.5) -> d, d > 0 -> d - 1, else d + 1`. *(bokura)*
- 16-byte struct copies with `lq`/`sq` need a 128-bit type: `*(u128 *)&dst = *(u128 *)src` (CVec4 here is only 4-aligned). *(bokura)*
- **GS packet code uses the sce macros**: `RGBAQ(c >> 24, c >> 16, c >> 8, c, 0)` with each argument
  masked inside the macro (`((u64)(r) & 0xFF) | ...`) reproduced retail's register use where hand
  shifts/masks did not; the A+D writes are `p = D; *p++ = tag; D = p; p[k] = v; D = p + k + 1;` with
  constant indices (0x247C00, 0x247D38). *(bokura)*
- **Repeated `div` traps mean repeated divisions in the source**: 0x247FA8 only came to 188 insns with
  `i0 % w` / `i1 / w` written at every use (9 divides), not cached in locals. *(bokura)*
- **Separate counters again**: reusing the inner-loop index for a later copy loop moved its register;
  a fresh `k` let the final call take it straight in `$6` (0x24E9C0). *(bokura)*
- **Struct copies of float vectors are field by field in retail** (`lwc1/swc1`), through a macro on
  `out[k]` so every store has a constant offset from one base; an inline function taking `&out[k]`
  let loop.c hoist `out + 16` and broke CSE of the sums. *(bokura)*
- **A store run's emission order**: GCC 2.96 emitted the last of a run of independent field stores
  right after the first; putting the store retail emits second at the end of the source run matched
  0x24FA88 at once. *(bokura)*
## d2
- **dklib units are level 1** (no own .rodata/vtable piece): any C++ that needs a jump table (switch with 4+
  dense cases) or a key method can't be matched yet; everything else works with the vtables in asm. *(bokura)*
- **Packet allocation in dklib is an inline with a count**: `inline u32 *PktAlloc(s32 n) { u32 *p = PKT; PKT = p + n;
  return p; }` gives retail's `li $5,4; addu` (the 4 kept in a register); r4's `PUT(v)` inline doesn't. *(bokura)*
- **Unaligned 64-bit struct arguments**: an 8-byte name passed by value in one register (`ldl/ldr` straight into
  `$a1`) matched as `((const struct { u64 v __attribute__((packed)); } *)D_x)->v`; a `char[8]` struct by value is
  copied through the stack. *(bokura)*
- **Parameters reused as locals show up in register choice**: when retail keeps a result in the register of a dead
  parameter (`a = vcall(a, ...)`, `b = func(a, name)`), write the assignment to the parameter; a fresh local gets
  another s-register (0x25AE80, 0x25AF70). *(bokura)*
- **A redundant null check kept by retail came from an inline**: `inline void FreeIf(void *p) { if (p) free(p); }`
  keeps the second test GCC drops when written inline in the function (0x25AE80). *(bokura)*
- **Callee "constructors" written as C functions still return a value**: `lui $3` (not `$2`) right after the call
  means the callee is non-void (GCC 2.x ctors return this); declare it `void *` and leave out the return in its
  own body (0x25E290, 0x25ED28). *(bokura)*
- **Sub-object init via an inline constructor**: stores through `this+0x68` as a base pointer (`addiu $2,$16,0x68;
  sw $4,4($2)`) came from `new (&u->m68) CSub;` with an inline ctor (placement new); plain field stores use the
  object register. *(bokura)*
- **Division by a constant that GCC didn't turn into a multiply** (`div.s` by 2048.0) came from a local
  `f32 n = 2048.0f;` (folding happens at tree level, the local is only propagated later). *(bokura)*
- **Accessors over an array of 0xD9B0-byte slots**: `if (i < 8) { CAt3 *a = &D[i]; if (a->m_active) return a; }`
  produced retail's `la $3, D($3)` ($at expansion) where `D[i].m_active` folded `D+8` first; error-printing
  accessors were one inline `GetAt3(i, fn)` with nested ifs. *(bokura)*

## head (tools, 2026-10-16)
- `bk test` alone gave false passes: it masks relocated fields and compiles the snippet without the
  rest of its unit. `bk utest` (whole unit, real flags, relocation targets compared) is now what
  `bk port` checks. Reverting one matched C++ function back to INCLUDE_ASM in Unit204500 broke a
  later function there through the GNU as `lui` bug: same-unit effects are real.
- Save every stuck function's best snippet in docs/hard/<lane>/hard_<ADDR>.snip; `bk hard` re-tests
  them all in seconds after any discovery.
- Once the small functions are gone, pick by readiness (tools/bk/rank.py), not size.
## w1 (overnight grind 2026-10-15/16: small functions across the game units and libraries)
- **EE `va_start` is the va-mips.h macro, not `__builtin_stdarg_start`**: retail passes `sp + (a1 save slot)` straight to vsprintf with no va_list object; `#define EE_VA_START(ap, last) (ap = (char *)__builtin_next_arg(last) - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))` with `char *ap` reproduces it (0x2432C8); `__builtin_stdarg_start` adds a stack slot for ap (frame +0x10) and `__builtin_next_arg` alone points past the GPR save area. *(bokura)*
- **Sized vs unsized extern arrays**: `extern s32 D_002B6810[2]` made each `D[a]` a `lui; addu; lw %lo` like retail, where `D[]` let GCC keep the computed address in a register (0x21BDD0). *(bokura)*
- **Operand order of an address sum**: `*(s32 *)((a << 3) + (s32)e->m_values + (b << 2))` gave retail's `addu a8, base`; every pointer-typed form canonicalised to `base + a8` (CResortDBMgr 0x172A60, an old HARD entry). *(bokura)*
- **VIF packet writers**: the register-setting callees (func_00237398, func_00237860, func_00237350) return values (`lui $3` right after the call), and the closing `PUT((D + k) | 0x14000000)` loads the base before bumping the packet pointer: a value-first macro or `u32 v = D + k; PUT(v | ...)` (20+ functions in Unit21BEC0/21D820/21F250). *(bokura)*
- **`!x ? 10 : 20` vs `x ? 20 : 10`** decides which constant is the default before the `movn`/`movz` (0x1932B8). *(bokura)*
- **Hidden pass-through arguments**: callers matched earlier with too few parameters (0x22E770, 0x22E828, 0x21B4A8, 0x21ACA8) got the extra parameter added so the callee can take its real arguments; the caller's code does not change. *(bokura)*
- **Store order of independent field resets** again: bk perm (hill climb) found 0x1B47E8, 0x1B6300, 0x1B7C10 quickly; when it stalls at DIFF 2 the remaining swap is usually two constants in registers (0x1121F0). *(bokura)*
- **GNU as lui bug moves with the code**: utest reported "the rest of Unit21F250 differs from 0x220FF0" and mk.sh/luibug.py then named func_00220FB8, which already had `asm(".p2align 3")`; after the code before it changed, *removing* that line fixed it (and 0x21BDD0 in Unit219970 needed a new one). Re-check every `.p2align` workaround when the code above it changes. *(bokura)*
