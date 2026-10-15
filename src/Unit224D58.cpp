#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern u32 *D_002B94E4;
extern u8 D_002CDA00[];
extern u8 D_002CDBB8[];
extern u8 D_002CDB10[];
extern u8 D_002CE5E8[];
extern u8 D_002CDBE8[];
extern u8 D_002CDC38[];
extern u8 D_002CDC78[];
extern u8 D_002CDCC8[];
extern u8 D_002CDDB0[];
extern u8 D_002CDD38[];
extern u8 D_002CDD78[];
extern u8 D_002CE888[];
extern u8 D_002CE948[];
extern u8 D_002CDE48[];
extern u8 D_002CDEE8[];
extern u8 D_002CEC90[];
extern u8 D_002CED40[];
extern u8 D_002CE1C8[];
extern u8 D_002CDFA8[];
extern u8 D_002CE170[];
extern u8 D_002CE628[];
extern u8 D_002CE808[];
extern u8 D_002CEE00[];
extern u8 D_002CE2B0[];
extern u8 D_002CDDD8[];
extern u32 D_33DE90;
extern u32 D_33DE94;
extern s32 D_33DE98;
extern s32 D_33DE9C;
extern s32 D_33DEA0;
extern s32 D_33DEA4;
extern s32 D_33DEA8;
extern s32 D_33DEAC;
extern s32 D_33DEB0;
extern s32 D_33DEB4;
extern s32 D_33DEB8;
extern s32 D_002B8C18;
extern s32 D_002B8C1C;
extern s32 D_002B8C20;
struct QW { u64 lo; u64 hi; };
struct Save33E220 { s32 w[13]; s32 pad[3]; QW q[54]; s32 last; };
extern Save33E220 D_33E220;
extern QW D_33DEC0[54];
extern s32 D_002B8BE0[7][2];
#define PKT D_002B94E4
inline u32 *PUT(u32 v) { u32 *p = PKT; PKT = p + 1; *p = v; return p; }
inline void PUTF(f32 v) { f32 *p = (f32 *)PKT; PKT = (u32 *)(p + 1); *p = v; }
#define MSCAL(l) (0x14000000 | ((l - D_002CDA00 + 7) / 8))
#define MSADDR(l) ((l - D_002CDA00 + 7) / 8)
inline s32 Chunk2(s32 n, s32 max) { s32 c = n; if (n > max) c = n / 2; return c > max ? max : c; }
extern "C" s32 func_00239088(void);
extern "C" s32 func_002390A0(void);
extern "C" s32 func_002375C0(void);
extern "C" void *func_002377D8(void);
int Func238158(void *p, int v);
extern "C" void *func_00237350(s32);
extern "C" s32 func_00237398(s32, void *);
extern "C" void *func_00237860(s32, void *);
extern "C" s32 func_002379D0(s32);
extern "C" void func_00225070(void);
extern "C" void func_00224FF0(u32);
extern "C" void func_00225B08(s32, s32, s32, u8 *, u32);
// @decl-end

extern "C" s32 func_00224D58(u32 i) {
    s32 r = 0;
    if (i < 7) r = D_002B8BE0[i][1];
    return r;
}

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00224D80);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00224EB8);

extern "C" void func_00224FF0(u32 v) {
    if (v) {
        if (v != D_33DE90) {
            D_33DE90 = v;
            v |= 0x14000000;
        } else {
            v = 0x17000000;
        }
        PUT(v);
    }
}

extern "C" s32 func_00225040(void) {
    return func_00239088();
}

extern "C" s32 func_00225058(void) {
    return func_002390A0();
}

extern "C" void func_00225070(void) {
    D_33DE90 = 0;
    D_33DE94 = 1;
}

void Func225088() {
    func_00225070();
    return (void)func_002375C0();
}

extern "C" void *func_002250A8(s32 n, void *p) {
    return func_00237860(n, p);
}

int Func2250C0() {
    return Func238158(func_002377D8(), 1);
}

extern "C" void func_002250E8(u32 a) {
    PUT(0x60018000);
    PUT(a);
    PUT(MSCAL(D_002CDBB8));
    D_33DE90 = 0;
}

extern "C" void func_00225168(f32 a) {
    PUT(0x60018000);
    PUTF(a);
    PUT(MSCAL(D_002CDB10));
    D_33DE90 = 0;
}

void Func2251E8() {
    PUT(MSCAL(D_002CE5E8));
    D_33DE90 = 0;
}

int Func225240(int a) {
    return func_002379D0(a);
}

extern "C" void func_00225258(void *src) {
    PUT(0x6C048000);
    func_00237398(0x10, src);
    PUT(MSCAL(D_002CDBE8));
    D_33DE90 = 0;
}

extern "C" void func_002252E8(void *src) {
    func_00237350(0xC);
    PUT(0x6C048000);
    func_00237860(4, src);
    PUT(MSCAL(D_002CDBE8));
    D_33DE90 = 0;
}

extern "C" void func_00225390(void *src, f32 s) {
    u32 *q;
    func_00237350(0xC);
    PUT(0x6C048000);
    q = PKT;
    PKT = q + 16;
    asm __volatile__(
        "mfc1 $8, %0\n"
        "qmtc2.ni $8, $vf2\n"
        "lqc2 $vf4, 0x0(%1)\n"
        "lqc2 $vf5, 0x10(%1)\n"
        "lqc2 $vf6, 0x20(%1)\n"
        "lqc2 $vf7, 0x30(%1)\n"
        "vmulx.xyzw $vf4, $vf4, $vf2x\n"
        "vmulx.xyzw $vf5, $vf5, $vf2x\n"
        "vmulx.xyzw $vf6, $vf6, $vf2x\n"
        "vmulx.xyzw $vf7, $vf7, $vf2x\n"
        "sqc2 $vf4, 0x0(%2)\n"
        "sqc2 $vf5, 0x10(%2)\n"
        "sqc2 $vf6, 0x20(%2)\n"
        "sqc2 $vf7, 0x30(%2)\n"
        : : "f"(s), "r"(src), "r"(q) : "$8", "memory");
    PUT(MSCAL(D_002CDBE8));
    D_33DE90 = 0;
}

void Func225470(int src) {
    PUT(0x6C038000);
    func_00237398(0xC, (void *)src);
    PUT(MSCAL(D_002CDC38));
    D_33DE90 = 0;
}

extern "C" void func_00225500(void *src) {
    func_00237350(0xC);
    PUT(0x6C038000);
    func_00237860(3, src);
    PUT(MSCAL(D_002CDC38));
    D_33DE90 = 0;
}

void Func2255A8(int src) {
    PUT(0x6C048000);
    func_00237398(0x10, (void *)src);
    PUT(MSCAL(D_002CDC78));
    D_33DE90 = 0;
}

extern "C" void func_00225638(void *src) {
    func_00237350(0xC);
    PUT(0x6C048000);
    func_00237860(4, src);
    PUT(MSCAL(D_002CDC78));
    D_33DE90 = 0;
}

extern "C" void func_002256E0(void *src) {
    PUT(0x6C088000);
    func_00237398(0x20, src);
    PUT(MSCAL(D_002CDCC8));
    D_33DE90 = 0;
}

extern "C" void func_00225770(void *src) {
    func_00237350(0xC);
    PUT(0x6C088000);
    func_00237860(8, src);
    PUT(MSCAL(D_002CDCC8));
    D_33DE90 = 0;
}

extern "C" void func_00225818(s32 a) {
    PUT(0x60018000);
    PUT(a << 1);
    PUT(MSCAL(D_002CDDB0));
    D_33DE90 = 0;
}

extern "C" void func_00225898(void *src) {
    PUT(0x6C028000);
    func_00237398(8, src);
    PUT(MSCAL(D_002CDD38));
    D_33DE90 = 0;
}

extern "C" void func_00225928(void *src) {
    func_00237350(0xC);
    PUT(0x6C028000);
    func_00237860(2, src);
    PUT(MSCAL(D_002CDD38));
    D_33DE90 = 0;
}

extern "C" void func_002259D0(void *src) {
    PUT(0x6C028000);
    func_00237398(8, src);
    PUT(MSCAL(D_002CDD78));
    D_33DE90 = 0;
}

extern "C" void func_00225A60(void *src) {
    func_00237350(0xC);
    PUT(0x6C028000);
    func_00237860(2, src);
    PUT(MSCAL(D_002CDD78));
    D_33DE90 = 0;
}

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00225B08);

extern "C" void func_00225C50(s32 addr, s32 n, s32 flag, u8 *src) {
    return func_00225B08(addr, n, flag, src, flag ? MSADDR(D_002CE888) : MSADDR(D_002CE948));
}

extern "C" void func_00225CB0(s32 addr, s32 n, u8 *src) {
    return func_00225B08(addr, n, 0, src, MSADDR(D_002CDE48));
}

extern "C" void func_00225CF8(s32 addr, s32 n, s32 flag, u8 *src) {
    return func_00225B08(addr, n, flag, src, flag ? MSADDR(D_002CDE48) : MSADDR(D_002CDEE8));
}

extern "C" void func_00225D58(s32 addr, s32 n, s32 flag, u8 *src) {
    return func_00225B08(addr, n, flag, src, flag ? MSADDR(D_002CEC90) : MSADDR(D_002CED40));
}

extern "C" void func_00225DB8(u32 a, u32 b) {
    PUT(0x64018000);
    PUT(b);
    PUT(a);
    PUT(MSCAL(D_002CE1C8));
    D_33DE90 = 0;
}

extern "C" void func_00225E48(u32 a, u32 b) {
    PUT(0x64018000);
    PUT(b);
    PUT(a);
    PUT(MSCAL(D_002CDFA8));
    D_33DE90 = 0;
}

extern "C" void func_00225ED8(u32 a, u32 b) {
    PUT(0x64018000);
    PUT(b);
    PUT(a);
    PUT(MSCAL(D_002CE170));
    D_33DE90 = 0;
}

extern "C" void func_00225F68(void) {
    PUT(MSCAL(D_002CE628));
}

extern "C" void func_00225FB8(u32 a, u32 b) {
    PUT(0x68018000);
    PUT(b);
    PUT(a);
    PUT(D_33DE94);
    PUT(MSCAL(D_002CE808));
    D_33DE94 = 0;
    D_33DE90 = 0;
}

extern "C" void func_00226068(u32 a, u32 b) {
    PUT(0x64018000);
    PUT(b);
    PUT(a);
    PUT(MSCAL(D_002CEE00));
    D_33DE90 = 0;
}

extern "C" void func_002260F8(u32 a, u32 b) {
    PUT(0x64018000);
    PUT(b);
    PUT(a);
    PUT(MSCAL(D_002CE2B0));
    D_33DE90 = 0;
}

extern "C" void func_00226188(f32 a, f32 b, f32 c, f32 d) {
    c *= 0.5f;
    d *= 0.5f;
    PUT(0x64028000);
    PUTF(a + c);
    PUTF(b + d);
    PUTF(c);
    PUTF(d);
    PUT(MSCAL(D_002CDDD8));
    D_33DE90 = 0;
}

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00226250);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00226338);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_002263C8);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00226478);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_002264D8);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00226520);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00226568);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_002265E0);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00226668);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00226730);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00226810);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00226860);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_002268C8);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00226920);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00226960);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_002269B8);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00226A10);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00226A68);

INCLUDE_ASM("asm/nonmatchings/Unit224D58", func_00226AA8);
