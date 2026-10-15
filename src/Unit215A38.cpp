#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct Work { Work *next; Work *parent; u8 m8; u8 m9; u8 mA; u8 mB; s16 mC; s16 mE; f32 m10; f32 m14; u8 m18; u8 m19; u8 pad1A[0x68 - 0x1A]; struct Play *m68; Work *child; u8 m70[16]; };
struct Rec2 { s16 m0; u8 m2; u8 m3; const char *m4; Rec2 *m8; u16 mC; s16 mE; s32 m10; s32 m14; s32 m18; s32 m1C; s16 m20; s16 m22; };
struct PtHdr { u8 m0; u8 m1; u16 m2; u16 stack[2]; };
struct POps { s32 (*f0)(void *); void (*f4)(void *); void (*f8)(void *); s32 (*fC)(Rec2 *, s32, s32); };
struct Play { Play *next; Work *m4; Rec2 *m8; u8 mC; u8 mD; u8 mE; u8 mF; u8 m10; u8 m11; u8 m12; u8 m13; s16 m14; s16 m16; f32 m18; f32 m1C; f32 m20; s32 m24; PtHdr hdr; s32 m30; s32 m34; s32 m38; s32 m3C; };
struct PSlot { s16 used; s16 h; POps ops; };
struct S336F40 { Rec2 **tbl; s32 n; PSlot slots[256]; s32 m1408; };
extern S336F40 D_336F40;
extern "C" void func_00212B30(void *);
extern "C" Work *func_00215010(void);
extern "C" POps *func_00216000(s32);
extern "C" void func_002160A8(Work *);
extern "C" s32 func_00212E90(s32);
extern "C" void func_00215988(Play *);
extern "C" f32 func_00219078(Work *);
extern "C" f32 func_00218E70(s32 *, s32 *, Work *, Rec2 *, f32);
extern "C" void func_00216410(void);
extern "C" void func_00216770(void);
extern "C" void func_00216AD0(void);
extern "C" void func_00216EC8(void);
extern "C" void func_002175B8(void);
extern "C" void func_00217C08(void);
extern "C" void func_00215D40(Work *);
extern "C" void func_00215DD8(Work *, s32);

extern POps D_002A6268;
extern u8 D_002A6278[];
extern const char D_002E3938[];
extern "C" void *func_00212AE0(s32);
extern "C" s32 func_00212918(void);
void Func235DE0(const char *, ...);
extern "C" Rec2 *func_00215FC0(s32);
extern "C" PSlot *func_00216068(u32);
extern "C" Play *func_00216230(Work *, Rec2 *);
extern "C" Play *func_00216368(Work *, s32);
extern "C" void func_002163B0(Work *, void (*)(Play *, s32), s32);
extern "C" void func_002161E0(Play *, s32);
extern "C" void func_00216208(Play *);
extern "C" s32 func_002158C8(u32, void *, s32);
extern "C" void func_0020A1E0(s32, s32);
extern "C" void func_00216438(Play *);
extern "C" s32 func_002130D8(s32, s32);
extern "C" void func_002130F8(s32, s32);
inline u16 RecLoop(Rec2 *p) { return p->mC & 1; }

#define PTV_BEGIN(h) u16 _lc = (h)->m2; u16 *_sp = &(h)->stack[(h)->m1]; if ((h)->m0 & 0x80) goto _yield; switch (_lc) { case 0:
#define PTV_WAIT_WHILE(h, line, cond) while (cond) { (h)->m2 = line; goto _yield; case line:; }
#define PTV_END(h) } _yield: (h)->m1 = _sp - (h)->stack;
extern "C" u8 func_002159D8(Play *);
extern "C" u8 func_00215A38(Play *);
extern "C" void func_00215A68(Play *, s32 *, s32 *);
extern "C" f32 func_00215BB8(Play *);
extern "C" f32 func_00215C38(Play *);
extern "C" s32 func_00213238(s32);
extern "C" s32 func_00212F20(s32);
extern "C" s32 func_00209F50(s32, s32, s32, s32, s32, s32);
extern "C" void func_0020A410(s32, s32);
extern "C" void func_0020A4A8(s32, s32, s32);
extern "C" void func_0020A5F8(s32, f32);
extern "C" void func_0020A6A0(s32, f32);
extern "C" s32 func_0020A310(s32);
extern u8 D_002A6288[];
extern "C" void func_00216798(Play *);

#define FS32(e, off) (*(s32 *)((u8 *)(e) + (off)))
#define FS16(e, off) (*(s16 *)((u8 *)(e) + (off)))
extern u8 D_002A6298[];
extern u8 D_002A62A8[];
extern u8 D_002A62B8[];
extern u8 D_002A62C8[];
extern "C" void func_002094A0(s32, s32);
extern "C" void func_0020C100(s32);
extern "C" void func_0022DE48(s32);
extern "C" void func_00219950(s32);
extern "C" void func_00219970(s32);
extern "C" void func_00219990(s32);
extern "C" void func_0020AF80(s32);
extern "C" void func_0020F480(s32, s32);
extern "C" void func_00216AF8(Play *);
extern "C" void func_00216EF0(Play *);
extern "C" void func_002175E0(Play *);
extern "C" void func_00217C30(Play *);

struct CbMsg4 { s32 kind; void *work; s32 id; s32 val; };
extern "C" Play *func_0020F858(s32);
extern "C" s32 func_0020F948(s32);
extern "C" s32 func_0020F998(s32);
extern "C" s32 func_0020E5C0(s32, s32, s32);
extern "C" void func_00212A30(void *);
// @decl-end

extern "C" u8 func_00215A38(Play *e) {
    Work *w = e->m4;
    u8 v = e->mF;
    do {
        u8 f = w->mB;
        w = w->parent;
        v |= f;
    } while (w);
    return v;
}

extern "C" void func_00215A68(Play *e, s32 *pa, s32 *pb) {
    Rec2 *r = e->m8;
    Work *w = e->m4;
    s32 v[2];
    if (r->mC & 0x40) {
        v[0] = 0;
        v[1] = 0;
    } else {
        if (r->mC & 0xC) {
            e->m18 = func_00218E70(&v[0], &v[1], w, r, e->m18);
        } else {
            v[0] = 0x80;
            v[1] = 0x80;
        }
        v[0] = v[0] * r->mE >> 7;
        v[1] = v[1] * r->mE >> 7;
        v[0] = v[0] * e->m14 >> 7;
        v[1] = v[1] * e->m16 >> 7;
        do {
            v[0] = v[0] * w->mC >> 7;
            v[1] = v[1] * w->mE >> 7;
            w = w->parent;
        } while (w);
    }
    *pa = v[0];
    *pb = v[1];
}

extern "C" void func_00215B90(Play *e, s32 *a, s32 *b, s32 k) {
    *a = e->m4->m70[k];
    *b = e->m4->m70[k];
}

extern "C" f32 func_00215BB8(Play *e) {
    Work *w = e->m4;
    f32 v;
    if (e->m8->mC & 0x20) v = func_00219078(w);
    else v = 1.0f;
    v *= e->m1C;
    do {
        f32 f = w->m10;
        w = w->parent;
        v *= f;
    } while (w);
    return v;
}

extern "C" f32 func_00215C38(Play *e) {
    Work *w = e->m4;
    f32 v = e->m20;
    do {
        f32 f = w->m14;
        w = w->parent;
        v *= f;
    } while (w);
    return v;
}

extern "C" void func_00215C68(void) {
    s32 i;
    D_336F40.tbl = 0;
    D_336F40.n = 0;
    for (i = 0; i < 256; i++) D_336F40.slots[i].used = 0;
    D_336F40.m1408 = 0;
    func_00216410();
    func_00216770();
    func_00216AD0();
    func_00216EC8();
    func_002175B8();
    func_00217C08();
    return;
}

extern "C" void func_00215CE0(void) {
    if (D_336F40.tbl) {
        func_00212B30(D_336F40.tbl);
        D_336F40.tbl = 0;
    }
}

extern "C" void func_00215D20(void) {
    func_00215D40(func_00215010());
    return;
}

extern "C" void func_00215D40(Work *w) {
    Play *e;
    Work *c;
    for (e = w->m68; e; e = e->next) {
        if (!e->mC) func_00216000(e->m8->m0)->f8(e);
    }
    func_002160A8(w);
    for (c = w->child; c; c = c->next) func_00215D40(c);
    w->m9 = 0;
}

extern "C" void func_00215DD8(Work *w, s32 id) {
    Play *e;
    Work *c;
    s32 n;
    s32 *buf;
    s32 i;
    s32 *q;
    for (e = w->m68; e; e = e->next) {
        if (e->mC) continue;
        n = func_00216000(e->m8->m0)->fC(e->m8, 0, 0);
        buf = (s32 *)__builtin_alloca(n * 4);
        func_00216000(e->m8->m0)->fC(e->m8, (s32)buf, n);
        for (i = 0; i < n; i++) {
            if (buf[i] == id || func_00212E90(buf[i]) == id) {
                func_00215988(e);
                break;
            }
        }
    }
    for (c = w->child; c; c = c->next) func_00215DD8(c, id);
}

extern "C" void func_00215F10(s32 id) {
    func_00215DD8(func_00215010(), id);
    return;
}

extern "C" void func_00215F40(Work *w, s32 v) {
    Play *e;
    for (e = w->m68; e; e = e->next) {
        if (!e->mC) e->m11 = v;
    }
}

extern "C" void func_00215F80(Work *w, s32 v) {
    Play *e;
    for (e = w->m68; e; e = e->next) {
        if (!e->mC) e->m12 = v;
    }
}

extern "C" Rec2 *func_00215FC0(s32 i) {
    if (i >= 0 && !(D_336F40.n - 1 < i)) goto found;
    return 0;
found:
    return D_336F40.tbl[i];
}

extern "C" POps *func_00216000(s32 i) {
    Rec2 *p = func_00215FC0(i);
    POps *r = &D_002A6268;
    if (p) r = &D_336F40.slots[p->m2].ops;
    return r;
}

extern "C" s32 func_00216048(void *) {
    return 1;
}

extern "C" void func_00216050(void) {
}

extern "C" void func_00216058(void) {
}

extern "C" s32 func_00216060(Rec2 *, s32, s32) {
    return 0;
}

extern "C" PSlot *func_00216068(u32 idx) {
    if (idx <= 256 && D_336F40.slots[idx].used) return &D_336F40.slots[idx];
    return 0;
}

extern "C" void func_002160A8(Work *w) {
    Play **pp = &w->m68;
    Play *e;
    while ((e = *pp) != 0) {
        if (e->mC) {
            *pp = e->next;
            func_00212B30(e);
        } else {
            pp = &e->next;
        }
    }
}

extern "C" s32 func_00216100(Work *w, s32 id, s32 mode) {
    Rec2 *p = func_00215FC0(id);
    if (!p) return 0;
    if (mode) {
        if (!RecLoop(p)) {
            func_002163B0(w, func_002161E0, p->m0);
            if (!RecLoop(p)) goto play;
        }
        if (func_00216368(w, p->m0)) return 1;
    }
play:
    for (; p; p = p->m8) func_00216230(w, p);
    func_002163B0(w, (void (*)(Play *, s32))func_00216208, 0);
    return 1;
}

extern "C" void func_002161E0(Play *e, s32 id) {
    if (e->m8->m0 == id) e->mD |= 0x80;
}

extern "C" void func_00216208(Play *e) {
    if (e->mD & 0x80) {
        func_00215988(e);
        return;
    }
}

extern "C" Play *func_00216230(Work *w, Rec2 *p) {
    PSlot *s;
    Play *e = 0;
    s = func_00216068(p->m2);
    if (!s) goto fail;
    if (!w) w = func_00215010();
    e = (Play *)func_00212AE0(s->h);
    if (!e) {
        if (func_00212918() & 2) Func235DE0(D_002E3938);
        goto fail;
    }
    e->next = 0;
    e->m4 = 0;
    e->m8 = p;
    e->mC = 0;
    e->mF = 0;
    e->m10 = 0;
    e->m11 = 0;
    e->m12 = 0;
    e->mD = 0x3F;
    e->mE = 1;
    e->m14 = 0x80;
    e->m16 = 0x80;
    e->m18 = 0;
    e->m1C = 1.0f;
    e->m20 = 1.0f;
    e->m24 = 0;
    if (!func_00216000(p->m0)->f0(e)) goto fail;
    e->next = w->m68;
    w->m68 = e;
    e->m4 = w;
    return e;
fail:
    if (e) func_00212B30(e);
    return 0;
}

extern "C" Play *func_00216368(Work *w, s32 id) {
    Play *e;
    for (e = w->m68; e; e = e->next) {
        if (!e->mC && e->m8->m0 == id) return e;
    }
    return 0;
}

extern "C" void func_002163B0(Work *w, void (*fn)(Play *, s32), s32 arg) {
    Play *e;
    for (e = w->m68; e; e = e->next) {
        if (!e->mC) fn(e, arg);
    }
}

extern "C" void func_00216410(void) {
    func_002158C8(0, D_002A6278, 0x40);
    return;
}

extern "C" void func_00216438(Play *e) {
    if (e->m3C >= 0) {
        func_0020A1E0(e->m3C, e->m11);
        e->m3C = -1;
        e->mE &= ~2;
    }
}

extern "C" s32 func_00216480(Play *e) {
    Rec2 *r = e->m8;
    PtHdr *h = &e->hdr;
    h->m1 = 6;
    h->m2 = 0;
    h->m0 = 0;
    e->m3C = -1;
    e->m38 = func_00212E90(r->m20);
    if (e->m38 < 0) return 0;
    if (D_336F40.m1408 && !func_002130D8(e->m38, 0)) return 0;
    return 1;
}

extern "C" void func_00216500(Play *e) {
    func_00216438(e);
    if (D_336F40.m1408) {
        func_002130F8(e->m38, 0);
        return;
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit215A38", func_00216548);

extern "C" s32 func_00216758(Rec2 *p, s32 *out, s32 n) {
    if (n > 0) out[0] = p->m20;
    return 1;
}

extern "C" void func_00216770(void) {
    func_002158C8(1, D_002A6288, 0x40);
    return;
}

extern "C" void func_00216798(Play *e) {
    if (e->m3C >= 0) {
        func_0020A1E0(e->m3C, e->m11);
        e->m3C = -1;
        e->mE &= ~2;
    }
}

extern "C" s32 func_002167E0(Play *e) {
    Rec2 *r = e->m8;
    PtHdr *h = &e->hdr;
    h->m1 = 6;
    h->m2 = 0;
    h->m0 = 0;
    e->m3C = -1;
    e->m38 = func_00212E90(r->m20);
    if (e->m38 < 0) return 0;
    if (D_336F40.m1408 && !func_002130D8(e->m38, 0)) return 0;
    return 1;
}

extern "C" void func_00216860(Play *e) {
    func_00216798(e);
    if (D_336F40.m1408) {
        func_002130F8(e->m38, 0);
        return;
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit215A38", func_002168A8);

extern "C" s32 func_00216AB8(Rec2 *p, s32 *out, s32 n) {
    if (n > 0) out[0] = p->m20;
    return 1;
}

extern "C" void func_00216AD0(void) {
    func_002158C8(2, D_002A6298, 0x40);
    return;
}

extern "C" void func_00216AF8(Play *e) {
    if (e->m3C >= 0) {
        func_002094A0(e->m3C, e->m11);
        e->m3C = -1;
        e->mE &= ~2;
    }
}

extern "C" s32 func_00216B40(Play *e) {
    Rec2 *r = e->m8;
    PtHdr *h = &e->hdr;
    h->m1 = 6;
    h->m2 = 0;
    h->m0 = 0;
    e->m3C = -1;
    e->m38 = func_00212E90(r->m20);
    if (e->m38 < 0) return 0;
    if (D_336F40.m1408 && !func_002130D8(e->m38, 0)) return 0;
    return 1;
}

extern "C" void func_00216BC0(Play *e) {
    func_00216AF8(e);
    if (D_336F40.m1408) {
        func_002130F8(e->m38, 0);
        return;
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit215A38", func_00216C08);

extern "C" s32 func_00216EB0(Rec2 *p, s32 *out, s32 n) {
    if (n > 0) out[0] = p->m20;
    return 1;
}

extern "C" void func_00216EC8(void) {
    func_002158C8(3, D_002A62A8, 0x4C);
    return;
}

extern "C" void func_00216EF0(Play *e) {
    if (FS32(e, 0x48) >= 0) {
        func_0020C100(FS32(e, 0x48));
        FS32(e, 0x48) = -1;
        e->mE &= ~2;
    }
    if (e->m38 >= 0) {
        func_0022DE48(e->m38);
        e->m38 = -1;
    }
    if (e->m3C) {
        func_00219950(e->m3C);
        e->m3C = 0;
    }
    if (FS32(e, 0x40)) {
        func_00219970(FS32(e, 0x40));
        FS32(e, 0x40) = 0;
    }
    if (FS32(e, 0x44)) {
        func_00219990(FS32(e, 0x44));
        FS32(e, 0x44) = 0;
    }
}

extern "C" s32 func_00216FA0(Play *e) {
    PtHdr *h = &e->hdr;
    h->m0 = 0;
    h->m2 = 0;
    h->m1 = 6;
    e->m38 = -1;
    e->m3C = 0;
    FS32(e, 0x40) = 0;
    FS32(e, 0x44) = 0;
    FS32(e, 0x48) = -1;
    return 1;
}

extern "C" void func_00216FD8(Play *e) {
    func_00216EF0(e);
    return;
}

INCLUDE_ASM("asm/nonmatchings/Unit215A38", func_00216FF0);

extern "C" void func_002175B8(void) {
    func_002158C8(4, D_002A62B8, 0x48);
    return;
}

extern "C" void func_002175E0(Play *e) {
    if (FS32(e, 0x44) >= 0) {
        func_0020AF80(FS32(e, 0x44));
        FS32(e, 0x44) = -1;
        e->mE &= ~2;
    }
    if (e->m38 >= 0) {
        func_0022DE48(e->m38);
        e->m38 = -1;
    }
    if (e->m3C) {
        func_00219950(e->m3C);
        e->m3C = 0;
    }
    if (FS32(e, 0x40)) {
        func_00219970(FS32(e, 0x40));
        FS32(e, 0x40) = 0;
    }
}

extern "C" s32 func_00217678(Play *e) {
    PtHdr *h = &e->hdr;
    h->m0 = 0;
    h->m2 = 0;
    h->m1 = 6;
    e->m38 = -1;
    FS32(e, 0x40) = 0;
    e->m3C = 0;
    FS32(e, 0x44) = -1;
    return 1;
}

extern "C" void func_002176A8(Play *e) {
    func_002175E0(e);
    return;
}

INCLUDE_ASM("asm/nonmatchings/Unit215A38", func_002176C0);

extern "C" void func_00217C08(void) {
    func_002158C8(5, D_002A62C8, 0x50);
    return;
}

extern "C" void func_00217C30(Play *e) {
    if (FS16(e, 0x42) >= 0) {
        func_0020F480(FS16(e, 0x42), e->m11);
        FS16(e, 0x42) = -1;
        e->mE &= ~2;
    }
    if (FS32(e, 0x44)) {
        func_00219950(FS32(e, 0x44));
        FS32(e, 0x44) = 0;
    }
    if (FS32(e, 0x48)) {
        func_00219970(FS32(e, 0x48));
        FS32(e, 0x48) = 0;
    }
    if (FS32(e, 0x4C)) {
        func_00219990(FS32(e, 0x4C));
        FS32(e, 0x4C) = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit215A38", func_00217CC0);

extern "C" void func_00217E88(Play *e) {
    func_00217C30(e);
    if (D_336F40.m1408) {
        func_002130F8(FS16(e, 0x40), 0);
        return;
    }
}

extern "C" void func_00217ED0(s32 strm, s32 x) {
    CbMsg4 m;
    Play *e = func_0020F858(strm);
    s32 bank;
    m.kind = 0;
    m.work = e->m4;
    m.id = e->m8->m0;
    bank = func_0020F948(strm);
    m.val = func_0020E5C0(bank, func_0020F998(strm), x);
    func_00212A30(&m);
}
