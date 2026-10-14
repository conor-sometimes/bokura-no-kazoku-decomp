#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001AC488(void *p);
class CMenuSysscr07 {
public:
    static CMenuSysscr07 *Create();
};

void Func235DE0(const char *fmt, ...);
void Func225088();
int Func2250C0();
extern char D_002DF5D8[];
extern "C" int func_001A7658(void *p);
class CMenuSysscr08 {
public:
    int Func1AC408();
    u8 pad0[0x58];
    void *m_unk58;            // 0x58
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr08", __13CMenuSysscr08);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr08", func_001AC180);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr08", func_001AC200);

int CMenuSysscr08::Func1AC408() {
    if (m_unk58 == 0) {
        Func235DE0(D_002DF5D8);
        Func225088();
        return Func2250C0();
    }
    return func_001A7658(m_unk58);
}

CMenuSysscr07 *CMenuSysscr07::Create() {
    CMenuSysscr07 *p = (CMenuSysscr07 *)operator new(0x60);
    func_001AC488(p);
    return p;
}
