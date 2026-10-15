#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct HL;
struct NL { void *m0; NL *m4; NL *m8; HL *mC; };
struct HL { NL *m0; NL *m4; NL *m8; s32 mC; s32 m10; s32 m14; };
struct PadSt {
    u8 m0; u8 m1; u16 m2; u16 m4; u16 m6; u16 m8; u16 mA; u16 mC; u16 mE;
    u16 m10; u16 m12; u8 m14; u8 m15; u8 m16; u8 m17; s8 m18[6]; u8 m1E[6]; s16 m24[6];
    u8 m30[16]; s32 m40; s32 m44; s32 m48; s32 m4C; s32 m50; s32 m54;
};
struct PadB { u8 m0; u8 m1; s16 m2; u8 pad4[0xC]; };
struct PadC { u8 m0; u8 m1; u8 pad2[2]; };
extern PadSt D_33FE90[2][4];
extern PadB D_340150[2][4];
extern PadC D_3401D8[2];
extern s32 D_33FE80;
extern s32 D_33FE84;
extern s32 D_33FE88;
extern s32 D_3401D0;
extern "C" s32 func_002359E8(void);
extern "C" void func_002662D0(void);
extern "C" void func_00266660(s32, s32);
extern "C" s32 func_0027E8C8(s32);
extern "C" void func_0027ED10(s32, s32);
extern "C" void func_00266580(s32);
extern "C" s32 func_0027EAA8(void);
extern "C" s32 func_0027F3C0(s32, s32, s32, s32);
extern "C" void func_0027F5B0(s32, s32, u8 *);
extern "C" void func_0022C018(s32, s32);
extern "C" void func_0022C2F0(s32, s32);
extern "C" void func_0022C378(s32, s32);
extern "C" void func_0022C428(void);

#define PCLAMP(id, port, slot) \
    port = id & 0xFF; slot = (id >> 8) & 0xFF; \
    port = port < 0 ? 0 : (port < 2 ? port : 1); \
    slot = slot < 0 ? 0 : (slot < 4 ? slot : 3)

struct FEnt { u8 pad0[4]; u8 m4; u8 pad5[0xCB]; };
struct L10 { L10 *m0; s32 pad[3]; };
struct L18 { L18 *m0; s32 pad[5]; };
struct M10 { s32 m0; M10 *m4; s32 pad[2]; };
struct FSys { FEnt f[64]; L10 m3400[64]; L10 *m3800; L18 m3804[64]; L18 *m3E04; M10 m3E08[256]; M10 *m4E08; };
extern FSys D_3401E0;
extern s32 D_002B8C50;
struct DevOps { s32 m0; s32 (*m4)(s32); s32 (*m8)(s32, s32); };
extern "C" DevOps *func_00230460(s32);
extern "C" void func_00230400(void);
extern "C" void func_002331B8(void);
extern "C" void func_00232840(void);
extern "C" s32 func_001F10C8(void *);
extern "C" void func_001F1150(void *);
extern "C" void func_002328E8(void);
extern "C" void func_002331E0(void);
extern "C" s32 func_00230438(void);
extern "C" s32 func_0022DB50(void);
extern "C" s32 func_002328F0(void);
extern "C" s32 func_0022D9D8(void);
extern "C" void func_0022DDE8(s32);
extern "C" s32 func_00232958(void);
extern "C" s32 func_00232A50(void);
extern "C" s32 func_00232A70(void);
extern "C" s32 func_00232B78(s32, s32);
extern "C" s32 func_00232C40(s32);
extern "C" s32 func_00232C60(s32, s32);
extern "C" s32 func_00232D90(s32);
extern "C" s32 func_00232DA8(s32);
extern "C" s32 func_00232E30(s32);
extern "C" s32 func_00232EC8(s32);
extern "C" s32 func_00232EE8(s32, s32);
extern "C" s32 func_0022E8E0(s32, s32, s32, s32, s32);
extern "C" s32 func_0022EA08(s32, s32, s32, s32, s32, s32);
extern "C" s32 func_0022EF38(s32, s32);
// @decl-end

extern "C" void func_0022BFD0(NL *n) {
    HL *h;
    n->m4 = 0;
    h = n->mC;
    n->m8 = h->m0;
    if (h->m0) h->m0->m4 = n;
    h->m0 = n;
    h->m10++;
}

extern "C" s32 func_0022C000(NL **a, NL **b) {
    return (s32)(*a)->m0 - (s32)(*b)->m0;
}

extern "C" void func_0022C018(s32 port, s32 slot) {
    D_33FE90[port][slot].mE = func_002359E8() * 40;
    D_33FE90[port][slot].m10 = func_002359E8() * 8;
    D_33FE90[port][slot].m12 = 0;
    D_33FE90[port][slot].mC = 0;
    D_33FE90[port][slot].mA = 0;
}

extern "C" void func_0022C0C0(void) {
    s32 port, slot;
    if (D_3401D0) {
        func_002662D0();
        func_00266660(0x28, 0xA);
    }
    func_0027E8C8(0);
    for (port = 0; port < 2; port++) {
        for (slot = 0; slot < 4; slot++) {
            D_33FE90[port][slot].m0 = 0;
            D_33FE90[port][slot].m16 = 1;
            func_0022C018(port, slot);
        }
    }
    for (port = 0; port < 2; port++) {
        D_3401D8[port].m0 = 0;
        D_3401D8[port].m1 = 0;
    }
    D_33FE84 = 1;
    D_33FE88 = 1;
    D_33FE80 = port;
    return func_0022C428();
}

extern "C" s32 func_0022C1D0(void) {
    s32 port, slot;
    PadC *c;
    for (port = 0; port < 2; port++) {
        for (slot = 0; slot < 4; slot++) {
            if (D_33FE90[port][slot].m0) {
                func_0027ED10(port, slot);
                D_33FE90[port][slot].m0 = 0;
            }
        }
    }
    for (port = 0; port < 2; port++) {
        c = &D_3401D8[port];
        if (c->m1) {
            func_00266580(port);
            c->m1 = 0;
        }
        c->m0 = 0;
    }
    return func_0027EAA8();
}

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", func_0022C2A8);

extern "C" s32 func_0022C2D8(void) {
    return D_33FE80;
}

extern "C" void func_0022C2E8(void) {
}

extern "C" void func_0022C2F0(s32 port, s32 slot) {
    PadSt *p = &D_33FE90[port][slot];
    s32 i;
    p->m14 = 0;
    p->m15 = 0;
    for (i = 0; i < 6; i++) {
        p->m18[i] = -1;
        p->m1E[i] = 0;
        p->m24[i] = 0;
    }
}

extern "C" void func_0022C378(s32 port, s32 slot) {
    PadSt *p = &D_33FE90[port][slot];
    s32 i;
    p->m2 = -1;
    p->m1 = 0;
    p->m4 = 0;
    p->m6 = 0;
    p->m8 = 0;
    p->m17 = 0;
    for (i = 15; i >= 0; i--) p->m30[i] = 0;
    p->m44 = 0;
    p->m30[0] = 0x80;
    p->m30[1] = 0x80;
    p->m30[2] = 0x80;
    p->m40 = 0;
    p->m30[3] = 0x80;
    return func_0022C2F0(port, slot);
}

extern "C" void func_0022C428(void) {
    s32 port, slot;
    for (port = 0; port < 2; port++) {
        for (slot = 0; slot < 4; slot++) {
            func_0022C378(port, slot);
            D_340150[port][slot].m2 = 0;
            D_340150[port][slot].m1 = 6;
            D_340150[port][slot].m0 = 0;
        }
    }
}

extern "C" s32 func_0022C4B8(s32 a, s32 b) {
    s32 r = func_0027F3C0(a, b, 1, 0);
    s32 t;
    if (r) {
        t = func_0027F3C0(a, b, 2, 0);
        if (t > 0) r = t;
    }
    return r;
}

extern "C" s32 func_0022C528(s32 n) {
    s32 r = 0;
    if (n == 6 || n == 2) r = 1;
    return r;
}

extern "C" void func_0022C550(s32 port, s32 slot) {
    PadSt *p = &D_33FE90[port][slot];
    if (p->m14 && p->m15) {
        func_0027F5B0(port, slot, p->m1E);
        p->m15 = 0;
    }
}

extern "C" void func_0022C5D0(s32 port, s32 slot) {
    PadSt *p = &D_33FE90[port][slot];
    s32 i;
    if (p->m14) {
        for (i = 0; i < p->m14; i++) {
            if (p->m24[i] > 0) p->m24[i]--;
            if (p->m24[i] == 0 && p->m1E[i]) {
                p->m1E[i] = 0;
                p->m15 = 1;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", func_0022C680);

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", func_0022C728);

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", func_0022CAB0);

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", Func22D008__Fi);

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", Func22D0A0__Fi);

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", Func22D138__Fi);

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", Func22D1D0__Fi);

extern "C" void func_0022D268(void) {
    s32 port, slot, l, t, r, b, x, y;
    PadSt *p;
    for (port = 0; port < D_33FE80; port++) {
        for (slot = 0; slot < 4; slot++) {
            p = &D_33FE90[port][slot];
            l = p->m48;
            t = p->m4C;
            r = l + p->m50 - 1;
            b = t + p->m54 - 1;
            x = p->m40;
            y = p->m44;
            if (x < r) r = x;
            if (y < b) b = y;
            if (r < l) r = l;
            if (b < t) b = t;
            p->m40 = r;
            p->m44 = b;
        }
    }
}

extern "C" void func_0022D310(s32 a, s32 b, s32 c, s32 d) {
    D_33FE90[0][0].m48 = a;
    D_33FE90[0][0].m4C = b;
    D_33FE90[0][0].m50 = c;
    D_33FE90[0][0].m54 = d;
}

extern "C" void func_0022D330(s32 x, s32 y) {
    D_33FE90[0][0].m40 = x;
    D_33FE90[0][0].m44 = y;
    return func_0022D268();
}

extern "C" void func_0022D358(s32 *x, s32 *y, s32 *a, s32 *b) {
    *x = D_33FE90[0][0].m40;
    *y = D_33FE90[0][0].m44;
    *a = (D_33FE90[0][0].m2 >> 2) & 1;
    *b = (D_33FE90[0][0].m2 >> 3) & 1;
}

extern "C" void func_0022D398(s32 *a, s32 *b, s32 *c, s32 *d) {
    *a = D_33FE90[0][0].m30[2];
    *b = D_33FE90[0][0].m30[3];
    *c = D_33FE90[0][0].m30[0];
    *d = D_33FE90[0][0].m30[1];
}

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", func_0022D3C8);

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", func_0022D480);

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", func_0022D538);

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", func_0022D6B0);

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", func_0022D7E0);

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", func_0022D8C0);

extern "C" s32 func_0022D958(s32 v) {
    s32 old = D_33FE84;
    D_33FE84 = v;
    return old;
}

extern "C" s32 func_0022D970(s32 v) {
    s32 old = D_33FE88;
    D_33FE88 = v;
    return old;
}

extern "C" void func_0022D988(void) {
    D_3401D0 = 1;
}

extern "C" u8 func_0022D998(s32 port) {
    port = port < 0 ? 0 : (port < 2 ? port : 1);
    return D_3401D8[port].m0;
}

extern "C" s32 func_0022D9D8(void) {
    return func_0022DB50();
}

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", func_0022D9F0);

extern "C" s32 func_0022DAE0(void) {
    s32 i;
    for (i = 0; i < 64; i++) func_0022DDE8(i);
    func_001F1150((void *)func_0022D9D8);
    func_002328E8();
    func_002331E0();
    return func_00230438();
}

extern "C" s32 func_0022DB38(s32 v) {
    s32 old = D_002B8C50;
    D_002B8C50 = v;
    return old;
}

extern "C" s32 func_0022DB50(void) {
    return func_002328F0();
}

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", func_0022DB68);

INCLUDE_ASM("asm/nonmatchings/Unit22BFD0", func_0022DBB8);

extern "C" s32 func_0022DBF8(void) {
    return func_00232958();
}

extern "C" s32 func_0022DC10(void) {
    return func_00232A50();
}

extern "C" s32 func_0022DC28(void) {
    return func_00232A70();
}

extern "C" s32 func_0022DC40(s32 x) {
    return func_00232B78(func_00232A50(), x);
}

extern "C" s32 func_0022DC70(void) {
    return func_00232C40(func_00232A50());
}

extern "C" s32 func_0022DC90(s32 x) {
    return func_00232C60(func_00232A50(), x);
}

extern "C" s32 func_0022DCC0(void) {
    return func_00232D90(func_00232A50());
}

extern "C" s32 func_0022DCE0(void) {
    return func_00232DA8(func_00232A50());
}

extern "C" s32 func_0022DD00(void) {
    return func_00232E30(func_00232A50());
}

extern "C" s32 func_0022DD20(void) {
    return func_00232EC8(func_00232A50());
}

extern "C" s32 func_0022DD40(s32 x) {
    return func_00232EE8(func_00232A50(), x);
}

extern "C" void func_0022DD70(void) {
}

extern "C" s32 func_0022DD78(s32 a, s32 b) {
    return func_0022E8E0(a, b, 0, 0, 0);
}

extern "C" s32 func_0022DD98(s32 a, s32 b, s32 c, s32 d) {
    return func_0022E8E0(a, 0x18001, b, c, d);
}

extern "C" s32 func_0022DDC8(s32 a, s32 b, s32 c) {
    return func_0022EA08(a, b, c, 0, 0, 0);
}

extern "C" void func_0022DDE8(s32 fd) {
    FEnt *f;
    if ((u32)(fd - 1) < 0x3F && (f = &D_3401E0.f[fd])->m4) return (void)func_0022EF38((s32)f, 0);
}
