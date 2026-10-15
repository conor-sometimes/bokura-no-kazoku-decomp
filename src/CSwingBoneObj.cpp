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
void Func235DE0(const char *fmt, ...);
void *Func245D00(int size);
struct CSwingBoneNode {
    s32 m0;                   // 0x0
    char m_name[0x14];        // 0x4
};
struct CSwingBone {
    s32 m_id;                 // 0x0
    s32 m_div[3];             // 0x4
    u8 pad10[0x4];
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

INCLUDE_ASM("asm/nonmatchings/CSwingBoneObj", func_001114D0);

INCLUDE_ASM("asm/nonmatchings/CSwingBoneObj", func_00111548);
