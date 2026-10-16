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

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr10.
class CMenuSysscr10 : public CMenuProcess {
public:
    CMenuSysscr10();
    virtual ~CMenuSysscr10();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuInputKanji *m_unk58; // 0x58
    u8 m_name[0x20];          // 0x5C
};

//@sym __builtin_new 0x245648
class CMenuSysscr09 {
public:
    CMenuSysscr09() throw();

    u8 pad0[0x5C];
};

#include "libc.h"
#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
extern char D_002DF518[], D_002DF520[];
CMenuInputKanji *CreateStatusWinSub1A4F20(u32 kind);
inline void Strcat(char *d, const char *s) { strcpy(d + strlen(d), s); }
// @decl-end

CMenuSysscr10::CMenuSysscr10() {
    s32 i;
    for (i = 0; i < 8; i++) {
        m_name[i * 2] = 0x81;
        m_name[i * 2 + 1] = 0x40;
    }
}

CMenuSysscr10::~CMenuSysscr10() {
}

s32 CMenuSysscr10::Update() {
    s32 done = 0;
    s32 i, n;
    char buf[0x100];
    if (m_state == 6) {
        if (m_unk58) {
            m_unk58->Func1A4FE0();
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
    switch (m_unk4) {
    case -1:
        m_unk58 = 0;
        m_unk58 = CreateStatusWinSub1A4F20(1);
        if (!m_unk58) Func235DE0("*** Can't Create InputKanji.\n");
        strcpy((char *)m_name, D_002A5358->GetStr(0));
        n = 4 - strlen(D_002A5358->GetStr(0)) / 2;
        for (i = 0; i < n; i++) {
            Strcat((char *)m_name, D_002DF518);
        }
        m_unk58->Func1A5048((char *)m_name);
        do {
    case -0x90:
            if (m_unk58->Func29B570() != 4) { m_unk4 = -0x90; done = 1; goto loop; }
        } while (0);
        m_state = 4;
    case -0xB9:
        if (m_unk58->Func29B570() == 5) {
            if (m_unk58->Func29B578() != -1) {
                buf[0] = D_002DF520[0];
                for (i = 0; i < 4 && !(m_name[8 + i * 2] == 0x81 && m_name[9 + i * 2] == 0x40); i++) {
                    buf[i * 2] = m_name[8 + i * 2];
                    buf[i * 2 + 1] = m_name[9 + i * 2];
                }
                buf[i * 2] = 0;
                D_002A5358->SetStr(2, buf);
                m_unk4C = 0;
            }
            m_unk58->Func1A4FE0();
            m_unk58 = 0;
            m_state = 5;
            goto fin;
        }
        m_unk4 = -0xB9; done = 1; goto loop;
    fin:
        m_unk4 = -0xBD;
    case -0xBD:
        done = 1;
        goto loop;
    }
out:
    if (m_unk58) m_unk58->Func1A50C8();
end:;
}
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr10", D_002DF518);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr10", D_002DF520);

s32 CMenuSysscr10::Draw() {
    if (m_unk58) {
        return m_unk58->Func1A64D0();
    }
    Func225088();
    return Func2250C0();
}

CMenuSysscr09 *CreateCMenuSysscr09() {
    return new CMenuSysscr09;
}
