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

## Data: vtables and .rodata per unit (scripts/data_units.py)

### What EE-GCC 2.96 emits for a class with virtual functions

- **Vtable** `_vt$<mangled class>` (`_vt$12CMenuProcess`), weak, in its own section
  `.gnu.linkonce.d._vt$<class>`, emitted only by the unit that defines the class's **key method**:
  the first virtual function the class declares that is neither inline nor pure (usually the
  destructor). Defining any other virtual emits nothing. All linkonce sections link after every
  `.data`, which is why the vtables sit together at the end of .data (0x2BFA40 on) in unit order.
- **Layout**: entries of 8 bytes `{s16 delta, s16 index, pfn}`: entry 0 is `{0, 0, __tf<class>}`,
  then one per virtual function in declaration order (base first), then a null entry. `delta` is 0
  everywhere in this game (no multiple inheritance). The vptr points at the vtable start; a call is
  `lw vt, vptr_off(this); addiu vt, 8*(i+1); lh delta, 0(vt); lw pfn, 4(vt); jalr pfn; addu a0,
  this, delta`. The vptr sits after the fields of the class that introduces the virtuals (0x54 in
  CMenuProcess): a class whose vptr is at 0 introduces virtuals without fields of its own.
- **Typeinfo function** `__tf<class>` in `.gnu.linkonce.t.__tf<class>` (the linkonce code at the end
  of .text, 0x28xxxx-0x29xxxx), calling `__rtti_user`/`__rtti_si` with the name; the typeinfo object
  `__ti<class>` is `.comm` (bss); the **RTTI name** (`"12CMenuProcess"`) goes into the unit's .rodata,
  after all its other literals. Typeinfo names of base classes without a vtable of their own
  (`9IMapDBMgr`) follow there too.
- Pure virtual slots point at `__pure_virtual` (0x283858); a deleting destructor is
  `_$_<class>(this, int in_chrg)` and calls `__builtin_delete` when `in_chrg & 1`.

### The split (config/SCPS_150.88.yaml)

- `ctors`: .ctors .dtors .reginfo and the non-vtable .data (all units' statics and tables, still
  one asm piece).
- `vt_<unit>` (asm) or `{start, type: .data, name: <unit>, linker_section: .gnu.linkonce.d.*}`
  (from the object): one piece per unit, from its first vtable to the next unit's; `vt_tail` for the
  C-style code and libraries (CAppMain on; CSndWorkReal's own vtable is out there too); `eh_frame`.
- `ro_<unit>` (asm) or `[start, .rodata, <unit>]` (from the object): one piece per unit. Each ends
  with its RTTI names (also those of vtable-less base classes such as `9IMapDBMgr`, whose typeinfo
  the unit needed); the next starts at the 8-aligned address after them (the gap is zero; the
  linker pads to the next piece's alignment). `ro_tail` from the C-style code on, with
  .gcc_except_table.
- **Merged units**: the interface units (IPadMgr, IFadeMgr, ISnapMgr, ICharaResMgr, IMapResMgr,
  IEnvResMgr, ISysFlag with CSysFlag, IInterfMgr, IAlbumMgr), CList (with CTexCacheMgr),
  CMapEffObj (with CMapEffObjRes) and CStatusBase (with CCommandIncDec) have their vtables and RTTI
  names inside the previous unit's:
  they are one object with it (yaml comment `# also ...`). Converting them means merging the two
  .cpp files first.
- **Text boundaries can be early**: CFlagWork.cpp ends with functions (0x109508-0x10ADD0) whose
  literals come after `9CFlagWork`, so they belong to the CPadMgr unit. Harmless for .text (it is
  one stream), but a function's literals must be emitted by the unit that owns them.

`scripts/data_units.py disc/SCPS_150.88 build/full/asm` (full disassembly: see its docstring) prints
per unit its vtables, rodata range, .data refs and the count of INCLUDE_ASM'd functions that store
or call through a vtable (614 on 2026-10-14); `--yaml` the pieces, `--syms` config/vtables.txt.

### Three levels, per unit

1. **Nothing changed** (lane 2's units, the merged ones): C++ may not make the compiler write
   .rodata or vtables; literals only through `extern const char D_XXXXXXXX[]`.
2. **.rodata from the object** (`dataconv.py UNIT apply ro`): the unit's literals come from its
   .cpp: C++ can use string literals, float constants and switch jump tables. Its vtable stays asm,
   so its RTTI name comes in through INCLUDE_RODATA at the end of the file.
3. **.rodata and vtables from the object** (`dataconv.py UNIT apply`): also the key method (usually
   the destructor) can be C++.

Constructors, virtual calls and every virtual function but the key method can be written at any
level (next section).

### Constructors and virtual calls: no data change needed

config/vtables.txt (second splat symbol file) names every vtable `_vt$<class>` and its typeinfo
function `__tf<class>`. So in any unit, with the vtable still in asm:

1. Declare the class with its real virtual functions, in vtable order (`tools/bk/dataconv.py UNIT`
   lists the slots), and its base classes with theirs. Put the fields so that the vptr lands where
   the constructor stores it.
2. Write constructors (they store `_vt$<class>`), virtual calls, and any virtual function **except
   the key method** (keep that one INCLUDE_ASM; give it its mangled name in symbol_addrs.txt).
3. Classes of other units used only for calls: declare their virtuals, define nothing.

Checked: CMenuSysscr23's constructor matched this way with its vtable in asm (then reverted: lane
2's unit).

### Converting a unit (levels 2 and 3)

1. `python3 -I tools/bk/dataconv.py UNIT apply ro` (level 2) or `apply` (level 3; then also write
   the key method in C++). The yaml's `ro_UNIT`/`vt_UNIT` pieces become
   `[start, .rodata, UNIT]` / `{start, type: .data, name: UNIT, linker_section: .gnu.linkonce.d.*}`.
2. Level 3: name every vtable slot target that lives in this unit with its mangled name in
   symbol_addrs.txt (`_$_13CMenuSysscr24`, `Update__13CMenuSysscr24`): the compiled vtable refers
   to them by name. `__tf<class>` and `__pure_virtual` are already named; the compiled `__tf` copy
   is dropped by the linker script (`/DISCARD/`), so the vtable links to the retail one.
3. `tools/bk/mk.sh`, then `python3 -I tools/bk/dataconv.py UNIT fix`: adds an
   `INCLUDE_RODATA("asm/nonmatchings/UNIT", D_XXXXXXXX);` for every literal that neither splat (it
   moves a literal used by one INCLUDE_ASM'd function into that function's .s) nor the compiler
   provides, placed at its first user or by address order among the file's other literals, RTTI
   names at the end. Literals that matched C++ uses by name get `force_not_migration` in
   config/rodata_syms.txt. Then `tools/bk/mk.sh` again (re-split).
4. Until it matches: `python3 -I tools/bk/rocheck.py` compares each converted unit's .rodata and
   vtables with the retail bytes at its own piece (so one build names every bad unit even when an
   earlier one shifts the rest); `tools/bk/imgdiff.py` shows the first differing ranges.
   `dataconv.py UNIT` (no verb) shows each literal's status.

Many units can be converted in one go: `apply ro` each, one mk.sh, `fix` each, mk.sh, rocheck.

**Once a unit is converted**: matching a function makes the compiler write its literals in place,
so delete the INCLUDE_RODATA lines of the literals it uses (and its rodata_syms.txt entries);
`dataconv.py UNIT` lists what is left. When the key method is matched (level 2 to 3), `apply` the
vtable and delete the RTTI name's INCLUDE_RODATA. Non-vtable .data of a unit stays asm (`ctors`):
a .cpp must not define initialised data yet (it would land at the unit's .text position).

### Pitfalls found on the way

- **splat gives a literal to the first function that uses it.** For an INCLUDE_ASM'd function it
  goes into its .s (fine); for a matched C++ function it goes nowhere (no file), so C++ that uses
  `extern D_X` needs `force_not_migration` (config/rodata_syms.txt) plus INCLUDE_RODATA.
  Unaligned labels (`ldl/ldr` targets like D_002D965F) stay inside the previous symbol's file.
- **The first user in the source is not always the first function in .text**: an inline helper
  writes its literals where it is defined (CUserFlagMgr's `" \t"` and `","` come before several
  INCLUDE_ASM'd functions). Turning such an `extern` into a literal in the C++ function put it in
  the wrong place; keeping the extern plus INCLUDE_RODATA is exact.
- **splat's per-symbol files have no `.align`**; scripts/rodata_align.py (run by the split) adds the
  one the address implies, else a symbol after a compiler-written string lands too early.
- **Literals of the next unit in this file**: several .cpp files end with functions whose literals
  come after this unit's RTTI name (they belong to the next unit, whose text starts too late in the
  yaml). Their INCLUDE_RODATA lives in the next unit's .cpp; matching such a function in this file
  would put its literals in the wrong object: move it to the next unit's file first.
- **Jump tables** are `jtbl_XXXXXXXX` symbols in .rodata and are handled like `D_` ones.
- **Empty strings**: `""` is a real 8-byte literal (with padding) and GCC merges identical
  literals within a unit.

### Converted units (2026-10-14)

Level 3 (vtables and .rodata from the object, destructor C++), 21 units: CMenuProcess (pilot),
CMenuSysscr24, CMenuNews, CMenuExGetMoney, CMenuConfig, CMenuNosave, CMenuMemorial,
CMenuReviewResult, CMenuReviewStart, CMenuContinue, CMenuAsksave, CMenuSysscr26, 22, 11, 10, 09,
05, 04, 03, 00, and CSvmRes (no base class: its vptr follows its own fields at 0x20). Shared menu
base: include/CMenuProcess.h (virtuals `Update`, `Draw` after the destructor).

Level 2 (.rodata from the object), 46 units: CLogoMain, CTitleMain, CDemoMain, CEndingMain,
CFlagWork, CEFontWork, CFaceObj, CDiffMotionObj, CModelRes, CSwingBoneObj, CSwingBoneRes,
CCharaObj, CModelAccResMgr, CMapRes, CMapSndRes, CMapSndObj, CSndWorkReal, CSceneSet,
CEventRes, CEventObj, CEventMesRes, CMovieObj, CUserFlagMgr, CResNameMgr, CGameMain,
CGameSeasonPrev, CGameSeasonPost, CGameSchedule, CGameEventObj, CResortDBMgr, CMenuLoadMemorial,
CMenuTutorSelect, CMenuTutorSelected, CMenuExam, CChrBodyWin, CMenuRecord, CCommandSelect,
CStatusWin, CMenuInputKanji, CMenuSysscr32, CMenuBoot, CLayoutRes, CLayoutObj, CMiniGame2Res,
CMiniGame3Res, CMiniGame5Res.

Not converted: lane 2's 40 units, and the merged pairs (CPadMgr/IPadMgr, CFadeMgr/IFadeMgr,
CSnapMgr/ISnapMgr, CTexCacheMgr/CList, CMapEffObjRes/CMapEffObj, CCharaResObj/ICharaResMgr,
CMapResObj/IMapResMgr, CEnvResObj/IEnvResMgr, CSysFlag/ISysFlag, CInterfRes/IInterfMgr,
CPhotoEventObj/IAlbumMgr, CCommandIncDec/CStatusBase), which need their two .cpp files merged
first.

### Vtable-blocked functions (2026-10-14)

`scripts/data_units.py` counted 614 INCLUDE_ASM'd functions that store a vptr or call through one.
Matched here: 44. Of the 570 left, 103 are key methods (the first virtual a class declares, nearly
always the destructor): those need their unit at level 3. The other 467 (constructors, virtual
calls, other virtual functions) can be written in any unit now.
