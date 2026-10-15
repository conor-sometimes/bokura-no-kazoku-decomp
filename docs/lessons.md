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
