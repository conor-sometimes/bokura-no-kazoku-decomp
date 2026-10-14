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
