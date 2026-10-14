#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuReviewStart.
class CMenuReviewStart : public CMenuProcess {
public:
    CMenuReviewStart();
    virtual ~CMenuReviewStart();
    virtual s32 Update();
    virtual s32 Draw();

    s32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
};

//@sym __builtin_new 0x245648
class CMenuContinue {
public:
    CMenuContinue() throw();

    u8 pad0[0x60];
};
// @decl-end

CMenuReviewStart::CMenuReviewStart() {
    m_unk58 = 0;
    m_unk5C = 0;
}

CMenuReviewStart::~CMenuReviewStart() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuReviewStart", Update__16CMenuReviewStart);
INCLUDE_RODATA("asm/nonmatchings/CMenuReviewStart", D_002DBCC0);
INCLUDE_RODATA("asm/nonmatchings/CMenuReviewStart", D_002DBCE0);

INCLUDE_ASM("asm/nonmatchings/CMenuReviewStart", Draw__16CMenuReviewStart);

CMenuContinue *CreateCMenuContinue() {
    return new CMenuContinue;
}
