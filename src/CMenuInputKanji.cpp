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
// Vtable 0x2C1B38: slot 0 is Func1A4FE0, the destructor is slot 6 (slot order comes from
// IMenuInputKanji). Func29B570 (inline in retail, never defined here) is declared first so it is
// the key method: Func1A4FE0 can be C++ while the vtable stays asm.
class CMenuInputKanji : public IMenuInputKanji {
public:
    CMenuInputKanji(s32 kind);
    virtual s32 Func29B570();
    virtual s32 Func1A4FE0();
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
    u8 pad60[0x1C];
    void *m_unk7C;            // 0x7C
    u8 pad80[0x800];
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

class CUnk1A4298 {
public:
    int Func1A4298();
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
void *Func237570(int size);
void Func237A88(void *p, int n);
void *Func237C30(void *p);
void Func238158(void *p, int v);
void Func225088();
int Func2250C0();
void Func225240(int v);
class CMenuMgrSub1B6418 {
public:
    void SetUnk0And20(f32 x, f32 y);
    void Move1B6488(f32 x, f32 y);
    void SetUnkE0(s32 v);
};
extern CMenuMgrSub1B6418 *D_002A5538;
// The window item (CStatusWin.cpp); CUnk1A4298 above is the same object.
class CVec4;
class CStatusItem {
public:
    void GetMappedUnkC0(f32 *x, f32 *y, s32 n);
    int Select(s32 n);
    void SetMappedColor(s32 n, const CVec4 *v);
    u8 pad0[0x38];
    s32 m_mapCount;           // 0x38
};
extern const char D_002DF0B8[];
extern "C" int func_001B66E8(void *p);
class CMenuSub1A7658 {
public:
    CMenuSub1A7658(CUnk1A4298 *item);
    int Func1A7658();
    void Func1A7038();
    void Func1A7308(s32 n);
    void Func1A7130();
    void Func1A71F0();

    CStateMachine m_sm;       // 0x0
    CUnk1A4298 *m_unk48;      // 0x48
    s32 m_unk4C;              // 0x4C
    s32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    s32 m_unk58;              // 0x58
};

extern void (*D_002B91B0)(void *p);

//@sym Func1A7038__14CMenuSub1A7658 0x1A7038

#include "CFlagWork.h"
extern CFlagWork *D_002A4B60;
// Sound player (global D_002A5468, as in CMenuAsksavequit.cpp); slot 14 plays a system sound.
class CSePlayer {
public:
    virtual ~CSePlayer();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual void F7();
    virtual void F8();
    virtual void F9();
    virtual void F10();
    virtual void F11();
    virtual void F12();
    virtual void F13();
    virtual void Play(s32 id);
};
extern CSePlayer *D_002A5468;
// @decl-end

CMenuInputKanji::CMenuInputKanji(s32 kind) {
    m_kind = kind;
}

CMenuInputKanji::~CMenuInputKanji() {
}

s32 CMenuInputKanji::Func1A4FE0() {
    func_00245818(&m_bg, 1);
    if (m_unk7C) D_002B91B0(m_unk7C);
    delete this;
}

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

void CMenuSub1A7658::Func1A7038() {
    f32 sel[4];
    f32 col[4];
    s32 i, j, n;
    for (i = 0; i < 4; i++) {
        sel[i] = D_002A4B60->Func1091B0(i + 0xB);
        col[i] = D_002A4B60->Func1091B0(i + 0xF);
    }
    n = ((CStatusItem *)m_unk48)->m_mapCount;
    ((CStatusItem *)m_unk48)->Select(m_unk50);
    for (j = 0; j < n; j++) {
        if (j == m_unk50) ((CStatusItem *)m_unk48)->SetMappedColor(j, (CVec4 *)sel);
        else ((CStatusItem *)m_unk48)->SetMappedColor(j, (CVec4 *)col);
    }
}

void CMenuSub1A7658::Func1A7130() {
    s32 n = ((CStatusItem *)m_unk48)->m_mapCount;
    s32 old = m_unk50;
    f32 x, y;
    if (n < 2) return;
    m_unk50 = old - 1;
    if (m_unk50 < 0) {
        if (n == 2) m_unk50 = 0;
        else m_unk50 = n - 1;
    }
    if (m_unk50 != old) {
        Func1A7038();
        ((CStatusItem *)m_unk48)->GetMappedUnkC0(&x, &y, m_unk50);
        D_002A5538->Move1B6488(x, y);
        D_002A5468->Play(0);
    }
}

void CMenuSub1A7658::Func1A71F0() {
    s32 n = ((CStatusItem *)m_unk48)->m_mapCount;
    s32 old = m_unk50;
    f32 x, y;
    if (n < 2) return;
    m_unk50 = old + 1;
    if (old + 1 >= n) {
        if (n == 2) m_unk50 = 1;
        else {
            m_unk50 = 0;
            D_002A5468->Play(0);
        }
    }
    if (m_unk50 != old) {
        Func1A7038();
        ((CStatusItem *)m_unk48)->GetMappedUnkC0(&x, &y, m_unk50);
        D_002A5538->Move1B6488(x, y);
        D_002A5468->Play(0);
    }
}

CMenuSub1A7658::CMenuSub1A7658(CUnk1A4298 *item) {
    m_unk48 = item;
    m_unk4C = 0;
    m_unk50 = 0;
    m_unk54 = 0;
    m_unk58 = -1;
}

void CMenuInputKanji::SetUnk4C(s32 v) {
    m_bg.m_unk0 = v;
}

void CMenuSub1A7658::Func1A7308(s32 n) {
    f32 x, y;
    s32 cnt = ((CStatusItem *)m_unk48)->m_mapCount;
    if (n < 0 || cnt - 1 < n) {
        Func235DE0(D_002DF0B8, n);
        n = 0;
    }
    Func1A7038();
    ((CStatusItem *)m_unk48)->GetMappedUnkC0(&x, &y, n);
    D_002A5538->SetUnk0And20(x, y);
    D_002A5538->SetUnkE0(1);
    m_unk50 = n;
}

INCLUDE_ASM("asm/nonmatchings/CMenuInputKanji", func_001A73B0);

int CMenuSub1A7658::Func1A7658() {
    u8 *p = (u8 *)Func237570(0x60);
    Func237A88(p, 6);
    Func238158(Func237C30(p + 0x50), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unk48->Func1A4298());
    ((CUnk237E90 *)(p + 0x40))->Func237E90(func_001B66E8(D_002A5538));
    Func225088();
    Func225240((int)p);
    return Func2250C0();
}

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
