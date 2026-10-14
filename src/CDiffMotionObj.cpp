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

f32 Func1EAC30(int v);
class CDiffMotionObj10FD20 {
public:
    f32 GetFrame();
    u8 pad0[8];
    s32 m8;
};
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CDiffMotionObj.
// CDiffMotionObjSub10FB10 is the same object's part from 0x14.
class CDiffMotionObj {
public:
    CDiffMotionObj();
    virtual ~CDiffMotionObj();
    void Func10FC98();

    s32 m_unk0;               // 0x00
    s32 m_unk4;               // 0x04
    s32 m_unk8;               // 0x08
    s32 m_unkC;               // 0x0C
    s32 m_unk10;              // 0x10
    u8 pad14[0x10];
    // vptr 0x24
};
// @decl-end

CDiffMotionObj::CDiffMotionObj() {
    m_unk8 = -1;
    m_unk0 = 0;
    m_unk4 = 0;
    m_unkC = 0;
    m_unk10 = 0;
    ((CDiffMotionObjSub10FB10 *)this)->Reset();
}

CDiffMotionObj::~CDiffMotionObj() {
    Func10FC98();
}

void CDiffMotionObjSub10FB10::Reset() {
    m_unk14 = 1;
    m_unk18 = 1.0f;
    m_unk20 = 1.0f;
    m_unk1C = 0;
}

INCLUDE_ASM("asm/nonmatchings/CDiffMotionObj", func_0010FB30);

INCLUDE_ASM("asm/nonmatchings/CDiffMotionObj", Func10FC98__14CDiffMotionObj);

f32 CDiffMotionObj10FD20::GetFrame() {
    if (m8 < 0) return 0.0f;
    return Func1EAC30(m8) - 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/CDiffMotionObj", func_0010FD58);

INCLUDE_ASM("asm/nonmatchings/CDiffMotionObj", func_0010FE08);
