#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct CVec4 { f32 x; f32 y; f32 z; f32 w; };
void Func270C50(CVec4 *dst, const CVec4 *src);
struct Work3 { Work3 *next; Work3 *parent; u8 m8; u8 m9; u8 mA; u8 mB; u8 padC[0xC]; u8 m18; u8 m19; u8 pad1A[6]; CVec4 m20; CVec4 m30; CVec4 m40; CVec4 m50; f32 m60; f32 m64; };
struct S338350 { f32 m0; s32 pad4[3]; CVec4 a; CVec4 b; s32 flag; };
extern S338350 D_338350;
extern CVec4 D_338360;
extern CVec4 D_338370;
extern s32 D_338380;
extern u8 D_002A62D8[];
extern u8 D_002A63D8[];
extern "C" Work3 *func_00215010(void);
extern "C" void func_00219110(CVec4 *, CVec4 *, CVec4 *, CVec4 *);
extern "C" void func_00219290(CVec4 *, CVec4 *, CVec4 *, CVec4 *);
extern "C" f32 func_002186B0(void *, void *, CVec4 *, void *, void *, s32, f32, f32, f32);
extern "C" f32 func_00218AD0(void *, void *, void *, void *, f32, f32, f32, void *, void *, s32);
extern "C" f32 func_00218B70(void *, void *, void *, void *, f32, f32, f32, void *, void *, s32);
inline void Zero3(CVec4 *v) { v->x = 0.0f; v->y = 0.0f; v->z = 0.0f; }
struct Rec3 { u8 pad[0x20]; s32 m20; };

extern "C" int strcmp(const char *, const char *);
struct Rec4 { s16 m0; u8 m2; u8 m3; const char *m4; };
struct S338390 { Rec4 **tbl; s32 n; };
extern S338390 D_338390;
extern const char D_002E39F0[];
extern const char D_002E3A28[];
typedef void *(*Fn67E8)(Rec4 *, s32, s32);
extern Fn67E8 D_002A67E8[];
extern "C" void func_00212B30(void *);
extern "C" void *func_00212AE0(s32);
extern "C" s32 func_00212918(void);
void Func235DE0(const char *, ...);
extern "C" Rec4 *func_00219B68(s32);
extern "C" s32 func_00219BA8(s32);
extern "C" s32 func_00219C78(s32, s32, s32, s32);
extern "C" s32 func_00219E48(s32);
extern "C" void func_00219E90(s32);
extern "C" void func_00219F48(s32);
extern "C" void func_0021A380(s32, s32);

struct CbMsg5 { s32 kind; void *work; s32 id; const char *val; s32 ret; };
struct PlayR { s16 m0; };
struct PlayX { void *m0; void *m4; PlayR *m8; };
extern "C" PlayX *func_0020F858(s32);
extern "C" s32 func_0020F948(s32);
extern "C" s32 func_0020F998(s32);
extern "C" const char *func_0020E668(s32, s32, s32);
extern "C" void func_00212A30(void *);

extern "C" void func_00270A98(CVec4 *d, const CVec4 *a, const CVec4 *b);
inline f32 VuSqrt217(f32 x) { f32 r; asm volatile("mfc1 $8, %1\n\tqmtc2.ni $8, $vf2\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "f"(x) : "$8"); return r; }

inline f32 VuDot3_217(CVec4 *a, CVec4 *b) {
    f32 r;
    asm volatile("lqc2 $vf2, 0x0(%1)\n\tlqc2 $vf3, 0x0(%2)\n\tvmul.xyz $vf3, $vf2, $vf3\n\tvaddy.x $vf3, $vf3, $vf3y\n\tvaddz.x $vf3, $vf3, $vf3z\n\tqmfc2.ni $8, $vf3\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8");
    return r;
}
extern "C" void func_00270B68(CVec4 *d, const CVec4 *a, f32 s);

inline f32 VuDot3_217b(CVec4 *a, CVec4 *b) {
    f32 r;
    asm volatile("lqc2 $vf2, 0x0(%1)\n\tlqc2 $vf3, 0x0(%2)\n\tvmul.xyz $vf3, $vf2, $vf3\n\tvaddy.x $vf3, $vf3, $vf3y\n\tvaddz.x $vf3, $vf3, $vf3z\n\tqmfc2.ni $8, $vf3\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8");
    return r;
}
extern "C" void func_00270A30(CVec4 *d, const CVec4 *a, const CVec4 *b);

struct P217 { u8 pad[0xC]; u16 mC; s16 mE; void *m10; void *m14; f32 m18; f32 m1C; };
// @decl-end

extern "C" s32 func_00217F50(s32 strm, s32 x) {
    CbMsg5 m;
    PlayX *e = func_0020F858(strm);
    s32 bank;
    m.kind = 1;
    m.work = e->m4;
    m.id = e->m8->m0;
    bank = func_0020F948(strm);
    m.val = func_0020E668(bank, func_0020F998(strm), x);
    m.ret = 1;
    func_00212A30(&m);
    return m.ret;
}

INCLUDE_ASM("asm/nonmatchings/Unit217F50", func_00217FE8);

extern "C" s32 func_002183D8(Rec3 *p, s32 *out, s32 n) {
    if (n > 0) out[0] = p->m20;
    return 1;
}

extern "C" void func_002183F0(f32 v) {
    D_338350.m0 = v;
}

extern "C" void func_00218400(CVec4 *v) {
    func_00215010()->m9 |= 0x14;
    Func270C50(&D_338350.a, v);
    D_338350.flag = 1;
}

extern "C" void func_00218458(CVec4 *out) {
    Func270C50(out, &D_338360);
    return;
}

extern "C" void func_00218478(CVec4 *v) {
    func_00215010()->m9 |= 0x14;
    Func270C50(&D_338350.b, v);
    D_338350.flag = 1;
}

extern "C" void func_002184D0(CVec4 *out) {
    Func270C50(out, &D_338370);
    return;
}

extern "C" void func_002184F0(Work3 *w, CVec4 *v) {
    CVec4 d;
    w->m18 = 1;
    w->m9 |= 0x14;
    Func270C50(&w->m20, v);
    w->m64 = w->m60;
    func_00270A98(&d, v, &D_338360);
    w->m60 = w->m60 + (VuSqrt217(d.x * d.x + d.y * d.y + d.z * d.z) - w->m64) * 0.5f;
}

extern "C" void func_002185B0(Work3 *w, CVec4 *a, CVec4 *b) {
    w->m18 = 2;
    w->m9 |= 0x14;
    Func270C50(&w->m20, a);
    Func270C50(&w->m30, b);
    return;
}

extern "C" void func_00218600(Work3 *w, CVec4 *a, CVec4 *b) {
    w->m18 = 3;
    w->m9 |= 0x14;
    Func270C50(&w->m20, a);
    Func270C50(&w->m30, b);
    return;
}

extern "C" void func_00218650(Work3 *w, CVec4 *v) {
    w->m19 = 1;
    w->m9 |= 0x14;
    Func270C50(&w->m40, v);
    return;
}

extern "C" void func_00218680(Work3 *w, CVec4 *v) {
    w->m19 = 1;
    w->m9 |= 0x14;
    Func270C50(&w->m50, v);
    return;
}

INCLUDE_ASM("asm/nonmatchings/Unit217F50", func_002186B0);

INCLUDE_ASM("asm/nonmatchings/Unit217F50", func_00218AD0);

INCLUDE_ASM("asm/nonmatchings/Unit217F50", func_00218B70);

extern "C" void func_00218C10(void *a, void *b, CVec4 *c, f32 f, f32 g) {
    func_002186B0(a, b, c, D_002A62D8, D_002A63D8, 0xC, f, g, 0.0f);
    return;
}

extern "C" void func_00218C40(void *a, void *b, CVec4 *c, f32 f, f32 g) {
    func_002186B0(a, b, c, D_002A62D8, D_002A63D8, 0x1C, f, g, 0.0f);
    return;
}

extern "C" void func_00218C70(void *a, void *b, CVec4 *c, f32 f, f32 g, f32 h) {
    func_002186B0(a, b, c, D_002A62D8, D_002A63D8, 0xC, f, g, h);
    return;
}

extern "C" void func_00218C98(void *a, void *b, CVec4 *c, f32 f, f32 g, f32 h) {
    func_002186B0(a, b, c, D_002A62D8, D_002A63D8, 0x1C, f, g, h);
    return;
}

extern "C" void func_00218CC0(void *a, void *b, void *c, void *d, f32 f, f32 g) {
    func_00218AD0(a, b, c, d, f, g, 0.0f, D_002A62D8, D_002A63D8, 0xC);
    return;
}

extern "C" void func_00218CF0(void *a, void *b, void *c, void *d, f32 f, f32 g) {
    func_00218AD0(a, b, c, d, f, g, 0.0f, D_002A62D8, D_002A63D8, 0x1C);
    return;
}

extern "C" void func_00218D20(void *a, void *b, void *c, void *d, f32 f, f32 g, f32 h) {
    func_00218AD0(a, b, c, d, f, g, h, D_002A62D8, D_002A63D8, 0xC);
    return;
}

extern "C" void func_00218D48(void *a, void *b, void *c, void *d, f32 f, f32 g, f32 h) {
    func_00218AD0(a, b, c, d, f, g, h, D_002A62D8, D_002A63D8, 0x1C);
    return;
}

extern "C" void func_00218D70(void *a, void *b, void *c, void *d, f32 f, f32 g) {
    func_00218B70(a, b, c, d, f, g, 0.0f, D_002A62D8, D_002A63D8, 0xC);
    return;
}

extern "C" void func_00218DA0(void *a, void *b, void *c, void *d, f32 f, f32 g) {
    func_00218B70(a, b, c, d, f, g, 0.0f, D_002A62D8, D_002A63D8, 0x1C);
    return;
}

extern "C" void func_00218DD0(void *a, void *b, void *c, void *d, f32 f, f32 g, f32 h) {
    func_00218B70(a, b, c, d, f, g, h, D_002A62D8, D_002A63D8, 0xC);
    return;
}

extern "C" void func_00218DF8(void *a, void *b, void *c, void *d, f32 f, f32 g, f32 h) {
    func_00218B70(a, b, c, d, f, g, h, D_002A62D8, D_002A63D8, 0x1C);
    return;
}

extern "C" void func_00218E20(void) {
    D_338350.m0 = 1.0f;
    Zero3(&D_338350.a);
    Zero3(&D_338350.b);
    D_338350.flag = 0;
}

extern "C" void func_00218E60(void) {
}

extern "C" void func_00218E68(void) {
}

extern "C" f32 func_00218E70(s32 *outA, s32 *outB, Work3 *o, P217 *p, f32 f) {
    CVec4 s0, s1;
    Work3 *n;
    s32 found;
    void *t1, *t2;
    Func270C50(&s0, &D_338350.a);
    Func270C50(&s1, &D_338350.b);
    found = D_338350.flag;
    for (n = o->parent; n; n = n->parent) {
        if (n->m19) {
            Func270C50(&D_338350.a, &n->m40);
            Func270C50(&D_338350.b, &n->m50);
            found = 1;
            break;
        }
    }
    if (found) {
        t1 = p->m10;
        if (!t1) t1 = D_002A62D8;
        t2 = p->m14;
        if (!t2) t2 = D_002A63D8;
        switch (o->m18) {
        case 0:
            *outA = 0x80;
            *outB = 0x80;
            break;
        case 1:
            f = ((f32 (*)(void *, void *, CVec4 *, f32, f32, f32, void *, void *, s32))func_002186B0)(outA, outB, &o->m20, p->m18, p->m1C, f, t1, t2, p->mC);
            break;
        case 2:
            f = func_00218AD0(outA, outB, &o->m20, &o->m30, p->m18, p->m1C, f, t1, t2, p->mC);
            break;
        case 3:
            f = func_00218B70(outA, outB, &o->m20, &o->m30, p->m18, p->m1C, f, t1, t2, p->mC);
            break;
        }
    } else {
        *outA = 0;
        *outB = 0;
    }
    Func270C50(&D_338350.a, &s0);
    Func270C50(&D_338350.b, &s1);
    return f;
}

extern "C" f32 func_00219078(Work3 *w) {
    f32 v;
    f32 d;
    switch (w->m18) {
    case 1:
        d = (w->m60 - w->m64) * D_338350.m0;
        v = 0.0f;
        if (-340.0f < d) v = 340.0f / (d + 340.0f);
        break;
    case 0:
    case 2:
    case 3:
        v = 1.0f;
        break;
    default:
        v = 1.0f;
        break;
    }
    return v < 0.01f ? 0.01f : v;
}

extern "C" void func_00219110(CVec4 *out, CVec4 *a, CVec4 *b, CVec4 *c) {
    CVec4 d, e;
    f32 len, t;
    s32 eq = 0;
    if (b->x == c->x && b->y == c->y && b->z == c->z) eq = 1;
    if (!eq) {
        func_00270A98(&d, a, b);
        func_00270A98(&e, c, b);
        len = VuSqrt217(e.x * e.x + e.y * e.y + e.z * e.z);
        t = VuDot3_217b(&d, &e) / (len * len);
        if (t < 0.0f) {
            Func270C50(out, b);
        } else if (!(t < 1.0f)) {
            Func270C50(out, c);
        } else {
            func_00270B68(out, &e, t);
            func_00270A30(out, out, b);
        }
    } else {
        Func270C50(out, b);
    }
}

extern "C" void func_00219290(CVec4 *out, CVec4 *a, CVec4 *b, CVec4 *c) {
    CVec4 d, e;
    f32 len, dot;
    func_00270A98(&d, a, b);
    Func270C50(&e, c);
    len = VuSqrt217(e.x * e.x + e.y * e.y + e.z * e.z);
    dot = VuDot3_217(&d, &e);
    func_00270B68(out, c, dot / (len * len));
    func_00270A98(out, a, out);
}

extern "C" s32 func_00219368(s32 n) {
    s32 i;
    if (D_338390.tbl) {
        func_00212B30(D_338390.tbl);
        D_338390.tbl = 0;
    }
    if (n > 0) {
        D_338390.tbl = (Rec4 **)func_00212AE0(n * 4);
        if (D_338390.tbl == 0) {
            if (func_00212918() & 2) Func235DE0(D_002E39F0);
            return 0;
        }
    }
    D_338390.n = n;
    for (i = 0; i < n; i++) D_338390.tbl[i] = 0;
    return 1;
}

extern "C" void func_00219430(Rec4 *p) {
    s32 k;
    for (; p->m3; p = (Rec4 *)((u8 *)p + p->m3)) {
        k = p->m0;
        if (k >= 0 && !(D_338390.n - 1 < k)) D_338390.tbl[k] = p;
    }
}

extern "C" Rec4 *func_00219490(s32 i) {
    return func_00219B68(i);
}

extern "C" const char *func_002194A8(s32 i) {
    Rec4 *p = func_00219B68(i);
    return p ? p->m4 : D_002E3A28;
}

extern "C" s32 func_002194D8(s32 i) { Rec4 *p = func_00219B68(i); if (p) return p->m2; return -1; }

extern "C" s32 func_00219508(const char *name) {
    s32 i;
    Rec4 *p;
    for (i = 0; i < D_338390.n; i++) {
        p = func_00219B68(i);
        if (p || !strcmp(p->m4, name)) return i;
    }
    return -1;
}

extern "C" s32 func_00219590(s32 a, s32 b) {
    func_00219BA8(0);
    return func_00219C78(0, 0, a, b);
}

extern "C" s32 func_002195D8(s32 a, s32 b) {
    func_00219BA8(1);
    return func_00219C78(1, 0, a, b);
}

extern "C" s32 func_00219620(s32 a, s32 b) {
    func_00219BA8(2);
    return func_00219C78(2, 0, a, b);
}

extern "C" s32 func_00219668(s32 a, s32 b) {
    return func_00219C78(0, func_00219E48(0), a, b);
}

extern "C" s32 func_002196B0(s32 a, s32 b) {
    return func_00219C78(1, func_00219E48(1), a, b);
}

extern "C" s32 func_002196F8(s32 a, s32 b) {
    return func_00219C78(2, func_00219E48(2), a, b);
}

extern "C" void func_00219740(s32 a) {
    func_00219E90(a);
    return;
}

extern "C" void func_00219758(s32 a) {
    func_00219E90(a);
    return;
}

extern "C" void func_00219770(s32 a) {
    func_00219E90(a);
    return;
}

extern "C" void func_00219788(s32 a) {
    func_00219F48(a);
    return;
}

extern "C" void func_002197A0(s32 a) {
    func_00219F48(a);
    return;
}

extern "C" void func_002197B8(s32 a) {
    func_00219F48(a);
    return;
}

extern "C" s32 func_002197D0(void) {
    return func_00219BA8(0);
}

extern "C" s32 func_002197E8(void) {
    return func_00219BA8(1);
}

extern "C" s32 func_00219800(void) {
    return func_00219BA8(2);
}

INCLUDE_ASM("asm/nonmatchings/Unit217F50", func_00219818);

INCLUDE_ASM("asm/nonmatchings/Unit217F50", func_00219880);

INCLUDE_ASM("asm/nonmatchings/Unit217F50", func_002198E8);

extern "C" void func_00219950(s32 a) {
    func_0021A380(2, a);
    return;
}
