#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CDiffMotionObjSub10FB10 {
public:
    void Reset();

    u8 pad0[0x14];
    s32 m_unk14;              // 0x14
    f32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    f32 m_unk20;              // 0x20
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CDiffMotionObj", func_0010FA70);

INCLUDE_ASM("asm/nonmatchings/CDiffMotionObj", func_0010FAB0);

void CDiffMotionObjSub10FB10::Reset() {
    m_unk14 = 1;
    m_unk18 = 1.0f;
    m_unk20 = 1.0f;
    m_unk1C = 0;
}

INCLUDE_ASM("asm/nonmatchings/CDiffMotionObj", func_0010FB30);

INCLUDE_ASM("asm/nonmatchings/CDiffMotionObj", func_0010FC98);

INCLUDE_ASM("asm/nonmatchings/CDiffMotionObj", func_0010FD20);

INCLUDE_ASM("asm/nonmatchings/CDiffMotionObj", func_0010FD58);

INCLUDE_ASM("asm/nonmatchings/CDiffMotionObj", func_0010FE08);
