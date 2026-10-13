#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMapSndRes {
public:
    void Func127928();
    void CallFunc127928();


};

class CMapSndResSub1278F8 {
public:
    void Reset();

    s8 m_unk0;                // 0x0
    u8 pad1[0x1F];
    s32 m_unk20;              // 0x20
    s32 m_unk24;              // 0x24
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
    s32 m_unk30;              // 0x30
    s32 m_unk34;              // 0x34
    s32 m_unk38;              // 0x38
    u8 pad3C[0x104];
    s32 m_unk140;             // 0x140
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127850);

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127888);

void CMapSndResSub1278F8::Reset() {
    m_unk0 = 0;
    m_unk20 = 0x80;
    m_unk24 = 0;
    m_unk28 = 0;
    m_unk2C = 0;
    m_unk30 = 0;
    m_unk34 = 0x80;
    m_unk38 = 0;
    m_unk140 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", Func127928__10CMapSndRes);

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127968);

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127AB0);

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127C10);

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127C48);

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127D38);

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127E70);

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127E98);

void CMapSndRes::CallFunc127928() {
    Func127928();
}

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127EE0);

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00128040);
