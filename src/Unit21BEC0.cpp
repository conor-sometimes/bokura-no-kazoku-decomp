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

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021C8B8);

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021C978);

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021C9E8);

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021CA68);

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021CAD8);

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021CB58);

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021CC30);

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021CCB0);

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021CD38);

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

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021CEE8);

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

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021D160);

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021D248);

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

INCLUDE_ASM("asm/nonmatchings/Unit21BEC0", func_0021D750);
