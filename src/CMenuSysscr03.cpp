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


// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr03.
class CMenuSysscr03 : public CMenuProcess {
public:
    CMenuSysscr03();
    virtual ~CMenuSysscr03();
    virtual void Update();
    virtual s32 Draw();
    void Init1AD668();        // CMenuSysscr02's constructor (that unit's name for it)

    CMenuSub1A7658 *m_unk58; // 0x58
    class CStatusItem *m_win; // 0x5C
};

void *operator new(unsigned int n);
CMenuSysscr03 *NewCMenuSysscr03();
class CStatusItem {
public:
    void Func1A3378();
    void SetUnkF0(s32 i, s32 v);
    const char *GetUnkE4(s32 k);
    void SetText(s32 k, const char *s);
};
class CStatusWinSub1A0A10 {
public:
    CStatusItem *Find(const char *name);
};
class CMenuInputKanji {
public:
    void SetUnk4C(s32 v);
};
#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern CStatusWinSub1A0A10 *D_002A5408;
extern "C" void func_001A73B0(void *p);
// @decl-end

CMenuSysscr03::CMenuSysscr03() {
    m_unk58 = 0;
}

CMenuSysscr03::~CMenuSysscr03() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

void CMenuSysscr03::Update() {
    s32 done = 0;
    CMenuSub1A7658 *k;
    s32 st;
    char buf[0x100];
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
        m_win = D_002A5408->Find("sysscr03");
        if (!m_win) { Func235DE0("*** Can't Get %s Window.\n", "sysscr03"); return; }
        m_win->Func1A3378();
        k = new CMenuSub1A7658((CUnk1A4298 *)m_win);
        m_unk58 = k;
        if (!k) {
            Func235DE0("*** Can't Create SelectMenu\n");
            m_state = 5;
            m_unk4C = st;
            goto fin;
        }
        ((CMenuInputKanji *)k)->SetUnk4C(0x1000);
        if (m_unk50 < 0) m_unk58->Func1A7308(0);
        else m_unk58->Func1A7308(m_unk50);
        {
            const char *fmt = m_win->GetUnkE4(6);
            sprintf(buf, fmt, D_002A5358->GetStr(0), D_002A5358->GetStr(1), D_002A5358->GetStr(2));
            m_win->SetText(6, buf);
        }
        for (;;) {
    case -0xA0:
    case -0xAB:
            if (m_unk58->m_unk54 != 2) {
                m_unk4 = -0xAB;
                done = 1;
                goto loop;
            }
            goto n1;
        }
    n1:
        m_state = 4;
        goto bb;
        for (;;) {
    case -0xBB:
    bb:
            if (m_unk58->m_unk54 != 3) break;
            m_state = 5;
            m_unk4C = m_unk58->m_unk58;
            goto fin;
        }
        m_unk4 = -0xBB;
        done = 1;
        goto loop;
    fin:
        m_unk4 = -0xBF;
        done = 1;
        goto loop;
    case -0xBF:
    default:
        goto out;
    }
out:
    if (m_unk58) func_001A73B0(m_unk58);
end:;
}

s32 CMenuSysscr03::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

// Creates the CMenuSysscr02 screen.
CMenuSysscr03 *NewCMenuSysscr03() {
    CMenuSysscr03 *p = (CMenuSysscr03 *)operator new(0xD8);
    p->Init1AD668();
    return p;
}
