#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" s32 func_0020A748(s32, s32, s32);
extern "C" void func_0020DE28(s32, s32, s32);
extern "C" void *func_0020DED8(void);
extern "C" s32 func_0020DEF0(void);
extern "C" void func_0020AF80(s32);
extern "C" void func_0020C100(s32);
extern "C" s32 func_0020BDF0(s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 func_0020C280(s32, s32);
struct Pkt3 { s32 m0; s32 m4; s32 m8; };
struct SeEnt { SeEnt *m0; s32 m4; u32 m8; s32 mC; s16 m10; s16 m12; };
struct S3148D0 { SeEnt m0[64]; SeEnt *m500; s32 m504; SeEnt *m508; s16 m50C; s16 m50E; s32 m510; s32 m514; };
extern S3148D0 D_3148D0;
struct StrmEnt { StrmEnt *m0; s32 m4; s32 m8; s32 mC; s32 m10; s32 m14; u8 m18; u8 pad19[3]; s16 m1C; s16 m1E; s32 m20; s32 m24; s32 m28; s32 m2C; s32 m30; s32 m34; struct Node20 *m38; };
extern StrmEnt D_316204[32];
extern s16 D_316990;
extern s16 D_316992;
inline u8 Used(StrmEnt *e) { return e->m18 & 1; }
struct VoiceEnt { s32 m0; s32 m4; u8 m8; u8 m9; u8 padA[2]; s32 mC[14]; };
struct S318DC4 { VoiceEnt m0[48]; s32 mCC0; s32 mCC4; s32 mCC8; s32 mCCC; s32 mCD0; s32 mCD4; };
extern S318DC4 D_318DC4;
inline u8 Used(VoiceEnt *e) { return e->m9 & 1; }

extern "C" void func_0020B8C8(s32, s32, s32);
extern "C" void func_0020D118(s32, s32, s32);
struct Node20 { Node20 *m0; s32 m4; s32 m8; s32 mC; s32 m10; };
struct S314E00 { Node20 m0[256]; Node20 *m1400; StrmEnt m1404[32]; StrmEnt *m1B84; StrmEnt *m1B88; StrmEnt *m1B8C; s16 m1B90; s16 m1B92; };
extern S314E00 D_314E00;
struct VoiceHdr { VoiceHdr *m0; s32 m4; u8 m8; u8 m9; u8 padA[2]; s32 mC; s32 m10; s16 m14; s16 m16; s32 m18[10]; struct Node20 *m40; };
struct S3179C0 { Node20 m0[256]; Node20 *m1400; VoiceHdr m1404[48]; VoiceHdr *m20C4; VoiceHdr *m20C8; VoiceHdr *m20CC; s16 m20D0; s16 m20D2; };
extern S3179C0 D_3179C0;
struct Pkt4 { s32 m0; s32 m4; s16 m8; s16 mA; };

struct VoiceX { s32 m0; s32 m4; u8 m8; u8 m9; u8 padA[2]; u8 mC; u8 padD[3]; s32 m10; s32 m14; s32 m18; s32 m1C; s32 m20; };

extern "C" void func_00206560(const char *);
extern const char D_002E3208[];
extern const char D_002E32D8[];

extern "C" s16 func_00206518(void);
extern "C" s16 func_00206528(void);
struct Pkt4s { s32 m0; s32 m4; s16 m8; s16 mA; };

extern u16 D_3169C0[];
extern "C" u16 *func_00206538(void);
extern "C" void func_0020B160(u32 i, u16 *a, u16 *b, s32 n);

struct S316200 { Node20 *free; StrmEnt e[32]; };
extern S316200 D_316200;

inline u8 Flags(StrmEnt *e) { return e->m18; }
inline u8 Flags(VoiceEnt *e) { return e->m9; }
// @decl-end

extern "C" s32 func_0020A410(u32 i, s32 v) {
    if (i < 64) {
        SeEnt *e = &D_3148D0.m0[i];
        if (e->m8 & 1) {
            Pkt3 *p;
            func_0020DE28(0x82, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 2;
            p->m8 = v;
            return func_0020DEF0();
        }
    }
}

extern "C" void func_0020A4A8(s32 i, s32 a, s32 b) {
    if ((u32)i < 64) {
        SeEnt *e = &D_3148D0.m0[i];
        if (e->m8 & 1) {
            Pkt4s *p;
            s32 x, y;
            a = a < -128 ? -128 : (a > 128 ? 128 : a);
            b = b < -128 ? -128 : (b > 128 ? 128 : b);
            e->m10 = a;
            e->m12 = b;
            x = func_00206518() * D_3148D0.m50C * a >> 14;
            y = func_00206528() * D_3148D0.m50E * b >> 14;
            func_0020DE28(0x82, 0, 0xC);
            p = (Pkt4s *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 3;
            p->m8 = x;
            p->mA = y;
            return (void)func_0020DEF0();
        }
    }
}

extern "C" s32 func_0020A5F8(u32 i, f32 v) {
    if (i < 64) {
        SeEnt *e = &D_3148D0.m0[i];
        if (e->m8 & 1) {
            Pkt3 *p;
            s32 x = (s32)(v * 4096.0f);
            func_0020DE28(0x82, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 4;
            p->m8 = x;
            return func_0020DEF0();
        }
    }
}

extern "C" s32 func_0020A6A0(u32 i, f32 v) {
    if (i < 64) {
        SeEnt *e = &D_3148D0.m0[i];
        if (e->m8 & 1) {
            Pkt3 *p;
            s32 x = (s32)(v * 4096.0f);
            func_0020DE28(0x82, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 5;
            p->m8 = x;
            return func_0020DEF0();
        }
    }
}

extern "C" s32 func_0020A748(s32 i, s32 k, s32 v) {
    if ((u32)i < 64) {
        SeEnt *e = &D_3148D0.m0[i];
        if (e->m8 & 1) {
            Pkt3 *p;
            func_0020DE28(0x82, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = k;
            p->m8 = v;
            return func_0020DEF0();
        }
    }
}

extern "C" s32 func_0020A7E8(s32 a, s32 v) {
    return func_0020A748(a, 6, v < 0 ? 0 : (v > 128 ? 128 : v));
}

extern "C" s32 func_0020A828(s32 a, s32 v) {
    return func_0020A748(a, 7, v < 0 ? 0 : (v > 128 ? 128 : v));
}

extern "C" s32 func_0020A868(s32 a, s32 v) {
    return func_0020A748(a, 8, v < 0 ? 0 : (v > 128 ? 128 : v));
}

extern "C" s32 func_0020A8A8(s32 a, s32 v) {
    return func_0020A748(a, 9, v < 0 ? 0 : (v > 128 ? 128 : v));
}

extern "C" s32 func_0020A8E8(s32 a, f32 x) {
    s32 v = (s32)((x + 1.0f) * 128.0f);
    return func_0020A748(a, 10, v < 0 ? 0 : (v > 255 ? 255 : v));
}

extern "C" s32 func_0020A948(s32 a, s32 v) {
    if (v >= 0) return func_0020A748(a, 11, v < -1 ? -1 : (v > 2 ? 2 : v));
}

extern "C" s32 func_0020A9A0(s32 a, s32 v) {
    if (v >= 0) return func_0020A748(a, 12, v < -1 ? -1 : (v > 126 ? 126 : v));
}

extern "C" void func_0020A9F8(void) {
    s32 i;
    D_3148D0.m500 = 0;
    D_3148D0.m504 = 0;
    D_3148D0.m508 = 0;
    D_3148D0.m50C = 0x80;
    D_3148D0.m50E = 0x80;
    D_3148D0.m510 = -1;
    D_3148D0.m514 = -1;
    for (i = 0; i < 64; i++) {
        SeEnt *e = &D_3148D0.m0[i];
        e->m4 = i;
        e->m0 = D_3148D0.m508;
        D_3148D0.m508 = e;
    }
}

extern "C" void func_0020AA58(void) {
}

INCLUDE_ASM("asm/nonmatchings/Unit20A410", func_0020AA60);

extern "C" s16 func_0020ABD0(void) { return D_3148D0.m50C; }

extern "C" s16 func_0020ABE0(void) { return D_3148D0.m50E; }

extern "C" void func_0020ABF0(s32 a, s32 b) {
    StrmEnt *n;
    a = a < -128 ? -128 : (a > 128 ? 128 : a);
    b = b < -128 ? -128 : (b > 128 ? 128 : b);
    D_314E00.m1B90 = a;
    D_314E00.m1B92 = b;
    for (n = D_314E00.m1B84; n; n = n->m0) func_0020B8C8(n->m4, n->m1C, n->m1E);
}

extern "C" s32 func_0020AC88(s32 flag) {
    Pkt3 *p;
    func_0020DE28(0x31, 0, 0xC);
    p = (Pkt3 *)func_0020DED8();
    p->m8 = 0xFCC;
    p->m0 = 0;
    p->m4 = 0;
    if (flag) p->m8 = 0xFFC;
    return func_0020DEF0();
}

extern "C" s32 func_0020ACE0(s32 flag) {
    Pkt4 *p;
    func_0020DE28(0x31, 0, 0xC);
    p = (Pkt4 *)func_0020DED8();
    p->m4 = 2;
    p->m0 = 0;
    p->m8 = flag ? 0 : 0x7FFF;
    p->mA = flag ? 0 : 0x7FFF;
    return func_0020DEF0();
}

extern "C" s32 func_0020AD50(s32 v) {
    s32 *p;
    func_0020DE28(0xB4, 0, 4);
    p = (s32 *)func_0020DED8();
    *p = v;
    return func_0020DEF0();
}

INCLUDE_ASM("asm/nonmatchings/Unit20A410", func_0020AD90);
INCLUDE_RODATA("asm/nonmatchings/Unit20A410", D_002E3208);

extern "C" void func_0020AF80(s32 id) {
    StrmEnt **pp;
    StrmEnt *e;
    func_00206560(D_002E3208);
    for (pp = &D_314E00.m1B84; (e = *pp) != 0; pp = &e->m0) {
        if (e->m4 == id) {
            Pkt3 *p;
            Node20 *n;
            func_0020DE28(0xB2, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 0;
            p->m8 = 0;
            func_0020DEF0();
            while ((n = e->m38) != 0) {
                e->m38 = n->m0;
                n->m0 = D_314E00.m1400;
                D_314E00.m1400 = n;
            }
            e->m18 = 0;
            *pp = e->m0;
            e->m0 = D_314E00.m1B88;
            D_314E00.m1B88 = e;
            return;
        }
    }
}

extern "C" void func_0020B078(void) {
    s32 i;
    for (i = 0; i < 32; i++) func_0020AF80(i);
}

extern "C" u8 func_0020B0B8(u32 i) {
    StrmEnt *e;
    if (i < 32 && Used(e = &D_316204[i])) goto found;
    return 0;
found:
    return Flags(e);
}

extern "C" s32 func_0020B100(u32 i) {
    StrmEnt *e;
    if (i < 32) {
        e = &D_316204[i];
        if (Used(e)) goto found;
    }
    return 0;
found:
    return (e->m10 - e->m20) * e->m14 - e->m2C;
}

INCLUDE_ASM("asm/nonmatchings/Unit20A410", func_0020B160);

extern "C" void func_0020B448(u32 i) {
    StrmEnt *e;
    u16 *buf;
    s32 n;
    if (i < 32) {
        e = &D_316204[i];
        if (Used(e)) {
            if (e->pad19[0] == 3) {
                s32 k;
                u16 *p = D_3169C0;
                for (k = 1023; k >= 0; k--) {
                    p[0] = ((u16 *)&e->m34)[1];
                    p[1] = ((u16 *)&e->m34)[0];
                    p += 2;
                }
                buf = D_3169C0;
            } else {
                buf = func_00206538();
            }
            if (e->m2C > 0) {
                n = 0x1000 - e->m2C;
                while (n > 0) {
                    s32 c = n > 0x1000 ? 0x1000 : n;
                    func_0020B160(i, buf, buf, c);
                    n -= c;
                }
            }
            {
                Pkt3 *pk;
                func_0020DE28(0xB2, 0, 0xC);
                pk = (Pkt3 *)func_0020DED8();
                pk->m0 = e->m4;
                pk->m4 = 5;
                pk->m8 = 0;
                return (void)func_0020DEF0();
            }
        }
    }
}

extern "C" s32 func_0020B5A0(u32 i, s32 off, s32 x, s32 y) {
    StrmEnt *e;
    Node20 *nd;
    Node20 *cur;
    Node20 **pp;
    s32 a, b, t;
    if (i < 32) {
        e = &D_316200.e[i];
        if (Used(e) && (nd = D_316200.free)) goto found;
    }
    return 0;
found:
    t = e->pad19[0];
    switch (t) {
    case 0:
        a = e->m30 + (e->m2C + off) / e->m14;
        b = (e->m2C + off) % e->m14;
        break;
    case 1:
    case 2:
    case 3:
        a = e->m30 + (e->m2C + off) / e->m14;
        b = (e->m2C + off) % e->m14 / 2;
        break;
    default:
        a = 0;
        b = 0;
        break;
    }
    nd->mC = x;
    nd->m10 = y;
    nd->m4 = a;
    nd->m8 = b;
    D_316200.free = nd->m0;
    for (pp = &e->m38; (cur = *pp); pp = &cur->m0) {
        if (nd->m4 < cur->m4) break;
        if (nd->m4 == cur->m4 && nd->m8 < cur->m8) break;
    }
    nd->m0 = cur;
    *pp = nd;
    return 1;
}

extern "C" s32 func_0020B6F8(u32 i, s32 v) {
    StrmEnt *e;
    if (i < 32) {
        e = &D_316204[i];
        if (Used(e)) goto found;
    }
    return 0;
found:
    {
        s32 old = e->m8;
        e->m8 = v;
        return old;
    }
}

extern "C" s32 func_0020B740(u32 i) {
    StrmEnt *e;
    if (i < 32) {
        e = &D_316204[i];
        if (Used(e)) goto found;
    }
    return 0;
found:
    return e->m8;
}

extern "C" s32 func_0020B788(u32 i, s32 v) {
    if (i < 32) {
        StrmEnt *e = &D_316204[i];
        if (Used(e)) {
            Pkt3 *p;
            e->m34 = v;
            func_0020DE28(0xB2, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 2;
            p->m8 = v;
            return func_0020DEF0();
        }
    }
}

extern "C" s32 func_0020B828(u32 i, s32 v) {
    if (i < 32) {
        StrmEnt *e = &D_316204[i];
        if (Used(e)) {
            Pkt3 *p;
            func_0020DE28(0xB2, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 1;
            p->m8 = v;
            return func_0020DEF0();
        }
    }
}

extern "C" void func_0020B8C8(s32 i, s32 a, s32 b) {
    if ((u32)i < 32) {
        StrmEnt *e = &D_316204[i];
        if (Used(e)) {
            Pkt4s *p;
            s32 x, y;
            a = a < -128 ? -128 : (a > 128 ? 128 : a);
            b = b < -128 ? -128 : (b > 128 ? 128 : b);
            e->m1C = a;
            e->m1E = b;
            x = func_00206518() * D_314E00.m1B90 * e->m1C >> 14;
            y = func_00206528() * D_314E00.m1B92 * e->m1E >> 14;
            func_0020DE28(0xB2, 0, 0xC);
            p = (Pkt4s *)func_0020DED8();
            p->m0 = e->m4;
            p->m4 = 4;
            p->m8 = x;
            p->mA = y;
            return (void)func_0020DEF0();
        }
    }
}

extern "C" void func_0020B9F0(void) {
    s32 i;
    Node20 *n;
    StrmEnt *e;
    D_314E00.m1400 = 0;
    for (i = 0, n = D_314E00.m0; i < 256; i++, n++) {
        n->m0 = D_314E00.m1400;
        D_314E00.m1400 = n;
    }
    D_314E00.m1B84 = 0;
    D_314E00.m1B88 = 0;
    D_314E00.m1B8C = 0;
    D_314E00.m1B90 = 0x80;
    D_314E00.m1B92 = 0x80;
    for (i = 0, e = D_314E00.m1404; i < 32; i++, e++) {
        e->m4 = i;
        e->m18 = 0;
        e->m0 = D_314E00.m1B8C;
        D_314E00.m1B8C = e;
    }
}

extern "C" void func_0020BA80(void) {
}

INCLUDE_ASM("asm/nonmatchings/Unit20A410", func_0020BA88);

extern "C" s16 func_0020BC98(void) { return D_316990; }

extern "C" s16 func_0020BCA8(void) { return D_316992; }

extern "C" void func_0020BCB8(s32 a, s32 b) {
    VoiceHdr *n;
    a = a < -128 ? -128 : (a > 128 ? 128 : a);
    b = b < -128 ? -128 : (b > 128 ? 128 : b);
    D_3179C0.m20D0 = a;
    D_3179C0.m20D2 = b;
    for (n = D_3179C0.m20C4; n; n = n->m0) func_0020D118(n->m8, n->m14, n->m16);
}

extern "C" void func_0020BD50(s32 v) {
    s32 t = v < 0 ? 0 : (v > 2 ? 2 : v);
    D_318DC4.mCD0 = t;
}

extern "C" void func_0020BD80(s32 v) {
    s32 t = v < 0 ? 0 : (v > 127 ? 127 : v);
    D_318DC4.mCD4 = t;
}

extern "C" s32 func_0020BDB0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    return func_0020BDF0(a, b, c, d << 10, e, f << 10, -1);
}

extern "C" s32 func_0020BDD0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g) {
    return func_0020BDF0(a, b, c, d << 10, e, f << 10, g);
}

INCLUDE_ASM("asm/nonmatchings/Unit20A410", func_0020BDF0);
INCLUDE_RODATA("asm/nonmatchings/Unit20A410", D_002E32D8);

extern "C" void func_0020C100(s32 id) {
    VoiceHdr **pp;
    VoiceHdr *e;
    func_00206560(D_002E32D8);
    for (pp = &D_3179C0.m20C4; (e = *pp) != 0; pp = &e->m0) {
        if (e->m8 == id) {
            Pkt3 *p;
            Node20 *n;
            func_0020DE28(0xA2, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m8;
            p->m4 = 0;
            p->m8 = 0;
            func_0020DEF0();
            while ((n = e->m40) != 0) {
                e->m40 = n->m0;
                n->m0 = D_3179C0.m1400;
                D_3179C0.m1400 = n;
            }
            e->m9 = 0;
            *pp = e->m0;
            e->m0 = D_3179C0.m20C8;
            D_3179C0.m20C8 = e;
            return;
        }
    }
}

extern "C" void func_0020C1F8(void) {
    s32 i;
    for (i = 0; i < 48; i++) func_0020C100(i);
}

extern "C" u8 func_0020C238(u32 i) {
    VoiceEnt *e;
    if (i < 48 && Used(e = &D_318DC4.m0[i])) goto found;
    return 0;
found:
    return Flags(e);
}

extern "C" s32 func_0020C280(s32 i, s32 flag) {
    VoiceX *e;
    s32 t;
    s32 r;
    if ((u32)i < 48) {
        e = (VoiceX *)&D_318DC4.m0[i];
        if (Used((VoiceEnt *)e)) goto found;
    }
    return 0;
found:
    t = e->m4;
    r = e->m1C - e->m20;
    switch (t) {
    case 0:
        break;
    case 1:
    case 2:
        r <<= 1;
        break;
    case 0x1000000:
        r = r * e->mC;
        break;
    }
    if (!flag) r -= e->mC << 7;
    return r;
}

extern "C" s32 func_0020C320(s32 a) { return func_0020C280(a, 0); }

INCLUDE_ASM("asm/nonmatchings/Unit20A410", func_0020C338);
