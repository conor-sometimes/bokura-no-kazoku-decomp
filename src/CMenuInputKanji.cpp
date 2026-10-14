#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CProcess.h"

// Interface without fields (its RTTI name only): the vptr is at 0. Slots 1 and 2 are inline
// (0x29B570, 0x29B578).
class IMenuInputKanji {
public:
    virtual s32 Func1A4FE0() = 0;
    virtual s32 Func29B570() = 0;
    virtual s32 Func29B578() = 0;
    virtual s32 SetNameBuf(char *buf) = 0;
    virtual s32 Func1A50C8() = 0;
    virtual s32 Func1A64D0() = 0;
};
// Vtable 0x2C1B38: the key method is Func1A4FE0 (slot 0); the destructor is slot 6.
class CMenuInputKanji : public IMenuInputKanji {
public:
    CMenuInputKanji(s32 kind);
    virtual s32 Func1A4FE0();
    virtual s32 Func29B570();
    virtual s32 Func29B578();
    virtual s32 SetNameBuf(char *buf);
    virtual s32 Func1A50C8();
    virtual s32 Func1A64D0();
    virtual ~CMenuInputKanji();
    void SetUnk4C(s32 v);

    CStateMachine m_sm;       // 0x04
    CBgWork m_bg;             // 0x4C
    s32 m_unk58;              // 0x58
    s32 m_kind;               // 0x5C
    u8 pad60[0x820];
    char *m_nameBuf;          // 0x880
};
s32 Func235DE0(const char *fmt, ...);

void *operator new(unsigned int n);
// CMenuSysscr32 (its unit starts after these functions): only the fields FreeBuf uses.
class CMenuSysscr32 {
public:
    CMenuSysscr32() throw();
    void FreeBuf();
    s16 m0;                   // 0x0
    s16 m2;                   // 0x2
    s32 m4;                   // 0x4
    u8 pad8[0x40];
    s32 m48;                  // 0x48
    s32 m4C;                  // 0x4C
    s32 m50;                  // 0x50
    s32 m54;                  // 0x54
    s32 m58;                  // 0x58
    u8 pad5C[0x8];
    void *m64;                // 0x64
    u8 pad68[0xC];
};
CMenuSysscr32 *NewMenuInputKanji2();
// @decl-end

CMenuInputKanji::CMenuInputKanji(s32 kind) {
    m_kind = kind;
}

CMenuInputKanji::~CMenuInputKanji() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuInputKanji", func_001A4FE0);

INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DDED0);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DDEE0);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DDF00);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DDF10);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DDF18);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DDF30);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DDF58);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DDF68);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DDF70);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DDF78);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DDF98);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DDFB8);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DDFE0);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DDFE8);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE018);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE040);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE070);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE088);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE090);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE0B0);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE0D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", jtbl_002DE100);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", jtbl_002DE130);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", jtbl_002DE160);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", jtbl_002DE180);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE198);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE238);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE3B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE3E0);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE3E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE3F0);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE3F8);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE400);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE420);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE448);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE478);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE480);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE488);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE4E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE548);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE5A8);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE5D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", jtbl_002DE600);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", jtbl_002DE630);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE660);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE680);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE6A8);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE6C8);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE6F0);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE720);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE758);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE788);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE7B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE7E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE818);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE848);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE878);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE8A8);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE8D8);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE908);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE938);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE968);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE9A0);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DE9D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEA00);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEA30);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEA60);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", jtbl_002DEA90);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEAC0);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEAF0);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEAF8);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEB00);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEB10);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEB20);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEB40);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEB60);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEBA0);
s32 CMenuInputKanji::SetNameBuf(char *buf) {
    s32 i;
    if (!buf) {
        return Func235DE0("*** NameBuf is NULL!\n");
    }
    m_nameBuf = buf;
    for (i = m_kind ? 4 : 0; i < 8; i++) {
        m_nameBuf[i * 2] = 0x81;
        m_nameBuf[i * 2 + 1] = 0x40;
    }
}

INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEBE0);
INCLUDE_ASM("asm/nonmatchings/CMenuInputKanji", func_001A50C8);

INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEDE8);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEE00);
INCLUDE_ASM("asm/nonmatchings/CMenuInputKanji", func_001A64D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEE30);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEE40);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEE50);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEE58);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEE60);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEE68);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEE70);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEE88);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEE90);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEE98);

INCLUDE_ASM("asm/nonmatchings/CMenuInputKanji", func_001A7038);

INCLUDE_ASM("asm/nonmatchings/CMenuInputKanji", func_001A7130);

INCLUDE_ASM("asm/nonmatchings/CMenuInputKanji", func_001A71F0);

INCLUDE_ASM("asm/nonmatchings/CMenuInputKanji", func_001A72D8);

void CMenuInputKanji::SetUnk4C(s32 v) {
    m_bg.m_unk0 = v;
}

INCLUDE_ASM("asm/nonmatchings/CMenuInputKanji", func_001A7308);

INCLUDE_ASM("asm/nonmatchings/CMenuInputKanji", func_001A73B0);

INCLUDE_ASM("asm/nonmatchings/CMenuInputKanji", Func1A7658__14CMenuSub1A7658);

CMenuSysscr32 *NewMenuInputKanji2() {
    return new CMenuSysscr32;
}

void CMenuSysscr32::FreeBuf() {
    if (m64) {
        operator delete(m64);
        m64 = 0;
    }
}
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEEA0);
