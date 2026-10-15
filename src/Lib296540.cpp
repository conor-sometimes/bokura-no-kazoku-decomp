#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "linkonce.h"
extern "C" {
extern TypeInfo D_2EB7D0;
extern const char D_002D4E48[];
extern TypeInfo D_2EB7C8;
extern const char D_002D4E88[];
extern TypeInfo D_2EB7D8;
extern const char D_002D4EC8[];
extern TypeInfo D_4247D0;
TypeInfo *__tf9CResCache();
extern const char D_002D4F40[];
extern TypeInfo D_2EB8C0;
extern TypeInfo D_4247C0;
TypeInfo *func_00295D00();
extern const char D_002D4F50[];
extern TypeInfo D_424700;
extern TypeInfo D_4247B0;
TypeInfo *__tf12ICharaResMgr();
extern const char D_002D4F60[];
extern TypeInfo D_424800;
extern const char D_002D5010[];
extern TypeInfo D_4247E0;
extern const char D_002D5020[];
extern TypeInfo D_4247F0;
TypeInfo *__tf10IMapResMgr();
extern const char D_002D5030[];
extern TypeInfo D_424820;
extern const char D_002D5130[];
extern TypeInfo D_424830;
extern const char D_002D5140[];
extern TypeInfo D_424810;
TypeInfo *__tf10IEnvResMgr();
extern const char D_002D5150[];
}
struct VDel_297208 { u8 pad[0x13c]; virtual ~VDel_297208(); };
struct VDel_297448 { u8 pad[0x13c]; virtual ~VDel_297448(); };

#include "linkonce.h"
extern "C" {
extern void *(*D_002B91A4)(u32 n);
extern void *(*D_002B91AC)(void *p, u32 n);
extern void (*D_002B91B0)(void *p);
void *memcpy(void *, const void *, u32);
void *memset(void *, s32, u32);
}
void Func235DE0(const char *fmt, ...);
extern "C" const char D_002D4E10[];
struct SceneMapSet { s32 w[0x54 / 4]; };
struct TArrSceneMapSet { s32 m0; SceneMapSet *m_data; s32 m_cap; s32 m_count; s32 m_grow; void *vptr; };
extern "C" {
extern char _vt$t6TArray3Z12CSceneMapSeti_16_Zt10TAllocator1Z12CSceneMapSet[];
void func_00296700(TArrSceneMapSet *a, s32 n, s32 keep);
SceneMapSet *func_002968E0(TArrSceneMapSet *a, s32 i);
SceneMapSet *func_00296AF0(TArrSceneMapSet *a, s32 n);
void func_00296B28(TArrSceneMapSet *a, SceneMapSet *p);
void func_00296B58(TArrSceneMapSet *a, SceneMapSet *p, const SceneMapSet &v, s32 n);
void func_00296BC0(TArrSceneMapSet *a, SceneMapSet *p, s32 n);
SceneMapSet *func_00296C18(TArrSceneMapSet *a, SceneMapSet *p, s32 n);
void func_00296DC0(TArrSceneMapSet *a, SceneMapSet *p, const SceneMapSet &v);
void func_00296E98(TArrSceneMapSet *a, SceneMapSet *p);
void func_00296678(TArrSceneMapSet *a, s32 n);
}
struct SceneCharaSet { s32 w[0x28 / 4]; };
struct TArrSceneCharaSet { s32 m0; SceneCharaSet *m_data; s32 m_cap; s32 m_count; s32 m_grow; void *vptr; };
extern "C" {
extern char _vt$t6TArray3Z14CSceneCharaSeti_16_Zt10TAllocator1Z14CSceneCharaSet[];
void func_00296900(TArrSceneCharaSet *a, s32 n, s32 keep);
SceneCharaSet *func_00296AC0(TArrSceneCharaSet *a, s32 i);
SceneCharaSet *func_00296AD8(TArrSceneCharaSet *a, s32 i);
SceneCharaSet *func_00296C60(TArrSceneCharaSet *a, s32 n);
void func_00296C90(TArrSceneCharaSet *a, SceneCharaSet *p);
void func_00296CC0(TArrSceneCharaSet *a, SceneCharaSet *p, const SceneCharaSet &v, s32 n);
void func_00296D28(TArrSceneCharaSet *a, SceneCharaSet *p, s32 n);
SceneCharaSet *func_00296D80(TArrSceneCharaSet *a, SceneCharaSet *p, s32 n);
void func_00296EA0(TArrSceneCharaSet *a, SceneCharaSet *p, const SceneCharaSet &v);
void func_00296F00(TArrSceneCharaSet *a, SceneCharaSet *p);
void func_002966B0(TArrSceneCharaSet *a, s32 n);
}

#include "linkonce.h"
extern "C" {
extern char _vt$12ICharaResMgr[];
void _$_9CResCache(void *, s32);
extern char _vt$10IMapResMgr[];
extern char _vt$10IEnvResMgr[];
}
extern "C" void *__nw__8CHeapObjUi(u32 n);

extern "C" s32 func_00296568(void *);
extern "C" s32 Func296570__7CDkList(void *);
// @decl-end

extern "C" void func_00296540(void *p, f32 v) { FLD(f32, p, 0x54) = v; }

extern "C" f32 func_00296548(void *p) { return FLD(f32, p, 0x54); }

extern "C" void func_00296550(void *p, f32 v) { FLD(f32, p, 0x98) = v; }

extern "C" f32 func_00296558(void *p) { return FLD(f32, p, 0x98); }

extern "C" void func_00296560(void *p, s32 v) { FLD(s32, p, 0x9C) = v; }

extern "C" s32 func_00296568(void *p) { return FLD(s32, p, 0xC); }

extern "C" s32 Func296570__7CDkList(void *p) { return FLD(s32, p, 0xC); }

extern "C" void func_00296578(TArrSceneMapSet *a)
{
    a->m_grow = 16;
    a->vptr = _vt$t6TArray3Z12CSceneMapSeti_16_Zt10TAllocator1Z12CSceneMapSet;
    a->m_count = 0;
    a->m_cap = 0;
    a->m_data = 0;
}

extern "C" void func_002965A0(TArrSceneMapSet *a, s32 flag)
{
    func_00296678(a, 0);
    if (flag & 1) return __builtin_delete(a);
}

extern "C" void func_002965F8(TArrSceneCharaSet *a)
{
    a->m_grow = 16;
    a->vptr = _vt$t6TArray3Z14CSceneCharaSeti_16_Zt10TAllocator1Z14CSceneCharaSet;
    a->m_count = 0;
    a->m_cap = 0;
    a->m_data = 0;
}

extern "C" void func_00296620(TArrSceneCharaSet *a, s32 flag)
{
    func_002966B0(a, 0);
    if (flag & 1) return __builtin_delete(a);
}

extern "C" void func_00296678(TArrSceneMapSet *a, s32 n) { func_00296700(a, n, 1); }

extern "C" SceneMapSet *func_00296698(TArrSceneMapSet *a, s32 i) { return func_002968E0(a, i); }

extern "C" void func_002966B0(TArrSceneCharaSet *a, s32 n) { func_00296900(a, n, 1); }

extern "C" SceneCharaSet *func_002966D0(TArrSceneCharaSet *a, s32 i) { return func_00296AC0(a, i); }

extern "C" SceneCharaSet *func_002966E8(TArrSceneCharaSet *a, s32 i) { return func_00296AD8(a, i); }

extern "C" void func_00296700(TArrSceneMapSet *a, s32 n, s32 keep)
{
    if (a->m_cap < n) {
        a->m_cap = (n + a->m_grow - 1) / a->m_grow * a->m_grow;
        SceneMapSet *p = func_00296AF0(a, a->m_cap);
        if (!p) {
            Func235DE0(D_002D4E10, a->m_cap * sizeof(SceneMapSet));
            return;
        }
        if (a->m_data) {
            memcpy(p, a->m_data, a->m_count * sizeof(SceneMapSet));
            func_00296B28(a, a->m_data);
        }
        a->m_data = p;
    }
    if (keep) {
        if (a->m_count < n) {
            SceneMapSet v;
            SceneMapSet *q = a->m_data + a->m_count;
            memset(&v, 0, sizeof(SceneMapSet));
            func_00296B58(a, q, v, n - a->m_count);
        } else if (n < a->m_count) {
            func_00296BC0(a, a->m_data + n, a->m_count - n);
        }
    }
    a->m_count = n;
    if (a->m_data) {
        if (n == 0) {
            func_00296B28(a, a->m_data);
            a->m_data = 0;
            a->m_cap = 0;
        } else if (a->m_cap - a->m_grow >= n) {
            a->m_cap = (n + a->m_grow - 1) / a->m_grow * a->m_grow;
            a->m_data = func_00296C18(a, a->m_data, a->m_cap);
        }
    }
}

extern "C" SceneMapSet *func_002968E0(TArrSceneMapSet *a, s32 i) { return &a->m_data[i]; }

extern "C" void func_00296900(TArrSceneCharaSet *a, s32 n, s32 keep)
{
    if (a->m_cap < n) {
        a->m_cap = (n + a->m_grow - 1) / a->m_grow * a->m_grow;
        SceneCharaSet *p = func_00296C60(a, a->m_cap);
        if (!p) {
            Func235DE0(D_002D4E10, a->m_cap * sizeof(SceneCharaSet));
            return;
        }
        if (a->m_data) {
            memcpy(p, a->m_data, a->m_count * sizeof(SceneCharaSet));
            func_00296C90(a, a->m_data);
        }
        a->m_data = p;
    }
    if (keep) {
        if (a->m_count < n) {
            SceneCharaSet v;
            SceneCharaSet *q = a->m_data + a->m_count;
            memset(&v, 0, sizeof(SceneCharaSet));
            func_00296CC0(a, q, v, n - a->m_count);
        } else if (n < a->m_count) {
            func_00296D28(a, a->m_data + n, a->m_count - n);
        }
    }
    a->m_count = n;
    if (a->m_data) {
        if (n == 0) {
            func_00296C90(a, a->m_data);
            a->m_data = 0;
            a->m_cap = 0;
        } else if (a->m_cap - a->m_grow >= n) {
            a->m_cap = (n + a->m_grow - 1) / a->m_grow * a->m_grow;
            a->m_data = func_00296D80(a, a->m_data, a->m_cap);
        }
    }
}

extern "C" SceneCharaSet *func_00296AC0(TArrSceneCharaSet *a, s32 i) { return &a->m_data[i]; }

extern "C" SceneCharaSet *func_00296AD8(TArrSceneCharaSet *a, s32 i) { return &a->m_data[i]; }

extern "C" SceneMapSet *func_00296AF0(TArrSceneMapSet *a, s32 n) { return (SceneMapSet *)D_002B91A4(n * sizeof(SceneMapSet)); }

extern "C" void func_00296B28(TArrSceneMapSet *a, SceneMapSet *p) { if (p) D_002B91B0(p); }

extern "C" void func_00296B58(TArrSceneMapSet *a, SceneMapSet *p, const SceneMapSet &v, s32 n)
{
    for (s32 i = 0; i < n; i++) func_00296DC0(a, &p[i], v);
}

extern "C" void func_00296BC0(TArrSceneMapSet *a, SceneMapSet *p, s32 n)
{
    for (s32 i = 0; i < n; i++) func_00296E98(a, &p[i]);
}

extern "C" SceneMapSet *func_00296C18(TArrSceneMapSet *a, SceneMapSet *p, s32 n)
{
    D_002B91AC(p, n * sizeof(SceneMapSet));
    return p;
}

extern "C" SceneCharaSet *func_00296C60(TArrSceneCharaSet *a, s32 n) { return (SceneCharaSet *)D_002B91A4(n * sizeof(SceneCharaSet)); }

extern "C" void func_00296C90(TArrSceneCharaSet *a, SceneCharaSet *p) { if (p) D_002B91B0(p); }

extern "C" void func_00296CC0(TArrSceneCharaSet *a, SceneCharaSet *p, const SceneCharaSet &v, s32 n)
{
    for (s32 i = 0; i < n; i++) func_00296EA0(a, &p[i], v);
}

extern "C" void func_00296D28(TArrSceneCharaSet *a, SceneCharaSet *p, s32 n)
{
    for (s32 i = 0; i < n; i++) func_00296F00(a, &p[i]);
}

extern "C" SceneCharaSet *func_00296D80(TArrSceneCharaSet *a, SceneCharaSet *p, s32 n)
{
    D_002B91AC(p, n * sizeof(SceneCharaSet));
    return p;
}

extern "C" void func_00296DC0(TArrSceneMapSet *a, SceneMapSet *p, const SceneMapSet &v) { if (p) *p = v; }

extern "C" void func_00296E98(TArrSceneMapSet *a, SceneMapSet *p) {
}

extern "C" void func_00296EA0(TArrSceneCharaSet *a, SceneCharaSet *p, const SceneCharaSet &v) { if (p) *p = v; }

extern "C" void func_00296F00(TArrSceneCharaSet *a, SceneCharaSet *p) {
}

extern "C" TypeInfo *__tft6TArray3Z12CSceneMapSeti_16_Zt10TAllocator1Z12CSceneMapSet()
{
    if (!D_2EB7D0.vptr) func_00286BE0(&D_2EB7D0, D_002D4E48);
    return &D_2EB7D0;
}

extern "C" TypeInfo *__tft6TArray3Z14CSceneCharaSeti_16_Zt10TAllocator1Z14CSceneCharaSet()
{
    if (!D_2EB7C8.vptr) func_00286BE0(&D_2EB7C8, D_002D4E88);
    return &D_2EB7C8;
}

extern "C" TypeInfo *__tf9CSceneSet()
{
    if (!D_2EB7D8.vptr) func_00286BE0(&D_2EB7D8, D_002D4EC8);
    return &D_2EB7D8;
}

extern "C" s32 func_00296FC8(void *p) { return func_00296568(p); }

extern "C" s32 func_00296FE0(void *p) { return Func296570__7CDkList((u8 *)p + 0x18); }

extern "C" void func_00296FF8(void *p, s32 v) { FLD(s32, p, 0x38) = v; }

extern "C" void func_00297000(void *p, s32 flag)
{
    FLD(void *, p, 0x13C) = _vt$12ICharaResMgr;
    _$_9CResCache(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf12ICharaResMgr()
{
    if (!D_4247D0.vptr) {
        __tf9CResCache();
        func_00286BC0(&D_4247D0, D_002D4F40, &D_2EB8C0);
    }
    return &D_4247D0;
}

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_002970B8);

extern "C" TypeInfo *__tf12CCharaResObj()
{
    if (!D_4247C0.vptr) {
        func_00295D00();
        func_00286BC0(&D_4247C0, D_002D4F50, &D_424700);
    }
    return &D_4247C0;
}

extern "C" void *func_002971A0(u32 n) { return __nw__8CHeapObjUi(n); }

extern "C" TypeInfo *__tf12CCharaResMgr()
{
    if (!D_4247B0.vptr) {
        __tf12ICharaResMgr();
        func_00286BC0(&D_4247B0, D_002D4F60, &D_4247D0);
    }
    return &D_4247B0;
}

extern "C" void func_00297208(VDel_297208 *p) { delete p; }

extern "C" void func_00297240(void *p, s32 flag)
{
    FLD(void *, p, 0x13C) = _vt$10IMapResMgr;
    _$_9CResCache(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf10IMapResMgr()
{
    if (!D_424800.vptr) {
        __tf9CResCache();
        func_00286BC0(&D_424800, D_002D5010, &D_2EB8C0);
    }
    return &D_424800;
}

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_002972F8);

extern "C" TypeInfo *__tf10CMapResObj()
{
    if (!D_4247E0.vptr) {
        func_00295D00();
        func_00286BC0(&D_4247E0, D_002D5020, &D_424700);
    }
    return &D_4247E0;
}

extern "C" void *func_002973E0(u32 n) { return __nw__8CHeapObjUi(n); }

extern "C" TypeInfo *__tf10CMapResMgr()
{
    if (!D_4247F0.vptr) {
        __tf10IMapResMgr();
        func_00286BC0(&D_4247F0, D_002D5030, &D_424800);
    }
    return &D_4247F0;
}

extern "C" void func_00297448(VDel_297448 *p) { delete p; }

extern "C" void func_00297480(void *p, s32 flag)
{
    FLD(void *, p, 0x13C) = _vt$10IEnvResMgr;
    _$_9CResCache(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf10IEnvResMgr()
{
    if (!D_424820.vptr) {
        __tf9CResCache();
        func_00286BC0(&D_424820, D_002D5130, &D_2EB8C0);
    }
    return &D_424820;
}

extern "C" TypeInfo *__tf10CEnvResObj()
{
    if (!D_424830.vptr) {
        func_00295D00();
        func_00286BC0(&D_424830, D_002D5140, &D_424700);
    }
    return &D_424830;
}

extern "C" void *func_00297588(u32 n) { return __nw__8CHeapObjUi(n); }

extern "C" TypeInfo *__tf10CEnvResMgr()
{
    if (!D_424810.vptr) {
        __tf10IEnvResMgr();
        func_00286BC0(&D_424810, D_002D5150, &D_424820);
    }
    return &D_424810;
}
