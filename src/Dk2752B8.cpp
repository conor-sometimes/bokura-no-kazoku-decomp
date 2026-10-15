#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern u32 D_002BDAA8;
extern s32 D_002BDB3C;
typedef struct G { s32 m0, m4, m8, mC, m10, m14, m18; } G;
extern G D_41D198;
void func_00275268();
void func_00276CE8();
s32 func_002731E0(s32);
s32 func_002731C0(s32);
typedef struct E { u8 b[64]; } E;
typedef struct P { s32 m0, m4, m8, mC; u32 m10; E *m14; s32 m18; s32 m1C, m20; s32 m24; } P;
// @decl-end

s32 func_002752B8(s32 a, s32 b) { s32 old = D_41D198.mC; D_41D198.mC = a; D_41D198.m10 = b; return old; }

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_002752D0);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275348);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275398);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_002754D0);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275510);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275550);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275698);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275744);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275748);

void func_002758E8(void) { func_00275268(); D_002BDAA8 = 0; }

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275910);

void func_002759B8(P *p) { p->m18 = 0; p->m10 &= ~1; }

E *func_002759D8(P *p) { s32 i = p->m24 % p->m18; E *e = &p->m14[i]; p->m24 = i + 1; return e; }

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275A08);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275A48);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275B18);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275B58);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275C28);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275D80);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275DD0);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275E10);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275EE0);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276020);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_002760B0);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_002762A8);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_002762E8);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276380);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276450);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_002764E8);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276578);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_002765D0);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276798);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_002767D8);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276838);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_002768C0);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276930);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276CE8);

s32 func_00276D38(void) { func_00276CE8(); func_002731E0(D_002BDB3C); return 0; }

void func_00276D68(void) { func_002731C0(D_002BDB3C); }

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276D78);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276E20);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276E68);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00277070);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00277100);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00277138);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_002773C0);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00277540);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00277778);
