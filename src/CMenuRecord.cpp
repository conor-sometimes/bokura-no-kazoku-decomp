#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
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
    virtual s32 Update();
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
class CMenuRecordWin {
public:
    void Func1A3740(s32 v, const char *s);
    void Func1A39A8(f32 *v, s32 *n, s32 k);
    void Func1A3B58(f32 *v, s32 *n, s32 k);
};
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

class CStatusWinSub1A40B8 {
public:
    void SetUnk80(f32 x, f32 y);
};

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
class CMenuMgrSub1B5BF8 {
public:
    void SetUnk0(f32 a, f32 b);
    void Reset();
    void SetUnk30(s32 v);
    void SetUnk10(f32 a, f32 b, f32 c);
    void SetUnk1C(f32 v);
};
extern "C" int func_001B5FE0(CMenuMgrSub1B5BF8 *p, const char *s, f32 x, f32 y);
extern CMenuMgrSub1B5BF8 *D_002A5534;
struct CMenuRecordWinF { u8 pad0[0x34]; f32 m_unk34; };

extern "C" void func_001A3DC8(CMenuRecordWin *w, s32 i, s32 v);

class CUnk237E90 {
public:
    int Func237E90(int v);
};
u8 *Func237570(int n);
void Func237A88(void *p, int v);
void *Func237C30(void *p);
int Func238158(void *p, int v);
void Func225240(int v);
class CMenuMgrSub1B4768 {
public:
    void SetUnk50(s32 v);
    void SetUnk30(f32 a, f32 b, f32 c, f32 d);
    s32 GetEntry0(s32 i);
    void Reset1B4D28();
    void SetUnk4C(f32 v);
    void SetUnk20(f32 a, f32 b, f32 c);
    void SetUnk40(f32 a, f32 b, f32 c, f32 d);
    void SetUnk58(u32 v);
};
class CMenuMgr {
public:
    int Func1B4ED0(int v);
};
extern CMenuMgrSub1B4768 *D_002A5530;
extern "C" int func_001B50B0(CMenuMgrSub1B4768 *p, s32 v);
struct CVec2f { f32 x, y; };
struct CMenuRecordWinF2 { u8 pad0[0x34]; f32 m_unk34; };

class CMenuLoadMemorialSub17B3A0 {
public:
    void CallFunc17B3E8();
    void SetUnk40(f32 x, f32 y, s32 v);
    void SetUnk10(f32 x, f32 y);
    void SetUnk20(f32 x, f32 y);
    void SetUnk30(f32 x, f32 y, f32 z, f32 w);
    s32 Draw17B4D8(s32 k);
};
extern CMenuLoadMemorialSub17B3A0 *D_002A3AF8;

extern "C" int func_001A0510(void *p);
extern "C" int func_0018A1F0(void *p);
extern "C" int func_0017D3B0(void *p);
extern "C" int func_001B66E8(void *p);
class CStatusWin {
public:
    f32 GetItemUnk34_2();
};
class CMenuMgrSub1B6418 {
public:
    void SetUnk4C(f32 v);
};
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

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00196938);

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

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_001972E8);

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
