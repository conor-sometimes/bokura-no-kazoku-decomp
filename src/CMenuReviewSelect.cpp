#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_00191E28(void *p);
class CMenuReviewStart {
public:
    static CMenuReviewStart *Create();
};
#include "CMenuProcess.h"
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuReviewSelect.
class CMenuReviewSelect : public CMenuProcess {
public:
    CMenuReviewSelect();
    virtual ~CMenuReviewSelect();
    virtual s32 Update();
    virtual s32 Draw();

    s32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
    u8 pad60[0x8];
    s32 m_unk68[5];           // 0x68
};
// @decl-end

CMenuReviewSelect::CMenuReviewSelect() {
    s32 i;
    m_unk58 = 0;
    m_unk5C = 0;
    for (i = 4; i >= 0; i--) {
        m_unk68[i] = 0;
    }
}

CMenuReviewSelect::~CMenuReviewSelect() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuReviewSelect", Update__17CMenuReviewSelect);
INCLUDE_RODATA("asm/nonmatchings/CMenuReviewSelect", D_002DBC00);
INCLUDE_RODATA("asm/nonmatchings/CMenuReviewSelect", D_002DBC20);

INCLUDE_ASM("asm/nonmatchings/CMenuReviewSelect", Draw__17CMenuReviewSelect);

CMenuReviewStart *CMenuReviewStart::Create() {
    CMenuReviewStart *p = (CMenuReviewStart *)operator new(0x68);
    func_00191E28(p);
    return p;
}
