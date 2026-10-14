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

#include "CCommandBase.h"
extern "C" void func_00196B50(void *p);
// Vtable 0x2C1A60: Update (key method, 0x1986A8) and Draw.
class CCommandSelect : public CCommandBase {
public:
    CCommandSelect();
    virtual s32 Update();
    virtual s32 Draw();

    u8 pad4EC[0x54];
};
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD928);
INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD940);
INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD960);
INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD9A0);
CCommandSelect::CCommandSelect() {
    func_00196B50(this);
}

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", Update__14CCommandSelect);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", Draw__14CCommandSelect);

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
