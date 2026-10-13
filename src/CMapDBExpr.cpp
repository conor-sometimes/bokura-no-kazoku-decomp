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
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00172C30);

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00172C88);

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00172D00);

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00172DD0);

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

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00172F38);

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

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_001737A0);

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00173828);

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00173940);

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00173980);

INCLUDE_ASM("asm/nonmatchings/CMapDBExpr", func_00173A30);
