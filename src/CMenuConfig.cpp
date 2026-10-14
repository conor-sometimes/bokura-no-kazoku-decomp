#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuConfig.
class CMenuConfig : public CMenuProcess {
public:
    CMenuConfig();
    virtual ~CMenuConfig();
    virtual s32 Update();
    virtual s32 Draw();

    s32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
    s32 m_unk64;              // 0x64
    u8 pad68[0x14];
};

//@sym __builtin_new 0x245648
class CMenuNosave {
public:
    CMenuNosave() throw();

    u8 pad0[0x60];
};
// @decl-end

CMenuConfig::CMenuConfig() {
    m_unk58 = 0;
    m_unk5C = 0;
    m_unk60 = 0;
    m_unk64 = 0;
}

CMenuConfig::~CMenuConfig() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuConfig", Update__11CMenuConfig);
INCLUDE_RODATA("asm/nonmatchings/CMenuConfig", D_002DA4C0);
INCLUDE_RODATA("asm/nonmatchings/CMenuConfig", D_002DA4E0);

INCLUDE_ASM("asm/nonmatchings/CMenuConfig", Draw__11CMenuConfig);

CMenuNosave *CreateCMenuNosave() {
    return new CMenuNosave;
}
