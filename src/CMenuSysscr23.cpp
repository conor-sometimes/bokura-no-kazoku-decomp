#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

extern "C" void func_001AB280(void *p);
class CMenuSysscr22 {
public:
    static CMenuSysscr22 *Create();
};

class CMenuAsksavequitWin {
public:
    CMenuAsksavequitWin(s32 mode) throw();
    void Func193358();
    int Func193D68();

    u8 pad0[0x58];
    s32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr23.
class CMenuSysscr23 : public CMenuProcess {
public:
    CMenuSysscr23();
    virtual ~CMenuSysscr23();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuAsksavequitWin *m_unk58; // 0x58
};
//@sym __19CMenuAsksavequitWini 0x1932B8
// @decl-end

CMenuSysscr23::CMenuSysscr23() {
    m_unk58 = 0;
}

CMenuSysscr23::~CMenuSysscr23() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr23", Update__13CMenuSysscr23);

s32 CMenuSysscr23::Draw() {
    if (m_unk58 == 0) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func193D68();
}

CMenuSysscr22 *CMenuSysscr22::Create() {
    CMenuSysscr22 *p = (CMenuSysscr22 *)operator new(0x60);
    func_001AB280(p);
    return p;
}
