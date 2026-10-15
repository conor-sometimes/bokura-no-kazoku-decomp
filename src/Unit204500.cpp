#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" char *strcpy(char *dst, const char *src);
void Func225088();
int Func2250C0();
void Func2251E8();
extern "C" void func_00204BC8(s32, s32, s32, s32, s32, s32, s32);
extern "C" void func_00202D68(void);
extern "C" void func_00205A80(void);
extern "C" char *func_002052E8(char *, const char *);
struct Ent2A5D0C { u8 pad0[0x18]; void (*m_fn)(void); u8 pad1C[0x34 - 0x1C]; };
extern Ent2A5D0C *D_002A5D0C;
extern char D_002A5D68[];
extern void (*D_002A5D70)(void);
extern s32 D_002A5D74;
extern s32 D_002A5D78;
typedef char *(*CopyFn)(char *, const char *);
extern CopyFn D_002A5D7C;
extern CopyFn D_002A5D80;
inline void *OffPtr(void *p, s32 off) { return off > 0 ? (char *)p + off : 0; }
extern const char _ctype_[];
#define isupper(c) ((_ctype_+1)[(unsigned)(c)]&01)
#define tolower(c) ({ __typeof__ (c) __x = (c); isupper (__x) ? (__x - 'A' + 'a') : __x;})

extern "C" s32 func_0020DC98(s32 cmd, void *rbuf, s32 rsize, void *sbuf, s32 ssize);
extern "C" void func_0020DE28(s32, s32, s32);
extern "C" void *func_0020DED8(void);
extern "C" s32 func_0020DEC0(void);
extern "C" s32 func_0020DEF0(void);
extern "C" void func_0020DF38(void);
extern "C" void func_0020DC40(void);
extern "C" void func_002064C8(void);
extern "C" void func_00206D78(void);
extern "C" void func_002073D0(void);
extern "C" void func_00208218(void);
extern "C" void func_00209100(void);
extern "C" void func_00209C60(void);
extern "C" void func_0020A9F8(void);
extern "C" void func_0020B9F0(void);
extern "C" void func_0020D6E0(void);
extern "C" void func_0020D778(void);
extern "C" void func_0020BA80(void);
extern "C" void func_0020AA58(void);
extern "C" void func_00209CB8(void);
extern "C" void func_00209108(void);
extern "C" void func_00208220(void);
extern "C" void func_002074F0(void);
extern "C" void func_00206DC8(void);
extern "C" void func_002064F8(void);
extern "C" s32 func_0020DC78(void);
extern "C" void func_00209CC0(s32);
extern "C" void func_0020AA60(s32);
extern "C" void func_0020BA88(s32);
extern "C" s32 func_0020D780(s32);
struct S30E4C0 { u8 m0, m1, m2, m3; u16 m4, m6; };
extern S30E4C0 D_30E4C0;
extern s32 D_002A5DE8;
extern f32 D_002A5DF0[];
extern f32 D_002A5F78[];

extern "C" void *func_002303E0(const char *);
extern void (*D_002B91B0)(void *p);
extern "C" s32 func_00205398(void *);
extern "C" s32 func_00201210(void *, s32);
extern "C" s32 func_002012D8(void *);
extern "C" s32 func_00201378(void *);
extern "C" s32 func_00201570(void *, s32);
extern "C" s32 func_00201628(void *, s32);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Unit204500", func_00204500);

INCLUDE_ASM("asm/nonmatchings/Unit204500", func_00204548);

INCLUDE_ASM("asm/nonmatchings/Unit204500", func_00204BC8);

extern "C" void func_00204C88(s32 a, s32 b, s32 c, s32 d) {
    func_00204BC8(a, b, c, d, 0, 0, 0);
    return;
}

extern "C" void func_00204CA8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    func_00204BC8(a, b, c, d, e, f, 0);
    return;
}

INCLUDE_ASM("asm/nonmatchings/Unit204500", func_00204CC0);

INCLUDE_ASM("asm/nonmatchings/Unit204500", func_00204E08);

extern "C" int func_00204F78(void) {
    Func225088();
    Func2251E8();
    return Func2250C0();
}

extern "C" void func_00204FA0(s32 i, void (*fn)(void)) {
    Ent2A5D0C *e = &D_002A5D0C[i];
    if (!fn) fn = func_00202D68;
    e->m_fn = fn;
}

INCLUDE_ASM("asm/nonmatchings/Unit204500", func_00204FD8);

extern "C" s32 func_002051B8(s32 *p) {
    s32 *q = (s32 *)OffPtr(p, p[1]);
    if (q) return *q;
    return 0;
}

extern "C" char *func_002051E0(s32 i, s32 *p) {
    s32 *q = (s32 *)OffPtr(p, p[1]);
    char *s;
    s32 n;
    if (!q) return 0;
    n = *q;
    if (i < 0 || i >= n) return 0;
    s = (char *)(q + 1);
    while (i > 0) {
        char *t = s;
        while (*t++);
        s = t;
        i--;
    }
    return s;
}

extern "C" void *func_00205258(char *p) {
    s32 off = *(s32 *)(p + 8);
    if (off) return p + off;
    return 0;
}

extern "C" char *func_00205270(char *s) {
    char *t = s;
    if (*s == '.') t = s + 1;
    return strcpy(D_002A5D68, t);
}

extern "C" void *func_002052A0(void (*fn)(void)) {
    void (*old)(void) = D_002A5D70;
    if (!fn) fn = func_00205A80;
    D_002A5D70 = fn;
    return (void *)old;
}

extern "C" void func_002052C8(s32 v) { D_002A5D74 = v; }

extern "C" void func_002052D8(s32 v) { D_002A5D78 = v; }

extern "C" char *func_002052E8(char *d, const char *s) { return strcpy(d, s); }

extern "C" CopyFn func_00205300(CopyFn fn) {
    CopyFn old = D_002A5D7C;
    if (!fn) fn = func_002052E8;
    D_002A5D7C = fn;
    return old;
}

extern "C" CopyFn func_00205328(CopyFn fn) {
    CopyFn old = D_002A5D80;
    if (!fn) fn = func_002052E8;
    D_002A5D80 = fn;
    return old;
}

extern "C" void func_00205350(char *d, const char *s) {
    char c;
    do {
        c = tolower(*s);
        s++;
        *d++ = c;
    } while (c);
}

INCLUDE_ASM("asm/nonmatchings/Unit204500", func_00205398);

s32 Func205598(const char *name) {
    char tmp[0x40];
    void *buf = func_002303E0(name);
    s32 r;
    if (!buf) return -1;
    {
        r = func_00205398(buf);
        if (r >= 0) r = func_00201210(buf, r);
        D_002B91B0(buf);
    }
    return r;
}

extern "C" s32 func_00205610(const char *name) {
    char tmp[0x40];
    void *buf = func_002303E0(name);
    s32 r;
    if (!buf) return -1;
    {
        r = func_002012D8(buf);
        D_002B91B0(buf);
    }
    return r;
}

extern "C" s32 func_00205670(const char *name) {
    char tmp[0x40];
    void *buf = func_002303E0(name);
    s32 r;
    if (!buf) return -1;
    {
        r = func_00201378(buf);
        D_002B91B0(buf);
    }
    return r;
}

extern "C" s32 func_002056D0(const char *name) {
    char tmp[0x40];
    void *buf = func_002303E0(name);
    s32 r;
    if (!buf) return -1;
    {
        r = func_00205398(buf);
        if (r >= 0) r = func_00201570(buf, r);
        D_002B91B0(buf);
    }
    return r;
}

extern "C" s32 func_00205748(const char *name) {
    char tmp[0x40];
    void *buf = func_002303E0(name);
    s32 r;
    if (!buf) return -1;
    {
        r = func_00205398(buf);
        if (r >= 0) r = func_00201628(buf, r);
        D_002B91B0(buf);
    }
    return r;
}

extern "C" u64 func_002057C0(u64 *p) { return (*p >> 20) & 0x3F; }

extern "C" u64 func_002057D0(u64 *p) { return (*p >> 51) & 0xF; }

extern "C" u64 func_002057E0(u64 *p) { return (p[1] & 0x1C) >> 2; }

extern "C" void func_002057F0(u64 *p, s32 v) { *p = (*p & ~(0x3FUL << 20)) | (v << 20); }

extern "C" s32 func_00205810(u64 *p) { return func_002057C0(p); }

extern "C" void func_00205838(u64 *p, u64 v) { *p = (*p & ~(0xFUL << 51)) | (v << 51); }

extern "C" s32 func_00205868(u64 *p) { return func_002057D0(p); }

extern "C" void func_00205890(void) {
}

INCLUDE_ASM("asm/nonmatchings/Unit204500", func_00205898);

INCLUDE_ASM("asm/nonmatchings/Unit204500", func_00205908);

INCLUDE_ASM("asm/nonmatchings/Unit204500", func_00205980);

INCLUDE_ASM("asm/nonmatchings/Unit204500", func_00205A80);

INCLUDE_ASM("asm/nonmatchings/Unit204500", Func205BA0__FPv);

INCLUDE_ASM("asm/nonmatchings/Unit204500", func_00205DE0);

extern "C" void func_00205E20(void) {
    func_0020DC40();
    func_002064C8();
    func_00206D78();
    func_002073D0();
    func_00208218();
    func_00209100();
    func_00209C60();
    func_0020A9F8();
    func_0020B9F0();
    func_0020D6E0();
    return;
}

extern "C" s32 func_00205E80(void) {
    while (func_0020DC98(0x11, 0, 0, 0, 0));
    func_0020D778();
    func_0020BA80();
    func_0020AA58();
    func_00209CB8();
    func_00209108();
    func_00208220();
    func_002074F0();
    func_00206DC8();
    func_002064F8();
    return func_0020DC78();
}

extern "C" s32 func_00205F00(void) {
    s32 a, b, c, d;
    func_0020DF38();
    func_0020DE28(0x72, 0x104, 0);
    a = func_0020DEC0();
    func_0020DEF0();
    func_0020DE28(0x83, 0x104, 0);
    b = func_0020DEC0();
    func_0020DEF0();
    func_0020DE28(0xB3, 0x184, 0);
    c = func_0020DEC0();
    func_0020DEF0();
    func_0020DE28(0xA3, 0x304, 0);
    d = func_0020DEC0();
    func_0020DEF0();
    func_0020DF38();
    func_00209CC0(a);
    func_0020AA60(b);
    func_0020BA88(c);
    return func_0020D780(d);
}

extern "C" void func_00205FE0(s32 on) {
    s32 buf[2];
    buf[0] = 2;
    if (!on) buf[1] = 0;
    else buf[1] = 1;
    func_0020DC98(0x30, 0, 0, buf, 8);
}

extern "C" u8 func_00206030(s32 v) {
    s32 buf[2];
    u8 old = D_30E4C0.m0;
    D_30E4C0.m0 = v;
    buf[0] = 0;
    buf[1] = v;
    func_0020DC98(0x30, 0, 0, buf, 8);
    return old;
}

extern "C" u8 func_00206088(void) { return D_30E4C0.m0; }

extern "C" void func_00206098(s32 hz) {
    s32 buf[2];
    buf[0] = 1;
    if (hz != 50) buf[1] = 60;
    else buf[1] = hz;
    func_0020DC98(0x30, 0, 0, buf, 8);
}

INCLUDE_ASM("asm/nonmatchings/Unit204500", func_002060F0);

extern "C" s32 func_00206170(s32 a, s32 b, s32 c) {
    struct Pkt { s32 m0; s32 m4; s16 m8; s16 mA; } *p;
    func_0020DE28(0x31, 0, 0xC);
    p = (Pkt *)func_0020DED8();
    p->m0 = a;
    p->m4 = 1;
    p->m8 = b;
    p->mA = c;
    return func_0020DEF0();
}

INCLUDE_ASM("asm/nonmatchings/Unit204500", func_002061D8);

INCLUDE_ASM("asm/nonmatchings/Unit204500", func_002062B8);

extern "C" void func_002062F0(s32 *out) {
    s32 buf[0x30];
    s32 i;
    func_0020DC98(0x90, buf, 0xC0, 0, 0);
    for (i = 0; i < 0x30; i++) out[i] = buf[i];
}

extern "C" void func_00206350(s32 arg, s32 *out) {
    s32 buf[0x30];
    s32 a;
    s32 i;
    a = arg;
    func_0020DC98(0x93, buf, 0xC0, &a, 4);
    for (i = 0; i < 0x30; i++) out[i] = buf[i];
}

extern "C" void func_002063B0(u32 i, s32 v) {
    s32 buf[2];
    if (i < 0x30) {
        buf[0] = i;
        buf[1] = v;
        func_0020DC98(0x91, 0, 0, buf, 8);
    }
}

extern "C" void func_002063F8(s32 *out) {
    s32 buf[0x30];
    s32 i;
    func_0020DC98(0x92, buf, 0xC0, 0, 0);
    for (i = 0; i < 0x30; i++) out[i] = buf[i];
}

extern "C" f32 func_00206458(s32 v) {
    s32 i;
    v = v < -4800 ? -4800 : (v > 4800 ? 4800 : v);
    i = v + 4800;
    return D_002A5DF0[i / 100] * D_002A5F78[i % 100];
}

extern "C" void func_002064C8(void) {
    D_30E4C0.m0 = 7;
    D_30E4C0.m1 = 1;
    D_30E4C0.m2 = 60;
    D_30E4C0.m4 = 0x80;
    D_30E4C0.m6 = 0x80;
}

extern "C" void func_002064F8(void) {
}

extern "C" void func_00206500(void) {
}
