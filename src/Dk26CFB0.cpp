#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define SYSCALL(name, n) void name(void) { asm volatile("addiu $3,$0," #n "\n\tsyscall"); }

#define HWREG(a) (*(volatile u32 *)(a))
typedef struct BitStr { u64 m0; u32 m8; u8 *mC; u32 m10; u32 pad14; u64 m18; u8 *m20; u8 *m24; u32 m28; } BitStr;
extern u8 D_002BD9C0[];
extern u32 D_002BDA10[];
int func_00289230();

typedef int u128 __attribute__((mode(TI)));
s32 func_0027BD20(void);
s32 func_0027BD78(void);
void func_002683A0(void *m, const char *msg);
int func_0026AFC0(void *m);
void func_0026D898(void *m, int fb, int n);
void func_0026D9A8(void *m, int fb0, int fb1, int n);
extern const char D_002E9928[];
extern const char D_002E9948[];
extern const char D_002E99B0[];
extern u128 D_002BD9D0[2];
int func_00277138(const char *, int);
int func_00277778(int, void *, int);
int func_002773C0(int);
int atoi(const char *);
void *func_0026E888(void);
s32 func_0026E520(BitStr *s, s32 n);
void func_0026E540(BitStr *s, int n);
typedef struct { u8 p0[0x110]; int m110; u8 p114[0x24]; int m138; u8 p13C[0x2C]; int m168; u8 p16C[0x20]; int m18C; u8 p190[0x40]; int m1D0; int p1D4; int *m1D8; int m1DC; int m1E0; int p1E4; int *m1E8; int m1EC; int m1F0; int p1F4; int *m1F8; int m1FC; } Mpeg;
typedef struct { u64 pmode; u64 m8; u64 m10; u64 m18; u64 m20; } DispEnv;
#define HW64(a) (*(volatile u64 *)(a))
// @decl-end

int func_0026CFB0(Mpeg *m)
{
    int *p;
    int r;
    if (m->m18C == 3 && m->m138) {
        func_002683A0(m, D_002E9928);
        m->m138 = 0;
    }
    switch (m->m18C) {
    case 3: p = m->m1D8; break;
    case 1: p = m->m1E8; break;
    case 2: p = m->m1F8; break;
    default:
        p = m->m1D8;
        func_002683A0(m, D_002E9948);
        break;
    }
    r = func_0026AFC0(m);
    if (r) p[10] = 1;
    return r;
}

void func_0026D080(Mpeg *m, int a, int b)
{
    if (b) {
        if (m->m18C == 3) {
            int f;
            if (m->m168 == 3) f = m->m1DC; else f = m->m1D0;
            func_0026D898(m, f, a - 1);
        } else {
            int f0, f1;
            if (m->m168 == 3) { f0 = m->m1EC; f1 = m->m1FC; } else { f0 = m->m1E0; f1 = m->m1F0; }
            func_0026D9A8(m, f0, f1, a - 1);
        }
    }
    if (m->m110 == 1) m->m110 = 2;
}

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026D110);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026D3C8);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026D468);

int func_0026D6F8(int *p)
{
    int r = 1;
    if (p[2] != 2) {
        p[2] = 2;
        p[0xC4 / 4] = p[0x130 / 4];
    }
    p[0x838 / 4] = r;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026D720);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026D898);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026D9A8);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026DB60);

void func_0026DCD0(void *addr, int size)
{
    int s = func_0027BD20();
    HWREG(0x1000B010) = ((u32)addr & 0x0FFFFFFF) | 0x80000000;
    HWREG(0x1000B020) = size >> 4;
    HWREG(0x1000B000) = 0x100;
    if (s) func_0027BD78();
}

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026DD58);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026DE80);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026DFC8);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026E188);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026E260);

void func_0026E4E8(BitStr *s, u8 *p, u8 *base, int size)
{
    s->m8 = (u32)p;
    s->m0 = 0;
    s->m10 = 0;
    s->m18 = 0;
    s->m20 = base;
    s->mC = p;
    s->m24 = base + size;
    s->m28 = size;
    func_0026E540(s, 0);
}

s32 func_0026E520(BitStr *s, s32 n) { return (s32)(s->m0 >> (64 - n)); }

void func_0026E540(BitStr *s, int n)
{
    s->m0 <<= n;
    s->m10 -= n;
    while (s->m10 < 57) {
        s->m0 |= (u64)*s->mC++ << (56 - s->m10);
        if (s->mC >= s->m24) s->mC = s->m20;
        s->m10 += 8;
    }
    s->m18 += n;
}

s32 func_0026E5D8(BitStr *s, int n)
{
    s32 v = func_0026E520(s, n);
    func_0026E540(s, n);
    return v;
}

s32 func_0026E628(BitStr *s)
{
    s32 v = func_0026E520(s, 1);
    func_0026E540(s, 1);
    return v;
}

void func_0026E670(BitStr *s, int n)
{
    u8 *p;
    s->m0 = 0;
    s->m10 = 0;
    s->m18 = n * 8 + s->m18;
    p = (u8 *)s->m8 + (int)(s->m18 >> 3);
    s->mC = p;
    if (p >= s->m24) s->mC = p - s->m28;
    func_0026E540(s, 0);
}

u8 *func_0026E6C8(BitStr *s, s32 n) { u8 *p = (u8 *)s->m8 + (n >> 3); if (p >= s->m24) p -= s->m28; return p; }

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026E6F8);

void *func_0026E888(void) { return D_002BD9C0; }

void func_0026E898(void)
{
    HWREG(0x10003C10) = 1;
    HWREG(0x10003C20) = 2;
    asm volatile("sync\n\tcfc2.ni %0, $vi28\n\tori %0, %0, 0x200\n\tctc2.ni %0, $vi28\n\tsync.p" : : "r"(0));
    *(volatile u128 *)0x10005000 = D_002BD9D0[0];
    *(volatile u128 *)0x10005000 = D_002BD9D0[1];
    HWREG(0x10003000) = 1;
}

int func_0026E900(void)
{
    char buf[256];
    int fd;
    u32 i;
    char *p;
    fd = func_00277138(D_002E99B0, 1);
    if (fd < 0) return -1;
    for (i = 0, p = buf; i < 256; i++) {
        func_00277778(fd, p, 1);
        if (*p++ == 0) break;
    }
    func_002773C0(fd);
    return atoi(&buf[i - 9]) > 20010608;
}

SYSCALL(func_0026E9A0, 0x80)

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026E9B0);

void func_0026ED28(DispEnv *e)
{
    if (((s16 *)func_0026E888())[3] == 1) {
        HW64(0x12000000) = e->pmode;
        HW64(0x12000070) = e->m10;
        HW64(0x12000080) = e->m18;
        HW64(0x120000C0) = e->m20;
    } else {
        HW64(0x12000000) = e->pmode;
        HW64(0x12000020) = e->m8;
        HW64(0x12000090) = e->m10;
        HW64(0x120000A0) = e->m18;
        HW64(0x120000E0) = e->m20;
    }
}

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026EDE8);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026EFD0);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026F0D8);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026F2C0);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026F400);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026F580);
