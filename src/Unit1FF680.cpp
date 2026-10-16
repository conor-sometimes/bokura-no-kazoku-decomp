#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
int Func235DE0(const char *, ...);
class CVec4 { public: f32 x, y, z, w; };
void Func270CA0(CVec4 *, void *);
extern "C" int func_0023E5E8(int);
extern "C" s32 func_00200A30(void *);
extern s32 D_002A5CD0;
extern s32 D_002A5CD4;
extern f32 D_002A5CE0[4];
extern f32 D_002A5CF0[4];
extern f32 D_002A5D00;
extern f32 D_002A5D04;
extern s32 D_002A5D08;
extern const char D_002E26B8[];
extern const char D_002E2960[];
extern s32 D_30E104;
extern s32 D_30E3C0;
extern s32 D_30E3C8;
extern s32 D_30E3CC;
extern f32 D_30E210[4];
extern f32 D_30E220[4];
extern f32 D_30E230[4];
extern f32 D_30E3D0[3][4];
extern f32 D_30E400[3][4];
extern f32 D_30E430[4];
extern char D_30E2C0[];
extern s32 D_30E180;
extern s32 D_30E184;
extern s32 D_30E188;
struct HrcNode { u8 pad0[6]; u16 m_flags; };
struct HrcTbl { s32 m_count; s32 m4; HrcNode m_nodes[1]; };

extern "C" void func_001F1D80(const char *);
extern "C" s32 func_00224D58(s32);
extern "C" s32 func_00222CB8(s32);
extern "C" s32 func_0021C638(s32);
extern "C" s32 func_0021E6E0(s32);
extern "C" s32 func_00220FE0(s32);
extern "C" s32 func_00200B28(void *, s32);
extern "C" void func_001F2838(void);
extern "C" void func_00225070(void);
extern "C" void func_00227A20(void);
extern "C" void func_00227AA8(void);
extern "C" void func_001F2628(void);
extern "C" void func_00222D98(void);
extern "C" void func_00223A68(void);
extern "C" void func_00223A78(void);
extern "C" void func_001F36D0(void);
extern "C" void func_0021C748(void);
extern "C" void func_001F3AC0(void);
extern "C" void func_0021E810(void);
extern "C" void func_002210D8(void);
extern "C" void func_00271380(void *, void *, void *, void *);
extern "C" void func_00270790(void *, void *);
extern "C" void func_002705A0(void *, void *, void *);
extern "C" void func_00271440(void *, void *, void *, void *, void *);
extern "C" s32 func_0023AED8(s32);
typedef void (*RendFn)(void);
struct RendCfg { RendFn m0, m4, m8, mC; s32 m10[5]; s32 m24, m28, m2C, m30, m34, m38; };
extern RendCfg D_30E170;
extern const char D_002E2890[];
extern const char D_002E28A8[];
extern const char D_002E28C0[];
extern const char D_002E28E0[];
extern const char D_002E2900[];
extern const char D_002E2920[];
extern const char D_002E2940[];
extern f32 D_30E340[4][4];
extern f32 D_30E380[4][4];
extern f32 D_30E300[4][4];
struct HrcObj { HrcObj *m0; s32 m4; s32 m8; s32 mC; s32 m10[1]; };
extern HrcObj *D_30E108;
extern "C" s32 func_002051B8(void *);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Unit1FF680", func_001FF680);

INCLUDE_ASM("asm/nonmatchings/Unit1FF680", func_001FF960);

INCLUDE_ASM("asm/nonmatchings/Unit1FF680", func_001FFC20);

INCLUDE_ASM("asm/nonmatchings/Unit1FF680", func_001FFF78);

INCLUDE_ASM("asm/nonmatchings/Unit1FF680", func_00200130);

INCLUDE_ASM("asm/nonmatchings/Unit1FF680", func_002003A8);
INCLUDE_RODATA("asm/nonmatchings/Unit1FF680", D_002E26B8);

extern "C" int func_00200560(HrcTbl *t) {
    s32 n = t->m_count;
    s32 c = 0;
    s32 i;
    for (i = 0; i < n; i++) {
        if (!(t->m_nodes[i].m_flags & 0x40)) c++;
    }
    if (D_002A5CD0) return Func235DE0(D_002E26B8, c, n);
}

INCLUDE_ASM("asm/nonmatchings/Unit1FF680", func_002005D0);

INCLUDE_ASM("asm/nonmatchings/Unit1FF680", func_002008A0);

extern "C" s32 func_00200A30(void *p) {
    if (*(s32 *)p <= 0) return 0;
    return (s32)p + *(s32 *)p;
}

extern "C" s32 func_00200A50(void *p) {
    return *(s32 *)func_00200A30(p);
}

extern "C" s32 func_00200A70(HrcObj *p, void *x, s32 y, s32 a, s32 b) {
    s32 n = 0;
    s32 i;
    p->m0 = D_30E108;
    D_30E108 = p;
    p->m4 = a;
    p->m8 = b;
    if (y >= 0) n = func_002051B8(x);
    p->mC = n;
    for (i = 0; i < n; i++) {
        p->m10[i] = y;
        y = func_0023AED8(y);
    }
    return (n * 4 + (s32)p + 0x8F) & ~0x7F;
}

INCLUDE_ASM("asm/nonmatchings/Unit1FF680", func_00200B28);
INCLUDE_RODATA("asm/nonmatchings/Unit1FF680", D_002E2890);
INCLUDE_RODATA("asm/nonmatchings/Unit1FF680", D_002E28A8);
INCLUDE_RODATA("asm/nonmatchings/Unit1FF680", D_002E28C0);
INCLUDE_RODATA("asm/nonmatchings/Unit1FF680", D_002E28E0);
INCLUDE_RODATA("asm/nonmatchings/Unit1FF680", D_002E2900);
INCLUDE_RODATA("asm/nonmatchings/Unit1FF680", D_002E2920);
INCLUDE_RODATA("asm/nonmatchings/Unit1FF680", D_002E2940);
INCLUDE_RODATA("asm/nonmatchings/Unit1FF680", D_002E2960);

extern "C" s32 func_00201210(void *buf, s32 r) {
    func_001F1D80(D_002E2890);
    D_30E170.m38 = 0;
    D_30E170.m28 = func_00224D58(3);
    D_30E170.m24 = func_00224D58(0);
    D_30E170.m2C = func_00224D58(2);
    D_30E170.m30 = func_00224D58(5);
    D_30E170.m34 = func_00224D58(4) - 1;
    D_30E170.m0 = func_001F2838;
    D_30E170.m4 = func_00225070;
    D_30E170.m8 = func_00227A20;
    D_30E170.mC = func_00227AA8;
    return func_00200B28(buf, r);
}

extern "C" s32 func_002012D8(void *buf) {
    func_001F1D80(D_002E28A8);
    D_30E170.m38 = 1;
    D_30E170.m24 = func_00222CB8(0);
    D_30E170.m28 = 0x7FFFFFFF;
    D_30E170.m2C = 0x7FFFFFFF;
    D_30E170.m30 = 0x7FFFFFFF;
    D_30E170.m0 = func_001F2628;
    D_30E170.m4 = func_00222D98;
    D_30E170.m8 = func_00223A68;
    D_30E170.mC = func_00223A78;
    return func_00200B28(buf, -1);
}

extern "C" s32 func_00201378(void *buf) {
    func_001F1D80(D_002E28C0);
    D_30E170.m38 = 2;
    D_30E170.m28 = func_0021C638(1);
    D_30E170.m24 = func_0021C638(0);
    D_30E170.m2C = 0x7FFFFFFF;
    D_30E170.m30 = 0x7FFFFFFF;
    D_30E170.m0 = func_001F36D0;
    D_30E170.m4 = func_0021C748;
    D_30E170.m8 = 0;
    D_30E170.mC = 0;
    return func_00200B28(buf, -1);
}

extern "C" s32 func_00201410(void *buf) {
    func_001F1D80(D_002E28E0);
    D_30E170.m38 = 3;
    D_30E170.m28 = func_0021E6E0(1);
    D_30E170.m24 = func_0021E6E0(0);
    D_30E170.m2C = func_0021E6E0(2);
    D_30E170.m30 = func_0021E6E0(4);
    D_30E170.m34 = func_00224D58(4) - 1;
    D_30E170.m0 = func_001F3AC0;
    D_30E170.m4 = func_0021E810;
    D_30E170.m8 = 0;
    D_30E170.mC = 0;
    return func_00200B28(buf, -1);
}

extern "C" s32 func_002014C0(void *buf) {
    func_001F1D80(D_002E2900);
    D_30E170.m38 = 4;
    D_30E170.m28 = func_00220FE0(1);
    D_30E170.m24 = func_00220FE0(0);
    D_30E170.m2C = func_00220FE0(2);
    D_30E170.m30 = func_00220FE0(4);
    D_30E170.m34 = func_00224D58(4) - 1;
    D_30E170.m0 = func_001F3AC0;
    D_30E170.m4 = func_002210D8;
    D_30E170.m8 = 0;
    D_30E170.mC = 0;
    return func_00200B28(buf, -1);
}

extern "C" s32 func_00201570(void *buf, s32 r) {
    func_001F1D80(D_002E2920);
    D_30E170.m38 = 3;
    D_30E170.m28 = func_0021E6E0(1);
    D_30E170.m24 = func_0021E6E0(0);
    D_30E170.m2C = func_0021E6E0(2);
    D_30E170.m30 = func_0021E6E0(4);
    D_30E170.m34 = func_00224D58(4) - 1;
    D_30E170.m0 = func_001F3AC0;
    D_30E170.m4 = func_0021E810;
    D_30E170.m8 = 0;
    D_30E170.mC = 0;
    return func_00200B28(buf, r);
}

extern "C" s32 func_00201628(void *buf, s32 r) {
    func_001F1D80(D_002E2940);
    D_30E170.m38 = 4;
    D_30E170.m28 = func_00220FE0(1);
    D_30E170.m24 = func_00220FE0(0);
    D_30E170.m2C = func_00220FE0(2);
    D_30E170.m30 = func_00220FE0(4);
    D_30E170.m34 = func_00224D58(4) - 1;
    D_30E170.m0 = func_001F3AC0;
    D_30E170.m4 = func_002210D8;
    D_30E170.m8 = 0;
    D_30E170.mC = 0;
    return func_00200B28(buf, r);
}

extern "C" s32 func_002016E0(void) {
    return D_002A5D08 - func_0023E5E8(D_30E104);
}

extern "C" void func_00201710(s32 v) { D_30E180 = v; }

extern "C" void func_00201720(f32 a, f32 b, f32 c, f32 d) {
    D_002A5CE0[0] = a; D_002A5CE0[1] = b; D_002A5CE0[2] = c; D_002A5CE0[3] = d;
}

extern "C" void func_00201740(s32 v) { D_30E184 = v; }

extern "C" void func_00201750(f32 a, f32 b, f32 c, f32 d) {
    D_002A5CF0[0] = a; D_002A5CF0[1] = b; D_002A5CF0[2] = c; D_002A5CF0[3] = d;
}

extern "C" void func_00201770(s32 v) { D_30E188 = v; }

extern "C" s32 func_00201780(s32 v) { s32 old = D_002A5CD0; D_002A5CD0 = v; return old; }

extern "C" s32 func_00201798(s32 v) {
    s32 old = D_002A5CD4;
    D_002A5CD4 = v;
    if (D_002A5CD0) Func235DE0(D_002E2960, old, v);
    return old;
}

extern "C" void func_002017E8(f32 a, f32 b) { D_002A5D00 = a; D_002A5D04 = b; }

extern "C" f32 func_00201800(void) { return D_002A5D00; }

extern "C" f32 func_00201810(void) { return D_002A5D04; }

INCLUDE_ASM("asm/nonmatchings/Unit1FF680", func_00201820);

INCLUDE_ASM("asm/nonmatchings/Unit1FF680", func_00201998);

extern "C" void func_00201B38(void) {
    f32 m[4][4];
    if (D_30E3C8) {
        D_30E3C8 = 0;
        func_00271380(D_30E340, D_30E3D0[0], D_30E3D0[1], D_30E3D0[2]);
        func_00270790(m, D_30E2C0);
        func_002705A0(D_30E300, D_30E340, m);
    }
    if (D_30E3CC) {
        D_30E3CC = 0;
        func_00271440(D_30E380, D_30E400[0], D_30E400[1], D_30E400[2], D_30E430);
    }
}

extern "C" void func_00201BE8(void *p) {
    Func270CA0((CVec4 *)D_30E2C0, p);
    D_30E3C0 = 0;
    D_30E3C8 = 1;
}

extern "C" void func_00201C20(f32 x, f32 y, f32 z) {
    D_30E210[0] = -x; D_30E210[1] = -y; D_30E210[2] = -z; D_30E210[3] = 1.0f;
    D_30E3C0 = 1;
}

extern "C" void func_00201C60(f32 x, f32 y, f32 z) {
    D_30E230[0] = x; D_30E230[1] = y; D_30E230[2] = z; D_30E230[3] = 0.0f;
    D_30E3C0 = 1;
}

extern "C" void func_00201C88(f32 x, f32 y, f32 z) {
    D_30E220[0] = -x; D_30E220[1] = -y; D_30E220[2] = -z; D_30E220[3] = 0.0f;
    D_30E3C0 = 1;
}

void Func201CC0(int i, CVec4 *v) {
    if (0 <= i && i < 3) {
        D_30E3D0[i][0] = v->x; D_30E3D0[i][1] = v->y; D_30E3D0[i][2] = v->z;
        D_30E3C8 = 1;
        D_30E3D0[i][3] = 0.0f;
    }
}

void Func201D18(int i, CVec4 *v) {
    if (0 <= i && i < 3) {
        D_30E400[i][0] = v->x; D_30E400[i][1] = v->y; D_30E400[i][2] = v->z;
        D_30E400[i][3] = v->w;
        D_30E3CC = 1;
    }
}

void Func201D78(CVec4 *v) {
    D_30E430[0] = v->x; D_30E430[1] = v->y; D_30E430[2] = v->z; D_30E430[3] = v->w;
    D_30E3CC = 1;
}
