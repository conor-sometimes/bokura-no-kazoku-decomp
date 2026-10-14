#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuGetMoney.
class CMenuGetMoney : public CMenuProcess {
public:
    CMenuGetMoney();
    virtual ~CMenuGetMoney();
    virtual s32 Update();
    virtual s32 Draw();

    s32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
    u8 pad64[0x4];
    s32 m_unk68;              // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
    f32 m_unk78;              // 0x78
};

extern "C" void func_001900B0(void *p);
class CMenuReviewResult {
public:
    static CMenuReviewResult *Create();
};
// @decl-end

CMenuGetMoney::CMenuGetMoney() {
    m_unk58 = 0;
    m_unk5C = 0;
    m_unk78 = 1.0f;
    m_unk68 = 0;
    m_unk6C = 0;
    m_unk70 = 0;
    m_unk74 = 0;
    m_unk60 = 0;
}

CMenuGetMoney::~CMenuGetMoney() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuGetMoney", Update__13CMenuGetMoney);

INCLUDE_RODATA("asm/nonmatchings/CMenuGetMoney", D_002DBB08);
INCLUDE_ASM("asm/nonmatchings/CMenuGetMoney", Draw__13CMenuGetMoney);

CMenuReviewResult *CMenuReviewResult::Create() {
    CMenuReviewResult *p = (CMenuReviewResult *)operator new(0x78);
    func_001900B0(p);
    return p;
}
