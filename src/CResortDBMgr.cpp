#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct CResortDBEntry20 {
    u8 data[0x14];
};
class CPushBuf {
public:
    void Func248E00();
    int Func248EB0();

    u8 m_data[0xC];
};
class CResortDBMgrSub171DD0 {
public:
    void Init();
    void Clear();

    u8 pad0[0x4];
    CPushBuf m_buf;           // 0x4
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    u8 pad18[0x10];
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
};

struct CResortDBEntry {
    u8 data[0x10];
};
extern CResortDBEntry D_002A36F0[];
extern CResortDBEntry D_002A3850[];
class CResortDBMgr {
public:
    CResortDBEntry20 *GetEntryC(s32 i);
    CResortDBEntry *GetEntryA(s32 i);
    CResortDBEntry *GetEntryB(s32 i);


};

extern CResortDBEntry20 D_002A3760[];
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00171D18);

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00171D58);

void CResortDBMgrSub171DD0::Clear() {
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk28 = 0;
    m_unk2C = 0;
}

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00171DE8);

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00171EC0);

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00171F68);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA0D8);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA0E0);

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_001722D8);

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00172498);

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00172640);

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00172690);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA108);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA118);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA128);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA138);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA148);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA158);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA160);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA170);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA180);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA190);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1A0);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1B0);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1C0);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1D0);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1E0);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1F0);

void CResortDBMgrSub171DD0::Init() {
    m_buf.Func248E00();
    Clear();
}

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00172920);

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00172968);

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00172A60);

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00172B28);

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00172B68);

CResortDBEntry *CResortDBMgr::GetEntryA(s32 i) {
    if (i < 1 || i > 6) {
        return 0;
    }
    return &D_002A36F0[i];
}

CResortDBEntry20 *CResortDBMgr::GetEntryC(s32 i) {
    if (i < 8 || i > 11) {
        return 0;
    }
    return &D_002A3760[i];
}

CResortDBEntry *CResortDBMgr::GetEntryB(s32 i) {
    if (i < 12 || i > 38) {
        return 0;
    }
    return &D_002A3850[i];
}
