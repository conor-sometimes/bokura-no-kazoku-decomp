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
// @decl-end

extern "C" void func_0021F250(f32 a, f32 b) {
    PUT(0x64018000);
    PUTF(a);
    PUTF(b);
    PUT((D_33D9A0 + 0xC) | 0x14000000);
}

INCLUDE_ASM("asm/nonmatchings/Unit21F250", func_0021F2B8);

extern "C" void func_0021F400(f32 a, f32 b, f32 c, f32 d) {
    PUT(0x64028000);
    PUTF(a);
    PUTF(b);
    PUTF(c);
    PUTF(d);
    PUT((D_33D9A0 + 0x12) | 0x14000000);
}

INCLUDE_ASM("asm/nonmatchings/Unit21F250", func_0021F488);

extern "C" void func_0021F5D0(f32 a, f32 b, f32 c, f32 d) {
    PUT(0x64028000);
    PUTF(a);
    PUTF(b);
    PUTF(c);
    PUTF(d);
    PUT((D_33D9A0 + 0x16) | 0x14000000);
}

INCLUDE_ASM("asm/nonmatchings/Unit21F250", func_0021F658);

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

INCLUDE_ASM("asm/nonmatchings/Unit21F250", func_0021FAD8);

INCLUDE_ASM("asm/nonmatchings/Unit21F250", func_0021FBC0);

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

INCLUDE_ASM("asm/nonmatchings/Unit21F250", func_002201A0);

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

INCLUDE_ASM("asm/nonmatchings/Unit21F250", func_00220D10);

INCLUDE_ASM("asm/nonmatchings/Unit21F250", func_00220DA8);

INCLUDE_ASM("asm/nonmatchings/Unit21F250", func_00220E08);

/* GNU as 2.10 corrupts the lui of the next lw macro here without this (docs/lessons.md) */
asm(".p2align 3");
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
