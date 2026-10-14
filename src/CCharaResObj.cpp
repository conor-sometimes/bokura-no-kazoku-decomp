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

//@sym __builtin_new 0x245648
//@sym __21CCharaResObjSub12D408 0x12D408
class CCharaResObjSub12D408 {
public:
    CCharaResObjSub12D408() throw();

    u8 pad0[0x140];
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CCharaResObj", func_0012D1C8);

INCLUDE_ASM("asm/nonmatchings/CCharaResObj", func_0012D218);

void CCharaResObj::ResFunc112A80() {
    m_res.Func112A80();
}

CCharaResObjSub12D408 *CreateCCharaResObjSub12D408() {
    return new CCharaResObjSub12D408;
}

INCLUDE_ASM("asm/nonmatchings/CCharaResObj", __21CCharaResObjSub12D408);
