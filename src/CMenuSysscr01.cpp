#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001AE488(void *p);
class CMenuSysscr00 {
public:
    static CMenuSysscr00 *Create();
};

void Func235DE0(const char *fmt, ...);
void Func225088();
int Func2250C0();
extern char D_002DF910[];
extern "C" int func_001A7658(void *p);
class CMenuSysscr01 {
public:
    int Func1AE378();
    u8 pad0[0x58];
    void *m_unk58;            // 0x58
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr01", func_001AE0A8);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr01", func_001AE0E0);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr01", func_001AE160);

int CMenuSysscr01::Func1AE378() {
    if (m_unk58 == 0) {
        Func235DE0(D_002DF910);
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

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr01", func_001AE3F8);
