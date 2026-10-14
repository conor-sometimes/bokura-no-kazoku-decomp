#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_0018F528(void *p);
class CMenuGetMoney {
public:
    static CMenuGetMoney *Create();
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuPTJobMoney", func_0018E750);

INCLUDE_ASM("asm/nonmatchings/CMenuPTJobMoney", func_0018E7E0);

INCLUDE_ASM("asm/nonmatchings/CMenuPTJobMoney", func_0018E848);

INCLUDE_ASM("asm/nonmatchings/CMenuPTJobMoney", func_0018EE78);

CMenuGetMoney *CMenuGetMoney::Create() {
    CMenuGetMoney *p = (CMenuGetMoney *)operator new(0x7C);
    func_0018F528(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CMenuPTJobMoney", func_0018F448);

INCLUDE_ASM("asm/nonmatchings/CMenuPTJobMoney", func_0018F4D8);
