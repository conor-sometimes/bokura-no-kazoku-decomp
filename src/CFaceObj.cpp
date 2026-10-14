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
    s32 Func10DD38();

    s32 m_unk0;               // 0x0
    CFaceObjSub10DC60Item* m_item; // 0x4
    u8 pad8[0x8];
    s32 m_unk10;              // 0x10
};

void *Func245D00(int size);
extern void (*D_002B91B0)(void *p);
struct CFacePart {
    void *m_unk0;             // 0x0
    s32 m_unk4;               // 0x4
};
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CFaceObj, its only
// virtual. The vptr follows its fields at 0x50. (CCharaObj.cpp called it CCharaObjPart24.)
class CFaceObj {
public:
    CFaceObj();
    virtual ~CFaceObj();
    void Release();

    s32 m_unk0;               // 0x00
    CFacePart *m_parts;       // 0x04
    s32 m_unk8;               // 0x08
    s32 m_unkC;               // 0x0C
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    u8 pad1C[0x30];
    s32 m_unk4C;              // 0x4C
};
// @decl-end

CFaceObj::CFaceObj() {
    s32 i;
    m_parts = (CFacePart *)Func245D00(0x18);
    for (i = 0; i < 3; i++) {
        m_parts[i].m_unk0 = 0;
        m_parts[i].m_unk4 = 0;
    }
    m_unk18 = -1;
    m_unk8 = 0;
    m_unkC = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk4C = 0;
}

CFaceObj::~CFaceObj() {
    Release();
    if (m_parts) {
        D_002B91B0(m_parts);
    }
}

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010D8F8);

void CFaceObj::Release() {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (m_parts[i].m_unk0) {
            D_002B91B0(m_parts[i].m_unk0);
            m_parts[i].m_unk0 = 0;
            m_parts[i].m_unk4 = 0;
        }
    }
    m_unk18 = -1;
    m_unk8 = 0;
    m_unkC = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk4C = 0;
    m_unk0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010DA40);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", Func10DB70__8CFaceObj);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", Func10DBD8__8CFaceObj);

s32 CFaceObjSub10DC60::GetItemUnk14() {
    return m_unk0 ? m_item->m_unk14 : 0;
}

INCLUDE_ASM("asm/nonmatchings/CFaceObj", Func10DC80__8CFaceObj);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", Func10DD38__17CFaceObjSub10DC60);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010DD88);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010DE20);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010DFD0);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010E0B0);

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010E138);
