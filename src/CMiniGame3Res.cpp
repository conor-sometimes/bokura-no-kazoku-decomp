#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CLayoutRes {
public:
    void Func1B9B30();
    u8 pad[0x24];
};
class CResMgr24F {
public:
    void Func24F5C0(void *res, int v);
};
void *Func24F2E8(int size);
struct CMiniGame3Ent {
    s32 m0;                   // 0x0
    s32 m4;                   // 0x4
    u8 pad8[0x8];
    f32 m10;                  // 0x10
    f32 m14;                  // 0x14
    f32 m18;                  // 0x18
    f32 m1C;                  // 0x1C
    s32 m20;                  // 0x20
    u8 pad24[0x4];
    f32 m28;                  // 0x28
    s32 m2C;                  // 0x2C
};
extern void *D_002A5A00;
class CMiniGame3Res {
public:
    void Release();
    void Init1C9D70(int a, int b);
    void Set3(u32 i);
    void Set5(u32 i);
    void Set2(u32 i);
    void Set1(u32 i);
    void Set4(u32 i, f32 t);
    void Layout(f32 t);

    u8 pad0[0x10];
    CLayoutRes m10;           // 0x10
    CLayoutRes m34;           // 0x34
    u8 pad58[0xBA8 - 0x58];
    s32 mBA8;                 // 0xBA8
    u8 padBAC[0xBF0 - 0xBAC];
    f32 mBF0, mBF4, mBF8, mBFC; // 0xBF0
    u8 padC00[0x30];
    CMiniGame3Ent m_ent[16];  // 0xC30
    u8 padF30[0x1C];
    f32 mF4C;                 // 0xF4C
};
void CreateMiniGame3Res(CResMgr24F *mgr, int a, int b);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001C9BB0);

INCLUDE_RODATA("asm/nonmatchings/CMiniGame3Res", D_002E1190);
INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001C9C08);

void CMiniGame3Res::Release() {
    D_002A5A00 = 0;
    m34.Func1B9B30();
    m10.Func1B9B30();
}

void CreateMiniGame3Res(CResMgr24F *mgr, int a, int b) {
    CMiniGame3Res *p = (CMiniGame3Res *)Func24F2E8(0xF70);
    p->Init1C9D70(a, b);
    mgr->Func24F5C0(p, 0);
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", Init1C9D70__13CMiniGame3Resii);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001C9E90);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001C9F80);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame3Res", D_002E1258);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame3Res", D_002E1260);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame3Res", D_002E1268);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA090);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA2B8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA378);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA3B8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA418);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA458);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA4C8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA528);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA5E8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA878);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA900);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame3Res", D_002E1318);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame3Res", D_002E1338);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001D4618);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame3Res", D_002E1388);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame3Res", D_002E1398);
