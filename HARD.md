- **CEventObj 0x135690** (Start: sets the five script slots' callbacks from the PMF constants D_002D5670.. as `extern const`): DIFF 82, only the temp registers of the PMF copies through the stack (`ldl/sdl` via sp); tried an inline setter with a by-value PMF, a local temp, direct assignment. **CEventObj 0x1327F8** (~CEventObj): key method; CEventObj's vtable is still asm.
- **Attempted only briefly / not attempted (size or shape)**: CEventObj command handlers 0x13A100, 0x13A2C8, 0x13A508, 0x13A790, 0x13AA80, 0x13AC58, 0x138610, 0x138908, 0x13C120, 0x13D518, 0x13D6D8, 0x134D28, 0x133B90, 0x13C2D0, 0x137DC8, 0x138BB8, 0x135C40, 0x139440, 0x13CA58, 0x13B068, 0x1362C0 (pointer-to-member state machines with the queue writers and the menu-loop shape above); CGameSeasonPost::Update 0x1590B8, CGameResort::Update 0x167F30, CEndingMain::Update 0x107A18, CDemoMain::Update 0x1065C8 (CStateMachine push/pop loops, same shape); CGameSchedule 0x15A158 (3234 insns), 0x15EB68 (else-if chain layout), CMiniGame5Res 0x1DF730 (3330) and 0x1E2B38; CEFontWork 0x10BFD0 (VU0 + switch); CFlagWork 0x1098A8, 0x109C30, 0x10A000, 0x10A3E8 (GS packet builders, 64-bit bitfields); CMapDBExpr 0x173050 (key method of CMapDBMgr in a `# also` unit), 0x173160 (stack spills); CMapSndObj 0x128528 (random pitch/volume floats); CEventMesRes 0x13E178 (switch; its jump table sits between INCLUDE_RODATA pieces); CMenuMgr 0x1B4820 (spills), 0x1B50B0, 0x1B5788, 0x1B66E8, 0x1B7EF8; CLayoutObj draw routines 0x1BA7E8, 0x1BADB0, 0x1BB438, 0x1BBDE8, 0x1BCAF8 (they share the rect block below).
- **CLayoutObj 0x1BC360** (text entry draw): all but one instruction; the shared rect block is an inline `LayoutCalcRect(CLayoutRect *r, CLayoutEntryX *e, const CLayoutRect *t, f32 dx, f32 dy, f32 sx, f32 sy, u32 flags)` (r = t + d; `if (t->w == 0) r->w = (f32)e->m88; if (t->h == 0) r->h = (f32)e->m8C;` then the image size through a local `img = e->mC`, scale by e->m30/m34, the sx/sy != 1.0f centring (not folded), the 0xF0/0xF00 alignment switches, r->w += r->x, r->h += r->y), locals declared st, t, r, buf. Remaining: ours keeps 0x8000000 in s5 for both `flags & 0x8000000` and `flags | 0x8000000`, retail rematerialises it (`lui`) each time.
#- **CEventObj 0x135690** (Start: sets the five script slots' callbacks from the PMF constants D_002D5670.. as `extern const`): DIFF 82, only the temp registers of the PMF copies through the stack (`ldl/sdl` via sp); tried an inline setter with a by-value PMF, a local temp, direct assignment. **CEventObj 0x1327F8** (~CEventObj): key method; CEventObj's vtable is still asm.
 - **CEventObj 0x135690** (Start: sets the five script slots' callbacks from the PMF constants D_002D5670.. as `extern const`): DIFF 82, only the temp registers of the PMF copies through the stack (`ldl/sdl` via sp); tried an inline setter with a by-value PMF, a local temp, direct assignment. **CEventObj 0x1327F8** (~CEventObj): key method; CEventObj's vtable is still asm.

-- **CEventObj 0x135690** (Start: sets the five script slots' callbacks from the PMF constants D_002D5670.. as `extern const`): DIFF 82, only the temp registers of the PMF copies through the stack (`ldl/sdl` via sp); tried an inline setter with a by-value PMF, a local temp, direct assignment. **CEventObj 0x1327F8** (~CEventObj): key method; CEventObj's vtable is still asm.

>- **CEventObj 0x135690** (Start: sets the five script slots' callbacks from the PMF constants D_002D5670.. as `extern const`): DIFF 82, only the temp registers of the PMF copies through the stack (`ldl/sdl` via sp); tried an inline setter with a by-value PMF, a local temp, direct assignment. **CEventObj 0x1327F8** (~CEventObj): key method; CEventObj's vtable is still asm.

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
*- **CEventObj 0x135690** (Start: sets the five script slots' callbacks from the PMF constants D_002D5670.. as `extern const`): DIFF 82, only the temp registers of the PMF copies through the stack (`ldl/sdl` via sp); tried an inline setter with a by-value PMF, a local temp, direct assignment. **CEventObj 0x1327F8** (~CEventObj): key method; CEventObj's vtable is still asm.

- **CMiniGame5Res 0x1DEF58** (CMiniGame5 ctor, snippet in g2 notes): DIFF 2, `li $5,-1` scheduled before `addiu $2,this,0x30` (CStateMachine member init); tried CStateMachine/CMiniGameTimer orders, CRand ctor vs body.
- **CMiniGame5Res 0x1DF2F0** (quest picker): DIFF 2, the cumulative-weight pick loop: retail `beqz` + `addiu i` in the delay slot, ours `beqzl`; tried for/while/goto/continue/j-temp variants.
- **CMiniGame5Res 0x1DEA78 / 0x1DF0F8**: key methods (CMiniGame5Res dtor inlines ~CListTag; CMiniGame5 dtor); need level 3 and CListTag's linkonce vtable kept out of the piece.
- **CEFontWork 0x10C710**: switch whose jump table (jtbl_002D2B40) sits in the next unit's .rodata (text boundary); needs the function moved to its real unit.
- **CEventMesRes 0x13DBF8** (ParseItem, DIFF 34) and **0x13DA10** (Load, size +3): register numbering/scheduling; second loop's `it->m_ids[i] = ...` address computed after the call in retail, buffer pointer copied to a fresh register; Load's alnum test layout.
- **CEventMesRes 0x13DE70 / 0x13DEB0 / 0x13D958**: CEventMesMgr ctor/dtor and CEventMesRes dtor inline TList/CList/CListTag ctors/dtors; inlining them would emit linkonce vtables (_vt$5CList, _vt$8CListTag) into this unit's piece.
- **CFaceRes 0x10E5E0** (ParseFaceParts, DIFF 15): retail interleaves the eight `lhu`/`sh` pairs (load, store, load, store), ours hoists all loads; tried array/struct locals, s16 pointer, inline setter.
- **CFaceRes 0x10E7A8** (LoadFaceSets, DIFF 3): `move s1,s3` (s = sets) placed before the hoisted `lui`s in retail; tried for-init, declaration orders.
- **CGameSchedule 0x159E18** (Next, size -9): first ScheduleUnit() is branchy (`bnez`/`b` + `move a1`) in retail, movz in ours; layout of the remove block; tried goto/for/while forms.
- **CGameSchedule 0x15F1B0** (size -2): register numbering (n in $20 vs ours $21) and a loop-alignment nop; returns 0 or Func15F9E0's value.
- **CGameSchedule 0x15F780** (DIFF ~72): register allocation of the nested slot-merge loops (k/n/b/p/j in s3/s4/s5/s6/s2 in retail); tried pointer and index forms of the D_002A3480 walk.
- **CGameSchedule 0x15D620** (DIFF 15 after perm of the field stores): ours computes `&D_002A26E4` (lui/addiu s3) before the `if (!rec)` branch, retail inside the found path; also s1/s3 save order. Tried if/else and single-exit forms.
- **CEventObj 0x135138** (DIFF 12): s4/s5 swapped between `&m_svm[3]` and `&m_svm[5]`; tried pointer locals in all orders and partial locals.
- **CEventObj 0x132BB8** (DIFF 5): only the list-count loop's registers (retail mgr in a0, count in a1; ours v1/a0); tried inline counters, goto loop, mgr local.
- **CFlagWork 0x108C30** (text loader, DIFF ~73): block layout of the matched-range branch (retail puts the per-value loop body before the found-block init and jumps to the test) and `text` first held in s0; tried break/flag and goto forms. **0x108700**: s0/s1 swapped (this vs the cached range); tried scope/inline-range variants.
- **CFlagWork 0x108448** (setup, size -2): close; remaining: d->m_size stored through a copy of d (`move a1,s0`) and reloaded for `size +=`, prologue scheduling of `defs = 0` / `Reset()`. Snippet in g2 notes (goto notfound form).
- **CMenuMgr 0x1B76D0** (DIFF 1): `bltzl` vs retail `bltz` after the save-data write of `m174` (delay slot `lui v0` from the exit block); tried void/int print, nested-if and goto forms. **0x1B4ED0 / 0x1B5E18**: GS register packets built from a 64-bit bitfield struct in a0 (needs the struct layout).
- **CMapRes 0x11A7C0** (DIFF 29): p/s register swap (s0/s1) and the `s = sets` copy placement; **0x119E08** (sorted insert into two item lists, size -10): loop shapes (first comparison against the cached key, later ones reload it->m40).
- **CMapDBExpr 0x173648** (DIFF 6): `s = line` lands in the first `bnez` delay slot in retail (ours first in the body, with the `this` reload in the slot).
- **CGameResort 0x166F80** (DIFF 11): copies the shared literal D_002D9940 "-100" (also used by INCLUDE_ASM'd 0x166D40) into a stack buffer as lw+lbu; ours memcpy gives lb and different scheduling. Probably `strcpy(buf, "-100")` with the literal merged with 0x166D40's: do both together.
- Solved this round from older entries: 0x109108, 0x109248 (CFlagWork), 0x159790 (CGameSeasonPost), 0x1B7188 (CMenuMgr), the pointer-to-member constants 0x108E10/0x108E38.
## g3
Lane g3 (goal 6b overnight grind). Snippets that came close are in the notes below.
Lane g3 (goal 6b overnight grind). Near-miss snippets are in the notes below; the full C for the
long ones is in the lane's scratch snippets (ask the head for them if a later lane wants them).
- **Menu state machines** (Update of CMenuSysscr08 0x1AC200, CMenuSysscr04 0x1AD020, CMenuSysscr05
  0x1ACDA0, CMenuSysscr25 0x1AA7C8, CMenuSysscr10 0x1ABAF0, CInterfMgr 0x16BB20, CMenuSysscr27
  0x1A8EE8, CTitleMain 0x1056A8): the shape now mostly matches with a `goto loop` loop and per-yield
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
- **0x185648**: DIFF 4, retail copies `&D_002A3C08[k]` into a second register (`daddu $16, $5`);
  index, pointer and block-scoped forms all give the same code.
- **0x1972E8**: DIFF 1, one `lw` of D_002A5530 through `%lo(...)($21)` (hi register) instead of the
  full-address register.
- **0x12CD30** CSceneSet add-chara: DIFF 2, argument setup order for the `func_00113C38(c, v, -1)`
  call (retail sets a2 = -1 first, a1 in the delay slot).
- **0x1A98F8 / 0x1A9BF8**: the `m_unk60 / 4` sequence uses a2/a0/v1/v0 in retail, v1/a1/a0/v0 in
  ours (local-alloc order). Temp variable, `/=` and an inline helper change nothing.
- **0x111BA8** CSwingBoneRes2::LoadFile: one difference left, docs/hard/nm/hard_111BA8.snip (utest DIFF 25 only because
  the rest shifts by one insn): `else if (Load(data)) ok = 1` is if-converted to sltu in ours (retail `bnel` + `li 1`); not nothrow (a may-throw Load alias changes nothing), goto/nested/!= forms tried (nm).
- **0x111960** CSwingBoneRes bone parser: retail stores `m_data` through a copy of the bone pointer
  and reloads it for the second Func1117C0 call; ours reuses the register.
- **0x110560** CModelRes parser: docs/hard/nm/hard_110560.snip (nm; DIFF 67 but only because of one shifted insn): retail hoists `lui %hi(D_002A03C8)` above the first strcmp branch
  and ends the option loop with `bnez`, ours `bnezl`; everything else matches.
- **0x178B30** CMenuLoadMemorialSub178778::DrawRow178B30 (410): DIFF 15, only the argument order of
  `func_001863F0(r, k, m_unk8[k])` after the SetUnk40 call (retail loads a2 first and puts a1 in the
  delay slot).
- **0x1B9CE8**: `(flags & 0x2000000) != 0` is `and` + `sltu` in retail, a shift extract in ours.
- **0x17A828** (Sub17A8D8b::Create): epilogue `ld s1` before `ld s0` in ours.
- **0x17B3E8**: store order of the eleven float/int stores; best DIFF 5 with chained assignments.
- **LCG draws** 0x16E518, 0x16FBF8, 0x1702E0 (CAlbumMgr::Draw): `((Next() << 16) | Next()) & 0xFFFF`
  keeps both halves and the final `andi` in retail; ours folds the first draw's high half away
  (tried u16 casts, `% 0x10000`, RandRange-style helpers, reassigned temporaries). 0x1702E0's
  constants are `RandF(lo, hi) = (f32)v / 65535.0f * (hi - lo) + lo` with (0.97, 1) and (0.9, 1).
- **0x16E960**: DIFF 31, `k * 0xF1` is strength-reduced in ours, retail multiplies by a register.
- **0x196938** (CMenuRecord item fill): retail's address arithmetic uses this+4/+8/+0xC bases;
  plain struct stores give simple offsets.
- **0x1DE060** CMiniGame4::Draw (622): ~54 register-numbering diffs left; retail keeps a copy of
  the layout-7 pointer, `this + 0xC` as a table base and the constant 1 in s-registers. Calling
  Draw1BA1D0 with the extra (flags, sx, sy) arguments needs an alias
  `Draw1BA1D0__10CLayoutObjP12CLayoutEntryUiffffff = 0x1BA1D0`.
- **0x17CAE8**: field layout unclear (array stores at 0x3C+j*36 overlap 0xC0+j*0x90).
- **0x17D240, 0x185BD0**: switches whose jump tables sit in the next unit's .rodata.
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
  CMapEffObjRes/CMapEffObj, not converted). C in docs/hard/g4/hard_11F2A8_122808.snip.
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
- **CSvmRes 0x12DE40** (CSvmHeader::Find chunk): DIFF 3, `p = (u8 *)this + 0x10` local; retail computes p after the `blez size`, ours before.
- **CSvmRes 0x12DEC0** (CSvmRes::Load): 3 insns long; retail keeps the found chunk in v0 and computes `c + 0xC` before the null test, ours copies c to a2.
- **ISysFlag 0x144270, 0x144378 (CSysFlag), 0x144C60, 0x144D68 (CCurFlag)**: bit get/set on `q = b / 7`, `mask = 1 << (b % 7)`, `if (q < 0 || 15 < q) printf(D_002D7940, b, q, mask)`. Retail keeps two signed compares (`bltz q; slti 15 < q`); ours folds to one unsigned compare. Inline `OutRange()` helper keeps two compares but materialises a flag. Same as 0x145160. Retail also computes `base + r*16` before the `r < 0` test (a local `id` did not help). Signatures are in include/CFlagWork.h now.
- **CUserFlagMgr 0x140D40** (recursive operator-precedence parser, `Func140D40(w, s, depth)`: it takes a depth in a3, which the matched Func140EA0 passes as 0 by accident of `r = 0` living in a3): loop shape and register numbering differ (retail keeps the table pointer in two s-regs). Not ported; rename to `...PPCci` when it is.
- **CSndWorkReal 0x129900** (DIFF 3), **0x1296F0** (DIFF 2): best C is in CSndWorkReal.cpp in `#if 0` blocks above the INCLUDE_ASM. **0x129020** (DIFF 8): store order of m2C/m30/m34 in the two not-busy branches (perm of both triples tried); use the `CSndWork::SetVol(h, x)` inline for the volume tail. **0x1295E8**: s-register numbering of e/next (51 vs 52 insns, SetVol inline tried). **0x12A420**: retail keeps one exit for the 1.0/0.0/curve results; if-chain and ternary shapes 4 insns off. **0x12A510**: DIFF 18, `s + 0x28` and the `out->w = 0` store scheduled differently. **0x128F10** (unlink chara / all): IndexOf inline loop shape (2 insns short).
- **CMiniGame3 0x1CA3B8 / 0x1CA4C8** (Set2/Set1, with Anim(i)->Set(..)): retail keeps `this + i*0x30` in three registers (two `daddu` copies) and addresses m_ent[i].m_state/m18/m1C as 0xC30/0xC48/0xC4C off it; ours folds 0xC30 into the base. Tried inline ResetScale on the entry and on the task, direct stores, chained. Set3/Set4/Set5 match with the Anim(i) helper.
- **CMiniGame3 0x1CA528** (Shuffle, DIFF 2): best C in the source; only the order of `li 16` (the inline Rand(n) divisor) vs the LCG constant's `ori`.
- **CMiniGame2 0x1C4810** (Pick): solved later (inline Range(lo, hi)); **0x1C4CA0** (LoadLevel): DIFF 25, s-register numbering (retail keeps &mD6C in s0; the CMiniGame3 twin 0x1C9F80 matches); **0x1C48E8** (SetQuestion): DIFF 26, register numbering only (m_q[j + 3] indexing and the inline CRand::Rand(n) give retail's shape).
- **CMenuTutorSelected 0x184640** (SetMode clamp 0..1, from older HARD): nested ternary now gives retail's branches; DIFF 2 left: retail shares the `sw; jr` tail for the 0 path, ours duplicates it.
- **ISysFlag 0x145160** solved: a range check written as nested ifs (`if (id < 0x22) { if (id >= 0x1F) {...; goto done;} } print; done:`) keeps two signed compares; `&&` folds to one unsigned compare. For the 144D68 family, `q > lim` with `s32 lim = 15` gives retail's `li 15; slt` (a constant folds to `slti 16`), best DIFF 13 with `if (b / 7 < 0 || q > lim)`: the second compare is scheduled above the `bltz`.
- **ISysFlag 0x144070** (GetBit): each failed bound returns through its own `b; daddu v0,0` stub in retail; `&&` chain, early returns and nested ifs all 1-4 insns off.
- **CDiffMotionObj 0x10FB30** (Load): DIFF 4, store order of the hand-over block (m_rec, m14, m_tbl, m_h, mC, m10 with the locals reset to -1/0); hill-climb perm best DIFF 4.
- **CMiniGame2 0x1C4710 / CMiniGame3 0x1C9E90** (task destructors, key methods; Load is now C++ so the units could go to level 3): retail keeps `this + 0xAA0` (0x920 in CMiniGame3) in an s-register from the entry and destroys it first with func_001B9D70(p, 2); that member is built by func_001BD188, the others by func_001B9D40. POD members with explicit calls, class members, an implicit/inline derived destructor (passes 0, not 2) and an empty inline call on the member: all 59/64 insns.
- **CMovieObj 0x13E800**: hill-climb perm of the 9 individual stores reaches DIFF 2 (as before); inline head Reset() can't interleave.
- **Menu Update state machines** (0x1A7818 CMenuSysscr32, 0x1ABF80 CMenuSysscr09, ...): the CStateMachine loop `while (!done && !(m_flags & 0x80)) switch (m_state) {...}` matches retail's case tree (cases -1, -202, -207/-213, -226, -230 and `default: goto out`), but ours jump-threads `done = 1` straight to the exit while retail keeps the flag in a register and loops back; the whole loop collapses (115 vs 122 insns).
- **CCommandSelect 0x198CE0** (insert) is the mirror of the matched Remove 0x198E40, 1 insn short (retail passes m_num for k in the k == m_num path). **0x19A480** (draw the two gauges): DIFF 29, s-register numbering only (pointer walk over m_rect; the index form is longer).
- **CMenuTutorSelected 0x184090 / 0x1841D0** (caption draws): a CTextBuf filled field by field (~20 stores) whose scheduled order differs between the two functions; not tried beyond decoding (0x1841D0 sprintf's six (s32) casts of a f32 v[2][4] picked by m_mode).
- **CSvmRes CValue setters** (update with `as -g`): the unfilled delay slots now match; what is left is the tail call: ours sibcalls sprintf/strcpy at the end of the switch (whatever the case order, `break` or `return`), retail keeps `jal` + epilogue.
- **CSndWorkReal 0x128E78** (SetChara): perm of the fade-reset stores (with m_unkA8) best DIFF 4; field at 0x18 of the chara, not m_name.
- **CUserFlagMgr 0x141F68 / 0x1425D8 / 0x141768 / 0x1409A8**: switch dispatchers now possible (jump tables work after the .rodata piece fix), not written yet.
- Solved later in this round: CMapAttr 0x1182B8 (field init), CGameMain 0x150C30 (dtor, unit to level 3),
  CPhotoDBMgr 0x1705C0 (key method, unit to level 3) and 0x170B18 (PMF literals), CMapEffObjRes 0x1228F0.
- Solved this round from older entries: CCharaRes 0x112030, 0x1120A0, 0x112B60 (lane 2 round 2).
  CMotionRes 0x110DC8 (lane 2 round 2).
## r3
Lane r3 (2026-10-15, rxsnd C units Unit20E938..Unit21F250).
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

## r4
- 0x222848, 0x2228E8 (Unit221008, GIF tag puts): retail computes `t = a | 0x45` then `t | 0x10` (two `ori`); ours folds to `a | 0x55`. Tried `a |= 0x45` param, a separate `u` local, xor, an inline Tag(); 24-25 diffs, all from the fold.
- 0x222C10 (Unit221008): `r = func_0021BDD0(1, 0); D_33DD2C = r; if (r < 0) return Func235DE0(fmt, r); ...`: retail keeps r in $2 (lui $3 for the .bss word), ours copies it to $3 first (`move v1,v0`). Tried void/int return, assignment in the condition, if/else swap, reading the global back.
- 0x224D80, 0x224EB8 (Unit224D58, save/restore of the VU1 state words + 54-qword copy): everything matches except the copy loop; retail counts i up (`slti 54`) with two pointer walks, ours reverses the counter (`bgez`); a `u32` counter keeps it up but gives `sltiu`; goto loop loses the loop alignment nop.
- 0x225B08 (Unit224D58, chunked unpack loop): DIFF 2, the two argument moves for func_00237860(k, src) come out a0-then-a1 (retail a1 first). Statement perms (5040) and x=0 placements didn't change it.
- 0x226668, 0x226730 (Unit224D58, chunked unpack state machine): retail loads max=53 into a register and copies k=max before the `n > 0` test, keeps c in $2; with the Chunk2 inline, explicit `max`/`k = max` or an inline Next() the register allocation differs (16-29 diffs). Best statement order: p=PKT; D_33DEA4=n-k; D_002B8C20=k; p[0]=...; PKT=p+5.
- 0x226B28, 0x226C00 (Unit226AE8): same chunk-state pattern as 0x226668/0x226730; only the register numbering of c/cmp and the global-address pseudos differ (DIFF 26). Store perms don't change it.
- 0x227690 (Unit226AE8, sibling of 0x2271E8 which matched): retail spills two lui'd .bss bases with `sq`/`lq` around the jalr; not tried further.
- 0x227FD8, 0x228020 (Unit226AE8, 12-byte table entry get/set of a u64): retail keeps redundant pointer copies (`daddu $4,$3,$0`) and loads/stores through each copy; inline helpers, offset locals didn't reproduce them.
- 0x228208 (Unit226AE8): DIFF 1, `addu base,off` operand order in the clear loop (`&tbl[i]`, `(tbl+i)`, byte offset all give off+base).
- 0x228458 (Unit226AE8, resource slot alloc): DIFF 2 with `goto search; found: ...; search: for (...) { e = &D_33F5D8[i]; if (!e->flags) goto found; }`; retail loads the table base into the found-pointer register and copies it to the probe pointer, ours the other way.
- 0x228710 (Unit226AE8, archive name lookup): best DIFF 11 with an inline `Cmp()` for the 24-char compare and the found block after the loop; retail reuses the compared char as the result (`beql ... daddu $4,$0,$0`), the inline gives a separate result register.
- 0x2288A0 (Unit226AE8, archive iterator): not tried.
- 0x228EA0 (Unit226AE8): `if (!tbl[TID]) return 0; func_00228658(...); return func_00228710(name);` must not sibcall but GCC makes it one; single-exit form copies the result through a0.
- 0x229300 (Unit228F78, LZ header size): retail keeps two copies of `x >> 8` (`daddu $3,$4,$0`) and ORs the bytes as (b2<<16|b1<<8)|(b0|b3<<24); inline helper / temp copies didn't reproduce it.
- 0x2299E0 (Unit228F78, memmove): `r` (copy of n) and n swap registers; tried if/else-if for the alignment test.
- 0x22AAF8 (Unit228F78, debug alloc): DIFF 2: retail `addiu; and -16; dsll32; dsra32` for the size argument of func_0022AD68 (32-bit add, sign-extending truncation); `(long)n+0x1F` gives daddiu, u32 casts give dsrl32.
- 0x22AD68, 0x22AE58 (Unit228F78, heap block split head/tail): DIFF 28 / ~10 from prologue scheduling and the n<16 test placement; single-exit `ret` variable made it worse.
- 0x22BC70, 0x22BDF0 (Unit228F78, first-fit search with inlined unlink): DIFF 34; retail copies the heap pointer to $6 so the node lives in $4, ours keeps the heap in $4 and hoists &h->m14.
- Unit228F78 not tried yet: 0x229028 (LZ decoder), 0x229678 (heap init), 0x2294E8 (128-bit fill check), 0x22A198 (realloc), 0x22A908 (compaction), 0x22AF98/0x22B138/0x22B390 (heap dump/check), 0x22B7C0 (alloca + qsort), 0x22B9F0 (free/coalesce).
- 0x22C2A8 (Unit22BFD0, clamp to 1..2 store): retail duplicates the lui per path; nested ternary / if-else-if give movz or a hoisted la.
- 0x22C680 (Unit22BFD0, pad repeat): DIFF 23 with if (!trig) { if (!held || mC != held) mC = held; else {repeat} } else mC = trig; retail's held==0 branch is a beql into the common tail.
- Unit22BFD0 pad-id clamp family (0x22D008, 0x22D0A0, 0x22D138, 0x22D1D0, 0x22D3C8, 0x22D480, 0x22D538, 0x22D6B0...): id&0xFF -> port 0..1, (id>>8)&0xFF -> slot 0..3. Retail tests the port with `slti $2,$2,0; bnez` but the slot with `bltzl`, and copies both into new registers (`daddu $5,$2`, `daddu $3,$4`); macro, inline clamp, if/else and ternary forms all if-convert or reorder (DIFF 25 best).
- 0x22D9F0 (Unit22BFD0, fs tables init): DIFF 3, only the first loop's counter register ($3 vs a0).
- 0x22DB68, 0x22DBB8 (Unit22BFD0, device op dispatch): retail copies the ops pointer from $2 to $3 before `lw $2,8($3); jalr`; ours keeps it in v0 (1 insn short). Tried typed fn local, if-assign, early return.
- 0x22F418 (Unit22DE48, chunked read through the cache): DIFF 49 on the first try, not pursued.
- 0x22F8A0 (Unit22DE48, queue a completion node under DI): retail copies `f` to $9 so `st & ~1` lands in $4 (and a nop aligns the loop); ours keeps f in $4. Same shape in 0x22F958 (a1 copied to $9). The DI/EI inlines from Unit20E938 are used.
- Unit22DE48 not tried yet: 0x22E618 (ring consume under DI), 0x22E8E0/0x22EA08 (open), 0x22F180, 0x22F6D0, 0x22F958 and the rest after 0x22F958. Units Unit230578 and Unit232B78 were not started (stopped after ~330 functions).
- **0x179790** CMenuLoadMemorialSub179568::DrawRow179790 (760): DIFF 24. Left: the k*2 spill slot
  sits before b/c/d in ours (retail: after d), and retail precomputes `&m_unk4[2k+1]` into s18
  before the post-loop draws while ours rebuilds it at the use. Needed so far: block-scoped loop
  counters, `id = k*2 + 0xE` then `id = k*2 + 0xF`, `(CUnk237E90 *)(p + 0x10)` spelled out inside
  the loops, `f32 yo = 3.0f` for the second row's y offset, `tb.m18 = tb.m10 = ...`.
- **GS packet builders** (0x186730 tried): the qword writes match the shape
  `D_2EC10C = &p[n]; p[n] = v;` with all 16 addresses precomputed, but retail also keeps the
  constants 1, 4 and 0x8000 in s-registers from the prologue (some inline/library helper we do
  not have yet) and stores `D_2EC108` through an unsymbolised `lui 0x2F / -0x3EF8`.
- **Not finished, large or spill-heavy**: 0x17C2C0 (482, graph rows), 0x17CC70 (316), 0x17BFA0 (stack-spilled loop counters), 0x11B428 and 0x16B2B0 (GS register packing like
  0x1B9CE8), 0x16EB68 / 0x169950 (Update state machines with many prints), 0x101480 (4234),
  0x1D5550 (8900). VU0 inline asm: 0x1865B8, 0x17B850, 0x16AA28, 0x16E280. GS packet builders:
  0x105CB0, 0x186730, 0x186AC8, 0x16A650, 0x16BD00, 0x10BBD0, 0x16DAD0, 0x16C0B8, 0x16F568,
  0x16FEE0, 0x16E688.
- **CMiniGame2 ctor 0x1C4540** (was Init1C4540): DIFF 23-29, best C in the source. Same recipe as the matched CMiniGame3 ctor (CProcess base, CStateMachine, CMgLayout/CMgLayout2/CMgSnd members with inline ctors, func_001BD188 returning void*); left: the colour loop (retail one pointer based at .b, offsets -8/-4/0) and register choice in the 3- and 10-iteration loops.
- **CMiniGame3 Shuffle 0x1CA528**: still DIFF 2 with the inline Range(0, 15); the `li 16` divisor is scheduled before the LCG ori.
- **CMovieObj 0x13E938**: CStateMachine update loop (push/pop asserts at lines 0x44-0x4C), same family as the menu Update state machines; not tried.
- **CMapEffRes 0x11BD20 / IFadeMgr 0x10B108 / ICharaResMgr 0x12D440**: destructors (key methods). CMapEffRes's data also holds a TArray template vtable and strings used by static-ctor data; IFadeMgr and ICharaResMgr share their data with CFadeMgr / CCharaResObj (`# also`), so not converted.
- **CUserFlagMgr 0x13F390** (destructor, vtable slot 34): key method (first declared virtual), needs level 3 with the ~30 library slots (0x298xxx) aliased to IUserFlagMgr names; not done.
- **CMiniGame2Res 0x1C4260** (qdata.txt loader): DIFF 25, best C in the source; retail computes i*3 and increments i straight after Func24AFE8 with no copy, ours copies i for the index (and the loop-exit test is beqz instead of beqzl). Separate locals for the separator strings change nothing.
- **CMiniGame3 Set2 0x1CA3B8** now DIFF 3 (best C in the source): writing the stores as `m_ent[i].m0 = 9; m_ent[i].S18(1.0f); m_ent[i].m1C = 1.0f;` gets retail's 0xC30/0xC48/0xC4C addressing; retail stores m18 through a copy of the m0 base where ours recomputes it. Set1 0x1CA4C8 is its twin.
- Solved later in g1: 0x13FF08 ParsePairs and 0x13FD00 (`while (s = Func(s, line, ...), *s || line[0])` with `continue`s, entries written as tbl[n].x), 0x142B38 SingleBit (`if (exact && (mask & ~(1 << i))) return -1; return i;`), 0x140358 (switch on *s with `*dst++ = *s++`), 0x1401B8 (inline Put(s32) on the writer, `Put(v >> 7i & 0x7F | (i > 0 ? 0x80 : 0))`, `n = n < 1 ? 1 : n`), 0x1C4810 Pick (inline Range), 0x1C9D70 CMiniGame3 ctor.
- **CCommandSelect 0x199108**: 19 vs 18 insns, best C in the source. Four separate `m_rect[k].c = 1.0f` stores reproduce retail's daddu copy chain (the same chain as CMiniGame3 Set2); ours folds 0x500 into the index add where retail keeps `this + k*32` with displacement 0x500.
- **CUserFlagMgr 0x1409A8** (compile one token): DIFF 59 at the same length, best C in the source; block layout of the shared 'unknown' print (cross-jumped in retail). Real signatures: Func1409A8(CUserFlagWriter *, const char *tok, const char **s) and Func140938(CUserFlagWriter *, const char **) (both renamed), Func140D40 takes a third int (depth).
- **IFadeMgr 0x10B350** (fade draw): hand-built GS/GIF packet (inline packet macros, u64 bitfield packing, cvt.w.s colours); not tried. **CFaceObj 0x10E138**: draw-list builder (10-arg virtual call, 32-byte upload entries on a 0x2000 stack array, TEX0 psm bits patched per entry); not tried.
- **CMenuTutorSelected 0x1848E0** (Draw): the same inline GS packet builder as IFadeMgr 0x10B350 (D_2EBB48 packet pointer, TEX/FRAME/ZBUF from func_0023C650/658); not tried. No lane has a C version of these packet macros yet.
- **GS packet builders** (CSndWorkReal 0x12A6B0 fade fill, IFadeMgr 0x10B350, CMenuTutorSelected 0x1848E0, probably 0x12AB18): 0x12A6B0's content is decoded in the source (best C, 305 vs 282 insns). `*D_2EBF8C++ = v` per word stores the packet pointer after every word; retail drops some of those stores (e.g. between the A+D tag word and the data) and reloads the pointer before others. The macro shape is still unknown (tried a macro, an inline function and a local-pointer macro).
- **CMiniGame3 0x1CA5E8** (StepCards, card state machine): DIFF 7, best C in the source, using CSwingBoneObj's FracVu0/Ftoi15 asm helpers and `u32 o` ScaleX/ScaleY helpers; retail schedules the 1.0f li.s above the frac store (asm without volatile, a temp for 1.0f, and expression orders tried).
- **CMovieObj 0x13EDC8** (draw the movie frame): long GS register sequence (func_00226DF8 per register, stack float rects, MovieTiles per strip); not tried.
- **CSndWorkReal 0x128870** is CSceneObj's constructor (vptr _vt$9CSceneObj at 0xD4, TList<CCharaObj> at 0x8, two CSndFade at 0x3C/0x6C, three `new` CSndWorkReal (0xF0: func_0025C230 base, vptr at 0xC, func_0025D478 member at 0x70), two `new` 0x6C base objects, `new CSndEntry[4]` with cookie, free list built from it); needs a separate CSceneObj class with that layout; not tried. 0x128BB0 is its destructor (key method).
- **CUserFlagMgr 0x140440** (compile a flag call/assignment: rewrites 'a op= b' into a recursive call via sprintf "(%s)=%s(%s)%c(%s)", argument count checks against the flag entry): long, not tried.
- **CMiniGame2 0x1C4A58** (SetCursor): 25 vs 27 insns, best C in the source; retail's flag loop is `li 1; movn` (ours folds to sltu) and it copies the m_pos base register (`daddu $2,$3`) before the x load. **CMiniGame3 0x1CA878** (Layout) solved: `f32 *p = &m_ent[i].m14; p[-1] = ...; p[0] = ...` puts the loop pointer on m14 as retail does.
- **CMiniGame3 0x1D4618** (Draw): 329 vs 334 insns, best C in the source (CLayoutObj calls; layout pointers l0/l1/l2; block-local `f32 a = 1.0f, b = 0.0f` reproduce retail's (a, a, b, b, a, a) argument copies). Left: inside the loops retail keeps 1.0f/2.0f in f24/f25, ours rematerializes them; float register naming in the two Printf blocks. CMiniGame2 0x1C95D8 is the same kind of Draw, not tried. Uses a merge-safe declaration of CLayoutObj::Draw1BA1D0 with main's signature (P12CLayoutEntryiffffff).
- Not attempted (size or family), each looked at once:
  - **CMapEffRes 0x11BD90 / 0x11C428**: effect serializers, a 9-case switch per effect writing through a by-value writer (`&param` at sp+0xB0) with func_0024B818 (printf-like) and fptodp for every float vararg; the unit's .rodata is still an asm piece (level 1), so formats must stay extern D_ symbols.
  - **CUserFlagMgr 0x142CE8 / 0x141768**: svm opcode handlers of the 0x142318/0x141F68 family (0x142318 is matched, 0x141F68 sits at DIFF 3).
  - **CSndWorkReal 0x12AB18**: GS packet builder (see the packet note). **0x12B180** (1176 insns, float): not tried.
  - **CMiniGame3 0x1CA900 / CMiniGame2 0x1C4E90** (Update, 10054 / 4562 insns, CStateMachine), **CCommandSelect 0x199500 / 0x199BC0**, **CMenuTutorSelected 0x1831A0**: CStateMachine update loops (menu family).
  - **CMenuTutorSelected 0x182130** (save-slot scan: 30 slots, CFlagWork on the stack, strength-reduced pointers spilled to the stack), **0x1829E8** (14 sprintf + CMenuRecordWin text lines), **0x1836E8** (record window layout), **0x183B98** (GS packet).
  - **CMiniGame2 0x1C95D8** (Draw): same recipe as CMiniGame3 Draw above.
- **CMiniGame2 0x1C4810** (Pick): DIFF 33, retail hoists `&m_rand` out of the retry loop and keeps k in a3; **0x1C4CA0** (LoadLevel): DIFF 25, s-register numbering (retail keeps &mD6C in s0; the CMiniGame3 twin 0x1C9F80 matches); **0x1C48E8** (SetQuestion): DIFF 26, register numbering only (m_q[j + 3] indexing and the inline CRand::Rand(n) give retail's shape).
- **CMenuTutorSelected 0x181CA0** (Draw): DIFF 35 in the source note, 17 after a perm of the 22 sprite-field stores (CTextBuf on the stack: func_0010BF88, fields, func_00256648/0256260/0256930/0256668); the menu-manager part matches.
- **Menu Update state machines in g1** (CMenuNosave 0x176300 best: DIFF 56 at the same length with the goto-loop recipe, note in the source; CMenuSysscr07 0x1AC540, CCommandSelect 0x1986A8 (key method), CMenuMemorial 0x176638, CMenuSysscr31 0x1A7C30, CMenuConfig 0x174AA0, CMenuTutorSelected 0x17FE58, CMenuSave 0x1AE998): same family; the last wait's then-block placement and register numbering stay open. Their Draws (CCommandSelect 0x1989D8, CMenuSysscr31 0x1A8AD8) matched.
## d1
Lane d1 (goal 6b, dklib units Dk245648, Dk2470E8, Dk2497C0, Dk24DE30, Dk24FAF0), 2026-10-15.
Near misses (C in the lane's scratch snippets; the shapes below are what is left):
- 0x246100 (memheap init, 107 insns): DIFF 2, store order of the eight header stores (magic, node
  table, counts, the two list heads); hill-climbing perm stuck at DIFF 2 with
  `magic, numNodes, nodes, usedNodes, list.prev, list.next, free.prev, free.next`.
- 0x2468F8 (memheap alloc, 167 insns): DIFF 1, retail `beq $21,1` + `daddu $16,$5` for `case 1:` of
  `switch (mode)`; ours `beql`. `if (!first || !last)` had to be split into separate failure blocks.
- 0x246C18 (pointer validity check): retail's chain `beql ..,L88 ; b bad ; nop ; L88: beqz` and the
  null-path print through `D_38F188.m_flags` vs the bad path through a materialised `&D_38F188`; tried
  one `&&` chain, nested ifs, gotos; DIFF 28.
- 0x247210 (range check): with `l = lo ? lo : func_00246008();` the registers match; the tail
  `if (p < l) goto zero; if (!(hi - 1 < p)) return 1;` comes out as movz or an extra return.
- 0x247B60 (colour lerp): DIFF 3, only the order of the first `srl`s.
- 0x249348 (close dir switch): DIFF 1-3, `bgtz` vs `bgtzl` on `D_002B9E50 <= 0`.
- 0x249428 (xap link by ini key): DIFF 3, `beql` layout of the `!strstr` return.
- 0x249700 (chunk search): DIFF 3, loop rotation (base+0x10 hoisting).
- 0x24A570 (tokenizer, 80 insns): DIFF 1, `beqz` vs `beqzl` before the final delimiter skip.
- 0x24AC50 (read line): DIFF 5, exit branches of the `'\n'`/`'#'` tests.
- 0x24A128 (xap link): DIFF 3, a1/a0 setup order of the "not found" print and the failed-alloc branch
  that retail sends back to the `if (n->m_data)` re-check.
- 0x24BAF0 / 0x24BB58 / 0x24BC00 / 0x24BF80 (CValue SetInt/SetFloat/SetString/Compare, `switch
  (m_type)`): retail loads the case constant `li $2,1` first and the default block has no alignment
  nop; best DIFF 6-7 with `do { switch } while (0)` and default-first case order.
- 0x24D340 / 0x24D3D0 (CExpr PMF hooks): `if (!m_obj) return 0; if (!m_get) return 0;` layout
  (`bnez index; nop; b ret`) not reproduced.
- 0x24D8D8 (float rand): ours folds `((Next() << 16) | (Next() & 0xFFFF)) & 0xFFFF` and drops the
  first LCG step; retail keeps `or` + `andi`.
- 0x24EEE8 (task tag reparent): DIFF 3, load order of the unlink (`next` before `prev`).
- 0x24F480 / 0x24F4D0 / 0x24F520 / 0x24F570 (task sibling/child walks): retail has a 7-insn loop
  (no short-loop nops) and `beqz $3 ; nop` before the final `n ? n->m_task : 0`.
- 0x24F6A8 (task counter inc/dec): retail `movz` for `inc ? v+1 : v-1` and `(j + i*3) + tag + 0x48`.
- 0x24F9B0 / 0x24FA50 (CProcess helpers): shared epilogue with `li v0,1` in the `bnez` delay slot;
  `r = 0; if (i < 4) r = m1C[i];` gets a v1 temp.
- 0x24FD90 (res cache alloc fallback): DIFF 9, `lui` of D_002BA0A4 hoisted above `beqz`.
- 0x251BF0 (CDebOut constructor, 14 field stores): DIFF 4, retail stores the float 0x38 right after
  0x28; hill-climbing perm (1245 orders) and chained-float variants stop at DIFF 4 with
  `m4, m28, m10, m14, m18, m8, mC, m20, m24, m2C, m30, m34, m38, m1C`.
- Round 2 (no cap), 2026-10-15:
  - 0x24FFE0 (CResCache ctor, written with explicit list-head stores and asm-label name): DIFF 4,
    store order of the three TList heads; hill-climbing perm stuck at 4.
  - 0x250208 (CResCache::Init250208): needs a real `new CResCacheUnit[n]` (cookie + count-down ctor
    loop); the unit declares CResCacheUnit as a POD view, so the manual loop comes out different.
  - 0x250368 (CResCache::Func250368): DIFF 19, retail keeps `bnez $5` after each unlink (`do { n =
    First(); if (n) Unlink(n); } while (n)`) where ours threads to `b`; unlink loads `next` first.
  - 0x250840, 0x250978, 0x250A48, 0x250B08, 0x250B80, 0x250D28, 0x250DD8 (res cache list walks): retail's
    TList::First is a branchy `bnez isHead ; daddu r,0 ; b ; daddu r,n` and the unlink helpers come in two
    load orders; our inline helpers give movz/movn and merged loops. 0x250D28 is DIFF 7.
  - 0x251398 (DISPFB writes): `D_39391C` must be its own symbol; OR order and the 0x12000090 address
    register still differ.
  - 0x2520C8 and 0x248298 (GS packet + VIF tail): retail keeps the constant 4 in `$17` for the four
    `D_002B94E4 += 4` writes; not reproduced with `p + 1`, byte casts or a temp.
  - 0x247FA8 (gradient bar, 188 insns): DIFF 9, only the stack slots of the two spilled quotients and
    `ca` (retail 0xC/0x10/0x14). Needs `i0 % w` etc. written inline at every use (retail redoes each div).
  - 0x24E9C0 (ear-clipping triangulation): DIFF 10, inner-loop `q` and the cached `j < n` flag get each
    other's saved register.
  - 0x24D6A0 (expression precedence level): structure right, register allocation and the spilled
    `&D_002BA008[level]` slot differ; D_002B9E60's address is not hoisted into a saved register in ours.
  - 0x24EF88 (task tree dispatch, 154 insns): first version 7 insns long, PMF and recursion shape close.
  - 0x24BA08 (int to SJIS digits): DIFF 10, registers of the second loop.
  - 0x24B650 (path split): register allocation (retail slash/dir/path/base/dot/ext = $16..$21).
  - 0x24ADE0, 0x24AF10, 0x24D2F8 (section tokenizer, digits check): loop shapes.
  - Not attempted: switch functions with jump tables (0x249958 decompressor, 0x24D460 primary
    parser) can't be compiled while the unit's .rodata is asm; 0x24DC40, 0x24A840, 0x248760, 0x250EC8,
    0x251650, 0x251DC0 (large); VU0 geometry 0x24DE30, 0x24E240, 0x24E560, 0x24E6D0, 0x24E830.
Not attempted (large / VU0 / linkonce): 0x24DE30-0x24E9C0 (geometry, VU0 macro), 0x247C00, 0x247D38,
0x247FA8, 0x248298, 0x248760 (GS packets), 0x249958 (xap decompressor), 0x24A840, 0x24B400, 0x24B4B8,
0x24B650, 0x24B8B8, 0x24BA08, 0x24D460, 0x24D6A0, 0x24DC40 (expression parser), 0x24ED20 / 0x24EDE8
(CTaskTag ctor/dtor build TList<CTaskTag> inline: linkonce vtable), 0x24EF88, 0x24FE80, 0x2505A0,
0x250208, 0x250368, CResCache list code 0x250840-0x250DD8, GS setup 0x250EC8-0x2520C8.
- **CFaceRes 0x10F068** (face group loader, size +1): control flow matches; register allocation/spills differ (retail keeps sets/nsets in s8/s7 and spills p, n, the group pointer and n*7 index).
- **Likely vs non-likely, one branch (DIFF 1)**: CMenuMgr 0x1B7910 (memory-card check, after the first strncmp), CGameSchedule 0x15F2C8 (solo picker, back-edge of the `for (i = 1; i < 7; i++)` loop), and the older 0x1DF2F0 (0x10C798, 0x198430, 0x1B4E70, 0x1B7E70 matched by nm; 0x1B76D0 now has the branch right but 4 register diffs around `m_unk8 * 3`, docs/hard/nm/hard_1B76D0.snip): retail `bnez`/`bltz` with a harmless insn in the slot, ours the `l` form. Snippets mm8_best/gs12_best/mm9 in the g2 scratch; tried int-returning print (asm-label alias), loop forms, statement orders.
- **CFlagWork 0x109778** (VU0 micro-mode matrix helper, called from CCharaObj): DIFF ~6. Best C: `vcallms` macros 0x30/0x20, store matrix (pointer in a `register asm("$2")` variable), vec {0,y,0,1} + `vcallms 0x80`, m[1][0] = -up[0]/up[1] and m[1][2] = -up[2]/up[1] (guarded by up[1] != 0), m[1][1] = 0, load matrix + `vcallms 0x60`, vec {0,-y,0,1}, store to out, `vcallms 0x40`. Retail stores v[0], v[3], v[1], v[2] and re-materialises 1.0f / `sw zero` for the second vector; ours reuses the first constants (GCSE).
- **CFlagWork 0x109508 / 0x10A878** (texture loaders whose strings sit in CPadMgr's rodata): DIFF 14; retail re-tests the loaded pointer before freeing it on the error path (`beqz s0` twice), GCC here folds the second test (tried `!f || (r = ...) < 0`, goto, r = -1, nested ifs, do-while(0)).
- **CGameSchedule 0x159CF0** (sorted insert, returns s32) and **0x15E860**: the list's first node is selected with branches (`bnez v0` / `move a0,zero` / `move a0,v1`, then copied), the next ones with `movz`; every inline/ternary/if form here gives `movz` for both.
- **CGameSchedule 0x15A090** (`v/3` three times): retail has three divide-by-zero checks but only one `div`; the first Func1091B0 result is unused. Not found.
- **CEventObj queue writers 0x133140, 0x1333D8, 0x133660, 0x1338E8, 0x134100, 0x134438, 0x134768**: inline ring-buffer `Push<T>(v)` on a CEvQueue {m_buf@8, m_wr@C, m_rd@10, m_size@14, m_num@18}: `if (m_size - m_num < n) { Func235DE0("*** queue overflow\n"); fail; }`, memcpy loop with wrap, then `w = (m_wr + n) % m_size; m_num = m_num + n; m_wr = w;` (`m_num++` gives an address temp). Best 0x133140 DIFF 34, only the free-space `bgtz` delay slot: retail has the `sb` of the pushed byte there (separate early `li v1,1`), ours steals `lw s1, m_wr`.
- **Menu Update state machines** (CMenuAsksave 0x192A80, CMenuSysscr01 0x1AE160, CMenuSysscr03 0x1AD360, CMenuSysscr23 0x1AB0B8 and ~35 more menu Updates in all lanes): best DIFF 25. What works: a goto loop (`r = 0; loop: if (r) goto out; if (busy) goto out; switch (m_unk4) { ... m_unk4 = K; r = 1; goto loop; }`) so CSE cannot thread the r = 1 paths; the busy test through an inline `bool IsBusy() { return m_busy; }` on a u16 bitfield (bit 7 of m_unk0); `return Func235DE0(...)` for the sibcall. What differs: retail puts the then-block of the `case -0xBA` test (`p->m_unk54 == 3`) before the test (backward `beql`, reached from case -0xAA by `b`), ours after it, and r lands in a1.
- **CMenuMgr 0x1B55A0** (glyph cell lookup): its jump table and message sit in CLayoutRes's .rodata (next unit). **CMenuMgr 0x1B3DD0** (~CMenuMgr, slot 20): key method, and slot 0 of _vt$8CMenuMgr is a library inline (0x29BD90). **CMapResObj 0x12D5A0**: key method, vtable data shared with IMapResMgr (`# also`). **CChrSchoolWin 0x186E90** (key method `Vf0() { Vf1(); }`): the unit's .rodata holds CMenuExam's strings, so not converted. **CGameSchedule 0x159850 / 0x159A10** (ctor/dtor): TList/CList/CListTag vtables would come out as linkonce copies.
- **CMapSndObj 0x128238** (sound id parser): DIFF 44, callee-saved register assignment only; "SE_STEP_CONCRE", ",", " \t", ":" must be literals of this function (the compiler then emits the jump table after them).
- **CEventMesRes 0x13E3D0** (CEventMesMgr slot 7, message expander): control flow right, 158 vs 165 insns; retail keeps the char as u8 and sign-extends at each test.
- **CPhotoEventObj 0x16CF98** (ctor): four pointer-to-member conversions into the CEventObj callback slots; needs CEventObj's class and ctor (0x132270) declared in that unit.
- **CLayoutObj 0x1BCFB0** (text control codes, jump table): DIFF 7, only `@w/@h`: retail keeps `c ^ 'h'` in v1 and `i` in a0, ours reuses v1.
- **Not attempted (size or shape)**: CGameSchedule 0x15A158 (3234 insns), CMiniGame5Res 0x1DF730 (3330) and 0x1E2B38, CDemoMain::Update, CEndingMain::Update, CGameResort::Update, CGameSeasonPost::Update and the CEventObj command handlers (state machines as above), CEFontWork 0x10BFD0, CFlagWork GS-packet builders 0x1098A8/0x109C30/0x10A000/0x10A3E8, CMapDBExpr 0x173160 (stack spills), CMenuMgr 0x1B4820 (spills), the CLayoutObj and CMenuMgr float draw routines.
- Solved this round from older entries: 0x109108, 0x109248, 0x108E10/0x108E38 (CFlagWork), 0x159790 (CGameSeasonPost), 0x1B7188 and 0x1B6570 (CMenuMgr), 0x1AE3F8 (CMenuSysscr01), 0x10E8D0 (CFaceRes), 0x16D2D8 (CPhotoEventObj), CDemoMain ctor, 0x135A28/0x132D30/0x132F40/0x1355E0/0x135BE0/0x1385E8/0x13C0F8 (CEventObj), 0x1BBD78/0x1BBDB0 (CLayoutObj), 0x15E2A8 (CGameSchedule): most by `-Wa,-g` (no assembler delay-slot reordering, docs/compiler.md).
|- **CEventObj 0x135690** (Start: sets the five script slots' callbacks from the PMF constants D_002D5670.. as `extern const`): DIFF 82, only the temp registers of the PMF copies through the stack (`ldl/sdl` via sp); tried an inline setter with a by-value PMF, a local temp, direct assignment. **CEventObj 0x1327F8** (~CEventObj): key method; CEventObj's vtable is still asm.

## r6
Lane r6 (Unit230578, Unit232B78: CD/host file layer, ISO9660 lookup, sector cache, worker-thread request queues). 104 of the 115 listed functions matched; the 11 left:
- 0x231268 (Unit230578, 162 insns, cached sector read into an unaligned buffer): DIFF 11. Best: `s32 done = 0, r = 1; mis = buf & 0x3F; skip = off & 0x7FF; abuf = (buf + 0x3F) & ~0x3F; soff = off & ~0x7FF; left = size - (-mis & 0x3F); D_002B8C6C |= 2;` (that statement order, from bk perm), `if (mis > 0 || skip > 0) { if ((buf & 3) || (skip & 3)) for (j = skip; ...) bytes; else for (j = skip; ...) words; skip = 0; } else done = n;`, then a second part with `j = skip` and the same byte/word split. Left: the byte loop's entry test uses `j` (ours) vs `skip` (retail `slt $2,$20,$16`), and in the second part `buf + done` / `j` take a2/a1 where retail has $5/$6.
- 0x2315B0 (Unit230578, 144 insns, CD read with init and error switch): DIFF 14. Both `sceCdGetError` switches need full bodies `case 0x11: case 0x12: case 0x31: reset; default: err; case 0: ...` so the two copies cross-jump, the loop exits `goto reset`, and the second switch carries `reset:`/`err:` labels inside its bodies. Only `if (D_002B8C9C) Func235DE0(D_002E4950);` differs: ours fills the branch from the target (`beqzl` + `addiu`), retail from the fallthrough (`beqz` + `lui`). Tried `!= 0`, braces, goto skip, a volatile read.
- 0x2318B8 (Unit230578, 80 insns, path table lookup): DIFF ~50. Retail hoists the constants 1 and -2 of the two `while ((r = func_00231E48(&v, 0x808C, 4)) != 1) if (r == -2) return r;` loops into s-registers and recomputes `&v` (sp+0x100) in each loop; ours hoists the address and keeps the constants inside. Tried while/for/do forms, an array, a struct for the two words. The same macro matched in 0x2319F8 and 0x231BC8.
- 0x231E48 (Unit230578, 138 insns, sector cache read with LRU list): not close (DIFF 100+). Retail: search loop with an out-of-line found block, retry loop as a `switch` on func_002314F0's result (cases -1, 1, -2), unlink/relink into the list head, then the byte copy; `(s64)sec << 11` goes through a copy ($17). A goto-structured version spills to the stack.
- 0x232840 (Unit230578, 42 insns, FS slot table init): DIFF 11, register numbering only: the `lbu` of D_002E49F8[0] lands in v1 and the inner counter in a1, retail has $4 and $3. Tried a local `char c` in several places, `__builtin_memcpy(.., 1)`, `strcpy(.., "")`, down-counting and pointer-bounded inner loops, array indexing.
- 0x232C60 (Unit232B78, 76 insns, chdir path walk): DIFF 2 instructions (73 vs 75). Everything else matches; retail leaves the `if (*path)` guard's delay slot empty and puts `daddu $5,$18` plus an alignment nop before the loop label, ours moves the `a1` copy into the guard's slot. Tried while vs do-while, `while (--n > 0)` vs for, `cwd[0] = comp[0]`, explicit strcpy for strcat.
- 0x2333C0 (Unit232B78, 60 insns, start a worker thread): DIFF 3: retail computes `prio + 1` into $5 (the dead incoming a1) before `li $3,-1`; ours uses v0 after. bk perm over the four header stores, a local `p`, `1 + prio`, `w->m0 = prio; w->m0++` all fail.
- 0x2334B0 (Unit232B78, 220 insns incl. the merged D_00233808 wrapper, worker thread loop): registers and blocks match with `loop: while (w->mC == 0) { fn = w->m4; ...; for (i, q) { while ((r = get(q)) && r->m0 == 1) pop(q); if (r) { ...; goto found; } } RestoreIntr; yield(); } w->mC = -1; for (;;) yield(); found: ...; goto loop;`. Left: our loop top gets an alignment nop and the bottom `beqz mC` is filled from the fallthrough (`li -1`); retail fills it from the target (`beql` + `lw m4`) with no nop. bk test can't check the function with D_00233808 (two symbols in one section), so the count is 213 + 6.
- 0x233CC0 (Unit232B78, 26 insns, port -> clamp -> table read): DIFF 17-20. Retail copies the `a == -1 ? f() : a` result $2 -> $4, then clamps into a third register $3; ours merges two of them (same family as r4's pad-id clamps in Unit22BFD0). Tried inline PortOf/Clamp3 combos, explicit x/y/j locals.
- 0x233D28, 0x233D40 (Unit232B78, 6 insns each, `D_002B8CD8[a] = v;` / `return D_002B8CD8[a];`): the C is trivial but retail has the last instruction of the `sw $5,D($4)` / `lw $2,D($4)` macro expansion in the `jr` delay slot; our GNU as 2.10 never moves a macro instruction into the slot (`-Wa,-O0..-O3` tried), so it emits `jr; nop`. Needs a different assembler or an asm body.
## r5
Lane r5 (goal 6b): Unit234318..Unit245450 (IOP/ini setup, file and debug console wrappers, DMA packet
builder and chains, GS display, texture and VRAM managers, font, sound stream). Not tried: the
switch-table functions (their jump tables would land in the asm .rodata) and the large (>100 insn)
functions listed in r5.tsv.
- 0x234F40 Unit234318 (70 insns, ini section finder): the `[name]` compare loop; retail loads `*p` with lbu+sign-extend and keeps `i` compare rotated (`beql` to `i++`); best `for (i = 0; i < n; i++) if (*p++ != sec[i]) break;` is one insn short (DIFF 1039).
- 0x235058 Unit234318 (49, ini key copy up to '='): retail loop is not rotated and lays out [increment][test][body]; `while (*src && !IsEol(*src))` (inline IsEol blocks the test copy) gets the jump-to-test shape but puts the body first (DIFF 1041); for(;;)/goto variants worse.
- 0x236E48 Unit236130 (35, debug console putc): DIFF 3, retail keeps `(u8)c` in $5, ours in $4; with `u32 color = D_379AA0 & 0xFFFFFF;` temp everything else matches.
- 0x237398 Unit236130 (17, packet word copy): ours 19 insns, extra moves around the count-down copy loop.
- 0x2375D8 Unit236130 (42, DMA cnt tag close): ours 39-41 insns; `n += (p - body + 15) / 16` and the qwc/id bitfield stores right, schedule differs (perm 7 lines no match).
- 0x237680 Unit236130 (39, DMA next tag): DIFF 1, `addu $3, n, t` operand order (ours t, n) in `D_37BDB0 = t + n`.
- 0x237860 Unit236130 (38, DMA ref tag): DIFF 8, n/addr callee-saved registers swapped ($17/$16).
- 0x2379D0 Unit236130 (45, DMA call tag): size mismatch, same tag-store schedule issue as 0x2375D8.
- 0x2365C8 Unit236130 (136, exception handler dump): DIFF 7, retail fills the `beqz` slot after the first register-table test with `daddu $19,$3`, ours hoists `lui %hi(D_002E5170)` there; the rest matches.
- 0x238BA0 Unit237A88 (36, copy n qword pairs into the packet as 32-bit halves): DIFF 8 with `for (i = 0; i < n; i++)` over a copy of p; the hi/lo halves' registers and store order differ between the two halves of each iteration.
- 0x239568 Unit237A88 (13, IPU/VIF FIFO write): DIFF 2 with `u32 b = 0x1000D000; if (ch != 8) b = 0x1000D400; *(u32 *)(b + 0x80) = v;` (the two `lui` swapped); a pointer ?: folds +0x80 into both constants.
- 0x239BD8, 0x23A0F8 Unit237A88 (49 / 56, build a packet in a stack buffer and kick DMA): retail keeps the stack buffer address (`daddu $17, $29, $0`; 0x23A0F8 also sp+0x400 for the PktSave) in a callee-saved register from the prologue; ours rematerialises `move a0, sp` at the call, so one saved register (8 bytes of frame) short. A `DmaTag *pk = (DmaTag *)buf;` local is folded away.
- 0x23A3E8 Unit23A1D8 (50, list-node pool init): ours 46 insns; the 2-iteration middle loop and the final append loop are laid out/strength-reduced differently.
- 0x23AA80 Unit23A1D8 (50, swap a texture handle under lock): ours 48 insns.
- 0x23AC10 Unit23A1D8 (22, copy with tolower, max n): best `for (i = 0; i < n; i++) { c = *s++; if (!c) break; *d++ = TOLOWER(c); }` DIFF 20; retail enters a `bnez c` test with `s++` in its slot.
- 0x23AF48 Unit23A1D8 (27, take a free texture slot): DIFF 20-24; retail recomputes each `D_37CDE0[...]` address from `lui 0x38` (no shared base) and returns `r + 8` through a branch, ours shares the base and uses movn.
- 0x23C048 Unit23A1D8 (43, CLUT swizzle copy): DIFF 1, retail computes the `(i & 0x10) >> 1` term with `dsrl $4, $7, 1; andi 8`, ours `sra` (tried u32/u64 casts, /2, >>4&1<<3).
- 0x23C1E0, 0x23C298 Unit23A1D8 (45 / 42, 16/24-bit to 32-bit colour loops): DIFF 18 / 11, callee-saved register assignment differs (retail gives r,g,b $16-$18 and count/dst/src $19-$21).
- 0x23C0F8 Unit23A1D8 (40): ours 37 insns; the 512-word clear loop and the `(n + 31) / 32 * 2` argument schedule differently.
- 0x23C698 Unit23C680 (11, GS reg 15-bit field from f ? 0xF0 : 0x90 >> 4): retail sra then andi 0x7FFF into a u64 field; ours folds or uses dsrl (bitfield, manual mask, /16 tried).
- 0x23E328 Unit23C680 (68, VRAM range setup): ours 66; clamps written as ifs, schedule/branch shape differ.
- 0x23E438, 0x23E510, 0x23E620, 0x23E690 Unit23C680 (54/52/27/35, VRAM free-list insert/alloc/find): best versions DIFF 29 / size off; retail re-reads `l[p].next` through the pointer after each store and keeps the loop exit tests in a different order.
- 0x23E720 Unit23C680 (17): DIFF 1, `addu $2, idx*4, l` operand order (ours l first; &l[i], l + i, i[l] tried).
- 0x23E788 Unit23C680 (22): ours copies both l and i into new registers (retail only l); 23 vs 22 insns.
- 0x23E7E8 Unit23C680 (32, vsync handler with sync/ei): ours 29-30; retail computes &D_002B9CD0 into $16 before the call and stores the compare constant 1 in the else path.
- 0x244860 Unit243AB8 (30, wait loop with a volatile busy flag): retail's assembler did not move the volatile `sw` into the `b`/`jal` delay slots (retail gas honoured `.set volatile`; ours prints it as a comment). With an `asm volatile(".set noreorder\n.set reorder")` barrier after the store, GCC then fills the `b` slot with the hoisted `lui` instead (DIFF 1019).
- 0x245398 Unit243AB8 (10): retail leaves the `beqz` slot empty (nop) with the `la` of D_38F088 before it; ours fills it with the final `addu`.
- 0x245230 Unit243AB8 (24, ring offset): DIFF 8, register numbering of the `(D_38F07C + 3) % 4` and the two mults.
- 0x23F458 Unit23E868 (20, alloc + memset): ours 21, n/p callee-saved registers swapped and an extra move.
- 0x23FCB8 Unit23E868 (40): DIFF 6, retail loads `c->m14` with `lh` before `andi 1` (ours `lhu`), and precomputes p+16 before the first `sw`.
- 0x23F770 Unit23E868 (54, font table reset): DIFF 12, only the order/registers of the ten trailing global stores differ (perm hill-climb found nothing from 174 orders).
- 0x240D68, 0x240DF0 Unit23E868 (34 / 33): retail calls func_0023AA40 / func_0023BD80 with `jal` (no sibcall) behind a `$2 = 0` preset and sibcalls func_0023F1B0; our early-return and single-exit versions are 3-4 insns longer.
- 0x23F8E0 Unit23E868 (94, font list flush + packet close): DIFF 1 with the loop as `for (e = head->m4; e != head && (e->mC & 1); e = e->m4)`; the `mC & 2` test is `bnez` with the `and ~1` in its slot in retail, `bnezl` in ours (3 variants).
- 0x244040 Unit243AB8 (77, feed a sound channel from its ring): DIFF 6, the callee-table load for D_002B9DE8[t] is scheduled after p + m2C in ours (ternary, if and &p[] forms tried).
- 0x244DE0 Unit243AB8 (51, open a sound stream): DIFF 2, the three trailing zero stores (D_002B9D98/D94/DBC) get registers in a different order whatever the statement order and the callee return type.
- 0x23B948 Unit23A1D8 (49): ours 50; the two `(t >> 38) & 0xFFF` / `(t >> 50) & 0xFFF` extractions share a `li 0xFFF` register in ours, retail uses two `andi` (bitfield union tried).
- 0x23BC28 Unit23A1D8 (35, follow a texture chain n-1 steps under lock): retail copies n into $16 then decrements it separately and keeps k in $17; ours folds `n - 1` and swaps the two saved registers.
- 0x240ED8 Unit23E868 (62, glyph binary search): ours 61; retail leaves the first `beqz e` slot empty and tests `code < g[mid]` with a likely branch to `hi = mid` (nested-if, goto and if/else-swapped versions tried).
- 0x23D1B0 Unit23C680 (74, VRAM table init): ours 72; retail walks the append loop through pointers to `t[0x1003].m2` and `&t->m4` (p*6 + t+4) and orders the eight head/tail stores differently.
- 0x23A1D8 Unit23A1D8 (51, upload a texture rectangle): ours 52; the two `& 0x3F` field extractions from the u64 handle share a `li 63` register in ours, retail uses two `andi` (shift/mask and bitfield-union forms tried; same issue as 0x23B948).
- CGameSeasonPrev 0x1582C8 DrawSeasonImage (225 insns): structure matches (best C: docs/hard/g4/hard_1582C8.snip, u64 tex from vslot 5, clut slot 6, `s32 ofs = 8; s32 w = 0x280;` before the loop so `(w<<4)+ofs` stays unfolded, loop-invariant TEX0 hoisted). Remaining: register allocation. Target keeps the raw tex ($17) and masked tex ($22) in separate pseudos but still computes TBP from the masked one; one variable gives the wrong s-reg order, two variables let combine fold `(tex0 & ~M) & 0x3FFF` into `tex0 & 0x3FFF`. DIFF ~1090.
- CChrBodyWin.cpp 0x187A68 Func187A68 (ChrTypeImg name, 191 insns): structure and branches match (best C: docs/hard/g4/hard_187A68.snip; returns int, `f = GetFlag187680(...)` reuses the parameter in the type-6 branch). Remaining: `this` and `f` swap s1/s2. DIFF 1130.
- CGameMain 0x151120 Func151120(slot, name, delta, useSaved, e) (172 insns): logic and layout right (best C: docs/hard/g4/hard_151120.snip; needs IGameDBMgr slot 24 as `Func14DB70(f32 *out, s32 id)` and CGameMainFlagDef fields m4/m18/m1C/m20). Retail reloads `rec->m0` in the else branch; ours reuses the loop-test value (gcse), which shifts the s-registers. A `base = rec->m0` local gets to DIFF 91 but costs an s-reg.
- CGameMain 0x151A78 (single-event picker, 214 insns): best C docs/hard/g4/hard_151A78.snip (goto loop for the "all married" scan, CGameRand at this+0x144). Remaining: retail keeps `blez n` before the "first single event" loop (ours drops it), the two event prints share one Func235DE0 call, and the s-registers differ. DIFF ~1135.
- CCharaObj 0x117B48 Func117B48 (VU0 matrix apply, 149 insns): DIFF 12, docs/hard/g4/hard_117B48.snip (VU_* macros as in 0x117898, VuApply with `register ... asm("$7")`/`asm("$5")` operands). Left: the resource entry pointer gets a0 (ours `beqz`) instead of v0 (`beql`), and the default `&D_002A05C0` goes through a3 instead of v0.
- CCharaObj 0x117668 Func117668(s32) (VU0 model matrix, 140 insns): DIFF 5, docs/hard/g4/hard_117668.snip. Retail recomputes `&out` (`addiu $6, $29, 0x40`) for the call after the VU store; ours reuses $2 from the store's register variable. A tied output or a "$2" clobber makes it worse (a pseudo copy).
- **Blocked key methods / vtable-data units (g4's units)**: dtors of the CMapEffObjRes work classes
  0x11D670 (CMapEffCurtainWork), 0x11F038 (Leaf), 0x120AC8 (Fly), 0x121788 (Rain), 0x1225F0 (Snow) and
  `_$_10CMapEffObj`: merged unit CMapEffObjRes/CMapEffObj, can't go to level 3. IEnvResMgr 0x12DC48
  (CEnvResMgr dtor, merged unit). CMapAttr 0x118248 (dtor; the unit would also emit the TArray template
  vtables). CMiniGame1Res `_$_10CMiniGame1` and 0x1BD700 (CMiniGame1Res slot 1 = key method, its dtor is
  the inline 0x29C5E0): the vt piece holds both classes' vtables. CTexCacheMgr 0x10CEE8 (ctor with the
  inline TList member; CList/CTexCacheMgr merged unit). CChrBodyWin 0x187038 (CChrBodyWin ctor: the file's
  `CChrBodyWin` class is really two classes; the real one derives from CStatusBase (vptr 0x58, 7 pure
  virtuals) whose ctor is func_0019A830; needs that split first). (CGameMain 0x150C30 is
  solved: unit converted to level 3.)
- CCharaObj 0x116AE0 Func116AE0 (per-frame update with the VU0 frac asm, 45 insns): DIFF 4, docs/hard/g4/hard_116AE0.snip.
  VuFrac asm (vftoi0/vitof0 with an internal `bgez`, no explicit nop: gas fills the slot) matches; left: `m_unk138 - 1`
  lands in v1 (retail $2) and the two pointer args of func_00270A30 are computed in the other order.
- CCharaObj 0x1146A8 Func1146A8(f32 target, s32 n, s32 dir) (rotation step setup, 95 insns): logic known
  (docs/hard/g4/hard_1146A8.snip, `if (n > 0) {...} else {...}` gives the blezl entry); left: block layout and
  branch senses of the dir<0 / dir>0 / dir==0 cases (retail shares one `X / (f32)n` tail between the (1-d),
  (d+1), (d-1) cases and converts n before each compare) and the first VuFrac result lands in f2 (ours f12).
- CCharaObj 0x1156A8 Func1156A8(f32 target, s32 turn, s32 n, s32 k, f32 a, f32 b) (turn start, 97 insns): logic known
  (docs/hard/g4/hard_1156A8.snip, same delta wrap as 0x1146A8: `[-0.5,0.5) -> d, >0 -> d-1, else d+1`); left: FP
  registers (retail loads m_unkC4 into f0 and copies it to f1 for the second VuFrac, outputs land in f2/f1) and the
  order of the `-1` / `1.0f` constants in the n == 0 path.
- CMapEffObjRes 0x120B38 (CMapEffFlyWork::Func120B38, move + wrap of 16 flies, 95 insns): DIFF 20,
  docs/hard/g4/hard_120B38.snip (needs a CMapEffFlyWork class; none exists in the file yet). Retail's frame is
  0x60 (0x30 of locals, so two unused CVec4-sized slots, probably from inline helpers) against our 0x40, and the
  VuFrac outputs alternate f0/f1 differently. Inline helpers with a local CVec4 give 0x50 and more instructions.
- CPhotoDBMgr 0x171510 Func171510 (photo info lookup, 202 insns): docs/hard/g4/hard_171510.snip matches up to the
  vector copy (StrCat inline, m20/m4C store order). Left: retail addresses `f->m10[idx]` as `(f + idx*16) + 0x10`
  and copies the pointer through four registers (nested inline helpers?), the else-branch store order, and the
  argument order of the last func_00171C08 call. DIFF ~1060.
- CCharaObj 0x116D60 (VU0 model matrix build: mat, trans, rotY/X/Z, scale, 227 insns): DIFF 16,
  docs/hard/g4/hard_116D60.snip (switch on mode for the extra scale, `cur = rot[1]` read before the VuFracs).
  Left: FP registers in the delta wrap (`rot[1]` and the second VuFrac result in f0 instead of f1) and one
  alignment nop before the second wrap block.
- CCharaObj 0x115470 Func115470 (path move setup: copy points, segment lengths with VuSqrt, normalised
  cumulative times, 141 insns): docs/hard/g4/hard_115470.snip (fields m_path[9] 0x1D0, m_pathT[9] 0x260, m_pathN
  0x284 added). Left: retail shares the `m_unk294 = -1` store between the frames == 0 path and the anim < 0 path
  (cross-jump), and the loop counters/pointers get different s-registers. DIFF ~1109.
- CMapEffObj 0x126E98 (FindPortal: n-th type-6 entry of the effect list, copies two vectors, 102 insns):
  docs/hard/g4/hard_126E98.snip (goto loop gets the block layout). Left: retail hoists `&D_002A0B00` into an
  s-register (loop.c ran) but not the constant 6; the goto loop hoists nothing, the for loop hoists both. DIFF ~1070.
- CList unit: 0x10D028 (CTexCacheMgr init: `new CCacheInfo[n]` whose inline ctor stores `_vt$10CCacheInfo` and links
  list nodes) and 0x10D4F0 (TList iteration with the inline CListTag code) would emit linkonce vtables/template code
  from this merged level-1 unit; 0x10D360 needs a jump table (level 1). Not tried further.
- CMapEffObjRes 0x11D6E0 (CMapEffCurtainWork::Func11D6E0, 14x14 curtain grid reset, 121 insns):
  docs/hard/g4/hard_11D6E0.snip (CMapEffCurtainPt layout added; `w = 30.0f/13.0f; h = w;` reproduces the two
  constant registers). Left: loop.c's induction variables (retail keeps separate givs for row 0, row 13 and the
  current point) and the int->float conversion of i duplicated into both arms of the `j == 0` test. DIFF ~1106.
- CMenuSysscr11 0x1AB748 Update (state.h menu loop, 152 insns): DIFF 26 with the goto-loop recipe,
  docs/hard/g4/hard_1AB748.snip (class now has the m_kanji/m_win union like CMenuNosave). Left, as in g1's
  CMenuNosave: `done` lives in a1 instead of a0, the init-failure and wait-B "then" paths do not share retail's
  `li -0xBF` tail, and the wait-B then-block sits after the test. Same family: CMenuSysscr22 0x1AB338,
  CMenuSysscr06 0x1AC8E8, CMenuAsksavequit 0x192DD8, CMenuNews 0x173B08, CMenuPTJobMoney 0x18E848,
  CMenuTutorSelect 0x17E060, CMenuChildStatus 0x18A548 (not attempted after this one).
- CBootMain 0x100358 Update (state.h wait loop with the stack push/pop asserts, 139 insns): docs/hard/g4/hard_100358.snip
  models the inline helpers (lines 0x44 push, 0x46 pop, 0x48 set top, 0x4C get top). DIFF ~1112: `done` should be
  in v1, the two "wait" yields share retail's `sw $2, 4(sm); li 1; b loop` tail (ours keeps -0x3F in an s-register).
- CMapEffObjRes 0x126C48 (CMapEffSwingWork::Func126C48, swing model draw, 116 insns): DIFF 2,
  docs/hard/g4/hard_126C48.snip (VU macros; the matrix store as `move $2, %0` asm with a "$2" clobber; the
  register-variable form gives DIFF 10 here). Left: `c * 4` for the D_002A0970 index lands in a0 (retail v0).
- CMapEffObjRes 0x124888 (CMapEffAquariumWork fish draw, 134 insns): DIFF 2, docs/hard/g4/hard_124888.snip (fields
  m_pos/m_rot/m_col/m_scale added to CMapEffAquaObj). Left, as in 0x126C48: a pointer that retail computes in v0
  goes to a0. Both forms of the matrix-store asm (a `$2` register variable, or `move $2, %0` with a "$2" clobber)
  keep GCC off v0 elsewhere in the function; retail's macro does not. Finding that form would likely fix
  0x126C48, 0x124888 and 0x117668 together.
- CCharaObj 0x113978 Func113978(a, b) (swing bone setup with three LCG ranges, 146 insns): DIFF 11,
  docs/hard/g4/hard_113978.snip (CCharaRand with seed-1 ctor; seeds from `m_res` and GetSndWorkRealInstance()).
  Left: FP registers of the first Range (retail adds the 0.0 lo into f20 from f0/f1) and the last LCG's
  temporaries (retail keeps the multiplier in s0 and uses a1/a2).
- CCharaObj 0x113C38 (diff-motion setup, 150 insns): same template as 0x113978 (ReleaseDiff, `new CDiffMotionObj`,
  func_0010FB30, the same three LCG ranges, GetFrame); expected to stop at the same FP-register difference. Not written.
- CCharaObj 0x114958 Func114958(CVec4 *v, s32 n) (rotation step per axis, 186 insns): DIFF 47,
  docs/hard/g4/hard_114958.snip (`AngDiff(a, b)` inline so both operands load before the first VuFrac asm,
  u128 copies for the lq/sq struct moves). Left: FP registers (retail's first VuFrac result in f2 and the delta in
  f1; ours f0/f3), the same family as 0x1146A8 / 0x1156A8 / 0x116D60. A VuFrac form that reproduces retail's
  FP choices would probably fix all four.
- **Not attempted yet (large; notes for the next pass).** VU0 macro-mode draws (use the FtoI15 / VuFrac /
  VuSqrt / VU_* inline asms now in CMapEffObjRes.cpp and CCharaObj.cpp): CMapEffObjRes 0x121E28 (rain draw, 152),
  0x11FE88 / 0x120298 (leaf draws, 260/330), 0x11E5E8 (482), 0x120CB8 (574), 0x122DD8 (snow, 472), 0x124AA0
  (aquarium, 588), 0x126170 (296), 0x124160 (aquarium update with CirclePos, 160), 0x11D8C8 (curtain update with
  9 VuSqrt, 574), 0x11F9C0 (leaf update, 280); CCharaObj 0x113418 (VU matrix loop over bones, 118), 0x1141F0
  (288), 0x115E48 (776, 22 VuFracs and Ease115C28). GS packet code: CMapEffObjRes 0x122088 (238), 0x11E1C0
  (curtain mesh, 226). Constructors of the work classes, which first need the classes declared as
  CMapEffWork subclasses (their vptr is at 0; CMapEffLeafWork is still declared without it): 0x11ED80 (leaf,
  174), 0x1207C0 (fly, 194), 0x11D2D8 (curtain, 230). CMapEffObjRes 0x125410 (grid, 330). CCharaObj 0x113128
  (init: vector constants copied with lq/sq plus an LCG, 144) and 0x114EA0 (face blink, 246). CPhotoDBMgr
  0x170E18 (Parse170E18, 238: eight pointer induction variables spilled to the stack). Menus and screens:
  CMenuPTJobMoney Draw 0x18EE78 (370), CMenuTutorSelect Draw 0x17F6C8 (408) and Update 0x17E060 (1434), CLogoMain
  Update 0x100770 (434), CMenuAsksavequit 0x193358 (644), CChrBodyWin.cpp 0x1895F8 (766, CMenuChildStatus event
  switch), CGameSeasonPrev 0x156E80 (398), 0x156120 (462), Draw 0x1587A8 (494), Update 0x153710 (2698), CGameMain
  Update 0x152090 (1146), CMiniGame1 Draw 0x1C3960 (488) and Update 0x1BDBE8 (5982).
## d2
dklib units Dk252208..Dk25E340 are level 1 (no per-unit .rodata/vtable piece; their literals live in ro_tail), so
functions with a compiled switch jump table (jtbl_) and key methods cannot be matched until the
data is split.
- Dk252208 switch (jump table, needs .rodata): 0x2539A0 (pixel mode -> bits), 0x253B00, 0x254730.
- Dk252208 key methods (unit not convertible): 0x252B58 `_$_11CBoneDupMap` (only slot), 0x253BE0 CShareTex slot 1,
  0x2541E8 `_$_7CMemTex`.
- 0x252C08 Func252C08 (find bone by name, 46 insns): ours 44. Retail returns `i` through a separate
  `b exit; move v0,i` block followed by an aligned label (barrier), ours folds it into `beqz v0,exit; move v0,s1`;
  also base/offset operand order of `D_002A5D0C + id*0x34`. Tried for/goto found/continue/inline FindName.
- 0x252CC0 Func252CC0 (bone pair table): down to DIFF 12, only `p` (out walker) and `j` swap $17/$18. Best C:
  `if (!ra || !(rb = &D_002A5D0C[b])) { Func235DE0(D_002E6B18, a, b); return 0; }` ... `if (out) { p->m_a = i;
  p->m_b = j; } p++; cnt++;` (inner `for (j...) if (!strcmp) break; if (j == lb->m_num) continue;`).
- 0x253358 Func253358 (BMP info header): DIFF 2, `bnel` where retail has `bne` at the two size tests
  (`if (bi->m_size == 0x28) {...} else if (== 0xC) {...} else { Func235DE0(fmt, bi->m_size); return 0; }`).
- 0x253530 / 0x2537E8 / 0x2538A0 (BMP palette/loader): retail puts the address-taken parameter's stack slot
  above the locals (allocated first: `sw a0,0x40(sp)` after fh at 0 and bi at 0x10) and rematerialises its
  address at each call; our compile allocates the slot last (sp+0) and, for a local copy, caches the address in an
  s-register. Code otherwise matches (2537E8 DIFF 5 with `CBmpInfo bi; CBmpFile fh;`).
- 0x2536C8 Func2536C8 (BMP pixels, bottom-up copy): DIFF 26, register allocation only (w/h/bpp in $7/$3/$4,
  ours v1/a0/a2).
- Dk254AA8 key methods: 0x2556A8 CFontTextRes::Load (slot 1), 0x255B20 CFontBankRes::Regist (slot 2; slots 0-1
  are inline), 0x255EE8 CFontVCodeRes::Load (slot 1).
- 0x2550E0 Func2550E0 (clip a segment to [lo,hi] in x, then swap x/y of both ends): 71 vs 72 insns; the second
  three-way if/else (`Func254FD0(o1, in, lo)` / `(o1, in, hi)` / `Func270C50(o1, &in[1])`) is cross-jumped
  differently (retail shares one `jal Func254FD0` after setting a1/f12 in each arm).
- 0x257DC8 Func257DC8 (AT3 node free-list init, `return Func258200();`): DIFF 16-18, retail keeps the full address
  of D_002BA1E4 in $2 (`lui; addiu; sw $0,0($2)` ... `sw $4,0($2)`) where ours uses %lo stores; tried `**fl`
  pointer, volatile alias, store order.
- 0x258110 Func258110 (unlink AT3 node by id, `Func259858(id, b)` with b passed through): DIFF 8, same full-address
  D_002BA1E4 ($18) plus s-register order.
- 0x258200 Func258200 (AT3 init + 0x801-entry Blackman-windowed sinc table at D_418780): DIFF ~1033. Retail divides
  by 2048 with `div.s` (GCC folds `/ 2048.0f` into a multiply; `f32 n = 2048.0f; ... / n` gives the div.s), PI is
  0x40490FDA (`3.1415926f`), the first scale is a multiply by 1/512. Remaining: FP register allocation
  (x and the window argument share $f20 in retail) and a 1-insn length difference.
- 0x257F40 Func257F40 (AT3 open: header lookup, then Func259340 (memory) or Func259600 (file) by
  func_0020E338 type, then push node): 119 vs 116 insns; retail keeps the second path buffer (sp+0x120) in the
  same s-register as the result `r` and uses one s-register less.
- 0x25A098 `__7CSndMgr` (ctor): DIFF 6. Members CSndWork x3 via explicit `func_0025C230(&m_w..)`; retail loads
  0x80 into $3 and -1 into $4 and stores 0x1C, 0x30, 0x24, 0x2C; ours swaps the two constant registers and the
  order of those four stores (bk perm over all 14 stores: no order fixes it).
- Dk25C438 unit-list finders 0x25C4B0, 0x25C510, 0x25C990 (`Func25C990__8CSndWorki`), 0x25C9F0, 0x25CA58: loop over
  the CSndWork unit list (`p = item(m2C); p; p = item(p->next)` with item(n) = n->m_head ? 0 : n, match on m14 == id
  && !m1D). Retail is 24-27 insns: the first item test is done with branches (`bnez; li 0; b; move`) and the
  loop has a pre-test; ours is 15-17 (movn + jump into the test). Tried guards, while/do, First inlines, break.
  0x25CDC0 (which calls them) matched.
- 0x25D1A0 CSndWork::Func25D1A0 (call unit slot 1 on each unit, next fetched before the call): DIFF 18, register
  allocation/scheduling only (`while (p) { u = p; p = item(p->next); u->Apply(prm); }`).
- 0x25CAC0, 0x25CEE8: same unit-list finder shape as 0x25C4B0 (see above).
- 0x25D008 Func25D008 (mark units for stop or delete them, via Func25C810): 48 vs 52 insns; retail keeps a separate
  iterator ($18), current ($16) and next ($17) and re-tests the pointer before `delete`; tried iterator variables.
- 0x260690 Func260690 (stream buffer setup: mode -> channels/rate/size, memset 0x68CA, sibcall func_00262B18):
  DIFF ~37 at best (`ch=2, md=0x12, n=0x60` defaults with `case 1/2/3/4/default` switch); retail's decision tree
  presets case-3 values before testing 3/4 and loads x->m_buf after the switch without keeping x.
- 0x25C098 func_0025C098 (CSndUnit base constructor, written as an extern "C" init function): DIFF 2, retail stores
  m0 = 0 before the vptr (0xC); ours stores the vptr first in every statement order (bk perm), also with an inline
  link-init helper. Remaining stores fixed with order `m54, m5C, m60, m58, m64`.
- 0x25F7B8 Func25F7B8 (CSndUnitStr init: BGM name lookup, stream info, manager defaults): DIFF 30, only the
  `p`/`a` registers are swapped ($17/$16) once `a` and `b` are reused as in retail (`a = GetId(a); if (0x10000 < b)
  { b = func_0020E698(a, name); ...}`); a member-function version gives the same.
- 0x25A738 CSndMgr::Func25A738 (find entry i or, for type-3 groups, its sub-entry by name): 61 vs 64 insns; retail
  orders the tests `m2C < 0`, `< 3` (strcmp), `== 3` (loop over `e[1].m_name`, which never advances: a bug in the
  original) with three separate return blocks; ours merges them.


## w1
- **0x21DD08, 0x21D9F8, 0x21DB80** (Unit21D820, GS TEX0/CLAMP register words built from func_0023AA40/func_0023BCB8 results, sce-style field macros): the repeated `& 0x3F` masks are `andi` twice in retail, ours loads 0x3F into a register (`li; and`), the r5 "same-mask DImode ANDs" problem; also s-register assignment of the four params differs.
- **0x21E370** (Unit21D820, cubic B-spline basis table D_33D9D0[3] (BzT: n, then 4 x {b0..b3, s, t, s, t})): math and stores match; retail recomputes `(f32)n` inside the inner loop and walks one pointer at the entry's last field (negative offsets), ours hoists the conversion and uses three bases.
- **0x21C588** (Unit21BEC0, init: func_0021BDD0(1,0) into D_33D6F4, error print if < 0, then func_0021BAC0 upload): DIFF 10, retail keeps the result in v0 and copies it to a1 before the `bgez`; ours copies it through v1 first. Tried int-returning print, single variable/global forms, if/else.
- **0x220278, 0x220318, 0x2200C8** (Unit21F250 GIF tags): retail computes `x = a | 0x45` once and then `x | 0x10` from it; GCC folds that into `a | 0x55` (DIFF 25/8). s64 locals and DImode forms made it worse.
- **0x10DD38 done; 0x172ED8** (CMapDBExpr digit check then atoi or func_0024DA00): DIFF 13+, retail tests the first char with `lb` then walks with `lbu` and a copied char register (`daddu $3,$2`), its fail path jumps into the result test with `v0 = 0` in the delay slot. Tried inline IsNum helpers (char/u8, for/while/do), a flag variable.
- **0x21B280** (Unit219970, quaternion to 4x4 matrix, `func_0021B280(void *m, Quat *q)`; the caller 0x21B4A8 now passes its a1 through as `q`): all arithmetic matches; the order of the nine non-constant stores and the constant block (0x30, 0x3C=1.0, 0x34, 0x38, 0xC, 0x1C, 0x2C) does not; hill-climb perm best DIFF 13.
- **0x21BCF8** (Unit219970, draw a group's items: `GItem *it = D_002B6818[a].rest + b*128`, count `D_002B6818[a].b[b]`, loop func_0021B8E8(it->p, it->y, it->x), then `Func238158(func_002377D8(), 1)`): retail's count-down loop tests `bnel n, 0`; ours `bgtzl`, and the early-exit shape differs (both `return 0` paths share `ld s0` in retail). Tried for/index/pointer and if/return forms.
- **0x21AA78** (Unit219970, sine table D_002A6800[0x4000] = sinf((f32)(i/16384.f * 2.0 * PI)) through soft-double dpadd/dpmul, then the four exact values): retail reloads the double PI (D_002E3BF8) with an `ld` macro inside the loop each iteration (a compiler literal); with the unit's .rodata in asm ours hoists it to an s-register. Needs the unit converted so the literal can be a real `3.14159...` constant.
- **0x21ACD8** (Unit219970, table atan2 to 0..0x3FFF, now `func_0021ACD8(f32 a, f32 b)`, caller 0x21ACA8 passes its floats): one insn long: retail takes `&D_33A5A8` into a register (lui/addiu) on the |a|<|b| path, `bc1f` (not likely) with the `lui` in the slot, and `li 0x1000` inside the else path. Tried pointer locals, split subtraction.
- **0x22FA70** (Unit22DE48, return a file's block list (DL ring at FEnt+0xB4) to the free list D_3401E0.m4E08 between DisableIntr/RestoreIntr): best DIFF 23 with `if (n != h) do {...} while (n != h)`; retail stores the loaded `next` into `prev->next` (no reload), keeps `h` in a second register ($9) and has an alignment nop before the loop; the forms that do that change the size.
- **0x22FED0** (Unit22DE48, `if (a == -1) a = func_00234938(); if (f = func_00230460(a)) f->f[8]();`): one insn short: retail copies the returned FsOps* to $3 before the `beqz` (as in the early-return getters), ours tests $2. Its twin 0x22FE80 (f[7](b)) matches.
- **0x10CDD0 / 0x10CE40** (CEFontWork, clamp a and b to [-128,128] then `(a * (b > 0 ? 128 - b : 128)) >> 7` / `b < 0 ? b + 128`): retail evaluates all four range compares (`slti -0x80`, `slti 0x81`) before the first branch, with the values copied through two registers; plain nested ternaries give the right compares but branchy order (DIFF 25), inline clamp helpers get `li 128; slt`.
- **0x1091B0** (CFlagWork::Func1091B0, read a flag value: bounds check, `memcpy(&v, m_data + d->m_off, d->m_size)`, sign-extend by `(4 - size) * 8`): DIFF 17, register choice only: retail copies `this` to a2 and keeps `id` in a1; ours copies both. Tried early returns, nested if, goto.
- **0x1447A8** (CCurFlag ctor: CFlagWork(0,-1) base, `D_002A26E4 = this`, Func108448(this, D_002A1D40, -1), then the print as a tail `j`): DIFF 2, only where the `lui %hi(D_002A26E4)` is scheduled (retail before the call setup, store in the jal delay slot).
- **0x1B4418** (CMenuMgr::Start1B4418: id < 0x2B check with print, m64/m68, `m_proc = D_002A5470[id](this, id)`, SetUnk50(arg), print): DIFF 2, prologue order of `move s0,a0` vs the `sll` of id.
- **0x19CCF8** (CStatusBase, `k = base + round(n * Clamp01(t))`, changed flag `*cur != k`, `*cur = k`, `*out` clamped 0..9 with movn/movz): two insns long; retail copies a0/a1 to t1/t0 first (inline-function parameters?) and if-converts the final clamp.
- **0x22D8C0** (Unit22BFD0, `D_33FE90[clamp(v & 0xFF, 0, 1)][clamp((v >> 8) & 0xFF, 0, 3)].m17`): same family as CEFontWork 0x10CDD0: retail computes both range compares of each clamp before the first branch (DIFF 25 with nested ternaries).
- **0x13DFF8** (CEventMesMgr::Remove: unlink n, or with n == 0 unlink every item `EvCheck(m_head.m_next)`): retail re-tests `n` after each unlink (`bnez n, loop`), so the loop is laid out with the test at the bottom; GCC drops the redundant test (size -5). Tried do/while, goto, while forms.
- **0x22D7E0** (Unit22BFD0, pad slot setup `D_33FE90[port][slot].mE = func_002359E8() * a; .m10 = func_002359E8() * b` with the same clamps as 0x22D8C0): same compare-hoisting problem.
- **0x2410D8 / 0x241238** (Unit240FD8, decode an SJIS/ASCII string into glyph pointers via the font's m34/m38 table and the GlyphGet binary search inline that matched 0x240FD8): DIFF 8, register allocation only (retail keeps `out` in a separate register $13 and the count in a0).
- **0x1EE200** (Unit1EE008, rxMc file check: open, size via seek end, read the 8-byte "!crc" header, func_001EE150/func_001EE1D0 verify, close; returns size or -0x65/-0x66): retail keeps fd and size in two registers each (five saved regs, frame 0x40) and reuses the fd register for the constant 8; first draft is far (register/frame).
- **0x1121F0** (CCharaRes::Init1121F0, ~26 field resets and two memsets): hill-climb perm best DIFF 2: retail emits the m_unk80 (-1) store where ours puts m_unk98 (0x50) (constants in t0/a3 swapped).
- **0x173578** (CMapDBMgr::Load173578: load D_002DA298, count with Parse173648(buf, 0), allocate from m_buf, parse again, qsort, free, print): DIFF 1016 (size): retail keeps a second `if (buf)` test before the free; GCC drops it (tried an inline FreeIf and a separate `if (buf)` after the block).
- **0x1B6158** (CMenuMgrSub1B6418::Func1B6158(i): load menu texture D_002A5540[i] into m_items[i], func_00253048 the 8 info words, print): retail precomputes i*36, keeps 4 saved regs (frame 0x40) and cross-jumps the two fail prints; first drafts with an item pointer or direct m_items[i] are ~60 insns off in allocation.
- **0x16D660** (CAlbumMgr::Init16D660: Term, allocate the 0xDF200-byte album buffer from D_002A0BE8 with a size warning, scene setup, CNameDBMgr::Create(1)): DIFF 2, only the delay-slot choice between `sw m_buf` and the copy of 0xDF200 before the `beqz`. (InitB takes one int, SetSnd returns a value.)
- **0x23CF18** (Unit23C680 log printf: vsprintf through the EE va_start macro (that part now matches), then console print and file append to D_002B9504): size off by 2, ours hoists the `-1` compare constant into a saved register and the flag reloads differ.
- **0x21ADB0** (Unit219970, matrix to euler through VU0 rotations and func_0021ACA8): DIFF 2: retail loads the second float argument (m[0] into f13) before the first in the first call only; all other parts match (VU_GET_MAT with `move $2, %0`).
- **0x14FA08** (CGameDBMgr slot 70, `Find14FA08(a, chk)`: a < 0 means flag 0x17, v = a/4 + 0x19, last m_tbl250 index with m_id <= v, optional exact/non-empty check): retail copies `a` into v0 so the flag call result merges there, loads m_num250 before the loop and m_tbl250 inside; drafts ~45 insns off in allocation.
- **0x22FDB8** (Unit22DE48, collect (offset, size) pairs of a file's cache nodes inside [pos, pos+len) per block; `func_0022FDB8(FEnt *, u32 *out, u32 max, s32 len)`, caller 0x22E880 now passes the three extra arguments through): DIFF 10, the entry tests (retail copies `&f->mB4` to $24 after both early tests and returns the count through one exit) and the base/len update order at the loop bottom.
- **0x21C468** (Unit21BEC0, the 4-float B-spline basis table D_33D720[3], twin of 0x21E370): same problem: retail loads the float constants per outer iteration and converts `n` inside the inner loop; loop.c hoists both in ours (goto inner loop tried).
## w2
Lane w2 (goal 6b, dklib Dk* and library Lib* units), 2026-10-16. Best attempts in docs/hard/w2/.
- 0x275744 (Dk2752B8, 1 insn `jr $31`) and 0x262AF0 / 0x2629CC (Dk260A60, `addi`/`lq`/`sq`/`qfsrv` loops marked
  "handwritten instruction"): hand-written assembly (libkernel cache ops, MPEG audio SIMD), not C.
- 0x292F48 / 0x293088 (Lib290990, 6 insns, `and` with lui/ori 0xFFFFFFC0 then frameless `j`): SDK code built
  with ee-gcc 2.9-991111 (16-byte register save stride from 0x292E20 to the unit end); needs Lib290990 split at
  0x292E20 into an SDKC unit. Six functions there.
- 0x29CFE8 (Lib29CBF0, 12 insns, `++/-- tbl[a][b]`, returns old > 0): DIFF 6 with
  `s8 *e = (s8 *)p + (b + a * 3) + 0x48; s32 v = *e; s32 n = v + 1; if (!inc) n = v - 1; *e = n; return v > 0;`;
  retail adds p into b's register (`addu $6,$6,$4`), ours `addu a0,a0,a2` (register choice only).
- 0x2745B8 (Dk2735D0, sio putc, C 991111): DIFF 2-5. Retail has `sb $4,0($3); jr $31; nop` (the volatile store
  is kept out of the delay slot by retail gas's `.set volatile`); our gas (no -g in SDKC units) moves it into the
  slot; an `asm volatile(".set noreorder\n.set reorder")` after the store fixes the slot but moves `move v0,a0`.
- 0x25D3E0 (Dk25C438): DIFF 1, `bnez` vs our `bnezl` at the second test of
  `if (b == 0xFFFF) { if (a == 1) func_0025C230(D_41A788); if (a == 0) func_0025C2C0(D_41A788, 2); }`.
- 0x27CE60 (Dk27C020, 64-bit timer read): retail reads the counter with `lwu` through one base register and
  shifts by `(m & 3 ? 2 : 0) << (m & 3)` with dsllv; ours (C 991111) uses lw + dsll32/dsrl32 with volatile and
  CSEs the reread without; 18 vs 25 insns.
- 0x2838D8 (Lib283858, libgcc new_eh_context): DIFF 6; retail sets up memset's a0-a2 before `bnez p` and falls
  from `jal __terminate; nop` into `jal memset`; ours `bnezl` with the setup in the slot (strict aliasing too).
- 0x2737E8 (Dk2735D0, C 991111): DIFF 9, s16/s17 swapped (retail keeps %hi(D_002BDA90) in s16, b in s17) and
  an extra `move a0` in our jal slot; `if (a == 0) { if (!D) { if (!f(b)) return -1; D = 1; } return g(b, c); }`.
- 0x2752D0 (Dk2752B8, handler table set with $gp): retail recomputes `D.mC[i]` per branch with `mult` and
  reloads the table pointer for the gp store (`daddu $5,$28`); register-asm and asm("move") variants 13+ off.
- 0x273768 (Dk2735D0): same shape and same s16/s17 swap as 0x2737E8 (`if (a == 1 || a == 2)`).
- 0x297CA0 (Lib2975F0, CRand range with a fixed override at 0x291C): DIFF 4 with an early `return v` form;
  retail keeps the result in one register ($5) for all exits; single-exit forms get much longer (divu trap
  placement).
- 0x27CEB0 (Dk27C020): 0x27CE60's timer read inlined between DI/EI; same lwu problem.
- 0x279EF0 (Dk2779D8, sif bind retry loop): DIFF 3 (docs/hard/w2/hard_279EF0.snip): the delay loop
  `i = 0x100000; do i--; while (i != -1);` and loop shape match; the tail `D_002BDB4C = 0; return 0;`
  schedules `move v0,zero` before the store.
- 0x276020 (Dk2752B8, queue a command): DIFF 5; retail emits `q->m10 = c` before copying the fields,
  ours after the first two loads (tried if/else orders, per-branch stores).
- 0x2843A8 (libgcc get_reg_addr), 0x285EF0 (libgcc add_fdes): with Lib283858 as C and the real
  frame_state layout (cfa, eh_ptr, cfa_offset, base_offset, args_size, long reg_or_offset[123], cfa_reg,
  retaddr_column, saved[123], indirect) get_reg_addr is DIFF 22 as `if (saved[reg] == 2) do ... while`:
  retail rotates the while loop by duplicating the exit test and, when the first test fails, reuses the
  loaded saved[] byte for the `== 1` test; ours reloads. add_fdes keeps the fde_insert inline's
  `accu->linear.count` pointer in t6 and branch-likely forms. docs/hard/w2/hard_2843A8_285EF0.snip.
- 0x287A70 (libgcc __cp_push_exception): DIFF 2 after hill-climbing perm of the 9 field stores
  (docs/hard/w2/hard_287A70.snip).
- 0x286E20 (__user_type_info::do_dyncast): 37 vs 38 insns; retail `beql` to a shared epilogue after the
  second type_info == and returns false from one `daddu v0,0` block.
- 0x27CFE8 (Dk27C020, release alarm): DIFF 2, retail `beqz; nop` before `jal func_0027CB88`, ours `beqzl` with
  `a->seq = 0` in the likely slot. 0x27D938 (alarm callback trampoline): retail has two epilogue copies;
  ours one (if/else and single-exit forms). docs/hard/w2/hard_27D938_27CFE8.snip.
- 0x297D20 (Lib2975F0, float CRand range with fixed override): DIFF 2, retail materialises 0.0f before
  loading m2920 (`mtc1 $0` first); ours loads first (early-return, inline and single-exit forms tried).
- 0x276D78 (Dk2752B8): retail keeps %hi(D_4203C0) in s16 and &D_4203C0 in s20 across the calls (two pseudos
  for the same symbol, splat left one relocation raw) and stores $gp to 0x420400; ours rematerialises.
- 0x27D188 (Dk27C020, start alarm): same shape as 0x27CFE8 (one instruction off in the `&D_002BF138` setup).
- 0x2844A0 (libgcc next_stack_level): 42 vs 44 insns; retail re-reads `caller->cfa` after the indirect load.
- 0x263AF0 (Dk2631E0, libcdvd/sif id -> buffer lookup): retail tests the 8 ids in source order with all
  case bodies after the tests sharing one `sw` (0x8011 has its own store); 991111 switch and if-chains
  give a different (longer) layout.
- 0x289DFC (newlib memcpy with lq/sq): newlib memcpy.c shape with u128 big blocks and u64 little blocks gives the
  right loops but retail keeps dst0 in t0 (`daddu $8,$4`) and walks with t3/a3 differently; 45 vs 44 insns.
- 0x27C778 (Dk27C020, alarm system end): retail `bgez; nop` (no likely slot) for the `id < 0` check, like
  0x27CFE8; volatile struct pointer makes it longer.

## x1

Overnight grind 2026-10-16 (game units). Best attempts in docs/hard/x1/hard_<ADDR>.snip.

- **0x21BAC0** (114 insns): Unit219970 func_0021BAC0 (VU program upload slot alloc): DIFF 22-23, prologue scheduling (i*4 / i*0x441 order) and the store order of the 3 GItem fields (retail p,x,y; best perm y,x,p). Needs Grp.it[32][16] (GItem moved up) and s32 return in the unit decl.
- **0x1D5420** (76 insns): CMiniGame4Res shuffle (CMiniGame4ResObj::Shuffle1D5420, needs CRand::Rand and the method decl added in the unit): DIFF 46. Retail reads order[j] through (this+4) + a running 0x1400+4j offset with the base re-copied in the loop (daddu $10,$7) and writes through a separate this+0x1404 pointer; best: read via a view struct o->a[0x500+j], write m_order[j]. Register allocation still differs.
- **0x10DFD0** (56 insns): CFaceObj::Draw (fills a sprite record {u64 tex; x; y; w; h; handle} from a face cell, optional font-manager vcall slot 5 with 9 args): DIFF 11. Store order and the early v0=0 now match; left: p->m0 lands in v1 (retail a0) and the order of the vcall argument setup (retail loads p->mA/p->m8 before the slot address).
- **0x244500** (86 insns): Unit243AB8 IPU/MPEG input refill: everything matches except one slot: retail 'li a0,0x101; and; sw (volatile 0x1000B410); jal func_00244498; nop' (retail gas honoured .set volatile), ours lets GNU as move the sw into the jal slot; NOSWAP() after the store blocks GCC from hoisting the li, a register-asm a0 variable miscompiles. Everything after is shifted by one insn (DIFF 38).
- **0x236BC8** (102 insns): Unit236130 debug console row render (8x8 1bpp font, rows doubled by 1 << (1 - mode)): DIFF 30, register allocation inside the cell loop only (retail: ch reuses v's register, col in $4, bits $10, p and the row-copy counter share $9). Needs the (s32 (*)(...)) cast on func_00236B50 (retail passes unextended ints).
- **0x2384B8** (106 insns): Unit237A88 BITBLTBUF/TRXPOS/TRXREG/TRXDIR A+D packet (returns 6 qwords): the mask part is solved with BITK/LOWB (all andi now, see the snippet and docs/lessons.md ## x1), DIFF 92 left: retail reassociates the bb ORs as ((srclo|dst32) | (dstlo|src32)) | (src14|dst14) and keeps &D_002B94E4 in t7 with 4 saved regs (0x20 frame), ours uses 5 (0x30). Statement-order perm (720 orders) found nothing.
- **0x2381C0** (32 insns): Unit237A88 switch with jump table jtbl_002E5230: blocked, the C-style units have no .rodata of their own (ro_tail).
- **0x23D330** (38 insns): Unit23C680 switch with jump table jtbl_002E55C0: blocked (ro_tail, level 1).
- **0x23DD40** (210 insns): Unit23C680 switch with jump table: blocked (ro_tail, level 1).
- **0x1FDC40** (786 insns): Unit1F4918 switch with jump table: blocked (ro_tail, level 1).
- **0x10BAC8** (22 insns): ISnapMgr switch with jump table jtbl_002D1F30: blocked, ISnapMgr shares its data with CSnapMgr (merged unit, level 1).
- **0x19AFA8** (148 insns): CStatusBase switch with jump table jtbl_002DDB70: blocked, CStatusBase shares its data with CCommandIncDec (merged unit, level 1).
- 0x28CB88 / 0x28D8F8 (newlib __sbprintf, two copies): DIFF 4, the five field copies into the fake FILE come out
  in a different load/store order (hill-climbing perm stuck at 4).
- 0x27ED10 (libpad close port): the `&D_424190[a][b].m10` pointer is formed as base+0x10 then index in retail.
- 0x288A00 (libgcc __dynamic_cast): retail calls `from()` through a0 directly after the abort test (abort is
  treated as noreturn, a0 not saved) and keeps to/sub/address/subptr in s17-s20; ours saves a0 first (35 vs 34).
- 0x289FB0 (newlib EE memset with pcpyh/pcpyld) not attempted; 0x2744F8 (SIO init, uncached struct at
  D_41CDC0|0x20000002) left.
- 0x25C580 / 0x25C5D8 (Dk25C438, delete all units of a list): same unit-list item shape as d2's 0x25C4B0 family:
  retail `daddu $6,0; movz $6,$3,$2` with `lw` in the bnel slot (22 insns), ours movn (21); both item() forms tried.
- 0x276380 (Dk2752B8, queue init + append): DIFF 8; retail stores m3C/m38/m0 before loading `q->m8`, ours
  loads first (strict-aliasing scheduling); perm and int-typed links tried.
- Not attempted (newlib EE string routines with MMI pcpyld/psubb: strcpy 0x28B2D4, 0x28B000, 0x28B190,
  0x28B3E8, 0x28B570, 0x28B728, 0x29189C; hand-written SIMD in Dk268138/Dk26A870/Dk260A60).
- CList / TList<T> deleting destructors 0x293840 (Lib2930A0), 0x29CE18 (Lib29CBF0), 0x29DC68 / 0x29DD68
  (Lib29D6D0): the drain loop's `First()` is `daddu r,0; movz r,n,head` into a separate register in retail;
  every inline/ternary/static_cast form gives `movn n,0,head` (same family as 0x25C580).
- 0x29A7A0 (Lib29A578, TArray<CMapDBExprReg>::Insert(idx, n)): DIFF 25, control flow and length right
  (docs/hard/w2/hard_29A7A0.snip); only s-register numbering (retail idx/this/n in s17/s18/s21, ours s2/s1/s5).
- 0x288F40 (fp-bit pack_f, EE variant with an exp == 128 rounding case): DIFF 1, `beqz` vs retail `beql` at the
  `exp > 128` test (docs/hard/w2/hard_288F40.snip). 0x288268 (fp-bit _fpcmp_parts): gcc's source order gives
  73 vs 71 insns; retail nests the inf/zero tests differently.
- 0x285FD8 (libgcc init_object): 94 vs 90 insns; retail keeps &accu in s16 (0x40 frame, three s-regs) and stores
  the start_fde_sort results through it; ours keeps pc_begin/pc_end pointers in s3/s4 (0x50 frame).
- 0x287B00 (__cp_pop_exception, newer rethrow logic), 0x287E50/0x287EB8 (__throw_bad_cast/typeid with EH
  landing pads merged with the next function) not attempted.
- 0x2762A8 (Dk2752B8, 15 insns): retail leaves every delay slot empty and returns 0/1 from two blocks; ours
  folds to `andi` result (10 insns); volatile fields tried.
- 0x27F670 (libpad, 6-byte copy into the RPC buffer): retail keeps &D_424380 in s16 and builds the copy
  pointer from it; ours materialises the address twice (55 vs 54).
- 0x2688E8 (Dk268138, MPEG buffer pointers, 9 out-params): retail recomputes `q * 384` three times; ours CSEs.
- 0x283D20 (libgcc __eh_alloc): retail's mask search is a short down-counting loop (67 vs 56 insns ours).
- 0x27DE90 (Dk27DBB8, call handler table switching $gp per entry) not attempted.
- 0x2926D0 (newlib d2b): DIFF 5, only which register carries word1 before the lo0bits call (docs/hard/w2/hard_2926D0.snip).
- 0x280E88 (newlib __ieee754_sqrtf, no-denormal variant): DIFF 8, scheduling of the mantissa setup only.
- 0x283490 / 0x2835A8 (libgcc __fixunsdfdi / __fixunssfdi): DIFF 17-18, the libgcc2 source matches except
  s16/s17 (retail keeps `a` in s17 and `v` in s16).
- 0x27BD20 (Dk27A100, libkernel DI): retail reloads 0x10000 inside the di/mfc0 poll loop and returns a value
  computed in the first branch's delay slot (20 insns); loop/goto/single-exit forms give 17.
- 0x2612F0 (Dk260A60, MPEG audio buffer init calling SIMD helpers) and 0x26CE28 (libmpeg header fields):
  first attempts 56/61 and 55/61 insns (loop shapes), best C in docs/hard/w2/.
- 0x27CF30 func_0027CF30 (Dk27C020, 28 insns, alarm alloc): logic and store order match (volatile AlarmSys *s, plain AlarmEnt *e, volatile reload of e->seq at return); every register is one lower than retail (ours s=a2,e=a1,e<<4=a0; retail s=$7,e=$6,$5). DIFF 17. Tried int id temp, direct global, args, if/else single exit. Snip docs/hard/w2/hard_27CF30.snip.
- 0x27E7B0 func_0027E7B0 (Dk27DBB8, 70 insns, pad DMA send): frame 0x150 (16-entry SifDma array) and logic right; retail recomputes &D_424190[a][b] (both mults) after the first sceSifDmaStat call and keeps a/b in s-regs, ours CSEs the address into s-regs (58 vs 69 insns). Tried q load before/after the check; all compiler modes. Snip docs/hard/w2/hard_27E7B0.snip.
- 0x260758 func_00260758 (Dk25E340, 72 insns, 4-block copy via func_00262AF0): logic right (two 4x loops, countdown counters); retail keeps the second loop's index k unreduced (`sll k,1; addu c; addiu 0x2A90`, k += 0x100, k=0 set before the -1 check) and copies src2 into a separate reg ($20) for loop 1; ours strength-reduces k into a pointer. DIFF 45. Snip docs/hard/w2/hard_260758.snip.
- 0x267E58 func_00267E58 (Dk265918, 72 insns, MPEG decode step): DIFF 3 with `{ s32 ok; if (!func_0026D110(s, 0)) ok = 0; else ok = func_0026CFB0(s) != 0; r = ok; }` (the sibling 0x267FC0 matched with the `ok = 0; if (f()) ok = 1;` movn form). Only the temp register differs: retail ok in $3 (v1), ours v0. Tried inline helper, t temp, ?:, u32. Snip docs/hard/w2/hard_267E58.snip.
- 0x2746E0 func_002746E0 (Dk2735D0, 38 insns, double -> int with round-half): logic and instruction sequence match; registers m/e swapped (retail m=$5 a1, e=$6 a2; ours m=a2, e=a1) and retail leaves the final `jr` delay slot empty (dsra32 before jr). DIFF 25. Tried m as param, union, decl orders. Snip docs/hard/w2/hard_2746E0.snip.
- 0x275398 func_00275398 (Dk2752B8, 78 insns, sceSifSendCmd core): DIFF 17, store scheduling only (needs alias D_41D1A0 in config/aliases.ld, added). Retail stores dma[0].data (from the a0 copy of src) before dma[0].addr, and in the packet entry stores data/addr/size/cid/psize/mode in source order with the D_41D1A0 load hoisted; `bk perm` over both blocks finds no order. Snip docs/hard/w2/hard_275398.snip.
- 0x27B1A0 func_0027B1A0 (Dk27A100, 86 insns, IOP reset/reboot packet): everything matches except retail leaves both `jal func_00273470` and `jal func_002735B0` delay slots empty (`lui a0,0x8000` stays before the jal); ours moves the lui into the second slot, shifting the rest (DIFF 12). Tried K&R/const/unsigned decls, asm barrier, temp arg. Snip docs/hard/w2/hard_27B1A0.snip.
- 0x263668 / 0x263980 (Dk2631E0, 92 insns each, sound RPC bind): structure matches (snip for 263668); retail leaves the delay slots of `jal func_002731F0` / `jal func_002731C0` (kernel syscall stubs, PollSema/SignalSema) empty with the `lw a0, D_002BBBE8` before the jal, ours moves the load into the slot. Same pattern as 0x27B1A0 (syscall stubs 0x273470/0x2735B0). Calls to non-syscall functions in the same functions are filled normally. Snip docs/hard/w2/hard_263668.snip.
- 0x26DB60 func_0026DB60 (Dk26CFB0, 92 insns, toSPR DMA REF-chain builder): logic right (struct blk[2] at 0x5A8 with cur at 0x828, n hoisted, id 3/0 via movz); loop body register allocation and scheduling differ (retail p=$10 i=$11 n=$12 n-1=$13 b=$14 a=$15, ours t2..t7 in another order), DIFF ~80. Snip docs/hard/w2/hard_26DB60.snip.
- 0x26D720 func_0026D720 (Dk26CFB0, 94 insns, MPEG pts/dts/flags): DIFF 17. Control flow and the divide call match; retail computes the odd bit as `andi $17,x,1; andi $16,cnt,1; and; andi $2,m90,1; and` (keeps the `& 1` on the 64-bit m90), ours drops it, and the 6-term flags OR (shifts 0,3,8,7,5,6 of p+0x2C..0x40) schedules differently (`bk perm` over the terms: best DIFF 19). Snip docs/hard/w2/hard_26D720.snip.
- 0x257068 func_00257068 (Dk254AA8, 86 insns, font string width/draw): DIFF 4, one call's argument scheduling: retail sets `mov.s $f13,y` before `jal func_00256DC8` and puts `daddu $6,$16` (l) in the delay slot; ours the other way round. The other call in the same function matches. Snip docs/hard/w2/hard_257068.snip.
- 0x262108 func_00262108 (Dk260A60, 97 insns, audio frame decode loop): outer loops and calls right (snip); the resync byte copy differs: retail skips trailing 0xF8 bytes with a do-loop whose `base < p` test sits in a bnel delay slot, then copies backwards entering the copy loop in its middle (`b; sb` with the already loaded byte). Our while/for forms get rotated/duplicated by GCC (DIFF ~74). Snip docs/hard/w2/hard_262108.snip.
- 0x25FBC8 func_0025FBC8 (Dk25E340, 90 insns, sound buffer size by format): DIFF 43, snip docs/hard/w2/hard_25FBC8.snip. The `cvt.w.s` is NOT a blocker: a plain `(s32)` cast emits it (objdump just prints the R5900 encoding 0x46000024|... as `trunc.w.s`; utest compares bytes). Left: the switch compares (retail `beql` with the next constant in the slot, ours `beqz`+`li`) and the n/z register pair (retail $6/$4, ours a1/a2). `if (id < 0 || rate == 0.0f) return 0;` fixed the head (89 -> 43).
- 0x274118 func_00274118 (Dk2735D0, 102 insns, DECI2 sio event handler): control flow right (snip); s-register assignment swapped (retail param/result/index in $16 and the Sio pointer in $17; ours the reverse), and the receive-size test is unsigned (`sltiu`, param u32). Reusing param as the result and index variable gets DIFF 64. Snip docs/hard/w2/hard_274118.snip.
- 0x275748 func_00275748 (Dk2752B8, 104 insns, sceSifInitRpc): structure, calls and tail calls right; s-register numbering differs (retail &D_41EBC0=$16, const 1=$17, D_41D3C0=$18; ours s0, s2, s1) and the ten RPC-data stores are ordered 0x20,0x0,0x14,0x4,0x1C,0x8,0xC,0x10,0x18,0x24 (`bk perm` can't run it standalone). DIFF 40. Snip docs/hard/w2/hard_275748.snip.
- 0x289EAC func_00289EAC (Lib2888C0, 65 insns, newlib memmove with EE 2x lq/sq 32-byte blocks and ld/sd 8-byte words): newlib structure in snip; register use differs (retail copies dst_void to $8 and walks dst in $3, src stays in a1; ours copies src) and the block loops schedule differently, DIFF ~62. memcpy (0x289DFC) is in the same state.
- 0x2958B0 func_002958B0 (Lib294A60, 22 insns): VU0 macro-mode distance (lqc2/vsub/sqc2, vsqrt via qmtc2/cfc2): inline-asm/handwritten, not attempted.
- **0x10CF40** (58 insns): CList ~CTexCacheMgr (slot 6; slot 1 is the key method, so it can be written with the vtable in asm: CList.cpp now declares the ITexCacheMgr/CTexCacheMgr virtuals and the TList member at 0x20): DIFF 44. The inlined ~CList drain loop: retail tests the node at the top and loops back with 'bnez e' (no rotation), ours either rotates (while) or folds the bottom test to 'b' (do/while, goto); also D_002A039C = 0 should be a direct %lo store.
- **0x21BF50** (98 insns): Unit21BEC0 TEX0/CLAMP setter (floats 0.5/1024 to D_33D6C0, GS_SET_TEX0/GS_SET_CLAMP into D_33D6B0): masks solved with LOWB/BITK (all andi, TBW folds to and 0xFC000 like retail): DIFF 10, only the order of 6 independent insns in the TEX0 OR tree (retail: dsll32 cpsm before the and of TBW; tcc constant built after). Field-temp perm (120 orders), CLAMP first, hand-ordered OR all worse. Twins 0x220708, 0x220890 (Unit21F250) should go the same way.
- **0x220708** (98 insns): Unit21F250 twin of 0x21BF50 (D_33DCA0/D_33DC90): same DImode-mask problem.
- **0x220890** (98 insns): Unit21F250 Func220890 twin of 0x21BF50 (D_33DCC0/D_33DCB0): same DImode-mask problem.
- **0x220E08** (108 insns): Unit21F250 VU microcode upload + debug size prints (D_33DCF8/D_33DCFC are now in config/aliases.ld): DIFF 12, only the first block: retail keeps the func_0021BDD0 result in v0 (sw/bgez on v0, copy to a1 for both paths) and uses v1 for the raw lui 0x34 of D_33DCFC; ours copies it to v1 and puts the lui in v0. Tried r = ..., chained assignment, if-block return, reading the global back. The twin 0x21E4A0 matched (its result is not printed).
- **0x23B510** (58 insns): Unit23A1D8 move a handle's node to the front of the D_37CDE0 index list: DIFF 51. Retail computes &D_37CDE0[r] and &D_37CDE0[1] from two separate lui/addiu of the symbol and writes the neighbours through `sh reg, D_37CDE0+off(idx)` $at macros; ours CSEs the base into one register (t3) and uses reg+reg addressing.
- **0x1A1B38** (44 insns): CStatusWin CStatusItem::Func1A1B38 (switch on m_unk2C: Fade(1, flag 3/4) or ResetColors): blocked, its jump table jtbl_002DE180 sits in CMenuInputKanji's .rodata (text boundary: the function belongs to the next unit).
- **0x2395A0** (62 insns): Unit237A88 DMA channel sync with timeout (sceDmaSync-like: mode 1 polls, else waits on chcr & 0x80000100, prints D_002E5348 and clears STR on timeout): draft DIFF 55; retail has an odd padded one-pass loop (and; li v0,0; 3 nops; bnez v0) around the chcr & ~0x101 store, i.e. some macro loop with a constant-false condition, and keeps the mask in $18.
- **0x1A3488** (66 insns): CStatusWin CStatusItem reset (switch per entry type): blocked like 0x1A1B38, its jump table jtbl_002DE630 is in CMenuInputKanji's .rodata, so the CStatusItem code (0x1A0xxx-0x1A4xxx) likely starts the CMenuInputKanji object (unit boundary).
- **0x241E78** (76 insns): Unit240FD8 TEX0 + GIF tag packet for the current font texture (same TEX0 expression as 0x21BF50): DImode-mask CSE problem; draft not written beyond the mask analysis (see 0x21BF50).
- **0x23DB28** (114 insns): Unit23C680 texture-handle debug print/refcount (uses the return address via $31 and u64 handle bitfields): not attempted beyond analysis; its three '& 0xFFF' and two '& 0x3F' masks are separate andi in retail (the DImode-mask problem of 0x21BF50).
- **0x1722D8** (112 insns): CResortDBMgr::Func1722D8 (GET table: m_names[i] = {i + 0x10, 8 value pairs}): DIFF 9, register choice only: retail materialises 0x40 before 8 and reuses $2 for the two lui of D_002DA0D8/D_002DA0E0; ours uses v1/v0. Statement-order perm and size expressions tried.
- **0x16D548** (52 insns): IAlbumMgr ~CAlbumMgr: blocked, key method (slot 0) of a class whose vtable sits in the merged IAlbumMgr/CPhotoEventObj data.
- **0x143A90** (30 insns): ISysFlag ~CSysFlag: blocked, key method in the merged CSysFlag/ISysFlag unit (vt_CSysFlag # also ISysFlag).
- **0x144808** (30 insns): ISysFlag ~CCurFlag: blocked, key method in the merged CSysFlag/ISysFlag unit.
- **0x126E38** (24 insns): CMapEffObj ~CMapEffObj: blocked, key method; vtable inside the merged CMapEffObjRes piece.
- **0x127888** (28 insns): CMapSndRes ~CMapSndRes: key method; level 3 would also have to emit the TArray<tagMapSndStepInfo> linkonce vtable that shares the piece. Not attempted.
- **0x172C88** (30 insns): CMapDBExpr ~CMapDBExpr: key method; the piece also holds CMapDBMgr's and TArray<CMapDBExprReg>'s vtables. Not attempted.
- **0x19D0A8** (36 insns): CStatusWin ~CStatusWin (slot 7, key method): the class is called CStatusWinV in CStatusWin.cpp because CStatusWin names the vtable-less window class there; level 3 needs that renaming first.
- **0x113090** (38 insns): CCharaObj ~CCharaObj (key method): level 3 needs the inline ~CListTag (unlink + _vt$8CListTag store) without emitting CListTag's vtable, and the RTTI chain CCharaObj : TListTag<CCharaObj> : CListTag (t8TListTag1Z9CCharaObj is in the unit's .rodata).
- **0x12E768** (60 insns): CSvmWork ~CSvmWork (key method): unit at level 1 and the piece holds TArray<const void *>'s vtable too. Not attempted.
- **0x1BD958** (44 insns): CMiniGame1Res ~CMiniGame1 (key method): unit at level 1. Not attempted.
- **0x1D4E98** (68 insns): CMiniGame4Res ~CMiniGame4 (key method): unit at level 1. Not attempted.
- **0x2186B0** (264 insns): Unit217F50 3D sound pan/volume from listener (frac-wrapped angles via VU0 vftoi0/vmadda, distance falloff table, pan table): first 36 insns match with the snippet; then retail reloads the 1.0f constant for every 'frac == 1.0f' test (ours CSEs it across the volatile asm) and copies the frac result (mov.s f2,f0) before the test. Float args come in f12-f14 after the int args.
- **0x108FF0** (70 insns): CFlagWork::Func108FF0 (set integer flag clamped to D_0029F2F0[size], memcpy into the data, Notify2/Notify1): clamp shape matches ('if (!(t < max)) t = max; v = t < min ? min : t'); left: retail builds &D_0029F2F0[size] with explicit lui/addiu/addu and reads m_min through a copy of that pointer (daddu $4,$3), ours uses the 'la $at' macro form. Tried sized/unsized array, base pointer local, inline clamp helper, struct copy.
- **0x235DE0** (126 insns): Unit234318 Func235DE0 (the debug printf: EE va_start, vsprintf into a 0x400 buffer, hook D_002B8D00, buffered console/host output): DIFF 2: the vsprintf argument moves come out a1, a0, (jal) a2 in ours and a1, a2, (jal) a0 in retail. Placement of the va_start, a buffer pointer local and void * ap tried.
- **0x241398** (164 insns): Unit240FD8 glyph alignment (sibling of the matched 0x241778: flags pick left/center/right and top/middle/bottom placement per glyph): draft DIFF 156; loop.c hoists fl & 1 and fl & 4 into saved registers in ours (retail keeps only fl & 2 hoisted, in $16) and the stack frame grows; store order inside the cases not yet checked.
- **0x23F1C0** (166 insns): Unit23E868 glyph texture upload packet (BITBLT A+D with TEX0-style masks, then a pixel copy loop): not attempted beyond analysis: the DImode-mask problem of 0x21BF50 again (retail andi 0x3FFF / 0x3F unshared).
- **0x146C08** (120 insns): CResNameMgr::Func146C08 (school name: entry by flag value, prefix D_002A28E0[j] for key in D_002A2910, uppercase, append season name; else Func146B58): DIFF 10: retail loads D_002A28E0[j] with explicit lui/addu/lw %lo into a1, ours gets the 'lw a1, D(reg)' $at macro, and j / j*4 swap registers. Loop forms and sized arrays tried.
- **0x23B658** (86 insns): Unit23A1D8 texture name hash lookup (byte-sum hash, double hashing over D_382E1C, strcmp against D_382E10[e - 8].name, then func_0023B510): draft DIFF 76: retail sets v0 = -1 before the null test and r = -1 later (two -1s), keeps the key address in $22 and the hi of D_002B94F0 in $21; ours keeps r in s7 from the start. Twin 0x23B7B0 (same body) not attempted separately.
- **0x23B7B0** (102 insns): Unit23A1D8 twin of 0x23B658 (hash lookup that also inserts): see 0x23B658.
- **0x2446D8** (96 insns): Unit243AB8 sound stream feeder thread (while !D_002B9DB8, push blocks while D_38F080 >= 2 and ring space > 0x800): DIFF 17, logic and code shape match; only register choice differs: retail hoists %hi of D_002B9DB4/DCC/DC8/D_38F000 into s6/s5/s4/s3, ours s3/s5/s6/s4; and the (D_38F078+5)%4 tail stores D_38F080 before the modulo (retail) vs after (ours). Locals for w/h, swapped statement order, other address forms tried.
- **0x2390B0** (110 insns): Unit237A88 DMA channel interrupt handler, marked /* Handwritten function */ in the asm (lui/ori of 0x10008000 per use, no CSE): not attempted, keep as asm.
- **0x224818** (138 insns): Unit222CE0 view/clip matrix setup (15 float args, 0x80-byte output, z range mapped to 0..255): math is complete in the draft but DIFF 116: float scheduling of the 13 div.s and the store order are far off (retail div order: slope, sz, sx, a*b/l, a*c/n, ofs, 1/m0, 1/m1, 1/sx, -sz/sx, ...; retail else branch reloads m[3]); reordering the source to the retail order made it worse (119). Twin 0x224A88 has the same shape.
- **0x224A88** (142 insns): Unit222CE0 twin of 0x224818 (other projection variant, -2.0 factor, same 0x80 layout): not attempted separately, see 0x224818.
- **0x235BF0** (100 insns): Unit234318 set boot path (device / dir / file name split into D_002B8D70/DF0/E70, ';1' stripped): logic complete, DIFF 58: retail copies q (func_00235B28 result, s2) into path's register s1 before the second half and reuses s2 for the func_00234108 result; ours keeps q in s2 throughout (CSE/regmove ties the copy). Tried path = q, a fresh variable, an inline helper taking q; the ending is a sibcall (return (void)Func235DE0).
- **0x223CA8** (190 insns): Unit222CE0 texture/FRAME A+D packet (0x11000000, 0x5000000B, GIFtag NLOOP 10, regs 0x4E/0x4A/0x47/0x4C/1 plus three raw qwords from h+0xB0..): packs func_0023C650/658 results with (x>>32)&0x3F and (x&0x3FFF)>>5 masks, the same DImode-mask CSE problem as 0x223A90 (retail separate andi). Not drafted beyond decoding.
- **0x2245A0** (150 insns): Unit222CE0 render-target setup (func_0023C650/658 of the target, func_0021BCF8, Func225088/2250C0, then FRAME/ZBUF/... A+D quads): three (x>>k)&0x3F masks in one block, the unsolved same-mask DImode problem (see 0x223A90); not drafted.
- **0x2242E0** (176 insns): Unit222CE0 sibling of 0x2245A0 (same target query + A+D quads with (x>>32)&0x3F and (x>>14)&0x3F masks): same-mask DImode problem, not drafted.
- **0x1A1AA0** (38 insns): CStatusWin switch whose jump table lives in CMenuInputKanji's rodata (like 0x1A1B38/0x1A3488): blocked until that rodata is split/converted.
- **0x234D40** (128 insns): Unit234318 system init (device setup, prints, D_36D540 = table[func_00235A38()] + func_00235A18()): DIFF 27 in three spots: the first store's lui/li order (D_002B8D08 = '0'), the clear loop uses v0 as pointer (retail v1), and the final strcpy dest: retail rematerialises lui/addiu D_36D540 and adds strlen (sym + len), ours reuses s1 (len + s1). Tried StrAdd, explicit strcpy(D + strlen(D), t), &D[strlen], strcat, a local p. The 3 nops in the clear loop are the assembler's short-loop fix, not source.
- **0x244A80** (136 insns): Unit243AB8 sound stream init (allocs via D_002B91A4, ring func_00245460(0x80000), func_00267608/266CF0/267A60 handler registration): code shape right but register allocation differs from the first lui on (DIFF 126): retail uses 7 saved regs (keeps hi(D_002B9D9C) in s4 and &D_002B9D9C in s2 for the post-call store, i in s3, &D_38F000 copied to s2), ours 6.
- **0x23E088** (130 insns): Unit23C680 texture free (unlink VEnt from the used list, push on the 0x1003 free list, D_002B94FC callback, debug print with the caller's ra): DIFF 11, only the tail: retail computes k2 = (h>>14)&0x3F before loading D_002B9500 (lw into v0), ours loads the flag first (into a1), then a2/a3 register order of the print args. Needed: BITS() pre-shift masks (andi), asm("move %0,$31") for the return address, &D_388F30[0x1003].m2 through a pointer, D_388F30[idx].mX indexing (no element pointer), x reusing w.
- **0x242170** (116 insns): Unit240FD8 font begin (packet start in D_38EF84/D_38EF80, TEX0 A+D for the current font texture with the 0x21BF50 TEX0 expression, then the RGBAQ A+D): masks fine with LOWB/BITK; DIFF 65 from store/load scheduling: retail stores D_38EF84, D_38EFE0, D_38EF80 (raw lui 0x39 -0x1080), D_38EFE4 in that order and loads p = D_38EF84 right after func_00240DF0 returns; ours differs (perm of the 4 stores best 72).
- **0x1D5140** (136 insns): CMiniGame4ResObj param table parser (5x4 floats at 0x144C, 4 pairs at 0x14C0, 3 at 0x14A4, 0x1500, 0x1508; needs 'int Parse1D5140();' in the class): DIFF 14, registers only: the loop-hoisted hi(D_002E1468)/hi(D_002E1470) are s7/s6 in ours vs s6/s7 retail, and in the pairs loop the counter and lo(D_002E1470) swap s1/s2. Element-pointer and local fmt-pointer variants tried.
- **0x23C340** (102 insns): Unit23A1D8 GS context/sprite setup: s16 args, func_0026EDE8/func_0026EFD0 (libvu0 sample-style), then a 128-bit GIF tag built with por/sq and ld/and/or/sd (sceGifTag bitfields on a u_long128): not attempted (needs a u128 bitfield struct).
- **0x23BA10** (134 insns): Unit23A1D8 set texture page handle (n == 0: TexEnt.m8; else walk/allocate the D_382E18 chain, allocating nodes from the D_380E04 LNode free list, then D_382E14[k]); needs the unit decl changed to 'void func_0023BA10(s32, s32, u64)' and func_0023BD60 to void (it still matches): DIFF 30, register numbering inside the allocation block only (retail v1 for &D_380E04, a3 = L, t0 = f; ours t4, a1, a3). An inline allocator helper is worse (86).
- **0x23BD98** (122 insns): Unit23A1D8 texture-page LNode list code (D_37CDE0/D_380E04 nodes, D_386E24 head index, unlink/relink sequences like 0x23BA10): not attempted beyond reading; expect the same t-register numbering issue as 0x23BA10 (and $at-macro la addressing in 0x23AFB8/0x23B1D0).
- **0x23AC68** (156 insns): Unit23A1D8 texture-page LNode list code (D_37CDE0/D_380E04 nodes, D_386E24 head index, unlink/relink sequences like 0x23BA10): not attempted beyond reading; expect the same t-register numbering issue as 0x23BA10 (and $at-macro la addressing in 0x23AFB8/0x23B1D0).
- **0x23AFB8** (134 insns): Unit23A1D8 texture-page LNode list code (D_37CDE0/D_380E04 nodes, D_386E24 head index, unlink/relink sequences like 0x23BA10): not attempted beyond reading; expect the same t-register numbering issue as 0x23BA10 (and $at-macro la addressing in 0x23AFB8/0x23B1D0).
- **0x23B1D0** (208 insns): Unit23A1D8 texture-page LNode list code (D_37CDE0/D_380E04 nodes, D_386E24 head index, unlink/relink sequences like 0x23BA10): not attempted beyond reading; expect the same t-register numbering issue as 0x23BA10 (and $at-macro la addressing in 0x23AFB8/0x23B1D0).
- **0x147130** (132 insns): CGameDBMgr::Func147130 (vtable slot 3, load the game database: Init(), open, the 15 table loaders, size print): DIFF 47 but only one real difference: the last test of the long loader chain becomes 'sltu s2, zero, v0' (if-converted ok = 1) in ours, retail keeps 'beqz; nop; li s2, 1'; every other diff is a branch offset. && chain, goto chain, bool, ok++ and swapped branch order tried. nm: docs/hard/nm/hard_147130.snip declares func_00248C70 `throw()` (nothrow in retail's CGameDBMgr; fixes the first `beqz` slot), DIFF 6 = only this if-conversion; 0x111BA8 is stuck on the same `if (call()) ok = 1` -> sltu.
- **0x147130** (132 insns): CGameDBMgr::Func147130 (vtable slot 3, load the game database: Init(), open, the 15 table loaders, size print): DIFF 47 but only one real difference: the last test of the long loader chain becomes 'sltu s2, zero, v0' (if-converted ok = 1) in ours, retail keeps 'beqz; nop; li s2, 1'; every other diff is a branch offset. && chain, goto chain, bool, ok++ and swapped branch order tried.
- **0x19F6C0** (228 insns): CStatusWin update: state.h menu state machine (goto-loop, (flags >> 7) & 1 busy test, switch on negative state codes, yields cross-jumped into one 'li v1,1; b loop; sw state' tail); the open layout problem of these machines (see 0x192710 and the docs/lessons.md state.h entry: none of this shape is matched yet, CMenuNosave's best is DIFF 56); not attempted.
- **0x131720** (388 insns): CSvmWork update: state.h menu state machine (goto-loop, (flags >> 7) & 1 busy test, switch on negative state codes, yields cross-jumped into one 'li v1,1; b loop; sw state' tail); the open layout problem of these machines (see 0x192710 and the docs/lessons.md state.h entry: none of this shape is matched yet, CMenuNosave's best is DIFF 56); not attempted.
- **0x1AA1B8** (314 insns): CMenuSysscr26 update: state.h menu state machine (goto-loop, (flags >> 7) & 1 busy test, switch on negative state codes, yields cross-jumped into one 'li v1,1; b loop; sw state' tail); the open layout problem of these machines (see 0x192710 and the docs/lessons.md state.h entry: none of this shape is matched yet, CMenuNosave's best is DIFF 56); not attempted.
- **0x12EF68** (630 insns): CSvmWork update: state.h menu state machine (goto-loop, (flags >> 7) & 1 busy test, switch on negative state codes, yields cross-jumped into one 'li v1,1; b loop; sw state' tail); the open layout problem of these machines (see 0x192710 and the docs/lessons.md state.h entry: none of this shape is matched yet, CMenuNosave's best is DIFF 56); not attempted.
- **0x18B080** (460 insns): CMenuCommon update: state.h menu state machine (goto-loop, (flags >> 7) & 1 busy test, switch on negative state codes, yields cross-jumped into one 'li v1,1; b loop; sw state' tail); the open layout problem of these machines (see 0x192710 and the docs/lessons.md state.h entry: none of this shape is matched yet, CMenuNosave's best is DIFF 56); not attempted.
- **0x190160** (832 insns): CMenuReviewResult update: state.h menu state machine (goto-loop, (flags >> 7) & 1 busy test, switch on negative state codes, yields cross-jumped into one 'li v1,1; b loop; sw state' tail); the open layout problem of these machines (see 0x192710 and the docs/lessons.md state.h entry: none of this shape is matched yet, CMenuNosave's best is DIFF 56); not attempted.
- **0x1B2C30** (954 insns): CMenuBoot update: state.h menu state machine (goto-loop, (flags >> 7) & 1 busy test, switch on negative state codes, yields cross-jumped into one 'li v1,1; b loop; sw state' tail); the open layout problem of these machines (see 0x192710 and the docs/lessons.md state.h entry: none of this shape is matched yet, CMenuNosave's best is DIFF 56); not attempted.
- **0x1A50C8** (1282 insns): CMenuInputKanji update: state.h menu state machine (goto-loop, (flags >> 7) & 1 busy test, switch on negative state codes, yields cross-jumped into one 'li v1,1; b loop; sw state' tail); the open layout problem of these machines (see 0x192710 and the docs/lessons.md state.h entry: none of this shape is matched yet, CMenuNosave's best is DIFF 56); not attempted.
- **0x1B1380** (1426 insns): CMenuLoad update: state.h menu state machine (goto-loop, (flags >> 7) & 1 busy test, switch on negative state codes, yields cross-jumped into one 'li v1,1; b loop; sw state' tail); the open layout problem of these machines (see 0x192710 and the docs/lessons.md state.h entry: none of this shape is matched yet, CMenuNosave's best is DIFF 56); not attempted.
- **0x176D30** (1564 insns): CMenuLoadMemorial update: state.h menu state machine (goto-loop, (flags >> 7) & 1 busy test, switch on negative state codes, yields cross-jumped into one 'li v1,1; b loop; sw state' tail); the open layout problem of these machines (see 0x192710 and the docs/lessons.md state.h entry: none of this shape is matched yet, CMenuNosave's best is DIFF 56); not attempted.
- **0x1945C0** (1906 insns): CMenuRecord update: state.h menu state machine (goto-loop, (flags >> 7) & 1 busy test, switch on negative state codes, yields cross-jumped into one 'li v1,1; b loop; sw state' tail); the open layout problem of these machines (see 0x192710 and the docs/lessons.md state.h entry: none of this shape is matched yet, CMenuNosave's best is DIFF 56); not attempted.
- **0x1602F8** (3426 insns): CGameEventObj update: state.h menu state machine (goto-loop, (flags >> 7) & 1 busy test, switch on negative state codes, yields cross-jumped into one 'li v1,1; b loop; sw state' tail); the open layout problem of these machines (see 0x192710 and the docs/lessons.md state.h entry: none of this shape is matched yet, CMenuNosave's best is DIFF 56); not attempted.
- **0x1E4C70** (2180 insns): CMiniGame6Res update: state.h menu state machine (goto-loop, (flags >> 7) & 1 busy test, switch on negative state codes, yields cross-jumped into one 'li v1,1; b loop; sw state' tail); the open layout problem of these machines (see 0x192710 and the docs/lessons.md state.h entry: none of this shape is matched yet, CMenuNosave's best is DIFF 56); not attempted.
- **0x2387D8** (204 insns): Unit237A88 texture upload (BITBLTBUF/TRXPOS/TRXREG/TRXDIR A+D chain via func_00237720 callbacks, 0xFFFF-qword chunks, returns qwords): masks fine with LOWB/BITK, logic complete; DIFF 88 from register allocation in the packet block: retail preloads the A+D constants into t-registers (t1..t3, t8, t9) and keeps the call args early, ours puts 0x52/0x61/1 into dead s-registers. The callers' prototype (Unit226AE8: 4 args) is short of the real six.
- **0x22FBF8** (96 insns): Unit22DE48, marked /* Handwritten function */ in the asm (unaligned lwl/lwr copy): not attempted, keep as asm.
- **0x23D470** (124 insns): Unit23C680 VRAM page free (lower the D_388E28 watermarks, then clear the 4-bit page bitmap D_386E28 over the swizzled block layout of D_002B95E0[k]); needs the unit decl changed to 'void func_0023D470(s32, s32, s32, s32)': DIFF 33, register numbering in the nested loops only (retail y = t1 shared with the first loop counter, x = a3, s = a2; ours x shares t1, y = t4, s = a3). Declaration-order perm, loop-variable reuse variants tried.
- **0x19C278** (98 insns): CStatusBaseSub19B8C8 hue setter (needs 'void SetHue19C278(u32 v);' in the class; VuFrac inline asm as in CCharaObj): DIFF 46, one root cause: retail moves v from a1 to a2 at entry (copy in the first bnez delay slot) and uses a2 for the range test, the m_unk18 store and GetHue's second argument; ours keeps v in a1 (bnezl + sltiu in the likely slot) and moves it before the call, which shifts the rest. Local copy and reading m_unk18 back tried.
- **0x2442C0** (108 insns): Unit243AB8 stream header handler (first block: copy the 0x20-byte format and 8-byte extra header from the request with __builtin_memcpy (ldl/ldr/sdl/sdr like retail), debug prints, then push the payload into the ring): DIFF 64, mostly the frame: retail's frame is 0x80 with 0x30 unused bytes below the saved registers (an inlined helper's dead local?) and it keeps the request pointer in s5, ours 0x50. Packed-struct copies give lwl/lwr field reads (worse).
- **0x1E3978** (148 insns): CMiniGame6 destructor (slot 0 of _vt$10CMiniGame6, the key method; drains the 0x9EC ring with an inlined modulo ring read): needs CMiniGame6Res converted to level 3 first (dataconv.py; its vt/ro pieces have no '# also'); not attempted this round.
- **0x1E3660** (198 insns): CMiniGame6Res virtual (vtable slot, jalr callbacks): same class as 0x1E3978, left with it for the level-3 conversion of CMiniGame6Res; not attempted.
- **0x14D7C8** (234 insns): CGameDBMgr::Func14D7C8 (vtable slot 23: a chara's 5 colour factors interpolated between the neighbouring table rows plus a seeded CRand jitter; needs 'void Func14D7C8(f32 *out, s32 idx, s32 v);' in the class): math, constants (0.2 must be written 0.20000001f: this as truncates '0.2f' to 0x3E4CCCCC, retail has ...CD) and the Rand form ((Next() << 16 | Next()) % 0x10000, cast to s32) are right; DIFF 193 from the clamp code (retail compares byte offsets with slt and adds the base afterwards, j via movz with a 0 default) and the scheduling of the unrolled 5-element block.
- **0x149670** (470 insns): CGameDBMgr::Func149670 (school.txt loader: SCHOOL table, flags, SCHOOL_PASS 0x50-byte records, per-school 9 stat bonuses, SCHOOL_SCHOLAR script; needs the CGameDBRecB0 fields m4/m8/m1C/m40/m64/m88/mAC, now in the unit): logic and layout complete, DIFF 49, all register choice: retail keeps this in s6 and the tok buffer address in s7, ours the other way round, which renumbers the loop counters too. (The SCHOOL_* strings are literals in the snippet.)
- **0x217FE8** (252 insns): Unit217F50 stream-play protothread (PtHdr at +0x2C, waits at lines 0x9F2/0x9FB/0xA0F/0xA24/0xA36/0xA79, then the 0x3F parameter push and a restart goto back to after the first wait): decoded (see the notes in this entry's history: waits on func_00213238, func_00219818, func_00219880 with a 0x2000/0x4000 mode, func_002198E8, func_0020F358 with 10 args) but not written; needs a Play variant struct (hdr at 0x2C, m40/m42 s16, m44..m4C) and the PTV macros of Unit215A38.
- **0x2176C0** (338 insns): Unit215A38 rxsnd protothread (PTV_BEGIN/PTV_WAIT_WHILE flavour, several waits and parameter pushes like 0x217FE8): not attempted this round.
- **0x216FF0** (370 insns): Unit215A38 rxsnd protothread (PTV_BEGIN/PTV_WAIT_WHILE flavour, several waits and parameter pushes like 0x217FE8): not attempted this round.
- **0x242468** (300 insns): Unit240FD8 glyph draw (flushes the pending TEX0/RGBA A+D like 0x242170 when D_38EFE4/D_38EFE0 are set, then the glyph sprite): contains the 0x242170/0x21BF50 TEX0 block whose scheduling is unsolved; not attempted.
- **0x19FE18** (166 insns): CStatusWin::Func19FE18 (9 slot brightness values from flag params 0x19-0x20, fade by m_unk58): DIFF 18, only the FP registers of the two '(f32)m_unk58 / (f32)nX' branches (retail: converted m_unk58 in f2, divisor f1, difference in f0; ours f0/f2/f1); the '(m58 - n) / n' branches match. Needed: the sums n1+n2 / n3+n4 written as expressions (retail keeps two copies), the output indexed off m_unk60 inside the loop. Implicit-conversion, local-ratio and reordered-term variants tried.
- **0x1A0D98** (170 insns): CStatusWin text draw helper (builds a local CEFontWork, __10CEFontWork ctor, then ~40 field stores of positions/colours/scale and the draw call): store-order puzzle of a 0x90-byte local; not attempted.
- **0x19E300** (178 insns): CStatusWin::Func19E300 (status line text via func_00185BD0 from flag values, truncated copy when m_unk64 == 2): logic complete, DIFF 45: the two values from flags 0x3B3D/m_unk50+0x28 sit in s6/s7 swapped against retail (s7/s6), and the final 'n*2 < strlen(buf)' test is if-converted to sltiu in ours (retail beql/b with li 1 / li 0). Declaration order, early returns vs single exit tried.
- **0x1A1040** (246 insns): CStatusWin: status window drawing/update (float layout math and CEFontWork setups); 246 insns, fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x239850** (176 insns): Unit237A88: GS/VIF packet builder with u64 handle fields (DImode masks now writable with BITK/LOWB) and many A+D quads; register allocation of the constant pool is the usual problem (see 0x2387D8); 176 insns, dsra32,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x244EE8** (176 insns): Unit243AB8: sound stream ring-buffer feeder (MIN macros calling the callee twice, see docs/lessons.md r3); 176 insns, fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x238C70** (220 insns): Unit237A88: GS/VIF packet builder with u64 handle fields (DImode masks now writable with BITK/LOWB) and many A+D quads; register allocation of the constant pool is the usual problem (see 0x2387D8); 220 insns, dsra32,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x212210** (318 insns): Unit210070: rxsnd PCM/sequence stream update (list walk with many callee results; frame-pointer/alloca style like the matched 0x211598); 318 insns, fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x2117D8** (284 insns): Unit210070: rxsnd PCM/sequence stream update (list walk with many callee results; frame-pointer/alloca style like the matched 0x211598); 284 insns, fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x238240** (158 insns): Unit237A88: GS/VIF packet builder with u64 handle fields (DImode masks now writable with BITK/LOWB) and many A+D quads; register allocation of the constant pool is the usual problem (see 0x2387D8); 158 insns, dsra32,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x211E30** (248 insns): Unit210070: rxsnd PCM/sequence stream update (list walk with many callee results; frame-pointer/alloca style like the matched 0x211598); 248 insns, fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1E8D68** (256 insns): CMiniGame6Res: mini game 6 (needs CMiniGame6Res converted to level 3 for its virtuals; float game logic); 256 insns, AT,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1F94C8** (232 insns): Unit1F4918: xmn sprite/packet builder (texture lookups through D_30E108 with error prints, TEX0/CLAMP/UV packing; the TEX0 OR-tree ordering of 0x21BF50 is still open); 232 insns, AT,u128,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1F9868** (232 insns): Unit1F4918: xmn sprite/packet builder (texture lookups through D_30E108 with error prints, TEX0/CLAMP/UV packing; the TEX0 OR-tree ordering of 0x21BF50 is still open); 232 insns, AT,u128,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x19C428** (194 insns): CStatusBase: status base window update/draw (float math, VU0 frac helper, virtual calls); 194 insns, AT,vu0. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1E6E80** (200 insns): CMiniGame6Res: mini game 6 (needs CMiniGame6Res converted to level 3 for its virtuals; float game logic); 200 insns, AT. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x23C8D8** (242 insns): Unit23C680: texture VRAM allocator (bitmap and LNode list code, see 0x23D470/0x23E088); 242 insns, AT. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1A0510** (306 insns): CStatusWin: status window drawing/update (float layout math and CEFontWork setups); 306 insns, AT,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x190E60** (296 insns): CMenuReviewResult: menu review result draw (float layout); 296 insns, AT,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x22C728** (226 insns): Unit22BFD0: file/stream system code; 226 insns, fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1FAEA8** (248 insns): Unit1F4918: xmn sprite/packet builder (texture lookups through D_30E108 with error prints, TEX0/CLAMP/UV packing; the TEX0 OR-tree ordering of 0x21BF50 is still open); 248 insns, AT,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x19C730** (344 insns): CStatusBase: status base window update/draw (float math, VU0 frac helper, virtual calls); 344 insns, AT,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1F5F28** (238 insns): Unit1F4918: xmn sprite/packet builder (texture lookups through D_30E108 with error prints, TEX0/CLAMP/UV packing; the TEX0 OR-tree ordering of 0x21BF50 is still open); 238 insns, AT,dsra32. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1F62E0** (238 insns): Unit1F4918: xmn sprite/packet builder (texture lookups through D_30E108 with error prints, TEX0/CLAMP/UV packing; the TEX0 OR-tree ordering of 0x21BF50 is still open); 238 insns, AT,dsra32. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x18FB50** (330 insns): CMenuGetMoney: menu get money draw (float layout); 330 insns, AT,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1F8E80** (402 insns): Unit1F4918: xmn sprite/packet builder (texture lookups through D_30E108 with error prints, TEX0/CLAMP/UV packing; the TEX0 OR-tree ordering of 0x21BF50 is still open); 402 insns, AT,u128,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x163DD0** (196 insns): CGameEventObj: game event object (huge frame, string buffers, virtual calls); 196 insns, AT,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x19B1F8** (408 insns): CStatusBase: status base window update/draw (float math, VU0 frac helper, virtual calls); 408 insns, AT,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1F9C08** (446 insns): Unit1F4918: xmn sprite/packet builder (texture lookups through D_30E108 with error prints, TEX0/CLAMP/UV packing; the TEX0 OR-tree ordering of 0x21BF50 is still open); 446 insns, AT,dsra32,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x18E1E0** (278 insns): CMenuCommon: menu common draw/update (switch with jump table, floats, VU0); 278 insns, AT,vu0,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1485E8** (410 insns): CGameDBMgr: game database table loader / query (same style as the matched Func14AAD0/Func1490F8: long, needs exact declaration order for spill slots); 410 insns, fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x14AE30** (422 insns): CGameDBMgr: game database table loader / query (same style as the matched Func14AAD0/Func1490F8: long, needs exact declaration order for spill slots); 422 insns, u128,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1FA300** (362 insns): Unit1F4918: xmn sprite/packet builder (texture lookups through D_30E108 with error prints, TEX0/CLAMP/UV packing; the TEX0 OR-tree ordering of 0x21BF50 is still open); 362 insns, AT,dsra32,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1FA8A8** (362 insns): Unit1F4918: xmn sprite/packet builder (texture lookups through D_30E108 with error prints, TEX0/CLAMP/UV packing; the TEX0 OR-tree ordering of 0x21BF50 is still open); 362 insns, AT,dsra32,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x22CAB0** (342 insns): Unit22BFD0: file/stream system code; 342 insns, fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1A4298** (466 insns): CStatusWin: status window drawing/update (float layout math and CEFontWork setups); 466 insns, AT,jtbl,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1FD5C8** (414 insns): Unit1F4918: xmn sprite/packet builder (texture lookups through D_30E108 with error prints, TEX0/CLAMP/UV packing; the TEX0 OR-tree ordering of 0x21BF50 is still open); 414 insns, AT,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x18D958** (396 insns): CMenuCommon: menu common draw/update (switch with jump table, floats, VU0); 396 insns, jtbl,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x19BA00** (444 insns): CStatusBase: status base window update/draw (float math, VU0 frac helper, virtual calls); 444 insns, AT,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x14EE18** (290 insns): CGameDBMgr: game database table loader / query (same style as the matched Func14AAD0/Func1490F8: long, needs exact declaration order for spill slots); 290 insns, AT,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x23A4D8** (320 insns): Unit23A1D8: texture page manager (LNode list code, see 0x23BA10); 320 insns, fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1F69D8** (304 insns): Unit1F4918: xmn sprite/packet builder (texture lookups through D_30E108 with error prints, TEX0/CLAMP/UV packing; the TEX0 OR-tree ordering of 0x21BF50 is still open); 304 insns, u128,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1F7E18** (306 insns): Unit1F4918: xmn sprite/packet builder (texture lookups through D_30E108 with error prints, TEX0/CLAMP/UV packing; the TEX0 OR-tree ordering of 0x21BF50 is still open); 306 insns, u128,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1E72D0** (672 insns): CMiniGame6Res: mini game 6 (needs CMiniGame6Res converted to level 3 for its virtuals; float game logic); 672 insns, AT,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x23D660** (280 insns): Unit23C680: texture VRAM allocator (bitmap and LNode list code, see 0x23D470/0x23E088); 280 insns, AT,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x18CEF0** (482 insns): CMenuCommon: menu common draw/update (switch with jump table, floats, VU0); 482 insns, AT,jtbl,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1A1418** (294 insns): CStatusWin: status window drawing/update (float layout math and CEFontWork setups); 294 insns, AT,jtbl,vu0. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1E80A0** (686 insns): CMiniGame6Res: mini game 6 (needs CMiniGame6Res converted to level 3 for its virtuals; float game logic); 686 insns, AT,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1E4630** (400 insns): CMiniGame6Res: mini game 6 (needs CMiniGame6Res converted to level 3 for its virtuals; float game logic); 400 insns, AT,jtbl,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1478E8** (522 insns): CGameDBMgr: game database table loader / query (same style as the matched Func14AAD0/Func1490F8: long, needs exact declaration order for spill slots); 522 insns, fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1E3FF8** (398 insns): CMiniGame6Res: mini game 6 (needs CMiniGame6Res converted to level 3 for its virtuals; float game logic); 398 insns, fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x164290** (378 insns): CGameEventObj: game event object (huge frame, string buffers, virtual calls); 378 insns, AT,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x15FE28** (248 insns): CGameEventObj: game event object (huge frame, string buffers, virtual calls); 248 insns, AT. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1B8CB0** (632 insns): CLayoutRes: layout resource parser (switch with jump table); 632 insns, AT,jtbl,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x19D5A0** (384 insns): CStatusWin: status window drawing/update (float layout math and CEFontWork setups); 384 insns, fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x14DCE0** (472 insns): CGameDBMgr: game database table loader / query (same style as the matched Func14AAD0/Func1490F8: long, needs exact declaration order for spill slots); 472 insns, fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1A64D0** (730 insns): CMenuInputKanji: kanji input menu draw (float layout, glyph grid); 730 insns, AT,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x240038** (610 insns): Unit23E868: glyph texture upload (BITBLT A+D with handle masks, pixel copy loop); 610 insns, u128,dsra32. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x242918** (474 insns): Unit240FD8: font text layout/draw (like the matched 0x243080 but with the TEX0 flush block of 0x242170); 474 insns, fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x243338** (480 insns): Unit240FD8: font text layout/draw (like the matched 0x243080 but with the TEX0 flush block of 0x242170); 480 insns. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x18C130** (830 insns): CMenuCommon: menu common draw/update (switch with jump table, floats, VU0); 830 insns, AT,jtbl,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x1A1CF0** (1442 insns): CStatusWin: status window drawing/update (float layout math and CEFontWork setups); 1442 insns, AT,jtbl,fp. Not attempted this round (time went to the smaller and better-understood functions first).
- **0x23F4A8** (178 insns): Unit23E868 glyph cache init (texture via func_0023DD40, entry and hash arrays via func_0023F458, free-list of 0x1C GEnt nodes on D_38EF58, cleanup path): logic, stack slots and n reuse right; DIFF 142 from s-register numbering only (retail per s0, n s1, w s2, tex s7, a s6, b s8, tw s5; ours shifted), which also changes the size. Declaration-order perm changes nothing.
- 0x286968 __frame_state_for (Lib285F80, 110 insns): DIFF 3 with the gcc 2.96 frame.c source (locals info, state, i, pc in that order; frame_state aligned 8 so the copy is ld/sd). Only `&pc` for the FDE loop: ours hoists `sp+0x4A4` into an s-register, retail recomputes it in the jal delay slot each iteration. Snip docs/hard/w2/hard_286968.snip.
- 0x278CC0 func_00278CC0 (Dk2779D8, 104 insns, mc RPC with a name argument): DIFF 1, one `addu` operand order in the name copy loop: retail `addu $4,$18,$16` (cmd + i), ours `addu a0,s0,s2` (i + cmd) for the `sb` to cmd->u.fn.name[i]; the load side (`name + i`) matches. Tried pointer/array/cast forms, declaration orders. Snip docs/hard/w2/hard_278CC0.snip.
- 0x274778 func_00274778 (Dk2735D0, 90 insns, print a double as "0.%d" "e+%d"): retail loads 0.1 (twice) and 1e6 from the unit's literal pool with the assembler macro form (`lui $1,%hi; ld $5,%lo($1)`), so the constants must be C literals emitted into Dk2735D0's .rodata at 0x2E9E98-0x2E9EAF: needs the unit's rodata converted first (not done; the unit shares the ro segment). Logic in snip (soft-float calls come out as dpcmp/dpsub/dpmul/dpdiv).
- 0x2877B8 __class_type_info::do_find_public_subobj (Lib285F80, 90 insns): DIFF 23 with the 2.96 tinfo.cc source (base_info as `int offset:29; bool is_virtual:1; access:2`, `p = 0;` hoisted). Left: objptr gets s3 instead of s1 and the `objptr + offset` add is scheduled into a different delay slot (retail recomputes it on the virtual path). Snip docs/hard/w2/hard_2877B8.snip.
- 0x284EF8 dpmul (Lib283858, 162 insns, fp-bit multiply with _fpmul_parts inlined, now in C): DIFF 47, same instruction sequence (64x64 via four __muldi3 calls with fp-bit's `(ps_hh__ << 32) & 0xffffffff00000000LL` and `((ps_hh__ >> 32) & 0xffffffffL)` forms); only the s-register allocation of pp_hl/res2/high differs (retail keeps them in s1, ours s6/t0). Snip docs/hard/w2/hard_284EF8.snip.
- 0x284558 throw_helper (Lib283858, 228 insns): the gcc 2.96 libgcc2 source with the cleanup/saved_state logic, DWARF_FRAME_REGISTERS 122 and the 0x478-byte frame_state gives the same blocks and frame (0xDF0, three frame_states at 0/0x480/0x900, spills at 0xD80..); register allocation differs throughout (retail hoists `my_udata + 0x460` as the copy-loop end into s7 and spills sub_udata; ours keeps sub_udata in s8). DIFF 216 (everything shifted). Snip docs/hard/w2/hard_284558.snip.
- 0x26DE80 func_0026DE80 (Dk26CFB0, 82 insns, libmpeg fromIPU DMA handler): DIFF 57; logic in snip (m0/m8/mC volatile, m10 not: retail CSEs `m10 - 1` across both tests). Retail keeps the state pointer in t1 and a hoisted 0x100 in t0, scheduling differs; ours is 2 insns longer.

### 0x275550 (Dk2752B8, sif cmd interrupt handler, 0x148) DIFF 27
docs/hard/w2/hard_275550.snip: everything but the copy-loop preheader. Retail tests the quad count with
`blez $5` and copies it to the doloop counter in the delay slot; ours emits `beqz` (gcc proves
(n+15)/16 >= 0 from the andi'd byte) and the loop registers shift by one. Tried i<cnt, i=cnt..>0,
while(cnt--), if(cnt>0), byte-step loop, ps2sdk `psize & 0xff` bitfield form.

### 0x27C970 (Dk27C020, alarm timer re-arm, 0x190) DIFF 9
docs/hard/w2/hard_27C970.snip: all but the scan loop's schedule. Retail puts `t = t2` before the
loop label (entry and `b` delay slot) and `t + 0x7333` in the `beqz e` delay slot; ours sinks
`t = t2` into that delay slot. Six loop spellings (while/for/for(;;), inline time helper, signedness)
all give DIFF 9; bk perm has nothing to permute.

### 0x26D9A8 (Dk26CFB0, field/frame picture setup, 0x1B8) DIFF 21
docs/hard/w2/hard_26D9A8.snip (perm-best order). Logic right; retail keeps `m->m870` in a3 ($7)
and builds the second call's args from it before storing mA0/m98, ours puts it in t1 and
schedules the `sd 1, 0xA0` early. bk perm on the 10 stores after the second call: 33 -> 21
(SDKC compile is slow, ~130 orders in 5 min).

### 0x26DFC8 (Dk26CFB0, IPU->mem transfer with DMA handler, 0x1C0) DIFF 6
docs/hard/w2/hard_26DFC8.snip (stores in bk perm's best order, 21 -> 6). Only a register swap left in
the `HWREG(0x1000B020) = 0xFFC0; HWREG(0x1000B000) = 0x100;` pair: retail keeps values in v1 and
the second address in a0, ours the other way round. `0x3FF << 6`, `0xFFC00 >> 4`, `(u16)` casts: no change.

### 0x262E30 (Dk262D28, libcdvd callback thread + its starter 0x262F00 merged by splat, 0xA0+0xD0)
docs/hard/w2/hard_262E30.snip: the thread loop 0x262E30 matches (V() on the D_002BBBF4/C18/BBD4/
D_41A814 stores and on D_002BBC1C; utest's DIFF 9 there is only the reloc-less `0x420000` hi
constants of the retail asm). The starter 0x262F00 (`r = 1; if (!D_002BBBD4) {GetThreadId,
ReferThreadStatus, CreateThread, StartThread} else {r = 0; ChangeThreadPriority}`) has r and the
hoisted %hi(D_002BBBD4) in swapped saved registers (retail r=s3, hi=s4). Setting `r = 1` at the end
of the if body fixes the registers but sinks the `li` into a delay slot. Needs D_41A814 in
config/aliases.ld (added).

### 0x27EB28 (Dk27DBB8, scePadPortOpen, 0x1E8) DIFF 9 (2 of them reloc-only)
docs/hard/w2/hard_27EB28.snip (bk perm best of all 5040 tail orders). Everything up to the RPC call
matches (a `q = D_424280[port][slot]` local fixes the port/slot register swap). Retail stores the
port entry as m10, *q, mC, m8, m0, m4 and loads the return value `D_424380[3]` after the stores;
ours sinks the stores/hoists the load differently (alias analysis sees D_424190, D_424280 and
D_424380 as distinct globals). The two reloc-only diffs are retail's raw `0x424380` lui/sw.

### 0x25C2C0 (Dk25A010, CSndWork deleting destructor, written without the vtable, 0x178) DIFF 78
docs/hard/w2/hard_25C2C0.snip: inline CList/CListTag dtors as W2Tag members. Retail's list-clear
loop tests at the top (`x = next->head ? 0 : next; beql x, exit`) and ends with `bnez x, top`
(reloading l->next in the slot); gcc here always proves x != 0 at the bottom and emits `b`, or
rotates the loop (`while`, `for(;;)`, `do {..} while (x)` all tried). Also the Unlink load order
(retail loads x->prev before x->next for `prev->next = next`).

### 0x25B048 (Dk25A010, CSndMgr slot 30: load a sound bank from a push buffer, 0x1E8) DIFF 49
docs/hard/w2/hard_25B048.snip (slot signature changed to (a, name, heap, src, n) in the unit's
CSndMgr). Logic matches; retail tests the allocation result inside each heap branch
(`beqz d, print` then `b common`) and allocates name/src/n/this to s3/s5/s6/s4 with the flag in s7;
ours inverts the per-branch test or merges it, and the saved-register assignment differs
(goto-to-cleanup, goto-to-print, in-branch print+return and merged `d &&` forms tried).

### 0x261470 (Dk260A60, MPEG audio Huffman decode of one section into the spectrum, 0x1F8) DIFF ~120
docs/hard/w2/hard_261470.snip: control flow, loops and arithmetic match instruction for
instruction; the saved-register assignment differs (retail: nbits s7, D_002E8898 row s6,
D_002E8808 row s5, end s1 copied in the prologue, `p` moved to a1) so every line shifts. All six
declaration orders tried (best 119).

### 0x263E80 (Dk2631E0, libcdvd S-command client init (sceCdInit-like, mode arg), 0x1F8) DIFF 26
docs/hard/w2/hard_263E80.snip: instruction-for-instruction except a permutation of the saved
registers (retail: mode s2, hi(D_002BBBD0) s6, hi(D_002BBC08) s1, hi(D_41AA50) s5, hi(D_41AA90)
s4, hi(D_002BCDC0) s7; ours mode s7, ...). Needs volatile reads of D_002BBBEC and the RPC-failure
block placed inline (`if (rpc < 0) { fail: ...; return mode != 8 ? 6 : -1; }`). The
`%hi(D_FFFFF)` spin-count relocations will also show as reloc-only diffs in utest.

### 0x288268 (Lib285F80, fp-bit.c __fpcmp_parts_d, 0x120) DIFF 55-66
docs/hard/w2/hard_288268.snip is the upstream source verbatim. The head confirmed it matches
byte-for-byte as C (`-x c -O2 -G0`), but Lib285F80 is compiled as C++ (tinfo.cc classes live in
the same unit) and the C++ front end lays out the isinf/iszero blocks differently (nested-if form:
DIFF 55). Needs the unit split at the fp-bit/tinfo boundary or a C-compiled slice.

### Big newlib functions: upstream newlib-1.9.0 is the source, blocked on jump tables
_dtoa_r 0x28F728 (dtoa.c, opcode similarity 0.96), _vfprintf_r 0x28DA28 (vfprintf.c, 0.93),
_strtod_r 0x28B970 (strtod.c, 0.91) and 0x28CCB8 all dispatch through `jtbl_` tables in the shared
`ro_tail` .rodata piece. Compiled as C their switches emit new jump tables into the unit's
.rodata, so they need the library .rodata split per unit (level 2) first. Generate the snippet from
the preprocessed upstream file the way build/bk/w2/malgen.py does for mallocr.c.
_malloc_r 0x289640 (mallocr.c with MALLOC_ALIGNMENT 16, no jump table): upstream is 408 insns,
retail 458: Sony changed it (DIFF ~400 as is); not attempted further.

### 0x2667C0 (Dk265918, libmpeg stream-id table match, 64-bit masks, 0x200) DIFF 126
docs/hard/w2/hard_2667C0.snip: semantics decoded (10-entry {id, mask} table at D_002BD7A8, nested
64-bit switches choose a sub-mask and a field width). Retail hoists `code >> 24`, `code >> 32` and
`(s32)(code & 0xFFFF)` before the loop but keeps `code & 0xFFFFFF0000` inside it, and lays out
the inner switches as compare trees (`bnel ... i++` continue paths); ours CSEs differently. SDK
compiler (991111, C++).

### 0x264078 (Dk2631E0, libcdvd N-command client init with retry fallback to 0x263E80, 0x1E8) DIFF 20
docs/hard/w2/hard_264078.snip: instruction for instruction except that the hoisted %hi registers
of D_002BBBD0 and D_41AA50 are swapped (retail s6/s5, ours s5/s6); the rest of the DIFF is utest
reloc noise (retail's raw `0x100000` spin count and `-0x5570` offsets). Needs `n = 0` before the
`if (D_002BBC08 < 0)` and volatile D_002BBBF0 reads. Same family as 0x263E80.

### 0x276E68 (Dk2752B8, fileio client init (sceFsInit-like), 0x204) DIFF 9 (some reloc-only)
docs/hard/w2/hard_276E68.snip: logic and calls match; a `q = &D_4203C0` pointer taken before
sceSifInitRpc reproduces the hoisted s0/s1 pair. Left: prologue save/`lui` scheduling and the tail
(retail materialises %hi(D_002BDB38) before %hi(D_002BDB34) around the unaligned 4-byte copies of the
reply). The reply is copied with lwl/lwr+swl/swr (a char[4] struct type); its real layout unknown.

### 0x253E78 (Dk252208, CShareTex::Func253E78 vtable slot 6: upload + GS CLAMP/TEX0 A+D packet, 0x218) DIFF 63
docs/hard/w2/hard_253E78.snip: everything up to the packet writes matches (`tex = m_unk8;` as its
own statement and `return n + m + 3`). The three PktAlloc(4) blocks (GIFtag 4/0x10000000/0xE,
CLAMP_1 region clamp, TEX0_1 like 0x2548F0) are scheduled differently: retail keeps the 16-byte
step in t5 and interleaves the header stores (0,8,4,0xC); store order perms don't help.

### 0x277540 (Dk2752B8, fileio RPC 4 (lseek-like, async flag 0x8000 registers the sema in D_002BDAB0), 0x238) DIFF 113
docs/hard/w2/hard_277540.snip: logic as retail (same shape as the matched 0x2773C0). Ours keeps
`fl & 0x8000` in a saved register and swaps the a/sema registers; retail recomputes the andi.
SDKC unit: a field-type search over W2RpcReq7 was not tried yet.
Same family, same blocker (not attempted separately): 0x277778 (Dk2752B8, RPC 2, 152 insns) and
0x2796D8 (Dk2779D8, RPC 0x16 with a 64-bit offset `sd` into the request, 142 insns).

### 0x259340 (Dk2571C0, AT3 stream slot allocate/init, 0x2C0) DIFF 52-63
docs/hard/w2/hard_259340.snip: logic complete (free-list pop, player open, ~30 field inits,
push on the active list, unwind path). Left: loop/start params in swapped saved registers and the
order of the ~18 inits (bk perm hill-climb 63 -> 52 in 900 tries).

### 0x268F50 (Dk268138, libmpeg form_predictions (mpeg2decode recon.c, Sony IPU variant), 450 insns) DIFF ~426 (4 short, shifted)
docs/hard/w2/hard_268F50.snip: full logic reconstructed from mpeg2decode's form_predictions:
frame/field pictures, MC_FRAME/FIELD/16X8/DMV, forward then backward with the average flag; the
predictor is func_00269658(d, src, sfield, dfield, yoff, h, bx, by, dx, dy, fieldflag, avg) and
field pictures pick their source from a local {{m1E0,m1F0},{m1E4,m1F4}} table. Retail keeps a 1 in
s3 (shared with `sel`) from the prologue and is 4 instructions longer; not tuned yet. calc_DMV
(0x26AD28, matched) and the macroblock loop (0x26B208, matched) are its neighbours.

### 0x299510 / 0x2996C0 (Lib298A78, linkonce DB-table loaders: per line, read a name, intern it in the user-flag script mgr, parse its conditions with Func148EC8; records 0x28 / 0x24 bytes) DIFF 77
docs/hard/w2/hard_299510.snip (W2Rec28 struct-array form; same pattern as CGameDBMgr::Func14A620).
Retail strength-reduces to a field pointer, a record pointer and a down-counter (num), with the
record arguments in different saved registers; ours keeps the index. 0x2996C0 is the same template
for 0x24-byte records (fields at 0x10..0x20).

### 0x27B798 (Dk27A100, kernel TLB init: three tables of 16-byte entries via 0x27B6B8, `mtc0 $6` Wired + sync.p, then fill to 48 entries)
Not C: the entry index lives in $25 (t9) across `jal 0x27B6B8`, which only hand-written code
does (the callee must preserve t9). Leave as INCLUDE_ASM.
- 0x267CA0 (Dk265918, sceMpegGetPicture-style decode loop) switches through jtbl_002E9570 in ro_tail: blocked like the big newlib functions (needs the library .rodata split).

### 0x2715B0 (Dk26FC10, planar shadow projection matrix from plane normal + light, point/directional, 100 insns) DIFF ~99
docs/hard/w2/hard_2715B0.snip: maths decoded (both branches). Retail loads n[0..2] once, keeps lx/ly
in $f16/$f15 and lz in $f14 and reuses the three products; its FP register choice and store
schedule differ from every form tried (plain, local n, product temporaries).

### 0x274FE8 (Dk2735D0, sceSifInitCmd, 160 insns) DIFF ~159 (one extra saved register)
docs/hard/w2/hard_274FE8.snip: full sifcmd init (cmd data at D_41D198, 32 handlers at D_41D1C0,
32 sregs at D_41D340 cleared from the top, the two system handlers 0x274F90/0x274F70, D_STAT/SIF
checks, DMAC 5 handler, then either the sub-address handshake or the 0x80000002 init packet).
Ours uses one more saved register (s5) so everything shifts; SDKC strict-aliasing field types
(W2CmdData) not searched yet.

### 0x26E260 (Dk26CFB0, libmpeg CSC through the IPU with the 0x26E188 DMA feed, 162 insns) DIFF 5 (v0/v1 swap only)
docs/hard/w2/hard_26E260.snip: matches except the first `if (IPU_CTRL & 0x4000) IPU_CTRL =
0x40000000;` where retail holds the address in v1 and the value in v0 (ours the reverse). The rest
of utest's DIFF is reloc-only lui noise. Volatile int/u32, pointer local, bit-shift tests tried.

### 0x278E60 (Dk2779D8, fileio chstat-like RPC 0xD: name + 64-byte stat + mask, 144 insns) DIFF 3
docs/hard/w2/hard_278E60.snip (adds a `cs` member to the unit's McCmd union). Same blocker as
0x278CC0: the name-copy store address is `addu c, i` in retail and `addu i, c` in ours (declaration
order, unsigned i, pointer/array spellings tried), plus one store pair swapped.

### Not attempted this round (triaged; addr, unit, insns, note)
- 0x24FAF0 func_0024FAF0 (Dk24FAF0, 58 insns): CResCacheUnit key-method destructor: needs Dk24FAF0 converted to level 3 first
- 0x260878 func_00260878 (Dk25E340, 122 insns): filter-bank interpolation, 4x256 loop with two coefficient tables (decoded in my notes: per-channel 8-step ramp)
- 0x261668 func_00261668 (Dk260A60, 136 insns): not attempted (size/time)
- 0x261888 func_00261888 (Dk260A60, 138 insns): not attempted (size/time)
- 0x287C88 func_00287C88 (Lib285F80, 114 insns): not attempted (size/time)
- 0x2574B8 Func2574B8__9CFontWorkffPfT3PPCcPvi (Dk2571C0, 150 insns): not attempted (size/time)
- 0x257B70 Func257B70__9CFontWorkffPfT3PPCcPvi (Dk2571C0, 150 insns): not attempted (size/time)
- 0x261068 func_00261068 (Dk260A60, 162 insns): not attempted (size/time)
- 0x26D468 func_0026D468 (Dk26CFB0, 164 insns): IPU field/frame picture output, heavy spilling (11 live values)
- 0x2562B0 Func2562B0__9CFontWorkPvPcii (Dk254AA8, 130 insns): not attempted (size/time)
- 0x268640 func_00268640 (Dk268138, 170 insns): not attempted (size/time)
- 0x2566A0 Func2566A0__9CFontWorkPCci (Dk254AA8, 164 insns): not attempted (size/time)
- 0x26D110 func_0026D110 (Dk26CFB0, 174 insns): not attempted (size/time)
- 0x2779D8 func_002779D8 (Dk2779D8, 176 insns): not attempted (size/time)
- 0x27CBC0 func_0027CBC0 (Dk27C020, 168 insns): not attempted (size/time)
- 0x263BA0 func_00263BA0 (Dk2631E0, 184 insns): not attempted (size/time)
- 0x256DC8 func_00256DC8 (Dk254AA8, 154 insns): not attempted (size/time)
- 0x2571C0 func_002571C0 (Dk2571C0, 190 insns): not attempted (size/time)
- 0x2669C0 func_002669C0 (Dk265918, 196 insns): not attempted (size/time)
- 0x26E9B0 func_0026E9B0 (Dk26CFB0, 222 insns): not attempted (size/time)
- 0x257840 func_00257840 (Dk2571C0, 204 insns): not attempted (size/time)
- 0x269658 func_00269658 (Dk268138, 264 insns): IPU form_prediction (Sony), 264 insns, heavy spilling
- 0x261AB0 func_00261AB0 (Dk260A60, 90 insns): not attempted (size/time)
- 0x255200 func_00255200 (Dk254AA8, 184 insns): not attempted (size/time)
- 0x254AA8 func_00254AA8 (Dk254AA8, 288 insns): not attempted (size/time)
- 0x26B4C8 func_0026B4C8 (Dk26A870, 298 insns): mpeg macroblock_modes/decode (Sony IPU VLC), 298 insns
- 0x287378 func_00287378 (Lib285F80, 272 insns): not attempted (size/time)
- 0x254248 func_00254248 (Dk252208, 298 insns): not attempted (size/time)
- 0x265D98 func_00265D98 (Dk265918, 116 insns): not attempted (size/time)
- 0x286518 func_00286518 (Lib285F80, 276 insns): frame.c with a jump table in ro_tail
- 0x256A00 func_00256A00 (Dk254AA8, 242 insns): jump table in ro_tail
- 0x2883B0 func_002883B0 (Lib285F80, 324 insns): not attempted (size/time)
- 0x282E40 func_00282E40 (Dk2828C0, 346 insns): not attempted (size/time)
- 0x285728 func_00285728 (Lib283858, 350 insns): frame.c execute_cfa_program-like (gcc 2.96), 350 insns
- 0x2828C0 func_002828C0 (Dk2828C0, 352 insns): not attempted (size/time)
- 0x26FF38 func_0026FF38 (Dk26FC10, 118 insns): not attempted (size/time)
- 0x287138 func_00287138 (Lib285F80, 144 insns): not attempted (size/time)
- 0x263330 func_00263330 (Dk2631E0, 198 insns): not attempted (size/time)
- 0x282230 func_00282230 (Dk280098, 420 insns): not attempted (size/time)
- 0x277C98 func_00277C98 (Dk2779D8, 222 insns): not attempted (size/time)
- 0x281B98 func_00281B98 (Dk280098, 422 insns): not attempted (size/time)
- 0x2523F8 Func2523F8__7CDebOutPCcPiN32i (Dk252208, 418 insns): CDebOut printf-style formatter, 418 insns
- 0x289640 func_00289640 (Lib2888C0, 458 insns): _malloc_r: upstream newlib mallocr.c (MALLOC_ALIGNMENT 16) is 408 insns, retail 458: Sony changes
- 0x26F580 func_0026F580 (Dk26CFB0, 420 insns): jump table in ro_tail
- 0x25D608 func_0025D608 (Dk25C438, 352 insns): not attempted (size/time)
- 0x2748E0 func_002748E0 (Dk2735D0, 382 insns): jump table in ro_tail (vsprintf-like)
- 0x276930 func_00276930 (Dk2752B8, 238 insns): jump table in ro_tail
- 0x261C18 func_00261C18 (Dk260A60, 316 insns): not attempted (size/time)
- 0x266FA8 func_00266FA8 (Dk265918, 364 insns): not attempted (size/time)
- 0x260A60 func_00260A60 (Dk260A60, 386 insns): not attempted (size/time)
- 0x28CCB8 func_0028CCB8 (Lib28AE50, 766 insns): jump table in ro_tail (newlib)
- 0x2586C8 Func2586C8__FP8CAt3Node (Dk2571C0, 782 insns): jump table in ro_tail
- 0x28B970 func_0028B970 (Lib28AE50, 966 insns): _strtod_r: upstream newlib strtod.c (0.91 similar), jump table in ro_tail
- 0x28F728 func_0028F728 (Lib28D8B0, 1178 insns): _dtoa_r: upstream newlib dtoa.c (0.96 similar), jump table in ro_tail
- 0x28DA28 func_0028DA28 (Lib28D8B0, 1436 insns): _vfprintf_r: upstream newlib vfprintf.c (0.93 similar), jump table in ro_tail
## sm
Lane sm (state.h machines, 2026-10-16). Recipe in docs/lessons.md ## sm; best attempts in docs/hard/sm/.
- **0x13D518** CEventObj commands 0x5C-0x60 (no machine loop: busy test, then a switch on the state):
  matches in utest (docs/hard/sm/hard_13D518.snip: four identical cases written out so GCC uses a jump
  table; `on = SlotAsInt(7, 1) != 0` before the m4 test; `goto busy` to a `return 1` at the end).
  Not ported: its jump table jtbl_002D5B80 is an INCLUDE_RODATA piece of CEventMesRes.cpp. CEventObj's
  .rodata really runs to 0x2D5BB0 (D_002D58B0..D_002D5B98 are only used by CEventObj); moving the
  yaml boundary and running dataconv fix re-split the literals and broke several matched CEventObj
  functions, so it needs a data-lane pass first. Needs `int Cmd13D518(CSvmWork *, int, int);`.
- **0x100770** CLogoMain::Update (two gosubs `Push(); SetVar(sm, 0, RET); goto sub;` into a fade sub that
  returns with `m_state = Get(); Pop(); goto loop;`; the pad skip `goto skip` lands in the caller's -0x90
  code): same length, ~20 words: the first gosub computes the file pointer before the Push test into
  `$18` with the hi part in `$2` (ours `$3`, so reorg moves the lo into the slot); the `Pop(4)` after the
  `for (; Get(0) < Get(1); Inc) { yield; case -0x87:; }` loop gets a cse2 copy of the loop's file pointer
  (`daddu $19,$20`; retail uses `$20`); a goto-built loop fixes the Pop but makes the yield fall through;
  the second Push check is `bnez` with `daddu $6,$20` from the fall-through in retail (ours `bnezl`).
  Needs `s32 m_unkCC; s32 m_unkD8;` in the unit's CLogoMain.
- **0x100358** CBootMain::Update (asserts): aligned diff 15. Asserts as an inline
  `Check(s32 v, const char *file, s32 line)` (the file pointer is then computed before the test, as
  retail), `Pop` as `m_depth = (s16)m_depth - 1` (addiu -1), the stack through `s32 *p = m_stack;`
  after the check in Var(); waits as `for (;;) { case L: if (c) break; yield }`. Left: `done` in `$4`
  (retail `$3`) and GCSE's insertion for the -0x42 dispatch edge hoisted into the dispatch block by
  ifcvt (same branch-probability problem as 0x16BB20).
- **0x19A9D8** CStatusBase update (mode machine on m_state 0..4 with gotos between states): same
  length, block order differs: retail puts two then-blocks (`m_state = 0; goto a0` and `V4(); m_state = 2;
  goto b5`) before their tests (rotated loops); written as plain labels/gotos here.


## y1

Lane y1 (Dk*/Lib* retry, 2026-10-16). Best attempts in docs/hard/y1/hard_<ADDR>.snip.

- Hand-written assembly (spimdisasm "Handwritten function": `addi`, `eret`, `cache` loops, MMI with fixed
  $8-$15/$24/$25 and no frame), not C: 0x26296C, 0x262A0C, 0x262A8C, 0x2629CC, 0x262AF0 (Dk260A60 MPEG audio
  SIMD), 0x269C98, 0x269D10, 0x269DA8, 0x269E60, 0x269F30, 0x269FE0, 0x26A098, 0x26A190, 0x26A290, 0x26A330,
  0x26A3E0, 0x26A4C0, 0x26A5A8, 0x26A680, 0x26A750 (Dk268138 IPU/CSC SIMD), 0x26A870, 0x26A988, 0x26A9E8
  (Dk26A870), 0x275698 (Dk2752B8 SyncDCache-style `cache 0x18` loop, `li 0xFFFFFFC0` as lui/ori),
  0x27C580 (Dk27C020 `eret`), 0x27B9C0 (Dk27A100, `eret`).
- 0x262FD0 (Dk262D28, cd callback: copy two 0x40-byte buffers to uncached and cached dest, then
  `j func_00262D90(&D_002BBC18)`): DIFF 12, only $8/$9 swapped (retail: source base `u+0x10` in t0, dest in
  t1); tried local/decl orders, int-typed dest, index forms.
- 0x266738 (Dk265918, `u64 f(u32 i, u64 v)`: `D_2BD7A8[i].m0 | v << sh`, sh 24/32/0 by `m8 ==
  0xFFFF000000 / 0xFF00000000`): DIFF 33; retail has a 16-byte frame with no saves and a `==, >, ==` compare
  tree; every switch/if form (991111) if-converts with `xor; movn` and no frame.
- 0x25D1A0 (CSndWork::Func25D1A0, call unit slot 1 on each unit with next fetched before the call): DIFF 18,
  retail keeps the unit in t0 and builds `a0 = u + delta` from it; ours allocates u to a0 (scheduling of the
  vtable load vs the `next` load). Same First form as the matched finders.
- 0x25D008 (Func25D008, stop or delete units of a tree): DIFF 44, retail's three iterators (it $18, cur $16,
  next $17) and `if (!f()) {stores} else delete` block order not reproduced.
- 0x250B80 (Dk24FAF0, n-th unit over the free then used list): DIFF 23, retail keeps `&m_used`/`&m_free` in
  $8/$4 and picks the head with `bnel k`, ours folds the offsets into the loads.
- 0x250978 (CResCache::Func250978, move idle units to the back of the used list): DIFF 37-41, same
  three-iterator shape as 0x25D008; retail also keeps the dead `n->next = n` store of the unlink.
- 0x24FA50: DIFF 4 (`r = 0; if (i < 4)
  r = m1C[i]` gets the address add before the branch in retail); 0x24F9B0: DIFF 5.
- MMI string routines (strncmp 0x289D68, memset 0x289FB0, strcpy/strlen/strcmp 0x28B2D4/0x28B3E8/0x28B190 and
  the rest of the newlib EE ones): cc1 rejects TImode compares ("unsupported wide integer operation"), so the
  u128 loops need inline asm; not attempted.
- 0x267E58 (Dk265918, w2 snippet): DIFF 3-4, the `ok` temp of `func_0026D110(s, 0) && func_0026CFB0(s)` lands
  in v0 (retail v1, copied to s2 in both branch slots); tried &&/?:/if forms and int/u32/u8 temps.
- 0x27D3A0 (Dk27C020, set alarm time): DIFF 4 after the 27D288 fixes (ENT before DI, volatile cur): retail stores
  `e->elapsed = t` before the dsubu, ours `e->start = now` first (u64 stores; statement orders tried).
- 0x27CF30 (Dk27C020, alarm alloc, w2's volatile version): DIFF 17, all registers shifted by one ($7/$6/$5/$4
  vs a2/a1/a0/v1) plus one store; 720 statement orders tried.
- 0x276E68 (Dk2752B8, fio init): DIFF 6 with `D_4203C0.m0 = 0; q->m4 = 0;` and `int *p = &D_002BDB38`: only
  the prologue order (retail saves $16 before `lui $16`).
- 0x275398 (Dk2752B8, sceSifSendCmd core, w2 snippet): DIFF 17; retail indexes `dma[count]` from `sp + count*16`
  per field and reads D_41D1A0 through a raw lui; type search over the dma/header fields found nothing.
- 0x277138 (Dk2752B8, fio open RPC with varargs mode): first draft DIFF 154: retail frame 0x150 with nine
  s-registers ($30 holds %hi(D_41EC40)) and the name copy peeled differently; not pursued.
- 0x249428 (Dk2470E8, xap link by ini key): DIFF 12-16; the literal order needs "not found" first but retail's
  block order puts the link print last; if/else, goto and r-variable forms tried.
- 0x247210 (Dk2470E8, range check): DIFF 13; s0/s1 roles swapped (retail p in s17) and the tail compare.
- 0x250C28 (Dk24FAF0, unit info switch): DIFF 13; case 5's index helper keeps the walker in $2 and the Next
  result in $3 (`daddu $2,$3` each step); RFirst/RNext and ternary helpers tried.
- 0x2683F8 (Dk268138, IPU DMA ref tags): DIFF 2, only the order of the hoisted `li 3` and `ori 0x0FFFFFFF`
  (statement and expression orders tried).
- 0x280E88 (newlib __ieee754_sqrtf, no-denormal): DIFF 8, scheduling of the mantissa setup; upstream text with
  `one - tiny` folded, statement orders tried.
- 0x25A098 (CSndMgr ctor): DIFF 6 with real member ctors (`CSndWorkM() asm("func_0025C230")`): only the
  0x80/-1 constant registers and the 0x1C/0x2C store order; 27 orders and chained forms tried.
- 0x26F0D8 (Dk26CFB0, libgraph sceGsSetDefLoadImage): MATCHES in utest (docs/hard/y1/hard_26F0D8.snip: psm
  switch with `qwc = 0` preset, giftag0 + the A+D registers, then giftag1 last), but the compiled jump table makes
  the object's .rodata 16-aligned and Dk26CFB0's .rodata piece starts at 0x2E9928 (8-aligned), so the whole piece
  shifts by 8. The libgraph code is its own object in retail (its .rodata starts at the 16-aligned 0x2E9A00 with
  "sceGsSetDefLoadImage: too big size"); port after the unit is split there.
- 0x25D3E0 note: matched (see below). 0x257DC8 (AT3 free-list init): DIFF 16 with `CAt3Node **fl =
  &D_002BA1E4`; structure right, registers one off (retail fl in $2).
- 0x246100 (memheap init): DIFF 2 again (utest hill-climb over the 12 header stores, list-insert helper and
  `CMemGlobal *g` min/max form fixed the rest): retail stores free.next (0x38) right after the magic, ours
  numNodes; docs/hard/y1/hard_246100.snip.
- Hand-written MMI also at 0x26228C and 0x262448 (Dk260A60 polyphase filter, fixed $8-$15/$24/$25).
- 0x2574B8 / 0x257B70 (CFontWork line layout, Dk2571C0): first draft of 0x2574B8 in docs/hard/y1/hard_2574B8.snip
  (DIFF 75): logic decoded (per line: copy the 0xA0-byte context, measure with func_002571C0, align by ctx m70,
  set colour/scale, draw with f | 2; width = max, height = sum + line gap); left: the shared 0.0 register (sum in
  f22, the per-line zero copy in f21), right-to-left argument loads for the stack copy's colour calls.
- 0x256DC8 (Dk254AA8, draw one glyph, optional shadow pass): docs/hard/y1/hard_256DC8.snip, DIFF ~70-86: the pass
  loop is `for (i = 0; i < n; i++)` (loop.c turns it into the $19 down-counter copied from n in $6); left: the
  CFontWork slot-1 vcall (vptr at 0x7C) loads the vtable before the float args and shares one call tail between
  cases 0 and 1; tried (ch, l, x, y), (x, y, ch, l), (ch, x, y, l) slot signatures.
- 0x24EF88 (CTaskTag tree run): logic in docs/hard/y1/hard_24EF88.snip (PMF calls on m_task, children walked by
  prev or next with the next item fetched before the recursive call, delete when parentless and taskless);
  retail recomputes `(t+8+i)+0x43` for m_count[1][i] where ours hoists `i+67` into one more s-register.
- 0x2468F8 (Dk245648, memheap alloc; lane d1's DIFF-1 snippet is lost): reconstructed in
  docs/hard/y1/hard_2468F8.snip (DIFF 133, every block present): left is the first/last test layout
  (retail `beql first` then `bnez last; nop; b fail`) and the case-0/1 search loops' block order.
- 0x261AB0 (Dk260A60, MPEG audio: 23-word history copy buf[256..278] -> buf[0..22] as a struct copy, then the
  128-sample overlap split with D_002E8ED0): DIFF 79 (docs/hard/y1/hard_261AB0.snip); retail's EE block copy
  tests `(src | dst) & 7` (no folding of the +0x400) and recomputes `ch * 0x660` after the copy.
- 0x2883B0 (Lib288388, tinfo2 __throw_type_match_rtti_2, 324 insns): the 2.95 source with dynamic_cast spelled
  as `p ? func_00288A88(vtbl[0].fn, __tfX, 0, p + vtbl[0].delta, __tf9type_info, p) : 0` gives the right calls
  and blocks; DIFF 245 (retail uses s8 too and falls into the `beqz p` join); docs/hard/y1/hard_2883B0.snip.
- 0x287C88 (__check_eh_spec + __check_null_eh_spec), 0x287E50 / 0x287EB8 (__throw_bad_cast / __throw_bad_typeid
  with std::uncaught_exception merged): try/catch landing pads (func_00284A38 calls after the throw); Lib286B20 is
  built -fno-exceptions, so these need their own -fexceptions object.
- 0x2745B8 (sio putc, C 991111): DIFF 4-7 (docs/hard/y1/hard_2745B8.snip); retail copies the return value
  before the volatile `sb` and leaves `jr` unfilled; asm barriers/`.set volatile` variants did not get both.
- 0x297D20 (Lib2975F0, float CRand range): DIFF 2 still (docs/hard/y1/hard_297D20.snip): `mtc1 $0` before the
  field load; member/FLD, compare-direction and early/late return forms tried.
- 0x284558 (throw_helper): DIFF 215 with the frame_state typedef and inline get_reg/next_stack_level from this
  unit; register allocation throughout (as w2 wrote).
- 0x27CE60 / 0x27CEB0 (Dk27C020 timer read): retail's `lwu` reads and unfilled `jr` slot look like inline asm;
  five C forms 17-20 off.
- 0x27CBC0 (Dk27C020 alarm interrupt handler, 168 insns): 16-byte register save stride and `sync; ei` at the
  end (not the 991111 SDKC prologue of the rest of the unit); not attempted.
- 0x29189C (memchr), 0x28B000 / 0x28B570 / 0x28B728 (Lib28AE50): newlib EE MMI routines (pcpyld/psubb), as the
  string ones above.
- 0x292E20-0x293088 (Lib290990 tail, six functions): still need the SDKC (991111) split w2 described.

Matched since (were on the w2/d1 lists above): 0x24F6A8, 0x24A128 (func_002496D0 declared throw()),
0x279EF0 (`asm("")` after the store keeps `move v0,zero` behind it), 0x2838D8, 0x283D20 (abort noreturn),
0x2843A8 (`if (c) do ... while (c)`), 0x2844A0 (inline get_reg), 0x285EF0, 0x285728 (2.96 end_fde_sort
with fde_split's static marker = D_424594), 0x285FD8 / 0x286968 / 0x286518 (Lib285F80 as C), 0x286E20,
0x287138, 0x287378, 0x2877B8 (convert_to_base inline), 0x287A70, 0x287B00, 0x288A00, 0x288F40, 0x28CB88 /
0x28D8F8 (real FILE field types), 0x2926D0 (upstream d2b `if (d1)`), 0x24BAF0.
## cv
Unit conversion lane (2026-10-16). Matched here (HARD.md entries above that name them are done): 0x288268,
0x17D240, 0x10AF00, 0x10B108, 0x10B8B8, 0x12D440, 0x12DC48, 0x16D548, 0x126E38, 0x118248, 0x11BD20,
0x127888, 0x186E90, 0x113090, 0x172C88, 0x173050, 0x1BD958, 0x1BD700, 0x1C4710, 0x1C9E90, 0x1D4E98,
0x1DEA78, 0x1DF0F8, 0x12E768, 0x1B3DD0, 0x11D670, 0x11F038, 0x120AC8, 0x121788, 0x1225F0, 0x143A90,
0x144808, 0x144070, 0x28DA28, 0x28CCB8, 0x28F728 (+ quorem), 0x28B970, 0x2539A0, 0x253B00, 0x254730,
0x10BAC8. Best attempts below are saved as docs/hard/cv/hard_<ADDR>.snip.
### 0x185BD0 (CChrSchoolWin, was CMenuExam: exam/job/school name formatter, switch on kind 1..9, 172 insns) DIFF 37
Unblocked by moving CMenuExam.cpp's tail into the CChrSchoolWin unit (its jump table jtbl_002DAE90 sits
after 9CMenuExam). Control flow, literals and frame match; only the s-register numbering differs
(retail p4=s0, p6=s1 (shared with the case-2/default record pointer), dst=s2, p5=s3, p2=s4, kind=s5,
p7=s6, p8=s7; ours p6=s0, dst=s1, p7=s2, p4=s3, ...). Tried: param types, declaration placement,
if/else shapes in case 1. Next: other ways to write the three error tails (they are cross-jumped).
### 0x1B55A0 (CMenuMgrSub1B4768, was CMenuMgr: glyph cell lookup for a char, switch with jump table, 122 insns) DIFF 33
Unblocked by the new CMenuMgrSub1B4768 unit (jump table and "*** no suppot char" literal now compiled in
place). Everything matches except the block layout at the end: retail keeps case ' ' (x=0x7A, y=0x3C) in
the cross-jumped tail of the other one-store cases and the default (print, then the same two stores with
$3/$2 swapped) separate at the end; ours cross-jumps case ' ' into the default's identical stores. Tried:
break/return, a shared `n` with one final store, ' ' first, fall-through from default.
### 0x286518 (Lib285F80, frame.c execute_cfa_insn, EE-GCC 2.96 flavour, 276 insns) DIFF ~247 (block layout)
Unblocked: Lib285F80 is frame.c only now, with its .rodata (jump table jtbl_002EABB0) from the object.
The source is gcc-2.95.2's execute_cfa_insn plus 2.96's DW_CFA_def_cfa_expression (0x0F: loop over
execute_stack_op 0x2863F8), DW_CFA_GNU_negative_offset_extended (0x2F) and the "reg == cfa_reg: record
nothing" test in DW_CFA_offset/offset_extended; frame_state layout {cfa, eh_ptr, cfa_offset, cfa_exp,
args_size, reg_or_offset[123] @0x20, cfa_reg @0x3F8, saved[] @0x3FC, cfa_how @0x477, saved_state @0x478}.
Every case's code matches; what differs is cross-jumping: ours merges DW_CFA_offset's decode+test into
the offset_extended case, retail only shares the final stores, and insn lives in $5 in retail. Next: the
2.96 frame.c text itself (gcc CVS around 2000-06) would settle the statement shapes.
### 0x267CA0 (Dk265918, libmpeg sceMpegGetPicture, switch on the decoder state, 110 insns) DIFF ~90
Unblocked by Dk265918's .rodata at level 2 (jump table and messages compiled in place). The flow
matches with goto loops (a for/while hoists the -1 constant into an s-register); left: the two
"print + return -1" blocks get cross-jumped in ours (retail keeps both, the "aborted" one placed before
the loop), and r/ret take s3/s2 where retail has s2/s3.
### 0x10D360 (CTexCacheMgr, was CList: texture blit with flip by pixel mode, switch, 154 insns) DIFF ~8
Unblocked by merging CList.cpp and CEFontWork's tail into the CTexCacheMgr unit (level 2). All five
cases match (BlitFlip32/16/8 sibcalls, the 24-bit and 4-bit inline loops); only the default
`Func235DE0("*** unknown pixel mode '%X'\n", psm)` is a sibcall in ours (`j`) and a `jal` falling into
the epilogue in retail. Tried: int/void prototypes with and without throw().
### 0x24DC40 (Dk2497C0, CExpr assignment statement `name op= expr`, 124 insns) DIFF 31 (tail only)
Unblocked by Dk2497C0 at level 2 ("," and the "unknown assignment symbol" message compiled in place).
Everything matches up to the final `func_0024D340(e, name, &val)` (store the value): retail has two
copies of it (the kind == 3 / computed path ending `bnel v0, ret; li v0, 1`, and the kind < 0 path
ending `beqz v0, ret; li v0, 1`), ours one copy returning `sltu`. Tried if/else shapes and returns
written as `x ? 1 : 0`, `if (!x) return 0; return 1;`.
- 0x26F0D8 (Dk26CFB0, libgraph sceGsSetDefLoadImage): MATCHES in utest (docs/hard/y1/hard_26F0D8.snip: psm
  switch with `qwc = 0` preset, giftag0 + the A+D registers, then giftag1 last), but the compiled jump table makes
  the object's .rodata 16-aligned and Dk26CFB0's .rodata piece starts at 0x2E9928 (8-aligned), so the whole piece
  shifts by 8. The libgraph code is its own object in retail (its .rodata starts at the 16-aligned 0x2E9A00 with
  "sceGsSetDefLoadImage: too big size"); port after the unit is split there.
- 0x25D3E0 note: matched (see below). 0x257DC8 (AT3 free-list init): DIFF 16 with `CAt3Node **fl =
  &D_002BA1E4`; structure right, registers one off (retail fl in $2).
- 0x246100 (memheap init): DIFF 2 again (utest hill-climb over the 12 header stores, list-insert helper and
  `CMemGlobal *g` min/max form fixed the rest): retail stores free.next (0x38) right after the magic, ours
  numNodes; docs/hard/y1/hard_246100.snip.
- Hand-written MMI also at 0x26228C and 0x262448 (Dk260A60 polyphase filter, fixed $8-$15/$24/$25).
### 0x24D460 (Dk2497C0, CExpr primary: number / variable / unary op / parentheses, switch, 144 insns) DIFF ~98 (layout)
Unblocked by Dk2497C0 at level 2 (four messages and the jump table compiled in place, in retail order
with case 0x12 '(' first). Same open question as 0x24DC40: retail returns the result of the unary-op
callback as `bnel v0, ret; li v0, 1` and keeps the "back brace error" call cross-jumped with "brace
error"; ours turns every `return f() ? 1 : 0` / `if (!f()) return 0; return 1;` into `sltu`. Find that
idiom once (it recurs in this parser) and both functions should fall.
- **0x1AD800** CMenuSysscr02::Update (gosubs into a cursor/colour sub, PMF background loader, states in
  do-while loops): same length, ~11 words, all register choice/scheduling: the 6-path's constants (`5` in
  `$3`, `-1` in `$2` with the `m_state` store first; ours either regs or store order), the old cursor
  in the 0x1000 branch (`$4`, ours `$3`), and the sub's `Move1B6488(x, y)` loading `this` last (in the
  jal slot; ours first). Notes: `case -0x147: default: goto out;` gives retail's case tree (10 nodes),
  the return cases (`case -0xE3: Play(0); goto y10C;`) sit right after their gosubs so cross-jumping
  keeps the Play(4) copy, the PMF is `&CMenuSysscr02::LoadFlags` (a .rodata constant between the
  literals), func_00245818's int return through an asm-named declaration. Needs `s32 m_unkAC;
  s32 m_unkB4[3];` in the unit's class.
- **0x19F6C0** CStatusWin::Update19F6C0 (mode machine on m_state 0..5, states in do-while loops as
  0x19A9D8): DIFF 3, one register: retail compares `m_unk64 != 3` (in the moved `c3` block) with the
  register that already holds 3 for the `m_state == 3` test (`$4`); ours uses `m_state`'s register
  (`$3`): cse1 follows the jump to c3 and the m_state pseudo becomes the class's canonical register
  (make_regs_eqv). Tried `3 == m_state`, a local copy, `m_unk64 != m_state`, a switch. Needs
  `void Update19F6C0();` in the unit's CStatusWin (`bk addm`).
- **0x1831A0** CMenuTutorSelectedSub182108::Update1831A0 (three windows, a Push(4) counting frame as
  CMenuMemorial): DIFF 18, all one register swap in the Push(4) frame: retail keeps the stack base
  (`sm + 8`, a GCSE pseudo) in `$16` and the slot values in `$18`; ours the other way round (global
  alloc gives the base `$18`). The snippet also needs `asm volatile("")` after `Pop(4)` so the depth
  store stays before the `m_unk50` load (as CMenuMemorial before its fix). Wait shapes that work here:
  the -0x248 wait as `while (m_state != 1) { yield; case -0x248:; }` (the -1 code then jumps over the
  deleted yield as retail's `b`), the three-window wait as one `||` condition, the color loop indexed
  (`GetColor(&c[i], i + 12)`). Needs `void Update1831A0();` in the unit's class (`bk addm`).- **0x18B080** CMenuCommon::Update (three sub-objects created with operator new, three PMF background
  loads, two gosubs into a refresh sub): DIFF 9, one register swap: `done` and the D_002A5468 hi part
  are `$20`/`$21` in retail and the other way round here (global alloc priority: done 36 refs over the
  whole loop vs the hi part 13 refs). Everything else matches with func_00245818 returning int, the
  -0xE6 wait as the last statement of a do-while (its continuation then starts at the loop's exit label,
  so reorg does not annul the branch), `case -0x158: goto out;`. Snippet: docs/hard/sm/hard_18B080.snip.
- **0x1056A8** CTitleMain::Func1056A8 (title background map switcher: fade out/in, a Push/Var wait on
  func_00251BA8, never ends): DIFF 20, one register swap: `&m_snd` is `$30` and D_0029F398's hi part
  `$23` in retail, the other way round here (global alloc priority 0.58 vs 0.50). Layout matches with
  the state.h literals taken from the unit's INCLUDE_RODATA symbols (D_002D1990/D_002D19B0 are shared
  with the still-asm Func101480, so the snippet carries its own CStateMachine copy using them), the
  waits as do-while/while forms, and the common tail behind a `t1:` label. Needs `f32 m_unk7C0;` in the
  unit's CTitleMain (pad7B4 shrinks to 0xC).
- **0x18A548** CMenuChildStatus::Update (child status screen, 15 states, PMF CChrBodyWin::Func1889F8):
  same length (564 words), 104 differing lines, all block placement: the 6-check `bnel`/`bne` (as
  0x1A7818); the -0xFB dispatch constant CSE'd into `$16` where retail rematerializes `li $2,-0xFB` in
  the -0xF5 yield; -0xF0's `a & 0x20` block (Play(3); SetMode5; goto y112) and -0xFB's `m48 == 3`
  then-block sit on the other side of their entries; the -0x12A else path and the shared Play(3)→s4
  block, and -0x146's pad-test block, likewise. do-while wrappers around -0xFB made it worse (125-136).
  Needs the CChrBodyWin.h method decls (committed) and the unit's CMenuChildStatus fields from the
  snippet. Snippet: docs/hard/sm/hard_18A548.snip.

## lb

- **0x287C88 / 0x287E50 / 0x287EB8** (Lib287920, exception.cc: __check_eh_spec + __check_null_eh_spec,
  __throw_bad_cast, __throw_bad_typeid + uncaught_exception): the 2.95 exception.cc source (with `p->value`,
  `unexpected`/`terminate` declared noreturn, uncaught_exception without `throw()`) compiled with -fexceptions
  gives the whole function set and the .gcc_except_table (0x2EB680, 0x7C bytes, byte for byte) except
  **4 words**: in __check_eh_spec's third loop retail has `beql v0,zero` (ours `beqz`, same delay slot), and in
  both __throw_bad_X retail keeps the vtable in s1 (`lui v0; addiu s1,v0`) and the eh_alloc result in s0
  (ours the other way round). Flag sweeps (-g*, -G8, -fno-inline (beql right, rest wrong),
  -fasynchronous-exceptions (beql right, bad_cast worse), -fno-elide-constructors, inline limits, vtable
  thunks, honor-std, the SDK compilers) and class-definition variants (implicit/explicit ctors and dtors,
  throw() specs, friend) did not get both. Full attempt: docs/hard/lb/Lib287920_eh.cpp (drop-in for
  src/Lib287920.cpp). Porting it also needs: the yaml piece
  `{start: 0x1EC680, type: .rodata, name: Lib287920, linker_section: .gcc_except_table}` in place of
  ro_libtail, and aliases.ld lines for the names -fexceptions code calls: `__eh_alloc` 0x283D20, `__throw`
  0x2848E8, `__rethrow` 0x284A38, `__start_cp_handler` 0x2879D8, `__cp_push_exception` 0x287A70,
  `__cp_pop_exception` 0x287B00, `__uncatch_exception` 0x287C28, `terminate__Fv` 0x287920,
  `_$_8bad_cast` 0x29E800, `_$_10bad_typeid` 0x29E898, `_$_13bad_exception` 0x29ECE8, and
  `D_002EB680 = 0x002EB680` (.data refers to the table's start). With all that the image differs in those 4
  words only.
- **0x13D6D8** CEventObj::Func13D6D8 (runs the m_FCB8 command queued by Cmd13D518: map flag /
  map-effect enable / sound fade / map-effect apply on two func_00134100 values): DIFF 71, same
  length; the busy test's temps (`ori $3` + flags in `$2` after `daddu $19,$2`) and the
  `if (!e) return 0;` exits that retail cross-jumps onto the Log path's `b; daddu $2,0` differ.
  Snippet: docs/hard/sm/hard_13D6D8.snip (CSceneSet::FindA, CSndWorkReal::FadeTo declared in the unit).
