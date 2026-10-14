#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMovieObj {
public:
    int Func13EDC8();
};
class CUnk237E90 {
public:
    void Func237E90(int v);
};
class CUnk2A5BC0 {
public:


    u8 pad0[0x60];
    CUnk237E90 m_unk60;       // 0x60
};
extern CUnk2A5BC0 *D_002A5BC0;
class CEndingMain {
public:
    void Func1082F0();

    u8 pad0[0x74];
    CMovieObj m_movie;        // 0x74
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CEndingMain", func_001078A8);
INCLUDE_RODATA("asm/nonmatchings/CEndingMain", D_002D1B58);
INCLUDE_RODATA("asm/nonmatchings/CEndingMain", D_002D1B78);
INCLUDE_RODATA("asm/nonmatchings/CEndingMain", D_002D1BB8);

INCLUDE_ASM("asm/nonmatchings/CEndingMain", func_00107978);

INCLUDE_ASM("asm/nonmatchings/CEndingMain", func_00107A18);

void CEndingMain::Func1082F0() {
    int r = m_movie.Func13EDC8();
    D_002A5BC0->m_unk60.Func237E90(r);
}
