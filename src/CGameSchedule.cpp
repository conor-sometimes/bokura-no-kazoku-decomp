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
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
};
inline void ListUnlink(CListTag *n) {
    n->m_prev->m_next = n->m_next;
    n->m_next->m_prev = n->m_prev;
    n->m_next = n;
    n->m_prev = n;
}
inline void ListInsertBefore(CListTag *n, CListTag *at) {
    CListTag *p = at->m_prev;
    n->m_next = at;
    n->m_prev = p;
    p->m_next = n;
    n->m_next->m_prev = n;
}
inline void ListInsertAfter(CListTag *n, CListTag *at) {
    n->m_prev = at;
    n->m_next = at->m_next;
    at->m_next = n;
    n->m_next->m_prev = n;
}
inline CGameScheduleUnit *ScheduleUnit(CListTag *n) { return n->m_isHead ? 0 : (CGameScheduleUnit *)n; }
struct CGameScheduleCfg {
    u8 pad0[0x4C4];
    s32 m_unk4C4;             // 0x4C4
};
struct CResortEntry {
    s32 m_unk0;               // 0x0
    s32 m_unk4;               // 0x4
    s32 m_unk8;               // 0x8
};
struct CResortList {
    s32 m0;                   // 0x0
    s32 *m_slots;             // 0x4
    s32 m_num;                // 0x8
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
    virtual s32 Vf172B28(s32 i);
    virtual struct CResortList *GetList(s32 id);
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
    s32 Func159CF0(s32 a, s32 b, s32 c, s32 d);
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
    void Reset159C50();
    void Next159E18();
    void Load159F80();
    s32 Func15F1B0(s32 a, s32 b, s32 c);
    void Func15DEA0();
    s32 Collect15D820();
    s32 Func15D468();
    s32 Func15F780(s32 b, s32 c, s32 d);
    s32 Func15D620();
    s32 Func15E048(s32 k);
    s32 Func15E908();
    s32 Func15F2C8(s32 who, s32 mode, s32 len);
    s32 Func15F9E0(s32 a, s32 b, s32 c, s32 d);

    u8 pad0[0x2C];
    CGameScheduleCfg *m_unk2C; // 0x2C
    u8 pad30[0x58];
    s32 m_unk88;              // 0x88
    u8 pad8C[0x20];
    CListTag m_listAC;        // 0xAC
    CListTag m_listBC;        // 0xBC
    CGameScheduleUnit *m_unkCC; // 0xCC
    s32 m_unkD0;              // 0xD0
    u8 padD4[0x6C];
    char m_name[0x100];       // 0x140
    s32 m_unk240;             // 0x240
    s32 m_unk244;             // 0x244
    s32 m_unk248;             // 0x248
    s32 m_unk24C;             // 0x24C
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
extern "C" s32 func_0015EEF8(s32 a, s32 k);
extern "C" int func_0015F0D8(const void *a, const void *b);
extern "C" void func_0028A140(void *base, u32 n, u32 size, int (*cmp)(const void *, const void *));
s32 Func15F030(int name, s32 base);
s32 Func145738(s32 a, s32 b);
extern s32 D_002A3480[];
struct CScheduleKey {
    s32 m_id;
    s32 m_val;
};
struct CGameDBRecSched {
    u8 pad0[0x24];
    s32 m24;                  // 0x24
};
inline CGameScheduleUnit *ScheduleUnit2(CListTag *n) { if (n->m_isHead) return 0; return (CGameScheduleUnit *)n; }
int IsFlagKind(int v);
struct CGameDBRecDC {
    s32 m0;                   // 0x0
    u8 pad4[0xC];
    s32 m10;                  // 0x10
    u8 pad14[0x10];
    s32 m24;                  // 0x24
    u8 pad28[0x4];
    s32 m2C;                  // 0x2C
};
s32 FindResortSlot(s32 a, s32 k);
s32 Func1456A8(s32 v);
struct CGameDBRec240 {
    u8 pad0[0x20];
    s32 m20;                  // 0x20
};
struct CGameDBRecSlot {
    s32 m0;                   // 0x0
    u8 pad4[0x14];
};
struct CGameDBRec1D0 {
    s32 m0;                   // 0x0
    s32 m4;                   // 0x4
    u8 pad8[0x4];
    s32 mC;                   // 0xC
    s32 m10;                  // 0x10
    u8 pad14[0x1C];
    CGameDBRecSlot *m30;      // 0x30
};
extern char D_002D9230[];
struct CGameDBRecAct {
    s32 m0;                   // 0x0
    u8 pad4[0x8];
    const char *mC;           // 0xC
    u8 pad10[0x1C];
    s32 m2C;                  // 0x2C
    s32 m30;                  // 0x30
};
s32 Func15A090(s32 k);
class CEvLog0D38 {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual s32 Printf(const char *fmt, s32 a, s32 b, s32 c);
};
extern CEvLog0D38 *D_002A0D38;
extern "C" void func_001513D0(void *cfg, s32 a, s32 b, s32 c);
struct CGameDBRec240b {
    u8 pad0[0x8];
    s32 m8;                   // 0x8
    s32 mC;                   // 0xC
    s32 m10;                  // 0x10
};
int Func251B88();
struct CRand {
    u32 m_seed;
    u32 Next() {
        m_seed = m_seed * 0x19660D + 1;
        return (m_seed >> 12) & 0xFFFF;
    }
};
inline s32 RandRange(CRand *rnd, s32 lo, s32 hi) {
    if (lo == hi) return lo;
    return ((rnd->Next() << 16) | rnd->Next()) % (u32)(hi - lo + 1) + lo;
}

int CompareScheduleIds(const s32 *a, const s32 *b);
int CheckScheduleId(int v);
struct CSchedSortEnt {
    s32 m_key;                // 0x0
    s32 m_id;                 // 0x4
    s32 m8;                   // 0x8
    s32 m_open;               // 0xC
    s32 m10;                  // 0x10
    s32 m_state5;             // 0x14
};
void SortSchedules15DAB0();
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_00159850);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_00159A10);

void CGameSchedule::Reset159C50() {
    CListTag *head = &m_listAC;
    CGameScheduleUnit *u;
    goto test;
loop:
    ListUnlink(u);
    ListInsertAfter(u, &m_listBC);
test:
    u = ScheduleUnit(head->m_next);
    if (u) goto loop;
    m_unkCC = 0;
    m_unkD0 = D_002A26E4->Vf2991B0() != 0;
}

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

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", Func15A090__Fi);

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

s32 CGameSchedule::Func15D468() {
    char name[0x100];
    CGameDBRec1D0 *rec = (CGameDBRec1D0 *)D_002A2988->Find1D0(m_unkCC->m_unk18);
    if (!rec) {
        Func235DE0("*** unknown preset id %d\n", m_unkCC->m_unk18);
        return 0;
    }
    CGameScheduleCfg *cfg = m_unk2C;
    s32 k = D_002A2988->Vf14DCE0(m_unkCC->m_unk18, (s32)name, cfg->m_unk4C4);
    if (k < 0) return 0;
    s32 bits = 0;
    for (s32 i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        if (D_002A26E4->Func1091B0(i + 0x28) == rec->m4) bits = 1 << (D_002A26E4->Func1091B0(i + 0x28) - 0x10);
    }
    strcpy(m_name, name);
    m_unk240 = rec->m30[k].m0;
    m_unk244 = rec->m0;
    m_unk248 = bits;
    m_unk250 = 0;
    m_unk254 = rec->mC;
    m_unk258 = rec->m10;
    m_unk25C = k;
    D_002A26E4->IncCur2(rec->m30[k].m0);
    return 1;
}

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

s32 CGameSchedule::Collect15D820() {
    CSchedSortEnt ents[256];
    s32 i, st, s, cnt = 0;
    s32 a, b;
    for (i = 0; i < 256; i++) {
        if (!D_002A2988->Find1DC(i)) continue;
        s = i + 0x1062;
        st = D_002A26E4->Func1091B0(s);
        if (st == 1 || st == 5 || st == 3 || st == 2) {
            ents[cnt].m_id = i;
            ents[cnt].m_key = CheckScheduleId(D_002A26E4->Func1091B0(i + 0x1162));
            ents[cnt].m10 = D_002A26E4->Func1091B0(i + 0x1362);
            if (st == 2) {
                D_002A26E4->Func108FF0(s, 5);
                ents[cnt].m8 = 1;
            } else {
                ents[cnt].m8 = 0;
            }
            cnt++;
        }
    }
    func_0028A140(ents, cnt, sizeof(CSchedSortEnt), (int (*)(const void *, const void *))CompareScheduleIds);
    D_002A5358->Func108700();
    D_002A5358->Func108FF0(0x1FF, 0);
    a = 0;
    b = 0;
    for (i = 0; i < cnt; i++) {
        if (ents[i].m8) {
            D_002A5358->Func108FF0(b + 0x211, ents[i].m_id);
            D_002A5358->Func108FF0(b + 0x201, a + b);
            D_002A5358->Func108FF0(b + 0x221, ents[i].m_key);
            D_002A5358->Func108FF0(b + 0x231, ents[i].m10);
            b++;
        } else {
            D_002A5358->Func108FF0(a + 0x1AF, ents[i].m_id);
            D_002A5358->Func108FF0(a + 0x1BF, ents[i].m_key);
            D_002A5358->Func108FF0(a + 0x1CF, 1);
            D_002A5358->Func108FF0(a + 0x1DF, ents[i].m10);
            a++;
        }
    }
    D_002A5358->Func108FF0(0x1AE, a);
    D_002A5358->Func108FF0(0x200, b);
    return b > 0;
}

void SortSchedules15DAB0() {
    CSchedSortEnt ents[256];
    s32 bit;
    s32 i, n, cnt = 0;
    bit = 1 << (D_002A26E4->Func1091B0(0x17) % 4);
    for (i = 0; i < 256; i++) {
        n = D_002A26E4->Func1091B0(i + 0x1162);
        if (n <= 0) continue;
        CGameDBRecDC *rec = (CGameDBRecDC *)D_002A2988->Find1DC(i);
        if (!rec) continue;
        if (D_002A26E4->Func1091B0(i + 0x1062) != 1 && D_002A26E4->Func1091B0(i + 0x1062) != 5) continue;
        s32 open = 1;
        if (D_002A26E4->Func1091B0(i + 0x1062) == 5) ents[cnt].m_state5 = 1;
        else ents[cnt].m_state5 = 0;
        if (!(rec->m24 & bit)) open = 0;
        if (D_002A26E4->Func1091B0(0x1C) < rec->m2C) open = 0;
        ents[cnt].m_key = CheckScheduleId(n);
        ents[cnt].m_id = rec->m0;
        ents[cnt].m_open = open;
        ents[cnt].m10 = D_002A26E4->Func1091B0(i + 0x1362);
        cnt++;
    }
    func_0028A140(ents, cnt, sizeof(CSchedSortEnt), (int (*)(const void *, const void *))CompareScheduleIds);
    D_002A5358->Func108700();
    for (i = 0; i < cnt; i++) {
        D_002A5358->Func108FF0(i + 0x1AF, ents[i].m_id);
        D_002A5358->Func108FF0(i + 0x1BF, ents[i].m_key);
        D_002A5358->Func108FF0(i + 0x1CF, ents[i].m_open);
        D_002A5358->Func108FF0(i + 0x1DF, ents[i].m10);
        D_002A5358->Func108FF0(i + 0x1EF, ents[i].m_state5);
    }
    D_002A5358->Func108FF0(0x1AE, cnt);
}

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

void CGameSchedule::Func15DEA0() {
    D_002A5358->Func108700();
    s32 n = 0;
    for (s32 i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        s32 id = D_002A26E4->Func1091B0(i + 0x46);
        s32 cnt = D_002A2988->GetNum240(id);
        if (cnt <= 0) continue;
        D_002A5358->Func108FF0(n + 0x2A7, i);
        D_002A5358->Func108FF0(n + 0x2AE, D_002A2988->Vf14FBB0(i));
        for (s32 j = 0; j < cnt && j < 3; j++) {
            CGameDBRec240 *r = (CGameDBRec240 *)D_002A2988->Get240(id, j);
            if (r) D_002A5358->Func108FF0(n * 3 + j + 0x2B4, r->m20);
        }
        n++;
    }
    D_002A5358->Func108FF0(n + 0x2A7, -1);
}

s32 CGameSchedule::Func15E048(s32 k) {
    s32 who = D_002A5358->Func1091B0(k / 3 + 0x2A7);
    s32 r = k % 3;
    CGameDBRec240b *rec = (CGameDBRec240b *)D_002A2988->Get240(D_002A26E4->Func1091B0(who + 0x46), r);
    if (!rec) return 0;
    D_002A26E4->Func108FF0(0x1046, who);
    D_002A26E4->Func108FF0(0x1047, r);
    D_002A26E4->MoveMoney(Func15A090(k));
    D_002A26E4->Func108FF0(0x1142, 3);
    D_002A26E4->IncCur(0xE0);
    D_002A26E0->Vf143FA8(D_002A26E4->Func1091B0(0x16), 0, 0xE0, 0, 1);
    D_002A26E4->IncCur2(0xE0);
    D_002A26E4->Func108FF0(who + 0x16C, 1);
    D_002A0D38->Printf("pow(%d)+=%d", 1, who, rec->m8);
    D_002A0D38->Printf("hum1(%d)+=%d", 1, who, rec->mC);
    D_002A0D38->Printf("sci1(%d)+=%d", 1, who, rec->m10);
    func_001513D0(m_unk2C, 3, who, 1);
    return 1;
}

s32 CGameSchedule::Func15E2A8() {
    s32 r = Func15E2F8() != 0;
    r |= Func15E450() != 0;
    r |= Func15E5A8() != 0;
    return r;
}

s32 CGameSchedule::Func15E2F8() {
    if (D_002A26E4->Func1091B0(0x1142)) return 0;
    if (D_002A26E4->Func1091B0(0x1046) >= 0) return 0;
    s32 i = 0;
    s32 n = D_002A26E4->Func1091B0(0x27);
    for (; i < n; i++) {
        if (D_002A2988->GetNum240(D_002A26E4->Func1091B0(i + 0x46)) > 0) break;
    }
    if (i >= n) return 0;
    if (D_002A26E4->Func1091B0(0x46) == 3 && D_002A26E4->Func1091B0(0x4C) == 0 && (D_002A26E4->Func1091B0(0x17) & 3) == 0) return 0;
    D_002A26E4->Func108FF0(0x1142, 2);
    D_002A26E4->Func108FF0(0x1242, 0x3FFF);
    D_002A26E4->Func108FF0(0x1342, 0x7F);
    D_002A26E4->Func108FF0(0x1442, 0);
    return 1;
}

s32 CGameSchedule::Func15E450() {
    if (D_002A26E4->Func1091B0(0x1143)) return 0;
    s32 sum = 0;
    for (s32 i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        s32 a = D_002A26E4->Func1091B0(i + 0x58);
        s32 b = D_002A26E4->Func1091B0(i + 0x5E);
        if (IsFlagKind(a)) {
            CGameDBRec *r = D_002A2988->Find1E8(b);
            if (r) sum += r->m_unk18;
        }
    }
    if (sum <= D_002A26E4->Func1091B0(0x1C)) return 0;
    D_002A26E4->Func108FF0(0x1143, 2);
    D_002A26E4->Func108FF0(0x1243, 0x3FFF);
    D_002A26E4->Func108FF0(0x1343, 0x7F);
    D_002A26E4->Func108FF0(0x1443, 0);
    return 1;
}

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

s32 CGameSchedule::Func15E6E8() {
    s32 season = D_002A26E4->Vf2991B0();
    s32 money = D_002A26E4->Func1091B0(0x1C);
    for (s32 i = 0; i < 0x100; i++) {
        CGameDBRecDC *r = (CGameDBRecDC *)D_002A2988->Find1DC(i);
        if (r && (r->m10 || !season) && ((r->m24 >> season) & 1) && r->m2C <= money) {
            s32 k = i + 0x1062;
            if (D_002A26E4->Func1091B0(k) == 1 || D_002A26E4->Func1091B0(k) == 5 || D_002A26E4->Func1091B0(k) == 4 || D_002A26E4->Func1091B0(k) == 2) return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", Func15E860__13CGameSchedule);

s32 CGameSchedule::Func15E908() {
    s32 ids[0x100];
    s32 saved;
    s32 ok = 0;
    saved = D_002A26E4->Func1091B0(0x17);
    for (s32 s = D_002A26E4->Vf2991B0() + 1; s < 4; s++) {
        D_002A26E4->Func108FF0(0x17, D_002A26E4->Vf2991E8() * 4 + s);
        if (Func15E6E8()) goto done;
        for (s32 j = 0; j < 3; j++) {
            s32 n = D_002A2988->Vf14BD00(D_002A26E4->Vf2991B0(), j, ids, 0x100);
            for (s32 k = 0; k < n; k++) {
                if (D_002A2988->Vf14DCE0(ids[k], 0, m_unk2C->m_unk4C4) >= 0) goto done;
            }
        }
    }
    ok = 1;
done:
    D_002A26E4->Func108FF0(0x17, saved);
    return ok;
}

void CGameSchedule::Func15EAE0() {
    s32 i;
    if (D_002A26E4->Vf2991B0()) return;
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        Func15EB68(i);
    }
}

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", Func15EB68__13CGameSchedulei);

s32 FindResortSlot(s32 a, s32 k) {
    if (!D_002A2988->Vf14F550(a, k, D_002A26E4->GetNamed(k, a))) return -1;
    s32 j;
    s32 lt5 = D_002A26E4->GetNamed(k, a) < 5;
    for (j = 1; j < 7; j++) {
        CResortEntry *e = D_002A36E8->GetEntryA(j);
        if (k != e->m_unk4) continue;
        if ((e->m_unk8 > 0 && lt5) || (e->m_unk8 < 0 && !lt5)) return j;
    }
    return -1;
}

s32 Func15F030(int name, s32 base) {
    s32 v = D_002A26E4->GetNamed(base, name);
    return v < 5 ? 5 - v : v - 4;
}

// GNU as 2.10 mis-assembles the jump-table lui here without this (docs/lessons.md, CNameDBMgr).
asm(".p2align 3");
int Func15F080(int v) {
    switch (v) {
    case 0x9A:
        return 0x18;
    case 0xB2:
        return 0x12;
    case 0xA0:
        return 0xC;
    case 0xAC:
        return 6;
    case 0xA6:
        return 0;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F0D8);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F1B0);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F2C8);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F780);

s32 CGameSchedule::Func15F958(s32 a, s32 b, s32 c) {
    s32 r = D_002A36E8->Vf172A60(a, b, 1);
    if (r < 0) return 0;
    return Func15F9E0(r, 0x18, c, 1);
}

s32 CGameSchedule::Func15F9E0(s32 r, s32 who, s32 len, s32 check) {
    s32 i;
    if (who != 0x18) {
        CResortEntry *rec = D_002A36E8->GetEntryA(r);
        if (!rec) return 0;
        if (rec->m_unk8 > 0 && D_002A26E4->GetNamed(rec->m_unk4, who) >= 7) {
            Func235DE0("addact : solo + 8~10 (type:%d, chr:%d, len:%d)\n", r, who, len);
            return 0;
        }
    }
    if (who == 0x18) {
        CResortEntry *rec = D_002A36E8->GetEntryA(r);
        if (!rec) return 0;
        for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
            if (rec->m_unk8 < 0) {
                if (D_002A26E4->GetNamed(rec->m_unk4, i) >= 3) break;
            }
            if (rec->m_unk8 > 0) {
                if (D_002A26E4->GetNamed(rec->m_unk4, i) < 7) break;
            }
        }
        if (i == D_002A26E4->Func1091B0(0x27)) {
            Func235DE0("addact : all under 3 or over 8 (val:%d)\n", rec->m_unk8);
            return 0;
        }
    }
    if (check) {
        for (i = 0; i < 256; i++) {
            if (D_002A2988->Find1DC(i) && D_002A26E4->Func1091B0(i + 0x1062) && D_002A36E8->Vf172B28(i) == r &&
                D_002A26E4->Func1091B0(i + 0x1362) == who) {
                Func235DE0("addact : same (type:%d, chr:%d, len:%d)\n", r, who, len);
                return 0;
            }
        }
    }
    CResortList *l = D_002A36E8->GetList(r);
    if (!l) return 0;
    s32 base = r + 0x1562;
    s32 k = D_002A26E4->Func1091B0(base) % l->m_num;
    for (i = 0; i < l->m_num; i++) {
        s32 slot = l->m_slots[k];
        s32 nk = (k + 1) % l->m_num;
        k = nk;
        D_002A26E4->Func108FF0(base, k);
        if (!D_002A26E4->Func1091B0(slot + 0x1062)) {
            D_002A26E4->Func108FF0(slot + 0x1062, 4);
            D_002A26E4->Func108FF0(slot + 0x1162, len * 4);
            D_002A26E4->Func108FF0(slot + 0x1262, 1);
            D_002A26E4->Func108FF0(slot + 0x1362, who);
            Func235DE0("addact : add %d(idx:%d) (type:%d, chr:%d, len:%d)\n", slot, nk, r, who, len);
            return 1;
        }
    }
    Func235DE0("addact : already added (type:%d, chr:%d, len:%d)\n", r, who, len);
    return 0;
}
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9508);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9528);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9540);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9560);
INCLUDE_RODATA("asm/nonmatchings/CGameSchedule", D_002D9570);

CGameEventObj *NewGameEventObj(s32 a) {
    return new CGameEventObj(a);
}
