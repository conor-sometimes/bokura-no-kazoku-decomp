#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMenuRecordWin;
#include "CMenuProcess.h"
#include "CBgWork.h"
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuRecord.
class CMenuRecord : public CMenuProcess {
public:
    CMenuRecord();
    static CMenuRecord *Create();
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
class CCommandBase {
public:
    int RowOf(int v);
    s32 NumRows();
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

class CMenuRecordList : public CCommandBase {
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

extern "C" const char *func_001A36B0(CMenuRecordWin *w, s32 k);

extern "C" int sprintf(char *buf, const char *fmt, ...);
extern "C" const char *func_001A36B0(CMenuRecordWin *w, s32 k);
extern char D_002DD800[], D_002DD810[], D_002DD928[];
#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
extern "C" void func_00196938(CMenuRecordList *p, s32 i, s32 a, s32 b, s32 c, s32 d, s32 e);
#include "CMenuMgrSub1B5BF8.h"
extern "C" int func_001B5FE0(CMenuMgrSub1B5BF8 *p, const char *s, f32 x, f32 y);
extern CMenuMgrSub1B5BF8 *D_002A5534;
struct CMenuRecordWinF { u8 pad0[0x34]; f32 m_unk34; };

extern "C" void func_001A3DC8(CMenuRecordWin *w, s32 i, s32 v);

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
class CStatusWin {
public:
    f32 GetItemUnk34_2();
};
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
class CMenuLoadMemorialSub17A8D8b {
public:
    int Draw17B1A8();
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

// From CMenuAsksavequit.cpp (lane lb moved its functions 0x1932B8.. here: their literals are this unit's)
#include "CMenuProcess.h"

class CMenuAsksavequitSub193E18 {
public:
    void ClearUnk10();

    u8 pad0[0x10];
    s32 m_unk10;              // 0x10
};
class CMenuAsksavequitSub193FC0 {
public:
    u64 SwapUnk0(u64 v);
    u64 SwapUnk8(u64 v);

    u64 m_unk0;               // 0x0
    u64 m_unk8;               // 0x8
};

extern "C" void func_00194490(void *p);

extern void (*D_002B91B0)(void *p);
class CMenuAsksavequitSub193F80 {
public:
    void Free();
    u8 pad0[0x10];
    void *m_unk10;            // 0x10
};

#include "CChrBodyWin.h"
extern CChrBodyWin *D_002A4308;
extern "C" void func_00189270(void *p, s32 v);
class CMenuLoadMemorialSub17A8D8 {
public:
    ~CMenuLoadMemorialSub17A8D8();
};
class CMenuLoadMemorialSub17CAB8 {
public:
    ~CMenuLoadMemorialSub17CAB8();
};
class CMenuAsksavequitObj {
public:
    void Release194300();
    u8 pad0[0x64];
    void *m_unk64;            // 0x64
    void *m_unk68;            // 0x68
    u8 pad6C[0x4];
    CMenuLoadMemorialSub17CAB8 *m_unk70; // 0x70
    u8 pad74[0x8];
    CMenuLoadMemorialSub17A8D8 *m_unk7C; // 0x7C
};

#include "CMenuMgrSub1B6418.h"
class CUnk1A4298 {
public:
    int Func1A4298();
    u8 pad0[0x34];
    f32 m_unk34;              // 0x34
    f32 GetUnk34() { return m_unk34; }
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
extern CMenuMgrSub1B6418 *D_002A5538;
extern "C" u8 *func_00237570(s32 v);
extern "C" void func_00237A88(void *p, s32 v);
extern "C" void *func_00237C30(void *p);
extern "C" int func_00238158(void *p, s32 v);
extern "C" int func_001B66E8(void *p);
void Func225240(s32 v);
class CMenuAsksavequitWin {
public:
    CMenuAsksavequitWin(int n);
    int Func193D68();
    u8 pad0[0x48];
    CUnk1A4298 *m_unk48;     // 0x48
};

#include "CMenuMgrSub1B4768.h"
extern CMenuMgrSub1B4768 *D_002A5530;
extern "C" int func_001B4ED0(CMenuMgrSub1B4768 *p, s32 v);
extern "C" int func_001B50B0(CMenuMgrSub1B4768 *p, s32 v);
#include "CMenuRecordWin.h"
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuAsksavequit.
class CMenuAsksavequit : public CMenuProcess {
public:
    CMenuAsksavequit();
    virtual ~CMenuAsksavequit();
    virtual void Update();
    virtual s32 Draw();

    CUnk1A4298 *m_unk58;      // 0x58
    s32 m_unk5C;              // 0x5C
};

extern char D_002DD5F0[];
extern char D_002DD600[];
extern char D_002DD610[];
extern char D_002DD630[];
extern char D_002DD648[];
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern "C" void *func_00248E48(const char *name);
extern "C" void func_00253048(void *p, s32 *a, s32 *b, s32 *c, s32 *d, s32 *e, s32 *f, s32 *g, s32 *h);
extern "C" void func_0023C048(s32 a, s32 b, s32 c);
class CMiniGame6Obj {
public:
    int Func247B00();
};
extern "C" CMiniGame6Obj *func_002460C8();
class CMenuAsksavequitImg {
public:
    int Load193E28(const char *name);
    u8 pad0[0x10];
    void *m_handle;           // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
    s32 m_unk24;              // 0x24
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
    s32 m_unk30;              // 0x30
};

// Sound player (global D_002A5468); slot 14 plays a system sound.
class CSePlayer {
public:
    virtual ~CSePlayer();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual int F7(s32 *a, s32 *b, s32 *c);
    virtual void F8();
    virtual void F9();
    virtual void F10();
    virtual void F11();
    virtual void F12();
    virtual void F13();
    virtual void Play(s32 id);
};
extern CSePlayer *D_002A5468;
// Cursor of a selection list (the class is in the next unit; not identified yet).
class CMenuCursorList {
public:
    void Up();
    void Down();

    u8 pad0[0x8C];
    s32 m_cur;                // 0x8C
    s32 m_prev;               // 0x90
    u8 pad94[0x8];
    s32 m_num;                // 0x9C
    u8 padA0[0xA8];
    s32 m_mute;               // 0x148
};

struct CGsTexInfo {
    u64 tbp : 14;
    u64 tbw : 6;
    u64 pad20 : 12;
    u64 psm : 6;
    u64 pad38 : 26;
};
class CMenuAsksavequitTex {
public:
    int Draw193FE0();
    void Draw194140(f32 x, f32 y, f32 s);

    u64 m_tex;                // 0x0
    u64 m_clut;               // 0x8
    u8 pad10[0x4];
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
    s32 m1C;                  // 0x1C
    s32 m20;                  // 0x20
    s32 m24;                  // 0x24
    u8 pad28[0x4];
    s32 m2C;                  // 0x2C
    s32 m30;                  // 0x30
};
void Func225088();
int Func2250C0();
void Func2251E8();
void Func227DC8(long a, s32 b, s32 c);
extern "C" void func_00227BF0(u64 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" void func_00227A20();
extern "C" void func_00227AA8();
extern "C" void func_00226DF8(s32 reg, u64 v);
#define GS_SET_TEX0(tbp, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((u64)(tbp) | ((u64)(tbw) << 14) | ((u64)(psm) << 20) | ((u64)(tw) << 26) | ((u64)(th) << 30) | \
     ((u64)(tcc) << 34) | ((u64)(tfx) << 35) | ((u64)(cbp) << 37) | ((u64)(cpsm) << 51) | \
     ((u64)(csm) << 55) | ((u64)(csa) << 56) | ((u64)(cld) << 61))
#define GS_SET_CLAMP(wms, wmt, minu, maxu, minv, maxv) \
    ((u64)(wms) | ((u64)(wmt) << 2) | ((u64)(minu) << 4) | ((u64)(maxu) << 14) | \
     ((u64)(minv) << 24) | ((u64)(maxv) << 34))

struct CAqSprPkt {
    s32 u0, v0, u1, v1;
    s32 x0, y0, x1, y1;
    s32 r, g, b, a;
};
inline void PutRGBA2(CAqSprPkt *p) { func_00226DF8(1, (u64)p->r | ((u64)p->g << 8) | ((u64)p->b << 16) | ((u64)p->a << 24)); }
inline void PutXYZ2(s32 x, s32 y) { func_00226DF8(5, (u64)x | ((u64)y << 16)); }
inline void PutUV2(s32 u, s32 v) { func_00226DF8(3, (u64)u | ((u64)v << 16)); }

struct AsqWinV { s16 m0; s16 m2; s32 m4; u8 pad8[0x44]; s32 m4C; s32 m50; s32 m54; s32 m58; s32 m5C; };
extern char D_002DBEB0[];
#include "CFlagWork.h"
extern CFlagWork *D_002A5358;

class CStatusItem {
public:
    void Func1A3378();
    void Func1A3628();
    void Start();
    void Func1A40C8();
    int Select(s32 i);
    void SetUnk34(f32 v);
    u8 pad0[0x20];
    s32 m_state;              // 0x20
};
class CStatusWinSub1A0A10 {
public:
    CStatusItem *Find(const char *name);
};
extern CStatusWinSub1A0A10 *D_002A5408;
#include "CFlagWork.h"
extern CFlagWork *D_002A4B60;
// @decl-end

CMenuAsksavequitWin::CMenuAsksavequitWin(int n) {
    AsqWinV *v = (AsqWinV *)this;
    v->m4 = -1; v->m2 = 0; v->m0 = 0;
    if ((u32)n >= 3) { Func235DE0(D_002DBEB0, n); n = 0; }
    v->m50 = n;
    s32 f = D_002A5358->Func1091B0(0xF);
    s32 lim = !v->m50 ? 10 : 20;
    s32 c = f < lim ? f : lim;
    v->m5C = -1; v->m4C = 0; v->m58 = 0;
    v->m54 = c < 1 ? 1 : c;
}

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", Func193358__19CMenuAsksavequitWin);

int CMenuAsksavequitWin::Func193D68() {
    u8 *p = func_00237570(0x40);
    func_00237A88(p, 4);
    func_00238158(func_00237C30(p + 0x30), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unk48->Func1A4298());
    D_002A5538->SetUnk4C(m_unk48->GetUnk34());
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B66E8(D_002A5538));
    Func225088();
    Func225240((s32)p);
    return Func2250C0();
}

void CMenuAsksavequitSub193E18::ClearUnk10() {
    m_unk10 = 0;
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00193E20() {
}

int CMenuAsksavequitImg::Load193E28(const char *name) {
    char path[256];
    int ok = 1;
    sprintf(path, D_002DD5F0, D_002DD600, name);
    void *h = func_00248E48(path);
    if (h == 0) {
        Func235DE0(D_002DD610, path);
        ok = 0;
        func_002460C8()->Func247B00();
    } else {
        m_handle = h;
        func_00253048(h, &m_unk14, &m_unk18, &m_unk1C, &m_unk20, &m_unk24, &m_unk28, &m_unk2C, &m_unk30);
        if (m_unk2C >= 17) func_0023C048(m_unk2C * m_unk30, m_unk24, m_unk24);
        Func235DE0(D_002DD630, path, m_unk1C, m_unk20);
        Func235DE0(D_002DD648, m_unk28, m_unk2C, m_unk30);
    }
    return ok;
}

void CMenuAsksavequitSub193F80::Free() {
    if (m_unk10) {
        D_002B91B0(m_unk10);
        m_unk10 = 0;
    }
}

u64 CMenuAsksavequitSub193FC0::SwapUnk0(u64 v) {
    u64 old = m_unk0;
    m_unk0 = v;
    return old;
}

u64 CMenuAsksavequitSub193FC0::SwapUnk8(u64 v) {
    u64 old = m_unk8;
    m_unk8 = v;
    return old;
}

int CMenuAsksavequitTex::Draw193FE0() {
    Func225088();
    if (m2C > 0) {
        Func227DC8(m_clut, m2C * m30, m24);
    }
    m_tex = (m_tex & ~((u64)0x3F << 32)) | ((u64)(m18 & 0x3F) << 32);
    func_00227BF0(m_tex, 0, 0, m1C, m20, m14);
    func_00227A20();
    func_00226DF8(0x14, 0x60);
    func_00226DF8(6, GS_SET_TEX0(m_tex & 0x3FFF, (m_tex >> 14) & 0x3F, (m_tex >> 32) & 0x3F, 10, 10, 1, 0, m_clut & 0x3FFF, (m_clut >> 32) & 0x3F, 0, 0, 1));
    func_00226DF8(8, GS_SET_CLAMP(2, 2, 0, m1C - 1, 0, m20 - 1));
    func_00227AA8();
    Func2251E8();
    return Func2250C0();
}

void CMenuAsksavequitTex::Draw194140(f32 x, f32 y, f32 s) {
    CAqSprPkt pkt;
    Func225088();
    func_00227A20();
    pkt.a = (s32)(s * 128.0f);
    pkt.u0 = 0;
    pkt.v0 = 0;
    pkt.u1 = m1C << 4;
    pkt.v1 = m20 << 4;
    pkt.x0 = (s32)(x * 16.0f) + 0x6C00;
    pkt.y0 = (s32)(y * 16.0f) + 0x7200;
    pkt.x1 = pkt.x0 + pkt.u1;
    pkt.y1 = pkt.y0 + pkt.v1;
    pkt.b = pkt.g = pkt.r = 0x80;
    func_00226DF8(0, 0x156);
    PutRGBA2(&pkt);
    PutUV2(pkt.u0, pkt.v0);
    PutXYZ2(pkt.x0, pkt.y0);
    PutUV2(pkt.u1, pkt.v1);
    PutXYZ2(pkt.x1, pkt.y1);
    func_00227AA8();
    Func2251E8();
    Func2250C0();
}

CMenuRecord *CMenuRecord::Create() {
    CMenuRecord *p = (CMenuRecord *)operator new(0x158);
    func_00194490(p);
    return p;
}

void CMenuAsksavequitObj::Release194300() {
    if (m_unk68) {
        func_00189270(m_unk68, 3);
        m_unk68 = 0;
    }
    if (m_unk7C) {
        delete m_unk7C;
        m_unk7C = 0;
    }
    if (m_unk70) {
        delete m_unk70;
        m_unk70 = 0;
    }
    if (m_unk64) {
        operator delete(m_unk64);
        m_unk64 = 0;
    }
    D_002A4308->Func188BA8();
}

void CMenuCursorList::Up() {
    if (m_num == 1) {
        return;
    }
    m_prev = m_cur;
    m_cur = m_cur - 1;
    if (m_cur < 0) {
        m_cur = m_num - 1;
    }
    if (m_prev != m_cur && !m_mute) {
        D_002A5468->Play(0x17);
    }
}

void CMenuCursorList::Down() {
    if (m_num == 1) {
        return;
    }
    m_prev = m_cur;
    m_cur = m_cur + 1;
    if (m_num - 1 < m_cur) {
        m_cur = 0;
    }
    if (m_prev != m_cur && !m_mute) {
        D_002A5468->Play(0x17);
    }
}

CMenuRecord::CMenuRecord() {
    m_unk64 = 0;
    m_unk68 = 0;
    m_unk6C = 0;
    m_unk90 = -1;
    m_unk130 = -1;
    m_unk134 = -1;
    m_unk138 = -1;
    m_unk70 = 0;
    m_unk7C = 0;
    m_unk80 = 0;
    m_unk84 = 0;
    m_unk88 = 0;
    m_unk8C = 0;
    m_unk94 = 0;
    m_unk9C = 0;
    m_unk13C = 0;
    m_unk140 = 0;
    m_unk148 = 0;
    m_unk14C = 0;
    m_unk150 = 0;
    m_unk144 = -1;
    m_unk154 = 0;
}

CMenuRecord::~CMenuRecord() {
    func_00245818(&m_bg, 1);
    ((CMenuAsksavequitObj *)this)->Release194300();
}

INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBE80);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBE90);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBEA0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBEB0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBEE0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBF00);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBF20);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBF60);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBF70);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBF80);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBF90);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBFA0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBFB0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBFC0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBFD0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBFE0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DBFF0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC000);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC010);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC028);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC040);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC058);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC070);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC088);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC098);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC0A8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC0B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC0C8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC0D8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC0E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC0F8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC108);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC118);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC130);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC148);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC160);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC178);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC188);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC198);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC1A8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC1B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC1D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC1E0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC1F0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC200);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC210);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC220);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC238);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC250);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC268);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC280);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC298);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC2B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC2D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC2E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC300);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC318);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC330);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC348);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC368);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC388);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC3A8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC3C8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC3E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC408);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC428);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC440);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC458);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC470);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC488);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC4A0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC4B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC4D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC4E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC500);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC518);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC530);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC548);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC560);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC578);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC590);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC5A8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC5C8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC5E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC608);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC628);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC648);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC668);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC688);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC6A8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC6C8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC6E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC708);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC728);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC748);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC760);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC780);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC798);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC7B0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC7C8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC7E0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC7F8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC810);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC830);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC850);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC868);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC880);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC8A0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC8B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC8D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC8E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC900);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC918);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC930);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC948);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC960);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC978);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC990);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC9A0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC9B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC9D8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DC9F0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCA08);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCA28);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCA48);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCA60);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCA78);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCA88);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCA90);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCAA0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCAB0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCAC8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCAD8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCAE8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCB00);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCB18);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCB30);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCB48);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCB58);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCB70);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCB88);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCBA0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCBB8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCBD0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCBE8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCC00);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCC18);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCC30);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCC48);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCC60);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCC78);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCC90);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCCA8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCCC0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCCD8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCCF0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCD08);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCD20);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCD38);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCD50);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCD68);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCD80);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCD98);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCDB0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCDC8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCDD8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCDF0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCE08);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCE20);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCE38);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCE50);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCE68);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCE80);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCE98);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCEB0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCEC8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCEE8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCF00);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCF18);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCF30);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCF48);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCF60);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCF78);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCF90);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCFA8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCFC0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCFD8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DCFF0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD008);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD028);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD040);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD060);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD078);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD090);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD0A8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD0C0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD0E0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD0F8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD110);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD128);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD140);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD158);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD170);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD180);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD198);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD1B0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD1C8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD1E0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD1F8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD210);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD228);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD240);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD258);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD270);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD288);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD2A0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD2B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD2D8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD2F0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD308);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD320);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD338);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD350);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD368);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD380);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD398);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD3B0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD3C0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD3D8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD3E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD3F8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD408);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD418);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD430);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD448);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD460);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD478);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD490);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD4A8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD4C0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD4D8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD4F0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD508);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD520);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD530);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD548);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD560);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD578);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD590);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD5A0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD5B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD5C8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD5D8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD5F0);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD600);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD610);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD630);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD648);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD660);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD668);
INCLUDE_ASM("asm/nonmatchings/CMenuRecord", Update__11CMenuRecord);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD6B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD6D8);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD718);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD730);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD738);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD750);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD758);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD760);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD768);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD770);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD780);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD790);
INCLUDE_RODATA("asm/nonmatchings/CMenuRecord", D_002DD7A0);

s32 CMenuRecord::Draw() {
    f32 x, y;
    f32 w, h;
    f32 dx, dy;
    if (m_unk80 == 0) {
        Func225088();
        Func2250C0();
    } else {
        u8 *pp = Func237570(0x50);
        Func237A88(pp, 5);
        CUnk237E90 *q1 = (CUnk237E90 *)(pp + 0x10);
        Func238158(Func237C30(pp + 0x40), 1);
        q1->Func237E90(func_001A0510((void *)m_unk64));
        switch (m_unk80) {
        case 1:
            q1->Func237E90(((CUnk1A4298 *)m_unk6C)->Func1A4298());
            q1->Func237E90(func_0018A1F0((void *)m_unk68));
            D_002A5538->SetUnk4C(((CStatusWin *)m_unk64)->GetItemUnk34_2());
            q1->Func237E90(((CMenuLoadMemorialSub17A8D8b *)m_unk7C)->Draw17B1A8());
            break;
        case 2:
            q1->Func237E90(((CUnk1A4298 *)m_unk6C)->Func1A4298());
            q1->Func237E90(func_0018A1F0((void *)m_unk68));
            q1->Func237E90(func_0017D3B0((void *)m_unk70));
            break;
        case 3: {
            s32 i;
            if (m_unk148) {
                func_001A3DC8(m_unk74, 2, 0);
                func_001A3DC8(m_unk74, 3, 0);
                func_001A3DC8(m_unk74, 4, 1);
                func_001A3DC8(m_unk74, 5, 1);
            } else {
                func_001A3DC8(m_unk74, 2, 1);
                func_001A3DC8(m_unk74, 3, 1);
                func_001A3DC8(m_unk74, 4, 0);
                func_001A3DC8(m_unk74, 5, 0);
            }
            CUnk237E90 *q2 = (CUnk237E90 *)(pp + 0x20);
            q1->Func237E90(((CUnk1A4298 *)m_unk74)->Func1A4298());
            D_002A5530->SetUnk50(0);
            q2->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x28)));
            D_002A5530->SetUnk30(1.0f, 1.0f, 0.0f, 0.0f);
            D_002A5530->SetUnk40(1.0f, 1.0f, 1.0f, ((CMenuRecordWinF2 *)m_unk74)->m_unk34);
            m_unk74->Func1A39A8(&x, (s32 *)&y, 9);
            m_unk74->Func1A39A8(&dx, (s32 *)&dy, 10);
            for (i = 0; i < 0x24; i++) {
                D_002A5530->SetUnk20(x, y, 0.0f);
                if (i == m_unk144) {
                    q2->Func237E90(func_001B50B0(D_002A5530, 0x27));
                } else if (i < m_unk9C) {
                    q2->Func237E90(func_001B50B0(D_002A5530, 0x28));
                } else {
                    q2->Func237E90(func_001B50B0(D_002A5530, 0x26));
                }
                x += dx;
            }
            if (m_unk134 >= 0 && *(f32 *)&m_unk13C < 1.0f) {
                m_unk78->Func1A39A8(&x, (s32 *)&y, 1);
                m_unk78->Func1A3B58(&w, (s32 *)&h, 0);
                q2->Func237E90(D_002A3680->DrawPhoto(m_unk134, 0x9A9A9A80, x, y, w, h));
            }
            if (m_unk138 >= 0 && 0.0f < *(f32 *)&m_unk13C) {
                m_unk78->Func1A39A8(&x, (s32 *)&y, 1);
                m_unk78->Func1A3B58(&w, (s32 *)&h, 0);
                q2->Func237E90(D_002A3680->DrawPhoto(m_unk138, (s32)(*(f32 *)&m_unk13C * 128.0f) | 0x9A9A9A00, x, y, w, h));
                q1->Func237E90(((CUnk1A4298 *)m_unk78)->Func1A4298());
            }
            if (m_unk140) {
                q2->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(m_unk150 + 0x49)));
                D_002A5530->SetUnk20(544.0f, 280.0f, 0.0f);
                D_002A5530->SetUnk4C(*(f32 *)&m_unk154);
                q2->Func237E90(func_001B50B0(D_002A5530, m_unk150 + 0x49));
            }
            D_002A5538->SetUnk4C(((CMenuRecordWinF2 *)m_unk74)->m_unk34);
            break;
        }
        }
        if (m_unk80 != 3 || m_unk148 == 0) {
            ((CUnk237E90 *)(pp + 0x30))->Func237E90(func_001B66E8(D_002A5538));
        }
        Func225088();
        Func225240((s32)pp);
        Func2250C0();
    }
}

