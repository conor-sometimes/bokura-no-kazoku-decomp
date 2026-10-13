#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CInterfMgr {
public:
    void ResetUnkD4Below(s32 v);
    void ClearUnkDE8();

    u8 pad0[0xD4];
    s32 m_unkD4;              // 0xD4
    u8 padD8[0xD10];
    s32 m_unkDE8;             // 0xDE8
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_00169128);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_001691D0);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_001692D0);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_00169308);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_00169340);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_001693B0);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_00169450);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_00169548);

void CInterfMgr::ResetUnkD4Below(s32 v) {
    if (m_unkD4 < v) {
        m_unkD4 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_001695C8);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_00169620);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_001696A0);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_00169718);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_00169788);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_001698A0);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_00169918);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_00169950);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016A650);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016A998);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016AA28);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016B178);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016B1C8);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016B2B0);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016BA80);

void CInterfMgr::ClearUnkDE8() {
    m_unkDE8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016BB20);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016BD00);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016C0B8);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016C6A0);

INCLUDE_ASM("asm/nonmatchings/IInterfMgr", func_0016C6D8);
