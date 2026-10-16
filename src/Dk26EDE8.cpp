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

typedef struct { W2GifTag giftag0; u64 bitbltbuf, bitbltbufaddr, trxpos, trxposaddr, trxreg, trxregaddr, trxdir, trxdiraddr; W2GifTag giftag1; } Y1GsLoadImage;
#define Y1BITBLTBUF(sbp, sbw, spsm, dbp, dbw, dpsm) ((u64)(sbp) | ((u64)(sbw) << 16) | ((u64)(spsm) << 24) | ((u64)(dbp) << 32) | ((u64)(dbw) << 48) | ((u64)(dpsm) << 56))
#define Y1TRXPOS(ssax, ssay, dsax, dsay, dir) ((u64)(ssax) | ((u64)(ssay) << 16) | ((u64)(dsax) << 32) | ((u64)(dsay) << 48) | ((u64)(dir) << 59))
#define Y1TRXREG(rrw, rrh) ((u64)(rrw) | ((u64)(rrh) << 32))
// @decl-end

// Sony libgraph, the object whose .rodata starts at the 16-aligned 0x2E9A00 (sceGsSetDefLoadImage's jump table
// makes it 16-aligned): split off Dk26CFB0 by lane lb. The text cut (sceGsSetDefDrawEnv) is a guess: the
// functions from sceGsPutDispEnv on have no literals.

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

int func_0026F0D8(Y1GsLoadImage *lp, short dbp, short dbw, short dpsm, short x, short y, short w, short h)
{
    int qwc = 0;
    switch (dpsm) {
    case 0: case 0x30: qwc = (w * h) >> 2; break;
    case 1: case 0x31: qwc = (w * h * 3) >> 4; break;
    case 2: case 0xA: case 0x32: case 0x3A: qwc = (w * h) >> 3; break;
    case 0x13: case 0x1B: qwc = (w * h) >> 4; break;
    case 0x14: case 0x24: case 0x2C: qwc = (w * h) >> 5; break;
    default: break;
    }
    if (qwc > 0x7FFF) {
        func_00274F10("sceGsSetDefLoadImage: too big size\r\n");
        return 0;
    }
    *(u128 *)&lp->giftag0 = 0;
    lp->giftag0.NLOOP = 4;
    lp->giftag0.NREG = 1;
    lp->giftag0.REGS0 = 0xE;
    lp->bitbltbuf = Y1BITBLTBUF(0, 0, 0, dbp, dbw, dpsm);
    lp->bitbltbufaddr = 0x50;
    lp->trxpos = Y1TRXPOS(0, 0, x, y, 0);
    lp->trxposaddr = 0x51;
    lp->trxreg = Y1TRXREG(w, h);
    lp->trxregaddr = 0x52;
    lp->trxdir = 0;
    lp->trxdiraddr = 0x53;
    *(u128 *)&lp->giftag1 = 0;
    lp->giftag1.NLOOP = qwc;
    lp->giftag1.EOP = 1;
    lp->giftag1.FLG = 2;
    asm volatile("sync");
    return 6;
}
INCLUDE_RODATA("asm/nonmatchings/Dk26EDE8", D_002E9B20);

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

INCLUDE_ASM("asm/nonmatchings/Dk26EDE8", func_0026F580);
