#include "common.h"

INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPost", D_002D8EA8);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPost", D_002D8EC8);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPost", D_002D8F08);
INCLUDE_ASM("asm/nonmatchings/CGameSeasonPost", func_00158FC0);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPost", func_00159050);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPost", func_001590B8);

int CompareSeasonPostIds(const s32 *a, const s32 *b) {
    return *a - *b;
}

int CheckSeasonPostId(int v) {
    if (v == 0x3FFF) {
        return -1;
    }
    if (v < 0) {
        return -1;
    }
    return v;
}

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPost", func_001592F8);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPost", func_00159648);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPost", func_00159688);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPost", func_00159790);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001597D8() {
}

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPost", func_001597E0);
