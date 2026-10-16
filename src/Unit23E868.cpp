#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "libc.h"
s32 Func235DE0(const char *fmt, ...);
extern "C" void *memset(void *, int, unsigned int);
extern s32 D_002B9CD4;
extern volatile s32 D_002B9CD8;
extern s32 D_002B9CCC;
extern s32 D_002B9CD0;
extern s32 D_38EF48;
extern s32 D_38EF4C;
extern s32 D_002B9CDC;
extern u64 D_002B9CE0;
extern s32 D_002B8C50;
extern const char D_002E5908[];
extern const char D_002E5A88[];
extern const char D_002E5A90[];
extern const char D_002E5AB8[];
extern const char D_002E5BA8[];
extern "C" s32 func_0023E7E8(void);
extern "C" s32 func_00272E80(s32, void *, s32);
extern "C" s32 func_00273A68(s32);
extern "C" void func_00273A00(s32);
extern "C" s32 func_00272EA0(s32, s32);
extern "C" s32 func_00273630(void);
extern "C" void func_0023E988(void);
extern "C" s32 func_0023E950(void);
extern "C" s32 func_002062B8(void);
extern "C" s32 func_001F1180(void);
extern "C" s32 func_001F1200(void);
extern "C" s32 func_001F0C08(void);
extern "C" s32 func_00206088(void);
extern "C" void func_00205E20(void);
extern "C" void func_001F10C8(void *);
extern "C" s32 func_00206550(void *);
extern "C" void func_001F1150(void *);
extern "C" s32 func_00205E80(void);
extern "C" s32 func_0023EA80(void);
extern "C" void func_0023EA98(s32);
extern "C" s32 func_0023EEE8(const char *, s32, const char *);
extern "C" s32 func_0023EB68(char *, const char *);
extern "C" s32 func_0027B370(char *);
extern "C" s32 func_0027B320(void);
extern "C" void func_0023F190(void);
extern "C" void func_0023FD58(void);
extern "C" void func_0023FD78(void);
extern "C" s32 func_0023F198(void);
extern "C" s32 func_0023F770(void);
typedef void *(*AllocFn)(s32);
extern AllocFn D_002B91A4;
struct Ent1C { s32 m0, m4, m8, mC, m10, m14, m18; };
extern Ent1C *D_002B9CF8;
extern s32 D_002B9CF4;
struct HEnt { s32 m0, m4; HEnt *m8; s32 mC, m10; };
extern HEnt **D_002B9D00;
extern s32 D_002B9CFC;
struct Ch14 { s16 m0, m2, m4, m6; u8 pad8[0xC]; s16 m14; };
extern u64 *D_38EF54;
extern s32 D_38EF50;
extern "C" s32 func_0023FB60(s32, Ch14 *);
extern "C" void func_0023F1C0(s32, Ch14 *);
extern s32 *D_38EF74;
extern s32 D_38EF78;
extern s32 *D_38EF7C;
extern "C" void func_0023FE98(void);

struct FEnt { s32 m0, m4, m8, mC, m10, m14, m18, m1C; u64 m20; };
static inline FEnt *FGet(s32 i) {
    if (i >= 0 && i <= D_38EF78 - 1) {
        FEnt *v = (FEnt *)D_38EF74[i];
        if (v) return v;
    }
    return 0;
}
typedef void (*FreeFn)(void *);
extern FreeFn D_002B91B0;
extern "C" void func_00240C10(void);
extern "C" void func_00240AA8(s32);
extern "C" u64 func_0023AA40(s32);
extern "C" u64 func_0023BD80(s32);
extern "C" void func_0023E088(u64);
extern "C" u64 func_0023F1B0(void);
extern s32 D_002B9CE8;
extern s32 D_002B9CEC;
extern s32 D_002B9CF0;
struct LHead { LHead *m0; LHead *m4; };
extern LHead D_38EF58;

typedef void (*LoadFn)(char *, char *);
struct FsObj { LoadFn m0; };
extern "C" void *func_00232A50(void);
extern "C" FsObj *func_00230460(void *);
extern "C" char *func_00232D90(void *);
extern "C" char *func_00232C40(void *);
extern "C" void func_00273420(s32);
extern "C" s32 func_002363B0(const char *, s32);
extern "C" s32 func_00236400(s32);
extern "C" void func_00275268(void);
extern "C" void func_0027C380(char *, s32, char **);
extern const char D_002E5930[];
extern const char D_002E5958[];
extern const char D_002E5968[];
extern const char D_002E5978[];
extern const char D_002E5988[];
extern const char D_002E59B0[];
extern const char D_002E59D8[];
extern const char D_002E5A08[];
extern const char D_002E5A30[];
extern const char D_002E5A50[];
extern const char D_002E5A60[];
extern "C" s32 func_002364E8(s32, s32, s32);
extern "C" s32 func_00236438(s32, void *, s32);
extern "C" s32 func_0027AE40(char *, s32, const char *);
inline void StrAdd(char *d, const char *s) { strcpy(d + strlen(d), s); }

extern "C" void *func_002303E0(const char *);
extern "C" s32 func_0022DD20(void);
extern "C" s32 func_00240038(s32, void *, void *);
extern const char D_002E5DB8[];
extern const char D_002E5DE0[];
struct FEnt2 { FEnt2 *m0; s32 m4, m8, mC, m10, m14, m18; void *m1C; u64 m20; u8 pad28[0xC]; void *m34; void *m38; };
void Func23B1D0(int);

struct Glyph { u16 m0; u16 m2; u16 m4; u16 m6; u8 m8, m9, mA, mB, mC, mD, mE, mF, m10, m11; s16 m12; u16 m14; u16 m16; };
struct SrcGlyph { u16 m0; u8 m2, m3; u16 m4; u16 m6; u8 m8, m9; u8 padA[2]; };
struct FEnt3 { u8 pad[0x30]; s32 m30; Glyph *m34; };
struct FontCtx { u8 pad[0x50]; u8 m50; };
extern const char D_002E5BE0[];

extern "C" HEnt *func_0023FAF0(s32 key);
extern "C" void func_0023FA98(s32 key);
extern "C" void func_0023FA58(HEnt *e);
struct GEnt { GEnt *m0; GEnt *m4; GEnt *m8; u32 mC; s32 m10; s16 m14; s16 m16; Ch14 *m18; };
inline void GIns(GEnt *h, GEnt *e) { e->m0 = h; e->m4 = h->m4; h->m4 = e; e->m4->m0 = e; }
inline void GUnl(GEnt *e) { e->m0->m4 = e->m4; e->m4->m0 = e->m0; }
// @decl-end

extern "C" void func_0023E868(void) {
    if (++D_002B9CD4 == 1) {
        D_002B9CD8 = 0;
        D_38EF48 = 0;
        D_38EF4C = 0;
        D_002B9CCC = func_00272E80(2, (void *)func_0023E7E8, -1);
        func_00273A68(2);
        *(volatile u32 *)0x10000010 = 0x8B;
        *(volatile u32 *)0x10000000 = 0;
    }
}

extern "C" void func_0023E8F0(void) {
    if (D_002B9CD4 > 0 && --D_002B9CD4 == 0) {
        func_00273A00(2);
        func_00272EA0(2, D_002B9CCC);
        D_002B9CCC = -1;
    }
}

extern "C" s32 func_0023E950(void) {
    s32 v = D_002B9CD8;
    s32 w = D_38EF4C;
    s32 r = *(volatile u32 *)0x10000000;
    D_38EF48 = v;
    r += w;
    *(volatile u32 *)0x10000000 = 0;
    D_38EF4C = 0;
    return r;
}

extern "C" void func_0023E988(void) {
    s32 v = D_002B9CD8;
    if (v == 0) return (void)func_00273630();
    while (v == D_002B9CD8);
}

extern "C" s32 func_0023E9D8(void) {
    return D_002B9CD0;
}

extern "C" s32 func_0023E9E8(s32 n) {
    if (n == 0) {
        func_0023E988();
        return func_0023E950();
    }
    if (n == 1) return func_0023E950();
    if (n > 0) {
        n += D_38EF48; while ((u32)D_002B9CD8 < (u32)n);
        return func_0023E950();
    }
    return D_002B9CD8;
}

extern "C" s32 func_0023EA80(void) {
    return func_002062B8();
}

extern "C" void func_0023EA98(s32 x) {
    if (func_001F1180() != 1) return;
    if (func_001F1200() != 0) return;
    if (func_001F0C08() != 0) return;
    if (func_00206088() & 2) return (void)Func235DE0(D_002E5908, x);
}

extern "C" s32 func_0023EB18(void) {
    func_00205E20();
    func_001F10C8((void *)func_0023EA80);
    return func_00206550((void *)func_0023EA98);
}

extern "C" s32 func_0023EB48(void) {
    func_001F1150((void *)func_0023EA80);
    return func_00205E80();
}

extern "C" s32 func_0023EB68(char *out, const char *name) {
    char buf[256];
    FsObj *o;
    if (!name) return 0;
    o = func_00230460(func_00232A50());
    buf[0] = 0;
    if (*func_00232D90(func_00232A50()) != '/' && *name != '/') strcpy(buf, func_00232C40(func_00232A50()));
    if (*name != '/') StrAdd(buf, func_00232D90(func_00232A50()));
    StrAdd(buf, name);
    if (o->m0 == 0) return 0;
    o->m0(out, buf);
    func_00273420(0);
    return 1;
}

extern "C" s32 func_0023EC70(const char *name, s32 argc, char **argv) {
    char path[256];
    s32 fd, i;
    if (!func_0023EB68(path, name)) return -2;
    fd = func_002363B0(path, 1);
    if (fd < 0) {
        if (D_002B8C50) Func235DE0(D_002E5930, path);
        return -2;
    }
    func_00236400(fd);
    Func235DE0(D_002E5958, path);
    Func235DE0(D_002E5968, argc);
    for (i = 0; i < argc; i++) Func235DE0(D_002E5978, i, argv[i]);
    func_00275268();
    func_0027C380(path, argc, argv);
    return -1;
}

extern "C" s32 func_0023ED90(const char *name, void *buf) {
    char path[256];
    s32 fd, size, n;
    if (!func_0023EB68(path, name)) return -2;
    fd = func_002363B0(path, 1);
    if (fd < 0) {
        if (D_002B8C50) Func235DE0(D_002E5930, path);
        return -2;
    }
    size = func_002364E8(fd, 0, 2);
    if (size < 0) {
        func_00236400(fd);
        if (D_002B8C50) Func235DE0(D_002E5988, path);
        return -1;
    }
    func_002364E8(fd, 0, 0);
    n = func_00236438(fd, buf, size + 0x80);
    if (n < 0) {
        func_00236400(fd);
        if (D_002B8C50) Func235DE0(D_002E59B0, path);
        return -1;
    }
    func_00236400(fd);
    func_00273420(0);
    if (D_002B8C50) Func235DE0(D_002E59D8, path, size, n);
    return size;
}

extern "C" s32 func_0023EEE8(const char *name, s32 len, const char *args) {
    char path[256];
    s32 fd, i, k;
    if (!func_0023EB68(path, name)) return 0;
    fd = func_002363B0(path, 1);
    if (fd < 0) {
        if (D_002B8C50) Func235DE0(D_002E5A08, path);
        return 0;
    }
    func_00236400(fd);
    if (D_002B8C50) Func235DE0(D_002E5A30, path);
    for (i = 0, k = 0; k < len; i++) {
        if (D_002B8C50) Func235DE0(D_002E5A50, i, &args[k]);
        k += strlen(&args[k]) + 1;
    }
    if (func_0027AE40(path, len, args) >= 0) return 1;
    if (D_002B8C50) Func235DE0(D_002E5A60, path);
    return 0;
}

extern "C" s32 func_0023F030(const char **list, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        if (func_0023EEE8(list[i], 0, D_002E5A88) == 0) return 0;
    }
    return 1;
}

extern "C" s32 func_0023F0A8(const char *name) {
    char buf[256];
    if (!func_0023EB68(buf, name)) return 0;
    if (func_0027B370(buf) == 0) {
        if (D_002B8C50) Func235DE0(D_002E5A90, buf);
        return 0;
    }
    while (!func_0027B320());
    if (D_002B8C50) Func235DE0(D_002E5AB8, buf);
    return 1;
}

extern "C" void func_0023F130(void) {
    func_0023F190();
    return func_0023FD58();
}

extern "C" void func_0023F150(void) {
    func_0023FD78();
    return (void)func_0023F198();
}

extern "C" void func_0023F170(s32 v) {
    D_002B9CDC = v;
}

extern "C" s32 func_0023F180(void) {
    return D_002B9CDC;
}

extern "C" void func_0023F190(void) {
}

extern "C" s32 func_0023F198(void) {
    return func_0023F770();
}

extern "C" u64 func_0023F1B0(void) {
    return D_002B9CE0;
}

INCLUDE_ASM("asm/nonmatchings/Unit23E868", func_0023F1C0);

INCLUDE_ASM("asm/nonmatchings/Unit23E868", func_0023F458);

INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5908);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5930);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5958);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5968);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5978);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5988);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E59B0);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E59D8);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5A08);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5A30);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5A50);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5A60);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5A88);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5A90);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5AB8);
INCLUDE_ASM("asm/nonmatchings/Unit23E868", func_0023F4A8);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5BA8);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5BE0);

INCLUDE_ASM("asm/nonmatchings/Unit23E868", func_0023F770);

extern "C" void func_0023F848(void) {
    s32 i;
    for (i = 0; i < D_002B9CF4; i++) D_002B9CF8[i].mC = 0;
    for (i = 0; i < D_002B9CFC; i++) D_002B9D00[i] = 0;
}

INCLUDE_ASM("asm/nonmatchings/Unit23E868", func_0023F8E0);

extern "C" void func_0023FA58(HEnt *e) {
    HEnt **pp = &D_002B9D00[e->m10 % D_002B9CFC];
    e->m8 = *pp;
    *pp = e;
}

extern "C" void func_0023FA98(s32 key) {
    HEnt **pp = &D_002B9D00[key % D_002B9CFC];
    HEnt *e;
    while ((e = *pp) != 0) {
        if (e->m10 == key) {
            *pp = e->m8;
            break;
        }
        pp = &e->m8;
    }
}

extern "C" HEnt *func_0023FAF0(s32 key) {
    HEnt *e = D_002B9D00[key % D_002B9CFC];
    while (e) {
        if (e->m10 == key) return e;
        e = e->m8;
    }
    return e;
}

extern "C" s32 func_0023FB60(s32 a, Ch14 *c) {
    s32 key = (a << 16) | (u16)c->m0;
    GEnt *e = (GEnt *)func_0023FAF0(key);
    GEnt *h;
    if (!e) {
        e = (GEnt *)D_38EF58.m0;
        if (e->mC & 1) return 0;
        if (e->mC & 4) func_0023FA98(e->m10);
        e->m10 = key;
        func_0023FA58((HEnt *)e);
        e->m16 = a;
        e->mC = (e->mC | 4) & ~2;
        e->m18 = c;
        s32 odd = c->m14;
        c->m4 = (e->m14 % D_002B9CE8) * D_002B9CEC + (odd & 1);
        c->m6 = (e->m14 / D_002B9CE8) * D_002B9CF0;
    }
    e->mC |= 1;
    GUnl(e);
    GIns((GEnt *)&D_38EF58, e);
    return (s32)e;
}

INCLUDE_ASM("asm/nonmatchings/Unit23E868", func_0023FCB8);

extern "C" void func_0023FD58(void) {
    D_38EF74 = 0;
    D_38EF78 = 0;
    D_38EF7C = 0;
}

extern "C" void func_0023FD78(void) {
    return func_0023FE98();
}

extern "C" s32 func_0023FD90(s32 i) {
    if (i >= 0 && i <= D_38EF78 - 1) {
        s32 v = D_38EF74[i];
        if (v) return v;
    }
    return 0;
}

extern "C" s32 func_0023FDD8(s32 i) {
    return D_38EF74[i];
}

extern "C" void func_0023FDF0(s32 n) {
    s32 **pp = &D_38EF74;
    s32 sz;
    func_0023FE98();
    sz = n * 4;
    *pp = (s32 *)D_002B91A4(sz);
    if (*pp == 0) {
        if (D_002B9CDC & 1) return (void)Func235DE0(D_002E5BA8, n);
        return;
    }
    memset(*pp, 0, sz);
    D_38EF78 = n;
}

extern "C" void func_0023FE98(void) {
    if (D_38EF74) {
        func_00240C10();
        D_002B91B0(D_38EF74);
        D_38EF74 = 0;
        D_38EF78 = 0;
    }
}

extern "C" Glyph *func_0023FEE8(FontCtx *ctx, s32 *src, s32 f) {
    Glyph *g0 = (Glyph *)D_002B91A4(src[0] * 24);
    Glyph *g;
    SrcGlyph *s;
    s32 i;
    if (!g0) {
        if (D_002B9CDC & 1) Func235DE0(D_002E5BE0, src[0]);
        return 0;
    }
    s = (SrcGlyph *)(src + 1);
    g = g0;
    for (i = 0; i < src[0]; i++, s++, g++) {
        g->m0 = s->m0;
        g->mA = s->m8;
        g->mB = ctx->m50;
        g->m4 = s->m4;
        g->m6 = s->m6;
        g->m8 = s->m8;
        g->m9 = s->m9;
        if (!f) g->mC = s->m2;
        else g->mC = 0;
        g->mD = s->m3;
        g->mE = g->mC + s->m8;
        g->mF = g->mD + s->m9;
        g->m10 = s->m2;
        g->m11 = s->m3;
        g->m12 = i;
        g->m14 = s->m4;
        g->m16 = s->m6;
    }
    return g0;
}

INCLUDE_ASM("asm/nonmatchings/Unit23E868", func_00240038);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5DB8);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5DE0);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5E00);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5E08);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5E10);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5E18);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5E20);
INCLUDE_RODATA("asm/nonmatchings/Unit23E868", D_002E5E28);

extern "C" s32 func_002409C0(s32 a, const char *n1, const char *n2) {
    s32 r = -1;
    void *f1 = func_002303E0(n1);
    void *f2 = 0;
    if (f1 == 0 || (f2 = func_002303E0(n2)) == 0) {
        if (D_002B9CDC & 1) Func235DE0(D_002E5DB8, func_0022DD20());
    } else {
        s32 v = func_00240038(a, f1, f2);
        if (v >= 0) r = v;
    }
    if (f1) D_002B91B0(f1);
    if (f2) D_002B91B0(f2);
    return r;
}

extern "C" void func_00240AA8(s32 id) {
    FEnt2 *e = (FEnt2 *)FGet(id);
    FEnt2 **pp;
    FEnt2 *n;
    if (!e) return;
    pp = (FEnt2 **)&D_38EF7C;
    for (n = *pp; n; n = n->m0) {
        if (n == e) {
            if (D_002B9CDC & 4) Func235DE0(D_002E5DE0, n->m4);
            *pp = n->m0;
            D_38EF74[n->m4] = 0;
            if (n->m18 >= 0) Func23B1D0(n->m18);
            if (n->m1C) D_002B91B0(n->m1C);
            if (n->m20) func_0023E088(n->m20);
            if (n->m34) D_002B91B0(n->m34);
            if (n->m38) D_002B91B0(n->m38);
            D_002B91B0(n);
            return;
        }
        pp = &n->m0;
    }
}

extern "C" void func_00240C10(void) {
    if (D_38EF7C) {
        while (D_38EF7C) func_00240AA8(D_38EF7C[1]);
    }
}

extern "C" s32 func_00240C60(s32 i) {
    FEnt *e = FGet(i);
    s32 r = -1;
    if (e) r = e->mC;
    return r;
}

extern "C" s32 func_00240CB8(s32 i) {
    FEnt *e = FGet(i);
    s32 r = -1;
    if (e) r = e->m10;
    return r;
}

extern "C" s32 func_00240D10(s32 i) {
    FEnt *e = FGet(i);
    s32 r = -1;
    if (e) r = e->m14;
    return r;
}


extern "C" u64 func_00240D68(s32 h)
{
    FEnt *e = FGet(h);
    u64 r = 0;
    if (e) {
        if (e->m8 & 4) return func_0023F1B0();
        if (e->m18 < 0) return 0;
        r = func_0023AA40(e->m18);
    }
    return r;
}


extern "C" u64 func_00240DF0(s32 h)
{
    FEnt *e = FGet(h);
    u64 r = 0;
    if (e) {
        if (e->m8 & 4) return e->m20;
        if (e->m18 < 0) return 0;
        r = func_0023BD80(e->m18);
    }
    return r;
}

extern "C" s32 func_00240E78(s32 i) {
    FEnt *e = FGet(i);
    s32 r = -1;
    if (e) r = (e->m8 >> 2) & 1;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/Unit23E868", func_00240ED8);
