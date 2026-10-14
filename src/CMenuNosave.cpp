#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuSub1A7658 {
public:
    int Func1A7658();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuNosave.
class CMenuNosave : public CMenuProcess {
public:
    CMenuNosave();
    virtual ~CMenuNosave();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuSub1A7658 *m_unk58;  // 0x58
    u8 pad5C[0x4];
};

//@sym __builtin_new 0x245648
class CMenuMemorial {
public:
    CMenuMemorial() throw();

    u8 pad0[0x5C];
};
// @decl-end

CMenuNosave::CMenuNosave() {
    m_unk58 = 0;
}

CMenuNosave::~CMenuNosave() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuNosave", Update__11CMenuNosave);

s32 CMenuNosave::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

CMenuMemorial *CreateCMenuMemorial() {
    return new CMenuMemorial;
}
