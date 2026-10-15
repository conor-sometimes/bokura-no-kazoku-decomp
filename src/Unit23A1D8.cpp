#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "libc.h"
s32 Func235DE0(const char *fmt, ...);
extern const char _ctype_[];
struct GsDispL { u64 b0 : 1; u64 b1 : 1; u64 rest : 62; u64 m8[4]; };
struct GsDBL { GsDispL disp[2]; u8 buf[2][0x110]; };
extern GsDBL D_37CA90;
extern s32 D_37CA8C;
extern s32 D_37CA74;
extern s32 D_37CA78;
extern u8 D_37CAE0[];
extern u8 D_37CB00[];
extern u64 D_37CD00[];
extern u64 D_37CD10;
extern u8 D_37CD20[];
struct LNode { s16 a; s16 b; };
extern LNode D_37CDE0[];
struct TexEnt { u64 m0; u64 m8; char name[0x14]; s16 m24; s16 m26; s32 m28; s32 m2C; };
extern TexEnt *D_382E10;
extern s16 *D_382E1C;
extern s16 D_380E10[];
extern s32 D_380E08;
extern s32 D_386E24;
extern s32 D_002B94F0;
extern u8 D_382E20[];
extern "C" void func_001F10C8(void *);
extern "C" void func_001F1150(void *);
extern "C" void func_001F1190(void);
extern "C" void func_001F11C8(void);
extern "C" void func_0023A4D8(s32, s32);
extern "C" void func_0023A4B8(s32);
extern "C" u64 func_0023DB28(u64, s32);
extern "C" void func_0023E088(u64);
extern "C" s32 func_0023E690(void *, s32);

extern s32 D_002B94F4;
struct GsTex { u64 tbp : 9; u64 rest : 55; };
struct TexCtx { u8 pad0[0x20]; GsTex m20; u64 m28; GsTex m30; u8 pad38[8]; u64 lo40 : 32; u64 m44 : 16; u64 rest44 : 16; u8 pad48[0xB8]; u64 m100; u64 m108; };
extern "C" s32 func_0023BA10(s32, s32, s32);
extern "C" u64 func_0023BCB8(s32, s32);
extern "C" void func_0023BFA0(u32);
extern "C" u64 func_0023DD40(s32, s32, s32, s32);
extern "C" void func_0023C0F8(u64, s32, u32 *);
extern "C" void func_0023C048(s32, u32 *, u32 *);
extern "C" void func_0023A0F8(u64, s32, s32, s32, s32, void *);
extern "C" s32 func_0023C198(s32, s32, s32, s32);

extern u64 *D_382E14;
union TexH { u64 v; struct { u64 lo : 38; u64 w : 12; u64 h : 12; u64 rest : 2; } b; };
extern s16 *D_382E18;
extern "C" s32 func_0023B510(s32);
extern "C" s32 func_0023AFB8(u64);
extern "C" s32 func_0023BC28(s32, s32);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023A1D8);

extern "C" void func_0023A2A8(s32 on) {
    s32 b = on != 0;
    D_37CA8C = b;
    D_37CA90.disp[0].b1 = b;
    D_37CA90.disp[1].b1 = b;
    *(volatile u64 *)0x12000000 = *(u64 *)&D_37CA90.disp[0];
}

extern "C" u8 *func_0023A2F0(s32 i) {
    return D_37CAE0 + i * 0x110;
}

extern "C" u64 func_0023A310(s32 i) {
    return D_37CD00[i];
}

extern "C" void func_0023A328(u64 v) {
    D_37CD10 = v;
}

extern "C" u64 func_0023A338(void) {
    return D_37CD10;
}

extern "C" u8 *func_0023A348(s32 i) {
    return D_37CB00 + i * 0x110;
}

extern "C" s32 func_0023A368(void) {
    return D_37CA74;
}

extern "C" s32 func_0023A378(void) {
    return D_37CA78;
}

extern "C" u8 *func_0023A388(void) {
    return D_37CD20;
}

extern "C" void func_0023A398(void) {
    s32 i;
    for (i = 0; i < D_002B94F0; i++) D_382E1C[i] = 0;
}

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023A3E8);

extern "C" void func_0023A4B8(s32 i) {
    if (i < 2) {
        if (i >= 0) D_386E24 = i;
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023A4D8);

extern "C" void func_0023A9D8(void) {
    func_0023A4B8(0);
    func_001F10C8((void *)func_0023A4B8);
    return func_0023A4D8(0x200, 0x80);
}

extern "C" void func_0023AA08(void) {
    func_0023A4D8(0, 0);
    return func_001F1150((void *)func_0023A4B8);
}

extern "C" s32 func_0023AA30(void) {
    return D_380E08;
}

extern "C" u64 func_0023AA40(s32 i) {
    if (i < 0) return 0;
    i = D_380E10[i];
    if (i < 0) return 0;
    return D_382E10[i].m0;
}

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023AA80);

extern "C" void func_0023AB48(s32 i, s32 v) {
    if (i >= 0) {
        i = D_380E10[i];
        if (i >= 0) D_382E10[i].m28 = v;
    }
}

extern "C" s32 func_0023AB88(s32 i) {
    if (i < 0) return 0;
    i = D_380E10[i];
    if (i < 0) return 0;
    return D_382E10[i].m28;
}

extern "C" char *func_0023ABC8(s32 i) {
    if (i < 0) return 0;
    i = D_380E10[i];
    if (i < 0) return 0;
    return D_382E10[i].name;
}

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023AC10);

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023AC68);

extern "C" s32 func_0023AED8(s32 i) {
    if (i < 0) return -1;
    if (D_380E10[i] < 0) return -1;
    return D_37CDE0[i + 8].b - 8;
}

extern "C" s32 func_0023AF10(s32 i) {
    if (i < 0) return -1;
    if (D_380E10[i] < 0) return -1;
    return D_37CDE0[i + 8].a - 8;
}

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023AF48);

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023AFB8);

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", Func23B1D0__Fi);

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023B510);

extern "C" s32 func_0023B5F8(s32 i) {
    s32 r;
    if (i < 0) return -1;
    i = D_380E10[i];
    if (i < 0) return -1;
    func_001F1190();
    r = func_0023B510(i);
    func_001F11C8();
    return r;
}

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023B658);

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023B7B0);

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023B948);

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023BA10);

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023BC28);

extern "C" u64 func_0023BCB8(s32 i, s32 f) {
    s32 k;
    if (i < 0) return 0;
    i = D_380E10[i];
    if (i < 0) return 0;
    if (f == 0) return D_382E10[i].m8;
    k = func_0023BC28(((s16 *)&D_382E10[i])[0x17], f);
    if (k == -1) return 0;
    return D_382E14[k];
}

extern "C" s32 func_0023BD60(s32 a, s32 b) {
    return func_0023BA10(a, 0, b);
}

extern "C" u64 func_0023BD80(s32 a) {
    return func_0023BCB8(a, 0);
}

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023BD98);

extern "C" void func_0023BF80(void) {
    return func_0023BFA0(0);
}

extern "C" void func_0023BF98(void) {
}

extern "C" void func_0023BFA0(u32 i) {
    if (i < 3) D_002B94F4 = i;
}

extern "C" s32 func_0023BFB8(void) {
    return D_002B94F4;
}

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023BFC8);

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023C048);

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023C0F8);

extern "C" s32 func_0023C198(s32 r, s32 g, s32 b, s32 a) {
    s32 v;
    switch (D_002B94F4) {
    case 1:
        v = a ? 0x80 : 0;
        break;
    case 2:
        v = a ? 0 : 0x80;
        break;
    default:
        v = (r | g | b) ? 0x80 : 0;
        break;
    }
    return v;
}

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023C1E0);

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023C298);

INCLUDE_ASM("asm/nonmatchings/Unit23A1D8", func_0023C340);

extern "C" void func_0023C4D8(TexCtx *p, s32 f) {
    s32 v = (s32)p->m44 & 0xFFF0;
    if (f) v += 8;
    p->m44 = v;
}

extern "C" s32 func_0023C4F8(TexCtx *p) {
    return ((s32)p->m44 & 8) >> 3;
}

extern "C" void func_0023C510(TexCtx *p) {
    func_0023DB28(p->m100, -1);
    func_0023E088(p->m100);
    p->m100 = 0;
    func_0023DB28(p->m108, -1);
    func_0023E088(p->m108);
    p->m108 = 0;
}

extern "C" void func_0023C560(TexCtx *p, u64 h) {
    if (p->m100 != h) {
        func_0023DB28(p->m100, -1);
        func_0023E088(p->m100);
        func_0023DB28(h, 1);
        p->m100 = h;
        p->m20.tbp = (h & 0x3FFF) >> 5;
    }
}

extern "C" void func_0023C5D8(TexCtx *p, u64 h) {
    if (p->m108 != h) {
        func_0023DB28(p->m108, -1);
        func_0023E088(p->m108);
        func_0023DB28(h, 1);
        p->m108 = h;
        p->m30.tbp = (h & 0x3FFF) >> 5;
    }
}

extern "C" u64 func_0023C650(TexCtx *p) {
    return p->m100;
}

extern "C" u64 func_0023C658(TexCtx *p) {
    return p->m108;
}

extern "C" GsTex *func_0023C660(TexCtx *p) {
    return &p->m20;
}

extern "C" s32 func_0023C668(TexCtx *p) {
    return (p->m100 >> 38) & 0xFFF;
}
