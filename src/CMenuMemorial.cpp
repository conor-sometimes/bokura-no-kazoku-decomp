#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CUnk1A4298 {
public:
    int Func1A4298();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuMemorial.
class CMenuMemorial : public CMenuProcess {
public:
    CMenuMemorial();
    virtual ~CMenuMemorial();
    virtual void Update();
    virtual s32 Draw();

    CUnk1A4298 *m_unk58;      // 0x58
};

//@sym __builtin_new 0x245648
//@sym __17CMenuLoadMemorial 0x176B98
class CMenuLoadMemorial {
public:
    CMenuLoadMemorial() throw();

    u8 pad0[0x7DC0];
};

#include "CMenuMgrSub1B6BA8.h"
extern CMenuMgrSub1B6BA8 *D_002A55AC;
class CMenuTutorSelectedSub182108 {
public:
    void GetCursorPos(f32 *x, f32 *y);
};
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
extern "C" void func_001829E8(void *p, s32 v);
// CMenuLoadMemorial's unit starts here (its text starts before its first vtable function).
class CMenuLoadMemorialPart {
public:
    void Func176AE0();

    u8 pad0[0x64];
    s32 m_unk64;              // 0x64
    u8 pad68[0x58];
    CMenuTutorSelectedSub182108 m_unkC0; // 0xC0
};

#include "state.h"
class CStatusItem {
public:
    void Func1A3378();
    void Func1A3628();
    void Start();
    void Func1A40C8();
    u8 pad0[0x20];
    s32 m_state;              // 0x20
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
#include "CFlagWork.h"
extern CFlagWork *D_002A4B60;
inline void SetVar(CStateMachine *sm, s32 k, s32 v) { sm->Var(k) = v; }
inline void Inc(CStateMachine *sm) { SetVar(sm, 0, sm->Get(0) + 1); }
// @decl-end

CMenuMemorial::CMenuMemorial() {
    m_unk58 = 0;
}

CMenuMemorial::~CMenuMemorial() {
}

void CMenuMemorial::Update() {
    CStateMachine *sm = (CStateMachine *)this;
    s32 a, b, c;
    s32 done;
    D_002A5468->V7(&a, &b, &c);
    if (m_state == 6) {
        m_state = 5;
        goto end;
    }
    done = 0;
loop:
    if (done) goto out;
    {
        u32 fl = sm->m_flags;
        if ((fl >> 7) & 1) goto out;
    }
    switch (sm->m_state) {
    case -1:
        m_unk58 = (CUnk1A4298 *)D_002A5408->Find("memorial");
        if (!m_unk58) { Func235DE0("*** Can't Get %s Window\n", "memorial"); return; }
        ((CStatusItem *)m_unk58)->Func1A3378();
        ((CStatusItem *)m_unk58)->Func1A3628();
        do {
    case -0x7D:
        if (((CStatusItem *)m_unk58)->m_state != 2) {
            sm->m_state = -0x7D; done = 1; goto loop;
        }
        } while (0);
        sm->m_state = -0x82; done = 1; goto loop;
    case -0x82:
        sm->Push(4);
        SetVar(sm, 1, D_002A4B60->Func1091B0(0x67));
        SetVar(sm, 0, 0);
        {
            f32 z = 0.0f;
            SetVar(sm, 2, *(s32 *)&z);
        }
        {
            f32 z = 0.0f;
            SetVar(sm, 3, *(s32 *)&z);
        }
        for (; sm->Get(0) < sm->Get(1); Inc(sm)) {
            if (!(a & 0x60)) {
                sm->m_state = -0x8C; done = 1; goto loop;
            }
            D_002A5468->V14(3);
            sm->Pop(4);
            goto s4;
    case -0x8C:;
        }
        sm->Pop(4);
    s4:
        m_state = 4;
        ((CStatusItem *)m_unk58)->Start();
        do {
    case -0x9D:
        if (((CStatusItem *)m_unk58)->m_state != 0) {
            sm->m_state = -0x9D; done = 1; goto loop;
        }
        } while (0);
        m_state = 5;
        sm->m_state = -0xA1;
    case -0xA1:
        done = 1; goto loop;
    }
out:
    ((CStatusItem *)m_unk58)->Func1A40C8();
end:;
}

s32 CMenuMemorial::Draw() {
    return m_unk58->Func1A4298();
}

CMenuLoadMemorial *CreateCMenuLoadMemorial() {
    return new CMenuLoadMemorial;
}

void CMenuLoadMemorialPart::Func176AE0() {
    f32 x, y;
    func_001829E8(&m_unkC0, m_unk64);
    m_unkC0.GetCursorPos(&x, &y);
    D_002A5538->Move1B6488(x, y);
}

int HasMemorialSave() {
    s32 i;
    for (i = 0; i < 30; i++) {
        if (D_002A55AC->Check1B7428(i) == 1) {
            return 1;
        }
    }
    return 0;
}
