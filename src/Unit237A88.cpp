#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct DmaTagB { u32 qwc : 16; u32 pad : 12; u32 id : 3; u32 irq : 1; u32 addr; u32 w2; u32 w3; };
struct DmaTagQ { u64 d0; u64 d1; };
struct DmaTag { DmaTagB b; };
#define TQ(t) ((DmaTagQ *)(t))
static inline u32 PA(u32 a) { return (a & 0x70000000) == 0x70000000 ? a | 0x80000000 : a; }
class CUnk237E90 {
public:
    int Func237E90(int v);
};
void *Func237C30(void *p);
extern "C" void func_00237BC0(DmaTag *t, u32 addr);
extern "C" void func_00237C20(DmaTag *t, u32 v);
extern "C" DmaTag *func_00237C80(DmaTag *t);
extern "C" DmaTag *func_00237CD0(DmaTag *t);
extern "C" DmaTag *func_00237CF8(DmaTag *t);

s32 Func235DE0(const char *fmt, ...);
extern u8 *D_002B94E4;
extern DmaTag *D_37BDB0;
struct DmaHnd { s32 m0; u8 pad[0x404]; };
extern DmaHnd D_37BE38[];
extern s32 D_37CA50[3];
extern s32 D_37CA60[3];
struct GsDisp { u32 b0 : 1; u32 b1 : 1; u32 rest : 30; u32 hi; u32 m8[8]; };
struct GsDB { GsDisp disp[2]; u8 buf[2][0x110]; };
extern GsDB D_37CA90;
extern u64 D_37CD00[];
extern u64 D_37CD10;
extern s32 D_37CA88;
extern s32 D_37CA8C;
extern u8 D_37CD20[];
extern u8 D_37CAE0[];
extern const char D_002E5330[];
extern "C" u8 *func_00237680(s32);
extern "C" u32 *func_00237720(u32, u32, u32, u32);
extern "C" u8 *func_002379D0(u32);
extern "C" u8 *func_00237860(s32, u32);
extern "C" void func_0023C048(s32, void *, s32);
extern "C" s32 func_00238240(s32, s32, s32, s32, s32, void *);
extern "C" void func_00238FE0(s32, s32 *);
extern "C" s32 func_002390B0(s32);
extern "C" s32 func_00272EB0(s32, void *, s32);
extern "C" s32 func_00273B38(s32);
extern "C" void func_00273AD0(s32);
extern "C" void func_00272ED0(s32, s32);
extern "C" void func_00239268(s32);
extern "C" void func_00273420(s32);
extern "C" void func_001F15F0(void);
extern "C" void func_001F1610(void);
struct DmaChan { u32 chcr; };
extern "C" DmaChan *func_0026FE30(s32);
extern "C" void func_00270160(DmaChan *, u32);
extern "C" void func_002701C8(DmaChan *, u32, s32);
extern "C" void func_002702B8(DmaChan *);
extern "C" void func_00270300(DmaChan *, s32, s32);
extern "C" s32 func_002395A0(DmaChan *, s32, s32, s32);
extern "C" void func_0023D1B0(void);
extern "C" void func_00239758(void);
extern "C" void func_0023A9D8(void);
extern "C" void func_0023BF80(void);
extern "C" void func_0023BF98(void);
extern "C" void func_0023AA08(void);
extern "C" void func_002397B8(void);
extern "C" void func_0023D2E8(void);
extern "C" void func_0023E868(void);
extern "C" void func_0023C858(void *);
extern "C" void func_0023C510(void *);
extern "C" void func_0023DB28(u64, s32);
extern "C" void func_0023E088(u64);
extern "C" void func_0023E8F0(void);
extern "C" s32 func_0026E6F8(s16, s16, s16, s16);

struct GsInfo { s16 m0; s16 m2; s16 m4; };
extern "C" GsInfo *func_0026E888(void);
extern "C" void func_0023C6E8(void *, s32, s32, s32, s32);
extern "C" void func_0023C700(void *, s32);
extern "C" void func_00239088(DmaTag *);
extern "C" DmaTag *func_002390A0(void);
extern "C" DmaTag *func_002375C0(void);
extern "C" u8 *func_00237350(s32);
extern "C" DmaTag *func_002377D8(void);
extern "C" s32 func_0023E9D8(void);
extern "C" void func_0023C4D8(void *, s32);
extern "C" void func_0026ED28(void *);
extern "C" void func_0023C7D0(void *, void *);
extern "C" void func_00239BD8(u64 *);
extern "C" s32 func_00239E00(s32, s32);
extern "C" void func_0026E898(void);
extern const char D_002E5440[];
extern "C" s32 func_002393A0(s32, u32);
extern "C" s32 func_00239698(u32, s32);
struct PktSave { DmaTag *tag; DmaTag *call; u8 *cur; s32 sp; u8 *stack[32]; s32 len; };
extern "C" void func_00237260(PktSave *);
extern "C" void func_002372D8(PktSave *);
struct DispB { u32 b0 : 1; u32 b1 : 1; u32 rest : 30; u32 pad[9]; };

s32 Func235DE0(const char *fmt, ...);
extern const char D_002E5368[], D_002E5398[], D_002E53C8[], D_002E53F0[], D_002E5418[];
#define VPUSTAT(v) asm volatile("cfc2.ni %0, $vi29" : "=r"(v))
// @decl-end

void *Func237A88(void *p0, int n) {
    DmaTag *p = (DmaTag *)p0;
    s32 i;
    for (i = 0; i < n; i++) {
        DmaTag *t = &p[i];
        TQ(t)->d0 = 0;
        TQ(t)->d1 = 0;
        t->b.id = 2;
        t->b.addr = PA((u32)(t + 1));
        t->b.w2 = (u32)(t - 1);
        t->b.w3 = (u32)(t + 1);
    }
    p->b.w2 = 0;
    p[n - 1].b.id = 7;
    p[n - 1].b.addr = 0;
    return p;
}

extern "C" DmaTag *func_00237B28(DmaTag *p, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        DmaTag *t = &p[i];
        TQ(t)->d0 = 0;
        TQ(t)->d1 = 0;
        t->b.id = 2;
        t->b.addr = PA((u32)(t - 1));
        t->b.w2 = (u32)(t + 1);
        t->b.w3 = (u32)(t + 1);
    }
    p[n - 1].b.w2 = 0;
    p->b.addr = 0;
    p->b.id = 7;
    return p;
}

extern "C" void func_00237BC0(DmaTag *t, u32 addr) {
    if (t) {
        DmaTag *l = (DmaTag *)t->b.w3 - 1;
        u32 a = addr;
        if ((addr & 0x70000000) == 0x70000000) a = addr | 0x80000000;
        l->b.addr = a;
        if (addr) l->b.id = 2;
        else l->b.id = 7;
    }
}

extern "C" void func_00237C20(DmaTag *t, u32 v) {
    if (t) t->b.w2 = v;
}

void *Func237C30(void *p) {
    DmaTag *t;
    if (p == 0) return 0;
    t = (DmaTag *)p;
    while (func_00237CD0(t)) t = func_00237CD0(t);
    return t;
}

extern "C" DmaTag *func_00237C80(DmaTag *p) {
    DmaTag *t;
    if (p == 0) return 0;
    t = p;
    while (func_00237CF8(t)) t = func_00237CF8(t);
    return t;
}

extern "C" DmaTag *func_00237CD0(DmaTag *t) {
    if (t == 0) return 0;
    return (DmaTag *)(((DmaTag *)t->b.w3 - 1)->b.addr & 0x7FFFFFFF);
}

extern "C" DmaTag *func_00237CF8(DmaTag *t) {
    if (t == 0) return 0;
    return (DmaTag *)t->b.w2;
}

extern "C" s32 func_00237D10(DmaTag *t) {
    if (t == 0) return 0;
    return t->b.w3 - (u32)t;
}

extern "C" DmaTag *func_00237D28(DmaTag *a, DmaTag *b) {
    DmaTag *c;
    if (b == 0) return 0;
    if (a == 0) return b;
    c = func_00237CD0(a);
    func_00237BC0(a, (u32)b);
    func_00237C20(b, (u32)a);
    func_00237BC0(b, (u32)c);
    func_00237C20(c, (u32)b);
    return b;
}

extern "C" void func_00237DB0(DmaTag *a, DmaTag *b, DmaTag *c) {
    DmaTag *d;
    if (a == 0) return;
    if (b == 0) {
        b = func_00237C80(c);
        if (b == 0) return;
    } else if (c == 0) {
        c = (DmaTag *)Func237C30(b);
        if (c == 0) return;
    }
    d = func_00237CD0(a);
    func_00237BC0(a, (u32)b);
    func_00237C20(b, (u32)a);
    func_00237BC0(c, (u32)d);
    return func_00237C20(d, (u32)c);
}

int CUnk237E90::Func237E90(int v) {
    DmaTag *b = (DmaTag *)v;
    DmaTag *a = (DmaTag *)this;
    DmaTag *p;
    if (b == 0) return 0;
    if (a == 0) return (int)b;
    p = func_00237CF8(a);
    func_00237BC0(p, (u32)b);
    func_00237C20(b, (u32)p);
    func_00237BC0(b, (u32)a);
    func_00237C20(a, (u32)b);
    return (int)b;
}

extern "C" void func_00237F18(DmaTag *a, DmaTag *b, DmaTag *c) {
    DmaTag *p;
    if (a == 0) return;
    if (b == 0) {
        b = func_00237C80(c);
        if (b == 0) return;
    } else if (c == 0) {
        c = (DmaTag *)Func237C30(b);
        if (c == 0) return;
    }
    p = func_00237CF8(a);
    func_00237BC0(p, (u32)b);
    func_00237C20(b, (u32)p);
    func_00237BC0(c, (u32)a);
    return func_00237C20(a, (u32)c);
}

extern "C" DmaTag *func_00237FF8(DmaTag *a) {
    DmaTag *p, *n;
    if (a == 0) return 0;
    p = func_00237CF8(a);
    n = func_00237CD0(a);
    func_00237BC0(p, (u32)n);
    func_00237C20(n, (u32)p);
    func_00237C20(a, 0);
    func_00237BC0(a, 0);
    return a;
}

extern "C" void func_00238080(DmaTag *a, DmaTag *b) {
    DmaTag *p, *n;
    if (a == 0) {
        a = func_00237C80(b);
        if (a == 0) return;
    } else if (b == 0) {
        b = (DmaTag *)Func237C30(a);
        if (b == 0) return;
    }
    p = func_00237CF8(a);
    n = func_00237CD0(b);
    func_00237BC0(p, (u32)n);
    func_00237C20(n, (u32)p);
    func_00237C20(a, 0);
    return func_00237BC0(b, 0);
}

int Func238158(void *p, int f) {
    DmaTag *last;
    s32 id;
    if (p == 0) return 0;
    id = f == 0 ? 7 : 6;
    last = (DmaTag *)Func237C30(p);
    ((DmaTag *)last->b.w3 - 1)->b.id = id;
    return (int)p;
}

INCLUDE_ASM("asm/nonmatchings/Unit237A88", func_002381C0);
INCLUDE_RODATA("asm/nonmatchings/Unit237A88", D_002E5320);
INCLUDE_RODATA("asm/nonmatchings/Unit237A88", D_002E5330);

INCLUDE_ASM("asm/nonmatchings/Unit237A88", func_00238240);

INCLUDE_ASM("asm/nonmatchings/Unit237A88", func_002384B8);

extern "C" void func_00238660(void) {
    *(volatile u64 *)0x12001000 = 2;
}

extern "C" void func_00238678(void) {
    while (!(*(volatile u64 *)0x12001000 & 2));
    while (*(volatile u32 *)0x10003C00 & 0xF000000);
    while ((*(volatile u64 *)0x12001000 & 0xC000) != 0x4000);
    *(volatile u32 *)0x10003C00 = 0x800000;
    *(volatile u64 *)0x12001040 = 1;
}

extern "C" void func_00238718(s32 unused, u32 *p) {
    u32 a;
    *(volatile u32 *)0x10009030 += 16;
    *(volatile u32 *)0x10009020 = p[1];
    a = p[0];
    if ((a & 0x70000000) == 0x70000000) a |= 0x80000000;
    *(u32 *)0x10009010 = a;
    *(volatile u32 *)0x10009000 = (*(volatile u32 *)0x10009000 & 0x7FFFFEF2) | 0x80000000;
}

extern "C" void func_00238788(void) {
    *(volatile u32 *)0x10003C00 = 0;
    *(volatile u64 *)0x12001040 = 0;
    *(volatile u64 *)0x12001000 = 2;
    *(volatile u32 *)0x10009000 = (*(volatile u32 *)0x10009000 & 0x7FFFFEF2) | 0x85;
}

INCLUDE_ASM("asm/nonmatchings/Unit237A88", func_002387D8);

extern "C" s32 func_00238B08(s32 a, s32 n, s32 c) {
s32 q = (n + 31) / 32; s32 qw; u8 *r; u32 sz = q * 32; qw = q * 2; r = func_00237680(sz >> 2); func_0023C048(n, r, c); return func_00238240(a, 0, 0, 16, qw, r);
}

INCLUDE_ASM("asm/nonmatchings/Unit237A88", func_00238BA0);

extern "C" s32 func_00238C30(u64 *p) {
    s32 n = (s32)(*p & 0x7FFF) + 1;
    func_00237860(n, (u32)p);
    return n;
}

INCLUDE_ASM("asm/nonmatchings/Unit237A88", func_00238C70);

extern "C" void func_00238FE0(s32 ch, s32 *on) {
    volatile u32 *chcr = (volatile u32 *)(0x10008000 + (ch << 12));
    if (*on) *chcr |= 0x40;
    else *chcr &= ~0x40;
}

extern "C" u32 *func_00239020(u32 a) {
    func_00237720((u32)func_00238FE0, 1, 0, 0);
    if (a) func_002379D0(a);
    return func_00237720((u32)func_00238FE0, 0, 0, 0);
}

extern "C" void func_00239088(DmaTag *t) {
    D_37BDB0 = t;
    D_002B94E4 = (u8 *)(t + 1);
}

extern "C" DmaTag *func_002390A0(void) {
    return D_37BDB0;
}

INCLUDE_ASM("asm/nonmatchings/Unit237A88", func_002390B0);

extern "C" void func_00239268(s32 i) {
    D_37BE38[i].m0 = 0;
}

extern "C" void func_00239288(void) {
}

extern "C" void func_00239290(void) {
}

extern "C" void func_00239298(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        D_37CA60[i] = 0;
        func_00239268(i);
        D_37CA50[i] = func_00272EB0(i, (void *)func_002390B0, 0);
        func_00273B38(i);
    }
    return (void)Func235DE0(D_002E5330);
}

extern "C" void func_00239338(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        func_00273AD0(i);
        if (D_37CA50[i] >= 0) func_00272ED0(i, D_37CA50[i]);
    }
}

extern "C" s32 func_002393A0(s32 ch, u32 addr) {
    DmaChan *c;
    func_00273420(0);
    func_001F15F0();
    c = func_0026FE30(ch);
    c->chcr |= 0x80;
    if ((addr & 0x70000000) == 0x70000000) addr |= 0x80000000;
    func_00270160(c, addr);
    func_001F1610();
    return ch;
}

extern "C" s32 func_00239420(s32 ch, u32 addr, s32 n) {
    DmaChan *c;
    u32 a;
    func_00273420(0);
    func_001F15F0();
    c = func_0026FE30(ch);
    a = addr;
    if ((a & 0x70000000) == 0x70000000) a |= 0x80000000;
    func_002701C8(c, a, n);
    func_001F1610();
    return ch;
}

extern "C" s32 func_002394A8(s32 ch) {
    func_00273420(0);
    func_001F15F0();
    func_002702B8(func_0026FE30(ch));
    func_001F1610();
    return ch;
}

extern "C" s32 func_002394F8(s32 ch, s32 a, s32 b) {
    func_00273420(0);
    func_001F15F0();
    func_00270300(func_0026FE30(ch), a, b);
    func_001F1610();
    return ch;
}

INCLUDE_ASM("asm/nonmatchings/Unit237A88", func_00239568);

INCLUDE_ASM("asm/nonmatchings/Unit237A88", func_002395A0);
INCLUDE_RODATA("asm/nonmatchings/Unit237A88", D_002E5368);
INCLUDE_RODATA("asm/nonmatchings/Unit237A88", D_002E5398);
INCLUDE_RODATA("asm/nonmatchings/Unit237A88", D_002E53C8);
INCLUDE_RODATA("asm/nonmatchings/Unit237A88", D_002E53F0);
INCLUDE_RODATA("asm/nonmatchings/Unit237A88", D_002E5418);
INCLUDE_RODATA("asm/nonmatchings/Unit237A88", D_002E5440);

extern "C" s32 func_00239698(u32 ch, s32 x) {
    s32 r = 0;
    if (ch < 10) r = func_002395A0(func_0026FE30(ch), x, 0, ch);
    return r;
}

extern "C" void func_002396F8(void) {
    func_0023D1B0();
    func_00239758();
    func_0023A9D8();
    return func_0023BF80();
}

extern "C" void func_00239728(void) {
    func_0023BF98();
    func_0023AA08();
    func_002397B8();
    return func_0023D2E8();
}

extern "C" void func_00239758(void) {
    func_0023E868();
    *(u64 *)&D_37CA90.disp[0] = 0x66;
    *(u64 *)&D_37CA90.disp[1] = 0x66;
    D_37CA88 = 0;
    D_37CA8C = 1;
    D_37CD00[0] = 0;
    D_37CD00[1] = 0;
    D_37CD10 = 0;
}

extern "C" void func_002397B8(void) {
    func_0023C858(D_37CD20);
    func_0023C510(D_37CAE0);
    func_0023C510(D_37CAE0 + 0x110);
    func_0023DB28(D_37CD10, -1);
    func_0023E088(D_37CD10);
    D_37CD10 = 0;
    return func_0023E8F0();
}

extern "C" s32 func_00239818(s16 a, s16 b, s16 c, s16 d) {
    return func_0026E6F8(a, b, c, d);
}

INCLUDE_ASM("asm/nonmatchings/Unit237A88", func_00239850);

extern "C" void func_00239B10(s32 a, s32 b, s32 c, s32 d) {
    func_0023C6E8(D_37CAE0, a, b, c, d);
    return func_0023C6E8(D_37CAE0 + 0x110, a, b, c, d);
}

extern "C" void func_00239B90(s32 a) {
    func_0023C700(D_37CAE0, a);
    return func_0023C700(D_37CAE0 + 0x110, a);
}

INCLUDE_ASM("asm/nonmatchings/Unit237A88", func_00239BD8);

extern "C" void func_00239CA0(void) {
    if (func_0026E888()->m4 != 0 && func_0026E888()->m0 == 1) {
        s32 f = func_0023E9D8() == 0;
        func_0023C4D8(D_37CAE0 + D_37CA88 * 0x110, f);
        func_0023C4D8(D_37CAE0 + (D_37CA88 ^ 1) * 0x110, f ^ 1);
    }
    D_37CA90.disp[D_37CA88].b1 = D_37CA8C;
    func_00273420(0);
    func_0026ED28(&D_37CA90.disp[D_37CA88]);
    func_00239BD8((u64 *)D_37CA90.buf[D_37CA88]);
    D_37CA88 ^= 1;
    return func_0023C7D0(D_37CD20, D_37CA90.buf[D_37CA88]);
}

extern "C" s32 func_00239E00(s32 mode, s32 timeout) {
    u32 cnt = 0;
    u32 st;
    if (mode == 0) {
        while (*(volatile u32 *)0x10009000 & 0x80000100) {
            if (cnt++ > 0x4000000) {
                Func235DE0(D_002E5368);
                return -1;
            }
        }
        while (*(volatile u32 *)0x1000A000 & 0x80000100) {
            if (cnt++ > 0x4000000) {
                Func235DE0(D_002E5398);
                return -1;
            }
        }
        while (*(volatile u32 *)0x10003C00 & 0x1F000003) {
            if (cnt++ > 0x4000000) {
                Func235DE0(D_002E53C8);
                return -1;
            }
        }
        VPUSTAT(st);
        while (st & 0x100) {
            if (cnt++ > 0x4000000) {
                Func235DE0(D_002E53F0);
                return -1;
            }
            VPUSTAT(st);
        }
        while (*(volatile u32 *)0x10003020 & 0xC00) {
            if (cnt++ > 0x4000000) {
                Func235DE0(D_002E5418);
                return -1;
            }
        }
        return 0;
    } else {
        s32 r = 0;
        if (*(volatile u32 *)0x10009000 & 0x80000100) r |= 1;
        if (*(volatile u32 *)0x1000A000 & 0x80000100) r |= 2;
        if (*(volatile u32 *)0x10003C00 & 0x1F000003) r |= 4;
        VPUSTAT(st);
        if (st & 0x100) r |= 8;
        if (*(volatile u32 *)0x10003020 & 0xC00) r |= 0x10;
        return r;
    }
}

extern "C" s32 func_0023A080(s32 f) {
    s32 r;
    if (f == 0) {
        r = func_00239E00(0, 0);
        if (r) {
            Func235DE0(D_002E5440, r);
            func_0026E898();
        }
    } else {
        r = func_00239E00(f, 0);
    }
    return r;
}

extern "C" s32 func_0023A0E8(void) {
    return D_37CA88;
}

INCLUDE_ASM("asm/nonmatchings/Unit237A88", func_0023A0F8);
