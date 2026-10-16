#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void *func_0024F2E8(s32 size);
extern "C" void func_0024F5C0(void *a, void *b, s32 c);

#include "CProcess.h"

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CBootMain.
class CBootMain : public CProcess {
public:
    CBootMain();
    virtual ~CBootMain();
    virtual void Update();

    u8 pad18[0x14];
    CStateMachine m_sm;       // 0x2C
};

// Created here; its unit follows.
class CLogoMain : public CProcess {
public:
    CLogoMain();

    u8 pad18[0xC4];
};

extern "C" s32 func_00251BA8();
extern "C" void func_0024FA38(void *p, s32 a, s32 b, s32 c, s32 d);
class CSndIf {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8(s32 a, s32 b);
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual s32 V12();
};
extern CSndIf *D_002A5468;
// @decl-end

CBootMain::CBootMain() {
}

CBootMain::~CBootMain() {
}

void CBootMain::Update() {
    s32 done = 0;
    s32 v;
    CStateMachine *sm = &m_sm;
loop:
    if (done) return;
    {
        u32 fl = sm->m_flags;
        if ((fl >> 7) & 1) return;
    }
    switch (sm->m_state) {
    case -1:
        D_002A5468->V8(0xE, -1);
        for (;;) {
    case -0x3F:
            if (D_002A5468->V12() == 5) break;
            sm->m_state = -0x3F;
            done = 1;
            goto loop;
        }
        sm->Push();
        sm->Var() = func_00251BA8();
        for (;;) {
    case -0x42:
            v = func_00251BA8();
            if (v != sm->Get()) break;
            sm->m_state = -0x42;
            done = 1;
            goto loop;
        }
        sm->Pop();
        func_0024FA38(this, 0, 0, 0, 0);
        sm->m_state = -0x45;
    case -0x45:
        done = 1;
        goto loop;
    }
}

void Func100588(void *a) {
    CLogoMain *p = new CLogoMain;
    func_0024F5C0(a, p, 0);
}
