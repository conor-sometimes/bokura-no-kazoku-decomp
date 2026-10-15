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
## g3
Lane g3 (goal 6b overnight grind). Snippets that came close are in the notes below.
- **Menu state machines** (Update of CMenuSysscr08 0x1AC200, CMenuSysscr04 0x1AD020, CMenuSysscr05
  0x1ACDA0, CMenuSysscr25 0x1AA7C8, CMenuSysscr10 0x1ABAF0, CInterfMgr 0x16BB20, CMenuSysscr27
  0x1A8EE8): the shape now mostly matches with a `goto loop` loop and per-yield
  `m_unk4 = X; done = 1; goto loop;` (docs/lessons.md, g3). 0x1AC200 is at DIFF 30: retail places
  the last wait's "then" block (`m_state = 5; m_unk4C = w->m_unk58; -> -0xB0`) before its test and
  reaches it with `beql`; ours keeps it inline after a `bne`. A `while` around it or explicit gotos
  in retail's order did not change it.
- **0x143A30** CSysFlag ctor: DIFF 2, `lui a1` of D_002A1AA0 scheduled after the `lui` of
  D_002A26E0 (retail: `lui; addiu a1` first). The header now declares `CSysFlag()` and
  `CFlagWork::Func108448`.
- **0x169450** CInterfMgr::Start169450: DIFF 1, retail compares `r != 1` with `xor` against s16
  (which holds 1 for `m_unkC0 = 1`); ours uses `xori`. Rest matches with
  `CInterfTimer *t = &m_timer; t->Reset(); t->m_unk4 = m_unkC4;`.
- **0x1787E8 / 0x179438** (memorial window SetX with switch on m_unk44): retail fills the first
  `beq` delay slot with the next case constant; ours steals the case-1 `sll`. 0x1787E8 also keeps
  `this + 0xC` in a register for the case-2 stores. `case 0: break;` makes it worse.
- **0x17BDF0**: DIFF 8, s18/s19 swapped (n = base + j vs j).
- **0x185648**: DIFF 4, retail copies `&D_002A3C08[k]` into a second register (`daddu $16, $5`).
- **0x1972E8**: DIFF 1, one `lw` of D_002A5530 through `%lo(...)($21)` (hi register) instead of the
  full-address register.
- **0x12CD30** CSceneSet add-chara: DIFF 2, argument setup order for the `func_00113C38(c, v, -1)`
  call (retail sets a2 = -1 first, a1 in the delay slot).
- **0x1A98F8**: DIFF 6, the `m_unk60 / 4` prologue uses a2/a0/v1 in retail, v1/a1/a0 in ours (same
  in the unit).
- **0x111BA8** CSwingBoneRes2::LoadFile: `this` and the archive pointer get s18/s19 swapped and
  `if (Load(data)) ok = 1` is if-converted to sltu.
- **0x16E518**: LCG `((Next() << 16) | Next()) & 0xFFFF`: ours folds the first draw's high half away.
- **0x17CAE8**: field layout unclear (array stores at 0x3C+j*36 overlap 0xC0+j*0x90).
- **0x17D240**: switch whose jump table sits in the next unit's .rodata.
- **Key methods of merged units** (no level 3 possible): 0x10AF00 CPadMgr dtor, 0x10B8B8 CSnapMgr
  dtor, 0x169128 CInterfMgr dtor, 0x12C4F0 CSceneSet dtor (its vtable piece holds two TArray
  template vtables).
- Not tried (VU0/large/scheduling-heavy): 0x1865B8 (VU0 fmod), 0x16E688 (sepia filter), 0x196938,
  0x110560, 0x111960, 0x17BFA0, and the >200-instruction functions of the list.
## g4
- **Soft-double libcalls: solved by `-g`** (docs/compiler.md): CCharaObj 0x1153E8 and CMapAttr 0x118448
  matched; worth retrying CSvmWork 0x130CB0 (fmod) and the other double-using entries above.
- **LCG `(Next() << 16 | Next()) & 0xFFFF`: solved** by building the value in one variable set twice
  (`u32 r = Next() << 16; r |= Next(); return r;`): combine cannot use the nonzero bits of a pseudo with
  two sets, so the dead high draw survives as in retail. CMapEffObjRes 0x123850 matched; worth retrying
  CSvmWork 0x130E78 / 0x1702E0. Still open here: 0x1236C8 (DIFF 33 after perm: retail hoists `i * 16`
  above the range check), 0x1239E8, 0x125DB8 (retail does not hoist the float constants out of the loop;
  with a `goto` loop it does not either, but the loop entry differs), 0x1266B0 (register choice, s_me9).
- **CCharaObj 0x113368** (`Func113368`, name lookup): retail loop keeps `j*4 + t` per iteration (no strength
  reduction, 3 saved regs) and tests `count > 0` then jumps into the loop test; ours strength-reduces the name
  pointer (4 saved regs). Tried for/while/do, index forms, inline member Find.
- **CCharaObj 0x115B48**: DIFF 1, `bnezl` (ours) vs `bnez` (retail) on the `m_unk90` check before Func113F38.
- **CMapEffObjRes 0x124460**: DIFF 7, retail does `lwc1; abs.s; li 3000; lw 0x5C; li -1` in source order, ours
  schedules the 3000.0f constant and -1 first. **0x1245C8** matches only when 0x124460 is C++ before it
  (`blez` vs our `blezl` otherwise), so it waits for 0x124460.
- **CCharaObj 0x113F80**: DIFF 12, only the entry: retail `beqz m_res -> return -1; bnel m_unk18 -> body`
  with the `return -1` block between; ours `beqz`/`beqz` to a shared exit. The two loops match.
- **CMapEffObjRes 0x11CD60** (`Func11CD60`, entry loader with a struct-by-value debug print): DIFF 29; retail keeps
  `i*12 + 0xC0` in s17 and `this` in s18 and recomputes `this + off` for the `m_unk8` store; ours keeps `i*12`.
- **CMapEffObjRes 0x126860** (CMapEffSwingWork anim time advance, same shape as 0x124460): DIFF 24, address
  computation order (`&d->m_times[i]` before the entry lookup in retail).
- **LCG `& 0xFFFF` family also blocks** CMapEffObjRes 0x125DB8, 0x1266B0 (`(f32)(Rand32() & 0xFFFF) / 65535`).
- **CMapEffObjRes 0x11F2A8 / 0x122808** (with `-Wa,-g` now): only the double constant differs: retail loads
  59.94 with `lui $at; ld $5, %lo(D_002D4750)($at)`, the `li.d` macro, i.e. a C literal `59.94` whose
  8 bytes gas put in the unit's .rodata. Needs the unit's .rodata from the object (merged unit
  CMapEffObjRes/CMapEffObj, not converted). C in build/bk/snips/s_me1h.snip.
- **CChrBodyWin 0x189018** (`Init189018`, menu setup with `new`): DIFF 1, `beqzl` vs `beqz` in the
  switch compare tree; the default case needs a non-sibcall print (`if (Func235DE0(...)) return;`).
- **CChrBodyWin 0x187D68**: DIFF 7, argument register setup order for the 9-argument func_00253048.
- **CGameMain 0x150EA8**: with a `goto` loop (no loop.c) only the first branch's sense differs
  (`beql` vs `bne` + return); 0x1532A8 needs CGameMainSub129D90 inline helpers (written, DIFF in
  first block).
- **CMapAttr 0x1182B8** (field init, ~70 stores): not tried.
## r1
Lane r1 (goal 6b): CAppMain, Unit1EB8E8, Unit1EE008, Unit1F0518, Unit1F1EC0, Unit1F4918 (the XMN
model/anim runtime and the rx* memory-card / thread / render middleware). Drafts for the entries
below are kept in the lane's notes; each line says what still differs.
- **Stack addresses not hoisted** (rxMc): retail recomputes `addiu $a, $sp, N` for `&local` on every
  call inside a loop, ours keeps it in an s-register (gcse/cse): 0x1ED6E0 McSync (`&result`),
  0x1EE4F8 write-with-CRC (matches byte for byte with `-fno-gcse`, but the unit is not built with
  it: 30+ matched functions change), 0x1EE318 read-with-CRC, 0x1EE940 dir size (also counts `n` down
  in place), 0x1EDA30 McGetInfo retry loop.
- **Register choice / giv base only**: 0x1EAE70, 0x1EAF10 (loop giv = list base, DIFF 5/9),
  0x1EAFF0, 0x1EB0C0 (DIFF 6), 0x1ED768 (DIFF 9, counter/pointer swapped), 0x1EADA0 (lq/sq copy,
  50 vs 52), 0x1ED318 (pose eval, DIFF 32 with explicit node/track/table/item pointer walks:
  only s-register numbering left; 0x1ECE18 and 0x1ED4C0 are the same shape), 0x1F2090 (DIFF 15,
  next pointer copied at the loop test), 0x1F5038 (DIFF 34+), CAppMain::Draw 0x1EA838 (GIF packet,
  size matches, DIFF 94 all registers: retail keeps 5 in $17 and 0x46 in $30 from the prologue),
  0x1EF8D8 IPU decode start (DIFF 23: bnezl vs bnez on the mode test, constant registers; the IPU
  command word goes through an inline with constant parameters so 0x10000|0x10000000 stay unfolded).
- **Scheduling we cannot steer**: 0x1EF5C8 clears six DMA words in the order 880,888,890,894,884;
  ours always 880,890,894,884,888 (bk test masks relocs, only mk.sh shows it); 0x1EF728 (DIFF 18
  around an inlined 16-byte memcpy).
- **Shape**: 0x1EC120 (name compare; '_' not hoisted into a register, 80 vs 76), 0x1EC9A8 (CSEs
  memcmp's zero), 0x1ECA58 (material chunk switch: retail cross-jumps the shared case tails),
  0x1FF328 (packet reset: retail keeps the init stores in source order via a temporary and copies
  the base to $16 only inside the loop; a volatile D_30E170 changes the whole unit), 0x1EF210 (job enqueue: a0-a2 spilled to the stack and copied, yet still a sibcall), 0x1EEFA8 (job
  thread loop), 0x1F18F0 (thread create: four differently formed entry addresses), 0x1F2230 (model
  table alloc), 0x1F13A0 (alarm handler), 0x1F4E40 (draw queue compaction: constants hoisted,
  k*16 giv).
- **Key method**: CAppMain's destructor 0x1E95C0 (vtable lives in vt_tail, unit not convertible).
- Not attempted (large): CAppMain Update 0x1E9E48 and Draw 0x1EA838, 0x1EB1E8/0x1EB4B0 (keyframe
  blend), Unit1EB8E8 0x1EB920/0x1EC250/0x1EC570/0x1ECFF8/0x1ED4C0, Unit1EE008 0x1EE668/
  0x1EFC80/0x1EFF48/0x1F0210, Unit1F0518 0x1F0518, Unit1F1EC0 0x1F2628/0x1F2838/0x1F36D0/0x1F3AC0,
  Unit1F4918 0x1F4918/0x1F4AA0/0x1F5158 and the 238-248-instruction family 0x1F5B70-0x1FB2E8
  (0x1F6E98/0x1F7278/0x1F7658/0x1F7A38 and 0x1F82E0/0x1F86C0/0x1F8AA0 are one template: group
  index, counters and three callees differ; heavy stack spills), 0x1FB6C0, 0x1FD0A8-0x1FE888,
  0x1FF4A0. CAppMain::Update 0x1E9E48 is a state.h coroutine (cases are negative line numbers).
## g1
- **CSvmRes CValue setters 0x12E0C8 / 0x12E130 / 0x12E1D8** (SetInt, SetFloat, Set12E1D8: switch on m_type): retail `jal sprintf`/`jal strcpy` at the end of a case and leaves `nop` in the atof/`__truncdfsf2` (0x285498) delay slots; ours sibcalls (`j`) out of the switch and fills the slots. Tried if-chains, `return;`, `case 0: default:`, -fno-* flags. Same family as CSvmWork 0x130CB0. These and Get12E350 use CSvmWork's literals (0x2D5200 "%d", 0x2D5208 "%f", 0x2D5210 ""): extern them.
- **CSvmRes 0x12E558** (CValue::Equals): DIFF 4, retail `beql` for the type>=2 test and a separate `b; daddu v0,0` per default path; ours shares. Tried 5 return/switch shapes.
- **CSvmRes 0x12DE40** (CSvmHeader::Find chunk): DIFF 3, `p = (u8 *)this + 0x10` local; retail computes p after the `blez size`, ours before.
- **CSvmRes 0x12DEC0** (CSvmRes::Load): 3 insns long; retail keeps the found chunk in v0 and computes `c + 0xC` before the null test, ours copies c to a2.
- **ISysFlag 0x144270, 0x144378 (CSysFlag), 0x144C60, 0x144D68 (CCurFlag)**: bit get/set on `q = b / 7`, `mask = 1 << (b % 7)`, `if (q < 0 || 15 < q) printf(D_002D7940, b, q, mask)`. Retail keeps two signed compares (`bltz q; slti 15 < q`); ours folds to one unsigned compare. Inline `OutRange()` helper keeps two compares but materialises a flag. Same as 0x145160. Retail also computes `base + r*16` before the `r < 0` test (a local `id` did not help). Signatures are in include/CFlagWork.h now.
- **CUserFlagMgr 0x140D40** (recursive operator-precedence parser, `Func140D40(w, s, depth)`: it takes a depth in a3, which the matched Func140EA0 passes as 0 by accident of `r = 0` living in a3): loop shape and register numbering differ (retail keeps the table pointer in two s-regs). Not ported; rename to `...PPCci` when it is.
- **CSndWorkReal 0x12A0F0** (DIFF 1), **0x129900** (DIFF 3), **0x1296F0** (DIFF 2): best C is in CSndWorkReal.cpp in `#if 0` blocks above the INCLUDE_ASM. **0x129020** (DIFF 8): store order of m2C/m30/m34 in the two not-busy branches (perm of both triples tried); use the `CSndWork::SetVol(h, x)` inline for the volume tail. **0x1295E8**: s-register numbering of e/next (51 vs 52 insns, SetVol inline tried). **0x12A420**: retail keeps one exit for the 1.0/0.0/curve results; if-chain and ternary shapes 4 insns off. **0x12A510**: DIFF 18, `s + 0x28` and the `out->w = 0` store scheduled differently. **0x128F10** (unlink chara / all): IndexOf inline loop shape (2 insns short).
- **CMiniGame3 0x1CA3B8 / 0x1CA4C8** (Set2/Set1, with Anim(i)->Set(..)): retail keeps `this + i*0x30` in three registers (two `daddu` copies) and addresses m_ent[i].m_state/m18/m1C as 0xC30/0xC48/0xC4C off it; ours folds 0xC30 into the base. Tried inline ResetScale on the entry and on the task, direct stores, chained. Set3/Set4/Set5 match with the Anim(i) helper.
- **CMiniGame3 0x1CA528** (Shuffle, DIFF 2): best C in the source; only the order of `li 16` (the inline Rand(n) divisor) vs the LCG constant's `ori`.
- **CMiniGame2 0x1C4810** (Pick): DIFF 33, retail hoists `&m_rand` out of the retry loop and keeps k in a3; **0x1C4CA0** (LoadLevel): DIFF 25, s-register numbering (retail keeps &mD6C in s0; the CMiniGame3 twin 0x1C9F80 matches); **0x1C48E8** (SetQuestion): DIFF 26, register numbering only (m_q[j + 3] indexing and the inline CRand::Rand(n) give retail's shape).
- **CMenuTutorSelected 0x184640** (SetMode clamp 0..1, from older HARD): nested ternary now gives retail's branches; DIFF 2 left: retail shares the `sw; jr` tail for the 0 path, ours duplicates it.
- **ISysFlag 0x145160** solved: a range check written as nested ifs (`if (id < 0x22) { if (id >= 0x1F) {...; goto done;} } print; done:`) keeps two signed compares; `&&` folds to one unsigned compare. For the 144D68 family, `q > lim` with `s32 lim = 15` gives retail's `li 15; slt` (a constant folds to `slti 16`), best DIFF 13 with `if (b / 7 < 0 || q > lim)`: the second compare is scheduled above the `bltz`.
- **ISysFlag 0x144070** (GetBit): each failed bound returns through its own `b; daddu v0,0` stub in retail; `&&` chain, early returns and nested ifs all 1-4 insns off.
- **CDiffMotionObj 0x10FB30** (Load): DIFF 4, store order of the hand-over block (m_rec, m14, m_tbl, m_h, mC, m10 with the locals reset to -1/0); hill-climb perm best DIFF 4.
- **CMiniGame2 0x1C4710 / CMiniGame3 0x1C9E90** (task destructors, key methods; Load is now C++ so the units could go to level 3): retail keeps `this + 0xAA0` (0x920 in CMiniGame3) in an s-register from the entry and destroys it first with func_001B9D70(p, 2); that member is built by func_001BD188, the others by func_001B9D40. POD members with explicit calls, class members, an implicit/inline derived destructor (passes 0, not 2) and an empty inline call on the member: all 59/64 insns.
- **CMovieObj 0x13E800**: hill-climb perm of the 9 individual stores reaches DIFF 2 (as before); inline head Reset() can't interleave.
- **Menu Update state machines** (0x1A7818 CMenuSysscr32, 0x1ABF80 CMenuSysscr09, ...): the CStateMachine loop `while (!done && !(m_flags & 0x80)) switch (m_state) {...}` matches retail's case tree (cases -1, -202, -207/-213, -226, -230 and `default: goto out`), but ours jump-threads `done = 1` straight to the exit while retail keeps the flag in a register and loops back; the whole loop collapses (115 vs 122 insns).
- **CCommandSelect 0x198E40** (record remove): DIFF 1, best C in the source; **0x198CE0** (insert) is its mirror, 1 insn short (retail passes m_num for k in the k == m_num path). **0x19A480** (draw the two gauges): DIFF 29, s-register numbering only (pointer walk over m_rect; the index form is longer).
- **CMenuTutorSelected 0x184090 / 0x1841D0** (caption draws): a CTextBuf filled field by field (~20 stores) whose scheduled order differs between the two functions; not tried beyond decoding (0x1841D0 sprintf's six (s32) casts of a f32 v[2][4] picked by m_mode).
- **CSvmRes CValue setters** (update with `as -g`): the unfilled delay slots now match; what is left is the tail call: ours sibcalls sprintf/strcpy at the end of the switch (whatever the case order, `break` or `return`), retail keeps `jal` + epilogue.
- **CSndWorkReal 0x128E78** (SetChara): perm of the fade-reset stores (with m_unkA8) best DIFF 4; field at 0x18 of the chara, not m_name.
- **CUserFlagMgr 0x141F68 / 0x1425D8 / 0x141768 / 0x1409A8 / 0x13F948**: switch dispatchers now possible (jump tables work after the .rodata piece fix), not written yet; 0x142318's best C is in the source (DIFF 1).
- Solved this round from older entries: CCharaRes 0x112030, 0x1120A0, 0x112B60 (lane 2 round 2).
  CMotionRes 0x110DC8 (lane 2 round 2).
## r3
Lane r3 (2026-10-15, rxsnd C units Unit20E938..Unit21F250).
- 0x20E938 (Unit20E938, 48 insns, find a bank entry name with strcmp): DIFF 1. Best
  `if ((e = func_0020E758(id)) == 0 || (t = func_0020E798(id, k)) == 0) return 0;` then
  `for (i = 0; i < t[1]; i++) { char *s = e->m18 + t[2 + i]; if (!strcmp(s + 8, name)) return i; } return -1;`:
  ours `beqzl s3` (likely) where retail has `beqz $19` with `daddu $2,$0,$0` in the delay slot.
- 0x20F530 (Unit20E938, 20 insns, `return slot->m19` after testing `m19 & 1`): the same reload
  problem as r2's 0x20B0B8: retail tests the u8-inline result and re-loads the byte for the return;
  `s`-pointer form CSEs the load (returns the tested register), index form gives other address
  registers (DIFF 19), volatile gives the reload but no delay-slot fill (DIFF 2). The same getter
  pattern for other fields (m30, m50, m8, mC, m1F) matched with `Strm *s; if (i < 64 && Used(s = &D.e[i]))
  goto found; return 0; found: return s->mXX;`.
- 0x20F9E8, 0x20FAC8 (Unit20E938, 29 insns, call `s->ops->f14/f1C(s->m4C)` if set, else -1/0):
  retail lays out `bnez fn -> call; b epilogue; li -1` (return-default block between the test and
  the call, the i<64 failure jumps to it, the Used() failure goes straight to the epilogue).
  Tried goto found, if/else, return-variable and nested forms: DIFF 23 or +1 insn.
- 0x210B88, 0x210DF8, 0x210E38, 0x211300 (Unit210070, 14-18 insns, `MemStrm *m = &D_331E58.m[i];
  if (i < 64 && m->used) ...`): retail schedules `sll` before `sltiu` and puts the compare result in
  $4 (i's register), ours does the `sltiu` first (DIFF 4-9). 0x210B18 and 0x210BD8 with the same
  prologue match.
- 0x210C58 (Unit210070, 104 insns, memory stream advance with marker callbacks): DIFF 1, one
  branch: retail `bnel $2,$0` (likely) with `daddu $5,$18` in the delay slot in the inlined
  `CLAMPZ(MIN(n, func_00210BD8(i)))`, ours `bnez` + same delay slot. Four macro spellings tried.
- 0x212D40, 0x213238 (Unit212790, 11/18 insns, `p = func_00213348(i); return p ? p->m2 : -1` and
  `if (p) return (p->mA & 1) && (p->mA & 2)`): retail copies the returned pointer to $3 and builds the
  result in $2; ours keeps p in $2 (DIFF 5, +1 insn). The same shape with a pointer result
  (0x212D10, 0x213388 with a result variable) matched.
- 0x215270, 0x2155F8, 0x215628 (Unit214938, 11-12 insns, `p = func(); return p ? p->m2 : -1` /
  `if (p) return p->bit`): same as 0x212D40: retail copies the returned pointer to $3 first. Calling
  through an int-returning cast did not change it.
- 0x215328 (Unit214938, 68 insns, collect child ids through alloca'd buffers): DIFF 15, only the
  prologue: retail sets `cnt = 0` in the delay slot after the first call, ours hoists it into the
  prologue (same registers otherwise). do-while / while / if-wrapped forms tried.
- 0x216548 (Unit215A38, 132 insns, type-0 player update protothread): structure matches
  (`PTV_WAIT_WHILE(0x501, ...)`, `restart:` label, `case 0x53E:` before the flag updates, 0x546
  stop yield); DIFF 55 left from two things: retail materialises `e->mD = 0x3F` with its own `li`
  instead of reusing the `flags = 0x3F` register, and the `flags & N` tests use plain `beqz` where ours
  use `beqzl`. u8/s32 flags and moving `flags = 0x3F` before the call tried. 0x2168A8 and 0x216C08 are
  the same function for player types 1/2.
- 0x219818, 0x219880, 0x2198E8 (Unit217F50, 25-26 insns, dispatch `D_002A67E8[p->m2](p, 0, n)` for
  two record types): retail keeps the 0 result in $2 from right after the lookup call and returns the
  table call's result directly; ours adds a copy (+1-2 insns) in every result-variable, switch and
  early-return form tried.
- 0x218AD0, 0x218B70 (Unit217F50, 40 insns, compute a listener-relative vector then call
  func_002186B0): DIFF 17, saved-register assignment only (retail gives a/b the first s-regs, ours
  gives them to the three stack-passed pointer/count args).
- 0x21A510 (Unit219970, 52 insns, find the SPU area containing an address): structure matches,
  DIFF 21 from the zone/link/base temporaries landing in different $4-$6 registers; declaration
  order and scoping variants tried.
- 0x21C7C8, 0x21C838, 0x21C978, 0x21C9E8, 0x21CC30, 0x21CCB0 (Unit21BEC0, 27-34 insns, GS packet
  writers with a call between two `*D_002B94E4++ = v` puts): DIFF 10-15, all in the second put:
  retail loads the value (`D_33D6F0 + n | 0x14000000`) before the packet pointer and gets $4/$3, ours
  loads the pointer first. Pointer-first and value-first macros, an inline `PutP(u32 **, v)` and
  open-coded temporaries tried; the same puts without a call in between (0x21CDF8, 0x21D010...) match.
- 0x21FD58 (Unit21F250, 60 insns, GS packet chunk header: `k = n > 0x35 ? n / 3 : n; r = min(k,
  0x35)`): retail keeps 0x35 in a register and builds the min with `movz` into a separate result;
  DIFF 22 at best (`lim` variable, ternary and if forms). 0x21D3E0 (Unit21BEC0) is the same function.
- 0x21E860 (Unit21D820, 24 insns, open a GIF packet: two puts, remember both pointers): DIFF 6, the
  four constant registers ($6-$9) come out in a different order; store-order permutations tried.
- 0x21BCC0 (Unit219970, 13 insns, `r = 0; if (i < 2) r = D_002B6818[i].m0;`): retail copies `i` to
  $5 and puts the `sltiu` result in $4 (same family as 0x210DF8); DIFF 13.
