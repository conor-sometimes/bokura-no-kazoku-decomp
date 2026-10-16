#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
typedef int u128 __attribute__((mode(TI)));
#define SYSCALL(name, n) void name(void) { asm volatile("addiu $3,$0," #n "\n\tsyscall"); }

#define HWREG(a) (*(volatile u32 *)(a))
#define CFC2(r, vi) asm volatile("cfc2 %0, $" #vi : "=r"(r))
#define CTC2(r, vi) asm volatile("ctc2 %0, $" #vi : : "r"(r))
typedef struct { u64 lo, hi; } Q16;
typedef union { u128 q; Q16 s; u64 d[2]; u32 w[4]; u16 h[8]; } QU;
Q16 func_00272170(u16 addr);

#define HWREG(a) (*(volatile u32 *)(a))
s32 func_0027BD20(void);
s32 func_0027BD78(void);
extern u128 D_002BDA60[2];
s32 func_00271DC8(void);
u32 func_00271E18(void);
void func_00271E08(u32);
u16 func_00272358(void);
void func_00272348(u32);
s32 func_00272300(void);
s32 func_00272758(void);
s32 func_00272A88(void);
#define CFC2(r, vi) asm volatile("cfc2 %0, $" #vi : "=r"(r))

#define LOCK() s32 _e = func_0027BD20()
#define UNLOCK() if (_e) func_0027BD78()
int func_00271C68(void);
typedef struct { u128 vf[32]; u32 vi16, vi17, vi18, vi20, vi21, vi22; u16 vi[16]; } VuCtx;
#define CF(r, n) asm volatile("cfc2.ni %0, $vi" #n : "=r"(r))
#define CT(r, n) asm volatile("ctc2.ni %0, $vi" #n : : "r"(r))

typedef struct { u128 vf[32]; u32 r[7]; u16 h[16]; } VuCtx1;
int func_00272100(void);
void func_00272130(u16 addr, Q16 *v);
// @decl-end

int func_00271AF8(float *a0, float *a1, float *a2, float *a3, int a4)
{
    register int r asm("$3");
    int ret;
    LOCK();
    asm volatile(
    ".set noreorder\n"
    "lqc2 vf8, 0x0(%4)\n"
    "lqc2 vf4, 0x0(%3)\n"
    "lqc2 vf5, 0x10(%3)\n"
    "lqc2 vf6, 0x20(%3)\n"
    "lqc2 vf7, 0x30(%3)\n"
    "lqc2 vf9, 0x0(%1)\n"
    "lqc2 vf10, 0x0(%2)\n"
    "lqc2 vf11, 0x0(%1)\n"
    "lqc2 vf12, 0x0(%2)\n"
    ".Lx00271B50:\n"
    "vmulax.xyzw ACC, vf4, vf8\n"
    "vmadday.xyzw ACC, vf5, vf8\n"
    "vmaddaz.xyzw ACC, vf6, vf8\n"
    "vmaddw.xyzw vf8, vf7, vf8\n"
    "vmulw.xyz vf11, vf9, vf8\n"
    "vmulw.xyz vf12, vf10, vf8\n"
    "vnop\n"
    "vnop\n"
    "ctc2.ni $0, $vi16\n"
    "vsub.xyw vf11, vf8, vf11\n"
    "vsub.xyw vf12, vf12, vf8\n"
    "vmove.w vf11, vf9\n"
    "vmove.w vf12, vf10\n"
    "vnop\n"
    "addi %4, %4, 0x10\n"
    "lqc2 vf8, 0x0(%4)\n"
    "addi %5, %5, -0x1\n"
    "cfc2.ni $3, $vi16\n"
    "andi $3, $3, 0xC0\n"
    "beqz $3, .Lx00271BB0\n"
    "nop\n"
    "bne $0, %5, .Lx00271B50\n"
    "nop\n"
    "addi $3, $0, 0x1\n"
    ".Lx00271BB0:\n"
    ".set reorder\n"
    : "=&r"(r) : "r"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(a4));
    ret = r;
    UNLOCK();
    return ret;
}

void func_00271BE8(void)
{
    int s = func_0027BD20();
    HWREG(0x10003830) = 0;
    HWREG(0x10003820) = 0;
    HWREG(0x10003810) = 1;
    asm volatile("cfc2.ni $8, $vi28\n\tori $8, $8, 0x2\n\tctc2.ni $8, $vi28\n\tsync.p" : : : "$8");
    *(volatile u128 *)0x10004000 = D_002BDA60[0];
    *(volatile u128 *)0x10004000 = D_002BDA60[1];
    if (s) func_0027BD78();
}

s32 func_00271C68(void) { u32 r; CFC2(r, vi29); return (r & 0xF) == 1; }

void func_00271C80(void) { u32 r; CFC2(r, vi28); r |= 2; CTC2(r, vi28); }

int func_00271C98(void)
{
    int r = 0;
    u32 v;
    switch (func_00271DC8()) {
    case 4: CF(v, 28); v |= 1; CT(v, 28);
    case 0: case 3: r = 1; break;
    case 1: case 2: break;
    }
    return r;
}

int func_00271CF8(void)
{
    int ret = 0;
    int s = func_00271DC8();
    if (s < 4) if (s > 0) {
        ret = 1;
        func_00271E08(func_00271E18());
    }
    return ret;
}

void func_00271D48(s32 a) { u32 r; CFC2(r, vi28); if (a == 1) r |= 4; else r &= ~4; CTC2(r, vi28); }

void func_00271D78(s32 a) { u32 r; CFC2(r, vi28); if (a == 1) r |= 8; else r &= ~8; CTC2(r, vi28); }

u32 func_00271DA8(void) { u32 r; CFC2(r, vi28); return (r >> 2) & 1; }

u32 func_00271DB8(void) { u32 r; CFC2(r, vi28); return (r >> 3) & 1; }

int func_00271DC8(void)
{
    u32 r;
    CFC2(r, vi29);
    if (r & 2) return 1;
    if (r & 4) return 2;
    if (r & 8) return 3;
    if (r & 1) return 4;
    return 0;
}

void func_00271E08(u32 a) { a &= 0xFFFF; asm volatile("ctc2 %0, $vi27" : : "r"(a)); asm volatile("vcallmsr $vi27"); }

u32 func_00271E18(void) { u32 r; CFC2(r, vi26); return r & 0xFFFF; }

int func_00271E28(VuCtx *c)
{
    u32 t;
    u128 *v = c->vf;
    if (func_00271C68()) return 0;
    asm volatile(
    "sqc2 vf0, 0x0(%0)\n"
    "sqc2 vf1, 0x10(%0)\n"
    "sqc2 vf2, 0x20(%0)\n"
    "sqc2 vf3, 0x30(%0)\n"
    "sqc2 vf4, 0x40(%0)\n"
    "sqc2 vf5, 0x50(%0)\n"
    "sqc2 vf6, 0x60(%0)\n"
    "sqc2 vf7, 0x70(%0)\n"
    "sqc2 vf8, 0x80(%0)\n"
    "sqc2 vf9, 0x90(%0)\n"
    "sqc2 vf10, 0xA0(%0)\n"
    "sqc2 vf11, 0xB0(%0)\n"
    "sqc2 vf12, 0xC0(%0)\n"
    "sqc2 vf13, 0xD0(%0)\n"
    "sqc2 vf14, 0xE0(%0)\n"
    "sqc2 vf15, 0xF0(%0)\n"
    "sqc2 vf16, 0x100(%0)\n"
    "sqc2 vf17, 0x110(%0)\n"
    "sqc2 vf18, 0x120(%0)\n"
    "sqc2 vf19, 0x130(%0)\n"
    "sqc2 vf20, 0x140(%0)\n"
    "sqc2 vf21, 0x150(%0)\n"
    "sqc2 vf22, 0x160(%0)\n"
    "sqc2 vf23, 0x170(%0)\n"
    "sqc2 vf24, 0x180(%0)\n"
    "sqc2 vf25, 0x190(%0)\n"
    "sqc2 vf26, 0x1A0(%0)\n"
    "sqc2 vf27, 0x1B0(%0)\n"
    "sqc2 vf28, 0x1C0(%0)\n"
    "sqc2 vf29, 0x1D0(%0)\n"
    "sqc2 vf30, 0x1E0(%0)\n"
    "sqc2 vf31, 0x1F0(%0)\n"
    : : "r"(v));
    CF(t, 16); c->vi16 = t;
    CF(t, 17); c->vi17 = t;
    CF(t, 18); c->vi18 = t;
    CF(t, 20); c->vi20 = t;
    CF(t, 21); c->vi21 = t;
    CF(t, 22); c->vi22 = t;
    CF(t, 0); c->vi[0] = t;
    CF(t, 1); c->vi[1] = t;
    CF(t, 2); c->vi[2] = t;
    CF(t, 3); c->vi[3] = t;
    CF(t, 4); c->vi[4] = t;
    CF(t, 5); c->vi[5] = t;
    CF(t, 6); c->vi[6] = t;
    CF(t, 7); c->vi[7] = t;
    CF(t, 8); c->vi[8] = t;
    CF(t, 9); c->vi[9] = t;
    CF(t, 10); c->vi[10] = t;
    CF(t, 11); c->vi[11] = t;
    CF(t, 12); c->vi[12] = t;
    CF(t, 13); c->vi[13] = t;
    CF(t, 14); c->vi[14] = t;
    CF(t, 15); c->vi[15] = t;
    return 1;
}

int func_00271F98(VuCtx *c)
{
    u128 *v = c->vf;
    if (func_00271C68()) return 0;
    asm volatile(
    "lqc2 vf0, 0x0(%0)\n"
    "lqc2 vf1, 0x10(%0)\n"
    "lqc2 vf2, 0x20(%0)\n"
    "lqc2 vf3, 0x30(%0)\n"
    "lqc2 vf4, 0x40(%0)\n"
    "lqc2 vf5, 0x50(%0)\n"
    "lqc2 vf6, 0x60(%0)\n"
    "lqc2 vf7, 0x70(%0)\n"
    "lqc2 vf8, 0x80(%0)\n"
    "lqc2 vf9, 0x90(%0)\n"
    "lqc2 vf10, 0xA0(%0)\n"
    "lqc2 vf11, 0xB0(%0)\n"
    "lqc2 vf12, 0xC0(%0)\n"
    "lqc2 vf13, 0xD0(%0)\n"
    "lqc2 vf14, 0xE0(%0)\n"
    "lqc2 vf15, 0xF0(%0)\n"
    "lqc2 vf16, 0x100(%0)\n"
    "lqc2 vf17, 0x110(%0)\n"
    "lqc2 vf18, 0x120(%0)\n"
    "lqc2 vf19, 0x130(%0)\n"
    "lqc2 vf20, 0x140(%0)\n"
    "lqc2 vf21, 0x150(%0)\n"
    "lqc2 vf22, 0x160(%0)\n"
    "lqc2 vf23, 0x170(%0)\n"
    "lqc2 vf24, 0x180(%0)\n"
    "lqc2 vf25, 0x190(%0)\n"
    "lqc2 vf26, 0x1A0(%0)\n"
    "lqc2 vf27, 0x1B0(%0)\n"
    "lqc2 vf28, 0x1C0(%0)\n"
    "lqc2 vf29, 0x1D0(%0)\n"
    "lqc2 vf30, 0x1E0(%0)\n"
    "lqc2 vf31, 0x1F0(%0)\n"
    "lw $2, 0x200(%1)\n"
    "ctc2.ni $2, $vi16\n"
    "lw $2, 0x208(%1)\n"
    "ctc2.ni $2, $vi18\n"
    "lw $2, 0x20C(%1)\n"
    "ctc2.ni $2, $vi20\n"
    "lw $2, 0x210(%1)\n"
    "ctc2.ni $2, $vi21\n"
    "lw $2, 0x214(%1)\n"
    "ctc2.ni $2, $vi22\n"
    "lhu $2, 0x218(%1)\n"
    "ctc2.ni $2, $vi0\n"
    "lhu $2, 0x21A(%1)\n"
    "ctc2.ni $2, $vi1\n"
    "lhu $2, 0x21C(%1)\n"
    "ctc2.ni $2, $vi2\n"
    "lhu $2, 0x21E(%1)\n"
    "ctc2.ni $2, $vi3\n"
    "lhu $2, 0x220(%1)\n"
    "ctc2.ni $2, $vi4\n"
    "lhu $2, 0x222(%1)\n"
    "ctc2.ni $2, $vi5\n"
    "lhu $2, 0x224(%1)\n"
    "ctc2.ni $2, $vi6\n"
    "lhu $2, 0x226(%1)\n"
    "ctc2.ni $2, $vi7\n"
    "lhu $2, 0x228(%1)\n"
    "ctc2.ni $2, $vi8\n"
    "lhu $2, 0x22A(%1)\n"
    "ctc2.ni $2, $vi9\n"
    "lhu $2, 0x22C(%1)\n"
    "ctc2.ni $2, $vi10\n"
    "lhu $2, 0x22E(%1)\n"
    "ctc2.ni $2, $vi11\n"
    "lhu $2, 0x230(%1)\n"
    "ctc2.ni $2, $vi12\n"
    "lhu $2, 0x232(%1)\n"
    "ctc2.ni $2, $vi13\n"
    "lhu $2, 0x234(%1)\n"
    "ctc2.ni $2, $vi14\n"
    "lhu $2, 0x236(%1)\n"
    "ctc2.ni $2, $vi15\n"
    : : "r"(v), "r"(c) : "$2");
    return 1;
}

s32 func_00272100(void) { u32 r; CFC2(r, vi29); if ((r & 0xF) == 1) return 1; else if ((r & 0xF00) == 0x100) return 1; return 0; }

void func_00272130(u16 addr, Q16 *v)
{
    QU u;
    u.s = *v;
    asm volatile("cfc2.ni $5, $vi1\n\tqmfc2.ni $3, $vf1\n\tqmtc2.ni %0, $vf1\n\tctc2.ni %1, $vi1\n\tvsqi.xyzw $vf1, ($vi1++)\n\tctc2.ni $5, $vi1\n\tqmtc2.ni $3, $vf1" : : "r"(u.q), "r"(addr) : "$3", "$5");
}

Q16 func_00272170(u16 addr)
{
    QU u;
    register u128 q asm("$2");
    asm volatile("cfc2.ni $6, $vi1\n\tqmfc2.ni $3, $vf1\n\tctc2.ni %1, $vi1\n\tvlqi.xyzw $vf1, ($vi1++)\n\tqmfc2.ni %0, $vf1\n\tctc2.ni $6, $vi1\n\tqmtc2.ni $3, $vf1" : "=&r"(q) : "r"(addr) : "$3", "$6");
    u.q = q;
    return u.s;
}

void func_002721B8(void) { u32 r; CFC2(r, vi28); r |= 0x200; CTC2(r, vi28); }

int func_002721D0(void)
{
    int r = 0;
    u32 v;
    switch (func_00272300()) {
    case 4: CF(v, 28); v |= 0x100; CT(v, 28);
    case 0: case 3: r = 1; break;
    case 1: case 2: break;
    }
    return r;
}

int func_00272230(void)
{
    int ret = 0;
    int s = func_00272300();
    if (s < 4) if (s > 0) {
        ret = 1;
        func_00272348(func_00272358());
    }
    return ret;
}

void func_00272280(s32 a) { u32 r; CFC2(r, vi28); if (a == 1) r |= 0x400; else r &= ~0x400; CTC2(r, vi28); }

void func_002722B0(s32 a) { u32 r; CFC2(r, vi28); if (a == 1) r |= 0x800; else r &= ~0x800; CTC2(r, vi28); }

u32 func_002722E0(void) { u32 r; CFC2(r, vi28); return (r >> 10) & 1; }

u32 func_002722F0(void) { u32 r; CFC2(r, vi28); return (r >> 11) & 1; }

int func_00272300(void)
{
    u32 r;
    int ret;
    CFC2(r, vi29);
    if (r & 0x200) ret = 1;
    else if (r & 0x400) ret = 2;
    else if (r & 0x800) ret = 3;
    else if (r & 0x100) ret = 4;
    else ret = 0;
    return ret;
}

void func_00272348(u32 a) { a &= 0xFFFF; CTC2(a, vi31); }

u16 func_00272358(void) { Q16 r = func_00272170(0x43A); return *(u16 *)&r; }

int func_00272380(VuCtx1 *c)
{
    u32 i;
    Q16 r;
    if (func_00272100()) return 0;
    for (i = 0; i < 32; i++) {
        r = func_00272170(i + 0x400);
        c->vf[i] = *(u128 *)&r;
    }
    r = func_00272170(0x430);
    c->r[0] = *(u32 *)&r;
    c->r[1] = func_00272170(0x431).lo;
    c->r[2] = func_00272170(0x432).lo;
    c->r[3] = func_00272170(0x434).lo;
    c->r[4] = func_00272170(0x435).lo;
    c->r[5] = func_00272170(0x436).lo;
    c->r[6] = func_00272170(0x437).lo;
    for (i = 0; i < 16; i++) c->h[i] = func_00272170(i + 0x420).lo;
    return 1;
}

int func_00272510(VuCtx1 *c)
{
    QU u;
    u32 i;
    if (func_00272100()) return 0;
    for (i = 0; i < 32; i++) {
        u.q = c->vf[i];
        func_00272130(i + 0x400, &u.s);
    }
    u.q = 0;
    u.d[0] = c->r[0]; func_00272130(0x430, &u.s);
    u.d[0] = c->r[1]; func_00272130(0x431, &u.s);
    u.d[0] = c->r[2]; func_00272130(0x432, &u.s);
    u.d[0] = c->r[3]; func_00272130(0x434, &u.s);
    u.d[0] = c->r[4]; func_00272130(0x435, &u.s);
    u.d[0] = c->r[5]; func_00272130(0x436, &u.s);
    u.d[0] = c->r[6]; func_00272130(0x437, &u.s);
    for (i = 0; i < 16; i++) {
        u.d[0] = c->h[i];
        func_00272130(i + 0x420, &u.s);
    }
    return 1;
}

void func_00272658(void) { HWREG(0x10003810) = 1; HWREG(0x10003820) = 6; }

int func_00272680(int mode)
{
    int s = func_00272758();
    if (s == 0) return 0;
    if (s == 1) return 0;
    if (mode == 0) HWREG(0x10003810) = 2;
    else if (mode == 1) HWREG(0x10003810) = 4;
    return 1;
}

int func_002726E8(void)
{
    if (func_00272758() != 1) return 0;
    HWREG(0x10003810) = 8;
    return 1;
}

u32 func_00272728(u32 a, u32 b, u32 c) { u32 v = a | (b << 1) | (c << 2); HWREG(0x10003820) = v; return v; }

u32 func_00272748(void) { return HWREG(0x10003820); }

int func_00272758(void)
{
    u32 s = HWREG(0x10003800);
    if (!(s & 3)) return 0;
    if (s & 0x700) return 1;
    if (s & 0xC) return 2;
    if (s & 0x3000) return 3;
    return 4;
}

int func_002727A8(u8 *r)
{
    u32 code = HWREG(0x10003840);
    if ((u32)func_00272758() >= 2) return 0;
    *(u32 *)(r + 0x00) = HWREG(0x10003900);
    *(u32 *)(r + 0x04) = HWREG(0x10003910);
    *(u32 *)(r + 0x08) = HWREG(0x10003920);
    *(u32 *)(r + 0x0C) = HWREG(0x10003930);
    *(u32 *)(r + 0x10) = HWREG(0x10003940);
    *(u32 *)(r + 0x14) = HWREG(0x10003950);
    *(u32 *)(r + 0x18) = HWREG(0x10003960);
    *(u32 *)(r + 0x1C) = HWREG(0x10003970);
    *(u32 *)(r + 0x20) = HWREG(0x10003870);
    *(u32 *)(r + 0x24) = HWREG(0x10003880);
    *(u32 *)(r + 0x28) = HWREG(0x10003800);
    *(u16 *)(r + 0x2C) = HWREG(0x100038D0);
    *(u16 *)(r + 0x2E) = HWREG(0x10003890);
    *(u16 *)(r + 0x30) = HWREG(0x10003830);
    *(u16 *)(r + 0x32) = HWREG(0x10003860);
    r[0x34] = HWREG(0x10003820);
    r[0x35] = code;
    r[0x36] = code >> 8;
    r[0x37] = HWREG(0x10003850);
    return 1;
}

int func_00272928(u128 *p, int n)
{
    int i = 0;
    while (n--) {
        if (HWREG(0x10003800) & 0x10000000) return i;
        *(volatile u128 *)0x10004000 = *p++;
        i++;
    }
    return i;
}

void func_00272988(void) { HWREG(0x10003C10) = 1; HWREG(0x10003C20) = 6; }

int func_002729B0(int mode)
{
    int s = func_00272A88();
    if (s == 0) return 0;
    if (s == 1) return 0;
    if (mode == 0) HWREG(0x10003C10) = 2;
    else if (mode == 1) HWREG(0x10003C10) = 4;
    return 1;
}

int func_00272A18(void)
{
    if (func_00272A88() != 1) return 0;
    HWREG(0x10003C10) = 8;
    return 1;
}

u32 func_00272A58(u32 a, u32 b, u32 c) { u32 v = a | (b << 1) | (c << 2); HWREG(0x10003C20) = v; return v; }

u32 func_00272A78(void) { return HWREG(0x10003C20); }

int func_00272A88(void)
{
    u32 s = HWREG(0x10003C00);
    if (!(s & 3)) return 0;
    if (s & 0x700) return 1;
    if (s & 0xC) return 2;
    if (s & 0x3000) return 3;
    return 4;
}

int func_00272AD8(u8 *r)
{
    u32 code = HWREG(0x10003C40);
    if ((u32)func_00272A88() >= 2) return 0;
    *(u32 *)(r + 0x00) = HWREG(0x10003D00);
    *(u32 *)(r + 0x04) = HWREG(0x10003D10);
    *(u32 *)(r + 0x08) = HWREG(0x10003D20);
    *(u32 *)(r + 0x0C) = HWREG(0x10003D30);
    *(u32 *)(r + 0x10) = HWREG(0x10003D40);
    *(u32 *)(r + 0x14) = HWREG(0x10003D50);
    *(u32 *)(r + 0x18) = HWREG(0x10003D60);
    *(u32 *)(r + 0x1C) = HWREG(0x10003D70);
    *(u32 *)(r + 0x20) = HWREG(0x10003C70);
    *(u32 *)(r + 0x24) = HWREG(0x10003C80);
    *(u32 *)(r + 0x28) = HWREG(0x10003C00);
    *(u16 *)(r + 0x2C) = HWREG(0x10003CD0);
    *(u16 *)(r + 0x2E) = HWREG(0x10003C90);
    *(u16 *)(r + 0x30) = HWREG(0x10003CA0);
    *(u16 *)(r + 0x32) = HWREG(0x10003CB0);
    *(u16 *)(r + 0x34) = HWREG(0x10003CE0);
    *(u16 *)(r + 0x36) = HWREG(0x10003CC0);
    *(u16 *)(r + 0x38) = HWREG(0x10003C30);
    *(u16 *)(r + 0x3A) = HWREG(0x10003C60);
    r[0x3C] = HWREG(0x10003C20);
    r[0x3D] = code;
    r[0x3E] = code >> 8;
    r[0x3F] = HWREG(0x10003C50);
    return 1;
}

int func_00272CB0(u128 *p, int n)
{
    int i = 0;
    while (n--) {
        if (HWREG(0x10003C00) & 0x10000000) return i;
        *(volatile u128 *)0x10005000 = *p++;
        i++;
    }
    return i;
}

int func_00272D10(u128 *p, int n)
{
    int i = 0;
    while (n--) {
        if (!(HWREG(0x10003C00) & 0x1F000000)) return i;
        *p++ = *(volatile u128 *)0x10005000;
        i++;
    }
    return i;
}

/* libkernel syscall stubs: a separate object in the original link, 16-aligned (.p2align 4 would
   raise this object's alignment, so pad by hand) */
asm(".space 0x10");
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
