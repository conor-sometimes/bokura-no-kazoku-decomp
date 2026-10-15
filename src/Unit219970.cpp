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
extern "C" s32 func_0021ACD8(void);
extern "C" void func_0021B280(void *);
extern "C" void func_0021ADB0(s32, void *);
extern "C" void func_00239698(s32, s32);
extern "C" void func_002393A0(s32, s32);
extern "C" void func_0021C588(void);
extern "C" void func_0021C0D8(s32, s32, s32, s32);
extern "C" void func_0021C0F8(f32, f32);
extern "C" void func_0021C698(void);
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

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021AB88);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021ABC8);

extern "C" f32 func_0021ACA8(void) {
    return func_0021ACD8() * (1.0f / 16384);
}

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021ACD8);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021ADB0);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021AF10);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021B040);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021B280);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021B340);

extern "C" void func_0021B4A8(s32 x) {
    u8 buf[0x40];
    func_0021B280(buf);
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

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021B780);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021B8E8);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021BA08);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021BAC0);

extern "C" void func_0021BC88(u32 i, u32 v) {
    if (i < 2 && v < 32) D_002B6818[i].m0 = v;
}

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021BCC0);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021BCF8);

INCLUDE_ASM("asm/nonmatchings/Unit219970", func_0021BDD0);

extern "C" void func_0021BE80(void) {
    func_0021C588();
    func_0021C0D8(0, 0, 0, 0x80);
    func_0021C0F8(2.0f, 2.0f);
    func_0021C698();
    return;
}
