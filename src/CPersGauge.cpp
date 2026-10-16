#include "common.h"

// Menu gauges and widgets after CMenuLoadMemorial (0x178650-0x17DF38: persgauge, intgauge,
// houseaccount, childreport, calendar): their literals and jump table sit between
// 17CMenuLoadMemorial and CMenuTutorSelect's literals, so they are a unit of their own.


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
    virtual void Update();
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

struct CMemSlideItem { u8 pad0[0x20]; s32 m_state; };
struct CMemSlide {
    s32 m_state;              // 0x0
    s32 m4, m8;
    CMemSlideItem *mC;        // 0xC
    CMemSlideItem *m10;       // 0x10
    u8 m14[4];                // 0x14
    f32 m18;                  // 0x18
    u8 pad1C[0xAC - 0x1C];
    f32 mAC;                  // 0xAC
    f32 mB0;                  // 0xB0
};
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA7B0);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA7C0);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA7E8);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA808);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA830);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA840);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA868);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA898);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA8D0);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA900);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA930);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA938);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA948);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA958);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA968);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA970);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA978);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA980);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA9A0);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA9A8);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA9B8);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DA9C8);

int CMenuLoadMemorialSub178778::Create() {
    m_unk0 = D_002A5408->Func1A0CF0(D_002DA7B0);
    return Reset();
}

CMenuLoadMemorialSub178690::~CMenuLoadMemorialSub178690() {
}

int CMenuLoadMemorialSub178778::Reset() {
    int i;
    for (i = 0; i < 5; i++) {
        m_unk8[i] = 0;
        m_unk1C[i] = 0;
        m_unk30[i] = 0;
        m_unk64[i] = 1.0f;
        m_unk78[i] = 0;
        m_unk8C[i] = 0;
    }
    m_unk4 = 0;
    m_unk44 = 0;
    m_unk50 = 0.0f;
    m_unk54 = 0.0f;
    m_unk60 = 0.0f;
    m_unkA0 = 0.25f;
    m_unkA4 = 0;
}

void CMenuLoadMemorialSub178778::SetUnk44(u32 v) {
    if (v >= 3) {
        Func235DE0(D_002DA7C0, v);
        v = 0;
    }
    m_unk44 = v;
}

void CMenuLoadMemorialSub178778::SetUnk4(s32 v) {
    m_unk4 = v;
}

void CMenuLoadMemorialSub178778::SetUnk8(u32 i, u32 v) {
    if (i >= 5) {
        Func235DE0(D_002DA7E8, i);
        return;
    }
    if (v >= 10) {
        Func235DE0(D_002DA808, v);
        return;
    }
    m_unk8[i] = v;
}

INCLUDE_ASM("asm/nonmatchings/CPersGauge", func_001787E8);

void CMenuLoadMemorialSub178778::SetUnk50(f32 x, f32 y) {
    m_unk50 = x;
    m_unk54 = y;
}

void CMenuLoadMemorialSub178778::SetUnk60(f32 v) {
    m_unk60 = Clamp01(v);
}

int CMenuLoadMemorialSub178778::SetUnk64(u32 i, f32 v) {
    if (i >= 5) return Func235DE0(D_002DA7E8, i);
    m_unk64[i] = v;
}

void CMenuLoadMemorialSub178778::Update1789B8() {
    if (m_unk60 != 1.0f) {
        for (s32 i = 0; i < 5; i++) m_unk78[i] = 0.0f;
        return;
    }
    if (!m_unk0) return;
    switch (m_unk44) {
    case 0:
        break;
    case 1: {
        f32 t = func_001865B8(&m_unkA0);
        *(f32 *)&m_unkA4 = t * (f32)func_001A4060(m_unk0, 0x12);
        for (s32 i = 0; i < 5; i++) m_unk78[i] = t;
        break;
    }
    case 2:
        for (s32 i = 0; i < 5; i++) {
            f32 v = m_unk78[i] + m_unk8C[i];
            m_unk78[i] = v;
            if (1.0f <= v) {
                m_unk78[i] = 1.0f;
                m_unk8C[i] = 0.0f;
            } else if (v <= 0.0f) {
                m_unk78[i] = 0.0f;
                m_unk8C[i] = 0.0f;
                m_unk1C[i] = 0;
                m_unk30[i] = 0;
            }
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/CPersGauge", func_00178B30);

int CMenuLoadMemorialSub178778::Draw179198() {
    s32 i;
    u8 *p = Func237570(0x30);
    Func237A88(p, 3);
    CUnk237E90 *q = (CUnk237E90 *)(p + 0x10);
    Func238158(Func237C30(p + 0x20), 1);
    f32 save = m_unk54;
    for (i = 0; i < 5; i++) {
        m_unk54 += func_001A4060(m_unk0, i + 10);
        q->Func237E90(func_00178B30(this, i));
    }
    m_unk54 = save;
    Func225088();
    Func225240((s32)p);
    return Func2250C0();
}

int CMenuLoadMemorialSub179568::Create() {
    m_unk0 = D_002A5408->Func1A0CF0(D_002DA830);
    return Reset();
}

CMenuLoadMemorialSub1792B0::~CMenuLoadMemorialSub1792B0() {
}

int CMenuLoadMemorialSub179568::Reset() {
    m_unk50 = 0; m_unk84 = 0.25f; m_unk54 = 0; m_unk44 = 0; m_unk60 = 0;
    for (s32 i = 0; i < 8; i++) { m_unk4[i] = 0; m_unk64[i] = 1.0f; }
    for (s32 j = 0; j < 4; j++) { m_unk34[j] = 0; m_unk24[j] = 0; m_unk88[j] = 0; m_unk98[j] = 0; }
    m_unkAC = 1;
    m_unkA8 = m_unkB0 = m_unkB4 = 0.0f;
}

void CMenuLoadMemorialSub179568::SetUnk44(u32 v) {
    if (v >= 3) {
        Func235DE0(D_002DA840, v);
        v = 0;
    }
    m_unk44 = v;
}

int CMenuLoadMemorialSub179568::SetUnk4(u32 i, s32 v) {
    if (i >= 8) return Func235DE0(D_002DA868, i);
    m_unk4[i] = v;
}

int CMenuLoadMemorialSub179568::SetUnk34(u32 i, s32 v) {
    if (i >= 4) return Func235DE0(D_002DA898, i);
    m_unk34[i] = v;
}

INCLUDE_ASM("asm/nonmatchings/CPersGauge", func_00179438);

void CMenuLoadMemorialSub178778::SetUnkAC(s32 v) {
    m_unkAC = v;
}

void CMenuLoadMemorialSub178778::SetUnkB0(f32 x, f32 y) {
    m_unkB0 = x;
    m_unkB4 = y;
}

void CMenuLoadMemorialSub179568::SetUnk50(f32 x, f32 y) {
    m_unk50 = x;
    m_unk54 = y;
}

void CMenuLoadMemorialSub179568::SetUnk60(f32 v) {
    m_unk60 = Clamp01(v);
}

int CMenuLoadMemorialSub179568::SetUnk64(u32 i, f32 v) {
    if (i >= 8) return Func235DE0(D_002DA900, i);
    m_unk64[i] = v;
}

void CMenuLoadMemorialSub179568::Update1795F8() {
    if (m_unk60 != 1.0f) {
        for (s32 i = 0; i < 8; i++) m_unk64[i] = m_unk60;
        for (s32 i = 0; i < 4; i++) m_unk88[i] = 0.0f;
        return;
    }
    switch (m_unk44) {
    case 0:
        break;
    case 1: {
        f32 t = func_001865B8(&m_unk84);
        for (s32 i = 0; i < 4; i++) m_unk88[i] = t;
        if (m_unk0) *(f32 *)&m_unkA8 = t * (f32)func_001A4060(m_unk0, 0xB);
        break;
    }
    case 2:
        for (s32 i = 0; i < 4; i++) {
            f32 v = m_unk88[i] + m_unk98[i];
            m_unk88[i] = v;
            if (1.0f <= v) {
                m_unk88[i] = 1.0f;
                m_unk98[i] = 0.0f;
            } else if (v <= 0.0f) {
                m_unk88[i] = 0.0f;
                m_unk98[i] = 0.0f;
                m_unk24[i] = 0;
            }
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/CPersGauge", func_00179790);

int CMenuLoadMemorialSub179568::Draw17A370() {
    f32 col[4];
    f32 cx, cy;
    f32 ex, ey;
    f32 ax, ay;
    CGsRect rect;
    f32 tmp[4];
    s32 i;
    u8 *p = Func237570(0x50);
    Func237A88(p, 5);
    Func238158(Func237C30(p + 0x40), 1);
    f32 save = m_unk54;
    for (i = 0; i < 4; i++) {
        ((CUnk237E90 *)(p + 0x10))->Func237E90(func_00179790(this, i));
        m_unk54 += func_001A4060(m_unk0, 0);
    }
    m_unk54 = save;
    ((CMenuRecordWin *)m_unk0)->Func1A39A8(&ax, (s32 *)&ay, 2);
    ((CMenuRecordWin *)m_unk0)->Func1A39A8(&cx, (s32 *)&cy, 6);
    ((CMenuRecordWin *)m_unk0)->Func1A39A8(&ex, (s32 *)&ey, 7);
    func_001A3EA8((CMenuRecordWin *)m_unk0, col, 6);
    col[3] = m_unk60 * 128.0f;
    {
        s32 m;
    for (m = 0; m < 4; m++) {
        s32 v = m_unk34[m];
        tmp[m] = 0.0f;
        if (v < 0) continue;
        tmp[m] = ex + (v / 100) * 13.0f + (v % 100) / 10;
        Func1866D0(&rect, cx + m_unk50 + ax, cy + ey * m + m_unk54 + ay, 2.0f, ey);
        ((CUnk237E90 *)(p + 0x30))->Func237E90(func_00186730(&rect, col, 0));
        Func1866D0(&rect, cx + tmp[m] + m_unk50 + ax, cy + ey * m + m_unk54 + ay, 2.0f, ey);
        ((CUnk237E90 *)(p + 0x30))->Func237E90(func_00186730(&rect, col, 0));
    }
    }
    {
        s32 j;
    for (j = 0; j < 4; j++) {
        if (m_unk34[j] >= 0) {
            Func1866D0(&rect, cx + m_unk50 + ax, cy + ey * j + m_unk54 + ay, tmp[j] + 2.0f, 2.0f);
            ((CUnk237E90 *)(p + 0x30))->Func237E90(func_00186730(&rect, col, 0));
            break;
        }
    }
    }
    {
        s32 k;
    for (k = 0; k < 4; k++) {
        if (m_unk34[k] < 0) continue;
        if (0.0f <= tmp[k + 1] - tmp[k]) {
            Func1866D0(&rect, cx + tmp[k] + m_unk50 + ax, cy + ey * (k + 1) + m_unk54 + ay, tmp[k + 1] - tmp[k], 2.0f);
        } else {
            Func1866D0(&rect, cx + tmp[k + 1] + m_unk50 + ax, cy + ey * (k + 1) + m_unk54 + ay, tmp[k] - tmp[k + 1] + 2.0f, 2.0f);
        }
        ((CUnk237E90 *)(p + 0x30))->Func237E90(func_00186730(&rect, col, 0));
    }
    }
    Func225088();
    Func225240((s32)p);
    return Func2250C0();
}

INCLUDE_ASM("asm/nonmatchings/CPersGauge", func_0017A828);

CMenuLoadMemorialSub17A8D8::~CMenuLoadMemorialSub17A8D8() {
}

void CMenuLoadMemorialSub17A8D8b::Hide() {
    m_state = 0;
    if (m_items[0]) m_items[0]->Func1A3378();
    if (m_items[1]) m_items[1]->Func1A3378();
    if (m_items[2]) m_items[2]->Func1A3378();
}

void CMenuLoadMemorialSub17A8D8b::Refresh17A968() {
    char out[0x100];
    char num[0x100];
    char num2[0x100];
    CTextBuf tb;
    char buf[0x100];
    CMemorialIds ids;
    f32 col[4];
    s32 i;
    tb.Clear();
    if (m_items[0]) {
        CMenuRecordWin *w;
        if (D_002A26E4->Vf2991E8() == 0) {
            const char *s1 = func_00256260(&tb, D_002A26E4->Vf2991B0() + 0xAD);
            sprintf(buf, D_002DA968, func_00256260(&tb, 0xAA), s1);
        } else if (D_002A26E4->Vf2991E8() == 0x23) {
            const char *s1 = func_00256260(&tb, D_002A26E4->Vf2991B0() + 0xAD);
            sprintf(buf, D_002DA968, func_00256260(&tb, 0xAB), s1);
        } else {
            const char *s1 = func_00256260(&tb, D_002A26E4->Vf2991B0() + 0xAD);
            const char *n = func_0024BA08(num, D_002A26E4->Vf2991E8() + 1);
            sprintf(buf, D_002DA970, n, func_00256260(&tb, 0xAC), s1);
        }
        {
            const char *n = func_0024BA08(num, D_002A26E4->Vf299218());
            sprintf(out, func_001A36B0((CMenuRecordWin *)m_items[0], 0x15), buf, n);
            ((CMenuRecordWin *)m_items[0])->Func1A3740(0x15, out);
        }
        {
            s32 v = D_002A26E4->Get145118();
            const char *fmt = func_001A36B0((CMenuRecordWin *)m_items[0], 0x16);
            const char *hi;
            if (v >= 10) hi = func_0024BA08(num, v / 10);
            else hi = D_002DA978;
            sprintf(out, fmt, hi, func_0024BA08(num2, v % 10));
            ((CMenuRecordWin *)m_items[0])->Func1A3740(0x16, out);
        }
        ids = D_002DA980;
        {
            s32 j;
            for (j = 0; j < 5; j++) {
                const char *fmt = func_001A36B0((CMenuRecordWin *)m_items[0], j + 0x17);
                sprintf(out, fmt, func_0024BA08(num, D_002A26E4->Func1091B0(ids.v[j])));
                ((CMenuRecordWin *)m_items[0])->Func1A3740(j + 0x17, out);
            }
        }
        {
            const char *fmt = func_001A36B0((CMenuRecordWin *)m_items[0], 0x1C);
            s32 a = D_002A26E4->Func1091B0(0x1F);
            s32 b = D_002A26E4->Func1091B0(0x20);
            s32 c = D_002A26E4->Func1091B0(0x21);
            sprintf(out, fmt, func_0024BA08(num, a + b + c));
            ((CMenuRecordWin *)m_items[0])->Func1A3740(0x1C, out);
        }
        for (i = 0; i < 3; i++) {
            s32 a, b;
            col[3] = 128.0f;
            if (D_002A26E4->Func1091B0(9)) {
                a = D_002A26E4->Func1091B0(i + 0xD);
                b = D_002A26E4->Func1091B0(i + 0x10);
            } else {
                a = D_002A26E0->Get143F20(i);
                b = D_002A26E0->Func1091B0(i + 0xA);
            }
            if (!a) {
                col[0] = col[1] = col[2] = 64.0f;
            } else {
                col[0] = col[1] = col[2] = 128.0f;
            }
            func_001A3E28((CMenuRecordWin *)m_items[0], i + 0x1D, col);
            func_001A3E28((CMenuRecordWin *)m_items[0], i + 0x12, col);
            if (a == 0) {
                sprintf(out, func_001A36B0((CMenuRecordWin *)m_items[0], i + 0x20));
            } else {
                const char *fmt = func_001A36B0((CMenuRecordWin *)m_items[0], i + 0x1D);
                const char *nb = func_0024BA08(num, b);
                sprintf(out, fmt, nb, func_0024BA08(num2, a));
            }
            ((CMenuRecordWin *)m_items[0])->Func1A3740(i + 0x1D, out);
        }
    }
    if (m_items[1]) {
        const char *fmt = func_001A36B0((CMenuRecordWin *)m_items[1], 2);
        const char *n = func_0024BA08(num, D_002A26E4->Func1091B0(1));
        sprintf(out, fmt, n, func_00256260(&tb, D_002A26E4->Func1091B0(0x16) + 4));
        ((CMenuRecordWin *)m_items[1])->Func1A3740(2, out);
    }
    if (m_items[2]) {
        const char *fmt = func_001A36B0((CMenuRecordWin *)m_items[2], 3);
        sprintf(out, fmt, func_0024BA08(num, D_002A26E4->Func1091B0(0x1C)));
        ((CMenuRecordWin *)m_items[2])->Func1A3740(3, out);
    }
}

void CMenuLoadMemorialSub17A8D8b::Func17AFC8() {
    m_state = 1;
    if (m_items[0]) m_items[0]->Func1A3628();
    if (m_items[1]) m_items[1]->Func1A3628();
    if (m_items[2]) m_items[2]->Func1A3628();
}

void CMenuLoadMemorialSub17A8D8b::Start() {
    m_state = 3;
    if (m_items[0]) m_items[0]->Start();
    if (m_items[1]) m_items[1]->Start();
    if (m_items[2]) m_items[2]->Start();
}

void CMenuLoadMemorialSub17A8D8b::Update() {
    switch (m_state) {
    case 0:
        break;
    case 1:
        if (m_items[0]->m_state == 2 && m_items[1]->m_state == 2 && m_items[2]->m_state == 2) {
            m_state = 2;
        }
        break;
    case 2:
        break;
    case 3:
        if (m_items[0]->m_state == 0 && m_items[1]->m_state == 0 && m_items[2]->m_state == 0) {
            m_state = 0;
        }
        break;
    }
    if (m_items[0]) {
        func_001A40C8(m_items[0]);
    }
    if (m_items[1]) {
        func_001A40C8(m_items[1]);
    }
    if (m_items[2]) {
        func_001A40C8(m_items[2]);
    }
}

void CMenuLoadMemorialSub17A8D8b::Draw17B1A8() {
    f32 x, y;
    u8 *p = Func237570(0x40);
    Func237A88(p, 4);
    Func238158(Func237C30(p + 0x30), 1);
    if (m_items[0]) ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_items[0])->Func1A4298());
    if (m_items[1]) ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_items[1])->Func1A4298());
    if (m_items[2]) ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_items[2])->Func1A4298());
    if (m_items[0]) {
        s32 i;
        CUnk237E90 *q = (CUnk237E90 *)(p + 0x20);
        q->Func237E90(D_002A5530->Func1B4ED0(((CMenuMgrSub1B4768 *)D_002A5530)->GetEntry0(0x18)));
        ((CMenuMgrSub1B4768 *)D_002A5530)->Reset1B4D28();
        ((CMenuMgrSub1B4768 *)D_002A5530)->SetUnk4C(((CUnk1A4298 *)m_items[0])->m_unk34);
        ((CMenuMgrSub1B4768 *)D_002A5530)->SetUnk30(0.65f, 0.65f, 0.0f, 0.0f);
        for (i = 0; i < 3; i++) {
            ((CMenuRecordWin *)m_items[0])->Func1A39A8(&x, (s32 *)&y, i + 0x23);
            ((CMenuMgrSub1B4768 *)D_002A5530)->SetUnk20(x, y, 0.0f);
            q->Func237E90(func_001B50B0((CMenuMgrSub1B4768 *)D_002A5530, 0x18));
        }
    }
    Func225088();
    Func225240((s32)p);
    Func2250C0();
}

CMenuLoadMemorialSub17B3A0 *NewMemorialSub17B3A0() {
    CMenuLoadMemorialSub17B3A0 *p = (CMenuLoadMemorialSub17B3A0 *)operator new(0x50);
    p->Init();
    return p;
}

// Returns int but has no return statement (keeps $v0 free, as in retail).
int CMenuLoadMemorialSub17B3A0::Init() {
    D_002A3AF8 = this;
}

CMenuLoadMemorialSub17B3A0::~CMenuLoadMemorialSub17B3A0() {
    D_002A3AF8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CPersGauge", Func17B3E8__26CMenuLoadMemorialSub17B3A0);

void CMenuLoadMemorialSub17B3A0::CallFunc17B3E8() {
    Func17B3E8();
}

void CMenuLoadMemorialSub17B3A0::SetUnk40(f32 x, f32 y, s32 v) {
    m_unk0 = v;
    m_unk40 = x;
    m_unk44 = y;
}

void CMenuLoadMemorialSub17B3A0::SetUnk10(f32 x, f32 y) {
    m_unk10 = x;
    m_unk14 = y;
}

void CMenuLoadMemorialSub17B3A0::SetUnk20(f32 x, f32 y) {
    m_unk20 = x;
    m_unk24 = y;
}

void CMenuLoadMemorialSub17B3A0::SetUnk30(f32 x, f32 y, f32 z, f32 w) {
    m_unk30 = x;
    m_unk34 = y;
    m_unk38 = z;
    m_unk3C = w;
}

void CMenuLoadMemorialSub17B3A0::SetUnk3C(f32 v) {
    m_unk3C = v;
}

int CMenuLoadMemorialSub17B3A0::Func17B4A0() {
    CMenuMgr *m = D_002A5530;
    return m->Func1B4ED0(m->Func1B4CD0(0x35));
}

s32 CMenuLoadMemorialSub17B3A0::Draw17B4D8(s32 k) {
    s32 id = 0x3F;
    u8 *p = Func237570(0x30);
    Func237A88(p, 3);
    Func238158(Func237C30(p + 0x20), 1);
    if (k != 0x18) id = Func145738(k, 1) + 0x25;
    f32 a = m_unk3C < 0.3f ? m_unk3C : 0.3f;
    ((CMenuMgrSub1B4768 *)D_002A5530)->SetUnk30(m_unk20, m_unk24, 0.0f, 0.0f);
    if (m_unk0) {
        ((CMenuMgrSub1B4768 *)D_002A5530)->SetUnk20(m_unk10 + m_unk40, m_unk14 + m_unk44, 0.0f);
        ((CMenuMgrSub1B4768 *)D_002A5530)->SetUnk40(0.0f, 0.0f, 0.0f, a);
        ((CUnk237E90 *)(p + 0x10))->Func237E90(func_001B50B0((CMenuMgrSub1B4768 *)D_002A5530, id));
    }
    ((CMenuMgrSub1B4768 *)D_002A5530)->SetUnk20(m_unk10, m_unk14, 0.0f);
    ((CMenuMgrSub1B4768 *)D_002A5530)->SetUnk40(m_unk30, m_unk34, m_unk38, m_unk3C);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(func_001B50B0((CMenuMgrSub1B4768 *)D_002A5530, id));
    Func225088();
    Func225240((s32)p);
    return Func2250C0();
}

int MemorialFunc17B680(s32 k, f32 x, f32 y, f32 z, f32 w) {
    ((CMenuMgrSub1B4768 *)D_002A5530)->Reset1B4D28();
    ((CMenuMgrSub1B4768 *)D_002A5530)->SetUnk54(1);
    ((CMenuMgrSub1B4768 *)D_002A5530)->SetUnk30(1.5f, 1.5f, 0.0f, 0.0f);
    ((CMenuMgrSub1B4768 *)D_002A5530)->SetUnk40(1.0f, 1.0f, 1.0f, w);
    ((CMenuMgrSub1B4768 *)D_002A5530)->SetUnk20(x + -4.0f, y + -3.0f, z);
    return func_001B50B0((CMenuMgrSub1B4768 *)D_002A5530, k + 0x2B);
}

void MemorialFunc17B758(s32 v, f32 x, f32 y, f32 a, f32 b) {
    char buf[256];
    D_002A5534->Reset();
    D_002A5534->SetUnk30(1);
    D_002A5534->SetUnk10(0.85f, 0.85f, 0.85f);
    D_002A5534->SetUnk1C(b);
    D_002A5534->SetUnk34(1);
    D_002A5534->SetUnk0(0.8f, 0.8f);
    D_002A5534->SetUnk5C((s32)a);
    sprintf(buf, D_002DA9A0, v);
    func_001B5FE0(D_002A5534, buf, x, y);
}

INCLUDE_ASM("asm/nonmatchings/CPersGauge", func_0017B850);

void CMenuLoadMemorialSub17D160::Func17BDF0() {
    s32 base;
    {
        s32 i;
        for (i = 0xD; i < 0x13; i++) func_001A3DC8(m_unkC, i, 0);
    }
    base = m_unk8 - 6;
    if (base < 0) base = 0;
    {
        s32 j;
        for (j = 0; j < 7 && base + j <= m_unk8; j++) {
            if (D_002A3B70[0] != -1) {
                s32 n = base + j;
                s32 k;
                for (k = 0; D_002A3B70[k] != -1; k++) {
                    if (n == D_002A3B70[k]) func_001A3DC8(m_unkC, j + 0xC, 1);
                }
            }
        }
    }
    if (D_002A26E4->Func1091B0(m_unk4 + 0x46) == 9) {
        s32 a = D_002A26E4->Func1091B0(m_unk4 + 0x34) - D_002A26E4->Func1091B0(m_unk4 + 0x4C);
        s32 j;
        for (j = 0; j < 7 && base + j <= m_unk8; j++) {
            if (a == base + j) func_001A3DC8(m_unkC, j + 0xC, 1);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/CPersGauge", Func17BFA0__26CMenuLoadMemorialSub17D160i);

INCLUDE_ASM("asm/nonmatchings/CPersGauge", func_0017C2C0);

void CMenuLoadMemorialSub17CAB8b::Create() {
    m_unkC = D_002A5408->Func1A0CF0(D_002DA9A8);
    if (m_unkC) {
        m_unk10 = D_002A5408->Func1A0CF0(D_002DA9B8);
        if (m_unk10) Func17CAE8();
    }
}

CMenuLoadMemorialSub17CAB8::~CMenuLoadMemorialSub17CAB8() {
}

INCLUDE_ASM("asm/nonmatchings/CPersGauge", Func17CAE8__27CMenuLoadMemorialSub17CAB8b);

void CMenuLoadMemorialSub17CAB8b::Func17CC00() {
    m_state = 1;
    m_unkC->Func1A3628();
    m_unk10->Func1A3628();
}

void CMenuLoadMemorialSub17CAB8b::Start() {
    m_state = 5;
    m_unkC->Start();
    m_unk10->Start();
}

INCLUDE_ASM("asm/nonmatchings/CPersGauge", func_0017CC70);

int CMenuLoadMemorialSub17D160::Next() {
    m_unk8++;
    if (D_002A26E4->Func1091B0(m_unk4 + 0x34) < m_unk8) {
        m_unk8--;
        return 0;
    }
    Func17BDF0();
    Func17BFA0(m_unk8);
    m_state = 3;
    m_unkAC = 0;
    return 1;
}

int CMenuLoadMemorialSub17D160::Prev() {
    if (m_unk8 < 7) return 0;
    m_unk8--;
    Func17BDF0();
    Func17BFA0(m_unk8);
    m_state = 4;
    m_unkAC = 0;
    return 1;
}

extern "C" void func_0017D240(CMemSlide *p) {
    switch (p->m_state) {
    case 0:
        break;
    case 1:
        if (p->mC->m_state == 2 && p->m10->m_state == 2) p->m_state = 2;
        break;
    case 2:
        p->m18 = func_001865B8(p->m14);
        break;
    case 3: {
        p->m18 = func_001865B8(p->m14);
        f32 t = p->mAC;
        p->mAC = t + 0.12f;
        p->mB0 = (1.0f - t) * 20.0f;
        if (1.0f <= p->mAC) {
            p->mB0 = 0;
            p->m_state = 2;
            p->mAC = 0;
        }
        break;
    }
    case 4: {
        p->m18 = func_001865B8(p->m14);
        f32 t = p->mAC;
        p->mAC = t + 0.12f;
        p->mB0 = (1.0f - t) * -20.0f;
        if (1.0f <= p->mAC) {
            p->mB0 = 0;
            p->m_state = 2;
            p->mAC = 0;
        }
        break;
    }
    case 5:
        if (p->mC->m_state == 0 && p->m10->m_state == 0) p->m_state = 0;
        break;
    }
    if (p->mC) func_001A40C8((CStatusItem *)p->mC);
    if (p->m10) func_001A40C8((CStatusItem *)p->m10);
}
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DAA18);
INCLUDE_RODATA("asm/nonmatchings/CPersGauge", D_002DAA20);

int CMenuLoadMemorialSub17D160::Draw17D3B0() {
    f32 x, y;
    f32 x2, y2;
    char buf[0x100];
    f32 col[4];
    CTextBuf tb;
    f32 z, w;
    u8 *p = Func237570(0x70);
    Func237A88(p, 7);
    Func238158(Func237C30(p + 0x60), 1);
    if (m_unkC) {
        s32 first, cnt;
        s32 i, j, k;
        ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_unkC)->Func1A4298());
        MGR->Reset1B4D28();
        ((CUnk237E90 *)(p + 0x20))->Func237E90(D_002A5530->Func1B4ED0(MGR->GetEntry0(0x44)));
        MGR->SetUnk40(1.0f, 1.0f, 1.0f, ((CUnk1A4298 *)m_unkC)->m_unk34);
        m_unkC->Func1A39A8(&x, (s32 *)&y, 0x1C);
        MGR->SetUnk20(x, y, 0.0f);
        ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B50B0(MGR, 0x44));
        SUB->CallFunc17B3E8();
        ((CUnk237E90 *)(p + 0x20))->Func237E90(SUB->Func17B4A0());
        m_unkC->Func1A39A8(&x, (s32 *)&y, 0x1B);
        SUB->SetUnk10(x, y);
        SUB->SetUnk20(0.95f, 0.95f);
        SUB->SetUnk30(1.0f, 1.0f, 1.0f, ((CUnk1A4298 *)m_unkC)->m_unk34);
        ((CUnk237E90 *)(p + 0x20))->Func237E90(SUB->Draw17B4D8(m_unk4));
        ((CUnk237E90 *)(p + 0x50))->Func237E90(func_001B5E18(D_002A5534));
        D_002A5534->Reset();
        D_002A5534->SetUnk30(1);
        D_002A5534->SetUnk1C(((CUnk1A4298 *)m_unkC)->m_unk34);
        D_002A5534->SetUnk34(1);
        D_002A5534->SetUnk0(0.85f, 0.85f);
        first = m_unk8 - 6;
        if (first < 0) first = 0;
        cnt = m_unk8 - first + 1;
        m_unkC->Func1A39A8(&x2, (s32 *)&y2, 0x1E);
        m_unkC->Func1A39A8(&x, (s32 *)&y, 0x1D);
        func_001A3EA8(m_unkC, col, 0x1D);
        D_002A5534->SetUnk10(col[0] / 255.0f, col[1] / 255.0f, col[2] / 255.0f);
        for (i = 0; i < cnt; i++) {
            sprintf(buf, D_002DA9A0, first + i);
            ((CUnk237E90 *)(p + 0x50))->Func237E90(func_001B5FE0(D_002A5534, buf, x + x2 * i, y));
        }
        D_002A5534->SetUnk0(0.9f, 0.9f);
        m_unkC->Func1A39A8(&x, (s32 *)&y, 0x1F);
        for (j = 0; j < 5; j++) {
            for (k = 0; k < cnt; k++) {
                s32 v = D_002A26E4->Func1091B0(D_002A3B18[j] + k + (first + m_unk4 * 36));
                func_001A3EA8(m_unkC, col, func_001863F0(Func145738(m_unk4, 1), j, v) + 0x20);
                D_002A5534->SetUnk10(col[0] / 255.0f, col[1] / 255.0f, col[2] / 255.0f);
                sprintf(buf, D_002DA9A0, v + 1);
                ((CUnk237E90 *)(p + 0x50))->Func237E90(func_001B5FE0(D_002A5534, buf, x + x2 * k, y + y2 * j));
            }
        }
    }
    if (m_unk10) {
        s32 i;
        ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_unk10)->Func1A4298());
        m_unk10->Func1A39A8(&z, (s32 *)&w, 0x1D);
        for (i = 0; i < 4; i++) {
            s32 f, n;
            f32 a;
            ((CUnk237E90 *)(p + 0x40))->Func237E90(func_0017C2C0(this, i));
            f = D_002A5358->Func1091B0(m_unk4 + 0xD6);
            if (!f) continue;
            if (m_unk8 != D_002A26E4->Func1091B0(m_unk4 + 0x34)) continue;
            n = D_002A26E4->Get144B68(D_002A3B30[i], m_unk4, f);
            if (n <= 0) continue;
            ((CUnk237E90 *)(p + 0x30))->Func237E90(D_002A5530->Func1B4ED0(MGR->GetEntry0(0x45)));
            m_unk10->Func1A39A8(&x, (s32 *)&y, i + 0x24);
            m_unk10->Func1A39A8(&x2, (s32 *)&y2, 0x23);
            MGR->Reset1B4D28();
            MGR->SetUnk40(1.0f, 1.0f, 1.0f, ((CUnk1A4298 *)m_unk10)->m_unk34);
            MGR->SetUnk20(x - x2, y - y2, 0.0f);
            ((CUnk237E90 *)(p + 0x30))->Func237E90(func_001B50B0(MGR, 0x45));
            tb.Clear();
            *(f32 *)&tb.pad40[0] = 0.0f;
            *(f32 *)&tb.pad40[4] = 0.0f;
            *(f32 *)&tb.pad40[8] = 0.0f;
            *(f32 *)&tb.pad40[0xC] = 0.0f;
            tb.m58 = 2;
            *(s32 *)&tb.pad4[0] = 0;
            *(s32 *)&tb.pad40[0x14] = 0;
            *(s32 *)&tb.pad70[0] = 0;
            *(s32 *)&tb.pad40[0x10] = 0;
            tb.m3C = ((CUnk1A4298 *)m_unk10)->m_unk34; tb.m30 = 1.0f; tb.m34 = 1.0f; tb.m38 = 1.0f;
            tb.m18 = tb.m10 = x - 320.0f; tb.m1C = tb.m14 = y - 224.0f;
            func_00256648(&tb);
            func_00256930(&tb, func_00256260(&tb, func_001A4060((CStatusItem *)m_unk10, 0x22)));
            ((CUnk237E90 *)(p + 0x30))->Func237E90(func_00256668(&tb));
            a = ((CUnk1A4298 *)m_unk10)->m_unk34;
            if (D_002A26E4->Func1091B0(D_002A3B50[i].m0 + m_unk4) + D_002A26E4->Func1091B0(D_002A3B50[i].m4 + m_unk4) >= n) {
                if (((CUnk1A4298 *)m_unk10)->m_unk34 == 1.0f) a = 1.9f;
            }
            m_unk10->Func1A39A8(&x, (s32 *)&y, i + 0x28);
            *(s32 *)&tb.pad40[0x10] = 1;
            tb.m30 = 1.0f; tb.m34 = 1.0f; tb.m38 = 1.0f; tb.m3C = a;
            tb.m18 = tb.m10 = x - 320.0f; tb.m1C = tb.m14 = y - 224.0f;
            func_00256648(&tb);
            func_00256988(&tb, D_002DAA18, func_00256260(&tb, func_001A4060((CStatusItem *)m_unk10, 0x22) + 1), n);
            ((CUnk237E90 *)(p + 0x30))->Func237E90(func_00256668(&tb));
        }
    }
    Func225088();
    Func225240((s32)p);
    return Func2250C0();
}

CMenuLoadMemorialSub17DC50 *NewMemorialSub17DC50() {
    CMenuLoadMemorialSub17DC50 *p = (CMenuLoadMemorialSub17DC50 *)operator new(0xA4);
    p->Func17DF38();
    return p;
}

void CMenuLoadMemorialSub17DC50::Init() {
    int i;
    for (i = 5; i >= 0; i--) m_unk80[i] = -1;
    for (i = 0; i < 6; i++) {
        int v = D_002A5358->Func1091B0(i + 0x2A7);
        if (v < 0) break;
        m_unk80[i] = v;
    }
    m_unk7C = i;
}

void CMenuLoadMemorialCal::SetDays(s32 n) {
    s32 i;
    if (m_win) {
        for (i = 0; i < 30; i++) {
            func_001A3DC8(m_win, i, 0);
        }
        func_001A3DC8(m_win, n - 1, 1);
        func_001A3DC8(m_win, n + 5, 1);
        func_001A3DC8(m_win, n + 11, 1);
        func_001A3DC8(m_win, n + 17, 1);
        for (i = 0; i < n; i++) {
            func_001A3DC8(m_win, i + 0x18, 1);
        }
        for (i = 0; i < 6; i++) {
            m_win->Func1A3740(i + 0x23, D_002DAA20);
        }
    }
}

void CMenuLoadMemorialCal::Draw17DE18() {
    f32 v[2];
    u8 *p = Func237570(0x60);
    Func237A88(p, 6);
    CUnk237E90 *q = (CUnk237E90 *)(p + 0x20);
    Func238158(Func237C30(p + 0x50), 1);
    if (m_win) {
        ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_win)->Func1A4298());
        q->Func237E90(D_002A5530->Func1B4ED0(((CMenuMgrSub1B4768 *)D_002A5530)->GetEntry0(0x17)));
        ((CMenuMgrSub1B4768 *)D_002A5530)->Reset1B4D28();
        ((CMenuMgrSub1B4768 *)D_002A5530)->SetUnk4C(((CUnk1A4298 *)m_win)->m_unk34);
        m_win->Func1A39A8(&v[0], (s32 *)&v[1], 0x29);
        ((CMenuMgrSub1B4768 *)D_002A5530)->SetUnk20(v[0], v[1], 0.0f);
        q->Func237E90(func_001B50B0((CMenuMgrSub1B4768 *)D_002A5530, 0x17));
    }
    Func225088();
    Func225240((s32)p);
    Func2250C0();
}
