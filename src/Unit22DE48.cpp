#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct DL { DL *m0; DL *m4; s32 m8; s32 mC; };
struct CN { CN *m0; u32 m4; u8 m8; u8 m9; u8 pad[0xE]; };
struct FEnt {
    u8 pad0[4]; u8 m4; u8 m5; u8 m6; u8 pad7[0x81]; u32 m88; u32 m8C; u32 m90; s32 m94; s32 m98; u32 m9C; s32 mA0;
    s32 mA4; s32 mA8; CN *mAC; s32 mB0; DL mB4; s32 mC4; volatile s32 mC8; volatile s32 mCC;
};
struct FSys { FEnt f[64]; u8 m3400[0x400]; void *m3800; CN m3804[64]; CN *m3E04; DL m3E08[256]; DL *m4E08; };
extern FSys D_3401E0;
extern const char D_002E47F0[];
s32 Func235DE0(const char *fmt, ...);
extern "C" void func_0027BD78(void);
extern "C" s32 func_0022EF38(FEnt *, s32);
extern "C" s32 func_0022F078(FEnt *, s32, u8 *, s32);
extern "C" s32 func_0022E2C8(s32, s32);
extern "C" s32 func_0022F6D0(FEnt *);
extern "C" void func_0022F860(FEnt *, s32, s32);
extern "C" s32 func_0022F000(FEnt *);
extern "C" s32 func_0022FB30(FEnt *, s32);
extern "C" s32 func_0022FBF8(FEnt *);
extern "C" void func_0022FD78(FEnt *, s32, s32);
extern "C" s32 func_0022FDB8(FEnt *, u32 *, u32, s32);
#define FDOK(fd, f) ((u32)((fd) - 1) < 0x3F && ((f) = &D_3401E0.f[fd])->m4)
#define CHECK_INTR() do { \
    u32 st_; \
    asm volatile("sync.p"); \
    asm volatile("mfc0 %0, $12" : "=r"(st_)); \
    asm volatile("sync.p"); \
    if (!(st_ & 0x10000)) { \
        func_0027BD78(); \
        Func235DE0(D_002E47F0); \
        func_0027BD78(); \
    } \
} while (0)

extern s32 D_002B8C50;
extern const char D_002E4828[];
extern "C" void func_002332C0(s32, FEnt *, s32);
extern "C" void func_0022FA70(FEnt *);
extern "C" s32 func_0022F0A8(FEnt *);
extern "C" s32 func_0022F180(FEnt *, s32, s32, u8 *, s32);

inline u32 GetSR() { u32 r; __asm__ volatile("sync.p"); __asm__ volatile("mfc0 %0, $12" : "=r"(r)); __asm__ volatile("sync.p"); return r; }
inline void SetSR(u32 v) { __asm__ volatile("sync.p"); __asm__ volatile("mtc0 %0, $12" : : "r"(v)); __asm__ volatile("sync.p"); }
inline void SetSRWait(u32 v) { do SetSR(v); while (GetSR() != v); }
inline u32 DisableIntr() { u32 st; __asm__ volatile("sync.p"); __asm__ volatile("sync"); st = GetSR(); SetSRWait(st & ~1); return st; }
inline void RestoreIntr(u32 st) { __asm__ volatile("sync.p"); __asm__ volatile("sync"); SetSRWait(st); }
extern "C" s32 func_00232F18(s32);
extern "C" s32 func_0022F418(FEnt *, s32, s32, u8 *, s32);
extern "C" s32 func_0022F560(FEnt *, s32, s32, u8 *, s32);
extern "C" s32 func_00233278(s32, s32, char *, s32, u32, u8 *, s32, s32, void *, FEnt *);
extern "C" void func_0022F658(FEnt *, s32, s32);
extern "C" void func_0022F8A0(FEnt *, s32, s32);

extern "C" void func_00230928(char *, const char *);
extern "C" s32 func_00230280(s32, void *(*)(u32));
extern void *(*D_002B91A4)(u32 n);
extern void *(*D_002B91A8)(u32 n);

extern "C" void func_00230528(void);
struct FsOps { void *f[9]; };
struct S344FF0 { u8 m0[0x24]; FsOps m24; FsOps m48; u8 m6C[4]; };
extern S344FF0 D_344FF0;
extern "C" void func_002304A0(S344FF0 *);
extern "C" void func_00230A48(FsOps *);
extern "C" char *func_002321F8(void *);
extern "C" void func_00230AD8(void);
extern "C" s32 func_00232280(void);

extern "C" s32 func_00232F38(void);
extern "C" void func_00232F58(void *);
extern "C" s32 func_00232F88(void);
extern "C" void func_00232FA8(void *);
extern "C" s32 func_002300B8(const char *, u8 *);
extern "C" s32 func_00230018(const char *);

typedef s32 (*Fn22FF)(void *);
typedef s32 (*Fn22FF2)(void *, void *);

extern "C" s32 func_0022E230(s32, s32, s32);
extern "C" s32 func_0022DF28(s32, u8 *, u32);
extern "C" s32 func_0022E0E8(s32, u8 *, s32);
extern "C" void func_00230530(char *, const char *);
extern "C" s32 func_00230548(void);
extern "C" s32 func_00234938(void);
extern "C" FsOps *func_00230460(s32);
typedef void (*FsFn0)(void);
typedef void (*FsFn1)(s32);
extern "C" void func_00273420(s32);
extern "C" s32 func_0022DD78(const char *, s32);
extern "C" void func_0022DDE8(s32);
extern const char D_002E4850[], D_002E4868[], D_002E4888[];
extern volatile u32 D_002B8C58;
extern "C" s32 func_00230550(s32);
extern "C" s32 func_00230578(void);
extern "C" s32 func_00230638(void);
extern "C" s32 func_002306E8(void);
extern "C" s32 func_00230808(void);
extern "C" s32 func_00230970(void);
extern "C" s32 func_00230980(s32);

extern "C" long func_0022DB38(s32);
extern "C" s32 func_0022DD20(void);
extern char D_002E48A8[];
extern "C" s32 func_0022FF58(void *a);
extern "C" s32 func_0022FF18(void *a, void *b);
extern void (*D_002B91B0)(void *p);
extern void *(*D_002B91AC)(void *p, u32 n);
typedef long (*FnL)(void *);

#define RCMIN(a, b) ((a) < (b) ? (a) : (b))
#define RCCLAMPZ(x) ((x) < 0 ? 0 : (x))
extern "C" void func_0022F958(FEnt *, s32);

extern "C" s32 func_00232A50(void);
extern "C" void func_00232E98(s32 dev, const char *path);
extern "C" char *func_00232D90(s32 dev);
extern "C" char *func_00232C40(s32 dev);
extern "C" char *strcpy(char *d, const char *s);
extern "C" unsigned int strlen(const char *s);
extern const char D_002E4800[];
extern "C" s32 func_0022EA08(s32 dev, char *path, s32 a, s32 b, s32 c, s32 d);
// @decl-end

extern "C" void func_0022DE48(s32 fd) {
    FEnt *f;
    if (FDOK(fd, f)) return (void)func_0022EF38(f, 1);
}

extern "C" s32 func_0022DEA8(s32 fd) {
    FEnt *f;
    s32 r;
    if (FDOK(fd, f)) {
        r = 1;
        if (f->mCC > 0) r = 5;
        if (f->m90 <= f->m8C) r |= 8;
        if (f->m5) r |= 2;
    } else {
        r = 0;
    }
    return r;
}

extern "C" s32 func_0022DF28(s32 fd, u8 *buf, u32 n) {
    FEnt *f;
    s32 left, r;
    if (FDOK(fd, f) && (f->m88 & 1)) {
        while (!(f->mC8 & 2)) CHECK_INTR();
        if (!(n < f->m90 - f->m8C)) n = f->m90 - f->m8C;
        left = n;
        if (left > 0) {
            while (f->m8C < f->m90) {
                r = func_0022F078(f, 2, buf, left);
                left -= r;
                buf += r;
                CHECK_INTR();
                if (left <= 0) break;
            }
        }
        if (!(f->m88 & 0x8000)) func_0022E2C8(fd, 0);
        return n;
    }
    return -1;
}

extern "C" s32 func_0022E0E8(s32 fd, u8 *buf, s32 n) {
    FEnt *f;
    s32 left, r;
    if (FDOK(fd, f) && (f->m88 & 2)) {
        left = n;
        if (left > 0) {
            do {
                r = func_0022F078(f, 3, buf, left);
                left -= r;
                buf += r;
                CHECK_INTR();
            } while (left > 0);
        }
        if (!(f->m88 & 0x8000)) func_0022E2C8(fd, 0);
        if (f->m90 < f->m8C) f->m90 = f->m8C;
        return n;
    }
    return -1;
}

extern "C" s32 func_0022E230(s32 fd, s32 off, s32 whence) {
    FEnt *f;
    if (FDOK(fd, f)) {
        switch (whence) {
        case 0:
            f->m8C = off;
            break;
        case 1:
            f->m8C += off;
            break;
        case 2:
            f->m8C = f->m90 - off;
            break;
        }
        return f->m8C;
    }
    return -1;
}

extern "C" s32 func_0022E2C8(s32 fd, s32 nowait) {
    FEnt *f;
    s32 r = 0;
    if (FDOK(fd, f)) {
        do {
            r = *(volatile s32 *)&f->mCC > 0;
            CHECK_INTR();
            if (!r) break;
        } while (!nowait);
    }
    return r;
}

extern "C" s32 func_0022E398(s32 fd) {
    FEnt *f;
    s32 r;
    if (FDOK(fd, f)) r = func_0022F6D0(f);
    else r = 0;
    return r;
}

extern "C" void func_0022E3F8(s32 fd, s32 id, s32 v) {
    FEnt *f;
    if (FDOK(fd, f)) return func_0022F860(f, id, v);
}

extern "C" s32 func_0022E450(s32 fd, s32 v) {
    FEnt *f;
    s32 old;
    if (FDOK(fd, f)) {
        old = f->m5;
        f->m5 = v;
        if (!f->m5) func_0022F000(f);
        return old;
    }
    return 0;
}

extern "C" s32 func_0022E4C8(s32 fd) {
    FEnt *f;
    if (FDOK(fd, f)) return f->m94 + f->mA4;
    return 0;
}

extern "C" s32 func_0022E518(s32 fd) {
    FEnt *f;
    if (FDOK(fd, f)) return f->mA4;
    return -1;
}

extern "C" s32 func_0022E560(s32 fd) {
    FEnt *f;
    if (FDOK(fd, f)) return f->m98;
    return 0;
}

extern "C" s32 func_0022E5A8(s32 fd) {
    FEnt *f;
    s32 r;
    if (FDOK(fd, f)) {
        r = *(volatile s32 *)&f->mA8;
        func_0022F000(f);
    } else {
        r = 0;
    }
    return r;
}

extern "C" void func_0022E618(s32 fd, s32 n) {
    FEnt *f;
    s32 k;
    u32 st;
    if (!FDOK(fd, f)) return;
    k = RCCLAMPZ(RCMIN(n, *(volatile s32 *)&f->mA8));
    f->mA4 = (u32)(f->mA4 + k) % (u32)f->m98;
    st = DisableIntr();
    f->mA8 -= k;
    RestoreIntr(st);
    func_0022F958(f, k);
    return (void)func_0022F000(f);
}

extern "C" s32 func_0022E770(s32 fd, s32 off) {
    FEnt *f;
    if (FDOK(fd, f)) return func_0022FB30(f, off);
    return -1;
}

extern "C" s32 func_0022E7C8(s32 fd) {
    FEnt *f;
    s32 r;
    if (FDOK(fd, f)) r = func_0022FBF8(f);
    else r = 0;
    return r;
}

extern "C" void func_0022E828(s32 fd, s32 a, s32 b) {
    FEnt *f;
    if (FDOK(fd, f)) return func_0022FD78(f, a, b);
}

extern "C" s32 func_0022E880(s32 fd, u32 *out, u32 max, s32 len) {
    FEnt *f;
    s32 r;
    if (FDOK(fd, f)) r = func_0022FDB8(f, out, max, len);
    else r = 0;
    return r;
}

extern "C" s32 func_0022E8E0(const char *path, s32 a, s32 b, s32 c, s32 d) {
    char buf[0x100];
    s32 dev = func_00232A50();
    func_00232E98(dev, path);
    if (*func_00232D90(dev) != '/' && path[0] != '/') strcpy(buf, func_00232C40(dev));
    else buf[0] = D_002E4800[0];
    if (path[0] != '/') {
        char *s = func_00232D90(dev);
        strcpy(buf + strlen(buf), s);
    }
    strcpy(buf + strlen(buf), path);
    return func_0022EA08(dev, buf, a, b, c, d);
}

INCLUDE_RODATA("asm/nonmatchings/Unit22DE48", D_002E47F0);
INCLUDE_RODATA("asm/nonmatchings/Unit22DE48", D_002E4800);
INCLUDE_ASM("asm/nonmatchings/Unit22DE48", func_0022EA08);
INCLUDE_RODATA("asm/nonmatchings/Unit22DE48", D_002E4828);
INCLUDE_RODATA("asm/nonmatchings/Unit22DE48", D_002E4850);
INCLUDE_RODATA("asm/nonmatchings/Unit22DE48", D_002E4868);
INCLUDE_RODATA("asm/nonmatchings/Unit22DE48", D_002E4888);
INCLUDE_RODATA("asm/nonmatchings/Unit22DE48", D_002E48A8);
INCLUDE_RODATA("asm/nonmatchings/Unit22DE48", D_002E48C0);

extern "C" void func_0022EE38(FEnt *f, s32 x, s32 n) {
    f->mC8 |= 1;
    f->mCC--;
    if (n <= 0) {
        f->mC8 |= 4;
        if (D_002B8C50) return (void)Func235DE0(D_002E4828, (char *)f + 8);
    }
}

extern "C" void func_0022EEA8(FEnt *f, s32 x, s32 n) {
    f->m90 = n;
    f->mC8 |= 2;
    f->mCC--;
    func_0022F000(f);
    if (n <= 0) {
        f->mC8 |= 4;
        if (D_002B8C50) return (void)Func235DE0(D_002E4828, (char *)f + 8);
    }
}

extern "C" s32 func_0022EF38(FEnt *f, s32 x) {
    func_002332C0(f->m6, f, x);
    while (f->mCC > 0) CHECK_INTR();
    func_0022FA70(f);
    ((s32 (*)(FEnt *, s32, s32, s32))func_0022F6D0)(f, 0, 0, 0);
    ((s32 (*)(FEnt *, s32, s32))func_0022FBF8)(f, 0, 0);
    f->m4 = 0;
}

extern "C" s32 func_0022F000(FEnt *f) {
    if (f->m5) goto out;
    if (!(f->m8C < f->m90)) goto out;
    if (f->mCC) goto out;
    if (!(f->mC8 & 2)) goto out;
    if (f->m9C < *(volatile u32 *)&f->mA8) goto out;
    if (f->mCC) goto out;
    return func_0022F0A8(f);
out:;
}

extern "C" s32 func_0022F078(FEnt *f, s32 a, u8 *b, s32 c) {
    return func_0022F180(f, 1, a, b, c);
}

extern "C" s32 func_0022F0A8(FEnt *f) {
    s32 total = 0;
    s32 avail = (f->m98 - f->mA8) & ~0x7FF;
    u32 wp = f->mA0;
    s32 n, r;
    if (avail > 0) {
        while (f->m8C < f->m90) {
            n = avail - total;
            if (!(wp + n < (u32)f->m98)) n = f->m98 - wp;
            r = func_0022F180(f, 0, 2, (u8 *)(f->m94 + wp), n);
            wp += r;
            total += r;
            if (!(wp < (u32)f->m98)) wp = 0;
            if (r < n || total >= avail) break;
        }
    }
    return total;
}

INCLUDE_ASM("asm/nonmatchings/Unit22DE48", func_0022F180);

extern "C" s32 func_0022F3B0(FEnt *f, s32 a, s32 b, u8 *c, s32 n) {
    if (a == 0 && f->m90 < f->m8C + n) return func_0022F418(f, a, b, c, f->m90 - f->m8C);
    return func_0022F418(f, a, b, c, n);
}

INCLUDE_ASM("asm/nonmatchings/Unit22DE48", func_0022F418);

extern "C" s32 func_0022F560(FEnt *f, s32 a, s32 b, u8 *c, s32 n) {
    u32 st;
    if (n <= 0) return 0;
    if (!func_00233278(a, f->m6, (char *)f + 8, b, f->m8C, c, n, 1, (void *)func_0022F658, f)) return 0;
    f->m8C += n;
    st = DisableIntr();
    f->mCC++;
    RestoreIntr(st);
    return n;
}

extern "C" void func_0022F658(FEnt *f, s32 x, s32 n) {
    if (n > 0 && (f->m88 & 0x10000)) {
        f->mA0 = (u32)(f->mA0 + n) % (u32)f->m98;
        f->mA8 += n;
        func_0022F8A0(f, x, n);
    }
    f->mCC--;
}

INCLUDE_ASM("asm/nonmatchings/Unit22DE48", func_0022F6D0);

extern "C" void func_0022F860(FEnt *f, s32 id, s32 v) {
    CN *e;
    for (e = f->mAC; e; e = e->m0) {
        if (e->m9 == id) e->m8 = v;
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit22DE48", func_0022F8A0);

INCLUDE_ASM("asm/nonmatchings/Unit22DE48", func_0022F958);

INCLUDE_ASM("asm/nonmatchings/Unit22DE48", func_0022FA70);

extern "C" s32 func_0022FB30(FEnt *f, s32 off) {
    u32 st = DisableIntr();
    s32 r = -1;
    DL *n = f->mB4.m4;
    DL *h = &f->mB4;
    for (; n != h; n = n->m4) { if (off < n->mC) { r = n->m8 + off; break; } off -= n->mC; }
    RestoreIntr(st);
    return r;
}

INCLUDE_ASM("asm/nonmatchings/Unit22DE48", func_0022FBF8);

extern "C" void func_0022FD78(FEnt *f, s32 a, s32 b) { CN *c; for (c = (CN *)f->mC4; c; c = c->m0) if (c->m9 == a) c->m8 = b; }

INCLUDE_ASM("asm/nonmatchings/Unit22DE48", func_0022FDB8);

extern "C" void func_0022FE80(s32 a, s32 b) { if (a == -1) a = func_00234938(); FsOps *f = func_00230460(a); if (f) ((FsFn1)f->f[7])(b); }

INCLUDE_ASM("asm/nonmatchings/Unit22DE48", func_0022FED0);

extern "C" s32 func_0022FF18(void *a, void *b) { return ((Fn22FF2)func_00232F38())(a, b); }

extern "C" s32 func_0022FF58(void *a) { return ((Fn22FF)func_00232F88())(a); }

extern "C" s32 func_0022FF88(void *a) { s32 r = func_00232F38(); if (!a) a = (void *)func_002300B8; func_00232F58(a); return r; }

extern "C" s32 func_0022FFD0(void *a) { s32 r = func_00232F88(); if (!a) a = (void *)func_00230018; func_00232FA8(a); return r; }

extern "C" s32 func_00230018(const char *name) {
    s32 r;
    if (!name) return -2;
    r = -2;
    func_00273420(0);
    s32 fd = func_0022DD78(name, 1);
    if (fd != -1) { r = func_0022E230(fd, 0, 2); func_0022DDE8(fd); }
    if (D_002B8C50) Func235DE0(D_002E4850, name, r);
    return r;
}

extern "C" s32 func_002300B8(const char *name, u8 *buf) {
    if (!name) return -2;
    func_00273420(0);
    s32 r = -2;
    s32 fd = func_0022DD78(name, 1);
    if (fd != -1) {
        r = func_0022E230(fd, 0, 2);
        func_0022E230(fd, 0, 0);
        if (func_0022DF28(fd, buf, r) != r) { func_0022DDE8(fd); r = -1; }
        else { func_0022DDE8(fd); func_00273420(0); }
    }
    if (D_002B8C50) Func235DE0(D_002E4868, name, buf, r);
    return r;
}

extern "C" s32 func_002301B0(const char *name, u8 *buf, s32 size) {
    func_00273420(0);
    s32 fd = func_0022DD78(name, 0x602);
    if (fd == -1) size = -1;
    else if (func_0022E0E8(fd, buf, size) != size) { func_0022DDE8(fd); size = -1; }
    else func_0022DDE8(fd);
    if (D_002B8C50) Func235DE0(D_002E4888, name, buf, size);
    return size;
}

extern "C" s32 func_00230280(s32 name, void *(*alloc)(u32)) {
    long old = func_0022DB38(0);
    long size = ((FnL)func_0022FF58)((void *)name);
    func_0022DB38(old);
    if (size <= 0) { if (old && D_002B8C50) Func235DE0(D_002E48A8, func_0022DD20()); return 0; }
    s32 sz = size;
    void *p = alloc((sz + 0x7FF) & ~0x7FF);
    if (!p) { if (old && D_002B8C50) Func235DE0(D_002E48A8, func_0022DD20()); return 0; }
    if (func_0022FF18((void *)name, p) <= 0) { D_002B91B0(p); return 0; }
    D_002B91AC(p, sz);
    return (s32)p;
}

extern "C" s32 func_002303C0(s32 a) { return func_00230280(a, D_002B91A4); }

extern "C" s32 func_002303E0(s32 a) { return func_00230280(a, D_002B91A8); }

extern "C" char *func_00230400(void) { S344FF0 *p = &D_344FF0; func_002304A0(p); func_00230A48(&p->m24); return func_002321F8(p->m6C); }

extern "C" s32 func_00230438(void) { func_00230528(); func_00230AD8(); return func_00232280(); }

extern "C" FsOps *func_00230460(s32 i) { switch (i) { case 0: case 1: case 3: return &((FsOps *)&D_344FF0)[i]; } return 0; }

extern "C" void func_002304A0(S344FF0 *pt) { FsOps *t = (FsOps *)pt;
    t->f[0] = (void *)func_00230530; t->f[2] = (void *)func_00230548; t->f[1] = (void *)func_00230550; t->f[3] = (void *)func_00230578;
    t->f[4] = (void *)func_00230638; t->f[5] = (void *)func_002306E8; t->f[6] = (void *)func_00230808; t->f[8] = (void *)func_00230970; t->f[7] = (void *)func_00230980;
    return (void)func_00230980(0);
}

extern "C" void func_00230528(void) {
}

extern "C" void func_00230530(char *a, const char *b) { return func_00230928(a, b); }

extern "C" s32 func_00230548(void) { return 0; }

extern "C" s32 func_00230550(s32 a) { if (a == 1) return D_002B8C58 & 1; return 0; }
