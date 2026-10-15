#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuSub1A7658 {
public:
    int Func1A7658();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuNosave.
class CMenuNosave : public CMenuProcess {
public:
    CMenuNosave();
    virtual ~CMenuNosave();
    virtual s32 Update();
    virtual s32 Draw();

    union {
        CMenuSub1A7658 *m_unk58;  // 0x58
        class CMenuInputKanji *m_kanji;
    };
    class CStatusItem *m_win; // 0x5C
};

//@sym __builtin_new 0x245648
class CMenuMemorial {
public:
    CMenuMemorial() throw();

    u8 pad0[0x5C];
};
// @decl-end

CMenuNosave::CMenuNosave() {
    m_unk58 = 0;
}

CMenuNosave::~CMenuNosave() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

#if 0 // DIFF 56, same length (g1): goto-loop recipe from docs/lessons.md; left: s1/s2 swap (this vs the state), done in a1 vs a0, the m_state==6 store order, and the -0xB0 wait's then-block placement (retail before the test)
s32 CMenuNosave::Update() {
    s32 done = 0;
    CMenuInputKanji *k;
    s32 st;
    if (m_state == 6) {
        if (m_kanji) {
            delete m_kanji;
            m_kanji = 0;
        }
        m_unk4C = -1;
        m_state = 5;
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
    case -1: {
        m_win = D_002A5408->Func1A0CF0("nosave");
        if (!m_win) return Func235DE0("*** Can't Get %s Window.\n", "nosave");
        m_win->Func1A3378();
        k = (CMenuInputKanji *)operator new(0x5C);
        func_001A72D8(k, m_win);
        m_kanji = k;
        if (!k) {
            Func235DE0("*** Can't Create SelectMenu\n");
            m_state = 5;
            m_unk4C = st;
            m_unk4 = -0xB4;
            done = 1;
            goto loop;
        }
        k->SetUnk4C(0x1110);
        if (m_unk50 < 0) func_001A7308(m_kanji, 0);
        else func_001A7308(m_kanji, m_unk50);
    }
    case -0xA0:
    case -0x95:
        if (m_kanji->m54 != 2) {
            m_unk4 = -0xA0;
            done = 1;
            goto loop;
        }
        m_state = 4;
        goto wait_b0;
    case -0xB0:
    wait_b0:
        if (m_kanji->m54 == 3) {
            m_state = 5;
            m_unk4C = m_kanji->m58;
            m_unk4 = -0xB4;
            done = 1;
            goto loop;
        }
        m_unk4 = -0xB0;
        done = 1;
        goto loop;
    case -0xB4:
    default:
        goto out;
    }
out:
    if (m_kanji) func_001A73B0(m_kanji);
end:;
}
#endif
INCLUDE_ASM("asm/nonmatchings/CMenuNosave", Update__11CMenuNosave);

s32 CMenuNosave::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

CMenuMemorial *CreateCMenuMemorial() {
    return new CMenuMemorial;
}
