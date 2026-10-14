#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CUnk1A4298 {
public:
    int Func1A4298();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr00.
class CMenuSysscr00 : public CMenuProcess {
public:
    CMenuSysscr00();
    virtual ~CMenuSysscr00();
    virtual s32 Update();
    virtual s32 Draw();
    void Init1AE800();        // CMenuSave's constructor (that unit's name for it)

    CUnk1A4298 *m_unk58;    // 0x58
};

void *operator new(unsigned int n);
CMenuSysscr00 *NewCMenuSysscr00();
// @decl-end

CMenuSysscr00::CMenuSysscr00() {
    m_unk58 = 0;
}

CMenuSysscr00::~CMenuSysscr00() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr00", Update__13CMenuSysscr00);

s32 CMenuSysscr00::Draw() {
    return m_unk58->Func1A4298();
}

// Creates the CMenuSave screen.
CMenuSysscr00 *NewCMenuSysscr00() {
    CMenuSysscr00 *p = (CMenuSysscr00 *)operator new(0x7DC0);
    p->Init1AE800();
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr00", func_001AE7A8);
