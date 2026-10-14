#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001900B0(void *p);
class CMenuReviewResult {
public:
    static CMenuReviewResult *Create();
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuGetMoney", func_0018F528);

INCLUDE_ASM("asm/nonmatchings/CMenuGetMoney", func_0018F580);

INCLUDE_ASM("asm/nonmatchings/CMenuGetMoney", func_0018F5E8);

INCLUDE_ASM("asm/nonmatchings/CMenuGetMoney", func_0018FB50);

CMenuReviewResult *CMenuReviewResult::Create() {
    CMenuReviewResult *p = (CMenuReviewResult *)operator new(0x78);
    func_001900B0(p);
    return p;
}
