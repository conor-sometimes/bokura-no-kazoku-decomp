#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct CSwingBone { s32 id; u8 pad[0x14]; void *m_data; };
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
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CSwingBoneRes.
// CSwingBoneRes2 is the same object's non-virtual part.
class CSwingBoneRes {
public:
    CSwingBoneRes();
    virtual ~CSwingBoneRes();

    CSwingBone *m0;           // 0x0
    s32 m4;                   // 0x4
    // vptr 0x8
};

extern void (*D_002B91B0)(void *p);
// @decl-end

CSwingBoneRes::CSwingBoneRes() {
    m0 = 0;
    m4 = 0;
}

CSwingBoneRes::~CSwingBoneRes() {
    ((CSwingBoneRes2 *)this)->Func111CF8();
}

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

void CSwingBoneRes2::Func111CF8() {
    s32 i;
    for (i = 0; i < m4; i++) {
        if (m0[i].m_data) D_002B91B0(m0[i].m_data);
    }
    if (m0) {
        D_002B91B0(m0);
        m0 = 0;
        m4 = 0;
    }
}

CSwingBone *CSwingBoneRes2::Find(int id) {
    int i;
    for (i = 0; i < m4; i++) {
        if (m0[i].id < 0) continue;
        if (id < 0 || m0[i].id == id) return &m0[i];
    }
    return 0;
}
