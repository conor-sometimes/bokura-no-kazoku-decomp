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
class CMenuMgrSub1B6BA8 {
public:
    ~CMenuMgrSub1B6BA8();
    void Release1B6F00();
};
class CUnk2A55B0 {
public:
    ~CUnk2A55B0();
    void Free1B7E28();
};
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
class CStatusWin {
public:
    CStatusItem *Func1A0CF0(const char *name);
};
extern CStatusWin *D_002A5408;

class CMenuLoadMemorialSub178778 {
public:
    void Update1789B8();
    int Func1787E8(u32 i, s32 a, s32 b);
    int Draw179198();
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
class CMenuLoadMemorialSub17D160 {
public:
    int Next();
    int Prev();
    void Func17BDF0();
    void Func17BFA0(int v);
    s32 m_state;              // 0x0
    s32 m_unk4;               // 0x4
    s32 m_unk8;               // 0x8
    u8 padC[0xA0];
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
class CMenuRecordWin {
public:
    void Func1A39A8(f32 *v, s32 *n, s32 k);
    void Func1A3740(s32 i, const char *s);
};
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
class CMenuMgrSub1B4768 {
public:
    void SetUnk4C(f32 v);
    s32 GetEntry0(s32 i);
    void Reset1B4D28();
    void SetUnk54(u32 v);
    void SetUnk30(f32 a, f32 b, f32 c, f32 d);
    void SetUnk40(f32 a, f32 b, f32 c, f32 d);
    void SetUnk20(f32 a, f32 b, f32 c);
};
extern "C" int func_001B50B0(CMenuMgrSub1B4768 *p, s32 v);
class CMenuMgrSub1B5BF8 {
public:
    void Reset();
    void SetUnk30(s32 v);
    void SetUnk10(f32 a, f32 b, f32 c);
    void SetUnk1C(f32 v);
    void SetUnk34(s32 v);
    void SetUnk0(f32 a, f32 b);
    void SetUnk5C(s32 v);
};
extern "C" void func_001B5FE0(CMenuMgrSub1B5BF8 *p, const char *s, f32 x, f32 y);
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

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_001787E8);

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

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00178B30);

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

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", Reset__26CMenuLoadMemorialSub179568);

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

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00179438);

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

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00179790);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017A370);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017A828);

CMenuLoadMemorialSub17A8D8::~CMenuLoadMemorialSub17A8D8() {
}

void CMenuLoadMemorialSub17A8D8b::Hide() {
    m_state = 0;
    if (m_items[0]) m_items[0]->Func1A3378();
    if (m_items[1]) m_items[1]->Func1A3378();
    if (m_items[2]) m_items[2]->Func1A3378();
}

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017A968);

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

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", Func17B3E8__26CMenuLoadMemorialSub17B3A0);

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

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017B850);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", Func17BDF0__26CMenuLoadMemorialSub17D160);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", Func17BFA0__26CMenuLoadMemorialSub17D160i);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017C2C0);

void CMenuLoadMemorialSub17CAB8b::Create() {
    m_unkC = D_002A5408->Func1A0CF0(D_002DA9A8);
    if (m_unkC) {
        m_unk10 = D_002A5408->Func1A0CF0(D_002DA9B8);
        if (m_unk10) Func17CAE8();
    }
}

CMenuLoadMemorialSub17CAB8::~CMenuLoadMemorialSub17CAB8() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", Func17CAE8__27CMenuLoadMemorialSub17CAB8b);

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

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017CC70);

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

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017D240);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017D3B0);

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
