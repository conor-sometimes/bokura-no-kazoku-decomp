#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMenuProcess {
public:
    void SetState4();
    void SetState6();
    void SetUnk50(s32 v);

    u8 pad0[0x48];
    s32 m_state;              // 0x48
    u8 pad4C[0x4];
    s32 m_unk50;              // 0x50
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuProcess", func_001B3BA8);

INCLUDE_ASM("asm/nonmatchings/CMenuProcess", func_001B3BD0);

void CMenuProcess::SetState4() {
    m_state = 4;
}

void CMenuProcess::SetState6() {
    m_state = 6;
}

void CMenuProcess::SetUnk50(s32 v) {
    m_unk50 = v;
}

INCLUDE_ASM("asm/nonmatchings/CMenuProcess", func_001B3C30);
