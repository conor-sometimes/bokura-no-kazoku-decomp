#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuSub193D68 {
public:
    int Func193D68();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr09.
class CMenuSysscr09 : public CMenuProcess {
public:
    CMenuSysscr09();
    virtual ~CMenuSysscr09();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuSub193D68 *m_unk58; // 0x58
};

//@sym __13CMenuSysscr08 0x1AC148
//@sym __builtin_new 0x245648
class CMenuSysscr08 {
public:
    CMenuSysscr08() throw();

    u8 pad0[0x60];
};
// @decl-end

CMenuSysscr09::CMenuSysscr09() {
    m_unk58 = 0;
}

CMenuSysscr09::~CMenuSysscr09() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr09", Update__13CMenuSysscr09);

s32 CMenuSysscr09::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func193D68();
}

CMenuSysscr08 *CreateCMenuSysscr08() {
    return new CMenuSysscr08;
}
