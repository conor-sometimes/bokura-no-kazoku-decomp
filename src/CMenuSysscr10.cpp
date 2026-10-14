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

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr10.
class CMenuSysscr10 : public CMenuProcess {
public:
    CMenuSysscr10();
    virtual ~CMenuSysscr10();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuInputKanji *m_unk58; // 0x58
    u8 m_name[0x20];          // 0x5C
};

//@sym __builtin_new 0x245648
class CMenuSysscr09 {
public:
    CMenuSysscr09() throw();

    u8 pad0[0x5C];
};
// @decl-end

CMenuSysscr10::CMenuSysscr10() {
    s32 i;
    for (i = 0; i < 8; i++) {
        m_name[i * 2] = 0x81;
        m_name[i * 2 + 1] = 0x40;
    }
}

CMenuSysscr10::~CMenuSysscr10() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr10", Update__13CMenuSysscr10);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr10", D_002DF518);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr10", D_002DF520);

s32 CMenuSysscr10::Draw() {
    if (m_unk58) {
        return m_unk58->Func1A64D0();
    }
    Func225088();
    return Func2250C0();
}

CMenuSysscr09 *CreateCMenuSysscr09() {
    return new CMenuSysscr09;
}
