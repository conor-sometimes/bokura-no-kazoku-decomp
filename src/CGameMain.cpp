#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
int Func145738(s32 a, s32 b);
class CGameMain {
public:
    void CallFunc151120(s32 a, s32 b);
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

// The current-flag object (vtable 0x2C0900, vptr at 0x1C); only the calls are needed here.
class CCurFlag {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void SetNamed(int id, int k, int v);
    virtual int GetNamed(int id, int k);

    u8 pad0[0x1C];
};
extern CCurFlag *D_002A26E4;
int Func151970(int k);

class CFlagWork108700 {
public:
    void Func108700();
};
extern CFlagWork108700 *D_002A4638[6];
class CEventObj135A28 { public: void Func135A28(); };
class CGameMainSub129D90 { public: void Func129D90(); };
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
    u8 pad0[0x13C];
    s32 m13C;                 // 0x13C
    u8 pad140[0x10];
    CGameMainSub129D90 m150;  // 0x150
    u8 pad151[0x11F];
    u8 *m270;                 // 0x270
    CEventObj135A28 *m274;    // 0x274
    u8 pad278[0x250];
    s32 m4C8;                 // 0x4C8
};
void ResetAllFlags();
void CreateGameMainRes(CResMgr24F *mgr, int a);
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

INCLUDE_ASM("asm/nonmatchings/CGameMain", func_00150D98);

INCLUDE_ASM("asm/nonmatchings/CGameMain", func_00150EA8);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00150FD8() {
}

void ResetAllFlags() {
    int i;
    for (i = 0; i < 6; i++) D_002A4638[i]->Func108700();
}

INCLUDE_ASM("asm/nonmatchings/CGameMain", func_00151028);

void CGameMain::CallFunc151120(s32 a, s32 b) {
    Func151120(a, b, 0, 1, 0);
}

INCLUDE_ASM("asm/nonmatchings/CGameMain", Func151120__9CGameMainiiiii);

INCLUDE_ASM("asm/nonmatchings/CGameMain", func_001513D0);

INCLUDE_ASM("asm/nonmatchings/CGameMain", func_00151658);

int Func151970(int k) {
    CCurFlag *f = D_002A26E4;
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

INCLUDE_ASM("asm/nonmatchings/CGameMain", func_00151DD0);

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
