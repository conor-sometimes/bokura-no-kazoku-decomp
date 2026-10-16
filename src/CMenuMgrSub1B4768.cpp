#include "common.h"

// Menu manager helpers after CMenuMgr's vtable unit (0x1B4730-0x1B86A0: menu sub-objects, glyph
// cells, McSys memory-card driver): their literals follow 8CMenuMgr/8IMenuMgr, before CLayoutRes's.

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "libc.h"
#include "CFlagWork.h"
#include "CTask.h"
// Menu screen base (CMenuProcess unit; include/CMenuProcess.h has the full class, but its
// Func235DE0 returns s32 while this unit's callers use it as void).
class CMenuProcess {
public:
    virtual ~CMenuProcess();
    virtual void Update() = 0;
    virtual s32 Draw() = 0;
    void SetUnk50(s32 v);
    void SetState4();
    void SetState6();

    u8 pad0[0x48];
    s32 m_state;              // 0x48
    s32 m_unk4C;              // 0x4C
    s32 m_unk50;              // 0x50
    // vptr 0x54
};
class CStatusWinSub1A0A10 {
public:
    void Clear();
};
#include "CMenuLoadMemorialSub17B3A0.h"
#include "CChrBodyWin.h"
class CChrBodyWinSub188748 {
public:
    u64 SwapUnk188(u64 v);
    u64 SwapUnk190(u64 v);
};
extern CStatusWinSub1A0A10 *D_002A5408;
extern CMenuLoadMemorialSub17B3A0 *D_002A3AF8;
extern CChrBodyWin *D_002A4308;
extern void *D_002A53D4;
extern CFlagWork *D_002A4B60;
extern void *D_002A551C;
extern void *D_002A5528;
extern void (*D_002B91B0)(void *p);
void Func235DE0(const char *fmt, ...) throw();
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

// CMenuMgr's vtable slots (_vt$8CMenuMgr); the vptr is at 0, so they come from a field-less base.
class IMenuMgr {
public:
    virtual ~IMenuMgr();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual s32 GetPad(s32 *a, s32 *b, s32 *c);
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void UpdateProc();
    virtual s32 DrawProc();
    virtual void Slot20();
};

// Pad repeat state (inline constructor).
struct CMenuMgrKey {
    CMenuMgrKey() {
        m_unk4 = -1;
        m_unk2 = 0;
        m_unk0 = 0;
    }
    s16 m_unk0;               // 0x0
    s16 m_unk2;               // 0x2
    s32 m_unk4;               // 0x4
};
class CMenuMgr : public IMenuMgr {
public:
    void Update1B45E8();
    CMenuMgr();
    virtual ~CMenuMgr();
    virtual s32 GetPad(s32 *a, s32 *b, s32 *c);
    virtual void UpdateProc();
    virtual s32 DrawProc();
    void DebugPrint1B85D8();
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
    int Load1B4050(const char *dir);

    CMenuMgrKey m_key;        // 0x4
    u8 padC[0x40];
    s32 m_unk4C;              // 0x4C
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
    int DrawString1B5FE0(f32 x, f32 y, const char *s);
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
    void Update1B6570();

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
    void Save1B7188(u32 i);
    void SetUnk34(u32 i, s32 v);
    s32 GetUnk34(u32 i);
    int AllSet1B73E8();
    void Alloc1B6CA8();
    void Load1B6FA8();
    void Load1B7008();

    s32 m_unk0;               // 0x0
    void *m_unk4;             // 0x4
    s32 m_unk8;               // 0x8
    s32 m_unkC[10];           // 0xC
    s32 m_unk34[10];          // 0x34
    u8 m_date[0x8];           // 0x5C
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

class CPadMgr : public CTask {
public:
    virtual s32 Vf293408();
    virtual s32 Vf293410();
    virtual s32 Vf293420();
    virtual s32 Vf293418();
    virtual void SetUnk18(s32 v);
    virtual s32 Vf293428();
};
extern CPadMgr *D_0029F390;
// Debug text printer at D_002BA0B0 (library side).
class CDbgText2BA0B0 {
public:
    virtual void Vf0();
    virtual void Vf1();
    virtual void Vf2();
    virtual void Vf3();
    virtual void Vf4();
    virtual void SetColor(f32 r, f32 g, f32 b, f32 a);
    virtual void Vf6();
    virtual void SetPos(f32 x, f32 y);
    virtual void Vf8();
    virtual void Vf9();
    virtual void Vf10();
    virtual void Vf11();
    virtual void Vf12();
    virtual s32 Print(const char *s);
};
extern CDbgText2BA0B0 *D_002BA0B0;
extern char D_002DFF10[], D_002E09C0[];
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern "C" void func_002491A8(void *f, const char *dir, void *a, void *b, void *c);
extern "C" int func_00249248(void *f);
extern "C" void func_00249348();
extern "C" void func_00249428(void *a, void *b);
extern void *D_002A5520;
extern void *D_002A5524;
extern char D_002DFE18[], D_002DFE30[], D_002DFE40[], D_002DFE50[], D_002DFE60[], D_002DFE70[], D_002DFE80[], D_002DFE90[];
extern "C" void func_001A0A98(void *w, const char *name);
extern "C" int func_001B4820(CMenuMgrSub1B4768 *p, const char *name);
extern "C" int func_0019BA00(void *p, const char *name);
extern "C" int func_001884F0(void *p, const char *name);
class CSeMgr1D0 {
public:
    virtual void V0();
    virtual s32 Load(const char *name, s32 k);
};
extern CSeMgr1D0 *D_002BA1D0;
extern "C" s32 func_001EDC18(const char *dir, s32 k);
extern "C" s32 func_001EDF78(const char *dir, s32 k);
extern "C" s32 func_001EDEE8(const char *dir, s32 k);
extern "C" s32 func_001EE4F8(const char *name, s32 a, s32 b, s32 c);
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern char D_002E0610[], D_002E0618[], D_002E0630[], D_002E0640[], D_002E0658[], D_002E0668[], D_002E0678[], D_002E0690[], D_002E06B0[];
extern u8 D_002A55C0[];
int BcdToInt(int v);
extern char D_002E04C0[], D_002E04E8[];

extern f32 D_002A6800[];
extern s32 D_002A55A0[];
// VU0 float to 1.15 fixed point (sine-table index), as in CSwingBoneObj.
inline s32 Ftoi15(f32 x) {
    s32 i;
    asm volatile(
        "mfc1 %0, %1\n"
        "qmtc2.ni %0, $vf2\n"
        "vftoi15.x $vf2, $vf2\n"
        "qmfc2.ni %0, $vf2\n"
        : "=r"(i) : "f"(x));
    return i;
}
extern CMenuMgr *D_002A5468;
extern CFlagWork *D_002A5358;
extern CFlagWork *D_002A4638[6];
extern char D_002A4B68[], D_002A4650[], D_002A43B8[];
void *NewStatusWinSub1A0A10();
void *NewMemorialSub17B3A0();
void *NewStatusSub19B8C8();
void *NewChrBodyWin();
int GetFontTable(u32 i);
extern "C" void *func_0025C230(void *p);
extern "C" void func_0025C438(s32 a, void *b);

extern "C" char *strcpy(char *, const char *);
inline void StrAdd1B7(char *d, const char *s) { strcpy(d + strlen(d), s); }

class CMenuProcV { public: u8 pad[0x54]; virtual ~CMenuProcV(); virtual void Update(); };

struct CGlyphDump { s32 m0; u8 *m4; s32 m8; u8 *mC[10]; };
extern const char D_002E05C0[], D_002E05D0[], D_002E05D8[], D_002E05E0[], D_002E05F8[];
#define PRINTI ((int (*)(const char *, ...))Func235DE0)
struct CMenuEnt20 { u8 pad0[0x14]; };
struct CMenuTbl1B4E70 { u8 pad0[0x14]; CMenuEnt20 *m_ents; u8 pad18[0x4]; s32 m_num; };
extern char D_002E07A8[], D_002E07D8[];

#include "state.h"
extern "C" int func_001ED830(s32 a, s32 *res);
extern "C" void func_001ED908(s32 port);
extern "C" void func_001EEB10(void *p);
extern "C" void func_001EEA80(void *fn, s32 a, s32 b, s32 c, s32 d);
extern "C" void func_001EED28();
extern "C" void func_001EED88(char *path, s32 a);
extern "C" void func_001EEDE8(char *path, s32 a, s32 b);
void *Func245D00(s32 size);
int CallFunc1B76D0(void *p);
int CallFunc1B7910();
extern char D_002E0800[], D_002E0820[], D_002E0840[], D_002E0860[], D_002E0888[], D_002E08A0[];
extern char D_002E08B0[], D_002E08D0[], D_002E08E0[], D_002E0900[], D_002E0910[], D_002E0928[];
extern char D_002E0950[], D_002E0980[], D_002E06E0[];
// Func235DE0 with its real int return (the void declaration above changes register choice after calls).
extern "C" int McPrint(const char *fmt, ...) throw() asm("Func235DE0__FPCce");
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002DFF50);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002DFF68);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002DFF70);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002DFF78);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002DFF98);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002DFFA0);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002DFFA8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002DFFB0);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002DFFD8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0008);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0030);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0060);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0090);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E00B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E00E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0120);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", jtbl_002E0140);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0270);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0298);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E02B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E02D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E02F0);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0318);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0338);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0350);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0380);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E03A8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E03C8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E03E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E03F8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0408);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0428);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0448);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0470);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0498);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E04C0);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E04E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0508);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0530);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0560);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0590);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E05B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E05C0);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E05D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E05D8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E05E0);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E05F8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0610);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0618);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0630);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0640);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0658);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0668);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0678);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0690);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E06B0);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E06C8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E06E0);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E06E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0700);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0718);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0730);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0738);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0740);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0760);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0778);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0788);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E07A8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E07D8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0800);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0820);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0840);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0860);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0888);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E08A0);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E08B0);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E08D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E08E0);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0900);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0910);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0928);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0950);
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E0980);

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

void CMenuMgrSub1B4768::Reset1B47E8() { m_unk30 = 1.0f; m_unk34 = 1.0f; m_unk38 = 0.0f; m_unk3C = 0.0f; m_unk40 = 1.0f; m_unk44 = 1.0f; m_unk48 = 1.0f; m_unk50 = 1; m_unk4C = 1.0f; }

INCLUDE_ASM("asm/nonmatchings/CMenuMgrSub1B4768", func_001B4820);

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

extern "C" CMenuEnt20 *func_001B4E70(CMenuTbl1B4E70 *t, s32 i) {
    if (i < 0 || i > t->m_num - 1) {
        Func235DE0(D_002E0060, i);
        return 0;
    }
    return &t->m_ents[i];
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001B4EC8() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgrSub1B4768", Func1B4ED0__8CMenuMgri);

INCLUDE_ASM("asm/nonmatchings/CMenuMgrSub1B4768", func_001B50B0);

CMenuMgrSub1B5BF8 *CMenuMgrSub1B5BF8::Create() {
    CMenuMgrSub1B5BF8 *p = (CMenuMgrSub1B5BF8 *)operator new(0x60);
    p->Init();
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgrSub1B4768", func_001B55A0);

INCLUDE_ASM("asm/nonmatchings/CMenuMgrSub1B4768", Func1B5788__17CMenuMgrSub1B5BF8ffSc);

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

INCLUDE_ASM("asm/nonmatchings/CMenuMgrSub1B4768", func_001B5E18);

int CMenuMgrSub1B5BF8::Draw1B5F78(f32 x, f32 y, s8 c) {
    Func225088();
    Func1B5788(x, y, c);
    Func2251E8();
    return Func2250C0();
}

int CMenuMgrSub1B5BF8::DrawString1B5FE0(f32 x, f32 y, const char *s) {
    f32 w = (f32)strlen(s) * (m_unk0 * 11.0f);
    switch (m_unk34) {
    case 0:
        break;
    case 1:
        x -= w * 0.5f;
        break;
    case 2:
        x -= w;
        break;
    }
    Func225088();
    while (*s) {
        Func1B5788(x, y, *s++);
        x += (f32)(s32)(m_unk0 * 11.0f);
    }
    Func2251E8();
    return Func2250C0();
}

CMenuMgrSub1B6418 *CMenuMgrSub1B6418::Create() {
    CMenuMgrSub1B6418 *p = (CMenuMgrSub1B6418 *)operator new(0xF0);
    p->Init();
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgrSub1B4768", Func1B6158__17CMenuMgrSub1B6418i);

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

void CMenuMgrSub1B6418::Reset1B6300() { m_unk0 = 0; m_unk4 = 0; m_unk30 = 24.0f; m_unk34 = 24.0f; m_unk40 = 1.0f; m_unk44 = 1.0f; m_unk48 = 1.0f; m_unk4C = 1.0f; m_unk58 = 0; m_unk54 = 0; m_unk50 = 0; m_unk5C = 0; m_unkDC = 0; m_unkE0 = 0; }

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

asm(".p2align 3");
void CMenuMgrSub1B6418::Update1B6570() {
    m_unk50++;
    if (m_unk50 >= D_002A4B60->Func1091B0(0x17)) {
        m_unk50 = 0;
        m_unk54++;
        if (m_unk54 >= D_002A55A0[m_unkDC]) m_unk54 = 0;
    }
    if (m_unkE0 != 2) return;
    if (m_unk5C > 0) {
        f32 k = 0.318309886f;
        s32 n = D_002A4B60->Func1091B0(0x18);
        f32 t = 1.0f - (f32)m_unk5C / (f32)n;
        u8 *tbl = (u8 *)D_002A6800;
        f32 s = *(f32 *)(tbl + ((Ftoi15(t * 0.5f) << 1) & 0xFFFC));
        m_unk5C--;
        f32 f = t + s * k;
        m_unk0 = (m_unk20 - m_unk10) * f + m_unk10;
        m_unk4 = (m_unk24 - m_unk14) * f + m_unk14;
    } else {
        m_unk0 = m_unk20;
        m_unk4 = m_unk24;
        m_unkE0 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgrSub1B4768", func_001B66E8);

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

void CMenuMgrSub1B6BA8::Load1B6FA8() {
    if (m_unk4 && D_002A26E0) {
        func_00108A20(D_002A26E0, (s32)m_unk4);
        D_002A26E0->Vf143BD0();
    }
}

void CMenuMgrSub1B6BA8::Load1B7008() {
    if (m_unk4 && D_002A26E0) {
        CFlagWork tmp(0, -1);
        tmp.CopyFrom(D_002A26E0);
        tmp.Func108700();
        func_00108A20(&tmp, (s32)m_unk4);
        D_002A26E0->Merge144440(&tmp);
        D_002A26E0->Load143BD8((CCurFlag *)D_002A26E4);
        D_002A26E0->Save((u8 *)m_unk4);
    }
}

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

void CMenuMgrSub1B6BA8::Save1B7188(u32 i) {
    if (i >= 30) {
        Func235DE0(D_002E04C0, i);
        return;
    }
    s32 q = (s32)i / 3;
    s32 r = (s32)i % 3;
    Func235DE0(D_002E04E8, i, q, r);
    D_002A26E4->Func108FF0(2, BcdToInt(m_date[7]));
    D_002A26E4->Func108FF0(3, BcdToInt(m_date[6]));
    D_002A26E4->Func108FF0(4, BcdToInt(m_date[5]));
    D_002A26E4->Func108FF0(5, BcdToInt(m_date[3]));
    D_002A26E4->Func108FF0(6, BcdToInt(m_date[2]));
    D_002A26E4->Func108FF0(7, BcdToInt(m_date[1]));
    D_002A26E4->Save((u8 *)(m_unkC[q] + m_unk8 * r));
}

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

extern "C" void func_001B7510(CGlyphDump *s) {
    u8 *p;
    u32 i;
    u32 j;
    s32 k;
    u8 **tbl;
    PRINTI(D_002E05C0, s->m0);
    p = s->m4;
    for (i = 0; i < 10; i++) PRINTI(D_002E05D0, p[i]);
    PRINTI(D_002E05D8);
    PRINTI(D_002E05E0, s->m8);
    for (k = 0, tbl = s->mC; k < 30; k++) {
        s32 q = k / 3;
        s32 r = k % 3;
        u8 **e = &tbl[q];
        PRINTI(D_002E05F8, k, q, r, *e);
        p = *e + s->m8 * r;
        for (j = 0; j < 12; j++) PRINTI(D_002E05D0, p[j]);
        PRINTI(D_002E05D8);
    }
}

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

INCLUDE_ASM("asm/nonmatchings/CMenuMgrSub1B4768", Func1B76D0__10CUnk2A55B0Pv);

INCLUDE_ASM("asm/nonmatchings/CMenuMgrSub1B4768", Func1B7910__10CUnk2A55B0);

void CUnk2A55B0::Init() {
    m_unk4 = -1; m_unk2 = 0; m_unk0 = 0;
    if (D_002A55B0) Func235DE0(D_002E0740);
    D_002A55B0 = this;
    strcpy(m_unk174, func_00235D80());
    StrAdd1B7(m_unk174, D_002E0760);
    func_001ED960(m_unk60);
    m_unk5C = 0; m_unk274 = 0; m_unk278 = 0; m_unk27C = 0; m_unk4C = 0; m_unk50 = 0; m_unk54 = 0; m_unk48 = 0; m_unk6C = 0; m_unk70 = 0; m_unk58 = 0;
}

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

int CUnk2A55B0::Start1B7E70(s32 a, s32 b) {
    if (m_unk4C == 1) {
        Func235DE0(D_002E07A8, a, b);
        return 0;
    }
    if (a >= 7) {
        Func235DE0(D_002E07D8, a);
        return 0;
    }
    m_unk50 = a;
    m_unk54 = b;
    m_unk4C = 1;
    m_unk4 = -1;
    m_unk2 = 0;
    m_unk0 = 0;
    m_unk48 = 0;
    return 1;
}

// GNU as 2.10 assembles the jump-table lui as a lw without this (docs/lessons.md).
asm(".p2align 3");
// The memory card system's request machine (McSys); returns whether it is still working.
extern "C" int func_001B7EF8(CUnk2A55B0 *p) {
    CStateMachine *sm = (CStateMachine *)p;
    s32 res = 0;
    char buf[0x100];
    s32 done = 0;
loop:
    if (done) goto out;
    {
        u32 fl = sm->m_flags;
        if ((fl >> 7) & 1) goto out;
    }
    switch (sm->m_state) {
    case -1:
        switch (p->m_unk50) {
        case 0: goto r0;
        case 1: goto r1;
        case 2: goto r2;
        case 3: goto r3;
        case 4: goto r4;
        case 5: goto r5;
        case 6: goto r6;
        default:
            McPrint(D_002E0800, p->m_unk50);
            sm->m_state = -0x208;
            goto e208;
        }
    case -0x208:
    e208:
        done = 1; goto loop;
    r0:
        for (;;) {
            sm->m_state = -0x210; done = 1; goto loop;
    case -0x210:;
        }
    r1:
        McPrint(D_002E0820);
        func_001ED908(p->m_unk5C);
        func_001EEB10(p->m_unk60);
        while (func_001ED830(1, &res)) {
            sm->m_state = -0x21F; done = 1; goto loop;
    case -0x21F:;
        }
        p->m_unk4C = 0;
        p->m_unk48 = 0;
        sm->m_state = -0x226;
    case -0x226:
        done = 1; goto loop;
    r2:
        func_001ED908(p->m_unk5C);
        func_001EEB10(p->m_unk60);
        while (func_001ED830(1, &res)) {
            sm->m_state = -0x233; done = 1; goto loop;
    case -0x233:;
        }
        p->m_unk4C = 0;
        if (*(s32 *)p->m_unk60 != 2) {
            p->m_unk58 = 0;
            p->m_unk48 = -2;
        } else {
            p->m_unk48 = 0;
        }
        sm->m_state = -0x242;
    case -0x242:
        done = 1; goto loop;
    r3:
        McPrint(D_002E0840);
        if (!(p->m_unk274 = Func245D00(0x3C4))) {
            McPrint(D_002E0860, 0x3C4);
            p->m_unk48 = -1;
            D_002A55AC->Init1B6DA8();
            p->m_unk58 = 0;
            goto free;
        }
        if (!(p->m_unk278 = Func245D00(p->m_unk6C))) {
            McPrint(D_002E0860, p->m_unk6C);
            p->m_unk48 = -1;
            D_002A55AC->Init1B6DA8();
            p->m_unk58 = 0;
            goto free;
        }
        McPrint(D_002E0888);
        func_001ED908(p->m_unk5C);
        func_001EEA80((void *)CallFunc1B7910, 0, 0, 0, 0);
        while (func_001ED830(1, &res)) {
            sm->m_state = -0x262; done = 1; goto loop;
    case -0x262:;
        }
        if (res == -0xC8) {
            p->m_unk58 = 0;
            p->m_unk48 = -2;
        } else {
            p->m_unk48 = 0;
        }
    free:
        p->m_unk4C = 0;
        if (p->m_unk274) {
            D_002B91B0(p->m_unk274);
            p->m_unk274 = 0;
        }
        if (p->m_unk278) {
            D_002B91B0(p->m_unk278);
            p->m_unk278 = 0;
        }
        sm->m_state = -0x27D;
    case -0x27D:
        done = 1; goto loop;
    r4:
        McPrint(D_002E08A0);
        func_001ED908(p->m_unk5C);
        func_001EED28();
        while (func_001ED830(1, &res)) {
            sm->m_state = -0x28A; done = 1; goto loop;
    case -0x28A:;
        }
        p->m_unk4C = 0;
        if (res == 0) {
            p->m_unk48 = 0;
        } else {
            p->m_unk58 = 0;
            p->m_unk48 = -1;
        }
        McPrint(D_002E08B0, res);
        sm->m_state = -0x29A;
    case -0x29A:
        done = 1; goto loop;
    r5:
        McPrint(D_002E08D0);
        func_001ED908(p->m_unk5C);
        func_001EEA80((void *)CallFunc1B76D0, p->m_unk54, 0, 0, 0);
        while (func_001ED830(1, &res)) {
            sm->m_state = -0x2A7; done = 1; goto loop;
    case -0x2A7:;
        }
        if (res >= 0) {
            p->m_unk48 = 0;
        } else {
            p->m_unk58 = 0;
            p->m_unk48 = -1;
        }
        McPrint(D_002E08E0, res);
        p->m_unk4C = 0;
        sm->m_state = -0x2B9;
    case -0x2B9:
        done = 1; goto loop;
    r6:
        McPrint(D_002E0900);
        sprintf(buf, D_002E0668, p->m_unk54);
        sprintf((char *)p->pad74, D_002E06E0, p->m_unk174, buf);
        func_001ED908(p->m_unk5C);
        func_001EED88((char *)p->pad74, 1);
        while (func_001ED830(1, &res)) {
            sm->m_state = -0x2C8; done = 1; goto loop;
    case -0x2C8:;
        }
        if (res == -0xC8) {
            McPrint(D_002E0910, -0xC8);
            p->m_unk48 = -2;
            p->m_unk58 = 0;
            goto fin;
        }
        if (res < 0 || res != D_002A55AC->m_unk8 * 3) {
            McPrint(D_002E0928, res);
            p->m_unk48 = -1;
            p->m_unk58 = 0;
            goto fin;
        }
        p->m_unk27C = D_002A55AC->GetUnkC(p->m_unk54);
        func_001ED908(p->m_unk5C);
        func_001EEDE8((char *)p->pad74, p->m_unk27C, 1);
        while (func_001ED830(1, &res)) {
            sm->m_state = -0x2DF; done = 1; goto loop;
    case -0x2DF:;
        }
        if (res == -0xC8) {
            McPrint(D_002E0910, -0xC8);
            p->m_unk48 = -2;
            p->m_unk58 = 0;
            goto fin;
        }
        if (res < 0) {
            McPrint(D_002E0950, p->m_unk54, res);
            p->m_unk48 = -1;
            p->m_unk58 = 0;
        } else {
            p->m_unk48 = 0;
            p->m_unk27C = 0;
        }
    fin:
        p->m_unk4C = 0;
        McPrint(D_002E0980, p->m_unk48);
        sm->m_state = -0x2F8;
    case -0x2F8:
        done = 1; goto loop;
    case -0x212:
        done = 1; goto loop;
    }
out:
    return p->m_unk4C;
}

// The switch table (jtbl_002E09A0) comes from the function above.
INCLUDE_RODATA("asm/nonmatchings/CMenuMgrSub1B4768", D_002E09C0);

s32 CUnk2A55B0::Size1B8500() {
    s32 total = (m_unk6C + 0x3FF) / 0x400 + 1;
    for (s32 i = 0; i < 10; i++) {
        s32 n = D_002A55AC->m_unk8 * 3;
        total += (func_001EE198(n, n) + 0x3FF) / 0x400;
    }
    total += (func_001EE198(D_002A55AC->m_unk0, D_002A55AC->m_unk0) + 0x3FF) / 0x400;
    return (total + 17) / 10 * 10;
}

void CMenuMgr::DebugPrint1B85D8() {
    char buf[0x400];
    sprintf(buf, D_002E09C0, m_unk4C, m_proc, m_unk64, m_unk68);
    D_002BA0B0->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
    D_002BA0B0->SetPos(388.0f, 40.0f);
    D_002BA0B0->Print(buf);
}
