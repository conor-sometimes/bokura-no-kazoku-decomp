#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

// Created by CreateStatusWinSub1A4F20 (CStatusWin.cpp); vtable 0x2C1B38. Only the calls are
// needed here, so no fields: the vptr is at 0.
class CMenuInputKanji {
public:
    virtual s32 Func1A4FE0();
    virtual s32 Func29B570();
    virtual s32 Func29B578();
    virtual s32 Func1A5048();
    virtual s32 Func1A50C8();
    virtual s32 Func1A64D0();
    virtual s32 Func1A4F78();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr24.
class CMenuSysscr24 : public CMenuProcess {
public:
    CMenuSysscr24();
    virtual ~CMenuSysscr24();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuInputKanji *m_win;   // 0x58
    u8 m_name[0x12];          // 0x5C
};

//@sym __builtin_new 0x245648
//@sym __13CMenuSysscr23 0x1AB000
class CMenuSysscr23 {
public:
    CMenuSysscr23() throw();

    u8 pad0[0x5C];
};
// @decl-end

CMenuSysscr24::CMenuSysscr24() {
    s32 i;
    for (i = 0; i < 8; i++) {
        m_name[i * 2] = 0x81;
        m_name[i * 2 + 1] = 0x40;
    }
}

CMenuSysscr24::~CMenuSysscr24() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr24", Update__13CMenuSysscr24);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr24", D_002DF388);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr24", D_002DF390);

s32 CMenuSysscr24::Draw() {
    if (m_win) {
        return m_win->Func1A64D0();
    }
    Func225088();
    return Func2250C0();
}

CMenuSysscr23 *CreateCMenuSysscr23() {
    return new CMenuSysscr23;
}
