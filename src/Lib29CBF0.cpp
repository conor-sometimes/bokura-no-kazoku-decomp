#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "linkonce.h"
extern "C" {
extern TypeInfo D_424E10;
TypeInfo *__tf8CProcess();
extern const char D_002E1F48[];
extern TypeInfo D_424E70;
extern TypeInfo D_2EB8A0;
extern const char D_002E5F50[];
extern TypeInfo D_424E20;
TypeInfo *func_0029CD10();
extern const char D_002E5F60[];
extern TypeInfo D_2EB898;
extern const char D_002E5F68[];
extern TypeInfo D_2EB8A8;
extern const char D_002E6478[];
extern TypeInfo D_2EB8B0;
extern const char D_002E6848[];
extern TypeInfo D_2EB8B8;
extern const char D_002E6870[];
extern TypeInfo D_424E30;
TypeInfo *__tf5CList();
extern const char D_002E6878[];
extern TypeInfo D_424660;
extern TypeInfo D_424E60;
TypeInfo *func_0029D0F0();
extern const char D_002E6890[];
extern TypeInfo D_424E40;
extern TypeInfo D_424E50;
TypeInfo *__tf5CTask();
extern const char D_002E68A0[];
TypeInfo *__tf8CListTag();
extern const char D_002E68B0[];
extern TypeInfo D_2EB708;
extern const char D_002E68D8[];
extern TypeInfo D_424E80;
extern const char D_002E69F0[];
extern TypeInfo D_2EB8C0;
extern const char D_002E6A10[];
extern TypeInfo D_424E90;
TypeInfo *func_0029D478();
extern const char D_002E6A20[];
extern TypeInfo D_424EA0;
extern const char D_002E6A30[];
extern TypeInfo D_424EB0;
TypeInfo *func_0029D570();
extern const char D_002E6AF8[];
extern TypeInfo D_2EB8C8;
extern const char D_002E6B08[];
extern TypeInfo D_2EB8D0;
extern const char D_002E6B50[];
extern TypeInfo D_424EC0;
TypeInfo *func_0029D690();
extern const char D_002E6ED8[];
extern TypeInfo D_2EB8D8;
extern const char D_002E6EE8[];
}
struct VDel_29CCD8 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual ~VDel_29CCD8(); };
struct VDel_29D518 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual ~VDel_29D518(); };
struct VDel_29D640 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual ~VDel_29D640(); };

#include "linkonce.h"
extern "C" void *__nw__8CHeapObjUi(u32 n);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2Tbl48 { u8 pad[0x48]; s8 m[4][3]; };
struct W2ListHead { s32 head; W2ListHead *First() { return head ? 0 : this; } };
extern "C" char *strcpy(char *, const char *);
extern "C" int func_00245818(void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2RcB { s32 a, b, c; virtual ~W2RcB(); };
struct W2Rc : W2RcB { s32 m10; s32 m14; };

extern u8 W2s__vt_9CRootTask[] asm("_vt$9CRootTask");
extern "C" void W2s____5CTask(void *, s32) asm("_$_5CTask");
extern "C" void W2s___dl__5CTaskPv(void *) asm("__dl__5CTaskPv");

struct Y1Tag { s32 isHead; Y1Tag *prev; Y1Tag *next; void *vptr; };
extern u8 Y1CList_vt[] asm("_vt$5CList");
extern u8 Y1CListTag_vt[] asm("_vt$8CListTag");
extern "C" void __builtin_delete(void *);
static inline Y1Tag *Y1First(Y1Tag *l) { Y1Tag *n = l->next; return n->isHead ? 0 : n; }
static inline Y1Tag *Y1Remove(Y1Tag *t) { if (t) { t->prev->next = t->next; t->next->prev = t->prev; t->next = t; t->prev = t; } return t; }
// @decl-end

extern "C" TypeInfo *__tf8CAppMain()
{
    if (!D_424E10.vptr) {
        __tf8CProcess();
        func_00286BC0(&D_424E10, D_002E1F48, &D_424E70);
    }
    return &D_424E10;
}

extern "C" TypeInfo *__tf7CBgWork()
{
    if (!D_2EB8A0.vptr) func_00286BE0(&D_2EB8A0, D_002E5F50);
    return &D_2EB8A0;
}

extern "C" s32 func_0029CC80(void *p) { return FLD(s32, p, 0x4); }

extern "C" TypeInfo *__tf6CBgMgr()
{
    if (!D_424E20.vptr) {
        func_0029CD10();
        func_00286BC0(&D_424E20, D_002E5F60, &D_2EB898);
    }
    return &D_424E20;
}

extern "C" void func_0029CCD8(VDel_29CCD8 *p) { delete p; }

extern "C" TypeInfo *func_0029CD10()
{
    if (!D_2EB898.vptr) func_00286BE0(&D_2EB898, D_002E5F68);
    return &D_2EB898;
}

extern "C" TypeInfo *__tf8CPushBuf()
{
    if (!D_2EB8A8.vptr) func_00286BE0(&D_2EB8A8, D_002E6478);
    return &D_2EB8A8;
}

extern "C" s32 func_0029CD90(void *p) { return FLD(s32, p, 0x4); }

extern "C" TypeInfo *__tf5CExpr()
{
    if (!D_2EB8B0.vptr) func_00286BE0(&D_2EB8B0, D_002E6848);
    return &D_2EB8B0;
}

extern "C" TypeInfo *__tf5CTask()
{
    if (!D_2EB8B8.vptr) func_00286BE0(&D_2EB8B8, D_002E6870);
    return &D_2EB8B8;
}

// CList::~CList() (linkonce, deleting): drain the list, then the CListTag base's unlink
extern "C" void func_0029CE18(Y1Tag *l, s32 flags)
{
    l->vptr = Y1CList_vt;
    while (Y1Remove(Y1First(l)));
    l->vptr = Y1CListTag_vt;
    l->prev->next = l->next;
    l->next->prev = l->prev;
    l->next = l;
    l->prev = l;
    if (flags & 1) return (void)__builtin_delete(l);
}

extern "C" TypeInfo *__tft5TList1Z8CTaskTag()
{
    if (!D_424E30.vptr) {
        __tf5CList();
        func_00286BC0(&D_424E30, D_002E6878, &D_424660);
    }
    return &D_424E30;
}

extern "C" TypeInfo *__tf8CTaskTag()
{
    if (!D_424E60.vptr) {
        func_0029D0F0();
        func_00286BC0(&D_424E60, D_002E6890, &D_424E40);
    }
    return &D_424E60;
}

extern "C" s32 func_0029CF68(void *p) { return FLD(s32, p, 0x10); }

extern "C" s32 func_0029CF70(void *p) { return FLD(s32, p, 0x14); }

extern "C" void *func_0029CF78(void *p) { void *n = FLD(void *, p, 0x5C); return FLD(s32, n, 0) ? 0 : n; }

extern "C" void *func_0029CF88(void *p) { void *n = FLD(void *, p, 0x58); return FLD(s32, n, 0) ? 0 : n; }

extern "C" void func_0029CF98(void *p, s32 v) { FLD(s32, p, 0x14) = v; }

extern "C" void func_0029CFA0(W2Rc *p) { p->m14 = 0; if (!p->m10) delete p; }

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029CFE8);

extern "C" s32 func_0029D018(W2Tbl48 *p, s32 a, s32 b) { return p->m[a][b] > 0; }

extern "C" void func_0029D038(void *p, s32 c) { *(void **)((u8 *)p + 0x4) = W2s__vt_9CRootTask; W2s____5CTask(p, 0); if (c & 1) { W2s___dl__5CTaskPv(p); return; } }

extern "C" TypeInfo *__tf9CRootTask()
{
    if (!D_424E50.vptr) {
        __tf5CTask();
        func_00286BC0(&D_424E50, D_002E68A0, &D_2EB8B8);
    }
    return &D_424E50;
}

extern "C" TypeInfo *func_0029D0F0()
{
    if (!D_424E40.vptr) {
        __tf8CListTag();
        func_00286BC0(&D_424E40, D_002E68B0, &D_2EB708);
    }
    return &D_424E40;
}

extern "C" TypeInfo *__tf8CProcess()
{
    if (!D_424E70.vptr) {
        __tf5CTask();
        func_00286BC0(&D_424E70, D_002E68D8, &D_2EB8B8);
    }
    return &D_424E70;
}

extern "C" s32 func_0029D190(void *p) { return FLD(s32, p, 0xC); }

// CList::~CList() (linkonce, deleting): drain the list, then the CListTag base's unlink
extern "C" void func_0029D198(Y1Tag *l, s32 flags)
{
    l->vptr = Y1CList_vt;
    while (Y1Remove(Y1First(l)));
    l->vptr = Y1CListTag_vt;
    l->prev->next = l->next;
    l->next->prev = l->prev;
    l->next = l;
    l->prev = l;
    if (flags & 1) return (void)__builtin_delete(l);
}

extern "C" TypeInfo *__tft5TList1Z13CResCacheUnit()
{
    if (!D_424E80.vptr) {
        __tf5CList();
        func_00286BC0(&D_424E80, D_002E69F0, &D_424660);
    }
    return &D_424E80;
}

extern "C" TypeInfo *__tf9CResCache()
{
    if (!D_2EB8C0.vptr) func_00286BE0(&D_2EB8C0, D_002E6A10);
    return &D_2EB8C0;
}

extern "C" s32 func_0029D2D8(void *p) { return FLD(s32, p, 0) != 0; }

extern "C" s32 func_0029D2E8(void *p) { return FLD(W2ListHead *, p, 0x24)->First() == 0; }

extern "C" s32 func_0029D300(void *p) { return FLD(s32, p, 0x4); }

extern "C" s32 func_0029D308(void *p) { s32 n = 0; for (W2ListHead *q = FLD(W2ListHead *, p, 0x14); (q = q->First()) != 0; q = FLD(W2ListHead *, q, 8)) n++; return n; }

extern "C" s32 func_0029D340(void *p) { s32 n = 0; for (W2ListHead *q = FLD(W2ListHead *, p, 0x24); (q = q->First()) != 0; q = FLD(W2ListHead *, q, 8)) n++; return n; }

extern "C" s32 func_0029D378(void *p) { return FLD(s32, p, 0x8); }

extern "C" void func_0029D380(void *p, const char *s) { strcpy((char *)p + 0x3C, s); }

extern "C" void *func_0029D3A0(void *p) { return (u8 *)p + 0x3C; }

extern "C" TypeInfo *__tf13CResCacheUnit()
{
    if (!D_424E90.vptr) {
        func_0029D478();
        func_00286BC0(&D_424E90, D_002E6A20, &D_424EA0);
    }
    return &D_424E90;
}

extern "C" void *func_0029D3F8(u32 n) { return __nw__8CHeapObjUi(n); }

extern "C" void *func_0029D410(void *p) { return (u8 *)p + 0x30; }

extern "C" s32 func_0029D418(void *p) { return FLD(s32, p, 0x50); }

extern "C" s32 func_0029D420(void *p) { return FLD(s32, p, 0x1C); }

extern "C" void func_0029D428(void *p) { FLD(s32, p, 0x58) = FLD(s32, p, 0x58) + 1; }

extern "C" void func_0029D438(void *p) { s32 v = FLD(s32, p, 0x58) - 1; if (v < 0) v = 0; FLD(s32, p, 0x58) = v; }

extern "C" void func_0029D450(void *p, s32 v) { FLD(s32, p, 0x58) = v; }

extern "C" s32 func_0029D458(void *p) { return FLD(s32, p, 0x58); }

extern "C" int func_0029D460(void *p) { return func_00245818((u8 *)p + 0x10); }

extern "C" TypeInfo *func_0029D478()
{
    if (!D_424EA0.vptr) {
        __tf8CListTag();
        func_00286BC0(&D_424EA0, D_002E6A30, &D_2EB708);
    }
    return &D_424EA0;
}

extern "C" TypeInfo *__tf7CDebOut()
{
    if (!D_424EB0.vptr) {
        func_0029D570();
        func_00286BC0(&D_424EB0, D_002E6AF8, &D_2EB8C8);
    }
    return &D_424EB0;
}

extern "C" void func_0029D518(VDel_29D518 *p) { delete p; }

extern "C" void func_0029D550(void *p, s32 a, s32 b) { FLD(s32, p, 0x10) = a; FLD(s32, p, 0x14) = b; }

extern "C" void func_0029D560(void *p, s32 a, s32 b) { FLD(s32, p, 0x18) = a; FLD(s32, p, 0x1C) = b; }

extern "C" TypeInfo *func_0029D570()
{
    if (!D_2EB8C8.vptr) func_00286BE0(&D_2EB8C8, D_002E6B08);
    return &D_2EB8C8;
}

extern "C" TypeInfo *__tf11CBoneDupMap()
{
    if (!D_2EB8D0.vptr) func_00286BE0(&D_2EB8D0, D_002E6B50);
    return &D_2EB8D0;
}

extern "C" TypeInfo *__tf9CShareTex()
{
    if (!D_424EC0.vptr) {
        func_0029D690();
        func_00286BC0(&D_424EC0, D_002E6ED8, &D_2EB8D8);
    }
    return &D_424EC0;
}

extern "C" void func_0029D640(VDel_29D640 *p) { delete p; }

extern "C" s32 func_0029D678(void *p) { return FLD(s32, p, 0x4); }

extern "C" u64 func_0029D680(void *p) { return FLD(u64, p, 0x8); }

extern "C" u64 func_0029D688(void *p) { return FLD(u64, p, 0x10); }

extern "C" TypeInfo *func_0029D690()
{
    if (!D_2EB8D8.vptr) func_00286BE0(&D_2EB8D8, D_002E6EE8);
    return &D_2EB8D8;
}
