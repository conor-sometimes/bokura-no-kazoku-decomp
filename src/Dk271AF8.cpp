#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define SYSCALL(name, n) void name(void) { asm volatile("addiu $3,$0," #n "\n\tsyscall"); }

#define HWREG(a) (*(volatile u32 *)(a))
#define CFC2(r, vi) asm volatile("cfc2 %0, $" #vi : "=r"(r))
#define CTC2(r, vi) asm volatile("ctc2 %0, $" #vi : : "r"(r))
void func_00272170(void *, s32);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00271AF8);

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00271BE8);

s32 func_00271C68(void) { u32 r; CFC2(r, vi29); return (r & 0xF) == 1; }

void func_00271C80(void) { u32 r; CFC2(r, vi28); r |= 2; CTC2(r, vi28); }

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00271C98);

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00271CF8);

void func_00271D48(s32 a) { u32 r; CFC2(r, vi28); if (a == 1) r |= 4; else r &= ~4; CTC2(r, vi28); }

void func_00271D78(s32 a) { u32 r; CFC2(r, vi28); if (a == 1) r |= 8; else r &= ~8; CTC2(r, vi28); }

u32 func_00271DA8(void) { u32 r; CFC2(r, vi28); return (r >> 2) & 1; }

u32 func_00271DB8(void) { u32 r; CFC2(r, vi28); return (r >> 3) & 1; }

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00271DC8);

void func_00271E08(u32 a) { a &= 0xFFFF; asm volatile("ctc2 %0, $vi27" : : "r"(a)); asm volatile("vcallmsr $vi27"); }

u32 func_00271E18(void) { u32 r; CFC2(r, vi26); return r & 0xFFFF; }

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00271E28);

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00271F98);

s32 func_00272100(void) { u32 r; CFC2(r, vi29); if ((r & 0xF) == 1) return 1; else if ((r & 0xF00) == 0x100) return 1; return 0; }

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00272130);

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00272170);

void func_002721B8(void) { u32 r; CFC2(r, vi28); r |= 0x200; CTC2(r, vi28); }

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_002721D0);

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00272230);

void func_00272280(s32 a) { u32 r; CFC2(r, vi28); if (a == 1) r |= 0x400; else r &= ~0x400; CTC2(r, vi28); }

void func_002722B0(s32 a) { u32 r; CFC2(r, vi28); if (a == 1) r |= 0x800; else r &= ~0x800; CTC2(r, vi28); }

u32 func_002722E0(void) { u32 r; CFC2(r, vi28); return (r >> 10) & 1; }

u32 func_002722F0(void) { u32 r; CFC2(r, vi28); return (r >> 11) & 1; }

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00272300);

void func_00272348(u32 a) { a &= 0xFFFF; CTC2(a, vi31); }

u16 func_00272358(void) { u16 buf[8]; func_00272170(buf, 0x43A); return buf[0]; }

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00272380);

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00272510);

void func_00272658(void) { HWREG(0x10003810) = 1; HWREG(0x10003820) = 6; }

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00272680);

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_002726E8);

u32 func_00272728(u32 a, u32 b, u32 c) { u32 v = a | (b << 1) | (c << 2); HWREG(0x10003820) = v; return v; }

u32 func_00272748(void) { return HWREG(0x10003820); }

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00272758);

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_002727A8);

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00272928);

void func_00272988(void) { HWREG(0x10003C10) = 1; HWREG(0x10003C20) = 6; }

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_002729B0);

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00272A18);

u32 func_00272A58(u32 a, u32 b, u32 c) { u32 v = a | (b << 1) | (c << 2); HWREG(0x10003C20) = v; return v; }

u32 func_00272A78(void) { return HWREG(0x10003C20); }

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00272A88);

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00272AD8);

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00272CB0);

INCLUDE_ASM("asm/nonmatchings/Dk271AF8", func_00272D10);

SYSCALL(func_00272D80, 0x0)

SYSCALL(func_00272D90, 0x1)

SYSCALL(func_00272DA0, 0x2)

SYSCALL(func_00272DB0, 0x3)

SYSCALL(func_00272DC0, 0x4)

SYSCALL(func_00272DD0, 0x5)

SYSCALL(func_00272DE0, 0x6)

SYSCALL(func_00272DF0, 0x7)

SYSCALL(func_00272E00, 0x8)

SYSCALL(func_00272E10, 0x9)

SYSCALL(func_00272E20, 0xA)

SYSCALL(func_00272E30, 0xB)

SYSCALL(func_00272E40, 0xC)
