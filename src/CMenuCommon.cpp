#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMenuCommonItem {
public:


    u8 pad0[0x20];
    s32 m_state;              // 0x20
};
class CMenuCommonSub18C110 {
public:
    s32 GetUnk14();
    s32 GetItemState();

    CMenuCommonItem* m_item;  // 0x0
    u8 pad4[0x10];
    s32 m_unk14;              // 0x14
};
class CMenuCommonSub18E0E0 {
public:
    s32 GetUnk8();
    s32 GetItemState();

    CMenuCommonItem* m_item;  // 0x0
    u8 pad4[0x4];
    s32 m_unk8;               // 0x8
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018AF98);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018AFE8);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018B080);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018B7B0);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018B880);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018B990);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018B9E0);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018BB10);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018BDF0);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018BEE8);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018C050);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018C0B0);

s32 CMenuCommonSub18C110::GetUnk14() {
    return m_unk14;
}

s32 CMenuCommonSub18C110::GetItemState() {
    return m_item ? m_item->m_state : -1;
}

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018C130);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018CE28);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018CEF0);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018D678);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018D768);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018D838);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018D8B8);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018D918);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018D958);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018DF88);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018DFC8);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018E008);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018E060);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018E0A0);

s32 CMenuCommonSub18E0E0::GetUnk8() {
    return m_unk8;
}

s32 CMenuCommonSub18E0E0::GetItemState() {
    return m_item ? m_item->m_state : -1;
}

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018E100);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018E1E0);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018E638);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018E670);

INCLUDE_ASM("asm/nonmatchings/CMenuCommon", func_0018E700);
