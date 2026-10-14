#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "libc.h"
class CMenuProcess {
public:
    void SetUnk50(s32 v);
    void SetState4();
    void SetState6();
};
class CStatusWinSub1A0A10 {
public:
    void Clear();
};
class CMenuLoadMemorialSub17B3A0 {
public:
    void Func17B3E8();
};
class CChrBodyWin {
public:
    void CallFunc188BA8();
};
class CChrBodyWinSub188748 {
public:
    u64 SwapUnk188(u64 v);
    u64 SwapUnk190(u64 v);
};
class CFlagWork {
public:
    int Func1091B0(s32 id);
};
extern CStatusWinSub1A0A10 *D_002A5408;
extern CMenuLoadMemorialSub17B3A0 *D_002A3AF8;
extern CChrBodyWin *D_002A4308;
extern void *D_002A53D4;
extern CFlagWork *D_002A4B60;
extern void *D_002A26E4;
extern void *D_002A551C;
extern void *D_002A5528;
extern void (*D_002B91B0)(void *p);
void Func235DE0(const char *fmt, ...);
extern "C" void func_002494B0(void *a, void *b);
extern "C" void func_0019C0F0(void *p);
extern "C" void func_0019B938(void *p);
extern "C" void func_001884B0(void *p);
extern "C" void func_001A0C58(void *p);
extern "C" void func_002320A0(s32 v);
extern "C" void func_00108A20(void *p, s32 v);
extern "C" void *func_00248E48(const char *name);

class CUnk2320F8 {
public:
    int Func2320F8();
};

class CUnk2A55B0 {
public:
    s32 Size1B8500();
    void Load1B7D78();
    int Func1B76D0(void *p);
    int Func1B7910();
    static CUnk2A55B0 *Create();
    void Init();
    ~CUnk2A55B0();
    void Free1B7E28();
    int Start1B7E70(s32 a, s32 b);

    s16 m_unk0;               // 0x0
    s16 m_unk2;               // 0x2
    s32 m_unk4;               // 0x4
    u8 pad8[0x40];
    s32 m_unk48;              // 0x48
    s32 m_unk4C;              // 0x4C
    s32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    s32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
    u8 m_unk60[0xC];          // 0x60
    s32 m_unk6C;              // 0x6C
    void *m_unk70;            // 0x70
    u8 pad74[0x100];
    char m_unk174[0x100];     // 0x174
    void *m_unk274;           // 0x274
    void *m_unk278;           // 0x278
    s32 m_unk27C;             // 0x27C
};
extern CUnk2A55B0 *D_002A55B0;

class CSndWork {
public:
    void Func25C648(s32 a, s32 b = 0);
    void Func25C840(s32 a, s32 b = 0, s32 c = 0);
    int Func25C990(s32 a);
    void Func25CB90(s32 a, s32 b, s32 c);
};

class CMenuMgr {
public:
    void SetUnk70(s32 v);
    int GetMenuId();
    void SndFunc25C648(s32 a);
    void SndFunc25C840(s32 a);
    int SndFunc25C990(s32 a);
    void Init1B3FC8();
    void Release1B41B8();
    u64 SwapUnk50(u64 v);
    u64 SwapUnk58(u64 v);
    void ProcState4();
    void ProcState6();
    void SetVolume1B4578(s32 a, f32 v);
    void Start1B4418(u32 id, s32 arg);

    u8 pad0[0x50];
    u64 m_unk50;              // 0x50
    u64 m_unk58;              // 0x58
    CMenuProcess *m_proc;     // 0x60
    s32 m_unk64;              // 0x64
    s32 m_unk68;              // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    CSndWork m_snd;           // 0x74
};

class CMenuMgrSub1B4768Item {
public:
    void *m_ptr;              // 0x0
    u8 pad4[0x20];
};

class CMenuMgrSub1B4768Entry {
public:
    s32 m0;                   // 0x0
    u8 pad4[0x10];
};

// Placeholder for the class of 0x1B4768-0x1B4E28 (name unknown).
class CMenuMgrSub1B4768 {
public:
    static CMenuMgrSub1B4768 *Create();
    ~CMenuMgrSub1B4768();
    void Reset1B47E8();
    void Release1B4BF8();
    s32 GetEntry0(s32 i);
    CMenuMgrSub1B4768Entry *GetEntry(s32 i);
    void Reset1B4D28();
    void SetUnk54(u32 v);
    void SetUnk58(u32 v);
    void Init();
    u64 SwapUnk0(u64 v);
    u64 SwapUnk8(u64 v);
    void SetUnk20(f32 x, f32 y, f32 z);
    void SetUnk30(f32 x, f32 y, f32 z, f32 w);
    void SetUnk40(f32 x, f32 y, f32 z, f32 w);
    void SetUnk4C(f32 v);
    void SetUnk50(s32 v);

    u64 m_unk0;               // 0x0
    u64 m_unk8;               // 0x8
    CMenuMgrSub1B4768Item *m_unk10; // 0x10
    CMenuMgrSub1B4768Entry *m_unk14; // 0x14
    s32 m_unk18;              // 0x18
    s32 m_numEntries;         // 0x1C
    f32 m_unk20;              // 0x20
    f32 m_unk24;              // 0x24
    f32 m_unk28;              // 0x28
    u8 pad2C[0x4];
    f32 m_unk30;              // 0x30
    f32 m_unk34;              // 0x34
    f32 m_unk38;              // 0x38
    f32 m_unk3C;              // 0x3C
    f32 m_unk40;              // 0x40
    f32 m_unk44;              // 0x44
    f32 m_unk48;              // 0x48
    f32 m_unk4C;              // 0x4C
    s32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    s32 m_unk58;              // 0x58
};
// Placeholder for the class of 0x1B5BF8-0x1B5E08 (name unknown).
class CMenuMgrSub1B5BF8 {
public:
    static CMenuMgrSub1B5BF8 *Create();
    ~CMenuMgrSub1B5BF8();
    int Load1B5C88(const char *name);
    void Release1B5D40();
    int Draw1B5F78(f32 x, f32 y, s8 c);
    void Func1B5788(f32 x, f32 y, s8 c);
    void Init();
    void CallReset();
    u64 SwapUnk20(u64 v);
    u64 SwapUnk28(u64 v);
    void Reset();
    void SetUnk0(f32 x, f32 y);
    void SetUnk10(f32 x, f32 y, f32 z);
    void SetUnk1C(f32 v);
    void SetUnk30(s32 v);
    void SetUnk34(s32 v);
    void SetUnk5C(s32 v);

    f32 m_unk0;               // 0x0
    f32 m_unk4;               // 0x4
    u8 pad8[0x8];
    f32 m_unk10;              // 0x10
    f32 m_unk14;              // 0x14
    f32 m_unk18;              // 0x18
    f32 m_unk1C;              // 0x1C
    u64 m_unk20;              // 0x20
    u64 m_unk28;              // 0x28
    s32 m_unk30;              // 0x30
    s32 m_unk34;              // 0x34
    void *m_unk38;            // 0x38
    s32 m_unk3C;              // 0x3C
    s32 m_unk40;              // 0x40
    s32 m_unk44;              // 0x44
    s32 m_unk48;              // 0x48
    s32 m_unk4C;              // 0x4C
    s32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    s32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
};

// Placeholder for the class of 0x1B6418-0x1B6558 (name unknown).
class CMenuMgrSub1B6418Item {
public:
    void *m_ptr;              // 0x0
    s32 m4;                   // 0x4
    s32 m8;                   // 0x8
    s32 mC;                   // 0xC
    s32 m10;                  // 0x10
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
    s32 m1C;                  // 0x1C
    s32 m20;                  // 0x20
};

class CMenuMgrSub1B6418 {
public:
    static CMenuMgrSub1B6418 *Create();
    void Init();
    ~CMenuMgrSub1B6418();
    void Reset1B6300();
    void Release1B63A8();
    int Func1B6158(s32 i);
    int AllReady1B6350();
    void SetUnkDC(u32 v);
    void Move1B6488(f32 x, f32 y);
    void SetUnk58(u32 v);
    u64 SwapUnk60(u64 v);
    u64 SwapUnk68(u64 v);
    void SetUnkE0(s32 v);
    void SetUnk0And20(f32 x, f32 y);
    void SetUnk40(f32 x, f32 y, f32 z, f32 w);
    void SetUnk4C(f32 v);
    void GetDefaultSize(f32 *w, f32 *h);

    f32 m_unk0;               // 0x0
    f32 m_unk4;               // 0x4
    u8 pad8[0x8];
    f32 m_unk10;              // 0x10
    f32 m_unk14;              // 0x14
    u8 pad18[0x8];
    f32 m_unk20;              // 0x20
    f32 m_unk24;              // 0x24
    u8 pad28[0x8];
    f32 m_unk30;              // 0x30
    f32 m_unk34;              // 0x34
    u8 pad38[0x8];
    f32 m_unk40;              // 0x40
    f32 m_unk44;              // 0x44
    f32 m_unk48;              // 0x48
    f32 m_unk4C;              // 0x4C
    s32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    s32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
    u64 m_unk60;              // 0x60
    u64 m_unk68;              // 0x68
    CMenuMgrSub1B6418Item m_items[3]; // 0x70
    s32 m_unkDC;              // 0xDC
    s32 m_unkE0;              // 0xE0
};

class CMenuMgrSub1B74F8 {
public:
    int CallFunc2320F8();

    u8 pad0[0x5C];
    CUnk2320F8 m_unk5C;       // 0x5C
};

// Placeholder for the class of 0x1B6B48-0x1B74F8 (name unknown).
class CMenuMgrSub1B6BA8 {
public:
    void Init1B6DA8();
    int Check1B7428(u32 i);
    static CMenuMgrSub1B6BA8 *Create();
    void Init();
    ~CMenuMgrSub1B6BA8();
    void Release1B6F00();
    s32 GetUnkC(u32 i);
    s32 Calc1B7118(u32 i);
    void Func1B72E0(u32 i);
    void SetUnk34(u32 i, s32 v);
    s32 GetUnk34(u32 i);
    int AllSet1B73E8();
    void Alloc1B6CA8();

    s32 m_unk0;               // 0x0
    void *m_unk4;             // 0x4
    s32 m_unk8;               // 0x8
    s32 m_unkC[10];           // 0xC
    s32 m_unk34[10];          // 0x34
    u8 pad5C[0x8];
    void *m_unk64;            // 0x64
};

extern CMenuMgrSub1B4768 *D_002A5530;
extern CMenuMgrSub1B5BF8 *D_002A5534;
extern CMenuMgrSub1B6418 *D_002A5538;
extern CMenuMgrSub1B6BA8 *D_002A55AC;

//@sym SetUnk54__17CMenuMgrSub1B4768Ui 0x1B4DA8
//@sym SetUnk58__17CMenuMgrSub1B4768Ui 0x1B4E30
//@sym Release1B4BF8__17CMenuMgrSub1B4768 0x1B4BF8
//@sym Release1B6F00__17CMenuMgrSub1B6BA8 0x1B6F00
//@sym Reset1B6300__17CMenuMgrSub1B6418 0x1B6300
//@sym Reset1B47E8__17CMenuMgrSub1B4768 0x1B47E8
//@sym __builtin_new 0x245648
//@sym Init__17CMenuMgrSub1B6BA8 0x1B6BA8
extern char D_002DFEE0[];
extern char D_002DFEF8[];
extern char D_002E0008[];
extern char D_002E0030[];
extern char D_002E0350[];
extern char D_002E0380[];
extern char D_002E0470[];
extern char D_002E0498[];
extern char D_002E0508[];
extern char D_002E0530[];
extern char D_002E0560[];
extern char D_002DFFD8[];
extern char D_002E0060[];
extern char D_002E03C8[];
extern char D_002E03E8[];
extern char D_002E03F8[];
extern char D_002E0270[];
extern char D_002E0298[];
extern char D_002E02B8[];
void Func2251E8();
int Func2250C0();
void Func225088();
extern "C" void func_00253048(void *p, s32 *a, s32 *b, s32 *c, s32 *d, s32 *e, s32 *f, s32 *g, s32 *h);

//@sym Init__10CUnk2A55B0 0x1B7C10
//@sym Free1B7E28__10CUnk2A55B0 0x1B7E28
//@sym Start1B7E70__10CUnk2A55B0ii 0x1B7E70
//@sym Release1B6F00__17CMenuMgrSub1B6BA8 0x1B6F00
//@sym Alloc1B6CA8__17CMenuMgrSub1B6BA8 0x1B6CA8
extern "C" unsigned int strlen(const char *s);
extern char D_002DFEA0[];
extern char D_002DFEB8[];
extern char D_002E03C8[];
extern char D_002E03E8[];
extern char D_002E0408[];
extern char D_002E0428[];
extern char D_002E0448[];
extern char D_002E02D0[];
extern char D_002E02F0[];
extern char D_002E0318[];
extern char D_002E0338[];
extern char D_002E0740[];
extern char D_002E0760[];
extern char D_002E07A8[];
extern char D_002E07D8[];
extern char D_002A5540[][32];
extern void *D_002A26E0;
extern CUnk2A55B0 *D_002A55B0;
extern CMenuProcess *(*D_002A5470[])(CMenuMgr *mgr, u32 id);
extern "C" s32 func_001089D0(void *p, s32 v);
extern "C" void *func_00245DD0(s32 size);
extern "C" char *func_00235D80();
extern "C" void func_001ED960(void *p);
extern "C" void func_00253048(void *p, s32 *a, s32 *b, s32 *c, s32 *d, s32 *e, s32 *f, s32 *g, s32 *h);

extern "C" unsigned int strlen(const char *s);
extern char D_002E0740[];
extern char D_002E0760[];
extern char D_002E07A8[];
extern char D_002E07D8[];
extern char D_002DFEA0[];
extern char D_002DFEB8[];
extern char D_002E02D0[];
extern char D_002E02F0[];
extern char D_002E0318[];
extern char D_002E0338[];
extern char D_002A5540[][32];
extern CMenuProcess *(*D_002A5470[])(CMenuMgr *mgr, u32 id);
extern "C" char *func_00235D80();
extern "C" void func_001ED960(void *p);
//@sym __builtin_new 0x245648
extern char D_002DFEE0[];
extern char D_002DFEF8[];
extern char D_002E0008[];
extern char D_002E0030[];
extern char D_002E0350[];
extern char D_002E0380[];
extern char D_002E0470[];
extern char D_002E0498[];
extern char D_002E0508[];
extern char D_002E0530[];
extern char D_002E0560[];
extern char D_002DFFD8[];
extern char D_002E0060[];
extern char D_002E03C8[];
extern char D_002E03E8[];
extern char D_002E03F8[];
extern char D_002E0270[];
extern char D_002E0298[];
extern char D_002E02B8[];
void Func2251E8();
int Func2250C0();
void Func225088();
extern "C" void func_00253048(void *p, s32 *a, s32 *b, s32 *c, s32 *d, s32 *e, s32 *f, s32 *g, s32 *h);

extern "C" void func_0022DC90(const char *s);
extern "C" s32 func_0022FF58(const char *s);
extern "C" s32 func_0022DD20();
extern char D_002E0658[];
extern char D_002E0778[];
extern char D_002E0788[];

struct CFlagTmp {
    u8 data[0x20];
};
extern "C" CFlagTmp *func_00108320(CFlagTmp *t, s32 a, s32 b);
extern "C" void func_001087F8(CFlagTmp *t, void *w);
extern "C" void func_00108700(CFlagTmp *t);

extern "C" const char *func_00109158(CFlagTmp *t, s32 v);
extern "C" void func_00108370(CFlagTmp *t, s32 v);
extern char D_002E0590[];
extern char D_002E05B8[];

class CMenuMgrSub1B6BA8;
extern "C" s32 func_001EE198(s32 a, s32 b);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", __8CMenuMgr);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B3DD0);

void CMenuMgr::Init1B3FC8() {
    m_unk6C = -1;
    m_unk70 = 1;
    m_proc = 0;
    m_unk64 = 0;
    m_unk68 = 0;
    D_002A5408->Clear();
    D_002A5538->Reset1B6300();
    D_002A5534->CallReset();
    D_002A5530->Reset1B47E8();
    D_002A3AF8->Func17B3E8();
    func_0019B938(D_002A53D4);
    func_001884B0(D_002A4308);
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4050);

void CMenuMgr::Release1B41B8() {
    func_002494B0(D_002A551C, D_002A5528);
    D_002A4308->CallFunc188BA8();
    func_0019C0F0(D_002A53D4);
    D_002A5530->Release1B4BF8();
    D_002A5534->Release1B5D40();
    D_002A5538->Release1B63A8();
    func_001A0C58(D_002A5408);
}

u64 CMenuMgr::SwapUnk50(u64 v) {
    u64 old = m_unk50;
    m_unk50 = v;
    D_002A5538->SwapUnk60(v);
    D_002A5534->SwapUnk20(v);
    D_002A5530->SwapUnk0(v);
    ((CChrBodyWinSub188748 *)D_002A4308)->SwapUnk188(v);
    return old;
}

u64 CMenuMgr::SwapUnk58(u64 v) {
    u64 old = m_unk58;
    m_unk58 = v;
    D_002A5538->SwapUnk68(v);
    D_002A5534->SwapUnk28(v);
    D_002A5530->SwapUnk8(v);
    ((CChrBodyWinSub188748 *)D_002A4308)->SwapUnk190(v);
    return old;
}

void CMenuMgr::SetUnk70(s32 v) {
    m_unk70 = v;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4318);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4418);

int CMenuMgr::GetMenuId() {
    return 0x2B;
}

void CMenuMgr::ProcState4() {
    if (m_proc) {
        m_proc->SetState4();
        Func235DE0(D_002DFEE0);
    }
}

void CMenuMgr::ProcState6() {
    if (m_proc) {
        m_proc->SetState6();
        Func235DE0(D_002DFEF8);
    }
}

void CMenuMgr::SndFunc25C648(s32 a) {
    m_snd.Func25C648(a);
}

void CMenuMgr::SndFunc25C840(s32 a) {
    m_snd.Func25C840(a);
}

void CMenuMgr::SetVolume1B4578(s32 a, f32 v) {
    CSndWork *snd = &m_snd;
    s32 x = (s32)(v * 128.0f);
    if (x >= 0) {
        return snd->Func25CB90(a, x, x);
    }
    snd->Func25CB90(a, x, -x);
}

int CMenuMgr::SndFunc25C990(s32 a) {
    return m_snd.Func25C990(a);
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B45E8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B46C8);

CMenuMgrSub1B4768 *CMenuMgrSub1B4768::Create() {
    CMenuMgrSub1B4768 *p = (CMenuMgrSub1B4768 *)operator new(0x60);
    p->Init();
    return p;
}

void CMenuMgrSub1B4768::Init() {
    D_002A5530 = this;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk54 = 0;
    m_unk58 = 0;
}

CMenuMgrSub1B4768::~CMenuMgrSub1B4768() {
    Release1B4BF8();
    D_002A5530 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", Reset1B47E8__17CMenuMgrSub1B4768);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4820);

void CMenuMgrSub1B4768::Release1B4BF8() {
    if (m_unk14) {
        D_002B91B0(m_unk14);
        m_unk14 = 0;
    }
    if (m_unk10) {
        for (s32 i = 0; i < m_unk18; i++) {
            D_002B91B0(m_unk10[i].m_ptr);
        }
        D_002B91B0(m_unk10);
        m_unk10 = 0;
    }
}

u64 CMenuMgrSub1B4768::SwapUnk0(u64 v) {
    u64 old = m_unk0;
    m_unk0 = v;
    return old;
}

u64 CMenuMgrSub1B4768::SwapUnk8(u64 v) {
    u64 old = m_unk8;
    m_unk8 = v;
    return old;
}

s32 CMenuMgrSub1B4768::GetEntry0(s32 i) {
    if (i < 0 || i > m_numEntries - 1) {
        Func235DE0(D_002DFFD8, i);
        return -1;
    }
    return m_unk14[i].m0;
}

void CMenuMgrSub1B4768::Reset1B4D28() {
    SetUnk54(0);
    SetUnk58(0);
    SetUnk50(1);
    SetUnk30(1.0f, 1.0f, 0.0f, 0.0f);
    SetUnk40(1.0f, 1.0f, 1.0f, 1.0f);
}

void CMenuMgrSub1B4768::SetUnk54(u32 v) {
    if (v >= 3) {
        return Func235DE0(D_002E0008, v);
    }
    m_unk54 = v;
}

void CMenuMgrSub1B4768::SetUnk20(f32 x, f32 y, f32 z) {
    m_unk20 = x;
    m_unk24 = y;
    m_unk28 = z;
}

void CMenuMgrSub1B4768::SetUnk30(f32 x, f32 y, f32 z, f32 w) {
    m_unk30 = x;
    m_unk34 = y;
    m_unk38 = z;
    m_unk3C = w;
}

void CMenuMgrSub1B4768::SetUnk40(f32 x, f32 y, f32 z, f32 w) {
    m_unk40 = x;
    m_unk44 = y;
    m_unk48 = z;
    m_unk4C = w;
}

void CMenuMgrSub1B4768::SetUnk4C(f32 v) {
    m_unk4C = v;
}

void CMenuMgrSub1B4768::SetUnk50(s32 v) {
    m_unk50 = v;
}

void CMenuMgrSub1B4768::SetUnk58(u32 v) {
    if (v >= 4) {
        Func235DE0(D_002E0030, v);
        v = 0;
    }
    m_unk58 = v;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4E70);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001B4EC8() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", Func1B4ED0__8CMenuMgri);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B50B0);

CMenuMgrSub1B5BF8 *CMenuMgrSub1B5BF8::Create() {
    CMenuMgrSub1B5BF8 *p = (CMenuMgrSub1B5BF8 *)operator new(0x60);
    p->Init();
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B55A0);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", Func1B5788__17CMenuMgrSub1B5BF8ffSc);

void CMenuMgrSub1B5BF8::Init() {
    D_002A5534 = this;
    m_unk38 = 0;
}

CMenuMgrSub1B5BF8::~CMenuMgrSub1B5BF8() {
    Release1B5D40();
    D_002A5534 = 0;
}

void CMenuMgrSub1B5BF8::CallReset() {
    Reset();
}

int CMenuMgrSub1B5BF8::Load1B5C88(const char *name) {
    if (m_unk38) {
        Func235DE0(D_002E0270);
        return 0;
    }
    void *p = func_00248E48(name);
    if (!p) {
        Func235DE0(D_002E0298);
        return 0;
    }
    m_unk38 = p;
    func_00253048(p, &m_unk3C, &m_unk40, &m_unk44, &m_unk48, &m_unk4C, &m_unk50, &m_unk54, &m_unk58);
    Func235DE0(D_002E02B8, m_unk44, m_unk48);
    return 1;
}

void CMenuMgrSub1B5BF8::Release1B5D40() {
    if (m_unk38) {
        D_002B91B0(m_unk38);
    }
    m_unk38 = 0;
}

u64 CMenuMgrSub1B5BF8::SwapUnk20(u64 v) {
    u64 old = m_unk20;
    m_unk20 = v;
    return old;
}

u64 CMenuMgrSub1B5BF8::SwapUnk28(u64 v) {
    u64 old = m_unk28;
    m_unk28 = v;
    return old;
}

void CMenuMgrSub1B5BF8::Reset() {
    m_unk0 = 1.0f;
    m_unk4 = 1.0f;
    m_unk10 = 1.0f;
    m_unk14 = 1.0f;
    m_unk18 = 1.0f;
    m_unk1C = 1.0f;
    m_unk30 = 0;
    m_unk34 = 0;
    m_unk5C = 0;
}

void CMenuMgrSub1B5BF8::SetUnk0(f32 x, f32 y) {
    m_unk0 = x;
    m_unk4 = y;
}

void CMenuMgrSub1B5BF8::SetUnk10(f32 x, f32 y, f32 z) {
    m_unk10 = x;
    m_unk14 = y;
    m_unk18 = z;
}

void CMenuMgrSub1B5BF8::SetUnk1C(f32 v) {
    m_unk1C = v;
}

void CMenuMgrSub1B5BF8::SetUnk30(s32 v) {
    m_unk30 = v;
}

void CMenuMgrSub1B5BF8::SetUnk34(s32 v) {
    m_unk34 = v;
}

void CMenuMgrSub1B5BF8::SetUnk5C(s32 v) {
    m_unk5C = v;
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001B5E10() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B5E18);

int CMenuMgrSub1B5BF8::Draw1B5F78(f32 x, f32 y, s8 c) {
    Func225088();
    Func1B5788(x, y, c);
    Func2251E8();
    return Func2250C0();
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B5FE0);

CMenuMgrSub1B6418 *CMenuMgrSub1B6418::Create() {
    CMenuMgrSub1B6418 *p = (CMenuMgrSub1B6418 *)operator new(0xF0);
    p->Init();
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", Func1B6158__17CMenuMgrSub1B6418i);

void CMenuMgrSub1B6418::Init() {
    D_002A5538 = this;
    for (s32 i = 0; i < 3; i++) {
        m_items[i].m_ptr = 0;
    }
}

CMenuMgrSub1B6418::~CMenuMgrSub1B6418() {
    Release1B63A8();
    D_002A5538 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", Reset1B6300__17CMenuMgrSub1B6418);

int CMenuMgrSub1B6418::AllReady1B6350() {
    for (s32 i = 0; i < 3; i++) {
        if (!Func1B6158(i)) {
            return 0;
        }
    }
    return 1;
}

void CMenuMgrSub1B6418::Release1B63A8() {
    for (s32 i = 0; i < 3; i++) {
        if (m_items[i].m_ptr) {
            D_002B91B0(m_items[i].m_ptr);
            m_items[i].m_ptr = 0;
        }
    }
    m_unkE0 = 0;
}

u64 CMenuMgrSub1B6418::SwapUnk60(u64 v) {
    u64 old = m_unk60;
    m_unk60 = v;
    return old;
}

u64 CMenuMgrSub1B6418::SwapUnk68(u64 v) {
    u64 old = m_unk68;
    m_unk68 = v;
    return old;
}

void CMenuMgrSub1B6418::SetUnkDC(u32 v) {
    if (v >= 3) {
        Func235DE0(D_002E0350, v);
        v = 0;
    }
    m_unkDC = v;
}

void CMenuMgrSub1B6418::SetUnkE0(s32 v) {
    if (v != 1) {
        v = 0;
    }
    m_unkE0 = v;
}

void CMenuMgrSub1B6418::Move1B6488(f32 x, f32 y) {
    m_unk10 = m_unk20;
    m_unk14 = m_unk24;
    m_unk20 = x;
    m_unk24 = y;
    m_unk5C = D_002A4B60->Func1091B0(0x18);
    m_unkE0 = 2;
}

void CMenuMgrSub1B6418::SetUnk0And20(f32 x, f32 y) {
    m_unk0 = x;
    m_unk4 = y;
    m_unk20 = x;
    m_unk24 = y;
}

void CMenuMgrSub1B6418::SetUnk40(f32 x, f32 y, f32 z, f32 w) {
    m_unk40 = x;
    m_unk44 = y;
    m_unk48 = z;
    m_unk4C = w;
}

void CMenuMgrSub1B6418::SetUnk4C(f32 v) {
    m_unk4C = v;
}

void CMenuMgrSub1B6418::SetUnk58(u32 v) {
    if (v >= 2) {
        Func235DE0(D_002E0380, v);
        v = 0;
    }
    m_unk58 = v;
}

void CMenuMgrSub1B6418::GetDefaultSize(f32 *w, f32 *h) {
    *w = 24.0f;
    *h = 24.0f;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6570);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B66E8);

CMenuMgrSub1B6BA8 *CMenuMgrSub1B6BA8::Create() {
    CMenuMgrSub1B6BA8 *p = (CMenuMgrSub1B6BA8 *)operator new(0x68);
    p->Init();
    return p;
}

// Two BCD digits to an int (0x42 -> 42).
int BcdToInt(int bcd) {
    return ((bcd & 0xF0) >> 4) * 10 + (bcd & 0xF);
}

void CMenuMgrSub1B6BA8::Init() {
    if (D_002A55AC) {
        Func235DE0(D_002E03C8);
    }
    D_002A55AC = this;
    m_unk0 = 0;
    m_unk4 = 0;
    for (s32 i = 0; i < 10; i++) {
        m_unkC[i] = 0;
    }
    m_unk64 = 0;
    Func235DE0(D_002E03E8);
    return func_002320A0(1);
}

CMenuMgrSub1B6BA8::~CMenuMgrSub1B6BA8() {
    Release1B6F00();
    D_002A55AC = 0;
    Func235DE0(D_002E03F8);
    func_002320A0(0);
}

void CMenuMgrSub1B6BA8::Alloc1B6CA8() {
    m_unk0 = func_001089D0(D_002A26E0, 0);
    m_unk4 = func_00245DD0(m_unk0);
    if (!m_unk4) {
        return Func235DE0(D_002E0408);
    }
    m_unk8 = func_001089D0(D_002A26E4, 0);
    for (s32 i = 0; i < 10; i++) {
        m_unkC[i] = (s32)func_00245DD0(m_unk8 * 3);
        if (!m_unkC[i]) {
            Func235DE0(D_002E0428);
            return;
        }
    }
    m_unk64 = func_00245DD0(m_unk8 * 3);
    Func235DE0(D_002E0448, m_unk0, m_unk8);
}

void CMenuMgrSub1B6BA8::Init1B6DA8() {
    CFlagTmp a;
    CFlagTmp b;
    s32 k;
    func_00108320(&a, 0, -1);
    func_00108320(&b, 0, -1);
    func_001087F8(&a, D_002A26E0);
    func_00108700(&a);
    func_001089D0(&a, (s32)m_unk4);
    func_001087F8(&b, D_002A26E4);
    func_00108700(&b);
    for (s32 j = 0; j < 10; j++) {
        for (k = 0; k < 3; k++) func_001089D0(&b, m_unkC[j] + m_unk8 * k);
    }
    for (k = 0; k < 3; k++) func_001089D0(&b, (s32)m_unk64 + m_unk8 * k);
    for (s32 i = 0; i < 10; i++) m_unk34[i] = 0;
    func_00108370(&b, 2);
    func_00108370(&a, 2);
}

void CMenuMgrSub1B6BA8::Release1B6F00() {
    if (m_unk4) {
        D_002B91B0(m_unk4);
        m_unk4 = 0;
    }
    for (s32 i = 0; i < 10; i++) {
        if (m_unkC[i]) {
            D_002B91B0((void *)m_unkC[i]);
            m_unkC[i] = 0;
        }
    }
    if (m_unk64) {
        D_002B91B0(m_unk64);
        m_unk64 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6FA8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7008);

s32 CMenuMgrSub1B6BA8::GetUnkC(u32 i) {
    if (i >= 10) {
        Func235DE0(D_002E0470, i);
        return 0;
    }
    return m_unkC[i];
}

s32 CMenuMgrSub1B6BA8::Calc1B7118(u32 i) {
    if (i >= 30) {
        Func235DE0(D_002E0498);
        return 0;
    }
    return m_unkC[(s32)i / 3] + m_unk8 * ((s32)i % 3);
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7188);

void CMenuMgrSub1B6BA8::Func1B72E0(u32 i) {
    if (i >= 30) {
        return Func235DE0(D_002E0508);
    }
    if (D_002A26E4) {
        func_00108A20(D_002A26E4, m_unkC[(s32)i / 3] + m_unk8 * ((s32)i % 3));
    }
}

void CMenuMgrSub1B6BA8::SetUnk34(u32 i, s32 v) {
    if (i >= 10) {
        return Func235DE0(D_002E0530, i);
    }
    m_unk34[i] = v;
}

s32 CMenuMgrSub1B6BA8::GetUnk34(u32 i) {
    if (i >= 10) {
        Func235DE0(D_002E0560, i);
        return 0;
    }
    return m_unk34[i];
}

int CMenuMgrSub1B6BA8::AllSet1B73E8() {
    for (s32 i = 0; i < 10; i++) {
        if (m_unk34[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int CMenuMgrSub1B6BA8::Check1B7428(u32 i) {
    CFlagTmp tmp;
    if (i >= 31) {
        Func235DE0(D_002E0590, i);
        return 0;
    }
    func_00108320(&tmp, 0, -1);
    func_001087F8(&tmp, D_002A26E4);
    func_00108700(&tmp);
    func_00108A20(&tmp, Calc1B7118(i));
    if (strcmp(func_00109158(&tmp, 0x23), D_002E05B8) == 0) {
        func_00108370(&tmp, 2);
        return 0;
    }
    func_00108370(&tmp, 2);
    return 1;
}

int CMenuMgrSub1B74F8::CallFunc2320F8() {
    return m_unk5C.Func2320F8();
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7510);

CUnk2A55B0 *CUnk2A55B0::Create() {
    CUnk2A55B0 *p = (CUnk2A55B0 *)operator new(0x280);
    p->Init();
    return p;
}

int CallFunc1B76D0(void *p) {
    return D_002A55B0->Func1B76D0(p);
}

int CallFunc1B7910() {
    return D_002A55B0->Func1B7910();
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", Func1B76D0__10CUnk2A55B0Pv);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", Func1B7910__10CUnk2A55B0);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", Init__10CUnk2A55B0);

CUnk2A55B0::~CUnk2A55B0() {
    if (m_unk274) {
        D_002B91B0(m_unk274);
        m_unk274 = 0;
    }
    if (m_unk278) {
        D_002B91B0(m_unk278);
        m_unk278 = 0;
    }
    Free1B7E28();
    D_002A55B0 = 0;
}

void CUnk2A55B0::Load1B7D78() {
    Free1B7E28();
    func_0022DC90(0);
    func_0022DC90(D_002E0778);
    m_unk6C = func_0022FF58(D_002E0658);
    if (m_unk6C <= 0) {
        Func235DE0(D_002E0788, func_0022DD20());
    } else {
        m_unk70 = func_00248E48(D_002E0658);
        if (m_unk70 == 0) {
            Func235DE0(D_002E0788, func_0022DD20());
        }
    }
    func_0022DC90(0);
}

void CUnk2A55B0::Free1B7E28() {
    if (m_unk70) {
        D_002B91B0(m_unk70);
        m_unk70 = 0;
        m_unk6C = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7E70);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7EF8);

s32 CUnk2A55B0::Size1B8500() {
    s32 total = (m_unk6C + 0x3FF) / 0x400 + 1;
    for (s32 i = 0; i < 10; i++) {
        s32 n = D_002A55AC->m_unk8 * 3;
        total += (func_001EE198(n, n) + 0x3FF) / 0x400;
    }
    total += (func_001EE198(D_002A55AC->m_unk0, D_002A55AC->m_unk0) + 0x3FF) / 0x400;
    return (total + 17) / 10 * 10;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B85D8);
