#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern u32 D_002BDAA8;
extern s32 D_002BDB3C;
typedef struct G { s32 m0, m4, m8, mC, m10, m14, m18; } G;
extern G D_41D198;
void func_00275268();
void func_00276CE8();
s32 func_002731E0(s32);
s32 func_002731C0(s32);
typedef struct E { u8 b[64]; } E;
typedef struct P { s32 m0, m4, m8, mC; u32 m10; E *m14; s32 m18; s32 m1C, m20; s32 m24; } P;

s32 func_0027BD20(void);
s32 func_0027BD78(void);
typedef struct { void *func; void *arg; void *gp; } Hnd;
typedef struct { s32 m0, m4, m8; Hnd *mC; s32 m10; Hnd *m14; } HTab;
extern HTab D_41D198_h __asm__("D_41D198");
int func_00275398(int, int, int, int, int, int, int);
int func_00275510(int, int, int, int, int, int);
E *func_002759D8(P *p);
typedef struct { u8 p0[0x1C]; E *m1C; int m20; } P2;
typedef struct { u8 p0[0x24]; int m24, m28, m2C; } Req;
typedef struct Ent { int m0; u8 p4[0x34]; struct Ent *m38; } Ent;
typedef struct Grp { u8 p0[8]; Ent *m8; u8 pC[8]; struct Grp *m14; } Grp;
typedef struct { u8 p0[0x28]; Grp *m28; } Ctx;
typedef struct Cmd { u8 p0[0xC]; int mC; u8 p10[0xC]; int m1C, m20, m24, m28, m2C, m30, m34; u8 p38[4]; struct Cmd *m3C; struct CQ *m40; } Cmd;
typedef struct CQ { int m0, m4, m8; Cmd *mC; Cmd *m10; } CQ;
typedef struct { u8 p0[0x10]; int m10, m14, m18, m1C, m20, m24, m28, m2C, m30; Cmd *m34; } Src;
s32 func_00273DD0(s32);
typedef struct { void *m0; int m4; } Chk;
typedef struct { u8 p0[0x10]; u32 m10; u8 p14[4]; int m18; } ChkO;
typedef struct Node { int m0, m4, m8, mC, m10; struct Node *m14; } Node;
typedef struct { u8 p0[0x28]; Node *m28; } NodeList;
extern NodeList D_41EBC0;
typedef struct Lnk { u8 p0[0x38]; struct Lnk *m38; } Lnk;
typedef struct { u8 p0[8]; Lnk *m8; } LnkList;
typedef struct Wq { u8 p0[0x3C]; struct Wq *m3C; } Wq;
typedef struct { int m0, m4, m8; Wq *mC; } WqHead;
void func_002765D0(Wq *);
Wq *func_00276578(WqHead *);
void func_002730C0(void);
typedef struct { int count, max_count, init_count, wait_threads; u32 attr, option; } SemaParam;
int func_002731A0(SemaParam *);
extern int D_002BDB40;
extern int D_002BDB44;
void func_002767D8(void);
typedef struct { int m0, m4, m8, mC; } Slot;
extern Slot D_420140[32];
extern void *D_420400;
int strncmp(const char *, const char *, int);
void *memset(void *, int, int);
extern char D_420368[];
extern char D_002BDA8C[];
extern char *D_002BDB48;
extern int D_002BDB34;

s32 func_0027BD20(void);
s32 func_0027BD78(void);
typedef struct { int m0, m4, m8, mC; u32 m10; void *m14; int m18; u8 p1C[0x24]; } PE;
typedef struct { int m0; PE *m4; int m8; } Pool;
typedef struct { void *m0; int m4; int m8; int mC; int m10; int m14; void *m18; void (*m1C)(void *); void *m20; int m24; } RC;
typedef struct { u8 p0[0x1C]; RC *m1C; u32 m20; int m24; int m28; } Rq;
typedef struct { u8 p0[0x10]; u32 m10; int m14; u8 p18[4]; int m1C, m20, m24, m28; } Cm;
typedef struct { u8 p0[0x14]; int m14; u8 p18[4]; int m1C; u32 m20; void *m24; int m28; int m2C; } EE;
EE *func_00275A08b(void *pool, int i) __asm__("func_00275A08");
EE *func_002759D8b(void *pool) __asm__("func_002759D8");
void *func_00275D80b(int id, void *c) __asm__("func_00275D80");
void func_0027DAC8(int, void *, void *);
int func_00275B18();
int func_00275DD0();
typedef struct C2 { int m0, m4, m8, mC, m10, m14; u8 p18[0x20]; struct C2 *m38; int m3C; void *m40; } C2;
typedef struct { int m0, m4; C2 *m8; } C2Q;
// @decl-end

s32 func_002752B8(s32 a, s32 b) { s32 old = D_41D198.mC; D_41D198.mC = a; D_41D198.m10 = b; return old; }

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_002752D0);

void func_00275348(int n)
{
    if (n < 0) D_41D198_h.mC[n & 0x7FFFFFFF].func = 0;
    else D_41D198_h.m14[n].func = 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275398);

int func_002754D0(int a, int b, int c, int d, int e, int f)
{
    return func_00275398(a, 0, b, c, d, e, f);
}

int func_00275510(int a, int b, int c, int d, int e, int f)
{
    return func_00275398(a, 1, b, c, d, e, f);
}

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275550);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275698);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275744);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275748);

void func_002758E8(void) { func_00275268(); D_002BDAA8 = 0; }

PE *func_00275910(Pool *p)
{
    PE *e;
    int i;
    func_0027BD20();
    e = p->m4;
    for (i = 0; i < p->m8; i++, e++) {
        if (!(e->m10 & 1)) {
            int s;
            e->m10 = (i << 16) | 5;
            if (++p->m0 == 1) { p->m0++; s = 1; } else s = p->m0;
            e->m14 = e;
            e->m18 = s;
            func_0027BD78();
            return e;
        }
    }
    func_0027BD78();
    return 0;
}

void func_002759B8(P *p) { p->m18 = 0; p->m10 &= ~1; }

E *func_002759D8(P *p) { s32 i = p->m24 % p->m18; E *e = &p->m14[i]; p->m24 = i + 1; return e; }

E *func_00275A08(P2 *p, int i)
{
    if (i < 0 || i >= p->m20) return func_002759D8((P *)p);
    return &p->m1C[i];
}

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275A48);

int func_00275B18(int a, int b, int c, Req *r)
{
    return func_00275510(0x80000008, (int)r, 0x40, r->m24, r->m28, r->m2C) ? 0 : 0x800;
}

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275B58);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275C28);

Ent *func_00275D80(int id, Ctx *c)
{
    Grp *g;
    Ent *e;
    for (g = c->m28; g; g = g->m14)
        for (e = g->m8; e; e = e->m38)
            if (e->m0 == id) return e;
    return 0;
}

int func_00275DD0(int a, int b, int c, Req *r)
{
    return func_00275510(0x80000008, (int)r, 0x40, 0, 0, 0) ? 0 : 0x800;
}

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275E10);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275EE0);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276020);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_002760B0);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_002762A8);

void func_002762E8(Node *n, int a)
{
    Node *p;
    func_0027BD20();
    n->m0 = a;
    n->m4 = 0;
    n->m8 = 0;
    n->mC = 0;
    n->m10 = 0;
    n->m14 = 0;
    if (D_41EBC0.m28 == 0) D_41EBC0.m28 = n;
    else {
        p = D_41EBC0.m28;
        while (p->m14) p = p->m14;
        p->m14 = n;
    }
    func_0027BD78();
}

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276380);

Lnk *func_00276450(Lnk *a, LnkList *l)
{
    Lnk *p;
    func_0027BD20();
    p = l->m8;
    if (p == a) l->m8 = p->m38;
    else {
        for (; p; p = p->m38) {
            if (p->m38 == a) { p->m38 = a->m38; break; }
        }
    }
    func_0027BD78();
    return p;
}

Node *func_002764E8(Node *a)
{
    Node *p;
    func_0027BD20();
    p = D_41EBC0.m28;
    if (p == a) D_41EBC0.m28 = p->m14;
    else {
        for (; p; p = p->m14) {
            if (p->m14 == a) { p->m14 = a->m14; break; }
        }
    }
    func_0027BD78();
    return p;
}

Wq *func_00276578(WqHead *q)
{
    Wq *e;
    func_0027BD20();
    e = q->mC;
    if (!e) q->m4 = 0;
    else { q->m4 = 1; q->mC = e->m3C; }
    func_0027BD78();
    return e;
}

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_002765D0);

void func_00276798(WqHead *q)
{
    Wq *e;
    for (;;) {
        while ((e = func_00276578(q)) != 0) func_002765D0(e);
        func_002730C0();
    }
}

void func_002767D8(void)
{
    SemaParam p;
    if (D_002BDB40 == -1) {
        p.init_count = 1;
        p.max_count = 1;
        p.option = 0;
        D_002BDB40 = func_002731A0(&p);
        D_002BDB44 = func_002731A0(&p);
    }
}

Slot *func_00276838(void)
{
    Slot *p;
    func_002767D8();
    func_002731E0(D_002BDB40);
    for (p = D_420140; p < D_420140 + 32; p++) {
        if (p->m4 == 0) {
            p->m4 = 0x10000000;
            func_002731C0(D_002BDB40);
            return p;
        }
    }
    func_002731C0(D_002BDB40);
    return 0;
}

Slot *func_002768C0(u32 i)
{
    Slot *p;
    func_002767D8();
    func_002731E0(D_002BDB40);
    if (i >= 32) {
        func_002731C0(D_002BDB40);
        return 0;
    }
    p = &D_420140[i];
    func_002731C0(D_002BDB40);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276930);

void func_00276CE8(void)
{
    SemaParam p;
    if (D_002BDB3C == -1) {
        p.init_count = 1;
        p.max_count = 1;
        p.option = 0;
        D_002BDB3C = func_002731A0(&p);
    }
}

s32 func_00276D38(void) { func_00276CE8(); func_002731E0(D_002BDB3C); return 0; }

void func_00276D68(void) { func_002731C0(D_002BDB3C); }

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276D78);

void func_00276E20(int cause, Hnd *h)
{
    if (h->func) {
        void *old;
        asm volatile("move %0, $28\n\tlw $28, %1" : "=r"(old) : "m"(D_420400));
        ((void (*)(void *))h->func)(h->arg);
        asm volatile("move $28, %0" : : "r"(old));
    }
    asm volatile("sync\n\tei");
}

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276E68);

int func_00277070(void)
{
    char *a = D_002BDA8C;
    char *b = D_420368;
    int r = 0;
    if (strncmp(b, a, 4) && strncmp(b, D_002BDB48, 4))
        r = strncmp(a, D_002BDB48, 4) != 0;
    return r;
}

int func_00277100(void)
{
    D_002BDB34 = 0;
    memset(D_420368, 0, 4);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00277138);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_002773C0);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00277540);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00277778);
