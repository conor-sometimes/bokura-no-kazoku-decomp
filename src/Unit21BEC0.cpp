#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct CVec4 { f32 x; f32 y; f32 z; f32 w; };
void Func270CA0(CVec4 *, void *);
s32 Func238158(void *, s32);
void Func225088();
int Func2250C0();
extern CVec4 D_33D630;
extern CVec4 D_33D670;
struct S4 { s32 m0; s32 m4; s32 m8; s32 mC; };
extern S4 D_33D6D0;
extern S4 D_33D708;
struct S33D6E0 { f32 m0; f32 m4; s32 m8; s32 mC; s32 m10; s32 m14; S4 m18; };
extern S33D6E0 D_33D6E0;
extern u32 *D_002B94E4;
extern "C" s32 func_0021C678(void);
extern "C" s32 func_0021C110(void);
extern "C" s32 func_0021C150(void);
extern "C" void func_0021C750(void);
extern "C" s32 func_0021C770(void);
extern "C" void func_0021C7B0(s32);
extern "C" void func_0021D160(void);
extern "C" void func_0021CD38(s32);
extern "C" void func_0021CC30(void *);
extern "C" void func_0021CEE8(s32, s32, s32, s32);
extern "C" void func_0021CDF8(f32, f32);
extern "C" void func_0021C978(CVec4 *);
extern "C" void func_0021CA68(CVec4 *);
extern "C" s32 func_0021BCF8(s32, s32);
extern "C" void func_00227AE8(void);
extern "C" s32 func_002375C0(void);
extern "C" void func_002379D0(s32);
extern "C" s32 func_002377D8(void);
extern "C" void func_00239088(void);
extern "C" void func_002390A0(void);
extern "C" void func_00237860(s32, s32);
extern "C" void func_00237398(s32, s32);
extern "C" void func_00237350(s32);
extern "C" void func_0021C748(void);
extern u8 D_33D5B0[];
struct Pair { s32 a; s32 b; };
extern Pair D_002B8A28[];
extern s32 D_33D6F8;
extern s32 D_33D6FC;
extern s32 D_33D700;
extern s32 D_33D704;

extern s32 D_33D6F0;
#define PUT(v) { u32 *_p = D_002B94E4; D_002B94E4 = _p + 1; *_p = (v); }
#define PUTF(v) { f32 *_p = (f32 *)D_002B94E4; D_002B94E4 = (u32 *)(_p + 1); *_p = (v); }
extern "C" void func_0021D248(s32, s32, s32, u32);
extern "C" void func_0021D3E0(void);

extern s32 D_33D6FC;
extern "C" void func_0021D4D0(void);

struct Blk128 { u64 d[16]; };
extern Blk128 D_33D5B0blk asm("D_33D5B0");

#define PUTB(v) { u8 *_p = (u8 *)D_002B94E4; D_002B94E4 = (u32 *)(_p + 1); *_p = (v); }

typedef s32 (*F398)(s32, CVec4 *);

typedef s32 (*F860)(s32, CVec4 *);
#define PUT2(v) { u32 _v = (v); u32 *_p = D_002B94E4; D_002B94E4 = _p + 1; *_p = _v; }
#define PUTF2(v) { f32 _v = (v); f32 *_p = (f32 *)D_002B94E4; D_002B94E4 = (u32 *)(_p + 1); *_p = _v; }
struct S50 { u8 b[0x50]; };
extern S50 D_33D720[3];
extern s32 D_33D6F4;
extern const char D_002E3CF8[];
extern u8 D_002C3D00[], D_002C51D0[];
extern "C" s32 func_0021C468(void);
extern "C" s32 func_0021BDD0(s32, s32);
extern "C" s32 func_0021BC88(s32, s32);
extern "C" s32 func_0021BAC0(s32, void *, s32);
void Func235DE0(const char *, ...);
struct P21EFB0 { f32 m0, m4, m8, mC; u8 pad[0x40]; f32 m50, m54, m58, m5C; };

#define PUT2(v) { u32 _v = (v); u32 *_p = D_002B94E4; D_002B94E4 = _p + 1; *_p = _v; }

#define PUT2(v) { u32 _v = (v); u32 *_p = D_002B94E4; D_002B94E4 = _p + 1; *_p = _v; }
typedef s32 (*F860c)(s32, s32);
inline s32 Chunk21D(s32 n, s32 max, s32 d) { s32 c = n; if (c > max) c = n / d; return c > max ? max : c; }
// @decl-end

extern "C" void func_0021BEC0(void) {
}

extern "C" void func_0021BEC8(s32 v) {
    D_33D5B0blk = *(Blk128 *)v;
}

extern "C" void func_0021BF10(void *p) {
    Func270CA0(&D_33D630, p);
    return;
}

extern "C" void func_0021BF30(void *p) {
    Func270CA0(&D_33D670, p);
    return;
}

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021BF50);

extern "C" void func_0021C0D8(s32 a, s32 b, s32 c, s32 d) {
    D_33D6D0.m0 = a;
    D_33D6D0.m4 = b;
    D_33D6D0.m8 = c;
    D_33D6D0.mC = d;
}

extern "C" void func_0021C0F8(f32 a, f32 b) {
    D_33D6E0.m0 = a;
    D_33D6E0.m4 = b;
}

extern "C" s32 func_0021C110(void) {
    u8 buf[0x50];
    func_0021C750();
    func_0021C978(&D_33D630);
    func_0021CA68(&D_33D670);
    return func_0021C770();
}

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021C150);

extern "C" s32 func_0021C328(s32 a) {
    func_0021C750();
    func_0021CD38(a);
    return func_0021C770();
}

extern "C" s32 func_0021C358(void) {
    s32 a = func_0021C678();
    s32 b = func_0021C110();
    s32 c = func_0021C150();
    func_0021C750();
    func_0021C7B0(a);
    func_0021D160();
    func_0021CD38(2);
    func_0021CC30(D_33D5B0);
    func_0021CEE8(D_33D6D0.m0, D_33D6D0.m4, D_33D6D0.m8, D_33D6D0.mC);
    func_0021CDF8(D_33D6E0.m0, D_33D6E0.m4);
    func_0021C7B0(b);
    func_0021C7B0(c);
    return func_0021C770();
}

extern "C" void func_0021C408(void) {
    s32 a = func_0021BCF8(1, 0);
    s32 b;
    Func225088();
    func_00227AE8();
    b = Func2250C0();
    func_002375C0();
    func_002379D0(a);
    func_002379D0(b);
    func_002377D8();
    return;
}

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021C468);

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021C588);

extern "C" s32 func_0021C610(u32 i) {
    s32 r = 0;
    if (i < 6) r = D_002B8A28[i].a;
    return r;
}

/* GNU as 2.10 corrupts the lui of the next lw macro here without this (docs/lessons.md) */
asm(".p2align 3");
extern "C" s32 func_0021C638(u32 i) {
    s32 r = 0;
    if (i < 6) r = D_002B8A28[i].b;
    return r;
}

extern "C" s32 func_0021C660(void) {
    return 3;
}

extern "C" s32 func_0021C668(void) {
    return 0xE;
}

extern "C" s32 func_0021C670(void) {
    return 4;
}

extern "C" s32 func_0021C678(void) {
    return func_0021BCF8(1, D_33D6E0.m14);
}

extern "C" void func_0021C698(void) {
    s32 a = D_33D6F8, b = D_33D6FC, c = D_33D700, e = D_33D704;
    D_33D708.m0 = a;
    D_33D708.m4 = b;
    D_33D708.m8 = c;
    D_33D708.mC = e;
}

extern "C" void func_0021C6D8(void) {
    D_33D6F8 = D_33D708.m0;
    D_33D6FC = D_33D708.m4;
    D_33D700 = D_33D708.m8;
    D_33D704 = D_33D708.mC;
}

extern "C" void func_0021C718(void) {
    func_00239088();
    return;
}

extern "C" void func_0021C730(void) {
    func_002390A0();
    return;
}

extern "C" void func_0021C748(void) {
}

extern "C" void func_0021C750(void) {
    func_0021C748();
    func_002375C0();
    return;
}

extern "C" s32 func_0021C770(void) {
    return Func238158((void *)func_002377D8(), 1);
}

extern "C" void func_0021C798(s32 a, s32 b) {
    func_00237860(a, b);
    return;
}

extern "C" void func_0021C7B0(s32 a) {
    func_002379D0(a);
    return;
}

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021C7C8);

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021C838);

extern "C" void func_0021C8B8(CVec4 *m, f32 s) {
    func_00237350(0xC);
    PUT(0x6C048000);
    u32 *p = D_002B94E4; D_002B94E4 = p + 16;
    asm volatile("mfc1 $8, %0\n\tqmtc2.ni $8, $vf2\n\tlqc2 $vf4, 0x0(%1)\n\tlqc2 $vf5, 0x10(%1)\n\tlqc2 $vf6, 0x20(%1)\n\tlqc2 $vf7, 0x30(%1)\n\tvmulx.xyzw $vf4, $vf4, $vf2x\n\tvmulx.xyzw $vf5, $vf5, $vf2x\n\tvmulx.xyzw $vf6, $vf6, $vf2x\n\tvmulx.xyzw $vf7, $vf7, $vf2x\n\tsqc2 $vf4, 0x0(%2)\n\tsqc2 $vf5, 0x10(%2)\n\tsqc2 $vf6, 0x20(%2)\n\tsqc2 $vf7, 0x30(%2)" : : "f"(s), "r"(m), "r"(p) : "$8", "memory");
    PUT2((D_33D6F0 + 4) | 0x14000000);
}

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021C978);

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021C9E8);

extern "C" void func_0021CA68(CVec4 *a) { PUT(0x6C048000); ((F398)func_00237398)(0x10, a); u32 v = D_33D6F0 + 8; PUT(v | 0x14000000); }

extern "C" void func_0021CAD8(CVec4 *a) { func_00237350(0xC); PUT(0x6C048000); ((F860)func_00237860)(4, a); u32 v = D_33D6F0 + 8; PUT(v | 0x14000000); }

extern "C" void func_0021CB58(CVec4 *pv) { P21EFB0 *p = (P21EFB0 *)pv; f32 s = 1536.0f; f32 a = p->m50, b = p->m54; PUTF2(p->m0 * a / s); PUTF2(p->m4 * b / s); PUTF2(p->m8); PUTF2(p->mC); PUTF2(s); PUTF2(s); PUTF2(p->m58); PUTF2(p->m5C); }

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021CC30);

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021CCB0);

extern "C" void func_0021CD38(s32 i) { i = i < 0 ? 0 : (i > 2 ? 2 : i); func_00237350(0xC); PUT2(0x6C058000); ((F860)func_00237860)(5, (CVec4 *)&D_33D720[i]); u32 v = D_33D6F0 + 0x10; PUT(v | 0x14000000); }

extern "C" void func_0021CDF8(f32 a, f32 b) {
    PUT(0x64018000);
    PUTF(a);
    PUTF(b);
    PUT((D_33D6F0 + 0xC) | 0x14000000);
}

extern "C" void func_0021CE60(f32 a, f32 b, f32 c, f32 d) {
    PUT(0x64028000);
    PUTF(a);
    PUTF(b);
    PUTF(c);
    PUTF(d);
    PUT((D_33D6F0 + 0xE) | 0x14000000);
}

extern "C" void func_0021CEE8(s32 a, s32 b, s32 c, s32 d) { PUT(0x6C018000); PUTF2((f32)a * 0.0078125f); PUTF2((f32)b * 0.0078125f); PUTF2((f32)c * 0.0078125f); PUTF2((f32)d * 0.0078125f); PUT2((D_33D6F0 + 0xA) | 0x14000000); }

extern "C" void func_0021CFA8(u32 a, u32 b) {
    PUT(0x64018000);
    PUT(b);
    PUT(a);
    PUT((D_33D6F0 + 0x12) | 0x14000000);
}

extern "C" void func_0021D010(u32 a, u32 b) {
    PUT(0x68018000);
    PUT(b);
    PUT(a);
    PUT(0);
    PUT((D_33D6F0 + 0x16) | 0x14000000);
}

extern "C" void func_0021D088(u32 a, u32 b) {
    PUT(0x68018000);
    PUT(b);
    PUT(a);
    PUT(0);
    PUT((D_33D6F0 + 0x1A) | 0x14000000);
}

extern "C" void func_0021D100(void) {
    PUT((D_33D6F0 + 0x1C) | 0x14000000);
}

extern "C" void func_0021D130(void) {
    PUT((D_33D6F0 + 0x1E) | 0x14000000);
}

extern "C" void func_0021D160(void) {
    PUT(0x11000000); PUT(0x1000404); PUT(0x5000000); PUT(0x3000270); PUT(0x200003A); PUT(0x6C018000);
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[3] = 0; p[0] = 1; p[1] = 0x10000000; p[2] = 1; }
    PUT2(D_33D6F0 | 0x14000000); PUT(0x10000000);
}

extern "C" void func_0021D248(s32 addr, s32 n, s32 src, u32 last) {
    while (n > 0) {
        s32 c = Chunk21D(n, 0x39, 3);
        func_00237350(0xC);
        PUT2(((c + 1) << 16) | 0x6C008000);
        n -= c;
        PUT(c);
        PUT(addr);
        addr += c;
        PUT(0);
        PUT(0);
        ((F860c)func_00237860)(c, src);
        src += c * 16;
        PUT(last);
    }
}

extern "C" void func_0021D390(s32 a, s32 b, s32 c) {
    func_0021D248(a, b, c, (D_33D6F0 + 0x14) | 0x14000000);
    return;
}

extern "C" void func_0021D3B8(s32 a, s32 b, s32 c) {
    func_0021D248(a, b, c, (D_33D6F0 + 0x18) | 0x14000000);
    return;
}

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021D3E0);

extern "C" void func_0021D4D0(void) {
    if (--D_33D6FC == 0) {
        PUT(D_33D704);
        func_0021D3E0();
        return;
    }
}

extern "C" void func_0021D530(s32 a, s32 b) {
    D_33D6F8 = a;
    D_33D6FC = 0;
    D_33D700 = b;
    D_33D704 = (D_33D6F0 + 0x14) | 0x14000000;
    func_0021D3E0();
    return;
}

extern "C" void func_0021D578(s32 a, s32 b) {
    D_33D6F8 = a;
    D_33D6FC = 0;
    D_33D700 = b;
    D_33D704 = (D_33D6F0 + 0x18) | 0x14000000;
    func_0021D3E0();
    return;
}

extern "C" void func_0021D5C0(f32 a, f32 b, f32 c, f32 d) {
    if (D_33D6FC > 0) {
        PUTF(a);
        PUTF(b);
        PUTF(c);
        PUTF(d);
        func_0021D4D0();
        return;
    }
}

extern "C" void func_0021D638(s32 a, s32 b) {
    s32 n = a * b;
    D_33D6FC = n;
    PUT(((n + 1) << 16) | 0x6E00C000);
    PUTB(a);
    PUTB(b);
    PUTB(0);
    PUTB(0);
}

extern "C" void func_0021D6B8(s32 a, s32 b) {
    if (D_33D6FC > 0) {
        PUTB(a);
        PUTB(b);
        PUTB(0);
        PUTB(0);
        if (--D_33D6FC == 0) PUT((D_33D6F0 + 0x20) | 0x14000000);
    }
}

extern "C" void func_0021D750(s32 n, s32 a, s32 b, s32 c, s32 d) {
    PUT(0x6C028000); PUT(a); PUT(b); PUT(c); PUT(d);
    { s64 t = ((s64)(n | 0x14) << 47) | ((s64)0x8001 << 46); u32 *p = D_002B94E4; D_002B94E4 = p + 2; p[1] = t >> 32; p[0] = t; }
    { u32 *p = D_002B94E4; D_002B94E4 = p + 2; p[0] = 0x42; p[1] = 0; }
    PUT2((D_33D6F0 + 0x22) | 0x14000000);
}
