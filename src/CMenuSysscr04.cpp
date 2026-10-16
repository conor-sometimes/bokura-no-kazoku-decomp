#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuSub1A7658 {
public:
    CMenuSub1A7658(class CUnk1A4298 *w);
    int Func1A7658();
    void Func1A7308(s32 v);

    u8 pad0[0x54];
    s32 m_unk54;              // 0x54
    s32 m_unk58;              // 0x58
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr04.
class CMenuSysscr04 : public CMenuProcess {
public:
    CMenuSysscr04();
    virtual ~CMenuSysscr04();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuSub1A7658 *m_unk58; // 0x58
    class CStatusItem *m_win; // 0x5C
};

//@sym __13CMenuSysscr03 0x1AD2A8
//@sym __builtin_new 0x245648
class CMenuSysscr03 {
public:
    CMenuSysscr03() throw();

    u8 pad0[0x60];
};

class CStatusItem {
public:
    void Func1A3378();
};
class CStatusWinSub1A0A10 {
public:
    CStatusItem *Find(const char *name);
};
extern CStatusWinSub1A0A10 *D_002A5408;
extern "C" void func_001A73B0(CMenuSub1A7658 *k);
// @decl-end

CMenuSysscr04::CMenuSysscr04() {
    m_unk58 = 0;
}

CMenuSysscr04::~CMenuSysscr04() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

s32 CMenuSysscr04::Update() {
    s32 done = 0;
    CMenuSub1A7658 *k;
    s32 st;
    if (m_state == 6) {
        if (m_unk58) {
            delete m_unk58;
            m_unk58 = 0;
        }
        m_state = 5;
        m_unk4C = -1;
        goto end;
    }
loop:
    if (done) goto out;
    {
        u32 fl = (u16)m_unk0;
        if ((fl >> 7) & 1) goto out;
    }
    st = m_unk4;
    switch (st) {
    case -1:
        m_win = D_002A5408->Find("sysscr04");
        if (!m_win) return Func235DE0("*** Can't Get %s Window.\n", "sysscr04");
        m_win->Func1A3378();
        k = new CMenuSub1A7658((CUnk1A4298 *)m_win);
        m_unk58 = k;
        if (!k) {
            Func235DE0("*** Can't Create SelectMenu\n");
            m_state = 5;
            m_unk4C = st;
            goto fin;
        }
        if (m_unk50 < 0) k->Func1A7308(0);
        else k->Func1A7308(m_unk50);
    case -0x92:
    case -0x9D:
        if (m_unk58->m_unk54 != 2) {
            m_unk4 = -0x9D;
            done = 1;
            goto loop;
        }
        m_state = 4;
        goto bb;
        for (;;) {
    case -0xAD:
    bb:
            if (m_unk58->m_unk54 != 3) break;
            m_state = 5;
            m_unk4C = m_unk58->m_unk58;
            goto fin;
        }
        m_unk4 = -0xAD;
        done = 1;
        goto loop;
    fin:
        m_unk4 = -0xB1;
        done = 1;
        goto loop;
    case -0xB1:
    default:
        goto out;
    }
out:
    if (m_unk58) func_001A73B0(m_unk58);
end:;
}

s32 CMenuSysscr04::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

CMenuSysscr03 *CreateCMenuSysscr03() {
    return new CMenuSysscr03;
}
