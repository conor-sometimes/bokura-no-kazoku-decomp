#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "libc.h"
s32 Func235DE0(const char *fmt, ...);
struct SifCli { u8 pad[0x24]; void *serve; };
struct RpcW { s32 sema; u8 pad[0x3C]; SifCli cd; };
extern s32 D_002B90AC;
extern s32 D_002B90B0;
extern s32 D_002B91A0;
extern s32 D_002B9160[];
extern s32 D_002B91C4;
extern s32 D_002B91C8;
extern s32 D_379A98;
extern s32 D_379A9C;
extern s32 D_379AA0;
extern s32 D_379AA8[28][80];

extern u8 D_36FA00[];
extern "C" void func_001F15F0(void);
extern "C" void func_001F1610(void);
extern "C" void func_002731E0(s32);
extern "C" s32 func_002731D0(s32);
extern "C" void func_00273420(s32);
extern "C" void func_002760B0(void *, s32, s32, void *, s32, void *, s32, void *, void *);
extern "C" s32 func_002762A8(void *);
extern "C" s32 func_00235FE8(s32, s32);
extern "C" s32 func_002731B0(s32);
extern "C" s32 func_002731F0(s32);
extern "C" s32 func_002731C0(s32);
extern "C" void func_001F1A80(void *, s32, s32, s32);
extern "C" void func_001F1230(void);
extern "C" s32 func_00235DA8(void);
extern "C" s32 func_00235AA0(const char *);
extern "C" s32 func_00234360(void);
extern "C" s32 func_00277138(const char *, s32);
extern "C" s32 func_002773C0(s32);
extern "C" s32 func_00277778(s32, void *, s32);
extern "C" s32 func_002779D8(s32, const void *, s32);
extern "C" s32 func_00277540(s32, s32, s32);
extern "C" s32 func_00277C98(s32, s32, s32);
extern "C" s32 func_0027B4E0(s32, void *);
extern "C" void func_002365C8(s32, s32, s32, s32, s32, void *);
extern "C" s32 func_00273630(void);
extern "C" void func_0026F0D8(void *, s32, s32, s32, s16, s16, s16, s16);
extern "C" s32 func_0026F400(void *, s32);
extern "C" void func_00236BC8(s32);
extern "C" s32 func_0026ED28(void *);
extern "C" void func_00236AF8(void);
extern "C" void func_00236AB0(s32);
extern "C" void func_00236D60(void);
struct GsReg { u32 b0 : 1; u32 b1 : 1; u32 rest : 30; };
extern GsReg D_379A70;
extern "C" void func_00236A98(void);
extern "C" void func_00236DB0(void);
extern "C" void func_00236E48(char);
extern "C" void func_002361F0(RpcW *);
extern "C" void func_00236288(void);
extern "C" s32 func_002362E8(void);
extern "C" void func_00236388(const char *);

struct DmaTagB { u32 qwc : 16; u32 pad : 12; u32 id : 3; u32 irq : 1; u32 addr; u32 w2; u32 w3; };
struct DmaTagQ { u64 d0; u64 d1; };
struct DmaTag { DmaTagB b; };
#define TQ(t) ((DmaTagQ *)(t))
struct PktSave { DmaTag *tag; DmaTag *call; u8 *cur; s32 sp; u8 *stack[32]; s32 len; };
extern u8 *D_002B94E4;
extern s32 D_002B94D0;
extern s32 D_002B94D4;
extern u8 *D_002B94D8;
extern s32 D_002B94DC;
extern s32 D_002B94E0;
extern DmaTag *D_37BDB0;
extern DmaTag *D_37BDB4;
extern u8 *D_37BDB8[32];
extern s32 D_002B91CC;
extern s32 D_002B91C0;
extern u32 D_37BDA8[2];
extern "C" void func_00100248(void);
extern "C" void func_00237000(s32);
extern "C" s32 func_00235D90(s32);
extern const char D_002E5200[];
extern const char D_002E51C8[];
extern const char D_002E51E8[];
struct GsInfo { u8 pad[4]; s16 m4; };
extern "C" GsInfo *func_0026E888(void);
extern "C" void func_0026E9B0(void *, s32, s32, s32, s32, s32);
extern "C" void func_00234C78(void);
extern "C" void func_00236F68(void);
DmaTag *Func237570(int n);
extern "C" u8 *func_00237350(s32);
extern "C" u8 *func_002375D8(s32);

extern const char _ctype_[];
#define isprint(c) ((_ctype_+1)[(unsigned)(c)]&(0x10|1|2|4|0x80))
extern const char D_002E5198[];
extern const char D_002E51A0[];
extern const char D_002E51A8[];
extern const char D_002E51B0[];
extern const char D_002E51B8[];
extern const char D_002E51C0[];
// @decl-end

extern "C" void func_00236130(RpcW *w, s32 fno, void *send, s32 ssize, void *recv, s32 rsize) {
    func_001F15F0();
    func_002731E0(w->sema);
    func_00273420(0);
    func_002760B0(&w->cd, fno, 1, send, ssize, recv, rsize, (void *)func_002361F0, w);
    func_001F1610();
    while (func_002762A8(&w->cd) == 1);
    return (void)func_00273420(0);
}

extern "C" void func_002361F0(RpcW *w) {
    func_002731D0(w->sema);
    asm volatile("sync");
    asm volatile("ei");
}

extern "C" void func_00236218(void) {
    D_002B90B0 = func_00235FE8(1, 1);
    D_002B90AC = func_00235FE8(1, 1);
}

extern "C" void func_00236258(void) {
    func_002731B0(D_002B90AC);
    return (void)func_002731B0(D_002B90B0);
}

extern "C" void func_00236288(void) {
    while (func_002731F0(D_002B90B0) == -1) {
        func_001F1A80((void *)func_00235DA8, 0, 0, 0);
        func_001F1230();
    }
}

extern "C" s32 func_002362E8(void) {
    return func_002731C0(D_002B90B0);
}

extern "C" void func_00236308(void) {
    while (func_002731F0(D_002B90AC) == -1) {
        func_001F1A80((void *)func_00235DA8, 0, 0, 0);
        func_001F1230();
    }
}

extern "C" s32 func_00236368(void) {
    return func_002731C0(D_002B90AC);
}

extern "C" void func_00236388(const char *s) {
    if (func_00235AA0(s)) return (void)func_00234360();
}

extern "C" s32 func_002363B0(const char *name, s32 mode) {
    s32 r;
    func_00236288();
    func_00236388(name);
    r = func_00277138(name, mode);
    func_002362E8();
    return r;
}

extern "C" s32 func_00236400(s32 fd) {
    s32 r;
    func_00236288();
    r = func_002773C0(fd);
    func_002362E8();
    return r;
}

extern "C" s32 func_00236438(s32 fd, void *buf, s32 n) {
    s32 r;
    func_00236288();
    r = func_00277778(fd, buf, n);
    func_002362E8();
    return r;
}

extern "C" s32 func_00236490(s32 fd, const void *buf, s32 n) {
    s32 r;
    func_00236288();
    r = func_002779D8(fd, buf, n);
    func_002362E8();
    return r;
}

extern "C" s32 func_002364E8(s32 fd, s32 off, s32 whence) {
    s32 r;
    func_00236288();
    r = func_00277540(fd, off, whence);
    func_002362E8();
    return r;
}

extern "C" s32 func_00236540(s32 a, s32 b, s32 c) {
    s32 r;
    func_00236288();
    r = func_00277C98(a, b, c);
    func_002362E8();
    return r;
}

extern "C" void func_00236598(void) {
    return func_00236288();
}

extern "C" s32 func_002365B0(void) {
    return func_002362E8();
}

INCLUDE_ASM("asm/nonmatchings/Unit236130", func_002365C8);

extern "C" void func_002367E8(void) {
    s32 i;
    if (D_002B91A0) return;
    D_002B91A0 = 1;
    for (i = 1; i < 8; i++) D_002B9160[i] = func_0027B4E0(i, (void *)func_002365C8);
    for (i = 10; i < 14; i++) D_002B9160[i] = func_0027B4E0(i, (void *)func_002365C8);
}

extern "C" void func_00236898(void) {
    s32 i;
    if (D_002B91A0 == 0) return;
    D_002B91A0 = 0;
    for (i = 1; i < 8; i++) func_0027B4E0(i, (void *)D_002B9160[i]);
    for (i = 10; i < 14; i++) func_0027B4E0(i, (void *)D_002B9160[i]);
}

extern "C" void func_00236930(char *p, s32 n) {
    s32 i, k;
    while (n > 0) {
        k = 16;
        if (n < k) k = n;
        Func235DE0(D_002E5198, p);
        n -= k;
        for (i = 0; i < k; i++) Func235DE0(D_002E51A0, (u8)*p++);
        for (; i < 16; i++) Func235DE0(D_002E51A8);
        p -= k;
        for (i = 0; i < k; i++) {
            char c = *p++;
            Func235DE0(D_002E51B0, isprint(c) ? c : '.');
        }
        for (; i < 16; i++) Func235DE0(D_002E51B8);
        Func235DE0(D_002E51C0);
    }
}

extern "C" void func_00236A98(void) {
    return (void)func_00273630();
}

extern "C" void func_00236AB0(s32 r) {
    s32 i;
    for (i = 0; i < 80; i++) D_379AA8[r + 1][i] = 0;
}

extern "C" void func_00236AF8(void) {
    s32 r, i;
    for (r = 0; r < 27; r++)
        for (i = 0; i < 80; i++) D_379AA8[r][i] = D_379AA8[r + 1][i];
}

extern "C" s32 func_00236B50(s16 x, s16 y, s16 w, s16 h, s32 p) {
    func_0026F0D8(D_36FA00, 0, 10, 0, x, y, w, h);
    func_00273420(0);
    return func_0026F400(D_36FA00, p);
}

INCLUDE_ASM("asm/nonmatchings/Unit236130", func_00236BC8);

extern "C" void func_00236D60(void) {
    s32 i;
    for (i = 0; i < 28; i++) func_00236BC8(i);
    func_00236A98();
    return (void)func_0026ED28(&D_379A70);
}

extern "C" void func_00236DB0(void) {
    s32 i;
    D_379A98 = 0;
    if (++D_379A9C >= 26) {
        func_00236AF8();
        D_379A9C = 25;
    }
    func_00236AB0(D_379A9C);
    func_00236D60();
    for (i = 0; i < D_002B91C4; i++) func_00236A98();
}

INCLUDE_ASM("asm/nonmatchings/Unit236130", func_00236E48);

extern "C" s32 func_00236ED8(const char *s) {
    while (*s) func_00236E48(*s++);
    return 1;
}

extern "C" s32 func_00236F28(s32 on) {
    D_379A70.b1 = on != 0;
    return func_0026ED28(&D_379A70);
}

extern "C" void func_00236F68(void) {
    s32 r, i;
    for (r = 0; r < 28; r++)
        for (i = 0; i < 80; i++) D_379AA8[r][i] = 0;
    D_379A98 = 0;
    D_379A9C = 0;
}

extern "C" void func_00236FD0(s32 a, s32 b) {
    D_002B91C4 = a;
    D_002B91C8 = b;
}

extern "C" s32 func_00236FE8(s32 v) {
    s32 old = D_379AA0;
    D_379AA0 = v;
    return old;
}

extern "C" void func_00237000(s32 a) {
    D_379AA0 = 0x80004080;
    Func235DE0(D_002E51C8, a);
    for (;;);
}

extern "C" void func_00237048(void) {
    u32 *p = (u32 *)func_00100248;
    GsInfo *g;
    if (D_002B91CC) return;
    D_002B91CC = 1;
    D_37BDA8[0] = p[0];
    D_37BDA8[1] = p[1];
    p[0] = ((s32)func_00237000 >> 2) | 0x8000000;
    p[1] = 0;
    func_00273420(3);
    func_00234C78();
    D_002B91C0 = func_00235D90((s32)func_00236ED8);
    g = func_0026E888();
    func_0026E9B0(&D_379A70, 0, 0x280, (0xE00000 << (1 - g->m4)) >> 16, 0, 0);
    *(u64 *)&D_379A70 = 0x66;
    func_00236F68();
    func_00236D60();
    D_379AA0 = 0x80804040;
    Func235DE0(D_002E51E8);
    D_379AA0 = 0x807F7F7F;
}

extern "C" void func_00237160(void) {
    s32 i;
    u32 *p = (u32 *)func_00100248;
    if (D_002B91CC == 0) return;
    D_002B91CC = 0;
    D_379AA0 = 0x80804040;
    Func235DE0(D_002E5200, D_002B91C8);
    D_379AA0 = 0x807F7F7F;
    for (i = 0; i < D_002B91C8; i++) func_00236A98();
    func_00235D90(D_002B91C0);
    D_002B91C0 = 0;
    p[0] = D_37BDA8[0];
    p[1] = D_37BDA8[1];
    return (void)func_00273420(3);
}

extern "C" void func_00237260(PktSave *s) {
    s32 i;
    s->tag = D_37BDB0;
    s->call = D_37BDB4;
    s->cur = D_002B94E4;
    s->sp = D_002B94D0;
    s->len = D_002B94D4;
    for (i = 0; i < 32; i++) s->stack[i] = D_37BDB8[i];
}

extern "C" void func_002372D8(PktSave *s) {
    s32 i;
    D_37BDB0 = s->tag;
    D_37BDB4 = s->call;
    D_002B94E4 = s->cur;
    D_002B94D0 = s->sp;
    D_002B94D4 = s->len;
    for (i = 0; i < 32; i++) D_37BDB8[i] = s->stack[i];
}

extern "C" u8 *func_00237350(s32 n) {
    u8 *p = D_002B94E4;
    n &= 0xF;
    for (; ((u32)p & 0xF) != n; p++) *p = 0;
    D_002B94E4 = p;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/Unit236130", func_00237398);

extern "C" u8 *func_002373E0(s32 i) {
    return D_37BDB8[(D_002B94D0 + i) & 31];
}

asm(".p2align 3");
extern "C" u8 *func_00237408(s32 n) {
    s32 sp = (D_002B94D0 - 1) & 31;
    u8 *p = D_002B94E4;
    D_002B94D0 = sp;
    D_37BDB8[sp] = p;
    return D_002B94E4 = p + n;
}

extern "C" s32 func_00237450(void) {
    return D_002B94D4;
}

extern "C" void func_00237460(void) {
    s32 sp = D_002B94D0;
    u8 *cur = D_002B94E4;
    u8 *old = D_37BDB8[sp];
    s32 d;
    D_37BDB8[sp] = cur;
    D_002B94E4 = old;
    d = cur - old;
    if (d < 0) d = -d;
    D_002B94D4 = d;
}

extern "C" u8 *func_002374B0(void) {
    s32 sp = D_002B94D0;
    D_002B94D0 = (sp + 1) & 31;
    return D_002B94E4 = D_37BDB8[sp];
}

extern "C" void func_002374E8(void) {
    u8 *base = D_002B94D8;
    s32 f = D_002B94E0;
    if (f) base += D_002B94DC;
    D_37BDB0 = (DmaTag *)base;
    D_002B94E4 = base + 16;
    D_002B94E0 = f ^ 1;
}

extern "C" void func_00237530(u8 *base, s32 size) {
    D_002B94DC = (size / 2) & ~15;
    D_002B94D8 = base;
    D_002B94E0 = 0;
}

extern "C" u8 *func_00237560(void) {
    return D_002B94D8;
}

DmaTag *Func237570(int n) {
    DmaTag *old = D_37BDB0;
    u8 *t;
    if (n > 0) n += 15;
    t = (u8 *)old + (n & ~15);
    D_37BDB0 = (DmaTag *)t;
    D_002B94E4 = t + 16;
    return old;
}

extern "C" DmaTag *func_002375A8(s32 n) {
    return Func237570(-n);
}

extern "C" DmaTag *func_002375C0(void) {
    return D_37BDB4 = D_37BDB0;
}

INCLUDE_ASM("asm/nonmatchings/Unit236130", func_002375D8);

INCLUDE_ASM("asm/nonmatchings/Unit236130", func_00237680);

extern "C" u32 *func_00237720(u32 a, u32 b, u32 c, u32 d) {
    DmaTag *t;
    u32 *r;
    func_002375D8(0);
    t = D_37BDB0;
    TQ(t)->d0 = 0;
    t->b.qwc = 0;
    TQ(t)->d1 = 0;
    t->b.id = 1;
    t->b.irq = 1;
    r = (u32 *)(t + 1);
    r[0] = a;
    r[1] = b;
    r[2] = c;
    r[3] = d;
    D_37BDB0 = t + 2;
    D_002B94E4 = (u8 *)(t + 3);
    return r;
}

extern "C" DmaTag *func_002377D8(void) {
    DmaTag *t;
    u8 *e;
    func_002375D8(0);
    t = D_37BDB0;
    TQ(t)->d0 = 0;
    TQ(t)->d1 = 0;
    t->b.id = 6;
    t++;
    e = (u8 *)(t + 1);
    D_37BDB4->b.w2 = 0;
    D_37BDB4->b.w3 = (u32)t;
    D_37BDB0 = t;
    t = D_37BDB4;
    D_002B94E4 = e;
    D_37BDB4 = 0;
    return t;
}

INCLUDE_ASM("asm/nonmatchings/Unit236130", func_00237860);

extern "C" u8 *func_002378F8(s32 n, u32 addr) {
    DmaTag *t = D_37BDB0;
    TQ(t)->d0 = 0;
    t->b.qwc = n;
    TQ(t)->d1 = 0;
    t->b.id = 1;
    if ((addr & 0x70000000) == 0x70000000) addr |= 0x80000000;
    t->b.addr = addr;
    t++;
    D_37BDB0 = t;
    D_002B94E4 = (u8 *)(t + 1);
    return (u8 *)t;
}

extern "C" u8 *func_00237968(s32 n, u32 addr) {
    DmaTag *t = D_37BDB0;
    TQ(t)->d0 = 0;
    t->b.qwc = n;
    TQ(t)->d1 = 0;
    t->b.id = 0;
    if ((addr & 0x70000000) == 0x70000000) addr |= 0x80000000;
    t->b.addr = addr;
    t++;
    D_37BDB0 = t;
    D_002B94E4 = (u8 *)(t + 1);
    return (u8 *)t;
}

INCLUDE_ASM("asm/nonmatchings/Unit236130", func_002379D0);
