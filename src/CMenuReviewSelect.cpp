#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_00191E28(void *p);
class CMenuReviewStart {
public:
    static CMenuReviewStart *Create();
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuReviewSelect", Init191338__17CMenuReviewResult);

INCLUDE_ASM("asm/nonmatchings/CMenuReviewSelect", func_00191398);

INCLUDE_ASM("asm/nonmatchings/CMenuReviewSelect", func_00191400);

INCLUDE_ASM("asm/nonmatchings/CMenuReviewSelect", func_00191A30);

CMenuReviewStart *CMenuReviewStart::Create() {
    CMenuReviewStart *p = (CMenuReviewStart *)operator new(0x68);
    func_00191E28(p);
    return p;
}
