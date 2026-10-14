#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CPushBuf {
public:
    void Func248E00();
    int Func248EB0();

    u8 m_data[0xC];
};
//@sym strcmp 0x28B190
#include "libc.h"
extern const char D_002DA210[];

// CMapDBExpr derives from CExpr (its calls pass this unchanged). GCC 2.96 has no empty
// base optimisation, so CExpr gets its real size here.
class CExpr {
public:
    int Func24DB98(s32 a, const char *s, s32 b);

    u8 pad0[0x4];
    CPushBuf m_buf;              // 0x4
    u8 pad10[0x10];
};
class CUnk29A558 {
public:
    void Func29A558(s32 v);
};
class CMapDBExpr : public CExpr {
public:
    int Set172D00(const char *name, void *src);
    int Lookup172DD0(const char *name, void *out);
    static CMapDBExpr *Create();
    void Init();
    void CallFunc172E98();
    void Func172E98();
    int CallFunc24DB98(s32 a);
    void Clear();

    CUnk29A558 m_unk20;          // 0x20
    u8 pad21[0x48 - 0x21];
    s32 m_unk48;                 // 0x48
    s32 m_unk4C;                 // 0x4C
    s32 m_unk50;                 // 0x50
    s32 m_unk54;                 // 0x54
};

extern "C" void func_00172F70(void *p);

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
    u8 pad4[0x20];
};
class CMapDBMgr {
public:
    void *Find173940(const char *name);
    CMapDBNameRec *FindByName(const char *name);
    u8 pad0[0x4];
    u8 m_buf[0xC];            // 0x4
    u8 pad10[0x38];
    CMapDBNameRec *m_recs;    // 0x48
    s32 m_num;                // 0x4C
    void *m_table;            // 0x50
    s32 m_count;              // 0x54
};

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
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00172C30);

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00172C88);

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

CMapDBExpr *CMapDBExpr::Create() {
    CMapDBExpr *p = (CMapDBExpr *)operator new(0x58);
    func_00172F70(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00172F70);

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00172FB8);

void CMapDBExpr::Clear() {
    m_unk48 = 0;
    m_unk4C = 0;
    m_unk50 = 0;
    m_unk54 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00173050);

int CompareMapDBNames(const char **a, const char **b) {
    return strcmp(*a, *b);
}

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00173160);

int CompareMapDBNames2(const char **a, const char **b) {
    return strcmp(*a, *b);
}

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00173578);

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00173648);

void CMapDBExpr::Init() {
    m_buf.Func248E00();
    Clear();
}

CMapDBNameRec *CMapDBMgr::FindByName(const char *name) {
    for (s32 i = 0; i < m_num; i++) {
        if (strcmp(m_recs[i].m_name, name) == 0) return &m_recs[i];
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00173828);

void *CMapDBMgr::Find173940(const char *name) {
    MapDBKey key;
    key.name = name;
    key.val = 0;
    return bsearch(&key, m_table, m_count, 8, (int (*)(const void *, const void *))CompareMapDBNames2);
}

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00173980);

CMenuNews *CMenuNews::Create() {
    CMenuNews *p = (CMenuNews *)operator new(0x5C);
    func_00173A68(p);
    return p;
}
