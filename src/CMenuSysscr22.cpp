#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuSub1A7658 {
public:
    int Func1A7658();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr22.
class CMenuSysscr22 : public CMenuProcess {
public:
    CMenuSysscr22();
    virtual ~CMenuSysscr22();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuSub1A7658 *m_unk58; // 0x58
    u8 pad5C[0x4];
};

//@sym __builtin_new 0x245648
class CMenuSysscr11 {
public:
    CMenuSysscr11() throw();

    u8 pad0[0x60];
};
// @decl-end

CMenuSysscr22::CMenuSysscr22() {
    m_unk58 = 0;
}

CMenuSysscr22::~CMenuSysscr22() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr22", Update__13CMenuSysscr22);

s32 CMenuSysscr22::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

CMenuSysscr11 *CreateCMenuSysscr11() {
    return new CMenuSysscr11;
}
