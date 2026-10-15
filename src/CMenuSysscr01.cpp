#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

extern "C" void func_001AE488(void *p);
class CMenuSysscr00 {
public:
    static CMenuSysscr00 *Create();
};

extern "C" int func_001A7658(void *p);
class CMenuSub1A7658 {
public:
    u8 pad0[0x5C];
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr01.
class CMenuSysscr01 : public CMenuProcess {
public:
    CMenuSysscr01();
    virtual ~CMenuSysscr01();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuSub1A7658 *m_unk58;  // 0x58
};

extern f32 D_002A6800[];
// VU0 float to 1.15 fixed point (sine-table index), as in CSwingBoneObj.
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
// Pulsing brightness for CMenuSysscr00::Update (sits after this unit's text).
// @decl-end

CMenuSysscr01::CMenuSysscr01() {
    m_unk58 = 0;
}

CMenuSysscr01::~CMenuSysscr01() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr01", Update__13CMenuSysscr01);

s32 CMenuSysscr01::Draw() {
    if (m_unk58 == 0) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return func_001A7658(m_unk58);
}

CMenuSysscr00 *CMenuSysscr00::Create() {
    CMenuSysscr00 *p = (CMenuSysscr00 *)operator new(0x60);
    func_001AE488(p);
    return p;
}

f32 Pulse1AE3F8(f32 *t) {
    u8 *tbl = (u8 *)D_002A6800;
    f32 s = *(f32 *)(tbl + ((Ftoi15(*t) << 1) & 0xFFFC)) * 0.75f;
    if (s < 0.0f) s = -s;
    s += 0.25f;
    f32 x = *t + 0.006f;
    *t = x;
    if (x >= 1.0f) *t = 0.0f;
    if (s > 1.0f) s = 1.0f;
    return s;
}
