#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
void *operator new(unsigned int n);
class CMenuSysscr32 {
public:
    void Init1A7B68();
};
CMenuSysscr32 *NewCMenuSysscr32();
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr32", D_002DEEB8);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr32", D_002DEF20);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr32", D_002DF0A0);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr32", D_002DF0B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr32", D_002DF0E8);
INCLUDE_ASM("asm/nonmatchings/CMenuSysscr32", Init1A7758__16CMenuInputKanji2);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr32", func_001A77A0);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr32", func_001A7818);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr32", func_001A7A00);

CMenuSysscr32 *NewCMenuSysscr32() {
    CMenuSysscr32 *p = (CMenuSysscr32 *)operator new(0x84);
    p->Init1A7B68();
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr32", func_001A7AF8);
