#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CSwingBoneObjSub1114C0 {
public:
    f32 GetUnk10(s32 i);

    u8 pad0[0x10];
    f32 m_unk10[1];           // 0x10
};

#include "libc.h"
extern void (*D_002B91B0)(void *p);
void Func235DE0(const char *fmt, ...) throw();
void *Func245D00(int size);
struct CSwingBoneNode {
    s32 m0;                   // 0x0 (Apply111548: axis mask, bits 0-2)
    char m_name[0x10];        // 0x4
    f32 m_weight;             // 0x14
};
struct CSwingBoneOut {
    u8 pad0[0x20];
    f32 m_rot[3];             // 0x20
    u8 pad2C[0x4];
};
extern f32 D_002A6800[];
// Sine table lookup: angle in [0, 1) turns, converted to 1.15 fixed point on VU0.
inline s32 Ftoi15(f32 x) {
    s32 i;
    asm volatile(
        "mfc1 %0, %1\n"
        "qmtc2.ni %0, $vf2\n"
        "vftoi15.x $vf2, $vf2\n"
        "qmfc2.ni %0, $vf2\n"
        : "=r"(i) : "f"(x));
    return i;
}
struct CSwingBone {
    s32 m_id;                 // 0x0
    s32 m_div[3];             // 0x4
    f32 m_unk10;              // 0x10
    s32 m_numNodes;           // 0x14
    CSwingBoneNode *m_nodes;  // 0x18
};
class CSwingBoneRes2 {
public:
    CSwingBone *Find(int id);
};
struct CModelBones {
    s32 m_num;                // 0x0
    u8 pad4[0xC];
    const char *m_names[1];   // 0x10
};
struct CModelEnt {
    u8 pad0[0x10];
    CModelBones *m_bones;     // 0x10
    u8 pad14[0x20];
};
extern CModelEnt *D_002A5D0C;
// Fractional part wrapped into [0, 1) on VU0 (macro-mode inline asm of the SDK math library).
inline f32 FracVu0(f32 x) {
    f32 r;
    asm volatile(
        "mfc1 $2, %1\n"
        "qmtc2.ni $2, $vf2\n"
        "vftoi0.x $vf3, $vf2\n"
        "vmulaw.x ACC, $vf2, $vf0w\n"
        "vaddw.x $vf2, $vf0, $vf0w\n"
        "vitof0.x $vf3, $vf3\n"
        "bgez $2, 1f\n"
        "vmadda.x ACC, $vf2, $vf2\n"
        "1:\n"
        "vmsubw.x $vf2, $vf3, $vf0w\n"
        "qmfc2.ni $8, $vf2\n"
        "mtc1 $8, %0\n"
        : "=f"(r) : "f"(x) : "$2", "$8");
    return r;
}

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CSwingBoneObj, its
// only virtual. The vptr follows its fields at 0x30.
class CSwingBoneObj {
public:
    CSwingBoneObj();
    virtual ~CSwingBoneObj();
    void Clear();
    void Release();
    int Setup(CSwingBoneRes2 *res, s32 id, s32 model);
    void SetUnk10(f32 v);
    void Step1114D0();
    void Apply111548(CSwingBoneOut *out);

    CSwingBoneRes2 *m_unk0;   // 0x00
    CSwingBone *m_unk4;       // 0x04
    s32 *m_unk8;              // 0x08
    s32 m_unkC;               // 0x0C
    f32 m_unk10[3];           // 0x10
    f32 m_unk1C[3];           // 0x1C
    f32 m_unk28;              // 0x28
    f32 m_unk2C;              // 0x2C
};
// @decl-end

CSwingBoneObj::CSwingBoneObj() {
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    Clear();
}

CSwingBoneObj::~CSwingBoneObj() {
    Release();
}

void CSwingBoneObj::Clear() {
    memset(m_unk10, 0, 0xC);
    memset(m_unk1C, 0, 0xC);
    m_unk2C = m_unk28 = 1.0f;
}

int CSwingBoneObj::Setup(CSwingBoneRes2 *res, s32 id, s32 model) {
    CModelEnt *e = &D_002A5D0C[model];
    CModelBones *bones;
    if (!e || !(bones = e->m_bones)) {
        Func235DE0("*** invalid model ID (xmd=%d)\n", model);
        return 0;
    }
    CSwingBone *sb = res->Find(id);
    if (!sb) {
        Func235DE0("*** invalid swing bone ID (ID=%d)\n", id);
        return 0;
    }
    m_unkC = sb->m_numNodes;
    m_unk8 = (s32 *)Func245D00(m_unkC * 4);
    s32 i;
    for (i = 0; i < m_unkC; i++) {
        m_unk8[i] = -1;
        for (s32 j = 0; j < bones->m_num; j++) {
            if (!strcmp(sb->m_nodes[i].m_name, bones->m_names[j])) {
                m_unk8[i] = j;
                break;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        m_unk10[i] = 0;
        m_unk1C[i] = 1.0f / (f32)sb->m_div[i];
    }
    m_unk0 = res;
    m_unk4 = sb;
    return 1;
}

void CSwingBoneObj::Release() {
    if (m_unk8) {
        D_002B91B0(m_unk8);
        m_unk8 = 0;
        m_unkC = 0;
    }
    Clear();
    m_unk0 = 0;
    m_unk4 = 0;
}

void CSwingBoneObj::SetUnk10(f32 v) {
    for (s32 i = 2; i >= 0; i--) {
        m_unk10[i] = v;
    }
}

f32 CSwingBoneObjSub1114C0::GetUnk10(s32 i) {
    return m_unk10[i];
}

void CSwingBoneObj::Step1114D0() {
    s32 i;
    for (i = 0; i < 3; i++) {
        m_unk10[i] += m_unk1C[i] * m_unk28;
        m_unk10[i] = FracVu0(m_unk10[i]);
    }
}

void CSwingBoneObj::Apply111548(CSwingBoneOut *out) {
    if (!m_unk0 || !m_unk4 || !out) return;
    f32 s = m_unk4->m_unk10 * m_unk2C;
    u8 *tbl = (u8 *)D_002A6800;
    f32 v[3];
    f32 t0a = (*(f32 *)(tbl + ((Ftoi15(m_unk10[0]) << 1) & 0xFFFC)));
    v[0] = s * (t0a + (*(f32 *)(tbl + ((Ftoi15(m_unk10[1]) << 1) & 0xFFFC)))) * 0.5f;
    f32 t1a = (*(f32 *)(tbl + ((Ftoi15(m_unk10[1]) << 1) & 0xFFFC)));
    v[1] = s * (t1a + (*(f32 *)(tbl + ((Ftoi15(m_unk10[2]) << 1) & 0xFFFC)))) * 0.5f;
    f32 t2a = (*(f32 *)(tbl + ((Ftoi15(m_unk10[2]) << 1) & 0xFFFC)));
    v[2] = s * (t2a + (*(f32 *)(tbl + ((Ftoi15(m_unk10[0]) << 1) & 0xFFFC)))) * 0.5f;
    s32 i;
    for (i = 0; i < m_unkC; i++) {
        s32 idx = m_unk8[i];
        if (idx < 0) continue;
        f32 *p = out[idx].m_rot;
        s32 f = m_unk4->m_nodes[i].m0;
        f32 w = m_unk4->m_nodes[i].m_weight;
        if (f & 1) p[0] += v[0] * w;
        if (f & 2) p[1] += v[1] * w;
        if (f & 4) p[2] += v[2] * w;
    }
}
