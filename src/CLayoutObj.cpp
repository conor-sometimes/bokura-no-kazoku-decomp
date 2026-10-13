#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CLayoutObjPart {
public:


    u8 pad0[0x8];
    s32 m_unk8;               // 0x8
};
class CLayoutObjSub1B9E60 {
public:
    s32 GetPartUnk8();

    u8 pad0[0x4];
    CLayoutObjPart* m_part;   // 0x4
};
class CLayoutObjSub1BA0A0 {
public:
    void Reset();

    u8 pad0[0x50];
    s32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    f32 m_unk58;              // 0x58
    f32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
};
class CLayoutObj {
public:
    void Func1B9E28();
    void CallFunc1B9E28();
    void SetUnk30(f32 x, f32 y);
    void SetUnk1DC(s32 v);
    void CopyUnk1DC();
    void ResetUnk1E0();
    int Func1BA0C0();
    void Func1B9FF0();
    void Func1BA0F0();
    int Func1BA1A0();

    s32 m_unk0;               // 0x0
    u8 pad4[0x4];
    s32 m_unk8;               // 0x8
    u8 padC[0x24];
    f32 m_unk30;              // 0x30
    f32 m_unk34;              // 0x34
    u8 pad38[0x1A4];
    s32 m_unk1DC;             // 0x1DC
    s32 m_unk1E0;             // 0x1E0
    s32 m_unk1E4;             // 0x1E4
    s32 m_unk1E8;             // 0x1E8
    u8 pad1EC[0x8];
    s32 m_unk1F4;             // 0x1F4
};

void Func225088();
int Func2250C0();
void Func225240(s32 v);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001B9D40);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001B9D70);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001B9DD0);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", Func1B9E28__10CLayoutObj);

s32 CLayoutObjSub1B9E60::GetPartUnk8() {
    return m_part ? m_part->m_unk8 : 0;
}

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001B9E78);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001B9EC0);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001B9F60);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001B9F90);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", Func1B9FF0__10CLayoutObj);

void CLayoutObjSub1BA0A0::Reset() {
    m_unk50 = 0;
    m_unk54 = 0;
    m_unk5C = 1.0f;
    m_unk58 = 1.0f;
    m_unk60 = 0;
}

int CLayoutObj::Func1BA0C0() {
    Func225088();
    Func225240(m_unk8);
    return Func2250C0();
}

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", Func1BA0F0__10CLayoutObj);

int CLayoutObj::Func1BA1A0() {
    Func1B9FF0();
    Func1BA0F0();
    return Func1BA0C0();
}

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BA1D0);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BA210);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BA440);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BA520);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BA5D0);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BA650);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BA728);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BA7E8);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BADB0);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BB438);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BBD08);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BBD78);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BBDB0);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BBDE8);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BC320);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BC360);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BC6A8);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BC870);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BC900);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BCAF8);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BCF60);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BCFB0);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BD188);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BD1E0);

void CLayoutObj::CallFunc1B9E28() {
    Func1B9E28();
}

void CLayoutObj::SetUnk30(f32 x, f32 y) {
    if (m_unk0) {
        m_unk30 = x;
        m_unk34 = y;
    }
}

void CLayoutObj::SetUnk1DC(s32 v) {
    m_unk1DC = v;
}

void CLayoutObj::CopyUnk1DC() {
    m_unk1E0 = m_unk1DC;
}

void CLayoutObj::ResetUnk1E0() {
    m_unk1E4 = 0;
    m_unk1E8 = 0;
    m_unk1E0 = 0;
    m_unk1F4 = -1;
}

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BD320);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BD420);
