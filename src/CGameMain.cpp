#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
int Func145738(s32 a, s32 b);
class CGameMain {
public:
    void CallFunc151120(s32 a, s32 b);
    int Func1513D0(s32 slot, s32 name, s32 all);
    void Func150FD8();
    s32 Func151028(s32 i, s32 j, s32 k);
    void Func151120(s32 a, s32 b, s32 c, s32 d, s32 e);
    int Func153220();


};

class CResCache {
public:
    void Func250978();

    u8 pad0[0x13C];
};
// The resource managers (CCharaResMgr, CMapResMgr, CEnvResMgr) as seen through their
// interfaces: vptr after CResCache's 0x13C bytes. Slot 5 exists in CEnvResMgr only.
class IResMgr : public CResCache {
public:
    virtual ~IResMgr();
    virtual void V1();
    virtual s32 *FindRes(s32 id);
    virtual void Init(s32 size, s32 n);
    virtual void CallFunc250368();
    virtual void V5();
};
extern IResMgr *D_002A0BE4;
extern IResMgr *D_002A0BE8;
extern IResMgr *D_002A0BEC;

#include "CFlagWork.h"
int Func151970(int k);

extern CFlagWork *D_002A4638[6];
class CEventObj135A28 { public: void Func135A28(); };
class CMapEffTarget;
class CMapEffObj {
public:
    void DrawAll(s32 a, CMapEffTarget *t);
};
struct CGameMainSub154 {
    u8 pad0[0x4];
    CMapEffObj *m4;           // 0x4
};
class CGameMainSub129D90 {
public:
    void Func129D90();
    void Set2C(s32 v) { m2C = v; }
    void DrawEff(u8 *buf) { m4->m4->DrawAll((s32)this, (CMapEffTarget *)buf); }

    u8 pad0[0x4];
    CGameMainSub154 *m4;      // 0x4
    u8 pad8[0x24];
    s32 m2C;                  // 0x2C
};
class CResMgr24F {
public:
    void Func24F5C0(void *res, int v);
};
void *Func24F2E8(int size);
class CGameMainRes153410 { public: void Init153410(int a); };
class CUnk237E90 {
public:
    int Func237E90(int v);
};
struct CUnk2A5BC0 {
    u8 pad0[0x60];
    CUnk237E90 m60;           // 0x60
};
extern CUnk2A5BC0 *D_002A5BC0;
void *Func237570(int size);
void Func237A88(void *p, int n);
void *Func237C30(void *p);
void Func238158(void *p, int v);
void Func225088();
int Func2250C0();
void Func225240(int v);
// CGameMain itself (vtable slot 4 is Update1531D8, slot 5 Draw153228).
class CGameMain2 {
public:
    void Update1531D8();
    void Draw153228();
    void Draw1532A8();
    void Func150D98();
    s32 Func150EA8(s32 k);
    u8 pad0[0x13C];
    s32 m13C;                 // 0x13C
    s32 m140;                 // 0x140
    u8 pad144[0xC];
    CGameMainSub129D90 m150;  // 0x150
    u8 pad180[0xF0];
    u8 *m270;                 // 0x270
    CEventObj135A28 *m274;    // 0x274
    u8 pad278[0x4];
    s32 m27C[138];            // 0x27C
    s32 m4A4;                 // 0x4A4
    u8 pad4A8[0x20];
    s32 m4C8;                 // 0x4C8
};
void ResetAllFlags();
void CreateGameMainRes(CResMgr24F *mgr, int a);

struct CGameMainFlagDef {
    s32 m0;
    s32 m4;
    s32 m8;
    u8 padC[0xC];
    s32 m18;
    s32 m1C;
    s32 m20;
    s32 m24;
};
extern CGameMainFlagDef D_002A2DB0[];
extern s32 D_002A3170[];
int Func1456A8(int name);
struct CUnk2A5BC0b {
    u8 pad0[0x80];
    CUnk237E90 m80;
};
extern "C" void func_00135BE0(CEventObj135A28 *p, u8 *buf);
extern "C" void func_0012B180(CGameMainSub129D90 *p, u8 *buf);

int IsFlagKind(int v);
extern s8 D_002A31D8[6][9];
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CGameMain", func_00150A70);

INCLUDE_ASM("asm/nonmatchings/CGameMain", func_00150C30);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8960);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8968);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8970);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8978);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8980);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8988);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8990);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8998);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D89A0);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D89A8);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D89B0);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D89B8);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D89C0);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D89C8);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D89D0);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D89D8);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D89E0);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D89E8);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D89F0);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D89F8);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8A00);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8A08);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8A10);

void CGameMain2::Func150D98() {
    s32 i;
    m4A4 = D_002A26E4->Func1091B0(0x27);
    for (i = 0; i < m4A4; i++) {
        s32 j;
        for (j = 0; D_002A2DB0[j].m0 >= 0; j++) {
            m27C[i * 23 + D_002A2DB0[j].m8] = D_002A26E4->Func1091B0(D_002A2DB0[j].m0 + i);
        }
    }
    D_002A26E4->Vf145A28(-1);
}

INCLUDE_ASM("asm/nonmatchings/CGameMain", func_00150EA8);

// Empty; called with `this` from Func1513D0 (and CGameResort).
void CGameMain::Func150FD8() {
}

void ResetAllFlags() {
    int i;
    for (i = 0; i < 6; i++) D_002A4638[i]->Func108700();
}

s32 CGameMain::Func151028(s32 i, s32 j, s32 k) {
    s32 base = Func1456A8(k);
    if (base < 0) {
        return 0;
    }
    s32 n;
    for (n = 0; D_002A3170[n] >= 0; n++) {
        if (D_002A4638[i]->Func1091B0(D_002A3170[n] + base) != D_002A4638[j]->Func1091B0(D_002A3170[n] + base)) {
            return 0;
        }
    }
    return 1;
}

void CGameMain::CallFunc151120(s32 a, s32 b) {
    Func151120(a, b, 0, 1, 0);
}

INCLUDE_ASM("asm/nonmatchings/CGameMain", Func151120__9CGameMainiiiii);

INCLUDE_ASM("asm/nonmatchings/CGameMain", func_001513D0);

INCLUDE_ASM("asm/nonmatchings/CGameMain", func_00151658);

int Func151970(int k) {
    ICurFlag *f = D_002A26E4;
    if (f->GetNamed(0x28, k) == 0x12 || D_002A26E4->GetNamed(0x28, k) == 0x13) return 0;
    return 1;
}

int Func151A00(int k) {
    int r = Func151970(k);
    if (r != 0) {
        r = D_002A26E4->GetNamed(0xE8, k) == 0;
    }
    return r;
}

int CallFunc145738(s32 a) {
    return Func145738(a, 1) - 0x10;
}

INCLUDE_ASM("asm/nonmatchings/CGameMain", func_00151A78);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8AF8);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8B00);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8B08);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8B10);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8B18);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8B20);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8B40);

void Func151DD0() {
    s32 n = D_002A26E4->Func1091B0(0x27);
    s32 i;
    s8 *p;
    D_002A26E4->Func108FF0(0x3B41, 0);
    for (i = 0; i < n; i++) {
        if (IsFlagKind(D_002A26E4->GetNamed(0x46, i))) {
            if (D_002A26E4->GetNamed(0x52, i) == 6 || D_002A26E4->GetNamed(0x52, i) == 9) {
                D_002A26E4->Func108FF0(0x3B41, 1);
                break;
            }
        }
    }
    p = D_002A31D8[D_002A26E4->Func1091B0(0x14) % 6];
    for (i = 0; i < 9; i++) {
        D_002A26E4->Func108FF0(0x3C34 + i, *p++);
    }
}

void InitResMgrs151F60() {
    D_002A0BE8->Init(-1, -1);
    D_002A0BEC->CallFunc250368();
    D_002A0BE4->Init(-1, -1);
}

void ReleaseResMgrs151FE8() {
    D_002A0BE4->CallFunc250368();
    D_002A0BEC->V5();
    D_002A0BE8->CallFunc250368();
}

void CallResCacheFunc250978() {
    D_002A0BE4->Func250978();
    D_002A0BE8->Func250978();
}

INCLUDE_ASM("asm/nonmatchings/CGameMain", func_00152090);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8C90);
INCLUDE_RODATA("asm/nonmatchings/CGameMain", D_002D8C98);

void CGameMain2::Update1531D8() {
    if (m13C == 0 && m4C8 == 0) {
        m274->Func135A28();
        m150.Func129D90();
    }
}

int CGameMain::Func153220() {
    return 0;
}

void CGameMain2::Draw153228() {
    m270 = (u8 *)Func237570(0x260);
    Func237A88(m270, 0x26);
    Func238158(Func237C30(m270 + 0x250), 1);
    Func225088();
    Func225240((int)m270);
    D_002A5BC0->m60.Func237E90(Func2250C0());
}

INCLUDE_ASM("asm/nonmatchings/CGameMain", func_001532A8);

void CreateGameMainRes(CResMgr24F *mgr, int a) {
    CGameMainRes153410 *p = (CGameMainRes153410 *)Func24F2E8(0x200);
    p->Init153410(a);
    mgr->Func24F5C0(p, 0);
}
