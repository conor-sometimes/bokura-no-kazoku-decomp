#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
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

class CUnk295E20 {
public:
    void Func295E20(int v);
};
class CMapSndRes {
public:
    void Func127928();
    void CallFunc127928();

    s32 m_unk0;               // 0x0
    u8 pad4[0xC];
    CMapSndResSub1278F8 m_unk10; // 0x10
    u8 pad154[0xC];
    CUnk295E20 m_unk160;      // 0x160
};

class CMapSndResSub127C10 {
public:
    void Init();
    u8 pad0[0x28];
    s32 m28;                  // 0x28
    f32 m2C;                  // 0x2C
    f32 m30;                  // 0x30
    s32 m34;                  // 0x34
    s32 m38;                  // 0x38
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

void CMapSndRes::Func127928() {
    m_unk0 = 0x80;
    m_unk10.Reset();
    m_unk160.Func295E20(0);
}

INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A08);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A38);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A48);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A60);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A68);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A70);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A78);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A80);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A88);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A90);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A98);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AA0);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AA8);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AB0);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AB8);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AC0);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AC8);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AD0);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AD8);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AE0);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AE8);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AF0);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AF8);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4B00);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4B08);
INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127968);

INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4B58);
INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127AB0);

void CMapSndResSub127C10::Init() {
    m28 = 1;
    m34 = 0x80;
    m38 = 0x30;
    m2C = 20.0f;
    m30 = 80.0f;
}

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127C48);

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127D38);

INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4B98);
INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127E70);

INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4BA0);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4BA8);
INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127E98);

void CMapSndRes::CallFunc127928() {
    Func127928();
}

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00127EE0);

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", func_00128040);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4BE0);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4C28);
