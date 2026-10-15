#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct CSwingBone {
    s32 id;                   // 0x0
    s32 m_4;                  // 0x4
    s32 m_8;                  // 0x8
    s32 m_C;                  // 0xC
    f32 m_10;                 // 0x10
    s32 m_numAxes;            // 0x14
    void *m_data;             // 0x18
};
int Func111960(CSwingBone *p, void *data);
void *Func245D00(int size);
class CSwingBoneRes2 {
public:
    s32 LoadFile(const char *name);
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

struct CSwingAxisDef {
    s32 m_axes;               // 0x0
    char m_name[0x10];        // 0x4
    f32 m_scale;              // 0x14
};
const char *Func24AFE8(const char *p, char *buf, s32 a, s32 n);
char *Func24A570(const char *p, char *dst, const char *s1, const char *s2);
extern "C" char *func_0024A778(char *p, f32 *v, f32 def, const char *s1, const char *s2);
extern char D_002D33A0[], D_002D33A8[];
// @decl-end

CSwingBoneRes::CSwingBoneRes() {
    m0 = 0;
    m4 = 0;
}

CSwingBoneRes::~CSwingBoneRes() {
    ((CSwingBoneRes2 *)this)->Func111CF8();
}

s32 Func1117C0(CSwingAxisDef *defs, const char *p) {
    char line[0x100];
    char axes[0x100];
    s32 n;
    for (n = 0; p = Func24AFE8(p, line, 1, 0x100), *p || line[0]; n++) {
        if (defs) {
            char *q = Func24A570(line, defs[n].m_name, D_002D33A0, D_002D33A8);
            char *s;
            q = Func24A570(q, axes, D_002D33A0, D_002D33A8);
            defs[n].m_axes = 7;
            for (s = axes; *s; s++) {
                if (*s == 'x') defs[n].m_axes &= ~1;
                if (*s == 'y') defs[n].m_axes &= ~2;
                if (*s == 'z') defs[n].m_axes &= ~4;
            }
            func_0024A778(q, &defs[n].m_scale, 1.0f, D_002D33A0, D_002D33A8);
        }
    }
    return n;
}

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
