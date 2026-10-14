#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuSub1A7658 {
public:
    int Func1A7658();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuAsksave.
class CMenuAsksave : public CMenuProcess {
public:
    CMenuAsksave();
    virtual ~CMenuAsksave();
    virtual s32 Update();
    virtual s32 Draw();
    void Init192D38();        // CMenuAsksavequit's constructor (that unit's name for it)

    CMenuSub1A7658 *m_unk58;  // 0x58
    u8 pad5C[0x4];
};

void *operator new(unsigned int n);
CMenuAsksave *NewCMenuAsksave();
// @decl-end

CMenuAsksave::CMenuAsksave() {
    m_unk58 = 0;
}

CMenuAsksave::~CMenuAsksave() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuAsksave", Update__12CMenuAsksave);

s32 CMenuAsksave::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

// Creates the CMenuAsksavequit screen.
CMenuAsksave *NewCMenuAsksave() {
    CMenuAsksave *p = (CMenuAsksave *)operator new(0x60);
    p->Init192D38();
    return p;
}
