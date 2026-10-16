#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"
#include "CBgWork.h"
#include "CCommandBase.h"

void *operator new(unsigned int n);
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr32.
// FreeBuf and the factory come first (lane lb moved them here from CMenuInputKanji.cpp).
class CMenuSysscr32 : public CMenuProcess {
public:
    CMenuSysscr32() throw();      // nothrow for NewMenuInputKanji2 (as the old view class had it)
    virtual ~CMenuSysscr32();
    virtual void Update();
    virtual s32 Draw();
    void FreeBuf() throw();      // nothrow in retail (0x1A7818 needs it)

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
#include "CChrBodyWin.h"
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

class CSndIf {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual int V7(s32 *a, s32 *b, s32 *c);
};
class CSePlayer;
class CCommandIncDec : public CCommandBase {
public:
    virtual s32 Update();
    virtual s32 Draw();
    u8 pad4EC[0x540 - 0x4EC];
};
void FreeBuf_dummy();
class CCmdV { public: u8 pad[0x4E8]; virtual void Update(); };

// From CMenuInputKanji.cpp (lane lb moved its functions 0x1A7038.. here: their literals are this unit's)
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
CMenuSysscr32 *NewMenuInputKanji2();

class CUnk1A4298 {
public:
    int Func1A4298();
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

void CMenuSub1A7658::Update1A73B0() {
    u32 b[3];
    s32 done;
    D_002A5468->F7(&b[0], &b[1], &b[2]);
    done = 0;
loop:
    if (done) goto out;
    {
        u32 fl = m_sm.m_flags;
        if ((fl >> 7) & 1) goto out;
    }
    switch (m_sm.m_state) {
    case -1:
        if (((CStatusItem *)m_unk48)->m_mapCount < 2) D_002A5538->SetUnkE0(0);
        Func1A7308(m_unk50);
        ((CStatusItem *)m_unk48)->Func1A3628();
        do {
    case -0xE0:
        if (((CStatusItem *)m_unk48)->m_state != 2) {
            m_sm.m_state = -0xE0; done = 1; goto loop;
        }
        } while (0);
        do {
        m_sm.m_state = -0xE5; done = 1; goto loop;
    case -0xE5:
    case -0x105:
        if (b[2] & 0x1000) {
            Func1A7130();
        } else if (b[2] & 0x4000) {
            Func1A71F0();
        } else if (b[0] & 0x20) {
            if ((m_unk4C & 0x1000) && m_unk50 == 1) D_002A5468->Play(2);
            else D_002A5468->Play(1);
            m_unk58 = m_unk50;
            goto sel;
        } else if (b[0] & 0x40) {
            if (!(m_unk4C & 0x10)) {
                D_002A5468->Play(2);
                m_unk58 = -1;
                goto sel;
            }
        }
        m_sm.m_state = -0x105; done = 1; goto loop;
        } while (0);
    sel:
        m_unk54 = 2;
        ((CStatusItem *)m_unk48)->Start();
        do {
    case -0x116:
        if (((CStatusItem *)m_unk48)->m_state != 0) {
            m_sm.m_state = -0x116; done = 1; goto loop;
        }
        } while (0);
        m_unk54 = 3;
        m_sm.m_state = -0x11A;
    case -0x11A:
        done = 1; goto loop;
    }
out:
    ((CStatusItem *)m_unk48)->Func1A40C8();
    D_002A5538->SetUnk4C(((CStatusItem *)m_unk48)->m_unk34);
    D_002A5538->Update1B6570();
}

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

void CMenuSysscr32::FreeBuf() throw() {
    if (m_cmd) {
        operator delete(m_cmd);
        m_cmd = 0;
    }
}

INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr32", D_002DF0B8);
CMenuSysscr32::CMenuSysscr32() throw() {
    m_cmd = 0;
    m_unk68 = 0;
    m_unk6C = 0;
    m_unk70 = 0;
}

CMenuSysscr32::~CMenuSysscr32() {
    FreeBuf();
}

void CMenuSysscr32::Update() {
    s32 done;
    s32 a, b, c;
    char buf[0x100];
    if (m_state == 6) {
        FreeBuf();
        m_state = 5;
        m_unk4C = -1;
        goto end;
    }
    D_002A5468->F7((u32 *)&a, (u32 *)&b, (u32 *)&c);
    done = 0;
loop:
    if (done) goto out;
    {
        u32 fl = (u16)m_unk0;
        if ((fl >> 7) & 1) goto out;
    }
    switch (m_unk4) {
    case -1:
        m_state = 0;
        m_cmd = new CCommandIncDec;
        m_cmd->Select198290(-1);
        m_state = 3;
        m_cmd->Open();
    case -0xCA:
        if (*(s32 *)((u8 *)m_cmd + 0x4C) != 3) {
            m_unk4 = -0xCA; done = 1; goto loop;
        }
        m_unk4 = -0xCF; done = 1; goto loop;
    case -0xCF:
    case -0xD5:
        if (*(s32 *)((u8 *)m_cmd + 0x4C) != 4) {
            m_unk4 = -0xD5; done = 1; goto loop;
        }
        do {
    case -0xE2:
        if (*(s32 *)((u8 *)m_cmd + 0x4C) != 0) {
            m_unk4 = -0xE2; done = 1; goto loop;
        }
        } while (0);
        m_state = 5;
        m_unk4 = -0xE6;
    case -0xE6:
        done = 1; goto loop;
    }
out:
    if ((u32)(m_state - 3) < 2) ((CCmdV *)m_cmd)->Update();
end:;
}

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
