#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CProcess.h"
#include "CMemTex.h"
class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};
// Created here; its unit follows.
class CTitleMain : public CProcess {
public:
    CTitleMain();

    u8 pad18[0x7B8];
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CLogoMain.
class CLogoMain : public CProcess {
public:
    CLogoMain();
    virtual ~CLogoMain();
    virtual void Update();
    virtual void Draw();
    virtual s32 Func7();
    virtual void ReleaseTextures();

    u8 pad18[0x14];
    CMemTex m_tex2C;          // 0x2C
    CMemTex m_tex58;          // 0x58
    CStateMachine m_sm;       // 0x84
    u8 padCC[0x10];
};
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CLogoMain", D_002D1870);
INCLUDE_RODATA("asm/nonmatchings/CLogoMain", D_002D1880);
INCLUDE_RODATA("asm/nonmatchings/CLogoMain", D_002D1890);
INCLUDE_RODATA("asm/nonmatchings/CLogoMain", D_002D18A0);
INCLUDE_RODATA("asm/nonmatchings/CLogoMain", D_002D18C0);
CLogoMain::CLogoMain() {
}

CLogoMain::~CLogoMain() {
}

INCLUDE_ASM("asm/nonmatchings/CLogoMain", Func7__9CLogoMain);

void CLogoMain::ReleaseTextures() {
    m_tex2C.Func2546F0();
    m_tex58.Func2546F0();
}

INCLUDE_ASM("asm/nonmatchings/CLogoMain", Update__9CLogoMain);

INCLUDE_ASM("asm/nonmatchings/CLogoMain", Draw__9CLogoMain);

void AddTitleMain(CTaskList24F5C0 *list) {
    CTitleMain *p = new CTitleMain;
    list->Func24F5C0(p, 0);
}
