#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuAsksavequitWin {
public:
    CMenuAsksavequitWin(s32 mode) throw();
    void Func193358();
    int Func193D68();

    u8 pad0[0x58];
    s32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr05.
class CMenuSysscr05 : public CMenuProcess {
public:
    CMenuSysscr05();
    virtual ~CMenuSysscr05();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuAsksavequitWin *m_unk58; // 0x58
    u8 pad5C[0x4];
};

//@sym __builtin_new 0x245648
class CMenuSysscr04 {
public:
    CMenuSysscr04() throw();

    u8 pad0[0x60];
};
// @decl-end

CMenuSysscr05::CMenuSysscr05() {
    m_unk58 = 0;
}

CMenuSysscr05::~CMenuSysscr05() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

s32 CMenuSysscr05::Update() {
    s32 done;
    if (m_state == 6) {
        if (m_unk58) {
            delete m_unk58;
            m_unk58 = 0;
        }
        m_state = 5;
        m_unk4C = -1;
        goto end;
    }
    done = 0;
loop:
    if (done) goto out;
    {
        u32 fl = (u16)m_unk0;
        if ((fl >> 7) & 1) goto out;
    }
    switch (m_unk4) {
    case -1:
        m_unk58 = new CMenuAsksavequitWin(0);
        if (!m_unk58) {
            Func235DE0("*** Can't Create SelectName\n");
            m_state = 5;
            m_unk4C = -1;
            goto fin;
        }
    case -121:
    case -134:
        while (m_unk58->m_unk58 == 5) {
            m_state = 5;
            m_unk4C = m_unk58->m_unk5C;
            goto fin;
        }
        m_unk4 = -134; done = 1; goto loop;
    fin:
        m_unk4 = -138; done = 1; goto loop;
    case -138:
    default:
        goto out;
    }
out:
    if (m_unk58) m_unk58->Func193358();
end:;
}

s32 CMenuSysscr05::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func193D68();
}

CMenuSysscr04 *CreateCMenuSysscr04() {
    return new CMenuSysscr04;
}
