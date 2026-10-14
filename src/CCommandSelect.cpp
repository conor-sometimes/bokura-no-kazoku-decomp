#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym memset 0x289FB0
#include "libc.h"
class CCommandSelectSub1990E0 {
public:
    void Clear();

    u8 pad0[0x4F0];
    u8 m_data[0x40];          // 0x4F0
};
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD928);
INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD940);
INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD960);
INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD9A0);
INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00198670);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_001986A8);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_001989D8);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00198C70);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00198CE0);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00198E40);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00198FA0);

void CCommandSelectSub1990E0::Clear() {
    memset(m_data, 0, sizeof(m_data));
}

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00199108);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00199150);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_001992E0);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_001993A0);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00199500);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00199BC0);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_0019A480);
