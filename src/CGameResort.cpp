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

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CGameResort.
class CGameResort : public CProcess {
public:
    CGameResort(s32 a, s32 b, s32 c, s32 d);
    virtual ~CGameResort();
    virtual void Update();
    void Func167EF8();

    u8 pad18[0x60];
    void *m_unk78;            // 0x78
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
    u8 pad0[0x78];
    struct CGameResortScene *m_unk78; // 0x78
    u8 pad7C[0x5C0 - 0x7C];
    s32 m_unk5C0;             // 0x5C0
    u8 pad5C4[0x4];
    s32 m_unk5C8;             // 0x5C8
    u8 pad5CC[0x5D4 - 0x5CC];
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
    virtual void *GetEntryA(s32 id);
    virtual CResortRec *GetEntryB(s32 id);
};
extern CResortDBMgr *D_002A36E8;
s32 Func1456A8(int who);
int IsFlagKind(int v);
int Func235DE0(const char *fmt, ...);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CGameResort", __11CGameResortiiii);
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

INCLUDE_ASM("asm/nonmatchings/CGameResort", func_00167310);
INCLUDE_RODATA("asm/nonmatchings/CGameResort", D_002D99A0);

INCLUDE_ASM("asm/nonmatchings/CGameResort", func_001675A0);
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

INCLUDE_ASM("asm/nonmatchings/CGameResort", func_00167C40);

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
