#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CUnk16E280 {
public:
    void Func16E280();
    void Func16E518();
};
class CGameSeasonPrevPart {
public:


    u8 pad0[0x230];
    CUnk16E280 m_unk230;      // 0x230
};
class CGameSeasonPrev {
public:
    void CallFunc16E280();
    void CallFunc16E518();

    u8 pad0[0x2C];
    CGameSeasonPrevPart* m_part; // 0x2C
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", Init153410__18CGameMainRes153410i);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00153550);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00153668);

void CGameSeasonPrev::CallFunc16E280() {
    m_part->m_unk230.Func16E280();
}

void CGameSeasonPrev::CallFunc16E518() {
    m_part->m_unk230.Func16E518();
}

INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8CA8);
INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00153710);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8CF0);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8D10);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8D50);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8D60);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8D68);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8D70);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8D78);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8D80);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8D90);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8DA0);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8DB0);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8DC0);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8DD0);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8DE0);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8DF0);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8E00);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8E10);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00156120);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00156858);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00156C50);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00156D28);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00156D60);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00156DD0);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00156E80);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00157498);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00157568);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00157738);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00157860);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00157978);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8E90);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00157AE8);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00157B68);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00157BF0);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00157C98);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00157DB0);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00157EE8);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00158088);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00158210);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00158290);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_001582C8);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00158650);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_001587A8);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00158F60);
