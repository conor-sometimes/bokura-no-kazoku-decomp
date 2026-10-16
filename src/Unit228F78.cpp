#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
typedef unsigned int u128 __attribute__((mode(TI)));
extern "C" s32 func_001F1180(void);
extern "C" void func_001F1190(void);
extern "C" s32 func_001F11C8(void);
extern "C" void func_00228658(u8 *);
extern "C" s32 func_00229FB8(void *);
extern "C" s32 func_0022A4D0(void *);
extern "C" u32 func_0022A7F0(void);
extern "C" void func_0022DDE8(s32);
extern "C" void func_0022B510(const char *, ...);
extern "C" void func_002298A0(u8 *, u32, char);
extern "C" void func_00229678(u32, u32, u32);
extern "C" void func_00229888(void *, u32);
extern u8 *D_33F5E0[2];
extern s32 D_33F608[2];
extern u8 *D_002B8C28[2];
#define TID func_001F1180()
struct Node { void *m0; s32 m4; Node *m8; };
struct Heap { s32 m0; Node *m4; s32 m8; s32 mC; s32 m10; s32 m14; s32 pad18[6]; s32 m30; s32 m34; s32 m38; s32 m3C; };
extern Heap *D_002B8C40;
extern s32 D_002B8C3C;
extern s32 D_002B8C44;
extern f32 D_002B8C48;
extern s32 D_002B8C4C;
extern s32 D_33F610;
extern const char D_002E4150[];
extern const char D_002E41D0[];

struct Loc { void *ra; s32 m4; const char *name; };
struct Blk { void *m0; s32 m4; s32 m8; u32 mC; };
extern const Loc D_002E4208;
extern const Loc D_002E4230;
extern const Loc D_002E4250;
extern const Loc D_002E4278;
extern const Loc D_002E4298;
extern const Loc D_002E4300;
extern const Loc D_002E4320;
extern const Loc D_002E4348;
extern const Loc D_002E4398;
extern const char D_002E42A8[];
extern const char D_002E42C8[];
extern "C" void *func_0022B8D0(Loc *, s32);
extern "C" void *func_0022B920(Loc *, s32);
extern "C" void **func_0022AC30(void *, s32, s32);
extern "C" void **func_0022AAF8(void *, s32, s32);
extern "C" void func_00229EC8(Loc *, void **);
extern "C" void func_0022A3E0(Loc *, void **);
extern "C" void func_0022B5C8(const char *, ...);
extern "C" void func_0022B9F0(void *);
extern "C" void func_0022AF60(void);
extern "C" void *func_0022A070(Loc *, u32);
extern "C" void func_0022A128(Loc *, void *, u32);
extern "C" void func_0022A198(Loc *, void *, u32);
extern "C" u32 func_00229C78(u32);
#define SETRA(l) asm volatile("addiu $8, $31, -8\n\tsw $8, 0(%0)" : : "r"(&l) : "$8", "memory")

typedef __builtin_va_list va_list;
extern "C" s32 vsprintf(char *, const char *, va_list);
extern "C" void func_0022B6F0(char *);
extern "C" void func_0022B390(void);
extern "C" void func_0022B7C0(void);
extern "C" s32 func_0022A908(Loc *);
extern "C" void func_0022A540(Loc *, void **);
extern "C" void func_0022A638(Loc *, void **);
extern "C" Blk *func_0022BC70(Heap *, s32);
extern "C" s32 func_0022AD68(Blk *, s32);
extern const Loc D_002E43C0;
extern const Loc D_002E43E8;
extern const Loc D_002E4420;
extern const Loc D_002E4448;
extern const char D_002E43F8[];
extern const char D_002E4408[];
extern const char D_002E41B0[];
extern const char D_002E4458[];
inline s32 HeapOk(void) {
    if (!D_002B8C40->m0) {
        func_0022B5C8(D_002E41B0);
        D_33F610 = -2;
        return 0;
    }
    return 1;
}

struct HeapX { s32 m0; void *m4; s32 m8; s32 mC; s32 m10; s32 m14; s32 pad18[4]; u8 *m28; s32 m2C; };
struct Nd { void *m0; s32 m4; Nd *m8; HeapX *mC; };
struct Bk { Nd *m0; s32 m4; u32 m8; u32 mC; };
extern "C" Bk *func_0022BDF0(Heap *, s32);
extern "C" Nd *func_0022BF70(HeapX *);
extern "C" Bk *func_0022AE58(Bk *, u32);
extern "C" void func_0022B138(Heap *);
extern "C" void func_0022AF98(void);

struct HL;
struct NL { void *m0; NL *m4; NL *m8; HL *mC; };
struct HL { NL *m0; NL *m4; NL *m8; s32 mC; s32 m10; s32 m14; s32 pad18[4]; u8 *m28; u32 m2C; };
struct BL { NL *m0; s32 m4; u32 m8; u32 mC; };
extern "C" u32 strlen(const char *);
extern "C" s32 func_0022DD78(const char *, s32);
extern "C" void func_0022E0E8(s32, const char *, u32);
extern "C" void func_0022B660(const char *);
extern "C" s32 func_00273600(void);
extern "C" s32 func_0022B758(void);
extern "C" s32 func_0022B768(void);
extern "C" void func_00100000(void);
extern u8 D_4254AC[];
extern "C" void *func_00229D98(void *, s32);
extern "C" void *func_00229E50(void *, s32);
extern "C" void func_0022BBF8(HL *, NL *);
extern "C" void func_0022BFD0(NL *);
extern "C" u32 func_0022A7D8(void);
extern "C" s32 func_002293D0(void);
extern const char D_002E47B8[];
extern const char D_002E4478[];
s32 Func235DE0(const char *fmt, ...);
inline void Unlink(HL *h, NL *n) {
    NL *p;
    if ((p = n->m4)) p->m8 = n->m8;
    if ((p = n->m8)) p->m4 = n->m4;
    if (h->m4 == n) h->m4 = n->m8;
    if (h->m4) h->m4->m4 = 0;
    if (h->m8 == n) h->m8 = n->m4;
    if (h->m8) h->m8->m8 = 0;
    n->m8 = 0;
    n->m4 = 0;
    h->m14--;
}

#define EE_VA_START(ap, last) (ap = (char *)__builtin_next_arg(last) - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
extern "C" int vsprintf2(char *buf, const char *fmt, char *ap) asm("vsprintf");
// @decl-end

extern "C" u8 *func_00228F78(s32 i) {
    if (!D_002B8C28[TID]) return 0;
    func_00228658(D_002B8C28[TID]);
    if (!(i < D_33F608[TID])) return 0;
    return D_33F5E0[TID] + i * 32 + 0x10;
}

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_00229028);

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_00229300);

extern "C" s32 func_00229350(s32 v) {
    s32 old;
    func_001F1190();
    old = D_002B8C3C;
    D_002B8C3C = v;
    func_001F11C8();
    return old;
}

extern "C" s32 func_00229398(void) {
    func_001F1190();
    if (D_002B8C4C >= 0) func_0022DDE8(D_002B8C4C);
    return func_001F11C8();
}

extern "C" s32 func_002293D0(void) {
    s32 total = 0;
    Node *n = D_002B8C40->m4;
    if (D_002B8C44) return 0;
    func_001F1190();
    for (; n; n = n->m8) total += func_00229FB8(n->m0);
    func_001F11C8();
    return total;
}

extern "C" s32 func_00229448(void) {
    return D_002B8C40->m10;
}

extern "C" s32 func_00229458(u128 v) {
    Node *n = D_002B8C40->m4;
    u128 *p;
    u32 c;
    func_001F1190();
    for (; n; n = n->m8) {
        p = (u128 *)n->m0;
        c = (u32)func_00229FB8(p) >> 4;
        while (c) {
            c--;
            *p++ = v;
        }
    }
    return func_001F11C8();
}

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_002294E8);

extern "C" u32 func_002295C8(u32 base, u32 size, u32 n) {
    func_001F1190();
    base = (base + 0xF) & ~0xF;
    size -= size & 0xF;
    n = (n + 0xF) & ~0xF;
    if (D_002B8C3C & 5) func_0022B510(D_002E4150, base, size, n);
    func_002298A0((u8 *)base, size, 0);
    func_00229678(base, size, n);
    func_001F11C8();
    return base;
}

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_00229678);

extern "C" void *func_00229808(void *p) {
    if (p) func_00229888(p, func_00229FB8(p));
    return p;
}

extern "C" void **func_00229848(void **p) {
    if (p) func_00229888(*p, func_0022A4D0(p));
    return p;
}

extern "C" void func_00229888(void *p, u32 n) {
    return func_002298A0((u8 *)p, n, 0);
}

extern "C" void func_002298A0(u8 *p, u32 n, char c) {
    s32 k = 8 - ((u32)p & 7);
    u32 q;
    u64 v;
    u64 *d;
    if (k != 8) {
        n -= k;
        while (k--) *p++ = c;
    }
    if (n) {
        q = n >> 3;
        n &= 7;
        d = (u64 *)p;
        if (q) {
            v = (c << 8) | c;
            v |= v << 16;
            v |= v << 32;
            while (q--) *d++ = v;
        }
        p = (u8 *)d;
        while (n--) *p++ = c;
    }
}

extern "C" s32 func_00229988(u8 *a, u8 *b, u32 n) {
    u8 x, y;
    while (n--) {
        x = *a++;
        y = *b++;
        if (x < y) return -1;
        if (x > y) return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_002299E0);

extern "C" Heap *func_00229AF8(void) {
    return D_002B8C40;
}

extern "C" Heap *func_00229B08(Heap *h) {
    Heap *old;
    func_001F1190();
    old = D_002B8C40;
    if (old) {
        old->m30 = D_33F610;
        old->m34 = D_002B8C44;
        old->m38 = D_002B8C3C;
        old->m3C = D_002B8C4C;
    }
    D_002B8C40 = h;
    if (h && old) {
        D_33F610 = h->m30;
        D_002B8C44 = h->m34;
        D_002B8C3C = h->m38;
        D_002B8C4C = h->m3C;
    }
    func_001F11C8();
    return old;
}

extern "C" f32 func_00229BC0(f32 v) {
    f32 old = D_002B8C48;
    if (v < 0.5f) v = 0.5f;
    if (1.0f < v) v = 1.0f;
    D_002B8C48 = v;
    if (D_002B8C3C & 5) func_0022B510(D_002E41D0, (double)old, (double)v);
    return old;
}

extern "C" u32 func_00229C78(u32 n) {
    if (!n) n = (u32)(func_0022A7F0() * D_002B8C48);
    return n;
}

extern "C" void *func_00229D08(s32 x) {
    Loc l = D_002E4208;
    SETRA(l);
    return func_0022B8D0(&l, x);
}

extern "C" void *func_00229D50(s32 x, void *ra) {
    Loc l = D_002E4230;
    l.ra = ra;
    return func_0022B8D0(&l, x);
}

extern "C" void *func_00229D98(void *a, s32 b) {
    void **p = func_0022AC30(a, b, 0x20000000);
    if (p) return *p;
    return 0;
}

extern "C" void *func_00229DC0(s32 x) {
    Loc l = D_002E4250;
    SETRA(l);
    return func_0022B920(&l, x);
}

extern "C" void *func_00229E08(s32 x, void *ra) {
    Loc l = D_002E4278;
    l.ra = ra;
    return func_0022B920(&l, x);
}

extern "C" void *func_00229E50(void *a, s32 b) {
    void **p = func_0022AAF8(a, b, 0x20000000);
    if (p) return *p;
    return 0;
}

extern "C" void func_00229E78(void *p) {
    Loc l;
    void *q;
    q = p;
    l = D_002E4298;
    SETRA(l);
    func_00229EC8(&l, &q);
}

extern "C" void func_00229EC8(Loc *l, void **pp) {
    Blk *b;
    if (!*pp) return;
    if ((u32)*pp & 0xF) return func_0022B5C8(D_002E42A8, l->name, *pp);
    func_001F1190();
    b = (Blk *)((u8 *)*pp - 0x10);
    if (D_002B8C3C & 5) func_0022B510(D_002E42C8, l->name, b->m0, *pp, b->m8 - 0x10, l->ra, l->m4);
    func_0022B9F0(b->m0);
    if (D_002B8C3C & 0xA) func_0022AF60();
    return (void)func_001F11C8();
}

extern "C" s32 func_00229FB8(void *p) {
    return ((s32 *)p)[-2] - 0x10;
}

extern "C" u32 func_00229FC8(void *p) {
    u32 s = ((u32 *)p)[-1] & 0xFFFFFFF;
    if (!s) s = func_00229FB8(p);
    return s;
}

extern "C" void *func_0022A000(u32 n) {
    Loc l = D_002E4300;
    void *r;
    SETRA(l);
    func_001F1190();
    r = func_0022A070(&l, func_00229C78(n));
    func_001F11C8();
    return r;
}

extern "C" void *func_0022A070(Loc *l, u32 n) {
    return func_0022AC30(l, n, 0);
}

extern "C" void func_0022A088(void *p, u32 n) {
    Loc l = D_002E4320;
    SETRA(l);
    func_0022A128(&l, p, n);
}

extern "C" void func_0022A0D8(void *p, u32 n) {
    Loc l = D_002E4348;
    SETRA(l);
    func_0022A198(&l, p, n);
}

extern "C" void func_0022A128(Loc *l, void *p, u32 n) {
    if (func_00229FB8(p) >= n) return func_0022A198(l, ((void **)p)[-4], n);
}

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_0022A198);

extern "C" void func_0022A390(void *p) {
    Loc l;
    void *q;
    q = p;
    l = D_002E4398;
    SETRA(l);
    func_0022A3E0(&l, &q);
}

extern "C" void func_0022A3E0(Loc *l, void **pp) {
    Blk *b;
    if (!*pp) return;
    if ((u32)*pp & 0xF) return func_0022B5C8(D_002E42A8, l->name, *pp);
    func_001F1190();
    b = (Blk *)(*(u8 **)*pp - 0x10);
    if (D_002B8C3C & 5) func_0022B510(D_002E42C8, l->name, *pp, *(void **)*pp, b->m8 - 0x10, l->ra, l->m4);
    func_0022B9F0(b->m0);
    if (D_002B8C3C & 0xA) func_0022AF60();
    return (void)func_001F11C8();
}

extern "C" s32 func_0022A4D0(void *pp) {
    return ((s32 *)*(void **)pp)[-2] - 0x10;
}

extern "C" u32 func_0022A4E0(void **pp) {
    return ((u32 *)*pp)[-1] & 0xFFFFFFF;
}

extern "C" void func_0022A4F8(void **pp) {
    Loc l = D_002E43C0;
    SETRA(l);
    func_0022A540(&l, pp);
}

extern "C" void func_0022A540(Loc *l, void **pp) {
    Blk *b;
    func_001F1190();
    b = (Blk *)((u8 *)*pp - 0x10);
    b->mC |= 0x20000000;
    if (l->name) {
        if (D_002B8C3C & 5) func_0022B510(D_002E42C8, l->name, pp, *pp, b->m8 - 0x10, l->ra, l->m4);
        if (D_002B8C3C & 2) func_0022B390();
    }
    return (void)func_001F11C8();
}

extern "C" void func_0022A5F0(void **pp) {
    Loc l = D_002E43E8;
    SETRA(l);
    func_0022A638(&l, pp);
}

extern "C" void func_0022A638(Loc *l, void **pp) {
    Blk *b;
    func_001F1190();
    b = (Blk *)((u8 *)*pp - 0x10);
    b->mC &= ~0x20000000;
    if (l->name) {
        if (D_002B8C3C & 5) func_0022B510(D_002E42C8, l->name, pp, *pp, b->m8 - 0x10, l->ra, l->m4);
        if (D_002B8C3C & 2) func_0022B390();
    }
    return (void)func_001F11C8();
}

extern "C" s32 func_0022A6E8(void) {
    func_001F1190();
    func_0022B5C8(D_002E43F8);
    return func_001F11C8();
}

extern "C" s32 func_0022A710(s32 x) {
    func_001F1190();
    if (D_002B8C3C & 5) func_0022B510(D_002E4408, x);
    return func_001F11C8();
}

extern "C" void func_0022A758(const char *fmt, ...) { char buf[0x100]; char *ap; EE_VA_START(ap, fmt); vsprintf2(buf + 2, fmt, ap); buf[0] = '!'; buf[1] = '-'; func_0022B6F0(buf); }

extern "C" u32 func_0022A7D8(void) {
    return func_0022A7F0();
}

extern "C" u32 func_0022A7F0(void) {
    s32 best = 0, s;
    Node *n = D_002B8C40->m4;
    if (D_002B8C44) return 0;
    func_001F1190();
    for (; n; n = n->m8) {
        s = ((s32 *)n->m0)[-2] - 0x10;
        if (best < s) best = s;
    }
    func_001F11C8();
    return best;
}

extern "C" s32 func_0022A870(void) {
    Loc l = D_002E4420;
    SETRA(l);
    return func_0022A908(&l);
}

extern "C" void func_0022A8B8(void) {
}

extern "C" void func_0022A8C0(void) {
}

extern "C" void func_0022A8C8(void) {
    Loc l = D_002E4448;
    SETRA(l);
    func_0022B7C0();
}

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_0022A908);

extern "C" s32 func_0022AAE8(void) {
    return D_33F610;
}

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_0022AAF8);

extern "C" void **func_0022AC30(void *vl, s32 n, s32 tag) {
    Loc *l = (Loc *)vl;
    Bk *b;
    if (!HeapOk()) return 0;
    b = func_0022BDF0(D_002B8C40, n);
    if (!b) {
        func_0022B5C8(D_002E4458, l->name, n);
        D_33F610 = -1;
        return 0;
    }
    b->mC = tag | 0x40000000;
    b = func_0022AE58(b, (n + 0x1F) & ~0xF);
    if (D_002B8C3C & 5) func_0022B510(D_002E42C8, l->name, b->m0, *(void **)b->m0, n, l->ra, l->m4);
    if (D_002B8C3C & 0xA) func_0022AF60();
    return (void **)b->m0;
}

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_0022AD68);

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_0022AE58);

extern "C" void func_0022AF60(void) {
    if (D_002B8C3C & 8) func_0022B138(D_002B8C40);
    func_0022AF98();
    return func_0022B390();
}

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_0022AF98);

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_0022B138);

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_0022B390);

extern "C" void func_0022B510(const char *fmt, ...) { char buf[0x100]; char *ap; EE_VA_START(ap, fmt); vsprintf2(buf, fmt, ap); func_001F1190(); if (D_002B8C3C & 4) func_0022B660(buf); if (D_002B8C3C & 1) Func235DE0(buf); func_001F11C8(); }

extern "C" void func_0022B5C8(const char *fmt, ...) { char buf[0x100]; char *ap; EE_VA_START(ap, fmt); vsprintf2(buf, fmt, ap); func_001F1190(); if (D_002B8C3C & 4) func_0022B660(buf); Func235DE0(buf); func_001F11C8(); }

extern "C" void func_0022B660(const char *s) {
    s32 fd = D_002B8C4C;
    if (fd == -1) fd = D_002B8C4C = func_0022DD78(D_002E47B8, 0x602);
    if (fd < 0) return;
    return func_0022E0E8(fd, s, strlen(s));
}

extern "C" void func_0022B6F0(char *s) {
    func_001F1190();
    if (D_002B8C3C & 4) func_0022B660(s);
    if (D_002B8C3C & 1) Func235DE0(s);
    return (void)func_001F11C8();
}

extern "C" s32 func_0022B758(void) {
    return (s32)func_00100000;
}

extern "C" s32 func_0022B768(void) {
    return (s32)D_4254AC;
}

extern "C" s32 func_0022B778(void) {
    s32 a = func_00273600();
    s32 b = func_0022B768();
    s32 c = func_0022B758();
    return a - b - c;
}

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_0022B7C0);

extern "C" void *func_0022B8D0(Loc *l, s32 n) {
    void *r;
    func_001F1190();
    r = func_00229D98(l, func_00229C78(n));
    func_001F11C8();
    return r;
}

extern "C" void *func_0022B920(Loc *l, s32 n) {
    void *r;
    func_001F1190();
    r = func_00229E50(l, func_00229C78(n));
    func_001F11C8();
    return r;
}

extern "C" void func_0022B970(BL *b, BL *nx) {
    NL *x = nx->m0;
    HL *h = x->mC;
    BL *nn;
    b->m8 += nx->m8;
    func_0022BBF8(h, x);
    func_0022BFD0(x);
    nn = (BL *)((u8 *)b + b->m8);
    if ((u8 *)nn < h->m28 + h->m2C) nn->m4 = b->m8;
}

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_0022B9F0);

extern "C" void func_0022BB88(HL *h, NL *n) {
    n->m4 = 0;
    n->m8 = h->m4;
    if (h->m4) h->m4->m4 = n;
    h->m4 = n;
    if (!h->m8) h->m8 = n;
    h->m14++;
}

extern "C" void func_0022BBC0(HL *h, NL *n) {
    n->m4 = h->m8;
    n->m8 = 0;
    if (h->m8) h->m8->m8 = n;
    h->m8 = n;
    if (!h->m4) h->m4 = n;
    h->m14++;
}

extern "C" void func_0022BBF8(HL *h, NL *n) {
    NL *p;
    if ((p = n->m4)) p->m8 = n->m8;
    if ((p = n->m8)) p->m4 = n->m4;
    if (h->m4 == n) h->m4 = n->m8;
    if (h->m4) h->m4->m4 = 0;
    if (h->m8 == n) h->m8 = n->m4;
    if (h->m8) h->m8->m8 = 0;
    n->m8 = 0;
    n->m4 = 0;
    h->m14--;
}

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_0022BC70);

INCLUDE_ASM("asm/nonmatchings/Unit228F78", func_0022BDF0);

extern "C" Nd *func_0022BF70(HeapX *hh) {
    HL *h = (HL *)hh;
    NL *x = h->m0;
    NL *nx;
    if (!x) {
        func_0022B5C8(D_002E41B0);
        D_33F610 = -2;
        return 0;
    }
    nx = x->m8;
    h->m0 = nx;
    if (nx) nx->m4 = 0;
    h->m10--;
    return (Nd *)x;
}
