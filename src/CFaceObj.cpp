#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CFaceObjSub10DC60Item {
public:


    u8 pad0[0x14];
    s32 m_unk14;              // 0x14
};
class CFaceObjSub10DC60 {
public:
    s32 GetItemUnk14();

    s32 m_unk0;               // 0x0
    CFaceObjSub10DC60Item* m_item; // 0x4
};
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CFaceObj", D_002D2DB0);
INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010D7F0);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010D878);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010D8F8);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010D990);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010DA40);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", Func10DB70__15CCharaObjPart24);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", Func10DBD8__15CCharaObjPart24);

s32 CFaceObjSub10DC60::GetItemUnk14() {
    return m_unk0 ? m_item->m_unk14 : 0;
}

INCLUDE_ASM("asm/nonmatchings/CFaceObj", Func10DC80__15CCharaObjPart24);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010DD38);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010DD88);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010DE20);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010DFD0);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010E0B0);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010E138);
