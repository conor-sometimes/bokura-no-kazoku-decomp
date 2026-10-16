#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern s32 D_002B9DA0;
extern volatile s32 D_002B9DB8;
/* retail gas honoured .set volatile: no delay-slot swap of a volatile store */
#define NOSWAP() asm volatile(".set noreorder\n.set reorder")
extern s32 D_002B9DC8;
extern s32 D_002B9DCC;
extern volatile s32 D_002B9D88;
extern s32 D_002B9D84;
extern s32 D_002B9D8C;
extern s32 D_002B9DAC;
extern s32 D_002B9DA8;
extern s32 D_002B9DB0;
extern s32 D_002B9DC4;
extern s32 D_002B9D98;
extern s32 D_002B9DBC;
extern s32 D_002B9DC0;
extern s32 D_002B9DB4;
extern s32 D_002B9D90;
extern s32 D_38F074;
extern s32 D_38F070;
extern s32 D_38F07C;
extern s32 D_38F000;
extern s32 D_38F004;
struct SndCh { s32 m0, m4, m8, mC, m10; u8 pad14[0x10]; s32 m24, m28; u8 pad2C[0x14]; };
extern SndCh D_38F088[4];
extern u8 D_38F048[];
extern "C" void func_001F15F0(void);
extern "C" void func_001F1610(void);
extern "C" void func_0027E260(void *);
extern "C" void func_0027E348(void *);
extern "C" s32 func_001F0C38(void);
extern "C" void func_001F1A80(void *, s32, s32, s32);
extern "C" void func_001F1230(void);
extern "C" s32 func_001F0C60(void *, s32, s32, s32);
extern "C" void func_002446D8(void);
extern "C" void func_00244860(void);
extern "C" void func_0022DDE8(s32);
extern "C" void func_00243F20(s32);
extern "C" void func_00267558(void);
extern "C" void func_00243D98(s32);
extern "C" void func_002449A8(void);
extern "C" void func_00244CA0(void);
extern "C" s32 func_00244858(void);

typedef __builtin_va_list va_list;
#define va_start(ap, last) __builtin_stdarg_start(ap, last)
#define va_end(ap)
s32 Func235DE0(const char *fmt, ...);
extern "C" int vsprintf(char *, const char *, va_list);
extern "C" void func_00243AB8(const char *);
extern "C" s32 func_0020AD90(s32, s32, s32);
extern "C" s32 func_0020BDB0(s32);
extern "C" void *memset(void *, int, unsigned int);
struct Ring;
struct SndChX { s32 m0, m4, m8, mC, m10; Ring *m14; s32 m18, m1C, m20, m24, m28, m2C, m30, m34; u8 pad38[8]; };
#define SNDX ((SndChX *)D_38F088)
typedef s32 (*SndOpen)(s32, s32, s32, s32, s32, s32);
typedef void (*SndClose)(s32);
extern SndOpen D_002B9DD0[];
extern SndClose D_002B9DD8[];
extern const char D_002E5E40[];
extern const char D_002E5EB8[];
extern "C" void func_002454D8(Ring *);
extern "C" Ring *func_00245460(s32);
extern "C" void func_002454B0(void *);
extern "C" void func_00243DF0(s32);
extern "C" s32 func_00245518(Ring *);
extern "C" void func_00245548(Ring *, const u8 *, s32);
extern s32 D_38F080;
extern s32 D_38F078;
#define D_002B9DB4 (*(void **)&D_002B9DB4)
typedef void *(*AllocFn)(s32);
typedef void (*FreeFn)(void *);
extern AllocFn D_002B91A4;
extern FreeFn D_002B91B0;
struct SndReq { s32 m0; s32 m4; const u8 *m8; s32 mC; };
extern "C" void func_0027BD20(void);
extern "C" void func_0027BD78(void);

extern s32 D_002B9DAC;
extern s32 D_002B9D94;
extern s32 D_002B9DA4;
extern "C" void func_00244928(void);
extern "C" void func_00244498(u32);
extern "C" void func_00244178(void);
extern "C" void func_00243FF8(s32);
extern "C" void func_00244208(void);
extern "C" s32 func_002448D8(void);
extern void *D_002B9D9C;
extern s32 D_002B9D80;
extern s32 D_38F06C;
extern "C" void func_002679A8(void *);
extern "C" void func_00267818(void *);
extern "C" void func_00244A80(s32);
extern "C" void func_002449A8(void);
extern "C" s32 func_0022FF58(s32);
extern "C" s32 func_0022DD98(s32, s32, s32, s32);
extern "C" void func_0022E450(s32, s32);
extern "C" s32 func_00243F80(s32);
extern "C" u8 *func_00245600(Ring *);
extern "C" void func_00245618(Ring *, s32);
extern "C" s32 func_00245510(Ring *);
typedef s32 (*SndAvail)(s32);
typedef void (*SndWrite)(s32, u8 *, u8 *, s32);
typedef void (*SndSet1)(s32, s32);
typedef void (*SndSet2)(s32, s32, s32);
extern SndAvail D_002B9DE0[];
extern SndWrite D_002B9DE8[];
extern SndSet1 D_002B9DF0[];
extern SndSet2 D_002B9DF8[];

#define EE_VA_START(ap, last) (ap = (char *)__builtin_next_arg(last) - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
extern "C" int vsprintf2(char *buf, const char *fmt, char *ap) asm("vsprintf");
// @decl-end

extern s32 D_38EF90;
extern f32 D_38EFA8, D_38EFAC, D_38EFB0, D_38EFB4, D_38EFB8, D_38EFBC, D_38EFC0, D_38EFC4, D_38EFC8, D_38EFCC;
extern "C" s32 func_00240C60(s32);
extern "C" s32 func_00240CB8(s32);
extern "C" s32 func_00241238(s32, s32 *, const char *, s32);
extern "C" f32 func_00243338(s32);

extern "C" void func_00243AB8(const char *s)
{
    f32 w = (f32)func_00240C60(D_38EF90);
    func_00240CB8(D_38EF90);
    f32 spx = D_38EFC8 * D_38EFC0 * D_38EFB0;
    f32 spy = D_38EFCC * D_38EFC4 * D_38EFB4;
    f32 ky = D_38EFB8 * D_38EFB0;
    f32 kx = D_38EFBC * D_38EFB4;
    while (*(const u8 *)s) {
        s32 n = 0;
        const char *p = s;
        if (*p != 0 && *p != '\n') {
            do { p++; n++; } while (*p != 0 && *p != '\n');
        }
        s32 *buf = (s32 *)__builtin_alloca(n * 4);
        s32 cnt = func_00241238(D_38EF90, buf, s, n);
        for (s32 i = 0; i < cnt; i++) {
            s32 g = buf[i];
            if (g) D_38EFAC += func_00243338(g) * kx;
            else D_38EFAC += w * kx;
            D_38EFAC += spx;
        }
        s += n;
        if (*(const u8 *)s == '\n') {
            s++;
            D_38EFAC = 0;
            D_38EFA8 -= w * ky + spy;
        }
    }
}

extern "C" void func_00243CF0(const char *fmt, ...) { char buf[0x1000]; char *ap; EE_VA_START(ap, fmt); vsprintf2(buf, fmt, ap); func_00243AB8(buf); }

extern "C" s32 func_00243D60(s32 a, s32 b, s32 c, s32 d) {
    return func_0020AD90(a, c, d);
}

extern "C" s32 func_00243D80(s32 a) {
    return func_0020BDB0(a);
}

extern "C" void func_00243D98(s32 i) {
    SndChX *e = &SNDX[i];
    e->m0 = i;
    e->m14 = 0;
    e->m8 = -1;
    e->m4 = -1;
    e->mC = 0x80;
    e->m10 = 0x80;
    return (void)memset(&e->m18, 0, 0x20);
}

extern "C" void func_00243DF0(s32 i) {
    SndChX *e = &SNDX[i];
    func_002454D8(e->m14);
    e->m0 = i;
    e->m8 = -1;
    e->m4 = -1;
    e->mC = 0x80;
    e->m10 = 0x80;
    return (void)memset(&e->m18, 0, 0x20);
}

extern "C" void func_00243E58(s32 i) {
    SndChX *e = &SNDX[i];
    s32 f, r;
    if (e->m8 >= 0) return;
    if (e->m4 == -1) return;
    f = (e->m28 < 2) ^ 1;
    r = D_002B9DD0[e->m4](f, e->m24, 0, 4, 0, 4);
    e->m8 = r;
    return (void)Func235DE0(D_002E5E40, i, e->m4, f + 1, r);
}

extern "C" void func_00243F20(s32 i) {
    SndChX *e = &SNDX[i];
    if (e->m8 >= 0) {
        D_002B9DD8[e->m4](e->m8);
        e->m8 = -1;
    }
}

extern "C" s32 func_00243F80(s32 i) {
    SndChX *e = &SNDX[i];
    s32 r = 0;
    if (e->m8 >= 0) r = e->m4 != -1;
    return r;
}

extern "C" void func_00243FB0(s32 i) {
    SndChX *e = &SNDX[i];
    e->m14 = func_00245460(0x20000);
    return func_00243DF0(i);
}

extern "C" void func_00243FF8(s32 i) {
    SndChX *e = &SNDX[i];
    if (e->m14) {
        func_002454B0(e->m14);
        e->m14 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit243AB8", func_00244040);

extern "C" void func_00244178(void) {
    D_38F078 = 0;
    D_38F07C = 0;
    D_38F080 = 4;
}

extern "C" void func_00244198(void) {
    void **p = (void **)&D_002B9DB4;
    D_38F078 = 0;
    D_38F07C = 0;
    D_38F080 = 4;
    *p = D_002B91A4(D_002B9DC8 * D_002B9DCC * 16 + 0x40);
}

extern "C" void func_00244208(void) {
    D_002B91B0(D_002B9DB4);
    D_002B9DB4 = 0;
}

extern "C" s32 func_00244240(s32 a, SndReq *q, Ring *r) {
    s32 n = q->mC;
    const u8 *src = q->m8;
    s32 ok = 1;
    func_001F15F0();
    if (func_00245518(r) < n) ok = 0;
    else func_00245548(r, src, n);
    func_001F1610();
    return ok;
}

INCLUDE_RODATA("asm/nonmatchings/Unit243AB8", D_002E5E40);
INCLUDE_ASM("asm/nonmatchings/Unit243AB8", func_002442C0);
INCLUDE_RODATA("asm/nonmatchings/Unit243AB8", D_002E5EB8);

extern "C" s32 func_00244470(s32 a, SndReq *q) {
    Func235DE0(D_002E5EB8, q->m4);
    return 1;
}

extern "C" void func_00244498(u32 v) {
    func_0027BD20();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B400 = v;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    return func_0027BD78();
}

INCLUDE_ASM("asm/nonmatchings/Unit243AB8", func_00244500);

extern "C" s32 func_00244658(void) {
    func_001F15F0();
    D_002B9DA0 = 0;
    func_0027E260(D_38F048);
    func_001F1610();
    return 1;
}

extern "C" s32 func_00244698(void) {
    func_001F15F0();
    func_0027E348(D_38F048);
    D_002B9DA0 = 1;
    func_001F1610();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/Unit243AB8", func_002446D8);

extern "C" s32 func_00244858(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/Unit243AB8", func_00244860);

extern "C" s32 func_002448D8(void) {
    D_002B9DB8 = 0;
    return func_001F0C60((void *)func_002446D8, 0, 0, 0);
}

extern "C" void func_00244910(s32 a, s32 b) {
    D_002B9DC8 = a;
    D_002B9DCC = b;
}

extern "C" void func_00244928(void) {
    s32 i;
    D_002B9D88 = 0;
    NOSWAP();
    func_00244860();
    if (D_002B9D84 >= 0) {
        func_0022DDE8(D_002B9D84);
        D_002B9D84 = -1;
        D_002B9D88 = 0;
    }
    for (i = 0; i < 4; i++) func_00243F20(i);
}

extern "C" void func_002449A8(void) {
    s32 i;
    if (!D_002B9DAC) return;
    func_00244928();
    D_002B9D94 = 1;
    D_002B9D98 = 0;
    D_002B9DBC = 0;
    func_002679A8(&D_38F000);
    for (i = 0; i < 4; i++) func_00243DF0(i);
    func_002454D8((Ring *)D_002B9DA8);
    func_00244498(1);
    D_002B9DA0 = 1;
    D_002B9DA4 = 0;
    D_38F06C = 0;
    D_38F070 = 0;
    D_38F074 = 0;
    D_002B9D90 = 0;
    D_002B9D8C = 0x80;
    return func_00244178();
}

INCLUDE_ASM("asm/nonmatchings/Unit243AB8", func_00244A80);

extern "C" void func_00244CA0(void) {
    s32 i;
    if (D_002B9DAC) {
        D_002B9DAC = 0;
        func_002679A8(&D_38F000);
        func_00267818(&D_38F000);
        func_002454B0((void *)D_002B9DA8);
        D_002B9DA8 = 0;
        for (i = 0; i < 4; i++) func_00243FF8(i);
        func_00244208();
        D_002B91B0(D_002B9D9C);
        D_002B9D9C = 0;
        D_002B91B0((void *)D_002B9D80);
        D_002B9D80 = 0;
    }
}

extern "C" void func_00244D68(void) {
    s32 i;
    D_002B9DAC = 0;
    D_002B9D8C = 0x80;
    D_002B9DA8 = 0;
    D_002B9DB0 = 0;
    D_002B9DC4 = 0;
    func_00267558();
    for (i = 0; i < 4; i++) func_00243D98(i);
}

extern "C" void func_00244DD8(void) {
}

INCLUDE_ASM("asm/nonmatchings/Unit243AB8", func_00244DE0);

extern "C" void func_00244EB0(void) {
    func_002449A8();
    return func_00244CA0();
}

extern "C" s32 func_00244ED0(void) {
    s32 v = D_002B9D98 - 2;
    if (v < 0) v = 0;
    return v;
}

INCLUDE_ASM("asm/nonmatchings/Unit243AB8", func_00244EE8);

extern "C" s32 func_002451A8(void) {
    return D_002B9DBC;
}

extern "C" s32 func_002451B8(void) {
    s32 old = D_38F074;
    D_38F074 = 0;
    return old;
}

extern "C" s32 func_002451D0(void) {
    return D_38F070 ^ D_002B9DC0 ^ 1;
}

extern "C" s32 func_002451F0(void) {
    return D_002B9DC0;
}

extern "C" void func_00245200(s32 v) {
    D_002B9DC0 = v != 0;
}

extern "C" s32 func_00245210(void) {
    return D_38F000;
}

extern "C" s32 func_00245220(void) {
    return D_38F004;
}

INCLUDE_ASM("asm/nonmatchings/Unit243AB8", func_00245230);

extern "C" s32 func_00245290(void) {
    return D_002B9DC4;
}

extern "C" void func_002452A0(void) {
}

extern "C" s32 func_002452A8(void) {
    return D_002B9DB0;
}

extern "C" void func_002452B8(s32 v) {
    D_002B9DB0 = v != 0;
}

extern "C" void func_002452C8(s32 v) {
    s32 t = v < 0 ? 0 : (v > 128 ? 128 : v);
    D_002B9D8C = t;
}

extern "C" s32 func_002452F8(u32 i) {
    s32 r = -1;
    if (i < 4) r = D_38F088[i].m8;
    return r;
}

extern "C" s32 func_00245320(u32 i) {
    s32 r = -1;
    if (i < 4) r = D_38F088[i].m4;
    return r;
}

extern "C" s32 func_00245348(u32 i) {
    s32 r = 0;
    if (i < 4) r = D_38F088[i].m24;
    return r;
}

extern "C" s32 func_00245370(u32 i) {
    s32 r = 0;
    if (i < 4) r = D_38F088[i].m28;
    return r;
}

extern "C" void func_00245398(u32 i, s32 b, s32 c) {
    SndCh *ch = &D_38F088[i];
    u32 ok = i < 4;
    NOSWAP();
    if (ok) { ch->mC = b; ch->m10 = c; }
}

extern "C" s32 func_002453C8(u32 i) {
    s32 r = 0;
    if (i < 4) r = D_38F088[i].mC;
    return r;
}

extern "C" s32 func_002453F0(u32 i) {
    s32 r = 0;
    if (i < 4) r = D_38F088[i].m10;
    return r;
}

extern "C" s32 func_00245418(void) {
    return D_002B9D8C;
}

extern "C" s32 func_00245428(void) {
    return D_002B9D84;
}

extern "C" s32 func_00245438(s32 v) {
    s32 old = D_002B9D90;
    D_002B9D90 = v;
    return old;
}
