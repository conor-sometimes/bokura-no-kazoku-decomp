#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001ACCE8(void *p);
class CMenuSysscr05 {
public:
    static CMenuSysscr05 *Create();
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr06", func_001AC820);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr06", func_001AC880);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr06", func_001AC8E8);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr06", func_001ACC60);

CMenuSysscr05 *CMenuSysscr05::Create() {
    CMenuSysscr05 *p = (CMenuSysscr05 *)operator new(0x5C);
    func_001ACCE8(p);
    return p;
}
