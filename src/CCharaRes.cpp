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
#include "CList.h"
// Owned parts deleted through their virtual destructors (vptr at 0x1C / 0xC).
class CCharaResPart14 {
public:
    virtual ~CCharaResPart14();
    u8 pad0[0x1C];
};
class CCharaResPart18 : public CListTag {
public:
    virtual ~CCharaResPart18();
};
class CFaceRes {
public:
    CFaceRes();
    u8 pad0[0x54];
    virtual ~CFaceRes();
};
extern "C" void func_0010F6F8(CFaceRes *p);
class CCharaRes {
public:
    CCharaRes();
    virtual ~CCharaRes();
    void Func112A80();
    void Init1121F0();
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
    CCharaResPart14 *m_unk14; // 0x14
    CCharaResPart18 *m_unk18; // 0x18
    CFaceRes *m_unk1C;        // 0x1C
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
    s32 m_unkA4;              // 0xA4
    u8 m_unkA8[0xC];          // 0xA8
    s32 m_unkB4;              // 0xB4
    s32 m_unkB8;              // 0xB8
};
extern char D_002D3400[];
extern "C" char *func_00111128(void *p);
// @decl-end

CCharaRes::CCharaRes() {
    m_unk1C = new CFaceRes;
    m_unkA4 = -1;
    m_unk8C = -1;
    m_unkB4 = 0;
    Init1121F0();
}

CCharaRes::~CCharaRes() {
    Func112A80();
    if (m_unk1C) delete m_unk1C;
}

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

INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3400);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3408);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3410);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3418);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3420);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3428);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3430);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3438);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3440);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3448);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3450);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3458);
INCLUDE_ASM("asm/nonmatchings/CCharaRes", func_00112030);

INCLUDE_ASM("asm/nonmatchings/CCharaRes", func_001120A0);

INCLUDE_ASM("asm/nonmatchings/CCharaRes", func_001120F8);

INCLUDE_ASM("asm/nonmatchings/CCharaRes", Init1121F0__9CCharaRes);

INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3460);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3468);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3470);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3478);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3480);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3488);
INCLUDE_ASM("asm/nonmatchings/CCharaRes", func_001122C0);

INCLUDE_ASM("asm/nonmatchings/CCharaRes", func_00112710);

void CCharaRes::Func112A80() {
    func_0010F6F8(m_unk1C);
    Func112E88(0);
    Release112C00();
    if (m_unk44) {
        delete[] m_unk44;
        m_unk44 = 0;
    }
    if (m_unk48) {
        delete[] m_unk48;
        m_unk48 = 0;
    }
    if (m_unk4C) {
        delete[] m_unk4C;
        m_unk4C = 0;
    }
    if (m_unk18) {
        delete m_unk18;
        m_unk18 = 0;
    }
    if (m_unk14) {
        delete m_unk14;
        m_unk14 = 0;
    }
    Init1121F0();
}

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
