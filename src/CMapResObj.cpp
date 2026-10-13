#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMapRes {
public:
    void Func11AC70();
};
class CMapResObj {
public:
    void ResFunc11AC70();

    u8 pad0[0x10];
    CMapRes m_res;            // 0x10
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMapResObj", func_0012D550);

INCLUDE_ASM("asm/nonmatchings/CMapResObj", func_0012D5A0);

void CMapResObj::ResFunc11AC70() {
    m_res.Func11AC70();
}

INCLUDE_ASM("asm/nonmatchings/CMapResObj", func_0012D730);

INCLUDE_ASM("asm/nonmatchings/CMapResObj", func_0012D768);
