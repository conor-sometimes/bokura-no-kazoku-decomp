# Hard / deferred functions

Functions skipped for now, with the reason. Pick them up when the blocker is solved.

## Vtables: unblocked (task #64, 2026-10-14)

Constructors, virtual calls and non-key virtual functions can now be written in any unit:
`config/vtables.txt` names all 216 vtables `_vt$<class>` and their `__tf<class>`. Only a class's
key method (first non-inline, non-pure virtual, nearly always the destructor) needs its unit's data
converted. Recipe, levels and the list of converted units: docs/units.md. 467 of the 570 remaining
vptr functions are writable now; 103 key methods wait for their unit's conversion.

## Not tried yet

- Functions that take the address of a `.rodata` 8-byte constant via `ldl/ldr` (0x108E10,
  0x108E38, 0x127E70, 0x127E98): look like pointer-to-member-function constants passed by
  value; needs the unit's .rodata.

## Tried, not matched

- **0x1385E8 / 0x13C0F8** (CEventObj unit): `if (enable) { slot->m4 = v; slot->m0 = 0;
  slot->m2 = 0; } return 0;` on the sub-struct at this+0xF924 / +0xF96C. Ours puts the
  `addu a0, at, a0` (slot address) into the `beqz` delay slot; retail computes it before the
  branch and leaves a `nop` in the slot. Tried: plain, `!enable` early return, inline
  `CEventObjSlot::Set`, a single s32 store for the two halves. Next idea: the slot pointer
  coming from an inline accessor or an array index (`m_slots[k]`).
- **0x184640** (CMenuTutorSelected unit): `m8 = clamp(v, 0, 1)`. Retail keeps two store
  tails (`bltz` to `v = 0; sw`, else `beql` with `v = 1`); ours if-converts to `movz`.
  Tried: nested ternary, early return, if/else with the store in each branch, temp variable.
- **0x12D4B8 / 0x12D818** (CCharaResMgr / CMapResMgr `FindRes`): `u = Find(id); return u ?
  &u->m10 : 0`. Retail: `xori a0, v1, 0; addiu v1, 0x10; movn v0, v1, a0` (4 insns), ours
  `addiu; movz; move` (3). Tried: ternary on `u != 0`, byte-pointer arithmetic, `if (u) u = ...`.

## Lane 2 leftovers (2026-10-14)

- **CSvmWork 0x12ECE0** (Jump): retail reloads `m_data->m_numLabels` for the Fatal arg; ours reuses it, branch layout differs.
- **CSvmWork 0x130CB0** (`SetFloat(fmod(a,b))`): retail leaves `nop` in the fmod/`__truncdfsf2` call delay slots; ours fills them with arg moves.
- **CSvmWork 0x130830 / 0x1308C8** (float or/and via `u32 r`, then `SetFloat(r)`): unsigned-to-float has `cvt.s.w` before `b` plus `nop` in retail; ours puts cvt in the delay slot (0x130830 also 2 insns short).
- **CSvmWork 0x130E78** (float rand, LCG 0x19660D at `work+4`): retail keeps `or` then `andi 0xFFFF`; ours drops the first draw (1702E0 same). 0x130718 matched in round 2 (seed as a sub-object with inline Next).
- **CSvmWork 0x131720**: 388 insns with a switch; not tried.
- **CMenuMgr 0x1B47E8 / 0x1B6300** (field resets): store order; no permutation matched.
- **CMenuMgr 0x1B4418** (Start): DIFF 2, `daddu s0,a0` before `bnez` with `sll` in its slot in retail; ours reversed.
- **CMenuMgr 0x1B7E70**: DIFF 1, retail `bnez` vs our `bnezl`; all 5040 store orders tried.
- **CMenuMgr 0x1B6158**: address computations for 9 out-pointers scheduled differently.
- **CMenuMgr 0x1B7C10** (`CUnk2A55B0::Init`): retail does 3 header stores before reading `D_002A55B0`; strcat through a buffer pointer.
- **CMenuMgr 0x1B4E70, CCommandBase 0x198430** (`return &arr[i]` after range check): DIFF 1, retail `beql` with `sll` in the likely slot.
- **CGameDBMgr 0x148400** (SJIS-aware trailing backslash find): branch shape, ours 3 insns longer.
- **CMenuCommon 0x18E700** (clamp 0..1, `m7C = 2 - v`): ~10 clamp forms; best `MinF(v, MaxF(0, MinF(v, 1)))` DIFF 11.
- **CCharaRes 0x112030, 0x1120A0, 0x112B60**: branch/loop shapes; 0x112B60 reloads `m_data->m_num` each iteration.

## Lane 3 leftovers (2026-10-14)

- **0x109108, 0x109248, 0x108700, 0x159790**: call Func108FF0 with (id, value) but `Func108FF0__9CFlagWorki` is declared with one arg (ISysFlag). Needs `(s32 id, s32 v)` there + symbol_addrs.
- **0x1091B0** CFlagWork::Func1091B0: block order/registers (bltz/beql layout); tried if/switch/early return.
- **CStatusWin bounds-checked get/set family (~18)**: 0x1A3A18, 0x1A3AF8, 0x1A3BC8, 0x1A3C98, 0x1A3D68, 0x1A3C28, 0x1A3CF8, 0x1A3DC8, 0x1A3FA8, 0x1A4008, 0x1A4060, 0x1A3E28, 0x1A3EA8, 0x1A3F20, 0x1A3A78, 0x1A38D0, 0x1A36B0, 0x1A3930: regalloc only, index in a3/t0 vs retail v1/a3 (with `CStatusEntry *e = &m_entries[i]`). One fix likely clears all. Try lane 2's lesson: pass the bad index to the debug print.
- **0x1A4E88**: 2 regs. **0x1829A0 / 0x1845F8**: 2 regs on the stored constant.
- **0x123D88**: inline LCG rand, retail `bnez` vs ours `bnezl` after the slot-busy check.
- **0x123670** Approach (float clamp): branch shape.
- **0x114C78**: needs `CCharaObjPart24::Func10DC80(s32, s32)`; that class is CFaceObj and the call has no args yet.
- **0x128E78** CSndWorkReal::SetChara: inline fade store order (perm of 5 found nothing).
- **0x129848 / 0x1698A0**: "if call then return sibcall else return 1" block layout.
- **0x12A2F0, 0x1B9CE8**: u64 arg to Func226DF8, constant scheduling.
- **0x16A998, 0x16B178**: arg move order and float select.
- **0x1820C8**: ours sibcalls Clear, retail `jal`.
- **0x169340, 0x1693B0**: `strcpy(x, "")` inline byte copy from .rodata: wait for the rodata split.
- **0x19DD48, 0x1A00B0**: field types at 0x5C/0x60 clash with CStatusWin's members.
- **0x196FF8**: retail stores float zero with swc1, else block out of line.

## Lane 1 leftovers (2026-10-14)

- **Loops/regalloc**: 0x1401B8 (inner loop keeps `this` and a zero in regs), 0x142B38 (loop rotation, -1 preset in prologue), 0x140358 (depth counter in a callee-saved reg; lbu/sign-extend switch), 0x13FF08 (`D_002D62A0` reloaded each iteration), 0x1792E0 (second loop's induction base), 0x1BC870 (SJIS copy loop), 0x1CA878, 0x13DFF8 (remove-all loop, DIFF 5), 0x19CCF8, 0x10D6C0 / 0x10D728 (source pointer register).
- **0x135BE0**: `sw` to `this+0xFBFC` before the `jal` with `nop` in the slot; ours fills the slot.
- **0x17B3E8 / 0x19B938**: float store order (DIFF 2 even with chained assignment).
- **0x145558**: `b*36` computed before the branch. **0x144070**: retail keeps `1<<bit` and an AND.
- **0x145160, 0x189348**: retail keeps two signed compares; ours folds the range check to unsigned.
- **0x1446D8**: branch order `v==0`/`v==1`. **0x1BBD78, 0x1BBDB0**: 2-case switch as an `slti` compare tree; ours if-converts.
- **0x1BD188, 0x1A72D8**: store order, best DIFF 3 / 2.
- **0x1B9E78, 0x19AEC0**: branch-likely vs branch. **0x18A410**: `$v1` vs `$v0` for one `lui`.
- **CMiniGame3Res 0x1CA378/418/3B8/4C8/458**: `this+(i*0x30+0xC50)` vs `(this+i*0x30)+0xC50`; inline anim setter DIFF 6.
- **0x1C4A58**: `this+idx*16` base then 0xE10/0xE14. **0x10CDD0, 0x10CE40**: clamp to ±128 via `slti 0x81`.

## Lane 2 round 2 leftovers (2026-10-14)

- **Redundant `if (data) free(data)` kept in retail, folded by ours**: CMapAttr 0x119BE0, 0x119B08; CMapDBExpr 0x173578; CGameDBMgr 0x148C50, 0x1473B0. A struct-wrapped pointer keeps the check but spills to the stack.
- **CMapDBExpr 0x172ED8**: matches in a snippet but not in the unit (`andi 0xff` only after `CallFunc24DB98`); left INCLUDE_ASM.
- **0..1 clamp, ~320 forms tried**: CMenuPTJobMoney 0x18F4D8, 0x18F448; CMenuCommon 0x18E670 (same as 0x18E700 above).
- **Register copy/numbering only**: 0x1A9BF8 (extra `daddu` of `m_60` before `/4`), 0x14FA08 (param copied first), 0x1D5140 (s6/s7 swapped), 0x110DC8, 0x1B7510 (s-register numbering).
- **Store/scheduling**: 0x1932B8 (DIFF 4, store before epilogue), 0x1121F0 (CCharaRes init), 0x148110 (loop alignment nop).
- **CMiniGame4Res 0x1D5420** (shuffle): retail splits read/write induction variables.
- **CMenuMgr 0x1B7188**: needs `Func108FF0` with (id, value); lane 1 fixed that signature on main, retry.
- **Jump tables in unsplit .rodata**: 0x10BAC8, 0x11B268, 0x10E8D0, 0x14F760, 0x14F550, 0x14F830 (the data split may unblock these).
- **VU0 macro ops**: 0x1AE3F8, 0x18E100, 0x1B6570.
- **0x198430 / 0x1B4E70**: still `beql`, DIFF 1, 6 more variants tried.

## Vtables round leftovers (goal 6a, 2026-10-14)

Exact notes for most are in the source next to the INCLUDE_ASM line.

Cross-cutting:
- **Key-method dtors of merged units** (a unit shares an object with another, so it can't go to
  level 3): CMapEffObj and its work dtors, IMapResMgr, IFadeMgr, CSnapMgr, CCharaResObj,
  CEnvResObj, 0x16D548, 0x143A90/0x144808, 0x10CF40, 0x168DF0. Blocked on task 48cfd5db.
- **Vtable pieces holding a second class's vtable**: CMapSndRes (TArray template vtable),
  CMiniGame1/4 (with _vt$CMiniGameNRes). CMiniGame2/3/5 also need CMiniGameNRes::Load first.
- **Inline template / CListTag code would emit linkonce vtables**: CSceneSet, CMapAttr, CMapDBExpr
  ctors and dtors, CSvmWork dtor, CCharaObj 0x112FE0/0x113090.
- **Layout unresolved**: CStatusWin (methods write this+0x58, which the dtor 0x19D0A8 treats as the
  vptr); CLayoutObj (vptr 0x164 with fields at 0x170+). Try tools/bk/structs.py first.
- **Branch-likely / delay slots**: 0x1863F0 (bnel vs bnez), 0x185868, 0x163DD0 (beqz vs beqzl),
  0x132F40/0x1355E0 (retail leaves the virtual path's `b` slot empty), 0x16D2D8 (both jal slots
  empty), 0x1061F0 CDemoMain ctor (member-ctor slots empty from the third member: that unit may
  have been built with exceptions, it has 0x7C bytes of .gcc_except_table).
- **Operand order of addu**: 0x14CAF0, 0x172A60, 0x199108, 0x108FF0 (DIFF 1-3).

Per lane:
- Lane 1: 0x10DD38 (branch layout), 0x10DFD0 (10-argument call), 0x1A01C8 and 0x146B58 (DIFF 15).
- Lane 2: 0x1AB0B8/0x1AE160 menu Update state machines (DIFF 53: retail cross-jumps the shared
  "flag = 1; state = next" tail); 0x13D910 CEventMesRes ctor and 0x12D1C8 (m0 stored before the
  vptr); 0x1D4D10 CMiniGame4 ctor (retail keeps a 2-iteration loop); 0x1866D0 (mul.s order);
  0x17A828 (epilogue ld order).
- Lane 3: 0x1447A8 CCurFlag ctor (lui scheduling), 0x15F0D8 (regalloc), 0x15E860 (branch vs
  movz), 0x15A090 (divide by 3), 0x15E2A8, 0x16D870/0x16D660 (this+4 / this+0xE0 kept in a
  register), 0x1B45E8 (cross-jump), 0x13E800 (DIFF 2 after perm), 0x13EC28 (matches but its jump
  table lands 8 bytes late in .rodata), 0x122440/0x1215B0 (bbox loop), 0x1AE528 (done loop
  threaded away), CChrBodyWin and CMenuSysscr27 (class decls need restructuring).
- Solved this round from older entries: the 0..1 clamps 0x18E700, 0x18E670, 0x18F4D8, 0x18F448.

## r2

Lane r2 (goal 6b, 2026-10-15): units Unit1FF680, Unit201DB0, Unit204500, Unit206508,
Unit208128, Unit20A410, Unit20CBF0 (render lights, file/string helpers, IOP sound RPC). 293 of
377 matched. Tried and left:

- 0x2062B8 (Unit204500, 13 insns, clamp-to-[0,1] setter returning the old value): best
  `s32 old = D_002A5DE8; D_002A5DE8 = v < 0 ? 0 : (v < 2 ? v : 1); return old;` DIFF 10: same
  branches and registers, but ours materialises `&D_002A5DE8` (lui+addiu) once, retail keeps
  `%lo(D_002A5DE8)($6)` in the lw and both sw. Array/struct-member forms of the global and
  if/else chains don't change it.
- 0x2073D0 (Unit206508, 72 insns, sound voice/channel table init): best (struct S30F580 with
  the node free list, inline PushFree/InsertNode helpers, the dummy channel through its own
  symbol D_3121A0) DIFF 36-42: the first loop wants retail's `daddu $5,$3; daddu $4,$5`
  copies, and constant loads (0x1BAFF0, 0x5010) schedule differently; bk perm over the 9 field
  stores found nothing.
- 0x2087E8, 0x2088B8, 0x208948 (Unit208128, 36-51 insns, seq-slot getters with two debug
  prints `D_002E2F90` (bad index) / `D_002E2FB8` (slot unused)): retail cross-jumps both
  `if (func_00206088() & 1) Func235DE0(fmt, i)` tails into one call site; ours keeps two
  (`if (e->m0 & 1) return e->m4;` form: 0x2088B8 38 vs 36 insns, 0x2087E8 DIFF 17).
- 0x2091F0, 0x209250 (Unit208128, 24 insns, chunk search `while (off < hdr->size)`): retail
  re-reads the bound `lw 8(base)` at the loop bottom; ours hoists it (while, for, do-while and
  goto loops all hoist). 1 insn short.
- 0x20B0B8, 0x20C238 (Unit20A410, 18 insns, "return the slot's flag byte if bit 0 is set"):
  retail tests `lbu; andi 1; andi 0xFF` (a u8-returning inline) and then re-loads the byte for
  the return; ours reuses the first load. Only `*(volatile u8 *)` gets the reload (DIFF 2).
- 0x20E798 (Unit20CBF0, 28 insns, bank sub-table lookup `t[k+1] ? (char *)t + t[k+1] : 0`):
  DIFF 8-9: retail ends with a branch (`bnez off` with `addu` in the delay slot, then
  `daddu $2,$0,$0`), ours if-converts to `xori`/`movz`; early-return, else and pointer forms tried.
- 0x2060F0 (Unit204500, 32 insns, switch 0/1/2 -> 3/4/5 then RPC 0x30): DIFF 16, all
  scheduling: retail stores `buf[1] = v` straight from $a1 before the call setup, ours copies v
  to $v1 and stores it in the jal delay slot (array, struct, store-order variants tried).
- 0x20E698 (Unit20CBF0, 47 insns, find a bank entry by name with strcmp): ours guards the
  loop twice (`bgtz` + `b`) where retail falls from `blez n` into a bottom-tested loop
  (do-while, for, nested-if forms all 1019+).
- 0x20E808 (Unit20CBF0, 43 insns, two-level bank lookup): DIFF 8, ours computes `n*4 + t`
  where retail does `t + n*4` and fills one delay slot differently; `(t + n)[2]` didn't help.
- 0x2061D8 (Unit204500, 56 insns, master pan: clamp both to [-128,127], store, push to the
  four sound modules): DIFF 8-10, only the registers of the two clamped values swap
  ($6/$3 in retail); statement order, fresh locals and a struct pointer tried.
- 0x20D118 (Unit20CBF0, 104 insns, voice pan: mono packet or two stereo packets by
  voice type 1..3): retail tests `t < 4` then `t > 0`; ours folds them to `(t-1) < 3`
  and lays the blocks out differently (110 insns; nested ifs, goto and switch tried).
- 0x208F98, 0x209058 (Unit208128): same two-debug-print shape as 0x2088B8 (cross-jumped
  print call), not tried separately.

Not tried yet (mostly large): 0x1FF680 0x1FF960 0x1FFC20 0x1FFF78 0x200130 0x2003A8 0x2005D0
0x2008A0 0x200B28 0x201820 0x201998 (Unit1FF680); 0x202040 0x202168 0x202430 0x202600 0x202A60
0x202C08 0x202D68 0x203108 0x2032F8 0x203500 0x203708 0x203A18 0x2042C0 0x2043B8 (Unit201DB0,
several with VU0 macro code / vcallms); 0x204500 0x204548 0x204BC8 0x204CC0 0x204E08 0x204FD8
0x205398 0x205898 0x205908 0x205980 0x205A80 0x205BA0 0x205DE0 (Unit204500; 0x205898/0x205908/
0x205DE0 return an 8-byte struct in $v0 built from an uninitialised register); 0x206808 0x206A18
0x207530 0x207960 0x207B80 0x207CD8 (Unit206508); 0x208260 0x208670 0x208B30 0x208E48 0x209CC0
0x209F50 0x20A098 (Unit208128); 0x20AA60 0x20AD90 0x20B160 0x20B448 0x20B5A0 0x20BA88 0x20BDF0
0x20C338 (Unit20A410); 0x20CC08 0x20CDF0 0x20D2B8 0x20D780 0x20DA30 0x20DB78 0x20DC98 0x20DFD8
(Unit20CBF0).
## g2
Goal 6b overnight lane g2 (2026-10-15). Each entry says what still differs; the best C for the near misses is in a comment next to the INCLUDE_ASM line.
- **CMiniGame5Res 0x1DEF58** (CMiniGame5 ctor, snippet in g2 notes): DIFF 2, `li $5,-1` scheduled before `addiu $2,this,0x30` (CStateMachine member init); tried CStateMachine/CMiniGameTimer orders, CRand ctor vs body.
- **CMiniGame5Res 0x1DF2F0** (quest picker): DIFF 2, the cumulative-weight pick loop: retail `beqz` + `addiu i` in the delay slot, ours `beqzl`; tried for/while/goto/continue/j-temp variants.
- **CMiniGame5Res 0x1DEA78 / 0x1DF0F8**: key methods (CMiniGame5Res dtor inlines ~CListTag; CMiniGame5 dtor); need level 3 and CListTag's linkonce vtable kept out of the piece.
- **CEFontWork 0x10C798** (InitEFont): DIFF 1, `bnezl` vs retail `bnez` + `lui` in the slot at the `if (!D_002BA248)` early return; tried return forms, int return, if/else.
- **CEFontWork 0x10C710**: switch whose jump table (jtbl_002D2B40) sits in the next unit's .rodata (text boundary); needs the function moved to its real unit.
- **CEventMesRes 0x13DBF8** (ParseItem, DIFF 34) and **0x13DA10** (Load, size +3): register numbering/scheduling; second loop's `it->m_ids[i] = ...` address computed after the call in retail, buffer pointer copied to a fresh register; Load's alnum test layout.
- **CEventMesRes 0x13DE70 / 0x13DEB0 / 0x13D958**: CEventMesMgr ctor/dtor and CEventMesRes dtor inline TList/CList/CListTag ctors/dtors; inlining them would emit linkonce vtables (_vt$5CList, _vt$8CListTag) into this unit's piece.
- **CFaceRes 0x10E5E0** (ParseFaceParts, DIFF 15): retail interleaves the eight `lhu`/`sh` pairs (load, store, load, store), ours hoists all loads; tried array/struct locals, s16 pointer, inline setter.
- **CFaceRes 0x10E7A8** (LoadFaceSets, DIFF 3): `move s1,s3` (s = sets) placed before the hoisted `lui`s in retail; tried for-init, declaration orders.
- **CGameSchedule 0x159F80**: DIFF 1, `bnel` vs retail `bne` + `ld $16` in the slot at `if (m88 == 1)`.
- **CGameSchedule 0x159E18** (Next, size -9): first ScheduleUnit() is branchy (`bnez`/`b` + `move a1`) in retail, movz in ours; layout of the remove block; tried goto/for/while forms.
- **CGameSchedule 0x15F1B0** (size -2): register numbering (n in $20 vs ours $21) and a loop-alignment nop; returns 0 or Func15F9E0's value.
- **CGameSchedule 0x15F780** (DIFF ~72): register allocation of the nested slot-merge loops (k/n/b/p/j in s3/s4/s5/s6/s2 in retail); tried pointer and index forms of the D_002A3480 walk.
- **CGameSchedule 0x15D620** (DIFF 15 after perm of the field stores): ours computes `&D_002A26E4` (lui/addiu s3) before the `if (!rec)` branch, retail inside the found path; also s1/s3 save order. Tried if/else and single-exit forms.
- **CEventObj 0x132D30** (size -3): retail leaves the delay slot empty after calls whose argument is `this + large offset` (`ori/addu` pair before `jal`, then `nop`), ours puts the `addu` in the slot (same as the CDemoMain ctor note).
- **CEventObj 0x135138** (DIFF 12): s4/s5 swapped between `&m_svm[3]` and `&m_svm[5]`; tried pointer locals in all orders and partial locals.
- **CEventObj 0x132BB8** (DIFF 5): only the list-count loop's registers (retail mgr in a0, count in a1; ours v1/a0); tried inline counters, goto loop, mgr local.
- **Cross-cutting, GAS delay-slot swap (blocks CEventObj 0x135A28, 0x132D30 and probably the pmf handlers 0x132F40-family and the CDemoMain ctor)**: when GCC leaves a call in `.set reorder` mode after a macro instruction (`la $4,0xCEB0($16)`, `sw $2,0xFC60($16)`: offsets >= 0x8000), our GNU as 2.10 swaps the macro's last instruction into the `jal` delay slot; retail has the pair before the `jal` and a `nop` in the slot. `-Wa,-O0/-O1` does not change it. Needs an assembler-side fix (e.g. a post-pass or a patched as).
- **CFlagWork 0x108C30** (text loader, DIFF ~73): block layout of the matched-range branch (retail puts the per-value loop body before the found-block init and jumps to the test) and `text` first held in s0; tried break/flag and goto forms. **0x108700**: s0/s1 swapped (this vs the cached range); tried scope/inline-range variants.
- **CFlagWork 0x108448** (setup, size -2): close; remaining: d->m_size stored through a copy of d (`move a1,s0`) and reloaded for `size +=`, prologue scheduling of `defs = 0` / `Reset()`. Snippet in g2 notes (goto notfound form).
- **CMenuMgr 0x1B76D0** (DIFF 1): `bltzl` vs retail `bltz` after the save-data write of `m174` (delay slot `lui v0` from the exit block); tried void/int print, nested-if and goto forms. **0x1B4ED0 / 0x1B5E18**: GS register packets built from a 64-bit bitfield struct in a0 (needs the struct layout).
- **CMapRes 0x11A7C0** (DIFF 29): p/s register swap (s0/s1) and the `s = sets` copy placement; **0x119E08** (sorted insert into two item lists, size -10): loop shapes (first comparison against the cached key, later ones reload it->m40).
- **CMapDBExpr 0x173648** (DIFF 6): `s = line` lands in the first `bnez` delay slot in retail (ours first in the body, with the `this` reload in the slot).
- **CGameResort 0x166F80** (DIFF 11): copies the shared literal D_002D9940 "-100" (also used by INCLUDE_ASM'd 0x166D40) into a stack buffer as lw+lbu; ours memcpy gives lb and different scheduling. Probably `strcpy(buf, "-100")` with the literal merged with 0x166D40's: do both together.
- Solved this round from older entries: 0x109108, 0x109248 (CFlagWork), 0x159790 (CGameSeasonPost), 0x1B7188 (CMenuMgr), the pointer-to-member constants 0x108E10/0x108E38.
