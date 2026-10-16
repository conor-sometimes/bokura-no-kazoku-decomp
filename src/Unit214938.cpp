#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct QNode;
struct QOps { s32 (*init)(QNode *); void (*cancel)(QNode *); s32 (*poll)(QNode *); };
struct QNode { QNode *next; QNode *prev; QOps ops; s32 m14; s32 m18; };
struct QHead { QNode *next; QNode *prev; };
extern QHead D_336E98;
struct Work { Work *next; Work *parent; u8 m8; u8 m9; u8 mA; u8 mB; s16 mC; s16 mE; f32 m10; f32 m14; u8 m18; u8 m19; u8 pad1A[0x68 - 0x1A]; s32 m68; Work *child; u8 m70[16]; };
extern Work D_336EC0;
extern "C" void *func_00212AE0(s32);
extern "C" void func_00212B30(void *);
extern "C" s32 func_00212918(void);
extern "C" void func_00212A60(const char *);
void Func235DE0(const char *, ...);
extern const char D_002E3848[];
extern const char D_002E3870[];
extern const char D_002E3890[];
extern const char D_002E38C0[];
extern "C" void func_00214B18(QNode *);
extern "C" void func_00214BB8(void);
extern "C" void func_00214C28(Work *, Work *);
extern "C" void func_00214DD8(Work *);
extern "C" void func_00215588(Work *, s32);
extern "C" void func_00215078(Work *, s32);

extern "C" int strcmp(const char *, const char *);
struct Rec2 { s16 m0; u8 m2; u8 m3; const char *m4; Rec2 *m8; };
struct Arg3 { s32 id; u8 a; u8 pad[3]; u8 b; };
struct ArgH { s32 id; u16 a; u16 b; };
struct POps { s32 (*f0)(void *); void (*f4)(void *); s32 (*f8)(void *); s32 (*fC)(Rec2 *, s32, s32); };
struct PSlot { s16 used; s16 h; POps ops; };
struct S336F40 { Rec2 **tbl; s32 n; PSlot slots[256]; s32 m1408; };
extern S336F40 D_336F40;
struct Play { Play *next; Work *m4; Rec2 *m8; u8 mC; u8 mD; u8 mE; u8 mF; u8 m10; u8 m11; u8 m12; u8 m13; u16 m14; u16 m16; s32 m18; f32 m1C; f32 m20; s32 m24; };
extern const char D_002E38D8[];
extern const char D_002E3910[];
extern const char D_002E3928[];
extern const char D_002E3918[];
extern "C" void func_00215F40(Work *, s32);
extern "C" void func_00215F80(Work *, s32);
extern "C" Rec2 *func_00215FC0(s32);
extern "C" POps *func_00216000(s32);
extern "C" void func_00216100(s32, s32, s32);
extern "C" void func_00215988(Play *);
extern "C" void func_002163B0(void *, void *, void *);
extern "C" void func_002160A8(Work *);
extern "C" void *func_00216368(void);
extern "C" s32 func_00216048(void *);
extern "C" void func_00216050(void);
extern "C" void func_00216058(void);
extern "C" s32 func_00216060(Rec2 *, s32, s32);
extern "C" void func_002154D0(Play *, s32 *);
extern "C" void func_00215570(Play *, s32);
extern "C" void func_00215658(Play *, s32 *);
extern "C" void func_002156C8(Play *, s32 *);
extern "C" void func_00215730(Play *, s32 *);
extern "C" void func_002157A0(Play *, s32 *);
extern "C" void func_00215808(Play *, s32 *);
extern "C" void func_00215870(Play *, s32 *);

struct PlayBits { u8 pad[0xE]; u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 rest : 5; };
// @decl-end
INCLUDE_RODATA("asm/nonmatchings/Unit214938", D_002E3848);
INCLUDE_RODATA("asm/nonmatchings/Unit214938", D_002E3870);
INCLUDE_RODATA("asm/nonmatchings/Unit214938", D_002E3890);
INCLUDE_RODATA("asm/nonmatchings/Unit214938", D_002E38C0);
INCLUDE_RODATA("asm/nonmatchings/Unit214938", D_002E38D8);
INCLUDE_RODATA("asm/nonmatchings/Unit214938", D_002E3910);
INCLUDE_RODATA("asm/nonmatchings/Unit214938", D_002E3918);
INCLUDE_RODATA("asm/nonmatchings/Unit214938", D_002E3928);

extern "C" void func_00214938(void) {
    QNode *h = (QNode *)&D_336E98;
    h->next = h;
    h->prev = h;
    h->m14 = 0;
    h->m18 = 0;
}

extern "C" void func_00214958(void) {
    QNode *n;
    while ((n = D_336E98.prev) != (QNode *)&D_336E98) {
        n->next->prev = n->prev;
        n->prev->next = n->next;
        func_00212B30(n);
    }
}

extern "C" void func_002149B8(void) {
    QNode *n;
    for (n = D_336E98.prev; n != (QNode *)&D_336E98; n = n->prev) {
        if (n->m14 == 0 && n->ops.poll(n) == 1) func_00214B18(n);
    }
    func_00214BB8();
    return;
}

extern "C" QNode *func_00214A30(QOps *ops, s32 size, s32 owner) {
    QNode *n = (QNode *)func_00212AE0(size);
    if (n == 0) {
        if (func_00212918() & 2) Func235DE0(D_002E3848);
        goto fail;
    }
    n->m18 = 0;
    n->ops = *ops;
    n->m18 = owner;
    n->m14 = 0;
    n->ops.init(n);
    n->next = D_336E98.next;
    n->prev = (QNode *)&D_336E98;
    n->next->prev = n;
    n->prev->next = n;
    return n;
fail:
    if (n) func_00212B30(n);
    return 0;
}

extern "C" void func_00214B18(QNode *n) {
    if (n->m14 != 1) {
        n->m14 = 1;
        n->ops.cancel(n);
    }
}

extern "C" void func_00214B50(s32 owner) {
    QNode *n;
    for (n = D_336E98.prev; n != (QNode *)&D_336E98; n = n->prev) {
        if (n->m18 == owner) func_00214B18(n);
    }
    func_00214BB8();
    return;
}

extern "C" void func_00214BB8(void) {
    QNode *n;
    QNode *c;
    n = D_336E98.prev;
    while ((c = n) != (QNode *)&D_336E98) {
        n = n->prev;
        if (c->m14) {
            c->next->prev = n;
            c->prev->next = c->next;
            func_00212B30(c);
        }
    }
}

extern "C" void func_00214C28(Work *parent, Work *w) {
    s32 i;
    if (!parent) parent = &D_336EC0;
    w->next = parent->child;
    parent->child = w;
    w->parent = parent;
    w->m8 = 0;
    w->m9 = 0;
    w->mA = 0;
    w->mB = 0;
    w->mC = 0x80;
    w->m10 = 1.0f;
    w->m18 = 0;
    w->mE = 0x80;
    w->m19 = 0;
    w->m68 = 0;
    w->m14 = 1.0f;
    w->child = 0;
    for (i = 0; i < 16; i++) w->m70[i] = 0x80;
}

extern "C" Work *func_00214CB8(Work *parent) {
    Work *w = (Work *)func_00212AE0(0x80);
    if (!w) {
        if (func_00212918() & 2) Func235DE0(D_002E3870);
        return 0;
    }
    func_00214C28(parent, w);
    w->m8 = 1;
    return w;
}

extern "C" Work *func_00214D38(Work *sib) {
    Work *w;
    if (!sib->parent) {
        if (func_00212918() & 1) Func235DE0(D_002E3890);
        return 0;
    }
    w = (Work *)func_00212AE0(0x80);
    if (!w) {
        if (func_00212918() & 2) Func235DE0(D_002E3870);
        return 0;
    }
    func_00214C28(sib->parent, w);
    w->m8 = 1;
    return w;
}

extern "C" void func_00214DD8(Work *w) {
    Work **pp = &w->parent->child;
    Work *c;
    Work *x;
    if (!w->parent) return;
    func_00212A60(D_002E38C0);
    for (c = *pp; c; c = c->next) {
        if (c == w) {
            func_00215588(c, 0);
            while ((x = c->child) != 0) func_00214DD8(x);
            *pp = c->next;
            c->next = 0;
            c->parent = 0;
            if (c->m8) func_00212B30(c);
            return;
        }
        pp = &c->next;
    }
}

extern "C" void func_00214EA0(Work *w, s32 x) {
    func_00215588(w, x);
    return;
}

extern "C" void func_00214EB8(Work *w, s32 v, s32 x) {
    w->mA = v;
    w->m9 |= 1;
    func_00215078(w, x);
    return;
}

extern "C" void func_00214EE8(Work *w, s32 v) {
    w->mB = v;
    w->m9 |= 2;
}

extern "C" void func_00214F00(Work *w, s32 a, s32 b) {
    w->mC = a;
    w->mE = b;
    w->m9 |= 4;
}

extern "C" void func_00214F18(Work *w, f32 v) {
    w->m10 = v;
    w->m9 |= 0x10;
}

extern "C" void func_00214F30(Work *w, f32 v) {
    w->m14 = v;
    w->m9 |= 0x20;
}

extern "C" void func_00214F48(Work *w, u32 k, s32 v) {
    if (k < 16) {
        w->m70[k] = v;
        w->m9 |= 8;
    }
}

extern "C" void func_00214F70(void) {
    Work *w = &D_336EC0;
    w->next = 0;
    w->parent = 0;
    w->m8 = 0;
    w->m9 = 0;
    w->mA = 0;
    w->mB = 0;
    w->mC = 0x80;
    w->m10 = 1.0f;
    w->m18 = 0;
    w->mE = 0x80;
    w->m19 = 0;
    w->m68 = 0;
    w->m14 = 1.0f;
    w->child = 0;
}

extern "C" void func_00214FC0(void) {
    Work *c;
    while ((c = D_336EC0.child) != 0) func_00214DD8(c);
}

extern "C" void func_00215008(void) {
}

extern "C" Work *func_00215010(void) {
    return &D_336EC0;
}

extern "C" void func_00215020(Work *w, s32 x) {
    Work *c;
    func_00215F40(w, x);
    for (c = w->child; c; c = c->next) func_00215020(c, x);
}

extern "C" void func_00215078(Work *w, s32 x) {
    Work *c;
    func_00215F80(w, x);
    for (c = w->child; c; c = c->next) func_00215078(c, x);
}

extern "C" s32 func_002150D0(s32 n) {
    s32 i;
    if (D_336F40.tbl) {
        func_00212B30(D_336F40.tbl);
        D_336F40.tbl = 0;
    }
    if (n > 0) {
        D_336F40.tbl = (Rec2 **)func_00212AE0(n * 4);
        if (D_336F40.tbl == 0) {
            if (func_00212918() & 2) Func235DE0(D_002E38D8);
            return 0;
        }
    }
    D_336F40.n = n;
    for (i = 0; i < n; i++) D_336F40.tbl[i] = 0;
    return 1;
}

extern "C" void func_00215198(Rec2 *p) {
    s32 k;
    Rec2 **pp;
    Rec2 *q;
    for (; p->m3; p = (Rec2 *)((u8 *)p + p->m3)) {
        k = p->m0;
        if (k >= 0 && !(D_336F40.n - 1 < k)) {
            pp = &D_336F40.tbl[k];
            while ((q = *pp) != 0) pp = &q->m8;
            *pp = p;
            p->m8 = 0;
        }
    }
}

extern "C" Rec2 *func_00215228(s32 i) {
    return func_00215FC0(i);
}

extern "C" const char *func_00215240(s32 i) {
    Rec2 *p = func_00215FC0(i);
    return p ? p->m4 : D_002E3910;
}

INCLUDE_ASM("asm/nonmatchings/Unit214938", func_00215270);

extern "C" s32 func_002152A0(const char *name) {
    s32 i;
    Rec2 *p;
    for (i = 0; i < D_336F40.n; i++) {
        p = func_00215FC0(i);
        if (p && !strcmp(p->m4, name)) return i;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/Unit214938", func_00215328);

extern "C" s32 func_00215438(s32 v) {
    s32 old = D_336F40.m1408;
    D_336F40.m1408 = v;
    return old;
}

extern "C" s32 func_00215450(void) {
    return D_336F40.m1408;
}

extern "C" void func_00215460(s32 a, s32 b) {
    func_00216100(a, b, 1);
    return;
}

extern "C" void func_00215478(s32 a, s32 b) {
    func_00216100(a, b, 0);
    return;
}

extern "C" void func_00215490(s32 a, s32 b, s32 c) {
    func_00216100(a, c, 1);
    return;
}

extern "C" void func_002154B0(s32 a, s32 b, s32 c) {
    func_00216100(a, c, 0);
    return;
}

extern "C" void func_002154D0(Play *e, s32 *arg) {
    if (e->m8->m0 == arg[0]) {
        e->m11 = *(u8 *)&arg[1];
        func_00215988(e);
        return;
    }
}

extern "C" void func_00215510(void *w, s32 a, s32 b) {
    s32 tmp[2];
    func_00212A60(D_002E3918);
    tmp[0] = a;
    tmp[1] = b;
    func_002163B0(w, (void *)func_002154D0, tmp);
}

extern "C" void func_00215570(Play *e, s32 v) {
    e->m11 = v;
    func_00215988(e);
    return;
}

extern "C" void func_00215588(Work *w, s32 x) {
    func_00212A60(D_002E3928);
    func_002163B0(w, (void *)func_00215570, (void *)x);
    func_002160A8(w);
    return;
}

extern "C" s32 func_002155D8(void) {
    return func_00216368() != 0;
}

INCLUDE_ASM("asm/nonmatchings/Unit214938", func_002155F8);

INCLUDE_ASM("asm/nonmatchings/Unit214938", func_00215628);

extern "C" void func_00215658(Play *e, s32 *varg) {
    Arg3 *arg = (Arg3 *)varg;
    if (e->m8->m0 == arg->id) {
        e->m10 = arg->a;
        e->m12 = arg->b;
        e->mD |= 1;
    }
}

extern "C" void func_00215698(void *w, s32 a, s32 b, s32 c) {
    s32 tmp[3];
    tmp[0] = a;
    tmp[1] = b;
    tmp[2] = c;
    func_002163B0(w, (void *)func_00215658, tmp);
}

extern "C" void func_002156C8(Play *e, s32 *varg) {
    Arg3 *arg = (Arg3 *)varg;
    if (e->m8->m0 == arg->id) {
        e->mF = arg->a;
        e->mD |= 2;
    }
}

extern "C" void func_00215700(void *w, s32 a, s32 b) {
    s32 tmp[2];
    tmp[0] = a;
    tmp[1] = b;
    func_002163B0(w, (void *)func_002156C8, tmp);
}

extern "C" void func_00215730(Play *e, s32 *varg) {
    ArgH *arg = (ArgH *)varg;
    if (e->m8->m0 == arg->id) {
        e->m14 = arg->a;
        e->m16 = arg->b;
        e->mD |= 4;
    }
}

extern "C" void func_00215770(void *w, s32 a, s16 b, s16 c) {
    s32 tmp[2];
    tmp[0] = a;
    ((s16 *)tmp)[2] = b;
    ((s16 *)tmp)[3] = c;
    func_002163B0(w, (void *)func_00215730, tmp);
}

extern "C" void func_002157A0(Play *e, s32 *arg) {
    if (e->m8->m0 == arg[0]) {
        e->m1C = *(f32 *)&arg[1];
        e->mD |= 0x10;
    }
}

extern "C" void func_002157D8(void *w, s32 a, f32 b) {
    s32 tmp[2];
    tmp[0] = a;
    *(f32 *)&tmp[1] = b;
    func_002163B0(w, (void *)func_002157A0, tmp);
}

extern "C" void func_00215808(Play *e, s32 *arg) {
    if (e->m8->m0 == arg[0]) {
        e->m20 = *(f32 *)&arg[1];
        e->mD |= 0x20;
    }
}

extern "C" void func_00215840(void *w, s32 a, f32 b) {
    s32 tmp[2];
    tmp[0] = a;
    *(f32 *)&tmp[1] = b;
    func_002163B0(w, (void *)func_00215808, tmp);
}

extern "C" void func_00215870(Play *e, s32 *arg) {
    if (e->m8->m0 == arg[0]) e->m24 = arg[1];
}

extern "C" void func_00215898(void *w, s32 a, s32 b) {
    s32 tmp[2];
    tmp[0] = a;
    tmp[1] = b;
    func_002163B0(w, (void *)func_00215870, tmp);
}

extern "C" s32 func_002158C8(u32 idx, POps *ops, s32 h) {
    if (idx > 256) return 0;
    {
        D_336F40.slots[idx].used = 1;
        D_336F40.slots[idx].h = h;
        D_336F40.slots[idx].ops.f0 = ops->f0 ? ops->f0 : func_00216048;
        D_336F40.slots[idx].ops.f4 = ops->f4 ? ops->f4 : (void (*)(void *))func_00216050;
        D_336F40.slots[idx].ops.f8 = ops->f8 ? ops->f8 : (s32 (*)(void *))func_00216058;
        D_336F40.slots[idx].ops.fC = ops->fC ? ops->fC : func_00216060;
    }
    return 1;
}

extern "C" void func_00215988(Play *e) {
    if (e->mC == 0) {
        e->mC = 1;
        func_00216000(e->m8->m0)->f4(e);
    }
}

extern "C" u8 func_002159D8(Play *e) {
    Work *w = e->m4;
    u8 v = e->mD;
    do {
        u8 f = w->m9;
        w = w->parent;
        v |= f;
    } while (w);
    return v;
}

extern "C" u8 func_00215A08(Play *e) {
    Work *w = e->m4;
    u8 v = e->m10;
    do {
        u8 f = w->mA;
        w = w->parent;
        v |= f;
    } while (w);
    return v;
}
