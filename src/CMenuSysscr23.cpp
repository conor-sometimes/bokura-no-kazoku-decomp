#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001AB280(void *p);
class CMenuSysscr22 {
public:
    static CMenuSysscr22 *Create();
};

void Func235DE0(const char *fmt, ...);
void Func225088();
int Func2250C0();
extern char D_002DF3C8[];
class CMenuAsksavequitWin {
public:
    int Func193D68();
};
class CMenuSysscr23 {
public:
    int Func1AB200();
    u8 pad0[0x58];
    CMenuAsksavequitWin *m_unk58; // 0x58
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr23", __13CMenuSysscr23);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr23", func_001AB038);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr23", func_001AB0B8);

int CMenuSysscr23::Func1AB200() {
    if (m_unk58 == 0) {
        Func235DE0(D_002DF3C8);
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func193D68();
}

CMenuSysscr22 *CMenuSysscr22::Create() {
    CMenuSysscr22 *p = (CMenuSysscr22 *)operator new(0x60);
    func_001AB280(p);
    return p;
}
