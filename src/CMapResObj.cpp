#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMapRes {
public:
    void Func11AC70();
};
class CMapResObj {
public:
    void Init12D768();
    void ResFunc11AC70();

    u8 pad0[0x10];
    CMapRes m_res;            // 0x10
};

void *operator new(unsigned int n);
CMapResObj *NewCMapResObj();
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMapResObj", Func12D550__Fv);

INCLUDE_ASM("asm/nonmatchings/CMapResObj", func_0012D5A0);

void CMapResObj::ResFunc11AC70() {
    m_res.Func11AC70();
}

CMapResObj *NewCMapResObj() {
    CMapResObj *p = (CMapResObj *)operator new(0x140);
    p->Init12D768();
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CMapResObj", Init12D768__10CMapResObj);
