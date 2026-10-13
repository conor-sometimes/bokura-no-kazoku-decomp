#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CCommandBase {
public:
    int RowOf(int v);


};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CCommandBase", func_00198080);

INCLUDE_ASM("asm/nonmatchings/CCommandBase", func_00198128);

INCLUDE_ASM("asm/nonmatchings/CCommandBase", func_00198220);

INCLUDE_ASM("asm/nonmatchings/CCommandBase", func_00198258);

INCLUDE_ASM("asm/nonmatchings/CCommandBase", func_00198290);

INCLUDE_ASM("asm/nonmatchings/CCommandBase", func_00198328);

INCLUDE_ASM("asm/nonmatchings/CCommandBase", func_001983D8);

INCLUDE_ASM("asm/nonmatchings/CCommandBase", func_00198430);

INCLUDE_ASM("asm/nonmatchings/CCommandBase", func_00198488);

INCLUDE_ASM("asm/nonmatchings/CCommandBase", func_001984E0);

int CCommandBase::RowOf(int v) {
    if (v < 7) {
        return 0;
    }
    return (v - 7) / 6 + 1;
}

INCLUDE_ASM("asm/nonmatchings/CCommandBase", func_00198548);

INCLUDE_ASM("asm/nonmatchings/CCommandBase", func_001985D0);
