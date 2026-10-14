#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CCharaResRec {
public:
    s32 m_id;                 // 0x0
    s32 m4;                   // 0x4
    s32 m8;                   // 0x8
    s32 mC;                   // 0xC
    s32 m10;                  // 0x10
    u8 pad14[0x20];
};
class CCharaResData {
public:
    s32 m_num;                // 0x0
    CCharaResRec *m_recs;     // 0x4
};
class CCharaRes {
public:
    s32 GetCurFlags();
    s32 GetCur8();
    s32 GetCurC();
    s32 Get44(s32 i);
    s32 Get48(s32 i);
    char *GetName112030(s32 i);
    int Func1120A0();
    int Set112B60(CCharaResData *d, s32 id);
    void Release112C00();
    void Func112E88(s32 v);

    CCharaResData *m_data;    // 0x0
    u8 m_unk4[0x10];          // 0x4
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    u8 pad1C[0x4];
    char m_unk20;             // 0x20
    u8 pad21[0x1F];
    s32 m_cur;                // 0x40
    s32 *m_unk44;             // 0x44
    s32 *m_unk48;             // 0x48
    s8 *m_unk4C;              // 0x4C
    s32 m_unk50;              // 0x50
    u8 pad54[0xC];
    s32 m_unk60;              // 0x60
    s32 m_unk64;              // 0x64
    s32 m_unk68;              // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
    s32 m_unk78;              // 0x78
    f32 m_unk7C;              // 0x7C
    s32 m_unk80;              // 0x80
    s32 m_unk84;              // 0x84
    s32 m_unk88;              // 0x88
    s32 m_unk8C;              // 0x8C
    s32 m_unk90;              // 0x90
    s32 m_unk94;              // 0x94
    s32 m_unk98;              // 0x98
    s32 m_unk9C;              // 0x9C
    s32 m_unkA0;              // 0xA0
    u8 padA4[0x4];
    u8 m_unkA8[0xC];          // 0xA8
    u8 padB4[0x4];
    s32 m_unkB8;              // 0xB8
};
extern char D_002D3400[];
extern "C" char *func_00111128(void *p);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CCharaRes", func_00111E00);

INCLUDE_ASM("asm/nonmatchings/CCharaRes", func_00111E60);

s32 CCharaRes::GetCurFlags() {
    if (m_data == 0 || m_cur < 0) {
        return -1;
    }
    return m_data->m_recs[m_cur].m4 & 0xF;
}

s32 CCharaRes::GetCur8() {
    if (m_data == 0 || m_cur < 0) {
        return -1;
    }
    return m_data->m_recs[m_cur].m8;
}

s32 CCharaRes::Get44(s32 i) {
    if (i < 0 || i > m_unk50 - 1 || m_unk44 == 0) {
        return -1;
    }
    return m_unk44[i];
}

s32 CCharaRes::Get48(s32 i) {
    if (i < 0 || i > m_unk50 - 1 || m_unk48 == 0) {
        return 0;
    }
    return m_unk48[i];
}

s32 CCharaRes::GetCurC() {
    if (m_data == 0 || m_cur < 0) {
        return -1;
    }
    return m_data->m_recs[m_cur].mC;
}

INCLUDE_ASM("asm/nonmatchings/CCharaRes", func_00112030);

INCLUDE_ASM("asm/nonmatchings/CCharaRes", func_001120A0);

INCLUDE_ASM("asm/nonmatchings/CCharaRes", func_001120F8);

INCLUDE_ASM("asm/nonmatchings/CCharaRes", func_001121F0);

INCLUDE_ASM("asm/nonmatchings/CCharaRes", func_001122C0);

INCLUDE_ASM("asm/nonmatchings/CCharaRes", func_00112710);

INCLUDE_ASM("asm/nonmatchings/CCharaRes", Func112A80__9CCharaRes);

INCLUDE_ASM("asm/nonmatchings/CCharaRes", func_00112B60);

void CCharaRes::Release112C00() {
    Func112E88(0);
    if (m_data) {
        m_data = 0;
        m_cur = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/CCharaRes", func_00112C40);

INCLUDE_ASM("asm/nonmatchings/CCharaRes", Func112E88__9CCharaResi);
