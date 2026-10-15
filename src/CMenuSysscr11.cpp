#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuSub1A7658 {
public:
    int Func1A7658();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr11.
class CMenuSysscr11 : public CMenuProcess {
public:
    CMenuSysscr11();
    virtual ~CMenuSysscr11();
    virtual s32 Update();
    virtual s32 Draw();

    union {
        CMenuSub1A7658 *m_unk58;  // 0x58
        class CMenuInputKanji *m_kanji;
    };
    class CStatusItem *m_win; // 0x5C
};

//@sym __builtin_new 0x245648
class CMenuSysscr10 {
public:
    CMenuSysscr10() throw();

    u8 pad0[0x7C];
};
// @decl-end

CMenuSysscr11::CMenuSysscr11() {
    m_unk58 = 0;
}

CMenuSysscr11::~CMenuSysscr11() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr11", Update__13CMenuSysscr11);

s32 CMenuSysscr11::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

CMenuSysscr10 *CreateCMenuSysscr10() {
    return new CMenuSysscr10;
}
