#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" int strcmp(const char *, const char *);
struct BankEnt { u8 m0; u8 m1; u8 m2; u8 m3; s32 m4; s32 *m8; s32 *mC; s32 *m10; s32 *m14; char *m18; s32 m1C; s32 m20; s32 m24; char m28[0x40]; char m68[0x40]; };
extern BankEnt D_324B00[256];
extern "C" BankEnt *func_0020E758(u32);
extern "C" s32 *func_0020E798(u32, s32) throw();  // nothrow in retail (same TU as Unit20CBF0's end?)
struct E808 { s16 m0; s16 m2; s16 m4; s16 m6; };
extern "C" E808 *func_0020E808(u32, s32);
extern "C" void *func_0020EF18(u32, s32, s32);
extern "C" void *func_0020F038(u32, s32, s32);
extern "C" s32 *func_0020ECC0(s32 *, s32);
inline BankEnt *GetBank(u32 i) {
    BankEnt *e;
    if (i < 256) {
        e = &D_324B00[i];
        if (e->m0) goto found;
    }
    return 0;
found:
    return e;
}
struct Tb { s32 n; s32 off[1]; };
struct Tb2 { s32 m0; s32 n; s32 off[1]; };
struct Strm;
struct StrmOps { s32 m0; s32 m4; s32 m8; s32 (*open)(Strm *); void (*close)(s32, s32); s32 (*f14)(s32); void (*f18)(s32); s32 (*f1C)(s32); };
struct Strm {
    Strm *next; StrmOps *ops; s32 m8; s32 mC; s32 m10; s32 m14;
    u8 m18; u8 m19; u8 m1A; u8 m1B; u8 m1C; u8 m1D; u8 m1E; u8 m1F;
    s16 m20; s16 m22; f32 m24; f32 m28; s32 m2C; s32 m30; s32 m34; s32 m38; s32 m3C; s32 m40; s32 m44; s32 m48; s32 m4C;
    s32 m50; s32 m54; s32 m58; s16 m5C[16]; s16 m7C[16];
};
struct FmtOps { void (*init)(void); void (*f4)(void); void (*f8)(void); s32 mC; s32 m10; s32 m14; s32 m18; s32 m1C; };
struct Fmt { Fmt *next; s32 m4; FmtOps ops; };
struct SndStr { Strm e[64]; Strm *active; Strm *free; s16 m2708; s16 m270A; Fmt fmt[8]; Fmt *fmtList; };
extern SndStr D_32F300;
struct Ent12 { Ent12 *next; u8 m4; u8 m5; u8 pad6[6]; };
struct S331B50 { Ent12 e[64]; Ent12 *active; Ent12 *free; };
extern S331B50 D_331B50;
inline u8 Used(Strm *s) { return s->m19 & 1; }
extern "C" void func_00211438(const char *);
extern "C" s32 func_00211428(void);
void Func235DE0(const char *, ...);
extern const char D_002E34C8[];
extern const char D_002E34F0[];
extern const char D_002E3500[];
extern "C" void func_0020F370(u32, s32, s32);
extern "C" void func_0020FA60(u32, s32);
extern "C" void func_0020F3C8(s32, s32, s32);
extern "C" void func_0020F468(s32, s32);
extern "C" void func_0020F498(s32);
extern "C" void func_002101B0(s32, s32);
extern "C" s32 func_00210070(s32, const char *, s32, s32);
extern "C" s32 func_0022DBF8(s32);
extern "C" void func_0022DCE0(void);
extern "C" void func_0022DC90(const char *);
extern "C" void func_0022DD00(void);
extern "C" s32 func_00210018(const char *, s32, s32);
extern "C" s32 func_00210048(s32, s32);
extern const char D_002E3400[];
extern const char D_002E3440[];
extern const char D_002E3478[];
extern const char D_002E3498[];
extern "C" u8 *func_0020EBF8(u32, s32);
extern "C" s32 func_0020F0D8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

inline u32 GetSR() { u32 r; __asm__ volatile("sync.p"); __asm__ volatile("mfc0 %0, $12" : "=r"(r)); __asm__ volatile("sync.p"); return r; }
inline void SetSR(u32 v) { __asm__ volatile("sync.p"); __asm__ volatile("mtc0 %0, $12" : : "r"(v)); __asm__ volatile("sync.p"); }
inline void SetSRWait(u32 v) { do SetSR(v); while (GetSR() != v); }
inline u32 DisableIntr() { u32 st; __asm__ volatile("sync.p"); __asm__ volatile("sync"); st = GetSR(); SetSRWait(st & ~1); return st; }
inline void RestoreIntr(u32 st) { __asm__ volatile("sync.p"); __asm__ volatile("sync"); SetSRWait(st); }

inline u8 Flags(Strm *s) { return s->m19; }
// @decl-end
INCLUDE_RODATA("asm/nonmatchings/Unit20E938", D_002E3400);
INCLUDE_RODATA("asm/nonmatchings/Unit20E938", D_002E3440);
INCLUDE_RODATA("asm/nonmatchings/Unit20E938", D_002E3478);
INCLUDE_RODATA("asm/nonmatchings/Unit20E938", D_002E3498);
INCLUDE_RODATA("asm/nonmatchings/Unit20E938", D_002E34C8);
INCLUDE_RODATA("asm/nonmatchings/Unit20E938", D_002E34F0);
INCLUDE_RODATA("asm/nonmatchings/Unit20E938", D_002E3500);

extern "C" s32 func_0020E938(u32 a, s32 k, const char *name) {
    BankEnt *e;
    s32 *t;
    s32 i;
    if ((e = func_0020E758(a)) == 0 || (t = func_0020E798(a, k)) == 0) return 0;
    for (i = 0; i < t[1]; i++) {
        char *s = e->m18 + t[2 + i];
        if (!strcmp(s + 8, name)) return i;
    }
    return -1;
}

extern "C" void func_0020E9F8(u32 id, s32 k, s32 c, s32 *w, s32 *h) {
    E808 *p;
    if (w) *w = 0x80;
    if (h) *h = 0x80;
    p = func_0020E808(id, k);
    if (!p) return;
    if (w) *w = p->m4;
    if (h) *h = p->m6;
}

extern "C" void func_0020EA70(void) {
    s32 i;
    for (i = 0; i < 256; i++) D_324B00[i].m0 = 0;
}

extern "C" void func_0020EAB0(void) {
}

extern "C" void func_0020EAB8(void) {
}

extern "C" s32 func_0020EAC0(u32 id, s32 a, s32 b) {
    BankEnt *e;
    s32 ret = -1;
    s32 old;
    if (id < 256) {
        e = &D_324B00[id];
        if (e->m0) goto found;
    }
    return -1;
found:
    switch (e->m2) {
    case -1:
        if (func_00211428() & 1) Func235DE0(D_002E3400, id);
        break;
    case 1:
        old = func_0022DBF8(e->m24);
        func_0022DCE0();
        func_0022DC90(0);
        func_0022DC90(e->m28);
        ret = func_00210018(e->m68, a, b);
        func_0022DD00();
        func_0022DBF8(old);
        break;
    case 0:
        ret = func_00210048(e->m1C, e->m20);
        break;
    }
    return ret;
}

extern "C" u8 *func_0020EBF8(u32 id, s32 k) {
    BankEnt *e;
    s32 *t;
    u8 *p;
    s32 i;
    if (id < 256 && (e = &D_324B00[id])->m0 && (t = e->m8) && k >= 0 && !(t[0] - 1 < k)) goto found;
    return 0;
found:
    p = (u8 *)(t + 1);
    for (i = 0; i < k; i++) p += p[1];
    return p;
}

extern "C" void *func_0020EC90(u32 id, s32 a, s32 b) {
    return func_0020EF18(id, a, b);
}

extern "C" void *func_0020ECA8(u32 id, s32 a, s32 b) {
    return func_0020F038(id, a, b);
}

extern "C" s32 *func_0020ECC0(s32 *h, s32 id) {
    s32 off;
    s32 *p;
    for (off = 0; off < h[1]; off += p[1] + 0x10) {
        char *d = (char *)(h + 4);
        p = (s32 *)(d + off);
        if (p[0] == id) return p;
    }
    return 0;
}

extern "C" s32 *func_0020ED08(s32 *h, s32 id) {
    s32 *p = func_0020ECC0(h, id);
    if (p) return p + 4;
    return 0;
}

extern "C" s32 func_0020ED38(u32 id) {
    BankEnt *e;
    s32 *t;
    if (id < 256 && (e = &D_324B00[id])->m0 && (t = e->m8)) goto found;
    return 0;
found:
    return t[0];
}

extern "C" u8 *func_0020ED88(u32 id, s32 k) {
    BankEnt *e;
    s32 *t;
    u8 *p;
    s32 i;
    if (id < 256 && (e = &D_324B00[id])->m0 && (t = e->m8) && k >= 0 && !(t[0] - 1 < k)) goto found;
    return 0;
found:
    p = (u8 *)(t + 1);
    for (i = 0; i < k; i++) p += p[1];
    return p;
}

extern "C" void *func_0020EE20(u32 id, s32 k) {
    BankEnt *e;
    Tb *t;
    if (id < 256 && (e = &D_324B00[id])->m0 && (t = (Tb *)e->mC) && k >= 0 && !(t->n - 1 < k)) goto found;
    return 0;
found:
    return (char *)t + t->off[k];
}

extern "C" s32 func_0020EE98(u32 id, s32 k) {
    BankEnt *e;
    Tb2 *t;
    if (id < 256 && (e = &D_324B00[id])->m0 && (t = (Tb2 *)e->m10) && k >= 0 && !(t->n - 1 < k)) goto found;
    return 0;
found:
    return *(s32 *)((char *)t + t->off[k]);
}

extern "C" void *func_0020EF18(u32 id, s32 k, s32 j) {
    BankEnt *e;
    Tb2 *t;
    Tb *s;
    if (id < 256 && (e = &D_324B00[id])->m0 && (t = (Tb2 *)e->m10) && k >= 0 && !(t->n - 1 < k)) goto found;
    return 0;
found:
    s = (Tb *)((char *)t + t->off[k]);
    if (j < 0 || s->n - 1 < j) return 0;
    return (char *)t + s->off[j];
}

extern "C" s32 func_0020EFB8(u32 id, s32 k) {
    BankEnt *e;
    Tb2 *t;
    if (id < 256 && (e = &D_324B00[id])->m0 && (t = (Tb2 *)e->m14) && k >= 0 && !(t->n - 1 < k)) goto found;
    return 0;
found:
    return *(s32 *)((char *)t + t->off[k]);
}

extern "C" void *func_0020F038(u32 id, s32 k, s32 j) {
    BankEnt *e;
    Tb2 *t;
    Tb *s;
    if (id < 256 && (e = &D_324B00[id])->m0 && (t = (Tb2 *)e->m14) && k >= 0 && !(t->n - 1 < k)) goto found;
    return 0;
found:
    s = (Tb *)((char *)t + t->off[k]);
    if (j < 0 || s->n - 1 < j) return 0;
    return (char *)t + s->off[j];
}

extern "C" s32 func_0020F0D8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j) {
    u8 *p = func_0020EBF8(a, b);
    Fmt *fm;
    Strm *s;
    s32 k;
    if (p == 0 || (fm = &D_32F300.fmt[p[0]])->m4 == 0) {
        if (func_00211428() & 1) Func235DE0(D_002E3440, a, b);
        goto fail;
    }
    s = D_32F300.free;
    if (s == 0) {
        if (func_00211428() & 1) Func235DE0(D_002E3478);
        goto fail;
    }
    s->ops = (StrmOps *)&fm->ops;
    s->m8 = a;
    s->mC = b;
    s->m10 = 0;
    s->m14 = 0;
    s->m1A = 0;
    s->m1B = j;
    s->m1C = 0x26;
    s->m1D = 0;
    s->m1E = 0;
    s->m1F = 0;
    s->m20 = 0x80;
    s->m22 = 0x80;
    s->m24 = 1.0f;
    s->m28 = 1.0f;
    s->m2C = c;
    s->m50 = 0;
    s->m34 = d;
    s->m38 = e;
    s->m3C = f;
    s->m40 = g;
    s->m44 = h;
    s->m48 = i;
    s->m54 = 0;
    s->m58 = 0;
    s->m4C = -1;
    s->m30 = 0;
    for (k = 0; k < 16; k++) {
        s->m5C[k] = 0x80;
        s->m7C[k] = 0x80;
    }
    s->m4C = s->ops->open(s);
    if (s->m4C < 0) {
        if (func_00211428() & 1) Func235DE0(D_002E3498, a, b);
        goto fail;
    }
    D_32F300.free = s->next;
    s->next = D_32F300.active;
    D_32F300.active = s;
    s->m19 = 1;
    return s->m18;
fail:
    return -1;
}

extern "C" s32 func_0020F308(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i) {
    return func_0020F0D8(a, b, 0, c, d, e, f, g, h, i);
}

extern "C" s32 func_0020F358(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j) {
    return func_0020F0D8(a, b, c, d, e, f, g, h, i, j);
}

extern "C" void func_0020F370(u32 i, s32 v, s32 x) {
    Strm *s;
    if (i < 64 && Used(s = &D_32F300.e[i])) {
        s->m1E = v;
        s->m1C |= 1;
    }
}

extern "C" void func_0020F3C8(s32 id, s32 x, s32 mode) {
    Strm **pp;
    Strm *s;
    func_00211438(D_002E34C8);
    pp = &D_32F300.active;
    while ((s = *pp) != 0) {
        if (s->m18 == id) {
            *pp = s->next;
            s->next = D_32F300.free;
            D_32F300.free = s;
            s->ops->close(s->m4C, mode);
            s->m19 = 0;
            break;
        }
        pp = &s->next;
    }
}

extern "C" void func_0020F468(s32 id, s32 x) {
    func_0020F3C8(id, x, 0);
    return;
}

extern "C" void func_0020F480(s32 id, s32 x) {
    func_0020F3C8(id, x, 1);
    return;
}

extern "C" void func_0020F498(s32 x) {
    Strm *s;
    func_00211438(D_002E34F0);
    while ((s = D_32F300.active) != 0) func_0020F468(s->m18, x);
}

extern "C" void func_0020F4F8(u32 i, s32 x) {
    func_0020F370(i, 1, x);
    func_0020FA60(i, 1);
    return;
}

extern "C" u8 func_0020F530(u32 i) {
    Strm *s;
    if (i < 64 && Used(s = &D_32F300.e[i])) goto found;
    return 0;
found:
    return Flags(s);
}

extern "C" void func_0020F580(u32 i, s32 v) {
    Strm *s;
    if (i < 64 && Used(s = &D_32F300.e[i])) {
        s->m1D = v;
        s->m1C |= 2;
    }
}

extern "C" void func_0020F5D8(s32 a, s32 b) {
    Strm *s;
    D_32F300.m2708 = a;
    D_32F300.m270A = b;
    for (s = D_32F300.active; s; s = s->next) s->m1C |= 4;
}

extern "C" s16 func_0020F620(void) {
    return D_32F300.m2708;
}

extern "C" s16 func_0020F630(void) {
    return D_32F300.m270A;
}

extern "C" void func_0020F640(u32 i, s32 a, s32 b) {
    Strm *s;
    if (i < 64 && Used(s = &D_32F300.e[i])) {
        s->m20 = a;
        s->m22 = b;
        s->m1C |= 4;
    }
}

extern "C" void func_0020F698(u32 i, u32 k, s32 a, s32 b) {
    Strm *s;
    if (i < 64 && Used(s = &D_32F300.e[i]) && k < 16) {
        s->m5C[k] = a;
        s->m7C[k] = b;
        s->m1C |= 0x20;
    }
}

extern "C" void func_0020F708(u32 i, f32 v) {
    Strm *s;
    if (i < 64 && Used(s = &D_32F300.e[i])) {
        s->m24 = v;
        s->m1C |= 8;
    }
}

extern "C" void func_0020F760(u32 i, f32 v) {
    Strm *s;
    if (i < 64 && Used(s = &D_32F300.e[i])) {
        s->m28 = v;
        s->m1C |= 0x10;
    }
}

extern "C" s32 func_0020F7B8(u32 i) {
    Strm *s;
    if (i < 64 && Used(s = &D_32F300.e[i])) goto found;
    return 0;
found:
    return s->m30;
}

extern "C" s32 func_0020F808(u32 i, s32 v) {
    Strm *s;
    s32 old;
    if (i < 64 && Used(s = &D_32F300.e[i])) goto found;
    return 0;
found:
    old = s->m50;
    s->m50 = v;
    return old;
}

extern "C" s32 func_0020F858(u32 i) {
    Strm *s;
    if (i < 64 && Used(s = &D_32F300.e[i])) goto found;
    return 0;
found:
    return s->m50;
}

extern "C" s32 func_0020F8A8(u32 i, s32 v) {
    Strm *s;
    s32 old;
    if (i < 64 && Used(s = &D_32F300.e[i])) goto found;
    return 0;
found:
    old = s->m54;
    s->m54 = v;
    return old;
}

extern "C" s32 func_0020F8F8(u32 i, s32 v) {
    Strm *s;
    s32 old;
    if (i < 64 && Used(s = &D_32F300.e[i])) goto found;
    return 0;
found:
    old = s->m58;
    s->m58 = v;
    return old;
}

extern "C" s32 func_0020F948(u32 i) {
    Strm *s;
    if (i < 64 && Used(s = &D_32F300.e[i])) goto found;
    return 0;
found:
    return s->m8;
}

extern "C" s32 func_0020F998(u32 i) {
    Strm *s;
    if (i < 64 && Used(s = &D_32F300.e[i])) goto found;
    return 0;
found:
    return s->mC;
}

INCLUDE_ASM("asm/nonmatchings/Unit20E938", func_0020F9E8);

extern "C" void func_0020FA60(u32 i, s32 x) {
    Strm *s;
    if (i < 64 && Used(s = &D_32F300.e[i])) {
        if (s->ops->f18) s->ops->f18(s->m4C);
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit20E938", func_0020FAC8);

extern "C" u8 func_0020FB40(u32 i) {
    Strm *s;
    if (i < 64 && Used(s = &D_32F300.e[i])) goto found;
    return 0;
found:
    return s->m1F;
}

extern "C" void func_0020FB90(void) {
    s32 i;
    Strm *s;
    D_32F300.active = 0;
    D_32F300.free = 0;
    s = D_32F300.e;
    for (i = 0; i < 64; i++, s++) {
        s->next = D_32F300.free;
        D_32F300.free = s;
        s->m18 = i;
    }
    D_32F300.m2708 = 0x80;
    D_32F300.m270A = 0x80;
    D_32F300.fmtList = 0;
    for (i = 0; i < 8; i++) D_32F300.fmt[i].m4 = 0;
}

extern "C" void func_0020FC18(void) {
    Fmt *f;
    for (f = D_32F300.fmtList; f; f = f->next) f->ops.f4();
    func_0020F498(0);
    return;
}

extern "C" void func_0020FC60(void) {
    Fmt *f;
    Strm *s;
    Strm *c;
    for (f = D_32F300.fmtList; f; f = f->next) f->ops.f8();
    s = D_32F300.active;
    while ((c = s) != 0) {
        s = s->next;
        if ((c->m19 & 4) && c->m1B == 0) func_0020F468(c->m18, 0);
    }
}

extern "C" s32 func_0020FD00(u32 i, const char *name, FmtOps *ops) {
    Fmt *f;
    if (i < 8) {
        f = &D_32F300.fmt[i];
        if (f->m4 != 1) goto ok;
    }
    return 0;
ok:
    f->m4 = 1;
    f->ops = *ops;
    f->ops.init();
    f->next = D_32F300.fmtList;
    D_32F300.fmtList = f;
    if (func_00211428() & 4) Func235DE0(D_002E3500, name, i);
    return 1;
}

extern "C" s16 func_0020FE00(void) {
    return D_32F300.m2708;
}

extern "C" s16 func_0020FE10(void) {
    return D_32F300.m270A;
}

extern "C" void func_0020FE20(Strm *s, s32 a) {
    void (*fn)(s32, s32) = (void (*)(s32, s32))s->m54;
    u32 st;
    if (fn) {
        st = DisableIntr();
        fn(s->m18, a);
        RestoreIntr(st);
    }
}

extern "C" s32 func_0020FEC0(Strm *s, s32 a) {
    s32 (*fn)(s32, s32) = (s32 (*)(s32, s32))s->m58;
    u32 st;
    s32 r;
    if (fn) {
        st = DisableIntr();
        r = fn(s->m18, a);
        RestoreIntr(st);
    } else {
        r = 1;
    }
    return r;
}

extern "C" void func_0020FF70(void) {
    s32 i;
    Ent12 *e;
    D_331B50.active = 0;
    D_331B50.free = 0;
    e = D_331B50.e;
    for (i = 0; i < 64; i++, e++) {
        e->next = D_331B50.free;
        D_331B50.free = e;
        e->m4 = i;
        e->m5 = 0;
    }
}

extern "C" void func_0020FFC0(void) {
    Ent12 *e;
    while ((e = D_331B50.active) != 0) func_002101B0(e->m4, 0);
}

extern "C" void func_00210010(void) {
}

extern "C" s32 func_00210018(const char *a, s32 b, s32 c) {
    return func_00210070(0, a, b, c);
}

extern "C" s32 func_00210048(s32 a, s32 b) {
    return func_00210070(1, 0, a, b);
}
