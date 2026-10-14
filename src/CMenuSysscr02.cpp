#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"
#include "IFlags.h"

class CMenuSysscr01 {
public:
    CMenuSysscr01() throw();
    static CMenuSysscr01 *Create();

    u8 pad0[0x60];
};

class CUnk1A4298 {
public:
    int Func1A4298();
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
extern "C" u8 *func_00237570(s32 v);
extern "C" void func_00237A88(void *p, s32 v);
extern "C" void *func_00237C30(void *p);
extern "C" int func_00238158(void *p, s32 v);
extern "C" int func_001B66E8(void *p);
extern void *D_002A5538;
void Func225240(s32 v);
extern ISysFlag *D_002A26E0;

// Background work (0x2456F8, library code).
extern "C" void func_00245818(void *p, s32 v);
class CBgWork {
public:
    CBgWork();
    ~CBgWork();

    u8 pad0[0xC];
};

// Same layout as the state block at the start of CMenuProcess.
class CMenuTimer {
public:
    CMenuTimer() {
        m_unk4 = -1;
        m_unk2 = 0;
        m_unk0 = 0;
    }

    s16 m_unk0;               // 0x0
    s16 m_unk2;               // 0x2
    s32 m_unk4;               // 0x4
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr02.
class CMenuSysscr02 : public CMenuProcess {
public:
    CMenuSysscr02();
    virtual ~CMenuSysscr02();
    virtual s32 Update();
    virtual s32 Draw();
    void LoadFlags();

    CBgWork m_bg;             // 0x58
    CMenuTimer m_timer;       // 0x64
    u8 pad6C[0x44];
    CUnk1A4298 *m_unkB0;      // 0xB0
    u8 padB4[0xC];
    s32 m_unkC0[3];           // 0xC0
    s32 m_unkCC[3];           // 0xCC
};
// @decl-end

CMenuSysscr02::CMenuSysscr02() {
}

CMenuSysscr02::~CMenuSysscr02() {
    func_00245818(&m_bg, 1);
}

void CMenuSysscr02::LoadFlags() {
    s32 i;
    for (i = 0; i < 3; i++) {
        m_unkC0[i] = D_002A26E0->V10(i);
        m_unkCC[i] = D_002A26E0->V7(i);
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr02", Update__13CMenuSysscr02);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr02", D_002DF840);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr02", D_002DF848);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr02", D_002DF868);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr02", D_002DF8A8);

s32 CMenuSysscr02::Draw() {
    u8 *p = func_00237570(0x60);
    func_00237A88(p, 4);
    func_00238158(func_00237C30(p + 0x30), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unkB0->Func1A4298());
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B66E8(D_002A5538));
    Func225088();
    Func225240((s32)p);
    return Func2250C0();
}

CMenuSysscr01 *CMenuSysscr01::Create() {
    return new CMenuSysscr01;
}
