#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CTask.h"
extern "C" void CTask_dtor(CTask *, s32) asm("_$_5CTask");
extern "C" void func_00286BC0(void *, const char *, void *);
extern "C" void func_00286BE0(void *, const char *);
extern "C" char D_002D4978[];
extern "C" char D_002D4990[];
extern "C" char D_002D49A8[];
extern "C" char D_002D49C0[];
extern "C" char D_002D49D8[];
extern "C" char D_002D49F0[];
extern "C" char D_002D4A38[];
extern "C" char D_002D4A48[];
extern "C" char D_002D4BE0[];
extern "C" char D_002D4C28[];
extern "C" char D_002D4CA8[];
extern "C" char D_002D4DE8[];
extern "C" char D_002D4E00[];
extern "C" u8 D_2EB708[];
extern "C" u8 D_2EB798[];
extern "C" u8 D_2EB7A8[];
extern "C" u8 D_2EB7B0[];
extern "C" u8 D_2EB7B8[];
extern "C" u8 D_2EB7C0[];
extern "C" u8 D_424660[];
extern "C" u8 D_4246E0[];
extern "C" u8 D_4246F0[];
extern "C" u8 D_424700[];
extern "C" u8 D_424710[];
extern "C" u8 D_424720[];
extern "C" u8 D_424730[];
extern "C" u8 D_424770[];
extern "C" u8 D_424780[];
extern "C" u8 D_4247A0[];
extern "C" void *__tf11CMapEffWork(void);
extern "C" void *__tf5CList(void);
extern "C" void *__tf8CListTag(void);
extern "C" void *func_00295D50(void);

struct TArrayBase { s32 m0; u8 *m_data; s32 m_cap; s32 m_count; s32 m_grow; void *m_vptr; };
extern void *(*D_002B91A4)(u32 n);
extern void (*D_002B91B0)(void *p);
extern void *(*D_002B91AC)(void *p, u32 n);
extern "C" void *memcpy(void *, const void *, u32);
extern "C" void *memset(void *, s32, u32);
extern "C" void __builtin_delete(void *);
void Func235DE0(const char *fmt, ...);
struct tagMapSndStepInfo { u64 m[0x150 / 8]; };
class CUnk295E20 { public: void Func295E20(s32 n); };
extern "C" char D_002D4BA8[];
struct TArrD { s32 m0; tagMapSndStepInfo *m_data; s32 m_cap; s32 m_count; s32 m_grow; void *m_vptr; };
extern u8 TArrD_vt[] asm("_vt$t6TArray3Z17tagMapSndStepInfoi_16_Zt10TAllocator1Z17tagMapSndStepInfo");
extern "C" void func_00295DA0(TArrD *a);
extern "C" void func_00295DC8(TArrD *a, s32 flags);
extern "C" tagMapSndStepInfo *func_00295E48(TArrD *a, s32 i);
extern "C" tagMapSndStepInfo *func_00296040(TArrD *a, s32 i);
extern "C" void func_00295E60(TArrD *a, s32 n, s32 init);
extern "C" tagMapSndStepInfo *func_00296060(TArrD *a, s32 n);
extern "C" void func_00296098(TArrD *a, tagMapSndStepInfo *p);
extern "C" void func_002960C8(TArrD *a, tagMapSndStepInfo *p, tagMapSndStepInfo *src, s32 n);
extern "C" void func_00296130(TArrD *a, tagMapSndStepInfo *p, s32 n);
extern "C" tagMapSndStepInfo *func_00296188(TArrD *a, tagMapSndStepInfo *p, s32 n);
extern "C" void func_002961D0(TArrD *a, tagMapSndStepInfo *p, tagMapSndStepInfo *src);
extern "C" void func_00296228(TArrD *a, tagMapSndStepInfo *p);

struct ListTag { s32 isHead; ListTag *prev; ListTag *next; void *vptr;
    ListTag *Next() { return next->isHead ? 0 : next; }
};
extern u8 CMapEffWork_vt[] asm("_vt$11CMapEffWork");
extern u8 CMapEffMirrorWork_vt[] asm("_vt$17CMapEffMirrorWork");
extern void (*D_002B91B0)(void *p);
// @decl-end

// CMapEffFlyWork[1]
extern "C" s32 func_002959A8(u8 *p, s32 id) { return id == -300; }

extern "C" void *__tf15CMapEffRainWork(void) {
    if (*(s32 *)D_4246F0 == 0) {
        __tf11CMapEffWork();
        func_00286BC0(D_4246F0, D_002D4978, D_2EB798);
    }
    return D_4246F0;
}

// CMapEffRainWork[1]
extern "C" s32 func_00295A08(u8 *p, s32 id) { return id == -400; }

extern "C" void *__tf15CMapEffSnowWork(void) {
    if (*(s32 *)D_424720 == 0) {
        __tf11CMapEffWork();
        func_00286BC0(D_424720, D_002D4990, D_2EB798);
    }
    return D_424720;
}

// CMapEffSnowWork[1]
extern "C" s32 func_00295A68(u8 *p, s32 id) { return id == -500; }

// CMapEffAquariumWork's deleting destructor (linkonce): the CMapEffWork base's
extern "C" void func_00295A78(void **p, s32 flags) {
    *p = CMapEffWork_vt;
    if (flags & 1) D_002B91B0(p);
}

extern "C" void *__tf19CMapEffAquariumWork(void) {
    if (*(s32 *)D_4246E0 == 0) {
        __tf11CMapEffWork();
        func_00286BC0(D_4246E0, D_002D49A8, D_2EB798);
    }
    return D_4246E0;
}

// CMapEffAquariumWork[1]
extern "C" s32 func_00295B00(u8 *p, s32 id) { return id == -600; }

// CMapEffMirrorWork's deleting destructor (linkonce)
extern "C" void func_00295B10(void **p, s32 flags) {
    *p = CMapEffWork_vt;
    if (flags & 1) D_002B91B0(p);
}

extern "C" void *__tf17CMapEffMirrorWork(void) {
    if (*(s32 *)D_424730 == 0) {
        __tf11CMapEffWork();
        func_00286BC0(D_424730, D_002D49C0, D_2EB798);
    }
    return D_424730;
}

// CMapEffMirrorWork constructor (linkonce)
extern "C" void **func_00295B98(void **p, void *a) {
    p[1] = a;
    *p = CMapEffMirrorWork_vt;
}

// CMapEffMirrorWork[1]
extern "C" s32 func_00295BB0(u8 *p, s32 id) { return id == -900; }

// CMapEffBreathWork's deleting destructor (linkonce)
extern "C" void func_00295BC0(void **p, s32 flags) {
    *p = CMapEffWork_vt;
    if (flags & 1) D_002B91B0(p);
}

extern "C" void *__tf17CMapEffBreathWork(void) {
    if (*(s32 *)D_424780 == 0) {
        __tf11CMapEffWork();
        func_00286BC0(D_424780, D_002D49D8, D_2EB798);
    }
    return D_424780;
}

// CMapEffBreathWork[1]
extern "C" s32 func_00295C48(u8 *p, s32 id) { return id == -1000; }

// CMapEffSwingWork's deleting destructor (linkonce)
extern "C" void func_00295C58(void **p, s32 flags) {
    *p = CMapEffWork_vt;
    if (flags & 1) D_002B91B0(p);
}

extern "C" void *__tf16CMapEffSwingWork(void) {
    if (*(s32 *)D_424770 == 0) {
        __tf11CMapEffWork();
        func_00286BC0(D_424770, D_002D49F0, D_2EB798);
    }
    return D_424770;
}

// CMapEffSwingWork[1]
extern "C" s32 func_00295CE0(u8 *p, s32 id) { return id == -1100; }

extern "C" void func_00295CF0(u8 *p, s32 v) { *(s32 *)(p + 0x90) = v != 0; }

extern "C" void *func_00295D00(void) {
    if (*(s32 *)D_424700 == 0) {
        func_00295D50();
        func_00286BC0(D_424700, D_002D4A38, D_424710);
    }
    return D_424700;
}

extern "C" void *func_00295D50(void) {
    if (*(s32 *)D_424710 == 0) {
        __tf8CListTag();
        func_00286BC0(D_424710, D_002D4A48, D_2EB708);
    }
    return D_424710;
}

extern "C" void func_00295DA0(TArrD *a) {
    a->m_vptr = TArrD_vt;
    a->m_data = 0;
    a->m_count = 0;
    a->m_cap = 0;
    a->m_grow = 16;
}

extern "C" void func_00295DC8(TArrD *a, s32 flags) {
    ((CUnk295E20 *)a)->Func295E20(0);
    if (flags & 1) return (void)__builtin_delete(a);
}

void CUnk295E20::Func295E20(s32 n) {
    func_00295E60((TArrD *)this, n, 1);
}

extern "C" s32 func_00295E40(u8 *p) { return *(s32 *)(p + 0xC); }

extern "C" tagMapSndStepInfo *func_00295E48(TArrD *a, s32 i) {
    return func_00296040(a, i);
}

extern "C" void func_00295E60(TArrD *a, s32 n, s32 init) {
    if (a->m_cap < n) {
        tagMapSndStepInfo *p;
        a->m_cap = (n + a->m_grow - 1) / a->m_grow * a->m_grow;
        p = func_00296060(a, a->m_cap);
        if (p == 0) {
            Func235DE0(D_002D4BA8, a->m_cap * sizeof(tagMapSndStepInfo));
            return;
        }
        if (a->m_data) {
            memcpy(p, a->m_data, a->m_count * sizeof(tagMapSndStepInfo));
            func_00296098(a, a->m_data);
        }
        a->m_data = p;
    }
    if (init) {
        if (a->m_count < n) {
            tagMapSndStepInfo *d = a->m_data + a->m_count;
            tagMapSndStepInfo tmp;
            memset(&tmp, 0, sizeof(tmp));
            func_002960C8(a, d, &tmp, n - a->m_count);
        } else if (n < a->m_count) {
            func_00296130(a, a->m_data + n, a->m_count - n);
        }
    }
    a->m_count = n;
    if (a->m_data) {
        if (n == 0) {
            func_00296098(a, a->m_data);
            a->m_data = 0;
            a->m_cap = 0;
        } else if (a->m_cap - a->m_grow >= n) {
            a->m_cap = (n + a->m_grow - 1) / a->m_grow * a->m_grow;
            a->m_data = func_00296188(a, a->m_data, a->m_cap);
        }
    }
}

extern "C" tagMapSndStepInfo *func_00296040(TArrD *a, s32 i) {
    return &a->m_data[i];
}

extern "C" tagMapSndStepInfo *func_00296060(TArrD *a, s32 n) {
    return (tagMapSndStepInfo *)D_002B91A4(n * sizeof(tagMapSndStepInfo));
}

extern "C" void func_00296098(TArrD *a, tagMapSndStepInfo *p) {
    if (p) D_002B91B0(p);
}

extern "C" void func_002960C8(TArrD *a, tagMapSndStepInfo *p, tagMapSndStepInfo *src, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) func_002961D0(a, &p[i], src);
}

extern "C" void func_00296130(TArrD *a, tagMapSndStepInfo *p, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) func_00296228(a, &p[i]);
}

extern "C" tagMapSndStepInfo *func_00296188(TArrD *a, tagMapSndStepInfo *p, s32 n) {
    D_002B91AC(p, n * sizeof(tagMapSndStepInfo));
    return p;
}

extern "C" void func_002961D0(TArrD *a, tagMapSndStepInfo *p, tagMapSndStepInfo *src) {
    if (p) *p = *src;
}

extern "C" void func_00296228(TArrD *a, tagMapSndStepInfo *p) {
}

extern "C" void *__tft6TArray3Z17tagMapSndStepInfoi_16_Zt10TAllocator1Z17tagMapSndStepInfo(void) {
    if (*(s32 *)D_2EB7B0 == 0) {
        func_00286BE0(D_2EB7B0, D_002D4BE0);
    }
    return D_2EB7B0;
}

extern "C" void *__tf10CMapSndRes(void) {
    if (*(s32 *)D_2EB7A8 == 0) {
        func_00286BE0(D_2EB7A8, D_002D4C28);
    }
    return D_2EB7A8;
}

extern "C" void *__tf10CMapSndObj(void) {
    if (*(s32 *)D_2EB7B8 == 0) {
        func_00286BE0(D_2EB7B8, D_002D4CA8);
    }
    return D_2EB7B8;
}

extern "C" s32 func_002962F0(u8 *p) { return *(s32 *)(p + 0x4); }

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_002962F8);

extern "C" void *__tft5TList1Z9CCharaObj(void) {
    if (*(s32 *)D_4247A0 == 0) {
        __tf5CList();
        func_00286BC0(D_4247A0, D_002D4DE8, D_424660);
    }
    return D_4247A0;
}

extern "C" void *__tf9CSceneObj(void) {
    if (*(s32 *)D_2EB7C0 == 0) {
        func_00286BE0(D_2EB7C0, D_002D4E00);
    }
    return D_2EB7C0;
}

extern "C" s32 func_00296438(u8 *p) { return *(s32 *)(p + 0x4); }

extern "C" void func_00296440(u8 *p, s32 v) {
    *(s32 *)(p + 0x0) = v;
    *(s32 *)(p + 0xA8) = 0;
}

extern "C" s32 func_00296450(u8 *p) { return *(s32 *)(p + 0x0); }

// index of node X in the list at 8 (CList), -1 if absent
extern "C" s32 func_00296458(u8 *p, ListTag *x) {
    ListTag *t = ((ListTag *)(p + 8))->Next();
    s32 i = 0;
    while (t) {
        if (t == x) return i;
        t = t->Next();
        i++;
    }
    return -1;
}

extern "C" ListTag *func_002964B8(u8 *p) {
    return ((ListTag *)(p + 8))->Next();
}

extern "C" void func_002964C8(u8 *p, s32 v) { *(s32 *)(p + 0x2C) = v; }

extern "C" s32 func_002964D0(u8 *p) { return *(s32 *)(p + 0x2C); }

extern "C" s32 func_002964D8(u8 *p) { return *(s32 *)(p + 0x24); }

extern "C" s32 func_002964E0(u8 *p) { return *(s32 *)(p + 0x28); }

extern "C" s32 func_002964E8(u8 *p) { return *(s32 *)(p + 0x20); }

extern "C" s32 func_002964F0(u8 *p) { return *(s32 *)(p + 0x1C); }

extern "C" void func_002964F8(u8 *p, s32 a, s32 b) {
    *(s32 *)(p + 0x30) = a;
    *(s32 *)(p + 0x34) = b;
}

extern "C" void func_00296508(u8 *p) {
    *(s32 *)(p + 0x30) = -1;
    *(s32 *)(p + 0x34) = 0;
}

extern "C" s32 func_00296518(u8 *p) { return *(s32 *)(p + 0x30); }

extern "C" s32 func_00296520(u8 *p) { return *(s32 *)(p + 0x34); }

extern "C" void func_00296528(u8 *p, s32 v) { *(s32 *)(p + 0x38) = v; }

extern "C" void func_00296530(u8 *p, f32 v) { *(f32 *)(p + 0x50) = v; }

extern "C" f32 func_00296538(u8 *p) { return *(f32 *)(p + 0x50); }
