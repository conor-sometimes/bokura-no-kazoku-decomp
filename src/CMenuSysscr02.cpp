#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001AE0A8(void *p);
class CMenuSysscr01 {
public:
    static CMenuSysscr01 *Create();
};

class CUnk1A4298 {
public:
    int Func1A4298();
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
extern void *D_002A5538;
void Func225088();
int Func2250C0();
void Func225240(s32 v);
class CMenuSysscr02 {
public:
    int Func1ADFE0();
    u8 pad0[0xB0];
    CUnk1A4298 *m_unkB0;      // 0xB0
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr02", Init1AD668__13CMenuSysscr03);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr02", func_001AD6B8);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr02", func_001AD748);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr02", func_001AD800);

int CMenuSysscr02::Func1ADFE0() {
    u8 *p = func_00237570(0x60);
    func_00237A88(p, 4);
    func_00238158(func_00237C30(p + 0x30), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unkB0->Func1A4298());
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B66E8(D_002A5538));
    Func225088();
    Func225240((s32)p);
    return Func2250C0();
}

CMenuSysscr01 *CMenuSysscr01::Create() {
    CMenuSysscr01 *p = (CMenuSysscr01 *)operator new(0x60);
    func_001AE0A8(p);
    return p;
}
