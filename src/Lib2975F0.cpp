#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "linkonce.h"
extern "C" {
extern TypeInfo D_2EB7E0;
extern const char D_002D51F0[];
extern TypeInfo D_2EB7E8;
extern const char D_002D55C8[];
extern TypeInfo D_2EB7F0;
extern const char D_002D55F0[];
extern TypeInfo D_2EB7F8;
extern const char D_002D5660[];
}
struct VDel_2975F0 { u8 pad[0x13c]; virtual ~VDel_2975F0(); };

#include "linkonce.h"
extern "C" {
extern void *(*D_002B91A4)(u32 n);
extern void *(*D_002B91AC)(void *p, u32 n);
extern void (*D_002B91B0)(void *p);
void *memcpy(void *, const void *, u32);
void *memset(void *, s32, u32);
}
void Func235DE0(const char *fmt, ...);
extern "C" const char D_002D5560[], D_002D5820[], D_002DA2B8[];
struct ConstPtr { s32 w[0x4 / 4]; };
struct TArrConstPtr { s32 m0; ConstPtr *m_data; s32 m_cap; s32 m_count; s32 m_grow; void *vptr; };
extern "C" {
extern char _vt$t6TArray3ZPCvi_16_Zt10TAllocator1ZPCv[];
void func_00297768(TArrConstPtr *a, s32 n, s32 keep);
ConstPtr *func_002978F8(TArrConstPtr *a, s32 i);
ConstPtr *func_00297958(TArrConstPtr *a, s32 n);
void func_00297980(TArrConstPtr *a, ConstPtr *p);
void func_002979B0(TArrConstPtr *a, ConstPtr *p, const ConstPtr &v, s32 n);
void func_00297A18(TArrConstPtr *a, ConstPtr *p, s32 n);
ConstPtr *func_00297A70(TArrConstPtr *a, ConstPtr *p, s32 n);
void func_00297BD0(TArrConstPtr *a, ConstPtr *p, const ConstPtr &v);
void func_00297BE8(TArrConstPtr *a, ConstPtr *p);
void Func2976E8__FPvi(TArrConstPtr *a, s32 n);
}
struct EventCharaResName { s32 w[0x20 / 4]; };
struct TArrEventCharaResName { s32 m0; EventCharaResName *m_data; s32 m_cap; s32 m_count; s32 m_grow; void *vptr; };
extern "C" {
extern char _vt$t6TArray3Z18CEventCharaResNamei_16_Zt10TAllocator1Z18CEventCharaResName[];
void func_00297FB8(TArrEventCharaResName *a, s32 n, s32 keep);
EventCharaResName *func_00298158(TArrEventCharaResName *a, s32 i);
EventCharaResName *func_00298168(TArrEventCharaResName *a, s32 n);
void func_00298190(TArrEventCharaResName *a, EventCharaResName *p);
void func_002981C0(TArrEventCharaResName *a, EventCharaResName *p, const EventCharaResName &v, s32 n);
void func_00298228(TArrEventCharaResName *a, EventCharaResName *p, s32 n);
EventCharaResName *func_00298280(TArrEventCharaResName *a, EventCharaResName *p, s32 n);
void func_002982B8(TArrEventCharaResName *a, EventCharaResName *p, const EventCharaResName &v);
void func_00298308(TArrEventCharaResName *a, EventCharaResName *p);
void Func297F78__8CDkArrayi(TArrEventCharaResName *a, s32 n);
}
struct MapDBExprReg { s32 w[0x24 / 4]; };
struct TArrMapDBExprReg { s32 m0; MapDBExprReg *m_data; s32 m_cap; s32 m_count; s32 m_grow; void *vptr; };
extern "C" {
extern char _vt$t6TArray3Z13CMapDBExprRegi_16_Zt10TAllocator1Z13CMapDBExprReg[];
void func_0029A5E0(TArrMapDBExprReg *a, s32 n, s32 keep);
MapDBExprReg *func_0029A578(TArrMapDBExprReg *a, s32 i);
MapDBExprReg *func_0029A948(TArrMapDBExprReg *a, s32 n);
void func_0029A978(TArrMapDBExprReg *a, MapDBExprReg *p);
void func_0029A9A8(TArrMapDBExprReg *a, MapDBExprReg *p, const MapDBExprReg &v, s32 n);
void func_0029AA10(TArrMapDBExprReg *a, MapDBExprReg *p, s32 n);
MapDBExprReg *func_0029AA68(TArrMapDBExprReg *a, MapDBExprReg *p, s32 n);
void func_0029AAA8(TArrMapDBExprReg *a, MapDBExprReg *p, const MapDBExprReg &v);
void func_0029AB00(TArrMapDBExprReg *a, MapDBExprReg *p);
void Func29A558__10CUnk29A558i(TArrMapDBExprReg *a, s32 n);
}

extern "C" {
s32 Func297708__FPv(void *a);
void func_00297908(TArrConstPtr *a, s32 i, const ConstPtr &v);
void func_00297AA8(TArrConstPtr *a, s32 i, s32 n);
void func_00297BB8(TArrConstPtr *a, s32 i, const ConstPtr &v);
extern const char D_002D5598[];
}

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2N8 { s32 a; s32 b; };

struct W2Rand2 { u32 m_seed; u32 Next() { m_seed = m_seed * 0x19660D + 1; return (m_seed >> 12) & 0xFFFF; } };
struct Y1RandOwner { u32 m0; W2Rand2 m_rand; u8 pad[0x291C - 8]; s32 m_fixI; f32 m_fixF; };
inline f32 W2RandF(W2Rand2 *g, f32 lo, f32 hi) { u32 r = g->Next() << 16; r |= g->Next(); return (f32)(s32)(r & 0xFFFF) / 65535.0f * (hi - lo) + lo; }
// @decl-end

extern "C" void func_002975F0(VDel_2975F0 *p) { delete p; }

extern "C" TypeInfo *__tf7CSvmRes()
{
    if (!D_2EB7E0.vptr) func_00286BE0(&D_2EB7E0, D_002D51F0);
    return &D_2EB7E0;
}

extern "C" void func_00297668(TArrConstPtr *a)
{
    a->m_grow = 16;
    a->vptr = _vt$t6TArray3ZPCvi_16_Zt10TAllocator1ZPCv;
    a->m_count = 0;
    a->m_cap = 0;
    a->m_data = 0;
}

extern "C" void func_00297690(TArrConstPtr *a, s32 flag)
{
    Func2976E8__FPvi(a, 0);
    if (flag & 1) return __builtin_delete(a);
}

extern "C" void Func2976E8__FPvi(TArrConstPtr *a, s32 n) { func_00297768(a, n, 1); }

extern "C" s32 Func297708__FPv(void *p) { return FLD(s32, p, 0xC); }

extern "C" ConstPtr *Func297710__FPvi(TArrConstPtr *a, s32 i) { return func_002978F8(a, i); }

extern "C" void Func297728__FPvPi(TArrConstPtr *a, const ConstPtr &v) { func_00297908(a, Func297708__FPv(a), v); }

extern "C" void func_00297768(TArrConstPtr *a, s32 n, s32 keep)
{
    if (a->m_cap < n) {
        a->m_cap = (n + a->m_grow - 1) / a->m_grow * a->m_grow;
        ConstPtr *p = func_00297958(a, a->m_cap);
        if (!p) {
            Func235DE0(D_002D5560, a->m_cap * sizeof(ConstPtr));
            return;
        }
        if (a->m_data) {
            memcpy(p, a->m_data, a->m_count * sizeof(ConstPtr));
            func_00297980(a, a->m_data);
        }
        a->m_data = p;
    }
    if (keep) {
        if (a->m_count < n) {
            ConstPtr v;
            ConstPtr *q = a->m_data + a->m_count;
            memset(&v, 0, sizeof(ConstPtr));
            func_002979B0(a, q, v, n - a->m_count);
        } else if (n < a->m_count) {
            func_00297A18(a, a->m_data + n, a->m_count - n);
        }
    }
    a->m_count = n;
    if (a->m_data) {
        if (n == 0) {
            func_00297980(a, a->m_data);
            a->m_data = 0;
            a->m_cap = 0;
        } else if (a->m_cap - a->m_grow >= n) {
            a->m_cap = (n + a->m_grow - 1) / a->m_grow * a->m_grow;
            a->m_data = func_00297A70(a, a->m_data, a->m_cap);
        }
    }
}

extern "C" ConstPtr *func_002978F8(TArrConstPtr *a, s32 i) { return &a->m_data[i]; }

extern "C" void func_00297908(TArrConstPtr *a, s32 i, const ConstPtr &v)
{
    func_00297AA8(a, i, 1);
    func_00297BB8(a, i, v);
}

extern "C" ConstPtr *func_00297958(TArrConstPtr *a, s32 n) { return (ConstPtr *)D_002B91A4(n * sizeof(ConstPtr)); }

extern "C" void func_00297980(TArrConstPtr *a, ConstPtr *p) { if (p) D_002B91B0(p); }

extern "C" void func_002979B0(TArrConstPtr *a, ConstPtr *p, const ConstPtr &v, s32 n)
{
    for (s32 i = 0; i < n; i++) func_00297BD0(a, &p[i], v);
}

extern "C" void func_00297A18(TArrConstPtr *a, ConstPtr *p, s32 n)
{
    for (s32 i = 0; i < n; i++) func_00297BE8(a, &p[i]);
}

extern "C" ConstPtr *func_00297A70(TArrConstPtr *a, ConstPtr *p, s32 n)
{
    D_002B91AC(p, n * sizeof(ConstPtr));
    return p;
}

extern "C" void func_00297AA8(TArrConstPtr *a, s32 i, s32 n)
{
    if (i < 0 || Func297708__FPv(a) < i) {
        Func235DE0(D_002D5598, i, Func297708__FPv(a));
        return;
    }
    s32 end = i + n;
    func_00297768(a, Func297708__FPv(a) + n, 0);
    u8 *d = (u8 *)(a->m_data + end);
    u8 *s = (u8 *)(a->m_data + i);
    for (s32 k = (Func297708__FPv(a) - end) * sizeof(ConstPtr) - 1; k >= 0; k--)
        d[k] = s[k];
    ConstPtr tmp;
    tmp.w[0] = 0;
    func_002979B0(a, a->m_data + i, tmp, n);
}

extern "C" void func_00297BB8(TArrConstPtr *a, s32 i, const ConstPtr &v) { a->m_data[i] = v; }

extern "C" void func_00297BD0(TArrConstPtr *a, ConstPtr *p, const ConstPtr &v) { if (p) *p = v; }

extern "C" void func_00297BE8(TArrConstPtr *a, ConstPtr *p) {
}

extern "C" TypeInfo *__tft6TArray3ZPCvi_16_Zt10TAllocator1ZPCv()
{
    if (!D_2EB7E8.vptr) func_00286BE0(&D_2EB7E8, D_002D55C8);
    return &D_2EB7E8;
}

extern "C" TypeInfo *__tf8CSvmWork()
{
    if (!D_2EB7F0.vptr) func_00286BE0(&D_2EB7F0, D_002D55F0);
    return &D_2EB7F0;
}

extern "C" s32 func_00297C70(void *p) { return FLD(s32, p, 0x0); }

extern "C" s32 func_00297C78(void *p) { return FLD(s32, p, 0x68); }

extern "C" void func_00297C80(void *p, s32 v) { FLD(s32, p, 0x68) = v; }

extern "C" s32 func_00297C88(void *p) { return FLD(s32, p, 0x6C); }

extern "C" void *func_00297C90(void *p) { return (u8 *)p + 0x70; }

extern "C" void func_00297C98(void *p, s32 v) { FLD(s32, p, 0x4) = v; }

INCLUDE_ASM("asm/nonmatchings/Lib2975F0", func_00297CA0);

extern "C" f32 func_00297D20(Y1RandOwner *p, f32 lo, f32 hi) {
    return p->m_fixF >= 0.0f ? p->m_fixF : W2RandF(&p->m_rand, lo, hi);
}

extern "C" s32 func_00297DA0(void *p) { return FLD(s32, p, 0x291C); }

extern "C" void func_00297DA8(void *p, s32 v) { FLD(s32, p, 0x291C) = v; }

extern "C" f32 func_00297DB0(void *p) { return FLD(f32, p, 0x2920); }

extern "C" void func_00297DB8(void *p, s32 v) { FLD(f32, p, 0x2920) = v; }

extern "C" void func_00297DC8(void *p, s32 v) { FLD(s32, p, 0x2924) = v; }

extern "C" s32 func_00297DD0(void *p) { return FLD(s32, p, 0x2924); }

extern "C" void func_00297DD8(void *p, s32 v) { FLD(s32, p, 0x480) = v; }

extern "C" s32 func_00297DE0(void *p) { return FLD(s32, p, 0x480); }

extern "C" void func_00297DE8(void *p, s32 v) { FLD(s32, p, 0x470) = v; }

extern "C" s32 func_00297DF0(void *p) { return FLD(s32, p, 0x470); }

extern "C" void func_00297DF8(void *p) { FLD(s32, p, 0x2914) = 1; }

extern "C" void func_00297E08(void *p, s32 a, W2N8 n) { FLD(s32, p, 0x50) = a; FLD(W2N8, p, 0x54) = n; }

extern "C" void func_00297E30(void *p, s32 a, W2N8 n) { FLD(s32, p, 0x5C) = a; FLD(W2N8, p, 0x60) = n; }

extern "C" s32 func_00297E58(void *p) { return FLD(s32, p, 0x704); }

extern "C" s32 func_00297E60(void *p) { return FLD(s32, p, 0x47C); }

extern "C" void func_00297E68(void *p, s32 v) { FLD(s32, p, 0x290C) = v; }

extern "C" void func_00297E70(void *p, s32 v) { FLD(s32, p, 0x2910) = v; }

extern "C" s32 func_00297E78(void *p) { return FLD(s32, p, 0x2918); }

extern "C" s32 func_00297E80(void *p) { return FLD(s32, p, 0x484); }

extern "C" void func_00297E88(void *p, s32 a, s32 b) { FLD(s32, p, 0x2928) = a; FLD(s32, p, 0x292C) = b; FLD(s32, p, 0x2930) = 0; }

extern "C" s32 func_00297E98(void *p) { return FLD(s32, p, 0x2928) && FLD(s32, p, 0x292C) > 0; }

extern "C" TypeInfo *__tf9CEventRes()
{
    if (!D_2EB7F8.vptr) func_00286BE0(&D_2EB7F8, D_002D5660);
    return &D_2EB7F8;
}

extern "C" void func_00297EF8(TArrEventCharaResName *a)
{
    a->m_grow = 16;
    a->vptr = _vt$t6TArray3Z18CEventCharaResNamei_16_Zt10TAllocator1Z18CEventCharaResName;
    a->m_count = 0;
    a->m_cap = 0;
    a->m_data = 0;
}

extern "C" void func_00297F20(TArrEventCharaResName *a, s32 flag)
{
    Func297F78__8CDkArrayi(a, 0);
    if (flag & 1) return __builtin_delete(a);
}

extern "C" void Func297F78__8CDkArrayi(TArrEventCharaResName *a, s32 n) { func_00297FB8(a, n, 1); }

extern "C" s32 Func297F98__8CDkArray(void *p) { return FLD(s32, p, 0xC); }

extern "C" EventCharaResName *Func297FA0__8CDkArrayi(TArrEventCharaResName *a, s32 i) { return func_00298158(a, i); }

extern "C" void func_00297FB8(TArrEventCharaResName *a, s32 n, s32 keep)
{
    if (a->m_cap < n) {
        a->m_cap = (n + a->m_grow - 1) / a->m_grow * a->m_grow;
        EventCharaResName *p = func_00298168(a, a->m_cap);
        if (!p) {
            Func235DE0(D_002D5820, a->m_cap * sizeof(EventCharaResName));
            return;
        }
        if (a->m_data) {
            memcpy(p, a->m_data, a->m_count * sizeof(EventCharaResName));
            func_00298190(a, a->m_data);
        }
        a->m_data = p;
    }
    if (keep) {
        if (a->m_count < n) {
            EventCharaResName v;
            EventCharaResName *q = a->m_data + a->m_count;
            memset(&v, 0, sizeof(EventCharaResName));
            func_002981C0(a, q, v, n - a->m_count);
        } else if (n < a->m_count) {
            func_00298228(a, a->m_data + n, a->m_count - n);
        }
    }
    a->m_count = n;
    if (a->m_data) {
        if (n == 0) {
            func_00298190(a, a->m_data);
            a->m_data = 0;
            a->m_cap = 0;
        } else if (a->m_cap - a->m_grow >= n) {
            a->m_cap = (n + a->m_grow - 1) / a->m_grow * a->m_grow;
            a->m_data = func_00298280(a, a->m_data, a->m_cap);
        }
    }
}

extern "C" EventCharaResName *func_00298158(TArrEventCharaResName *a, s32 i) { return &a->m_data[i]; }

extern "C" EventCharaResName *func_00298168(TArrEventCharaResName *a, s32 n) { return (EventCharaResName *)D_002B91A4(n * sizeof(EventCharaResName)); }
