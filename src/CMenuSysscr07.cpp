#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001AC820(void *p);
class CMenuSysscr06 {
public:
    static CMenuSysscr06 *Create();
};

void Func235DE0(const char *fmt, ...);
void Func225088();
int Func2250C0();
extern char D_002DF658[];
extern "C" int func_001A7658(void *p);
class CMenuSysscr07 {
public:
    int Func1AC7A0();
    u8 pad0[0x58];
    void *m_unk58;            // 0x58
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr07", func_001AC488);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr07", func_001AC4C0);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr07", func_001AC540);

int CMenuSysscr07::Func1AC7A0() {
    if (m_unk58 == 0) {
        Func235DE0(D_002DF658);
        Func225088();
        return Func2250C0();
    }
    return func_001A7658(m_unk58);
}

CMenuSysscr06 *CMenuSysscr06::Create() {
    CMenuSysscr06 *p = (CMenuSysscr06 *)operator new(0x7C);
    func_001AC820(p);
    return p;
}
