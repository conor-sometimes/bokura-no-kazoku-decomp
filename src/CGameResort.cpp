#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CProcess.h"
#include "CUserFlagMgr.h"

// Event message manager (CEventMesRes unit), global D_002A0CE0; only virtual calls here.
class CEventMesMgr {
public:
    virtual ~CEventMesMgr();
    virtual void Func1();
    virtual void Func2();
    virtual void Func3(const char *s);
};
extern CEventMesMgr *D_002A0CE0;
extern char D_002D9930[];
extern "C" void func_00150D98(void *p);

struct CRand {
    CRand() { m_seed = 1; }
    u32 m_seed;
    u32 Next() {
        m_seed = m_seed * 0x19660D + 1;
        return (m_seed >> 12) & 0xFFFF;
    }
};
inline s32 RandRange(CRand *rnd, s32 lo, s32 hi) {
    if (hi < lo) hi = lo;
    if (lo == hi) return lo;
    return ((rnd->Next() << 16) | rnd->Next()) % (u32)(hi - lo + 1) + lo;
}
struct CResortMapEnt {
    const char *m0;           // 0x0
    const char *m4;           // 0x4
    s32 m8;                   // 0x8
    s32 mC;                   // 0xC
};
struct CResortMap {
    s32 m0;                   // 0x0
    s32 m4;                   // 0x4
    s32 m8;                   // 0x8
    s32 mC;                   // 0xC
    const char *m10;          // 0x10
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
    s32 m1C;                  // 0x1C
    s32 m20;                  // 0x20
    s32 m24;                  // 0x24
    CResortMapEnt *m28;       // 0x28
    s32 m2C;                  // 0x2C
};
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CGameResort.
class CGameResort : public CProcess {
public:
    CGameResort(s32 a, s32 b, s32 c, s32 d);
    virtual ~CGameResort();
    virtual void Update();
    void Func167EF8();

    u8 pad18[0x14];
    CStateMachine m_sm;       // 0x2C
    CRand m_rnd;              // 0x74
    void *m_unk78;            // 0x78
    char m_unk7C[0x100];      // 0x7C
    char m_unk17C[0x100];     // 0x17C
    s32 m_unk27C;             // 0x27C
    s32 m_unk280;             // 0x280
    char m_unk284[0x100];     // 0x284
    s32 m_unk384;             // 0x384
    s32 m_unk388;             // 0x388
    s32 m_unk38C;             // 0x38C
    char m_unk390[0x20];      // 0x390
    char m_unk3B0[0x200];     // 0x3B0
    s32 m_unk5B0;             // 0x5B0
    s32 m_unk5B4;             // 0x5B4
    s32 m_unk5B8;             // 0x5B8
    s32 m_unk5BC;             // 0x5BC
    s32 m_unk5C0;             // 0x5C0
    s32 m_unk5C4;             // 0x5C4
    s32 m_unk5C8;             // 0x5C8
    s32 m_unk5CC;             // 0x5CC
    s32 m_unk5D0;             // 0x5D0
    u8 pad5D4[0x6A0 - 0x5D4];
    s32 m_unk6A0;             // 0x6A0
    f32 m_unk6A4;             // 0x6A4
    f32 m_unk6A8;             // 0x6A8
    f32 m_unk6AC;             // 0x6AC
    s32 m_unk6B0;             // 0x6B0
    s32 m_unk6B4;             // 0x6B4
    s32 m_unk6B8;             // 0x6B8
    s32 m_unk6BC;             // 0x6BC
    f32 m_unk6C0;             // 0x6C0
};
extern "C" void func_00168DC8(void *p);
class CInterfRes {
public:
    static CInterfRes *Create();
};

#include "CFlagWork.h"
extern void *D_002A0BE4;
extern "C" void func_00250840(void *p, void *item);
extern "C" int func_00250A48(void *p, void *item);
struct CGameResortItem {
    u8 data[0x20];
};
class CGameResortObj {
public:
    void Func167150();
    int Func1671D8();
    int Func1670A8();
    int Func167268();
    void Func166B68();
    void Func166F80(s32 flag);
    s32 Func167A48(s32 who);
    s32 Func167C40();
    s32 Func1675A0();
    u8 pad0[0x74];
    CRand m_rnd;              // 0x74
    struct CGameResortScene *m_unk78; // 0x78
    u8 pad7C[0x390 - 0x7C];
    char m_unk390[0x20];      // 0x390
    char m_unk3B0[0x200];     // 0x3B0
    u8 pad5B0[0xC];
    s32 m_unk5BC;             // 0x5BC
    s32 m_unk5C0;             // 0x5C0
    u8 pad5C4[0x4];
    s32 m_unk5C8;             // 0x5C8
    s32 m_unk5CC;             // 0x5CC
    s32 m_unk5D0;             // 0x5D0
    s32 m_unk5D4;             // 0x5D4
    s32 m_unk5D8;             // 0x5D8
    CGameResortItem m_items[1]; // 0x5DC
};

class CSceneSet {
public:
    void *GetBUnk24(s32 i);
};
struct CGameResortScene {
    u8 pad0[0x230];
    CSceneSet m_set;          // 0x230
};
extern "C" int func_001153E8(void *p);
extern "C" int func_00167310(void *p, s32 i, s32 k);
class CResNameIf {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual s32 Get(s32 kind, char *buf, s32 id);
};
extern CResNameIf *D_002A28D8;
s32 Func145738(s32 a, s32 b);
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern "C" void func_00250828(void *p, const char *name);
extern "C" int func_00289118(const char *s);
extern const s32 D_002D9940[];
class CCharaObj {
public:
    void Func115938(s32 a, s32 b, f32 x, f32 y);
    u8 pad0[0x74];
    s32 m74;                  // 0x74
};
#include "libc.h"

struct CResortRec {
    s32 m0;                   // 0x0
    s32 m4;                   // 0x4
    s32 m8;                   // 0x8
    s32 mC;                   // 0xC
    s32 m10;                  // 0x10
};
// Resort database (CResortDBMgr unit), only the virtual calls.
class CResortDBMgr {
public:
    virtual void Vf29A3B8();
    virtual void Vf171DE8();
    virtual void Init();
    virtual CResortMap *GetMap(s32 id);
    virtual void Vf172968();
    virtual void Vf29A3F0();
    virtual void Vf29A430();
    virtual s32 Vf172A60(s32 a, s32 b, s32 c);
    virtual void Vf172B28();
    virtual void Vf172B68();
    virtual void *GetEntryA(s32 id);
    virtual CResortRec *GetEntryB(s32 id);
    virtual CResortRec *GetEntryC(s32 id);
};
extern CResortDBMgr *D_002A36E8;
s32 Func1456A8(int who);
int IsFlagKind(int v);
int Func235DE0(const char *fmt, ...);

// Event log (D_002A0D38), only the slots called here.
class CEvLogR {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void Begin(s32 who);
    virtual void V8();
    virtual void Lock();
    virtual void End();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual s32 Print(const char *s, s32 a);
};

extern s32 D_002A34D8[];
extern char D_002D99F8[];

class CTextMgr2BA1D0 {
public:
    virtual void Vf0();
    virtual void Vf1();
    virtual void Vf2();
    virtual const char *GetText(s32 id);
};
extern CTextMgr2BA1D0 *D_002BA1D0;
extern const char *D_002A34D0;
extern "C" unsigned int strlen(const char *s);
inline void StrCat(char *d, const char *s) { strcpy(d + strlen(d), s); }

#include "CGameDBMgr.h"

int Func251B88();
// @decl-end

CGameResort::CGameResort(s32 a, s32 b, s32 c, s32 d) {
    m_unk78 = (void *)a;
    m_rnd.m_seed = Func251B88() + 0xD80;
    CResortMap *rec = 0;
    if (!D_002A36E8 || !(rec = D_002A36E8->GetMap(b))) Func235DE0("**** resort database error (%X, %X)\n", D_002A36E8, rec);
    s32 k = RandRange((CRand *)((u8 *)m_unk78 + 0x144), 0, rec->m2C - 1);
    Func235DE0("map %d(%d)\n", k, rec->m2C);
    CResortMapEnt *e = &rec->m28[k];
    m_unk5C0 = c;
    m_unk5BC = rec->m8;
    m_unk38C = rec->m4;
    m_unk5C4 = d;
    m_unk5B0 = e->mC;
    m_unk5B4 = 150;
    m_unk5B8 = rec->mC;
    m_unk5C8 = rec->m1C;
    m_unk5CC = rec->m20;
    m_unk5D0 = rec->m24;
    strcpy(m_unk7C, e->m0);
    strcpy(m_unk17C, e->m4);
    m_unk27C = e->m8;
    m_unk280 = 1;
    strcpy(m_unk284, rec->m10);
    m_unk384 = rec->m14;
    m_unk388 = rec->m18 != 0;
    D_002A0D38->V9();
    if (m_unk5C0 == 0x18) ((CEvLogR *)D_002A0D38)->V8();
    else D_002A0D38->V7(m_unk5C0);
    func_00150D98(m_unk78);
    m_unk6A0 = 0;
    m_unk6A4 = -10.0f;
    m_unk6A8 = -46.0f;
    m_unk6AC = 1.0f;
    m_unk6B0 = 0;
    m_unk6B4 = 0;
    m_unk6B8 = 0;
    m_unk6BC = 0;
    m_unk6C0 = 45.0f;
}
INCLUDE_RODATA("asm/nonmatchings/CGameResort", D_002D9930);

CGameResort::~CGameResort() {
    D_002A0D38->V10();
    func_00150D98(m_unk78);
    D_002A0CE0->Func3(D_002D9930);
}

void CGameResortObj::Func166B68() {
    char name[0x100];
    s32 i;
    m_unk5D4 = 0;
    m_unk5D8 = 0;
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        if (!D_002A26E4->GetNamed(0x34, i)) continue;
        if (m_unk5C0 != 0x18 && D_002A26E4->GetNamed(0x28, i) != m_unk5C0) continue;
        m_unk5D4 |= 1 << i;
        m_unk5D8++;
    }
    CGameResortItem *it = m_items;
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); it++, i++) {
        if (!((m_unk5D4 >> i) & 1)) continue;
        sprintf(name, "AC,%d", D_002A26E4->Vf2991B0());
        D_002A28D8->Get(1, name, Func145738(i, 1));
        func_00250828(D_002A0BE4, name);
        strcpy((char *)it->data, name);
    }
}

INCLUDE_RODATA("asm/nonmatchings/CGameResort", D_002D9940);
INCLUDE_ASM("asm/nonmatchings/CGameResort", func_00166D40);

INCLUDE_ASM("asm/nonmatchings/CGameResort", func_00166F80);

int CGameResortObj::Func1670A8() {
    for (s32 i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        if (!((m_unk5D4 >> i) & 1)) continue;
        void *p = m_unk78->m_set.GetBUnk24(i);
        if (p && func_001153E8(p)) return 1;
    }
    return 0;
}

void CGameResortObj::Func167150() {
    for (s32 i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        if (!((m_unk5D4 >> i) & 1)) continue;
        func_00250840(D_002A0BE4, &m_items[i]);
    }
}

int CGameResortObj::Func1671D8() {
    for (s32 i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        if (!((m_unk5D4 >> i) & 1)) continue;
        if (!func_00250A48(D_002A0BE4, &m_items[i])) return 0;
    }
    return 1;
}

int CGameResortObj::Func167268() {
    s32 r = 0;
    if (m_unk5C0 == 0x18) {
        for (s32 i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
            r |= func_00167310(this, i, 3) != 0;
        }
    } else {
        r = func_00167310(this, m_unk5C0, 1) != 0;
    }
    return r;
}

extern "C" int func_00167310(void *p, s32 who, s32 div) {
    CGameResortObj *self = (CGameResortObj *)p;
    char buf[0x100];
    CResortRec *rec = (CResortRec *)D_002A36E8->GetEntryA(self->m_unk5BC);
    if (!rec) return 0;
    if (self->m_unk5C0 == 0x18 && rec->m8 > 0) {
        s32 v = D_002A26E4->GetNamed(rec->m4, who);
        if (D_002A2988->Vf14F550(who, rec->m4, v) || D_002A2988->Vf14F830(who, rec->m4, v)) {
            switch (v) {
            case 7:
                if (RandRange(&self->m_rnd, 0, 100) < 50) {
                    Func235DE0("resort : 50perc no chg (%d, %d, %d)\n", who, rec->m4, 7);
                    return 0;
                }
                break;
            case 8:
            case 9:
                Func235DE0("resort : 100perc no chg (%d, %d, %d)\n", who, rec->m4, v);
                return 0;
            }
        }
    }
    sprintf(buf, (const char *)rec->mC, rec->m8 / div);
    D_002A0D38->V9();
    D_002A0D38->V7(who);
    ((CEvLogR *)D_002A0D38)->Print(buf, 1);
    D_002A0D38->V10();
    return 1;
}
INCLUDE_RODATA("asm/nonmatchings/CGameResort", D_002D99A0);

s32 CGameResortObj::Func1675A0() {
    char buf[0x100];
    s32 mask = 0;
    s32 n = D_002A26E4->Func1091B0(0x27);
    s32 i, num, cnt;
    if (m_unk5C8 <= 0) return 0;
    for (i = 0; i < n; i++) {
        if (m_unk5C0 == 0x18 || Func1456A8(m_unk5C0) == i) {
            if (Func167A48(i)) mask |= 1 << i;
        }
    }
    if (!mask) {
        if (RandRange(&m_rnd, 0, 100) < 25) {
            s32 who;
            if (m_unk5C0 == 0x18) who = RandRange(&m_rnd, mask, n - 1);
            else who = Func1456A8(m_unk5C0);
            mask = 1 << who;
            Func235DE0("omake 25perc rand %d\n", who);
        } else {
            Func235DE0("omake nashi\n");
            return 0;
        }
    }
    num = 0;
    m_unk3B0[0] = D_002D9930[0];
    cnt = 0;
    for (i = 0; i < n; i++) cnt += (mask >> i) & 1;
    for (i = 0; i < n; i++) {
        if (!((mask >> i) & 1)) continue;
        CResortRec *rec = D_002A36E8->GetEntryB(m_unk5C8);
        if (!rec) continue;
        sprintf(buf, (const char *)rec->m10, Func145738(i, 1), m_unk5CC);
        Func235DE0("omake %d:%s\n", i, buf);
        D_002A0D38->V9();
        D_002A0D38->V7(i);
        ((CEvLogR *)D_002A0D38)->Print(buf, 1);
        D_002A0D38->V10();
        if (num > 0) StrCat(m_unk3B0, D_002BA1D0->GetText(0x3FC));
        num++;
        StrCat(m_unk3B0, (const char *)D_002A26E4->Get1458F0(i, -1, -1, -1, -1, -1));
        StrCat(m_unk3B0, D_002A26E4->GetStr(i + 0x2E));
        StrCat(m_unk3B0, D_002A34D0);
    }
    if (cnt >= 2) {
        if (cnt == n) strcpy(m_unk3B0, D_002BA1D0->GetText(0x3FD));
        StrCat(m_unk3B0, "@n");
    }
    sprintf(m_unk390, D_002D99F8, m_unk5C8, 1);
    return 1;
}
INCLUDE_RODATA("asm/nonmatchings/CGameResort", D_002D99F8);

s32 CGameResortObj::Func167A48(s32 who) {
    s32 idx = Func1456A8(who);
    if (idx < 0) return 0;
    if (!IsFlagKind(D_002A26E4->GetNamed(0x58, who))) return 0;
    s32 v = D_002A26E4->GetNamed(0x5E, who);
    CResortRec *rec = D_002A36E8->GetEntryB(m_unk5C8);
    if (!rec) return 0;
    s32 fa = rec->m4;
    s32 fb = rec->m8;
    s32 limBase = rec->mC;
    s32 i, id;
    for (i = 0; i < 16 && D_002A26E4->Func1091B0(id = idx * 16 + i + 0x1F6); i++) {
        if (D_002A26E4->Func1091B0(id) == v) {
            s32 t = D_002A26E4->GetNamed(fa, who);
            t += D_002A26E4->GetNamed(fb, who);
            s32 lim = D_002A26E4->Func1091B0(limBase + idx * 16 + i);
            if (t < lim) {
                Func235DE0("omake no abi %d:%d<%d\n", idx, t, lim);
                return 1;
            }
        }
    }
    return 0;
}

s32 CGameResortObj::Func167C40() {
    char buf[0x100];
    if (m_unk5D0 <= 0) return 0;
    CResortRec *rec = D_002A36E8->GetEntryC(m_unk5D0);
    if (!rec) return 0;
    s32 k = RandRange(&m_rnd, 0, 3);
    Func235DE0("omake2 : tbl (%d)\n", k);
    s32 *tbl = &D_002A34D8[k * 6];
    s32 i, c;
    for (i = 0; i < 6; i++) {
        c = tbl[i] - 1;
        if (c < D_002A26E4->Func1091B0(0x27)) {
            if (m_unk5C0 == 0x18 || Func1456A8(m_unk5C0) == c) {
                if (D_002A26E4->GetNamed(rec->m4, c) == 9) goto found;
            }
        }
    }
    Func235DE0("omake2 : nashi\n");
    return 0;
found:
    sprintf(buf, (const char *)rec->mC, Func145738(c, 1), rec->m8);
    Func235DE0("omake2 %d:%s\n", c, buf);
    D_002A0D38->V9();
    D_002A0D38->V7(c);
    ((CEvLogR *)D_002A0D38)->Print(buf, 1);
    D_002A0D38->V10();
    sprintf(m_unk390, D_002D99F8, m_unk5D0, 1);
    D_002A0D38->V9();
    D_002A0D38->V7(c);
    return 1;
}

void CGameResort::Func167EF8() {
    D_002A0D38->V10();
}

INCLUDE_ASM("asm/nonmatchings/CGameResort", Update__11CGameResort);
INCLUDE_RODATA("asm/nonmatchings/CGameResort", D_002D9A60);
INCLUDE_RODATA("asm/nonmatchings/CGameResort", D_002D9A80);

CInterfRes *CInterfRes::Create() {
    CInterfRes *p = (CInterfRes *)operator new(0x14);
    func_00168DC8(p);
    return p;
}
