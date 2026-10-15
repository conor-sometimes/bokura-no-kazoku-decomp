#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
s32 Func235DE0(const char *fmt, ...);
struct GNode {
    GNode *parent; GNode *child; GNode *next; s32 mC;
    f32 m10, m14, m18, m1C, m20, m24, m28, m2C;
    s32 m30, m34, m38, m3C, m40, m44, m48, m4C;
    f32 m50, m54; s32 m58; u8 pad5C[0x64];
    u8 mC0, mC1, mC2, mC3; u8 padC4[0x10]; s32 mD4; u8 padD8[0xC]; s32 mE4; u8 padE8[0x18];
    u64 m100;
};
struct GsBits { u64 f15 : 15; u64 rest : 49; };
extern "C" void func_0023C710(GNode *);
extern "C" void func_0023C758(GNode *);
extern "C" void func_0023C8D8(GNode *);
extern "C" void func_001F1190(void);
extern "C" void func_001F11C8(void);
extern "C" void func_0023CF18(const char *, ...);
extern s32 D_002B9500;
extern s32 D_002B9504;
extern s32 D_388F28;
extern s32 D_388F2C;
extern const char D_002E54D0[];
extern const char D_002E54E8[];
struct SemaP { s32 count; s32 max; s32 init; s32 wait; u32 attr; u32 opt; };
extern "C" s32 func_002731A0(SemaP *);
extern "C" s32 func_002731F0(s32);
extern "C" s32 func_002731C0(s32);
extern "C" s32 func_002731B0(s32);
extern "C" void func_001F1A80(void *, s32, s32, s32);
extern "C" void func_001F1230(void);
extern "C" s32 func_0023D128(void);
extern "C" void func_0022DDE8(s32);
extern "C" s32 func_0023D330(s32);
struct Ent16 { u8 b[16]; };
extern Ent16 D_002B9510[];
extern s32 D_002B95E0[][32];
extern s32 D_002B9C98[];

struct Blk { s16 next; s16 size; };
struct VEnt { s16 m0; s16 m2; s16 m4; };
extern VEnt D_388F30[];
extern s32 D_002B94F8;
extern s32 D_002B94FC;
extern u32 D_386E28[0x800];
extern s32 D_002B9508;
extern s32 D_002B950C;
extern s32 D_388E28[64];
extern s32 D_002B9CD0;
extern s32 D_002B9CD8;
extern const char D_002E5888[];
extern const char D_002E58C8[];
extern "C" void func_0023D130(void);
extern "C" s32 func_0023D190(void);
extern "C" s32 func_0023D660(void);
extern "C" s32 func_0023D470(void);
extern "C" void func_0023E438(Blk *, s32, s32);
extern "C" s32 func_0023E510(Blk *, s32, s32);
struct GsInfo { s16 m0; s16 m2; s16 m4; };
extern "C" GsInfo *func_0026E888(void);
// @decl-end

extern "C" s32 func_0023C680(GNode *n) {
    return (n->m100 >> 50) & 0xFFF;
}

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023C698);

extern "C" s32 func_0023C6C8(GsBits *p) {
    return (s32)p->f15 != 9;
}

extern "C" void func_0023C6E8(GNode *n, u8 a, u8 b, u8 c, u8 d) {
    n->mC0 = a;
    n->mC1 = b;
    n->mC2 = c;
    n->mC3 = d;
}

extern "C" void func_0023C700(GNode *n, s32 v) {
    n->mD4 = v;
    n->mE4 = v;
}

extern "C" void func_0023C710(GNode *n) {
    GNode *nx;
loop:
    n->m58 = 1;
    if (n->child) func_0023C710(n->child);
    nx = n->next;
    if (nx) {
        n = nx;
        goto loop;
    }
}

extern "C" void func_0023C758(GNode *n) {
    n->m58 = 1;
    if (n->child) return func_0023C710(n->child);
}

extern "C" s32 func_0023C790(GNode *n) {
    for (; n; n = n->parent) if (n->mC) return n->mC;
    return 0;
}

extern "C" void func_0023C7D0(GNode *n, s32 v) {
    n->mC = v;
}

extern "C" void func_0023C7D8(GNode *n, GNode *parent) {
    n->m4C = 0x80;
    n->m58 = 1;
    n->next = 0;
    n->m10 = 0;
    n->m14 = 0;
    n->m18 = 0;
    n->m1C = 0;
    n->m50 = 0;
    n->m54 = 0;
    n->mC = 0;
    n->m20 = 0;
    n->m24 = 0;
    n->m28 = 0;
    n->m2C = 0;
    n->m30 = 0;
    n->m34 = 0;
    n->m38 = 0;
    n->m3C = 0;
    n->m40 = 0;
    n->m44 = 0;
    n->m48 = 0;
    n->parent = parent;
    n->child = 0;
    if (parent) {
        n->next = parent->child;
        parent->child = n;
    }
}

extern "C" void func_0023C858(GNode *n) {
    if (n->child) {
        GNode *c;
        func_0023C710(n->child);
        for (c = n->child; c; c = c->next) c->parent = 0;
        n->child = 0;
    }
    if (n->parent) n->parent->child = n->next;
}

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023C8D8);

extern "C" void func_0023CCA0(GNode *n, f32 x, f32 y) {
    x = x > 0.0f ? x : 0.0f;
    x = (s32)x;
    y = y > 0.0f ? y : 0.0f;
    n->m18 = x;
    n->m1C = (s32)y;
    return func_0023C758(n);
}

extern "C" void func_0023CD00(GNode *n, f32 x, f32 y) {
    n->m10 = (s32)x;
    n->m14 = (s32)y;
    return func_0023C758(n);
}

extern "C" void func_0023CD40(GNode *n, f32 x, f32 y) {
    n->m20 = (s32)x;
    n->m24 = (s32)y;
    return func_0023C758(n);
}

extern "C" void func_0023CD80(GNode *n, f32 x, f32 y) {
    x = x > 0.0f ? x : 0.0f;
    x = (s32)x;
    y = y > 0.0f ? y : 0.0f;
    n->m28 = x;
    n->m2C = (s32)y;
    return func_0023C758(n);
}

extern "C" void func_0023CDE0(GNode *n, f32 x, f32 y) {
    n->m50 = (s32)x;
    n->m54 = (s32)y;
    return func_0023C758(n);
}

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023CE20);

extern "C" void func_0023CE58(GNode *n, s32 a, s32 b, s32 c, s32 d) {
    n->m30 = a;
    n->m34 = b;
    n->m38 = c;
    n->m3C = d;
}

extern "C" void func_0023CE70(GNode *n, s32 v) {
    n->m40 = v;
}

extern "C" u8 *func_0023CE78(GNode *n) {
    func_0023C8D8(n);
    return (u8 *)n + 0xB0;
}

extern "C" u8 *func_0023CEA0(GNode *n) {
    func_0023C8D8(n);
    return (u8 *)n + 0xA0;
}

extern "C" u8 *func_0023CEC8(GNode *n) {
    func_0023C8D8(n);
    return (u8 *)n + 0xA8;
}

extern "C" u8 *func_0023CEF0(GNode *n) {
    func_0023C8D8(n);
    return (u8 *)n + 0x88;
}

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023CF18);

extern "C" s32 func_0023D030(s32 v) {
    s32 old;
    func_001F1190();
    old = D_002B9500;
    D_002B9500 = v;
    func_001F11C8();
    return old;
}

extern "C" void func_0023D078(void) {
    if (D_002B9500) func_0023CF18(D_002E54D0);
    return (void)Func235DE0(D_002E54D0);
}

extern "C" void func_0023D0C0(s32 a) {
    if (D_002B9500) return func_0023CF18(D_002E54E8, a);
}

extern "C" s32 func_0023D100(s32 max, s32 init) {
    SemaP p;
    p.max = max;
    p.init = init;
    return func_002731A0(&p);
}

extern "C" s32 func_0023D128(void) {
    return 1;
}

extern "C" void func_0023D130(void) {
    while (func_002731F0(D_388F28) == -1) {
        func_001F1A80((void *)func_0023D128, 0, 0, 0);
        func_001F1230();
    }
}

extern "C" s32 func_0023D190(void) {
    return func_002731C0(D_388F28);
}

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023D1B0);

extern "C" s32 func_0023D2D8(void) {
    return D_388F2C;
}

extern "C" void func_0023D2E8(void) {
    func_002731B0(D_388F28);
    if (D_002B9504 >= 0) return func_0022DDE8(D_002B9504);
}

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023D330);

extern "C" Ent16 *func_0023D3C8(s32 x) {
    return &D_002B9510[func_0023D330(x)];
}

extern "C" s32 func_0023D3F8(s32 x, s32 y) {
    return ((s32 *)D_002B95E0)[func_0023D330(x) * 32 + y];
}

extern "C" s32 func_0023D438(s32 x) {
    return D_002B9C98[func_0023D330(x)];
}

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023D470);

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023D660);

extern "C" s32 func_0023DAC0(u64 h) {
    s32 r;
    if (h == 0) return 0;
    func_001F1190();
    r = D_388F30[(s32)((h >> 20) & 0xFFF)].m0;
    func_001F11C8();
    return r;
}

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023DB28);

extern "C" s32 func_0023DCF0(s32 fn) {
    s32 old = D_002B94F8;
    if (!fn) fn = (s32)func_0023D660;
    D_002B94F8 = fn;
    return old;
}

extern "C" s32 func_0023DD18(s32 fn) {
    s32 old = D_002B94FC;
    if (!fn) fn = (s32)func_0023D470;
    D_002B94FC = fn;
    return old;
}

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023DD40);

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023E088);

int Func23E290(void) {
    s32 n = 0;
    s32 i, j;
    func_001F1190();
    for (i = 0; i < 0x800; i++) {
        u32 w = D_386E28[i];
        for (j = 0; j < 8; j++) {
            if (w & 0xF) n++;
            w >>= 4;
        }
    }
    func_001F11C8();
    return n << 8;
}

extern "C" void func_0023E300(s32 *a, s32 *b) {
    *a = D_002B9508;
    *b = D_002B950C - D_002B9508;
}

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023E328);

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023E438);

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023E510);

extern "C" s32 func_0023E5E8(Blk *l) {
    return l[0].size;
}

extern "C" void func_0023E5F0(Blk *l, s32 n) {
    l[0].next = -1;
    l[0].size = 0;
    return func_0023E438(l, 1, n - 1);
}

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023E620);

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023E690);

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023E720);

extern "C" s32 func_0023E768(Blk *l, s32 i) {
    if (i < 0) return 0;
    return l[i + 1].size;
}

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023E788);

INCLUDE_ASM("asm/nonmatchings/Unit23C680", func_0023E7E8);
