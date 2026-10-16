#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" s32 func_0020DC98(s32 cmd, void *rbuf, s32 rsize, void *sbuf, s32 ssize);
extern "C" void *memset(void *dst, int c, unsigned int n);
int Func235DE0(const char *, ...);
extern "C" s32 func_00206088(void);
extern "C" void func_00206808(void *dst, void *src, s32 n);
extern "C" void func_00207B80(s32);
extern "C" s32 func_00207530(s32, s32, s32);
extern "C" s32 func_00207960(s32);
struct S30E4C0 { u8 m0, m1, m2, m3; s16 m4, m6; };
extern S30E4C0 D_30E4C0;
extern s32 D_002A5DE8;
extern u8 D_30E500[];
extern void (*D_002A6108)(void);
typedef s32 (*AllocFn)(s32);
typedef void (*FreeFn)(void *);
extern AllocFn D_002A610C;
extern AllocFn D_002A6110;
extern FreeFn D_002A6114;
extern const char D_002E2C38[];
struct S30F500 { u8 pad0[0x40]; s32 m40; s32 m44; u8 pad48[0x38]; };
extern S30F500 D_30F500;
struct S310DA0 { s32 m0; s32 m4; s32 m8; s32 mC; s32 m10; };
extern S310DA0 D_310DA0[];
struct SndNode { SndNode *m0; SndNode *m4; s32 m8; s32 mC; s32 m10; s32 m14; };
struct SndChan { s32 m0; s32 m4; u32 m8; u32 mC; s32 m10; };
struct S30F580 { SndNode m0[256]; SndNode m1800; SndNode *m1818; s32 m181C; SndChan m1820[256]; SndChan m2C20; s32 m2C34[2]; };
extern S30F580 D_30F580;
typedef s32 (*Fn1)(s32);
extern Fn1 D_002A6118;
extern Fn1 D_002A611C;
typedef void (*Fn2)(void *);
extern Fn2 D_002A6120;

extern "C" void func_0020DE28(s32, s32, s32);
extern "C" void *func_0020DED8(void);
extern "C" s32 func_0020DEF0(void);
extern "C" void func_00206548(void);
struct Pkt3 { s32 m0; s32 m4; s32 m8; };
struct Pkt4 { s32 m0; s32 m4; s16 m8; s16 mA; };
struct CmdPkt { u8 m0; u8 m1; u8 pad[2]; s32 m4; s32 m8; s32 mC; };
extern s32 D_310D9C;
struct SndDummy { S310DA0 c; s32 m14[2]; };
extern SndDummy D_3121A0;

extern "C" void func_00206F50(u32 i);
extern "C" SndNode *func_00207C90(void);
extern const char D_002E2C60[];
// @decl-end

extern "C" s32 func_00206508(void) { return D_002A5DE8; }

extern "C" s16 func_00206518(void) { return D_30E4C0.m4; }

extern "C" s16 func_00206528(void) { return D_30E4C0.m6; }

extern "C" u8 *func_00206538(void) { return D_30E500; }

extern "C" void func_00206548(void) {
}

extern "C" void func_00206550(void (*fn)(void)) { D_002A6108 = fn; }

extern "C" void func_00206560(void) {
    if (D_002A6108) D_002A6108();
}

extern "C" void func_00206588(u8 *d, u8 *s, s32 n) {
    s32 i;
    if (d < s) {
        for (i = 0; i < n; i++) *d++ = *s++;
    } else {
        d = d + n - 1;
        s = s + n - 1;
        for (i = 0; i < n; i++) *d-- = *s--;
    }
}

extern "C" s32 func_00206608(s32 size) {
    s32 buf[3];
    s32 r;
    size = (size + 63) & ~63;
    buf[0] = 0;
    buf[2] = 0;
    buf[1] = size;
    r = func_0020DC98(0x20, 0, 0, buf, 0xC);
    if (r) return r;
    if (func_00206088() & 1) Func235DE0(D_002E2C38, size);
    return 0;
}

extern "C" s32 func_00206680(s32 size) {
    s32 buf[3];
    s32 r;
    size = (size + 63) & ~63;
    buf[0] = 1;
    buf[2] = 0;
    buf[1] = size;
    r = func_0020DC98(0x20, 0, 0, buf, 0xC);
    if (r) return r;
    if (func_00206088() & 1) Func235DE0(D_002E2C38, size);
    return 0;
}

extern "C" void func_00206700(void *p) {
    void *buf = p;
    func_0020DC98(0x21, 0, 0, &buf, 4);
}

extern "C" void func_00206730(AllocFn fn) {
    D_002A610C = (fn ? fn : func_00206608);
}

extern "C" void func_00206750(AllocFn fn) {
    D_002A6110 = (fn ? fn : func_00206680);
}

extern "C" void func_00206770(FreeFn fn) {
    D_002A6114 = (fn ? fn : func_00206700);
}

extern "C" s32 func_00206790(s32 size) { return D_002A610C(size); }

extern "C" s32 func_002067B8(s32 size) { return D_002A6110(size); }

void Func2067E0(void *p) { D_002A6114(p); }

INCLUDE_ASM("asm/nonmatchings/Unit206508", func_00206808);

INCLUDE_ASM("asm/nonmatchings/Unit206508", func_00206A18);

extern "C" s32 func_00206C00(void *dst, s32 n) {
    while (n > 0) {
        s32 c = n > 0x1000 ? 0x1000 : n;
        func_00206808(dst, func_00206538(), c);
        n -= c;
    }
    return 1;
}

extern "C" s32 func_00206C78(void *src, s32 size) {
    s32 p = func_00206790(size);
    if (!p) return 0;
    func_00206808((void *)p, src, size);
    return p;
}

extern "C" s32 func_00206CD0(void) {
    s32 buf = 1;
    return func_0020DC98(0x22, 0, 0, &buf, 4);
}

extern "C" s32 func_00206D08(void) {
    s32 buf = 2;
    return func_0020DC98(0x22, 0, 0, &buf, 4);
}

extern "C" s32 func_00206D40(s32 a, s32 b, s32 c) {
    s32 buf[3];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    return func_0020DC98(0x23, 0, 0, buf, 0xC);
}

extern "C" void func_00206D78(void) {
    memset(&D_30F500, 0, sizeof(D_30F500));
    D_30F500.m40 = func_00206790(0x20);
    D_30F500.m44 = func_00206790(0x20);
}

extern "C" void func_00206DC8(void) {
    if (D_30F500.m40) Func2067E0((void *)D_30F500.m40);
    if (D_30F500.m44) Func2067E0((void *)D_30F500.m44);
    return;
}

extern "C" s32 func_00206E18(s32 id, u32 addr, u32 size) {
    SndChan *c;
    u32 max;
    if (id < 0) {
        for (id = 0; id < 0x100; id++) {
            if (!D_30F580.m1820[id].m4) break;
        }
    }
    if ((u32)id >= 0x100) {
        if (func_00206088() & 1) Func235DE0(D_002E2C60, id);
        return -1;
    }
    c = &D_30F580.m1820[id];
    if (c->m4) func_00206F50(id);
    addr = addr < 0x5010 ? 0x5010 : (addr > 0x1BFFFF ? 0x1BFFFF : addr);
    max = 0x1C0000 - addr;
    if (size >= max) size = max;
    c->m4 = 1;
    c->m8 = addr;
    c->mC = size;
    return id;
}

extern "C" void func_00206F50(u32 i) {
    if (i < 0x100) {
        S310DA0 *e = &D_310DA0[i];
        if (e->m4) {
            func_00207B80(i);
            e->m4 = 0;
        }
    }
}

extern "C" s32 func_00206FA8(s32 v) {
    s32 old = D_30F580.m2C34[func_00206508()];
    D_30F580.m2C34[func_00206508()] = v;
    return old;
}

extern "C" s32 func_00207008(void) { return D_30F580.m2C34[func_00206508()]; }

extern "C" s32 func_00207040(s32 a) { return func_00207530(0, 0, a); }

extern "C" s32 func_00207060(s32 a) { return func_00207530(1, 0, a); }

extern "C" s32 func_00207080(s32 a) { return func_00207960(a); }

extern "C" void func_00207098(Fn1 fn) {
    D_002A6118 = (fn ? fn : func_00207040);
}

extern "C" void func_002070B8(Fn1 fn) {
    D_002A611C = (fn ? fn : func_00207060);
}

extern "C" void func_002070D8(Fn1 fn) {
    D_002A6120 = (Fn2)(fn ? fn : func_00207080);
}

extern "C" s32 func_002070F8(s32 a) { return D_002A6118(a); }

extern "C" s32 func_00207120(s32 a) { return D_002A611C(a); }

void Func207148(void *p) { D_002A6120(p); }

extern "C" s32 func_00207170(s32 a, s32 b, s32 c) {
    CmdPkt buf;
    buf.m0 = 3;
    buf.m1 = 1;
    buf.m4 = a;
    buf.m8 = b;
    buf.mC = c;
    return func_0020DC98(0x40, 0, 0, &buf, 0x10);
}

extern "C" s32 func_002071B8(s32 a, s32 b, s32 c) {
    CmdPkt buf;
    buf.m0 = 4;
    buf.m1 = 1;
    buf.m4 = a;
    buf.m8 = b;
    buf.mC = c;
    return func_0020DC98(0x40, 0, 0, &buf, 0x10);
}

extern "C" s32 func_00207200(s32 a, s32 b, s32 c) {
    CmdPkt buf;
    buf.m0 = 1;
    buf.m1 = 1;
    buf.m4 = a;
    buf.m8 = b;
    buf.mC = c;
    return func_0020DC98(0x40, 0, 0, &buf, 0x10);
}

extern "C" s32 func_00207248(s32 a, s32 b, s32 c) {
    CmdPkt buf;
    buf.m0 = 2;
    buf.m1 = 1;
    buf.m4 = a;
    buf.m8 = b;
    buf.mC = c;
    return func_0020DC98(0x40, 0, 0, &buf, 0x10);
}

extern "C" s32 func_00207290(s32 a, s32 c) {
    CmdPkt buf;
    buf.m0 = 5;
    buf.m1 = 1;
    buf.m4 = a;
    buf.m8 = 0;
    buf.mC = c;
    return func_0020DC98(0x40, 0, 0, &buf, 0x10);
}

extern "C" s32 func_002072D8(s32 a, s32 wait) {
    s32 buf;
    s32 r;
    s32 i;
    do {
        buf = a;
        r = func_0020DC98(0x41, 0, 0, &buf, 4);
        if (r && wait) {
            for (i = 9999; i >= 0; i--) func_00206548();
        }
    } while (wait && r);
    return r;
}

extern "C" s32 func_00207370(void) { return D_310D9C; }

extern "C" s32 func_00207380(void) {
    s32 max = 0;
    SndNode *n;
    for (n = D_30F580.m1800.m4; n != &D_30F580.m1800; n = n->m4) {
        if (n->mC == 0) {
            if (max < n->m14) max = n->m14;
        }
    }
    return max;
}

INCLUDE_ASM("asm/nonmatchings/Unit206508", func_002073D0);

extern "C" void func_002074F0(void) {
}

extern "C" S310DA0 *func_002074F8(u32 i) {
    if (i >= 0x100) return &D_3121A0.c;
    return &D_310DA0[i];
}

INCLUDE_RODATA("asm/nonmatchings/Unit206508", D_002E2C38);
INCLUDE_RODATA("asm/nonmatchings/Unit206508", D_002E2C60);
INCLUDE_ASM("asm/nonmatchings/Unit206508", func_00207530);

INCLUDE_ASM("asm/nonmatchings/Unit206508", func_00207960);

INCLUDE_ASM("asm/nonmatchings/Unit206508", func_00207B80);

extern "C" SndNode *func_00207C90(void) {
    SndNode *p = D_30F580.m1818;
    if (p) {
        D_30F580.m1818 = p->m4;
        return p;
    }
    return 0;
}

extern "C" void func_00207CB8(SndNode *p) {
    if (p) {
        p->m4 = D_30F580.m1818;
        D_30F580.m1818 = p;
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit206508", func_00207CD8);

extern "C" s32 func_00207F00(s32 a, s32 b) {
    Pkt3 *p;
    a = a < 0 ? 0 : (a > 1 ? 1 : a);
    b = b < 0 ? 0 : (b > 9 ? 9 : b);
    func_0020DE28(0x32, 0, 0xC);
    p = (Pkt3 *)func_0020DED8();
    p->m0 = a;
    p->m4 = 0;
    p->m8 = b;
    return func_0020DEF0();
}

extern "C" s32 func_00207FA0(s32 a, s32 b, s32 c) {
    Pkt4 *p;
    a = a < 0 ? 0 : (a > 1 ? 1 : a);
    func_0020DE28(0x32, 0, 0xC);
    p = (Pkt4 *)func_0020DED8();
    p->m0 = a;
    p->m4 = 2;
    p->m8 = b;
    p->mA = c;
    return func_0020DEF0();
}

extern "C" s32 func_00208028(s32 a, s32 b) {
    Pkt3 *p;
    a = a < 0 ? 0 : (a > 1 ? 1 : a);
    func_0020DE28(0x32, 0, 0xC);
    p = (Pkt3 *)func_0020DED8();
    p->m0 = a;
    p->m4 = 3;
    p->m8 = b;
    return func_0020DEF0();
}

extern "C" s32 func_002080A8(s32 a, s32 b) {
    Pkt3 *p;
    a = a < 0 ? 0 : (a > 1 ? 1 : a);
    func_0020DE28(0x32, 0, 0xC);
    p = (Pkt3 *)func_0020DED8();
    p->m0 = a;
    p->m4 = 4;
    p->m8 = b;
    return func_0020DEF0();
}
