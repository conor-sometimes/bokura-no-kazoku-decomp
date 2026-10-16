#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern int D_002BF158;
extern int D_002BF15C;
extern u8 D_423F08[];
extern const char D_002EA238[];
extern const char *D_002BF1F8[];
void *memset(void *, int, unsigned int);
char *strcpy(char *, const char *);
int func_002735D0(int, void *);

extern const char *D_002BF218[];

extern char D_424108[];
typedef struct { char pad[0x10]; int m10; char pad2[0x58 - 0x14]; int m58; unsigned char pad3[0x70 - 0x5C]; unsigned char m70; unsigned char m71; unsigned char m72; char pad4[0x80 - 0x73]; } PadSt;
typedef struct { PadSt *m0; int *m4; char pad[8]; int m10; int m14; int m18; } PadPort;
extern PadPort D_424190[][4];
PadSt *func_0027EDC8(int, int);
int func_0027F800(int, int, int);

int func_00292EC8(void *, void *);
int func_0027F748(int, int);

int func_002760B0(void *, int, int, void *, int, void *, int, int, int);
extern char D_424140[];
extern int D_424380[32];

typedef struct W2Sema { struct W2Sema *next; volatile int id; int p[2]; } W2Sema;
extern W2Sema *D_423F00;

extern int D_002BF1F0;

int func_0027D088(int);

typedef struct { void *func; void *arg; void *gp; int pad; } W2Hnd;

int func_0027E7B0(int, int);

typedef struct { void *func; void *arg; void *gp; int pad; } W2Hnd2;

typedef struct { unsigned char p0[0x30]; unsigned char act[4][4]; unsigned char comb[4][4]; unsigned char p50[0x14]; unsigned char m64, m65, m66, m67, m68, m69, m6A, m6B; unsigned char p6C[6]; unsigned char m72; } W2PadInfo;

typedef struct { unsigned char p0[0x50]; unsigned short m50[10]; unsigned char m64, m65, m66, m67, m68, m69, m6A, m6B; unsigned char p6C[5]; unsigned char m71, m72; } W2PadInfo2;

int func_0027EA08();
extern int D_002BF1F4;
void func_00274F10(const char *, ...);
typedef struct { unsigned char p0[0x24]; int serve; } W2RpcCli;
int func_00275EE0(W2RpcCli *, unsigned int, int);
extern W2RpcCli W2PadCd[2] __asm__("D_424140");
extern const char D_002EA160[];
extern const char D_002EA188[];

typedef struct { u32 m0, m4, m8, mC, m10, m14, m18, m1C; } W2IpuSt;
#define W2REG(a) (*(volatile int *)(a))
typedef int W2q __attribute__((mode(TI)));
extern volatile W2q D_002BF170[];
extern volatile W2q D_002BF1C0[];
void func_0027E500(int);
#define W2IPU_CMD (*(volatile u32 *)0x10002000)
#define W2IPU_CTRL (*(volatile int *)0x10002010)
#define W2IPU_IN (*(volatile W2q *)0x10007010)
// @decl-end

int func_0027DBB8(int id) { W2Sema *e = (W2Sema *)(((unsigned int)id >> 8) << 4); int s = func_0027BD20(); if (id < 0 || ((id ^ e->id) & 0xFF)) { if (s) func_0027BD78(); return 0x80008002; } func_0027D088(e->id); e->next = D_423F00; D_423F00 = e; e->id = 0; if (s) func_0027BD78(); return 0; }

int func_0027DC60(int id) { W2Sema *e = (W2Sema *)(((unsigned int)id >> 8) << 4); int r; if (id < 0 || ((id ^ e->id) & 0xFF)) return 0x80008002; r = func_0027CFE8(e->id); if (r == 0) { e->next = D_423F00; D_423F00 = e; e->id = 0; } return r; }

void func_0027DCD8(void) { D_002BF158 = 0; D_002BF15C = 0; memset(D_423F08, 0, 0x200); }

int func_0027DD00(void *buf, int n) { int s = func_0027BD20(); int old = D_002BF158; D_002BF158 = (int)buf; D_002BF15C = n; memset(buf, 0, n << 4); if (s) func_0027BD78(); return old; }

int func_0027DD80(int id, void *func, void *arg) { void *gp; W2Hnd2 *tbl; unsigned int n; int s; if (id < 0) { id &= 0x7FFFFFFF; tbl = (W2Hnd2 *)D_423F08; n = 0x20; } else { tbl = (W2Hnd2 *)D_002BF158; n = D_002BF15C; } if ((unsigned int)id >= n) return 0x80000069; s = func_0027BD20(); tbl[id].func = func; tbl[id].arg = arg; asm volatile("move %0, $28" : "=r"(gp)); tbl[id].gp = gp; if (s) func_0027BD78(); return 0; }

int func_0027DE38(int id) { W2Hnd2 *tbl; unsigned int n; if (id < 0) { id &= 0x7FFFFFFF; tbl = (W2Hnd2 *)D_423F08; n = 0x20; } else { tbl = (W2Hnd2 *)D_002BF158; n = D_002BF15C; } if ((unsigned int)id >= n) return -0x69; tbl[id].func = 0; return 0; }

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027DE90);

int func_0027DF38(unsigned short a, int x, int y) { int b[4]; b[0] = a; b[1] = x; b[2] = y; b[3] = (int)D_424108 | 0x20000000; return func_002735D0(1, b); }

int func_0027DF80(int a) { int b[1]; b[0] = a; return func_002735D0(2, b); }

int func_0027DFA8(int a, char c) { int b[2]; b[0] = a; b[1] = c; return func_002735D0(3, b); }

int func_0027DFD8(int a) { int b[1]; b[0] = a; return func_002735D0(4, b); }

int func_0027E000(unsigned char a, int x, int y) { int b[8]; b[0] = a; b[1] = x; b[2] = y; return func_002735D0(0x20, b); }

int func_0027E030(int a) { int b[1]; b[0] = a; return func_002735D0(0x21, b); }

int func_0027E058(int a, int x, unsigned short y) { int b[3]; b[0] = a; b[1] = x; b[2] = y; return func_002735D0(-5, b); }

int func_0027E090(int a, int x, unsigned short y) { int b[3]; b[0] = a; b[1] = x; b[2] = y; return func_002735D0(-6, b); }

int func_0027E0C8(int a, char c) { int b[2]; b[0] = a; b[1] = c; return func_002735D0(-7, b); }

int func_0027E0F8(int a) { int b[1]; b[0] = a; return func_002735D0(-8, b); }

int func_0027E120(int a) { int b[1]; b[0] = a; return func_002735D0(-9, b); }

int func_0027E148(int a) { int b[1]; b[0] = a; return func_002735D0(0x10, b); }

void func_0027E170(int v) { int s = func_0027BD20(); *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 | 0x10000; *(volatile int *)0x1000B000 = v; *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 & ~0x10000; if (s) func_0027BD78(); }

void func_0027E1E8(int v) { int s = func_0027BD20(); *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 | 0x10000; *(volatile int *)0x1000B400 = v; *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 & ~0x10000; if (s) func_0027BD78(); }

void func_0027E260(unsigned int *s) { func_0027E1E8(1); s[0] = *(volatile unsigned int *)0x1000B410; s[1] = *(volatile unsigned int *)0x1000B430; s[2] = *(volatile unsigned int *)0x1000B420; s[3] = *(volatile unsigned int *)0x1000B400; while (*(volatile unsigned int *)0x10002010 & 0xF0) ; func_0027E170(0); s[4] = *(volatile unsigned int *)0x1000B010; s[5] = *(volatile unsigned int *)0x1000B020; s[6] = *(volatile unsigned int *)0x1000B000; s[7] = *(volatile unsigned int *)0x10002020; s[8] = *(volatile unsigned int *)0x10002010; }

void func_0027E348(W2IpuSt *s)
{
    u32 ctrl = s->m1C;
    int cmd = ctrl & 0x7F;
    u32 q = ((ctrl >> 16) & 3) + ((ctrl >> 8) & 0xF);
    u32 madr = s->m0 - q * 16;
    u32 qwc = s->m8 + q;
    if (s->m10 && s->m14) {
        W2REG(0x1000B010) = s->m10;
        W2REG(0x1000B020) = s->m14;
        func_0027E170(s->m18 | 0x100);
    }
    while (W2REG(0x10002010) < 0)
        ;
    W2REG(0x10002000) = cmd;
    while (W2REG(0x10002010) < 0)
        ;
    if (madr && qwc) {
        W2REG(0x1000B410) = madr;
        W2REG(0x1000B430) = s->m4;
        W2REG(0x1000B420) = qwc;
        func_0027E1E8(s->mC | 0x100);
    }
}

int func_0027E498(int m) { int r = 0; switch (m) { case 0: while (*(volatile int *)0x10002010 < 0) ; r = 0; break; case 1: r = *(volatile unsigned int *)0x10002010 >> 31; break; } return r; }

void func_0027E500(int v) { int s = func_0027BD20(); *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 | 0x10000; *(volatile int *)0x1000B400 = v; *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 & ~0x10000; if (s) func_0027BD78(); }

void func_0027E578(void)
{
    func_0027E500(1);
    W2IPU_CTRL = 0x40000000;
    while (W2IPU_CTRL < 0)
        ;
    W2IPU_CMD = 0;
    while (W2IPU_CTRL < 0)
        ;
    W2IPU_IN = D_002BF170[0];
    W2IPU_IN = D_002BF170[1];
    W2IPU_IN = D_002BF170[2];
    W2IPU_IN = D_002BF170[3];
    W2IPU_IN = D_002BF170[4];
    W2IPU_IN = D_002BF170[4];
    W2IPU_IN = D_002BF170[4];
    W2IPU_IN = D_002BF170[4];
    W2IPU_CMD = 0x50000000;
    while (W2IPU_CTRL < 0)
        ;
    W2IPU_CMD = 0x58000000;
    while (W2IPU_CTRL < 0)
        ;
    W2IPU_IN = D_002BF1C0[0];
    W2IPU_IN = D_002BF1C0[1];
    W2IPU_CMD = 0x60000000;
    while (W2IPU_CTRL < 0)
        ;
    W2IPU_CMD = 0x90000000;
    while (W2IPU_CTRL < 0)
        ;
    W2IPU_CTRL = 0x40000000;
    while (W2IPU_CTRL < 0)
        ;
    W2IPU_CMD = 0;
    while (W2IPU_CTRL < 0)
        ;
}

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027E7B0);

int func_0027E8C8(int a)
{
    int i, v;
    D_002BF1F0 = 1;
    while (func_00275EE0(&W2PadCd[0], 0x80000100, 0), W2PadCd[0].serve == 0) {
        i = 0x10000;
        while (i--)
            ;
    }
    while (func_00275EE0(&W2PadCd[1], 0x80000101, 0), W2PadCd[1].serve == 0) {
        i = 0x10000;
        while (i--)
            ;
    }
    v = func_0027FB60();
    if ((v >> 8) != 4) {
        if (D_002BF1F4) {
            func_00274F10(D_002EA160);
            func_00274F10(D_002EA188, 4, 0, v >> 8, v & 0xFF);
        }
        return 0;
    }
    return func_0027EA08(a);
}

int func_0027EA08(void) { int i; for (i = 0; i < 4; i++) { D_424190[0][i].m10 = 0; D_424190[0][i].m18 = 0; D_424190[0][i].m14 = 0; D_424190[1][i].m10 = 0; D_424190[1][i].m18 = 0; D_424190[1][i].m14 = 0; } D_424380[0] = 0x10; D_424380[4] = 0; if (func_002760B0(D_424140, 1, 0, D_424380, 0x80, D_424380, 0x80, 0, 0) < 0) return 0; return D_424380[3]; }

int func_0027EAA8(void) { int r; D_424380[0] = 0xF; if (func_002760B0(D_424140, 1, 0, D_424380, 0x80, D_424380, 0x80, 0, 0) < 0) return 0; r = D_424380[3]; if (r == 1) D_002BF1F0 = 0; return r; }

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027EB28);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027ED10);

PadSt *func_0027EDC8(int a, int b) { PadSt *p = D_424190[a][b].m0; int i; func_00292EC8(p, (char *)p + 0xFF); i = p[0].m58 < p[1].m58; return &p[i]; }

int func_0027EE28(int a, int b) { if (D_424190[a][b].m10 == 0) return 0; return func_0027EDC8(a, b)->m58; }

int func_0027EE78(int a, int b, unsigned char *rdata)
{
    PadSt buf;
    PadSt *p;
    int st;
    if (D_424190[a][b].m10 == 0) return 0;
    st = func_0027BD20();
    p = &buf;
    *p = *func_0027EDC8(a, b);
    memcpy(rdata, p, *(int *)((char *)p + 0x60));
    if (st == 1) func_0027BD78();
    return *(int *)((char *)p + 0x60);
}

int func_0027EFE0(int a, int b) { PadSt *p; if (D_424190[a][b].m10 == 0) return 99; p = func_0027EDC8(a, b); if (p->m70 == 6) { if (p->m71 != 2) return p->m70; return 5; } return p->m70; }

void func_0027F058(unsigned int i, char *d) { if (i < 8) { strcpy(d, D_002BF1F8[i]); return; } *d = D_002EA238[0]; }

int func_0027F090(int a, int b, int c) { if (D_424190[a][b].m10 == 0) return 0; func_0027EDC8(a, b)->m71 = c; return 1; }

int func_0027F0F8(int a, int b) { if (D_424190[a][b].m10 == 0) return 0; return func_0027EDC8(a, b)->m71; }

void func_0027F148(unsigned int i, char *d) { if (i < 4) { strcpy(d, D_002BF218[i]); return; } *d = D_002EA238[0]; }

int func_0027F180(int a, int b, int n, int t)
{
    W2PadInfo *p;
    if (D_424190[a][b].m10 == 0) return 0;
    p = (W2PadInfo *)func_0027EDC8(a, b);
    if (p->m72 != 1) return 0;
    if (p->m64 < 2) return 0;
    if (n >= p->m6A) return 0;
    if (n == -1) return p->m6A;
    switch (t) {
    case 1: return p->act[n][0];
    case 2: return p->act[n][1];
    case 3: return p->act[n][2];
    case 4: return p->act[n][3];
    }
    return 0;
}

int func_0027F2A0(int a, int b, int n, int t)
{
    W2PadInfo *p;
    if (D_424190[a][b].m10 == 0) return 0;
    p = (W2PadInfo *)func_0027EDC8(a, b);
    if (p->m72 != 1) return 0;
    if (p->m64 < 2) return 0;
    if (n == -1) return p->m6B;
    if (n >= p->m6B) return 0;
    switch (t) {
    case -1: return p->comb[n][0];
    case 0: return p->comb[n][1];
    case 1: return p->comb[n][2];
    case 2: return p->comb[n][3];
    }
    return 0;
}

int func_0027F3C0(int a, int b, int t, int n)
{
    W2PadInfo2 *p;
    if (D_424190[a][b].m10 == 0) return 0;
    p = (W2PadInfo2 *)func_0027EDC8(a, b);
    if (p->m72 != 1) return 0;
    if (p->m71 == 2) return 0;
    switch (t) {
    case 1:
        if (p->m65 == 0xF3) return 0;
        return p->m65 >> 4;
    case 2:
        if (p->m64 == 1) return 0;
        return p->m50[p->m69];
    case 3:
        if (p->m64 == 1) return 0;
        return p->m69;
    case 4:
        if (p->m64 == 1) return 0;
        if (n == -1) return p->m68;
        if (n >= p->m68) return 0;
        return p->m50[n];
    }
    return 0;
}

int func_0027F4F8(int a, int b, int c, int d) { int r; D_424380[3] = c; D_424380[4] = d; D_424380[0] = 6; D_424380[1] = a; D_424380[2] = b; if (func_002760B0(D_424140, 1, 0, D_424380, 0x80, D_424380, 0x80, 0, 0) < 0) return 0; r = D_424380[5]; if (r == 1) { func_0027F090(a, b, 2); r = D_424380[5]; } return r; }

int func_0027F5B0(int a, int b, unsigned char *data) { int *q; int i; if (func_0027EDC8(a, b)->m72 != 1) return 0; q = D_424190[a][b].m4; { unsigned char *d = (unsigned char *)q + 0xC; for (i = 0; i < 6; i++) d[i] = data[i]; } q[1] = 1; q[2] = 6; if (func_0027E7B0(a, b) != 1) return 0; return 1; }

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027F670);

int func_0027F748(int a, int b) { unsigned char *p; if (D_424190[a][b].m10 == 0) return 0; p = (unsigned char *)func_0027EDC8(a, b); if (p[0x72] != 1) return 0; if (p[0x64] < 2) return 0; if (p[0x66] < 2) return 0; return p[0x79] + ((unsigned long)p[0x7A] << 8) + ((unsigned long)p[0x7B] << 16) + ((unsigned long)p[0x7C] << 24); }

int func_0027F800(int a, int b, int c) { int r; D_424380[3] = c; D_424380[0] = 0xA; D_424380[1] = a; D_424380[2] = b; if (func_002760B0(D_424140, 1, 0, D_424380, 0x80, D_424380, 0x80, 0, 0) < 0) return 0; r = D_424380[4]; if (r == 1) { func_0027F090(a, b, 2); r = D_424380[4]; } return r; }

int func_0027F8B0(int a, int b) { if (D_424190[a][b].m10 == 0) return 0; return func_0027F748(a, b) == 0x3FFFF; }

int func_0027F910(int a, int b) { if (D_424190[a][b].m10 == 0) return 0; return func_0027F800(a, b, 0xFFF); }

int func_0027F968(int a, int b) { if (D_424190[a][b].m10 == 0) return 0; return func_0027F800(a, b, 0); }

int func_0027F9C0(int a, int b, const unsigned char *data)
{
    int r;
    D_424380[1] = a;
    D_424380[0] = 0xB;
    D_424380[2] = b;
    memcpy(&D_424380[3], data, 12);
    if (func_002760B0(D_424140, 1, 0, D_424380, 0x80, D_424380, 0x80, 0, 0) < 0) return 0;
    r = D_424380[7];
    if (r == 1) {
        func_0027F090(a, b, 2);
        r = D_424380[7];
    }
    return r;
}

int func_0027FA90(void) { D_424380[0] = 0xC; if (func_002760B0(D_424140, 1, 0, D_424380, 0x80, D_424380, 0x80, 0, 0) < 0) return 0; return D_424380[3]; }

int func_0027FAF8(int a) { D_424380[1] = a; D_424380[0] = 0xD; if (func_002760B0(D_424140, 1, 0, D_424380, 0x80, D_424380, 0x80, 0, 0) < 0) return 0; return D_424380[3]; }

int func_0027FB60(void) { D_424380[0] = 0x12; if (func_002760B0(D_424140, 1, 0, D_424380, 0x80, D_424380, 0x80, 0, 0) < 0) return 0; return D_424380[3]; }

int func_0027FBC8(int a) { D_424380[1] = a; D_424380[0] = 0x14; if (func_002760B0(D_424140, 1, 0, D_424380, 0x80, D_424380, 0x80, 0, 0) < 0) return 0; return D_424380[2]; }
