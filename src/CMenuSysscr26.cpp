#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CUnk1A4298 {
public:
    int Func1A4298();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr26.
// Its .rodata starts with literals of functions still in CMenuSysscr27.cpp (0x1A98F8-0x1A9ED8)
// and of .data tables: those come in through INCLUDE_RODATA.
class CMenuSysscr26 : public CMenuProcess {
public:
    CMenuSysscr26();
    virtual ~CMenuSysscr26();
    virtual s32 Update();
    virtual s32 Draw();

    CUnk1A4298 *m_unk58;    // 0x58
    u8 pad5C[0x4];
};

//@sym __13CMenuSysscr25 0x1AA710
//@sym __builtin_new 0x245648
class CMenuSysscr25 {
public:
    CMenuSysscr25() throw();

    u8 pad0[0x60];
};
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr26", D_002DF208);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr26", D_002DF218);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr26", D_002DF228);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr26", D_002DF230);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr26", D_002DF238);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr26", D_002DF258);
CMenuSysscr26::CMenuSysscr26() {
    m_unk58 = 0;
}

CMenuSysscr26::~CMenuSysscr26() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr26", Update__13CMenuSysscr26);

s32 CMenuSysscr26::Draw() {
    if (!m_unk58) {
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A4298();
}

CMenuSysscr25 *CreateCMenuSysscr25() {
    return new CMenuSysscr25;
}
