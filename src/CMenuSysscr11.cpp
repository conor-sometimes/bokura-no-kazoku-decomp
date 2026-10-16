#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuSub1A7658 {
public:
    int Func1A7658();
    void Func1A7308(s32 v);
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr11.
class CMenuSysscr11 : public CMenuProcess {
public:
    CMenuSysscr11();
    virtual ~CMenuSysscr11();
    virtual s32 Update();
    virtual s32 Draw();

    union {
        CMenuSub1A7658 *m_unk58;  // 0x58
        class CMenuInputKanji *m_kanji;
    };
    class CStatusItem *m_win; // 0x5C
};

//@sym __builtin_new 0x245648
class CMenuSysscr10 {
public:
    CMenuSysscr10() throw();

    u8 pad0[0x7C];
};

class CStatusItem {
public:
    void Func1A3378();
};
class CStatusWin {
public:
    CStatusItem *Func1A0CF0(const char *name);
};
extern CStatusWin *D_002A5408;
class CMenuInputKanji {
public:
    void SetUnk4C(s32 v);
    u8 pad0[0x54];
    s32 m54;                  // 0x54
    s32 m58;                  // 0x58
};
extern "C" void func_001A72D8(CMenuInputKanji *k, CStatusItem *win);
extern "C" void func_001A73B0(CMenuInputKanji *k);
extern "C" const char *func_001A36B0(CStatusItem *win, s32 k);
class CMenuRecordWin {
public:
    void Func1A3740(s32 v, const char *s);
};
class CFlagWork {
public:
    const char *GetStr(s32 id);
};
extern CFlagWork *D_002A5358;
extern "C" int sprintf(char *buf, const char *fmt, ...);
void *operator new(unsigned int n);
// @decl-end

CMenuSysscr11::CMenuSysscr11() {
    m_unk58 = 0;
}

CMenuSysscr11::~CMenuSysscr11() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

s32 CMenuSysscr11::Update() {
    s32 done = 0;
    CMenuInputKanji *k;
    s32 st;
    char buf[0x100];
    if (m_state == 6) {
        if (m_kanji) {
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
        m_win = D_002A5408->Func1A0CF0("sysscr11");
        if (!m_win) return Func235DE0("*** Can't Get %s Window.\n", "sysscr11");
        m_win->Func1A3378();
        k = (CMenuInputKanji *)operator new(0x5C);
        func_001A72D8(k, m_win);
        m_kanji = k;
        if (!k) {
            Func235DE0("*** Can't Create SelectMenu\n");
            m_state = 5;
            m_unk4C = st;
            goto fin;
        }
        k->SetUnk4C(0x1000);
        if (m_unk50 < 0) m_unk58->Func1A7308(0);
        else m_unk58->Func1A7308(m_unk50);
        {
            const char *fmt = func_001A36B0(m_win, 6);
            sprintf(buf, fmt, D_002A5358->GetStr(0), D_002A5358->GetStr(2));
            ((CMenuRecordWin *)m_win)->Func1A3740(6, buf);
        }
    case -0xA0:
    case -0xAB:
        if (m_kanji->m54 != 2) {
            m_unk4 = -0xAB;
            done = 1;
            goto loop;
        }
        m_state = 4;
        goto bb;
        for (;;) {
    case -0xBB:
    bb:
            if (m_kanji->m54 != 3) break;
            m_state = 5;
            m_unk4C = m_kanji->m58;
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
    if (m_kanji) func_001A73B0(m_kanji);
end:;
}

s32 CMenuSysscr11::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

CMenuSysscr10 *CreateCMenuSysscr10() {
    return new CMenuSysscr10;
}
