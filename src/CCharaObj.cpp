#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CCharaObjPart1C {
public:


    u8 pad0[0x2C];
    f32 m_unk2C;              // 0x2C
};
class CCharaObjPart20 {
public:


    u8 pad0[0x18];
    f32 m_unk18;              // 0x18
};
class CCharaObjPart24 {
public:
    void Func10DC80();
    void Func10DBD8();
    void Func10DB70();


    u8 pad0[0x18];
    s32 m_unk18;              // 0x18
};
class CCharaObj {
public:
    void Part24Func10DC80();
    void Part24Func10DBD8();
    void Part24Func10DB70();
    void SetPart1CUnk2C(f32 v);
    void SetPart20Unk18(f32 v);
    void Func114050(s32 a, s32 b);
    void CallFunc114050(s32 b);
    void SetUnk150(s32 v);
    void SetPart24Unk18(s32 v);
    s32 GetPart24Unk18();
    void SetUnk354(u32 i, s32 v);
    s32 GetUnk354(u32 i);

    u8 pad0[0x1C];
    CCharaObjPart1C* m_part1C; // 0x1C
    CCharaObjPart20* m_part20; // 0x20
    CCharaObjPart24* m_part24; // 0x24
    u8 pad28[0x128];
    s32 m_unk150;             // 0x150
    u8 pad154[0x200];
    s8 m_unk354[6];           // 0x354
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00112FE0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113090);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113128);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113368);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113418);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001135F0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113758);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113860);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113898);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001138E8);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113978);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113BC0);

void CCharaObj::SetPart1CUnk2C(f32 v) {
    if (m_part1C) {
        m_part1C->m_unk2C = v;
    }
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113C38);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113E88);

void CCharaObj::SetPart20Unk18(f32 v) {
    if (m_part20) {
        m_part20->m_unk18 = v;
    }
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113F00);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113F38);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113F80);

void CCharaObj::CallFunc114050(s32 b) {
    Func114050(0, b);
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", Func114050__9CCharaObjii);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001141F0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00114670);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001146A8);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00114828);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00114958);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00114C40);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00114C78);

void CCharaObj::Part24Func10DB70() {
    if (m_part24) {
        m_part24->Func10DB70();
    }
}

void CCharaObj::SetUnk150(s32 v) {
    m_unk150 = v;
}

void CCharaObj::Part24Func10DBD8() {
    if (m_part24) {
        m_part24->Func10DBD8();
    }
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00114D18);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00114D70);

void CCharaObj::SetPart24Unk18(s32 v) {
    if (m_part24) {
        m_part24->m_unk18 = v;
    }
}

s32 CCharaObj::GetPart24Unk18() {
    return m_part24 ? m_part24->m_unk18 : -1;
}

void CCharaObj::Part24Func10DC80() {
    if (m_part24) {
        m_part24->Func10DC80();
    }
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00114EA0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115278);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115328);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115388);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001153E8);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115470);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001156A8);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115830);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001158C0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115938);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001159A0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001159E8);

void CCharaObj::SetUnk354(u32 i, s32 v) {
    if (i < 6) {
        m_unk354[i] = v;
    }
}

s32 CCharaObj::GetUnk354(u32 i) {
    s32 r = -1;
    if (i < 6) {
        r = m_unk354[i];
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115A98);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115B48);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115C28);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115D00);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115E48);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00116A40);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00116A98);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00116AE0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00116B98);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00116D60);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001170F0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00117198);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001173C0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00117468);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00117668);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00117898);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00117AC8);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00117B48);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00117DA0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00117E38);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00117E78);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00117F10);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00117F60);
