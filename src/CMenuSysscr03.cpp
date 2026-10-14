#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuSub1A7658 {
public:
    int Func1A7658();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr03.
class CMenuSysscr03 : public CMenuProcess {
public:
    CMenuSysscr03();
    virtual ~CMenuSysscr03();
    virtual s32 Update();
    virtual s32 Draw();
    void Init1AD668();        // CMenuSysscr02's constructor (that unit's name for it)

    CMenuSub1A7658 *m_unk58; // 0x58
    u8 pad5C[0x4];
};

void *operator new(unsigned int n);
CMenuSysscr03 *NewCMenuSysscr03();
// @decl-end

CMenuSysscr03::CMenuSysscr03() {
    m_unk58 = 0;
}

CMenuSysscr03::~CMenuSysscr03() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr03", Update__13CMenuSysscr03);

s32 CMenuSysscr03::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

// Creates the CMenuSysscr02 screen.
CMenuSysscr03 *NewCMenuSysscr03() {
    CMenuSysscr03 *p = (CMenuSysscr03 *)operator new(0xD8);
    p->Init1AD668();
    return p;
}
