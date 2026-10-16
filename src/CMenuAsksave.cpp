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


// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuAsksave.
class CMenuAsksave : public CMenuProcess {
public:
    CMenuAsksave();
    virtual ~CMenuAsksave();
    virtual s32 Update();
    virtual s32 Draw();
    void Init192D38();        // CMenuAsksavequit's constructor (that unit's name for it)

    CMenuSub1A7658 *m_unk58;  // 0x58
    class CStatusItem *m_win; // 0x5C
};

void *operator new(unsigned int n);
CMenuAsksave *NewCMenuAsksave();
class CStatusItem {
public:
    void Func1A3378();
    void SetUnkF0(s32 i, s32 v);
};
class CStatusWinSub1A0A10 {
public:
    CStatusItem *Find(const char *name);
};
class CMenuInputKanji {
public:
    void SetUnk4C(s32 v);
};
extern CStatusWinSub1A0A10 *D_002A5408;
extern "C" void func_001A73B0(void *p);
// @decl-end

CMenuAsksave::CMenuAsksave() {
    m_unk58 = 0;
}

CMenuAsksave::~CMenuAsksave() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

s32 CMenuAsksave::Update() {
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
        m_win = D_002A5408->Find("savequit");
        if (!m_win) return Func235DE0("*** Can't Get %s Window.\n", "savequit");
        m_win->Func1A3378();
        m_win->SetUnkF0(0x5, 0x1);
        m_win->SetUnkF0(0x6, 0);
        k = new CMenuSub1A7658((CUnk1A4298 *)m_win);
        m_unk58 = k;
        if (!k) {
            Func235DE0("*** Can't Create SelectMenu\n");
            m_state = 5;
            m_unk4C = st;
            goto fin;
        }
        ((CMenuInputKanji *)k)->SetUnk4C(0x1100);
        if (m_unk50 < 0) m_unk58->Func1A7308(0);
        else m_unk58->Func1A7308(m_unk50);
    case -0x9F:
    case -0xAA:
        if (m_unk58->m_unk54 != 2) {
            m_unk4 = -0xAA;
            done = 1;
            goto loop;
        }
        m_state = 4;
        goto bb;
        for (;;) {
    case -0xBA:
    bb:
            if (m_unk58->m_unk54 != 3) break;
            m_state = 5;
            m_unk4C = m_unk58->m_unk58;
            goto fin;
        }
        m_unk4 = -0xBA;
        done = 1;
        goto loop;
    fin:
        m_unk4 = -0xBE;
        done = 1;
        goto loop;
    case -0xBE:
    default:
        goto out;
    }
out:
    if (m_unk58) func_001A73B0(m_unk58);
end:;
}

s32 CMenuAsksave::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

// Creates the CMenuAsksavequit screen.
CMenuAsksave *NewCMenuAsksave() {
    CMenuAsksave *p = (CMenuAsksave *)operator new(0x60);
    p->Init192D38();
    return p;
}
