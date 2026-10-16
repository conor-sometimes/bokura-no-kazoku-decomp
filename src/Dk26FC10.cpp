#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define HWREG(a) (*(volatile u32 *)(a))
typedef struct BitStr { u64 m0; u32 m8; u8 *mC; u32 m10; u32 pad14; u64 m18; u8 *m20; u8 *m24; u32 m28; } BitStr;
extern u8 D_002BD9C0[];
extern u32 D_002BDA10[];
int func_00289230();

s32 func_0027BD20(void);
s32 func_0027BD78(void);
#define LOCK() s32 _e = func_0027BD20()
#define UNLOCK() if (_e) func_0027BD78()
extern float D_002BDA50[4];

typedef float sceVu0FVECTOR[4] __attribute__((aligned(16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned(16)));
void func_00270F18(sceVu0FMATRIX m0, sceVu0FMATRIX m1, float rz);
void func_00271008(sceVu0FMATRIX m0, sceVu0FMATRIX m1, float rx);
void func_00271100(sceVu0FMATRIX m0, sceVu0FMATRIX m1, float ry);
void Func270E48__FP5CVec4(sceVu0FMATRIX m);
void func_00270630(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);
void func_00270710(sceVu0FVECTOR v0, sceVu0FVECTOR v1);
void func_00270BD0(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FVECTOR tv);
void func_00270818(sceVu0FMATRIX m0, sceVu0FMATRIX m1);
void func_00270B68(sceVu0FVECTOR v0, sceVu0FVECTOR v1, float s);
void func_00270790(sceVu0FMATRIX m0, sceVu0FMATRIX m1);
void Func270C50__FP5CVec4PC5CVec4(sceVu0FVECTOR v0, sceVu0FVECTOR v1);
void func_002705A0(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FMATRIX m2);
typedef struct { int w[5]; } S20;
extern S20 D_41C440;

#define HWREG(a) (*(volatile u32 *)(a))
typedef int u128 __attribute__((mode(TI)));
s32 func_0027BD20(void);
s32 func_0027BD78(void);
void func_00274F10(const char *, ...);
extern const char D_002E9D30[];
u32 func_0026FDD0(u32 a);
u32 func_00270470(volatile u32 *d);
typedef struct { volatile u32 chcr; u32 p4[3]; volatile u32 madr; u32 p14[3]; volatile u32 qwc; u32 p24[3]; volatile u32 tadr; } DmaChanV;
typedef struct { int chcr; u32 p4[3]; u32 madr; u32 p14[3]; u32 qwc; u32 p24[3]; u32 tadr; } DmaChan;
void func_0026FCD8(void *d);
void func_0026FD48(void *d, u32 addr, int t);

#define HWREG(a) (*(volatile u32 *)(a))
typedef struct { u32 chcr; u32 p4[3]; u32 madr; u32 p14[7]; u32 tadr; u32 p34[3]; u32 asr0; u32 p44[3]; u32 asr1; u32 p54[11]; u32 sadr; } DmaRegs;
extern int D_002E9D48[10];
extern DmaRegs *D_002BDA10_c[10] __asm__("D_002BDA10");
int func_0026FF38(void *);
// @decl-end

short func_0026FC10(short psm, short w, short h) { unsigned long *p = (unsigned long *)func_0026E888(); int bw = (w + 63) / 64; int bh; if (psm & 2) bh = (h + 63) / 64; else bh = (h + 31) / 32; if ((*p & 0xFFFF0000FFFFUL) == 1) return bw * bh; return bw * bh * 2; }

void func_0026FCD8(void *d) { volatile u32 *p = (volatile u32 *)d; int i = 0x1000000; while (*p & 0x100) { if (--i < 0) { func_00274F10(D_002E9D30); func_00270470(p); } } }

void func_0026FD48(void *p, u32 addr, int t)
{
    DmaChanV *d = p;
    if (!t) t = 0x1000000;
    while (d->madr < addr) {
        if (--t < 0) {
            func_00274F10(D_002E9D30);
            func_00270470(&d->chcr);
        }
    }
}

u32 func_0026FDD0(u32 a) { if ((a >> 28) == 7) { a &= 0x0FFFFFFF; a |= 0x80000000; } return a; }

void func_0026FDF8(u8 *p, int n)
{
    while (n--) *p++ = 0;
}

u32 func_0026FE30(u32 n) { if (n < 10) return D_002BDA10[n]; return 0; }

int func_0026FE58(int mode)
{
    int en = HWREG(0x1000E000) & 1;
    int i;
    char env[20];
    for (i = 0; i < 10; i++) {
        if (D_002E9D48[i]) {
            DmaRegs *c = D_002BDA10_c[i];
            c->chcr = 0;
            c->tadr = 0;
            c->madr = 0;
            c->asr1 = 0;
            c->asr0 = 0;
            c->sadr = 0;
        }
    }
    HWREG(0x1000E010) = 0xFF1F;
    HWREG(0x1000E010) = HWREG(0x1000E010) & 0xFF1F0000;
    func_0026FDF8((u8 *)env, 20);
    func_0026FF38(env);
    if (mode == 1) HWREG(0x1000E000) = HWREG(0x1000E000) | 1;
    return en;
}

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_0026FF38);

S20 *func_00270110(S20 *d) { *d = D_41C440; return d; }

u32 func_00270148(u32 a) { u32 old = HWREG(0x1000E060); HWREG(0x1000E060) = a; return old; }

void func_00270160(DmaChan *d, void *tag)
{
    u32 a = func_0026FDD0((u32)tag);
    func_0026FCD8(d);
    if (d->tadr != 0xFFFFFFFF) d->tadr = a;
    d->qwc = 0;
    d->chcr = (d->chcr & ~0xC) | 0x105;
}

void func_002701C8(DmaChan *d, void *addr, int size)
{
    u32 a = func_0026FDD0((u32)addr);
    func_0026FCD8(d);
    if (d->madr != 0xFFFFFFFF) d->madr = a;
    d->qwc = size;
    d->chcr = (d->chcr & ~0xC) | 0x101;
}

void func_00270240(DmaChan *d, void *addr, int size)
{
    u32 a = func_0026FDD0((u32)addr);
    func_0026FCD8(d);
    if (d->madr != 0xFFFFFFFF) d->madr = a;
    d->qwc = size;
    d->chcr = (d->chcr & ~0xC) | 0x109;
}

void func_002702B8(DmaChan *d)
{
    func_0026FCD8(d);
    d->qwc = 0;
    d->chcr = (((d->chcr & ~0xC) | 4) & ~1) | 0x100;
}

void func_00270300(DmaChan *d, void *addr, int size)
{
    u32 a = func_0026FDD0((u32)addr);
    func_0026FCD8(d);
    if (d->madr != 0xFFFFFFFF) d->madr = a;
    d->qwc = size;
    d->chcr &= ~0xC;
    d->chcr &= ~1;
    d->chcr |= 0x100;
}

void func_00270380(DmaChan *d, void *addr, int size)
{
    u32 a = func_0026FDD0((u32)addr);
    func_0026FCD8(d);
    if (d->madr != 0xFFFFFFFF) d->madr = a;
    d->qwc = size;
    d->chcr = (((d->chcr & ~0xC) | 8) & ~1) | 0x100;
}

int func_00270400(DmaChan *d, int mode)
{
    if (mode == 1) return ((u32)d->chcr >> 8) & 1;
    func_0026FCD8(d);
    return 0;
}

int func_00270438(DmaChan *d, u32 addr, int mode, int t)
{
    if (mode == 1) return d->madr < addr;
    func_0026FD48(d, addr, t);
    return 0;
}

u32 func_00270470(volatile u32 *d)
{
    int s = func_0027BD20();
    u32 en = HWREG(0x1000F520);
    u32 r;
    if (!(en & 0x10000)) HWREG(0x1000F590) = en | 0x10000;
    HWREG(0x1000E000);
    r = *d;
    *d = r & ~0x100;
    HWREG(0x1000F590) = en;
    if (s) func_0027BD78();
    return r;
}

u32 func_00270508(volatile u32 *p, u32 v) { u32 old = *p; *p = v; return (old >> 8) & 1; }

void func_00270520(sceVu0FVECTOR a0, sceVu0FMATRIX a1, sceVu0FVECTOR a2)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "lqc2 vf5, 0x10(%1)\n"
    "lqc2 vf6, 0x20(%1)\n"
    "lqc2 vf7, 0x30(%1)\n"
    "lqc2 vf8, 0x0(%2)\n"
    "vmulax.xyzw ACC, vf4, vf8\n"
    "vmadday.xyzw ACC, vf5, vf8\n"
    "vmaddaz.xyzw ACC, vf6, vf8\n"
    "vmaddw.xyzw vf9, vf7, vf8\n"
    "sqc2 vf9, 0x0(%0)\n"
    : : "r"(a0), "r"(a1), "r"(a2));
    UNLOCK();
}

void func_002705A0(sceVu0FMATRIX a0, sceVu0FMATRIX a1, sceVu0FMATRIX a2)
{
    LOCK();
    asm volatile(
    ".set noreorder\n"
    "lqc2 vf4, 0x0(%1)\n"
    "lqc2 vf5, 0x10(%1)\n"
    "lqc2 vf6, 0x20(%1)\n"
    "lqc2 vf7, 0x30(%1)\n"
    "addiu $7, $0, 0x4\n"
    ".Lx002705D8:\n"
    "lqc2 vf8, 0x0(%2)\n"
    "vmulax.xyzw ACC, vf4, vf8\n"
    "vmadday.xyzw ACC, vf5, vf8\n"
    "vmaddaz.xyzw ACC, vf6, vf8\n"
    "vmaddw.xyzw vf9, vf7, vf8\n"
    "sqc2 vf9, 0x0(%0)\n"
    "addi $7, $7, -0x1\n"
    "addi %2, %2, 0x10\n"
    "bne $0, $7, .Lx002705D8\n"
    "addi %0, %0, 0x10\n"
    ".set reorder\n"
    : : "r"(a0), "r"(a1), "r"(a2));
    UNLOCK();
}

void func_00270630(sceVu0FVECTOR a0, sceVu0FVECTOR a1, sceVu0FVECTOR a2)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "lqc2 vf5, 0x0(%2)\n"
    "vopmula.xyz ACC, vf4, vf5\n"
    "vopmsub.xyz vf6, vf5, vf4\n"
    "vsub.w vf6, vf6, vf6\n"
    "sqc2 vf6, 0x0(%0)\n"
    : : "r"(a0), "r"(a1), "r"(a2));
    UNLOCK();
}

float func_002706A0(float *a0, float *a1)
{
    float r;
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "lqc2 vf5, 0x0(%2)\n"
    "vmul.xyz vf5, vf4, vf5\n"
    "vaddy.x vf5, vf5, vf5\n"
    "vaddz.x vf5, vf5, vf5\n"
    "qmfc2.ni $2, vf5\n"
    "mtc1 $2, %0\n"
    : "=f"(r) : "r"(a0), "r"(a1) : "$2");
    UNLOCK();
    return r;
}

void func_00270710(sceVu0FVECTOR a0, sceVu0FVECTOR a1)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "vmul.xyz vf5, vf4, vf4\n"
    "vaddy.x vf5, vf5, vf5\n"
    "vaddz.x vf5, vf5, vf5\n"
    ".word      0x4A0503BD /* vsqrt Q, vf5x (as 2.10 encodes it differently) */\n"
    "vwaitq\n"
    "vaddq.x vf5, vf0, Q\n"
    "vnop\n"
    "vnop\n"
    "vdiv Q, vf0w, vf5x\n"
    "vsub.xyzw vf6, vf0, vf0\n"
    "vwaitq\n"
    "vmulq.xyz vf6, vf4, Q\n"
    "sqc2 vf6, 0x0(%0)\n"
    : : "r"(a0), "r"(a1));
    UNLOCK();
}

void func_00270790(sceVu0FMATRIX a0, sceVu0FMATRIX a1)
{
    LOCK();
    asm volatile(
    "lq $8, 0x0(%1)\n"
    "lq $9, 0x10(%1)\n"
    "lq $10, 0x20(%1)\n"
    "lq $11, 0x30(%1)\n"
    "pextlw $12, $9, $8\n"
    "pextuw $13, $9, $8\n"
    "pextlw $14, $11, $10\n"
    "pextuw $15, $11, $10\n"
    "pcpyld $8, $14, $12\n"
    "pcpyud $9, $12, $14\n"
    "pcpyld $10, $15, $13\n"
    "pcpyud $11, $13, $15\n"
    "sq $8, 0x0(%0)\n"
    "sq $9, 0x10(%0)\n"
    "sq $10, 0x20(%0)\n"
    "sq $11, 0x30(%0)\n"
    : : "r"(a0), "r"(a1));
    UNLOCK();
}

void func_00270818(sceVu0FMATRIX a0, sceVu0FMATRIX a1)
{
    LOCK();
    asm volatile(
    "lq $8, 0x0(%1)\n"
    "lq $9, 0x10(%1)\n"
    "lq $10, 0x20(%1)\n"
    "lqc2 vf4, 0x30(%1)\n"
    "vmove.xyzw vf5, vf4\n"
    "vsub.xyz vf4, vf4, vf4\n"
    "vmove.xyzw vf9, vf4\n"
    "qmfc2.ni $11, vf4\n"
    "pextlw $12, $9, $8\n"
    "pextuw $13, $9, $8\n"
    "pextlw $14, $11, $10\n"
    "pextuw $15, $11, $10\n"
    "pcpyld $8, $14, $12\n"
    "pcpyud $9, $12, $14\n"
    "pcpyld $10, $15, $13\n"
    "qmtc2.ni $8, vf6\n"
    "qmtc2.ni $9, vf7\n"
    "qmtc2.ni $10, vf8\n"
    "vmulax.xyz ACC, vf6, vf5\n"
    "vmadday.xyz ACC, vf7, vf5\n"
    "vmaddz.xyz vf4, vf8, vf5\n"
    "vsub.xyz vf4, vf9, vf4\n"
    "sq $8, 0x0(%0)\n"
    "sq $9, 0x10(%0)\n"
    "sq $10, 0x20(%0)\n"
    "sqc2 vf4, 0x30(%0)\n"
    : : "r"(a0), "r"(a1));
    UNLOCK();
}

void func_002708C8(sceVu0FVECTOR a0, sceVu0FVECTOR a1, float a2)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "mfc1 $8, %2\n"
    "qmtc2.ni $8, vf5\n"
    "vdiv Q, vf0w, vf5x\n"
    "vwaitq\n"
    "vmulq.xyzw vf4, vf4, Q\n"
    "sqc2 vf4, 0x0(%0)\n"
    : : "r"(a0), "r"(a1), "f"(a2));
    UNLOCK();
}

void func_00270938(sceVu0FVECTOR a0, sceVu0FVECTOR a1, float a2)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "mfc1 $8, %2\n"
    "qmtc2.ni $8, vf5\n"
    "vdiv Q, vf0w, vf5x\n"
    "vwaitq\n"
    "vmulq.xyz vf4, vf4, Q\n"
    "sqc2 vf4, 0x0(%0)\n"
    : : "r"(a0), "r"(a1), "f"(a2));
    UNLOCK();
}

void func_002709A8(sceVu0FVECTOR a0, sceVu0FVECTOR a1, sceVu0FVECTOR a2, float a3)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "lqc2 vf5, 0x0(%2)\n"
    "mfc1 $8, %3\n"
    "qmtc2.ni $8, vf6\n"
    "vaddw.x vf7, vf0, vf0\n"
    "vsub.x vf8, vf7, vf6\n"
    "vmulax.xyzw ACC, vf4, vf6\n"
    "vmaddx.xyzw vf9, vf5, vf8\n"
    "sqc2 vf9, 0x0(%0)\n"
    : : "r"(a0), "r"(a1), "r"(a2), "f"(a3));
    UNLOCK();
}

void func_00270A30(sceVu0FVECTOR a0, sceVu0FVECTOR a1, sceVu0FVECTOR a2)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "lqc2 vf5, 0x0(%2)\n"
    "vadd.xyzw vf6, vf4, vf5\n"
    "sqc2 vf6, 0x0(%0)\n"
    : : "r"(a0), "r"(a1), "r"(a2));
    UNLOCK();
}

void func_00270A98(sceVu0FVECTOR a0, sceVu0FVECTOR a1, sceVu0FVECTOR a2)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "lqc2 vf5, 0x0(%2)\n"
    "vsub.xyzw vf6, vf4, vf5\n"
    "sqc2 vf6, 0x0(%0)\n"
    : : "r"(a0), "r"(a1), "r"(a2));
    UNLOCK();
}

void func_00270B00(sceVu0FVECTOR a0, sceVu0FVECTOR a1, sceVu0FVECTOR a2)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "lqc2 vf5, 0x0(%2)\n"
    "vmul.xyzw vf6, vf4, vf5\n"
    "sqc2 vf6, 0x0(%0)\n"
    : : "r"(a0), "r"(a1), "r"(a2));
    UNLOCK();
}

void func_00270B68(sceVu0FVECTOR a0, sceVu0FVECTOR a1, float a2)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "mfc1 $8, %2\n"
    "qmtc2.ni $8, vf5\n"
    "vmulx.xyzw vf6, vf4, vf5\n"
    "sqc2 vf6, 0x0(%0)\n"
    : : "r"(a0), "r"(a1), "f"(a2));
    UNLOCK();
}

void func_00270BD0(sceVu0FMATRIX a0, sceVu0FMATRIX a1, sceVu0FVECTOR a2)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%2)\n"
    "lqc2 vf5, 0x30(%1)\n"
    "lq $7, 0x0(%1)\n"
    "lq $8, 0x10(%1)\n"
    "lq $9, 0x20(%1)\n"
    "vadd.xyz vf5, vf5, vf4\n"
    "sq $7, 0x0(%0)\n"
    "sq $8, 0x10(%0)\n"
    "sq $9, 0x20(%0)\n"
    "sqc2 vf5, 0x30(%0)\n"
    : : "r"(a0), "r"(a1), "r"(a2));
    UNLOCK();
}

void Func270C50__FP5CVec4PC5CVec4(sceVu0FVECTOR a0, sceVu0FVECTOR a1)
{
    LOCK();
    asm volatile(
    "lq $6, 0x0(%1)\n"
    "sq $6, 0x0(%0)\n"
    : : "r"(a0), "r"(a1));
    UNLOCK();
}

void Func270CA0__FP5CVec4Pv(sceVu0FMATRIX a0, sceVu0FMATRIX a1)
{
    LOCK();
    asm volatile(
    "lq $6, 0x0(%1)\n"
    "lq $7, 0x10(%1)\n"
    "lq $8, 0x20(%1)\n"
    "lq $9, 0x30(%1)\n"
    "sq $6, 0x0(%0)\n"
    "sq $7, 0x10(%0)\n"
    "sq $8, 0x20(%0)\n"
    "sq $9, 0x30(%0)\n"
    : : "r"(a0), "r"(a1));
    UNLOCK();
}

void func_00270D08(sceVu0FVECTOR a0, sceVu0FVECTOR a1)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "vftoi4.xyzw vf5, vf4\n"
    "sqc2 vf5, 0x0(%0)\n"
    : : "r"(a0), "r"(a1));
    UNLOCK();
}

void func_00270D58(sceVu0FVECTOR a0, sceVu0FVECTOR a1)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "vftoi0.xyzw vf5, vf4\n"
    "sqc2 vf5, 0x0(%0)\n"
    : : "r"(a0), "r"(a1));
    UNLOCK();
}

void func_00270DA8(sceVu0FVECTOR a0, sceVu0FVECTOR a1)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "vitof4.xyzw vf5, vf4\n"
    "sqc2 vf5, 0x0(%0)\n"
    : : "r"(a0), "r"(a1));
    UNLOCK();
}

void func_00270DF8(sceVu0FVECTOR a0, sceVu0FVECTOR a1)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "vitof0.xyzw vf5, vf4\n"
    "sqc2 vf5, 0x0(%0)\n"
    : : "r"(a0), "r"(a1));
    UNLOCK();
}

void Func270E48__FP5CVec4(sceVu0FMATRIX a0)
{
    LOCK();
    asm volatile(
    "vsub.xyzw vf4, vf0, vf0\n"
    "vadd.w vf4, vf4, vf0\n"
    "vmr32.xyzw vf5, vf4\n"
    "vmr32.xyzw vf6, vf5\n"
    "vmr32.xyzw vf7, vf6\n"
    "sqc2 vf4, 0x30(%0)\n"
    "sqc2 vf5, 0x20(%0)\n"
    "sqc2 vf6, 0x10(%0)\n"
    "sqc2 vf7, 0x0(%0)\n"
    : : "r"(a0));
    UNLOCK();
}

void func_00270EA0(void)
{
    asm volatile(
    ".set noreorder\n"
    "la $8, D_002BDA50\n"
    "lqc2 vf5, 0x0($8)\n"
    "vmr32.w vf6, vf6\n"
    "vaddx.x vf4, vf0, vf6\n"
    "vmul.x vf6, vf6, vf6\n"
    "vmulx.yzw vf4, vf4, vf0\n"
    "vmulw.xyzw vf8, vf5, vf6\n"
    "vsub.xyzw vf5, vf0, vf0\n"
    "vmulx.xyzw vf8, vf8, vf6\n"
    "vmulx.xyz vf8, vf8, vf6\n"
    "vaddw.x vf4, vf4, vf8\n"
    "vmulx.xy vf8, vf8, vf6\n"
    "vaddz.x vf4, vf4, vf8\n"
    "vmulx.x vf8, vf8, vf6\n"
    "vaddy.x vf4, vf4, vf8\n"
    "vaddx.x vf4, vf4, vf8\n"
    "vaddx.xy vf4, vf5, vf4\n"
    "vmul.x vf7, vf4, vf4\n"
    "vsubx.w vf7, vf0, vf7\n"
    ".word      0x4B8703BD /* vsqrt Q, vf7w (as 2.10 encodes it differently) */\n"
    "vwaitq\n"
    "bnez $7, .Lx00270F08\n"
    "vaddq.x vf7, vf0, Q\n"
    "b .Lx00270F0C\n"
    "vaddx.x vf4, vf5, vf7\n"
    ".Lx00270F08:\n"
    "vsubx.x vf4, vf5, vf7\n"
    ".Lx00270F0C:\n"
    ".set reorder\n");
}

void func_00270F18(sceVu0FMATRIX a0, sceVu0FMATRIX a1, float a2)
{
    LOCK();
    asm volatile(
    ".set noreorder\n"
    "mtc1 $0, $f0\n"
    "c.lt.s %2, $f0\n"
    "lui $1, 0x3fc9\n"
    "ori $1, $1, 0xfdb\n"
    "mtc1 $1, $f0\n"
    "bc1f .Lx00270F64\n"
    "nop\n"
    "add.s %2, $f0, %2\n"
    "j .Lx00270F6C\n"
    "addiu $7, $0, 0x1\n"
    ".Lx00270F64:\n"
    "sub.s %2, $f0, %2\n"
    "daddu $7, $0, $0\n"
    ".Lx00270F6C:\n"
    "mfc1 $8, %2\n"
    "qmtc2.ni $8, vf6\n"
    "daddu $6, $31, $0\n"
    "jal func_00270EA0\n"
    "nop\n"
    "daddu $31, $6, $0\n"
    "vmove.xyzw vf6, vf5\n"
    "vmove.xyzw vf7, vf5\n"
    "vmove.xyzw vf9, vf0\n"
    "vsub.xyz vf9, vf9, vf9\n"
    "vmr32.xyzw vf8, vf9\n"
    "vsub.zw vf4, vf4, vf4\n"
    "vaddx.y vf6, vf5, vf4\n"
    "vaddy.x vf6, vf5, vf4\n"
    "vsubx.x vf7, vf5, vf4\n"
    "vaddy.y vf7, vf5, vf4\n"
    "addiu $7, $0, 0x4\n"
    ".Lx00270FB0:\n"
    "lqc2 vf4, 0x0(%1)\n"
    "vmulax.xyzw ACC, vf6, vf4\n"
    "vmadday.xyzw ACC, vf7, vf4\n"
    "vmaddaz.xyzw ACC, vf8, vf4\n"
    "vmaddw.xyzw vf5, vf9, vf4\n"
    "sqc2 vf5, 0x0(%0)\n"
    "addi $7, $7, -0x1\n"
    "addi %1, %1, 0x10\n"
    "bne $0, $7, .Lx00270FB0\n"
    "addi %0, %0, 0x10\n"
    ".set reorder\n"
    : : "r"(a0), "r"(a1), "f"(a2));
    UNLOCK();
}

void func_00271008(sceVu0FMATRIX a0, sceVu0FMATRIX a1, float a2)
{
    LOCK();
    asm volatile(
    ".set noreorder\n"
    "mtc1 $0, $f0\n"
    "c.lt.s %2, $f0\n"
    "lui $1, 0x3fc9\n"
    "ori $1, $1, 0xfdb\n"
    "mtc1 $1, $f0\n"
    "bc1f .Lx00271054\n"
    "nop\n"
    "add.s %2, $f0, %2\n"
    "j .Lx0027105C\n"
    "addiu $7, $0, 0x1\n"
    ".Lx00271054:\n"
    "sub.s %2, $f0, %2\n"
    "daddu $7, $0, $0\n"
    ".Lx0027105C:\n"
    "mfc1 $8, %2\n"
    "qmtc2.ni $8, vf6\n"
    "daddu $6, $31, $0\n"
    "jal func_00270EA0\n"
    "nop\n"
    "daddu $31, $6, $0\n"
    "vmove.xyzw vf6, vf5\n"
    "vmove.xyzw vf7, vf5\n"
    "vmove.xyzw vf8, vf5\n"
    "vmove.xyzw vf9, vf5\n"
    "vaddw.x vf6, vf5, vf0\n"
    "vaddw.w vf9, vf5, vf0\n"
    "vsub.zw vf4, vf4, vf4\n"
    "vaddx.z vf7, vf5, vf4\n"
    "vaddy.y vf7, vf5, vf4\n"
    "vsubx.y vf8, vf5, vf4\n"
    "vaddy.z vf8, vf5, vf4\n"
    "addiu $7, $0, 0x4\n"
    ".Lx002710A4:\n"
    "lqc2 vf4, 0x0(%1)\n"
    "vmulax.xyzw ACC, vf6, vf4\n"
    "vmadday.xyzw ACC, vf7, vf4\n"
    "vmaddaz.xyzw ACC, vf8, vf4\n"
    "vmaddw.xyzw vf5, vf9, vf4\n"
    "sqc2 vf5, 0x0(%0)\n"
    "addi $7, $7, -0x1\n"
    "addi %1, %1, 0x10\n"
    "bne $0, $7, .Lx002710A4\n"
    "addi %0, %0, 0x10\n"
    ".set reorder\n"
    : : "r"(a0), "r"(a1), "f"(a2));
    UNLOCK();
}

void func_00271100(sceVu0FMATRIX a0, sceVu0FMATRIX a1, float a2)
{
    LOCK();
    asm volatile(
    ".set noreorder\n"
    "mtc1 $0, $f0\n"
    "c.lt.s %2, $f0\n"
    "lui $1, 0x3fc9\n"
    "ori $1, $1, 0xfdb\n"
    "mtc1 $1, $f0\n"
    "bc1f .Lx0027114C\n"
    "nop\n"
    "add.s %2, $f0, %2\n"
    "j .Lx00271154\n"
    "addiu $7, $0, 0x1\n"
    ".Lx0027114C:\n"
    "sub.s %2, $f0, %2\n"
    "daddu $7, $0, $0\n"
    ".Lx00271154:\n"
    "mfc1 $8, %2\n"
    "qmtc2.ni $8, vf6\n"
    "daddu $6, $31, $0\n"
    "jal func_00270EA0\n"
    "nop\n"
    "daddu $31, $6, $0\n"
    "vmove.xyzw vf6, vf5\n"
    "vmove.xyzw vf7, vf5\n"
    "vmove.xyzw vf8, vf5\n"
    "vmove.xyzw vf9, vf5\n"
    "vaddw.y vf7, vf5, vf0\n"
    "vaddw.w vf9, vf5, vf0\n"
    "vsub.zw vf4, vf4, vf4\n"
    "vsubx.z vf6, vf5, vf4\n"
    "vaddy.x vf6, vf5, vf4\n"
    "vaddx.x vf8, vf5, vf4\n"
    "vaddy.z vf8, vf5, vf4\n"
    "addiu $7, $0, 0x4\n"
    ".Lx0027119C:\n"
    "lqc2 vf4, 0x0(%1)\n"
    "vmulax.xyzw ACC, vf6, vf4\n"
    "vmadday.xyzw ACC, vf7, vf4\n"
    "vmaddaz.xyzw ACC, vf8, vf4\n"
    "vmaddw.xyzw vf5, vf9, vf4\n"
    "sqc2 vf5, 0x0(%0)\n"
    "addi $7, $7, -0x1\n"
    "addi %1, %1, 0x10\n"
    "bne $0, $7, .Lx0027119C\n"
    "addi %0, %0, 0x10\n"
    ".set reorder\n"
    : : "r"(a0), "r"(a1), "f"(a2));
    UNLOCK();
}

void func_002711F8(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FVECTOR rot)
{
    func_00270F18(m0, m1, rot[2]);
    func_00271100(m0, m0, rot[1]);
    func_00271008(m0, m0, rot[0]);
}

void func_00271248(sceVu0FVECTOR a0, sceVu0FVECTOR a1, float a2, float a3)
{
    LOCK();
    asm volatile(
    "mfc1 $8, %2\n"
    "mfc1 $9, %3\n"
    "lqc2 vf6, 0x0(%1)\n"
    "qmtc2.ni $8, vf4\n"
    "qmtc2.ni $9, vf5\n"
    "vmaxx.xyzw vf6, vf6, vf4\n"
    "vminix.xyzw vf6, vf6, vf5\n"
    "sqc2 vf6, 0x0(%0)\n"
    : : "r"(a0), "r"(a1), "f"(a2), "f"(a3));
    UNLOCK();
}

void func_002712D0(sceVu0FMATRIX m, sceVu0FVECTOR p, sceVu0FVECTOR zd, sceVu0FVECTOR yd)
{
    sceVu0FMATRIX m0;
    sceVu0FVECTOR xd;
    Func270E48__FP5CVec4(m0);
    func_00270630(xd, yd, zd);
    func_00270710(m0[0], xd);
    func_00270710(m0[2], zd);
    func_00270630(m0[1], m0[2], m0[0]);
    func_00270BD0(m0, m0, p);
    func_00270818(m, m0);
}

void func_00271380(sceVu0FMATRIX m, sceVu0FVECTOR l0, sceVu0FVECTOR l1, sceVu0FVECTOR l2)
{
    sceVu0FVECTOR t;
    func_00270B68(t, l0, -1.0f);
    func_00270710(m[0], t);
    func_00270B68(t, l1, -1.0f);
    func_00270710(m[1], t);
    func_00270B68(t, l2, -1.0f);
    func_00270710(m[2], t);
    m[3][0] = m[3][1] = m[3][2] = 0.0f;
    m[3][3] = 1.0f;
    func_00270790(m, m);
}

void func_00271440(sceVu0FMATRIX m, sceVu0FVECTOR c0, sceVu0FVECTOR c1, sceVu0FVECTOR c2, sceVu0FVECTOR a)
{
    Func270C50__FP5CVec4PC5CVec4(m[0], c0);
    Func270C50__FP5CVec4PC5CVec4(m[1], c1);
    Func270C50__FP5CVec4PC5CVec4(m[2], c2);
    Func270C50__FP5CVec4PC5CVec4(m[3], a);
}

void func_002714A8(sceVu0FMATRIX m, float scrz, float ax, float ay, float cx, float cy, float zmin, float zmax, float nearz, float farz)
{
    float az, cz;
    sceVu0FMATRIX mt;

    cz = (-zmax * nearz + zmin * farz) / (-nearz + farz);
    az = farz * nearz * (-zmin + zmax) / (-nearz + farz);

    Func270E48__FP5CVec4(m);
    m[0][0] = scrz;
    m[1][1] = scrz;
    m[2][2] = 0;
    m[3][2] = 1;
    m[2][3] = 1;
    m[3][3] = 0;

    Func270E48__FP5CVec4(mt);
    mt[0][0] = ax;
    mt[1][1] = ay;
    mt[2][2] = az;
    mt[3][0] = cx;
    mt[3][1] = cy;
    mt[3][2] = cz;

    func_002705A0(m, mt, m);
}

INCLUDE_ASM("asm/nonmatchings/Dk26FC10", func_002715B0);

void func_00271740(sceVu0FVECTOR a0, sceVu0FMATRIX a1, sceVu0FVECTOR a2, int a3, int a4)
{
    LOCK();
    asm volatile(
    ".set noreorder\n"
    "lqc2 vf4, 0x0(%1)\n"
    "lqc2 vf5, 0x10(%1)\n"
    "lqc2 vf6, 0x20(%1)\n"
    "lqc2 vf7, 0x30(%1)\n"
    ".Lx00271784:\n"
    "lqc2 vf8, 0x0(%2)\n"
    "vmulax.xyzw ACC, vf4, vf8\n"
    "vmadday.xyzw ACC, vf5, vf8\n"
    "vmaddaz.xyzw ACC, vf6, vf8\n"
    "vmaddw.xyzw vf9, vf7, vf8\n"
    "vdiv Q, vf0w, vf9w\n"
    "vwaitq\n"
    "vmulq.xyz vf9, vf9, Q\n"
    "beqz %4, .Lx002717B0\n"
    "vftoi4.xyzw vf10, vf9\n"
    "vftoi0.zw vf10, vf9\n"
    ".Lx002717B0:\n"
    "sqc2 vf10, 0x0(%0)\n"
    "addi %3, %3, -0x1\n"
    "addi %2, %2, 0x10\n"
    "bne $0, %3, .Lx00271784\n"
    "addi %0, %0, 0x10\n"
    ".set reorder\n"
    : : "r"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(a4));
    UNLOCK();
}

void func_00271808(sceVu0FVECTOR a0, sceVu0FMATRIX a1, sceVu0FVECTOR a2, int a3)
{
    LOCK();
    asm volatile(
    ".set noreorder\n"
    "lqc2 vf4, 0x0(%1)\n"
    "lqc2 vf5, 0x10(%1)\n"
    "lqc2 vf6, 0x20(%1)\n"
    "lqc2 vf7, 0x30(%1)\n"
    "lqc2 vf8, 0x0(%2)\n"
    "vmulax.xyzw ACC, vf4, vf8\n"
    "vmadday.xyzw ACC, vf5, vf8\n"
    "vmaddaz.xyzw ACC, vf6, vf8\n"
    "vmaddw.xyzw vf9, vf7, vf8\n"
    "vdiv Q, vf0w, vf9w\n"
    "vwaitq\n"
    "vmulq.xyz vf9, vf9, Q\n"
    "beqz %3, .Lx00271870\n"
    "vftoi4.xyzw vf10, vf9\n"
    "vftoi0.zw vf10, vf9\n"
    ".Lx00271870:\n"
    "sqc2 vf10, 0x0(%0)\n"
    ".set reorder\n"
    : : "r"(a0), "r"(a1), "r"(a2), "r"(a3));
    UNLOCK();
}

void func_002718B0(f32 *d, f32 *s) { d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }

void func_002718D0(sceVu0FVECTOR a0, sceVu0FVECTOR a1, sceVu0FVECTOR a2, float a3)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "lqc2 vf5, 0x0(%2)\n"
    "mfc1 $8, %3\n"
    "qmtc2.ni $8, vf6\n"
    "vmove.w vf9, vf4\n"
    "vaddw.x vf7, vf0, vf0\n"
    "vsub.x vf8, vf7, vf6\n"
    "vmulax.xyz ACC, vf4, vf6\n"
    "vmaddx.xyz vf9, vf5, vf8\n"
    "sqc2 vf9, 0x0(%0)\n"
    : : "r"(a0), "r"(a1), "r"(a2), "f"(a3));
    UNLOCK();
}

void Func271960__FP5CVec4PC5CVec4f(sceVu0FVECTOR a0, sceVu0FVECTOR a1, float a2)
{
    LOCK();
    asm volatile(
    "lqc2 vf4, 0x0(%1)\n"
    "mfc1 $8, %2\n"
    "qmtc2.ni $8, vf5\n"
    "vmulx.xyz vf4, vf4, vf5\n"
    "sqc2 vf4, 0x0(%0)\n"
    : : "r"(a0), "r"(a1), "f"(a2));
    UNLOCK();
}

int func_002719C8(float *a0)
{
    register int r asm("$3");
    int ret;
    LOCK();
    asm volatile(
    "vsub.xyzw vf4, vf0, vf0\n"
    "dli %0, 0x4580000045800000\n"
    "lqc2 vf7, 0x0(%1)\n"
    "qmtc2.ni %0, vf6\n"
    "ctc2.ni $0, $vi16\n"
    "vsub.xyw vf5, vf7, vf4\n"
    "vsub.xy vf5, vf6, vf7\n"
    "vnop\n"
    "vnop\n"
    "vnop\n"
    "vnop\n"
    "vnop\n"
    "cfc2.ni %0, $vi16\n"
    "andi %0, %0, 0xC0\n"
    : "=r"(r) : "r"(a0));
    ret = r;
    UNLOCK();
    return ret;
}

int func_00271A48(float *a0, float *a1, float *a2)
{
    register int r asm("$3");
    int ret;
    LOCK();
    asm volatile(
    "vsub.xyzw vf4, vf0, vf0\n"
    "dli %0, 0x4580000045800000\n"
    "lqc2 vf6, 0x0(%1)\n"
    "lqc2 vf8, 0x0(%2)\n"
    "lqc2 vf9, 0x0(%3)\n"
    "qmtc2.ni %0, vf7\n"
    "ctc2.ni $0, $vi16\n"
    "vsub.xyw vf5, vf6, vf4\n"
    "vsub.xy vf5, vf7, vf6\n"
    "vsub.xyw vf5, vf8, vf4\n"
    "vsub.xy vf5, vf7, vf8\n"
    "vsub.xyw vf5, vf9, vf4\n"
    "vsub.xy vf5, vf7, vf9\n"
    "vnop\n"
    "vnop\n"
    "vnop\n"
    "vnop\n"
    "vnop\n"
    "cfc2.ni %0, $vi16\n"
    "andi %0, %0, 0xC0\n"
    : "=r"(r) : "r"(a0), "r"(a1), "r"(a2));
    ret = r;
    UNLOCK();
    return ret;
}
