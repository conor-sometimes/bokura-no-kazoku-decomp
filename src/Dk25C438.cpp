#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern void *(*D_002B91A4)(u32 n);
class CVec4;
void Func270C50(CVec4 *d, const CVec4 *s);
void Func270CA0(CVec4 *d, void *m);
void *Func245D00(s32 n);
extern "C" s32 func_001F1180(void);
extern s32 D_002BA268[];
extern s32 D_002BA780[];
// Intrusive list node of the sound tree (list heads have m_head = 1).
struct CSndNode {
    s32 m_head;               // 0x0
    CSndNode *m_prev;         // 0x4
    CSndNode *m_next;         // 0x8
};
inline CSndNode *SndItem(CSndNode *n) { return n->m_head == 0 ? n : 0; }
inline void SndUnlink(CSndNode *n) {
    n->m_prev->m_next = n->m_next;
    n->m_next->m_prev = n->m_prev;
    n->m_next = n;
    n->m_prev = n;
}
inline void SndInsert(CSndNode *n, CSndNode *h) {
    CSndNode *p = h->m_prev;
    n->m_next = h;
    n->m_prev = p;
    p->m_next = n;
    n->m_next->m_prev = n;
}
struct CSndUnitN : CSndNode {
    void *m_vt;               // 0xC
    void *m_owner;            // 0x10
};
// List node base with the vptr after its three fields (0xC).
class CSndNodeV {
public:
    s32 m_head;
    CSndNodeV *m_prev;
    CSndNodeV *m_next;
    virtual ~CSndNodeV();
};
class CSndWork : public CSndNodeV {
public:
    void Func25DD90(s32 id, s32 v, f32 a, f32 b, f32 c, f32 d);
    void Func25DEF0(s32 id, s32 v);
    void Func25DE60(s32 id, s32 v);
    void Func25DC78(s32 id, s32 m);
    void Func25DD08(s32 id, CVec4 *v);
    void Func25CC18(s32 id, s32 a, s32 b);
    void Func25CB90(s32 id, s32 a, s32 b);
    void Func25CD38(s32 id, f32 v);
    void Func25CCB0(s32 id, f32 v);
    void Func25C910(s32 id, s32 v, s32 w);
    s32 Func25CF58(s32 id);
    void Func25CE30(s32 id, s32 v);
    void Func25D1A0(struct CSndPrm *p);
    void Func25CDC0(s32 id, f32 v);
    s32 Func25CA58(s32 id);
    s32 Func25C9F0(s32 id);
    s32 Func25C990(s32 id);
    CSndUnitN *Func25C510(CSndUnitN *cur);
    CSndUnitN *Func25C4B0(s32 id);
    virtual ~CSndWork();                         // [0] key, 0x25C2C0
    virtual void Func1();                        // [1] inline
    virtual s32 Func25C630(s32 i);               // [2]
    virtual void Func25D198(struct CSndPrm *p);  // [3]
    void Func25C438(CSndUnitN *u);
    void Func25D130(struct CSndPrm *p);
    void Func25D218(struct CSndPrm *p);
};
class CSndWorkReal {
public:
    virtual void Func0();
    virtual void Func1();
    virtual s32 Func25DF80(s32 i);               // [2]
};
struct CSndTree { CSndNode n; u8 padC[0x10]; CSndNode *m1C; u8 pad20[0xC]; CSndNode *m2C; };
struct CSndLeaf { CSndNode n; u8 padC[0x11]; s8 m1D; };
struct CSndObj { u8 m0; u8 pad1[0x1F]; u8 m20[0x80]; u8 mA0[0x40]; s32 mE0; };
struct CSndFlt { u8 m0; s8 m1, m2, m3; s32 m4, m8; f32 mC; s32 m10, m14, m18; };
void Func25D008(CSndTree *t, s32 b);
void Func25D0D8(CSndTree *t, s32 b);
void Func25D2B0(CSndTree *t, s32 b);
void Func25D388(CSndTree *t, s32 b);
extern "C" void func_0025D3E0(s32 init, s32 prio);
void Func25D4C8(s32 a, s32 b);

struct CSndPrm;
void Func25BDD0(CSndPrm *d, const CSndPrm *s);
void Func25BE98(CSndPrm *d, const CSndPrm *s);
struct CSndUnitX : CSndUnitN { s32 m14; s32 m18; u8 m1C; s8 m1D; s8 m1E; u8 pad1F; s8 m20; u8 pad21[0x17]; f32 m38; };
class CSndMgrV {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void *Alloc(s32 n);
    virtual void Free(void *p);
};
extern CSndMgrV *D_002BA248;
extern void (*D_002B91B0)(void *p);
struct CSndPrmB { u8 pad[0x40]; };

struct CSndUnitX2 : CSndUnitN { s32 m14; s32 m18; u8 m1C; s8 m1D; s8 m1E; s8 m1F; s8 m20; s8 m21; u8 pad22[6]; f32 m28; f32 m2C; u8 pad30[8]; f32 m38; u8 pad3C[0x20]; s32 m5C; };
class CSndUnitV : public CSndNodeV {
public:
    virtual void Apply(struct CSndPrm *p);
};
class CSndOwnerV : public CSndNodeV {
public:
    virtual void *Parent();
};
struct CSndFlt2 { u8 m0, m1, m2, m3; f32 m4, m8, mC, m10, m14, m18; u8 pad1C[4]; u8 m20[0x10]; };
struct CSndObj2 { u8 pad0[0x10]; CSndOwnerV *m10; u8 pad14[0x8C]; u8 mA0[0x40]; s32 mE0; };
void *Func25DFE0(s32 n);
void *Func25E290(void *p, s32 a, s32 b, s32 c, s32 d);

struct CSndUnitX3 : CSndUnitN { s32 m14; s32 m18; u8 m1C; u8 pad1D[7]; s16 m24; s16 m26; u8 pad28[8]; f32 m30; f32 m34; u8 pad38[4]; u16 m3C; u16 m3E; s16 m40; u8 pad42[2]; s32 m44; s32 m48; };
class CSndUnitV3 : public CSndNodeV {
public:
    virtual void Apply(struct CSndPrm *p);
    virtual void V2();
    virtual CSndObj *Obj();
};
void Func25DB88(CSndObj *o, CVec4 *v);
void Func25D478(CSndFlt *f);
extern u8 D_vtSndUnitTg[] __asm__("_vt$t12TSndUnitReal1Z10CSndUnitTg");

s32 Func25C810(s32 a, s32 b);
struct CSndUnitX4 : CSndUnitN { s32 m14; s32 m18; u8 m1C; s8 m1D; s8 m1E; s8 m1F; u8 pad20[0x2E]; s16 m4E; };

extern "C" void *func_0025C098(void *p, s32 a);
extern u8 D_vtCSndUnitTg[] __asm__("_vt$10CSndUnitTg");
class CSndMgrV2 {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual s32 GetId(s32 i);
};
struct CSndSub68 { s16 m0; s16 m2; s32 m4; CSndSub68() { m4 = -1; m2 = 0; m0 = 0; } };
struct CSndUnitTgH { u8 pad0[0x50]; u8 m50; u8 pad51[3]; s32 m54; u8 pad58[0x10]; CSndSub68 m68; u8 pad70[0x40]; s32 mB0; s32 mB4; s32 mB8; };
inline void *operator new(unsigned int, void *p) { return p; }

void Func25D270(CSndTree *t, s32 b);
extern u8 D_41A788[];
extern "C" void func_0025C230(void *w);
extern "C" void func_0025C2C0(void *w, s32 c);

void *Func25DBF8(CSndObj2 *o);
extern "C" void func_0025D608(void *, void *, s32);
extern "C" void func_0025C230(void *);
extern "C" void func_0025C2C0(void *, s32);
extern "C" u8 D_41A788[];
// @decl-end

void CSndWork::Func25C438(CSndUnitN *u) {
    CSndNode *h = (CSndNode *)((u8 *)this + 0x14);
    if ((void *)this == (void *)u) return;
    SndUnlink(u);
    SndInsert(u, h);
    u->m_owner = this;
}

void Func25C488(CSndUnitN *u) {
    u->m_owner = 0;
    SndUnlink(u);
}

INCLUDE_ASM("asm/nonmatchings/Dk25C438", Func25C4B0__8CSndWorki);

INCLUDE_ASM("asm/nonmatchings/Dk25C438", Func25C510__8CSndWorkP9CSndUnitN);

INCLUDE_ASM("asm/nonmatchings/Dk25C438", func_0025C580);

INCLUDE_ASM("asm/nonmatchings/Dk25C438", func_0025C5D8);

s32 CSndWork::Func25C630(s32 i) { return D_002BA268[i]; }

INCLUDE_ASM("asm/nonmatchings/Dk25C438", Func25C648__8CSndWorkii);

s32 Func25C810(s32 a, s32 b) {
    if (a) return 0;
    if (b > 0) return 0;
    return func_001F1180() == 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk25C438", Func25C840__8CSndWorkiii);

void CSndWork::Func25C910(s32 id, s32 v, s32 w) {
    for (CSndUnitX2 *p = (CSndUnitX2 *)Func25C4B0(id); p; p = (CSndUnitX2 *)Func25C510(p)) {
        if (p->m1E != v) {
            p->m1E = v;
            p->m1F = w;
            p->m1C = 1;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/Dk25C438", Func25C990__8CSndWorki);

INCLUDE_ASM("asm/nonmatchings/Dk25C438", func_0025C9F0);

INCLUDE_ASM("asm/nonmatchings/Dk25C438", func_0025CA58);

INCLUDE_ASM("asm/nonmatchings/Dk25C438", func_0025CAC0);

INCLUDE_ASM("asm/nonmatchings/Dk25C438", func_0025CB28);

void CSndWork::Func25CB90(s32 id, s32 a, s32 b) {
    for (CSndUnitX3 *p = (CSndUnitX3 *)Func25C4B0(id); p; p = (CSndUnitX3 *)Func25C510(p)) {
        if (p->m24 != a || p->m26 != b) {
            p->m24 = a;
            p->m26 = b;
            p->m1C = 1;
        }
    }
}

void CSndWork::Func25CC18(s32 id, s32 a, s32 b) {
    for (CSndUnitX3 *p = (CSndUnitX3 *)Func25C4B0(id); p; p = (CSndUnitX3 *)Func25C510(p)) {
        if (b == 0) {
            p->m3C = a;
            p->m44 = 0;
            p->m48 = 0;
            p->m1C = 1;
        } else {
            p->m40 = a;
            p->m3E = p->m3C;
            p->m44 = 0;
            p->m48 = b;
        }
    }
}

void CSndWork::Func25CCB0(s32 id, f32 v) {
    for (CSndUnitX2 *p = (CSndUnitX2 *)Func25C4B0(id); p; p = (CSndUnitX2 *)Func25C510(p)) {
        if (p->m28 != v || p->m2C != v) {
            p->m28 = v;
            p->m2C = v;
            p->m1C = 1;
        }
    }
}

void CSndWork::Func25CD38(s32 id, f32 v) {
    for (CSndUnitX3 *p = (CSndUnitX3 *)Func25C4B0(id); p; p = (CSndUnitX3 *)Func25C510(p)) {
        if (p->m30 != v || p->m34 != v) {
            p->m30 = v;
            p->m34 = v;
            p->m1C = 1;
        }
    }
}

void CSndWork::Func25CDC0(s32 id, f32 v) {
    for (CSndUnitX *p = (CSndUnitX *)Func25C4B0(id); p; p = (CSndUnitX *)Func25C510(p)) {
        if (p->m38 != v) {
            p->m38 = v;
            p->m1C = 1;
        }
    }
}

void CSndWork::Func25CE30(s32 id, s32 v) {
    for (CSndUnitX2 *p = (CSndUnitX2 *)Func25C4B0(id); p; p = (CSndUnitX2 *)Func25C510(p)) {
        if (p->m21 != v) {
            p->m21 = v;
            p->m1C = 1;
        }
    }
}

s32 Func25CEA0(CSndTree *t) {
    s32 n = 0;
    for (CSndNode *p = SndItem(t->m2C); p; p = SndItem(p->m_next)) {
        if (((CSndLeaf *)p)->m1D == 0) n++;
    }
    return n;
}

INCLUDE_ASM("asm/nonmatchings/Dk25C438", func_0025CEE8);

s32 CSndWork::Func25CF58(s32 id) {
    for (CSndUnitX2 *p = (CSndUnitX2 *)Func25C4B0(id); p; p = (CSndUnitX2 *)Func25C510(p)) {
        if (p->m14 == id) return p->m5C;
    }
    return -1;
}

void Func25CFC8(CSndTree *t, s32 b) {
    Func25D008(t, b);
    Func25D0D8(t, b);
}

INCLUDE_ASM("asm/nonmatchings/Dk25C438", Func25D008__FP8CSndTreei);

void Func25D0D8(CSndTree *t, s32 b) {
    for (CSndNode *p = SndItem(t->m1C); p; p = SndItem(p->m_next)) Func25D0D8((CSndTree *)p, b);
}

void CSndWork::Func25D130(CSndPrm *prm) {
    CSndPrmB t;
    Func25BDD0((CSndPrm *)&t, prm);
    Func25BE98((CSndPrm *)&t, (CSndPrm *)((u8 *)this + 0x34));
    Func25D198((CSndPrm *)&t);
    Func25D1A0((CSndPrm *)&t);
    Func25D218((CSndPrm *)&t);
}

extern "C" void func_0025D198(void) {
}

INCLUDE_ASM("asm/nonmatchings/Dk25C438", Func25D1A0__8CSndWorkP7CSndPrm);

void CSndWork::Func25D218(CSndPrm *b) {
    for (CSndNode *p = SndItem(((CSndTree *)this)->m1C); p; p = SndItem(p->m_next)) ((CSndWork *)p)->Func25D130(b);
}

void Func25D270(CSndTree *t, s32 b) {
    Func25D2B0(t, b);
    Func25D388(t, b);
}

INCLUDE_ASM("asm/nonmatchings/Dk25C438", Func25D2B0__FP8CSndTreei);

void Func25D388(CSndTree *t, s32 b) {
    for (CSndNode *p = SndItem(t->m1C); p; p = SndItem(p->m_next)) Func25D270((CSndTree *)p, b);
}

INCLUDE_ASM("asm/nonmatchings/Dk25C438", func_0025D3E0);

extern "C" void func_0025D438(void) { func_0025D3E0(1, 0xFFFF); }

extern "C" void func_0025D458(void) { func_0025D3E0(0, 0xFFFF); }

void Func25D478(CSndFlt *f) {
    f->m18 = 0;
    f->m0 = 0;
    f->m1 = -1;
    f->m2 = -1;
    f->m4 = 0;
    f->m8 = 0;
    f->mC = 1.0f;
    f->m10 = 0;
    f->m14 = 0;
    f->m3 = -1;
}

void Func25D4B0(s32 a, s32 b) { return Func25D4C8(a, b); }

void Func25D4C8(s32 a, s32 b) {
    CSndFlt2 *d = (CSndFlt2 *)a;
    CSndFlt2 *s = (CSndFlt2 *)b;
    d->m0 = s->m0;
    d->m1 = s->m1;
    d->m2 = s->m2;
    d->m3 = s->m3;
    d->m4 = s->m4;
    d->m8 = s->m8;
    d->mC = s->mC;
    d->m10 = s->m10;
    d->m14 = s->m14;
    d->m18 = s->m18;
    Func270C50((CVec4 *)d->m20, (CVec4 *)s->m20);
}

void Func25D540(CSndFlt2 *d, CSndFlt2 *s) {
    u8 m = s->m0 & (d->m0 ^ s->m0);
    if (m & 0x10) {
        d->m1 = s->m1;
        d->m4 = s->m4;
        d->m8 = s->m8;
        d->mC = s->mC;
        d->m10 = s->m10;
    }
    if (m & 0x20) d->m2 = s->m2;
    if (m & 0x40) {
        d->m3 = s->m3;
        d->m18 = s->m18;
    }
    if (m & 0x80) Func270C50((CVec4 *)d->m20, (CVec4 *)s->m20);
    d->m0 |= s->m0;
}

INCLUDE_ASM("asm/nonmatchings/Dk25C438", func_0025D608);

void Func25DB88(CSndObj *o, CVec4 *v) {
    o->m0 |= 0x80;
    Func270C50((CVec4 *)o->m20, v);
}

void Func25DBB8(CSndObj *o, void *m) {
    if (m) {
        Func270CA0((CVec4 *)o->mA0, m);
        o->mE0 = 1;
    } else {
        o->mE0 = 0;
    }
}

void *Func25DBF8(CSndObj2 *o) {
    for (;;) {
        if (o->mE0) return o->mA0;
        if (!o->m10) return 0;
        if (!o->m10->Parent()) return 0;
        o = (CSndObj2 *)o->m10->Parent();
    }
}

void CSndWork::Func25DC78(s32 id, s32 m) {
    for (CSndUnitN *p = Func25C4B0(id); p; p = Func25C510(p)) {
        CSndObj *o = ((CSndUnitV3 *)p)->Obj();
        if (o) o->m0 = (o->m0 & 0x8F) | m;
    }
}

void CSndWork::Func25DD08(s32 id, CVec4 *v) {
    for (CSndUnitN *p = Func25C4B0(id); p; p = Func25C510(p)) {
        CSndObj *o = ((CSndUnitV3 *)p)->Obj();
        if (o) Func25DB88(o, v);
    }
}

void CSndWork::Func25DD90(s32 id, s32 v, f32 a, f32 b, f32 c, f32 d) {
    for (CSndUnitN *p = Func25C4B0(id); p; p = Func25C510(p)) {
        CSndFlt2 *o = (CSndFlt2 *)((CSndUnitV3 *)p)->Obj();
        if (o) {
            o->m1 = v;
            o->m4 = a;
            o->m8 = b;
            o->mC = c;
            o->m10 = d;
            o->m0 |= 0x10;
        }
    }
}

void CSndWork::Func25DE60(s32 id, s32 v) {
    for (CSndUnitN *p = Func25C4B0(id); p; p = Func25C510(p)) {
        CSndObj *o = ((CSndUnitV3 *)p)->Obj();
        if (o) {
            ((u8 *)o)[2] = v;
            o->m0 |= 0x20;
        }
    }
}

void CSndWork::Func25DEF0(s32 id, s32 v) {
    for (CSndUnitN *p = Func25C4B0(id); p; p = Func25C510(p)) {
        CSndObj *o = ((CSndUnitV3 *)p)->Obj();
        if (o) {
            ((u8 *)o)[3] = v;
            o->m0 |= 0x40;
        }
    }
}

s32 CSndWorkReal::Func25DF80(s32 i) { return D_002BA780[i]; }

extern "C" void func_0025DF98(void *p, s32 x) { void *r = Func25DBF8((CSndObj2 *)p); if (r) func_0025D608((u8 *)p + 0x70, r, x); }

void *Func25DFE0(s32 n) {
    if (D_002BA248) return D_002BA248->Alloc(n);
    return Func245D00(n);
}

void Func25E030(void *p) {
    if (D_002BA248) D_002BA248->Free(p);
    else D_002B91B0(p);
}

void *Func25E088(s32 a, s32 b, s32 c, s32 d) {
    void *p = Func25DFE0(0xBC);
    Func25E290(p, a, b, c, d | 0x1000000);
    return p;
}

void *Func25E100(s32 a, s32 b, s32 c, s32 d) {
    void *p = Func25DFE0(0xBC);
    Func25E290(p, a, b, c, d);
    return p;
}

void *Func25E178(s32 a, s32 b, s32 c, s32 d) {
    u8 *p = (u8 *)Func25DFE0(0xF0);
    Func25E290(p, a, b, c, d | 0x1000000);
    *(void **)(p + 0xC) = D_vtSndUnitTg;
    Func25D478((CSndFlt *)(p + 0xC0));
    return p;
}

void *Func25E208(s32 a, s32 b, s32 c, s32 d) {
    u8 *p = (u8 *)Func25DFE0(0xF0);
    Func25E290(p, a, b, c, d);
    *(void **)(p + 0xC) = D_vtSndUnitTg;
    Func25D478((CSndFlt *)(p + 0xC0));
    return p;
}

void *Func25E290(void *p, s32 a, s32 b, s32 c, s32 d) {
    CSndUnitTgH *u = (CSndUnitTgH *)p;
    func_0025C098(p, a);
    *(void **)((u8 *)p + 0xC) = D_vtCSndUnitTg;
    new (&u->m68) CSndSub68;
    u->mB0 = ((CSndMgrV2 *)D_002BA248)->GetId(a);
    u->mB4 = b;
    u->mB8 = c;
    u->m54 = d;
    u->m50 = 1;
}
