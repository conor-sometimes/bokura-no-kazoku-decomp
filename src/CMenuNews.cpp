#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CUnk1A4298 {
public:
    int Func1A4298();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuNews.
class CMenuNews : public CMenuProcess {
public:
    CMenuNews();
    virtual ~CMenuNews();
    virtual s32 Update();
    virtual s32 Draw();

    CUnk1A4298 *m_unk58;      // 0x58
};

class CMenuExGetMoney {
public:
    CMenuExGetMoney() throw();

    u8 pad0[0x78];
};
// @decl-end

CMenuNews::CMenuNews() {
    m_unk58 = 0;
}

CMenuNews::~CMenuNews() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuNews", Update__9CMenuNews);
INCLUDE_RODATA("asm/nonmatchings/CMenuNews", D_002DA3D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuNews", D_002DA3F0);

s32 CMenuNews::Draw() {
    return m_unk58->Func1A4298();
}

CMenuExGetMoney *CreateCMenuExGetMoney() {
    return new CMenuExGetMoney;
}

INCLUDE_ASM("asm/nonmatchings/CMenuNews", func_00174058);

INCLUDE_ASM("asm/nonmatchings/CMenuNews", func_001740E8);
