#include "common.h"
#pragma interface

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym memset 0x289FB0
#include "libc.h"
class CCommandSelectSub1990E0 {
public:
    void Clear();

    u8 pad0[0x4F0];
    u8 m_data[0x40];          // 0x4F0
};

#include "CCommandBase.h"
#include "CFlagWork.h"
extern CFlagWork *D_002A4B60;
extern "C" void func_00196B50(void *p);
// A selection rectangle and its colour (two of them at 0x4F0).
struct CCsRect {
    f32 x, y, w, h;
    f32 r, g, b, a;
};
// Vtable 0x2C1A60: Update (key method, 0x1986A8) and Draw.
class CCommandSelect : public CCommandBase {
public:
    CCommandSelect();
    virtual s32 Update();
    virtual s32 Draw();
    void Func199108(s32 k, f32 x, f32 y, f32 w, f32 h);
    CCsRect *Rect(s32 k) {
        u32 o = k * 32 + 0x4F0;
        return (CCsRect *)((u8 *)this + o);
    }
    void Func199150(f32 *x, f32 *y, f32 *w, f32 *h, s32 n);
    void Func1992E0(s32 a, s32 b);
    void Func1993A0(s32 k, s32 n);
    void Func198FA0(s32 k);

    u8 pad4EC[0x4];
    CCsRect m_rect[2];        // 0x4F0
    u8 pad530[0x10];
};

// The command list's records as CCommandSelect's code sees them (CCommandBaseRec, 0x48 bytes).
struct CCmdRec {
    s32 m0;                   // 0x00
    s32 m4;                   // 0x04
    s32 m8;                   // 0x08
    s32 mC;                   // 0x0C
    u8 pad10[0x28];
    s32 m38;                  // 0x38
    u8 pad3C[0xC];
};
class CCommandRecs {
public:
    void ClearRec(s32 i);
    void Remove(s32 k);
    u8 pad0[0x50];
    CCmdRec m_recs[16];       // 0x50
    s32 m_num;                // 0x4D0
};

class CMenuRecordList {
public:
    void Func196D78();
    s32 GetPage();
    void SetOffset(s32 v);
    s32 PageCol(s32 n);
};
class CMenuRecordSub196E68 {
public:
    f32 GetWinValueA();
    f32 GetWinValueB();
};
#include "CMenuRecordWin.h"

extern CFlagWork *D_002A5358;
extern "C" void func_00196938(void *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
class CSePlayer {
public:
    virtual ~CSePlayer();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual void F7();
    virtual void F8();
    virtual void F9();
    virtual void F10();
    virtual void F11();
    virtual void F12();
    virtual void F13();
    virtual void Play(s32 id);
};
extern CSePlayer *D_002A5468;
extern char D_002DD9E8[];
int Func235DE0(const char *fmt, ...) throw();

u8 *Func237570(s32 v);
void Func237A88(void *p, s32 v);
void *Func237C30(void *p);
void Func238158(void *p, s32 v);
void Func225088();
void Func225240(s32 v);
s32 Func2250C0();
class CUnk237E90 {
public:
    int Func237E90(int v);
};
class CUnk1A4298 {
public:
    int Func1A4298();
};
#include "CMenuMgrSub1B4768.h"
class CMenuMgr {
public:
    int Func1B4ED0(s32 e);
};
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B4768 *D_002A5530;
extern void *D_002A5534;
extern CMenuMgrSub1B6418 *D_002A5538;
extern void *D_002A3AF8;
extern s32 D_002A5390[];
extern "C" int func_001B50B0(CMenuMgrSub1B4768 *m, s32 v);
extern "C" int func_001B5E18(void *p);
extern "C" int func_001B66E8(void *p);
extern "C" int func_00197950(CCommandSelect *c);
extern "C" int func_001972E8(CCommandSelect *c);
extern "C" int func_00197AE0(CCommandSelect *c);
extern "C" int func_001974F8(CCommandSelect *c);
extern "C" int func_001976A0(CCommandSelect *c);
extern "C" int func_00197FA8(CCommandSelect *c);
// Named by another lane as taking no arguments; retail passes D_002A3AF8.
extern "C" int MemorialMenuFunc17B4A0__Fv(void *p);
struct CCsWin {
    u8 pad0[0x34];
    f32 m34;                  // 0x34
};
extern char D_002DD9C8[];
#include "state.h"
class CStatusItem {
public:
    void GetUnkC0(f32 *x, f32 *y, s32 n);
    void Func1A3628();
    void Start();
    void Func1A40C8();
    u8 pad0[0x20];
    s32 m_state;              // 0x20
};
inline void SetVar(CStateMachine *sm, s32 k, s32 v) { sm->Var(k) = v; }
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD928);
CCommandSelect::CCommandSelect() {
    func_00196B50(this);
}

s32 CCommandSelect::Update() {
    CStateMachine *sm = (CStateMachine *)this;
    s32 done = 0;
    f32 x, y;
    char buf[0x100];
loop:
    if (done) goto out;
    {
        u32 fl = sm->m_flags;
        if ((fl >> 7) & 1) goto out;
    }
    switch (sm->m_state) {
    case -1:
        SetMode198128(0);
        ((CMenuRecordList *)this)->SetOffset(0);
        do {
    case -0x59:
        if (m_state != 1) {
            sm->m_state = -0x59; done = 1; goto loop;
        }
        } while (0);
        D_002A5538->SetUnkE0(1);
        ((CStatusItem *)m_win)->GetUnkC0(&x, &y, ((CMenuRecordList *)this)->GetPage());
        D_002A5538->SetUnk0And20(x, y);
        ((CMenuRecordList *)this)->Func196D78();
        Select198290(m_cursor);
        ((CStatusItem *)m_win)->Func1A3628();
        do {
    case -0x70:
        if (((CStatusItem *)m_win)->m_state == 2) {
            m_state = 2;
            sm->m_state = -0x76; done = 1; goto loop;
        }
        sm->m_state = -0x70; done = 1; goto loop;
        } while (0);
    case -0x76:
        for (;;) {
            if (*(s32 *)((u8 *)this + 0x4E4)) {
                sm->Push(); SetVar(sm, 0, -0x7A);
                goto sub;
    case -0x7A:;
            }
            if (m_state != 4) {
                sm->m_state = -0x80; done = 1; goto loop;
            }
            break;
    case -0x80:;
        }
        ((CStatusItem *)m_win)->Start();
        do {
    case -0x8D:
            if (((CStatusItem *)m_win)->m_state == 0) {
                m_state = 0;
                sm->m_state = -0x9B;
                goto e9B;
            }
            sm->m_state = -0x8D; done = 1; goto loop;
        } while (0);
    sub:
        *(s32 *)((u8 *)this + 0x4E4) = 0;
        ((CMenuRecordList *)this)->Func196D78();
        ((CStatusItem *)m_win)->GetUnkC0(&x, &y, ((CMenuRecordList *)this)->GetPage());
        D_002A5538->Move1B6488(x, y);
        sm->m_state = sm->Get();
        sm->Pop();
        goto loop;
    case -0x9B:
    e9B:
        done = 1; goto loop;
    }
out:
    ((CStatusItem *)m_win)->Func1A40C8();
    D_002A5538->Update1B6570();
}
INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD9A0);

s32 CCommandSelect::Draw() {
    u8 *p;
    f32 v[2];
    if (!m_win) {
        Func225088();
        return Func2250C0();
    }
    p = Func237570(0x60);
    Func237A88(p, 6);
    Func238158(Func237C30(p + 0x50), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_win)->Func1A4298());
    ((CUnk237E90 *)(p + 0x20))->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x2F)));
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_00197950(this));
    ((CUnk237E90 *)(p + 0x20))->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x21)));
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001972E8(this));
    D_002A5530->Reset1B4D28();
    ((CMenuRecordWin *)m_win)->Func1A39A8(v, (s32 *)&v[1], 0x44);
    D_002A5530->SetUnk20(v[0], v[1], 0.0f);
    D_002A5530->SetUnk4C(((CCsWin *)m_win)->m34);
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B50B0(D_002A5530, D_002A5390[((ICurFlag *)D_002A26E4)->Vf2991B0()]));
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_00197AE0(this));
    if (NumRows() >= 2) ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001974F8(this));
    ((CUnk237E90 *)(p + 0x20))->Func237E90(MemorialMenuFunc17B4A0__Fv(D_002A3AF8));
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001976A0(this));
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B5E18(D_002A5534));
    if (NumRows() >= 2) ((CUnk237E90 *)(p + 0x30))->Func237E90(func_00197FA8(this));
    D_002A5538->SetUnk4C(((CCsWin *)m_win)->m34);
    ((CUnk237E90 *)(p + 0x40))->Func237E90(func_001B66E8(D_002A5538));
    Func225088();
    Func225240((s32)p);
    return Func2250C0();
}

