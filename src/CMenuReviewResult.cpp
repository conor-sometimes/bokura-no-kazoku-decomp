#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuReviewResult.
class CMenuReviewResult : public CMenuProcess {
public:
    CMenuReviewResult();
    virtual ~CMenuReviewResult();
    virtual s32 Update();
    virtual s32 Draw();
    void Init191338();        // CMenuReviewSelect's constructor (that unit's name for it)

    s32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
    u8 pad60[0x8];
    s32 m_unk68;              // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
};

void *operator new(unsigned int n);
CMenuReviewResult *NewCMenuReviewResult();
// @decl-end

CMenuReviewResult::CMenuReviewResult() {
    m_unk58 = 0;
    m_unk5C = 0;
    m_unk68 = 0;
    m_unk6C = 0;
    m_unk70 = 0;
    m_unk74 = 0;
}

CMenuReviewResult::~CMenuReviewResult() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuReviewResult", Update__17CMenuReviewResult);
INCLUDE_RODATA("asm/nonmatchings/CMenuReviewResult", D_002DBB80);

INCLUDE_RODATA("asm/nonmatchings/CMenuReviewResult", D_002DBB90);
INCLUDE_ASM("asm/nonmatchings/CMenuReviewResult", Draw__17CMenuReviewResult);

// Creates the CMenuReviewSelect screen.
CMenuReviewResult *NewCMenuReviewResult() {
    CMenuReviewResult *p = (CMenuReviewResult *)operator new(0x7C);
    p->Init191338();
    return p;
}
