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


// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr22.
class CMenuSysscr22 : public CMenuProcess {
public:
    CMenuSysscr22();
    virtual ~CMenuSysscr22();
    virtual void Update();
    virtual s32 Draw();

    CMenuSub1A7658 *m_unk58; // 0x58
    class CStatusItem *m_win; // 0x5C
};

//@sym __builtin_new 0x245648
class CMenuSysscr11 {
public:
    CMenuSysscr11() throw();

    u8 pad0[0x60];
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

#include "IGameDBMgr.h"
class CFontMgr {
public:
    const char *GetText(s32 id);
    void SetUnk0(s32 v) { m_unk0 = v; }
    s32 m_unk0;
};
class CEFontWork : public CFontMgr {
public:
    CEFontWork();
    u8 pad4[0x84];
};
// @decl-end

CMenuSysscr22::CMenuSysscr22() {
    m_unk58 = 0;
}

CMenuSysscr22::~CMenuSysscr22() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

void CMenuSysscr22::Update() {
    char buf[0x100];
    CEFontWork font;
    s32 done;
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
    done = 0;
loop:
    if (done) goto out;
    {
        u32 fl = (u16)m_unk0;
        if ((fl >> 7) & 1) goto out;
    }
    st = m_unk4;
    switch (st) {
    case -1:
        m_win = D_002A5408->Find("sysscr22");
        if (!m_win) { Func235DE0("*** Can't Get %s Window.\n", "sysscr22"); return; }
        m_win->Func1A3378();
        font.SetUnk0(0);
        {
            char *name = D_002A2988->GetCharaName(D_002A5358->Func1091B0(4));
            const char *fmt = m_win->GetUnkE4(7);
            const char *s;
            if (!D_002A26E4->Func1091B0(D_002A5358->Func1091B0(4) + 0x3A)) s = font.GetText(0x3D);
            else s = font.GetText(0x3E);
            sprintf(buf, fmt, name, s);
            m_win->SetText(7, buf);
        }
        k = new CMenuSub1A7658((CUnk1A4298 *)m_win);
        m_unk58 = k;
        if (!k) {
            Func235DE0("*** Can't Create SelectMenu\n");
            m_state = 5;
            m_unk4C = -1;
            goto fin;
        }
        ((CMenuInputKanji *)k)->SetUnk4C(0x10);
        if (m_unk50 < 0) m_unk58->Func1A7308(0);
        else m_unk58->Func1A7308(m_unk50);
    case -0xAD:
    case -0xB8:
        if (m_unk58->m_unk54 != 2) {
            m_unk4 = -0xB8;
            done = 1;
            goto loop;
        }
        m_state = 4;
        goto bb;
        for (;;) {
    case -0xC8:
    bb:
            if (m_unk58->m_unk54 != 3) break;
            m_state = 5;
            m_unk4C = m_unk58->m_unk58;
            goto fin;
        }
        m_unk4 = -0xC8;
        done = 1;
        goto loop;
    fin:
        m_unk4 = -0xCC;
        done = 1;
        goto loop;
    case -0xCC:
    default:
        goto out;
    }
out:
    if (m_unk58) func_001A73B0(m_unk58);
end:;
}

s32 CMenuSysscr22::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

CMenuSysscr11 *CreateCMenuSysscr11() {
    return new CMenuSysscr11;
}
