#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001A8E28(void *p);
class CMenuSysscr27 {
public:
    static CMenuSysscr27 *Create();
};

#include "CChrBodyWin.h"
extern CChrBodyWin *D_002A4308;
extern "C" int func_00245818(void *p, s32 v);
extern "C" void func_00189270(void *p, s32 v);
#include "CMenuProcess.h"
#include "CBgWork.h"
#include "CCommandBase.h"

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr31.
// Release1A7AF8 and the factory sit at the end of CMenuSysscr32.cpp (unit text starts late).
class CMenuSysscr31 : public CMenuProcess {
public:
    CMenuSysscr31();
    virtual ~CMenuSysscr31();
    virtual s32 Update();
    virtual s32 Draw();
    void Release1A7AF8();
    void Release1A8DC0();

    CBgWork m_bg;             // 0x58
    void *m_unk64;            // 0x64
    CCommandBase *m_cmd;      // 0x68
    void *m_unk6C;            // 0x6C
    u8 pad70[0x8];
    s32 m_unk78;              // 0x78
    s32 m_unk7C;              // 0x7C
    s32 m_unk80;              // 0x80
};

u8 *Func237570(s32 v);
void Func237A88(void *p, s32 v);
void *Func237C30(void *p);
void Func238158(void *p, s32 v);
void Func225240(s32 v);
class CUnk237E90 {
public:
    int Func237E90(int v);
};
class CUnk1A4298 {
public:
    int Func1A4298();
};
#include "CMenuRecordWin.h"
#include "CMenuMgrSub1B4768.h"
class CMenuMgr {
public:
    int Func1B4ED0(s32 e);
};
#include "CMenuMgrSub1B5BF8.h"
extern CMenuMgrSub1B4768 *D_002A5530;
extern CMenuMgrSub1B5BF8 *D_002A5534;
extern "C" int func_001B50B0(CMenuMgrSub1B4768 *m, s32 v);
extern "C" int func_001B5E18(CMenuMgrSub1B5BF8 *p);
extern "C" int func_001B5FE0(CMenuMgrSub1B5BF8 *p, const char *s, f32 x, f32 y);
extern "C" int func_0018A1F0(void *p);
extern "C" int sprintf(char *buf, const char *fmt, ...);
#include "CFlagWork.h"
struct CS31Win {
    u8 pad0[0x34];
    f32 m34;                  // 0x34
};
// @decl-end

CMenuSysscr31::CMenuSysscr31() {
    m_unk64 = 0;
    m_cmd = 0;
    m_unk78 = 0;
    m_unk7C = 0;
    m_unk80 = 0;
}

CMenuSysscr31::~CMenuSysscr31() {
    Release1A7AF8();
}



INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr31", D_002DF0F8);
INCLUDE_ASM("asm/nonmatchings/CMenuSysscr31", Update__13CMenuSysscr31);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr31", D_002DF110);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr31", D_002DF118);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr31", D_002DF138);

s32 CMenuSysscr31::Draw() {
    if ((u32)(m_state - 3) < 2) {
        f32 one = 1.0f, zero = 0.0f;
        u8 *p = Func237570(0x60);
        f32 v[2];
        char buf[0x100];
        Func237A88(p, 6);
        Func238158(Func237C30(p + 0x50), 1);
        ((CUnk237E90 *)(p + 0x10))->Func237E90(m_cmd->Draw());
        ((CUnk237E90 *)(p + 0x10))->Func237E90(func_0018A1F0(m_unk64));
        ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_unk6C)->Func1A4298());
        ((CMenuRecordWin *)m_unk6C)->Func1A39A8(v, (s32 *)&v[1], 9);
        D_002A5530->SetUnk30(one, one, zero, zero);
        D_002A5530->SetUnk40(one, one, one, ((CS31Win *)m_unk6C)->m34);
        D_002A5530->SetUnk20(v[0], v[1], zero);
        D_002A5530->SetUnk50(1);
        ((CUnk237E90 *)(p + 0x20))->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x18)));
        ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B50B0(D_002A5530, 0x18));
        ((CUnk237E90 *)(p + 0x30))->Func237E90(func_001B5E18(D_002A5534));
        D_002A5534->Reset();
        D_002A5534->SetUnk30(1);
        D_002A5534->SetUnk10(0.78f, 0.78f, 0.78f);
        D_002A5534->SetUnk1C(((CS31Win *)m_unk6C)->m34);
        D_002A5534->SetUnk0(one, one);
        sprintf(buf, "%d", D_002A26E4->Func1091B0(0x1C));
        ((CMenuRecordWin *)m_unk6C)->Func1A39A8(v, (s32 *)&v[1], 10);
        ((CUnk237E90 *)(p + 0x30))->Func237E90(func_001B5FE0(D_002A5534, buf, v[0], v[1]));
        Func225088();
        Func225240((s32)p);
        return Func2250C0();
    }
    Func225088();
    return Func2250C0();
}

CMenuSysscr27 *CMenuSysscr27::Create() {
    CMenuSysscr27 *p = (CMenuSysscr27 *)operator new(0x78);
    func_001A8E28(p);
    return p;
}

void CMenuSysscr31::Release1A8DC0() {
    func_00245818(&m_bg, 1);
    D_002A4308->Func188BA8();
    if (m_cmd) {
        operator delete(m_cmd);
        m_cmd = 0;
    }
    if (m_unk64) {
        func_00189270(m_unk64, 3);
        m_unk64 = 0;
    }
}
