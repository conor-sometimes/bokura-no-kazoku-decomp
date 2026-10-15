#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define HWREG(a) (*(volatile u32 *)(a))
typedef struct BitStr { u64 m0; u32 m8; u8 *mC; u32 m10; u32 pad14; u64 m18; u8 *m20; u8 *m24; u32 m28; } BitStr;
extern u8 D_002BD9C0[];
extern u32 D_002BDA10[];
int func_00289230();
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_0026FC10);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_0026FCD8);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_0026FD48);

u32 func_0026FDD0(u32 a) { if ((a >> 28) == 7) { a &= 0x0FFFFFFF; a |= 0x80000000; } return a; }

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_0026FDF8);

u32 func_0026FE30(u32 n) { if (n < 10) return D_002BDA10[n]; return 0; }

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_0026FE58);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_0026FF38);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270110);

u32 func_00270148(u32 a) { u32 old = HWREG(0x1000E060); HWREG(0x1000E060) = a; return old; }

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270160);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_002701C8);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270240);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_002702B8);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270300);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270380);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270400);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270438);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270470);

u32 func_00270508(volatile u32 *p, u32 v) { u32 old = *p; *p = v; return (old >> 8) & 1; }

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270520);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_002705A0);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270630);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_002706A0);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270710);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270790);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270818);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_002708C8);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270938);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_002709A8);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270A30);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270A98);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270B00);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270B68);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270BD0);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", Func270C50__FP5CVec4PC5CVec4);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", Func270CA0__FP5CVec4Pv);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270D08);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270D58);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270DA8);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270DF8);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", Func270E48__FP5CVec4);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270EA0);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00270F18);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00271008);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00271100);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_002711F8);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00271248);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_002712D0);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00271380);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00271440);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_002714A8);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_002715B0);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00271740);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00271808);

void func_002718B0(f32 *d, f32 *s) { d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_002718D0);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", Func271960__FP5CVec4PC5CVec4f);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_002719C8);

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_00271A48);
