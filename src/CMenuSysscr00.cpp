#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CUnk1A4298 {
public:
    int Func1A4298();
};
class CMenuSysscr00 {
public:
    int CallFunc1A4298();

    u8 pad0[0x58];
    CUnk1A4298* m_unk58;      // 0x58
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr00", func_001AE488);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr00", func_001AE4C0);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr00", func_001AE528);

int CMenuSysscr00::CallFunc1A4298() {
    return m_unk58->Func1A4298();
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr00", func_001AE770);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr00", func_001AE7A8);
