#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct CSwingBone { s32 id; u8 pad[0x18]; };
int Func111960(CSwingBone *p, void *data);
void *Func245D00(int size);
class CSwingBoneRes2 {
public:
    int Load(void *data);
    void Func111CF8();
    CSwingBone *Find(int id);
    CSwingBone *m0;           // 0x0
    s32 m4;                   // 0x4
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CSwingBoneRes", func_00111748);

INCLUDE_ASM("asm/nonmatchings/CSwingBoneRes", func_00111760);

INCLUDE_ASM("asm/nonmatchings/CSwingBoneRes", func_001117C0);

INCLUDE_RODATA("asm/nonmatchings/CSwingBoneRes", D_002D33A0);
INCLUDE_RODATA("asm/nonmatchings/CSwingBoneRes", D_002D33A8);
INCLUDE_RODATA("asm/nonmatchings/CSwingBoneRes", D_002D33B0);
INCLUDE_ASM("asm/nonmatchings/CSwingBoneRes", Func111960__FP10CSwingBonePv);
INCLUDE_RODATA("asm/nonmatchings/CSwingBoneRes", D_002D33C0);
INCLUDE_RODATA("asm/nonmatchings/CSwingBoneRes", D_002D33C8);

int CSwingBoneRes2::Load(void *data) {
    int n;
    CSwingBone *p;
    Func111CF8();
    n = Func111960(0, data);
    m4 = n;
    p = 0;
    if (n > 0) p = (CSwingBone *)Func245D00(n * 28);
    m0 = p;
    Func111960(p, data);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CSwingBoneRes", func_00111BA8);
INCLUDE_RODATA("asm/nonmatchings/CSwingBoneRes", D_002D33F0);

INCLUDE_ASM("asm/nonmatchings/CSwingBoneRes", Func111CF8__14CSwingBoneRes2);

CSwingBone *CSwingBoneRes2::Find(int id) {
    int i;
    for (i = 0; i < m4; i++) {
        if (m0[i].id < 0) continue;
        if (id < 0 || m0[i].id == id) return &m0[i];
    }
    return 0;
}
