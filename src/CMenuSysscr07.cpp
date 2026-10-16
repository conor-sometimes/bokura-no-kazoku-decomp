#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001AC820(void *p);
class CMenuSysscr06 {
public:
    static CMenuSysscr06 *Create();
};

extern char D_002DF658[];
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
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr07.
class CMenuSysscr07 : public CMenuProcess {
public:
    CMenuSysscr07();
    virtual ~CMenuSysscr07();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuSub1A7658 *m_unk58;              // 0x58
    class CStatusItem *m_win; // 0x5C
};
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

CMenuSysscr07::CMenuSysscr07() {
    m_unk58 = 0;
}

CMenuSysscr07::~CMenuSysscr07() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

s32 CMenuSysscr07::Update() {
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
        m_win = D_002A5408->Find("sysscr07");
        if (!m_win) return Func235DE0("*** Can't Get %s Window.\n", "sysscr07");
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
            sprintf(buf, fmt, D_002A5358->GetStr(0), D_002A5358->GetStr(1));
            m_win->SetText(6, buf);
        }
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
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr07", D_002DF658);

s32 CMenuSysscr07::Draw() {
    if (m_unk58 == 0) {
        Func235DE0(D_002DF658);
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

CMenuSysscr06 *CMenuSysscr06::Create() {
    CMenuSysscr06 *p = (CMenuSysscr06 *)operator new(0x7C);
    func_001AC820(p);
    return p;
}
