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
## w2 (overnight grind 2026-10-16: libgcc, newlib, Sony SDK libs, linkonce)
- **libgcc and newlib (0x283858-0x292E20) are ee-gcc 2.96 C with strict aliasing**: `-x c` matched the first
  wrappers, but C++ with `return;` after a final void call gives the same sibcall, so they stay .cpp; what
  needed the Makefile group (LIBC_OBJS, no -fno-strict-aliasing) was __register_frame_info (mutex load
  hoisted above the list stores) and _init_signal_r (table pointer hoisted out of the clear loop). *(bokura)*
- **newlib math_private.h macros as written**: isnan/isinf/fabsf/copysignf only matched with the
  `do { ieee_double_shape_type ew_u; ew_u.value = d; ix0 = ew_u.parts.msw; ... } while (0)` macros
  (GET/SET_FLOAT_WORD likewise); a single union or block-scoped unions were 2-12 off. Same for
  newlib's CHECK_INIT(fp) in vfprintf wrappers: the `do {...} while (0)` form fixed the s-register order. *(bokura)*
- **newlib reent syscall wrappers**: `errno = 0; if ((ret = _read(fd, buf, n)) == -1 && errno != 0) ptr->_errno = errno;`
  with `long ret` (EE long is 64-bit) for _read_r/_write_r (retail `bne` + `daddu v0`), `int` for the
  others (`bnel`). *(bokura)*
- **libgcc fp-bit wrappers**: the FLO_union locals go after the fp_number_type locals in declaration
  order (retail frame: a/b/tmp at 0/0x20/0x40, the unions at 0x60/0x68). *(bokura)*
- **Raw addresses splat left unnamed** (`lui 0x42; sw 0x3F00`): defined as symbols in config/aliases.ld
  (D_423F00, D_424518) so C can reference them without a %hi(sym)+off fold into another symbol. *(bokura)*
- **Linkonce field-store order**: GCC 2.96 emits a run of 2-4 independent stores as last, first, second, ...;
  write the source so that order comes out (or `bk perm`). *(bokura)*
- **Callee `throw()` and delay slots (C++ units)**: a call to a function whose definition is not visible (and not declared `throw()`) keeps reorg from filling the following branch's delay slot with the shared `move a0,sN` (retail fills it; ours leaves a nop and duplicates the move). Retail saw the definition (template member such as TArray<T>::Count, compiled elsewhere). Fix: call through a local alias declared `throw()`: `extern "C" s32 W2Cnt(TArrB *) throw() asm("func_002943C8");` (Lib294A60 func_00294D70).
- A value-initialised temporary `T()` passed to a const-ref parameter zero-fills it (memset for a 16-byte struct, sw $0 for 4 bytes), evaluated after the other arguments' loads; use an alias of the callee with `const T &`.
- SDK C (Dk27C020 alarms): retail re-tests a popped free-list entry (`if (e) pop; if (!e) error` with unfilled slots) when the pop is a `static __inline__` helper returning e; written inline, jump threading merges the tests. A store that retail keeps out of a delay slot (the slot gets the return-value move instead) was a volatile store: `((volatile FreeEnt *)e)->p[0] = 0;`.
- Switch shape (EE-GCC 2.96): the case bodies are laid out in source order, so the retail block order gives the case order (Lib285F80 DW_OP decoder: a `case 0x90:` falling into `case 0x70 ... 0x8F:` had to come right before it). An `sltiu` range test means the switch operand is unsigned (`unsigned int op = *p++`); a `u8` operand promotes to int and gives `slti`.
- A pointer kept in a0 across `jal abort` (not moved to an s-register) means the callee was declared noreturn.
- A shared error block (printf + return -1) that retail places in the middle of the function, between an if's then-branch and its else, came from duplicated inline `{ printf(...); return -1; }` bodies in two wait loops that GCC cross-jumped; a single `goto timeout` label at the end places it last (Dk26CFB0 0x26F400).
- Float to int: retail uses `cvt.w.s` (splat shows `.word 0x46000064`), but our ee-gcc 2.96 compiles a C `(int)f` cast to `trunc.w.s`, so those functions cannot match without inline asm (`asm("cvt.w.s %1,%2\n\tmfc1 %0,%1" : "=r"(n), "=&f"(t) : "f"(v))`). About 10 unmatched functions across the tree contain it.
- **More 2.96 shapes (w2, second half)**: `return ret > -1 ? 0 : ret` folds to `slti/movz`; retail's `slt/movn` came from `{ int v = 0; if (ret < 0) v = ret; return v; }`. A bool temp that retail materialises with `daddu r,0; movn r,one,v0` is `ok = 0; if (f()) ok = 1;`. `(p + 11) - s` keeps the `s - 11` hoist that `p - s + 11` loses. Accumulating `w += a; w += b;` vs `w += a + b` changes the add order.
- **Varargs on EE** (coordinator): `char *ap = (char *)__builtin_next_arg(last) - (8 - __builtin_args_info(2)) * 8;` (va-mips.h form) matched sprintf/_sprintf_r/fiprintf.
- **fp-bit**: write the class as an enum with the inline `isnan/isinf/iszero` helpers from fp-bit.c; `a->normal_exp -= 1` vs `--` changes scheduling (dpdiv).
- **Callee return type**: declaring a void-looking SDK callee as returning a value (or void) flips v0/v1 choices around the call (sceGsResetGraph's GsPutIMR, the sio write loop's DECI2 poll); try both before permuting.

## head (upstream library sources, 2026-10-16)
- libgcc is GCC's own code: gcc-2.95.2's `config/fp-bit.c` and `libgcc2.c`, compiled unmodified
  with EE-GCC 2.96 `-x c -O2 -G0`, match retail byte for byte (`dptofp` = `__truncdfsf2`,
  `__fpcmp_parts_d`, `__muldi3`). libgcc2.c needs a stub tconfig.h (UNITS_PER_WORD 4,
  LONG_LONG_TYPE_SIZE 64, little-endian, `#include "gansidecl.h"`) plus gcc/include for ansidecl.h.
  Compile a reference file whole and compare every function against every INCLUDE_ASM'd one of the
  same size: matches fall out without knowing names.
- The string functions (strlen, strcmp, strcpy, memcpy, memset) are NOT newlib's portable C: they
  are Sony's R5900 versions scanning 16 bytes at a time with MMI (lq, psubb, pnor, pcpyld).
## x1 (overnight grind 2026-10-16: game units, 208-function list)
- **Same-mask DImode ANDs, solved**: write a shifted field as `((x & ((u64)m << k)) >> k)` (combine
  turns it into `dsrl; andi`, and the mask never exists as a constant CSE could share) and a low
  field as `(x << (64 - n)) >> (64 - n)` (becomes `andi`). When the same (shift, mask) pair occurs
  twice, give the copies different pre-shifts (`BITK(x, sh, m, k)` = `((x >> (sh - k)) & (m << k)) >> k`
  with a different k each) or combine folds them back into one register. Matched 0x223A90 and made
  0x21BF50/0x2384B8/0x23E088/0x242170 andi-exact. *(bokura)*
- **Strength-reduced givs get pseudos (and spill slots) in reverse order of appearance**: two loop
  pointers spilled to the stack came out in swapped slots until the key load was written before the
  table-entry pointer (`key = tbl[i]; t = &arr[i]; p = F(data, key);`), 0x14AAD0. Spilled user
  variables take slots in declaration order (declare `p`, `data`, `i` in retail's slot order). *(bokura)*
- **Converted units take string literals and jump tables in C**: in CGameDBMgr (level 3) a switch
  and `Func235DE0("...")` literals land exactly where the function's migrated .rodata was
  (0x14C048, 0x1490F8, 0x14AAD0). *(bokura)*
- **`(u64)` callee arguments**: a callee declared `(s32, s32, s32)` that really takes a u64 handle
  (`ld`/`beq` on the full register) must be redeclared; the caller that passes an s32 still matches
  (0x23BA10/0x23BD60). *(bokura)*
- **Shared temporary for an inline-asm read**: `cfc2.ni %0, $vi29` matched only with one function-scope
  `u32 st` used by every read (macro `VPUSTAT(st)`), not a value-returning inline (sceGsSyncPath
  0x239E00). *(bokura)*
- **This toolchain's assembler truncates decimal float literals**: `0.2f` assembles to 0x3E4CCCCC; retail's
  0x3E4CCCCD needs `0.20000001f` (0x14D7C8). *(bokura)*
- **`!(a < b)` vs `(a < b) == 0`**: the first gives `xori 1`, the second `sltiu 1` (0x14C048). *(bokura)*
- **`noreturn` on exit-like callees**: a `nop` before the label after `func_00289240(1)` was the
  barrier's `.align 3`; declaring the callee `__attribute__((noreturn))` reproduced it (0x234718). *(bokura)*
- **Void vs value-returning callees again**: `func_0021BC88` declared void fixed the register of the
  next address (0x21E4A0); calling `func_00279EF0` as returning s32 fixed a `lw v1` (0x234718). *(bokura)*
- **Return address**: retail's `daddu s6, ra` copy is `asm volatile("move %0, $31" : "=r"(ra))`
  after the prologue, not `__builtin_return_address(0)` (which reloads the saved slot). *(bokura)*
- **VLA-free alloca**: a `subu sp, sp, ((n*8+15)>>4)<<4` with a frame pointer and no restore per
  iteration is `__builtin_alloca(n * 8)` inside the loop (0x211598). *(bokura)*
- **GNU as lui bug, both ways**: a new function after `func_00239268` made its existing
  `asm(".p2align 3")` wrong (imgdiff showed `lui` vs `sw` at 0x239274); removing it fixed the build.
  utest's "rest of unit differs" with a `lw` where retail has `lui` is the same bug and can be a false
  alarm when mk.sh matches (0x235260). *(bokura)*
- **bk port compiles the snippet alone**: unit-local callees used by the snippet must be in its
  `//@decl` block (or port fails with "undeclared"); when port's standalone test disagrees with utest,
  splice the function in by hand (`build/bk/x1port.py`-style) and trust mk.sh. *(bokura)*
- **Menu state machines**: 22 of the list were state.h machines (lhu flags; srl 7; switch on negative
  codes); left in HARD.md as not attempted, none of that shape is matched yet. *(bokura)*
- **utest relocation addends**: utest ignored in-place REL addends of HI16/LO16 relocations
  (`D_338390+0x2210` vs retail `D_33A5A0` was flagged); fixed in 22e2648 (LO16 exact, HI16 within
  +-0x8000). *(bokura)*
- **Constructor store order "m0 before vptr"**: retail stores members before the vptr when the base
  class has an inline constructor and the members are real objects with constructors (CBoneDupMap,
  CPushBuf, CLayoutObj through an asm-label ctor); a hand-written vptr store always schedules first
  (CCharaObj 0x112FE0, CEventMesRes 0x13D910). *(bokura)*
- **Arrays of member objects are constructed unrolled**: declare separate members (`m_l0..m_l12`),
  not an array, when retail calls the constructor once per element (CMiniGame4 0x1D4D10). A member
  constructor called as returning `void *` changes later register choice (func_0025C230). *(bokura)*
- **Field order of plain store runs**: after `bk perm` the natural field order usually wins; float
  `0.0` stores through an FPU register need the `+ 0.0f` expression before the stores (snow/rain
  effect ctors 0x122440/0x1215B0). *(bokura)*
- **Loop-variable hoisting and variable reuse**: one pointer variable for several roles and
  `for (k = 0, tbl = s->mC; ...)` matched the glyph dump 0x1B7510; `(int)` cast of a void-declared
  printf-like call (PRINTI) fixed its register. *(bokura)*
- **Cross-jumping control**: putting the duplicated call into an `else` at the end (0x219110) or
  duplicating the tail per branch (0x1A4D28) chooses whether GCC merges the tails. *(bokura)*
- **`bk vtest` gives bogus 1000+ diffs here; separate snippets plus `bk utest` are reliable; `bk show`
  lacks unit context (a unit-context show helper was used instead).** *(bokura)*
## nm (near misses, 2026-10-16: the branch-likely group)
- **`bnezl` vs `bnez` next to calls is nothrow, not source shape**: EE-GCC 2.96 marks every function
  it has compiled as nothrow (TREE_NOTHROW, even under `-fno-exceptions`), and a call to a nothrow
  function gets a `REG_EH_REGION 0` note. Whether a call may throw changes the basic blocks reorg
  works with, and with them its liveness answers, so the annulled (likely) or plain form of a nearby
  branch flips, in either direction. Retail compiled the callees that sit earlier in the same .cpp, so
  its calls to them were nothrow; ours are INCLUDE_ASM (or in another unit) and may throw. Fix: declare
  the callee `throw()`. Seven of the eight DIFF-1/2 branch-likely near misses matched this way (0x1513D0,
  0x19AEC0, 0x1A40C8, 0x123D88, 0x234460, 0x234718; 0x1A4D28 the other way round). The 991111
  compiler and C (`-x c`, where every call is nothrow) differ, which is why the libgcc functions stuck on
  `bnez`/`bnezl` matched as C (lane w2). No compiler flag changes it (`-fexceptions`, `-g`, scheduling,
  `-O1`, gcse, `-fno-reorder-blocks` all tried). *(bokura)*
- **Func235DE0 (the debug printf) is nothrow in every game C++ unit (0x100000-0x1E91B8)**: retail's
  header must have declared it so (`throw()`); all those units now declare it `throw()`, the whole tree
  still matches, and 0x198430, 0x142318, 0x148110 (DIFF 61 before) matched with no other change. In
  the C-style units after CAppMain it is may-throw (Unit226AE8, Unit230578, Unit236130 and Dk2571C0
  break with `throw()`), so those keep the plain declaration. New game units should declare
  `Func235DE0(const char *fmt, ...) throw();`. *(bokura)*
- **Where to put the `throw()`**: for an `extern "C"` or free function, a redeclaration with `throw()`
  right after the callee's INCLUDE_ASM line copies retail exactly (2.96 accepts it; callers above it
  stay may-throw), e.g. `extern "C" int func_00150EA8(CGameMain *p, s32 i) throw();` in CGameMain.cpp.
  A member function cannot be redeclared outside its class, so put `throw()` on the in-class
  declaration (CStatusItem::Func1A1AA0/Func1A1B38, CMapEffAquariumWork::Func1236C8). Once a callee
  is matched in C, its own definition makes it nothrow; a member declared `throw()` then needs
  `throw()` on the definition too (the compiler says "throws different exceptions"). *(bokura)*
- **The reverse (retail `bnel`, ours `bne`) means retail did not see a definition we compile above**:
  CStatusWinSub1A4A40::Func1A4D28 only matched calling Select/GetMappedUnkC0 through may-throw asm
  aliases (`extern "C" int SelMT(CStatusItem *, s32) asm("Select__11CStatusItemi");`). So retail
  compiled it in a different .cpp from CStatusItem (a TU boundary somewhere between 0x1A40C8, which needs
  CStatusItem's callees nothrow, and 0x1A4D28). Likewise retail's Unit234318 saw func_00234108 (0x234108, our Unit232B78) as nothrow:
  the boundary at 0x234318 is probably too late. Nothrow-ness is a cheap probe of TU boundaries
  (CStatusItem's code was already suspected to start another object, HARD.md 0x1A3488). *(bokura)*
- **Diagnosing**: `tools/bk/ushow.py SNIP` (utest's in-unit compile side by side, `!!` on differing
  words; `BK_EXTRA="-flags"` for experiments, `BK_KEEP=1` keeps the spliced .cpp, `-dd` writes the
  reorg dump). A one-line `bnez`/`bnezl` diff whose fall-through or target path contains a `jal`:
  try the callee `throw()` first; `tools/bk/ntprobe.py SNIP ADDR` tries every free callee. *(bokura)*
- **Old DIFF-1 likely/plain entries unlock as their neighbours get matched**: once a callee earlier in
  the unit is matched in C, calls to it become nothrow and the delay-slot choice flips. The `#if 0`
  best attempts of g1 for CUserFlagMgr 0x13F948 and CCommandSelect 0x198E40 matched unchanged (after
  re-adding the declarations they had lost); CSndWorkReal 0x12A0F0 needed only `throw()` on the
  INCLUDE_ASM'd Func1295E8 above it. Retry likely/plain HARD entries after nearby ports. *(bokura)*
- **`(int)f` is fine in game units**: ee-gcc 2.96 (and 991111) emit `cvt.w.s`, encoded 0x46000024 |
  regs, the same word as retail's `.word 0x46000064`; decompals objdump just prints that encoding as
  `trunc.w.s`, and splat prints it as a `.word`. The w2 note that a C cast "compiles to trunc.w.s" and
  needs inline asm misread the disassembly: CSndWorkReal 0x12A0F0 matched with plain `(s32)(v * 128.0f)`
  casts. *(bokura)*
- **utest and splat strings**: a function .s that carries its own `.rodata` string (`.asciz` line with an
  offset/address comment) shifted utest's relocation check by one instruction (false "ours D_x, retail
  func_y" notes); utest now counts only lines with the full offset/address/word comment. *(bokura)*
- **C vs C++ front end for C sources (libgcc/newlib)**: compiling the C library units as C++ leaves some
  functions one instruction off after calls (`bnezl` where retail has `bnez`, dpdiv, lo0bits, pow5mult);
  as `-x c` they match. As C, a final call becomes a sibcall even to a noreturn function; where retail keeps
  `jal` (abort's exit, __register_frame_info's unlock), add `__asm__("");` after the call. C++-only
  builtins aside, cc1plus also lacks `__builtin_dwarf_cfa`/`__builtin_eh_return` (__throw, __rethrow).
- `n = n > 10 ? 0 : n;` keeps `sltu rC, n` with the constant hoisted into an s-register and a `movn`; `if (n > 10) n = 0;` becomes `sltiu n, 11` + `movz` (SDK 991111, libmpeg extension dispatch 0x26C8E8).
- A local array/struct initialised from a .rodata table (`W2Tbl t = D_002E98A0;`) gives retail's ldl/ldr copy to the stack.
- Implicit copy constructors: a run of `lw/sw` + per-array `n=3; do {...} while (--n != -1)` float
  copy loops (with gaps where 16-byte alignment pads) is g++'s implicit copy ctor. Declare the
  struct with `__attribute__((aligned(16)))` float arrays and write `new (p) T(*src)` (placement new
  declared `throw()` gives the `if (p)` test). A member whose copy ctor is an unnamed function can
  be bound with an asm label on the declaration: `W2ArrB(const W2ArrB &) asm("func_00294C80");`
  (0x294A98).
- A `CSndMgr` virtual's failure path placed first (`if (h < 0) { print; } else { ...; return }`)
  is the block order retail uses; the reversed `if (h >= 0)` form costs ~37 diffs (0x25AC38).
- Splat symbolized some `lui/addiu` constants as fake data symbols (`%hi(D_FFFFF)` for the
  0x100000 spin count in 0x264AA8): `bk utest` then reports DIFF 2 (relocation only) on a byte
  match. Port with a manual splice and trust mk.sh / `cmp -l build/SCPS_150.88 disc/SCPS_150.88`.
- Loop-invariant `lui` hoisting order follows the order the addresses first appear: a local
  `b = D_41AB40;` before `v = &D_41C080;` swapped two hoisted hi registers into retail order.
- `throw()` on an inline ctor's callee (CModelAccSub118168::Init) turned a `beqzl`+slot into
  `beqz` with the shared `slt` in the slot: EH regions around temporaries block delay-slot fills
  (0x294438).
- `if ((id = f()) >= 0) {...}` vs `id = f(); if (id >= 0)`: the separate assignment let gcse
  propagate `id = -1` into the cleanup path and delete `if (id >= 0) release(id)` entirely; the
  assignment-in-condition form keeps retail's check (0x25AAD0).
- Hardware register read-modify-writes between calls (0x26CA10, SDK unit): a non-volatile
  `*(u32 *)0x10002010` gets its address CSE'd into a saved register across calls; retail's
  per-statement `lui/lw lo` + `lui $1/sw lo` form is `*(volatile u32 *)0x10002010`, and its
  `lui/ori` + `lw 0(reg)` form is an inline helper with `volatile u32 *r = (volatile u32 *)0x10002010;`.
- **SDKC units (Dk26CFB0..Dk27DBB8, `-x c -O2` with ee-gcc 2.9-991111-01) build WITHOUT
  -fno-strict-aliasing**, so field types steer the scheduler: a load is only hoisted over a store
  of a different type. sceSifCallRpc (0x2760B0) matched only with the exact field types (packet
  m14/m1C `void *`, client m24 and packet m34 `int`); a 16-combination type search found it in
  seconds. Store-order near misses in these units are a type question before they are an order
  question (bk perm can't fix them).
- In SDKC units, reading $gp with `asm volatile("move %0, $28" : "=r"(gp))` keeps the following
  store in place; `register void *gp asm("$28")` lets it float.
- Upstream sources are kept with the decomp (refsrc: gcc-2.95.2 libgcc2.c, fp-bit.c,
  frame.c; newlib-1.9.0). __muldi3 (0x281B20) and dptofp (__truncdfsf2, 0x285498) matched straight
  from them; __muldi3 needed its unit (Dk280098) on the C front end, which kept every already-matched
  libm function identical.
- **Upstream newlib/fdlibm sweep** (a small script: compile each upstream file with ee-gcc
  2.96 `-x c -O2 -G0`, compare every function against the remaining list by word diff and by
  opcode-sequence similarity): found __sfvwrite, qsort, __ieee754_fmod, __ieee754_acosf,
  __kernel_rem_pio2f (exact) and malloc_extend_top (Sony builds mallocr.c with MALLOC_ALIGNMENT 16).
  Port by preprocessing the upstream file (`-E`) and renaming globals to asm-labelled externs of
  the retail data symbols; static const scalars become `#define`s and static tables become externs of
  the ROM tables so no new .rodata is emitted. A missing prototype for a later-defined callee
  (implicit int) was the only thing between kf_rem_pio2 and a match.
- **`.word 0x46000064 # cvt.w.s` in retail asm is not a blocker**: ee-gcc 2.96 emits that exact
  encoding for a plain `(int)f` cast; objdump with the R5900 arch prints our copy as `trunc.w.s`, which
  made it look different in side-by-side diffs. Several HARD entries (mine for 0x25FBC8, and the
  "~10 other functions" it cited) were wrongly blamed on it.
- The SDK C++ units (SDK_OBJS, ee-gcc 991111) are built without -fno-strict-aliasing too; the
  field-type search applies there as well. In 0x2765D0 (sifrpc request reply) only one combination
  of {server m1C, packet m1C/m20, dma src/dest} types matched; it took 9 compiles.
- Two saved registers swapped between variables assigned in both arms of an if: the order of the
  assignments inside one arm decides it (0x25C648: moving `type = e->m8` after a/b/c fixed the
  type/c swap; declaration order made no difference).
## sm (state.h state machines, 2026-10-16)
The Update functions built on `../dklib/include/state.h` (CStateMachine: u16 flags, u16 depth, s32
state, s32 stack[16]) all have the same skeleton; this one matches (CMenuSysscr23/09/05/08/04/11/07/03/
00/01/06/10/22/24/25, CMenuNosave, CMenuContinue, CMenuAsksave):
```
    s32 done = 0;                      // or `done = 0;` right before loop: (see below)
    if (m_state == 6) { ...; goto end; }
loop:
    if (done) goto out;
    { u32 fl = (u16)m_unk0; if ((fl >> 7) & 1) goto out; }
    switch (m_unk4) {                  // states are -__LINE__ of the macro; -1 is the start
    case -1: ...setup...
    <waits>
    }
out: ...
end:;
```
- **A wait comes in a few shapes, chosen by the retail block order** (the macro text is still unknown;
  these are equivalent spellings that give GCC the same RTL):
  - test, yield, then: `case L: if (!c) { m_unk4 = L; done = 1; goto loop; } then...`;
  - the same with retail's lone `nop` before the case label (the label is 8-aligned although code
    falls into it): wrap it in `do { case L: if (!c) { yield } } while (0);` (or
    `for (;;) { case L: if (!c) { yield } goto next; } next:`). The LOOP_BEG note makes final align
    the next label (LOOP_ALIGN 3 on the EE). Do not use `break` out of a `for (;;)`: a jump to the
    loop's end label within its first 30 insns makes expand_end_loop rotate the loop.
  - then-block before the test, test branches back to it (`beql c, then`), yield falls through:
    a rotated loop, `for (;;) { case L: if (!c) break; then...; goto fin; } m_unk4 = L; done = 1; goto loop;`.
    Rotation puts the test at the end; jump does not copy it back (duplicate_loop_exit_test) because the
    case label sits inside the exit test (a CODE_LABEL). Code falling into the loop also needs a jump
    (`goto x;` to a label `x:` next to the case label), or the loop's entry jump survives.
  - test, then, yield after it, END after that: `case L: if (c) { then; goto fin; } yield; fin: m_unk4 = END;
    case END: done = 1; goto loop;` (CMenuSysscr24 family).
- **Retail's shared yield tail** (`li done,1; b loop; sw $2,4(this)` with the state in the branch delay
  slot) is cross-jumping of the per-yield `m_unk4 = X; done = 1; goto loop;`; write every yield in full.
- **`done` in a callee-saved register** when its `= 0` is before a constructor call: put `done = 0;`
  after the local object's declaration (CMenuSysscr22's CEFontWork).
- **Virtual slots whose results are unused** put the vtable in `$2` and the function in `$3`: declare
  them `void` (CMenuInputKanji's Func1A4FE0/Func1A5048/Func1A50C8 in the name-input menus).
- **A local struct's field store through its address register** (`sw $0,0($20)`) needs an inline
  setter; a direct `font.m = 0` is sp-relative.
- **Inline `strcpy(d + strlen(d), s)` helper** for strcat: the copy of `d` lands in its own register.
- **Yields carry their case label after them**: `m_unk4 = L; done = 1; goto loop; case L:;` inside
  ordinary C loops (`while (c) { ...; yield; case L:; }`, `for (...; ...; inc) { ...; yield; case L:; }`,
  `do { yield; case L:; } while (c)`) gives retail's rotated layouts: the yield block before the test, the
  case label on the test or the increment (CMovieObj, CInterfMgr, CMenuMemorial, CMenuExGetMoney).
- **Cancel blocks that retail puts just before the next state's code** (reached by a backward branch):
  write them there, `goto`-reached, as `if (0) { cancel: ...; goto x; }` right after the yield that ends
  the previous state (CMenuExGetMoney's `Stop(0x4C); m4C = -1;` and `Play(3); m4C = -1;`). Code that
  shares a tail with such a block (two cancels ending in the same stores) is written in full in each
  place; cross-jumping merges them and CSE keeps the global's address in a register as retail.
- **Two END-like cases (`case -0x50A: case -0x4E2: done = 1; goto loop;`) share one block**: each extra
  `goto loop` makes another natural loop, and estimate_probability's first pass marks every dispatch
  jump that leaves one of them PROB_VERY_LIKELY, so ifcvt hoists `done = 1` (and GCSE insertions) into
  the dispatch. The END state falls into its own case (`m_unk4 = END; case END: done = 1; goto loop;`).
- **state.h's stack**: `Push(n)`/`Pop(n)`, `Var(k)`/`Get(k)` (k-th slot below the top); a value stored
  into a slot is evaluated before the check, so store through an inline `SetVar(sm, k, v)`; a return
  state kept across calls is an inline function's parameter (`SmCall(sm, -0x7A)`).
- **A loop exit that `break`s and then pops** (CMenuMemorial/CMenuNews `if (a & 0x60) { Play(3); break; }`
  before `Pop(4)`): write the pop in both places, `{ Play(3); sm->Pop(4); goto s4; } ... } sm->Pop(4); s4:`.
  cse2 then reuses the loop test's file pointer in each copy (one block each, no label in between) and
  jump2's cross-jumping merges the copies into retail's `b pop; lhu $5` with the check's `bnel` and the
  file pointer in a register (`daddu $6,$19`); one shared Pop reached by a label recomputes the
  pointer and the depth store moves after `m_state = 4`. *(bokura)*
- **loop.c moves exit blocks out of C loops** (find_and_verify_loops): inside a `do`/`while`/`for`, a
  block `if (c) { ...; goto L; }` whose jump leaves the loop and that sits between a conditional jump and
  that jump's label is moved to the nearest BARRIER before L that is at L's loop depth (else after L).
  That is where retail's "out of place" blocks come from: CMenuSub1A7658::Update1A73B0's cancel block
  (`Play(2); m58 = -1; goto sel;`) sits in the switch's compare tree because the -0xE5/-0x105 code is
  one `do { yield -0xE5; case -0xE5: ...; if (!(m4C & 0x10)) { cancel } yield -0x105; } while (0);`
  (barriers inside loops do not count, so it lands after the dispatch's `b out`). A yield
  `if (!c) { yield }` is such a block too (it jumps to `loop:`), unless it is the last statement of the
  loop body (its skip label then merges with the loop's exit label: mark_jump_label skips LOOP_END notes).
  A moved yield (a) is no longer marked PROB_VERY_LIKELY by estimate_probability's first pass and (b)
  gives reorg a `li state` to steal: retail's `bne c, tail; li state` with the continuation inline
  (CMenuSysscr26's -0x1EC wait: `do { case L: if (!c) yield; if (!d) yield2; } while (0);`).
- **Label alignment**: final aligns (`.p2align 3`) every label that follows a BARRIER and the first
  CODE_LABEL after a NOTE_INSN_LOOP_BEG, even past real insns, so where a `do {` starts decides which
  label gets a nop before it (start it at a case label that retail has 8-aligned).
- **A loop exit that `break`s and then pops** (CMenuMemorial/CMenuNews `if (a & 0x60) { Play(3); break; }`
  before `Pop(4)`): write the pop in both places, `{ Play(3); sm->Pop(4); goto s4; } ... } sm->Pop(4); s4:`.
  cse2 then reuses the loop test's file pointer in each copy and jump2's cross-jumping merges the copies
  into retail's `b pop; lhu $5` with the check's `bnel` and `daddu $6,$19`.
- **Counting waits** `m5C = 0; while (m5C++ < F(0x76)) { yield; case L:; }` (CMenuAsksavequit): the
  yield-only body disappears and the test branches straight to the shared yield tail. Several yields to
  one state can share one `yX: m_unk4 = X; done = 1; goto loop;` block reached by `goto yX;`
  (CMenuSysscr26): a yield right after a call in the same block is scheduled `sw` first and becomes its
  own cross-jump tail.
- **Cross-jumping keeps the last copy**: jump.c redirects each `goto loop` (in insn order) into the
  first matching jump on the label's jump chain, which runs from the last jump backwards, so retail's
  shared yield tail is the last yield in the function whose `li done / sw state` order matches.
- **reorg and branch probabilities**: the state.h checks get REG_BR_PROB 5000 (LTU has no heuristic,
  mostly_true_jump 1 = likely); estimate_probability's first pass gives 9001 to a jump from a natural
  loop's node into a non-node block inside the loop's index range (every `goto loop` is its own natural
  loop), which turns `if (!c) yield` tests into `beql`/`bnel` with the continuation's first insn.
- **Gosubs** (`Push(); SetVar(sm, 0, RET); ...; m_state = Get(); Pop(); goto loop;`): the return state
  goes through `SetVar` (evaluated after the Push, before the Var check, so it lives in an s-register).
  Two gosubs that share the call and the return: write the second's Push/SetVar in full and `goto call;`
  from the first; cross-jumping merges them from `m_depth++` on (CGameSeasonPost 0x1590B8). A sub that
  returns to several callers: `sub: ...; m_state = Get(); Pop(); goto loop;` inside the switch
  (CCommandSelect 0x1986A8).
- **A case that only sets the END state** (`case -1: m_state = -0x4E2;` in CInterfMgr 0x16BB20): store it
  and `goto e;` to a label on the END case (`case -0x50A: case -0x4E2: e: done = 1; goto loop;`), so
  cross-jumping lands it on the END block's `sw state` rather than the yields' tail.
- **States with gotos between them** (CStatusBase 0x19A9D8): each state in its own `do { ... } while (0)`
  so loop.c moves the blocks that leave it (`V4(); goto s2;`) to the barrier before the target; a
  `m_state = 2;` reached from two places goes behind one label outside the loops (`s2:`), otherwise CSE
  stores the compared register (`sw $3`) instead of `li 2`.
- **Key-method Updates** (CCommandSelect::Update is its class's first virtual): `#pragma interface` at
  the top of the unit (main's lesson), keep the typeinfo-name INCLUDE_RODATA after the function so the
  state.h literals keep their place.
- **More shapes from the menu Updates** (CMenuReviewSelect/ReviewStart/Exam, CMenuSysscr02):
  - gosub return cases go right after their `goto sub;` (`goto sub; case -0xE3: Play(0); goto y;`): the
    code after a return is then in source order, and cross-jumping keeps the later copy.
  - an END state that only ends the machine: `case -0x147: default: goto out;` (it becomes a case node,
    which changes the compare tree's root, and falls into the default range test).
  - the error return after each `Find`: write it per window (`if (!w) return Func235DE0(fmt, name);`)
    so the format string's literal lands between the two window names; one shared error block puts it
    after both.
  - `if (m20 == 2) { yield A } yield B;` vs `if (m20 != 2) { yield B } yield A;` decides which yield is
    the branch and which falls through; try both.
  - a wait written `while (c) { yield; case L:; }` right after a call: the -1/previous code jumps over the
    (deleted) yield body (retail's `b` with the test's first insn in the slot); the yield body can also
    be the kept copy of the shared yield tail (CMenuExam's -0xD6).
  - counting loops over a table: a separate loop variable per loop (`s32 j`) can fix the s-register
    choice; colour tables passed by pointer: `f32 *c0 = &col0.x;` keeps the address in an s-register;
    `*(f32 *)((u8 *)c0 + o)` with `o = i * 4` gives `addu base, off` (base first).
  - a call whose result is unused through a non-virtual view (`void Select(s32)`) avoids a `$2`
    conflict for the next `lui`.
  - utest does not check literal order: always run mk.sh.
- `tools/bk/kfam.py` (scratch, not committed) generated the kanji-select family; the decl blocks of those
  units now declare CMenuSub1A7658 with its ctor/Func1A7308/m_unk54/m_unk58. *(bokura)*
- **utest counted a function's own .rodata lines** (strings at the top of its .s) as instructions,
  shifting the relocation-symbol check by the number of strings; fixed in utest.target_refs. *(bokura)*
## cv (unit conversion, 2026-10-16)
- **The C-style/dklib .rodata splits cleanly by unit**: in ro_tail every literal's referencing text
  units were monotonic in link order, so one piece per unit fell out of a full-disassembly scan (63
  pieces, all to level 2 in one `apply ro` / `fix` / mk round). Literals only .data refers to go with the
  unit before them. The library part does not follow the size-cut Lib units: split it by object
  (strtod.c, vfiprintf, vfprintf.c, dtoa.c, locale.c+mprec.c, .gcc_except_table), and cut the text
  units to match (dtoa.c into Lib28F4F8, frame.c alone in Lib285F80). *(bokura)*
- **"Literals of the next unit in this file" is common**: a full-disassembly scan of which piece each
  function's %lo literals sit in found ~15 class files whose tail belongs to the next unit (helpers,
  factories, widgets). Move the tail into the next unit's file, or into a new unit when the literals
  sit between two units' RTTI-bounded ranges (CPersGauge, CMenuMgrSub1B4768, CStatusItem,
  CMenuCommonRes, Unit1E80A0). Give every INCLUDE_RODATA'd literal of the moved range
  force_not_migration first: once user and literal share a unit, splat migrates it into the asm
  function and the INCLUDE_RODATA file disappears. *(bokura)*
- **Key methods without level 3: `#pragma interface` at the top of the .cpp** (lanes g5/y1) keeps the
  unit from emitting any vtable, so a destructor (or whatever the first non-inline virtual is) is just
  C++. 20 key methods matched this way here. Shapes: base-interface dtors are inline (`virtual ~IFoo()
  {}`), so the base vptr store comes out inline; an interface that has *no* destructor shows as no base
  vptr store at all (IMenuMgr: ~CMenuMgr is a new slot 20); member objects whose dtors live elsewhere
  are raw storage with explicit `Dtor(p, 2)` calls (asm-labelled externs), last member first; a member
  made of a layout plus a sound object is one inline helper `{ snd(p + 0x170, 2); layout(p, 2); }`,
  which is what keeps `this + off` in an s-register (CMiniGame2/3/5). *(bokura)*
- **An inline ~CListTag in one unit needs `#pragma interface` in the header too**: with the inline
  body CListTag has no key method, so the unit emitted its RTTI name into .rodata; CList.h now gives
  the inline body (and the pragma) only under `CLISTTAG_INLINE_DTOR`. *(bokura)*
- **newlib 1.9.0 upstream matches the big libc functions with two Sony facts**: build with `-g` (cc1
  schedules differently: the dpcmp libcall delay slots stay empty) and Sony's float.h has
  `FLT_ROUNDS 0` (strtod's exact fast path compiles out). vfprintf.c also needs Sony's small edits
  (no `{0}`/NULL initialisers for _double/expsize/xdigs, `if (expt || ndig)`), and EE va_arg is a
  post-increment: `(*(T *)({ char *t = ap; ap = t + 8; t; }))` (gcc-2.95 va-mips.h's `(ap += 8) - 8`
  folds into a -8 offset). `%p` converts through `(unsigned long)va_arg(ap, void *)` (lw, sign-extended).
  _vfprintf_r, _vfiprintf_r (same source, INTEGER_ONLY, shared in include/nl_vfprintf.h), _dtoa_r and
  _strtod_r (3800 instructions) matched. *(bokura)*
- **objdump hides runs of zero words**: compare object code with `objdump -d -z`, or the R5900
  short-loop nops look like missing instructions. *(bokura)*
- **frame.c is EE-GCC 2.96's, not 2.95.2's**: execute_cfa_insn has DW_CFA_def_cfa_expression,
  GNU_negative_offset_extended and a `reg == cfa_reg` skip; and as C its calls are nothrow (bnezl),
  where retail has bnez, so the unit stays C++. *(bokura)*
- **A compiled jump table that lands 8 bytes early marks a missed object boundary**: jump tables are
  `.align 4`, so the object holding one starts 16-aligned. Dk252208's first switch landed at 0x..18
  instead of 0x..20: its image/BMP code is a separate object whose .rodata starts at the 16-aligned
  0x2E6B90 (new unit Dk253048, cut where the literal-less helpers before the first literal user
  begin). Inside one object, a table of strings that retail starts 16-aligned right after a jump
  table needs an explicit `asm(".section .rodata\n.balign 16\n.previous")`. *(bokura)*
- **A same-unit callee keeps `bnez`**: after the cut, 0x253358 turned into `bnezl` until its helpers
  (Func2531D0/2531E8) were back in the same unit; when splitting a unit, keep a function's helpers
  with it (nothrow-by-definition, see ## nm). *(bokura)*

## y1 (overnight grind 2026-10-16: Dk*/Lib* retry list)
- **`#pragma interface` must sit in the header that defines the class**: in the .cpp it only covers classes
  defined there (CEnvResObj etc.); for CProcess/CTask/CBgWork/CPushBuf/CMemTex (include/*.h) the key-method
  destructors only kept their vtables in asm once the pragma went into the header. *(bokura)*
- **Template vtables ignore `#pragma interface`**: constructing a `TList<T>` member (placement new) emitted
  `_vt$t5TList1Z...` and its `__tf` into the object; `extern template class TList<CResCacheUnit>;` suppresses
  the implicit instantiation (CResCache ctor 0x24FFE0). utest does not see the extra linkonce section; mk.sh does. *(bokura)*
- **CList drain loop**: `while (Remove(First(l)));` with `First = { n = l->next; return n->isHead ? 0 : n; }` and
  `Remove(t) { if (t) {unlink} return t; }` gives retail's `daddu r,0; movz r,n,head` + `beql` top test + the
  redundant `bnez t` at the bottom (nine CList/TList deleting dtors, CResCache/CSndWork/CTaskTag dtors).
  The list walkers use two First forms: `h->next->isHead ? 0 : h->next` (branchy first item, then movz/movn)
  and the local-variable form; which one a function used shows in whether the first item is branchy. *(bokura)*
- **"m0 stored before the vptr" in a constructor** came from a member object with a real (non-inline)
  constructor: declaring that member's ctor with an asm label (`Y1Prm() asm("Func25BD60__FP7CSndPrm")`) and
  writing a real C++ ctor reproduced it (CSndUnit 0x25C098); the same body with an explicit call did not. *(bokura)*
- **Argument setup order hints at the parameter order**: when retail loads a float argument register before an
  int one, the float parameter probably comes later in the signature (0x256DC8 is (ctx, ch, x, y, l): retail
  sets f13 before a2). *(bokura)*
- **nothrow crosses unit boundaries the wrong way**: a callee compiled earlier in the same retail .cpp is
  nothrow, so a `throw()` redeclaration that fixes a near miss also tells you where the callee's code really
  lives: `func_0025C2C0` (CSndWork dtor, at the end of Dk25A010) had to be `throw()` for 0x25D3E0 in Dk25C438,
  i.e. CSndWork's code belongs to Dk25C438's object (unit text starts late); 0x24A128 needed func_002496D0
  `throw()`. tools/bk/ntprobe.py finds these. *(bokura)*
- **libgcc2 from gcc-2.95.2 needs `__ll_B` as `((USItype) 1 << 16)`**: 2.95's `(1L << 16)` is 64-bit on the
  EE and turns `r * __ll_B` into dsll32/dsra32 pairs; with the 32-bit constant __udivdi3/__umoddi3/__divdi3/
  __moddi3 match (each with its own static __clz_tab, __negdi2 as a static inline), and the conversions match
  with `a -= (DFtype)v` on the parameter (dptoul/__floatdidf libcall names need aliases.ld lines). *(bokura)*
- **newlib mallocr.c `_malloc_trim_r`**: `_sbrk_r` must be prototyped with an `int` increment (ptrdiff_t);
  without a prototype `-extra` is passed as a 64-bit long (dnegu instead of negu of the truncated value). *(bokura)*
- **SDK C (991111, strict aliasing) field-type searches**: the sifrpc request handlers matched only with the
  input packet's pkt_addr/client as pointers and the output packet all-int (0x275B58/0x275E10), the
  _request_call queue with `end`/`client` as void* (0x276020), the alarm functions with flags read into an
  `unsigned int` (li 0xFFFFFFFE) and the current id read through a `volatile AlarmSys *`. A small script that
  expands `{{a|b}}` alternatives in a snippet and utests every combination (build/bk/y1/ts.py) found these in
  seconds. *(bokura)*
- **Constant in the wrong FPR before a call**: `w = h = x = y = 0.0f; f(x, y, &w, &h)` put the zero in f13
  and copied it to f12 like retail; `f(0.0f, 0.0f, ...)` loads f12 first (CFontWork 0x2566A0). *(bokura)*
- **Loop counters that count down in retail but were `for (i = 0; i < n; i++)`**: loop.c reverses an
  unused biv into a down-counter copied from n (0x256DC8's `daddu $19,$6`). *(bokura)*
- **SDK library objects and jump tables**: a compiled switch makes the object's .rodata 16-aligned; Dk26CFB0's
  .rodata piece starts 8-aligned (0x2E9928), so sceGsSetDefLoadImage (0x26F0D8) matches in utest but shifts the
  piece; the libgraph object starts at 0x2E9A00 in .rodata and needs its own unit. *(bokura)*
- **Library code: write the upstream source with its real types first**. In the strict-aliasing LIBC units the
  field types decide load/store order: newlib __sbprintf (two copies) matched with FILE's real function-pointer
  and short fields where an all-void* struct was stuck at DIFF 4; libgcc add_fdes/init_object with
  `uword`/`fde **`; __cp_push_exception with the real cp_eh_info (bool caught, long handlers); tinfo
  do_dyncast/do_upcast/do_find_public_subobj with 2.96 tinfo.cc's `convert_to_base` inline (the `if
  (!is_virtual) return addr + off; return *(void **)(addr + off)` shape) and `type_info::operator==` declared
  `bool ... throw()`. d2b matched as the upstream `if (d1) { y = d1; ...`. *(bokura)*
- **frame.c is C**: with the tinfo C++ split off (lane cv), Lib285F80 compiles with `-x c` (added to
  LIBC_C_OBJS, bk.py's LIBC_C_RANGES updated): the C++ front end hoists `&local` stack addresses out of call
  loops into s-registers, C does not (init_object, __frame_state_for, execute_cfa_insn all matched as C).
  Quick test for "which front end": compile the snippet standalone with `ee-gcc -x c` and compare
  (build/bk/y1/fcmp.py). *(bokura)*
- **2.96 does not rotate `while` loops here**: `while (c) body` compiled as jump-to-test; retail's duplicated
  entry test came from `if (c) do body while (c);` (get_reg_addr 0x2843A8). *(bokura)*
- **RTL inlining keeps wide loads**: `(void *)*(long *)f()` narrows to `lw`; going through an inline
  `long get_reg(...) { return *get_reg_addr(...); }` keeps retail's `ld` + sign-extend (next_stack_level). *(bokura)*
- **noreturn decides fallthrough code**: abort/__terminate called as noreturn give `jal; nop` and no a0 save
  (0x283D20, 0x288A00, 0x2838D8); declare a local asm-labelled alias with `__attribute__((noreturn))` rather
  than changing the shared declaration. *(bokura)*
- **A function-local static in a matched function needs the retail symbol**: fde_split's `static fde *marker`
  compiled as `marker.0` in our .bss; replacing it with `extern Y1Fde *D_424594` (the retail .bss slot) fixed
  the relocation (end_fde_sort 0x285728). *(bokura)*
- **Defining a function earlier in a C unit can change its callers**: porting new_eh_context turned
  __get_eh_context's caller `bne` into `bnel`; giving the definition its own C name with an asm label
  (`void *Y1NewEhContext(void) asm("func_002838D8")`) kept the caller as retail. *(bokura)*
- **utest vs mk.sh after a compiler-group change**: tools/bk/bk.py keeps its own LIBC_C_RANGES; until that is
  updated utest compiles the unit with the old front end (DIFF 85 in utest, OK in mk.sh). *(bokura)*
- **CEventObj command handlers** (`int CmdXXXX(CSvmWork *w, int id, int reset)`, one `m_sm[i]` each;
  Cmd13A100/13A508/13AA80/138610/13C120): the shape that matches is
  ```
  if (reset) SmInit(&m_sm[i], id);              // inline: m_depth = 0; m_flags = 0; m_state = st;
  if ((u32)(id - 0x80) < 0x80) {                 // script ids 0x80-0xFF go to the host callback
      int r = 0;
      if (m_FD30 && m_FD34) r = (m_FD30->*m_FD34)(w, id, reset);   // PMF takes (w, id, reset)
      return r;
  }
  done = 0;                                      // (inside or before the block, per function)
  { CStateMachine *sm = &m_sm[i];
  loop: if (done) goto r1; ...busy test...; switch (sm->m_state) { ... } }
  return 0;
  r1: return 1;
  ```
  The `int r` redirect is what keeps if-conversion (IF-CASE-2) from hoisting `done = 0` and the
  machine pointer above the range test (with `return call; return 0;` it hoists them, done loses $2
  and the pointer's s-register swaps with `this`); an empty `asm volatile("")` there also works but
  is not needed. The pointer is set up outside `loop:` (inside, its def counts as a loop ref and
  wins `$16` from `this`). Every exit is its own `return 0;` (`if (!buf[0]) return 0; f(); return 0;`,
  not `if (buf[0]) f(); return 0;`), or a shared return-0 block survives in front of the epilogue.
  Waits are `while (<int>) { yield; case L:; }`: an int-valued test (`EvREmpty(mgr)`, a virtual
  `int`) gives the rotated loop with the yield block before the test; a pointer test
  (`!RFirst(...)`) gets its exit test copied to the loop entry (duplicate_loop_exit_test). Two
  yields share retail's `li $3,1; b loop; sw $2,4(sm)` tail by cross-jumping. *(bokura)*
- **Branch-likely vs plain branch with a `$2` slot is decided by reorg's liveness of `$2` on the
  other path**, not by the source branch: an `s32` function that falls off its end still has
  `(use $2)` before the epilogue, so a `goto end` path counts `$2` as live and a slot insn that sets
  `$2` gets annulled (`bnel`). CMenuSysscr26::Update matches only with a `void` Update (the base
  CMenuProcess::Update is probably `void` in retail; not changed here, see HARD.md 0x1AA1B8). Use
  `ushow.py` (under `.bokura-env/bin/bokura-env -c`) for exact per-word diffs, and the `-da` dumps'
  `REG_BR_PRED` notes to see what reorg predicted. *(bokura)*
## sm2 (state.h machines, second pass, 2026-10-16)
- **CMenuProcess::Update returns void.** With `s32`, the epilogue's `(use $2)` keeps `$2` live on
  every path to the return, so reorg annuls slots that retail fills plainly (`bnel` for retail `bne`
  with `lui $2` from the target). The header pass (every menu screen's Update, `return Func235DE0(...)`
  error exits written as `{ Func235DE0(...); return; }`) left the build matching and matched
  CMenuSysscr26 0x1AA1B8 at once. A virtual's return type is not in g++ 2.x's mangled name, so a
  wrong `s32` on a virtual never shows up as a link error: suspect it when an Update's result is never
  used by its callers.
- **CMenuSysscr32::Update (0x1A7818) needed FreeBuf `throw()` as well**: FreeBuf is defined in
  CMenuInputKanji.cpp (retail compiled it in the same .cpp as Sysscr32's Update). sm's test of
  `throw()` alone (with `s32` Update) did not move it; both together match. Re-test the nothrow probe
  after any return-type fix.
- **`if (flag) return 0; log(...); return 0;` vs `if (!flag) log(...); return 0;`**: in the first
  form if-conversion (find_if_case_1/2) speculates the then-block's `$2 = 0` before the branch (the
  other path's call clobbers `$2`), and reorg puts that hoisted set in the slot (`bnez` + `daddu $2,0`).
  Retail's `bnel ..., ret; daddu $2,0` (annulled, from the shared return block) is the second form, where
  the return block has two predecessors and is not speculated (CEventObj 0x13A2C8, 0x13A790; the
  `m_FC50` log tail of the command handlers). *(bokura)*
- CEventObj 0x13AC58's `beqzl`/`beqz` on a wait was `func_00138908` (same unit, still asm) being
  may-throw: `ntprobe.py` found it in one run.
- **Counted waits** (`m4D8++; if (m4D8 > F(n)) exit; yield;` with the yield inline as the fall-through
  and the exit as a `bnel` with the reset in its slot, CCommandIncDec 0x1995F0/0x199BC0): write each as
  `do { case L: ...; m++; if (m <= F(n)) { yield } } while (0); m = 0;`. With `for (;;) { ... if (m > F(n))
  break; yield; }` loop.c moves the yield out of the loop and the test branches straight to the shared
  yield tail. Conversely, a wait whose test branches to the yield tail with the continuation falling
  through (`bne c, tail; li state`) is a do-while whose yield is *not* its last statement
  (`do { case L: if (c) { yield } m_state = 3; ... } while (0);`): moving one statement out of or into
  the do-while flips between the two. `ok`/`cancel` blocks that leave the do-whiles land together
  before the first loop (loop.c), as retail has them. *(bokura)*
- A virtual whose vtable lands in `$3` and function in `$2` returns a value (declare it `int`), the
  inverse of sm's `void` note. *(bokura)*
- `bk port` prints `ported 1 into ...`: check for it. When the snippet's standalone compile fails (a
  callee defined only in the unit, not declared in the snippet) port silently does nothing and mk.sh
  still says OK.
- **CMenuMgr's McSys machine (0x1B7EF8)**, the things that mattered: (1) `Func235DE0` called with its
  real `int` return (`McPrint` asm alias): a void call leaves `$2` free, so constants stored right
  after it move from `$3` to `$2` and the shared error tail stops cross-jumping; (2) waits as
  `while (f(1, &res)) { yield; case L:; }` (the kept yield copy sits before the last test, which is
  reached by a `b`); (3) the END states as `sm->m_state = X; case X: done = 1; goto loop;` with the
  inner `switch (request)`'s default jumping to a `case -0x208: e208: done = 1; goto loop;` placed right
  after that switch (elsewhere `done` lost `$4` or the range check became `beqzl`); (4) the inner switch
  written as `case n: goto rn;` with the request code after it, since a case label inside the inner
  switch belongs to it, not to the state switch. Its jump table comes from our object: drop the
  `jtbl` INCLUDE_RODATA and move the INCLUDE_RODATA lines after it below the function. *(bokura)*

- **Early `return 0` exits and cross-jumping** (CEventObj 0x13D6D8, 0x13C2D0): retail's
  `if (!x) return 0;` exits branch to the *first* `return 0` block in the function (a Log path, case
  0), ours to a later copy that jump2 kept. Writing those exits as `goto ret0;` with `ret0:` on the first
  `return 0` copies retail where that copy is not itself cross-jumped away (0x13D6D8: DIFF 71 to 35).
  jump2 runs after sched2 in this compiler (`-dR` is .25, `-dJ` .27), so cross-jumping sees scheduled
  insns. *(bokura)*
- **`while ((f & 0x60) ? (f &= ~0x60, 0) : --n >= 0) { yield; case L:; }`** gives retail's two copies
  of a countdown wait's test (jump copies a `while` exit test to the entry when it has no label in it)
  with one shared clear block (CEventObj 0x137DC8). *(bokura)*
- **Push(4) fade frames that read their floats back** (`s32 v = Get(k); f32 f = *(f32 *)&v;`, sound
  unit 0x25E590): retail reloads `m_depth` after each temp store, ours CSE/PREs it: the stack temp
  cannot alias the machine (an argument-based pointer) for our alias analysis. Not solved; it is the
  remaining wall of CLogoMain/CTitleMain/CEndingMain-style fades too. *(bokura)*
- `tools/bk` side helpers used in this lane (scratch, not committed): an aligned diff of `ushow.py`
  output that normalizes `li`/`move`/`%lo` spellings and drops branch targets made the near-miss
  hunting much faster than the raw `!!` lines; worth turning into a `ushow.py --align` mode.

### Finds
- **McSys debug overlay** (CMenuMgr): the memory-card request machine 0x1B7EF8 prints a progress
  line for every request ("Get Card Infomation" [sic], format, save, load, user-data checks) and
  CMenuMgr::DebugPrint1B85D8 (0x1B85D8) draws the card state (working flag, info type, free blocks) on
  screen; developer tracing left in retail.
- **A scripting language with a print command**: CSvmWork::Func131720 (0x131720) is the event
  script's expression evaluator, a stack machine over tagged int/float/string values with an operator
  table indexed by [opcode][type] (D_002A0A2C); event command 3 in 0x13C2D0 writes a script-supplied
  string to the event log, and command 1's frame wait goes through SkipTime (event fast-forward).
- **Inconsistent error text**: CMenuReviewResult::Update (0x190160) has "***Can't Get %s Window" for
  its first window and "*** Can't Get %s Window" for the second, two copies of the same message.
- **Self-deleting sounds**: the CSndUnitTg/Seq/Str updates (0x25E590 ...) fade out over m4E frames and
  then `delete this` from inside their own update.
## sm3 (state.h machines, third pass, 2026-10-16)
- **Which `return 0` copy an exit lands on: try `break;`** (to the switch's trailing `return 0`) as well
  as `return 0;` and `goto ret0;`. CEventObj 0x13C2D0's command-1 exit `Pop(); break;` jumps to case
  0's copy as retail; `goto ret0` (label in case 0) and `return 0` both landed on case 3's. The break
  goes through the switch's end label, which jump threads to the first copy rather than cross-jumping
  into the last one. A `{{a|b}}` variant tester over utest (build/bk/sm3/ts.py, scratch) found it in
  one run of 24 combinations. *(bokura)*
  CEventObj 0x13D6D8 (DIFF 35 in sm2) matched the same way: the two `if (!m4) goto ret0;` exits
  as `break;`, and case 0x60's `if (!m4) return 0;` as `if (m4) m4->Apply(a, b); return 0;` (that
  one gave retail's `beql` and stopped the dispatch's delay slot stealing case 0x60's first insn).

- **A constant reused from another register instead of the compared variable's**: CStatusWin 0x19F6C0
  `if (m_state == 3) goto c3; ... c3: if (m_unk64 != 3)` gave `bne m_unk64, <m_state reg>` where
  retail reuses the `li $4,3` of the first test (DIFF 3 through two lanes). cse's follow-jumps
  (cse_end_of_basic_block) follows a branch only if its label is preceded by a BARRIER, skipping
  notes *except NOTE_INSN_LOOP_END*; following it lets cse record `m_state == 3` and substitute the
  register; without it gcse does the job with the constant's pseudo. Putting the yield before `c3:`
  inside the `do { } while (0)` (its last statement) puts a LOOP_END note in front of the label and
  matched. Quick probe: `BK_EXTRA=-fno-cse-follow-jumps ushow.py` matching means "find the label that
  must not be followed". *(bokura)*
- **Register swaps between `done` and a hoisted global's hi part: count the yields**. CMenuCommon
  0x18B080 (DIFF 9 in two lanes, `done` and D_002A5468's `lui` swapped between `$20`/`$21`) matched once
  the -0xF5 and -0x13C waits shared one yield each (`if (a) goto y; if (b) { y: m_state = L; done = 1;
  goto loop; }`): every written-out `done = 1` is a reference that global alloc's priority
  (refs * log2(refs) / live length) counts, cross-jumped away or not. When `done` is in the wrong
  s-register, try merging or splitting identical yields before anything else. *(bokura)*
- **Porting a function removes its INCLUDE_RODATA lines**: the PMF constants and strings of
  CMenuCommon::Update (D_002DB558..D_002DB590) came out of our object as $LC0..$LC5, so the build
  shifted .rodata by 0x78 until those five INCLUDE_RODATA lines were deleted; utest does not show it. *(bokura)*
- **Two s-registers swapped between GCSE pseudos: it can be a global-alloc tie broken by gcse's hash
  table size.** global.c sorts allocnos by `floor_log2(refs) * refs / live_length` (integer division,
  so long-lived values often tie at 0) and breaks ties by pseudo number. PRE (pre_delete) creates its
  reaching registers while walking the expression hash table bucket by bucket, and the bucket is
  `hash % size` with size = (insns at gcse time) / 2, made odd; the hash of a `symbol_ref` is computed
  from the name's characters, so it is deterministic. Any source change that adds or removes a few
  insns before gcse (a duplicated yield, a jump) can reorder those pseudos. Read the bucket count and
  the PRE "reaching reg" lines from a `-dG` dump (`Expression hash table (177 buckets ...)`), and the
  priorities from `-dl` (`Register N used R times across L insns`) plus `-dg` (allocation order,
  dispositions). CTitleMain 0x1056A8: merging two identical yields took the table from 177 to 175
  buckets and fixed a 20-word swap (D_0029F398's hi now ahead of `this + 0x6A0`). Scratch tools:
  build/bk/sm3/tsg.py (variant tester that also prints the bucket count), regdump.sh. *(bokura)*
- **Moving a .rodata boundary by hand works when every literal in the moved range is INCLUDE_RODATA'd**:
  CEventObj's literals ran on to 0x2D5BB0 inside CEventMesRes's piece, which blocked 0x13D518 (its jump
  table sat there). The yaml boundary moved to 0x1D6BB0, the 38 INCLUDE_RODATA lines moved from
  CEventMesRes.cpp to CEventObj.cpp (path renamed), split around the jump table's function (the
  literals below the table before it, D_002D5B98 after it), every moved symbol given
  force_not_migration in config/rodata_syms.txt so splat keeps them as files; matched in one build
  (scratch build/bk/sm3/romove.py). The compiled jump table landed 16-aligned by itself. *(bokura)*
- **Two identical call tails that retail did not cross-jump**: find_cross_jump gives up on a pair of
  CALL_INSNs whose patterns or CALL_INSN_FUNCTION_USAGE differ, so the two calls had different
  signatures in retail. CSvmWork 0x131720's binary- and unary-op table calls stayed separate with one
  of them called through an `f32`-returning view of the table (an `int` view also separates them but
  puts the function pointer in `$2`): DIFF 214 to 15. Try the return type (void/int/f32) and the
  argument count of one copy before `asm volatile` tricks. *(bokura)*
- **Where loop.c puts a moved exit block decides the layout; aim it with the goto target**
  (loop.c find_and_verify_loops: a block `if (c) { ...; goto L; }` that leaves its loop goes to the
  nearest BARRIER *before L whose insn is in L's loop* (uid_loop_num equal; -1 = no loop), else after
  L). CMenuSysscr27::Update (0x1A8EE8, 578 insns) matched from a first draft at DIFF 538 once:
  every state sits in a loop (`do { case L: ... yield; } while (0)` with all its yields inside, the
  last one as the last statement, or `for (;;) { case L: if (!c) break; ...; yield; }` for retail's
  rotated "then-block before the test" states), so the only barriers outside loops are the few
  yields retail has at the top level; an exit that retail places *before* a later state's code
  jumps to a label after its own loop (`goto y124;` with `y124: yield -0x124;` after the next loop:
  the block lands after the previous top-level yield), and a block shared by several states
  (`advance:`) sits right after the preceding loop, without an `if (0)` (whose jump is a barrier
  outside any loop and attracts the moved blocks). Yield blocks moved this way vanish (cross-jumped
  and threaded into `bxx c, tail; li state`). Then: unused `int` results of non-virtual calls through
  a `void` view (Check2To3: fixed a `$2`/`$3` swap), the Pop(4)/SetMode1 order (next item), and
  Release1A8DC0 (a CMenuSysscr31 method retail compiled in the same .cpp) `throw()` for the entry
  test's `bne`. *(bokura)*
- **Loop notes are scheduling barriers: `do { } while (0);` instead of `asm volatile("")`**. haifa-sched
  (sched_analyze_insn) flushes its dependence lists at a NOTE_INSN_LOOP_BEG/END inside a block, so an
  empty `do { } while (0);` keeps later loads below earlier stores exactly like an empty asm, and
  it is plausible source (a state.h macro remnant). After `sm->Pop(4);` it gave retail's `addiu; sh;
  jal SetMode1; lw $4` in CMenuChildStatus 0x18A548 and CMenuSysscr27 0x1A8EE8 (where the asm had
  slipped in); wrapping the Pop itself (`do { sm->Pop(4); } while (0);`) does not work. The
  CMenuMemorial-style "needs asm volatile after Pop(4)" notes are probably this. *(bokura)*
- **`bk port` also runs the standalone test** (the snippet without the unit's other functions): a
  function whose callees are defined earlier in the unit (nothrow there, may-throw standalone) can be
  MATCH in utest and refused by port. Port by hand then (scratch build/bk/sm3/mport.py: decls before
  `// @decl-end`, body in place of the INCLUDE_ASM) and let mk.sh decide. *(bokura)*
- **The fade wall was loop notes**: retail's `m_depth` reload after each stack-temp store in the
  Push(4) fade frames (0x25E590) comes back with `do { } while (0);` after each `x = Get(k);` (cse's
  extended block ends at loop notes, haifa-sched treats them as barriers), and the exit Pop reuses the
  loop test's depth when it sits inside the loop (`if (!(...)) { Pop(4); break; }`). DIFF 195 to 7.
  The same barrier replaced asm volatile in two menu Updates; state.h probably wraps steps in
  do/while macros. *(bokura)*
### Finds
## lb (structural blockers, 2026-10-16)
- **A function-static (or file-static) const table comes after the object's RTTI names**: CMiniGame4Res's
  func_001D5550 table (0x2E15C8) and CMenuInputKanji's kana/romaji tables follow "13CMiniGame4Res" /
  "15CMenuInputKanji". unit_literals.py reports such a function as "uses the next unit's literals"; check
  what the literal is before moving code: a table used only by the previous unit's code means the next
  piece starts after it (rocheck then names the true boundary: CMiniGame5Res's own table starts at
  0x2E1630). An object's RTTI names also include its bases' (11CStatusBase ends CChrBodyWin's). *(bokura)*
- **Merging two .cpp files that saw one class differently**: keep each side's codegen with a view class
  whose methods are asm-labelled to the real symbols (`class CCommandBaseV { int RowOf(int) asm("RowOf__12CCommandBasei"); }`),
  an asm-labelled alias for a callee declared with another return type (`void CbPrint(...) asm("Func235DE0__FPCce")`),
  and real member classes with ctors/dtors where one side built the object (CAlbumMgr: ~CAlbumMgr's
  explicit `Dtor(p, 2)` calls become the implicit member destructors and still match). A tiny script
  (scratch dedupe.py) dropped duplicate class definitions whose members were a subset of the other's. *(bokura)*
- **splat only emits a global label for a function start inside another function when another unit
  calls it**: after CCommandSelect's tail moved into CCommandIncDec, func_001995F0 (inside func_00199500)
  lost its label and the C caller failed to link; naming it in symbol_addrs.txt splits it out. *(bokura)*
- **cc1plus 2.96 -O2 can ICE on a merged unit that compiles fine in two halves** (CStatusBase.cpp +
  CStatusWin.cpp: segfault in a function that only reads `m_item->m_unk34`; no -fno-* flag avoided it,
  -O1 did). Keep two units cut at the literal boundary instead. *(bokura)*
- **libgcc's exception.cc was built with -fexceptions** (its own unit Lib287920): the compiler then calls
  __eh_alloc, __throw, __rethrow(label in .gcc_except_table), __cp_push_exception, __start_cp_handler by
  name (aliases.ld), and the object's .gcc_except_table is the retail table byte for byte (yaml piece with
  `linker_section: .gcc_except_table`). Still 4 words off (HARD ## lb). *(bokura)*
- **A void sibcall that retail did not make**: `f(); asm(""); break;` keeps `jal` + shared epilogue where
  2.96 would turn the last call of a switch case into `j f` (CStatusItem 0x1A1AA0/0x1A1B38, as other lanes
  found for C; main had matched these two meanwhile). A ternary `return c ? a : f()` gave retail's `c.le.s`/`bc1t` where every if/else form gave
  `c.lt.s`/`bc1f` (0x297D20). *(bokura)*
## z1 (overnight grind 2026-10-16: game units, C-style units)
- VU vector loads (VU_VEC) in the CMapEffObjRes draws: the pointer goes through `register void *r asm("$2")` (0x124888, 0x126C48); 0x117668 (CCharaObj) still differs.
- Inlined ~CList / ~TList: `l->vptr = CList_vt; while (Remove(First(l))); l->vptr = CListTag_vt; unlink(l)` with `Remove(t) { if (t) {unlink} return t; }` (y1's helper) gives retail's top-tested drain loop with `bnez e`; CEventMesMgr::Remove(0) is `while (EvRemove(EvFirst(&m_head)));`.
- Inlined TList ctor: `vptr; isHead = 1; prev = l; next = l;` (prev before next in the source gives retail's next-then-prev stores).
- Destructors with the vtable still in asm need no #pragma interface when written as `extern "C" void func_X(T *p, s32 flags)` with the vptr store, asm-labelled member dtors (`asm("_$_8CSvmWork")`) and `if (flags & 1) return (void)::operator delete(p);` (or CTask::operator delete). Six matched first try (0x169128, 0x12C4F0, 0x19D0A8, 0x13F390, 0x1327F8, 0x1E95C0).
- Do not declare `extern "C" void __builtin_delete(void *)` in a unit: cc1plus segfaulted on a later function (CUserFlagMgr); use `::operator delete(p)`.
- Store-order rule again: a run of stores comes out [first, last, second, third...] or [last, first, second...] depending on context; for CEvWait's 5-field reset the source m8, m14, m18, m10, mC gave retail's two different orders.
- A jump table at a 16-byte boundary in the object moves the unit's .rodata start: CTexCacheMgr's piece starts at 0x1D3040, not 0x1D3038 (the 8 zero bytes are CEFontWork's padding).
- `__asm__("");` after a final debug print keeps retail's `jal` + epilogue instead of a sibcall (0x10D360's default case).
- lq/sq copies: an `unsigned int __attribute__((mode(TI)))` member assignment, sources non-const externs (const ones get hoisted out of the loop).
- Loop givs whose base is the list header (retail `daddu $4, list`): address the element as `(Item *)((u8 *)h + i * size)` with the header inside the item struct's first bytes (0x1EAE70, 0x1EAF10).
- Float literal 1/36: `0.027777777f` assembles to retail's 0x3CE38E38 (0.027777778f gives ...39).
- `*(s16 *)p &= ~1` gives retail's `and` with a -2 register (u16 gives andi 0xFFFE) (0x1EB0C0).
- Early return is a lever in the C-style units: retail's `daddu $3,$2` copy of a returned pointer (or of the argument, `daddu $5,$4`) with the result built in $2 comes from `if (!p) return K; return p->m;` / `if ((u32)i >= 2) return 0; return D[i].m0;` (0x212D40, 0x213238, 0x215270, 0x2155F8, 0x215628, 0x21BCC0); ternaries and result variables put p in $2 and the result in $3. `(u8)(x & 1) && (x & 2)` reproduces the `andi 1; andi 0xFF` test.
- CEventObj's queue writers/readers and CMiniGame6's ring: one ring-buffer class {alloc fn, free fn, buf, wr, rd, size, num} (CEventObj's CEvWait members are the same class). Writers: `if (m_size - m_num < n) {print; return 0;}` then a pre-tested `while (done < n)` copy with `c = m_size - pos; if (n - done < c) c = n - done;`, then `w = (m_wr + n) % m_size; m_num = m_num - n... ; m_wr = w;`. Readers cap the other way (`c = n - done; if (m_size - pos <= c) c = m_size - pos;`) and skip a null destination. Value pushes take the parameter's own address (`Push(&v, 4)`, the param gets a stack home); a float result through `f32 r; *(s32 *)&r = v;` with r declared first (stack slot order follows declaration order). (0x133140..0x134768)
- Success-path goto: `if (e->m0 & 1) goto ok; if (dbg() & 1) print(fmt, i); return 0; ok: return e->m4;` gives retail's `bnel cond, epilogue` with the result load in the slot; `if (cond) return e->m4;` puts the return in the fall-through (0x2087E8..0x209058).
- Level-2 units: a function's string literals are written out when the *next* function is compiled, so an INCLUDE_RODATA right after the function lands before them; put it after the following function (Unit20CBF0 "DI error\n", an unreferenced literal kept with rodata_syms force_not_migration).
- VU0 `vcallms` as `asm volatile("vcallms %0" : : "i"(0x30))` (immediate operand), not a literal string: the operand form lets the scheduler put the call-argument moves before it and changes the parameter register allocation (0x2042C0 matched only this way).
- **Copy of a parameter (`daddu $8, $4, $0` at entry)**: write a local alias, `Blk *t = l;`, use
  it for the accesses and pass the original to the call (0x23E720, 0x23E788; also gives the copy in
  0x23E620/0x23E690). Retail's copy shows the parameter and the alias were separate variables.
- **Loop entered at its test with no invariant hoisting** (`b test` with the load in the slot, the
  `lui` of a table recomputed inside the loop): build the loop from labels and gotos
  (`c = *s; goto test; loop: ...; c = *s; test: s++; if (c) goto loop;`); `for`/`while` get the
  exit test duplicated and the table base hoisted (0x23AC10, also the shape of 0x23E620).
- **u64 functions that `jal` a u64 callee and return its value**: `u64 r = 0; if (e) { if (bit)
  return other(); if (e->m18 < 0) return 0; r = f(e->m18); } return r;` gives retail's
  "preset $2 = 0, jal, fall into the epilogue" while the other call stays a sibcall (0x240D68,
  0x240DF0).
- `if (p == 0) return 0; memset(p, 0, n); return p;` and `if (p) memset(p, 0, n); return p;` give
  different register assignments for p; the first is retail's for the alloc+clear helpers (0x23F458).
- The simplest loop is worth a try before clever ones: 0x23BC28 (HARD: "n copied then decremented")
  matched as `for (i = 0; i < n - 1 && k != -1; i++) k = D_382E18[k];`.
- Float temporaries' registers follow declaration order: `bk perm` over the four `f32 a = x * y;`
  lines fixed 0x243AB8's $f20-$f24 assignment (MATCH from DIFF 10).
- `while (1) { ...; if (n <= 0 || i >= 2) break; }` instead of `do { } while (n > 0 && i < 2)`
  removes the rotated duplicate test (0x244EE8).
- In C units, an `extern "C"` callee that is INCLUDE_ASM'd *earlier in the same .cpp* was nothrow in
  retail too: `throw()` on its declaration fixed 0x23F8E0's bnez/bnezl (tools/bk/ntprobe.py must run
  inside bokura-env: `.bokura-env/bin/bokura-env -c "python3 -I tools/bk/ntprobe.py SNIP ADDR"`).
- A "rest of unit differs" line from `bk utest` (seen at 0x23AF30 after 0x23BC28) was a false alarm:
  mk.sh matched with the function ported by hand. `bk port` refuses on that line, so check with
  mk.sh before giving up.
- `bk perm` compiles the function alone with only the snippet's declarations: a snippet that relies
  on the unit's types or a `volatile` global from the unit scores 1000000 for every order. Put the
  needed declarations in the snippet (they must agree with the unit's, volatile included), or permute
  with whole-unit utests.

- **An inlined helper can change loop-invariant motion**: 0x22BC70/0x22BDF0 matched only with the
  heap `Unlink(h, n)` inline written out by hand (the inline version hoisted `&h->m14` out of the
  search loop and lost retail's `daddu $6,$4` heap copy); its two `n->m8 = 0; n->m4 = 0;` stores come
  out reversed as usual.
- **A copy of a returned pointer before `beqz`, then `jalr`**: the function returns the callback's
  value: `o = get(id); if (!o) return 0; return o->fn(a);` (0x22FED0, 0x22DB68, 0x22DBB8). A call
  through a pointer in tail position stays a `jalr`.
- **`jal` + return where GCC would sibcall**: `r = f(x); asm(""); return r;` (0x228EA0; also a
  `s64` return type works, the mode mismatch blocks the sibcall).
- **A stack buffer's address kept in a callee-saved register from the prologue** (`daddu $17,$29`):
  `asm("" : "=r"(b) : "0"(buf));` and use b; the frame size then tells the real buffer size
  (0x23C0F8 needed `u32 buf[516]` for retail's 0x830 frame).
- **Pointer walks with separate count-down counters**: `for (c = tbl, i = 63; i >= 0; i--, c++)`
  and an explicit `e++` next to an up-counting `i` reproduce loops where retail keeps both the
  counter and the pointer (0x22D9F0, 0x232840); give each loop its own counter variable.
- **GNU as lui bug, again both ways**: matching 0x228EA0 broke 0x228658 (a `lui` assembled as `sw`);
  removing the existing `asm(".p2align 3")` before 0x228618 fixed it.
- `bk port` refuses when the standalone `bk test` differs even if `bk utest` and mk.sh match
  (0x22BC70); port such a function by hand and trust mk.sh.

### Finds
- **On-screen debug console** (Unit236130): a 75-column by 26-row text buffer at 0x379BF4 written by
  the putc 0x236E48 (newline and column 75 wrap via 0x236DB0) and drawn with an 8x8 1bpp font by
  0x236BC8; 0x2365C8 is an exception handler that dumps the CPU registers to it. A crash screen the
  retail build still carries.
- **Debug text printer** 0x243AB8 / printf wrapper 0x243CF0 (Unit243AB8): lays out glyphs with the
  font's advance widths and handles newlines; developer overlay text.
- **"ready" print in the sound stream feeder** 0x244EE8: once the first buffers are queued it calls
  the debug printf with "ready\n" (a leftover trace).
- **Allocator diagnostics carry source line numbers**: the heap first-fit/last-fit searches
  0x22BC70/0x22BDF0 print a corruption warning with the constants 0x88D / 0x8A7 (lines 2189 and
  2215 of the allocator's source file) when a free block is larger than the heap's limit, with the block and heap counters;
  a flag makes it print only the first time.
## dl (Dk*/Lib* retry, 2026-10-16)
- **`bnel v0, ret; li v0, 1` after a call is a `return 1` reached by a jump**: the CExpr parser's
  `if (!f()) return 0; return 1;` turned into `sltu` (store-flag) in every spelling, but with the
  success paths written as `break` / `goto ok` to one final `return 1;` at the end of the function,
  reorg steals the end block's `li v0,1` into a likely delay slot and the `return 0` path reuses the
  call's zero in v0 (0x24D460, 0x24DC40). The copy that falls straight into the final `return 1`
  keeps the `beqz v0, ret; li v0,1` shape, which is why retail had two different-looking copies. *(bokura)*
- **Hoisted loop invariants come out in the order the loop first uses them**: a hoisted `li 3`
  landing between `lui`/`ori` pairs moved after them once the masked value got its own temp,
  assigned between the two statements that use the other constants (`addr = data & 0x0FFFFFFF;`
  between `n = ...` and `size -= n`, 0x2683F8). *(bokura)*
- **`while (*(s = f(s, buf)) && buf[0]) { if (!strcmp(buf, key)) return s; } return s;`** gave the
  jump-to-test layout with the call in the test; `break`, `for (;;)` and do-while spellings all came
  out as a top-tested loop with no entry jump (0x24AF10). *(bokura)*
- **CValue switches** (`switch (m_type)`): the case whose code doubles as the default is `case 1:
  default:` (or `case 2: default:`), cases written in retail's block order, and a final `sprintf`
  that must stay `jal` is called through a block-scoped pointer copy (`{ char *p = v->u.s;
  sprintf(p, ...); } break;`) (0x24BB58/0x24BC00/0x24BF80). *(bokura)*
- **PMF hooks**: `if (!e->m_obj || !e->m_get) return 0;` (one `||`) gave the `bnez index; nop; b ret`
  layout that two separate ifs did not (0x24D340/0x24D3D0). *(bokura)*

## rep (objdiff progress report, 2026-10-16)

- **A byte-matching build makes progress a function of the tree.** With the ELF's SHA-1 checked on
  every build, "written in C" is "matched", so the objdiff-format report for bytematch.dev comes from
  the yaml, `config/functions.txt` and the INCLUDE_ASM lines (tools/bk/progress_report.py) and CI
  never needs the game (after lombyte-project/Lombyte). It agrees with tools/bk/progress.py to the
  byte (828,500 of 1,700,400, 6,327 / 7,223 functions) and, function by function, with a real objdiff
  run on target/base objects (`make objdiff`).
- **The SKIP_ASM base build is not quite the real layout.** Dropping the INCLUDE_ASM'd functions
  (sly1-decomp's way to make objdiff count them unmatched) moves the C functions, and GNU as 2.10's
  lui bug depends on alignment: 3 matched functions (0x1863F0, 0x2810A8, 0x1EF700) show 93-99.9% in
  base. Keeping the asm in place without its labels fails instead: asm tail branches to other
  functions' labels (`b func_X`) need the label in the same section (BFD_RELOC_16_PCREL_S2 errors).
  `bk utest` stays the authoritative in-unit test.
- **`build/SCPS_150.88` is the rebuilt ELF (a file)**, so nothing can live under
  `build/SCPS_150.88/`: reports go to `build/progress/` and `build/objdiff/`.
- **objdiff counts linkonce code twice over**: the units' objects carry 88 weak `__tf*` typeinfo
  functions (`.gnu.linkonce.t`), counted per object by objdiff; the tree report counts each function
  once, at its linked address in `config/functions.txt`.
## gb (overnight grind 2026-10-16/17: old HARD entries in the game units)
- **A tested byte that retail loads twice** (`lbu; andi 1; andi 0xFF; bnez` then `lbu` again for the return):
  the return goes through an inline getter too (`inline u8 Flags(StrmEnt *e) { return e->m18; }`,
  `if (i < 32 && Used(e = &D[i])) goto found; return 0; found: return Flags(e);`). With `return e->m18;`
  CSE reuses the tested load; volatile reloads but loses the delay-slot fill (0x20B0B8, 0x20C238, 0x20F530). *(bokura)*
- **Clamp setters**: `s32 t = v < 1 ? 1 : (v < 3 ? v : 2); G = t;` (a temp for the store) gives retail's
  per-path `lui` and shared `sw` tail where storing the ternary directly duplicates the tail (0x22C2A8,
  0x2062B8; 0x184640 matched storing the ternary into a member). *(bokura)*
- **GS register values built at run time** (`and; sltu; dsll 14`, `li 1; movn 3; dsll 12`): a u64 copy of the
  parameter and if-assigned locals, `u64 f = flags; s32 af = 1; u64 d = 0; if (f & 0x10000000) af = 3; if (f &
  0x2000000) d = 1; put((u64)af << 12 | d << 14 | 0x38001);`. `?:` and `!= 0` fold into the constants or turn
  the bit test into a shift extract (0x1B9CE8). *(bokura)*
- **An empty `beqz` slot after a `la reg, D(reg)` macro in a C-style unit (no `as -g`)**: compute the
  compare into a local, then the unit's `NOSWAP()` (`.set noreorder/.set reorder`) before the `if`; gas then
  cannot pull the macro's last `addu` into the slot (0x245398). *(bokura)*
- **`bk port` names callees declared as C++ functions**: a stale `void Func226DF8(s32, u64);` in the unit got
  `Func226DF8__FiUl = 0x226df8` added to symbol_addrs.txt ("1 renames"), which broke every other unit's
  INCLUDE_ASM and callers of func_00226DF8. Watch port's rename count; call such callees by their
  `func_` name. *(bokura)*
- **utest's DIFF is positional**: once the instruction count differs, every later word counts, so a run of
  variants all scoring the same DIFF says nothing. An aligned score (difflib over the masked words,
  build/bk/gb/ascore.py) ranks near misses of different lengths. *(bokura)*
- **A key-method destructor without converting the unit**: ~CResCacheUnit (0x24FAF0) matched as the
  destructor of a view class (`class DlRUnit : public DlTagB { virtual ~DlRUnit() asm("func_0024FAF0"); ... }`)
  whose base is a copy of CListTag with the inline unlink destructor; the unit's `#pragma interface`
  keeps both vtables out of the object, and aliases.ld maps `_vt$7DlRUnit` / `_vt$6DlTagB` to the
  retail `_vt$13CResCacheUnit` / `_vt$8CListTag`. Member and base destructors (`_$_7CBgWork(p, 2)`,
  the unlink, `delete this` on in_chrg & 1) all come out of the compiler. `bk port` trips over the
  standalone compile's `__rtti_user` reference; splice it in with utest's splice instead. *(bokura)*
- **Unlink + push-back as one inline** (`DlMoveBack(&list, n) { unlink(n); push_back(&list, n); }`):
  the list head is evaluated before the unlink loads, and the unlink's `n->next = n` store survives
  because the push-back's `h->prev` load comes before its own `n->next = h` (0x250D28, 0x250DD8;
  0x250978 to DIFF 5). *(bokura)*
- **Store runs come out as a rotation of the source order**: two long-stuck store-order near misses
  matched once the source was retail's output order *rotated* (the scheduler emitted the later part
  of the run first): CDebOut's ctor (0x251BF0, output m28 m38 m10..m1C m4.. = source m4..m34 then
  m28 m38 m10..m1C) and memheap init (0x246100, DIFF 2 through three lanes' hill climbs: source
  starts at `usedNodes`, the output at `magic`). Hill-climbing perm over swaps never got there;
  generating every rotation and every two-block swap of the output order (122 candidates, one vt
  run) found it at once. Try this first for any field-init run. *(bokura)*
- **Lessons from the Dk lanes carry over to the game units**: dl's CValue switch shape (`case 0: default:` for the
  case that doubles as the default, cases in retail's block order, a final `sprintf`/`strcpy` kept as `jal` by
  calling it through a block-scoped pointer copy `{ char *p = m_u.s; sprintf(p, ...); } break;`) matched
  CSvmWork's SetInt/SetFloat/Set12E1D8 (0x12E0C8/0x12E130/0x12E1D8) at once; w1's integer-sum trick
  (`(T *)((s32)n * 16 + (s32)t)`) fixed 0x237680's `addu n, t` order. *(bokura)*
- **`addu base, off` in a clear loop**: `Res *e = &D_33F5D8[i]; e->flags = 0;` (a local element pointer) gives
  retail's base-first add where `D_33F5D8[i].flags = 0` and every cast form put the offset first (0x228208). *(bokura)*
- **Post-increment inside a call argument**: retail's `daddu $6,$18` (copy of i into the argument register)
  followed by `addiu $18,$18,1` before the `jal` is `f(a, b, i++)` (0x211E30). *(bokura)*
- **Store order after a null test**: `if (c) { m_unkC = c->m8; m_unk10 = (s32)c + 0x10; m_unk14 = c->mC; }`
  (vt over the 6 orders) matched CSvmRes::Load; a separate block-scoped `c` per lookup kept each result in
  `$2` as retail (0x12DEC0). Strings that dataconv lists as "in asm/.../func.s" become C literals. *(bokura)*
- **Where a `return 0` lands decides `beql v0,0,ret; daddu v0,0` vs a bare branch**: when the zero
  return is its own block, cse knows v0 is already 0 on the taken edge and drops the move (ours
  `beqz v0, epilogue`); when the test jumps to a `return 0` shared with a path that clobbered v0 (an
  error print), the block keeps `b ret; daddu v0,0` and reorg threads the branch through it as
  `beql ... daddu v0,0`. Fold the test into the outer `if (a && b) {...} return 0;` (0x249428). The
  same function's success print + `return 1` went last via `goto ok`. *(bokura)*
- **Spill slots follow pseudo creation order**: 0x247FA8's two spilled quotients (`i0 / w`, `i1 / w`,
  CSE temps) and a colour variable came out in swapped stack slots until the variable was declared
  after the first use of the quotients (C++ allows the late declaration); pseudos for locals are
  made when their declaration is expanded. *(bokura)*
- **`return f(...)` on a void callee** in a void C++ function is how retail gets the sibcall `j f`
  with the frame popped first (0x247FA8's single-row case). *(bokura)*
- **`lh` vs `lhu` before an `andi 1`**: storing `c->m14 & 1` into an s16 field let GCC narrow the load to
  `lhu`; retail's `lh` comes from the value read into an int local first (`s32 odd = c->m14; c->m4 = odd & 1;`,
  the same spelling the matched 0x23FB60 uses). A packet function that returns the advanced pointer keeps it in
  the parameter's register when the source assigns the parameter (`p = D_38EF54; ... return p;`) (0x23FCB8). *(bokura)*
- **A null test kept twice around a free** (`beqz buf` at the top and again before the `jalr` free): the free is an
  inline `FreeIf(p) { if (p) D_002B91B0(p); }` called after the `if (buf) {...}` block, not inside it (0x173578).
  A callee whose caller ignores the result can still return one: retail's `daddu $2,$18` at the end meant
  `s32 func_00173578`, and changing the caller's extern from void kept CMapDBMgr::Func173050 identical. *(bokura)*
- **`dsll32; dsra32` on a 32-bit argument** (sign-extending truncation) is a `long` (64-bit on the EE) value
  passed to an `s32` parameter: `long sz = n + 0x1F; func_0022AD68(b, sz & ~0xF);` (the add stays `addiu`,
  the and is DImode, the call truncates); `(long)n + 0x1F` gives `daddiu` (0x22AAF8). *(bokura)*
- **A difference computed straight into its register** (`lw $20, 8(b); subu $20, $20, n`) is a variable
  assigned twice (`rest = b->m8; rest -= n;`); `u32 rest = b->m8 - n;` gets its own temp and shifts every
  s-register (0x22AD68, also its twin 0x22AE58). A field stored twice through a pointer (`t->m0 = b->m0;
  b->m0->m0 = ...`) reloads b->m0 under -fno-strict-aliasing; retail's single load is a local `Nd *o = b->m0;`. *(bokura)*
- **utest's "rest of unit differs" is also how the GNU as lui bug shows up**, and the fix can move:
  after 0x24E560 went in, the old `asm(".p2align 3")` before 0x24F1F0 stopped working; one before
  the new function (the first code that changed) fixed it. A small script that tries the directive
  before each candidate function and runs mk.sh (build/bk/dl/p2try.sh) finds the spot in minutes;
  luibug.py did not recognise this instance. *(bokura)*
- **Two identical tail calls in the source, one jal in retail**: an early `if (same) { f(out, a);
  return; }` and a later `if (t < 0) f(out, a);` cross-jump into one call; the early copy keeps its
  arguments in the parameter registers, which is why retail's first path sets nothing before the
  shared `jal` (0x24E560). Writing it as one shared `goto` target instead copies `out` to a saved
  register. *(bokura)*
- **A result variable kept in a saved register through the error exits** (`daddu $20,$0,$0` in the prologue,
  `b end; daddu $2,$20` after each error print) is `s32 ok = 0; ... goto end; ... ok = 1; print; end: return ok;`;
  `return ok;` at each error site lets GCC fold the 0 (CChrBodyWin 0x187D68, DIFF 7 before). *(bokura)*
- **`&local` arguments inside loops** are expanded through force_operand into a pseudo, which gcse's PRE hoists
  out of the loop; retail recomputes `addiu $a2, $sp, 4` before each call in a few rxMc/rxsnd loops (HARD.md
  ## gb, stack-address family). `-fno-gcse` reproduces those loops but nothing at source level found yet. *(bokura)*
- **GIF tag words whose constants did not fold** (`ori $4,$4,0x45; ori $2,$4,0x10; dsll32 $4; dsll32 $2,$2,15`):
  the matched sibling 0x2271E8 had the shape: OR the parameter in place, build part of the u64 in a temp, then
  the rest in the PUTD argument: `a |= 0x45; t = (u64)b | ((u64)a << 32); PUTD(t | ((u64)(a | 0x10) << 47) |
  ((u64)0xC001 << 46));`. Every single-expression form folds `(a | 0x45) | 0x10` into `a | 0x55`. Five old
  HARD entries matched at once (0x222848, 0x2228E8, 0x220278, 0x220318, 0x2200C8): look for a matched sibling
  before fighting a fold. *(bokura)*
- **"Not tried" entries are cheap**: CDiffMotion/archive/heap functions marked "not tried" in older HARD lists
  (0x2288A0) matched on the first draft; check those before the heavily-tried near misses. *(bokura)*
- **LCG pairs: `u32 r = Next() << 16; r |= Next(); ... r & 0xFFFF`** with `Next()` returning
  `(seed >> 12) & 0xFFFF` keeps retail's `or` + `andi` (0x24D8D8); one expression folds the high half
  away. The same inline under a `fix >= 0 ? fix : Rand(...)` ternary matched the int range 0x297CA0
  (its float twin 0x297D20 had shown the shape). Look for an already matched sibling first. *(bokura)*
- **An asm reading `$gp` with a `"memory"` clobber** gives retail's reload of the table pointer before
  the gp store (sceSifAddCmdHandler-like 0x2752D0); without it the address is CSE'd. *(bokura)*
- **A store kept out of a delay slot and a second epilogue copy** came from a volatile store
  (`((volatile FreeEnt *)e)->p[0] = 0;`, 0x27D938), as w2 found for the alarm code. *(bokura)*
- **Load-before-store order with strict aliasing**: 0x27D3A0 matched once the u64 `e->start` was read
  into a local before storing `e->elapsed` (same type, so the compiler may not reorder them). *(bokura)*
- **Find siblings by opcode sequence**: comparing each unmatched function's opcode sequence (op/funct only,
  registers and immediates ignored) with every matched function's (difflib ratio, length within 30%) turned up
  exact twins of old HARD entries: 0x21E860 is 0x221128 with other globals, the six Unit21BEC0 GS writers
  (0x21C7C8..0x21CCB0) are 0x21CA68/0x21CAD8/0x21F088/0x21F108 with other constants (the matched siblings use
  `u32 v = D_33D6F0 + k; PUT(v | 0x14000000);`, which the old notes had not tried). Script: build/bk/gb/sib.py
  (scratch). *(bokura)*

### Finds (dl)
- **Duff's device in the XAP archive decoder** (0x249958, Dk2497C0): the LZ decompressor copies long
  matches with an 8-way unrolled `switch (n & 7)` falling into a `do { ... } while` loop, the
  classic Duff's device, in a game's resource loader.
- **The full-width digit writer stores its minus sign even with a NULL buffer** (0x24BA08): every digit
  store checks `if (buf)`, the SJIS minus `0x817C` for negative numbers does not.
- **A heap-usage overlay in dklib** (0x248298, 0x248760 family): debug code draws each memheap block as
  a coloured bar (allocated blocks one colour, the first/last free node highlighted), a leftover
  memory visualiser.

## Hard-tail lessons (lanes w1/w3, 2026-10-28)

Return types and liveness steer scheduling more than body shape at this stage.

- A discarded callee result still steers regalloc/scheduling. For a near-miss differing only in a temp register or delay slot around a call, flip the callee return type (void -> s32) before rewriting the body.
- `j callee` after the epilogue means the function (and that callee) return a value; `void` + `jal`/`jr` is the wrong signature.
- A duplicated `return 0;` inside a branch changes the epilogue and branch layout.
- Un-strength-reduced loop (index recomputed each iteration): write `goto test; body: ...; test: e = &T[j++]; if (e->k >= 0) goto body;`. `while ((e = &T[j++])->k >= 0)` gets reduced to a pointer step.
- Port out of INCLUDE_ASM with string literals in the C, not the extern `D_xxx` names: the strings vanish with the asm file and the link comes up exactly their size short.
- A vtable slot at retail offset +0x30 is virtual index 5: declare five dummy virtuals before it.
- After a `make` with a ported function removed from asm, the matching `.s` is deleted; run `make` again to regenerate it before `bk utest`.
- A `this` spilled to the stack in retail means one extra live variable (e.g. keep `out` alongside a separate walker `o`).
- A single index variable shared by two loops, one of which crosses calls, steals an s-register; give each loop its own variable.
- `if (x >= 0) { p = ...; do {} while }` makes the pointer inits land after the first test (sinks them, as retail does).
- `(hi = 15, hi < q)` gets `li; slt` instead of `slti` and keeps two compares, instead of folding to one unsigned compare.
- When a C method replaces INCLUDE_ASM, check where it lands: `.p2align 3` before it may be needed.
- **A dummy `case` changes the switch compare tree.** gcc 2.96 roots a 3-case switch (17,18,19) at the median (18); retail's `beq 17; slti <18 -> default; beq 18; beq 19` is the tree of a switch that has one more far-away case. Adding `case 0:` (falls into `default:`) gave the retail tree (CEventObj 0x138908). Put `default:` first in the source when retail lays the default body out before the cases.
- A `return 1;` merged after `if (buf[0] && n > 0) {...}` instead of two returns fixed a `lb $3` vs `lb $2` choice (the loaded byte reuses $2 when the constant return is set in the branch delay slot).
- To force a reload that gcse would remove (retail re-reads `rec->m0` in a later branch), read the field through a `volatile` cast: `((volatile T *)rec)->m0` (CGameMain 0x151120 went from DIFF 138 to 46).


## w1 (2026-10-28)
- **Tied same-register stores: later-in-source is emitted first**: two `swc1 $f0` of `1.0f`
  (CMovieObj::Init13E800 0x13E800, m_unk170 / m_unk16C) share one `mtc1 $f0` and have equal
  scheduler priority. GCC 2.96 Haifa tie-break schedules the HIGHER-LUID (later-in-source) one
  first, so the two stores come out in reverse source order. Retail emits 0x170 then 0x16C, so
  m_unk170 must be the LAST store in the source. No statement reorder of the other fields and no
  chained a = b = 1.0f flips it (both still CSE to $f0); only moving m_unk170 after m_unk16C in
  source matched (DIFF 2 -> 0, whole build byte-exact). Applies to any pair of equal-priority
  stores reading the same register. *(bokura)*
