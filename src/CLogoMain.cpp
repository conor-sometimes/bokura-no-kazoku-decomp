#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMemTex {
public:
    void Func2546F0();
    u8 m_data[0x2C];
};
class CLogoMain {
public:
    void ReleaseTextures();

    u8 pad0[0x2C];
    CMemTex m_tex2C;          // 0x2C
    CMemTex m_tex58;          // 0x58
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CLogoMain", func_001005D8);

INCLUDE_ASM("asm/nonmatchings/CLogoMain", func_00100630);

INCLUDE_ASM("asm/nonmatchings/CLogoMain", func_001006B0);

void CLogoMain::ReleaseTextures() {
    m_tex2C.Func2546F0();
    m_tex58.Func2546F0();
}

INCLUDE_ASM("asm/nonmatchings/CLogoMain", func_00100770);

INCLUDE_ASM("asm/nonmatchings/CLogoMain", func_00100E38);

INCLUDE_ASM("asm/nonmatchings/CLogoMain", func_00100F18);
