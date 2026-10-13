#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CPadMgr {
public:
    void SetUnk18(s32 v);

    u8 pad0[0x8];
    s32 m_unk8;               // 0x8
    s32 m_unkC;               // 0xC
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/IPadMgr", func_0010AF00);

void CPadMgr::SetUnk18(s32 v) {
    if (m_unk18 != v) {
        m_unk18 = v;
        m_unk8 = 0;
        m_unk10 = 0;
        m_unk14 = 0;
        m_unkC = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/IPadMgr", func_0010AFA0);

INCLUDE_ASM("asm/nonmatchings/IPadMgr", func_0010B000);
