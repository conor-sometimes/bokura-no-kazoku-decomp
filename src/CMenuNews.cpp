#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CUnk1A4298 {
public:
    int Func1A4298();
};
class CMenuNews {
public:
    int CallFunc1A4298();

    u8 pad0[0x58];
    CUnk1A4298* m_unk58;      // 0x58
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuNews", func_00173A68);

INCLUDE_ASM("asm/nonmatchings/CMenuNews", func_00173AA0);

INCLUDE_ASM("asm/nonmatchings/CMenuNews", func_00173B08);

int CMenuNews::CallFunc1A4298() {
    return m_unk58->Func1A4298();
}

INCLUDE_ASM("asm/nonmatchings/CMenuNews", func_00174020);

INCLUDE_ASM("asm/nonmatchings/CMenuNews", func_00174058);

INCLUDE_ASM("asm/nonmatchings/CMenuNews", func_001740E8);
