#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern void *D_002A3AF8;

class CStatusItem {
public:
    void Func1A3378();
    void Func1A3628();
    void Start();
};
class CStatusWin {
public:
    CStatusItem *Func1A0CF0(const char *name);
};
extern CStatusWin *D_002A5408;
int Func235DE0(const char *fmt, ...);

class CMenuLoadMemorialSub178778 {
public:
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
    s32 m_unk78[5];           // 0x78
    s32 m_unk8C[5];           // 0x8C
    f32 m_unkA0;              // 0xA0
    s32 m_unkA4;              // 0xA4
    u8 padA8[0x4];
    s32 m_unkAC;              // 0xAC
    f32 m_unkB0;              // 0xB0
    f32 m_unkB4;              // 0xB4
};

class CMenuLoadMemorialSub179568 {
public:
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
    s32 m_unk88[4];           // 0x88
    s32 m_unk98[4];           // 0x98
    f32 m_unkA8;              // 0xA8
    s32 m_unkAC;              // 0xAC
    f32 m_unkB0;              // 0xB0
    f32 m_unkB4;              // 0xB4
};

class CMenuLoadMemorialSub17B3A0 {
public:
    int Init();
    ~CMenuLoadMemorialSub17B3A0();
    void Func17B3E8();
    void CallFunc17B3E8();
    void SetUnk40(f32 x, f32 y, s32 v);
    void SetUnk10(f32 x, f32 y);
    void SetUnk20(f32 x, f32 y);
    void SetUnk30(f32 x, f32 y, f32 z, f32 w);
    void SetUnk3C(f32 v);

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
class CFlagWork {
public:
    int Func1091B0(int id);
};
extern CFlagWork *D_002A26E4;
extern CFlagWork *D_002A5358;
extern char D_002DA7B0[], D_002DA7C0[], D_002DA7E8[], D_002DA808[], D_002DA830[], D_002DA840[], D_002DA868[], D_002DA898[], D_002DA900[], D_002DA9A8[], D_002DA9B8[];
void *operator new(unsigned int n);
class CMenuLoadMemorialSub17A8D8b {
public:
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
int MemorialMenuFunc17B4A0();

inline f32 Clamp01(f32 v) { return (v < 1.0f ? v : 1.0f) < 0.0f ? 0.0f : (v < 1.0f ? v : 1.0f); }
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", __17CMenuLoadMemorial);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00176BE0);

INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA648);
INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00176D30);
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
INCLUDE_RODATA("asm/nonmatchings/CMenuLoadMemorial", D_002DA798);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_001785A0);

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

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_001789B8);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00178B30);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00179198);

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

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_001795F8);

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

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017B098);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017B1A8);

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

int MemorialMenuFunc17B4A0() {
    CMenuMgr *m = D_002A5530;
    return m->Func1B4ED0(m->Func1B4CD0(0x35));
}

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017B4D8);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017B680);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017B758);

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

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017DD28);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017DE18);
