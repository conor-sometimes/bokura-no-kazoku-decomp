#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"
#include "CFlagWork.h"
#include "CCommandBase.h"
extern CFlagWork *D_002A5358;
class CUnk1A4298 {
public:
    int Func1A4298();
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
u8 *Func237570(int n);
void Func237A88(void *p, int v);
void *Func237C30(void *p);
int Func238158(void *p, int v);
void Func225240(int v);
#include "CMenuMgrSub1B4768.h"
class CMenuMgr {
public:
    int Func1B4ED0(int v);
};
extern CMenuMgrSub1B4768 *D_002A5530;
extern void *D_002A5534;
#include "CMenuLoadMemorialSub17B3A0.h"
extern CMenuLoadMemorialSub17B3A0 *D_002A3AF8;
// Command menu with +/- rows. Update is the vtable's key method: written as a plain member
// here (the unit shares its object with CStatusBase, so its vtable stays asm).
class CCommandIncDec {
public:
    void Update();
    s32 Draw();
    s32 NumRows() { return ((CCommandBase *)this)->NumRows(); }

    u8 pad0[0x48];
    CUnk1A4298 *m_unk48;      // 0x48
};
extern "C" void func_001995F0(CCommandIncDec *p);
extern "C" void func_00199BC0(CCommandIncDec *p);
extern "C" void func_001A40C8(void *p);
extern "C" int func_001972E8(void *p);
// CMenuRecord.cpp: the same object (its text sits in that file).
class CMenuRecordList {
public:
    int Func197FA8();
    int Draw1974F8();
    int Draw1976A0();
    void Func196D78();
    s32 GetPage();
    void SetOffset(s32 v);
    s32 PageCol(s32 n);
};
extern "C" int func_0019A480(CCommandIncDec *p);
extern "C" int func_001B5E18(void *p);

// From CCommandSelect.cpp (lane lb moved its functions 0x198C70.. here: their literals are this unit's)
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

void Func225088();
s32 Func2250C0();
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B4768 *D_002A5530;
extern void *D_002A5534;
extern CMenuMgrSub1B6418 *D_002A5538;
extern s32 D_002A5390[];
extern "C" int func_001B50B0(CMenuMgrSub1B4768 *m, s32 v);
extern "C" int func_001B5E18(void *p);
extern "C" int func_001B66E8(void *p);
extern "C" int func_00197950(CCommandSelect *c);
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
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
// CCommandIncDec helper (this + 0x50C: a 0..1 ratio, mode 1 inverted, 128 otherwise).

extern "C" void func_00199500(u8 *p, s32 a, s32 b, s32 mode);
extern "C" void func_00198CE0(CCommandSelect *p, s32 v);
extern "C" void CsRecInit(void *p) asm("Func196B50__15CMenuRecordList");
extern "C" void CsRecSel(void *p, s32 r) asm("Func196E90__15CMenuRecordListi");
extern "C" s32 CsRowOf(void *p, s32 v) asm("RowOf__12CCommandBasei");
extern "C" void CsItemSelect(void *p, s32 i) asm("Select__11CStatusItemi");
class CSndV7 {
public:
    virtual ~CSndV7();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual int V7(s32 *a, s32 *b, s32 *c);
};
#define M4D8 (*(s32 *)((u8 *)p + 0x4D8))
#define M530 (*(s32 *)((u8 *)p + 0x530))
#define WIN ((CStatusItem *)p->m_win)
#define REC ((CMenuRecordList *)p)
#define SUB ((CCommandSelectSub1990E0 *)p)

extern "C" void CsTick(void *p) asm("TickItems__15CMenuRecordList");
#define RECS ((CCommandRecs *)p)
#define CUR (D_002A5358->Func1091B0(M530 + 0x201))
// @decl-end

void CCommandRecs::ClearRec(s32 i) {
    memset(&m_recs[i], 0, sizeof(CCmdRec));
    m_recs[i].m38 = 4;
    m_recs[i].mC = -1;
    m_recs[i].m8 = -1;
}

INCLUDE_RODATA("asm/nonmatchings/CCommandIncDec", D_002DD9C8);
INCLUDE_RODATA("asm/nonmatchings/CCommandIncDec", D_002DD9E8);
INCLUDE_ASM("asm/nonmatchings/CCommandIncDec", func_00198CE0);

void CCommandRecs::Remove(s32 k) {
    s32 i, n;
    if (k < 0 || m_num - 1 < k || (u32)k >= 16) return (void)Func235DE0(D_002DD9C8, k);
    for (i = k; i < m_num; i++) m_recs[i] = m_recs[i + 1];
    ClearRec(m_num - 1);
    n = m_num - 1;
    if (n < 0) n = 0;
    m_num = n;
}

void CCommandSelect::Func198FA0(s32 k) {
    s32 a, b, c, d, e;
    if (k < 0 || D_002A5358->Func1091B0(0x200) - 1 < k) {
        return (void)Func235DE0(D_002DD9E8, k);
    }
    a = D_002A5358->Func1091B0(k + 0x201);
    b = D_002A5358->Func1091B0(k + 0x211);
    c = D_002A5358->Func1091B0(k + 0x221);
    d = D_002A5358->Func1091B0(k + 0x231);
    e = D_002A5358->Func1091B0(k + 0x1EF);
    func_00196938(this, a, b, c, d, 1, e != 0);
    D_002A5468->Play(8);
}

void CCommandSelectSub1990E0::Clear() {
    memset(m_data, 0, sizeof(m_data));
}

#if 0 // 19 vs 18 insns (g1): the rect half matches with the Rect(k) helper and the four m_rect[k].colour stores give retail's copy chain, but ours folds 0x500 into the index (k*32 + 0x500) where retail keeps this + k*32 with displacement 0x500
void CCommandSelect::Func199108(s32 k, f32 x, f32 y, f32 w, f32 h) {
    CCsRect *q = Rect(k);
    q->h = h;
    q->x = x;
    q->y = y;
    q->w = w;
    m_rect[k].r = 1.0f;
    m_rect[k].g = 1.0f;
    m_rect[k].b = 1.0f;
    m_rect[k].a = 1.0f;
}
#endif
INCLUDE_ASM("asm/nonmatchings/CCommandIncDec", Func199108__14CCommandSelectiffff);

void CCommandSelect::Func199150(f32 *x, f32 *y, f32 *w, f32 *h, s32 n) {
    f32 v[3];
    f32 sx, sy;
    s32 col = ((CMenuRecordList *)this)->PageCol(n);
    *x = ((CMenuRecordSub196E68 *)this)->GetWinValueA();
    *w = ((CMenuRecordSub196E68 *)this)->GetWinValueB();
    (*(CMenuRecordWin **)((u8 *)this + 0x48))->Func1A39A8(&v[2], (s32 *)y, col);
    (*(CMenuRecordWin **)((u8 *)this + 0x48))->Func1A3B58(&v[2], (s32 *)&v[0], col);
    (*(CMenuRecordWin **)((u8 *)this + 0x48))->Func1A3B58(&v[2], (s32 *)&v[1], col + 1);
    *h = v[0] + v[1];
    sx = (f32)D_002A4B60->Func1091B0(0x3F) / 100.0f;
    sy = (f32)D_002A4B60->Func1091B0(0x40) / 100.0f;
    *x = *x - (*w * sx - *w) * 0.5f;
    *y = *y - (*h * sy - *h) * 0.5f;
    *w = *w * sx;
    *h = *h * sy;
}

void CCommandSelect::Func1992E0(s32 a, s32 b) {
    f32 x, y, w, h;
    f32 t;
    Func199150(&x, &y, &w, &h, m_cursor - 3);
    t = (f32)a / (f32)b;
    if (t > 1.0f) t = 1.0f;
    Func199108(0, x + w * 0.5f * (1.0f - t), y, w * t, h);
}

void CCommandSelect::Func1993A0(s32 k, s32 n) {
    f32 x, y, w, h;
    if (k == 0) {
        Func199150(&x, &y, &w, &h, m_cursor - 3);
        h = (f32)D_002A4B60->Func1091B0(0x3D);
        Func199108(0, x, y, w, h);
    } else {
        f32 t = 1.0f - (f32)k / (f32)n;
        if (t < 0.0f) t = 0.0f;
        Func199150(&x, &y, &w, &h, m_cursor - 3);
        h = (f32)D_002A4B60->Func1091B0(0x3D);
        w *= 0.5f;
        Func199108(0, x, y, w * t, h);
        Func199108(1, x + w + w * (1.0f - t), y, w * t, h);
    }
}

extern "C" void func_00199500(u8 *p, s32 a, s32 b, s32 mode) {
    f32 v;
    switch (mode) {
    case 0:
        v = (f32)a / (f32)b;
        v = MAX(MIN(v, 1.0f), 0.0f);
        *(f32 *)(p + 0x50C) = v;
        break;
    case 1:
        v = (f32)a / (f32)b;
        v = MAX(MIN(v, 1.0f), 0.0f);
        *(f32 *)(p + 0x50C) = 1.0f - v;
        break;
    default:
        *(f32 *)(p + 0x50C) = 128.0f;
        break;
    }
}

// CCommandIncDec::Update's machine when flag 0x1FF is clear (rows counted up one by one).
extern "C" void func_001995F0(CCommandIncDec *q) {
    CCommandSelect *p = (CCommandSelect *)q;
    CStateMachine *sm = (CStateMachine *)p;
    s32 a, b, c;
    s32 done;
    ((CSndV7 *)D_002A5468)->V7(&a, &b, &c);
    done = 0;
loop:
    if (done) return;
    {
        u32 fl = sm->m_flags;
        if ((fl >> 7) & 1) return;
    }
    switch (sm->m_state) {
    case -1:
        CsRecInit(p);
        REC->SetOffset(1);
        p->SetMode198128(1);
        SUB->Clear();
        M530 = 0;
        do {
    case -0x169:
            if (p->m_state != 1) {
                sm->m_state = -0x169; done = 1; goto loop;
            }
        } while (0);
        CsItemSelect(p->m_win, -1);
        p->m_cursor = D_002A5358->Func1091B0(M530 + 0x201) + 3;
        CsRecSel(p, CsRowOf(p, p->m_cursor));
        REC->Func196D78();
        WIN->Func1A3628();
    case -0x17F:
        if (WIN->m_state != 2) {
            sm->m_state = -0x17F; done = 1; goto loop;
        }
    s3:
        p->m_state = 3;
        M4D8 = 0;
        sm->m_state = -0x187; done = 1; goto loop;
    case -0x187:
        p->m_cursor = D_002A5358->Func1091B0(M530 + 0x201) + 3;
        CsRecSel(p, CsRowOf(p, p->m_cursor));
        REC->Func196D78();
        do {
    case -0x1A2:
            if (a & 0x40) goto cancel;
            if (a & 0x20) {
                D_002A5468->Play(3);
                func_00198CE0(p, D_002A5358->Func1091B0(M530 + 0x201));
                p->Func198FA0(M530);
                REC->Func196D78();
                goto s2;
            }
            M4D8++;
            if (M4D8 <= D_002A4B60->Func1091B0(0x31)) {
                sm->m_state = -0x1A2; done = 1; goto loop;
            }
        } while (0);
        M4D8 = 0;
        func_00198CE0(p, D_002A5358->Func1091B0(M530 + 0x201));
        REC->Func196D78();
        do {
    case -0x1C0:
            if (a & 0x40) goto cancel;
            if (a & 0x20) {
                D_002A5468->Play(3);
                p->Func198FA0(M530);
                REC->Func196D78();
                goto s2;
            }
            M4D8++;
            if (M4D8 <= D_002A4B60->Func1091B0(0x32)) {
                sm->m_state = -0x1C0; done = 1; goto loop;
            }
        } while (0);
        M4D8 = 0;
        do {
    case -0x1DC:
            if (a & 0x40) goto cancel;
            if (a & 0x20) {
                D_002A5468->Play(3);
                p->Func198FA0(M530);
                REC->Func196D78();
                goto s2;
            }
            p->Func1992E0(M4D8, D_002A4B60->Func1091B0(0x33));
            M4D8++;
            if (M4D8 <= D_002A4B60->Func1091B0(0x33)) {
                sm->m_state = -0x1DC; done = 1; goto loop;
            }
        } while (0);
        M4D8 = 0;
        p->Func198FA0(M530);
        REC->Func196D78();
        do {
    case -0x1F9:
            if (a & 0x40) goto cancel;
            if (a & 0x20) {
                D_002A5468->Play(3);
                goto s2;
            }
            func_00199500((u8 *)p, M4D8, D_002A4B60->Func1091B0(0x34), 1);
            M4D8++;
            if (M4D8 <= D_002A4B60->Func1091B0(0x34)) {
                sm->m_state = -0x1F9; done = 1; goto loop;
            }
        } while (0);
    s2:
        M4D8 = 0;
        p->m_state = 2;
        SUB->Clear();
        sm->m_state = -0x202; done = 1; goto loop;
    case -0x202:
        M530++;
        if (M530 < D_002A5358->Func1091B0(0x200)) goto s3;
        sm->m_state = -0x209; done = 1; goto loop;
        if (0) {
    cancel:
            D_002A5468->Play(3);
            goto s4;
        }
    case -0x209:
        do {
    case -0x21D:
            if (a & 0x40) goto cancel;
            if (a & 0x20) {
                D_002A5468->Play(3);
                goto s4;
            }
            M4D8++;
            if (M4D8 <= D_002A4B60->Func1091B0(0x35)) {
                sm->m_state = -0x21D; done = 1; goto loop;
            }
        } while (0);
    s4:
        p->m_state = 4;
        SUB->Clear();
        WIN->Start();
    case -0x22C:
        if (WIN->m_state != 0) {
            sm->m_state = -0x22C; done = 1; goto loop;
        }
        p->m_state = 0;
        sm->m_state = -0x230;
    case -0x230:
        done = 1; goto loop;
    }
}

// CCommandIncDec::Update's machine when flag 0x1FF is set (rows removed one by one).
extern "C" void func_00199BC0(CCommandIncDec *q) {
    CCommandSelect *p = (CCommandSelect *)q;
    CStateMachine *sm = (CStateMachine *)p;
    f32 x, y, w, h;
    s32 a, b, c;
    s32 done;
    ((CSndV7 *)D_002A5468)->V7(&a, &b, &c);
    done = 0;
loop:
    if (done) return;
    {
        u32 fl = sm->m_flags;
        if ((fl >> 7) & 1) return;
    }
    switch (sm->m_state) {
    case -1:
        CsRecInit(p);
        REC->SetOffset(1);
        p->SetMode198128(1);
        SUB->Clear();
        M530 = 0;
        do {
    case -0x257:
            if (p->m_state != 1) {
                sm->m_state = -0x257; done = 1; goto loop;
            }
        } while (0);
        REC->Func196D78();
        CsItemSelect(p->m_win, -1);
        p->m_cursor = CUR + 3;
        CsRecSel(p, CsRowOf(p, p->m_cursor));
        REC->Func196D78();
        WIN->Func1A3628();
        do {
    case -0x276:
            if (WIN->m_state != 2) {
                sm->m_state = -0x276; done = 1; goto loop;
            }
            p->m_state = 3;
            if (D_002A5358->Func1091B0(0x241) != 1) goto s3;
        } while (0);
        sm->m_state = -0x27B; done = 1; goto loop;
    case -0x27B:
        M4D8 = 0;
        CsTick(p);
        REC->Func196D78();
        D_002A5468->Play(0x5A);
        do {
    case -0x298:
            if (a & 0x40) goto cancel;
            if (a & 0x20) {
                D_002A5468->Play(3);
                goto s3;
            }
            M4D8++;
            if (M4D8 <= D_002A4B60->Func1091B0(0x3E)) {
                sm->m_state = -0x298; done = 1; goto loop;
            }
        } while (0);
    s3:
        M4D8 = 0;
        p->m_state = 3;
        p->m_cursor = CUR + 3;
        CsRecSel(p, CsRowOf(p, p->m_cursor));
        REC->Func196D78();
        do {
    case -0x2B9:
            if (a & 0x40) goto cancel;
            if (a & 0x20) {
                D_002A5468->Play(3);
                RECS->ClearRec(CUR);
                RECS->Remove(CUR);
                REC->Func196D78();
                goto s2;
            }
            M4D8++;
            if (M4D8 <= D_002A4B60->Func1091B0(0x36)) {
                sm->m_state = -0x2B9; done = 1; goto loop;
            }
        } while (0);
        M4D8 = 0;
        p->Func199150(&x, &y, &w, &h, p->m_cursor - 3);
        p->Func199108(0, x, y, w, h);
        D_002A5468->Play(0x5A);
        do {
    case -0x2D8:
            if (a & 0x40) goto cancel;
            if (a & 0x20) {
                D_002A5468->Play(3);
                RECS->ClearRec(CUR);
                RECS->Remove(CUR);
                REC->Func196D78();
                goto s2;
            }
            func_00199500((u8 *)p, M4D8, D_002A4B60->Func1091B0(0x37), 0);
            M4D8++;
            if (M4D8 <= D_002A4B60->Func1091B0(0x37)) {
                sm->m_state = -0x2D8; done = 1; goto loop;
            }
        } while (0);
        M4D8 = 0;
        do {
    case -0x2F3:
            if (a & 0x40) goto cancel;
            if (a & 0x20) {
                D_002A5468->Play(3);
                RECS->ClearRec(CUR);
                RECS->Remove(CUR);
                REC->Func196D78();
                goto s2;
            }
            M4D8++;
            if (M4D8 <= D_002A4B60->Func1091B0(0x38)) {
                sm->m_state = -0x2F3; done = 1; goto loop;
            }
        } while (0);
        M4D8 = 0;
        SUB->Clear();
        RECS->ClearRec(CUR);
        REC->Func196D78();
        do {
    case -0x30F:
            if (a & 0x40) goto cancel;
            if (a & 0x20) {
                D_002A5468->Play(3);
                RECS->Remove(CUR);
                REC->Func196D78();
                goto s2;
            }
            M4D8++;
            if (M4D8 <= D_002A4B60->Func1091B0(0x39)) {
                sm->m_state = -0x30F; done = 1; goto loop;
            }
        } while (0);
        M4D8 = 0;
        RECS->Remove(CUR);
        REC->Func196D78();
        p->Func1993A0(0, 1);
        do {
    case -0x329:
            if (a & 0x40) goto cancel;
            if (a & 0x20) {
                D_002A5468->Play(3);
                goto s2;
            }
            M4D8++;
            if (M4D8 <= D_002A4B60->Func1091B0(0x3A)) {
                sm->m_state = -0x329; done = 1; goto loop;
            }
        } while (0);
        M4D8 = 0;
        do {
    case -0x341:
            if (a & 0x40) goto cancel;
            if (a & 0x20) {
                D_002A5468->Play(3);
                goto s2;
            }
            p->Func1993A0(M4D8, D_002A4B60->Func1091B0(0x3B));
            M4D8++;
            if (M4D8 <= D_002A4B60->Func1091B0(0x3B)) {
                sm->m_state = -0x341; done = 1; goto loop;
            }
        } while (0);
    s2:
        M4D8 = 0;
        SUB->Clear();
        sm->m_state = -0x348; done = 1; goto loop;
        if (0) {
    cancel:
            D_002A5468->Play(3);
            goto s4;
        }
    case -0x348:
        M530++;
        if (M530 < D_002A5358->Func1091B0(0x200)) goto s3;
        do {
    case -0x35F:
            if (a & 0x40) goto cancel;
            if (a & 0x20) {
                D_002A5468->Play(3);
                goto s4;
            }
            M4D8++;
            if (M4D8 <= D_002A4B60->Func1091B0(0x3C)) {
                sm->m_state = -0x35F; done = 1; goto loop;
            }
        } while (0);
    s4:
        p->m_state = 4;
        SUB->Clear();
        WIN->Start();
        do {
    case -0x36E:
            if (WIN->m_state != 0) {
                sm->m_state = -0x36E; done = 1; goto loop;
            }
        } while (0);
        p->m_state = 0;
        sm->m_state = -0x372;
    case -0x372:
        done = 1; goto loop;
    }
}

INCLUDE_ASM("asm/nonmatchings/CCommandIncDec", func_0019A480);

void CCommandIncDec::Update() {
    if (D_002A5358->Func1091B0(0x1FF) == 0) {
        func_001995F0(this);
    } else {
        func_00199BC0(this);
    }
    func_001A40C8(m_unk48);
}

s32 CCommandIncDec::Draw() {
    if (m_unk48 == 0) {
        Func225088();
        return Func2250C0();
    }
    u8 *p = Func237570(0x70);
    Func237A88(p, 7);
    CUnk237E90 *a = (CUnk237E90 *)(p + 0x20);
    Func238158(Func237C30(p + 0x60), 1);
    CUnk237E90 *c = (CUnk237E90 *)(p + 0x50);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unk48->Func1A4298());
    CUnk237E90 *b = (CUnk237E90 *)(p + 0x40);
    a->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x21)));
    a->Func237E90(func_001972E8(this));
    if (NumRows() >= 2) a->Func237E90(((CMenuRecordList *)this)->Draw1974F8());
    a->Func237E90(D_002A3AF8->Func17B4A0());
    a->Func237E90(((CMenuRecordList *)this)->Draw1976A0());
    b->Func237E90(func_001B5E18(D_002A5534));
    if (NumRows() >= 2) b->Func237E90(((CMenuRecordList *)this)->Func197FA8());
    c->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x42)));
    c->Func237E90(func_0019A480(this));
    Func225088();
    Func225240((int)p);
    return Func2250C0();
}
INCLUDE_RODATA("asm/nonmatchings/CCommandIncDec", D_002DDA10);
INCLUDE_RODATA("asm/nonmatchings/CCommandIncDec", D_002DDA28);
