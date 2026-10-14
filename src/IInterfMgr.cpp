#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CSndWork {
public:
    void Func25C840(s32 a, s32 b = 0, s32 c = 0);
    int Func25C990(s32 a);
    int Func25CAC0(s32 a);
    s32 Func25CF58(s32 a);
};

class CCharaObj {
public:
    void Func114D70(s32 a, s32 b);
};

class CInterfTimer {
public:
    void Reset() {
        m_unk4 = -1;
        m_unk2 = 0;
        m_unk0 = 0;
    }

    s16 m_unk0;               // 0x0
    s16 m_unk2;               // 0x2
    s32 m_unk4;               // 0x4
};

class CInterfMgr {
public:
    void ResetUnkD4Below(s32 v);
    void ClearUnkDE8();
    void Func1692D0();
    void Func169308();
    s32 IsVoicePlaying();
    void SetChara(CCharaObj *c);
    void StopVoice();
    int Func1698A0();
    void SetFade(s32 on, s32 dur);
    void DrawText(s32 a, f32 x, f32 y);
    void Func169950();
    void Func16B1C8();
    void Func16BB20();
    void Func16AA28();
    void Func16B2B0();
    void Func16C0B8();
    void Func16A650(s32 a, f32 x, f32 y, f32 w, f32 h);

    u8 pad0[0x8];
    CInterfTimer m_timer;     // 0x8
    u8 pad10[0x40];
    CSndWork m_snd;           // 0x50
    u8 pad51[0x6B];
    CCharaObj *m_chara;       // 0xBC
    s32 m_unkC0;              // 0xC0
    s32 m_unkC4;              // 0xC4
    s32 m_voice;              // 0xC8
    s32 m_unkCC;              // 0xCC
    u8 padD0[0x4];
    s32 m_unkD4;              // 0xD4
    u8 padD8[0x814];
    s32 m_unk8EC;             // 0x8EC
    u8 pad8F0[0x20];
    s32 m_unk910;             // 0x910
    s32 m_unk914;             // 0x914
    f32 m_unk918;             // 0x918
    f32 m_unk91C;             // 0x91C
    u8 pad920[0x4C8];
    s32 m_unkDE8;             // 0xDE8
};

class CFlagWork {
public:
    int Func1091B0(s32 id);
};
extern CFlagWork *D_002A26E4;
extern s32 D_002A35E0[];
u64 Func23AA40();

//@sym __builtin_new 0x245648
//@sym __10CNameDBMgr 0x16C778
class CNameDBMgr {
public:
    CNameDBMgr() throw();

    u8 pad0[0x60];
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_00169128);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_001691D0);

void CInterfMgr::Func1692D0() {
    Func169950();
    Func16B1C8();
    Func16BB20();
}

void CInterfMgr::Func169308() {
    Func16AA28();
    Func16B2B0();
    Func16C0B8();
}

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_00169340);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_001693B0);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_00169450);

void CInterfMgr::StopVoice() {
    if (m_voice) {
        m_snd.Func25C840(m_voice, 0, 0);
        m_voice = 0;
    }
    m_timer.Reset();
    m_unkD4 = 8;
    m_unkC0 = 0;
    m_unkCC = 0;
}

void CInterfMgr::ResetUnkD4Below(s32 v) {
    if (m_unkD4 < v) {
        m_unkD4 = 0;
    }
}

void CInterfMgr::SetChara(CCharaObj *c) {
    m_chara = c;
    if (c && m_voice && !m_unk8EC) {
        m_chara->Func114D70(1, m_snd.Func25CF58(m_voice));
    }
}

s32 MaxLineLen(const char *s) {
    s32 n = 0;
    s32 max = 0;
    while (*s) {
        if (*s < 0) {
            s += 2;
            n++;
        } else if (*s == '@' && s[1] == 'n') {
            if (n >= max) {
                max = n;
            }
            s += 2;
            n = 0;
        } else {
            s++;
        }
    }
    return n < max ? max : n;
}

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_001696A0);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_00169718);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_00169788);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_001698A0);

s32 CInterfMgr::IsVoicePlaying() {
    s32 r = 0;
    if (m_unk910) {
        r = m_snd.Func25C990(m_unk910) != 0;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", Func169950__10CInterfMgr);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016A650);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016A998);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", Func16AA28__10CInterfMgr);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016B178);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", Func16B1C8__10CInterfMgr);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", Func16B2B0__10CInterfMgr);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016BA80);

void CInterfMgr::ClearUnkDE8() {
    m_unkDE8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", Func16BB20__10CInterfMgr);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016BD00);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", Func16C0B8__10CInterfMgr);

CNameDBMgr *CreateCNameDBMgr() {
    return new CNameDBMgr;
}

s32 FindInterfIndex(s32 i) {
    s32 k;
    if (i < D_002A26E4->Func1091B0(0x27)) {
        i = D_002A26E4->Func1091B0(i + 0x28);
    }
    for (k = 0; D_002A35E0[k] >= 0; k++) {
        if (D_002A35E0[k] == i) {
            return k;
        }
    }
    return -1;
}
