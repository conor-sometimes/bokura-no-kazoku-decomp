#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001AAB60(void *p);
class CMenuSysscr24 {
public:
    static CMenuSysscr24 *Create();
};

void Func235DE0(const char *fmt, ...);
void Func225088();
int Func2250C0();
extern char D_002DF338[];
extern "C" int func_001A7658(void *p);
class CMenuSysscr25 {
public:
    int Func1AAAE0();
    u8 pad0[0x58];
    void *m_unk58;            // 0x58
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr25", __13CMenuSysscr25);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr25", func_001AA748);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr25", func_001AA7C8);

int CMenuSysscr25::Func1AAAE0() {
    if (m_unk58 == 0) {
        Func235DE0(D_002DF338);
        Func225088();
        return Func2250C0();
    }
    return func_001A7658(m_unk58);
}

CMenuSysscr24 *CMenuSysscr24::Create() {
    CMenuSysscr24 *p = (CMenuSysscr24 *)operator new(0x7C);
    func_001AAB60(p);
    return p;
}
