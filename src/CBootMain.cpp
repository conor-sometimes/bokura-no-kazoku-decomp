#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void *func_0024F2E8(s32 size);
extern "C" void func_0024F5C0(void *a, void *b, s32 c);

#include "CProcess.h"

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CBootMain.
class CBootMain : public CProcess {
public:
    CBootMain();
    virtual ~CBootMain();
    virtual void Update();

    u8 pad18[0x14];
    CStateMachine m_sm;       // 0x2C
};

// Created here; its unit follows.
class CLogoMain : public CProcess {
public:
    CLogoMain();

    u8 pad18[0xC4];
};
// @decl-end

CBootMain::CBootMain() {
}

CBootMain::~CBootMain() {
}

INCLUDE_RODATA("asm/nonmatchings/CBootMain", D_002D1800);
INCLUDE_RODATA("asm/nonmatchings/CBootMain", D_002D1820);
INCLUDE_ASM("asm/nonmatchings/CBootMain", Update__9CBootMain);

void Func100588(void *a) {
    CLogoMain *p = new CLogoMain;
    func_0024F5C0(a, p, 0);
}
