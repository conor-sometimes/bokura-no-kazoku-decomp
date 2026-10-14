#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CGameScheduleNode {
public:


    s32 m_unk0;               // 0x0
    u8 pad4[0x4];
    CGameScheduleNode* m_next; // 0x8
};
class CGameScheduleSub159F58 {
public:
    void Advance();

    u8 pad0[0xCC];
    CGameScheduleNode* m_cur; // 0xCC
};

#include "CFlagWork.h"
#include "CGameDBMgr.h"
#include "CList.h"
#include "libc.h"
class CGameScheduleUnit : public CListTag {
public:
    u8 pad10[0x8];
    s32 m_unk18;              // 0x18
};
inline CGameScheduleUnit *ScheduleUnit(CListTag *n) { return n->m_isHead ? 0 : (CGameScheduleUnit *)n; }
struct CGameScheduleCfg {
    u8 pad0[0x4C4];
    s32 m_unk4C4;             // 0x4C4
};
struct CResortEntry {
    s32 m_unk0;               // 0x0
    s32 m_unk4;               // 0x4
};
// Resort database (CResortDBMgr unit), only the virtual calls.
class CResortDBMgr {
public:
    virtual void Vf29A3B8();
    virtual void Vf171DE8();
    virtual void Init();
    virtual void Vf172920();
    virtual void Vf172968();
    virtual void Vf29A3F0();
    virtual void Vf29A430();
    virtual s32 Vf172A60(s32 a, s32 b, s32 c);
    virtual void Vf172B28();
    virtual void Vf172B68();
    virtual CResortEntry *GetEntryA(s32 id);
};
extern CResortDBMgr *D_002A36E8;
extern CFlagWork *D_002A5358;
struct CGameScheduleRec {
    s32 m_unk0;               // 0x0
    u8 pad4[0x18];
    s32 m_unk1C;              // 0x1C
};
struct CGameScheduleEnt {
    s32 m_id;                 // 0x0
    s32 m_unk4;               // 0x4
};
extern char D_002D9270[];
int Func235DE0(const char *fmt, ...);
int Func15F080(int v);
class CGameSchedule {
public:
    s32 Init15D3E0();
    void Func15DD38(s32 k);
    void Func159CF0(s32 a, s32 b, s32 c, s32 d);
    s32 Func15E638();
    s32 Func15E6E8();
    s32 Func15E2A8();
    s32 Func15E2F8();
    s32 Func15E450();
    s32 Func15E5A8();
    void Func15DE20();
    s32 Func15E860();
    void Func15EAE0();
    void Func15EB68(s32 i);
    s32 Func15F958(s32 a, s32 b, s32 c);
    s32 Func15F9E0(s32 a, s32 b, s32 c, s32 d);

    u8 pad0[0x2C];
    CGameScheduleCfg *m_unk2C; // 0x2C
    u8 pad30[0x7C];
    CListTag m_listAC;        // 0xAC
    u8 padBC[0x84];
    char m_name[0x100];       // 0x140
    s32 m_unk240;             // 0x240
    s32 m_unk244;             // 0x244
    s32 m_unk248;             // 0x248
    u8 pad24C[0x4];
    s32 m_unk250;             // 0x250
    s32 m_unk254;             // 0x254
    s32 m_unk258;             // 0x258
    s32 m_unk25C;             // 0x25C
};

//@sym __13CGameEventObji 0x15FE28
class CGameEventObj {
public:
    CGameEventObj(s32 a);
    u8 pad0[0x1014C];
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_00159850);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_00159A10);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_00159C50);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", Func159CF0__13CGameScheduleiiii);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_00159E18);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D8FD8);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D8FF8);

void CGameScheduleSub159F58::Advance() {
    if (m_cur) {
        CGameScheduleNode *n = m_cur->m_next;
        m_cur = n->m_unk0 ? 0 : n;
    }
}

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_00159F80);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015A090);

s32 Func15A120(s32 bits) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if ((bits >> i) & 1) return i + 16;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015A158);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9158);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9160);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9168);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9170);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9180);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9190);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D91A0);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D91B0);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D91C8);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D91E0);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D91E8);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9200);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9218);

s32 CGameSchedule::Init15D3E0() {
    strcpy(m_name, D_002A2988->GetName248(3, D_002A26E4->Func1091B0(0x17)));
    m_unk240 = -1;
    m_unk244 = -1;
    m_unk248 = 0;
    m_unk250 = 0;
    m_unk254 = -1;
    m_unk258 = -1;
    m_unk25C = -1;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015D468);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015D620);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9270);

int CompareScheduleIds(const s32 *a, const s32 *b) {
    return *a - *b;
}

int CheckScheduleId(int v) {
    if (v == 0x3FFF) {
        return -1;
    }
    if (v < 0) {
        return -1;
    }
    return v;
}

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015D820);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015DAB0);

void CGameSchedule::Func15DD38(s32 k) {
    if (k < D_002A5358->Func1091B0(0x1AE)) {
        CGameScheduleRec *r = (CGameScheduleRec *)D_002A2988->Find1DC(D_002A5358->Func1091B0(k + 0x1AF));
        if (!r) {
            Func235DE0(D_002D9270, D_002A5358->Func1091B0(k + 0x1AF));
            return;
        }
        Func159CF0(r->m_unk1C, 3, r->m_unk0, 0);
    }
}

void CGameSchedule::Func15DE20() {
    s32 i;
    for (i = 0; i < 0x100; i++) {
        if (D_002A26E4->Func1091B0(i + 0x1062) == 5) {
            D_002A26E4->Func108FF0(i + 0x1062, 1);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015DEA0);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015E048);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015E2A8);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015E2F8);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015E450);

s32 CGameSchedule::Func15E5A8() {
    s32 i;
    s32 ok = 0;
    for (i = 0; i < 0x100; i++) {
        if (D_002A26E4->Func1091B0(i + 0x1062) == 4) {
            D_002A26E4->Func108FF0(i + 0x1062, 2);
            ok = 1;
        }
    }
    return ok;
}

s32 CGameSchedule::Func15E638() {
    s32 v;
    if (!D_002A26E0->Func1091B0(9)) return 0;
    v = D_002A26E4->Func1091B0(0x18);
    if (!((v >> D_002A26E4->Vf2991B0()) & 1)) return 0;
    if (Func15E6E8()) return 0;
    return Func15E860() == 0;
}

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", Func15E6E8__13CGameSchedule);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", Func15E860__13CGameSchedule);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015E908);

void CGameSchedule::Func15EAE0() {
    s32 i;
    if (D_002A26E4->Vf2991B0()) return;
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        Func15EB68(i);
    }
}

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", Func15EB68__13CGameSchedulei);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015EEF8);

s32 Func15F030(int name, s32 base) {
    s32 v = D_002A26E4->GetNamed(base, name);
    return v < 5 ? 5 - v : v - 4;
}

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F080);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F0D8);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F1B0);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F2C8);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F780);

s32 CGameSchedule::Func15F958(s32 a, s32 b, s32 c) {
    s32 r = D_002A36E8->Vf172A60(a, b, 1);
    if (r < 0) return 0;
    return Func15F9E0(r, 0x18, c, 1);
}

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", Func15F9E0__13CGameScheduleiiii);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9528);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9540);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9560);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9570);

CGameEventObj *NewGameEventObj(s32 a) {
    return new CGameEventObj(a);
}
