#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

extern "C" void func_001AB280(void *p);
class CMenuSysscr22 {
public:
    static CMenuSysscr22 *Create();
};

class CMenuAsksavequitWin {
public:
    CMenuAsksavequitWin(s32 mode) throw();
    void Func193358();
    int Func193D68();

    u8 pad0[0x58];
    s32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr23.
class CMenuSysscr23 : public CMenuProcess {
public:
    CMenuSysscr23();
    virtual ~CMenuSysscr23();
    virtual void Update();
    virtual s32 Draw();

    CMenuAsksavequitWin *m_unk58; // 0x58
};
//@sym __19CMenuAsksavequitWini 0x1932B8
// @decl-end

CMenuSysscr23::CMenuSysscr23() {
    m_unk58 = 0;
}

CMenuSysscr23::~CMenuSysscr23() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

void CMenuSysscr23::Update() {
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
        m_unk58 = new CMenuAsksavequitWin(2);
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

s32 CMenuSysscr23::Draw() {
    if (m_unk58 == 0) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func193D68();
}

CMenuSysscr22 *CMenuSysscr22::Create() {
    CMenuSysscr22 *p = (CMenuSysscr22 *)operator new(0x60);
    func_001AB280(p);
    return p;
}
