#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMiniGame6Obj {
public:
    s32 GetRemaining();
    int Func247B00();

    u8 pad0[0x14];
    s32 m_unk14;              // 0x14
    u8 pad18[0x30];
    s32 m_unk48;              // 0x48
};
extern CMiniGame6Obj *D_002A5BAC;
extern CMiniGame6Obj *D_002A5BB0;
extern s32 D_002A5BB8;
extern s32 D_002A5B90;
extern s32 D_002A5B94;

s32 Func23E290();
extern void (*D_002B91B0)();
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E33E8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3440);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E34E8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E35A8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E35E0);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3660);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3978);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3BC8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3C48);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3CD0);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3D50);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3DC0);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3F20);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3FF8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E4630);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E4C70);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E6E80);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E71A0);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E72D0);

s32 GetMiniGame6Remaining() {
    return 0x400000 - Func23E290();
}

s32 CMiniGame6Obj::GetRemaining() {
    return m_unk14 - m_unk48;
}

s32 GetMiniGame6RemainingA() {
    return D_002A5BAC->GetRemaining();
}

s32 GetMiniGame6RemainingB() {
    return D_002A5BB0->GetRemaining();
}

int CallMiniGame6Func247B00A() {
    return D_002A5BAC->Func247B00();
}

int CallMiniGame6Func247B00B() {
    return D_002A5BB0->Func247B00();
}

CMiniGame6Obj *GetMiniGame6ObjA() {
    return D_002A5BAC;
}

CMiniGame6Obj *GetMiniGame6ObjB() {
    return D_002A5BB0;
}

s32 GetMiniGame6Unk2A5BB8() {
    return D_002A5BB8;
}

s32 GetMiniGame6Unk2A5B90() {
    return D_002A5B90;
}

s32 GetMiniGame6Unk2A5B94() {
    return D_002A5B94;
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E7E58);

void CallMiniGame6Hook() {
    D_002B91B0();
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E7ED8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E8030);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E80A0);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E8B58);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E8C28);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E8CA8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E8D68);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E9168);
