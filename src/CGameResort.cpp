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

class CFlagWork {
public:
    int Func1091B0(s32 id);
};
extern CFlagWork *D_002A26E4;
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
    u8 pad0[0x78];
    struct CGameResortScene *m_unk78; // 0x78
    u8 pad7C[0x5C0 - 0x7C];
    s32 m_unk5C0;             // 0x5C0
    u8 pad5C4[0x5D4 - 0x5C4];
    s32 m_unk5D4;             // 0x5D4
    u8 pad5D8[0x4];
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
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CGameResort", __11CGameResortiiii);
INCLUDE_RODATA("asm/nonmatchings/CGameResort", D_002D9930);

CGameResort::~CGameResort() {
    D_002A0D38->V10();
    func_00150D98(m_unk78);
    D_002A0CE0->Func3(D_002D9930);
}

INCLUDE_ASM("asm/nonmatchings/CGameResort", func_00166B68);

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

INCLUDE_ASM("asm/nonmatchings/CGameResort", func_00167A48);

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
