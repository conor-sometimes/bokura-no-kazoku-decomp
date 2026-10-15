#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CVec4 {
public:
    f32 x, y, z, w;
};
// The window item (CStatusWin.cpp); Func1A4298 is named under another class there.
class CStatusItem {
public:
    int GetColor(CVec4 *out, s32 i);
    int GetPos(f32 *x, f32 *y, s32 i);

    u8 pad0[0x34];
    f32 m_unk34;              // 0x34
};
class CUnk1A4298 {
public:
    int Func1A4298();
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
class CMenuMgrSub1B5BF8 {
public:
    void Reset();
    void SetUnk30(int v);
    void SetUnk0(f32 x, f32 y);
    void SetUnk34(int v);
    void SetUnk1C(f32 v);
    void SetUnk10(f32 r, f32 g, f32 b);
};
extern CMenuMgrSub1B5BF8 *D_002A5534;
extern "C" int func_001B5E18(CMenuMgrSub1B5BF8 *p);
extern "C" int func_001B5FE0(CMenuMgrSub1B5BF8 *p, f32 x, f32 y, const char *s);
class CMenuMgrSub1B4768 {
public:
    int GetEntry0(int k);
    void Reset1B4D28();
    void SetUnk20(f32 x, f32 y, f32 z);
    void SetUnk4C(f32 v);
};
class CMenuMgr {
public:
    int Func1B4ED0(int v);
};
extern CMenuMgrSub1B4768 *D_002A5530;
extern "C" int func_001B50B0(CMenuMgrSub1B4768 *p, int k);
#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern char D_002DA470[];
void *Func237570(int size);
void Func237A88(void *p, int n);
void *Func237C30(void *p);
void Func238158(void *p, int v);
void Func225240(int v);

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuExGetMoney.
class CMenuExGetMoney : public CMenuProcess {
public:
    CMenuExGetMoney();
    virtual ~CMenuExGetMoney();
    virtual s32 Update();
    virtual s32 Draw();

    CStatusItem *m_unk58;     // 0x58
    s32 m_unk5C;              // 0x5C
    u8 pad60[0x4];
    s32 m_unk64;              // 0x64
    s32 m_unk68;              // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    f32 m_unk74;              // 0x74
};

class CMenuConfig {
public:
    CMenuConfig() throw();

    u8 pad0[0x7C];
};
// @decl-end

CMenuExGetMoney::CMenuExGetMoney() {
    m_unk58 = 0;
    m_unk64 = 0;
    m_unk68 = 0;
    m_unk6C = 0;
    m_unk70 = 0;
    m_unk74 = 1.0f;
    m_unk5C = 0;
}

CMenuExGetMoney::~CMenuExGetMoney() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuExGetMoney", Update__15CMenuExGetMoney);

s32 CMenuExGetMoney::Draw() {
    f32 x, y;
    char buf[0x100];
    CVec4 col;
    u8 *p;
    if (!m_unk58) {
        Func225088();
        Func2250C0();
    } else {
        p = (u8 *)Func237570(0x60);
        Func237A88(p, 6);
        Func238158(Func237C30(p + 0x50), 1);
        ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_unk58)->Func1A4298());
        ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B5E18(D_002A5534));
        D_002A5534->Reset();
        D_002A5534->SetUnk30(1);
        D_002A5534->SetUnk0(1.0f, 1.0f);
        D_002A5534->SetUnk34(0);
        D_002A5534->SetUnk1C(m_unk58->m_unk34);
        m_unk58->GetColor(&col, 9);
        D_002A5534->SetUnk10(col.x * 0.0078125f, col.y * 0.0078125f, col.z * 0.0078125f);
        sprintf(buf, D_002DA470, D_002A5358->Func1091B0(0x25E));
        m_unk58->GetPos(&x, &y, 9);
        ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B5FE0(D_002A5534, x, y, buf));
        if (m_unk5C == 1) D_002A5534->SetUnk1C(m_unk74);
        else D_002A5534->SetUnk1C(m_unk58->m_unk34);
        m_unk58->GetColor(&col, 10);
        D_002A5534->SetUnk10(col.x * 0.0078125f, col.y * 0.0078125f, col.z * 0.0078125f);
        sprintf(buf, D_002DA470, m_unk70);
        m_unk58->GetPos(&x, &y, 10);
        ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B5FE0(D_002A5534, x, y, buf));
        ((CUnk237E90 *)(p + 0x30))->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x18)));
        D_002A5530->Reset1B4D28();
        D_002A5530->SetUnk4C(m_unk58->m_unk34);
        m_unk58->GetPos(&x, &y, 8);
        D_002A5530->SetUnk20(x, y, 0.0f);
        ((CUnk237E90 *)(p + 0x30))->Func237E90(func_001B50B0(D_002A5530, 0x18));
        Func225088();
        Func225240((int)p);
        Func2250C0();
    }
}
INCLUDE_RODATA("asm/nonmatchings/CMenuExGetMoney", D_002DA470);

CMenuConfig *CreateCMenuConfig() {
    return new CMenuConfig;
}
