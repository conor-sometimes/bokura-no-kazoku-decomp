#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

// Created by CreateStatusWinSub1A4F20 (CStatusWin.cpp); vtable 0x2C1B38. Only the calls are
// needed here, so no fields: the vptr is at 0.
class CMenuInputKanji {
public:
    virtual void Func1A4FE0();
    virtual s32 Func29B570();
    virtual s32 Func29B578();
    virtual void Func1A5048(char *buf);
    virtual void Func1A50C8();
    virtual s32 Func1A64D0();
    virtual s32 Func1A4F78();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr24.
class CMenuSysscr24 : public CMenuProcess {
public:
    CMenuSysscr24();
    virtual ~CMenuSysscr24();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuInputKanji *m_win;   // 0x58
    u8 m_name[0x12];          // 0x5C
};

//@sym __builtin_new 0x245648
//@sym __13CMenuSysscr23 0x1AB000
class CMenuSysscr23 {
public:
    CMenuSysscr23() throw();

    u8 pad0[0x5C];
};

#include "libc.h"
#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
extern char D_002DF388[], D_002DF390[];
CMenuInputKanji *CreateStatusWinSub1A4F20(u32 kind);
inline void Strcat(char *d, const char *s) { strcpy(d + strlen(d), s); }
// @decl-end

CMenuSysscr24::CMenuSysscr24() {
    s32 i;
    for (i = 0; i < 8; i++) {
        m_name[i * 2] = 0x81;
        m_name[i * 2 + 1] = 0x40;
    }
}

CMenuSysscr24::~CMenuSysscr24() {
}

s32 CMenuSysscr24::Update() {
    s32 done = 0;
    s32 i, n;
    char buf[0x100];
    if (m_state == 6) {
        if (m_win) {
            m_win->Func1A4FE0();
            m_win = 0;
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
    switch (m_unk4) {
    case -1:
        m_win = 0;
        m_win = CreateStatusWinSub1A4F20(2);
        if (!m_win) Func235DE0("*** Can't Create InputKanji.\n");
        strcpy((char *)m_name, D_002A5358->GetStr(0));
        n = 4 - strlen(D_002A5358->GetStr(0)) / 2;
        for (i = 0; i < n; i++) {
            Strcat((char *)m_name, D_002DF388);
        }
        m_win->Func1A5048((char *)m_name);
        for (;;) {
    case -0x91:
            if (m_win->Func29B570() == 4) goto n1;
            m_unk4 = -0x91; done = 1; goto loop;
        }
    n1:
        m_state = 4;
    case -0xBA:
        if (m_win->Func29B570() == 5) {
            if (m_win->Func29B578() != -1) {
                buf[0] = D_002DF390[0];
                for (i = 0; i < 4 && !(m_name[8 + i * 2] == 0x81 && m_name[9 + i * 2] == 0x40); i++) {
                    buf[i * 2] = m_name[8 + i * 2];
                    buf[i * 2 + 1] = m_name[9 + i * 2];
                }
                buf[i * 2] = 0;
                D_002A5358->SetStr(3, buf);
                m_unk4C = 0;
            }
            m_win->Func1A4FE0();
            m_win = 0;
            m_state = 5;
            goto fin;
        }
        m_unk4 = -0xBA; done = 1; goto loop;
    fin:
        m_unk4 = -0xBE;
    case -0xBE:
        done = 1;
        goto loop;
    }
out:
    if (m_win) m_win->Func1A50C8();
end:;
}
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr24", D_002DF388);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr24", D_002DF390);

s32 CMenuSysscr24::Draw() {
    if (m_win) {
        return m_win->Func1A64D0();
    }
    Func225088();
    return Func2250C0();
}

CMenuSysscr23 *CreateCMenuSysscr23() {
    return new CMenuSysscr23;
}
