#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001ACCE8(void *p);
class CMenuSysscr05 {
public:
    static CMenuSysscr05 *Create();
};

#include "CMenuProcess.h"

// Vptr at 0; only the calls are needed here.
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

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr06.
class CMenuSysscr06 : public CMenuProcess {
public:
    CMenuSysscr06();
    virtual ~CMenuSysscr06();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuInputKanji *m_win;   // 0x58
    u8 m_name[0x12];          // 0x5C
};

#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
extern char D_002DF6A8[];
CMenuInputKanji *CreateStatusWinSub1A4F20(u32 kind);
// @decl-end

CMenuSysscr06::CMenuSysscr06() {
    s32 i;
    for (i = 0; i < 8; i++) {
        m_name[i * 2] = 0x81;
        m_name[i * 2 + 1] = 0x40;
    }
}

CMenuSysscr06::~CMenuSysscr06() {
}

s32 CMenuSysscr06::Update() {
    s32 done = 0;
    s32 i;
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
        m_win = CreateStatusWinSub1A4F20(0);
        if (!m_win) {
            Func235DE0("*** Can't Create InputKanji.\n");
            goto fin;
        }
        m_win->Func1A5048((char *)m_name);
        do {
    case -0x8A:
            if (m_win->Func29B570() != 4) { m_unk4 = -0x8A; done = 1; goto loop; }
        } while (0);
        m_state = 4;
    case -0xC6:
        if (m_win->Func29B570() == 5) {
            if (m_win->Func29B578() != -1) {
                buf[0] = D_002DF6A8[0];
                for (i = 0; i < 4 && !(m_name[i * 2] == 0x81 && m_name[i * 2 + 1] == 0x40); i++) {
                    buf[i * 2] = m_name[i * 2];
                    buf[i * 2 + 1] = m_name[i * 2 + 1];
                }
                buf[i * 2] = 0;
                D_002A5358->SetStr(0, buf);
                buf[0] = D_002DF6A8[0];
                for (i = 0; i < 4 && !(m_name[8 + i * 2] == 0x81 && m_name[9 + i * 2] == 0x40); i++) {
                    buf[i * 2] = m_name[8 + i * 2];
                    buf[i * 2 + 1] = m_name[9 + i * 2];
                }
                buf[i * 2] = 0;
                D_002A5358->SetStr(1, buf);
                m_unk4C = 0;
            }
            m_win->Func1A4FE0();
            m_win = 0;
            m_state = 5;
            goto fin;
        }
        m_unk4 = -0xC6; done = 1; goto loop;
    fin:
        m_unk4 = -0xCA;
    case -0xCA:
        done = 1;
        goto loop;
    }
out:
    if (m_win) m_win->Func1A50C8();
end:;
}
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr06", D_002DF6A8);

s32 CMenuSysscr06::Draw() {
    if (m_win) {
        return m_win->Func1A64D0();
    }
    Func225088();
    return Func2250C0();
}

CMenuSysscr05 *CMenuSysscr05::Create() {
    CMenuSysscr05 *p = (CMenuSysscr05 *)operator new(0x5C);
    func_001ACCE8(p);
    return p;
}
