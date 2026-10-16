#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern u32 *D_002B94E4;
extern s32 D_33DD28;
extern s32 D_33DD2C;
extern s32 D_33DD30;
extern s32 D_33DD34;
extern s32 D_33DD38;
extern s32 D_33DD40[3];
#define PKT D_002B94E4
inline u32 *PUT(u32 v) { u32 *p = PKT; PKT = p + 1; *p = v; return p; }
inline void PUTF(f32 v) { f32 *p = (f32 *)PKT; PKT = (u32 *)(p + 1); *p = v; }
inline void PUTB(u8 v) { u8 *p = (u8 *)PKT; PKT = (u32 *)(p + 1); *p = v; }
#define MSCAL(o) ((D_33DD28 + (o)) | 0x14000000)
inline s32 Chunk(s32 n, s32 max) { s32 c = n; if (n > max) c = n / 3; return c > max ? max : c; }
extern "C" s32 func_0021BCF8(s32, s32);
extern "C" s32 func_00239088(void);
extern "C" s32 func_002390A0(void);
extern "C" void func_00222D98(void);
extern "C" s32 func_002375C0(void);
extern "C" void *func_002377D8(void);
int Func238158(void *p, int v);
extern "C" void *func_00237350(s32);
extern "C" s32 func_00237398(s32, void *);
extern "C" void *func_00237860(s32, void *);
extern "C" s32 func_002379D0(void);
extern "C" s32 func_00237460(void);
extern "C" s32 func_002374B0(void);
extern "C" void *func_00237408(s32);
extern "C" void func_00223708(void);
extern "C" void func_002237F8(void);
extern "C" void func_002238F0(void);

class CVec4 { public: f32 x, y, z, w; };
struct Mat44 { CVec4 r[4]; };
struct B80 { u64 d[16]; };
struct QW { u64 lo; u64 hi; };
extern s32 D_002B8B90;
extern CVec4 D_002B8BA0;
extern s32 D_002B8BB0[4];
extern CVec4 D_002B8BC0;
extern CVec4 D_002B8BD0;
extern B80 D_33DD50;
extern Mat44 D_33DDD0;
extern Mat44 D_33DE10;
extern Mat44 D_33DE50;
extern QW D_002B8AE0[9];
void Func270CA0(CVec4 *dst, void *m);
void Func270E48(CVec4 *v);
extern "C" void func_002715B0(Mat44 *, CVec4 *, s32, f32, f32, f32);
extern "C" void func_00270710(CVec4 *, CVec4 *);
extern "C" void func_00270818(Mat44 *, Mat44 *);
extern "C" void func_002705A0(Mat44 *, Mat44 *, Mat44 *);
extern "C" void func_00270520(CVec4 *, Mat44 *, CVec4 *);
extern "C" s32 func_00222C10(void);
extern "C" void func_00222D08(void);
extern "C" s32 func_0023A0E8(void);
extern "C" s32 func_0023A2F0(s32);
extern "C" void func_00223CA8(s32, s32);
extern "C" void func_00223C00(s32, s32, s32);
extern "C" void func_00223FF8(void);
extern "C" s32 func_00222DA0(void);
extern "C" int func_00222DC0(void);
extern "C" void func_002230B8(void *);
extern "C" void func_002231A8(void *);
extern "C" void func_00223298(void *);
inline u32 *PutQ(u64 hi, u64 lo) {
    u32 *q = PKT;
    PKT = q + 4;
    q[0] = lo;
    q[1] = lo >> 32;
    q[2] = hi;
    q[3] = hi >> 32;
    return q;
}

extern "C" void func_00224818(f32 *, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void func_00224A88(f32 *, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" s32 func_002280D0(void);
extern "C" s32 func_00224D80(void);
extern s32 D_002B8BE0[7][2];

inline u32 *PutQs(s64 hi, s64 lo) {
    u32 *q = PKT;
    PKT = q + 4;
    q[0] = lo;
    q[1] = lo >> 32;
    q[2] = hi;
    q[3] = hi >> 32;
    return q;
}
#define BITS(h, sh, m) (((h) & ((u64)(m) << (sh))) >> (sh))
// @decl-end

extern "C" s32 func_00222CE0(void) {
    return 6;
}

extern "C" s32 func_00222CE8(void) {
    return func_0021BCF8(1, D_33DD2C);
}

extern "C" void func_00222D08(void) {
    D_33DD40[0] = D_33DD30;
    D_33DD40[1] = D_33DD34;
    D_33DD40[2] = D_33DD38;
}

extern "C" void func_00222D38(void) {
    D_33DD30 = D_33DD40[0];
    D_33DD34 = D_33DD40[1];
    D_33DD38 = D_33DD40[2];
}

extern "C" s32 func_00222D68(void) {
    return func_00239088();
}

extern "C" s32 func_00222D80(void) {
    return func_002390A0();
}

extern "C" void func_00222D98(void) {
}

extern "C" s32 func_00222DA0(void) {
    func_00222D98();
    return func_002375C0();
}

extern "C" int func_00222DC0(void) {
    return Func238158(func_002377D8(), 1);
}

extern "C" void *func_00222DE8(s32 n, void *p) {
    return func_00237860(n, p);
}

extern "C" s32 func_00222E00(void) {
    return func_002379D0();
}

extern "C" void func_00222E18(void *src) {
    PUT(0x6C048000);
    func_00237398(0x10, src);
    PUT(MSCAL(4));
}

extern "C" void func_00222E88(void *src) {
    func_00237350(0xC);
    PUT(0x6C048000);
    func_00237860(4, src);
    PUT(MSCAL(4));
}

extern "C" void func_00222F08(void *src, f32 s) {
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
    PUT(MSCAL(4));
}

extern "C" void func_00222FC8(void *src) {
    PUT(0x6C088000);
    func_00237398(0x20, src);
    PUT(MSCAL(2));
}

extern "C" void func_00223038(void *src) {
    func_00237350(0xC);
    PUT(0x6C088000);
    func_00237860(8, src);
    PUT(MSCAL(2));
}

extern "C" void func_002230B8(void *src) {
    PUT(0x6C048000);
    func_00237398(0x10, src);
    PUT(MSCAL(6));
}

extern "C" void func_00223128(void *src) {
    func_00237350(0xC);
    PUT(0x6C048000);
    func_00237860(4, src);
    PUT(MSCAL(6));
}

extern "C" void func_002231A8(void *src) {
    PUT(0x6C048000);
    func_00237398(0x10, src);
    PUT(MSCAL(8));
}

extern "C" void func_00223218(void *src) {
    func_00237350(0xC);
    PUT(0x6C048000);
    func_00237860(4, src);
    PUT(MSCAL(8));
}

extern "C" void func_00223298(void *src) {
    PUT(0x6C018000);
    func_00237398(4, src);
    PUT(MSCAL(0xA));
}

extern "C" void func_00223308(void *src) {
    func_00237350(0xC);
    PUT(0x6C018000);
    func_00237860(1, src);
    PUT(MSCAL(0xA));
}

extern "C" void func_00223388(u32 a, u32 b) {
    PUT(0x64018000);
    PUT(b);
    PUT(a);
    PUT(MSCAL(0xC));
}

extern "C" void func_002233F0(u32 a, u32 b) {
    PUT(0x68018000);
    PUT(b);
    PUT(a);
    PUT(0);
    PUT(MSCAL(0x14));
    PUT(0x68018000);
    PUT(b);
    PUT(a + 0x61);
    PUT(0);
    PUT(MSCAL(0x14));
}

extern "C" void func_002234D0(u32 a, u32 b) {
    PUT(0x68018000);
    PUT(b);
    PUT(a);
    PUT(a + 0x61);
    PUT(MSCAL(0x12));
    PUT(0x68018000);
    PUT(b);
    PUT(a);
    PUT(a);
    PUT(MSCAL(0x10));
}

extern "C" void func_002235B0(s32 addr, s32 n, u8 *src) {
    s32 k;
    while (n > 0) {
        k = Chunk(n, 31);
        func_00237350(0xC);
        PUT(((k + 1) << 16) | 0x6C008000);
        n -= k;
        PUT(k);
        PUT(addr);
        addr += k;
        PUT(0);
        PUT(0);
        func_00237860(k, src);
        src += k * 16;
        PUT(MSCAL(0xE));
    }
}

extern "C" void func_00223708(void) {
    s32 k;
    if (D_33DD38 > 0) {
        k = Chunk(D_33DD38, 31);
        D_33DD38 -= k;
        D_33DD34 = k;
        PUT(((k + 1) << 16) | 0x6C008000);
        PUT(D_33DD34);
        PUT(D_33DD30);
        PUT(0);
        PUT(0);
        D_33DD30 += D_33DD34;
    }
}

extern "C" void func_002237F8(void) {
    if (--D_33DD34 == 0) {
        PUT(MSCAL(0xE));
        return func_00223708();
    }
}

extern "C" void func_00223860(s32 addr, s32 n) {
    D_33DD30 = addr;
    D_33DD34 = 0;
    D_33DD38 = n;
    return func_00223708();
}

extern "C" void func_00223890(f32 a, f32 b, f32 c, f32 d) {
    PUTF(a);
    PUTF(b);
    PUTF(c);
    PUTF(d);
    return func_002237F8();
}

extern "C" void func_002238F0(void) {
    if (D_33DD38 > 0) {
        func_00237460();
        PUT((D_33DD38 << 16) | 0x6E00C000);
        func_002374B0();
        PUT(D_33DD38 | 0x04000000);
        PUT(MSCAL(0x16));
        D_33DD38 = 0;
    }
}

extern "C" void func_002239A0(s32 a, s32 b, s32 c) {
    if (D_33DD38 >= 6) func_002238F0();
    if (D_33DD38 == 0) func_00237408(4);
    PUTB(a);
    PUTB(b);
    PUTB(c);
    PUTB(0);
    D_33DD38++;
}

extern "C" void func_00223A68(void) {
    D_33DD38 = 0;
}

extern "C" void func_00223A78(void) {
    return func_002238F0();
}

extern "C" void func_00223A90(u64 t) {
    u64 w, h, f;
    s32 i;
    w = (t & 0x3FFF) >> 5;
    h = BITS(t, 14, 0x3F) << 16;
    f = BITS(t, 32, 0x3F) << 24;
    D_002B8AE0[4].lo = w | h | f;
    D_002B8AE0[7].lo = w | (f | h) | 0x7FFFFFFF00000000ULL;
    PUT(0x11000000);
    PUT(0x1000404);
    PUT(0x5000000);
    PUT(0x300019C);
    PUT(0x2000020);
    PUT(0x6C098000);
    for (i = 0; i < 9; i++) PutQs(D_002B8AE0[i].hi, D_002B8AE0[i].lo);
    PUT(MSCAL(0));
    PUT(0x10000000);
}

extern "C" void func_00223C00(s32 r, s32 g, s32 b) {
    PUT(0x11000000);
    PUT(0x50000002);
    PutQ(0xE, 0x1000000000008001);
    PutQ(1, (u64)r | ((u64)g << 8) | ((u64)b << 16) | ((u64)0x3F800000 << 32));
}

INCLUDE_ASM("asm/nonmatchings/Unit222CE0", func_00223CA8);

extern "C" void func_00223FA0(void) {
    func_00222C10();
    return func_00222D08();
}

extern "C" void func_00223FC0(void) {
}

extern "C" void func_00223FC8(void *p) {
    return Func270CA0((CVec4 *)&D_33DE50, p);
}

extern "C" void func_00223FE8(s32 a) {
    D_002B8B90 = a;
}

extern "C" void func_00223FF8(void) {
    if (D_002B8BC0.x == 0.0f && D_002B8BC0.y == 0.0f && D_002B8BC0.z == 0.0f) {
        Func270E48((CVec4 *)&D_33DDD0);
    } else {
        func_002715B0(&D_33DDD0, &D_002B8BA0, 0, D_002B8BC0.x, D_002B8BC0.y, D_002B8BC0.z);
    }
    return func_002715B0(&D_33DE10, &D_002B8BA0, 0, D_002B8BD0.x, D_002B8BD0.y, D_002B8BD0.z);
}

extern "C" void func_002240B0(f32 x, f32 y, f32 z) {
    D_002B8BA0.x = x;
    D_002B8BA0.y = y;
    D_002B8BA0.z = z;
    D_002B8BA0.w = 0;
    return func_00270710(&D_002B8BA0, &D_002B8BA0);
}

extern "C" void func_002240E8(f32 x, f32 y, f32 z) {
    D_002B8BC0.x = x;
    D_002B8BC0.y = y;
    D_002B8BC0.z = z;
    D_002B8BC0.w = 0;
}

extern "C" void func_00224108(f32 x, f32 y, f32 z) {
    D_002B8BD0.x = x;
    D_002B8BD0.y = y;
    D_002B8BD0.z = z;
    D_002B8BD0.w = 0;
}

extern "C" void func_00224128(s32 a, s32 b, s32 c, s32 d) {
    D_002B8BB0[0] = a;
    D_002B8BB0[1] = b;
    D_002B8BB0[2] = c;
    D_002B8BB0[3] = d;
}

extern "C" void func_00224148(B80 *src) {
    D_33DD50 = *src;
}

extern "C" void func_00224190(void) {
    s32 h = D_002B8B90;
    if (!h) h = func_0023A2F0(func_0023A0E8());
    func_00222DA0();
    func_00223CA8(h, D_002B8BB0[3]);
    func_00223C00(D_002B8BB0[0], D_002B8BB0[1], D_002B8BB0[2]);
    return (void)func_00222DC0();
}

extern "C" void func_00224200(void) {
    Mat44 m;
    CVec4 v;
    func_00222DA0();
    func_00223FF8();
    func_00270818(&m, &D_33DE50);
    func_002705A0(&m, &D_33DDD0, &m);
    func_002705A0(&m, &D_33DE50, &m);
    func_002230B8(&m);
    func_00270818(&m, &D_33DE50);
    func_002705A0(&m, &D_33DE10, &m);
    func_002705A0(&m, &D_33DE50, &m);
    func_002231A8(&m);
    func_00270520(&v, &D_33DE50, &D_002B8BA0);
    func_00270710(&v, &v);
    func_00223298(&v);
    func_00222DC0();
}

INCLUDE_ASM("asm/nonmatchings/Unit222CE0", func_002242E0);

INCLUDE_ASM("asm/nonmatchings/Unit222CE0", func_002245A0);

extern "C" Mat44 *func_002247F8(void) {
    return &D_33DDD0;
}

extern "C" Mat44 *func_00224808(void) {
    return &D_33DE10;
}

INCLUDE_ASM("asm/nonmatchings/Unit222CE0", func_00224818);

extern "C" void func_00224A40(f32 *m, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h, f32 i, f32 j, f32 k, f32 l, f32 n) {
    func_00224818(m, a, b, c, d, e, f, g, h, i, h, i, j, k, l, n);
}

INCLUDE_ASM("asm/nonmatchings/Unit222CE0", func_00224A88);

extern "C" void func_00224CC0(f32 *m, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h, f32 i, f32 j, f32 k, f32 l, f32 n) {
    func_00224A88(m, a, b, c, d, e, f, g, h, i, h, i, j, k, l, n);
}

extern "C" s32 func_00224D08(void) {
    func_002280D0();
    return func_00224D80();
}

extern "C" void func_00224D28(void) {
}

extern "C" s32 func_00224D30(u32 i) {
    s32 r = 0;
    if (i < 7) r = D_002B8BE0[i][0];
    return r;
}
