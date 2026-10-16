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

struct GItem { s16 x; s16 y; s32 p; };
struct Grp { s32 m0; s32 a[32]; s32 b[32]; GItem it[32][16]; };
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
extern "C" s32 func_0021BAC0(s32, void *, s32);

extern "C" s32 func_002390A0(void);
extern "C" void func_00239088(s32);
extern "C" s32 func_002375C0(void);
extern "C" s32 func_002377D8(void);
extern "C" void func_0021B8E8(s32, s32, s32);
extern "C" void func_0021B680(s32, s32);
extern const char D_002E3C30[];
extern u8 D_33C5B0[];
extern s32 D_002B6810[2];
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

extern "C" void func_0021A720(Ent14 *e);
inline void ZUnlink(ZLink *l) {
    l->m0->m4 = l->m4;
    l->m4->m0 = l->m0;
}

extern "C" void func_0021A720(Ent14 *e);
inline void ZLinkTo(ZLink *a, ZLink *b) {
    a->m4 = b;
    b->m0 = a;
}

extern const char D_002E3B78[];
extern const char D_002E3BA0[];
extern const char D_002E3BB8[];
extern const char D_002E3BD8[];
extern const char *D_002A67D8[];

extern "C" f32 func_00280278(f32);

inline f32 VuSqrt219(f32 x) { f32 r; asm volatile("mfc1 $8, %1\n\tqmtc2.ni $8, $vf2\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "f"(x) : "$8"); return r; }
extern s32 D_002B6800[3];

extern "C" Ent14 *func_0021A6F8(void);
extern "C" void func_0021A720(Ent14 *e);
extern const char D_002E3B50[];

extern "C" Ent14 *func_0021A6F8(void);
extern const char D_002E3A30[];
extern const char D_002E3A50[];
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

extern "C" void func_00219BA8(s32 id) {
    Zone **pp = &D_338390.active;
    Zone *z;
    while ((z = *pp) != 0) {
        if (z->mC == id) {
            ZLink *l;
            while ((l = z->m28) != (ZLink *)&z->m24) {
                ZUnlink(l);
                func_0021A720((Ent14 *)l);
            }
            z->mC = -1;
            *pp = z->next;
            z->next = D_338390.freeZ;
            D_338390.freeZ = z;
        } else {
            pp = &z->next;
        }
    }
}

extern "C" s32 func_00219C78(s32 type, u32 start, s32 c, s32 size) {
    Zone *z = D_338390.freeZ;
    Zone *p;
    u32 end;
    ZLink *e;
    ZLink *head;
    if (!z) {
        if (func_00212918() & 2) Func235DE0(D_002E3A30);
        return -1;
    }

    for (p = D_338390.active; p; p = p->next) {
        if (p->mC != type) continue;
        if ((p->m10 <= start && start < p->m10 + p->m18) || (start <= p->m10 && p->m10 < start + size)) {
            if (func_00212918() & 1) Func235DE0(D_002E3A50, start, start + size - 1);
            return -1;
        }
    }
    z->mC = type;
    z->m8 = 1;
    z->m10 = start;
    z->m14 = c;
    z->m18 = size;
    z->m1C = size;
    z->m20 = 0;
    e = (ZLink *)func_0021A6F8();
    if (!e) return -1;
    head = (ZLink *)&z->m24;
    e->m4 = head;
    e->m0 = head;
    head->m4 = e;
    e->m4->m0 = e;
    e->m10 = size;
    e->mC = 0;
    z->m20++;
    D_338390.freeZ = z->next;
    z->next = D_338390.active;
    D_338390.active = z;
    return z->m4;
}

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

extern "C" s32 func_00219FC0(s32 type, s32 mode, u32 lo, u32 hi, u32 x, s32 size) {
    Zone *z;
    ZLink *l;
    ZLink *e1;
    ZLink *e2;
    u32 a;
    s32 ret;
    switch (type) {
    case 1:
        size = (size + 3) & ~3;
        break;
    case 0:
    case 2:
        size = (size + 0x3F) & ~0x3F;
        break;
    }
    if (size <= 0) return 0;
    func_001F15F0();
    ret = 0;
    e2 = 0;
    for (z = D_338390.active; z; z = z->next) {
        if (z->mC != type) continue;
        if (z->m8 == 0) continue;
        switch (mode) {
        case 0:
            a = z->m10;
            for (l = z->m28; l != (ZLink *)&z->m24; l = l->m4) {
                u32 s = a < lo ? lo : a;
                u32 e = hi < a + l->m10 ? hi : a + l->m10;
                if (l->mC == 0 && (s32)(e - s) >= size) {
                    x = s;
                    goto found;
                }
                a += l->m10;
            }
            break;
        case 1:
            l = z->m24;
            a = z->m10 + z->m18 - l->m10;
            for (; l != (ZLink *)&z->m24; ) {
                u32 s = a < lo ? lo : a;
                u32 e = hi < a + l->m10 ? hi : a + l->m10;
                if (l->mC == 0 && (s32)(e - s) >= size) {
                    x = e - size;
                    goto found;
                }
                l = l->m0;
                a -= l->m10;
            }
            break;
        case 2:
            a = z->m10;
            for (l = z->m28; l != (ZLink *)&z->m24; l = l->m4) {
                u32 s = a < lo ? lo : a;
                u32 e = hi < a + l->m10 ? hi : a + l->m10;
                if (l->mC == 0 && !(x < s) && !(e < x + size)) goto found;
                a += l->m10;
            }
            break;
        }
    }
    goto end;
found:
    e1 = (ZLink *)func_0021A6F8();
    if (!e1 || !(e2 = (ZLink *)func_0021A6F8())) {
        func_0021A720((Ent14 *)e1);
        func_0021A720((Ent14 *)e2);
        if (func_00212918() & 2) Func235DE0(D_002E3B50);
        goto end;
    }
    if (a < x) {
        e1->m0 = l->m0;
        e1->m10 = x - a;
        e1->m4 = l;
        e1->mC = 0;
        l->m0->m4 = e1;
        l->m0 = e1;
        l->m10 -= e1->m10;
    } else {
        func_0021A720((Ent14 *)e1);
    }
    if (size < (s32)l->m10) {
        e2->m0 = l;
        e2->m4 = l->m4;
        e2->mC = 0;
        e2->m10 = l->m10 - size;
        l->m4->m0 = e2;
        l->m4 = e2;
        l->m10 -= e2->m10;
    } else {
        func_0021A720((Ent14 *)e2);
    }
    l->m8 = (s32)z;
    l->mC = 1;
    z->m1C -= size;
    z->m20++;
    ret = z->m14 + x - z->m10;
end:
    func_001F1610();
    return ret;
}

extern "C" void func_0021A380(s32 type, s32 v) {
    Zone *z;
    ZLink *l;
    ZLink *n;
    ZLink *head;
    func_001F15F0();
    for (z = D_338390.active; z; z = z->next) {
        if (z->mC != type) continue;
        {
            u32 a = z->m10;
            u32 target = a + v - z->m14;
            head = (ZLink *)&z->m24;
            for (l = z->m28; l != (ZLink *)&z->m24; l = l->m4) {
                if (l->mC == 1 && a == target) goto found;
                a += l->m10;
            }
        }
    }
    goto end;
found:
    l->mC = 0;
    z->m20--;
    z->m1C += l->m10;
    n = l->m0;
    if (n != head && n->mC == 0) {
        ZLinkTo(n, l->m4);
        n->m10 += l->m10;
        func_0021A720((Ent14 *)l);
        l = n;
    }
    n = l->m4;
    if (n != head && n->mC == 0) {
        ZLinkTo(l->m0, n);
        n->m10 += l->m10;
        func_0021A720((Ent14 *)l);
        l = n;
    }
    if (l->mC == 0 && l->m10 == 0) {
        ZLinkTo(l->m0, l->m4);
        func_0021A720((Ent14 *)l);
    }
end:
    func_001F1610();
    return;
}

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

extern "C" void func_0021A890(Zone *z) {
    ZLink *l;
    s32 n;
    s32 nf;
    u32 off;
    if (func_00212918() & 4) Func235DE0(D_002E3B78);
    if (func_00212918() & 4) Func235DE0(D_002E3BA0, D_002A67D8[z->mC], z->m10, z->m10 + z->m18);
    if (func_00212918() & 4) Func235DE0(D_002E3B78);
    n = 0;
    nf = 0;
    off = 0;
    for (l = z->m28; l != (ZLink *)&z->m24; l = l->m4) {
        if (func_00212918() & 4) Func235DE0(D_002E3BB8, l->mC ? 'o' : 'x', z->m10 + off, z->m10 + off + l->m10 - 1, l->m10);
        n++;
        off += l->m10;
    }
    for (l = (ZLink *)D_338390.free1408; l; l = l->m4) nf++;
    if (func_00212918() & 4) Func235DE0(D_002E3BD8, n, nf);
    if (func_00212918() & 4) {
        Func235DE0(D_002E3B78);
        return;
    }
}

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

extern "C" void func_0021B040(Quat *q, f32 (*m)[4]) {
    f32 tr = m[0][0] + m[1][1] + m[2][2];
    f32 s;
    f32 t[4];
    s32 i, j, k;
    if (tr > 0.0f) {
        s = VuSqrt219(tr + 1.0f);
        q->w = s * 0.5f;
        s = 0.5f / s;
        q->x = (m[1][2] - m[2][1]) * s;
        q->y = (m[2][0] - m[0][2]) * s;
        q->z = (m[0][1] - m[1][0]) * s;
    } else {
        i = 0;
        if (m[0][0] < m[1][1]) i = 1;
        if (m[i][i] < m[2][2]) i = 2;
        j = D_002B6800[i];
        k = D_002B6800[j];
        s = VuSqrt219(m[i][i] - (m[j][j] + m[k][k]) + 1.0f);
        t[i] = s * 0.5f;
        if (s != 0.0f) s = 0.5f / s;
        t[3] = (m[j][k] - m[k][j]) * s;
        t[j] = (m[i][j] + m[j][i]) * s;
        t[k] = (m[i][k] + m[k][i]) * s;
        q->x = t[0];
        q->y = t[1];
        q->z = t[2];
        q->w = t[3];
    }
}

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

extern "C" void func_0021B4E0(Quat *out, Quat *a, Quat *b, f32 t) {
    Quat q;
    f32 d = a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
    f32 s0, s1;
    if (d < 0.0f) {
        q.x = -b->x;
        q.y = -b->y;
        q.z = -b->z;
        q.w = -b->w;
        d = -d;
    } else {
        q.x = b->x;
        q.y = b->y;
        q.z = b->z;
        q.w = b->w;
    }
    if (1.0f - d > 0.00015230485f) {
        f32 ang = func_00280278(d);
        f32 sn = func_00280178(ang);
        s0 = func_00280178((1.0f - t) * ang) / sn;
        s1 = func_00280178(t * ang) / sn;
    } else {
        s0 = 1.0f - t;
        s1 = t;
    }
    out->x = s0 * a->x + s1 * q.x;
    out->y = s0 * a->y + s1 * q.y;
    out->z = s0 * a->z + s1 * q.z;
    out->w = s0 * a->w + s1 * q.w;
}

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

INCLUDE_RODATA("asm/nonmatchings/Unit219970", D_002E3A30);
INCLUDE_RODATA("asm/nonmatchings/Unit219970", D_002E3A50);
INCLUDE_RODATA("asm/nonmatchings/Unit219970", D_002E3A78);
INCLUDE_RODATA("asm/nonmatchings/Unit219970", D_002E3AC0);
INCLUDE_RODATA("asm/nonmatchings/Unit219970", D_002E3B08);
INCLUDE_RODATA("asm/nonmatchings/Unit219970", D_002E3B50);
INCLUDE_RODATA("asm/nonmatchings/Unit219970", D_002E3B78);
INCLUDE_RODATA("asm/nonmatchings/Unit219970", D_002E3BA0);
INCLUDE_RODATA("asm/nonmatchings/Unit219970", D_002E3BB8);
INCLUDE_RODATA("asm/nonmatchings/Unit219970", D_002E3BD8);
INCLUDE_RODATA("asm/nonmatchings/Unit219970", D_002E3BF8);
INCLUDE_RODATA("asm/nonmatchings/Unit219970", D_002E3C00);
INCLUDE_RODATA("asm/nonmatchings/Unit219970", D_002E3C30);
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
