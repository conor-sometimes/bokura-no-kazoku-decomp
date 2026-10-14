#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001B11E8(void *p);
class CMenuLoad {
public:
    static CMenuLoad *Create();
};

class CMenuMgrSub1B6BA8 {
public:
    int Check1B7428(u32 i);
};
extern CMenuMgrSub1B6BA8 *D_002A55AC;

class CMenuMgrSub1B6418 {
public:
    void Move1B6488(f32 x, f32 y);
};
extern CMenuMgrSub1B6418 *D_002A5538;
extern "C" void func_001829E8(void *p, s32 v);
extern "C" void func_00183090(void *p, f32 *x, f32 *y);
class CMenuSaveObj {
public:
    void Func1B1130();
    u8 pad0[0x64];
    s32 m_unk64;              // 0x64
    u8 pad68[0xC0 - 0x68];
    u8 m_unkC0[0x10];         // 0xC0
};

class CUnk237E90 {
public:
    int Func237E90(int v);
};
extern "C" u8 *func_00237570(s32 v);
extern "C" void func_00237A88(void *p, s32 v);
extern "C" void *func_00237C30(void *p);
extern "C" int func_00238158(void *p, s32 v);
extern "C" int func_001B66E8(void *p);
extern "C" int func_001836E8(void *p);
extern "C" int func_001848E0(void *p);

void Func225088();
int Func2250C0();
void Func225240(s32 v);
class CMenuSaveWin {
public:
    void Func1B1048();
    u8 pad0[0x70];
    u8 m_unk70[0x50];         // 0x70
    u8 m_unkC0[0x10];         // 0xC0
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuSave", Init1AE800__13CMenuSysscr00);

INCLUDE_ASM("asm/nonmatchings/CMenuSave", func_001AE848);

INCLUDE_ASM("asm/nonmatchings/CMenuSave", func_001AE998);

void CMenuSaveWin::Func1B1048() {
    char buf[32];
    u8 *p = func_00237570(0x70);
    func_00237A88(p, 7);
    func_00238158(func_00237C30(p + 0x60), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(func_001836E8(m_unkC0));
    ((CUnk237E90 *)(p + 0x40))->Func237E90(func_001848E0(m_unk70));
    ((CUnk237E90 *)(p + 0x50))->Func237E90(func_001B66E8(D_002A5538));
    Func225088();
    Func225240((s32)p);
    Func2250C0();
}

CMenuLoad *CMenuLoad::Create() {
    CMenuLoad *p = (CMenuLoad *)operator new(0x7DC0);
    func_001B11E8(p);
    return p;
}

void CMenuSaveObj::Func1B1130() {
    f32 x, y;
    func_001829E8(m_unkC0, m_unk64);
    func_00183090(m_unkC0, &x, &y);
    D_002A5538->Move1B6488(x, y);
}

int Func1B1188() {
    for (s32 i = 0; i < 30; i++) {
        if (D_002A55AC->Check1B7428(i) == 1) return 1;
    }
    return 0;
}
