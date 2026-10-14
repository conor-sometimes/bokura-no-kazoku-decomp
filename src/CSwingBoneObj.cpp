#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CSwingBoneObjSub1114C0 {
public:
    f32 GetUnk10(s32 i);

    u8 pad0[0x10];
    f32 m_unk10[1];           // 0x10
};

#include "libc.h"
extern void (*D_002B91B0)(void *p);

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CSwingBoneObj, its
// only virtual. The vptr follows its fields at 0x30.
class CSwingBoneObj {
public:
    CSwingBoneObj();
    virtual ~CSwingBoneObj();
    void Clear();
    void Release();

    s32 m_unk0;               // 0x00
    s32 m_unk4;               // 0x04
    void *m_unk8;             // 0x08
    s32 m_unkC;               // 0x0C
    u8 m_unk10[0xC];          // 0x10
    u8 m_unk1C[0xC];          // 0x1C
    f32 m_unk28;              // 0x28
    f32 m_unk2C;              // 0x2C
};
// @decl-end

CSwingBoneObj::CSwingBoneObj() {
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    Clear();
}

CSwingBoneObj::~CSwingBoneObj() {
    Release();
}

void CSwingBoneObj::Clear() {
    memset(m_unk10, 0, 0xC);
    memset(m_unk1C, 0, 0xC);
    m_unk2C = m_unk28 = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/CSwingBoneObj", func_00111260);

void CSwingBoneObj::Release() {
    if (m_unk8) {
        D_002B91B0(m_unk8);
        m_unk8 = 0;
        m_unkC = 0;
    }
    Clear();
    m_unk0 = 0;
    m_unk4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CSwingBoneObj", func_00111490);

f32 CSwingBoneObjSub1114C0::GetUnk10(s32 i) {
    return m_unk10[i];
}

INCLUDE_ASM("asm/nonmatchings/CSwingBoneObj", func_001114D0);

INCLUDE_ASM("asm/nonmatchings/CSwingBoneObj", func_00111548);
