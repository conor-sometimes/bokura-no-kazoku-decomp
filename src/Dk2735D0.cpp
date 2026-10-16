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

#define HWREG(a) (*(volatile u32 *)(a))
s32 func_0027BD20(void);
s32 func_0027BD78(void);
int func_002744F8(void *);
int func_002742B0(void *, int);
int func_00274428(void *, int);
s32 func_00272EF0(s32);
s32 func_00272EE0(s32);
s32 func_00272F10(s32);
s32 func_00272F00(s32);
s32 func_002730E0(s32);
s32 func_00273120(s32);
extern int D_002BDA98;
typedef struct { s32 m0; u32 m4; u8 e[0x200][2]; } TQ;
extern TQ D_41C868;
extern int D_41C860;
typedef struct { int size; int count; u8 *rd; u8 *wr; u8 buf[1]; } Ring;
int func_002745B8(int c);

typedef struct { int count, max_count, init_count, wait_threads; u32 attr, option; } SemaParam;
void func_00273510(volatile int *flag, u64 *out);
u32 func_00273180(void);
int *func_00289230();
extern char *D_002BDA94;
int func_0027D7E8(int, int);
int func_0027D998(int, void *, int);
s32 func_00274048(s32 a, s32 b, s32 c, s32 d);
int func_002731B0(int);
s32 func_002731E0(s32);
extern char D_002E9E00[];
int func_00273420(int);
int func_0027DF38(int, void *, void *);
s32 func_00274118();
typedef struct { int m0, m4, m8, mC; u8 *m10; u32 m14; Ring *m18; } Sio;
extern Sio D_41CD90;
extern u8 D_41CDC0[];
extern u8 D_41CF00[];
void func_002740D8(Ring *r);
extern int D_002BDA9C;
extern char D_41D040[0x80];
void func_0027E148(char *);
s32 func_00273AD0(s32 a);
int func_00272ED0(int, int);
extern int D_41D194;
extern int D_002BDAA4;

typedef char *va_list;
#define va_start(ap, last) (ap = (char *)__builtin_next_arg(last) - (__builtin_args_info(0) < 8 ? (8 - __builtin_args_info(0)) * 8 : 0))
#define va_end(ap)
int func_002748E0(const char *fmt, va_list ap);
extern void *D_002BDAA0;
void func_002745F8(int c);
typedef struct { u8 p0[0xF4]; int mF4; int mF8; int mFC; } MS;
typedef struct { u8 p0[4]; int m4, m8, mC, m10; } MI;
int sprintf(char *, const char *, ...);
extern const char D_002E9968[];
void func_002683A0(void *m, const char *msg);

int func_0027DFA8(int, char);
void func_0027DFD8(int);
#define W2SIO (*(volatile Sio *)&D_41CD90)
typedef struct { int status; void *entry; void *stack; int stackSize; void *gpReg; int initPriority; int currentPriority; u32 attr, option; int waitType, waitId, wakeupCount; } W2ThreadParam;
extern u8 D_41C460[];
extern u8 D_2F36F0[];
extern const char D_002E9DD8[];
int func_00272FA0(W2ThreadParam *);
int func_00272FC0(int, void *);
int func_00273090(void);
int func_00273030(int, int);
void func_002730D0(int);
void func_00273050(int);
void func_00273110(int);
void func_00273C20(TQ *q);
// @decl-end

SYSCALL(func_002735D0, 0x7C)

SYSCALL(func_002735E0, 0x7D)

SYSCALL(func_002735F0, 0x7E)

SYSCALL(func_00273600, 0x7F)

SYSCALL(func_00273610, 0x82)

void func_00273620(void) { D_002BDA90 = 0; }

void func_00273630(void)
{
    int s = func_0027BD20();
    HWREG(0x1000F000) = 4;
    asm volatile("sync");
    if (s) func_0027BD78();
    while (!(HWREG(0x1000F000) & 4))
        ;
    s = func_0027BD20();
    HWREG(0x1000F000) = 4;
    asm volatile("sync");
    if (s) func_0027BD78();
}

u64 func_002736C0(void)
{
    volatile int flag;
    volatile u64 r;
    volatile u32 *p;
    int s;
    flag = 0;
    func_00273510(&flag, &r);
    s = func_0027BD20();
    *(volatile u32 *)0x1000F000 = 4;
    asm volatile("sync");
    if (s) func_0027BD78();
    while (!(*(volatile u32 *)0x1000F000 & 4) && !flag)
        ;
    s = func_0027BD20();
    *(volatile u32 *)0x1000F000 = 4;
    asm volatile("sync");
    if (s) func_0027BD78();
    return r;
}

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00273768);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_002737E8);

s32 func_00273860(void) { *func_00289230() = 5; return -1; }

s32 func_00273888(void) { return -1; }

s32 func_00273890(void) { return -1; }

s32 func_00273898(void) { return -1; }

void *func_002738A0(int incr)
{
    u32 st, t;
    char *n, *r;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st) {
        do {
            asm volatile("di");
            asm volatile("sync.p");
            asm volatile("mfc0 %0, $12" : "=r"(t));
        } while (t & 0x10000);
    }
    n = D_002BDA94 + incr;
    if (func_00273180() < (u32)n) {
        *func_00289230() = 12;
        if (st) asm volatile("ei");
        return (void *)-1;
    }
    r = D_002BDA94;
    D_002BDA94 = n;
    if (st) asm volatile("ei");
    return r;
}

s32 func_00273950(void) { return 1; }

s32 func_00273958(s32 fd, Stat *st) { st->m48 = 0; st->m4 = 0x2000; return 0; }

s32 func_00273970(void) { return 1; }

s32 func_00273978(s32 a, s32 b) { if (a == 1) func_0027C3C8(b); return 0; }

s32 func_002739A0(void) { *func_00289230() = 5; return -1; }

s32 func_002739C8(void) { *func_00289230() = 5; return -1; }

u32 func_002739F0(void) { u32 r; asm volatile("mfc0 %0, $12" : "=r"(r)); return (r ^ 1) & 1; }

s32 func_00273A00(s32 a)
{
    u32 st;
    s32 r;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st) func_0027BD20();
    r = func_00272EF0(a);
    asm volatile("sync");
    if (st) func_0027BD78();
    return r;
}

s32 func_00273A68(s32 a)
{
    u32 st;
    s32 r;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st) func_0027BD20();
    r = func_00272EE0(a);
    asm volatile("sync");
    if (st) func_0027BD78();
    return r;
}

s32 func_00273AD0(s32 a)
{
    u32 st;
    s32 r;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st) func_0027BD20();
    r = func_00272F10(a);
    asm volatile("sync");
    if (st) func_0027BD78();
    return r;
}

s32 func_00273B38(s32 a)
{
    u32 st;
    s32 r;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st) func_0027BD20();
    r = func_00272F00(a);
    asm volatile("sync");
    if (st) func_0027BD78();
    return r;
}

s32 func_00273BA0(s32 n) { s32 r = func_00272F40(n); asm volatile("sync"); return r; }

s32 func_00273BC0(s32 n) { s32 r = func_00272F50(n); asm volatile("sync"); return r; }

s32 func_00273BE0(s32 n) { s32 r = func_00272F60(n); asm volatile("sync"); return r; }

s32 func_00273C00(s32 n) { s32 r = func_00272F70(n); asm volatile("sync"); return r; }

void func_00273C20(TQ *q)
{
    for (;;) {
        int i;
        func_002731E0(D_41C860);
        i = q->m0 & 0x1FF;
        q->m0 = i + 1;
        switch (q->e[i][0]) {
        case 0:
            func_002730D0(q->e[i][1]);
            break;
        case 1:
            func_00273050(q->e[i][1]);
            break;
        case 2:
            func_00273110(q->e[i][1]);
            break;
        default:
            func_00274ED8(D_002E9DD8);
            break;
        }
    }
}

int func_00273CF8(void)
{
    W2ThreadParam tp;
    SemaParam sp;
    if (D_002BDA98 > 0) return -1;
    sp.init_count = 0;
    sp.max_count = 0xFF;
    if ((D_41C860 = func_002731A0(&sp)) < 0) return -1;
    tp.entry = (void *)func_00273C20;
    tp.stack = D_41C460;
    tp.stackSize = 0x400;
    tp.gpReg = D_2F36F0;
    tp.initPriority = 0;
    if ((D_002BDA98 = func_00272FA0(&tp)) < 0) {
        func_002731B0(D_41C860);
        return -1;
    }
    D_41C868.m0 = 0;
    D_41C868.m4 = 0;
    func_00272FC0(D_002BDA98, &D_41C868);
    func_00273030(func_00273090(), 1);
    return D_002BDA98;
}

s32 func_00273DD0(s32 tid)
{
    register s32 r asm("$2");
    s32 id;
    u32 k;
    asm volatile("addiu $3, $0, -0x2F\n\tsyscall" : "=r"(r) : : "$3");
    id = r;
    if (id != tid) return func_002730E0(tid);
    if ((u32)id >= 0x100 || !D_002BDA98) return -1;
    k = D_41C868.m4 & 0x1FF;
    D_41C868.m4 = k + 1;
    D_41C868.e[k][0] = 0;
    D_41C868.e[k][1] = id;
    func_002731D0(D_41C860);
    return id;
}

s32 func_00273E68(s32 id)
{
    u32 k;
    if ((u32)id >= 0x80 || !D_002BDA98) return -1;
    k = D_41C868.m4 & 0x1FF;
    D_41C868.m4 = k + 1;
    D_41C868.e[k][0] = 1;
    D_41C868.e[k][1] = id;
    func_002731D0(D_41C860);
    return id;
}

s32 func_00273EE8(s32 tid)
{
    register s32 r asm("$2");
    s32 id;
    u32 k;
    asm volatile("addiu $3, $0, -0x2F\n\tsyscall" : "=r"(r) : : "$3");
    id = r;
    if (id != tid) return func_00273120(tid);
    if ((u32)id >= 0x100 || !D_002BDA98) return -1;
    k = D_41C868.m4 & 0x1FF;
    D_41C868.m4 = k + 1;
    D_41C868.e[k][0] = 2;
    D_41C868.e[k][1] = id;
    func_002731D0(D_41C860);
    return id;
}

int func_00273F80(int usec)
{
    u32 st;
    SemaParam p;
    int sema, id;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    if (!(st & 0x10000)) return 0x80008008;
    p.max_count = 1;
    p.option = (u32)D_002E9E00;
    p.init_count = 0;
    sema = func_002731A0(&p);
    if (sema < 0) return 0x80008003;
    id = func_0027D998(func_0027D7E8(0, usec), func_00274048, sema);
    if (id < 0) {
        func_002731B0(sema);
        return id;
    }
    func_002731E0(sema);
    func_002731B0(sema);
    return 0;
}

s32 func_00274048(s32 a, s32 b, s32 c, s32 d) { func_002731D0(d); asm volatile("sync"); asm volatile("ei"); return 0; }

Q *func_00274070(s32 a) { D_41CC80.m0 = a; D_41CC80.m4 = 0; D_41CC80.mC = D_41CC80.m10; D_41CC80.m8 = D_41CC80.m10; return &D_41CC80; }

void func_00274098(Ring *r)
{
    r->count++;
    r->wr++;
    if (r->wr == r->buf + r->size) r->wr = r->buf;
}

void func_002740D8(Ring *r)
{
    r->count--;
    r->rd++;
    if (r->rd == r->buf + r->size) r->rd = r->buf;
}

INCLUDE_RODATA("asm/nonmatchings/Dk2735D0", D_002E9DD8);
INCLUDE_RODATA("asm/nonmatchings/Dk2735D0", D_002E9E00);
INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00274118);

int func_002742B0(void *s_, int len)
{
    const char *s = (const char *)s_;
    int n = 0, i = 0, st;
    u8 *out, *p;
    if (W2SIO.mC) return -1;
    st = func_0027BD20();
    out = (u8 *)((u32)D_41CDC0 | 0x20000000);
    W2SIO.mC = 1;
    W2SIO.m10 = out;
    p = out + 0xC;
    while (--len != -1) {
        if (*s == '\n') {
            *p++ = '\r';
            if (++i >= 0x100) break;
        }
        *p++ = *s++;
        n++;
        if (++i >= 0x100) break;
    }
    W2SIO.m4 = i + 0xC;
    *(u16 *)out = W2SIO.m4;
    if (func_0027DFA8(W2SIO.m0, out[7]) < 0) {
        W2SIO.mC = 0;
        if (st) func_0027BD78();
        return -1;
    }
    while (W2SIO.mC) func_0027DFD8(W2SIO.m0);
    if (st) func_0027BD78();
    return n;
}

int func_00274428(void *vbuf, int n)
{
    char *buf = vbuf;
    int i = 0;
    while (i < n) {
        char *p = buf + i;
        int k = i + 1;
        while (((volatile Ring *)D_41CD90.m18)->count == 0)
            ;
        *p = *D_41CD90.m18->rd;
        func_002740D8(D_41CD90.m18);
        if (*p == '\n' || *p == '\r') return k;
        i = k;
    }
    return i;
}

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_002744F8);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_002745B8);

void func_002745F8(int c)
{
    if (D_002BDA9C >= 0x7E) {
        D_002BDA9C = 0;
        D_41D040[0x7F] = 0;
        func_0027E148(D_41D040);
    }
    if (c == '\n') {
        int i = D_002BDA9C;
        D_002BDA9C = 0;
        D_41D040[i] = c;
        D_41D040[i + 1] = 0;
        func_0027E148(D_41D040);
    } else {
        int i = D_002BDA9C;
        D_002BDA9C = i + 1;
        D_41D040[i] = c;
    }
}

void func_002746A8(int c)
{
    if (c == '\n') { func_002745B8('\r'); func_002745B8('\n'); }
    else func_002745B8(c);
}

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_002746E0);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00274778);
INCLUDE_RODATA("asm/nonmatchings/Dk2735D0", D_002E9E98);
INCLUDE_RODATA("asm/nonmatchings/Dk2735D0", D_002E9EA0);
INCLUDE_RODATA("asm/nonmatchings/Dk2735D0", D_002E9EA8);

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_002748E0);

int func_00274ED8(const char *fmt, ...)
{
    va_list ap;
    int r;
    va_start(ap, fmt);
    r = func_002748E0(fmt, ap);
    va_end(ap);
    return r;
}

int func_00274F10(const char *fmt, ...)
{
    va_list ap;
    int r;
    void *old = D_002BDAA0;
    D_002BDAA0 = func_002745F8;
    va_start(ap, fmt);
    r = func_002748E0(fmt, ap);
    va_end(ap);
    D_002BDAA0 = old;
    return r;
}

void func_00274F70(R *a, R *b) { b->m1C[a->m10] = a->m14; }

void func_00274F90(R *a, s32 *b) { b[2] = a->m10; }

s32 func_00274FA0(s32 n) { return D_41D340[n]; }

s32 func_00274FB8(s32 n, s32 v) { D_41D340[n] = v; return v; }

G *func_00274FD8(void) { return &D_41D198; }

INCLUDE_ASM("asm/nonmatchings/Dk2735D0", func_00274FE8);

void func_00275268(void)
{
    func_00273AD0(5);
    func_00272ED0(5, D_41D194);
    D_002BDAA4 = 0;
}

s32 func_002752A0(s32 a, s32 b) { s32 old = D_41D198.m14; D_41D198.m14 = a; D_41D198.m18 = b; return old; }
