# Hard / deferred functions

Functions skipped for now, with the reason. Pick them up when the blocker is solved.

## Blocked on class layout (vtables)

- **Constructors that store a vtable pointer** (e.g. 0x1B3BA8 CMenuProcess, 0x19A830
  CStatusBase, 0x12D8E8 CEnvResObj, 0x168DC8 CInterfRes, 0x110AB0 CMotionRes, 0x111748,
  0x126E18, 0x128110). Writing them needs `virtual` methods, and declaring the class's first
  non-inline virtual in this unit makes GCC emit the vtable and typeinfo into our object's
  .data/.rodata, which breaks the layout. Needs: the unit's .data/.rodata split out of the
  big data blobs first (docs/units.md), or the vtable declared so that it is emitted elsewhere.
  Note: in GCC 2.96 the vptr sits after the fields of the class that introduces it (0x54,
  0x58 in the menu classes).
- **Virtual calls through the vptr** (e.g. 0x186E90 CChrSchoolWin vt[0]: `lw vptr,0x58;
  lh delta; lw pfn; jalr`): need the same virtual declarations; the call itself compiles to
  this old-ABI {delta, index, pfn} entry pattern.

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
