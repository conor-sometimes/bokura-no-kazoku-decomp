#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CSceneSetItemA {
public:


    u8 pad0[0x4C];
    s32 m_unk4C;              // 0x4C
    s32 m_unk50;              // 0x50
};
class CSceneSetItemB {
public:


    u8 pad0[0x20];
    s32 m_unk20;              // 0x20
    s32 m_unk24;              // 0x24
};
class CSceneSet {
public:
    CSceneSetItemA *FindA(s32 id);
    CSceneSetItemB *FindB(s32 id);
    s32 GetAUnk4C(s32 id);
    s32 GetAUnk50(s32 id);
    s32 GetBUnk20(s32 id);
    s32 GetBUnk24(s32 id);


};
//@sym FindA__9CSceneSeti 0x12CC60
//@sym FindB__9CSceneSeti 0x12D070
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012C4A8);

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012C4F0);

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012C578);

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012C5F0);

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012C630);

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012C6A8);

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012C6F8);

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012C7E0);

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012C8D0);

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012CB00);

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012CBF0);

INCLUDE_ASM("asm/nonmatchings/CSceneSet", FindA__9CSceneSeti);

s32 CSceneSet::GetAUnk4C(s32 id) {
    CSceneSetItemA *p = FindA(id);
    if (p) {
        return p->m_unk4C;
    }
    return 0;
}

s32 CSceneSet::GetAUnk50(s32 id) {
    CSceneSetItemA *p = FindA(id);
    if (p) {
        return p->m_unk50;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012CD30);

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012CF40);

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012CFF0);

INCLUDE_ASM("asm/nonmatchings/CSceneSet", FindB__9CSceneSeti);

s32 CSceneSet::GetBUnk20(s32 id) {
    CSceneSetItemB *p = FindB(id);
    if (p) {
        return p->m_unk20;
    }
    return 0;
}

s32 CSceneSet::GetBUnk24(s32 id) {
    CSceneSetItemB *p = FindB(id);
    if (p) {
        return p->m_unk24;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012D148);
