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

void func_0026BCE8(void *m, int cmd);
void func_00267A98(void *, int *);
typedef struct { u8 p0[0x10]; int m10; u8 p14[0xC]; u64 m20; } MT;
typedef struct { u8 p0[4]; int m4, m8, mC, m10; u8 p14[0x14]; int m28; u8 p2C[0x18]; int m44, m48, m4C, m50, m54, m58, m5C, m60; } MP;
typedef struct { u8 p0[0x98]; int m98; u8 p9C[4]; u64 mA0; u8 pA8[0x20]; int mC8; int mCC, mD0, mD4, mD8, mDC, mE0, mE4, mE8; u8 pEC[0x18C - 0xEC]; int m18C; u8 p190[0x870 - 0x190]; MT *m870; } MM;
void func_0026D720(void *m, MP *p, void *a, void *b, void *c);
int func_0026D3C8(void *m, MP *p);
void func_0026E260(void *m, MP *p);
void func_0026D468(void *m, MP *p);
int func_0026D6F8(int *p);
extern u32 D_002BD968[16];

typedef struct { u8 p0[0xF4]; int mF4; int mF8; int mFC; } MS;
int sprintf(char *, const char *, ...);
extern const char D_002E9968[];

typedef struct { u64 testa, testaaddr, prim, primaddr, rgbaq, rgbaqaddr, xyz2a, xyz2aaddr, xyz2b, xyz2baddr, testb, testbaddr; } W2GsClear;

typedef struct { unsigned long NLOOP : 15; unsigned long EOP : 1; unsigned long pad16 : 16; unsigned long id : 14; unsigned long PRE : 1; unsigned long PRIM : 11; unsigned long FLG : 2; unsigned long NREG : 4; unsigned long REGS0 : 4; unsigned long REGS1 : 4; unsigned long REGS2 : 4; unsigned long REGS3 : 4; unsigned long REGS4 : 4; unsigned long REGS5 : 4; unsigned long REGS6 : 4; unsigned long REGS7 : 4; unsigned long REGS8 : 4; unsigned long REGS9 : 4; unsigned long REGS10 : 4; unsigned long REGS11 : 4; unsigned long REGS12 : 4; unsigned long REGS13 : 4; unsigned long REGS14 : 4; unsigned long REGS15 : 4; } W2GifTag;
typedef struct { u32 vifcode[4]; W2GifTag giftag; u64 bitbltbuf, bitbltbufaddr, trxpos, trxposaddr, trxreg, trxregaddr, finish, finishaddr, trxdir, trxdiraddr; } W2GsStoreImage;

typedef struct { u32 m0; u32 m4; } W2Feed;

typedef struct { u32 vif[4]; W2GifTag giftag0; u64 r[6]; W2GifTag giftag1; } W2GsLoadImage;
extern const char D_002E9B20[];
#define W2DMAADDR(p) ((((u32)(p) & 0x70000000) == 0x70000000) ? (((u32)(p) & 0x0FFFFFFF) | 0x80000000) : ((u32)(p) & 0x0FFFFFFF))

typedef struct { s16 inter, omode, ffmode, version; s32 m8, mC; } W2GsState;
u64 func_002734E0(u64);
void func_00273A00(int);
void func_00272EA0(int, int);
void func_00272DA0(int, int, int);

typedef struct { u64 frame1, frame1addr, zbuf1, zbuf1addr, xyoffset1, xyoffset1addr, scissor1, scissor1addr, prmodecont, prmodecontaddr, colclamp, colclampaddr, dthe, dtheaddr, test1, test1addr; } W2GsDrawEnv1;
short func_0026FC10(short psm, short w, short h);
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

int func_0026D3C8(void *vm, MP *s)
{
    MS *m = vm;
    char buf[256];
    int ok;
    if (m->mF8) ok = m->mF4 >= s->m4 && m->mF8 >= s->m8;
    else ok = m->mFC >= s->mC * s->m10;
    if (!ok) {
        sprintf(buf, D_002E9968, s->m4, s->m8);
        func_002683A0(m, buf);
    }
    return ok;
}

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

void func_0026D898(void *vm, int vp, int n)
{
    MM *m = vm;
    MP *p = (MP *)vp;
    MT *t;
    func_0026D720(m, p, (u8 *)m->m870 + 0x10, (u8 *)m->m870 + 0x18, (u8 *)m->m870 + 0x20);
    t = m->m870;
    m->m98 = t->m10;
    m->mA0 = D_002BD968[(int)(t->m20 >> 5) & 0xF];
    m->mE4 = p->m5C;
    m->mE8 = p->m60;
    m->mCC = p->m44;
    m->mD0 = p->m48;
    m->mD4 = p->m4C;
    m->mD8 = p->m50;
    m->mDC = p->m54;
    m->mE0 = p->m58;
    if (func_0026D3C8(m, p) && p->m28 == 1) {
        if (m->mC8) func_0026E260(m, p);
        else func_0026D468(m, p);
        func_0026D6F8((int *)m);
    }
}

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

void func_0026DD58(void *m, void *addr, int n)
{
    int s;
    int v[5];
    while ((s32)HWREG(0x10002010) < 0)
        ;
    s = func_0027BD20();
    HWREG(0x1000B010) = (u32)addr & 0x0FFFFFFF;
    HWREG(0x1000B020) = n << 6;
    HWREG(0x1000B000) = 0x100;
    if (s) func_0027BD78();
    func_0026BCE8(m, n | 0x70000000);
    v[0] = 4;
    func_00267A98(((MM *)m)->m870, v);
    while ((HWREG(0x1000B000) >> 8) & 1)
        ;
    while ((s32)HWREG(0x10002010) < 0)
        ;
}

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026DE80);

INCLUDE_RODATA("asm/nonmatchings/Dk26CFB0", D_002E9928);
INCLUDE_RODATA("asm/nonmatchings/Dk26CFB0", D_002E9948);
INCLUDE_RODATA("asm/nonmatchings/Dk26CFB0", D_002E9968);
INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026DFC8);
INCLUDE_RODATA("asm/nonmatchings/Dk26CFB0", D_002E99B0);

int func_0026E188(int ch, W2Feed *f)
{
    *(volatile u32 *)0x1000E010 = 0x10;
    if (f->m0 == 0) {
        asm volatile("sync.l\n\tei");
        return 1;
    }
    if (f->m0 > 0xFFFF) {
        *(volatile u32 *)0x1000B410 = f->m4;
        *(volatile u32 *)0x1000B420 = 0xFFFF;
        *(volatile u32 *)0x1000B400 = 0x101;
        f->m4 = (f->m4 + 0xFFFF0) & 0x0FFFFFFF;
        f->m0 -= 0xFFFF;
    } else {
        *(volatile u32 *)0x1000B410 = f->m4;
        *(volatile u32 *)0x1000B420 = f->m0;
        *(volatile u32 *)0x1000B400 = 0x101;
        f->m0 = 0;
    }
    asm volatile("sync.l\n\tei");
    return 0;
}

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

void func_0026E6F8(short mode, short inter, short omode, short ffmode)
{
    W2GsState *g;
    switch (mode) {
    case 0:
        g = (W2GsState *)func_0026E888();
        *(volatile u64 *)0x12001000 = 0x200;
        g->inter = inter;
        g->omode = omode;
        g->version = (u16)((*(volatile u64 *)0x12001000 >> 16) & 0xFF);
        func_002734E0(0xFF00);
        g->ffmode = ffmode != 0;
        if (g->m8) {
            func_00273A00(2);
            func_00272EA0(2, g->mC);
            g->m8 = 0;
            g->mC = 0;
        }
        func_00272DA0(inter & 1, omode & 0xFF, ffmode & 1);
        break;
    case 1:
        *(volatile u64 *)0x12001000 = 0x100;
        break;
    case 5:
        g = (W2GsState *)func_0026E888();
        g->ffmode = ffmode != 0;
        g->inter = inter;
        g->omode = omode;
        g->version = (u16)((*(volatile u64 *)0x12001000 >> 16) & 0xFF);
        func_00272DA0(inter & 1, omode & 0xFF, ffmode & 1);
        break;
    }
}

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

int func_0026EDE8(W2GsDrawEnv1 *draw, short psm, short w, short h, short ztest, short zpsm)
{
    draw->frame1addr = 0x4C;
    draw->frame1 = ((u64)(((w + 63) >> 6) & 0x3F) << 16) | ((u64)(psm & 0xF) << 24);
    draw->zbuf1addr = 0x4E;
    if (ztest == 0)
        draw->zbuf1 = (u64)(long)func_0026FC10(psm, w, h) | ((u64)(zpsm & 0xF) << 24) | ((u64)1 << 32);
    else
        draw->zbuf1 = (u64)(long)func_0026FC10(psm, w, h) | ((u64)(zpsm & 0xF) << 24);
    draw->xyoffset1addr = 0x18;
    draw->xyoffset1 = (((u64)0x800 - (short)(w >> 1)) << 4) | (((u64)0x800 - (short)(h >> 1)) << 36);
    draw->scissor1addr = 0x40;
    draw->scissor1 = ((u64)(w - 1) << 16) | ((u64)(h - 1) << 48);
    draw->prmodecontaddr = 0x1A;
    draw->prmodecont |= 1;
    draw->colclampaddr = 0x46;
    draw->colclamp |= 1;
    draw->dtheaddr = 0x45;
    if (psm & 2) draw->dthe |= 1;
    else draw->dthe &= ~(u64)1;
    draw->test1addr = 0x47;
    if (ztest) draw->test1 = ((u64)(ztest & 3) << 17) | 0x10000;
    else draw->test1 = 0x30000;
    asm volatile("sync");
    return 8;
}

int func_0026EFD0(W2GsClear *cp, short ztest, short x, short y, short w, short h, u8 r, u8 g, u8 b, u8 a, u32 z)
{
    cp->testaaddr = 0x47;
    cp->testa = ((u64)1 << 16) | ((u64)1 << 17);
    cp->prim = 6;
    cp->rgbaqaddr = 1;
    cp->rgbaq = (u64)r | ((u64)g << 8) | ((u64)b << 16) | ((u64)a << 24) | ((u64)0x3f800000 << 32);
    cp->primaddr = 0;
    cp->xyz2a = (u64)(x << 4) | ((u64)(y << 4) << 16) | ((u64)z << 32);
    cp->xyz2aaddr = 5;
    cp->xyz2baddr = 5;
    cp->xyz2b = (u64)((x + w) << 4) | ((u64)((y + h) << 4) << 16) | ((u64)z << 32);
    cp->testbaddr = 0x47;
    if (ztest) cp->testb = ((u64)1 << 16) | ((u64)(ztest & 3) << 17);
    else cp->testb = ((u64)1 << 16) | ((u64)1 << 17);
    asm volatile("sync");
    return 6;
}

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026F0D8);
INCLUDE_RODATA("asm/nonmatchings/Dk26CFB0", D_002E9B20);

int func_0026F2C0(W2GsStoreImage *sp, short sbp, short sbw, short spsm, short x, short y, short w, short h)
{
    sp->vifcode[0] = 0;
    sp->vifcode[1] = 0x06008000;
    sp->vifcode[2] = 0x13000000;
    sp->vifcode[3] = 0x50000006;
    *(u128 *)&sp->giftag = 0;
    sp->giftag.NLOOP = 5;
    sp->giftag.EOP = 1;
    sp->giftag.NREG = 1;
    sp->giftag.REGS0 = 0xE;
    sp->bitbltbuf = (u64)sbp | ((u64)sbw << 16) | ((u64)spsm << 24);
    sp->bitbltbufaddr = 0x50;
    sp->trxpos = (u64)x | ((u64)y << 16);
    sp->trxposaddr = 0x51;
    sp->trxreg = (u64)w | ((u64)h << 32);
    sp->trxregaddr = 0x52;
    sp->finish = 0;
    sp->finishaddr = 0x61;
    sp->trxdir = 1;
    sp->trxdiraddr = 0x53;
    asm volatile("sync");
    return 7;
}

int func_0026F400(W2GsLoadImage *lp, void *src)
{
    u32 i = 0;
    while (*(volatile u32 *)0x1000A000 & 0x100) {
        if (i++ > 0x1000000) {
            func_00274F10(D_002E9B20);
            return -1;
        }
    }
    *(volatile u32 *)0x1000A020 = 6;
    if (((u32)lp & 0x70000000) == 0x70000000)
        *(volatile u32 *)0x1000A010 = ((u32)lp & 0x0FFFFFFF) | 0x80000000;
    else
        *(volatile u32 *)0x1000A010 = (u32)lp & 0x0FFFFFFF;
    *(volatile u32 *)0x1000A000 = 0x101;
    while (*(volatile u32 *)0x1000A000 & 0x100) {
        if (i++ > 0x1000000) {
            func_00274F10(D_002E9B20);
            return -1;
        }
    }
    *(volatile u32 *)0x1000A020 = lp->giftag1.NLOOP;
    if (((u32)src & 0x70000000) == 0x70000000)
        *(volatile u32 *)0x1000A010 = ((u32)src & 0x0FFFFFFF) | 0x80000000;
    else
        *(volatile u32 *)0x1000A010 = (u32)src & 0x0FFFFFFF;
    *(volatile u32 *)0x1000A000 = 0x101;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026F580);
