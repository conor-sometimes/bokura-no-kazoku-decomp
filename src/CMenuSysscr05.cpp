#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuSub193D68 {
public:
    int Func193D68();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr05.
class CMenuSysscr05 : public CMenuProcess {
public:
    CMenuSysscr05();
    virtual ~CMenuSysscr05();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuSub193D68 *m_unk58; // 0x58
    u8 pad5C[0x4];
};

//@sym __builtin_new 0x245648
class CMenuSysscr04 {
public:
    CMenuSysscr04() throw();

    u8 pad0[0x60];
};
// @decl-end

CMenuSysscr05::CMenuSysscr05() {
    m_unk58 = 0;
}

CMenuSysscr05::~CMenuSysscr05() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr05", Update__13CMenuSysscr05);

s32 CMenuSysscr05::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func193D68();
}

CMenuSysscr04 *CreateCMenuSysscr04() {
    return new CMenuSysscr04;
}
