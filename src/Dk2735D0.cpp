#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define SYSCALL(name, n) void name(void) { asm volatile("addiu $3,$0," #n "\n\tsyscall"); }

extern u32 D_002BDA90;
int *func_00289230();
void func_0027C3C8(s32);
s32 func_00272F40(s32);
s32 func_00272F50(s32);
s32 func_00272F60(s32);
s32 func_00272F70(s32);
s32 func_002731D0(s32);
typedef struct Stat { u8 pad0[4]; s32 m4; u8 pad8[0x40]; u64 m48; } Stat;
typedef struct Q { s32 m0; s32 m4; void *m8; void *mC; u8 m10[0x10]; } Q;
extern Q D_41CC80;
typedef struct R { s32 pad[4]; s32 m10; s32 m14; s32 m18; s32 *m1C; } R;
extern s32 D_41D340[];
typedef struct G { s32 m0, m4, m8, mC, m10, m14, m18; } G;
extern G D_41D198;
// @decl-end

SYSCALL(func_002735D0, 0x7C)

SYSCALL(func_002735E0, 0x7D)

SYSCALL(func_002735F0, 0x7E)

SYSCALL(func_00273600, 0x7F)

SYSCALL(func_00273610, 0x82)

void func_00273620(void) { D_002BDA90 = 0; }

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00273630);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_002736C0);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00273768);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_002737E8);

s32 func_00273860(void) { *func_00289230() = 5; return -1; }

s32 func_00273888(void) { return -1; }

s32 func_00273890(void) { return -1; }

s32 func_00273898(void) { return -1; }

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_002738A0);

s32 func_00273950(void) { return 1; }

s32 func_00273958(s32 fd, Stat *st) { st->m48 = 0; st->m4 = 0x2000; return 0; }

s32 func_00273970(void) { return 1; }

s32 func_00273978(s32 a, s32 b) { if (a == 1) func_0027C3C8(b); return 0; }

s32 func_002739A0(void) { *func_00289230() = 5; return -1; }

s32 func_002739C8(void) { *func_00289230() = 5; return -1; }

u32 func_002739F0(void) { u32 r; asm volatile("mfc0 %0, $12" : "=r"(r)); return (r ^ 1) & 1; }

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00273A00);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00273A68);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00273AD0);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00273B38);

s32 func_00273BA0(s32 n) { s32 r = func_00272F40(n); asm volatile("sync"); return r; }

s32 func_00273BC0(s32 n) { s32 r = func_00272F50(n); asm volatile("sync"); return r; }

s32 func_00273BE0(s32 n) { s32 r = func_00272F60(n); asm volatile("sync"); return r; }

s32 func_00273C00(s32 n) { s32 r = func_00272F70(n); asm volatile("sync"); return r; }

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00273C20);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00273DD0);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00273E68);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00273EE8);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00273F80);

s32 func_00274048(s32 a, s32 b, s32 c, s32 d) { func_002731D0(d); asm volatile("sync"); asm volatile("ei"); return 0; }

Q *func_00274070(s32 a) { D_41CC80.m0 = a; D_41CC80.m4 = 0; D_41CC80.mC = D_41CC80.m10; D_41CC80.m8 = D_41CC80.m10; return &D_41CC80; }

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00274098);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_002740D8);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00274118);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_002742B0);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00274428);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_002744F8);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_002745B8);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_002745F8);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_002746A8);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_002746E0);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00274778);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_002748E0);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00274ED8);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00274F10);

void func_00274F70(R *a, R *b) { b->m1C[a->m10] = a->m14; }

void func_00274F90(R *a, s32 *b) { b[2] = a->m10; }

s32 func_00274FA0(s32 n) { return D_41D340[n]; }

s32 func_00274FB8(s32 n, s32 v) { D_41D340[n] = v; return v; }

G *func_00274FD8(void) { return &D_41D198; }

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00274FE8);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00275268);

s32 func_002752A0(s32 a, s32 b) { s32 old = D_41D198.m14; D_41D198.m14 = a; D_41D198.m18 = b; return old; }
