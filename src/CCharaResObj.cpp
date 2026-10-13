#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CCharaRes {
public:
    void Func112A80();
};
class CCharaResObj {
public:
    void ResFunc112A80();

    u8 pad0[0x10];
    CCharaRes m_res;          // 0x10
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CCharaResObj", func_0012D1C8);

INCLUDE_ASM("asm/nonmatchings/CCharaResObj", func_0012D218);

void CCharaResObj::ResFunc112A80() {
    m_res.Func112A80();
}

INCLUDE_ASM("asm/nonmatchings/CCharaResObj", func_0012D3D0);

INCLUDE_ASM("asm/nonmatchings/CCharaResObj", func_0012D408);
