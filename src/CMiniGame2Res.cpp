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
extern void *D_002A59FC;
extern void (*D_002B91B0)(void *p);
class CUnk1B6488 {
public:
    void Func1B6488(f32 x, f32 y);
};
extern CUnk1B6488 *D_002A5538;
struct CMiniGame2Pos { f32 x, y; u8 pad[8]; };
class CMiniGame2Res {
public:
    void Release();
    void Init1C4540(int a, int b);
    void Select(void);

    u8 pad0[0x10];
    CLayoutRes m10;           // 0x10
    CLayoutRes m34;           // 0x34
    void *m58;                // 0x58
    s32 m5C;                  // 0x5C
    u8 pad60[0xD60 - 0x60];
    s32 mD60;                 // 0xD60
    u8 padD64[0xDB4 - 0xD64];
    s32 mDB4[3];              // 0xDB4
    u8 padDC0[0xE10 - 0xDC0];
    f32 mE10f[4][4];          // 0xE10
};
void CreateMiniGame2Res(CResMgr24F *mgr, int a, int b);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C4100);

INCLUDE_RODATA("asm/nonmatchings/CMiniGame2Res", D_002E0F00);
INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C4158);

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C4260);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame2Res", D_002E0FC0);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame2Res", D_002E0FC8);

void CMiniGame2Res::Release() {
    D_002A59FC = 0;
    if (m58) {
        D_002B91B0(m58);
        m58 = 0;
        m5C = 0;
    }
    m34.Func1B9B30();
    m10.Func1B9B30();
}

void CreateMiniGame2Res(CResMgr24F *mgr, int a, int b) {
    CMiniGame2Res *p = (CMiniGame2Res *)Func24F2E8(0xE50);
    p->Init1C4540(a, b);
    mgr->Func24F5C0(p, 0);
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", Init1C4540__13CMiniGame2Resii);

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C4710);

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C4810);

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C48E8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C4A58);

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C4AC8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C4BB0);

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C4CA0);

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C4DD0);

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C4E90);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame2Res", D_002E10F0);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame2Res", D_002E1110);

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C95D8);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame2Res", D_002E1170);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame2Res", D_002E1180);
