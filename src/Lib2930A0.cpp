#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CTask.h"
extern "C" void CTask_dtor(CTask *, s32) asm("_$_5CTask");
extern "C" void func_00286BC0(void *, const char *, void *);
extern "C" void func_00286BE0(void *, const char *);
extern "C" char D_002D1860[];
extern "C" char D_002D1900[];
extern "C" char D_002D1A38[];
extern "C" char D_002D1B28[];
extern "C" char D_002D1BB8[];
extern "C" char D_002D1CA0[];
extern "C" char D_002D1EE8[];
extern "C" char D_002D1EF8[];
extern "C" char D_002D1F08[];
extern "C" char D_002D1F18[];
extern "C" char D_002D1FE8[];
extern "C" char D_002D1FF8[];
extern "C" char D_002D2028[];
extern "C" char D_002D2D28[];
extern "C" char D_002D2D48[];
extern "C" char D_002D2D58[];
extern "C" char D_002D2D70[];
extern "C" char D_002D2D80[];
extern "C" char D_002D2D90[];
extern "C" char D_002D2DB0[];
extern "C" char D_002D3020[];
extern "C" u8 D_2EB700[];
extern "C" u8 D_2EB708[];
extern "C" u8 D_2EB710[];
extern "C" u8 D_2EB718[];
extern "C" u8 D_2EB720[];
extern "C" u8 D_2EB8B8[];
extern "C" u8 D_2EB900[];
extern "C" u8 D_4245A0[];
extern "C" u8 D_4245B0[];
extern "C" u8 D_4245C0[];
extern "C" u8 D_4245D0[];
extern "C" u8 D_4245E0[];
extern "C" u8 D_4245F0[];
extern "C" u8 D_424600[];
extern "C" u8 D_424610[];
extern "C" u8 D_424620[];
extern "C" u8 D_424630[];
extern "C" u8 D_424640[];
extern "C" u8 D_424650[];
extern "C" u8 D_424660[];
extern "C" u8 D_424670[];
extern "C" u8 D_424680[];
extern "C" u8 D_424690[];
extern "C" u8 D_4246A0[];
extern "C" u8 D_424E70[];
extern "C" void *__tf5CList(void);
extern "C" void *__tf5CTask(void);
extern "C" void *__tf7IPadMgr(void);
extern "C" void *__tf8CListTag(void);
extern "C" void *__tf8CProcess(void);
extern "C" void *__tf8IFadeMgr(void);
extern "C" void *__tf8ISnapMgr(void);
extern "C" void *__tf9CFontWork(void);
extern "C" void *func_00293B28(void);
extern "C" void *func_00293B68(void);
extern u8 IFadeMgr_vt[] asm("_vt$8IFadeMgr");
extern u8 IPadMgr_vt[] asm("_vt$7IPadMgr");
extern u8 ISnapMgr_vt[] asm("_vt$8ISnapMgr");

extern "C" s64 func_00283490(double);
// List node as laid out by CListTag (include/CList.h); the linkonce destructors below unlink it.
struct ListTag { s32 isHead; ListTag *prev; ListTag *next; void *vptr; };
extern u8 CListTag_vt[] asm("_vt$8CListTag");
extern u8 CCacheInfo_vt[] asm("_vt$10CCacheInfo");
extern "C" void __builtin_delete(void *);
extern "C" void func_00286B98(void *, const char *, void *, s32);
extern "C" void *__tf8CListTag(void);
extern "C" u8 D_424660[];
extern "C" char D_002D2D38[];
extern "C" u8 D_002D2D40[];
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

// libgcc __fixdfdi (soft-float double to 64-bit int)
extern "C" s64 func_002930A0(double a) {
    if (a < 0) return -func_00283490(-a);
    return func_00283490(a);
}

extern "C" void *__tf9CBootMain(void) {
    if (*(s32 *)D_4245A0 == 0) {
        __tf8CProcess();
        func_00286BC0(D_4245A0, D_002D1860, D_424E70);
    }
    return D_4245A0;
}

extern "C" void *__tf9CLogoMain(void) {
    if (*(s32 *)D_4245B0 == 0) {
        __tf8CProcess();
        func_00286BC0(D_4245B0, D_002D1900, D_424E70);
    }
    return D_4245B0;
}

extern "C" void *__tf10CTitleMain(void) {
    if (*(s32 *)D_4245C0 == 0) {
        __tf8CProcess();
        func_00286BC0(D_4245C0, D_002D1A38, D_424E70);
    }
    return D_4245C0;
}

extern "C" s32 func_00293208(u8 *p) { return *(s32 *)(p + 0x7C8); }

extern "C" void *__tf9CDemoMain(void) {
    if (*(s32 *)D_4245D0 == 0) {
        __tf8CProcess();
        func_00286BC0(D_4245D0, D_002D1B28, D_424E70);
    }
    return D_4245D0;
}

extern "C" void *__tf11CEndingMain(void) {
    if (*(s32 *)D_4245E0 == 0) {
        __tf8CProcess();
        func_00286BC0(D_4245E0, D_002D1BB8, D_424E70);
    }
    return D_4245E0;
}

extern "C" void *__tf9CFlagWork(void) {
    if (*(s32 *)D_2EB700 == 0) {
        func_00286BE0(D_2EB700, D_002D1CA0);
    }
    return D_2EB700;
}

extern "C" void func_002932F0(void) {
}

extern "C" void func_002932F8(void) {
}

// IPadMgr[0]
// IPadMgr::~IPadMgr() (linkonce, deleting): the interface's implicit destructor
extern "C" void IPadMgr_dtor(CTask *p, s32 flags) asm("_$_7IPadMgr");
extern "C" void IPadMgr_dtor(CTask *p, s32 flags) {
    *(void **)((u8 *)p + 4) = IPadMgr_vt;
    CTask_dtor(p, 0);
    if (flags & 1) return (void)CTask::operator delete(p);
}

extern "C" void *__tf7IPadMgr(void) {
    if (*(s32 *)D_424600 == 0) {
        __tf5CTask();
        func_00286BC0(D_424600, D_002D1EE8, D_2EB8B8);
    }
    return D_424600;
}

extern "C" void *__tf7CPadMgr(void) {
    if (*(s32 *)D_4245F0 == 0) {
        __tf7IPadMgr();
        func_00286BC0(D_4245F0, D_002D1EF8, D_424600);
    }
    return D_4245F0;
}

// CPadMgr[7]
extern "C" s32 func_00293408(u8 *p) { return *(s32 *)(p + 0x8); }

// CPadMgr[8]
extern "C" s32 func_00293410(u8 *p) { return *(s32 *)(p + 0xC); }

// CPadMgr[10]
extern "C" s32 func_00293418(u8 *p) { return *(s32 *)(p + 0x10); }

// CPadMgr[9]
extern "C" s32 func_00293420(u8 *p) { return *(s32 *)(p + 0x14); }

// CPadMgr[12]
extern "C" s32 func_00293428(u8 *p) { return *(s32 *)(p + 0x18); }

// IFadeMgr[0]
// IFadeMgr::~IFadeMgr() (linkonce, deleting): the interface's implicit destructor
extern "C" void IFadeMgr_dtor(CTask *p, s32 flags) asm("_$_8IFadeMgr");
extern "C" void IFadeMgr_dtor(CTask *p, s32 flags) {
    *(void **)((u8 *)p + 4) = IFadeMgr_vt;
    CTask_dtor(p, 0);
    if (flags & 1) return (void)CTask::operator delete(p);
}

extern "C" void *__tf8IFadeMgr(void) {
    if (*(s32 *)D_424610 == 0) {
        __tf5CTask();
        func_00286BC0(D_424610, D_002D1F08, D_2EB8B8);
    }
    return D_424610;
}

extern "C" void *__tf8CFadeMgr(void) {
    if (*(s32 *)D_424620 == 0) {
        __tf8IFadeMgr();
        func_00286BC0(D_424620, D_002D1F18, D_424610);
    }
    return D_424620;
}

// CFadeMgr[8]
extern "C" s32 func_00293538(u8 *p) { return *(s32 *)(p + 0x4C); }

// CFadeMgr[9]
extern "C" s32 func_00293540(u8 *p) { return *(s32 *)(p + 0x48) != 0; }

extern "C" f32 func_00293550(u8 *p) {
    s32 d = *(s32 *)(p + 0x44);
    if (d != 0) return (f32)*(s32 *)(p + 0x40) / (f32)d;
    return 0.0f;
}

// CFadeMgr[11]
extern "C" s32 func_00293590(u8 *p) { return *(s32 *)(p + 0x48); }

// CFadeMgr[12]
extern "C" void func_00293598(u8 *p, s32 v) { *(s32 *)(p + 0x50) = v; }

extern "C" void func_002935A0(u8 *p, s32 v) {
    *(s32 *)(p + 0xC) = v < 0 ? 8 : v;
}

// ISnapMgr[0]
// ISnapMgr::~ISnapMgr() (linkonce, deleting): the interface's implicit destructor
extern "C" void ISnapMgr_dtor(CTask *p, s32 flags) asm("_$_8ISnapMgr");
extern "C" void ISnapMgr_dtor(CTask *p, s32 flags) {
    *(void **)((u8 *)p + 4) = ISnapMgr_vt;
    CTask_dtor(p, 0);
    if (flags & 1) return (void)CTask::operator delete(p);
}

extern "C" void *__tf8ISnapMgr(void) {
    if (*(s32 *)D_424630 == 0) {
        __tf5CTask();
        func_00286BC0(D_424630, D_002D1FE8, D_2EB8B8);
    }
    return D_424630;
}

extern "C" void *__tf8CSnapMgr(void) {
    if (*(s32 *)D_424640 == 0) {
        __tf8ISnapMgr();
        func_00286BC0(D_424640, D_002D1FF8, D_424630);
    }
    return D_424640;
}

// CSnapMgr[8]
extern "C" s32 func_002936C0(u8 *p) { return *(s32 *)(p + 0x24); }

// CSnapMgr[9]
extern "C" s32 func_002936C8(u8 *p) { return *(s32 *)(p + 0x20); }

// CSnapMgr[10]
extern "C" s32 func_002936D0(u8 *p) { return *(s32 *)(p + 0x8); }

extern "C" void func_002936D8(u8 *p, s32 v) {
    *(s32 *)(p + 0x30) = v;
    *(s32 *)(p + 0x28) = 1;
}

// CSnapMgr[12]
extern "C" void func_002936E8(u8 *p) { *(s32 *)(p + 0x2C) = 0; }

// CSnapMgr[13]
extern "C" void func_002936F0(u8 *p, s32 v) { *(s32 *)(p + 0x34) = v; }

extern "C" void *__tf10CEFontWork(void) {
    if (*(s32 *)D_424650 == 0) {
        __tf9CFontWork();
        func_00286BC0(D_424650, D_002D2028, D_2EB900);
    }
    return D_424650;
}

extern "C" void *__tf8CListTag(void) {
    if (*(s32 *)D_2EB708 == 0) {
        func_00286BE0(D_2EB708, D_002D2D28);
    }
    return D_2EB708;
}

// CListTag::~CListTag() (linkonce, deleting)
extern "C" void CListTag_dtor(ListTag *p, s32 flags) asm("_$_8CListTag");
extern "C" void CListTag_dtor(ListTag *p, s32 flags) {
    p->vptr = CListTag_vt;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    p->next = p;
    p->prev = p;
    if (flags & 1) return (void)__builtin_delete(p);
}

extern "C" void *__tf5CList(void) {
    if (*(s32 *)D_424660 == 0) {
        __tf8CListTag();
        func_00286B98(D_424660, D_002D2D38, D_002D2D40, 1);
    }
    return D_424660;
}

INCLUDE_ASM("asm/nonmatchings/Lib2930A0", func_00293840);

// CCacheInfo::~CCacheInfo() (linkonce, deleting): only the CListTag base's unlink
extern "C" void CCacheInfo_dtor(ListTag *p, s32 flags) asm("_$_10CCacheInfo");
extern "C" void CCacheInfo_dtor(ListTag *p, s32 flags) {
    p->vptr = CListTag_vt;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    p->next = p;
    p->prev = p;
    if (flags & 1) return (void)__builtin_delete(p);
}

extern "C" void *__tf10CCacheInfo(void) {
    if (*(s32 *)D_424670 == 0) {
        func_00293B68();
        func_00286BC0(D_424670, D_002D2D48, D_424690);
    }
    return D_424670;
}

INCLUDE_ASM("asm/nonmatchings/Lib2930A0", func_002939A0);

extern "C" void *__tft5TList1Z10CCacheInfo(void) {
    if (*(s32 *)D_4246A0 == 0) {
        __tf5CList();
        func_00286BC0(D_4246A0, D_002D2D58, D_424660);
    }
    return D_4246A0;
}

extern "C" void *__tf12CTexCacheMgr(void) {
    if (*(s32 *)D_424680 == 0) {
        func_00293B28();
        func_00286BC0(D_424680, D_002D2D70, D_2EB710);
    }
    return D_424680;
}

// CTexCacheMgr slot 0: inline Release() { delete this; }
extern "C" void func_00293AF0(CRelease7 *p) { delete p; }

extern "C" void *func_00293B28(void) {
    if (*(s32 *)D_2EB710 == 0) {
        func_00286BE0(D_2EB710, D_002D2D80);
    }
    return D_2EB710;
}

extern "C" void *func_00293B68(void) {
    if (*(s32 *)D_424690 == 0) {
        __tf8CListTag();
        func_00286BC0(D_424690, D_002D2D90, D_2EB708);
    }
    return D_424690;
}

extern "C" void *__tf8CFaceObj(void) {
    if (*(s32 *)D_2EB718 == 0) {
        func_00286BE0(D_2EB718, D_002D2DB0);
    }
    return D_2EB718;
}

extern "C" s32 func_00293BF8(u8 *p) { return *(s32 *)(p + 0x8); }

extern "C" s32 func_00293C00(u8 *p) { return *(s32 *)(p + 0xC); }

extern "C" s32 func_00293C08(u8 *p) { return *(s32 *)(p + 0x10); }

extern "C" void func_00293C10(u8 *p, s32 v) { *(s32 *)(p + 0x14) = v; }

extern "C" s32 func_00293C18(u8 *p) { return *(s32 *)(p + 0x14); }

extern "C" void func_00293C20(u8 *p, s32 v) { *(s32 *)(p + 0x18) = v; }

extern "C" s32 func_00293C28(u8 *p) { return *(s32 *)(p + 0x18); }

extern "C" void *__tf8CFaceRes(void) {
    if (*(s32 *)D_2EB720 == 0) {
        func_00286BE0(D_2EB720, D_002D3020);
    }
    return D_2EB720;
}

extern "C" void func_00293C70(u8 *p, s32 a, s32 b, s32 c, s32 d) {
    *(s32 *)(p + 0x34) = a;
    *(s32 *)(p + 0x38) = b;
    *(s32 *)(p + 0x3C) = c;
    *(s32 *)(p + 0x40) = d;
}

extern "C" void func_00293C88(u8 *p, s32 *v) {
    *(s32 *)(p + 0x44) = v[0];
    *(s32 *)(p + 0x48) = v[1];
    *(s32 *)(p + 0x4C) = v[2];
    *(s32 *)(p + 0x50) = v[3];
}
