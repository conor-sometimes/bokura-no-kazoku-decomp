#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CUnk1A4298 {
public:
    int Func1A4298();
};
class CMenuMemorial {
public:
    int CallFunc1A4298();

    u8 pad0[0x58];
    CUnk1A4298* m_unk58;      // 0x58
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuMemorial", func_00176598);

INCLUDE_ASM("asm/nonmatchings/CMenuMemorial", func_001765D0);

INCLUDE_ASM("asm/nonmatchings/CMenuMemorial", func_00176638);

int CMenuMemorial::CallFunc1A4298() {
    return m_unk58->Func1A4298();
}

INCLUDE_ASM("asm/nonmatchings/CMenuMemorial", func_00176AA8);

INCLUDE_ASM("asm/nonmatchings/CMenuMemorial", func_00176AE0);

INCLUDE_ASM("asm/nonmatchings/CMenuMemorial", func_00176B38);
