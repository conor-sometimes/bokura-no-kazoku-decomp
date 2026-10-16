#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern u32 *D_002B94E4;
extern u8 D_002CDA00[];
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
extern void (*D_002B8C1C)(void);
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
inline u32 *PutQ(u64 hi, u64 lo) {
    u32 *q = PKT;
    PKT = q + 4;
    q[0] = lo;
    q[1] = lo >> 32;
    q[2] = hi;
    q[3] = hi >> 32;
    return q;
}
inline u32 *PUTD(u64 v) { u32 *p = PKT; PKT = p + 2; p[0] = v; p[1] = v >> 32; return p; }
extern u8 D_002CE000[];
extern u8 D_002CE0A8[];
extern u8 D_002CE5C0[];
extern "C" void func_00226B28(s32, s32, s32, u32);
extern "C" void func_00226C00(void);
extern "C" void func_00226ED0(s32);
extern "C" void func_00226DF8(u64, u64);

extern u8 D_002CF7B0[];
extern u8 D_002CF760[];
extern u8 D_002D0288[];
extern u8 D_002CF788[];
extern "C" s32 func_00237460(void);
extern "C" s32 func_002374B0(void);
extern "C" void *func_00237408(s32);
extern "C" void func_00227090(void);
extern "C" void func_002271E8(s32, u32, u32, s32);
extern "C" void func_002275A8(void);

extern u8 D_002CEFA0[];
extern u8 D_002CEF78[];
extern u8 D_002D1798[];
extern "C" void func_00227690(s32, u32, u32, s32, s32);
extern "C" s32 func_00238240(s32, s32, s32, s32, s32, s32);
extern "C" s32 func_002387D8(s32, s32, s32, s32);
extern "C" s32 func_002384B8(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 func_00238B08(long, s32, s32);
extern "C" s32 func_00238BA0(s32);
extern "C" s32 func_00238C30(s32);
extern "C" s32 func_00238C70(s32);
struct PEnt { u32 lo; u32 hi; s32 x; };
struct PTbl { s32 m0; s32 m4; s32 m8; s32 mC; PEnt e[1]; };
extern "C" s32 func_00225058(void);
extern "C" s32 func_00225040(void *);
void Func225088();
int Func2250C0();
extern "C" void func_00227AE8(void);
extern "C" s32 func_002393A0(s32, s32);
extern "C" s32 func_00239698(s32, s32);
extern "C" s32 func_0021BAC0(s32, void *, s32);
extern "C" void func_00228058(void);
extern "C" void func_002282A8(void);
extern "C" s32 strcmp(const char *, const char *);
s32 Func235DE0(const char *fmt, ...);
extern const char D_002E4008[];
extern u8 D_33E5D0[];
extern s32 D_33F5D0;
struct Res { u32 flags; s32 m4; void *m8; char name[0x24]; };
extern Res *D_33F5D8;
extern s32 D_002B8C30;
extern s32 D_002B8C34;
extern s32 D_002B8C38;
extern void *(*D_002B91A4)(s32);
extern void (*D_002B91B0)(void *);

extern "C" s32 func_001F1180(void);
extern "C" s32 func_0022FF58(const char *);
extern "C" s32 func_0022FF18(const char *, void *);
extern "C" void func_0022FFD0(void *);
extern "C" s32 func_0022FF88(void *);
extern "C" void *func_002303C0(const char *);
extern "C" void func_00229028(void *, u8 *);
extern "C" char *strcpy(char *, const char *);
extern "C" s32 func_00228458(const char *, void *, s32);
extern "C" s32 func_00228618(s32);
extern "C" void func_00228658(u8 *);
extern "C" u8 *func_00228710(const char *);
extern "C" s32 func_002289E8(u8 *);
extern "C" s32 func_00228A18(const char *, void *);
extern "C" s32 func_00228B20(const char *);
extern "C" s32 func_00228C38(void *);
extern "C" void func_00228CA8(void);
extern "C" void *func_002283A0(const char *);
extern const char D_002E4060[];
extern const char D_002E4090[];
extern const char D_002E40B0[];
extern const char D_002E40D0[];
extern u8 *D_33F5E0[2];
extern u8 *D_33F5E8[2];
extern u8 *D_33F5F0[2];
extern s32 D_33F5F8[2];
extern s32 D_33F600[2];
extern s32 D_33F608[2];
extern u8 *D_002B8C28[2];
#define TID func_001F1180()
// @decl-end
INCLUDE_RODATA("asm/nonmatchings/Unit226AE8", D_002E4008);
INCLUDE_RODATA("asm/nonmatchings/Unit226AE8", D_002E4060);
INCLUDE_RODATA("asm/nonmatchings/Unit226AE8", D_002E4090);
INCLUDE_RODATA("asm/nonmatchings/Unit226AE8", D_002E40B0);
INCLUDE_RODATA("asm/nonmatchings/Unit226AE8", D_002E40D0);

extern "C" void func_00226AE8(s32 a, s32 n) {
    D_33DE9C = 0;
    D_33DEA4 = 0;
    PUT((a + 0x149) | (n << 16) | 0x6C000000);
}

INCLUDE_ASM("asm/nonmatchings/Unit226AE8", func_00226B28);

INCLUDE_ASM("asm/nonmatchings/Unit226AE8", func_00226C00);

extern "C" void func_00226CF0(s32 addr, s32 n) {
    return func_00226B28(addr, n, 0, MSADDR(D_002CE000));
}

extern "C" void func_00226D30(s32 addr, s32 n, s32 flag) {
    return func_00226B28(addr, n, 0, flag ? MSADDR(D_002CE000) : MSADDR(D_002CE0A8));
}

extern "C" void func_00226D88(s32 a, s32 n) {
    D_33DEA4 = 0;
    D_33DE9C = 0;
    PUT((a + 0x1AA) | (n << 16) | 0x74000000);
}

extern "C" void func_00226DC8(f32 a, f32 b) {
    f32 *p = (f32 *)PKT;
    PKT = (u32 *)(p + 2);
    p[0] = a;
    p[1] = b;
    return func_00226C00();
}

extern "C" void func_00226DF8(u64 a, u64 b) {
    D_002B8C1C();
    D_33DE90 = 0;
    if (D_002B8C18 >= 54) func_00226ED0(1);
    if (D_002B8C18 == 0) D_33DEB0 = 1;
    D_33DEC0[D_002B8C18].lo = a;
    D_33DEC0[D_002B8C18].hi = b;
    D_002B8C18++;
}

extern "C" void func_00226EA0(s32 a) {
    func_00226DF8(a | 0x8000, 0);
    D_33DEB4 = 1;
}

extern "C" void func_00226ED0(s32 flag) {
    s32 i;
    u64 tag;
    u32 a;
    if (D_002B8C18 > 0) {
        a = D_33DEB8 | 0x8000;
        PUT(a | ((D_002B8C18 + 1) << 16) | 0x68000000);
        tag = D_002B8C18;
        if (D_33DEB4) tag |= 0x1000000000008000;
        else tag |= 0x1000000000000000;
        PUTD(tag);
        PUT(0xE);
        for (i = 0; i < D_002B8C18; i++) {
            PUTD(D_33DEC0[i].hi);
            PUT(*(u32 *)&D_33DEC0[i].lo);
        }
        D_33DEB4 = 0;
        D_33DEB8 += D_002B8C18 + 1;
        D_002B8C18 = 0;
        D_33DE90 = 0;
    }
    if (flag && D_33DEB0) {
        PUT(MSCAL(D_002CE5C0));
        D_33DEB8 = 0;
        D_33DEB0 = 0;
        D_33DE90 = 0;
    }
}

extern "C" void func_00227090(void) {
    u32 h;
    if (D_33DEA4 > 0) {
        func_00237460();
        h = (D_33DEB8 + 1) | 0xC000;
        PUT(h | ((D_33DEA4 * D_33DEA8) << 16) | 0x6E000000);
        func_002374B0();
        PUT((D_33DEA4 * (D_33DEA8 * 3 + 1)) | 0x04000000);
        if (D_33DEB8 > 0) {
            PUT(D_33DEA0 | 0x14000000);
            D_33DE90 = 0;
        } else {
            func_00224FF0(D_33DE9C);
        }
        D_33DEB8 = 0;
        if (D_002B8C18 == 0) D_33DEB0 = 0;
        D_33DEA4 = 0;
        D_33DEA8 = 0;
        D_33DEAC = 0;
    }
}

extern "C" void func_002271E8(s32 a, u32 b, u32 c, s32 d) {
    u64 t;
    D_002B8C1C = func_00227090;
    func_00226ED0(0);
    if ((D_33DE9C == 0 || D_33DE9C == b) && (D_33DEAC == 0 || D_33DEAC == a)
        && D_33DEB8 + D_33DEA4 * D_33DEA8 + 1 < 54 - d
        && d * 3 + 1 < 0x91 - D_33DEA4 * (D_33DEA8 * 3 + 1) - D_33DEB8) {
    } else {
        D_002B8C1C();
    }
    D_33DE9C = b;
    D_33DEA0 = c;
    D_33DEA8 = d;
    D_33DEAC = a;
    D_002B8C20 = d;
    if (D_33DEA4 == 0) {
        PUT(D_33DEB8 | 0x68018000);
        t = (u64)d | ((u64)a << 32);
        PUTD(t | ((u64)a << 47) | ((u64)0xC001 << 46));
        if (a & 0x10) PUT(0x412);
        else PUT(0x41F);
        func_00237408(4);
    }
    D_33DEA4++;
}

extern "C" void func_002273F8(s32 a) {
    return func_002271E8(a | 5, MSADDR(D_002CF7B0), MSADDR(D_002CF760), 3);
}

extern "C" void func_00227460(s32 a) {
    return func_002271E8(a | 5, MSADDR(D_002D0288), MSADDR(D_002CF788), 4);
}

extern "C" void func_002274C8(s32 a, s32 n) {
    if (n == 3) return func_002271E8(a | 5, MSADDR(D_002CF7B0), MSADDR(D_002CF760), 3);
    if (n == 4) return func_002271E8(a | 5, MSADDR(D_002D0288), MSADDR(D_002CF788), 4);
}

extern "C" void func_002275A8(void) {
    if (D_33DEA4 > 0) {
        PUT((D_33DEA4 + D_33DEA8 * 3) | 0x04000000);
        if (D_33DEB8 > 0) {
            PUT(D_33DEA0 | 0x14000000);
            D_33DE90 = 0;
        } else {
            func_00224FF0(D_33DE9C);
        }
        D_33DEB8 = 0;
        if (D_002B8C18 == 0) D_33DEB0 = 0;
        D_33DEA4 = 0;
        D_33DEA8 = 0;
        D_33DEAC = 0;
    }
}

extern "C" s32 func_00227688(void) {
    return 0x30;
}

INCLUDE_ASM("asm/nonmatchings/Unit226AE8", func_00227690);

extern "C" void func_00227900(s32 a, s32 d) {
    return func_00227690(a | 2, MSADDR(D_002CEFA0), MSADDR(D_002CEF78), d, 0);
}

extern "C" void func_00227968(s32 a, s32 d, s32 e) {
    return func_00227690(a | 4, MSADDR(D_002CEFA0), MSADDR(D_002CEF78), d, e);
}

extern "C" void func_002279D0(s32 a, s32 b, s32 c, s32 d) {
    u8 *p;
    if (D_002B8C20 > 0) {
        p = (u8 *)PKT;
        PKT = (u32 *)(p + 4);
        p[0] = a;
        p[1] = b;
        p[2] = c;
        p[3] = d;
        D_002B8C20--;
    }
}

extern "C" void func_00227A20(void) {
    D_33DE90 = 0;
    D_33DE94 = 1;
    D_33DE9C = 0;
    D_33DEA0 = 0;
    D_33DEA4 = 0;
    D_002B8C18 = 0;
    D_33DEB4 = 0;
    D_33DEB0 = 0;
    D_33DEB8 = 0;
    D_002B8C20 = 0;
    D_33DEA8 = 0;
    D_33DEAC = 0;
    D_002B8C1C = func_00227090;
}

extern "C" void func_00227AA8(void) {
    D_002B8C1C();
    func_00226ED0(1);
    D_33DE90 = 0;
    D_33DE94 = 1;
}

extern u8 D_002CDA00_b[] __asm__("D_002CDA00");
extern "C" void func_00227AE8(void) {
    PUT(0x11000000);
    PUT(0x01000404);
    PUT(0x05000000);
    PUT(0x20000000);
    PUT(0xF0F0F0F0);
    PUT(0x03000394);
    PUT(0x02000036);
    PUT(0x14000000 | ((D_002CDA00_b - D_002CDA00 + 7) / 8));
    PUT(0x10000000);
    D_33DE90 = 0;
}

extern "C" s32 func_00227BF0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 r;
    func_00237350(8);
    func_00237408(8);
    r = func_00238240(a, b, c, d, e, f);
    func_00237460();
    PUT(0x11000000);
    PUT(r | 0x50000000);
    return func_002374B0();
}

extern "C" s32 func_00227CB8(s32 a, s32 b, s32 c, s32 d) {
    return func_002387D8(a, b, c, d);
}

extern "C" s32 func_00227CD0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i) {
    s32 r;
    func_00237350(8);
    func_00237408(8);
    r = func_002384B8(a, b, c, d, e, f, g, h, i);
    func_00237460();
    PUT(0x11000000);
    PUT(r | 0x50000000);
    return func_002374B0();
}

int Func227DC8(long a, int b, int c) {
    s32 r;
    func_00237350(8);
    func_00237408(8);
    r = func_00238B08(a, b, c);
    func_00237460();
    PUT(0x11000000);
    PUT(r | 0x50000000);
    return func_002374B0();
}

extern "C" s32 func_00227E60(s32 a) {
    s32 r;
    func_00237350(8);
    func_00237408(8);
    r = func_00238BA0(a);
    func_00237460();
    PUT(0x11000000);
    PUT(r | 0x50000000);
    return func_002374B0();
}

extern "C" s32 func_00227ED8(s32 a) {
    s32 r;
    func_00237350(8);
    func_00237408(8);
    r = func_00238C30(a);
    func_00237460();
    PUT(0x11000000);
    PUT(r | 0x50000000);
    return func_002374B0();
}

extern "C" s32 func_00227F50(s32 a) {
    s32 r;
    func_00237350(8);
    func_00237408(8);
    r = func_00238C70(a);
    func_00237460();
    PUT(0x11000000);
    PUT(r | 0x50000000);
    return func_002374B0();
}

extern "C" u32 func_00227FC8(PTbl *p) {
    return p->m4 & 0x7FFF;
}

INCLUDE_ASM("asm/nonmatchings/Unit226AE8", func_00227FD8);

extern "C" s32 func_00228008(PTbl *p, s32 i) {
    return p->e[i].x;
}

INCLUDE_ASM("asm/nonmatchings/Unit226AE8", func_00228020);

extern "C" void func_00228058(void) {
    s32 a, r;
    a = func_00225058();
    func_00225040(D_33E5D0);
    Func225088();
    func_00227AE8();
    r = Func2250C0();
    func_00225040((void *)a);
    func_002393A0(1, r);
    return (void)func_00239698(1, 0);
}

extern "C" void func_002280D0(void) {
    s32 r = func_0021BAC0(1, D_002CDA00, D_002D1798 - D_002CDA00);
    D_33F5D0 = r;
    if (r > 0) {
        Func235DE0(D_002E4008);
        for (;;) {
        }
    }
    return func_00228058();
}

extern "C" s32 func_00228140(u8 *a, u8 *b) {
    return func_0021BAC0(1, a, b - a);
}

extern "C" void func_00228168(void) {
    s32 i;
    Res *e;
    u32 f;
    if (D_002B8C30) {
        for (i = 0; i < D_002B8C30; i++) {
            e = &D_33F5D8[i];
            f = e->flags;
            if (f & 1) {
                if (!(f & 2)) D_002B91B0(e->m8);
            }
        }
    }
}

extern "C" void func_00228208(void) {
    s32 i;
    D_002B8C30 = 0x20;
    D_33F5D8 = (Res *)D_002B91A4(0x600);
    for (i = 0; i < D_002B8C30; i++) {
        Res *e = &D_33F5D8[i];
        e->flags = 0;
    }
    D_002B8C34 = 1;
    D_002B8C38 = 0;
}

extern "C" void func_002282A8(void) {
    s32 i;
    Res *e;
    if (D_002B8C30) {
        for (i = 0; i < D_002B8C30; i++) {
            e = &D_33F5D8[i];
            if (e->flags & 1) D_002B91B0(e->m8);
        }
    }
}

extern "C" void func_00228340(void) {
    if (D_002B8C30) {
        func_002282A8();
        D_002B91B0(D_33F5D8);
        D_002B8C30 = 0;
        D_002B8C34 = 0;
        D_002B8C38 = 0;
    }
}

extern "C" void *func_002283A0(const char *name) {
    s32 i;
    Res *e;
    if (!D_002B8C30) return 0;
    for (i = 0; i < D_002B8C30; i++) {
        e = &D_33F5D8[i];
        if ((e->flags & 1) && strcmp(name, e->name) == 0) return e->m8;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/Unit226AE8", func_00228458);

extern "C" void func_00228538(s32 a) {
    D_002B8C34 = a;
}

extern "C" s32 func_00228548(const char *name) {
    s32 size, r, al;
    void *buf;
    if (!D_002B8C30) return -1;
    if (func_002283A0(name)) return -1;
    size = func_0022FF58(name);
    al = (size + 0x7FF) & ~0x7FF;
    if (size <= 0) return -1;
    buf = D_002B91A4(al);
    if (!buf) return -1;
    func_0022FF18(name, buf);
    r = func_00228458(name, buf, 3);
    Func235DE0(D_002E4060, name, size);
    return r;
}

asm(".p2align 3");
extern "C" s32 func_00228618(s32 off) {
    return *(s32 *)(D_33F5E0[TID] + off);
}

extern "C" void func_00228658(u8 *base) {
    s32 o;
    D_33F5E0[TID] = base;
    o = func_00228618(4);
    D_33F608[TID] = func_00228618(8);
    D_33F5E8[TID] = base + o;
    D_33F5F0[TID] = base + 0x10;
    D_33F600[TID] = 0;
}

INCLUDE_ASM("asm/nonmatchings/Unit226AE8", func_00228710);

INCLUDE_ASM("asm/nonmatchings/Unit226AE8", func_002288A0);

extern "C" s32 func_002289E8(u8 *p) {
    return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}

extern "C" s32 func_00228A18(const char *name, void *buf) {
    u8 *e;
    if (!D_002B8C28[TID]) return func_0022FF18(name, buf);
    func_00228658(D_002B8C28[TID]);
    e = func_00228710(name);
    if (!e) {
        Func235DE0(D_002E4090, name);
        return -2;
    }
    D_33F5F8[TID] = func_002289E8(e);
    func_00229028(buf, e);
    return D_33F5F8[TID];
}

extern "C" s32 func_00228B20(const char *name) {
    u8 *e;
    if (!D_002B8C28[TID]) return func_0022FF58(name);
    func_00228658(D_002B8C28[TID]);
    e = func_00228710(name);
    if (!e) {
        Func235DE0(D_002E4090, name);
        return -2;
    }
    D_33F5F8[TID] = func_002289E8(e);
    return D_33F5F8[TID];
}

extern "C" u8 *func_00228C00(void) {
    return D_002B8C28[TID];
}

extern "C" s32 func_00228C38(void *a) {
    D_002B8C28[TID] = (u8 *)a;
    if (!a) {
        func_0022FFD0(0);
        return func_0022FF88(0);
    }
    func_0022FFD0((void *)func_00228B20);
    return func_0022FF88((void *)func_00228A18);
}

extern "C" void func_00228CA8(void) {
    if (D_002B8C28[TID] && !D_002B8C38) D_002B91B0(D_002B8C28[TID]);
    return (void)func_00228C38(0);
}

extern "C" s32 func_00228D18(const char *name) {
    void *r;
    if (D_002B8C28[TID]) func_00228CA8();
    D_002B8C38 = D_002B8C34;
    r = 0;
    if (D_002B8C30) {
        r = func_002283A0(name);
        if (r) {
            Func235DE0(D_002E40B0, name, r);
            D_002B8C38 = 1;
        }
    }
    if (!r) {
        r = func_002303C0(name);
        if (!r) Func235DE0(D_002E40D0, name);
        if (D_002B8C38) func_00228458(name, r, 1);
    }
    func_00228C38(r);
    return 0;
}

extern "C" s32 func_00228E18(const char *name) {
    if (!D_002B8C28[TID]) return 0;
    func_00228658(D_002B8C28[TID]);
    if (!func_00228710(name)) return 0;
    return D_33F5F8[TID];
}


extern "C" u8 *func_00228EA0(const char *name)
{
    u8 *r;
    if (!D_002B8C28[TID]) return 0;
    func_00228658(D_002B8C28[TID]);
    r = func_00228710(name);
    asm("");
    return r;
}

extern "C" s32 func_00228F08(void) {
    if (!D_002B8C28[TID]) return 0;
    func_00228658(D_002B8C28[TID]);
    return D_33F608[TID];
}
