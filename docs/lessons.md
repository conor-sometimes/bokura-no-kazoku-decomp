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

- **GNU as swaps a macro's last instruction into a call's delay slot; retail's assembler didn't**: when
  GCC leaves a `jal` in `.set reorder` mode right after a macro (`la $4,0xCEB0($16)`,
  `sw $2,0xFC60($16)`: offsets >= 0x8000), our as 2.10 moves the last instruction of the expansion
  into the slot, retail keeps the pair before the call and a `nop` in the slot. Blocks big-object
  code (CEventObj, CDemoMain ctor, the pointer-to-member handlers). `-Wa,-O0/1` doesn't help. *(bokura)*
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
