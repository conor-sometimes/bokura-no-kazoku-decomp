#pragma interface
#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CProcess.h"
class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};
// CSnapMgr (another lane's unit; constructor through config/aliases.ld).
class CSnapMgr : public CTask {
public:
    CSnapMgr();

    u8 pad8[0x30];
};
struct CVec4 { f32 x, y, z, w; };
void Func270C50(CVec4 *dst, const CVec4 *src);
extern "C" void func_002709A8(CVec4 *d, CVec4 *a, CVec4 *b, f32 t);
class CSndWorkReal {
public:
    void Func1291B8(s32 on, s32 dur);
};
// The fade manager (CFadeMgr unit, which shares this object); its slot functions sit in this
// file. Only the fields used here. #pragma interface (top) keeps this unit from emitting the
// vtables (asm data), so the key method ~CFadeMgr can be C++; ~IFadeMgr is inline in retail.
class IFadeMgr : public CTask {
public:
    virtual ~IFadeMgr() {}
};
class CFadeMgr : public IFadeMgr {
public:
    virtual ~CFadeMgr();
    void Start(s32 type, s32 dur, s32 snd);
    void Update();

    s32 *m8;                  // 0x8: owner's pointer slot
    u8 padC[0x4];
    CVec4 m10;                // 0x10: target colour
    CVec4 m20;                // 0x20: start colour
    CVec4 m30;                // 0x30: current colour
    s32 m40;                  // 0x40: frame
    s32 m44;                  // 0x44: length
    s32 m48;                  // 0x48: fade type
    s32 m4C;                  // 0x4C: fading
    CSndWorkReal *m50;        // 0x50
};
// @decl-end

CFadeMgr::~CFadeMgr() {
    *m8 = 0;
}

void CFadeMgr::Start(s32 type, s32 dur, s32 snd) {
    s32 on;
    if ((u32)type >= 3) return;
    if (m48 == type && !m4C) return;
    Func270C50(&m20, &m30);
    switch (type) {
    case 0:
        m10.x = m30.x;
        m10.y = m30.y;
        m10.z = m30.z;
        m10.w = 0.0f;
        break;
    case 1:
        m10.x = 0.0f;
        m10.w = 1.0f;
        m10.y = 0.0f;
        m10.z = 0.0f;
        break;
    case 2:
        m10.w = m10.z = m10.y = m10.x = 1.0f;
        break;
    }
    on = 0 < dur;
    Func270C50(&m30, on ? &m20 : &m10);
    m48 = type;
    m4C = on;
    m40 = 0;
    m44 = dur;
    if (m50 && snd) m50->Func1291B8(type != 0, dur);
}

void CFadeMgr::Update() {
    if (m40 < m44) {
        m40++;
        func_002709A8(&m30, &m10, &m20, (f32)m40 / (f32)m44);
        if (m40 == m44) m4C = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/IFadeMgr", func_0010B350);

s32 AddSnapMgr(CTaskList24F5C0 *list) {
    CSnapMgr *p = new CSnapMgr;
    return list->Func24F5C0(p, 0);
}
