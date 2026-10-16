#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" s32 func_002731B0(s32);
extern "C" void func_002731D0(s32);
extern s32 D_002BD790;
extern "C" s32 func_00263330(s32, s32, s32);
struct S41C080 { s32 m0; u8 pad4[0x38]; s32 m3C; };
extern S41C080 D_41C080;
extern s32 D_002BD788;
extern s32 D_002BD78C;
struct SifClient { u8 pad0[0x24]; s32 m24; };
extern SifClient D_41AAC0;
extern u32 *D_41AAE8;
extern u32 *D_41AAEC;
extern u32 *D_41AAF0;
extern "C" s32 func_00264E90(s32, s32, const char *, s32);
struct Rx { s32 m0; u32 m4; u8 pad8[0x90 - 8]; u32 m90; };
extern void (*D_41A808)(s32);
extern u32 D_41A80C;
extern s32 D_41A810;
extern s32 D_002BBBE4;

extern "C" s32 func_00274F10(const char *, ...);
extern s32 D_002BBBD0;
extern const char D_002E9130[];
extern "C" s32 func_00273F80(s32);
extern "C" s32 func_002762A8(void *);
extern u8 D_002BD740[];
extern s32 D_41AB40[];
extern const char D_002E92F8[];
extern "C" s32 func_002760B0(void *, s32, s32, void *, s32, void *, s32, void *, void *);
extern "C" s32 func_0027BD20(void);
extern "C" s32 func_0027BD78(void);
extern "C" s32 func_002752D0(u32, void *, s32);
extern s32 D_002BBC00;
extern "C" void func_00263260(void);
extern "C" void func_00264CF8(void);

extern "C" s32 func_00263668(s32);
extern "C" s32 func_00263980(s32);
extern "C" s32 func_002731C0(s32);
extern u8 D_002BCD90[];
extern u8 D_002BCDC0[];
extern s32 D_002BBC40[];
extern s32 D_002BBBE8;
extern s32 D_002BBBEC;
extern s32 D_002BBBF4;
extern u8 D_002BBCC0[];
extern u8 D_002BD200[];
extern const char D_002E9120[];
extern const char D_002E9240[];
extern u8 D_41B080[];
struct CdBuf { s32 m0; s32 m4; u8 *m8; u8 *mC; u8 m10[0x40]; u8 m50[0x40]; };
#define UNCACHED(p) ((u32)(p) | 0x20000000)

extern "C" s32 func_002731F0(s32);
extern "C" s32 func_002731E0(s32);

extern "C" void func_00275698(void *, s32);
extern s32 D_002BD768;
extern s32 D_002BD76C;
extern s32 D_002BD770;
extern "C" s32 func_002731F0(s32);

extern s32 D_41AFC0[];
extern "C" void func_00265190(CdBuf *);

extern s32 D_41AB70[];
extern "C" char *func_0028B728(char *, const char *, u32);

extern "C" s32 func_00263088(void);
extern "C" s32 func_00263870(s32);
extern "C" s32 func_00263910(s32);
extern "C" s32 func_002730A0(s32, void *);
extern "C" s32 func_00275748(s32);
extern "C" s32 func_00275EE0(void *, u32, s32);
extern s32 D_41A818;
extern u8 D_41A820[];
extern s32 D_002BBBDC;
extern s32 D_002BBBD8;
extern s32 D_002BBBFC;
extern s32 D_002BBC0C;
extern const char D_002E90E0[];
extern const char D_002E9108[];
extern const char D_002E9140[];
extern const char D_002E9168[];

extern "C" void func_00265580(Rx *);

extern "C" void func_00273420(s32);
struct McCmd { s32 m0, m4, m8, mC, m10, m14, m18, m1C; u8 data[0x10]; };

extern "C" s32 func_002632B8(void);

extern const char D_002E9250[];
extern const char D_002E9270[];
struct W2Clock8 { u8 b[8]; };
struct W2Sema { s32 count, max_count, init_count, wait_threads; u32 attr, option; };
extern "C" s32 func_002731A0(W2Sema *);
extern "C" void func_002654B8(s32, s32, s32);
struct W2CdVer { s32 m0, m4, m8; };
extern W2CdVer D_41C080v asm("D_41C080");
extern const char D_002E9290[];
extern const char D_002E92A8[];
extern const char D_002E92D0[];

extern s32 D_002BBBF8;
extern "C" s32 func_002637D8(void);
extern s32 D_002BBC18;
extern u8 D_002BCCC0[];
extern s32 D_002BCD80[];
extern const char D_002E9218[];
extern const char D_002E9230[];
extern "C" void func_00262FD0(void);
struct W2CdRd { u32 lsn; u32 sectors; void *buf; u8 mode[3]; u8 pad; void *p10; void *p14; };
// @decl-end

extern "C" void *func_002631E0(void (*cb)(s32), s32 arg) {
    void *old; s32 r;
    if (D_002BBC00 < 0) func_002632B8();
    r = func_0027BD20(); old = (void *)D_41A808; D_41A810 = arg; D_41A808 = cb;
    asm volatile("sw $28, %0" : "=m"(D_41A80C));
    if (r) func_0027BD78();
    return old;
}

extern "C" void func_00263260(void) {
    void (*cb)(s32) = D_41A808;
    if (cb && !D_002BBBE4) {
        u32 save;
        asm volatile("move %0, $28\n\tlw $28, %1" : "=&r"(save) : "m"(D_41A80C));
        cb(D_41A810);
        asm volatile("move $28, %0" : : "r"(save));
    }
}

extern "C" s32 func_002632B8(void) { s32 r; D_002BBBE4 = 1; r = func_0027BD20(); func_002752D0(0x80000012, (void *)func_00263260, 0); if (r) func_0027BD78(); D_002BBBE4 = 0; D_002BBC00 = 1; return 1; }

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00263330);

extern "C" s32 func_00263648(s32 a, s32 b) { return func_00263330(a, b, 0); }

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00263668);

extern "C" s32 func_002637D8(void) {
    s32 r;
    if (!func_00263668(2)) return 0;
    if (func_002760B0(D_002BCD90, 0xE, 0, 0, 0, D_002BBC40, 4, 0, 0) < 0) { func_002731C0(D_002BBBE8); return 0; }
    r = *(s32 *)UNCACHED(D_002BBC40);
    func_002731C0(D_002BBBE8);
    return r;
}

extern "C" s32 func_00263870(s32 mode) {
    if (mode == 0) {
        if (D_002BBBD0 > 0) func_00274F10(D_002E9120);
        while (D_002BBBF4 || func_002762A8(D_002BCD90)) func_00273F80(4000);
        return 0;
    }
    if (D_002BBBF4 || func_002762A8(D_002BCD90)) return 1;
    return 0;
}

extern "C" s32 func_00263910(s32 mode) {
    if (mode == 0) {
        if (D_002BBBD0 > 0) func_00274F10(D_002E9130);
        while (func_002762A8(D_002BD740)) func_00273F80(4000);
        return 0;
    }
    return func_002762A8(D_002BD740);
}

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00263980);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00263AF0);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00263BA0);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00263E80);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00264078);

extern "C" s32 func_00264280(u32 lsn, u32 sectors, void *buf, u8 *mode) {
    W2CdRd *r = (W2CdRd *)D_002BBCC0;
    s32 n;
    if (D_002BBBF8 & 1) ; else if (func_002637D8() == 6) return 0;
    if (!func_00263668(4)) return 0;
    r->lsn = lsn;
    r->sectors = sectors;
    r->buf = buf;
    r->mode[0] = mode[0];
    r->mode[1] = mode[1];
    r->mode[2] = mode[2];
    r->p10 = D_002BCCC0;
    r->p14 = D_002BCD80;
    switch (mode[2]) {
    case 1:
        n = sectors * 0x918;
        break;
    case 2:
        n = sectors * 0x924;
        break;
    case 0:
    default:
        n = sectors << 11;
        break;
    }
    D_002BCD80[0] = 0;
    if ((*(volatile s32 *)&D_002BBBF8 & 2) == 0) func_00275698(buf, n);
    func_00275698(D_002BCCC0, 0x90);
    func_00275698(r, 0x18);
    func_00275698(D_002BCD80, 4);
    if (D_002BBBD0 > 0) func_00274F10(D_002E9218);
    *(volatile s32 *)&D_002BBC18 = 1;
    *(volatile s32 *)&D_002BBBF4 = 1;
    if (func_002760B0(D_002BCD90, 1, 1, r, 0x18, 0, 0, (void *)func_00262FD0, D_002BCCC0) < 0) {
        *(volatile s32 *)&D_002BBC18 = 0;
        *(volatile s32 *)&D_002BBBF4 = 0;
        func_002731C0(*(volatile s32 *)&D_002BBBE8);
        return 0;
    }
    if (D_002BBBD0 > 0) func_00274F10(D_002E9230);
    return 1;
}

extern "C" s32 func_00264460(void) {
    s32 r;
    if (!func_00263980(1)) return 0;
    if (func_002760B0(D_002BD740, 3, 0, 0, 0, D_002BCDC0, 4, 0, 0) < 0) { func_002731C0(D_002BBBEC); return 0; }
    r = *(s32 *)UNCACHED(D_002BCDC0);
    func_002731C0(D_002BBBEC);
    return r;
}

extern "C" s32 func_002644F8(void) {
    s32 r;
    if (!func_00263980(3)) return -1;
    if (func_002760B0(D_002BD740, 4, 0, 0, 0, D_002BCDC0, 4, 0, 0) < 0) { func_002731C0(D_002BBBEC); return -1; }
    r = *(s32 *)UNCACHED(D_002BCDC0);
    func_002731C0(D_002BBBEC);
    return r;
}

extern "C" s32 func_00264590(void) {
    s32 r;
    if (!func_00263980(2)) return -1;
    if (func_002760B0(D_002BD740, 0xC, 0, 0, 0, D_002BCDC0, 4, 0, 0) < 0) { func_002731C0(D_002BBBEC); return -1; }
    r = *(s32 *)UNCACHED(D_002BCDC0);
    func_002731C0(D_002BBBEC);
    if (D_002BBBD0 >= 2) func_00274F10(D_002E9240);
    return r;
}

extern "C" s32 func_00264648(s32 x, s32 y) {
    s32 r; s32 *buf = (s32 *)D_002BD200;
    if (!func_00263980(0x25)) return 0;
    buf[0] = x;
    buf[1] = y;
    func_00275698(buf, 8);
    if (func_002760B0(D_002BD740, 0x25, 0, buf, 8, D_002BCDC0, 4, 0, 0) < 0) { func_002731C0(D_002BBBEC); return 0; }
    r = *(s32 *)UNCACHED(D_002BCDC0);
    func_002731C0(D_002BBBEC);
    return r;
}

extern "C" s32 func_00264720(s32 *a, s32 *b) {
    s32 r;
    if (!func_00263980(0x27)) return 0;
    if (func_002760B0(D_002BD740, 0x27, 0, 0, 0, D_002BCDC0, 0xC, 0, 0) < 0) { func_002731C0(D_002BBBEC); return 0; }
    *a = *(s32 *)UNCACHED(D_002BCDC0 + 4);
    *b = *(s32 *)UNCACHED(D_002BCDC0 + 8);
    r = *(s32 *)UNCACHED(D_002BCDC0);
    func_002731C0(D_002BBBEC);
    return r;
}

extern "C" s32 func_002647F0(s32 x) {
    s32 r; s32 *buf = (s32 *)D_002BD200;
    if (!func_00263980(0x22)) return 0;
    buf[0] = x;
    func_00275698(buf, 4);
    if (func_002760B0(D_002BD740, D_002BD768, 0, buf, D_002BD76C, D_002BCDC0, D_002BD770, 0, 0) < 0) { func_002731C0(D_002BBBEC); return 0; }
    r = *(s32 *)UNCACHED(D_002BCDC0);
    func_002731C0(D_002BBBEC);
    return r;
}

extern "C" s32 func_002648C0(W2Clock8 *out) {
    s32 r;
    if (!func_00263980(0xF)) return 0;
    if (D_002BBBD0 > 0) func_00274F10(D_002E9250);
    if (func_002760B0(D_002BD740, 1, 0, 0, 0, D_002BCDC0, 0x10, 0, 0) < 0) { func_002731C0(D_002BBBEC); return 0; }
    *out = *(W2Clock8 *)UNCACHED(D_002BCDC0 + 4);
    if (D_002BBBD0 > 0) func_00274F10(D_002E9270);
    r = *(s32 *)UNCACHED(D_002BCDC0);
    func_002731C0(D_002BBBEC);
    return r;
}

extern "C" s32 func_002649B8(s32 x, s32 *p) {
    s32 r; s32 *buf = (s32 *)D_002BD200;
    if (!func_00263980(0x1A)) return -1;
    buf[0] = x;
    func_00275698(buf, 4);
    if (func_002760B0(D_002BD740, 5, 0, buf, 4, D_002BCDC0, 8, 0, 0) < 0) { func_002731C0(*(volatile s32 *)&D_002BBBEC); return -1; }
    if (p) *p = *(s32 *)UNCACHED(D_002BCDC0 + 4);
    r = *(s32 *)UNCACHED(D_002BCDC0);
    func_002731C0(D_002BBBEC);
    return r;
}

extern "C" s32 func_00264AA8(void)
{
    W2Sema p;
    s32 r, i;
    W2CdVer *v;
    SifClient *c;
    s32 *b;
    if (D_002BD78C < 0) {
        p.option = 0;
        p.init_count = 1;
        p.max_count = 1;
        D_002BD78C = func_002731A0(&p);
        p.max_count = 1;
        p.init_count = 0;
        p.option = 0;
        D_002BD790 = func_002731A0(&p);
    }
    func_002654B8(0, 0, 0);
    func_002731E0(D_002BD78C);
    func_00275748(0);
    while (1) {
        if (func_00275EE0(&D_41AAC0, 0x80000400, 0) < 0) {
            func_00274F10(D_002E9290);
            while (1)
                ;
        }
        if (D_41AAC0.m24) break;
        i = 0x100000;
        while (--i)
            ;
    }
    c = &D_41AAC0;
    b = D_41AB40;
    v = &D_41C080v;
    r = func_002760B0(c, 0xFE, 0, b, 0x30, v, 0xC, 0, 0);
    func_002731C0(D_002BD78C);
    if (r < 0) {
        D_41AAC0.m24 = 0;
        return r - 100;
    }
    if (v->m4 < 0x20A) {
        func_00274F10(D_002E92A8);
        D_41AAC0.m24 = 0;
        return -120;
    }
    if (v->m8 < 0x20E) {
        func_00274F10(D_002E92D0);
        D_41AAC0.m24 = 0;
        return -121;
    }
    return D_41C080v.m0;
}

extern "C" s32 func_00264C78(void) { if (D_002BD78C >= 0) { func_002731B0(D_002BD78C); D_002BD78C = -1; func_002731B0(D_002BD790); } return 1; }

extern "C" void *func_00264CC8(void **a, void **b) { *a = &D_41C080; *b = &D_002BD788; D_41C080.m3C = D_002BD78C; return &D_41AAC0; }

extern "C" void func_00264CF8(void) { func_002731D0(D_002BD790); }

extern "C" s32 func_00264D08(s32 x) {
    s32 r;
    if (!D_41AAC0.m24) return -100;
    if (func_002731F0(D_002BD78C) < 0) return -200;
    D_41AB40[5] = x;
    r = func_002760B0(&D_41AAC0, 0x14, 1, D_41AB40, 0x30, &D_41C080, 4, (void *)func_00264CF8, 0);
    if (r == 0) D_002BD788 = 0x14; else func_002731C0(D_002BD78C);
    return r;
}

extern "C" s32 func_00264DC8(s32 x) {
    s32 r;
    if (!D_41AAC0.m24) return -100;
    if (func_002731F0(D_002BD78C) < 0) return -200;
    D_41AB40[1] = x;
    r = func_002760B0(&D_41AAC0, 0x15, 0, D_41AB40, 0x30, &D_41C080, 4, 0, 0);
    if (r) { func_002731C0(D_002BD78C); return r; }
    func_002731C0(D_002BD78C);
    return D_41C080.m0;
}

extern "C" s32 func_00264E90(s32 port, s32 slot, const char *name, s32 mode) {
    s32 r;
    if (!D_41AAC0.m24) return -100;
    if (func_002731F0(D_002BD78C) < 0) return -200;
    if (!name || !*name) { func_002731C0(D_002BD78C); return -210; }
    func_0028B728((char *)&D_41AB70[5], name, 0x3FF);
    D_41AB70[0] = port; D_41AB70[2] = mode; D_41AB70[1] = slot;
    ((char *)D_41AB70)[0x413] = 0;
    r = func_002760B0(&D_41AAC0, 2, 1, D_41AB70, 0x414, &D_41C080, 4, (void *)func_00264CF8, 0);
    if (r == 0) D_002BD788 = 2; else func_002731C0(D_002BD78C);
    return r;
}

extern "C" s32 func_00264FB8(s32 a, s32 b, const char *c) { s32 r = func_00264E90(a, b, c, 0x40); if (r == 0) D_002BD788 = 11; return r; }

extern "C" s32 func_00264FF0(s32 x) {
    s32 r;
    if (!D_41AAC0.m24) return -100;
    if (func_002731F0(D_002BD78C) < 0) return -200;
    D_41AB40[0] = x;
    r = func_002760B0(&D_41AAC0, 3, 1, D_41AB40, 0x30, &D_41C080, 4, (void *)func_00264CF8, 0);
    if (r == 0) D_002BD788 = 3; else func_002731C0(D_002BD78C);
    return r;
}

extern "C" s32 func_002650B0(s32 x, s32 y, s32 z) {
    s32 r;
    if (!D_41AAC0.m24) return -100;
    if (func_002731F0(D_002BD78C) < 0) return -200;
    D_41AB40[0] = x; D_41AB40[4] = y; D_41AB40[5] = z;
    r = func_002760B0(&D_41AAC0, 4, 1, D_41AB40, 0x30, &D_41C080, 4, (void *)func_00264CF8, 0);
    if (r == 0) D_002BD788 = 4; else func_002731C0(D_002BD78C);
    return r;
}

extern "C" void func_00265190(CdBuf *b) {
    s32 i; u8 *d;
    b = (CdBuf *)UNCACHED(b);
    if (b->m0) { d = b->m8; for (i = 0; i < b->m0; i++) *d++ = b->m10[i]; }
    if (b->m4) { d = b->mC; for (i = 0; i < b->m4; i++) *d++ = b->m50[i]; }
    func_002731D0(D_002BD790);
}

extern "C" s32 func_00265228(s32 port, void *buf, s32 size) {
    s32 r;
    if (!D_41AAC0.m24) return -100;
    if (func_002731F0(D_002BD78C) < 0) return -200;
    D_41AB40[0] = port; D_41AB40[7] = (s32)D_41AFC0; D_41AB40[6] = (s32)buf; D_41AB40[3] = size;
    func_00275698(buf, size);
    func_00275698(D_41AFC0, 0xC0);
    r = func_002760B0(&D_41AAC0, 5, 1, D_41AB40, 0x30, &D_41C080, 4, (void *)func_00265190, D_41AFC0);
    if (r == 0) D_002BD788 = 5; else func_002731C0(D_002BD78C);
    return r;
}

extern "C" s32 func_00265340(s32 fd, const u8 *buf, s32 size) {
    s32 r; u32 i;
    if (!D_41AAC0.m24) return -100;
    if (func_002731F0(D_002BD78C) < 0) return -200;
    D_41AB40[0] = fd;
    if (size < 17) { D_41AB40[5] = size; D_41AB40[3] = 0; D_41AB40[6] = 0; }
    else {
        u32 a = ((u32)buf - 1) & ~0xF; u32 b = (u32)buf - 16; s32 head = a - b;
        D_41AB40[3] = size - head;
        D_41AB40[5] = head;
        D_41AB40[6] = (s32)(buf + head);
    }
    for (i = 0; i < (u32)((McCmd *)D_41AB40)->m14; i++) ((McCmd *)D_41AB40)->data[i] = buf[i];
    func_00273420(0);
    r = func_002760B0(&D_41AAC0, 6, 1, D_41AB40, 0x30, &D_41C080, 4, (void *)func_00264CF8, 0);
    if (r == 0) D_002BD788 = 6; else func_002731C0(D_002BD78C);
    return r;
}

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_002654B8);

extern "C" void func_00265580(Rx *r) { r = (Rx *)((u32)r | 0x20000000); if (D_41AAE8) *D_41AAE8 = r->m0; if (D_41AAEC) *D_41AAEC = r->m4; if (D_41AAF0) *D_41AAF0 = r->m90; func_002731D0(D_002BD790); }

extern "C" s32 func_002655D8(s32 port, s32 slot, s32 *type, s32 *free, s32 *format) {
    s32 r;
    if (!D_41AAC0.m24) return -100;
    if (func_002731F0(D_002BD78C) < 0) return -200;
    D_41AB40[1] = port; D_41AB40[2] = slot; D_41AB40[7] = (s32)D_41AFC0;
    if (type) D_41AB40[5] = 1; else D_41AB40[5] = 0;
    if (free) D_41AB40[4] = 1; else D_41AB40[4] = 0;
    if (format) D_41AB40[3] = 1; else D_41AB40[3] = 0;
    D_41AAE8 = (u32 *)type; D_41AAEC = (u32 *)free; D_41AAF0 = (u32 *)format;
    func_00275698(D_41AFC0, 0xC0);
    r = func_002760B0(&D_41AAC0, 1, 1, D_41AB40, 0x30, &D_41C080, 4, (void *)func_00265580, D_41AFC0);
    if (r == 0) D_002BD788 = 1; else func_002731C0(D_002BD78C);
    return r;
}

extern "C" s32 func_00265758(void) {
    if (func_002760B0(&D_41AAC0, 0x35, 0, D_41AB40, 0x30, &D_41C080, 4, (void *)func_00264CF8, 0)) { func_00274F10(D_002E92F8); return -1; }
    return D_41C080.m0;
}

extern "C" s32 func_002657C8(s32 port, s32 slot, const char *name, s32 mode, s32 maxent, void *table) {
    s32 r;
    if (!D_41AAC0.m24) return -100;
    if (func_002731F0(D_002BD78C) < 0) return -200;
    if (!name || !*name) { func_002731C0(D_002BD78C); return -210; }
    D_41AB70[0] = port; D_41AB70[1] = slot; D_41AB70[2] = mode; D_41AB70[3] = maxent; D_41AB70[4] = (s32)table;
    func_0028B728((char *)&D_41AB70[5], name, 0x3FF);
    ((char *)D_41AB70)[0x413] = 0;
    if (maxent >= 0) func_00275698(table, maxent << 6);
    r = func_002760B0(&D_41AAC0, 0xD, 1, D_41AB70, 0x414, &D_41C080, 4, (void *)func_00264CF8, 0);
    if (r == 0) D_002BD788 = 0xD; else func_002731C0(D_002BD78C);
    return r;
}
