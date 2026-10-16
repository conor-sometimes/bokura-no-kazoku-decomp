#include "common.h"

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
    u8 pad0[0x50];
    CCmdRec m_recs[16];       // 0x50
};

class CMenuRecordList {
public:
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
int Func235DE0(const char *fmt, ...);

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
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD928);
INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD940);
INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD960);
INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD9A0);
CCommandSelect::CCommandSelect() {
    func_00196B50(this);
}

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", Update__14CCommandSelect);

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

void CCommandRecs::ClearRec(s32 i) {
    memset(&m_recs[i], 0, sizeof(CCmdRec));
    m_recs[i].m38 = 4;
    m_recs[i].mC = -1;
    m_recs[i].m8 = -1;
}

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00198CE0);

#if 0 // DIFF 1 (g1): retail bnez with the next index's sll in the slot, ours bnezl; Insert 0x198CE0 is the mirror (k >= 16 is an unsigned test)
void CCommandRecs::Remove(s32 k) {
    s32 i, n;
    if (k < 0 || m_num - 1 < k || (u32)k >= 16) return (void)Func235DE0(D_002DD9C8, k);
    for (i = k; i < m_num; i++) m_recs[i] = m_recs[i + 1];
    ClearRec(m_num - 1);
    n = m_num - 1;
    if (n < 0) n = 0;
    m_num = n;
}
#endif
INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00198E40);

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
INCLUDE_ASM("asm/nonmatchings/CCommandSelect", Func199108__14CCommandSelectiffff);

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

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00199500);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00199BC0);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_0019A480);
