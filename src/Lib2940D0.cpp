#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CTask.h"
extern "C" void CTask_dtor(CTask *, s32) asm("_$_5CTask");
extern "C" void func_00286BC0(void *, const char *, void *);
extern "C" void func_00286BE0(void *, const char *);
extern "C" char D_002D3768[];
extern "C" char D_002D37F0[];
extern "C" char D_002D3808[];
extern "C" u8 D_2EB708[];
extern "C" u8 D_2EB758[];
extern "C" u8 D_4246B0[];
extern "C" u8 D_4246D0[];
extern "C" void *__tf8CListTag(void);
extern "C" void *func_002942A0(void);

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
class CModelAccSub118168 { public: CModelAccSub118168 *Init() throw(); };
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

// A class whose slot 0 is an inline Release() { delete this; } and whose destructor is slot 6.
class CRelease7 {
public:
    virtual void Release();
    virtual void Func1();
    virtual void Func2();
    virtual void Func3();
    virtual void Func4();
    virtual void Func5();
    virtual ~CRelease7();
};
// @decl-end

extern "C" s32 func_002940D0(u8 *p) { return *(s32 *)(p + 0x74); }

extern "C" s32 func_002940D8(u8 *p) { return *(s32 *)(p + 0x78); }

extern "C" void func_002940E0(u8 *p, f32 v) { *(f32 *)(p + 0x7C) = v; }

extern "C" void func_002940E8(u8 *p, f32 v) { *(f32 *)(p + 0x80) = v; }

extern "C" f32 func_002940F0(u8 *p) { return *(f32 *)(p + 0x7C); }

extern "C" f32 func_002940F8(u8 *p) { return *(f32 *)(p + 0x80); }

extern "C" s32 func_00294100(u8 *p) { return *(s32 *)(p + 0x94); }

extern "C" s32 func_00294108(u8 *p) { return *(s32 *)(p + 0x90); }

extern "C" s32 func_00294110(u8 *p) { return *(s32 *)(p + 0x138) > 0; }

extern "C" void func_00294120(u8 *p, s32 v) { *(s32 *)(p + 0x6C) = v; }

extern "C" s32 func_00294128(u8 *p) { return *(s32 *)(p + 0x6C); }

extern "C" void func_00294130(u8 *p, s32 v) { *(s32 *)(p + 0x64) = v; }

extern "C" s32 func_00294138(u8 *p) { return *(s32 *)(p + 0x64); }

extern "C" void func_00294140(u8 *p, f32 v) { *(f32 *)(p + 0x168) = v; }

extern "C" f32 func_00294148(u8 *p) { return *(f32 *)(p + 0x168); }

extern "C" u8 *func_00294150(u8 *p) { return p + 0x1A8; }

extern "C" u8 *func_00294158(u8 *p) { return p + 0x1B8; }

extern "C" void func_00294160(u8 *p, s32 v) { *(s32 *)(p + 0x16C) = v; }

extern "C" s32 func_00294168(u8 *p) { return *(s32 *)(p + 0x16C); }

extern "C" void func_00294170(u8 *p, s32 v) { *(s32 *)(p + 0x178) = v; }

extern "C" s32 func_00294178(u8 *p) { return *(s32 *)(p + 0x178); }

extern "C" s32 func_00294180(u8 *p) { return *(s32 *)(p + 0x188); }

extern "C" void func_00294188(u8 *p, s32 v) { *(s32 *)(p + 0x1C8) = v; }

extern "C" s32 func_00294190(u8 *p) { return *(s32 *)(p + 0x1C8); }

extern "C" s32 func_00294198(u8 *p) { return *(s32 *)(p + 0x3C); }

extern "C" s32 func_002941A0(u8 *p) { return *(s32 *)(p + 0x44); }

extern "C" s32 func_002941A8(u8 *p) { return *(s32 *)(p + 0x40); }

extern "C" void *func_002941B0(void) {
    if (*(s32 *)D_4246B0 == 0) {
        __tf8CListTag();
        func_00286BC0(D_4246B0, D_002D3768, D_2EB708);
    }
    return D_4246B0;
}

extern "C" void *__tf15CModelAccResMgr(void) {
    if (*(s32 *)D_4246D0 == 0) {
        func_002942A0();
        func_00286BC0(D_4246D0, D_002D37F0, D_2EB758);
    }
    return D_4246D0;
}

// CModelAccResMgr slot 0: inline Release() { delete this; }
extern "C" void func_00294250(CRelease7 *p) { delete p; }

// CModelAccResMgr[3]
extern "C" u8 *func_00294288(u8 *p) { return p + 0x4; }

// CModelAccResMgr[4]
extern "C" u8 *func_00294290(u8 *p) { return p + 0x24; }

// CModelAccResMgr[5]
extern "C" u8 *func_00294298(u8 *p) { return p + 0x34; }

extern "C" void *func_002942A0(void) {
    if (*(s32 *)D_2EB758 == 0) {
        func_00286BE0(D_2EB758, D_002D3808);
    }
    return D_2EB758;
}

extern "C" void func_002942E0(TArrB *a) {
    a->m_vptr = TArrB_vt;
    a->m_data = 0;
    a->m_count = 0;
    a->m_cap = 0;
    a->m_grow = 16;
}

extern "C" void func_00294308(TArrA *a) {
    a->m_vptr = TArrA_vt;
    a->m_data = 0;
    a->m_count = 0;
    a->m_cap = 0;
    a->m_grow = 16;
}

extern "C" void func_00294330(TArrA *a, s32 flags) {
    func_00294388(a, 0);
    if (flags & 1) return (void)__builtin_delete(a);
}

extern "C" void func_00294388(TArrA *a, s32 n) {
    func_00294438(a, n, 1);
}

extern "C" s32 func_002943A8(TArrA *a) { return a->m_count; }

extern "C" CMapAttrLight *func_002943B0(TArrA *a, s32 i) {
    return func_002945F8(a, i);
}

extern "C" s32 func_002943C8(TArrB *a) { return a->m_count; }

extern "C" CMapAttrLightPos *func_002943D0(TArrB *a, s32 i) {
    return func_00294610(a, i);
}

extern "C" void func_002943E8(TArrB *a, s32 n) {
    func_00294620(a, n, 1);
}

extern "C" CMapAttrLightPos *func_00294408(TArrB *a, s32 i) {
    return func_002947C0(a, i);
}

extern "C" CMapAttrLight *func_00294420(TArrA *a, s32 i) {
    return func_002947D0(a, i);
}

extern "C" void func_00294438(TArrA *a, s32 n, s32 init) {
    if (a->m_cap < n) {
        CMapAttrLight *p;
        a->m_cap = (n + a->m_grow - 1) / a->m_grow * a->m_grow;
        p = func_002947E8(a, a->m_cap);
        if (p == 0) {
            Func235DE0(D_002D3B28, a->m_cap * sizeof(CMapAttrLight));
            return;
        }
        if (a->m_data) {
            memcpy(p, a->m_data, a->m_count * sizeof(CMapAttrLight));
            func_00294818(a, a->m_data);
        }
        a->m_data = p;
    }
    if (init) {
        if (a->m_count < n) {
            CMapAttrLight tmp;
            func_00294848(a, a->m_data + a->m_count, &tmp, n - a->m_count);
        } else if (n < a->m_count) {
            func_002948B0(a, a->m_data + n, a->m_count - n);
        }
    }
    a->m_count = n;
    if (a->m_data) {
        if (n == 0) {
            func_00294818(a, a->m_data);
            a->m_data = 0;
            a->m_cap = 0;
        } else if (a->m_cap - a->m_grow >= n) {
            a->m_cap = (n + a->m_grow - 1) / a->m_grow * a->m_grow;
            a->m_data = func_00294908(a, a->m_data, a->m_cap);
        }
    }
}

extern "C" CMapAttrLight *func_002945F8(TArrA *a, s32 i) {
    return &a->m_data[i];
}

extern "C" CMapAttrLightPos *func_00294610(TArrB *a, s32 i) {
    return &a->m_data[i];
}

extern "C" void func_00294620(TArrB *a, s32 n, s32 init) {
    if (a->m_cap < n) {
        CMapAttrLightPos *p;
        a->m_cap = (n + a->m_grow - 1) / a->m_grow * a->m_grow;
        p = func_00294948(a, a->m_cap);
        if (p == 0) {
            Func235DE0(D_002D3B28, a->m_cap * sizeof(CMapAttrLightPos));
            return;
        }
        if (a->m_data) {
            memcpy(p, a->m_data, a->m_count * sizeof(CMapAttrLightPos));
            func_00294970(a, a->m_data);
        }
        a->m_data = p;
    }
    if (init) {
        if (a->m_count < n) {
            CMapAttrLightPos *d = a->m_data + a->m_count;
            CMapAttrLightPos tmp;
            memset(&tmp, 0, sizeof(tmp));
            func_002949A0(a, d, &tmp, n - a->m_count);
        } else if (n < a->m_count) {
            func_00294A08(a, a->m_data + n, a->m_count - n);
        }
    }
    a->m_count = n;
    if (a->m_data) {
        if (n == 0) {
            func_00294970(a, a->m_data);
            a->m_data = 0;
            a->m_cap = 0;
        } else if (a->m_cap - a->m_grow >= n) {
            a->m_cap = (n + a->m_grow - 1) / a->m_grow * a->m_grow;
            a->m_data = func_00294A60(a, a->m_data, a->m_cap);
        }
    }
}

extern "C" CMapAttrLightPos *func_002947C0(TArrB *a, s32 i) {
    return &a->m_data[i];
}

extern "C" CMapAttrLight *func_002947D0(TArrA *a, s32 i) {
    return &a->m_data[i];
}

extern "C" CMapAttrLight *func_002947E8(TArrA *a, s32 n) {
    return (CMapAttrLight *)D_002B91A4(n * sizeof(CMapAttrLight));
}

extern "C" void func_00294818(TArrA *a, CMapAttrLight *p) {
    if (p) D_002B91B0(p);
}

extern "C" void func_00294848(TArrA *a, CMapAttrLight *p, CMapAttrLight *src, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) func_00294A98(a, &p[i], src);
}

extern "C" void func_002948B0(TArrA *a, CMapAttrLight *p, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) func_00294C28(a, &p[i]);
}

extern "C" CMapAttrLight *func_00294908(TArrA *a, CMapAttrLight *p, s32 n) {
    D_002B91AC(p, n * sizeof(CMapAttrLight));
    return p;
}

extern "C" CMapAttrLightPos *func_00294948(TArrB *a, s32 n) {
    return (CMapAttrLightPos *)D_002B91A4(n * sizeof(CMapAttrLightPos));
}

extern "C" void func_00294970(TArrB *a, CMapAttrLightPos *p) {
    if (p) D_002B91B0(p);
}

extern "C" void func_002949A0(TArrB *a, CMapAttrLightPos *p, CMapAttrLightPos *src, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) func_00294C48(a, &p[i], src);
}

extern "C" void func_00294A08(TArrB *a, CMapAttrLightPos *p, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) func_00294C78(a, &p[i]);
}
