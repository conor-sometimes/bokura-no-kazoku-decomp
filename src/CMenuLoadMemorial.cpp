#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

// Members and globals shared by the memory-card screens (CMenuLoadMemorial, CMenuSave, CMenuLoad).
extern "C" int func_00245818(void *p, s32 v);
extern "C" int func_001B7EF8(void *p);
class CBgWork {
public:
    CBgWork();
    ~CBgWork();

    u8 pad0[0xC];
};
// Constructor 0x1843D8 (CallFunc184420__18CMenuTutorSelected), destructor 0x1843F0.
class CMenuTutorSelectedSub1843F0 {
public:
    CMenuTutorSelectedSub1843F0();
    ~CMenuTutorSelectedSub1843F0();

    u8 pad0[0x50];
};
// Constructor 0x182070 (Init__27CMenuTutorSelectedSub182108), destructor 0x182098.
class CMenuTutorSelectedSub182098 {
public:
    CMenuTutorSelectedSub182098();
    ~CMenuTutorSelectedSub182098();

    u8 pad0[0x10];
};
#include "CMenuMgrSub1B6BA8.h"
#include "CUnk2A55B0.h"
extern CMenuMgrSub1B6BA8 *D_002A55AC;
extern CUnk2A55B0 *D_002A55B0;

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuLoadMemorial.
class CMenuLoadMemorial : public CMenuProcess {
public:
    CMenuLoadMemorial();
    virtual ~CMenuLoadMemorial();
    virtual s32 Update();
    virtual s32 Draw();

    CBgWork m_bg;             // 0x58
    s32 m_unk64;              // 0x64
    u8 pad68[0x8];
    CMenuTutorSelectedSub1843F0 m_unk70; // 0x70
    CMenuTutorSelectedSub182098 m_unkC0; // 0xC0
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
extern "C" int func_001836E8(void *p);
extern "C" int func_001848E0(void *p);
extern "C" int func_001B66E8(void *p);
extern void *D_002A5538;

extern void *D_002A3AF8;

class CStatusItem {
public:
    void Func1A3378();
    void Func1A3628();
    void Start();

    u8 pad0[0x20];
    s32 m_state;              // 0x20
};
#include "CStatusWin.h"
extern CStatusWin *D_002A5408;

class CMenuLoadMemorialSub178778 {
public:
    void Update1789B8();
    int Func1787E8(u32 i, s32 a, s32 b);
    int Draw179198();
    int DrawRow178B30(s32 k);
    void SetUnk4(s32 v);
    void SetUnk50(f32 x, f32 y);
    void SetUnkAC(s32 v);
    void SetUnkB0(f32 x, f32 y);
    int Create();
    int Reset();
    void SetUnk44(u32 v);
    void SetUnk8(u32 i, u32 v);
    void SetUnk60(f32 v);
    int SetUnk64(u32 i, f32 v);

    CStatusItem *m_unk0;      // 0x0
    s32 m_unk4;               // 0x4
    s32 m_unk8[5];            // 0x8
    s32 m_unk1C[5];           // 0x1C
    s32 m_unk30[5];           // 0x30
    s32 m_unk44;              // 0x44
    u8 pad48[0x8];
    f32 m_unk50;              // 0x50
    f32 m_unk54;              // 0x54
    u8 pad58[0x8];
    f32 m_unk60;              // 0x60
    f32 m_unk64[5];           // 0x64
    f32 m_unk78[5];           // 0x78
    f32 m_unk8C[5];           // 0x8C
    f32 m_unkA0;              // 0xA0
    s32 m_unkA4;              // 0xA4
    u8 padA8[0x4];
    s32 m_unkAC;              // 0xAC
    f32 m_unkB0;              // 0xB0
    f32 m_unkB4;              // 0xB4
};

class CMenuLoadMemorialSub179568 {
public:
    void Update1795F8();
    int Draw17A370();
    int Func179438(u32 i, s32 a);
    void SetUnk50(f32 x, f32 y);
    int Create();
    int Reset();
    void SetUnk44(u32 v);
    int SetUnk4(u32 i, s32 v);
    int SetUnk34(u32 i, s32 v);
    void SetUnk60(f32 v);
    int SetUnk64(u32 i, f32 v);

    CStatusItem *m_unk0;      // 0x0
    s32 m_unk4[8];            // 0x4
    s32 m_unk24[4];           // 0x24
    s32 m_unk34[4];           // 0x34
    s32 m_unk44;              // 0x44
    u8 pad48[0x8];
    f32 m_unk50;              // 0x50
    f32 m_unk54;              // 0x54
    u8 pad58[0x8];
    f32 m_unk60;              // 0x60
    f32 m_unk64[8];           // 0x64
    f32 m_unk84;              // 0x84
    f32 m_unk88[4];           // 0x88
    f32 m_unk98[4];           // 0x98
    f32 m_unkA8;              // 0xA8
    s32 m_unkAC;              // 0xAC
    f32 m_unkB0;              // 0xB0
    f32 m_unkB4;              // 0xB4
};

class CMenuLoadMemorialSub17B3A0 {
public:
    s32 Draw17B4D8(s32 k);
    int Init();
    ~CMenuLoadMemorialSub17B3A0();
    void Func17B3E8();
    void CallFunc17B3E8();
    void SetUnk40(f32 x, f32 y, s32 v);
    void SetUnk10(f32 x, f32 y);
    void SetUnk20(f32 x, f32 y);
    void SetUnk30(f32 x, f32 y, f32 z, f32 w);
    void SetUnk3C(f32 v);
    int Func17B4A0();

    s32 m_unk0;               // 0x0
    u8 pad4[0xC];
    f32 m_unk10;              // 0x10
    f32 m_unk14;              // 0x14
    u8 pad18[0x8];
    f32 m_unk20;              // 0x20
    f32 m_unk24;              // 0x24
    u8 pad28[0x8];
    f32 m_unk30;              // 0x30
    f32 m_unk34;              // 0x34
    f32 m_unk38;              // 0x38
    f32 m_unk3C;              // 0x3C
    f32 m_unk40;              // 0x40
    f32 m_unk44;              // 0x44
};

//@sym __builtin_delete 0x2456A8
// Empty destructors (GCC 2.96 deleting-destructor shape: delete when (in_chrg & 1)).
class CMenuLoadMemorialSub178690 { public: ~CMenuLoadMemorialSub178690(); };
class CMenuLoadMemorialSub1792B0 { public: ~CMenuLoadMemorialSub1792B0(); };
class CMenuLoadMemorialSub17A8D8 { public: ~CMenuLoadMemorialSub17A8D8(); };
class CMenuLoadMemorialSub17CAB8 { public: ~CMenuLoadMemorialSub17CAB8(); };

//@sym Reset__26CMenuLoadMemorialSub178778 0x1786C0
//@sym Reset__26CMenuLoadMemorialSub179568 0x1792E0
class CMenuMgr {
public:
    int Func1B4CD0(int id);
    int Func1B4ED0(int v);
};
extern CMenuMgr *D_002A5530;
#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
extern char D_002DA7B0[], D_002DA7C0[], D_002DA7E8[], D_002DA808[], D_002DA830[], D_002DA840[], D_002DA868[], D_002DA898[], D_002DA900[], D_002DA9A8[], D_002DA9B8[];
void *operator new(unsigned int n);
class CMenuLoadMemorialSub17A8D8b {
public:
    void Draw17B1A8();
    void Create();
    void Update();
    void Hide();
    void Refresh17A968();
    void Func17AFC8();
    void Start();
    s32 m_state;              // 0x0
    CStatusItem *m_items[3];  // 0x4
};
class CMenuLoadMemorialSub17CAB8b {
public:
    void Create();
    void Func17CAE8();
    void Func17CC00();
    void Start();
    s32 m_state;              // 0x0
    u8 pad4[0x8];
    CStatusItem *m_unkC;      // 0xC
    CStatusItem *m_unk10;     // 0x10
};
class CMenuRecordWin;
class CMenuLoadMemorialSub17D160 {
public:
    int Next();
    int Prev();
    void Func17BDF0();
    void Func17BFA0(int v);
    int Draw17D3B0();
    s32 m_state;              // 0x0
    s32 m_unk4;               // 0x4
    s32 m_unk8;               // 0x8
    CMenuRecordWin *m_unkC;   // 0xC
    CMenuRecordWin *m_unk10;  // 0x10
    u8 pad14[0x98];
    s32 m_unkAC;              // 0xAC
};
class CMenuLoadMemorialSub17DC50 {
public:
    void Func17DF38();
    void Init();
    u8 pad0[0x7C];
    s32 m_unk7C;              // 0x7C
    s32 m_unk80[6];           // 0x80
};
CMenuLoadMemorialSub17B3A0 *NewMemorialSub17B3A0();
CMenuLoadMemorialSub17DC50 *NewMemorialSub17DC50();


inline f32 Clamp01(f32 v) { return (v < 1.0f ? v : 1.0f) < 0.0f ? 0.0f : (v < 1.0f ? v : 1.0f); }

extern char D_002DA938[], D_002DA948[], D_002DA958[], D_002DAA20[];
extern "C" void func_001A40C8(CStatusItem *p);
extern "C" void func_001A3DC8(void *p, s32 i, s32 v);
#include "CMenuRecordWin.h"
// Calendar window part (0x17DD28; the class is not identified yet).
class CMenuLoadMemorialCal {
public:
    void Draw17DE18();
    void SetDays(s32 n);

    u8 pad0[0x64];
    CMenuRecordWin *m_win;    // 0x64
};

extern "C" int func_001A4060(CStatusItem *p, s32 k);
extern "C" int func_00178B30(CMenuLoadMemorialSub178778 *p, s32 i);
#include "CMenuMgrSub1B4768.h"
extern "C" int func_001B50B0(CMenuMgrSub1B4768 *p, s32 v);
#include "CMenuMgrSub1B5BF8.h"
extern "C" int func_001B5FE0(CMenuMgrSub1B5BF8 *p, const char *s, f32 x, f32 y);
extern CMenuMgrSub1B5BF8 *D_002A5534;
extern char D_002DA9A0[];
extern "C" int sprintf(char *buf, const char *fmt, ...);

class CUnk1A4298 {
public:
    int Func1A4298();
    u8 pad0[0x34];
    f32 m_unk34;              // 0x34
};

extern "C" f32 func_001865B8(void *p);
s32 Func145738(s32 a, s32 b);

struct CTextBuf;
extern "C" CTextBuf *func_0010BF88(CTextBuf *p);
// Font text object (0x90 bytes; 0x10BF88 initialises it, 0x256xxx draw it).
struct CTextBuf {
    CTextBuf() { func_0010BF88(this); }
    void Clear() { m0 = 0; }
    s32 m0;                   // 0x0
    u8 pad4[0xC];
    f32 m10;                  // 0x10
    f32 m14;                  // 0x14
    f32 m18;                  // 0x18
    f32 m1C;                  // 0x1C
    u8 pad20[0x10];
    f32 m30;                  // 0x30
    f32 m34;                  // 0x34
    f32 m38;                  // 0x38
    f32 m3C;                  // 0x3C
    u8 pad40[0x18];
    s32 m58;                  // 0x58
    u8 pad5C[0x4];
    f32 m60;                  // 0x60
    f32 m64;                  // 0x64
    f32 m68;                  // 0x68
    f32 m6C;                  // 0x6C
    u8 pad70[0x20];
};
extern "C" const char *func_00256260(CTextBuf *p, s32 id);
extern "C" const char *func_0024BA08(char *buf, s32 v);
extern "C" const char *func_001A36B0(CMenuRecordWin *w, s32 k);
extern "C" void func_001A3E28(CMenuRecordWin *w, s32 k, f32 *col);
extern char D_002DA968[], D_002DA970[], D_002DA978[];
struct CMemorialIds { s32 v[5]; };
extern const CMemorialIds D_002DA980;

extern "C" int func_001B5E18(CMenuMgrSub1B5BF8 *p);
extern "C" void func_001A3EA8(CMenuRecordWin *w, f32 *col, s32 k);
extern "C" void func_00256648(CTextBuf *p);
extern "C" void func_00256930(CTextBuf *p, const char *s);
extern "C" void func_00256988(CTextBuf *p, const char *fmt, ...);
extern "C" int func_00256668(CTextBuf *p);
extern "C" u32 func_001863F0(s32 a, s32 b, s32 c);
extern "C" int func_0017C2C0(CMenuLoadMemorialSub17D160 *p, s32 i);
extern s32 D_002A3B18[];
extern s32 D_002A3B30[];
struct CMemorialPair { s32 m0; s32 m4; };
extern CMemorialPair D_002A3B50[];
extern char D_002DAA18[];
#define MGR ((CMenuMgrSub1B4768 *)D_002A5530)
#define SUB ((CMenuLoadMemorialSub17B3A0 *)D_002A3AF8)

struct CGsRect { s32 x0, y0, x1, y1; };
extern "C" void func_001A3EA8(CMenuRecordWin *w, f32 *col, s32 k);
void Func1866D0(CGsRect *r, f32 x, f32 y, f32 w, f32 h);
extern "C" int func_00186730(CGsRect *r, f32 *col, s32 k);
extern "C" int func_00179790(CMenuLoadMemorialSub179568 *p, s32 i);

extern s32 D_002A3B70[];
// @decl-end

CMenuLoadMemorial::CMenuLoadMemorial() {
}

CMenuLoadMemorial::~CMenuLoadMemorial() {
    func_00245818(&m_bg, 1);
    if (D_002A55AC) {
        if (D_002A55B0) {
            while (func_001B7EF8(D_002A55B0)) {
            }
        }
        D_002A55AC->Release1B6F00();
        delete D_002A55AC;
    }
    if (D_002A55B0) {
        D_002A55B0->Free1B7E28();
        delete D_002A55B0;
    }
}

INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA648);
INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", Update__17CMenuLoadMemorial);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA660);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA668);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA670);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA680);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA6A0);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA6E0);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA6F0);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA708);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA718);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA740);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA748);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA758);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA768);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA778);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA788);

s32 CMenuLoadMemorial::Draw() {
    char buf[32];
    u8 *p = Func237570(0x70);
    Func237A88(p, 7);
    Func238158(Func237C30(p + 0x60), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(func_001836E8(&m_unkC0));
    ((CUnk237E90 *)(p + 0x40))->Func237E90(func_001848E0(&m_unk70));
    ((CUnk237E90 *)(p + 0x50))->Func237E90(func_001B66E8(D_002A5538));
    Func225088();
    Func225240((s32)p);
    Func2250C0();
}
