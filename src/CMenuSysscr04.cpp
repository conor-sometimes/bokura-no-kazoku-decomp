#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuSub1A7658 {
public:
    int Func1A7658();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr04.
class CMenuSysscr04 : public CMenuProcess {
public:
    CMenuSysscr04();
    virtual ~CMenuSysscr04();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuSub1A7658 *m_unk58; // 0x58
    u8 pad5C[0x4];
};

//@sym __13CMenuSysscr03 0x1AD2A8
//@sym __builtin_new 0x245648
class CMenuSysscr03 {
public:
    CMenuSysscr03() throw();

    u8 pad0[0x60];
};
// @decl-end

CMenuSysscr04::CMenuSysscr04() {
    m_unk58 = 0;
}

CMenuSysscr04::~CMenuSysscr04() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr04", Update__13CMenuSysscr04);

s32 CMenuSysscr04::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

CMenuSysscr03 *CreateCMenuSysscr03() {
    return new CMenuSysscr03;
}
