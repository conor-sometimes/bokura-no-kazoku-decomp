#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern u32 *D_002B94E4;
extern s32 D_33D9A0;
extern s32 D_33D9B0;
extern s32 D_33D9B4;
extern s32 D_33D9B8;
extern s32 D_33D9BC;
extern "C" void func_0021FBC0(s32, s32, s32, u32);
extern "C" void func_0021FD58(void);
#define PUT(v) { u32 *_p = D_002B94E4; D_002B94E4 = _p + 1; *_p = (v); }
#define PUTF(v) { f32 *_p = (f32 *)D_002B94E4; D_002B94E4 = (u32 *)(_p + 1); *_p = (v); }

struct CVec4 { f32 x; f32 y; f32 z; f32 w; };
void Func270CA0(CVec4 *, void *);
struct V4 { f32 x; f32 y; f32 z; s32 w; };
extern V4 D_33DCE0;
extern s32 D_33DCF0;
extern CVec4 D_33DC10;
extern CVec4 D_33DC50;
struct S4 { s32 m0; s32 m4; s32 m8; s32 mC; };
extern S4 D_33DCD0;
struct Pair { s32 a; s32 b; };
extern Pair D_002B8AA0[];
extern "C" void func_00220E08(void);
extern "C" void func_00221028(void);
void Func220A18(s32 a, s32 b, s32 c, s32 d);
extern "C" void func_002210E0(void);
extern "C" void func_00221100(void);
extern "C" void func_002217E0(CVec4 *);
extern "C" void func_00221908(CVec4 *);
#define PUTB(v) { u8 *_p = (u8 *)D_002B94E4; D_002B94E4 = (u32 *)(_p + 1); *_p = (v); }

struct Blk128 { u64 d[16]; };
extern Blk128 D_33DB90;

extern "C" void func_0021FE48(void);

extern "C" void func_00227AE8(void);
extern "C" void func_002379D0(s32);
extern "C" s32 func_0021BCF8(s32, s32);
extern "C" s32 func_002375C0(void);
extern "C" s32 func_002377D8(void);
void Func225088();
int Func2250C0();

#define PUT2(v) { u32 _v = (v); u32 *_p = D_002B94E4; D_002B94E4 = _p + 1; *_p = _v; }
extern "C" s32 func_00221008(void);
typedef s32 (*FnI)(void);
extern "C" s32 func_00220AE8(void);
extern "C" void func_00221468(s32);
extern "C" void func_00222258(void);
extern "C" void func_00221B08(Blk128 *);
extern "C" void func_00222050(s32, s32, s32, s32);
#define PUT2(v) { u32 _v = (v); u32 *_p = D_002B94E4; D_002B94E4 = _p + 1; *_p = _v; }

#define PUT2(v) { u32 _v = (v); u32 *_p = D_002B94E4; D_002B94E4 = _p + 1; *_p = _v; }
extern "C" void func_00237350(s32);
extern "C" s32 func_00237860(s32, CVec4 *);
inline s32 Chunk21F(s32 n, s32 max, s32 d) { s32 c = n; if (c > max) c = n / d; return c > max ? max : c; }
// @decl-end

extern "C" void func_0021F250(f32 a, f32 b) {
    PUT(0x64018000);
    PUTF(a);
    PUTF(b);
    PUT((D_33D9A0 + 0xC) | 0x14000000);
}

extern "C" void func_0021F2B8(s64 a, s64 b, s64 c, s64 d) {
    PUT(0x6C058000);
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[0] = 4; p[1] = 0x10000000; p[2] = 0xE; p[3] = 0; }
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[0] = b; p[1] = b >> 32; p[2] = a; p[3] = a >> 32; }
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[0] = d; p[1] = d >> 32; p[2] = c; p[3] = c >> 32; }
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[0] = 0x44; p[1] = 0; p[2] = 0x42; p[3] = 0; }
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[0] = 0x5000D; p[1] = 0; p[2] = 0x47; p[3] = 0; }
    PUT2((D_33D9A0 + 0x10) | 0x14000000);
}

extern "C" void func_0021F400(f32 a, f32 b, f32 c, f32 d) {
    PUT(0x64028000);
    PUTF(a);
    PUTF(b);
    PUTF(c);
    PUTF(d);
    PUT((D_33D9A0 + 0x12) | 0x14000000);
}

extern "C" void func_0021F488(s64 a, s64 b, s64 c, s64 d) {
    PUT(0x6C058000);
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[0] = 4; p[1] = 0x10000000; p[2] = 0xE; p[3] = 0; }
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[0] = b; p[1] = b >> 32; p[2] = a; p[3] = a >> 32; }
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[0] = d; p[1] = d >> 32; p[2] = c; p[3] = c >> 32; }
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[0] = 0x44; p[1] = 0; p[2] = 0x42; p[3] = 0; }
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[0] = 0x53001; p[1] = 0; p[2] = 0x47; p[3] = 0; }
    PUT2((D_33D9A0 + 0x14) | 0x14000000);
}

extern "C" void func_0021F5D0(f32 a, f32 b, f32 c, f32 d) {
    PUT(0x64028000);
    PUTF(a);
    PUTF(b);
    PUTF(c);
    PUTF(d);
    PUT((D_33D9A0 + 0x16) | 0x14000000);
}

extern "C" void func_0021F658(s64 a, s64 b, s64 c, s64 d) {
    PUT(0x6C058000);
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[0] = 4; p[1] = 0x10000000; p[2] = 0xE; p[3] = 0; }
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[0] = b; p[1] = b >> 32; p[2] = a; p[3] = a >> 32; }
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[0] = d; p[1] = d >> 32; p[2] = c; p[3] = c >> 32; }
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[0] = 0x44; p[1] = 0; p[2] = 0x42; p[3] = 0; }
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[0] = 0x5000D; p[1] = 0; p[2] = 0x47; p[3] = 0; }
    PUT2((D_33D9A0 + 0x18) | 0x14000000);
}

extern "C" void func_0021F7A0(s32 a, s32 b, s32 c, s32 d) {
    PUT(0x6C018000);
    PUTF(a * (1.0f / 128));
    PUTF(b * (1.0f / 128));
    PUTF(c * (1.0f / 128));
    PUTF(d * (1.0f / 128));
    PUT((D_33D9A0 + 0xA) | 0x14000000);
}

extern "C" void func_0021F860(s32 a, s32 b, s32 c, s32 d) {
    PUT(0x6C018000);
    PUTF(a * (1.0f / 128));
    PUTF(b * (1.0f / 128));
    PUTF(c * (1.0f / 128));
    PUTF(d * (1.0f / 128));
    PUT((D_33D9A0 + 0xE) | 0x14000000);
}

extern "C" void func_0021F920(u32 a, u32 b) {
    PUT(0x64018000);
    PUT(b);
    PUT(a);
    PUT((D_33D9A0 + 0x1C) | 0x14000000);
}

extern "C" void func_0021F988(u32 a, u32 b) {
    PUT(0x68018000);
    PUT(b);
    PUT(a);
    PUT(0);
    PUT((D_33D9A0 + 0x20) | 0x14000000);
}

extern "C" void func_0021FA00(u32 a, u32 b) {
    PUT(0x68018000);
    PUT(b);
    PUT(a);
    PUT(0);
    PUT((D_33D9A0 + 0x24) | 0x14000000);
}

extern "C" void func_0021FA78(void) {
    PUT((D_33D9A0 + 0x26) | 0x14000000);
}

extern "C" void func_0021FAA8(void) {
    PUT((D_33D9A0 + 0x28) | 0x14000000);
}

extern "C" void func_0021FAD8(void) {
    PUT(0x11000000); PUT(0x1000404); PUT(0x5000000); PUT(0x300024F); PUT(0x2000036); PUT(0x6C018000);
    { u32 *p = D_002B94E4; D_002B94E4 = p + 4; p[3] = 0; p[0] = 1; p[1] = 0x10000000; p[2] = 1; }
    PUT2(D_33D9A0 | 0x14000000); PUT(0x10000000);
}

extern "C" void func_0021FBC0(s32 addr, s32 n, s32 src, u32 last) {
    while (n > 0) {
        s32 c = Chunk21F(n, 0x35, 3);
        func_00237350(0xC);
        PUT2(((c + 1) << 16) | 0x6C008000);
        n -= c;
        PUT(c);
        PUT(addr);
        addr += c;
        PUT(0);
        PUT(0);
        func_00237860(c, (CVec4 *)src);
        src += c * 16;
        PUT(last);
    }
}

extern "C" void func_0021FD08(s32 a, s32 b, s32 c) {
    func_0021FBC0(a, b, c, (D_33D9A0 + 0x1E) | 0x14000000);
    return;
}

extern "C" void func_0021FD30(s32 a, s32 b, s32 c) {
    func_0021FBC0(a, b, c, (D_33D9A0 + 0x22) | 0x14000000);
    return;
}

INCLUDE_ASM("asm/nonmatchings/Unit21F250", func_0021FD58);

extern "C" void func_0021FE48(void) {
    if (--D_33D9B4 == 0) {
        PUT(D_33D9BC);
        func_0021FD58();
        return;
    }
}

extern "C" void func_0021FEA8(s32 a, s32 b) {
    D_33D9B0 = a;
    D_33D9B4 = 0;
    D_33D9B8 = b;
    D_33D9BC = (D_33D9A0 + 0x1E) | 0x14000000;
    func_0021FD58();
    return;
}

extern "C" void func_0021FEF0(s32 a, s32 b) {
    D_33D9B0 = a;
    D_33D9B4 = 0;
    D_33D9B8 = b;
    D_33D9BC = (D_33D9A0 + 0x22) | 0x14000000;
    func_0021FD58();
    return;
}

extern "C" void func_0021FF38(f32 a, f32 b, f32 c, f32 d) {
    if (D_33D9B4 > 0) {
        PUTF(a);
        PUTF(b);
        PUTF(c);
        PUTF(d);
        func_0021FE48();
        return;
    }
}

extern "C" void func_0021FFB0(s32 a, s32 b, s32 c) {
    s32 n = a * b;
    D_33D9B4 = n;
    PUT(((n + 1) << 16) | 0x6E00C000);
    PUTB(a);
    PUTB(b);
    PUTB(c);
    PUTB(0);
}

extern "C" void func_00220030(s32 a, s32 b, s32 c, s32 d) {
    if (D_33D9B4 > 0) {
        PUTB(a);
        PUTB(b);
        PUTB(c);
        PUTB(d);
        if (--D_33D9B4 == 0) PUT((D_33D9A0 + 0x2A) | 0x14000000);
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit21F250", func_002200C8);

extern "C" void func_002201A0(s32 n, s32 a, s32 b, s32 c, s32 d) {
    PUT(0x6C028000); PUT(a); PUT(b); PUT(c); PUT(d);
    { s64 t = ((s64)((n | 4) & ~0x10) << 47) | ((s64)0x8002 << 45); u32 *p = D_002B94E4; D_002B94E4 = p + 2; p[1] = t >> 32; p[0] = t; }
    { u32 *p = D_002B94E4; D_002B94E4 = p + 2; p[0] = 4; p[1] = 0; }
    PUT2((D_33D9A0 + 0x2E) | 0x14000000);
}

INCLUDE_ASM("asm/nonmatchings/Unit21F250", func_00220278);

INCLUDE_ASM("asm/nonmatchings/Unit21F250", func_00220318);

extern "C" void func_002203B8(u8 a, u8 b, u8 c, u8 d) {
    PUTB(a);
    PUTB(b);
    PUTB(c);
    PUTB(d);
}

extern "C" void func_00220408(void) {
    PUT((D_33D9A0 + 0x30) | 0x14000000);
}

extern "C" void func_00220438(void) {
    PUT((D_33D9A0 + 0x32) | 0x14000000);
}

extern "C" void func_00220468(void) {
    PUT((D_33D9A0 + 0x38) | 0x14000000);
}

extern "C" void func_00220498(void) {
    PUT((D_33D9A0 + 0x3A) | 0x14000000);
}

extern "C" void func_002204C8(void) {
    PUT((D_33D9A0 + 0x34) | 0x14000000);
}

extern "C" void func_002204F8(void) {
    PUT((D_33D9A0 + 0x36) | 0x14000000);
}

extern "C" void func_00220528(s32 a, s32 b) {
    D_33D9BC = 0;
    PUT((a + 0x157) | (b << 16) | 0x6C000000);
}

extern "C" void func_00220560(f32 a, f32 b, f32 c, f32 d) {
    PUTF(a);
    PUTF(b);
    PUTF(c);
    PUTF(d);
}

extern "C" void func_002205B0(s32 a, s32 b) {
    D_33D9B8 = 0;
    D_33D9BC = 0;
    PUT((a + 0xA5) | (b << 16) | 0x74000000);
}

extern "C" void func_002205F0(f32 a, f32 b) {
    PUTF(a);
    PUTF(b);
}

extern "C" void func_00220620(void) {
    func_00220E08();
    Func220A18(0x80, 0x80, 0x80, 0x80);
    func_00221028();
    D_33DCF0 = 0;
    D_33DCE0.x = 0;
    D_33DCE0.y = 0;
    D_33DCE0.z = 0;
    D_33DCE0.w = 0;
}

extern "C" void func_00220678(void) {
}

void Func220680(s32 v) {
    D_33DB90 = *(Blk128 *)v;
}

void Func2206C8(s32 v) {
    Func270CA0(&D_33DC10, (void *)v);
    return;
}

void Func2206E8(s32 v) {
    Func270CA0(&D_33DC50, (void *)v);
    return;
}

INCLUDE_ASM("asm/nonmatchings/Unit21F250", func_00220708);

INCLUDE_ASM("asm/nonmatchings/Unit21F250", Func220890__Fiiiiii);

void Func220A18(s32 a, s32 b, s32 c, s32 d) {
    D_33DCD0.m0 = a;
    D_33DCD0.m4 = b;
    D_33DCD0.m8 = c;
    D_33DCD0.mC = d;
}

extern "C" void func_00220A38(s32 v) {
    D_33DCF0 = v;
}

extern "C" s32 func_00220A48(void) {
    return D_33DCF0;
}

void Func220A58(f32 a, f32 b, f32 c) {
    D_33DCE0.x = a;
    D_33DCE0.y = b;
    D_33DCE0.z = c;
    D_33DCE0.w = 0;
}

extern "C" f32 func_00220A78(void) {
    return D_33DCE0.x;
}

extern "C" f32 func_00220A88(void) {
    return D_33DCE0.y;
}

extern "C" f32 func_00220A98(void) {
    return D_33DCE0.z;
}

extern "C" void func_00220AA8(void) {
    u8 buf[0x50];
    func_002210E0();
    func_002217E0(&D_33DC10);
    func_00221908(&D_33DC50);
    func_00221100();
}

INCLUDE_ASM("asm/nonmatchings/Unit21F250", func_00220AE8);

extern "C" void func_00220D10(void) { s32 a = func_00221008(); s32 b = ((FnI)func_00220AA8)(); s32 c = func_00220AE8(); func_002210E0(); func_00221468(a); func_00222258(); func_00221B08(&D_33DB90); func_00222050(D_33DCD0.m0, D_33DCD0.m4, D_33DCD0.m8, D_33DCD0.mC); func_00221468(b); func_00221468(c); return func_00221100(); }

extern "C" s32 func_00220DA8(void) { s32 a = func_0021BCF8(1, 0); Func225088(); func_00227AE8(); s32 b = Func2250C0(); func_002375C0(); func_002379D0(a); func_002379D0(b); return func_002377D8(); }

INCLUDE_ASM("asm/nonmatchings/Unit21F250", func_00220E08);

extern "C" s32 func_00220FB8(u32 i) {
    s32 r = 0;
    if (i < 7) r = D_002B8AA0[i].a;
    return r;
}

extern "C" s32 func_00220FE0(u32 i) {
    s32 r = 0;
    if (i < 7) r = D_002B8AA0[i].b;
    return r;
}
