#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CStatusItem;
class CUnk1A4298 {
public:
    int Func1A4298();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr00.
class CMenuSysscr00 : public CMenuProcess {
public:
    CMenuSysscr00();
    virtual ~CMenuSysscr00();
    virtual void Update();
    virtual s32 Draw();
    void Init1AE800();
    CStatusItem *Item() { return (CStatusItem *)m_unk58; }        // CMenuSave's constructor (that unit's name for it)

    CUnk1A4298 *m_unk58;    // 0x58
    f32 m_unk5C;              // 0x5C
};

void *operator new(unsigned int n);
CMenuSysscr00 *NewCMenuSysscr00();

class CMenuTutorSelectedSub182108 {
public:
    void Func1829E8(s32 v);
    void GetCursorPos(f32 *x, f32 *y);
};
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
// The CMenuSave screen (0x7DC0 bytes, created by NewCMenuSysscr00); its code starts here.
class CMenuSave {
public:
    void Func1AE7A8();
    u8 pad0[0x64];
    s32 m64;                  // 0x64
    u8 pad68[0x58];
    u8 m_tutor[0x7C00];       // 0xC0: CMenuTutorSelectedSub182108
};
//@sym Func1829E8__27CMenuTutorSelectedSub182108i 0x1829E8

class CStatusItem {
public:
    void Func1A3378();
    void Func1A3628();
    void Select(s32 i);
    void SetUnk34(f32 v);
    void Start();
    void Func1A40C8();
    u8 pad0[0x20];
    s32 m_unk20;              // 0x20
};
class CStatusWinSub1A0A10 {
public:
    CStatusItem *Find(const char *name);
};
extern CStatusWinSub1A0A10 *D_002A5408;
class CSndIf {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual int V7(s32 *a, s32 *b, s32 *c);
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14(s32 v);
};
extern CSndIf *D_002A5468;
f32 Pulse1AE3F8(f32 *t);
// @decl-end

CMenuSysscr00::CMenuSysscr00() {
    m_unk58 = 0;
}

CMenuSysscr00::~CMenuSysscr00() {
}

void CMenuSysscr00::Update() {
    s32 done;
    s32 a, b, c;
    D_002A5468->V7(&a, &b, &c);
    if (m_state == 6) {
        m_state = 5;
        goto end;
    }
    done = 0;
loop:
    if (done) goto out;
    {
        u32 fl = (u16)m_unk0;
        if ((fl >> 7) & 1) goto out;
    }
    switch (m_unk4) {
    case -1:
        m_unk58 = (CUnk1A4298 *)D_002A5408->Find("sysscr00");
        if (!m_unk58) { Func235DE0("*** Can't Get %s Window\n", "sysscr00"); return; }
        Item()->Func1A3378();
        D_002A5538->SetUnkE0(0);
        m_unk5C = 0.25f;
        Item()->Func1A3628();
        Item()->Select(-1);
        do {
    case -0x99:
        if (Item()->m_unk20 != 2) {
            m_unk4 = -0x99; done = 1; goto loop;
        }
        } while (0);
        m_unk4 = -0x9E; done = 1; goto loop;
    case -0x9E:
    case -0xAB:
        if (!(a & 0x820)) {
            f32 v = Pulse1AE3F8(&m_unk5C);
            Item()->SetUnk34(v);
            m_unk4 = -0xAB; done = 1; goto loop;
        }
        D_002A5468->V14(1);
        m_unk4C = 0;
        m_state = 4;
        Item()->Start();
        do {
    case -0xBC:
        if (Item()->m_unk20 != 0) {
            m_unk4 = -0xBC; done = 1; goto loop;
        }
        } while (0);
        m_state = 5;
        m_unk4 = -0xC0;
    case -0xC0:
        done = 1; goto loop;
    }
out:
    Item()->Func1A40C8();
end:;
}

s32 CMenuSysscr00::Draw() {
    return m_unk58->Func1A4298();
}

// Creates the CMenuSave screen.
CMenuSysscr00 *NewCMenuSysscr00() {
    CMenuSysscr00 *p = (CMenuSysscr00 *)operator new(0x7DC0);
    p->Init1AE800();
    return p;
}

void CMenuSave::Func1AE7A8() {
    f32 x, y;
    CMenuTutorSelectedSub182108 *t = (CMenuTutorSelectedSub182108 *)m_tutor;
    t->Func1829E8(m64);
    t->GetCursorPos(&x, &y);
    D_002A5538->Move1B6488(x, y);
}
