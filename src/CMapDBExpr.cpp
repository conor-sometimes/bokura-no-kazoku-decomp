#pragma interface
#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CPushBuf.h"
//@sym strcmp 0x28B190
#include "libc.h"
extern const char D_002DA210[];

// CMapDBExpr derives from CExpr (0x24D168, library side): vtable ~CExpr only, vptr at 0x1C
// after its fields.
class CExpr;
typedef int (CExpr::*CExprAccessFn)(const char *name, void *p);
class CExpr {
public:
    CExpr();
    virtual ~CExpr();
    int Func24DB98(s32 a, const char *s, s32 b);
    void Func24D9C8(CExpr *obj, CExprAccessFn set, CExprAccessFn get);

    u8 pad0[0x1C];
};
// Pointers to Set172D00 / Lookup172DD0 (vtable index 3 / 4, vptr at 0x1C), still in the asm
// .rodata piece of this unit.
extern const CExprAccessFn D_002DA200, D_002DA208;
class CUnk29A558 {
public:
    CUnk29A558();
    void Func29A558(s32 v);
};
// Vtable 0x2C1650: ~CMapDBExpr (key method), Set172D00, Lookup172DD0. m_unk20 is a
// TArray<CMapDBExprReg, 16, TAllocator<CMapDBExprReg> > (inline template, vptr of its own).
class CMapDBExpr : public CExpr {
public:
    CMapDBExpr();
    virtual ~CMapDBExpr();
    virtual int Set172D00(const char *name, void *src);
    virtual int Lookup172DD0(const char *name, void *out);
    void CallFunc172E98();
    void Func172E98();
    int CallFunc24DB98(s32 a);

    CUnk29A558 m_unk20;          // 0x20
    u8 pad21[0x38 - 0x21];
};

extern "C" void func_00173A68(void *p);
class CMenuNews {
public:
    static CMenuNews *Create();
};

extern "C" void *bsearch(const void *key, const void *base, unsigned int n, unsigned int size, int (*cmp)(const void *, const void *));
//@sym bsearch 0x289160
int CompareMapDBNames2(const char **a, const char **b);
struct MapDBKey {
    const char *name;
    s32 val;
};
struct CMapDBNameRec {
    const char *m_name;
    const char *m_strs[4];    // 0x4
    s32 m_vals[4];            // 0x14
};
// Interface without fields (its RTTI name only): the vptr is at 0.
class IMapDBMgr {
public:
    virtual void Release() = 0;
    virtual int Func173050(const char *path) = 0;
    virtual void Init() = 0;
    virtual int Func29AC20() = 0;
    virtual int Func29AC28() = 0;
    virtual CMapDBNameRec *FindByName(const char *name) = 0;
    virtual int Func173828(const char *name, s32 idx, char *outName, s32 *outAbs, s32 *outSign) = 0;
    virtual MapDBKey *Find173940(const char *name) = 0;
    virtual int Func173980(const char *a, const char *b) = 0;
};
// Vtable 0x2C15F0: slot 0 is an inline `delete this` (emitted elsewhere), so the key method is
// Func173050, not the destructor (slot 9). Slots 3 and 4 are inline too.
struct CMapDBPair {
    s32 m0;
    s32 m4;
};
class CMapDBMgr : public IMapDBMgr {
public:
    CMapDBMgr();
    virtual void Release() { delete this; }
    virtual int Func173050(const char *path);
    virtual void Init();
    virtual int Func29AC20();
    virtual int Func29AC28();
    virtual CMapDBNameRec *FindByName(const char *name);
    virtual int Func173828(const char *name, s32 idx, char *outName, s32 *outAbs, s32 *outSign);
    virtual MapDBKey *Find173940(const char *name);
    virtual int Func173980(const char *a, const char *b);
    virtual ~CMapDBMgr();
    void Clear();
    static CMapDBMgr *Create();
    s32 Parse173648(const char *p, CMapDBPair *out);

    CPushBuf m_buf;           // 0x4
    CMapDBExpr m_expr;        // 0x10
    CMapDBNameRec *m_recs;    // 0x48
    s32 m_num;                // 0x4C
    void *m_table;            // 0x50
    s32 m_count;              // 0x54
};
extern CMapDBMgr *D_002A3AC0;

struct CExprEntry {
    char m_name[0x20];
    s32 m_unk20;              // 0x20
};
extern "C" s32 func_0029A4F8(void *arr);
extern "C" CExprEntry *func_0029A500(void *arr, s32 i);
extern "C" void func_0024BAF0(void *out, s32 v);

void Func24B600(char *dst, const char *src, s32 n);
extern "C" void func_0029A518(void *arr, CExprEntry *e);
extern "C" s32 func_0024BC88(void *src);
#include "CFlagWork.h"
extern "C" char *func_00248DA8(CPushBuf *b);
extern "C" s32 func_00248DC0(CPushBuf *b);
extern "C" const char *func_0024AD10(const char *p, char *buf, s32 k, s32 n);
const char *Func24A570(const char *s, char *out, const char *sep, const char *ws);
extern char D_002DA280[];
// @decl-end

CMapDBExpr::CMapDBExpr() {
    Func24D9C8(this, D_002DA200, D_002DA208);
}

extern "C" void func_0029A4A0(void *arr, s32 flags);   // TArray<CMapDBExprReg> destructor (linkonce)
// Key method: #pragma interface (top) keeps this unit from emitting the vtables (asm data).
CMapDBExpr::~CMapDBExpr() {
    Func172E98();
    func_0029A4A0(&m_unk20, 2);
}

int CMapDBExpr::Set172D00(const char *name, void *src) {
    s32 i;
    for (i = 0; i < func_0029A4F8(&m_unk20); i++) {
        if (strcmp(func_0029A500(&m_unk20, i)->m_name, name) == 0) goto found;
    }
    {
        CExprEntry e;
        Func24B600(e.m_name, name, 0x20);
        func_0029A518(&m_unk20, &e);
        i = func_0029A4F8(&m_unk20) - 1;
    }
found:
    func_0029A500(&m_unk20, i)->m_unk20 = func_0024BC88(src);
    return 1;
}

int CMapDBExpr::Lookup172DD0(const char *name, void *out) {
    for (s32 i = 0; i < func_0029A4F8(&m_unk20); i++) {
        if (strcmp(func_0029A500(&m_unk20, i)->m_name, name) == 0) {
            func_0024BAF0(out, func_0029A500(&m_unk20, i)->m_unk20);
            return 1;
        }
    }
    return 0;
}

void CMapDBExpr::CallFunc172E98() {
    Func172E98();
}

void CMapDBExpr::Func172E98() {
    m_unk20.Func29A558(0);
}

int CMapDBExpr::CallFunc24DB98(s32 a) {
    return Func24DB98(a, D_002DA210, 1);
}

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00172ED8);

CMapDBMgr *CMapDBMgr::Create() {
    return new CMapDBMgr;
}

CMapDBMgr::CMapDBMgr() {
    D_002A3AC0 = this;
    Clear();
}

CMapDBMgr::~CMapDBMgr() {
    Init();
    D_002A3AC0 = 0;
}

void CMapDBMgr::Clear() {
    m_recs = 0;
    m_num = 0;
    m_table = 0;
    m_count = 0;
}

INCLUDE_RODATA("asm/nonmatchings/CMapDBExpr", D_002DA200);
INCLUDE_RODATA("asm/nonmatchings/CMapDBExpr", D_002DA208);
INCLUDE_RODATA("asm/nonmatchings/CMapDBExpr", D_002DA210);
void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
int Func249248(void *buf);
void Func249348();
int Func235DE0(const char *fmt, ...);
extern "C" void func_00248C30(CPushBuf *b);
extern "C" void func_00248C70(CPushBuf *b);
extern "C" s32 func_00173160(CMapDBMgr *m);
extern "C" void func_00173578(CMapDBMgr *m);

// Key method: #pragma interface (top) keeps this unit from emitting the vtables (asm data).
int CMapDBMgr::Func173050(const char *path) {
    u8 buf[0x100];
    CPushBuf *b = &m_buf;
    CMapDBExpr *e = &m_expr;
    Init();
    Func2491A8(buf, path, (s32)"FILE", (s32)"mapdb", (s32)"data/mapdb.xap");
    if (!Func249248(buf)) return 0;
    Func235DE0("map database ...\n");
    func_00248C30(b);
    e->CallFunc172E98();
    if (func_00173160(this)) func_00173578(this);
    e->Func172E98();
    func_00248C70(b);
    Func249348();
    Func235DE0("size=%d\n", b->m_unk4);
    return 1;
}

int CompareMapDBNames(const char **a, const char **b) {
    return strcmp(*a, *b);
}

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00173160);
INCLUDE_RODATA("asm/nonmatchings/CMapDBExpr", D_002DA280);
INCLUDE_RODATA("asm/nonmatchings/CMapDBExpr", D_002DA288);

int CompareMapDBNames2(const char **a, const char **b) {
    return strcmp(*a, *b);
}

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00173578);
INCLUDE_RODATA("asm/nonmatchings/CMapDBExpr", D_002DA2B8);
INCLUDE_RODATA("asm/nonmatchings/CMapDBExpr", D_002DA2F0);

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00173648);

void CMapDBMgr::Init() {
    m_buf.Func248E00();
    Clear();
}

CMapDBNameRec *CMapDBMgr::FindByName(const char *name) {
    for (s32 i = 0; i < m_num; i++) {
        if (strcmp(m_recs[i].m_name, name) == 0) return &m_recs[i];
    }
    return 0;
}

int CMapDBMgr::Func173828(const char *name, s32 idx, char *outName, s32 *outAbs, s32 *outSign) {
    if (idx < 0) idx = D_002A26E4->Vf2991B0();
    CMapDBNameRec *r = FindByName(name);
    if (!r) return 0;
    const char *s = r->m_strs[idx];
    if (!s || !*s) return 0;
    if (outName) strcpy(outName, s);
    if (outAbs) {
        s32 v = r->m_vals[idx];
        *outAbs = v < 0 ? -v : v;
    }
    if (outSign) *outSign = r->m_vals[idx] < 0 ? -1 : 1;
    return 1;
}

MapDBKey *CMapDBMgr::Find173940(const char *name) {
    MapDBKey key;
    key.name = name;
    key.val = 0;
    return (MapDBKey *)bsearch(&key, m_table, m_count, 8, (int (*)(const void *, const void *))CompareMapDBNames2);
}

int CMapDBMgr::Func173980(const char *a, const char *b) {
    MapDBKey *ka;
    MapDBKey *kb;
    if (strcmp(a, b) == 0) {
        return 1;
    }
    ka = Find173940(a);
    if (ka == 0) {
        return 0;
    }
    kb = Find173940(b);
    if (kb == 0) {
        return 0;
    }
    return ka->val == kb->val;
}

CMenuNews *CMenuNews::Create() {
    CMenuNews *p = (CMenuNews *)operator new(0x5C);
    func_00173A68(p);
    return p;
}
INCLUDE_RODATA("asm/nonmatchings/CMapDBExpr", D_002DA320);
INCLUDE_RODATA("asm/nonmatchings/CMapDBExpr", D_002DA360);
INCLUDE_RODATA("asm/nonmatchings/CMapDBExpr", D_002DA370);
INCLUDE_RODATA("asm/nonmatchings/CMapDBExpr", D_002DA380);
