#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "sceMpeg.h"
struct Q4 { s32 m0, m4, m8, mC, m10; };
extern "C" s32 func_002669C0(s32, s32, s32, s32, s32);
extern "C" s32 func_00267A98(SceMpeg *, s32 *);

extern "C" s32 func_002683F8(MpegSys *, s32, s32);
extern "C" s32 func_00267CA0(SceMpeg *);
extern "C" s32 func_00267FC0(SceMpeg *, s32, s32);
extern "C" s32 func_00267E58(SceMpeg *, s32, s32);
extern "C" s32 func_00268290(MpegSys *);
extern "C" void func_002681A0(MpegSys *);
extern "C" void func_002662A8(const char *, ...);
extern "C" s32 func_002760B0(void *, s32, s32, void *, s32, void *, s32, void *, void *);
extern u8 D_41C160[];
extern s32 D_41C1C0[];
extern const char D_002E9418[];

extern "C" s32 func_002760B0(void *, s32, s32, void *, s32, void *, s32, void *, void *);
extern u8 D_41C0C0[];
extern u8 D_41C0E8[];
extern u8 D_41C110[];
extern u8 D_41C138[];
extern s32 D_41C1C0[];
extern const char D_002E9388[];
extern const char D_002E93A8[];
extern const char D_002E93C8[];
extern const char D_002E93F0[];
extern "C" s32 func_0026E5D8(void *, s32);
extern "C" s32 func_0026E520(void *, s32);
extern "C" s32 func_002683A0(MpegSys *, const char *);
extern const char D_002E94A8[];
struct Reg64 { u64 m0; u64 m8; };
extern Reg64 D_002BD7A8[];

extern "C" u32 strlen(const char *);
extern "C" void *memcpy(void *, const void *, u32);
extern u8 D_41B080[];
extern "C" void func_002731D0(s32);
extern s32 D_002BD790;
extern "C" s32 func_0027BD20(void);
extern "C" s32 func_0027BD78(void);
extern "C" s32 func_0027E578(void);
#define UNCACHED(p) ((u32)(p) | 0x20000000)

struct SifClient { u8 pad0[0x24]; s32 m24; };
extern SifClient D_41AAC0;
extern s32 D_41AB40[];
extern s32 D_41C080[];
extern s32 D_002BD788;
extern s32 D_002BD78C;
extern "C" s32 func_002731F0(s32);
extern "C" s32 func_002731C0(s32);
extern "C" void func_00264CF8(void);

extern s32 D_41AB70[];
extern "C" char *func_0028B728(char *, const char *, u32);

extern "C" void func_00275698(void *, s32);
extern "C" void func_00265918(char *);

extern "C" s32 func_00267CA0(SceMpeg *);

struct McTbl { u8 pad[0x20]; char name[0x20]; };
extern McTbl D_41AB00;
extern "C" void func_00273420(s32);
extern "C" s32 func_0026E628(void *);
struct PackHdr { s32 m0; u32 m4; s32 m8; s32 mC; };
extern "C" s32 func_00266F38(void *, void *);

extern "C" s32 func_00275748(s32);
extern "C" s32 func_00275EE0(void *, u32, s32);
extern "C" s32 func_00274F10(const char *, ...);
extern const char D_002E9318[];
extern const char D_002E9330[];
extern const char D_002E9358[];
extern "C" s32 func_002666D0(void);

extern "C" u64 func_00266738(u32, u64);
struct StrEnt { u64 id; u64 m8; s32 m10; s32 m14; void *m18; s32 m1C; };
// @decl-end

extern "C" void func_00265918(char *dst) {
    if (dst) {
        u32 n;
        if (strlen((char *)UNCACHED(D_41B080)) < 0x400) n = strlen((char *)UNCACHED(D_41B080)); else n = 0x3FF;
        memcpy(dst, (char *)UNCACHED(D_41B080), n);
        dst[n] = 0;
    }
    func_002731D0(D_002BD790);
}

extern "C" s32 func_002659A8(s32 port, s32 slot, const char *name, s32 arg) {
    s32 r;
    if (!D_41AAC0.m24) return -100;
    if (func_002731F0(D_002BD78C) < 0) return -200;
    if (!name || !*name) { func_002731C0(D_002BD78C); return -210; }
    D_41AB70[0] = port; D_41AB70[4] = (s32)D_41B080; D_41AB70[1] = slot;
    func_0028B728((char *)&D_41AB70[5], name, 0x3FF);
    ((char *)D_41AB70)[0x413] = 0;
    func_00275698(D_41B080, 0x400);
    r = func_002760B0(&D_41AAC0, 0xC, 1, D_41AB70, 0x414, D_41C080, 4, (void *)func_00265918, (void *)arg);
    if (r == 0) D_002BD788 = 0xC; else func_002731C0(D_002BD78C);
    return r;
}

extern "C" s32 func_00265AE8(s32 x, s32 y) {
    s32 r;
    if (!D_41AAC0.m24) return -100;
    if (func_002731F0(D_002BD78C) < 0) return -200;
    D_41AB40[1] = x; D_41AB40[2] = y;
    r = func_002760B0(&D_41AAC0, 0x10, 1, D_41AB40, 0x30, D_41C080, 4, (void *)func_00264CF8, 0);
    if (r == 0) D_002BD788 = 0x10; else func_002731C0(D_002BD78C);
    return r;
}

extern "C" s32 func_00265BB8(s32 port, s32 slot, const char *name) {
    s32 r;
    if (!D_41AAC0.m24) return -100;
    if (func_002731F0(D_002BD78C) < 0) return -200;
    if (!name || !*name) { func_002731C0(D_002BD78C); return -210; }
    func_0028B728((char *)&D_41AB70[5], name, 0x3FF);
    D_41AB70[0] = port; D_41AB70[1] = slot;
    ((char *)D_41AB70)[0x413] = 0;
    D_41AB70[2] = 0;
    r = func_002760B0(&D_41AAC0, 0xF, 1, D_41AB70, 0x414, D_41C080, 4, (void *)func_00264CF8, 0);
    if (r == 0) D_002BD788 = 0xF; else func_002731C0(D_002BD78C);
    return r;
}

extern "C" s32 func_00265CD8(s32 x) {
    s32 r;
    if (!D_41AAC0.m24) return -100;
    if (func_002731F0(D_002BD78C) < 0) return -200;
    D_41AB40[0] = x;
    r = func_002760B0(&D_41AAC0, 0xA, 1, D_41AB40, 0x30, D_41C080, 4, (void *)func_00264CF8, 0);
    if (r == 0) D_002BD788 = 0xA; else func_002731C0(D_002BD78C);
    return r;
}

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00265D98);

extern "C" s32 func_00265F68(s32 port, s32 slot, const char *name, const char *newname) {
    s32 r;
    if (!D_41AAC0.m24) return -100;
    if (func_002731F0(D_002BD78C) < 0) return -200;
    if (!name || !*name || !newname) { func_002731C0(D_002BD78C); return -210; }
    D_41AB70[0] = port; D_41AB70[1] = slot; D_41AB70[2] = 0x10;
    func_0028B728((char *)&D_41AB70[5], name, 0x3FF);
    ((char *)D_41AB70)[0x413] = 0;
    func_0028B728(D_41AB00.name, newname, 0x20);
    D_41AB00.name[0x1F] = 0;
    D_41AB70[4] = (s32)&D_41AB00;
    func_00273420(0);
    r = func_002760B0(&D_41AAC0, 0xE, 1, D_41AB70, 0x414, D_41C080, 4, (void *)func_00264CF8, 0);
    if (r == 0) D_002BD788 = 0x13; else func_002731C0(D_002BD78C);
    return r;
}

extern "C" s32 func_002660C8(s32 x, s32 y) {
    s32 r;
    if (!D_41AAC0.m24) return -100;
    if (func_002731F0(D_002BD78C) < 0) return -200;
    D_41AB40[1] = x; D_41AB40[2] = y;
    r = func_002760B0(&D_41AAC0, 0x11, 1, D_41AB40, 0x30, D_41C080, 4, (void *)func_00264CF8, 0);
    if (r == 0) D_002BD788 = 0x11; else func_002731C0(D_002BD78C);
    return r;
}

extern "C" s32 func_00266198(s32 port, s32 slot, const char *name) {
    s32 r;
    if (!D_41AAC0.m24) return -100;
    if (func_002731F0(D_002BD78C) < 0) return -200;
    if (!name || !*name) { func_002731C0(D_002BD78C); return -210; }
    D_41AB70[0] = port; D_41AB70[1] = slot;
    func_0028B728((char *)&D_41AB70[5], name, 0x3FF);
    ((char *)D_41AB70)[0x413] = 0;
    r = func_002760B0(&D_41AAC0, 0x12, 1, D_41AB70, 0x414, D_41C080, 4, (void *)func_00264CF8, 0);
    if (r == 0) D_002BD788 = 0x12; else func_002731C0(D_002BD78C);
    return r;
}

extern "C" void func_002662A8(const char *fmt, ...) { }

extern "C" s32 func_002662D0(void) {
    s32 i, v;
    func_00275748(0);
    for (;;) { if (func_00275EE0(D_41C0C0, 0x80000901, 0) < 0) goto err; if (*(s32 *)(D_41C0C0 + 0x24)) break; i = 0x10000; while (i--); }
    for (;;) { if (func_00275EE0(D_41C0E8, 0x80000902, 0) < 0) goto err; if (*(s32 *)(D_41C0E8 + 0x24)) break; i = 0x10000; while (i--); }
    for (;;) { if (func_00275EE0(D_41C110, 0x80000903, 0) < 0) goto err; if (*(s32 *)(D_41C110 + 0x24)) break; i = 0x10000; while (i--); }
    for (;;) { if (func_00275EE0(D_41C138, 0x80000904, 0) < 0) goto err; if (*(s32 *)(D_41C138 + 0x24)) break; i = 0x10000; while (i--); }
    for (;;) { if (func_00275EE0(D_41C160, 0x80000905, 0) < 0) goto err; if (*(s32 *)(D_41C160 + 0x24)) break; i = 0x10000; while (i--); }
    v = func_002666D0();
    if ((v >> 8) == 3) goto ok;
    func_00274F10(D_002E9330); func_00274F10(D_002E9358, 3, 0, v >> 8, v & 0xFF);
    return 0;
err:
    func_002662A8(D_002E9318);
    return 0;
ok:
    return 1;
}

extern "C" s32 func_00266510(s32 port) { D_41C1C0[0] = port; if (func_002760B0(D_41C0C0, 1, 0, D_41C1C0, 0x80, D_41C1C0, 0x80, 0, 0) < 0) { func_002662A8(D_002E9388); return 0; } return D_41C1C0[1]; }

extern "C" s32 func_00266580(s32 port) { D_41C1C0[0] = port; if (func_002760B0(D_41C0E8, 1, 0, D_41C1C0, 0x80, D_41C1C0, 0x80, 0, 0) < 0) { func_002662A8(D_002E93A8); return 0; } return D_41C1C0[1]; }

extern "C" s32 func_002665F0(s32 port) { D_41C1C0[0] = port; if (func_002760B0(D_41C110, 1, 0, D_41C1C0, 0x80, D_41C1C0, 0x80, 0, 0) < 0) { func_002662A8(D_002E93C8); return 0; } return D_41C1C0[1]; }

extern "C" s32 func_00266660(s32 port, s32 slot) { D_41C1C0[0] = port; D_41C1C0[1] = slot; if (func_002760B0(D_41C138, 1, 0, D_41C1C0, 0x80, D_41C1C0, 0x80, 0, 0) < 0) { func_002662A8(D_002E93F0); return 0; } return D_41C1C0[2]; }

extern "C" s32 func_002666D0(void) { if (func_002760B0(D_41C160, 1, 0, D_41C1C0, 0x80, D_41C1C0, 0x80, 0, 0) < 0) { func_002662A8(D_002E9418); return 0; } return D_41C1C0[0]; }

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00266738);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_002667C0);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_002669C0);

extern "C" s32 func_00266CD0(s32 a, s32 b, s32 c) { return func_002669C0(a, b, c, 0, -1); }

extern "C" s32 func_00266CF0(SceMpeg *mp, s32 type, s32 ch, s32 cb, s32 data) {
    register u32 gp asm("$28");
    MpegSys *s = mp->sys;
    s32 r = 0, i;
    StrEnt *tbl; s32 n; u64 id;
    tbl = *(StrEnt **)((u8 *)s + 0x60);
    id = func_00266738(type, ch);
    n = *(s32 *)((u8 *)s + 0x64);
    for (i = 0; i < n; i++) if (id == tbl[i].id) { r = tbl[i].m10; break; }
    if (i < 64) {
        tbl[i].id = id;
        tbl[i].m10 = cb;
        tbl[i].m14 = data;
        tbl[i].m8 = D_002BD7A8[type].m8;
        { void *g; asm volatile("move %0, $28" : "=r"(g)); tbl[i].m18 = g; }
        (*(s32 *)((u8 *)s + 0x64))++;
    }
    return r;
}

extern "C" s32 func_00266DE8(void *bs, PackHdr *h) {
    u32 a, b, c, n, i;
    func_0026E5D8(bs, 0x22);
    a = func_0026E5D8(bs, 3); func_0026E628(bs);
    b = func_0026E5D8(bs, 15); func_0026E628(bs);
    c = func_0026E5D8(bs, 15); func_0026E628(bs);
    h->m0 = func_0026E5D8(bs, 9);
    func_0026E5D8(bs, 0x1E);
    n = func_0026E5D8(bs, 3);
    h->m4 = (a << 30) | (b << 15) | c;
    h->m8 = (a >> 2) & 1;
    for (i = 0; i < n; i++) func_0026E5D8(bs, 8);
    if (func_0026E520(bs, 0x20) == 0x1BB) { h->mC = 1; func_00266F38(bs, h); }
    else h->mC = 0;
    return 1;
}

extern "C" s32 func_00266F38(void *p, void *h) { func_0026E5D8(p, 0x38); func_0026E5D8(p, 0x28); while (func_0026E520(p, 1) == 1) func_0026E5D8(p, 0x18); return 1; }

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00266FA8);

extern "C" s32 func_00267558(void) {
    s32 r = func_0027BD20();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B000 &= ~0x100;
    *(volatile u32 *)0x1000B400 &= ~0x100;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    if (r) func_0027BD78();
    *(volatile u32 *)0x1000B020 = 0;
    *(volatile u32 *)0x1000B420 = 0;
    func_0027E578();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00267608);

extern "C" s32 func_00267818(void) { return 1; }

extern "C" s32 func_00267820(SceMpeg *p, s32 a, s32 n) { func_002683F8(p->sys, a, (n + 19) / 16 * 16); return 1; }

extern "C" s32 func_00267860(SceMpeg *p, u32 a, s32 n) { MpegSys *o = p->sys; o->mC8 = 1; o->mF0 = (a & 0x0FFFFFFF) | 0x20000000; o->mFC = n; o->mF8 = 0; o->mF4 = 0; return func_00267CA0(p); }

extern "C" s32 func_002678A8(SceMpeg *p, u32 a, s32 n) { MpegSys *o = p->sys; o->mFC = n; o->mF0 = (a & 0x0FFFFFFF) | 0x20000000; o->mC8 = 0; o->mF8 = 0; o->mF4 = 0; return func_00267CA0(p); }

extern "C" s32 func_002678F0(SceMpeg *p, u32 a, s32 w, s32 h) { MpegSys *o = p->sys; o->mF8 = h << 4; o->mF0 = (a & 0x0FFFFFFF) | 0x20000000; o->mFC = w * h; o->mF4 = w << 4; o->mC8 = 0; return func_00267CA0(p); }

extern "C" void func_00267940(SceMpeg *p) { p->sys->m10A0 = 1; }

extern "C" void func_00267950(SceMpeg *p, s32 a, s32 b, s32 c) { MpegSys *o = p->sys; o->mAC = a; o->mB0 = b; o->mB4 = c; }

extern "C" void func_00267968(SceMpeg *p, s32 *a, s32 *b, s32 *c) { MpegSys *o = p->sys; *a = o->mAC; *b = o->mB0; *c = o->mB4; }

extern "C" s32 func_00267988(SceMpeg *p) { return p->sys->m0; }

extern "C" s32 func_00267998(SceMpeg *p) { return p->sys->m4 == 0; }

extern "C" s32 func_002679A8(SceMpeg *p) {
    MpegSys *o = p->sys;
    o->m10A0 = 0; o->m0 = 0; o->m4 = 0; o->m8 = 0;
    p->frameCount = 0; o->mC4 = 0; o->m98 = -1;
    func_00268290(o); o->m130 = 0; func_002681A0(o); return 1;
}

extern "C" s32 func_00267A08(SceMpeg *p) {
    MpegSys *o = p->sys; MpegBuf *q;
    if ((q = o->m1D0[0].m0) != 0) q->m28 = 0;
    if ((q = o->m1D0[1].m0) != 0) q->m28 = 0;
    if ((q = o->m1D0[2].m0) != 0) q->m28 = 0;
    if ((q = o->m1D0[0].m4) != 0) q->m28 = 0;
    if ((q = o->m1D0[1].m4) != 0) q->m28 = 0;
    if ((q = o->m1D0[2].m4) != 0) q->m28 = 0;
    return 1;
}

extern "C" s32 func_00267A60(SceMpeg *p, s32 i, s32 a, s32 b) { MpegSys *s = p->sys; s32 old = s->mC[i].m0; void *g; s->mC[i].m0 = a; s->mC[i].m4 = b; asm volatile("move %0, $28" : "=r"(g)); s->mC[i].m8 = g; return old; }

extern "C" s32 func_00267A98(SceMpeg *mp, s32 *d) {
    s32 r = 0;
    MpegSys *s;
    if (mp && (s = mp->sys)) {
        s32 (*fn)(SceMpeg *, s32 *, s32) = (s32 (*)(SceMpeg *, s32 *, s32))s->mC[*d].m0;
        if (fn) {
            void *ngp = s->mC[*d].m8, *save;
            asm volatile("move %0, $28\n\tmove $28, %1" : "=&r"(save) : "r"(ngp) : "memory");
            r = fn(mp, d, s->mC[*d].m4);
            asm volatile("move $28, %0" : : "r"(save) : "memory");
        }
    }
    return r;
}

extern "C" s32 func_00267B10(SceMpeg *mp) { struct { s32 m0; s32 pad[7]; } t; t.m0 = 1; func_00267A98(mp, &t.m0); return 1; }

extern "C" s32 func_00267B38(SceMpeg *p, s64 a) { p->sys->m8C = 1; p->sys->m90 = a; return 1; }

extern "C" s32 func_00267B50(SceMpeg *p) { p->sys->m8C = 0; p->sys->m90 = 0; return 1; }

extern "C" s32 func_00267B68(SceMpeg *p, s32 a) { p->sys->mF0 = a; return 1; }

extern "C" s32 func_00267B78(SceMpeg *p) { return p->sys->mE4; }

extern "C" s32 func_00267B88(SceMpeg *p) { return p->sys->mE8; }

extern "C" s32 *func_00267B98(SceMpeg *p) { return &p->sys->mCC; }

extern "C" s32 *func_00267BA8(SceMpeg *p) { return &p->sys->mCC; }

extern "C" s32 func_00267BB8(SceMpeg *p, s32 a) { s32 old = p->sys->m100; p->sys->m100 = a; return old; }

extern "C" s32 func_00267BC8(SceMpeg *p, s64 a) { MpegSys *o = p->sys; o->m108 = a; o->m110 = 1; return 1; }

extern "C" void func_00267BE0(Q4 *p, s32 a, s32 b) { p->m0 = a; p->m4 = b; p->m8 = a; p->mC = a; }

extern "C" void func_00267BF8(Q4 *p) { p->mC = p->m8; }

extern "C" void func_00267C08(Q4 *p) { p->m8 = p->mC; }

extern "C" u32 func_00267C18(MpegSys *s, Q4 *q, s32 size, u32 align) {
    u32 p = (q->m8 + align - 1) / align * align;
    if ((u32)(q->m0 + q->m4) >= p + size) { q->m8 = p + size; return p; }
    func_002683A0(s, D_002E94A8); return 0;
}

extern "C" s32 func_00267C88(Q4 *p) { return p->m0 + p->m4 - p->m8; }

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00267CA0);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00267E58);

extern "C" s32 func_00267F78(SceMpeg *p, s32 a, s32 b) { if (p->sys->m18C != 3) return func_00267FC0(p, a, b); return func_00267E58(p, a, b); }

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00267FC0);
