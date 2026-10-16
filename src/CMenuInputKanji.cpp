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
s32 Func235DE0(const char *fmt, ...) throw();

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
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
// The window item (CStatusWin.cpp); CUnk1A4298 above is the same object.
class CVec4;
class CStatusItem {
public:
    void GetMappedUnkC0(f32 *x, f32 *y, s32 n);
    int Select(s32 n);
    void SetMappedColor(s32 n, const CVec4 *v);
    void Func1A3628();
    void Start();
    void Func1A40C8();
    u8 pad0[0x20];
    s32 m_state;              // 0x20
    u8 pad24[0x10];
    f32 m_unk34;              // 0x34
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
    void Update1A73B0();

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
    virtual int F7(u32 *a, u32 *b, u32 *c);
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

INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEEA0);
// (lane lb) the kana and romaji tables and IMenuInputKanji's RTTI name follow this object's own RTTI name
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEEB8);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DEF20);
INCLUDE_RODATA("asm/nonmatchings/CMenuInputKanji", D_002DF0A0);
