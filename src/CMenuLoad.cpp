#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001B2AB0(void *p);
class CMenuBoot {
public:
    static CMenuBoot *Create();
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
extern void *D_002A5538;
void Func225088();
int Func2250C0();
void Func225240(s32 v);
class CMenuLoadWin {
public:
    void Func1B29C8();
    u8 pad0[0x70];
    u8 m_unk70[0x50];         // 0x70
    u8 m_unkC0[0x10];         // 0xC0
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuLoad", func_001B11E8);

INCLUDE_ASM("asm/nonmatchings/CMenuLoad", func_001B1230);

INCLUDE_ASM("asm/nonmatchings/CMenuLoad", func_001B1380);

void CMenuLoadWin::Func1B29C8() {
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

CMenuBoot *CMenuBoot::Create() {
    CMenuBoot *p = (CMenuBoot *)operator new(0xE0);
    func_001B2AB0(p);
    return p;
}
