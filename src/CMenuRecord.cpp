#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
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
    u8 pad74[0x8];
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
};

class CStatusWinSub1A40B8 {
public:
    void SetUnk80(f32 x, f32 y);
};

class CMenuRecordItem {
public:
    s32 m_timer;              // 0x0
    u8 pad4[0x44];
};

class CMenuRecordList : public CCommandBase {
public:
    void TickItems();
    s32 GetPage();
    s32 PageRow(s32 i);
    s32 PageCol(s32 i);
    void GetRange(s32 *a, s32 *b);
    void GetRange2(s32 *a, s32 *b);
    void SetOffset(s32 on);

    u8 pad1[0x47];
    CMenuRecordWin *m_win;    // 0x48
    u8 pad4C[0xC];
    CMenuRecordItem m_items[15]; // 0x58
    u8 pad490[0x40];
    s32 m_count;              // 0x4D0
    s32 m_cursor;             // 0x4D4
    u8 pad4D8[0x4];
    f32 m_ofsX;               // 0x4DC
    f32 m_ofsY;               // 0x4E0
};
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

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", Draw__11CMenuRecord);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00196938);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00196B50);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00196C70);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00196D78);

void CMenuRecordSub196E68::CallFunc1A3740(s32 v) {
    m_win->Func1A3740(v + 0x24, D_002DD7F8);
}

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00196E90);

int CMenuRecordSub196FC8::IsUnk4D4InWindow() {
    s32 v = m_unk4D4;
    if (v >= 3) {
        if (v < m_unk4D0 + 3) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00196FF8);

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

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_001974F8);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_001976A0);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00197950);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00197AE0);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00197FA8);
