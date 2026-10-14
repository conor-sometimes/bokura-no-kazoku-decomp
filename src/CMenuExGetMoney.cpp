#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuExGetMoney.
class CMenuExGetMoney : public CMenuProcess {
public:
    CMenuExGetMoney();
    virtual ~CMenuExGetMoney();
    virtual s32 Update();
    virtual s32 Draw();

    s32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
    u8 pad60[0x4];
    s32 m_unk64;              // 0x64
    s32 m_unk68;              // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    f32 m_unk74;              // 0x74
};

class CMenuConfig {
public:
    CMenuConfig() throw();

    u8 pad0[0x7C];
};
// @decl-end

CMenuExGetMoney::CMenuExGetMoney() {
    m_unk58 = 0;
    m_unk64 = 0;
    m_unk68 = 0;
    m_unk6C = 0;
    m_unk70 = 0;
    m_unk74 = 1.0f;
    m_unk5C = 0;
}

CMenuExGetMoney::~CMenuExGetMoney() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuExGetMoney", Update__15CMenuExGetMoney);

INCLUDE_ASM("asm/nonmatchings/CMenuExGetMoney", Draw__15CMenuExGetMoney);
INCLUDE_RODATA("asm/nonmatchings/CMenuExGetMoney", D_002DA470);

CMenuConfig *CreateCMenuConfig() {
    return new CMenuConfig;
}
