#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct CVec4 { f32 x; f32 y; f32 z; f32 w; };
void Func270CA0(CVec4 *, void *);
s32 Func238158(void *, s32);
struct S4 { s32 m0; s32 m4; s32 m8; s32 mC; };
struct F2 { f32 m0; f32 m4; };
extern CVec4 D_33D890;
extern CVec4 D_33D8D0;
extern S4 D_33D960;
extern F2 D_33D970;
extern S4 D_33D980;
extern S4 D_33D9C0;
extern s32 D_33D990;
extern s32 D_33D994;
extern s32 D_33D998;
extern s32 D_33D9A4;
extern s32 D_33D9AC;
extern s32 D_33D9B0;
extern s32 D_33D9B4;
extern s32 D_33D9B8;
extern s32 D_33D9BC;
extern u32 *D_33DB80;
extern u32 *D_33DB84;
extern s32 D_002B8A98;
extern u32 *D_002B94E4;
struct Pair { s32 a; s32 b; };
extern Pair D_002B8A60[];
extern "C" s32 func_0021BCF8(s32, s32);
extern "C" void func_00239088(void);
extern "C" void func_002390A0(void);
extern "C" void func_0021E810(void);
extern "C" s32 func_002375C0(void);
extern "C" s32 func_002377D8(void);
extern "C" void func_0021E818(void);
extern "C" s32 func_0021E838(void);
extern "C" void func_0021EDD0(CVec4 *);
extern "C" void func_0021EEC0(CVec4 *);
#define PUT(v) { u32 *_p = D_002B94E4; D_002B94E4 = _p + 1; *_p = (v); }

#define PUT2(v) { u32 _v = (v); u32 *_p = D_002B94E4; D_002B94E4 = _p + 1; *_p = _v; }
extern s32 D_33D9A0;
extern "C" void func_00237860(s32, s32);
extern "C" void func_002379D0(s32);

struct Blk128 { u64 d[16]; };
extern Blk128 D_33D810;

extern "C" void func_0021F190(void *);

extern "C" s32 func_00237398(s32, CVec4 *);
extern "C" void func_00227AE8(void);
void Func225088();
int Func2250C0();

extern "C" void func_00237350(s32);
typedef s32 (*F860)(s32, CVec4 *);
extern "C" void func_0021EFB0(CVec4 *);
extern "C" void func_0021E4A0(void);
extern "C" void func_0021E760(void);
extern "C" void func_0021DE00(s32, s32, s32, s32);
extern "C" void func_0021DE20(f32, f32);
extern "C" void func_0021DE38(s32, s32, s32, s32);

#define PUTF2(v) { f32 _v = (v); f32 *_p = (f32 *)D_002B94E4; D_002B94E4 = (u32 *)(_p + 1); *_p = _v; }
struct BzE { f32 b[4]; f32 s0, t0, s1, t1; };
struct BzT { s32 n; u8 pad[0xC]; BzE e[4]; };
extern BzT D_33D9D0[3];
extern "C" s32 func_0021DEF8(void);
extern "C" s32 func_0021E720(void);
extern "C" s32 func_0021E740(void);
extern "C" s32 func_0021DEB8(void);
extern "C" void func_0021EAD8(s32);
extern "C" void func_0021FAD8(void);
extern "C" void func_0021F7A0(s32, s32, s32, s32);
extern "C" void func_0021F250(f32, f32);
extern "C" void func_0021F860(s32, s32, s32, s32);
extern "C" void func_0021F088(CVec4 *);
struct P21EFB0 { f32 m0, m4, m8, mC; u8 pad[0x40]; f32 m50, m54, m58, m5C; };

extern s32 D_33D6F0;

#define PUT2(v) { u32 _v = (v); u32 *_p = D_002B94E4; D_002B94E4 = _p + 1; *_p = _v; }

s32 Func238158(void *, s32);
extern u64 D_33D910[2];
extern f32 D_33D920[4];
extern u64 D_33D930[2];
extern f32 D_33D940[4];
extern u64 D_33D950[2];
extern "C" void func_00237408(s32);
extern "C" void func_00237460(void);
extern "C" s32 func_00237450(void);
extern "C" s32 func_002374B0(void);
extern "C" void func_0021F2B8(s32, u64, s32, u64);
extern "C" void func_0021F400(f32, f32, f32, f32);
extern "C" void func_0021F488(s32, u64, s32, u64);
extern "C" void func_0021F5D0(f32, f32, f32, f32);
extern "C" void func_0021F658(s32, u64, s32, u64);
inline void PutAD1D(s64 v, u32 a) {
    u32 *p = D_002B94E4;
    D_002B94E4 = p + 4;
    p[0] = v;
    p[1] = v >> 32;
    p[2] = a;
    p[3] = 0;
}
inline void PutADc1D(u32 v, u32 a) {
    u32 *p = D_002B94E4;
    D_002B94E4 = p + 4;
    p[0] = v;
    p[2] = a;
    p[1] = 0;
    p[3] = 0;
}

extern "C" s32 func_0021BAC0(s32, void *, s32);
extern "C" void func_0021BC88(s32, s32);
extern "C" s32 func_0021BDD0(s32, s32);
extern "C" void func_0021E370(void);
extern s32 D_33D9A8;
s32 Func235DE0(const char *fmt, ...);
extern char D_002C5200[], D_002C82E8[], D_002C8300[], D_002CAE78[];
extern const char D_002E3D18[], D_002E3D38[], D_002E3D58[], D_002E3D70[], D_002E3D88[], D_002E3DA0[], D_002E3DB8[];
extern const char D_002E3DD0[], D_002E3DE8[], D_002E3E00[], D_002E3E18[], D_002E3E30[], D_002E3E48[], D_002E3E60[];

inline u32 *PutW(u32 v) { u32 *p = D_002B94E4; D_002B94E4 = p + 1; *p = v; return p; }
inline u32 *PutQW(u64 hi, u64 lo) {
    u32 *q = D_002B94E4;
    D_002B94E4 = q + 4;
    q[0] = lo;
    q[1] = lo >> 32;
    q[2] = hi;
    q[3] = hi >> 32;
    return q;
}
// @decl-end
INCLUDE_RODATA("asm/nonmatchings/Unit21D820", D_002E3D18);
INCLUDE_RODATA("asm/nonmatchings/Unit21D820", D_002E3D38);
INCLUDE_RODATA("asm/nonmatchings/Unit21D820", D_002E3D58);
INCLUDE_RODATA("asm/nonmatchings/Unit21D820", D_002E3D70);
INCLUDE_RODATA("asm/nonmatchings/Unit21D820", D_002E3D88);
INCLUDE_RODATA("asm/nonmatchings/Unit21D820", D_002E3DA0);
INCLUDE_RODATA("asm/nonmatchings/Unit21D820", D_002E3DB8);
INCLUDE_RODATA("asm/nonmatchings/Unit21D820", D_002E3DD0);
INCLUDE_RODATA("asm/nonmatchings/Unit21D820", D_002E3DE8);
INCLUDE_RODATA("asm/nonmatchings/Unit21D820", D_002E3E00);
INCLUDE_RODATA("asm/nonmatchings/Unit21D820", D_002E3E18);
INCLUDE_RODATA("asm/nonmatchings/Unit21D820", D_002E3E30);
INCLUDE_RODATA("asm/nonmatchings/Unit21D820", D_002E3E48);
INCLUDE_RODATA("asm/nonmatchings/Unit21D820", D_002E3E60);

extern "C" void func_0021D820(s32 n, s32 a, s32 b, s32 c, s32 d) {
    PUT(0x6C028000); PUT(a); PUT(b); PUT(c); PUT(d);
    { s64 t = ((s64)(n | 4) << 47) | ((s64)0x8002 << 45); u32 *p = D_002B94E4; D_002B94E4 = p + 2; p[1] = t >> 32; p[0] = t; }
    { u32 *p = D_002B94E4; D_002B94E4 = p + 2; p[0] = 4; p[1] = 0; }
    PUT2((D_33D6F0 + 0x24) | 0x14000000);
}

extern "C" void func_0021D8F0(void) { func_0021E4A0(); func_0021DE00(0, 0, 0, 0x80); func_0021DE20(2.0f, 2.0f); func_0021DE38(0x80, 0x80, 0x80, 0x80); func_0021E760(); D_33D990 = 0; D_33D994 = 1; D_33D998 = 0; }

extern "C" void func_0021D968(void) {
}

extern "C" void func_0021D970(s32 v) {
    D_33D810 = *(Blk128 *)v;
}

extern "C" void func_0021D9B8(void *p) {
    Func270CA0(&D_33D890, p);
    return;
}

extern "C" void func_0021D9D8(void *p) {
    Func270CA0(&D_33D8D0, p);
    return;
}

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021D9F8);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021DB80);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021DD08);

extern "C" void func_0021DE00(s32 a, s32 b, s32 c, s32 d) {
    D_33D960.m0 = a;
    D_33D960.m4 = b;
    D_33D960.m8 = c;
    D_33D960.mC = d;
}

extern "C" void func_0021DE20(f32 a, f32 b) {
    D_33D970.m0 = a;
    D_33D970.m4 = b;
}

extern "C" void func_0021DE38(s32 a, s32 b, s32 c, s32 d) {
    D_33D980.m0 = a;
    D_33D980.m4 = b;
    D_33D980.m8 = c;
    D_33D980.mC = d;
}

extern "C" void func_0021DE58(s32 v) {
    D_33D990 = v;
}

extern "C" s32 func_0021DE68(void) {
    return D_33D990;
}

extern "C" void func_0021DE78(s32 v) {
    D_33D994 = v;
}

extern "C" s32 func_0021DE88(void) {
    return D_33D994;
}

extern "C" void func_0021DE98(s32 v) {
    D_33D998 = v;
}

extern "C" s32 func_0021DEA8(void) {
    return D_33D998;
}

extern "C" s32 func_0021DEB8(void) {
    u8 buf[0x50];
    func_0021E818();
    func_0021EDD0(&D_33D890);
    func_0021EEC0(&D_33D8D0);
    return func_0021E838();
}

extern "C" s32 func_0021DEF8(void) {
    s32 n;
    s64 t;
    func_002375C0();
    func_00237350(8);
    func_00237408(8);
    func_00237408(0x10);
    PutAD1D(D_33D910[0], 6);
    PutAD1D(D_33D910[1], 8);
    PutADc1D(0x44, 0x42);
    PutADc1D(0x60, 0x14);
    func_00237460();
    t = ((func_00237450() + 15) / 16 - 1) | 0x8000 | ((s64)0x8000 << 45);
    PutAD1D(t, 0xE);
    func_002374B0();
    func_00237460();
    PUT(0x11000000);
    n = func_00237450();
    PUT2(((n + 15) / 16 - 1) | 0x50000000);
    func_002374B0();
    func_0021F2B8(6, D_33D910[0], 8, D_33D910[1]);
    func_0021F400(D_33D920[0], D_33D920[1], D_33D920[2], D_33D920[3]);
    func_0021F488(6, D_33D930[0], 8, D_33D930[1]);
    func_0021F5D0(D_33D940[0], D_33D940[1], D_33D940[2], D_33D940[3]);
    func_0021F658(6, D_33D950[0], 8, D_33D950[1]);
    return Func238158((void *)func_002377D8(), 1);
}

extern "C" s32 func_0021E140(void *a) { func_0021E818(); func_0021F190(a); return func_0021E838(); }

extern "C" s32 func_0021E170(void) { s32 a = func_0021E720(); s32 b = func_0021DEB8(); s32 c = func_0021DEF8(); func_0021E818(); func_0021EAD8(a); func_0021FAD8(); func_0021F190((void *)2); func_0021F088((CVec4 *)&D_33D810); func_0021F7A0(D_33D960.m0, D_33D960.m4, D_33D960.m8, D_33D960.mC); func_0021F250(D_33D970.m0, D_33D970.m4); func_0021F860(D_33D980.m0, D_33D980.m4, D_33D980.m8, D_33D980.mC); func_0021EAD8(b); func_0021EAD8(c); return func_0021E838(); }

extern "C" s32 func_0021E240(void) { s32 a = func_0021E740(); s32 b = func_0021DEB8(); s32 c = func_0021DEF8(); func_0021E818(); func_0021EAD8(a); func_0021FAD8(); func_0021F190((void *)2); func_0021F088((CVec4 *)&D_33D810); func_0021F7A0(D_33D960.m0, D_33D960.m4, D_33D960.m8, D_33D960.mC); func_0021F250(D_33D970.m0, D_33D970.m4); func_0021F860(D_33D980.m0, D_33D980.m4, D_33D980.m8, D_33D980.mC); func_0021EAD8(b); func_0021EAD8(c); return func_0021E838(); }

extern "C" s32 func_0021E310(void) { s32 a = func_0021BCF8(1, 0); Func225088(); func_00227AE8(); s32 b = Func2250C0(); func_002375C0(); func_002379D0(a); func_002379D0(b); return func_002377D8(); }

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021E370);

extern "C" void func_0021E4A0(void) {
    s32 h, n;
    func_0021E370();
    h = func_0021BDD0(1, 0);
    D_33D9A4 = h;
    if (h < 0) {
        Func235DE0(D_002E3D18);
        return;
    }
    func_0021BC88(1, h);
    D_33D9A0 = func_0021BAC0(1, D_002C5200, n = D_002C82E8 - D_002C5200);
    func_0021BC88(1, 0);
    Func235DE0(D_002E3D38);
    Func235DE0(D_002E3D58, n, n);
    Func235DE0(D_002E3D70, 0x39, 0x39);
    Func235DE0(D_002E3D88, 0x36, 0x36);
    Func235DE0(D_002E3DA0, 0x36, 0x36);
    Func235DE0(D_002E3DB8, 0x36, 0x36);
    Func235DE0(D_002E3DD0, 0x7C, 0x7C);
    Func235DE0(D_002E3DE8, 0x7C, 0x7C);
    Func235DE0(D_002E3E00, 0x7C, 0x7C);
    Func235DE0(D_002E3E18, 0x36, 0x36);
    Func235DE0(D_002E3E18, 0x36, 0x36);
    Func235DE0(D_002E3E30, 0xA2, 0xA2);
    Func235DE0(D_002E3E30, 0xA2, 0xA2);
    Func235DE0(D_002E3E48, 0x3FF, 0x3FF);
    h = func_0021BDD0(1, 0);
    D_33D9AC = h;
    if (h < 0) {
        Func235DE0(D_002E3E60);
        return;
    }
    func_0021BC88(1, h);
    D_33D9A8 = func_0021BAC0(1, D_002C8300, D_002CAE78 - D_002C8300);
    return (void)func_0021BC88(1, 0);
}

extern "C" s32 func_0021E6B8(u32 i) {
    s32 r = 0;
    if (i < 7) r = D_002B8A60[i].a;
    return r;
}

asm(".p2align 3");

extern "C" s32 func_0021E6E0(u32 i) {
    s32 r = 0;
    if (i < 7) r = D_002B8A60[i].b;
    return r;
}

extern "C" s32 func_0021E708(void) {
    return 3;
}

extern "C" s32 func_0021E710(void) {
    return 0xD;
}

extern "C" s32 func_0021E718(void) {
    return 4;
}

extern "C" s32 func_0021E720(void) {
    return func_0021BCF8(1, D_33D9A4);
}

extern "C" s32 func_0021E740(void) {
    return func_0021BCF8(1, D_33D9AC);
}

extern "C" void func_0021E760(void) {
    s32 a = D_33D9B0, b = D_33D9B4, c = D_33D9B8, e = D_33D9BC;
    D_33D9C0.m0 = a;
    D_33D9C0.m4 = b;
    D_33D9C0.m8 = c;
    D_33D9C0.mC = e;
}

extern "C" void func_0021E7A0(void) {
    D_33D9B0 = D_33D9C0.m0;
    D_33D9B4 = D_33D9C0.m4;
    D_33D9B8 = D_33D9C0.m8;
    D_33D9BC = D_33D9C0.mC;
}

extern "C" void func_0021E7E0(void) {
    func_00239088();
    return;
}

extern "C" void func_0021E7F8(void) {
    func_002390A0();
    return;
}

extern "C" void func_0021E810(void) {
}

extern "C" void func_0021E818(void) {
    func_0021E810();
    func_002375C0();
    return;
}

extern "C" s32 func_0021E838(void) {
    return Func238158((void *)func_002377D8(), 1);
}

extern "C" void func_0021E860(void) {
    D_002B8A98 = 0;
    D_33DB80 = PutW(0x6C008000);
    D_33DB84 = PutQW(0xE, 0x1000000000000000);
}

extern "C" void func_0021E8C0(void) {
    *D_33DB80 |= (D_002B8A98 + 1) << 16;
    *D_33DB84 |= D_002B8A98;
    PUT2((D_33D9A0 + 0x40) | 0x14000000);
    D_002B8A98 = 0;
}

extern "C" void func_0021E938(s64 a, s64 b) {
    u32 *p = D_002B94E4;
    D_002B94E4 = p + 4;
    p[0] = b;
    p[1] = b >> 32;
    p[2] = a;
    p[3] = a >> 32;
    D_002B8A98++;
}

extern "C" void func_0021E990(s64 a, s64 b, s64 c, s64 d) {
    PUT(0x6C028000);
    {
        u32 *p = D_002B94E4;
        D_002B94E4 = p + 4;
        p[0] = b;
        p[1] = b >> 32;
        p[2] = a;
        p[3] = a >> 32;
    }
    {
        u32 *p = D_002B94E4;
        D_002B94E4 = p + 4;
        p[0] = d;
        p[1] = d >> 32;
        p[2] = c;
        p[3] = c >> 32;
    }
    PUT((D_33D9A0 + 0x3C) | 0x14000000);
}

extern "C" void func_0021EA40(s64 a, s64 b) {
    PUT(0x6C018000);
    {
        u32 *p = D_002B94E4;
        D_002B94E4 = p + 4;
        p[0] = b;
        p[1] = b >> 32;
        p[2] = a;
        p[3] = a >> 32;
    }
    PUT((D_33D9A0 + 0x3E) | 0x14000000);
}

extern "C" void func_0021EAC0(s32 a, s32 b) {
    func_00237860(a, b);
    return;
}

extern "C" void func_0021EAD8(s32 a) {
    func_002379D0(a);
    return;
}

extern "C" void func_0021EAF0(CVec4 *a) { PUT(0x6C048000); func_00237398(0x10, a); u32 v = D_33D9A0 + 4; PUT(v | 0x14000000); }

extern "C" void func_0021EB60(CVec4 *a) { func_00237350(0xC); PUT(0x6C048000); ((F860)func_00237860)(4, a); u32 v = D_33D9A0 + 4; PUT(v | 0x14000000); }

extern "C" void func_0021EBE0(s32 a, CVec4 *b) { func_00237350(0xC); PUT((a << 16) | 0x6C008000); ((F860)func_00237860)(a, b); u32 v = D_33D9A0 + 0x3C; PUT(v | 0x14000000); }

extern "C" void func_0021EC78(s32 a, CVec4 *b) { func_00237350(0xC); PUT((a << 16) | 0x6C008000); ((F860)func_00237860)(a, b); u32 v = D_33D9A0 + 0x3E; PUT(v | 0x14000000); }

extern "C" void func_0021ED10(CVec4 *m, f32 s) {
    func_00237350(0xC);
    PUT(0x6C048000);
    u32 *p = D_002B94E4; D_002B94E4 = p + 16;
    asm volatile("mfc1 $8, %0\n\tqmtc2.ni $8, $vf2\n\tlqc2 $vf4, 0x0(%1)\n\tlqc2 $vf5, 0x10(%1)\n\tlqc2 $vf6, 0x20(%1)\n\tlqc2 $vf7, 0x30(%1)\n\tvmulx.xyzw $vf4, $vf4, $vf2x\n\tvmulx.xyzw $vf5, $vf5, $vf2x\n\tvmulx.xyzw $vf6, $vf6, $vf2x\n\tvmulx.xyzw $vf7, $vf7, $vf2x\n\tsqc2 $vf4, 0x0(%2)\n\tsqc2 $vf5, 0x10(%2)\n\tsqc2 $vf6, 0x20(%2)\n\tsqc2 $vf7, 0x30(%2)" : : "f"(s), "r"(m), "r"(p) : "$8", "memory");
    PUT2((D_33D9A0 + 4) | 0x14000000);
}

extern "C" void func_0021EDD0(CVec4 *a) { PUT(0x6C038000); func_00237398(0xC, a); u32 v = D_33D9A0 + 6; PUT(v | 0x14000000); }

extern "C" void func_0021EE40(CVec4 *a) { func_00237350(0xC); PUT(0x6C038000); ((F860)func_00237860)(3, a); u32 v = D_33D9A0 + 6; PUT(v | 0x14000000); }

extern "C" void func_0021EEC0(CVec4 *a) { PUT(0x6C048000); func_00237398(0x10, a); u32 v = D_33D9A0 + 8; PUT(v | 0x14000000); }

extern "C" void func_0021EF30(CVec4 *a) { func_00237350(0xC); PUT(0x6C048000); ((F860)func_00237860)(4, a); u32 v = D_33D9A0 + 8; PUT(v | 0x14000000); }

extern "C" void func_0021EFB0(CVec4 *pv) { P21EFB0 *p = (P21EFB0 *)pv; f32 s = 1536.0f; f32 a = p->m50, b = p->m54; PUTF2(p->m0 * a / s); PUTF2(p->m4 * b / s); PUTF2(p->m8); PUTF2(p->mC); PUTF2(s); PUTF2(s); PUTF2(p->m58); PUTF2(p->m5C); }

extern "C" void func_0021F088(CVec4 *a) { PUT(0x6C0A8000); func_00237398(0x20, a); func_0021EFB0(a); u32 v = D_33D9A0 + 2; PUT(v | 0x14000000); }

extern "C" void func_0021F108(CVec4 *a) { func_00237350(0xC); PUT(0x6C088000); ((F860)func_00237860)(6, a); func_0021EFB0(a); u32 v = D_33D9A0 + 2; PUT(v | 0x14000000); }

extern "C" void func_0021F190(void *pi) { s32 i = (s32)pi; i = i < 0 ? 0 : (i > 2 ? 2 : i); func_00237350(0xC); PUT2(0x6C098000); ((F860)func_00237860)(9, (CVec4 *)&D_33D9D0[i]); u32 v = D_33D9A0 + 0x1A; PUT(v | 0x14000000); }
