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
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021D820);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021D8F0);

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

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021DEF8);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021E140);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021E170);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021E240);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021E310);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021E370);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021E4A0);

extern "C" s32 func_0021E6B8(u32 i) {
    s32 r = 0;
    if (i < 7) r = D_002B8A60[i].a;
    return r;
}

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

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021E860);

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

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021EAF0);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021EB60);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021EBE0);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021EC78);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021ED10);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021EDD0);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021EE40);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021EEC0);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021EF30);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021EFB0);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021F088);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021F108);

INCLUDE_ASM("asm/nonmatchings/Unit21D820", func_0021F190);
