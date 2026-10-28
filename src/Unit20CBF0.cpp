#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" char *strcpy(char *dst, const char *src);
extern "C" void *memset(void *dst, int c, unsigned int n);
extern "C" s32 func_0020C338(s32, s32, s32, s32, s32);
extern "C" s32 func_002731A0(void *);
extern "C" s32 func_002731B0(s32);
extern "C" void func_002731D0(s32);
extern "C" s32 func_0020DA30(void *, s32);
extern "C" s32 func_0020DB28(void *);
extern "C" void func_001F15F0(void);
extern "C" void func_001F1610(void);
extern "C" s32 func_0020ED38(s32);
extern "C" const char *func_0020EE20(s32, s32);
extern "C" s32 func_0020EE98(s32);
extern "C" s32 func_0020EFB8(s32);
struct StrmInfo { u8 m0; u8 m1; u8 pad2[6]; u8 m8; u8 m9; u16 mA; s32 mC; s32 m10; s32 m14; s32 m18; };
extern "C" StrmInfo *func_0020EBF8(s32);
struct NameEnt { s32 m0; s32 m4; s32 m8; char mC[1]; };
extern "C" NameEnt *func_0020EF18(s32);
extern "C" NameEnt *func_0020F038(s32);
extern "C" void *func_0020E808(u32, s32, s32);
extern "C" s32 func_0020E458(s32);
extern "C" const char *func_0020E470(s32, s32);
struct E808 { s32 m0; s32 m4; u8 m8[1]; };
extern "C" void *func_0020E798(u32, s32);
struct VoiceEnt { s32 m0; s32 m4; u8 m8; u8 m9; u8 padA[2]; s32 mC; s32 m10; s32 m14[12]; };
struct S318DC4 { VoiceEnt m0[48]; s32 mCC0; s32 mCC4; s32 mCC8; s16 mCCC; s16 mCCE; s32 mCD0; s32 mCD4; };
extern S318DC4 D_318DC4;
inline u8 Used(VoiceEnt *e) { return e->m9 & 1; }
struct BankEnt { u8 m0; u8 m1; u8 m2; u8 m3; s32 m4; s32 m8; s32 mC; s32 m10; s32 m14; s32 *m18; s32 m1C; s32 m20; s32 m24; char m28[0x40]; char m68[0x40]; };
extern BankEnt D_324B00[256];
extern s32 D_002A6180;
extern s32 D_002A6184;
extern s32 D_002A6188;
extern u8 D_322AC0[];
extern u8 D_322B00[];
extern u8 D_322B0C[];
extern u8 D_323B00[];
extern const char D_002E33F0[];
extern "C" BankEnt *func_0020E758(u32);

extern "C" void func_0020DE28(s32, s32, s32);
extern "C" void func_0020DF38(void);
extern "C" void func_0020DEF0(void);
extern "C" u8 *func_0020DED8(void);
extern "C" void func_0020DB78(void *, s32, void *, s32, void *, s32);
extern "C" s32 func_0022DC10(void);
extern "C" const char *func_0022DCC0(void);
struct Pkt3 { s32 m0; s32 m4; s32 m8; };
struct Node20 { Node20 *m0; s32 m4; s32 m8; s32 mC; s32 m10; };
struct S3179C0 { Node20 m0[256]; Node20 *m1400; VoiceEnt m1404[48]; s32 m20C4; s32 m20C8; VoiceEnt *m20CC; s16 m20D0; s16 m20D2; s32 m20D4; s32 m20D8; };
extern S3179C0 D_3179C0;

extern "C" int strcmp(const char *, const char *);
struct Pkt3h { s16 m0; s16 m2; s32 m4; s32 m8; };

extern "C" s32 func_002762A8(void *cl);
extern "C" s32 func_00273420(s32 a);
extern "C" s32 func_002760B0(void *cl, s32 fno, s32 mode, void *send, s32 ssize, void *recv, s32 rsize, void *end, void *para);
extern "C" s32 func_00275EE0(void *cl, s32 id, s32 mode);
extern "C" s32 func_00206088(void);
extern "C" void func_00206548(void);
extern "C" s32 func_0020D9E0(s32 a, s32 b);
int Func235DE0(const char *fmt, ...);

struct PktVP { s16 m0; s16 m2; s32 m4; s16 m8; s16 mA; };
// @decl-end

extern "C" s32 func_0020CBF0(s32 a, s32 b, s32 c, s32 d) { return func_0020C338(a, b, c, d, 0); }

INCLUDE_ASM("asm/nonmatchings/Unit20CBF0", func_0020CC08);

INCLUDE_ASM("asm/nonmatchings/Unit20CBF0", func_0020CDF0);

extern "C" s32 func_0020CF48(u32 i, s32 v) {
    VoiceEnt *e;
    if (i < 48) {
        e = &D_318DC4.m0[i];
        if (Used(e)) goto found;
    }
    return 0;
found:
    {
        s32 old = e->m10;
        e->m10 = v;
        return old;
    }
}

extern "C" s32 func_0020CF90(u32 i) {
    VoiceEnt *e;
    if (i < 48) {
        e = &D_318DC4.m0[i];
        if (Used(e)) goto found;
    }
    return 0;
found:
    return e->m10;
}

extern "C" void func_0020CFD8(u32 i, s32 v) {
    if (i < 48) {
        VoiceEnt *e = &D_318DC4.m0[i];
        if (Used(e)) {
            Pkt3 *p;
            func_0020DE28(0xA2, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m8;
            p->m4 = 1;
            p->m8 = v;
            func_0020DEF0();
            return;
        }
    }
}

extern "C" void func_0020D078(u32 i, s32 v) {
    if (i < 48) {
        VoiceEnt *e = &D_318DC4.m0[i];
        if (Used(e)) {
            Pkt3 *p;
            func_0020DE28(0xA2, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m8;
            p->m4 = 2;
            p->m8 = v;
            func_0020DEF0();
            return;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit20CBF0", func_0020D118);

extern "C" void func_0020D2B8(u32 i, s32 k, s32 a, s32 b) {
    VoiceEnt *e;
    if (i < 48) {
        e = &D_318DC4.m0[i];
        if (Used(e) && k >= 0 && k <= *(u8 *)&e->mC - 1) {
            PktVP *p;
            a = a < -128 ? -128 : (a > 128 ? 128 : a);
            b = b < -128 ? -128 : (b > 128 ? 128 : b);
            func_0020DE28(0xA4, 0, 0xC);
            p = (PktVP *)func_0020DED8();
            p->m0 = e->m8;
            p->m2 = k;
            p->m4 = 3;
            p->m8 = a;
            p->mA = b;
            return (void)func_0020DEF0();
        }
    }
}

extern "C" void func_0020D3F0(u32 i, f32 v) {
    if (i < 48) {
        VoiceEnt *e = &D_318DC4.m0[i];
        if (Used(e)) {
            Pkt3 *p;
            func_0020DE28(0xA2, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m8;
            p->m4 = 4;
            p->m8 = (s32)(v * 4096.0f);
            func_0020DEF0();
            return;
        }
    }
}

extern "C" void func_0020D4A0(u32 i, s32 a, s32 b) {
    if (i < 48) {
        VoiceEnt *e = &D_318DC4.m0[i];
        if (Used(e)) {
            Pkt3h *p;
            func_0020DE28(0xA4, 0, 0xC);
            p = (Pkt3h *)func_0020DED8();
            p->m0 = e->m8;
            p->m2 = a;
            p->m4 = 5;
            p->m8 = b;
            func_0020DEF0();
            return;
        }
    }
}

extern "C" void func_0020D550(u32 i, s32 v) {
    if (i < 48) {
        VoiceEnt *e = &D_318DC4.m0[i];
        if (Used(e)) {
            Pkt3 *p;
            v = v < 0 ? 0 : (v > 2 ? 2 : v);
            func_0020DE28(0xA2, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m8;
            p->m4 = 6;
            p->m8 = v;
            func_0020DEF0();
            return;
        }
    }
}

extern "C" void func_0020D618(u32 i, s32 v) {
    if (i < 48) {
        VoiceEnt *e = &D_318DC4.m0[i];
        if (Used(e)) {
            Pkt3 *p;
            v = v < 0 ? 0 : (v > 127 ? 127 : v);
            func_0020DE28(0xA2, 0, 0xC);
            p = (Pkt3 *)func_0020DED8();
            p->m0 = e->m8;
            p->m4 = 7;
            p->m8 = v;
            func_0020DEF0();
            return;
        }
    }
}

extern "C" void func_0020D6E0(void) {
    s32 i;
    Node20 *n;
    VoiceEnt *e;
    D_3179C0.m1400 = 0;
    for (i = 0, n = D_3179C0.m0; i < 256; i++, n++) {
        n->m0 = D_3179C0.m1400;
        D_3179C0.m1400 = n;
    }
    D_3179C0.m20C4 = 0;
    D_3179C0.m20C8 = 0;
    D_3179C0.m20CC = 0;
    D_3179C0.m20D0 = 0x80;
    D_3179C0.m20D2 = 0x80;
    for (i = 0, e = D_3179C0.m1404; i < 48; i++, e++) {
        e->m8 = i;
        e->m9 = 0;
        e->m0 = (s32)D_3179C0.m20CC;
        D_3179C0.m20CC = e;
    }
    D_3179C0.m20D4 = 0;
    D_3179C0.m20D8 = 0;
}

extern "C" void func_0020D778(void) {
}

INCLUDE_ASM("asm/nonmatchings/Unit20CBF0", func_0020D780);

extern "C" s16 func_0020D9C0(void) { return D_318DC4.mCCC; }

extern "C" s16 func_0020D9D0(void) { return D_318DC4.mCCE; }

extern "C" s32 func_0020D9E0(s32 a, s32 b) {
    s32 buf[6];
    memset(buf, 0, sizeof(buf));
    buf[1] = a;
    buf[2] = b;
    return func_002731A0(buf);
}

extern "C" s32 func_0020DA30(void *cl, s32 id) {
    s32 k;
    if (func_00206088() & 4) Func235DE0("binding IOP module %08X ...\n", id);
    do {
        if (func_00275EE0(cl, id, 0) < 0) {
            if (func_00206088() & 1) Func235DE0("bind error '%08X'\n", id);
            return 0;
        }
        for (k = 9999; k >= 0; k--) func_00206548();
    } while (*(s32 *)((u8 *)cl + 0x24) == 0);
    func_00273420(0);
    if (func_00206088() & 4) Func235DE0("... binding completed\n");
    D_002A6180 = func_0020D9E0(1, 1);
    return 1;
}

extern "C" s32 func_0020DB28(void *p) { return func_002731B0(D_002A6180); }

extern "C" void func_0020DB48(void) {
    func_002731D0(D_002A6180);
    __asm__ volatile("sync");
    __asm__ volatile("ei");
}

extern "C" void func_0020DB78(void *cl, s32 fno, void *send, s32 ssize, void *recv, s32 rsize) {
    while (func_002762A8(cl) == 1);
    func_00273420(0);
    func_001F15F0();
    func_002760B0(cl, fno, 1, send, ssize, recv, rsize, 0, 0);
    func_001F1610();
    while (func_002762A8(cl) == 1);
    return (void)func_00273420(0);
}

// "DI error\n": no code in this unit refers to it any more.
INCLUDE_RODATA("asm/nonmatchings/Unit20CBF0", D_002E3338);


extern "C" void func_0020DC40(void) {
    while (!func_0020DA30(D_322AC0, 0xD000));
}

extern "C" s32 func_0020DC78(void) { return func_0020DB28(D_322AC0); }

INCLUDE_ASM("asm/nonmatchings/Unit20CBF0", func_0020DC98);

extern "C" void func_0020DE28(s32 cmd, s32 b, s32 size) {
    s32 *h;
    if ((u32)(D_002A6184 + size + 12) > 0x1000 || D_002A6188 + b > 0x1000) func_0020DF38();
    h = (s32 *)(D_322B00 + D_002A6184);
    h[0] = cmd;
    h[1] = b;
    h[2] = size;
}

extern "C" u8 *func_0020DEC0(void) { return D_323B00 + D_002A6188; }

extern "C" u8 *func_0020DED8(void) { return D_322B0C + D_002A6184; }

extern "C" void func_0020DEF0(void) {
    s32 a = D_002A6184;
    s32 b = D_002A6188;
    s32 *h = (s32 *)(D_322B00 + a);
    D_002A6184 = a + h[2] + 12;
    D_002A6188 = b + h[1];
}

extern "C" void func_0020DF38(void) {
    s32 n = D_002A6184;
    if (n > 0) {
        s32 *h = (s32 *)(D_322B00 + n);
        h[0] = 0;
        h[1] = 0;
        h[2] = 0;
        D_002A6184 = n + 12;
        func_0020DB78(D_322AC0, 0x200, D_322B00, (n + 12 + 0x3F) & ~0x3F, D_323B00, (D_002A6188 + 0x3F) & ~0x3F);
        D_002A6184 = 0;
        D_002A6188 = 4;
    }
}

INCLUDE_RODATA("asm/nonmatchings/Unit20CBF0", D_002E3348);
INCLUDE_ASM("asm/nonmatchings/Unit20CBF0", func_0020DFD8);
INCLUDE_RODATA("asm/nonmatchings/Unit20CBF0", D_002E33C8);
INCLUDE_RODATA("asm/nonmatchings/Unit20CBF0", D_002E33D0);
INCLUDE_RODATA("asm/nonmatchings/Unit20CBF0", D_002E33D8);
INCLUDE_RODATA("asm/nonmatchings/Unit20CBF0", D_002E33E0);
INCLUDE_RODATA("asm/nonmatchings/Unit20CBF0", D_002E33E8);
INCLUDE_RODATA("asm/nonmatchings/Unit20CBF0", D_002E33F0);
INCLUDE_RODATA("asm/nonmatchings/Unit20CBF0", D_002E33F8);

extern "C" void func_0020E1B8(u32 i) {
    func_001F15F0();
    if (i < 256 && D_324B00[i].m0) D_324B00[i].m0 = 0;
    func_001F1610();
    return;
}

extern "C" void func_0020E210(u32 i, const char *s) {
    if (i < 256) {
        BankEnt *e = &D_324B00[i];
        if (e->m0) {
            e->m2 = 1;
            e->m24 = func_0022DC10();
            strcpy(e->m28, func_0022DCC0());
            return (void)strcpy(e->m68, s);
        }
    }
}

extern "C" void func_0020E2A8(u32 i, s32 b, s32 c) {
    if (i < 256) {
        BankEnt *e = &D_324B00[i];
        if (e->m0) {
            e->m20 = c;
            e->m1C = b;
            e->m2 = 0;
        }
    }
}

extern "C" s32 func_0020E2F0(u32 i) {
    BankEnt *e;
    if (i < 256) {
        e = &D_324B00[i];
        if (e->m0) goto found;
    }
    return 0;
found:
    return e->m4;
}

extern "C" s32 func_0020E338(u32 i) {
    BankEnt *e;
    if (i < 256) {
        e = &D_324B00[i];
        if (e->m0) goto found;
    }
    return -1;
found:
    return e->m2;
}

extern "C" s32 func_0020E380(u32 i) {
    BankEnt *e;
    if (i < 256) {
        e = &D_324B00[i];
        if (e->m0) goto found;
    }
    return 0;
found:
    return e->m1C;
}

extern "C" void func_0020E3C8(u32 i, s32 *out, char *a, char *b) {
    if (i < 256) {
        BankEnt *e = &D_324B00[i];
        if (e->m0) {
            if (out) *out = e->m24;
            if (a) strcpy(a, e->m28);
            if (b) strcpy(b, e->m68);
        }
    }
}

extern "C" s32 func_0020E458(s32 a) { return func_0020ED38(a); }

extern "C" const char *func_0020E470(s32 a, s32 b) { return func_0020EE20(a, b); }

extern "C" s32 func_0020E488(s32 a) {
    StrmInfo *p = func_0020EBF8(a);
    return p ? p->m0 : -1;
}

extern "C" s32 func_0020E4B8(s32 a) {
    StrmInfo *p = func_0020EBF8(a);
    return p ? p->mA : 0;
}

extern "C" s32 func_0020E4E8(s32 a) {
    StrmInfo *p = func_0020EBF8(a);
    return p ? p->m9 : 0;
}

extern "C" s32 func_0020E518(s32 a) {
    StrmInfo *p = func_0020EBF8(a);
    return p ? p->m10 : 0;
}

extern "C" s32 func_0020E548(s32 a) {
    StrmInfo *p = func_0020EBF8(a);
    return p ? p->m14 : 0;
}

extern "C" s32 func_0020E578(s32 a) {
    StrmInfo *p = func_0020EBF8(a);
    return p ? p->m18 : 0;
}

extern "C" s32 func_0020E5A8(s32 a) { return func_0020EE98(a); }

extern "C" const char *func_0020E5C0(s32 a) {
    NameEnt *p = func_0020EF18(a);
    return p ? p->mC : D_002E33F0;
}

extern "C" s32 func_0020E5F0(s32 a) {
    NameEnt *p = func_0020EF18(a);
    return p ? p->m0 : 0;
}

extern "C" s32 func_0020E620(s32 a) {
    NameEnt *p = func_0020EF18(a);
    return p ? p->m4 : 0;
}

extern "C" s32 func_0020E650(s32 a) { return func_0020EFB8(a); }

extern "C" const char *func_0020E668(s32 a) {
    NameEnt *p = func_0020F038(a);
    return p ? p->mC : D_002E33F0;
}

asm(".p2align 3");
extern "C" s32 func_0020E698(u32 i, const char *name) {
    s32 k, n;
    if (i < 256 && D_324B00[i].m0) {
        if (!name) return -1;
        k = 0;
        n = func_0020E458(i);
        if (n > 0) {
            do {
                if (!strcmp(func_0020E470(i, k), name)) return k;
                k++;
            } while (k < n);
        }
    }
    return -1;
}

extern "C" BankEnt *func_0020E758(u32 i) {
    BankEnt *e;
    if (i < 256) {
        e = &D_324B00[i];
        if (e->m0) goto found;
    }
    return 0;
found:
    return e;
}

INCLUDE_ASM("asm/nonmatchings/Unit20CBF0", func_0020E798);

INCLUDE_ASM("asm/nonmatchings/Unit20CBF0", func_0020E808);

extern "C" s32 func_0020E8B8(u32 i, s32 k) {
    s32 *p = (s32 *)func_0020E798(i, k);
    if (p) return p[1];
    return 0;
}

extern "C" u8 func_0020E8E0(u32 i, s32 k, s32 n) {
    u8 *p = (u8 *)func_0020E808(i, k, n);
    if (p) return p[1];
    return 0;
}

extern "C" u8 *func_0020E908(u32 i, s32 k, s32 n) {
    E808 *p = (E808 *)func_0020E808(i, k, n);
    if (p == 0) return 0;
    return p->m8;
}
