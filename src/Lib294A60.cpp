#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CTask.h"
extern "C" void CTask_dtor(CTask *, s32) asm("_$_5CTask");
extern "C" void func_00286BC0(void *, const char *, void *);
extern "C" void func_00286BE0(void *, const char *);
extern "C" char D_002D3B90[];
extern "C" char D_002D3BD8[];
extern "C" char D_002D3C18[];
extern "C" char D_002D3D78[];
extern "C" char D_002D3E48[];
extern "C" char D_002D41F0[];
extern "C" char D_002D4230[];
extern "C" char D_002D4900[];
extern "C" char D_002D4910[];
extern "C" char D_002D4920[];
extern "C" char D_002D4930[];
extern "C" char D_002D4948[];
extern "C" char D_002D4960[];
extern "C" u8 D_2EB760[];
extern "C" u8 D_2EB768[];
extern "C" u8 D_2EB770[];
extern "C" u8 D_2EB778[];
extern "C" u8 D_2EB780[];
extern "C" u8 D_2EB788[];
extern "C" u8 D_2EB790[];
extern "C" u8 D_2EB798[];
extern "C" u8 D_2EB7A0[];
extern "C" u8 D_424700[];
extern "C" u8 D_424740[];
extern "C" u8 D_424750[];
extern "C" u8 D_424760[];
extern "C" u8 D_424790[];
extern "C" void *__tf11CMapEffWork(void);
extern "C" void *func_00295D00(void);

struct TArrayBase { s32 m0; u8 *m_data; s32 m_cap; s32 m_count; s32 m_grow; void *m_vptr; };
extern void *(*D_002B91A4)(u32 n);
extern void (*D_002B91B0)(void *p);
extern void *(*D_002B91AC)(void *p, u32 n);
extern "C" void *memcpy(void *, const void *, u32);
extern "C" void *memset(void *, s32, u32);
extern "C" void __builtin_delete(void *);
void Func235DE0(const char *fmt, ...);
struct CMapAttrLightPos { s32 m[4]; };
struct TArrB { s32 m0; CMapAttrLightPos *m_data; s32 m_cap; s32 m_count; s32 m_grow; void *m_vptr; };
class CModelAccSub118168 { public: CModelAccSub118168 *Init(); };
extern "C" void func_00294E90(TArrB *a, s32 flags);
// The map light (0xC0 bytes): its constructor is CModelAccSub118168::Init (it returns this), its
// destructor only destroys the TArray<CMapAttrLightPos> at 0x28.
struct CMapAttrLight {
    CMapAttrLight() { ((CModelAccSub118168 *)this)->Init(); }
    ~CMapAttrLight() { func_00294E90(&m_pos, 2); }
    u8 m0[0x28];
    TArrB m_pos;              // 0x28
    u8 m40[0x80];
};
extern "C" char D_002D3B28[];
struct MapEffInfo;
extern "C" char D_002D4188[];
struct TArrA { s32 m0; CMapAttrLight *m_data; s32 m_cap; s32 m_count; s32 m_grow; void *m_vptr; };
extern u8 TArrA_vt[] asm("_vt$t6TArray3Z13CMapAttrLighti_16_Zt10TAllocator1Z13CMapAttrLight");
extern "C" void func_00294308(TArrA *a);
extern "C" void func_00294330(TArrA *a, s32 flags);
extern "C" void func_00294388(TArrA *a, s32 n);
extern "C" s32 func_002943A8(TArrA *a);
extern "C" CMapAttrLight *func_002943B0(TArrA *a, s32 i);
extern "C" CMapAttrLight *func_002945F8(TArrA *a, s32 i);
extern "C" CMapAttrLight *func_00294420(TArrA *a, s32 i);
extern "C" CMapAttrLight *func_002947D0(TArrA *a, s32 i);
extern "C" void func_00294438(TArrA *a, s32 n, s32 init);
extern "C" CMapAttrLight *func_002947E8(TArrA *a, s32 n);
extern "C" void func_00294818(TArrA *a, CMapAttrLight *p);
extern "C" void func_00294848(TArrA *a, CMapAttrLight *p, CMapAttrLight *src, s32 n);
extern "C" void func_002948B0(TArrA *a, CMapAttrLight *p, s32 n);
extern "C" CMapAttrLight *func_00294908(TArrA *a, CMapAttrLight *p, s32 n);
extern "C" void func_00294A98(TArrA *a, CMapAttrLight *p, CMapAttrLight *src);
extern "C" void func_00294C28(TArrA *a, CMapAttrLight *p);
extern u8 TArrB_vt[] asm("_vt$t6TArray3Z16CMapAttrLightPosi_16_Zt10TAllocator1Z16CMapAttrLightPos");
extern "C" void func_002942E0(TArrB *a);
extern "C" void func_00294E90(TArrB *a, s32 flags);
extern "C" void func_002943E8(TArrB *a, s32 n);
extern "C" s32 func_002943C8(TArrB *a);
extern "C" CMapAttrLightPos *func_002943D0(TArrB *a, s32 i);
extern "C" CMapAttrLightPos *func_00294610(TArrB *a, s32 i);
extern "C" CMapAttrLightPos *func_00294408(TArrB *a, s32 i);
extern "C" CMapAttrLightPos *func_002947C0(TArrB *a, s32 i);
extern "C" void func_00294620(TArrB *a, s32 n, s32 init);
extern "C" CMapAttrLightPos *func_00294948(TArrB *a, s32 n);
extern "C" void func_00294970(TArrB *a, CMapAttrLightPos *p);
extern "C" void func_002949A0(TArrB *a, CMapAttrLightPos *p, CMapAttrLightPos *src, s32 n);
extern "C" void func_00294A08(TArrB *a, CMapAttrLightPos *p, s32 n);
extern "C" CMapAttrLightPos *func_00294A60(TArrB *a, CMapAttrLightPos *p, s32 n);
extern "C" void func_00294C48(TArrB *a, CMapAttrLightPos *p, CMapAttrLightPos *src);
extern "C" void func_00294C78(TArrB *a, CMapAttrLightPos *p);
struct TArrC { s32 m0; MapEffInfo * *m_data; s32 m_cap; s32 m_count; s32 m_grow; void *m_vptr; };
extern u8 TArrC_vt[] asm("_vt$t6TArray3ZP10MapEffInfoi_16_Zt10TAllocator1ZP10MapEffInfo");
extern "C" void func_00295090(TArrC *a);
extern "C" void func_002950B8(TArrC *a, s32 flags);
extern "C" void func_00295188(TArrC *a, s32 n);
extern "C" s32 func_00295110(TArrC *a);
extern "C" MapEffInfo * *func_00295118(TArrC *a, s32 i);
extern "C" MapEffInfo * *func_002951A8(TArrC *a, s32 i);
extern "C" MapEffInfo * *func_00295170(TArrC *a, s32 i);
extern "C" MapEffInfo * *func_00295208(TArrC *a, s32 i);
extern "C" void func_00295218(TArrC *a, s32 n, s32 init);
extern "C" MapEffInfo * *func_002954D0(TArrC *a, s32 n);
extern "C" void func_002954F8(TArrC *a, MapEffInfo * *p);
extern "C" void func_00295528(TArrC *a, MapEffInfo * *p, MapEffInfo * *src, s32 n);
extern "C" void func_00295590(TArrC *a, MapEffInfo * *p, s32 n);
extern "C" MapEffInfo * *func_002955E8(TArrC *a, MapEffInfo * *p, s32 n);
extern "C" void func_00295620(TArrC *a, MapEffInfo * *p, MapEffInfo * *src);
extern "C" void func_00295638(TArrC *a, MapEffInfo * *p);
extern "C" void func_00295130(TArrC *a, MapEffInfo * *v);
extern "C" void func_002951B8(TArrC *a, s32 pos, MapEffInfo * *v);
extern "C" void func_002953A8(TArrC *a, s32 pos, s32 n);
extern "C" void func_002954B8(TArrC *a, s32 pos, MapEffInfo * *v);

struct ListTag { s32 isHead; ListTag *prev; ListTag *next; void *vptr; };
extern u8 CListTag_vt[] asm("_vt$8CListTag");
extern u8 CMapEffWork_vt[] asm("_vt$11CMapEffWork");
extern void (*D_002B91B0)(void *p);
extern u8 TArrLightPos_vt[] asm("_vt$t6TArray3Z16CMapAttrLightPosi_16_Zt10TAllocator1Z16CMapAttrLightPos");
extern "C" void func_00294CC0(TArrB *a, s32 pos, TArrB *src);
extern "C" void func_00294D70(TArrB *a, s32 pos, s32 n);
extern const char D_002D41C0[];

extern "C" void W2Fill(TArrB *, CMapAttrLightPos *, const CMapAttrLightPos &, s32) asm("func_002949A0");
extern "C" s32 W2Cnt(TArrB *) throw() asm("func_002943C8");
extern const char D_002D3B60[];

inline void *operator new(unsigned int, void *p) throw() { return p; }
struct W2ArrB {
    s32 m0; void *m4; s32 m8, mC, m10; void *m14;
    W2ArrB(const W2ArrB &o) asm("func_00294C80");
};
struct W2Lt {
    s32 m0;
    f32 m10[4] __attribute__((aligned(16)));
    f32 m20[2];
    W2ArrB m28;
    f32 m40; s32 m44;
    f32 m50[4] __attribute__((aligned(16)));
    s32 m60;
    f32 m70[4] __attribute__((aligned(16)));
    f32 m80; s32 m84;
    f32 m90[4] __attribute__((aligned(16)));
    s32 mA0;
    f32 mB0[4] __attribute__((aligned(16)));
};
struct DlV4 { f32 x, y, z, w; };
inline void DlVuSub3(DlV4 *d, DlV4 *a, DlV4 *b) {
    asm volatile("lqc2 $vf4, 0x0(%1)\n\tlqc2 $vf5, 0x0(%2)\n\tlqc2 $vf6, 0x0(%1)\n\tvsub.xyz $vf6, $vf4, $vf5\n\tsqc2 $vf6, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
inline f32 DlVuSqrtB(f32 x) { f32 r; asm volatile("mfc1 $8, %1\n\tqmtc2.ni $8, $vf2\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "f"(x) : "$8"); return r; }
// @decl-end

extern "C" CMapAttrLightPos *func_00294A60(TArrB *a, CMapAttrLightPos *p, s32 n) {
    D_002B91AC(p, n * sizeof(CMapAttrLightPos));
    return p;
}

extern "C" void func_00294A98(TArrA *a, CMapAttrLight *p, CMapAttrLight *src)
{
    new (p) W2Lt(*(W2Lt *)src);
}

extern "C" void func_00294C28(TArrA *a, CMapAttrLight *p) {
    func_00294E90(&p->m_pos, 2);
}

extern "C" void func_00294C48(TArrB *a, CMapAttrLightPos *p, CMapAttrLightPos *src) {
    if (p) *p = *src;
}

extern "C" void func_00294C78(TArrB *a, CMapAttrLightPos *p) {
}

// TArray<CMapAttrLightPos> copy constructor
extern "C" void func_00294C80(TArrB *a, TArrB *src) {
    a->m_vptr = TArrLightPos_vt;
    a->m_data = 0;
    a->m_count = 0;
    a->m_cap = 0;
    a->m_grow = 16;
    return (void)func_00294CC0(a, 0, src);
}

extern "C" void func_00294CC0(TArrB *a, s32 pos, TArrB *src) {
    s32 i;
    func_00294D70(a, pos, func_002943C8(src));
    for (i = 0; i < func_002943C8(src); i++) a->m_data[pos + i] = src->m_data[i];
}

extern "C" void func_00294D70(TArrB *a, s32 i, s32 n)
{
    if (i < 0 || W2Cnt(a) < i) {
        Func235DE0(D_002D3B60, i, W2Cnt(a));
        return;
    }
    s32 end = i + n;
    func_00294620(a, W2Cnt(a) + n, 0);
    u8 *d = (u8 *)(a->m_data + end);
    u8 *s = (u8 *)(a->m_data + i);
    for (s32 k = (W2Cnt(a) - end) * sizeof(*a->m_data) - 1; k >= 0; k--)
        d[k] = s[k];
    W2Fill(a, a->m_data + i, CMapAttrLightPos(), n);
}

extern "C" void func_00294E90(TArrB *a, s32 flags) {
    func_002943E8(a, 0);
    if (flags & 1) return (void)__builtin_delete(a);
}

extern "C" void *__tft6TArray3Z16CMapAttrLightPosi_16_Zt10TAllocator1Z16CMapAttrLightPos(void) {
    if (*(s32 *)D_2EB770 == 0) {
        func_00286BE0(D_2EB770, D_002D3B90);
    }
    return D_2EB770;
}

extern "C" void *__tft6TArray3Z13CMapAttrLighti_16_Zt10TAllocator1Z13CMapAttrLight(void) {
    if (*(s32 *)D_2EB760 == 0) {
        func_00286BE0(D_2EB760, D_002D3BD8);
    }
    return D_2EB760;
}

extern "C" void *__tf8CMapAttr(void) {
    if (*(s32 *)D_2EB768 == 0) {
        func_00286BE0(D_2EB768, D_002D3C18);
    }
    return D_2EB768;
}

extern "C" void *__tf7CMapRes(void) {
    if (*(s32 *)D_2EB778 == 0) {
        func_00286BE0(D_2EB778, D_002D3D78);
    }
    return D_2EB778;
}

extern "C" s32 func_00294FE8(u8 *p) { return *(s32 *)(p + 0x18); }

extern "C" s32 func_00294FF0(u8 *p) { return *(s32 *)(p + 0x1C); }

extern "C" s32 func_00294FF8(u8 *p) { return *(s32 *)(p + 0x20); }

extern "C" s32 func_00295000(u8 *p, s32 i) { return ((s32 *)(p + 0x24))[i]; }

extern "C" void *__tf7CMapObj(void) {
    if (*(s32 *)D_2EB780 == 0) {
        func_00286BE0(D_2EB780, D_002D3E48);
    }
    return D_2EB780;
}

extern "C" void func_00295050(u8 *p, s32 a, s32 b) {
    *(s32 *)(p + 0x10) = a;
    *(s32 *)(p + 0x14) = b;
}

extern "C" void func_00295060(u8 *p, s32 a, s32 b, s32 c, s32 d) {
    *(s32 *)(p + 0x20) = a;
    *(s32 *)(p + 0x24) = b;
    *(s32 *)(p + 0x28) = c;
    *(s32 *)(p + 0x2C) = d;
}

extern "C" s32 func_00295078(u8 *p) { return *(s32 *)(p + 0x0); }

extern "C" s32 func_00295080(u8 *p) { return *(s32 *)(p + 0x4); }

extern "C" s32 func_00295088(u8 *p) { return *(s32 *)(p + 0x8); }

extern "C" void func_00295090(TArrC *a) {
    a->m_vptr = TArrC_vt;
    a->m_data = 0;
    a->m_count = 0;
    a->m_cap = 0;
    a->m_grow = 16;
}

extern "C" void func_002950B8(TArrC *a, s32 flags) {
    func_00295188(a, 0);
    if (flags & 1) return (void)__builtin_delete(a);
}

extern "C" s32 func_00295110(TArrC *a) { return a->m_count; }

extern "C" MapEffInfo * *func_00295118(TArrC *a, s32 i) {
    return func_002951A8(a, i);
}

extern "C" void func_00295130(TArrC *a, MapEffInfo * *v) {
    func_002951B8(a, func_00295110(a), v);
}

extern "C" MapEffInfo * *func_00295170(TArrC *a, s32 i) {
    return func_00295208(a, i);
}

extern "C" void func_00295188(TArrC *a, s32 n) {
    func_00295218(a, n, 1);
}

extern "C" MapEffInfo * *func_002951A8(TArrC *a, s32 i) {
    return &a->m_data[i];
}

extern "C" void func_002951B8(TArrC *a, s32 pos, MapEffInfo * *v) {
    func_002953A8(a, pos, 1);
    func_002954B8(a, pos, v);
}

extern "C" MapEffInfo * *func_00295208(TArrC *a, s32 i) {
    return &a->m_data[i];
}

extern "C" void func_00295218(TArrC *a, s32 n, s32 init) {
    if (a->m_cap < n) {
        MapEffInfo * *p;
        a->m_cap = (n + a->m_grow - 1) / a->m_grow * a->m_grow;
        p = func_002954D0(a, a->m_cap);
        if (p == 0) {
            Func235DE0(D_002D4188, a->m_cap * sizeof(MapEffInfo *));
            return;
        }
        if (a->m_data) {
            memcpy(p, a->m_data, a->m_count * sizeof(MapEffInfo *));
            func_002954F8(a, a->m_data);
        }
        a->m_data = p;
    }
    if (init) {
        if (a->m_count < n) {
            MapEffInfo *tmp = 0;
            func_00295528(a, a->m_data + a->m_count, &tmp, n - a->m_count);
        } else if (n < a->m_count) {
            func_00295590(a, a->m_data + n, a->m_count - n);
        }
    }
    a->m_count = n;
    if (a->m_data) {
        if (n == 0) {
            func_002954F8(a, a->m_data);
            a->m_data = 0;
            a->m_cap = 0;
        } else if (a->m_cap - a->m_grow >= n) {
            a->m_cap = (n + a->m_grow - 1) / a->m_grow * a->m_grow;
            a->m_data = func_002955E8(a, a->m_data, a->m_cap);
        }
    }
}

extern "C" void func_002953A8(TArrC *a, s32 i, s32 n)
{
    if (i < 0 || func_00295110(a) < i) {
        Func235DE0(D_002D41C0, i, func_00295110(a));
        return;
    }
    s32 end = i + n;
    func_00295218(a, func_00295110(a) + n, 0);
    u8 *d = (u8 *)(a->m_data + end);
    u8 *s = (u8 *)(a->m_data + i);
    for (s32 k = (func_00295110(a) - end) * sizeof(*a->m_data) - 1; k >= 0; k--)
        d[k] = s[k];
    MapEffInfo *tmp;
    tmp = 0;
    func_00295528(a, a->m_data + i, &tmp, n);
}

extern "C" void func_002954B8(TArrC *a, s32 pos, MapEffInfo * *v) {
    a->m_data[pos] = *v;
}

extern "C" MapEffInfo * *func_002954D0(TArrC *a, s32 n) {
    return (MapEffInfo * *)D_002B91A4(n * sizeof(MapEffInfo *));
}

extern "C" void func_002954F8(TArrC *a, MapEffInfo * *p) {
    if (p) D_002B91B0(p);
}

extern "C" void func_00295528(TArrC *a, MapEffInfo * *p, MapEffInfo * *src, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) func_00295620(a, &p[i], src);
}

extern "C" void func_00295590(TArrC *a, MapEffInfo * *p, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) func_00295638(a, &p[i]);
}

extern "C" MapEffInfo * *func_002955E8(TArrC *a, MapEffInfo * *p, s32 n) {
    D_002B91AC(p, n * sizeof(MapEffInfo *));
    return p;
}

extern "C" void func_00295620(TArrC *a, MapEffInfo * *p, MapEffInfo * *src) {
    if (p) *p = *src;
}

extern "C" void func_00295638(TArrC *a, MapEffInfo * *p) {
}

extern "C" void *__tft6TArray3ZP10MapEffInfoi_16_Zt10TAllocator1ZP10MapEffInfo(void) {
    if (*(s32 *)D_2EB788 == 0) {
        func_00286BE0(D_2EB788, D_002D41F0);
    }
    return D_2EB788;
}

extern "C" void *__tf10CMapEffRes(void) {
    if (*(s32 *)D_2EB790 == 0) {
        func_00286BE0(D_2EB790, D_002D4230);
    }
    return D_2EB790;
}

extern "C" void *__tf10CMapEffObj(void) {
    if (*(s32 *)D_2EB7A0 == 0) {
        func_00286BE0(D_2EB7A0, D_002D4900);
    }
    return D_2EB7A0;
}

extern "C" s32 func_00295700(u8 *p) { return *(s32 *)(p + 0x0); }

// CMapEffObjRes::~CMapEffObjRes() (linkonce, deleting): only the CListTag base's unlink
extern "C" void CMapEffObjRes_dtor(ListTag *p, s32 flags) asm("_$_13CMapEffObjRes");
extern "C" void CMapEffObjRes_dtor(ListTag *p, s32 flags) {
    p->vptr = CListTag_vt;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    p->next = p;
    p->prev = p;
    if (flags & 1) return (void)__builtin_delete(p);
}

extern "C" void *__tf13CMapEffObjRes(void) {
    if (*(s32 *)D_424750 == 0) {
        func_00295D00();
        func_00286BC0(D_424750, D_002D4910, D_424700);
    }
    return D_424750;
}

extern "C" void *__tf11CMapEffWork(void) {
    if (*(s32 *)D_2EB798 == 0) {
        func_00286BE0(D_2EB798, D_002D4920);
    }
    return D_2EB798;
}

// CMapEffWork::~CMapEffWork() (linkonce, deleting; vptr at 0, operator delete through D_002B91B0)
extern "C" void func_002957F8(void **p, s32 flags) {
    *p = CMapEffWork_vt;
    if (flags & 1) D_002B91B0(p);
}

// CMapEffWork[1]
extern "C" s32 func_00295830(u8 *p) { return 0; }

extern "C" void func_00295838(void) {
}

extern "C" void func_00295840(void) {
}

extern "C" void func_00295848(void) {
}

extern "C" void *__tf18CMapEffCurtainWork(void) {
    if (*(s32 *)D_424790 == 0) {
        __tf11CMapEffWork();
        func_00286BC0(D_424790, D_002D4930, D_2EB798);
    }
    return D_424790;
}

// CMapEffCurtainWork[1]
extern "C" s32 func_002958A0(u8 *p, s32 id) { return id == -100; }

extern "C" f32 func_002958B0(u8 *p, DlV4 *d, DlV4 *a, DlV4 *b)
{
    DlVuSub3(d, a, b);
    return DlVuSqrtB(d->x * d->x + d->y * d->y + d->z * d->z);
}

extern "C" void *__tf15CMapEffLeafWork(void) {
    if (*(s32 *)D_424760 == 0) {
        __tf11CMapEffWork();
        func_00286BC0(D_424760, D_002D4948, D_2EB798);
    }
    return D_424760;
}

extern "C" void *__tf14CMapEffFlyWork(void) {
    if (*(s32 *)D_424740 == 0) {
        __tf11CMapEffWork();
        func_00286BC0(D_424740, D_002D4960, D_2EB798);
    }
    return D_424740;
}
