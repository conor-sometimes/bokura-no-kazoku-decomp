#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern void *D_002A53D4;
extern f32 D_002A53D8;
extern f32 D_002A53DC;
extern f32 D_002A53E0;
extern f32 D_002A53E4;

// The object a status window points to at 0x48 (methods at 0x1A3480 on, in CStatusWin.cpp).
class CStatusItem {
public:
    void Start();
    void Func1A3628();


    u8 pad0[0x20];
    s32 m_state;              // 0x20
    u8 pad24[0xC];
    s32 m_unk30;              // 0x30
    f32 m_unk34;              // 0x34
};

// Task-side tag (as CTaskTag8 in CInterfRes.cpp): m4 = -1, m0 = m2 = 0.
struct CStatusTag {
    CStatusTag() {
        m_unk4 = -1;
        m_unk2 = 0;
        m_unk0 = 0;
    }
    s16 m_unk0;               // 0x0
    s16 m_unk2;               // 0x2
    s32 m_unk4;               // 0x4
};

class CStatusBase {
public:
    CStatusBase();
    f32 GetItemUnk34();
    s32 GetItemState();
    void Advance2To3();
    void Func19A8C0();
    void Start();
    void Func19A990();
    void Select19A858(u32 k);
    virtual void Refresh(u32 k);

    CStatusTag m_tag;         // 0x0
    u8 pad8[0x40];
    CStatusItem* m_item;      // 0x48
    s32 m_state;              // 0x4C
    u32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    // vptr 0x58
};

class CStatusBaseSub19AE68 {
public:
    void Init19AC20(s32 kind);
    void Set(s32 v);
    s32 GetUnk18();
    void Func19AE78();
    void Func19AEC0();
    void Func19ADD0(s32 c);

    s32 m_unk0;               // 0x0 (the CStatusItem)
    s32 m_unk4;               // 0x4
    s32 m_unk8;               // 0x8
    f32 m_unkC;               // 0xC
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
};

class CStatusBaseSub19AF50 {
public:
    f32 GetItemUnk34();

    CStatusItem* m_item;      // 0x0
};

struct CStatusHueTable {
    u8 pad0[0xC];
    f32 m_vals[0xFD];         // 0xC
};
struct CVec4 { f32 x, y, z, w; };
class CStatusBaseSub19B8C8 {
public:
    void Init();
    ~CStatusBaseSub19B8C8();
    void Func19C0F0();
    void SetUnk8(u32 v);
    void SetUnk14(s32 i);
    f32 GetHue(s32 a, s32 b);
    void SetUnk18(u32 v);
    void Reset19B938();
    void SetUnk18b(u32 v);

    s32 m_unk0;               // 0x0
    CStatusHueTable *m_unk4;  // 0x4
    s32 m_unk8;               // 0x8
    f32 m_unkC;               // 0xC
    f32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    u32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    f32 m_unk20;              // 0x20
    f32 m_unk24;              // 0x24
    u8 pad28[0x8];
    CVec4 m_unk30[4];   // 0x30
    CVec4 m_unk70[4];   // 0x70
    s32 m_unkB0;              // 0xB0
    s32 m_unkB4;              // 0xB4
    s32 m_unkB8;              // 0xB8
    u8 padBC[0x4];
    s32 m_unkC0;              // 0xC0
    f32 m_unkC4;              // 0xC4
    s32 m_unkC8;              // 0xC8
    s32 m_unkCC;              // 0xCC
};

class CStatusBaseSub19C400 {
public:
    void Init();

    u8 pad0[0x1C];
    s32 m_unk1C;              // 0x1C
    u8 pad20[0xA4];
    f32 m_unkC4;              // 0xC4
    s32 m_unkC8;              // 0xC8
    s32 m_unkCC;              // 0xCC
};

//@sym __builtin_delete 0x2456A8
class CStatusBaseSub19AD40 { public: ~CStatusBaseSub19AD40(); };
class CStatusBaseSub19AD70 {
public:
    void ItemFunc1A3628();
    void ItemStart();

    CStatusItem* m_item;      // 0x0
    u8 pad4[0x14];
    s32 m_unk18;              // 0x18
};

void *operator new(unsigned int n);
int Func235DE0(const char *fmt, ...) throw();
#include "CFlagWork.h"
extern CFlagWork *D_002A4B60;
#include "CChrBodyWin.h"
extern CChrBodyWin *D_002A4308;
extern void (*D_002B91B0)(void *p);
extern char D_002DDCE8[], D_002DDAE8[], D_002DDD10[], D_002DDB18[], D_002DDAB8[], D_002DDD30[], D_002DDD50[];
void Func270C50(CVec4 *dst, const CVec4 *src);
CStatusBaseSub19B8C8 *NewStatusSub19B8C8();
int IsBodyAlphaZero();

inline f32 Clamp01(f32 v) { return (v < 1.0f ? v : 1.0f) < 0.0f ? 0.0f : (v < 1.0f ? v : 1.0f); }
int LerpInt(int a, int b, f32 t);
int StepDigit(int *out, int *p, int base, int range, f32 t);

extern char D_002DDA38[];
// @decl-end

CStatusBase::CStatusBase() {
    m_unk50 = 0;
    m_state = 0;
}

void CStatusBase::Select19A858(u32 k) {
    if (k >= 6) {
        Func235DE0(D_002DDA38, k);
        return;
    }
    if (m_unk50 != k) {
        m_unk50 = k;
        Refresh(k);
    }
}

void CStatusBase::Func19A8C0() {
    if (m_item) {
        m_item->Func1A3628();
        m_state = 1;
    }
}

void CStatusBase::Start() {
    if (m_item) {
        m_item->Start();
        m_state = 4;
    }
}

f32 CStatusBase::GetItemUnk34() {
    return m_item ? m_item->m_unk34 : 0.0f;
}

s32 CStatusBase::GetItemState() {
    return m_item ? m_item->m_state : -1;
}

void CStatusBase::Advance2To3() {
    if (m_state == 2) {
        m_unk54 = 0;
        m_state = 3;
    }
}

void CStatusBase::Func19A990() {
    if (m_state == 3) m_unk54 = D_002A4B60->Func1091B0(0x22);
}

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019A9D8);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019AC20);

CStatusBaseSub19AD40::~CStatusBaseSub19AD40() {
}

void CStatusBaseSub19AD70::ItemFunc1A3628() {
    m_item->Func1A3628();
    m_unk18 = 1;
}

void CStatusBaseSub19AD70::ItemStart() {
    m_item->Start();
    m_unk18 = 4;
}

void CStatusBaseSub19AE68::Func19ADD0(s32 c) {
    if (c < 0 || D_002A26E4->Func1091B0(0x27) - 1 < c) {
        Func235DE0(D_002DDAB8, c);
        c = 0;
    }
    D_002A4308->SetChar(c);
    D_002A4308->SetUnk384(0.0f);
    m_unk1C = 0;
    m_unk14 = c;
}

void CStatusBaseSub19AE68::Set(s32 v) {
    m_unk8 = v;
    m_unk10 = 0;
    m_unkC = 0;
}

void CStatusBaseSub19AE68::Func19AE78() {
    if (m_unk18 != 2) Func235DE0(D_002DDAE8, m_unk18);
    m_unk18 = 3;
}

void CStatusBaseSub19AE68::Func19AEC0() { if ((u32)(m_unk18 - 2) >= 2) Func235DE0(D_002DDB18, m_unk18); m_unk18 = 2; m_unk1C = D_002A4B60->Func1091B0(0x68); D_002A4308->SetUnk384(1.0f); }

s32 CStatusBaseSub19AE68::GetUnk18() {
    if (m_unk0 == 0) {
        return 0;
    }
    return m_unk18;
}

f32 CStatusBaseSub19AF50::GetItemUnk34() {
    return m_item->m_unk34;
}

int IsBodyAlphaZero() {
    f32 c, d, a, b;
    int r = 0;
    D_002A4308->Func188778(&a, &b, &c, &d);
    if (c == 0.0f) r = 1;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019AFA8);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019B1F8);

CStatusBaseSub19B8C8 *NewStatusSub19B8C8() {
    CStatusBaseSub19B8C8 *p = (CStatusBaseSub19B8C8 *)operator new(0xD0);
    p->Init();
    return p;
}

f32 CStatusBaseSub19B8C8::GetHue(s32 a, s32 b) {
    return m_unk4[a].m_vals[b] / 360.0f;
}

void CStatusBaseSub19B8C8::Init() {
    D_002A53D4 = this;
    m_unk4 = 0;
}

CStatusBaseSub19B8C8::~CStatusBaseSub19B8C8() {
    Func19C0F0();
    D_002A53D4 = 0;
}

void CStatusBaseSub19B8C8::Reset19B938() {
    s32 i;
    f32 z = 0.0f;
    m_unk8 = 0;
    m_unk10 = z;
    m_unkC = z;
    m_unkB0 = 100;
    m_unkB4 = 100;
    m_unkB8 = 100;
    m_unkC0 = 0x10;
    m_unk30[0].x = z;
    m_unk30[0].y = z;
    m_unk30[0].z = z;
    m_unk30[1].x = z;
    m_unk30[1].y = z;
    m_unk30[1].z = z;
    m_unk30[2].x = z;
    m_unk30[2].y = z;
    m_unk30[2].z = z;
    m_unk30[3].x = z;
    m_unk30[3].y = z;
    m_unk30[3].z = z;
    for (i = 0; i < 4; i++) Func270C50(&m_unk70[i], &m_unk30[i]);
    m_unkCC = 0;
    m_unk20 = 0;
    m_unk24 = 0;
    m_unk1C = 0;
    m_unk14 = 0;
    m_unk18 = 1;
}

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019BA00);

void CStatusBaseSub19B8C8::Func19C0F0() {
    if (m_unk4) {
        D_002B91B0(m_unk4);
        m_unk4 = 0;
    }
}

void CStatusBaseSub19B8C8::SetUnk8(u32 v) {
    if (v >= 2) {
        Func235DE0(D_002DDCE8, v);
        v = 0;
    }
    m_unk8 = v;
}

void CStatusBaseSub19B8C8::SetUnk14(s32 i) {
    if (i < 0 || m_unk0 - 1 < i) {
        Func235DE0(D_002DDD10, i);
        return;
    }
    m_unk14 = i;
}

void SetStatusColor(f32 r, f32 g, f32 b, f32 a) {
    D_002A53D8 = r;
    D_002A53DC = g;
    D_002A53E0 = b;
    D_002A53E4 = a;
}

void CStatusBaseSub19B8C8::SetUnk18(u32 v) {
    f32 f;
    if (!m_unkCC) {
        Func235DE0(D_002DDD30, 0);
        return;
    }
    if (v >= 15) {
        Func235DE0(D_002DDD50, v);
        return;
    }
    m_unk18 = v;
    f = GetHue(m_unk14, v);
    if (m_unk20 != f) {
        m_unk1C = 0;
        m_unk20 = f;
        m_unk24 = f;
    }
}

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019C278);

void CStatusBaseSub19C400::Init() {
    m_unk1C = 3;
    m_unkC4 = D_002A53DC;
    m_unkC8 = 0;
    m_unkCC = 2;
}

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019C428);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019C730);

int LerpInt(int a, int b, f32 t) {
    return (int)(((f32)b - (f32)a) * Clamp01(t) + (f32)a + 0.5f);
}

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019CCF8);
