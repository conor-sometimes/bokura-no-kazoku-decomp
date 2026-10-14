#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuSub1A7658 {
public:
    int Func1A7658();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuContinue.
class CMenuContinue : public CMenuProcess {
public:
    CMenuContinue();
    virtual ~CMenuContinue();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuSub1A7658 *m_unk58;  // 0x58
    u8 pad5C[0x4];
};

//@sym __builtin_new 0x245648
//@sym __12CMenuAsksave 0x1929C8
class CMenuAsksave {
public:
    CMenuAsksave() throw();

    u8 pad0[0x60];
};
// @decl-end

CMenuContinue::CMenuContinue() {
    m_unk58 = 0;
}

CMenuContinue::~CMenuContinue() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuContinue", Update__13CMenuContinue);

s32 CMenuContinue::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

CMenuAsksave *CreateCMenuAsksave() {
    return new CMenuAsksave;
}
