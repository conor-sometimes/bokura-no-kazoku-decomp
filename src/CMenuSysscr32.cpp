#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"
#include "CBgWork.h"
#include "CCommandBase.h"

void *operator new(unsigned int n);
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr32.
// FreeBuf and the factory sit at the end of CMenuInputKanji.cpp (unit text starts late).
class CMenuSysscr32 : public CMenuProcess {
public:
    CMenuSysscr32();
    virtual ~CMenuSysscr32();
    virtual s32 Update();
    virtual s32 Draw();
    void FreeBuf();

    CBgWork m_bg;             // 0x58
    CCommandBase *m_cmd;      // 0x64
    void *m_unk68;            // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
};

class CUnk237E90 {
public:
    int Func237E90(int v);
};
void *Func237570(int size);
void Func237A88(void *p, int n);
void *Func237C30(void *p);
void Func238158(void *p, int v);
void Func225240(int v);

// CMenuSysscr31's constructor (CMenuSysscr31.cpp); this factory is the start of its unit.
class CChrBodyWin {
public:
    void Func188BA8();
};
extern CChrBodyWin *D_002A4308;
extern "C" int func_00245818(void *p, s32 v);
extern "C" void func_00189270(void *p, s32 v);
class CMenuSysscr31 {
public:
    CMenuSysscr31() throw();
    void Release1A7AF8();

    u8 pad0[0x58];
    u8 m_bg[0xC];             // 0x58
    void *m_unk64;            // 0x64
    void *m_cmd;              // 0x68
    u8 pad6C[0x18];
};
CMenuSysscr31 *NewCMenuSysscr32();
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr32", D_002DEEB8);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr32", D_002DEF20);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr32", D_002DF0A0);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr32", D_002DF0B8);
CMenuSysscr32::CMenuSysscr32() {
    m_cmd = 0;
    m_unk68 = 0;
    m_unk6C = 0;
    m_unk70 = 0;
}

CMenuSysscr32::~CMenuSysscr32() {
    FreeBuf();
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr32", Update__13CMenuSysscr32);

s32 CMenuSysscr32::Draw() {
    if ((u32)(m_state - 3) < 2) {
        void *p = Func237570(0x40);
        Func237A88(p, 4);
        Func238158(Func237C30((u8 *)p + 0x30), 1);
        ((CUnk237E90 *)((u8 *)p + 0x10))->Func237E90(m_cmd->Draw());
        Func225088();
        Func225240((int)p);
        return Func2250C0();
    }
    Func225088();
    return Func2250C0();
}

CMenuSysscr31 *NewCMenuSysscr32() {
    return new CMenuSysscr31;
}

void CMenuSysscr31::Release1A7AF8() {
    func_00245818(m_bg, 1);
    D_002A4308->Func188BA8();
    if (m_unk64) {
        func_00189270(m_unk64, 3);
        m_unk64 = 0;
    }
    if (m_cmd) {
        operator delete(m_cmd);
        m_cmd = 0;
    }
}
