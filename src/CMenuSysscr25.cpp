#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001AAB60(void *p);
class CMenuSysscr24 {
public:
    static CMenuSysscr24 *Create();
};

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

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr25.
class CMenuSysscr25 : public CMenuProcess {
public:
    CMenuSysscr25();
    virtual ~CMenuSysscr25();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuSub1A7658 *m_unk58;            // 0x58
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

void Func185E80(char *buf, s32 a);
void Func185F18(char *buf, s32 a, s32 b);
// @decl-end

CMenuSysscr25::CMenuSysscr25() {
    m_unk58 = 0;
}

CMenuSysscr25::~CMenuSysscr25() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

s32 CMenuSysscr25::Update() {
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
        m_win = D_002A5408->Find("sysscr25");
        if (!m_win) return Func235DE0("*** Can't Get %s Window.\n", "sysscr25");
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
            char s1[0x100], s2[0x100], s3[0x100];
            Func185F18(s1, D_002A5358->Func1091B0(4), 1);
            Func185E80(s2, D_002A5358->Func1091B0(4));
            sprintf(s3, "%s%s", (char *)D_002A26E4->Get1458F0(D_002A5358->Func1091B0(4), -1, -1, -1, -1, -1), D_002A5358->GetStr(3));
            {
                const char *fmt = m_win->GetUnkE4(6);
                sprintf(buf, fmt, s1, s2, D_002A5358->GetStr(0), s3);
            }
            m_win->SetText(6, buf);
        }
        do {
    case -0xAE:
    case -0xB9:
        if (m_unk58->m_unk54 != 2) {
            m_unk4 = -0xB9;
            done = 1;
            goto loop;
        }
        } while (0);
        m_state = 4;
        goto bb;
        for (;;) {
    case -0xC9:
    bb:
            if (m_unk58->m_unk54 != 3) break;
            m_state = 5;
            m_unk4C = m_unk58->m_unk58;
            goto fin;
        }
        m_unk4 = -0xC9;
        done = 1;
        goto loop;
    fin:
        m_unk4 = -0xCD;
        done = 1;
        goto loop;
    case -0xCD:
    default:
        goto out;
    }
out:
    if (m_unk58) func_001A73B0(m_unk58);
end:;
}

s32 CMenuSysscr25::Draw() {
    if (m_unk58 == 0) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

CMenuSysscr24 *CMenuSysscr24::Create() {
    CMenuSysscr24 *p = (CMenuSysscr24 *)operator new(0x7C);
    func_001AAB60(p);
    return p;
}
