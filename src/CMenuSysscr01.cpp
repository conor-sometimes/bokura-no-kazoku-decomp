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

extern "C" void func_001AE488(void *p);
class CMenuSysscr00 {
public:
    static CMenuSysscr00 *Create();
};


// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr01.
class CMenuSysscr01 : public CMenuProcess {
public:
    CMenuSysscr01();
    virtual ~CMenuSysscr01();
    virtual void Update();
    virtual s32 Draw();

    CMenuSub1A7658 *m_unk58;  // 0x58
    class CStatusItem *m_win; // 0x5C
};

extern f32 D_002A6800[];
// VU0 float to 1.15 fixed point (sine-table index), as in CSwingBoneObj.
inline s32 Ftoi15(f32 x) {
    s32 i;
    asm volatile(
        "mfc1 %0, %1\n"
        "qmtc2.ni %0, $vf2\n"
        "vftoi15.x $vf2, $vf2\n"
        "qmfc2.ni %0, $vf2\n"
        : "=r"(i) : "f"(x));
    return i;
}
// Pulsing brightness for CMenuSysscr00::Update (sits after this unit's text).
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

CMenuSysscr01::CMenuSysscr01() {
    m_unk58 = 0;
}

CMenuSysscr01::~CMenuSysscr01() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

void CMenuSysscr01::Update() {
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
        m_win = D_002A5408->Find("sysscr01");
        if (!m_win) { Func235DE0("*** Can't Get %s Window.\n", "sysscr01"); return; }
        m_win->Func1A3378();
        k = new CMenuSub1A7658((CUnk1A4298 *)m_win);
        m_unk58 = k;
        if (!k) {
            Func235DE0("*** Can't Create SelectMenu\n");
            m_state = 5;
            m_unk4C = st;
            goto fin;
        }
        ((CMenuInputKanji *)k)->SetUnk4C(0x100);
        if (m_unk50 < 0) m_unk58->Func1A7308(0);
        else m_unk58->Func1A7308(m_unk50);
    case -0x92:
    case -0x9D:
        if (m_unk58->m_unk54 != 2) {
            m_unk4 = -0x9D;
            done = 1;
            goto loop;
        }
        m_state = 4;
        goto bb;
        for (;;) {
    case -0xAD:
    bb:
            if (m_unk58->m_unk54 != 3) break;
            m_state = 5;
            m_unk4C = m_unk58->m_unk58;
            goto fin;
        }
        m_unk4 = -0xAD;
        done = 1;
        goto loop;
    fin:
        m_unk4 = -0xB1;
        done = 1;
        goto loop;
    case -0xB1:
    default:
        goto out;
    }
out:
    if (m_unk58) func_001A73B0(m_unk58);
end:;
}

s32 CMenuSysscr01::Draw() {
    if (m_unk58 == 0) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

CMenuSysscr00 *CMenuSysscr00::Create() {
    CMenuSysscr00 *p = (CMenuSysscr00 *)operator new(0x60);
    func_001AE488(p);
    return p;
}

f32 Pulse1AE3F8(f32 *t) {
    u8 *tbl = (u8 *)D_002A6800;
    f32 s = *(f32 *)(tbl + ((Ftoi15(*t) << 1) & 0xFFFC)) * 0.75f;
    if (s < 0.0f) s = -s;
    s += 0.25f;
    f32 x = *t + 0.006f;
    *t = x;
    if (x >= 1.0f) *t = 0.0f;
    if (s > 1.0f) s = 1.0f;
    return s;
}
