#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void *func_0023FD90(s32);
extern "C" void func_00241398(void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" void func_00241778(void *, s32, s32, s32, s32, s32);
extern "C" void func_002419E8(void *, s32, s32, s32, s32, s32, s32);
extern "C" void func_00241D68(void);
struct FontEnt { u8 pad[0x30]; s32 m30, m34, m38; };
extern u64 *D_38EF84;
extern s32 D_38EFE0;
extern s32 D_38EFE4;
extern s32 D_38EF98;
extern f32 D_38EF88;
extern f32 D_38EF8C;
extern f32 D_38EF9C;
extern f32 D_38EFA0;
extern f32 D_38EFA4;
extern f32 D_38EFA8;
extern f32 D_38EFAC;
extern f32 D_38EFB0;
extern f32 D_38EFB4;
extern f32 D_38EFB8;
extern f32 D_38EFBC;
extern f32 D_38EFC0;
extern f32 D_38EFC4;
extern f32 D_38EFC8;
extern f32 D_38EFCC;

extern u8 *D_002B94E4;
extern s32 D_38EFD0[4];
extern "C" void func_00237460(void);
extern "C" s32 func_00237450(void);
extern "C" void func_002374B0(void);
extern "C" void *func_002377D8(void);
#define PUT32(v) { u32 *w_ = (u32 *)D_002B94E4; D_002B94E4 = (u8 *)(w_ + 1); *w_ = (v); }

struct PsmInfo { u32 m0; u32 m4; u32 m8; u32 mC; };
extern PsmInfo D_002B9D08[];
struct Tim2Pic { u32 m0; u32 m4; u32 m8; u16 mC; u16 mE; u8 m10, m11, m12, m13; u16 m14; u16 m16; };
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Unit240FD8", func_00240FD8);

INCLUDE_ASM("asm/nonmatchings/Unit240FD8", func_002410D8);

INCLUDE_ASM("asm/nonmatchings/Unit240FD8", func_00241238);

INCLUDE_ASM("asm/nonmatchings/Unit240FD8", func_00241398);

extern "C" void func_00241628(s32 id, s32 a, s32 b, s32 c, s32 d, s32 e) {
    FontEnt *p = (FontEnt *)func_0023FD90(id);
    if (p == 0) return;
    if (p->m34 == 0) return;
    return func_00241398(p, p->m34, p->m30, a, b, c, d, e);
}

extern "C" void func_002416D0(s32 id, s32 a, s32 b, s32 c, s32 d, s32 e) {
    FontEnt *p = (FontEnt *)func_0023FD90(id);
    if (p == 0) return;
    if (p->m38 == 0) return;
    return func_00241398(p, p->m38, p->m30, a, b, c, d, e);
}

INCLUDE_ASM("asm/nonmatchings/Unit240FD8", func_00241778);

extern "C" void func_002418E8(s32 id, s32 a, s32 b, s32 c) {
    FontEnt *p = (FontEnt *)func_0023FD90(id);
    if (p == 0) return;
    if (p->m34 == 0) return;
    return func_00241778(p, p->m34, p->m30, a, b, c);
}

extern "C" void func_00241968(s32 id, s32 a, s32 b, s32 c) {
    FontEnt *p = (FontEnt *)func_0023FD90(id);
    if (p == 0) return;
    if (p->m38 == 0) return;
    return func_00241778(p, p->m38, p->m30, a, b, c);
}

INCLUDE_ASM("asm/nonmatchings/Unit240FD8", func_002419E8);

extern "C" void func_00241AE0(s32 id, s32 a, s32 b, s32 c, s32 d) {
    FontEnt *p = (FontEnt *)func_0023FD90(id);
    if (p == 0) return;
    if (p->m34 == 0) return;
    return func_002419E8(p, p->m34, p->m30, a, b, c, d);
}

extern "C" void func_00241B78(s32 id, s32 a, s32 b, s32 c, s32 d) {
    FontEnt *p = (FontEnt *)func_0023FD90(id);
    if (p == 0) return;
    if (p->m38 == 0) return;
    return func_002419E8(p, p->m38, p->m30, a, b, c, d);
}

extern "C" s32 func_00241C10(u32 *p) {
    return *p == 0x324D4954;
}

extern "C" s32 func_00241C28(u32 *tim, u8 **pImg, u64 *pPsm, s32 *pW, s32 *pH, u8 **pClut, u64 *pCpsm, u32 *pDiv, s32 *pCnt) {
    Tim2Pic *p;
    u8 *img, *clut;
    u32 psm, cpsm, div, cnt;
    s32 w, h;
    if (tim[0] != 0x324D4954) return 0;
    p = (Tim2Pic *)(tim + 4);
    psm = D_002B9D08[p->m13].m0;
    img = (u8 *)p + p->mC;
    cpsm = D_002B9D08[p->m12 & 0x7F].m0;
    div = D_002B9D08[p->m13].m8;
    clut = img + p->m8;
    w = p->m14;
    h = p->m16;
    cnt = div ? p->mE / div : 0;
    if (pImg) *pImg = img;
    if (pPsm) *pPsm = psm;
    if (pW) *pW = w;
    if (pH) *pH = h;
    if (pClut) *pClut = clut;
    if (pCpsm) *pCpsm = cpsm;
    if (pDiv) *pDiv = div;
    if (pCnt) *pCnt = cnt;
    return 1;
}

extern "C" void func_00241D38(void) {
    func_00241D68();
    D_38EFE0 = 0;
}

extern "C" void func_00241D60(void) {
}

INCLUDE_ASM("asm/nonmatchings/Unit240FD8", func_00241D68);

extern "C" void func_00241E60(f32 a, f32 b) {
    D_38EF88 = a;
    D_38EF8C = b;
}

INCLUDE_ASM("asm/nonmatchings/Unit240FD8", func_00241E78);

extern "C" void func_00241FA8(s32 v) {
    D_38EF98 = v;
}

extern "C" void func_00241FB8(f32 v) {
    D_38EF9C = v;
}

extern "C" void func_00241FC8(f32 a, f32 b) {
    D_38EFA0 = a;
    D_38EFA4 = b;
    D_38EFA8 = 0.0f;
    D_38EFAC = 0.0f;
}

extern "C" void func_00241FF0(f32 a, f32 b) {
    D_38EFA8 = a;
    D_38EFAC = b;
}

extern "C" f32 func_00242008(void) {
    return D_38EFA8;
}

extern "C" f32 func_00242018(void) {
    return D_38EFAC;
}

extern "C" void func_00242028(f32 a, f32 b) {
    D_38EFB0 = a;
    D_38EFB4 = b;
}

extern "C" void func_00242040(f32 a, f32 b) {
    D_38EFB8 = a;
    D_38EFBC = b;
}

extern "C" void func_00242058(f32 v) {
    D_38EFC0 = v;
}

extern "C" void func_00242068(f32 v) {
    D_38EFC4 = v;
}

extern "C" void func_00242078(f32 v) {
    D_38EFC8 = v;
}

extern "C" void func_00242088(f32 v) {
    D_38EFCC = v;
}

extern "C" void func_00242098(s32 a, s32 b, s32 c, s32 d) {
    if (D_38EFD0[0] != a || D_38EFD0[1] != b || D_38EFD0[2] != c || D_38EFD0[3] != d) {
        s32 *s = D_38EFD0;
        s[0] = a;
        s[1] = b;
        s[2] = c;
        s[3] = d;
        if (D_38EFE0) {
            u64 *p = D_38EF84;
            *p = 0x1000000000000001ULL;
            p++;
            D_38EF84 = p;
            p[0] = 0xE;
            D_38EF84 = p + 1;
            p[1] = (u64)s[0] | ((u64)s[1] << 8) | ((u64)s[2] << 16) | ((u64)s[3] << 24);
            D_38EF84 = p + 2;
            p[2] = 1;
            D_38EF84 = p + 3;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit240FD8", func_00242170);

extern "C" void *func_00242340(void) {
    u64 *p = D_38EF84;
    s32 n;
    D_38EFE0 = 0;
    *p = 0x8000;
    p++;
    D_38EF84 = p;
    p[0] = 0;
    D_38EF84 = p + 1;
    D_002B94E4 = (u8 *)(p + 1);
    func_00237460();
    PUT32(0);
    PUT32(0);
    PUT32(0x11000000);
    n = func_00237450();
    {
        u32 v = ((n + 15) / 16 - 1) | 0x50000000;
        PUT32(v);
    }
    func_002374B0();
    return func_002377D8();
}

extern "C" void func_00242408(u64 a, u64 b) {
    u64 *p = D_38EF84;
    *p = 0x1000000000000001ULL;
    p++;
    D_38EF84 = p;
    p[0] = 0xE;
    D_38EF84 = p + 1;
    p[1] = b;
    D_38EF84 = p + 2;
    p[2] = a;
    D_38EF84 = p + 3;
    D_38EFE4 = 1;
}

INCLUDE_ASM("asm/nonmatchings/Unit240FD8", func_00242468);

INCLUDE_ASM("asm/nonmatchings/Unit240FD8", func_00242918);

INCLUDE_ASM("asm/nonmatchings/Unit240FD8", func_00243080);

INCLUDE_ASM("asm/nonmatchings/Unit240FD8", func_002432C8);

INCLUDE_ASM("asm/nonmatchings/Unit240FD8", func_00243338);
