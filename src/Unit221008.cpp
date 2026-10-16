#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern u32 *D_002B94E4;
extern s32 D_002B8AD8;
extern u8 D_002CAF00[];
extern u8 D_002CBEC0[];
extern u8 D_002CB2D0[];
extern u8 D_002CB308[];
extern u8 D_002CB330[];
extern u8 D_002CB020[];
extern u8 D_002CB070[];
extern u8 D_002CB0B0[];
extern u8 D_002CAF68[];
extern u8 D_002CB128[];
extern u8 D_002CB190[];
extern u8 D_002CB1C8[];
extern u8 D_002CB230[];
extern u8 D_002CB100[];
extern u8 D_002CB268[];
extern u8 D_002CB500[];
extern s32 D_33DCFC;
extern s32 D_33DD00;
extern s32 D_33DD04;
extern s32 D_33DD08;
extern s32 D_33DD0C;
extern s32 D_33DD10[4];
extern u32 *D_33DD20;
extern u32 *D_33DD24;
#define PKT D_002B94E4
inline u32 *PUT(u32 v) { u32 *p = PKT; PKT = p + 1; *p = v; return p; }
inline void PUTF(f32 v) { f32 *p = (f32 *)PKT; PKT = (u32 *)(p + 1); *p = v; }
#define MSCAL(l) (0x14000000 | ((l - D_002CAF00 + 7) / 8))
inline u32 *PutQ(u64 hi, u64 lo) {
    u32 *q = PKT;
    PKT = q + 4;
    q[0] = lo;
    q[1] = lo >> 32;
    q[2] = hi;
    q[3] = hi >> 32;
    return q;
}
extern "C" s32 func_0021BCF8(s32, s32);
extern "C" s32 func_00239088(void);
extern "C" s32 func_002390A0(void);
extern "C" void func_002210D8(void);
extern "C" s32 func_002375C0(void);
extern "C" void *func_002377D8(void);
int Func238158(void *p, int v);
extern "C" void *func_00237350(s32);
extern "C" void func_00237398(s32, void *);
extern "C" void *func_00237860(s32, void *);
extern "C" s32 func_002379D0(void);
extern "C" void func_00221A30(f32 *);

extern u8 D_002CB350[];
extern u8 D_002CB440[];
extern u8 D_002CB830[];
extern u8 D_002CBB30[];
extern u8 D_002CBF60[];
extern u8 D_002CC260[];
extern u8 D_002CC600[];
extern u8 D_002CD958[];
extern const char D_002E3FE8[];
extern s32 D_33DD28;
extern s32 D_33DD2C;
struct B8B70 { s32 m0; s32 m4; };
extern B8B70 D_002B8B70[3];
s32 Func235DE0(const char *fmt, ...);
extern "C" s32 func_0021BDD0(s32, s32);
extern "C" s32 func_0021BC88(s32, s32);
extern "C" s32 func_0021BAC0(s32, void *, s32);
extern "C" void func_00222360(s32, s32, u8 *, u32);
extern "C" void func_00222538(void);
extern "C" void func_00222628(void);
inline void PUTB(u8 v) { u8 *p = (u8 *)PKT; PKT = (u32 *)(p + 1); *p = v; }
inline u32 *PUTD(u64 v) { u32 *p = PKT; PKT = p + 2; p[0] = v; p[1] = v >> 32; return p; }
inline s32 Chunk(s32 n, s32 max) { s32 c = n; if (n > max) c = n / 3; return c > max ? max : c; }
// @decl-end

extern "C" s32 func_00221008(void) {
    return func_0021BCF8(1, D_33DCFC);
}

extern "C" void func_00221028(void) {
    D_33DD10[0] = D_33DD00;
    D_33DD10[1] = D_33DD04;
    D_33DD10[2] = D_33DD08;
    D_33DD10[3] = D_33DD0C;
}

extern "C" void func_00221068(void) {
    D_33DD00 = D_33DD10[0];
    D_33DD04 = D_33DD10[1];
    D_33DD08 = D_33DD10[2];
    D_33DD0C = D_33DD10[3];
}

extern "C" s32 func_002210A8(void) {
    return func_00239088();
}

extern "C" s32 func_002210C0(void) {
    return func_002390A0();
}

extern "C" void func_002210D8(void) {
}

extern "C" s32 func_002210E0(void) {
    func_002210D8();
    return func_002375C0();
}

extern "C" int func_00221100(void) {
    return Func238158(func_002377D8(), 1);
}

extern "C" void func_00221128(void) {
    D_002B8AD8 = 0;
    D_33DD20 = PUT(0x6C008000);
    D_33DD24 = PutQ(0xE, 0x1000000000000000);
}

extern "C" void func_00221188(void) {
    *D_33DD20 |= (D_002B8AD8 + 1) << 16;
    *D_33DD24 |= D_002B8AD8;
    PUT(MSCAL(D_002CBEC0));
    D_002B8AD8 = 0;
}

extern "C" void func_00221218(u64 a, u64 b) {
    PutQ(a, b);
    D_002B8AD8++;
}

extern "C" void func_00221270(u64 a, u64 b, u64 c, u64 d) {
    PUT(0x6C028000);
    PutQ(a, b);
    PutQ(c, d);
    PUT(MSCAL(D_002CB2D0));
}

extern "C" void func_00221340(u64 a, u64 b) {
    PUT(0x6C018000);
    PutQ(a, b);
    PUT(MSCAL(D_002CB308));
}

extern "C" void func_002213D8(u32 a) {
    PUT(0x60018000);
    PUT(a);
    PUT(MSCAL(D_002CB330));
}

extern "C" void *func_00221450(s32 n, void *p) {
    return func_00237860(n, p);
}

extern "C" s32 func_00221468(void) {
    return func_002379D0();
}

extern "C" void func_00221480(void *src) {
    PUT(0x6C048000);
    func_00237398(0x10, src);
    PUT(MSCAL(D_002CB020));
}

extern "C" void func_00221508(void *src) {
    func_00237350(0xC);
    PUT(0x6C048000);
    func_00237860(4, src);
    PUT(MSCAL(D_002CB020));
}

extern "C" void func_002215A8(s32 n, void *src) {
    func_00237350(0xC);
    PUT((n << 16) | 0x6C008000);
    func_00237860(n, src);
    PUT(MSCAL(D_002CB2D0));
}

extern "C" void func_00221658(s32 n, void *src) {
    func_00237350(0xC);
    PUT((n << 16) | 0x6C008000);
    func_00237860(n, src);
    PUT(MSCAL(D_002CB308));
}

extern "C" void func_00221708(void *src, f32 s) {
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
    PUT(MSCAL(D_002CB020));
}

extern "C" void func_002217E0(void *src) {
    PUT(0x6C038000);
    func_00237398(0xC, src);
    PUT(MSCAL(D_002CB070));
}

extern "C" void func_00221868(void *src) {
    func_00237350(0xC);
    PUT(0x6C038000);
    func_00237860(3, src);
    PUT(MSCAL(D_002CB070));
}

extern "C" void func_00221908(void *src) {
    PUT(0x6C048000);
    func_00237398(0x10, src);
    PUT(MSCAL(D_002CB0B0));
}

extern "C" void func_00221990(void *src) {
    func_00237350(0xC);
    PUT(0x6C048000);
    func_00237860(4, src);
    PUT(MSCAL(D_002CB0B0));
}

extern "C" void func_00221A30(f32 *s) {
    f32 w = s[20], h = s[21];
    PUTF(s[0] * w / 1536.0f);
    PUTF(s[1] * h / 1536.0f);
    PUTF(s[2]);
    PUTF(s[3]);
    PUTF(1536.0f);
    PUTF(1536.0f);
    PUTF(s[22]);
    PUTF(s[23]);
}

extern "C" void func_00221B08(f32 *src) {
    PUT(0x6C0A8000);
    func_00237398(0x20, src);
    func_00221A30(src);
    PUT(MSCAL(D_002CAF68));
}

extern "C" void func_00221BA8(f32 *src) {
    func_00237350(0xC);
    PUT(0x6C088000);
    func_00237860(6, src);
    func_00221A30(src);
    PUT(MSCAL(D_002CAF68));
}

extern "C" void func_00221C50(u64 a, u64 b, u64 c, u64 d) {
    PUT(0x6C058000);
    PutQ(0xE, 0x1000000000000004);
    PutQ(a, b);
    PutQ(c, d);
    PutQ(0x42, 0x44);
    PutQ(0x47, 0x5000D);
    PUT(MSCAL(D_002CB128));
}

extern "C" void func_00221DA8(f32 a, f32 b, f32 c, f32 d) {
    PUT(0x64028000);
    PUTF(a);
    PUTF(b);
    PUTF(c);
    PUTF(d);
    PUT(MSCAL(D_002CB190));
}

extern "C" void func_00221E50(u64 a, u64 b, u64 c, u64 d) {
    PUT(0x6C058000);
    PutQ(0xE, 0x1000000000000004);
    PutQ(a, b);
    PutQ(c, d);
    PutQ(0x42, 0x44);
    PutQ(0x47, 0x53001);
    PUT(MSCAL(D_002CB1C8));
}

extern "C" void func_00221FA8(f32 a, f32 b, f32 c, f32 d) {
    PUT(0x64028000);
    PUTF(a);
    PUTF(b);
    PUTF(c);
    PUTF(d);
    PUT(MSCAL(D_002CB230));
}

extern "C" void func_00222050(s32 a, s32 b, s32 c, s32 d) {
    PUT(0x6C018000);
    PUTF(a * (1.0f / 128));
    PUTF(b * (1.0f / 128));
    PUTF(c * (1.0f / 128));
    PUTF(d * (1.0f / 128));
    PUT(MSCAL(D_002CB100));
}

extern "C" void func_00222130(u32 a, u32 b) {
    PUT(0x64018000);
    PUT(b);
    PUT(a);
    PUT(MSCAL(D_002CB268));
}

extern "C" void func_002221B8(void) {
}

extern "C" void func_002221C0(u32 a, u32 b) {
    PUT(0x68018000);
    PUT(b);
    PUT(a);
    PUT(0);
    PUT(MSCAL(D_002CB500));
}

extern u8 D_002CAF00_b[] __asm__("D_002CAF00");
extern "C" void func_00222258(void) {
    PUT(0x11000000);
    PUT(0x01000404);
    PUT(0x05000000);
    PUT(0x0300024F);
    PUT(0x02000036);
    PUT(0x6C018000);
    PutQ(1, 0x1000000000000001);
    PUT(0x14000000 | ((D_002CAF00_b - D_002CAF00 + 7) / 8));
    PUT(0x10000000);
}

extern "C" void func_00222360(s32 addr, s32 n, u8 *src, u32 mscal) {
    s32 k;
    while (n > 0) {
        k = Chunk(n, 53);
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
        PUT(mscal);
    }
}

extern "C" void func_002224A8(s32 addr, s32 n, u8 *src) {
    return func_00222360(addr, n, src, MSCAL(D_002CB350));
}

extern "C" void func_002224F0(s32 addr, s32 n, u8 *src) {
    return func_00222360(addr, n, src, MSCAL(D_002CB440));
}

extern "C" void func_00222538(void) {
    s32 k;
    if (D_33DD08 > 0) {
        k = Chunk(D_33DD08, 53);
        D_33DD08 -= k;
        D_33DD04 = k;
        PUT(((k + 1) << 16) | 0x6C008000);
        PUT(D_33DD04);
        PUT(D_33DD00);
        PUT(0);
        PUT(0);
        D_33DD00 += D_33DD04;
    }
}

extern "C" void func_00222628(void) {
    if (--D_33DD04 == 0) {
        PUT(D_33DD0C);
        return func_00222538();
    }
}

extern "C" void func_00222688(s32 addr, s32 n) {
    D_33DD00 = addr;
    D_33DD04 = 0;
    D_33DD08 = n;
    D_33DD0C = MSCAL(D_002CB350);
    return func_00222538();
}

extern "C" void func_002226F0(s32 addr, s32 n) {
    D_33DD00 = addr;
    D_33DD04 = 0;
    D_33DD08 = n;
    D_33DD0C = MSCAL(D_002CB440);
    return func_00222538();
}

extern "C" void func_00222758(f32 a, f32 b, f32 c, f32 d) {
    if (D_33DD04 > 0) {
        PUTF(a);
        PUTF(b);
        PUTF(c);
        PUTF(d);
        return func_00222628();
    }
}

extern "C" void func_002227D0(s32 a, s32 b, s32 c, s32 d) {
    if (D_33DD04 > 0) {
        PUTB(a);
        PUTB(b);
        PUTB(c);
        PUTB(d);
        D_33DD04--;
    }
}

extern "C" void func_00222848(s32 a, s32 b) {
    u64 t;
    PUT(0x68018000);
    a |= 0x45;
    t = (u64)b | ((u64)a << 32);
    PUTD(t | ((u64)(a | 0x10) << 47) | ((u64)0xC001 << 46));

    PUT(0x412);
    PUT((b << 16) | 0x6E00C001);
}

extern "C" void func_002228E8(s32 a, s32 b) {
    u64 t;
    PUT(0x68018000);
    a |= 0x44;
    t = (u64)b | ((u64)a << 32);
    PUTD(t | ((u64)(a | 0x10) << 47) | ((u64)0xC001 << 46));
    PUT(0x412);
    PUT((b << 16) | 0x6E00C001);
}

extern "C" void func_00222988(u8 a, u8 b, u8 c, u8 d) {
    PUTB(a);
    PUTB(b);
    PUTB(c);
    PUTB(d);
}

extern "C" void func_002229D8(void) {
    PUT(MSCAL(D_002CB830));
}

extern "C" void func_00222A28(void) {
    PUT(MSCAL(D_002CBB30));
}

extern "C" void func_00222A78(void) {
    PUT(MSCAL(D_002CBF60));
}

extern "C" void func_00222AC8(void) {
    PUT(MSCAL(D_002CC260));
}

extern "C" void func_00222B18(s32 a, s32 b) {
    D_33DD0C = 0;
    PUT((a + 0x157) | (b << 16) | 0x6C000000);
}

extern "C" void func_00222B50(f32 a, f32 b, f32 c, f32 d) {
    PUTF(a);
    PUTF(b);
    PUTF(c);
    PUTF(d);
}

extern "C" void func_00222BA0(s32 a, s32 b) {
    D_33DD08 = 0;
    D_33DD0C = 0;
    PUT((a + 0xA5) | (b << 16) | 0x74000000);
}

extern "C" void func_00222BE0(f32 a, f32 b) {
    PUTF(a);
    PUTF(b);
}

INCLUDE_ASM("asm/nonmatchings/Unit221008", func_00222C10);

extern "C" s32 func_00222C90(u32 i) {
    s32 r = 0;
    if (i < 3) r = D_002B8B70[i].m0;
    return r;
}

extern "C" s32 func_00222CB8(u32 i) {
    s32 r = 0;
    if (i < 3) r = D_002B8B70[i].m4;
    return r;
}
