#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CStatusBase {
public:
    f32 GetItemUnk34();
};
class CFlagWork {
public:
    int Func1091B0(s32 id);
};
extern CFlagWork *D_002A464C;

class CStatusBaseSub19AE68 {
public:
    void Set(s32 v);
};

struct CChrBodyEntry {
    s32 m0;                   // 0x0
    void *m4;                 // 0x4
    u8 pad8[0x20];
    void *m28;                // 0x28
    u8 pad2C[0x20];
};
class CChrBodyWin {
public:
    void SetUnk384(f32 v);
    ~CChrBodyWin();
    void Init1883D0();
    void Clear1884B0();
    void GetColor(s32 *rgb, s32 *a);
    int GetFlag187A00(s32 id);
    int Check1888B8();
    void Set189348(s32 a, s32 b);
    void SetChar(s32 c);
    int GetFlag187610(s32 id, s32 k);
    void Open(s32 i);
    int CallFunc1091B0(s32 id);
    void CallFunc188BA8();
    void Func188BA8();
    void SetUnk6C(s32 v);
    void SetMode1();
    void SetMode2();
    void SetMode6();
    void CallSetMode2();
    void Check2To3();
    void Check3To4();
    void SetMode5();
    f32 GetStatusUnk34();

    u8 pad0[0x48];
    s32 m_unk48;              // 0x48
    s32 m_mode;               // 0x4C
    u8 pad50[0x4];
    s32 m_unk54;              // 0x54
    s32 m_unk58b;             // 0x58
    u8 pad5C[0x8];
    CStatusBase* m_status;    // 0x64
    u8 pad68[0x4];
    CStatusBaseSub19AE68* m_unk6C; // 0x6C
    u8 pad70[0x128];
    CChrBodyEntry m_ent[6];   // 0x198
    s32 m_unk360;             // 0x360
    s32 m_unk364;             // 0x364
    s32 m_unk368;             // 0x368
    u8 pad36C[0x4];
    s32 m_unk370;             // 0x370
    f32 m_unk374;             // 0x374
    f32 m_unk378;             // 0x378
    s32 m_unk37C;             // 0x37C
    s32 m_unk380;             // 0x380
    f32 m_unk384;             // 0x384
    s32 m_unk388;             // 0x388
    f32 m_unk38C;             // 0x38C
    f32 m_unk390;             // 0x390
    f32 m_unk394;             // 0x394
    f32 m_unk398;             // 0x398
};

class CChrBodyWinSub188748 {
public:
    u64 SwapUnk188(u64 v);
    u64 SwapUnk190(u64 v);
    void SetUnk388(s32 v);
    void SetUnk380(s32 v);
    void SetUnk374(f32 v);
    void SetUnk378(f32 v);

    u8 pad0[0x188];
    u64 m_unk188;             // 0x188
    u64 m_unk190;             // 0x190
    u8 pad198[0x1DC];
    f32 m_unk374;             // 0x374
    f32 m_unk378;             // 0x378
    u8 pad37C[0x4];
    s32 m_unk380;             // 0x380
    u8 pad384[0x4];
    s32 m_unk388;             // 0x388
};

//@sym memset 0x289FB0
#include "libc.h"
void *operator new(unsigned int n);
int Func235DE0(const char *fmt, ...);
extern CFlagWork *D_002A4638;
extern CFlagWork *D_002A5358;
extern CFlagWork *D_002A26E4;
extern CChrBodyWin *D_002A4308;
extern void (*D_002B91B0)(void *p);
extern char D_002DB400[], D_002DB380[], D_002DB310[];
class CChrBodySub189270 {
public:
    void Func189270(int v);
};
class CChrBodySub245818 {
public:
    void Func245818(int v);
};
class CChrBodyWinSub18A410 {
public:
    void Init18A480();
    void Close();
    u8 pad0[0x58];
    CChrBodySub245818 m58;    // 0x58
    u8 pad59[0xB];
    CChrBodySub189270 *m64;   // 0x64
    void *m68;                // 0x68
};
CChrBodyWin *NewChrBodyWin();
CChrBodyWinSub18A410 *NewChrBodyWinSub18A410();

inline f32 Clamp01(f32 v) { return (v < 1.0f ? v : 1.0f) < 0.0f ? 0.0f : (v < 1.0f ? v : 1.0f); }
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CChrBodyWin", D_002DAFD0);
INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187038);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187088);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001870B8);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001871C0() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001871C8() {
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001871D0);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001872D8() {
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001872E0);
INCLUDE_RODATA("asm/nonmatchings/CChrBodyWin", D_002DB018);

CChrBodyWin *NewChrBodyWin() {
    CChrBodyWin *p = (CChrBodyWin *)operator new(0x3A0);
    p->Init1883D0();
    return p;
}

int CChrBodyWin::GetFlag187610(s32 id, s32 k) {
    if (m_unk380) {
        if (k == 1) return D_002A464C->Func1091B0(id + 0xB4);
        return D_002A4638->Func1091B0(id + 0xB4);
    }
    return D_002A5358->Func1091B0(id + 0xA0);
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187680);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187758);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001878F8);

int CChrBodyWin::GetFlag187A00(s32 id) {
    if (m_unk380) return D_002A4638->Func1091B0(id + 0xAE);
    return D_002A5358->Func1091B0(id + 0x9A);
}

int CChrBodyWin::CallFunc1091B0(s32 id) {
    return D_002A464C->Func1091B0(id + 0xAE);
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187A68);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187D68);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187ED0);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00188098);

void CChrBodyWin::Init1883D0() {
    D_002A4308 = this;
    m_unk360 = 8;
    m_unk364 = 8;
    m_unk368 = 8;
    m_unk370 = 16;
    m_unk374 = 0.0f;
    m_unk378 = 1.0f;
    m_unk37C = 0;
    m_unk380 = 0;
    m_unk384 = 0.0f;
    m_unk388 = 0;
    m_unk38C = 1.0f;
    m_unk390 = 1.0f;
    m_unk394 = 1.0f;
    m_unk398 = 1.0f;
    memset(this, 0, 0x188);
    Clear1884B0();
    return;
}

CChrBodyWin::~CChrBodyWin() {
    CallFunc188BA8();
    D_002A4308 = 0;
}

void CChrBodyWin::Clear1884B0() {
    int i;
    for (i = 5; i >= 0; i--) m_ent[i].m0 = 0;
    Func188BA8();
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001884F0);

void CChrBodyWin::CallFunc188BA8() {
    Func188BA8();
}

u64 CChrBodyWinSub188748::SwapUnk188(u64 v) {
    u64 old = m_unk188;
    m_unk188 = v;
    return old;
}

u64 CChrBodyWinSub188748::SwapUnk190(u64 v) {
    u64 old = m_unk190;
    m_unk190 = v;
    return old;
}

void CChrBodyWinSub188748::SetUnk388(s32 v) {
    if (v) {
        m_unk388 = v;
    }
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", Func188778__11CChrBodyWinPfN31);

int CChrBodyWin::Check1888B8() {
    int a = GetFlag187A00(m_unk37C);
    if (a != CallFunc1091B0(m_unk37C) && m_unk380) return 1;
    return 0;
}

void CChrBodyWin::GetColor(s32 *rgb, s32 *a) {
    if (rgb) {
        rgb[0] = m_unk360;
        rgb[1] = m_unk364;
        rgb[2] = m_unk368;
    }
    if (a) *a = m_unk370;
}

void CChrBodyWin::Open(s32 i) {
    if (i < 0 || D_002A26E4->Func1091B0(0x27) - 1 < i) Func235DE0(D_002DB310, i);
    else {
        m_ent[i].m0 = 1;
        Func188BA8();
    }
}

void CChrBodyWinSub188748::SetUnk380(s32 v) {
    m_unk380 = v;
}

void CChrBodyWinSub188748::SetUnk374(f32 v) {
    m_unk374 = v;
}

void CChrBodyWinSub188748::SetUnk378(f32 v) {
    m_unk378 = v;
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001889F8);

void CChrBodyWin::Func188BA8() {
    int i;
    for (i = 0; i < 6; i++) {
        if (m_ent[i].m4) {
            D_002B91B0(m_ent[i].m4);
            m_ent[i].m4 = 0;
        }
        if (m_ent[i].m28) {
            D_002B91B0(m_ent[i].m28);
            m_ent[i].m28 = 0;
        }
    }
}

void CChrBodyWin::SetChar(s32 c) {
    if (c < 0 || D_002A26E4->Func1091B0(0x27) - 1 < c) {
        Func235DE0(D_002DB380, c);
        c = 0;
    }
    m_unk37C = c;
}

void CChrBodyWin::SetUnk384(f32 v) {
    m_unk384 = Clamp01(v);
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00188CD8);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00188F30);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00189018);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", _$_12CChrBodyData);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00189348);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001893A0);

void CChrBodyWin::SetUnk6C(s32 v) {
    if (m_unk6C) {
        m_unk6C->Set(v);
    }
}

void CChrBodyWin::SetMode1() {
    m_mode = 1;
}

void CChrBodyWin::SetMode2() {
    m_mode = 2;
}

void CChrBodyWin::SetMode6() {
    m_mode = 6;
}

void CChrBodyWin::CallSetMode2() {
    SetMode2();
}

void CChrBodyWin::Check2To3() {
    if (m_unk48 == 2 && m_unk54) {
        m_mode = 3;
    }
}

void CChrBodyWin::Check3To4() {
    if (m_unk48 == 3) {
        m_mode = 4;
    }
}

void CChrBodyWin::SetMode5() {
    m_mode = 5;
}

f32 CChrBodyWin::GetStatusUnk34() {
    if (m_status) {
        return m_status->GetItemUnk34();
    }
    return 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001895F8);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_0018A1F0);

CChrBodyWinSub18A410 *NewChrBodyWinSub18A410() {
    CChrBodyWinSub18A410 *p = (CChrBodyWinSub18A410 *)operator new(0x94);
    p->Init18A480();
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_0018A410);
