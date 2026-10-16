#pragma interface
#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void *func_00251488();
extern "C" void func_00227CB8(void *ctx, s32 x, s32 y, s32 w, s32 h, void *src);
#include "CTask.h"
// #pragma interface (top) keeps this unit from emitting the vtables (asm data), so the key method
// ~CSnapMgr can be C++; ~ISnapMgr is inline in retail.
class ISnapMgr : public CTask {
public:
    virtual ~ISnapMgr() {}
};
extern void (*D_002B91B0)(void *p);
extern s32 D_0029F398;
class CSnapMgr : public ISnapMgr {
public:
    virtual ~CSnapMgr();
    void Update10B9E8();
    void Start10B950(s32 mode, s32 n, s32 flag);
    void Draw10BEF0();
    u8 *m_unk8;               // 0x8
    f32 m_unkC;               // 0xC
    f32 m_unk10;              // 0x10
    f32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
    s32 m_unk24;              // 0x24
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
    s32 m_unk30;              // 0x30
    void *m_unk34;            // 0x34
};

extern "C" s32 func_0010BAC8(s32 psm);
extern "C" void func_00227BF0(u64 tex, s32 a, s32 b, s32 w, s32 h, u8 *src);

extern "C" void func_00129250(void *p, s32 mode, s32 n);
void Func10BA48(u8 *p);
extern "C" void func_0010BBD0(u8 *p, f32 v);
class CUnk237E90 {
public:
    int Func237E90(int v);
    u8 pad0[0x10];
};
extern CUnk237E90 *D_002A5BC0;
int Func225088();
int Func2250C0();
// @decl-end

CSnapMgr::~CSnapMgr() {
    if (m_unk8) D_002B91B0(m_unk8);
    D_0029F398 = 0;
}

void CSnapMgr::Start10B950(s32 mode, s32 n, s32 flag) {
    if (m_unk20 == mode && m_unk24 == 0) return;
    m_unkC = mode ? 1.0f : 0.0f;
    m_unk10 = m_unk14;
    m_unk18 = 0;
    m_unk20 = mode;
    m_unk1C = n;
    if (n > 0) {
        m_unk24 = 1;
    } else {
        m_unk24 = 0;
        m_unk14 = m_unkC;
    }
    if (m_unk34 && flag) func_00129250(m_unk34, mode, n / 2);
}

void CSnapMgr::Update10B9E8() {
    if (m_unk18 < m_unk1C) {
        m_unk18++;
        m_unk14 = m_unk10 + (m_unkC - m_unk10) * ((f32)m_unk18 / (f32)m_unk1C);
        if (m_unk18 == m_unk1C) m_unk24 = 0;
    }
}

void Func10BA48(u8 *p) {
    u8 *q = p + 0x8C000;
    if (p) {
        func_00227CB8(func_00251488(), 0, 0, 0x280, 0xE0, p);
        func_00227CB8(func_00251488(), 0, 0xE0, 0x280, 0xE0, q);
    }
}

INCLUDE_ASM("asm/nonmatchings/ISnapMgr", func_0010BAC8);

void Blit10BB20(u64 tex, s32 a, s32 b, s32 w, s32 y, s32 h, u8 *base) {
    func_00227BF0(tex, a, b, w, h, base + y * func_0010BAC8((s32)((tex >> 32) & 0x3F)) * w / 8);
}

INCLUDE_ASM("asm/nonmatchings/ISnapMgr", func_0010BBD0);

void CSnapMgr::Draw10BEF0() {
    Func225088();
    if (m_unk28) {
        Func10BA48(m_unk8);
        m_unk28 = 0;
        m_unk2C = 1;
    }
    if (m_unk2C) {
        if (m_unk14 > 0.0f) func_0010BBD0(m_unk8, m_unk14);
    }
    s32 k = m_unk30;
    if (k < 0) k = 7;
    D_002A5BC0[k].Func237E90(Func2250C0());
}
