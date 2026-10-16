#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
s32 Func235DE0(const char *fmt, ...);
// AT3 (ATRAC3) stream players: 8 slots of 0xD9B0 bytes at D_393A00.
struct CAt3Node;
struct CAt3 {
    CAt3Node *m_next;         // 0x0
    s32 m_id;                 // 0x4
    s32 m_active;             // 0x8
    u8 padC[8];
    s32 m_pitch;              // 0x14
    u8 pad18[8];
    s32 m_syncCount;          // 0x20
    s32 m_sndId;              // 0x24
    s32 m_handle;             // 0x28
    u8 pad2C[0xD994 - 0x2C];
    s32 m_paused;             // 0xD994
    s32 m_ready;              // 0xD998
    s32 m_level;              // 0xD99C
    s32 m_volL;               // 0xD9A0
    s32 m_volR;               // 0xD9A4
    u8 padD9A8[8];
};
extern CAt3 D_393A00[8];
extern const char D_002E7490[];
extern const char D_002E75A8[];
extern const char D_002E75B0[];
extern const char D_002E75E0[];
extern const char D_002E75F0[];
extern const char D_002E75F8[];
inline CAt3 *GetAt3(u32 i, const char *fn) {
    if (i < 8) {
        CAt3 *a = &D_393A00[i];
        if (a->m_active) return a;
    }
    if (fn) Func235DE0(D_002E7490, fn, i);
    return 0;
}
extern "C" s32 func_0020B0B8(s32 h);
extern "C" s32 func_0020B828(u32 i, s32 v);
extern "C" s32 func_0020FD00(u32 i, const char *name, void *ops);
extern const char D_002E7470[];
extern u8 D_002BA1E8[];
extern s32 D_002BA208;
struct CAt3Node { CAt3Node *m_next; s32 m_id; s32 m8; s32 mC; };
extern CAt3Node *D_002BA1E0;
extern CAt3Node *D_002BA1E4;
extern CAt3Node D_393968[8];
extern CAt3Node *D_002BA20C;
void Func258200();
void Func2583B8();
void Func259978();
s32 Func259A78(u32 i, s32 x);
void Func259B08(u32 i, s32 x);
void Func259D20(u32 i, s32 l, s32 r);
void Func2586C8(CAt3Node *n);
void Func259858(s32 id, s32 b);
extern s32 D_002BA230[];
struct CAt3Tbl { u8 pad0[0xC]; s32 m_mode; u8 pad10[0x6930 - 0x10]; s16 m_tbl[1][4][256]; };

extern "C" void func_0022DE48(s32 id);
extern "C" void func_0022DDE8(s32 id);
extern "C" void func_0020AF80(s32 h);
extern CAt3Node *D_002BA210;
void Func258458(CAt3Tbl *o, s32 a, u32 b, s32 c, s32 v, s32 flag);
s32 Func2583D0(CAt3Tbl *o, s32 a, u32 b, s32 c, s32 flag);
extern "C" s32 func_0022E2C8(s32 a, s32 b);
extern "C" s32 func_0022E450(s32 a, s32 b);
extern "C" s32 func_0020B8C8(s32 h, s32 l, s32 r);
extern const char D_002E7580[];
extern const char D_002E7588[];
extern const char D_002E7598[];
extern const char D_002E75C0[];
extern const char D_002E75D0[];
extern const char D_002E7578[];

extern "C" s16 func_0020F620(void);
extern "C" s16 func_0020F630(void);
struct CAt3Prm { u8 pad0[4]; s8 m_volL; s8 m_volR; };
struct CAt3St { u8 pad0[0x19]; u8 m_level; u8 pad1A[2]; u8 m_flags; u8 pad1D; u8 m_pause; u8 m_ready; s16 m_volL; s16 m_volR; f32 m_pitch; };
void Func259BA0(u32 i, s32 v);
void Func259E90(u32 i, f32 v);
s32 Func259F18(u32 i);
s32 Func259C28(u32 i);
void Func259300();

struct W2FontCh { u8 p0[0x10]; s8 m10; };
struct W2FontLay { u8 p0[0x10]; f32 m10; f32 m14; u8 p18[8]; f32 m20; u8 p24[0x30]; f32 m54; };
extern "C" void func_00256DC8(void *ctx, W2FontCh *c, W2FontLay *l, f32 x, f32 y);
extern s32 D_002BA218[];
extern const char D_002E7550[];
extern "C" s32 func_00259340(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3);
extern "C" s32 func_0022DD98(const char *name, s32 b, s32 n, s32 h);
struct W2SndPos { s32 m0; u8 m4, m5, m6, m7; s32 m8; s32 mC; s32 m10; };
extern "C" void func_0022E398(s32 h, W2SndPos *p, s32 n, s32 x);
extern "C" void func_0022E230(s32 h, s32 pos, s32 x);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk2571C0", func_002571C0);

INCLUDE_ASM("asm/nonmatchings/Dk2571C0", Func2574B8__9CFontWorkffPfT3PPCcPvi);

extern "C" void func_00257710(void *ctx, f32 *ox, f32 *oy, W2FontCh **items, s32 n, W2FontLay *l, s32 flags, f32 x, f32 y)
{
    f32 w;
    if (flags & 4) {
        s32 i;
        w = 0.0f;
        for (i = 0; i < n; i++) {
            W2FontCh *c = items[i];
            if (c) func_00256DC8(ctx, c, l, x - l->m10 + (f32)c->m10 * l->m20, y + w);
            w += l->m14;
            w += l->m54;
        }
        w -= l->m54;
    } else {
        w = l->m14 * (f32)n + l->m54 * (f32)(n - 1);
    }
    *ox = l->m10;
    *oy = w;
}

INCLUDE_ASM("asm/nonmatchings/Dk2571C0", func_00257840);

INCLUDE_ASM("asm/nonmatchings/Dk2571C0", Func257B70__9CFontWorkffPfT3PPCcPvi);

INCLUDE_ASM("asm/nonmatchings/Dk2571C0", func_00257DC8);

void Func257E28() { return Func2583B8(); }

void Func257E40() {
    for (CAt3Node *n = D_002BA1E0; n; n = n->m_next) {
        CAt3St *s = (CAt3St *)n->mC;
        s32 fl = s->m_flags;
        CAt3Prm *p = (CAt3Prm *)n->m8;
        if (fl & 1) Func259BA0(n->m_id, s->m_pause);
        if (fl & 4) {
            s32 l = p->m_volL * s->m_volL >> 7;
            s32 r = p->m_volR * s->m_volR >> 7;
            l = l * func_0020F620() >> 7;
            r = r * func_0020F630() >> 7;
            Func259D20(n->m_id, l, r);
        }
        if (fl & 8) Func259E90(n->m_id, s->m_pitch);
        s->m_flags = 0;
        s->m_level = Func259C28(n->m_id);
        s->m_ready = Func259F18(n->m_id);
    }
    return Func259300();
}

INCLUDE_ASM("asm/nonmatchings/Dk2571C0", func_00257F40);
INCLUDE_RODATA("asm/nonmatchings/Dk2571C0", D_002E7470);
INCLUDE_RODATA("asm/nonmatchings/Dk2571C0", D_002E7490);

INCLUDE_ASM("asm/nonmatchings/Dk2571C0", func_00258110);

s32 Func2581A0(s32 x) { return x; }

void Func2581A8(u32 i, s32 x) { return Func259B08(i, x); }

s32 Func2581C0(u32 i, s32 x) { return Func259A78(i, x); }

s32 Func2581D8() { return func_0020FD00(2, D_002E7470, D_002BA1E8); }

INCLUDE_ASM("asm/nonmatchings/Dk2571C0", func_00258200);

void Func2583B8() { return Func259978(); }

s32 Func2583D0(CAt3Tbl *o, s32 a, u32 b, s32 c, s32 flag) {
    s32 sh = D_002BA230[o->m_mode];
    s32 s1 = sh - 1;
    if (flag && (b & ~0x3FF)) a = (a + 1) % 6;
    b &= 0x3FF;
    b = ((b & 0x300) << s1) | (b & 0xFF);
    return o->m_tbl[a * sh][c][b];
}

void Func258458(CAt3Tbl *o, s32 a, u32 b, s32 c, s32 v, s32 flag) {
    s32 sh = D_002BA230[o->m_mode];
    s32 s1 = sh - 1;
    if (flag && (b & ~0x3FF)) a = (a + 1) % 6;
    b &= 0x3FF;
    b = ((b & 0x300) << s1) | (b & 0xFF);
    o->m_tbl[a * sh][c][b] = v;
}

void Func2584E0(CAt3Tbl *o, s32 a, s32 b, s32 n, s32 flag) {
    s32 sh = D_002BA230[o->m_mode];
    for (s32 i = 0; i < n; i++) {
        for (s32 j = 0; j < sh; j++) Func258458(o, a, b + i, j, 0, flag);
    }
}

void Func2585B8(CAt3Tbl *o, s32 da, s32 db, s32 sa, s32 sb, s32 n, s32 flag) {
    s32 sh = D_002BA230[o->m_mode];
    for (s32 i = 0; i < n; i++) {
        for (s32 j = 0; j < sh; j++) Func258458(o, da, db + i, j, Func2583D0(o, sa, sb + i, j, flag), flag);
    }
}

INCLUDE_ASM("asm/nonmatchings/Dk2571C0", Func2586C8__FP8CAt3Node);

void Func259300() {
    for (CAt3Node *n = D_002BA20C; n; n = n->m_next) Func2586C8(n);
}

INCLUDE_ASM("asm/nonmatchings/Dk2571C0", func_00259340);
INCLUDE_RODATA("asm/nonmatchings/Dk2571C0", D_002E7550);
INCLUDE_RODATA("asm/nonmatchings/Dk2571C0", D_002E7578);
INCLUDE_RODATA("asm/nonmatchings/Dk2571C0", D_002E7580);
INCLUDE_RODATA("asm/nonmatchings/Dk2571C0", D_002E7588);
INCLUDE_RODATA("asm/nonmatchings/Dk2571C0", D_002E7598);
INCLUDE_RODATA("asm/nonmatchings/Dk2571C0", D_002E75A8);
INCLUDE_RODATA("asm/nonmatchings/Dk2571C0", D_002E75B0);
INCLUDE_RODATA("asm/nonmatchings/Dk2571C0", D_002E75C0);
INCLUDE_RODATA("asm/nonmatchings/Dk2571C0", D_002E75D0);
INCLUDE_RODATA("asm/nonmatchings/Dk2571C0", D_002E75E0);
INCLUDE_RODATA("asm/nonmatchings/Dk2571C0", D_002E75F0);
INCLUDE_RODATA("asm/nonmatchings/Dk2571C0", D_002E75F8);

extern "C" s32 func_00259600(s32 i, s32 a1, s32 end, s32 loop, s32 start, const char *name, s32 base, s32 t3, s32 size, s32 s88, s32 s90)
{
    W2SndPos p;
    CAt3 *a = 0;
    s32 h = -1;
    s32 idx;
    idx = func_00259340(i, a1, end, loop, 0, t3, s88, s90);
    if (idx >= 0) {
        s32 n;
        a = &D_393A00[idx];
        a->m_ready = 0;
        n = size / (D_002BA218[i] * 2) * D_002BA218[i] * 2;
        h = func_0022DD98(name, t3, n, n >> 1);
        if (h < 0) {
            Func235DE0(D_002E7550, name);
        } else {
            a->m_sndId = h;
            p.m0 = (*(s32 *)((u8 *)a + 0x40) + 0x3FF) / 1024 * D_002BA218[i] + base;
            p.m4 = 1;
            p.m5 = 0;
            p.m6 = 0;
            p.m7 = 0;
            p.m8 = loop < 0 ? -1 : (*(s32 *)((u8 *)a + 0x3C) - 0x400) / 1024 * D_002BA218[i] + base;
            p.mC = 0;
            p.m10 = 0;
            func_0022E398(h, &p, 1, 0);
            if (start) {
                if (start >= end) start = end;
                if (start < 0) start = 0;
                *(s32 *)((u8 *)a + 0x34) = start & ~0x3FF;
                *(s32 *)((u8 *)a + 0x38) = start + 0x400;
            }
            func_0022E230(h, *(s32 *)((u8 *)a + 0x34) / 1024 * D_002BA218[i] + base, 0);
            func_0022E450(h, 0);
            return a->m_id;
        }
    }
    if (h >= 0) func_0022DE48(h);
    if (a) Func259858(idx, 1);
    return -1;
}

void Func259858(s32 i, s32 b) {
    CAt3 *a = GetAt3(i, D_002E7578);
    if (!a) return;
    if (a->m_sndId >= 0) {
        if (b) func_0022DE48(a->m_sndId);
        else func_0022DDE8(a->m_sndId);
        a->m_sndId = -1;
    }
    if (a->m_handle >= 0) {
        func_0020AF80(a->m_handle);
        a->m_handle = -1;
    }
    CAt3Node **pp = &D_002BA20C;
    CAt3Node *n;
    while ((n = *pp) != 0) {
        if (n == (CAt3Node *)a) {
            *pp = n->m_next;
            n->m_next = D_002BA210;
            D_002BA210 = n;
            break;
        }
        pp = &n->m_next;
    }
    a->m_active = 0;
}

void Func259978() {
    CAt3Node *n;
    while ((n = D_002BA20C) != 0) Func259858(n->m_id, 0);
}

void Func2599C0(u32 i) {
    CAt3 *a = GetAt3(i, D_002E7580);
    if (a && !a->m_paused && a->m_sndId >= 0) {
        func_0020B828(a->m_handle, 1);
        func_0022E450(a->m_sndId, 1);
        a->m_paused = 1;
    }
}

s32 Func259A78(u32 i, s32 x) {
    CAt3 *a = GetAt3(i, D_002E7588);
    if (!a) return 0;
    if (a->m_sndId < 0) return 0;
    return func_0022E2C8(a->m_sndId, x == 0);
}

void Func259B08(u32 i, s32 x) {
    CAt3 *a = GetAt3(i, D_002E7598);
    if (a && a->m_sndId >= 0) return (void)func_0022E450(a->m_sndId, x);
}

void Func259BA0(u32 i, s32 v) {
    CAt3 *a = GetAt3(i, D_002E75A8);
    if (a) return (void)func_0020B828(a->m_handle, v);
}

s32 Func259C28(u32 i) {
    if (i >= 8) return 0;
    CAt3 *a = &D_393A00[i];
    if (!a->m_active) return 0;
    return func_0020B0B8(a->m_handle);
}

s32 Func259C78(u32 i) {
    if (i >= 8) return 0;
    CAt3 *a = &D_393A00[i];
    if (!a->m_active) return 0;
    return a->m_handle;
}

s32 Func259CB0(u32 i) {
    CAt3 *a = GetAt3(i, D_002E75B0);
    if (a) return a->m_level;
    return 0;
}

void Func259D20(u32 i, s32 l, s32 r) {
    CAt3 *a = GetAt3(i, D_002E75C0);
    if (a) {
        a->m_volL = l;
        a->m_volR = r;
        return (void)func_0020B8C8(a->m_handle, l, r);
    }
}

void Func259DD8(u32 i, s32 v) { return Func259D20(i, v, v); }

void Func259DF0(u32 i, s32 *l, s32 *r) {
    CAt3 *a = GetAt3(i, D_002E75D0);
    if (a) {
        *l = a->m_volL;
        *r = a->m_volR;
    }
}

void Func259E90(u32 i, f32 v) {
    CAt3 *a = GetAt3(i, D_002E75E0);
    if (a) a->m_pitch = (s32)(v * 4096.0f);
}

s32 Func259F18(u32 i) {
    CAt3 *a = GetAt3(i, D_002E75F0);
    if (a) return a->m_ready;
    return 0;
}

void Func259F88(s32 v) { D_002BA208 = v; }

void Func259F98(u32 i, s32 v) {
    CAt3 *a = GetAt3(i, D_002E75F8);
    if (a) a->m_syncCount = v;
}
