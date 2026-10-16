#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CCommandBaseRec {
public:
    s32 m0;                   // 0x0
    s32 m4;                   // 0x4
    u8 pad8[0x4];
    s32 mC;                   // 0xC
    u8 pad10[0x30];
    s32 m40;                  // 0x40
    u8 pad44[0x4];
};
#include "CProcess.h"
class CStatusItem {
public:
    void Func1A3378();
};
#include "CStatusWin.h"
extern CStatusWin *D_002A5408;
extern char D_002DD818[];
// Command menu base. Vtable 0x2C1A40: Update and Draw, both pure in retail; Update is declared
// non-pure here only so that this unit does not emit the vtable (it stays asm). The vptr follows
// the fields at 0x4E8.
class CCommandBase {
public:
    CCommandBase();
    virtual s32 Update();
    virtual s32 Draw() = 0;
    void SetMode198128(s32 mode);
    int GetRecC198328(s32 i);
    void Select198290(s32 i);
    int RowOf(int v);
    void Open();
    void Close();
    s32 NumRows();
    s32 GetRec40(s32 i);
    CCommandBaseRec *GetRec(s32 i);
    s32 GetRec4(s32 i);
    s32 NextRowItem();
    s32 PrevRowItem(s32 wrap);

    CStateMachine m_sm;       // 0x00
    CStatusItem *m_win;       // 0x48
    s32 m_state;              // 0x4C
    CCommandBaseRec m_recs[16]; // 0x50
    s32 m_num;                // 0x4D0
    s32 m_cursor;             // 0x4D4
    s32 m_unk4D8;             // 0x4D8
    f32 m_unk4DC;             // 0x4DC
    f32 m_unk4E0;             // 0x4E0
    s32 m_unk4E4;             // 0x4E4
};

// The debug printf as this unit's own code declares it (void); CMenuProcess.h has the s32 one.
void CbPrint(const char *fmt, ...) throw() asm("Func235DE0__FPCce");
extern s32 D_002A5370[];
extern char D_002DD838[];
extern char D_002DD858[];
extern char D_002DD8A0[];
extern char D_002DD8C8[];
extern char D_002DD8F0[];

extern "C" void func_001A3840(void *win, s32 i);
extern "C" s32 func_001971A0(void *p, s32 i);
extern "C" void func_00196E90(void *p, s32 row);

#include "CFlagWork.h"
extern char D_002DD878[];
extern "C" int func_001456A8(s32 v);

#include "CMenuRecordWin.h"
extern "C" void func_001A3DC8(void *p, s32 i, s32 v);
extern "C" void func_001864A8(char *buf);
extern "C" const char *func_001A36B0(void *w, s32 v);
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern char D_002DD820[];

// From CMenuRecord.cpp (lane lb moved its functions 0x196938.. here: their literals are this unit's)
class CMenuRecordWin;
#include "CMenuProcess.h"
#include "CBgWork.h"
class CMenuAsksavequitObj {
public:
    void Release194300();
};
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuRecord.
class CMenuRecord : public CMenuProcess {
public:
    CMenuRecord();
    virtual ~CMenuRecord();
    virtual void Update();
    virtual s32 Draw();
    int GetMenuId();

    CBgWork m_bg;             // 0x58
    s32 m_unk64;              // 0x64
    s32 m_unk68;              // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    CMenuRecordWin *m_unk74;  // 0x74
    CMenuRecordWin *m_unk78;  // 0x78
    s32 m_unk7C;              // 0x7C
    s32 m_unk80;              // 0x80
    s32 m_unk84;              // 0x84
    s32 m_unk88;              // 0x88
    s32 m_unk8C;              // 0x8C
    s32 m_unk90;              // 0x90
    s32 m_unk94;              // 0x94
    u8 pad98[0x4];
    s32 m_unk9C;              // 0x9C
    u8 padA0[0x90];
    s32 m_unk130;             // 0x130
    s32 m_unk134;             // 0x134
    s32 m_unk138;             // 0x138
    s32 m_unk13C;             // 0x13C
    s32 m_unk140;             // 0x140
    s32 m_unk144;             // 0x144
    s32 m_unk148;             // 0x148
    s32 m_unk14C;             // 0x14C
    s32 m_unk150;             // 0x150
    s32 m_unk154;             // 0x154
};

extern const char D_002DD7F8[];
#include "CMenuRecordWin.h"
class CMenuRecordSub196E68 {
public:
    void CallFunc1A3740(s32 v);
    f32 GetWinValueA();
    f32 GetWinValueB();

    u8 pad0[0x48];
    CMenuRecordWin* m_win;    // 0x48
};

class CMenuRecordSub196FC8 {
public:
    int IsUnk4D4InWindow();

    u8 pad0[0x4D0];
    s32 m_unk4D0;             // 0x4D0
    s32 m_unk4D4;             // 0x4D4
};
// CCommandBase as CMenuRecordList's code sees it: no fields, and its methods taken as not defined
// here (as when this code was in CMenuRecord.cpp).
class CCommandBaseV {
public:
    int RowOf(int v) asm("RowOf__12CCommandBasei");
    s32 NumRows() asm("NumRows__12CCommandBase");
};

#include "CStatusWinSub1A40B8.h"

class CMenuRecordItem {
public:
    s32 m_value;              // 0x0
    u8 pad4[0x4];
    s32 m_timer;              // 0x8
    s32 m_unkC;               // 0xC
    u8 pad10[0x28];
    u32 m_unk38;              // 0x38
    s32 m_unk3C;              // 0x3C
    s32 m_unk40;              // 0x40
    s32 m_unk44;              // 0x44
};

class CMenuRecordList : public CCommandBaseV {
public:
    int Draw197AE0();
    int Draw1976A0();
    int Draw1972E8();
    int Draw1974F8();
    void Draw197950();
    void Func196E90(s32 flag);
    void Func196B50();
    void Func196C70(s32 i);
    int Func197FA8();
    void Func196D78();
    void TickItems();
    s32 GetPage();
    s32 PageRow(s32 i);
    s32 PageCol(s32 i);
    void GetRange(s32 *a, s32 *b);
    void GetRange2(s32 *a, s32 *b);
    void SetOffset(s32 on);

    u8 pad1[0x47];
    CMenuRecordWin *m_win;    // 0x48
    u8 pad4C[0x4];
    CMenuRecordItem m_items[15]; // 0x50
    u8 pad488[0x48];
    s32 m_count;              // 0x4D0
    s32 m_cursor;             // 0x4D4
    u8 pad4D8[0x4];
    f32 m_ofsX;               // 0x4DC
    f32 m_ofsY;               // 0x4E0
};


extern "C" int sprintf(char *buf, const char *fmt, ...);
extern char D_002DD800[], D_002DD810[], D_002DD928[];
#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
extern "C" void func_00196938(CMenuRecordList *p, s32 i, s32 a, s32 b, s32 c, s32 d, s32 e);
#include "CMenuMgrSub1B5BF8.h"
extern "C" int func_001B5FE0(CMenuMgrSub1B5BF8 *p, const char *s, f32 x, f32 y);
extern CMenuMgrSub1B5BF8 *D_002A5534;
struct CMenuRecordWinF { u8 pad0[0x34]; f32 m_unk34; };


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
extern "C" int func_001B50B0(CMenuMgrSub1B4768 *p, s32 v);
struct CVec2f { f32 x, y; };
struct CMenuRecordWinF2 { u8 pad0[0x34]; f32 m_unk34; };

#include "CMenuLoadMemorialSub17B3A0.h"
extern CMenuLoadMemorialSub17B3A0 *D_002A3AF8;

extern "C" int func_001A0510(void *p);
extern "C" int func_0018A1F0(void *p);
extern "C" int func_0017D3B0(void *p);
extern "C" int func_001B66E8(void *p);
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
class CMenuLoadMemorialSub17A8D8b {
public:
    int Draw17B1A8();
};
class CUnk1A4298 {
public:
    int Func1A4298();
};
#include "CTask.h"
class CPhotoDraw : public CTask {
public:
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual int DrawPhoto(s32 id, u32 color, f32 x, f32 y, f32 w, f32 h);
};
extern CPhotoDraw *D_002A3680;

extern "C" int func_001B5E18(void *p);
extern f32 D_002A5380[];
extern char D_002DD808[];
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CCommandBase", func_00196938);

void CMenuRecordList::Func196B50() {
    s32 i;
    s32 n = D_002A5358->Func1091B0(0x1AE);
    m_count = n;
    m_count = n < 0 ? 0 : (n > 16 ? 16 : n);
    for (i = 0; i < m_count; i++) {
        s32 a = D_002A5358->Func1091B0(i + 0x1AF);
        s32 b = D_002A5358->Func1091B0(i + 0x1BF);
        s32 c = D_002A5358->Func1091B0(i + 0x1DF);
        s32 d = D_002A5358->Func1091B0(i + 0x1CF) != 0;
        s32 f = D_002A5358->Func1091B0(i + 0x1EF) != 0;
        func_00196938(this, i, a, b, c, d, f);
    }
}

void CMenuRecordList::Func196C70(s32 i) {
    char buf[256];
    char buf2[256];
    if (m_win == 0) return;
    if (i < 0 || m_count - 1 < i) return;
    s32 k = PageRow(i) + 0x24;
    m_win->Func1A3740(k, D_002DD7F8);
    s32 o = i * 0x48 + 0x50;
    CMenuRecordItem *e = (CMenuRecordItem *)((u8 *)this + o);
    if (e->m_value == 0) return;
    sprintf(buf, func_001A36B0(m_win, k), e->m_value);
    m_win->Func1A3740(k, buf);
    if (m_items[i].m_unk40 == 0) {
        sprintf(buf2, D_002DD800, D_002DD928, buf);
        m_win->Func1A3740(k, buf2);
    }
}

void CMenuRecordList::Func196D78() {
    char buf[0x100];
    s32 i;
    s32 a, b;
    m_win->Func1A3740(0x21, func_001A36B0(m_win, 0x21));
    m_win->Func1A3740(0x22, func_001A36B0(m_win, 0x22));
    m_win->Func1A3740(0x23, func_001A36B0(m_win, 0x23));
    for (i = 0; i < 10; i++) {
        ((CMenuRecordSub196E68 *)this)->CallFunc1A3740(i);
    }
    GetRange2(&a, &b);
    for (i = a; i < a + b; i++) {
        Func196C70(i);
    }
}

void CMenuRecordSub196E68::CallFunc1A3740(s32 v) {
    m_win->Func1A3740(v + 0x24, D_002DD7F8);
}

void CMenuRecordList::Func196E90(s32 flag) {
    s32 i, on, off;
    if (flag == 0) {
        func_001A3DC8(m_win, 0x21, 1);
        func_001A3DC8(m_win, 0x22, 1);
        func_001A3DC8(m_win, 0x23, 1);
        on = 1;
        off = 0;
    } else {
        func_001A3DC8(m_win, 0x21, 0);
        func_001A3DC8(m_win, 0x22, 0);
        func_001A3DC8(m_win, 0x23, 0);
        on = 0;
        off = 1;
    }
    for (i = 7; i < 20; i++) func_001A3DC8(m_win, i, on);
    for (i = 20; i < 33; i++) func_001A3DC8(m_win, i, off);
    for (i = 0x24; i < 0x28; i++) func_001A3DC8(m_win, i, on);
    for (i = 0x28; i < 0x2E; i++) func_001A3DC8(m_win, i, off);
}

int CMenuRecordSub196FC8::IsUnk4D4InWindow() {
    s32 v = m_unk4D4;
    if (v >= 3) {
        if (v < m_unk4D0 + 3) {
            return 1;
        }
    }
    return 0;
}

void CMenuRecordList::SetOffset(s32 on) {
    if (!m_win) return;
    if (on == 1) {
        m_win->Func1A39A8(&m_ofsX, (s32 *)&m_ofsY, 0x43);
        ((CStatusWinSub1A40B8 *)m_win)->SetUnk80(m_ofsX, m_ofsY);
    } else {
        m_ofsX = m_ofsY = 0.0f;
    }
}

void CMenuRecordList::TickItems() {
    s32 i;
    for (i = 0; i < m_count; i++) {
        s32 t = m_items[i].m_timer;
        if (t > 0 && t != 1000) {
            m_items[i].m_timer = t - 1;
        }
    }
}

s32 CMenuRecordList::GetPage() {
    if (m_cursor < 3) {
        return m_cursor + 33;
    }
    return PageRow(m_cursor - 3) + 36;
}

int CMenuRecord::GetMenuId() {
    return 0x31;
}

s32 CMenuRecordList::PageCol(s32 i) {
    if (i < 4) {
        return i * 2 + 11;
    }
    return (i - 4) % 6 * 2 + 20;
}

f32 CMenuRecordSub196E68::GetWinValueA() {
    f32 v;
    s32 n;
    m_win->Func1A39A8(&v, &n, 1);
    return v;
}

f32 CMenuRecordSub196E68::GetWinValueB() {
    f32 v;
    s32 n;
    m_win->Func1A3B58(&v, &n, 1);
    return v;
}

s32 CMenuRecordList::PageRow(s32 i) {
    if (i < 10) {
        return i;
    }
    return i - (i - 4) / 6 * 6;
}

void CMenuRecordList::GetRange(s32 *a, s32 *b) {
    if (RowOf(m_cursor) == 0) {
        *a = 0;
        s32 v = m_count - 1;
        *b = v < 4 ? v : 3;
    } else {
        *a = 4;
        *b = m_count - 1;
    }
}

void CMenuRecordList::GetRange2(s32 *a, s32 *b) {
    if (m_cursor < 7) {
        *a = 0;
        *b = m_count < 5 ? m_count : 4;
    } else {
        s32 s = (m_cursor - 7) / 6 * 6 + 4;
        *a = s;
        if (m_count < s + 6) {
            *b = m_count - s;
        } else {
            *b = 6;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/CCommandBase", func_001972E8);

int CMenuRecordList::Draw1974F8() {
    f32 v[2];
    u8 *pp = Func237570(0x30);
    Func237A88(pp, 3);
    CUnk237E90 *q = (CUnk237E90 *)(pp + 0x10);
    Func238158(Func237C30(pp + 0x20), 1);
    q->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x29)));
    D_002A5530->Reset1B4D28();
    f32 w = ((CMenuRecordWinF2 *)m_win)->m_unk34;
    D_002A5530->SetUnk40(1.0f, 1.0f, 1.0f, w);
    m_win->Func1A39A8(&v[0], (s32 *)&v[1], 0x2E);
    D_002A5530->SetUnk20(v[0] + m_ofsX, v[1] + m_ofsY, 0.0f);
    q->Func237E90(func_001B50B0(D_002A5530, 0x29));
    m_win->Func1A39A8(&v[0], (s32 *)&v[1], 0x2F);
    D_002A5530->SetUnk20(v[0] + m_ofsX, v[1] + m_ofsY, 0.0f);
    D_002A5530->SetUnk58(2);
    q->Func237E90(func_001B50B0(D_002A5530, 0x29));
    D_002A5530->SetUnk58(0);
    Func225088();
    Func225240((s32)pp);
    Func2250C0();
}

int CMenuRecordList::Draw1976A0() {
    f32 x, y;
    f32 cx, cy;
    f32 sx, sy;
    s32 a, b;
    s32 i;
    u8 *pp = Func237570(0x30);
    Func237A88(pp, 3);
    Func238158(Func237C30(pp + 0x20), 1);
    D_002A5530->Reset1B4D28();
    m_win->Func1A39A8(&sx, (s32 *)&sy, 0x51);
    sx = sx / 100.0f;
    sy = sy / 100.0f;
    m_win->Func1A39A8(&cx, (s32 *)&cy, 0x50);
    GetRange2(&a, &b);
    for (i = a; i < a + b; i++) {
        if ((u32)(m_items[i].m_unkC - 0x10) >= 9) continue;
        m_win->Func1A39A8(&x, (s32 *)&y, PageRow(i) + 0x45);
        D_002A3AF8->CallFunc17B3E8();
        D_002A3AF8->SetUnk40(3.0f, 1.0f, 1);
        D_002A3AF8->SetUnk10(x + cx + m_ofsX, y + cy + m_ofsY);
        if (m_items[i].m_unk40) {
            D_002A3AF8->SetUnk30(1.0f, 1.0f, 1.0f, ((CMenuRecordWinF2 *)m_win)->m_unk34);
        } else {
            D_002A3AF8->SetUnk30(0.5f, 0.5f, 0.5f, ((CMenuRecordWinF2 *)m_win)->m_unk34);
        }
        if (m_items[i].m_unkC == 0x18) {
            D_002A3AF8->SetUnk20(1.0f, 1.0f);
        } else {
            D_002A3AF8->SetUnk20(sx, sy);
        }
        ((CUnk237E90 *)(pp + 0x10))->Func237E90(D_002A3AF8->Draw17B4D8(m_items[i].m_unkC));
    }
    Func225088();
    Func225240((s32)pp);
    Func2250C0();
}

void CMenuRecordList::Draw197950() {
    s32 a, b;
    f32 px, py;
    f32 bx, by;
    s32 i;
    u8 *pp = Func237570(0x30);
    Func237A88(pp, 3);
    Func238158(Func237C30(pp + 0x20), 1);
    D_002A5530->Reset1B4D28();
    D_002A5530->SetUnk4C(((CMenuRecordWinF2 *)m_win)->m_unk34);
    m_win->Func1A39A8(&bx, (s32 *)&by, 0x4F);
    GetRange2(&a, &b);
    for (i = a; i < a + b; i++) {
        if (!m_items[i].m_unk44) continue;
        m_win->Func1A39A8(&px, (s32 *)&py, PageRow(i) + 0x45);
        D_002A5530->SetUnk20(px + bx + m_ofsX, py + by + m_ofsY, 0.0f);
        ((CUnk237E90 *)(pp + 0x10))->Func237E90(func_001B50B0(D_002A5530, 0x2F));
    }
    Func225088();
    Func225240((s32)pp);
    Func2250C0();
}

int CMenuRecordList::Draw197AE0() {
    s32 a, b;
    f32 px, py;
    f32 bx, by;
    f32 sx, sy;
    char buf[256];
    u8 *pp = Func237570(0x30);
    Func237A88(pp, 3);
    CUnk237E90 *q = (CUnk237E90 *)(pp + 0x10);
    Func238158(Func237C30(pp + 0x20), 1);
    GetRange2(&a, &b);
    D_002A5530->Reset1B4D28();
    q->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x18)));
    D_002A5530->SetUnk4C(((CMenuRecordWinF2 *)m_win)->m_unk34);
    m_win->Func1A39A8(&sx, (s32 *)&sy, 0x54);
    D_002A5530->SetUnk30(sx / 100.0f, sy / 100.0f, 0.0f, 0.0f);
    m_win->Func1A39A8(&bx, (s32 *)&by, 0x53);
    {
        s32 i;
        for (i = a; i < a + b; i++) {
            if (m_items[i].m_unk3C <= 0) continue;
            if (m_items[i].m_unk40) {
                D_002A5530->SetUnk40(1.0f, 1.0f, 1.0f, ((CMenuRecordWinF2 *)m_win)->m_unk34);
            } else {
                D_002A5530->SetUnk40(0.5f, 0.5f, 0.5f, ((CMenuRecordWinF2 *)m_win)->m_unk34);
            }
            m_win->Func1A39A8(&px, (s32 *)&py, PageRow(i) + 0x45);
            D_002A5530->SetUnk20(px + bx + m_ofsX, py + by + m_ofsY, 0.0f);
            q->Func237E90(func_001B50B0(D_002A5530, 0x18));
        }
    }
    D_002A5534->Reset();
    D_002A5534->SetUnk30(1);
    D_002A5534->SetUnk1C(((CMenuRecordWinF2 *)m_win)->m_unk34);
    q->Func237E90(func_001B5E18(D_002A5534));
    m_win->Func1A39A8(&sx, (s32 *)&sy, 0x56);
    D_002A5534->SetUnk0(sx / 100.0f, sy / 100.0f);
    m_win->Func1A39A8(&bx, (s32 *)&by, 0x55);
    {
        s32 j;
        for (j = a; j < a + b; j++) {
            if (m_items[j].m_unk3C <= 0) continue;
            if (m_items[j].m_unk40) {
                D_002A5534->SetUnk10(0.78f, 0.78f, 0.78f);
            } else if (D_002A26E4->Func1091B0(0x1C) < m_items[j].m_unk3C) {
                D_002A5534->SetUnk10(D_002A5380[0] * 0.5f, D_002A5380[1] * 0.5f, D_002A5380[2] * 0.5f);
            } else {
                D_002A5534->SetUnk10(0.39f, 0.39f, 0.39f);
            }
            m_win->Func1A39A8(&px, (s32 *)&py, PageRow(j) + 0x45);
            sprintf(buf, D_002DD808, m_items[j].m_unk3C);
            q->Func237E90(func_001B5FE0(D_002A5534, buf, px + bx + m_ofsX, py + by + m_ofsY));
        }
    }
    Func225088();
    Func225240((s32)pp);
    Func2250C0();
}

int CMenuRecordList::Func197FA8() {
    char buf[256];
    f32 x, y;
    m_win->Func1A39A8(&x, (s32 *)&y, 0x30);
    s32 row = RowOf(m_cursor) + 1;
    sprintf(buf, D_002DD810, row, NumRows());
    D_002A5534->Reset();
    D_002A5534->SetUnk30(1);
    D_002A5534->SetUnk10(0.78f, 0.78f, 0.78f);
    D_002A5534->SetUnk1C(((CMenuRecordWinF *)m_win)->m_unk34);
    return func_001B5FE0(D_002A5534, buf, x + m_ofsX, y + m_ofsY);
}
INCLUDE_RODATA("asm/nonmatchings/CCommandBase", D_002DD7D8);
INCLUDE_RODATA("asm/nonmatchings/CCommandBase", D_002DD7F8);
INCLUDE_RODATA("asm/nonmatchings/CCommandBase", D_002DD800);
INCLUDE_RODATA("asm/nonmatchings/CCommandBase", D_002DD808);
INCLUDE_RODATA("asm/nonmatchings/CCommandBase", D_002DD810);
INCLUDE_RODATA("asm/nonmatchings/CCommandBase", D_002DD818);
INCLUDE_RODATA("asm/nonmatchings/CCommandBase", D_002DD820);
INCLUDE_RODATA("asm/nonmatchings/CCommandBase", D_002DD838);
INCLUDE_RODATA("asm/nonmatchings/CCommandBase", D_002DD858);
INCLUDE_RODATA("asm/nonmatchings/CCommandBase", D_002DD878);
INCLUDE_RODATA("asm/nonmatchings/CCommandBase", D_002DD8A0);
INCLUDE_RODATA("asm/nonmatchings/CCommandBase", D_002DD8C8);
INCLUDE_RODATA("asm/nonmatchings/CCommandBase", D_002DD8F0);

CCommandBase::CCommandBase() {
    s32 i;
    m_win = D_002A5408->Func1A0CF0(D_002DD818);
    if (m_win) {
        m_win->Func1A3378();
        m_state = 0;
        for (i = 0; i < 16; i++) {
            m_recs[i].m0 = 0;
        }
        m_num = 0;
        m_cursor = 0;
        m_unk4D8 = 0;
        m_unk4DC = m_unk4E0 = 0.0f;
        m_unk4E4 = 0;
    }
}

void CCommandBase::SetMode198128(s32 mode) {
    char str[0x200];
    char buf[0x200];
    if (m_win == 0) return;
    switch (mode) {
    case 0:
        func_001A3DC8(m_win, 4, 1);
        func_001A3DC8(m_win, 5, 0);
        func_001A3DC8(m_win, 6, 1);
        func_001864A8(buf);
        sprintf(str, func_001A36B0(m_win, 6), buf);
        ((CMenuRecordWin *)m_win)->Func1A3740(6, str);
        break;
    case 1:
        func_001A3DC8(m_win, 4, 0);
        func_001A3DC8(m_win, 5, 1);
        func_001A3DC8(m_win, 6, 0);
        break;
    default:
        CbPrint(D_002DD820, mode);
        break;
    }
}

void CCommandBase::Open() {
    if (m_state) {
        return CbPrint(D_002DD838);
    }
    m_state = 1;
}

void CCommandBase::Close() {
    if (m_state != 2) {
        return CbPrint(D_002DD858);
    }
    m_state = 4;
}

void CCommandBase::Select198290(s32 i) {
    if (m_win == 0) return;
    if ((u32)i >= 19) {
        m_cursor = -1;
    } else {
        m_cursor = i;
        if (i < 3) {
            func_001A3840(m_win, i);
        } else {
            func_001A3840(m_win, func_001971A0(this, i - 3) + 3);
        }
    }
    func_00196E90(this, RowOf(m_cursor));
    m_unk4E4 = 1;
}

int CCommandBase::GetRecC198328(s32 i) {
    if (i < 0 || i > m_num - 1) {
        CbPrint(D_002DD878, i);
        return -1;
    }
    s32 v = m_recs[i].mC;
    if ((u32)(v - 16) >= 9) return -1;
    if (v == 24) {
        if (D_002A26E4->Func1091B0(0x27) == 1) v = 0;
        return v;
    }
    return func_001456A8(v);
}

s32 CCommandBase::GetRec40(s32 i) {
    if (i < 0 || i > m_num - 1) {
        CbPrint(D_002DD8A0, i);
        return 0;
    }
    return m_recs[i].m40;
}

CCommandBaseRec *CCommandBase::GetRec(s32 i) {
    if (i < 0 || i > m_num - 1) {
        CbPrint(D_002DD8C8, i);
        return 0;
    }
    return &m_recs[i];
}

s32 CCommandBase::GetRec4(s32 i) {
    if (i < 0 || i > m_num - 1) {
        CbPrint(D_002DD8F0, i);
        return 0;
    }
    return m_recs[i].m4;
}

s32 CCommandBase::NumRows() {
    if (m_num < 5) {
        return 1;
    }
    return (m_num - 5) / 6 + 2;
}

int CCommandBase::RowOf(int v) {
    if (v < 7) {
        return 0;
    }
    return (v - 7) / 6 + 1;
}

s32 CCommandBase::NextRowItem() {
    if (NumRows() == 1) {
        return -1;
    }
    if (RowOf(m_cursor) == NumRows() - 1) {
        return D_002A5370[0];
    }
    return D_002A5370[RowOf(m_cursor) + 1];
}

s32 CCommandBase::PrevRowItem(s32 wrap) {
    if (NumRows() == 1) {
        return -1;
    }
    if (RowOf(m_cursor) == 0) {
        if (wrap) {
            return D_002A5370[NumRows() - 1];
        }
        return -1;
    }
    return D_002A5370[RowOf(m_cursor) - 1];
}
INCLUDE_RODATA("asm/nonmatchings/CCommandBase", D_002DD918);
