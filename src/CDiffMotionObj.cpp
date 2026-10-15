#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CDiffMotionObjSub10FB10 {
public:
    void Reset();

    u8 pad0[0x14];
    s32 m_unk14;              // 0x14
    f32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    f32 m_unk20;              // 0x20
};

f32 Func1EAC30(int v);
class CDiffMotionObj10FD20 {
public:
    f32 GetFrame();
    u8 pad0[8];
    s32 m8;
};
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CDiffMotionObj.
// CDiffMotionObjSub10FB10 is the same object's part from 0x14.
struct CVec4 { f32 x, y, z, w; };
struct CDiffJoint { CVec4 r; CVec4 t; CVec4 s; };
// A pose buffer: joint count, then the joints from 0x20 (0x30 each).
struct CDiffPose {
    s32 m_num;                // 0x00
    u8 pad4[0x1C];
    CDiffJoint m_j[1];        // 0x20
};
extern "C" int func_001ECCA8(s32 h);
extern "C" void func_001ECE18(s32 h, f32 t, void *p);
extern "C" void func_00270A98(CVec4 *d, CVec4 *a, CVec4 *b);
extern "C" void func_00270B68(CVec4 *d, CVec4 *a, f32 s);
extern "C" void func_00270A30(CVec4 *d, CVec4 *a, CVec4 *b);
extern void (*D_002B91B0)(void *p);
class CDiffMotionObj {
public:
    CDiffMotionObj();
    virtual ~CDiffMotionObj();
    void Func10FC98();
    void Update();
    void Apply(CDiffPose *out);

    s32 m_unk0;               // 0x00
    s32 m_unk4;               // 0x04
    s32 m_unk8;               // 0x08: motion handle
    s32 m_unkC;               // 0x0C: CDiffPose *
    s32 m_unk10;              // 0x10: CDiffPose *
    s32 m_unk14;              // 0x14
    f32 m_unk18;              // 0x18
    f32 m_unk1C;              // 0x1C
    f32 m_unk20;              // 0x20
    // vptr 0x24
};
// @decl-end

CDiffMotionObj::CDiffMotionObj() {
    m_unk8 = -1;
    m_unk0 = 0;
    m_unk4 = 0;
    m_unkC = 0;
    m_unk10 = 0;
    ((CDiffMotionObjSub10FB10 *)this)->Reset();
}

CDiffMotionObj::~CDiffMotionObj() {
    Func10FC98();
}

void CDiffMotionObjSub10FB10::Reset() {
    m_unk14 = 1;
    m_unk18 = 1.0f;
    m_unk20 = 1.0f;
    m_unk1C = 0;
}

INCLUDE_ASM("asm/nonmatchings/CDiffMotionObj", func_0010FB30);

void CDiffMotionObj::Func10FC98() {
    if (m_unk8 >= 0) {
        func_001ECCA8(m_unk8);
        m_unk8 = -1;
    }
    if (m_unkC) {
        D_002B91B0((void *)m_unkC);
        m_unkC = 0;
    }
    if (m_unk10) {
        D_002B91B0((void *)m_unk10);
        m_unk10 = 0;
    }
    m_unk0 = 0;
    m_unk4 = 0;
    ((CDiffMotionObjSub10FB10 *)this)->Reset();
}

f32 CDiffMotionObj10FD20::GetFrame() {
    if (m8 < 0) return 0.0f;
    return Func1EAC30(m8) - 1.0f;
}

void CDiffMotionObj::Update() {
    f32 f, t;
    if (m_unk8 < 0) return;
    if (m_unk14) func_001ECE18(m_unk8, 0.0f, (void *)m_unkC);
    func_001ECE18(m_unk8, m_unk1C, (void *)m_unk10);
    m_unk1C += m_unk20;
    f = Func1EAC30(m_unk8) - 1.0f;
    t = m_unk1C;
    if (f <= t) {
        f32 u;
        do {
            u = t - f;
            t = u;
        } while (f <= u);
        m_unk1C = u;
    }
    m_unk14 = 0;
}

void CDiffMotionObj::Apply(CDiffPose *out) {
    s32 i;
    CVec4 d0, d1;
    if (!m_unkC || !m_unk10 || m_unk14) return;
    for (i = 0; i < out->m_num; i++) {
        func_00270A98(&d0, &((CDiffPose *)m_unk10)->m_j[i].t, &((CDiffPose *)m_unkC)->m_j[i].t);
        func_00270A98(&d1, &((CDiffPose *)m_unk10)->m_j[i].r, &((CDiffPose *)m_unkC)->m_j[i].r);
        d0.w = 0.0f;
        d1.w = 0.0f;
        func_00270B68(&d0, &d0, m_unk18);
        func_00270B68(&d1, &d1, m_unk18);
        func_00270A30(&out->m_j[i].t, &out->m_j[i].t, &d0);
        func_00270A30(&out->m_j[i].r, &out->m_j[i].r, &d1);
    }
}
