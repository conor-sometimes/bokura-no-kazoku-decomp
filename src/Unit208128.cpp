#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
int Func235DE0(const char *, ...);
extern "C" s32 func_00206088(void);
extern "C" s32 func_00207F00(s32, s32);
extern "C" s32 func_00207FA0(s32, s32, s32);
extern "C" s32 func_00208028(s32, s32);
extern "C" s32 func_002080A8(s32, s32);
extern "C" s32 func_002072D8(s32, s32);
struct SeqHdr { u8 m0; u8 m1; u8 pad2[2]; s32 m4; s32 m8; s32 mC; };
extern "C" SeqHdr *func_002092B0(char *, s32);
extern "C" u32 func_00209118(s32 *);
extern "C" s32 func_00209120(s32 *);
extern "C" s32 func_002091F0(char **, s32 *, char *, s32);
extern "C" s32 func_00209250(char **, s32 *, char *, s32);
struct S3121C0 { u32 m0; s32 m4; s32 m8; s32 mC; s32 m10; s32 m14; };
extern S3121C0 D_3121C0[];
extern const char D_002E2F90[];
extern const char D_002E2FB8[];
extern const s32 D_002E2FE8;
extern const s32 D_002E2FF0;

extern "C" s32 func_00209160(char **, s32 *, char *, s32);
extern "C" void func_0020DE28(s32, s32, s32);
extern "C" void *func_0020DED8(void);
extern "C" s32 func_0020DEF0(void);
extern "C" void func_00209928(s32, s32, s32);
extern "C" void func_0020A4A8(s32, s32, s32);
extern "C" void func_002094A0(s32, s32);
extern "C" void func_0020A1E0(s32, s32);
struct Pkt3 { s32 m0; s32 m4; s32 m8; };
struct SeqEnt { SeqEnt *m0; s32 m4; u32 m8; s32 mC; s32 m10; s16 m14; s16 m16; };
struct S3145C0 { SeqEnt m0[32]; SeqEnt *m300; SeqEnt *m304; SeqEnt *m308; s16 m30C; s16 m30E; };
extern S3145C0 D_3145C0;
struct SeEnt { SeEnt *m0; s32 m4; u32 m8; s32 mC; s16 m10; s16 m12; };
struct S3148D0 { SeEnt m0[64]; SeEnt *m500; SeEnt *m504; SeEnt *m508; s16 m50C; s16 m50E; s32 m510; s32 m514; };
extern S3148D0 D_3148D0;

struct PktB { u8 m0; u8 m1; u8 pad2[2]; s32 m4; s16 m8; s16 mA; };

extern "C" void func_00206560(const char *);
extern const char D_002E3130[];
extern const char D_002E3178[];
extern const char D_002E30F8[];

extern "C" s16 func_00206518(void);
extern "C" s16 func_00206528(void);
struct Pkt4s { s32 m0; s32 m4; s16 m8; s16 mA; };
// @decl-end

extern "C" s32 func_00208128(s32 a) {
    func_00207F00(0, a);
    return func_00207F00(1, a);
}

extern "C" s32 func_00208160(s32 a, s32 b) {
    func_00207FA0(0, a, b);
    return func_00207FA0(1, a, b);
}

extern "C" s32 func_002081A8(s32 a) {
    func_00208028(0, a);
    return func_00208028(1, a);
}

extern "C" s32 func_002081E0(s32 a) {
    func_002080A8(0, a);
    return func_002080A8(1, a);
}

extern "C" void func_00208218(void) {
}

extern "C" void func_00208220(void) {
}

extern "C" u32 func_00208228(u8 **pp) {
    u8 *p = *pp;
    u32 v = 0;
    u8 c;
    do {
        c = *p++;
        v = (v << 7) | (c & 0x7F);
    } while (c & 0x80);
    *pp = p;
    return v;
}

INCLUDE_ASM("asm/nonmatchings/Unit208128", func_00208260);
INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E2EE0);
INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E2EE8);
INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E2F10);
INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E2F40);
INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E2F70);

INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E2F90);
INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E2FB8);
INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E2FE8);
INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E2FF0);
INCLUDE_ASM("asm/nonmatchings/Unit208128", func_00208670);

INCLUDE_ASM("asm/nonmatchings/Unit208128", func_002087E8);

INCLUDE_ASM("asm/nonmatchings/Unit208128", func_002088B8);

INCLUDE_ASM("asm/nonmatchings/Unit208128", func_00208948);

extern "C" s32 func_002089D8(s32 a) { return a; }

extern "C" s32 func_002089E0(s32 *p) { return func_00209120(p); }

extern "C" s32 func_002089F8(char **pdata, s32 *psize, char *chunk) {
    SeqHdr *h = func_002092B0(chunk, D_002E2FE8);
    s32 ok;
    if (h && h->m1) {
        *pdata = chunk + ((func_00209120((s32 *)chunk) + 15) & ~15);
        *psize = h->m4;
        ok = 1;
    } else {
        SeqHdr *h2 = func_002092B0(chunk, D_002E2FF0);
        if (h2) {
            *pdata = chunk + h2->m8;
            *psize = h2->mC;
            ok = 1;
        } else {
            *pdata = 0;
            *psize = 0;
            ok = 0;
        }
    }
    return ok;
}

extern "C" char *func_00208AD0(char *chunk) {
    char *data;
    s32 size;
    if (!func_002089F8(&data, &size, chunk)) data = 0;
    return data;
}

extern "C" s32 func_00208B00(char *chunk) {
    char *data;
    s32 size;
    if (!func_002089F8(&data, &size, chunk)) size = 0;
    return size;
}

INCLUDE_ASM("asm/nonmatchings/Unit208128", func_00208B30);
INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E3050);
INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E3058);
INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E3080);

INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E30A0);
INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E30C8);
INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E30F8);
INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E3130);
INCLUDE_ASM("asm/nonmatchings/Unit208128", func_00208E48);

INCLUDE_ASM("asm/nonmatchings/Unit208128", func_00208F98);

INCLUDE_ASM("asm/nonmatchings/Unit208128", func_00209058);

extern "C" s32 func_002090E8(s32 *p) { return func_00209120(p); }

extern "C" void func_00209100(void) {
}

extern "C" void func_00209108(void) {
}

extern "C" s32 func_00209110(s32 *p) { return p[0]; }

extern "C" u32 func_00209118(s32 *p) { return p[1]; }

extern "C" s32 func_00209120(s32 *p) {
    return func_00209118(p) < 0x200 ? p[2] : p[2] + 0x10;
}

extern "C" s32 func_00209160(char **a, s32 *b, char *c, s32 d) {
    if (func_00209118((s32 *)c) < 0x200) return func_002091F0(a, b, c, d);
    return func_00209250(a, b, c, d);
}

INCLUDE_ASM("asm/nonmatchings/Unit208128", func_002091F0);

INCLUDE_ASM("asm/nonmatchings/Unit208128", func_00209250);

extern "C" SeqHdr *func_002092B0(char *chunk, s32 id) {
    char *data;
    s32 size;
    if (!func_00209160(&data, &size, chunk, id)) data = 0;
    return (SeqHdr *)data;
}

extern "C" s32 func_002092E8(char *chunk, s32 id) {
    char *data;
    s32 size;
    if (!func_00209160(&data, &size, chunk, id)) size = 0;
    return size;
}

extern "C" void func_00209320(s32 a, s32 b) {
    SeqEnt *n;
    a = a < -128 ? -128 : (a > 128 ? 128 : a);
    b = b < -128 ? -128 : (b > 128 ? 128 : b);
    D_3145C0.m30C = a;
    D_3145C0.m30E = b;
    for (n = D_3145C0.m300; n; n = n->m0) func_00209928(n->m4, n->m14, n->m16);
}

extern "C" s32 func_002093B8(s32 id, s32 a, s32 b, s32 c) {
    SeqEnt *e = D_3145C0.m308;
    s32 *p;
    if (!e) {
        if (func_00206088() & 4) Func235DE0(D_002E30F8, id);
        return -1;
    }
    e->mC = c;
    e->m14 = a;
    e->m16 = b;
    e->m8 = 3;
    D_3145C0.m308 = e->m0;
    e->m0 = D_3145C0.m300;
    D_3145C0.m300 = e;
    func_0020DE28(0x70, 0, 8);
    p = (s32 *)func_0020DED8();
    p[0] = e->m4;
    p[1] = id;
    func_0020DEF0();
    func_00209928(e->m4, a, b);
    return e->m4;
}

extern "C" void func_002094A0(s32 id, s32 flag) {
    SeqEnt **pp;
    SeqEnt *e;
    func_00206560(D_002E3130);
    pp = &D_3145C0.m300;
    for (;;) {
        e = *pp;
        if (!e) return;
        if (e->m4 == id) {
            Pkt3 *p;
            func_0020DE28(0x71, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 0;
            if (flag) p->m8 = 1;
            else p->m8 = 2;
            func_0020DEF0();
            e->m8 = 0;
            *pp = e->m0;
            e->m0 = D_3145C0.m304;
            D_3145C0.m304 = e;
            return;
        }
        pp = &e->m0;
    }
}

extern "C" void func_00209580(s32 a) {
    s32 i;
    for (i = 0; i < 32; i++) func_002094A0(i, a);
}

extern "C" s32 func_002095D0(u32 i, s32 a, s32 b) {
    if (i < 32) {
        SeqEnt *e = &D_3145C0.m0[i];
        if (e->m8 & 1) {
            Pkt3 *p;
            func_0020DE28(0x71, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 1;
            if (a) {
                if (b) p->m8 = 1;
                else p->m8 = 2;
            } else {
                p->m8 = 0;
            }
            return func_0020DEF0();
        }
    }
}

extern "C" u32 func_00209698(u32 i) {
    if (i < 32) {
        u32 f = D_3145C0.m0[i].m8;
        if (f & 1) return f;
    }
    return 0;
}

extern "C" s32 func_002096D0(u32 i) {
    SeqEnt *e;
    if (i < 32) {
        e = &D_3145C0.m0[i];
        if (e->m8 & 1) goto found;
    }
    return 0;
found:
    return e->m10;
}

extern "C" s32 func_00209710(u32 i, s32 a, s32 b, s32 c) {
    SeqEnt *e = &D_3145C0.m0[i];
    if (i < 32 && (e->m8 & 1)) {
        PktB *p;
        func_0020DE28(0x73, 0, 0xC);
        p = (PktB *)func_0020DED8();
        p->m0 = e->m4;
        p->m1 = a;
        p->m4 = 3;
        p->m8 = b;
        p->mA = c;
        return func_0020DEF0();
    }
}

extern "C" s32 func_002097D0(u32 i, s32 a, s32 b, s32 c) {
    SeqEnt *e = &D_3145C0.m0[i];
    if (i < 32 && (e->m8 & 1)) {
        PktB *p;
        func_0020DE28(0x74, 0, 0xC);
        p = (PktB *)func_0020DED8();
        p->m0 = e->m4;
        p->m1 = a;
        p->m4 = 3;
        p->m8 = b;
        p->mA = c;
        return func_0020DEF0();
    }
}

extern "C" s32 func_00209890(u32 i, s32 v) {
    if (i < 32) {
        SeqEnt *e = &D_3145C0.m0[i];
        if (e->m8 & 1) {
            Pkt3 *p;
            func_0020DE28(0x71, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 2;
            p->m8 = v;
            return func_0020DEF0();
        }
    }
}

extern "C" void func_00209928(s32 i, s32 a, s32 b) {
    if ((u32)i < 32) {
        SeqEnt *e = &D_3145C0.m0[i];
        if (e->m8 & 1) {
            Pkt4s *p;
            s32 x, y;
            a = a < -128 ? -128 : (a > 128 ? 128 : a);
            b = b < -128 ? -128 : (b > 128 ? 128 : b);
            e->m14 = a;
            e->m16 = b;
            x = func_00206518() * D_3145C0.m30C * a >> 14;
            y = func_00206528() * D_3145C0.m30E * b >> 14;
            func_0020DE28(0x71, 0, 0xC);
            p = (Pkt4s *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 3;
            p->m8 = x;
            p->mA = y;
            return (void)func_0020DEF0();
        }
    }
}

extern "C" s32 func_00209A78(u32 i, f32 v) {
    if (i < 32) {
        SeqEnt *e = &D_3145C0.m0[i];
        if (e->m8 & 1) {
            Pkt3 *p;
            s32 x = (s32)(v * 4096.0f);
            func_0020DE28(0x71, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 4;
            p->m8 = x;
            return func_0020DEF0();
        }
    }
}

extern "C" s32 func_00209B20(u32 i, f32 v) {
    if (i < 32) {
        SeqEnt *e = &D_3145C0.m0[i];
        if (e->m8 & 1) {
            Pkt3 *p;
            s32 x = (s32)(v * 4096.0f);
            func_0020DE28(0x71, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 5;
            p->m8 = x;
            return func_0020DEF0();
        }
    }
}

extern "C" s32 func_00209BC8(u32 i, s32 v) {
    if (i < 32) {
        SeqEnt *e = &D_3145C0.m0[i];
        if (e->m8 & 1) {
            Pkt3 *p;
            func_0020DE28(0x71, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 6;
            p->m8 = v;
            return func_0020DEF0();
        }
    }
}

extern "C" void func_00209C60(void) {
    s32 i;
    D_3145C0.m300 = 0;
    D_3145C0.m304 = 0;
    D_3145C0.m308 = 0;
    D_3145C0.m30C = 0x80;
    D_3145C0.m30E = 0x80;
    for (i = 0; i < 32; i++) {
        SeqEnt *e = &D_3145C0.m0[i];
        e->m4 = i;
        e->m0 = D_3145C0.m308;
        D_3145C0.m308 = e;
    }
}

extern "C" void func_00209CB8(void) {
}

INCLUDE_ASM("asm/nonmatchings/Unit208128", func_00209CC0);

extern "C" s16 func_00209E38(void) { return D_3145C0.m30C; }

extern "C" s16 func_00209E48(void) { return D_3145C0.m30E; }

extern "C" void func_00209E58(s32 a, s32 b) {
    SeEnt *n;
    a = a < -128 ? -128 : (a > 128 ? 128 : a);
    b = b < -128 ? -128 : (b > 128 ? 128 : b);
    D_3148D0.m50C = a;
    D_3148D0.m50E = b;
    for (n = D_3148D0.m500; n; n = n->m0) func_0020A4A8(n->m4, n->m10, n->m12);
}

extern "C" void func_00209EF0(s32 v) {
    s32 t = v < -1 ? -1 : (v > 2 ? 2 : v);
    D_3148D0.m510 = t;
}

extern "C" void func_00209F20(s32 v) {
    s32 t = v < -1 ? -1 : (v > 126 ? 126 : v);
    D_3148D0.m514 = t;
}

INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E3140);
INCLUDE_RODATA("asm/nonmatchings/Unit208128", D_002E3178);
INCLUDE_ASM("asm/nonmatchings/Unit208128", func_00209F50);

INCLUDE_ASM("asm/nonmatchings/Unit208128", func_0020A098);

extern "C" void func_0020A1E0(s32 id, s32 flag) {
    SeEnt **pp;
    SeEnt *e;
    func_00206560(D_002E3178);
    pp = &D_3148D0.m500;
    for (;;) {
        e = *pp;
        if (!e) return;
        if (e->m4 == id) {
            Pkt3 *p;
            func_0020DE28(0x82, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 0;
            if (flag) p->m8 = 1;
            else p->m8 = 2;
            func_0020DEF0();
            e->m8 = 0;
            *pp = e->m0;
            e->m0 = D_3148D0.m504;
            D_3148D0.m504 = e;
            return;
        }
        pp = &e->m0;
    }
}

extern "C" void func_0020A2C0(s32 a) {
    s32 i;
    for (i = 0; i < 64; i++) func_0020A1E0(i, a);
}

extern "C" u32 func_0020A310(u32 i) {
    if (i < 64) {
        u32 f = D_3148D0.m0[i].m8;
        if (f & 1) return f;
    }
    return 0;
}

extern "C" s32 func_0020A348(u32 i, s32 a, s32 b) {
    if (i < 64) {
        SeEnt *e = &D_3148D0.m0[i];
        if (e->m8 & 1) {
            Pkt3 *p;
            func_0020DE28(0x82, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 1;
            if (a) p->m8 = b ? 1 : 2;
            else p->m8 = 0;
            return func_0020DEF0();
        }
    }
}
