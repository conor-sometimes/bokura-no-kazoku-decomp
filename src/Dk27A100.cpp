#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define SYSCALL(name, n) int name()  { asm volatile("addiu $3,$0," #n "\n\tsyscall"); }
typedef struct SemaParam { int count, max_count, init_count, wait_threads; unsigned int attr, option; } SemaParam;
extern int D_002BDB4C;
extern int D_002BDB50;
extern char *D_002BDB54;
extern char D_002BDA8C[];
extern char D_420440[];
extern int D_420480[];
extern int D_4204C0[];
extern char D_420800[];
extern char D_420828[];
extern int D_420600[];
extern char D_420608[];
typedef struct McBuf { int r; int pad; char name[0xFC]; } McBuf;
extern McBuf D_420600x asm("D_420600");
extern const char D_002EA058[];
extern int D_002BDE88;
extern int D_002BDE90[];
extern char D_0027BC00[];
extern int D_002BE1C0;
extern int D_002BE1C4;
extern int *D_002BE1A8;
extern int func_002760B0(void *, int, int, void *, int, void *, int, void *, void *);
extern int strncmp(const char *, const char *, unsigned int);
extern void *memset(void *, int, unsigned int);
extern char *func_0028B728(char *, const char *, unsigned int);
extern int func_0027A440(void);
extern int func_0027A540(void);
extern int func_0027A608(int, int, int, int);
extern int func_0027AC18(int, int, int, int, int);
extern int func_0027AE80(const char *, const char *, int *, int);
extern unsigned int func_002735B0(int);
extern int func_00273600(void);
extern int func_00273610(void);
extern void func_00273620(void);
extern void func_0027DE90(int, int);
extern void func_00272E50(int, void *);
extern void func_00272E60(int, void *);
extern void func_0027B9C0(void);
extern int func_0027B6B8();
extern int func_0027B798(void);
extern int func_002731A0(SemaParam *);
extern int func_0027BDE8();
extern void func_0027BD90(void);
extern void func_0027BEB8(void);
extern void func_0027C4A8(void);
extern void func_0027C620(int);
extern void func_0027C860(void);
extern void func_00273CF8(void);
extern void func_0027C0F0(void);
extern void func_0027B5D0(void);
extern void func_0027DCD8(void);
typedef struct SifHdr { unsigned int psize:8; unsigned int dsize:24; void *dest; int cid; unsigned int opt; int size; char name[0x50]; } __attribute__((aligned(16))) SifHdr;
extern SifHdr D_420840;
typedef struct SifDma { void *src; void *dest; int size; int attr; } SifDma;
extern int func_00273470(void);
extern int func_002735A0(unsigned int, unsigned int);
extern int func_00273560(SifDma *, int);
extern void func_00275698(void *, int);
extern int func_00275748(int);
extern void func_002758E8(void);
extern void func_00274F10(const char *, ...);
extern const char D_002EA060[];
extern const char D_002EA070[];
extern int func_0027B1A0(const char *, int);
extern int func_0027B5B0();
extern int func_0027B5C0();
extern int func_0027B568();
extern void func_00273420(int);
typedef struct Pair { int a, b; } Pair;
extern Pair D_002BDED8[8];
extern char D_002BDB58[];
extern int D_002BDED0;
extern int func_0027BE70();
extern int func_0027BFB8();
extern int D_002BE1B0[4];
extern unsigned int *func_0027BE30(unsigned int *, unsigned int *, unsigned int);
extern int func_0027BDF8(unsigned int *, unsigned int *, unsigned int);
extern unsigned int D_002BE1A8x asm("D_002BE1A8");
typedef struct NameBuf { int b; char name[0xFC]; } NameBuf;
extern NameBuf D_420500;
typedef struct Cd { int a[9]; int serve; } Cd;
extern Cd D_420800x asm("D_420800");
extern void *memcpy(void *, const void *, unsigned int);
typedef struct McBuf2 { int r; int x4; char name[0xFC]; char name2[0xFC]; } McBuf2;
extern McBuf2 D_420600y asm("D_420600");
extern int func_00275EE0(void *, unsigned int, int);
// @decl-end

int func_0027A100(const char *name, int b)
{
    int i;
    if (D_002BDB4C < 0) return 0;
    for (i = 0; i < 0xFC; i++) {
        if ((D_420500.name[i] = name[i]) == 0) break;
    }
    if (i == 0xFC) {
        D_420500.name[0xFB] = 0;
        i = 0xFB;
    }
    D_420500.b = b;
    D_420500.name[0xFB] = 0;
    if (func_002760B0(D_420440, 3, 0, &D_420500, i + 5, D_420480, 4, 0, 0) < 0) return -1;
    return D_420480[0];
}

unsigned int func_0027A1F0(void)
{
    if (D_002BDB4C < 0) return 0;
    if (func_002760B0(D_420440, 5, 0, 0, 0, D_420480, 4, 0, 0) < 0) return 0xFFFFFFFF;
    return D_420480[0];
}

unsigned int func_0027A260(void)
{
    if (D_002BDB4C < 0) return 0;
    if (func_002760B0(D_420440, 6, 0, 0, 0, D_420480, 4, 0, 0) < 0) return 0xFFFFFFFF;
    return D_420480[0];
}

unsigned int func_0027A2D0(void)
{
    if (D_002BDB4C < 0) return 0;
    if (func_002760B0(D_420440, 7, 0, 0, 0, D_420480, 4, 0, 0) < 0) return 0xFFFFFFFF;
    return D_420480[0];
}

unsigned int func_0027A340(int a)
{
    if (D_002BDB4C < 0) return 0;
    D_4204C0[0] = a;
    if (func_002760B0(D_420440, 8, 0, D_4204C0, 4, D_420480, 4, 0, 0) < 0) return 0xFFFFFFFF;
    return D_420480[0];
}

unsigned int func_0027A3C0(int a)
{
    if (D_002BDB4C < 0) return 0;
    D_4204C0[0] = a;
    if (func_002760B0(D_420440, 9, 0, D_4204C0, 4, D_420480, 4, 0, 0) < 0) return 0xFFFFFFFF;
    return D_420480[0];
}

int func_0027A440(void)
{
    int i;
    if (D_002BDB50 < 0) {
        while (1) {
            if (func_00275EE0(&D_420800x, 0x80000006, 0) < 0) return -1;
            if (D_420800x.serve != 0) {
                D_002BDB50 = 0;
                if (func_002760B0(&D_420800x, 0xFF, 0, 0, 0, D_420600, 4, 0, 0) < 0) return 0xFFFEFFFF;
                memcpy(D_420828, D_420600, 4);
                return 0;
            }
            i = 0x100000; while (i-- != 0) ;
        }
    }
    return 0;
}

int func_0027A540(void)
{
    char *a = D_002BDA8C;
    char *b = D_420828;
    return strncmp(b, a, 4) && strncmp(b, D_002BDB54, 4) && strncmp(a, D_002BDB54, 4);
}

int func_0027A5D0(void)
{
    D_002BDB50 = -1;
    memset(D_420828, 0, 4);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk27A100", func_0027A608);

INCLUDE_ASM("asm/nonmatchings/Dk27A100", func_0027A810);

int func_0027AA18(int a)
{
    if (func_0027A440() < 0) return 0xFFFF0000;
    if (func_0027A540()) return 0xFFFEFFFC;
    D_420600[0] = a;
    if (func_002760B0(D_420800, 8, 0, D_420600, 4, D_420600, 4, 0, 0) < 0) return 0xFFFEFFFF;
    return D_420600[0];
}

int func_0027AAA8(const char *a)
{
    if (func_0027A440() < 0) return 0xFFFF0000;
    if (func_0027A540()) return 0xFFFEFFFC;
    func_0028B728(D_420600x.name, a, 0xFC);
    D_420600x.name[0xFB] = 0;
    if (func_002760B0(D_420800, 9, 0, &D_420600x, 0x200, &D_420600x, 4, 0, 0) < 0) return 0xFFFEFFFF;
    return D_420600x.r;
}

int func_0027AB48(int a)
{
    if (func_0027A440() < 0) return 0xFFFF0000;
    if (func_0027A540()) return 0xFFFEFFFC;
    D_420600[0] = a;
    if (func_002760B0(D_420800, 0xA, 0, D_420600, 4, D_420600, 4, 0, 0) < 0) return 0xFFFEFFFF;
    return D_420600[0];
}

int func_0027ABD8(int a, int b, int c)
{
    int t;
    return func_0027A608(a, b, c, (int)&t);
}

int func_0027ABF8(int a, int b, int c, int d) { return func_0027A608(a, b, c, d); }

INCLUDE_ASM("asm/nonmatchings/Dk27A100", func_0027AC18);

int func_0027AE40(int a, int b, int c)
{
    int t;
    return func_0027AC18(a, b, c, (int)&t, 0);
}

int func_0027AE60(int a, int b, int c, int d) { return func_0027AC18(a, b, c, d, 0); }

int func_0027AE80(const char *a, const char *b, int *c, int cmd)
{
    if (func_0027A440() < 0) return 0xFFFF0000;
    if (func_0027A540()) return 0xFFFEFFFC;
    func_0028B728(D_420600y.name, a, 0xFC);
    D_420600y.name[0xFB] = 0;
    func_0028B728(D_420600y.name2, b, 0xFC);
    D_420600y.name2[0xFB] = 0;
    if (func_002760B0(&D_420800x, cmd, 0, &D_420600y, 0x200, &D_420600y, 0x10, 0, 0) < 0) return 0xFFFEFFFF;
    if (D_420600y.r == 0) return 0xFFFEFFFD;
    c[0] = D_420600y.r;
    c[1] = D_420600y.x4;
    return 0;
}

int func_0027AF88(const char *a, const char *b, int *c) { return func_0027AE80(a, b, c, 1); }

int func_0027AFA8(const char *a, int *c) { return func_0027AE80(a, D_002EA058, c, 1); }

int func_0027AFD0(int a, void *out, unsigned int size) { if (func_0027A440() < 0) return 0xFFFF0000; if (size >= 3) return 0xFFFEFFFE; D_420600[0] = a; D_420600[1] = size; if (func_002760B0(D_420800, 3, 0, D_420600, 0x20, D_420600, 0x20, 0, 0) < 0) return 0xFFFEFFFF; if (size == 0) *(unsigned char *)out = *(unsigned char *)D_420600; else if (size == 1) *(unsigned short *)out = *(unsigned short *)D_420600; else if (size == 2) *(int *)out = D_420600[0]; else return 0xFFFEFFFE; return 0; }

int func_0027B0C0(int a, void *b, int n)
{
    if (func_0027A440() < 0) return 0xFFFF0000;
    D_420600[0] = a;
    D_420600[1] = n;
    if (n == 0) *(unsigned char *)&D_420600[2] = *(unsigned char *)b;
    else if (n == 1) *(unsigned short *)&D_420600[2] = *(unsigned short *)b;
    else if (n == 2) D_420600[2] = *(int *)b;
    else return 0xFFFEFFFE;
    if (func_002760B0(&D_420800x, 2, 0, D_420600, 0x20, D_420600, 0x10, 0, 0) < 0) return 0xFFFEFFFF;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk27A100", func_0027B1A0);

int func_0027B2F8(void) { unsigned int r = func_002735B0(4) & 0x10000; return r != 0; }

int func_0027B320(void)
{
    if (func_002735B0(4) & 0x40000) {
        func_00273620();
        func_0027DE90(1, 1);
        func_0027DE90(0, 1);
        return 1;
    }
    return 0;
}

int func_0027B370(const char *s)
{
    char buf[0x50];
    const char *p;
    const char *pfx = D_002EA060;
    char *d;
    for (p = s; *p; p++)
        ;
    if ((unsigned int)((p + 11) - s) > 0x50) {
        func_00274F10(D_002EA070, s);
        return 0;
    }
    func_00275748(0);
    func_002758E8();
    d = buf;
    while (*pfx) *d++ = *pfx++;
    while (*s) *d++ = *s++;
    *d = 0;
    return func_0027B1A0(buf, 0);
}

int func_0027B480(int a)
{
    D_002BDE88 = a;
    func_00272E50(1, func_0027B9C0);
    func_00272E50(2, func_0027B9C0);
    func_00272E50(3, func_0027B9C0);
    return a;
}

unsigned int func_0027B4E0(int a, int b)
{
    int old;
    if ((unsigned int)(a - 1) >= 13) return 0xFFFFFFFF;
    old = D_002BDE90[a];
    D_002BDE90[a] = b;
    if ((unsigned int)(a - 1) < 3) func_00272E50(a, D_0027BC00);
    else func_00272E60(a, D_0027BC00);
    return old;
}

SYSCALL(func_0027B568, 0x5A)

int func_0027B578(unsigned int *dst, unsigned int *src, unsigned int n)
{
    unsigned int i;
    n >>= 2;
    for (i = 0; i < n; i++) *dst++ = *src++;
    return 0;
}

SYSCALL(func_0027B5B0, 0x5B)

SYSCALL(func_0027B5C0, 0x74)

void func_0027B5D0(void) { unsigned int i; func_0027B5C0(D_002BDED8[0].a, D_002BDED8[0].b); func_0027B568(0x80075000, D_002BDB58, 0x330); func_00273420(0); func_00273420(2); func_0027B5C0(D_002BDED8[1].a, D_002BDED8[1].b); func_0027B5C0(D_002BDED8[2].a, D_002BDED8[2].b); for (i = 3; i < 8; i++) ((void (*)(int, int))func_0027B5C0)(D_002BDED8[i].a, func_0027B5B0(D_002BDED8[i].a)); D_002BDED0 = func_0027B5B0(3); }

SYSCALL(func_0027B698, 0x55)

SYSCALL(func_0027B6A8, -0x55)

SYSCALL(func_0027B6B8, 0x56)

int func_0027B6C8(int a)
{
    if ((unsigned int)(a - 13) >= 35) return -1;
    return func_0027B6B8(a);
}

SYSCALL(func_0027B6F8, -0x56)

SYSCALL(func_0027B708, 0x57)

SYSCALL(func_0027B718, -0x57)

SYSCALL(func_0027B728, 0x58)

SYSCALL(func_0027B738, -0x58)

SYSCALL(func_0027B748, 0x59)

int func_0027B758(void)
{
    if (func_00273600() == 0x2000000) return func_0027B798();
    return func_00273610();
}

INCLUDE_ASM("asm/nonmatchings/Dk27A100", func_0027B798);

INCLUDE_ASM("asm/nonmatchings/Dk27A100", func_0027B9C0);

INCLUDE_ASM("asm/nonmatchings/Dk27A100", func_0027BD20);

int func_0027BD78(void)
{
    int st;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    asm volatile("ei");
    return st != 0;
}

void func_0027BD90(void)
{
    SemaParam a, b;
    a.max_count = 1;
    a.init_count = 1;
    b.max_count = 1;
    b.init_count = 1;
    D_002BE1C0 = func_002731A0(&a);
    D_002BE1C4 = func_002731A0(&b);
}

int func_0027BDD8(void) { return D_002BE1C4; }

SYSCALL(func_0027BDE8, 0x5A)

int func_0027BDF8(unsigned int *dst, unsigned int *src, unsigned int n)
{
    unsigned int i;
    n >>= 2;
    for (i = 0; i < n; i++) *dst++ = *src++;
    return 0;
}

unsigned int *func_0027BE30(unsigned int *p, unsigned int *end, unsigned int v)
{
    while (*p != v && p < end) p++;
    if (!(p < end)) p = 0;
    return p;
}

SYSCALL(func_0027BE70, 0x83)

int func_0027BE80(int i)
{
    int v;
    func_0027BDE8(&v, D_002BE1A8 + i, 4);
    return v;
}

void func_0027BEB8(void)
{
    unsigned int a, b, pa, pb;
    func_0027BFB8(D_002BE1B0[0], D_002BE1B0[1]);
    func_0027BFB8(D_002BE1B0[2], D_002BE1B0[3]);
    a = func_0027BE70(0x80000000, 0x80080000, func_0027BE30);
    b = func_0027BE70(0x80000000, 0x80080000, func_0027BDF8);
    pa = a - 0x20C;
    pb = b - 0x168;
    while (pa != pb) {
        if (pa < pb) {
            a = func_0027BE70(a + 4, 0x80080000, func_0027BE30);
            pa = a - 0x20C;
        } else {
            b = func_0027BE70(b + 4, 0x80080000, func_0027BDF8);
            pb = b - 0x168;
        }
    }
    D_002BE1A8x = pa;
}

SYSCALL(func_0027BFB8, 0x74)

void func_0027BFC8(void)
{
    func_0027BD90();
    func_0027BEB8();
    func_0027C4A8();
    func_0027C620(2);
    func_0027C860();
    func_00273CF8();
    func_0027C0F0();
    func_0027B5D0();
    func_0027DCD8();
}
