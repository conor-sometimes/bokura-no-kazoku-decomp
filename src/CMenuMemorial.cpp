#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CUnk1A4298 {
public:
    int Func1A4298();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuMemorial.
class CMenuMemorial : public CMenuProcess {
public:
    CMenuMemorial();
    virtual ~CMenuMemorial();
    virtual s32 Update();
    virtual s32 Draw();

    CUnk1A4298 *m_unk58;      // 0x58
};

//@sym __builtin_new 0x245648
//@sym __17CMenuLoadMemorial 0x176B98
class CMenuLoadMemorial {
public:
    CMenuLoadMemorial() throw();

    u8 pad0[0x7DC0];
};
// @decl-end

CMenuMemorial::CMenuMemorial() {
    m_unk58 = 0;
}

CMenuMemorial::~CMenuMemorial() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuMemorial", Update__13CMenuMemorial);
INCLUDE_RODATA("asm/nonmatchings/CMenuMemorial", D_002DA5D8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMemorial", D_002DA5F8);

s32 CMenuMemorial::Draw() {
    return m_unk58->Func1A4298();
}

CMenuLoadMemorial *CreateCMenuLoadMemorial() {
    return new CMenuLoadMemorial;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMemorial", func_00176AE0);

INCLUDE_ASM("asm/nonmatchings/CMenuMemorial", func_00176B38);
