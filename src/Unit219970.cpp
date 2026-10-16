#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct Rec4 { s16 m0; u8 m2; u8 m3; const char *m4; };
struct Ent14 { s32 m0; Ent14 *m4; s32 m8; s32 mC; s32 m10; };
struct Zone { Zone *next; s32 m4; s32 m8; s32 mC; u32 m10; s32 m14; u32 m18; s32 m1C; s32 m20; struct ZLink *m24; struct ZLink *m28; s32 m2C; s32 m30; s32 m34; };
struct S338390 { Rec4 **tbl; s32 n; Ent14 ent[256]; Ent14 *free1408; Zone zones[64]; Zone *freeZ; Zone *active; };
extern S338390 D_338390;
extern "C" void func_00212B30(void *);
extern "C" void func_0021A380(s32, s32);
extern "C" s32 func_00219E48(s32);
extern "C" s32 func_00219E00(s32);
extern "C" u32 func_0021A510(s32, u32);

struct Area { s32 m0; s32 m4; u32 m8; u32 mC; u32 m10; };
extern Zone D_33979C[64];
extern "C" s32 func_00212918(void);
void Func235DE0(const char *, ...);
extern const char D_002E3A78[];
extern const char D_002E3AC0[];
extern const char D_002E3B08[];
extern "C" s32 func_00219FC0(s32, s32, u32, u32, u32, s32);
extern "C" s32 func_0021A5E0(s32, s32, u32, u32, u32, s32);

struct ZLink { ZLink *m0; ZLink *m4; s32 m8; s32 mC; u32 m10; };
extern "C" void func_001F15F0(void);
extern "C" void func_001F1610(void);
extern "C" void func_0021AA78(void);
extern "C" void func_0021ABC8(void);
extern "C" void func_0021AB88(void);

struct Grp { s32 m0; s32 a[32]; s32 b[32]; u8 rest[0x1000]; };
extern Grp D_002B6818[2];
extern "C" s32 func_0021ACD8(f32, f32);
struct Quat { f32 x, y, z, w; };
extern "C" void func_0021B280(void *, Quat *);
extern "C" void func_0021ADB0(s32, void *);
extern "C" void func_00239698(s32, s32);
extern "C" void func_002393A0(s32, s32);
extern "C" void func_0021C588(void);
extern "C" void func_0021C0D8(s32, s32, s32, s32);
extern "C" void func_0021C0F8(f32, f32);
extern "C" void func_0021C698(void);

extern u8 D_002C3600[], D_002C3C60[];
extern "C" void func_0021BAC0(s32, void *, s32);

extern "C" s32 func_002390A0(void);
extern "C" void func_00239088(s32);
extern "C" s32 func_002375C0(void);
extern "C" s32 func_002377D8(void);
extern "C" void func_0021B8E8(s32, s32, s32);
extern "C" void func_0021B680(s32, s32);
extern const char D_002E3C30[];
extern u8 D_33C5B0[];
extern s32 D_002B6810[2];
struct GItem { s16 x; s16 y; s32 p; };
s32 Func238158(void *, s32);

extern f32 D_002A6800[0x4000];
extern s16 D_33A5A8[];
extern const double D_002E3BF8;
extern "C" f32 func_00280178(f32);
extern "C" f32 func_0027FC30(f32);

extern f32 D_002A6800[];
struct RotV { f32 x, y, z; };
inline s32 Ftoi15b(f32 x) { s32 i; asm volatile("mfc1 %0, %1\n\tqmtc2.ni %0, $vf2\n\tvftoi15.x $vf2, $vf2\n\tqmfc2.ni %0, $vf2" : "=r"(i) : "f"(x)); return i; }
#define VU_ROT2(mic, ang) do { s32 i_ = (Ftoi15b(ang) >> 1) & 0x3FFF; s32 s_ = ((s32 *)D_002A6800)[i_]; s32 c_ = ((s32 *)D_002A6800)[(i_ + 0x1000) & 0x3FFF]; asm volatile("qmtc2.i %0, $vf4\n\tqmtc2.ni %1, $vf5\n\tvnop\n\tvnop\n\tvcallms " #mic : : "r"(c_), "r"(s_)); } while (0)

extern u32 *D_002B94E4;
#define PUTW(v) { u32 *_p = D_002B94E4; D_002B94E4 = _p + 1; *_p = (v); }
extern "C" s32 func_00237860(s32, s32);
extern const char D_002E3C00[];

extern "C" s32 func_00237350(s32);
inline s32 Ftoi15c(f32 x) { s32 i; asm volatile("mfc1 %0, %1\n\tqmtc2.ni %0, $vf2\n\tvftoi15.x $vf2, $vf2\n\tqmfc2.ni %0, $vf2" : "=r"(i) : "f"(x)); return i; }
// @decl-end

extern "C" void func_00219970(s32 a) {
    func_0021A380(1, a);
    return;
}

extern "C" void func_00219990(s32 a) {
    func_0021A380(0, a);
    return;
}

extern "C" s32 func_002199B0(void) {
    return func_00219E48(2);
}

extern "C" s32 func_002199C8(void) {
    return func_00219E48(1);
}

extern "C" s32 func_002199E0(void) {
    return func_00219E48(0);
}

extern "C" s32 func_002199F8(void) {
    return func_00219E00(2);
}

extern "C" s32 func_00219A10(void) {
    return func_00219E00(1);
}

extern "C" s32 func_00219A28(void) {
    return func_00219E00(0);
}

extern "C" void func_00219A40(s32 a) {
    func_0021A510(2, a);
    return;
}

extern "C" void func_00219A60(s32 a) {
    func_0021A510(1, a);
    return;
}

extern "C" void func_00219A80(s32 a) {
    func_0021A510(0, a);
    return;
}

extern "C" void func_00219AA0(void) {
    s32 i;
    s32 j;
    Ent14 *e;
    Zone *z;
    D_338390.tbl = 0;
    D_338390.n = 0;
    D_338390.free1408 = 0;
    e = D_338390.ent;
    for (i = 0; i < 256; i++, e++) {
        e->m4 = D_338390.free1408;
        D_338390.free1408 = e;
    }
    D_338390.active = 0;
    D_338390.freeZ = 0;
    z = D_338390.zones;
    for (j = 0; j < 64; j++, z++) {
        z->m4 = j;
        z->next = D_338390.freeZ;
        D_338390.freeZ = z;
    }
}

extern "C" void func_00219B20(void) {
    if (D_338390.tbl) {
        func_00212B30(D_338390.tbl);
        D_338390.tbl = 0;
    }
}

extern "C" void func_00219B60(void) {
}

extern "C" Rec4 *func_00219B68(s32 i) {
    if (i >= 0 && !(D_338390.n - 1 < i)) goto found;
    return 0;
found:
    return D_338390.tbl[i];
}

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_00219BA8);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_00219C78);

extern "C" s32 func_00219E00(s32 type) {
    Zone *z;
    s32 sum = 0;
    for (z = D_338390.active; z; z = z->next) {
        if (z->mC == type) sum += z->m1C;
    }
    return sum;
}

extern "C" s32 func_00219E48(s32 type) {
    Zone *z;
    u32 max = 0;
    u32 end;
    for (z = D_338390.active; z; z = z->next) {
        if (z->mC == type) {
            end = z->m10 + z->m18;
            if (!(end < max)) max = end;
        }
    }
    return max;
}

extern "C" void func_00219E90(u32 id, s32 v) {
    Zone *z;
    if (id < 64 && (z = &D_338390.zones[id])->mC >= 0) goto found;
    if (func_00212918() & 1) {
        Func235DE0(D_002E3A78, id);
        return;
    }
    return;
found:
    if (z->m1C < (s32)z->m18) {
        if (func_00212918() & 1) {
            Func235DE0(D_002E3AC0, id);
            return;
        }
        return;
    }
    z->m14 = v;
}

extern "C" void func_00219F48(u32 id, s32 v) {
    Zone *z;
    if (id < 64 && (z = &D_338390.zones[id])->mC >= 0) goto found;
    if (func_00212918() & 1) {
        Func235DE0(D_002E3B08, id);
        return;
    }
    return;
found:
    z->m8 = v;
}

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_00219FC0);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021A380);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021A510);

extern "C" s32 func_0021A5E0(s32 type, s32 dir, u32 start, u32 end, u32 n, s32 x) {
    u32 step;
    u32 p;
    s32 r;
    if ((s32)n <= 0) return 0;
    step = (end - start) / n;
    switch (dir) {
    case 0:
        for (p = start; p < end; p += step) {
            r = func_00219FC0(type, 2, p, p + step, p, x);
            if (r) return r;
        }
        break;
    case 1:
        for (p = end - step; !(p < end); p -= step) {
            r = func_00219FC0(type, 2, p, p + step, p, x);
            if (r) return r;
        }
        break;
    }
    return 0;
}

extern "C" Ent14 *func_0021A6F8(void) {
    Ent14 *e = D_338390.free1408;
    if (e) {
        D_338390.free1408 = e->m4;
        return e;
    }
    return 0;
}

extern "C" void func_0021A720(Ent14 *e) {
    if (e) {
        e->m4 = D_338390.free1408;
        D_338390.free1408 = e;
    }
}

extern "C" s32 func_0021A740(Area *p, s32 b, s32 c) {
    return func_00219FC0(0, b, p->m8, p->m8 + p->mC, 0, c);
}

extern "C" s32 func_0021A778(Area *p, s32 b, s32 c) {
    return func_00219FC0(1, b, p->m8, p->m8 + p->mC, 0, c);
}

extern "C" s32 func_0021A7B0(Area *p, s32 b, s32 c) {
    return func_00219FC0(2, b, p->m8, p->m8 + p->mC, 0, c);
}

extern "C" s32 func_0021A7E8(Area *p, s32 b, s32 c) {
    return func_0021A5E0(0, b, p->m8, p->m8 + p->mC, p->m10, c);
}

extern "C" s32 func_0021A820(Area *p, s32 b, s32 c) {
    return func_0021A5E0(1, b, p->m8, p->m8 + p->mC, p->m10, c);
}

extern "C" s32 func_0021A858(Area *p, s32 b, s32 c) {
    return func_0021A5E0(2, b, p->m8, p->m8 + p->mC, p->m10, c);
}

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021A890);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021AA78);

extern "C" void func_0021AB58(void) {
    func_0021AA78();
    func_0021ABC8();
    func_0021AB88();
    return;
}

extern "C" void func_0021AB80(void) {
}

extern "C" void func_0021AB88(void) { func_0021BAC0(0, D_002C3600, D_002C3C60 - D_002C3600); asm volatile("vcallms 0x10"); asm volatile("vcallms 0x20"); asm volatile("vcallms 0x0"); }

extern "C" void func_0021ABC8(void) {
    f32 a = 0.0f;
    s16 *p = D_33A5A8;
    for (s32 i = 0xFFF; i >= 0; i--) { *p++ = (s32)(func_0027FC30(a * (1.0f / 4096)) * 4.0f * 2048.0f / 3.1415926f + 0.5f); a += 1.0f; }
}

extern "C" f32 func_0021ACA8(f32 a, f32 b) {
    return func_0021ACD8(a, b) * (1.0f / 16384);
}

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021ACD8);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021ADB0);

extern "C" void func_0021AF10(void *m, RotV *a) {
    asm volatile("vcallms 0x30");
    VU_ROT2(0x90, a->z);
    VU_ROT2(0xA0, a->y);
    VU_ROT2(0xB0, a->x);
    asm volatile("vcallms 0x0\n\tqmfc2.i $0, $vf0\n\tsqc2 $vf24, 0x0(%0)\n\tsqc2 $vf25, 0x10(%0)\n\tsqc2 $vf26, 0x20(%0)\n\tsqc2 $vf27, 0x30(%0)\n\tvcallms 0x40" : : "r"(m) : "memory");
}

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021B040);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021B280);

extern "C" void func_0021B340(f32 *q, RotV *a) {
    u8 *tbl = (u8 *)D_002A6800;
    f32 h, sx, cx, sy, cy, sz, cz;
    h = a->x * 0.5f; sx = *(f32 *)(tbl + ((Ftoi15c(h) << 1) & 0xFFFC)); cx = ((f32 *)tbl)[(((Ftoi15c(h) >> 1) & 0x3FFF) + 0x1000) & 0x3FFF];
    h = a->y * 0.5f; sy = *(f32 *)(tbl + ((Ftoi15c(h) << 1) & 0xFFFC)); cy = ((f32 *)tbl)[(((Ftoi15c(h) >> 1) & 0x3FFF) + 0x1000) & 0x3FFF];
    h = a->z * 0.5f; sz = *(f32 *)(tbl + ((Ftoi15c(h) << 1) & 0xFFFC)); cz = ((f32 *)tbl)[(((Ftoi15c(h) >> 1) & 0x3FFF) + 0x1000) & 0x3FFF];
    q[0] = sx * (cy * cz) - cx * (sy * sz);
    q[1] = cx * sy * cz + sx * cy * sz;
    q[2] = cx * cy * sz - sx * sy * cz;
    q[3] = cx * (cy * cz) + sx * (sy * sz);
}

extern "C" void func_0021B4A8(s32 x, Quat *q) {
    u8 buf[0x40];
    func_0021B280(buf, q);
    func_0021ADB0(x, buf);
}

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021B4E0);

extern "C" void func_0021B680(s32 a, s32 b) {
    func_00239698(a, 0);
    func_002393A0(a, b);
    func_00239698(a, 0);
    return;
}

extern "C" void func_0021B6C8(u32 i, u32 j) {
    if (i < 2 && j < 32) {
        D_002B6818[i].a[j] = 0;
        D_002B6818[i].b[j] = 0;
    }
}

extern "C" void func_0021B718(void) {
    s32 i;
    s32 j;
    for (i = 0; i < 2; i++) {
        D_002B6818[i].m0 = 0;
        for (j = 0; j < 32; j++) {
            D_002B6818[i].a[j] = 0;
            D_002B6818[i].b[j] = 0;
        }
    }
}

extern "C" void func_0021B780(s32 a, s32 src, s32 n, u32 addr) {
    s32 r = func_002390A0();
    s32 q = (n + 15) / 16;
    Func235DE0(D_002E3C00, a, src, addr, q * 16);
    func_00239088((s32)D_33C5B0);
    s32 s = func_002375C0();
    while (q > 0) {
        s32 c = q < 255 ? q : 254;
        PUTW(0); PUTW(0); PUTW(0);
        PUTW((addr | (c << 16)) | 0x6C000000);
        func_00237860(c, src);
        addr += c; q -= c; src += c * 16;
    }
    func_002377D8();
    func_00239088(r);
    return func_0021B680(a, s);
}

extern "C" void func_0021B8E8(s32 src, s32 n, s32 addr) {
    s32 q = (n + 7) / 8;
    func_00237350(0x10);
    while (q > 0) {
        s32 c = q < 255 ? q : 254;
        PUTW(0); PUTW(0); PUTW(0x10000000);
        PUTW((addr | (c << 16)) | 0x4A000000);
        func_00237860((c + 1) / 2, src);
        q -= c; addr += c; src += c * 8;
    }
}

extern "C" void func_0021BA08(s32 a, s32 b, s32 c, s32 d) { s32 r = func_002390A0(); Func235DE0(D_002E3C30, a, b, d, c); func_00239088((s32)D_33C5B0); s32 s = func_002375C0(); func_0021B8E8(b, c, d); func_002377D8(); func_00239088(r); return func_0021B680(a, s); }

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021BAC0);

extern "C" void func_0021BC88(u32 i, u32 v) {
    if (i < 2 && v < 32) D_002B6818[i].m0 = v;
}

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021BCC0);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021BCF8);

asm(".p2align 3");
extern "C" s32 func_0021BDD0(u32 a, s32 b) {
    if (a >= 2) return -1;
    if (b == 0) b = D_002B6810[a] * 8;
    s32 t = (b + 7) / 8;
    for (s32 i = 0; i < 32; i++) if (D_002B6818[a].a[i] + t <= D_002B6810[a]) return i;
    return -1;
}

extern "C" void func_0021BE80(void) {
    func_0021C588();
    func_0021C0D8(0, 0, 0, 0x80);
    func_0021C0F8(2.0f, 2.0f);
    func_0021C698();
    return;
}
