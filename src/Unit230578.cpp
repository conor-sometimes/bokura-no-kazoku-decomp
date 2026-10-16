#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" unsigned int strlen(const char *s);
extern "C" char *strcpy(char *d, const char *s);
extern "C" int strcmp(const char *a, const char *b);
extern const char _ctype_[];
s32 Func235DE0(const char *fmt, ...);
inline u32 GetSR() { u32 r; __asm__ volatile("sync.p"); __asm__ volatile("mfc0 %0, $12" : "=r"(r)); __asm__ volatile("sync.p"); return r; }
inline void SetSR(u32 v) { __asm__ volatile("sync.p"); __asm__ volatile("mtc0 %0, $12" : : "r"(v)); __asm__ volatile("sync.p"); }
inline void SetSRWait(u32 v) { do SetSR(v); while (GetSR() != v); }
inline u32 DisableIntr() { u32 st; __asm__ volatile("sync.p"); __asm__ volatile("sync"); st = GetSR(); SetSRWait(st & ~1); return st; }
inline void RestoreIntr(u32 st) { __asm__ volatile("sync.p"); __asm__ volatile("sync"); SetSRWait(st); }
struct CdClock { u8 b[8]; };
struct CEnt { CEnt *m0; CEnt *m4; u8 *m8; s32 mC; };
struct CCache { CEnt e[32]; CEnt head; CEnt *free; s32 m214; s32 m218; };
extern CCache D_345180;
extern u8 D_3453C0[32][0x800];
extern s32 D_002B8C50;
extern char *D_002B8C54;
extern volatile u32 D_002B8C58;
extern char *D_002B8C60;
extern char *D_002B8C64;
extern char *D_002B8C68;
extern volatile s32 D_002B8C6C;
extern volatile s32 D_002B8C70;
extern volatile s32 D_002B8C74;
extern volatile u32 D_002B8C78;
extern s32 (*D_002B8C7C)(s32, u32 *, u32 *);
extern s32 D_002B8C80;
extern s32 D_002B8C84;
extern s32 D_002B8C88;
extern s32 D_002B8C8C;
extern CdClock D_002B8C90;
extern s32 D_002B8C98;
extern s32 D_002B8C9C;
extern s32 D_002B8CA0;
extern s32 D_002B8CA4;
extern s32 D_002B8CA8;
extern s32 D_002B8CAC;
extern s32 D_002B8CB0;
extern s64 D_002B8CB8;
extern char *D_002B8CC0;
extern volatile u32 D_002B8CC4;
extern char D_345080[];
extern char D_3573C0[];
extern u8 D_3553C0[];
extern const char D_002E48C8[];
extern const char D_002E48F0[];
extern const char D_002E4918[];
extern const char D_002E4938[];
extern const char D_002E4950[];
extern const char D_002E4968[];
extern const char D_002E4998[];
extern const char D_002E49D0[];
extern "C" s32 func_002363B0(const char *, s32);
extern "C" s32 func_002364E8(s32, s32, s32);
extern "C" s32 func_00236400(s32);
extern "C" s32 func_00236438(s32, void *, s32);
extern "C" s32 func_00236490(s32, void *, s32);
extern "C" void func_00273420(s32);
extern "C" void func_0027BD78(void);
extern "C" s32 func_001F1230(void);
extern "C" s32 func_00263870(s32);
extern "C" s32 func_00264590(void);
extern "C" s32 func_002649B8(s32, void *);
extern "C" s32 func_0023E9E8(s32);
extern "C" s32 func_002648C0(CdClock *);
extern "C" void func_00230928(char *, const char *);
extern "C" void func_002309C8(void);
extern "C" void func_002327A0(char *, const char *);
extern "C" s32 func_00230AE0(void);
extern "C" void func_00230A18(void);
extern "C" void func_00230B10(s32);
extern "C" void func_00231850(void);
extern "C" char *func_00231158(char *, const char *);
extern "C" s32 func_002314F0(u8 *, s64, s32);
extern "C" s32 func_002315B0(u8 *, s32, s32);
extern "C" s32 func_00231268(u8 *, s64, s32);
extern "C" s32 func_00231230(s32);
extern "C" s32 func_00231E48(void *, s64, s32);
extern "C" s32 func_002319F8(s64, s32, const char *, s32 *, s32 *);
extern "C" s32 func_00231BC8(s64, const char *, s32 *, s32 *);
extern "C" s32 func_00231DF8(const char *);
extern "C" char *func_00231D98(char *, char *);
extern "C" s32 func_00233D40(s32);
extern "C" void func_00233C10(s32, s32);
typedef void (*ErrCb)(const char *, s32);
extern "C" ErrCb func_00233D68(void);
extern "C" void func_00232288(const char *, s32);
inline char *strcat(char *d, const char *s) { return strcpy(d + strlen(d), s); }
struct FsOps { void *f[9]; };
extern "C" void func_00232080(s32);
extern "C" void func_002317F0(void);
extern "C" char *func_002327F8(const char *);
struct FsSub { char m0[0x880]; s32 m880; char m884[0x80]; };
struct FsEnt { s32 m0; char m4[0x80]; FsSub sub[2]; };
struct FsSlot { s32 m0; void *m4; void *m8; };
struct FsRoot { s32 m0; FsSlot m4[2]; FsEnt e[4]; };
extern FsRoot D_3574C0;
extern const char D_002E49F8[];
extern const char D_002E4A00[];
extern const char D_002E4A28[];
extern const char D_002E4A48[];
extern const char D_002E4A68[];
extern "C" void func_002300B8(void);
extern "C" void func_00230018(void);
extern "C" FsSlot *func_00233050(void);
extern "C" s32 func_00234938(void);
extern "C" s32 func_00234910(s32);
extern "C" void func_00230E50(char *, const char *);
extern "C" s32 func_00230F68(s32);
extern "C" s32 func_00230E98(s32, s32);
extern "C" s32 func_00230FE8(s32);
extern "C" s32 func_00231060(void);
extern "C" s32 func_00231068(s32, u8 *, u32, s32);
extern "C" s32 func_00231150(void);
extern "C" char *func_00232070(void);
extern "C" void func_00232338(char *, const char *);
extern "C" s32 func_00232350(void);
extern "C" s32 func_00232358(s32);
extern "C" s32 func_00232380(const char *);
extern "C" s32 func_00232450(const char *, s32);
extern "C" s32 func_00232520(const char *, void *, s32, s32);
extern "C" s32 func_00232660(const char *, s32, void *, s32);
extern "C" char *func_002327E8(void);
// @decl-end

extern "C" s32 func_00230578(const char *name) {
    char path[256];
    s32 fd, r;
    D_002B8C58 |= 1;
    func_00230928(path, name);
    fd = func_002363B0(path, 1);
    if (fd < 0) {
        if (D_002B8C50) Func235DE0(D_002E48C8, path);
        D_002B8C58 &= ~1;
        return -2;
    }
    r = func_002364E8(fd, 0, 2);
    func_00236400(fd);
    D_002B8C58 &= ~1;
    return r;
}

extern "C" s32 func_00230638(const char *name, s32 trunc) {
    char path[256];
    s32 fd;
    D_002B8C58 |= 1;
    func_00230928(path, name);
    fd = func_002363B0(path, trunc ? 0x602 : 0x202);
    if (fd < 0) {
        if (D_002B8C50) Func235DE0(D_002E48C8, path);
        D_002B8C58 &= ~1;
        return -2;
    }
    func_00236400(fd);
    D_002B8C58 &= ~1;
    return 1;
}

extern "C" s32 func_002306E8(const char *name, void *buf, s32 off, s32 size) {
    char path[256];
    s32 fd;
    D_002B8C58 |= 1;
    func_00230928(path, name);
    func_00273420(0);
    fd = func_002363B0(path, 1);
    if (fd < 0) {
        if (D_002B8C50) Func235DE0(D_002E48C8, path);
        D_002B8C58 &= ~1;
        return -2;
    }
    func_002364E8(fd, off, 0);
    if (func_00236438(fd, buf, size) <= 0) {
        func_00236400(fd);
        D_002B8C58 &= ~1;
        return -1;
    }
    func_00236400(fd);
    func_00273420(0);
    D_002B8C58 &= ~1;
    return size;
}

extern "C" s32 func_00230808(const char *name, s32 off, void *buf, s32 size) {
    char path[256];
    s32 fd;
    D_002B8C58 |= 1;
    func_00230928(path, name);
    func_00273420(0);
    fd = func_002363B0(path, 2);
    if (fd < 0) {
        if (D_002B8C50) Func235DE0(D_002E48C8, path);
        D_002B8C58 &= ~1;
        return -2;
    }
    func_002364E8(fd, off, 0);
    if (func_00236490(fd, buf, size) <= 0) {
        func_00236400(fd);
        D_002B8C58 &= ~1;
        return -1;
    }
    func_00236400(fd);
    func_00273420(0);
    D_002B8C58 &= ~1;
    return size;
}

extern "C" void func_00230928(char *dst, const char *name) {
    strcpy(dst, D_345080);
    return (void)strcpy(dst + strlen(dst), name);
}

extern "C" char *func_00230970(void) {
    return D_345080;
}

extern "C" char *func_00230980(const char *s) {
    if (s == 0) return strcpy(D_345080, D_002B8C54);
    return strcpy(D_345080, s);
}

extern "C" void func_002309C8(void) {
    u32 st;
    asm volatile("sync.p");
    asm volatile("mfc0 %0, $12" : "=r"(st));
    asm volatile("sync.p");
    if (!(st & 0x10000)) {
        func_0027BD78();
        Func235DE0(D_002E48F0);
        func_0027BD78();
    }
    return (void)func_001F1230();
}

extern "C" void func_00230A18(void) {
    while (func_00263870(1)) func_002309C8();
}

extern "C" void func_00230A48(FsOps *t) {
    t->f[0] = (void *)func_00230E50;
    t->f[1] = (void *)func_00230F68;
    t->f[2] = (void *)func_00230E98;
    t->f[3] = (void *)func_00230FE8;
    t->f[4] = (void *)func_00231060;
    t->f[5] = (void *)func_00231068;
    t->f[6] = (void *)func_00231150;
    t->f[8] = (void *)func_00232070;
    t->f[7] = (void *)func_00232080;
    func_00232080(0);
    return (void)func_002317F0();
}

extern "C" void func_00230AD8(void) {
}

extern "C" s32 func_00230AE0(void) {
    s32 r;
    while ((r = func_00264590()) < 0) func_002309C8();
    return r;
}

extern "C" void func_00230B10(s32 a) {
    u8 buf[16];
    func_002649B8(a, buf);
}

extern "C" void func_00230B30(s32 n) {
    u32 st;
    s32 t;
    CdClock clk;
    if (D_345180.m214) {
        D_002B8CB0 += n;
        if (D_002B8CB0 > 0x400) {
            if (func_00230AE0() == 1) {
                func_00231850();
                D_002B8C6C |= 1;
            } else {
                D_002B8C6C &= ~1;
            }
            D_002B8CB0 = 0;
        }
    }
    if (D_002B8C78 & 1) {
        st = DisableIntr();
        D_002B8C78 &= ~1;
        RestoreIntr(st);
        func_00230B10(0);
        func_00230A18();
    }
    if (D_002B8C78 & 2) {
        st = DisableIntr();
        D_002B8C78 &= ~2;
        RestoreIntr(st);
        func_00230B10(1);
        func_00230A18();
    }
    if (D_002B8C80) {
        t = func_0023E9E8(-1);
        if (D_002B8C84 != t || !D_002B8C98) {
            if (--D_002B8C88 < 0) {
                if (func_002648C0(&clk)) {
                    st = DisableIntr();
                    D_002B8C90.b[0] = clk.b[0];
                    D_002B8C90.b[1] = clk.b[1];
                    D_002B8C90.b[2] = clk.b[2];
                    D_002B8C90.b[3] = clk.b[3];
                    D_002B8C90.b[4] = clk.b[4];
                    D_002B8C90.b[5] = clk.b[5];
                    D_002B8C90.b[6] = clk.b[6];
                    D_002B8C90.b[7] = clk.b[7];
                    RestoreIntr(st);
                    D_002B8C98 = 1;
                    D_002B8C88 = D_002B8C8C;
                }
            }
            D_002B8C84 = t;
        }
    }
}

extern "C" void func_00230E50(char *dst, const char *name) {
    strcpy(dst, D_002B8C60);
    return (void)func_00231158(dst + strlen(dst), name);
}

extern "C" s32 func_00230E98(s32 a, s32 b) {
    u32 st;
    if (a == 0) {
        st = DisableIntr();
        if (b) {
            D_002B8C78 |= 1;
            D_002B8C78 &= ~2;
        } else {
            D_002B8C78 &= ~1;
            D_002B8C78 |= 2;
        }
        RestoreIntr(st);
        return 0;
    }
    return 0;
}

extern "C" s32 func_00230F68(s32 x) {
    switch (x) {
    case 0: return D_002B8C6C & 1;
    case 1: return (D_002B8C6C >> 1) & 1;
    case 2: return D_002B8C70 + D_002B8C74;
    }
    return 0;
}

extern "C" s32 func_00230FE8(s32 x) {
    u32 a, b;
    switch (D_002B8C7C(x, &a, &b)) {
    case 1: return b;
    case -3: return -2;
    case -2: func_00231850();
    case -1: 
    default: return -1;
    }
}

extern "C" s32 func_00231060(void) {
    return -2;
}

extern "C" s32 func_00231068(s32 fd, u8 *buf, u32 off, s32 size) {
    u32 a, b;
    s32 n;
    switch (D_002B8C7C(fd, &a, &b)) {
    case -2: func_00231850(); return -1;
    case 1:
        n = func_002314F0(buf, ((u64)a << 11) + off, size);
        switch (n) { case -2: case -1: break; case 1: return size; } return -1;
    case -3: return -2;
    case -1: default: return -1;
    }
}

extern "C" s32 func_00231150(void) {
    return -2;
}

extern "C" char *func_00231158(char *dst, const char *name) {
    s32 i;
    char *ext;
    dst[0] = 0;
    if (name[0] != '/') strcpy(dst, D_002B8C64);
    strcat(dst, name);
    for (i = 0; dst[i]; i++) {
        if (dst[i] == '/') dst[i] = '\\';
        else if ((u8)dst[i] >= 'a' && (u8)dst[i] <= 'z') dst[i] -= 0x20;
    }
    ext = D_002B8C68;
    return strcpy(dst + strlen(dst), ext);
}

extern "C" s32 func_00231230(s32 x) {
    if (D_002B8C9C && D_002B8CA4 == 1) return x + D_002B8CA0;
    return x;
}

INCLUDE_ASM("asm/nonmatchings/Unit230578", func_00231268);

extern "C" s32 func_002314F0(u8 *buf, s64 off, s32 size) {
    s32 r, sec;
    if (D_002B8CB8 == off) {
        sec = off / 0x800 - 32;
        r = func_002315B0(D_3553C0, sec < 0 ? 0 : sec, 1);
        if (r < 0) return r;
    }
    D_002B8CB8 = off;
    return func_00231268(buf, off, size);
}

INCLUDE_RODATA("asm/nonmatchings/Unit230578", D_002E48C8);
INCLUDE_RODATA("asm/nonmatchings/Unit230578", D_002E48F0);
INCLUDE_RODATA("asm/nonmatchings/Unit230578", D_002E4900);
INCLUDE_RODATA("asm/nonmatchings/Unit230578", D_002E4908);
INCLUDE_RODATA("asm/nonmatchings/Unit230578", D_002E4910);
INCLUDE_ASM("asm/nonmatchings/Unit230578", func_002315B0);

extern "C" void func_002317F0(void) {
    CEnt *e;
    s32 i;
    D_345180.free = 0;
    for (i = 0, e = D_345180.e; i < 32; i++, e++) {
        e->m8 = D_3453C0[0] + i * 0x800;
        e->m4 = D_345180.free;
        D_345180.free = e;
    }
    D_345180.m218 = 1;
    D_345180.head.m0 = &D_345180.head;
    D_345180.m214 = 0;
    D_345180.head.m4 = &D_345180.head;
}

extern "C" void func_00231850(void) {
    CEnt *e, *n;
    D_345180.m218 = 1;
    D_345180.m214 = 0;
    n = D_345180.head.m4;
    while ((e = n) != &D_345180.head) {
        n = e->m4;
        e->m4 = D_345180.free;
        D_345180.free = e;
    }
    D_345180.head.m0 = &D_345180.head;
    D_345180.head.m4 = &D_345180.head;
    D_002B8CB8 = -1;
}

INCLUDE_ASM("asm/nonmatchings/Unit230578", func_002318B8);

#define READ(b, p, n) while ((r = func_00231E48(b, p, n)) != 1) if (r == -2) return r
extern "C" s32 func_002319F8(s64 pt, s32 size, const char *path, s32 *a1, s32 *a2) {
    u16 rec[8];
    char comp[256];
    char name[256];
    s32 r, off, idx, dirno;
    READ(rec, pt, 8);
    dirno = 1;
    off = (rec[0] + 9) & ~1;
    idx = 2;
    while (off < size) {
        if (func_00231DF8(path)) return func_00231BC8(((rec[2] << 16) | rec[1]) << 11, path, a1, a2);
        path = func_00231D98(comp, (char *)path);
        do {
            READ(rec, pt + off, 8);
            if (rec[3] == dirno) {
                READ(name, pt + off + 8, rec[0]);
                name[rec[0]] = 0;
                if (strcmp(name, comp) == 0) break;
            }
            off += (rec[0] + 9) & ~1;
            idx++;
        } while (off < size);
        dirno = idx;
    }
    return -3;
}

struct DirRec { u16 m0; u16 m2; u16 m4; u16 m6; u16 m8; u16 mA; u16 mC; u8 pad[0xB]; u8 m19; u8 pad2[6]; u8 m20; u8 m21; };
#define READ(b, p, n) while ((r = func_00231E48(b, p, n)) != 1) if (r == -2) return r
extern "C" s32 func_00231BC8(s64 dir, const char *name, s32 *a1, s32 *a2) {
    DirRec rec;
    char buf[256];
    s32 r, off, total;
    READ(&rec, dir, 0x22);
    total = (rec.mC << 16) | rec.mA;
    off = (rec.m0 + 1) & ~1;
    do {
        READ(&rec, dir + off, 0x22);
        if (rec.m0 != 0 && rec.m20 != 0 && !(rec.m19 & 2)) {
            READ(buf, dir + off + 0x21, rec.m20);
            buf[rec.m20] = 0;
            if (strcmp(buf, name) == 0) {
                *a1 = (rec.m4 << 16) | rec.m2;
                *a2 = (rec.mC << 16) | rec.mA;
                return 1;
            }
        }
        if (rec.m0 == 0 || (u32)((off & 0x7FF) + 0x22) > 0x800) off = (off & ~0x7FF) + 0x800;
        else off += rec.m0;
    } while (off < total);
    return -3;
}

extern "C" char *func_00231D98(char *dst, char *src) {
    while (*src && *src != '\\') *dst++ = *src++;
    *dst = 0;
    if (*src == '\\') src++;
    return src;
}

extern "C" s32 func_00231DF8(const char *s) {
    while (*s && *s != '\\') s++;
    return *s == 0;
}

INCLUDE_ASM("asm/nonmatchings/Unit230578", func_00231E48);
INCLUDE_RODATA("asm/nonmatchings/Unit230578", D_002E4990);
INCLUDE_RODATA("asm/nonmatchings/Unit230578", D_002E4998);
INCLUDE_RODATA("asm/nonmatchings/Unit230578", D_002E49D0);

extern "C" char *func_00232070(void) {
    return D_002B8C60;
}

extern "C" void func_00232080(s32) {
}

extern "C" void *func_00232088(void *f) {
    void *old = (void *)D_002B8C7C;
    D_002B8C7C = (s32 (*)(s32, u32 *, u32 *))f;
    return old;
}

extern "C" s32 func_002320A0(s32 x) {
    s32 old = D_002B8C80;
    if (old != x) {
        D_002B8C80 = x;
        D_002B8C84 = 0;
        D_002B8C88 = 0;
        D_002B8C8C = 30;
        D_002B8C98 = 0;
    }
    return old;
}

extern "C" s32 func_002320E8(void) {
    return D_002B8C80;
}

class CUnk2320F8 {
public:
    int Func2320F8();
};
int CUnk2320F8::Func2320F8() {
    u32 st;
    if (!D_002B8C98 || !D_002B8C80) return 0;
    if (this) {
        st = DisableIntr();
        *(CdClock *)this = D_002B8C90;
        RestoreIntr(st);
    }
    return 1;
}

extern "C" s32 func_002321B0(s32 x) {
    s32 old = D_002B8CA8;
    if ((u32)x >= 2) return -1;
    D_002B8CA8 = x;
    D_002B8CAC = 1;
    return old;
}

extern "C" s32 func_002321E8(void) {
    return D_002B8CA8;
}

extern "C" char *func_002321F8(FsOps *t) {
    t->f[0] = (void *)func_00232338;
    t->f[2] = (void *)func_00232350;
    t->f[1] = (void *)func_00232358;
    t->f[3] = (void *)func_00232380;
    t->f[4] = (void *)func_00232450;
    t->f[5] = (void *)func_00232520;
    t->f[6] = (void *)func_00232660;
    t->f[8] = (void *)func_002327E8;
    t->f[7] = (void *)func_002327F8;
    return func_002327F8(0);
}

extern "C" void func_00232280(void) {
}

extern "C" void func_00232288(const char *name, s32 err) {
    if (err < -4 && (err >= -6 || err == (s32)0xFFFF0005 || err == -19)) {
        if (D_002B8C50) Func235DE0(D_002E4998, err);
        func_00233C10(3, func_00233D40(3));
        if (func_00233D68()) func_00233D68()(name, err);
    }
}

extern "C" void func_00232338(char *a, const char *b) {
    return (void)func_002327A0(a, b);
}

extern "C" s32 func_00232350(void) {
    return 0;
}

extern "C" s32 func_00232358(s32 x) {
    if (x == 1) return D_002B8CC4 & 1;
    return 0;
}

extern "C" s32 func_00232380(const char *name) {
    char path[256];
    s32 fd, r;
    D_002B8CC4 |= 1;
    func_002327A0(path, name);
    fd = func_002363B0(path, 1);
    if (fd < 0) {
        func_00232288(name, fd);
        if (D_002B8C50) Func235DE0(D_002E49D0, path);
        D_002B8CC4 &= ~1;
        return -2;
    }
    r = func_002364E8(fd, 0, 2);
    func_00236400(fd);
    D_002B8CC4 &= ~1;
    return r;
}

extern "C" s32 func_00232450(const char *name, s32 trunc) {
    char path[256];
    s32 fd;
    D_002B8CC4 |= 1;
    func_002327A0(path, name);
    fd = func_002363B0(path, trunc ? 0x602 : 0x202);
    if (fd < 0) {
        func_00232288(name, fd);
        if (D_002B8C50) Func235DE0(D_002E49D0, path);
        D_002B8CC4 &= ~1;
        return -2;
    }
    func_00236400(fd);
    D_002B8CC4 &= ~1;
    return 1;
}

extern "C" s32 func_00232520(const char *name, void *buf, s32 off, s32 size) {
    char path[256];
    s32 fd, n;
    D_002B8CC4 |= 1;
    func_002327A0(path, name);
    func_00273420(0);
    fd = func_002363B0(path, 1);
    if (fd < 0) {
        func_00232288(name, fd);
        if (D_002B8C50) Func235DE0(D_002E49D0, path);
        D_002B8CC4 &= ~1;
        return -2;
    }
    func_002364E8(fd, off, 0);
    n = func_00236438(fd, buf, size);
    if (n <= 0) {
        func_00236400(fd);
        func_00232288(name, n);
        D_002B8CC4 &= ~1;
        return -1;
    }
    func_00236400(fd);
    func_00273420(0);
    D_002B8CC4 &= ~1;
    return size;
}

extern "C" s32 func_00232660(const char *name, s32 off, void *buf, s32 size) {
    char path[256];
    s32 fd, n;
    D_002B8CC4 |= 1;
    func_002327A0(path, name);
    func_00273420(0);
    fd = func_002363B0(path, 2);
    if (fd < 0) {
        func_00232288(name, fd);
        if (D_002B8C50) Func235DE0(D_002E49D0, path);
        D_002B8CC4 &= ~1;
        return -2;
    }
    func_002364E8(fd, off, 0);
    n = func_00236490(fd, buf, size);
    if (n <= 0) {
        func_00236400(fd);
        func_00232288(name, n);
        D_002B8CC4 &= ~1;
        return -1;
    }
    func_00236400(fd);
    func_00273420(0);
    D_002B8CC4 &= ~1;
    return size;
}

extern "C" void func_002327A0(char *dst, const char *name) {
    strcpy(dst, D_3573C0);
    return (void)strcpy(dst + strlen(dst), name);
}

extern "C" char *func_002327E8(void) {
    return D_3573C0;
}

extern "C" char *func_002327F8(const char *s) {
    if (s == 0) return strcpy(D_3573C0, D_002B8CC0);
    return strcpy(D_3573C0, s);
}

INCLUDE_RODATA("asm/nonmatchings/Unit230578", D_002E49F8);
INCLUDE_RODATA("asm/nonmatchings/Unit230578", D_002E4A00);
INCLUDE_RODATA("asm/nonmatchings/Unit230578", D_002E4A28);
INCLUDE_RODATA("asm/nonmatchings/Unit230578", D_002E4A48);
INCLUDE_RODATA("asm/nonmatchings/Unit230578", D_002E4A68);
INCLUDE_ASM("asm/nonmatchings/Unit230578", func_00232840);

extern "C" void func_002328E8(void) {
}

extern "C" s32 func_002328F0(s32 x) {
    s32 old = D_3574C0.m0;
    if (x < 2) {
        if (x >= 0) {
            D_3574C0.m0 = x;
            return old;
        }
    }
    if (D_002B8C50) Func235DE0(D_002E4A00, x);
    return old;
}

extern "C" s32 func_00232958(s32 n) {
    FsSlot *t = func_00233050();
    s32 old = t->m0;
    if (n == -1) n = func_00234938();
    if (!func_00234910(n)) {
        if (D_002B8C50) Func235DE0(D_002E4A28, n);
        return old;
    }
    switch (n) {
    case 0: case 1: case 3:
        t->m0 = n;
        if (D_002B8C50) Func235DE0(D_002E4A48, n);
        break;
    case 2:
    default:
        if (D_002B8C50) Func235DE0(D_002E4A68, n);
        break;
    }
    return old;
}

extern "C" s32 func_00232A50(void) {
    return func_00233050()->m0;
}

extern "C" s32 func_00232A70(s32 i, s32 n) {
    FsSlot *t = &D_3574C0.m4[i];
    s32 old = t->m0;
    if (n == -1) n = func_00234938();
    if (!func_00234910(n)) {
        if (D_002B8C50) Func235DE0(D_002E4A28, n);
        return old;
    }
    switch (n) {
    case 0: case 1: case 3:
        t->m0 = n;
        if (D_002B8C50) Func235DE0(D_002E4A48, n);
        break;
    case 2:
    default:
        if (D_002B8C50) Func235DE0(D_002E4A68, n);
        break;
    }
    return old;
}
