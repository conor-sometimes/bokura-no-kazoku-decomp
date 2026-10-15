#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "libc.h"
extern "C" unsigned int strlen(const char *s);
s32 Func235DE0(const char *fmt, ...);
class CTaskList24F5C0;
void AddFadeMgr(CTaskList24F5C0 *l);
void AddSnapMgr(CTaskList24F5C0 *l);
void AddPadMgr(CTaskList24F5C0 *l);
void AddInterfResSub169090(CTaskList24F5C0 *l);
void AddPhotoEventObjSub16D4D8(CTaskList24F5C0 *l);
extern s32 D_002A5BD4;
extern s32 D_002A5BD8;
extern char D_2EC1F0[][64];
extern const char D_002E1FD0[];
extern const char D_002E1FF8[];
typedef void (*VoidFn)();
extern VoidFn D_002A5BC4;
extern "C" void func_001EB1E8();
extern "C" void func_001EB4B0();
struct CAnim1EA {
    u16 m_unk0;               // 0x0
    u16 m_id;                 // 0x2
    s32 m_unk4;               // 0x4
    u16 m_unk8;               // 0x8
    u16 m_unkA;               // 0xA
    f32 m_rate;               // 0xC
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
};
extern s32 D_002A5BCC;
extern CAnim1EA **D_002A5BD0;
inline CAnim1EA *GetAnim(s32 i) { return (i >= 0 && i < D_002A5BCC) ? D_002A5BD0[i] : 0; }
extern void *(*D_002B91A4)(u32 n);
extern void (*D_002B91B0)(void *p);
void Func1EB828(int x);
extern "C" void func_001EB8E8(s32 x);
extern "C" void func_001ECCA8(s32 i);

#include "CProcess.h"
// Resource managers driven by CAppMain (slot 1 loads, slot 2 releases).
class CVt4 {
public:
    virtual void V0();
    virtual s32 V1(s32 x);
    virtual void V2();
    virtual void V3();
};
class CVt4b {
public:
    virtual void V0();
    virtual void V1();
    virtual s32 V2(s32 x);
    virtual void V3();
};
class CVt2Arg {
public:
    virtual void V0();
    virtual void V1(void *arg);
    virtual void V2(void *arg);
};
class CVtAtC {
public:
    s32 m0, m4, m8;
    virtual void V0();
    virtual s32 V1(s32 x);
    virtual void V2();
};
#define VDUMMY(n) virtual void Vd##n();
class CSndDrvApp {
public:
    VDUMMY(0) VDUMMY(1) VDUMMY(2) VDUMMY(3) VDUMMY(4) VDUMMY(5) VDUMMY(6) VDUMMY(7) VDUMMY(8) VDUMMY(9)
    VDUMMY(10) VDUMMY(11)
    virtual void SetAlloc(s32 (*fn)(s32));                                           // [12]
    virtual void SetHook(void (*fn)());                                              // [13]
    VDUMMY(14) VDUMMY(15) VDUMMY(16) VDUMMY(17) VDUMMY(18) VDUMMY(19)
    VDUMMY(20) VDUMMY(21) VDUMMY(22) VDUMMY(23) VDUMMY(24) VDUMMY(25) VDUMMY(26) VDUMMY(27)
    virtual s32 LoadBank(s32 slot, const char *path, s32 a, s32 b, s32 c, s32 d);  // [28]
    VDUMMY(29)
    virtual s32 LoadWave(s32 slot, const char *path, s32 a, s32 b, s32 c);         // [30]
    VDUMMY(31) VDUMMY(32) VDUMMY(33) VDUMMY(34) VDUMMY(35) VDUMMY(36) VDUMMY(37) VDUMMY(38) VDUMMY(39)
    VDUMMY(40) VDUMMY(41) VDUMMY(42) VDUMMY(43)
    virtual void V44();                                                              // [44]
};
class CSePlayerApp {
public:
    VDUMMY(0)
    virtual void V1();
    virtual s32 V2(s32 x);
    VDUMMY(3)
    virtual s32 V4(s32 x);
    virtual s32 V5(s32 x);
    VDUMMY(6) VDUMMY(7) VDUMMY(8) VDUMMY(9)
    VDUMMY(10) VDUMMY(11) VDUMMY(12) VDUMMY(13) VDUMMY(14) VDUMMY(15) VDUMMY(16) VDUMMY(17)
    virtual void V18();                                                              // [18]
    VDUMMY(19)
    virtual s32 V20();                                                               // [20]
};
extern CSndDrvApp *D_002BA248;
extern CSePlayerApp *D_002A5468;
extern const char D_002E1E10[], D_002E1E28[], D_002E1E40[], D_002E1E58[], D_002E1E70[], D_002E1E88[], D_002E1EA0[];
extern const char D_002E1DE8[], D_002E1E08[], D_002E1E00[], D_002E1EB8[], D_002E1DF0[], D_002E1EC0[], D_002E1ED8[], D_002E1EE8[];
s32 Func235DE0(const char *fmt, ...);
extern "C" void func_00249428(const char *a, const char *b);
int Func249248(void *p);
void Func249348();
extern "C" s32 func_0013DA10(void *p, const char *name);
class CEventMesResSub13DD98 {
public:
    CEventMesResSub13DD98();
    ~CEventMesResSub13DD98();
    void Init();
    u8 m_data[0x24];
};
class CAppMain : public CProcess {
public:
    CAppMain();
    virtual ~CAppMain();
    virtual void Update();
    virtual void Func4();
    virtual void Draw();
    virtual s32 Func7();
    virtual void ReleaseTextures();

    u8 pad18[0x14];
    CStateMachine m_sm;       // 0x2C
    CBgWork m_bg2;            // 0x74
    CVtAtC *m_80;             // 0x80
    CVtAtC *m_84;             // 0x84
    s32 m_88;                 // 0x88
    u8 pad8C[0x10];
    CEventMesResSub13DD98 m_mes; // 0x9C
};
extern CVt4 *D_002A3AC0, *D_002A36E8, *D_002A05D0, *D_002A28D8, *D_002A35B0;
extern CVt4b *D_002A0D38;
extern CVt2Arg *D_002A0CE0;

class CGs2BA128 {
public:
    virtual void V0();
    virtual s32 V1(s32 a, s32 b, s32 c, s32 d);
    virtual void V2();
    virtual s32 V3();
    virtual s32 V4();
    virtual s32 V5();
};
extern CGs2BA128 *D_002BA128;
struct CTexInfo1EA780 {
    u8 pad0[0x10];
    s32 m_w;                  // 0x10
    s32 m_h;                  // 0x14
};
extern "C" void func_00254AA8(CTexInfo1EA780 *t, s32 ctx, f32 *pos, f32 *col, s32 a, s32 b);

class CFontMgr2A039C { public: virtual void V0(); virtual s32 V1(s32 a, s32 b, s32 c, s32 d); };
extern CFontMgr2A039C *D_002A039C;
class CFontRes2BA1D4 { public: virtual void V0(); virtual void V1(); virtual void V2(); virtual s32 V3(s32 a, const char *b, const char *c); };
extern CFontRes2BA1D4 *D_002BA1D4;
class CTxtRes2BA1D8 { public: virtual void V0(); virtual s32 V1(const char *name); };
extern CTxtRes2BA1D8 *D_002BA1D8;
class CTxtRes2BA1D0 { public: virtual void V0(); virtual s32 V1(const char *name, s32 x); };
extern CTxtRes2BA1D0 *D_002BA1D0;
extern const char D_002E1D10[], D_002E1D30[], D_002E1D48[], D_002E1D60[], D_002E1D70[], D_002E1D80[];
extern const char D_002E1D90[], D_002E1DA0[], D_002E1DB0[], D_002E1DC0[], D_002E1DD8[];
void CallFunc220A58();
void Load10A878(const char *path);
void Load109508(const char *path);
extern "C" void func_001094E0();
extern "C" void func_00253A38();
s32 NewEFontWorkSub();
extern "C" void func_0025A060();
extern "C" void func_0010C798();
s32 Alloc1E7E58(s32 n);
void CallMiniGame6Hook();
extern "C" s32 func_00255A30();
extern "C" s32 func_00255E18();
extern "C" void func_002554E0();
void *NewUserFlagSub();
void *NewSysFlag();
void NewResNameMgr();
void CreateCNameDBMgr();
void NewEventMesRes13DE70();
void CreateCUserFlagMgr();
void NewSysFlagSub145BD0();
class CPhotoDBMgr { public: static void Create(); };
class CResortDBMgr { public: static void Create(); };
class CMapDBMgr { public: static void Create(); };
class CMapEffObjRes { public: static CVtAtC *Create(); };
class CInterfRes { public: static CVtAtC *Create(); };
void NewCMapResObj();
class CEnvResObj { public: static void Create(); };
void CreateCCharaResObjSub12D408();
void CreateSub117F98();
void CreateCMenuMgr();
extern void *D_002A26E0, *D_002A26E4;
class CTaskList24F5C0;
extern "C" void func_001E9E00(CTaskList24F5C0 *l);
// @decl-end

CAppMain::CAppMain()
{
    CallFunc220A58();
    Load10A878(D_002E1D10);
    func_001094E0();
    Load109508(D_002E1D10);
    func_00253A38();
    D_002BA128->V1(0x13, 0x300, 0x200, 1);
    NewEFontWorkSub();
    D_002A039C->V1(0x13, 0x50, 0x50, 0x10);
    func_0025A060();
    func_0010C798();
    D_002BA248->SetAlloc(Alloc1E7E58);
    D_002BA248->SetHook(CallMiniGame6Hook);
    D_002BA248->LoadBank(0, D_002E1D30, 9, 8, 0, 0);
    D_002BA248->LoadBank(1, D_002E1D48, 9, 8, 0, 0);
    Func249248((void *)D_002E1D60);
    func_00255A30();
    D_002BA1D4->V3(0, D_002E1D70, D_002E1D80);
    func_00255E18();
    D_002BA1D8->V1(D_002E1D90);
    Func249348();
    func_002554E0();
    Func249248((void *)D_002E1DA0);
    D_002BA1D0->V1(D_002E1DB0, 0);
    Func249348();
    D_002A26E0 = NewUserFlagSub();
    D_002A26E4 = NewSysFlag();
    NewResNameMgr();
    CreateCNameDBMgr();
    NewEventMesRes13DE70();
    CreateCUserFlagMgr();
    NewSysFlagSub145BD0();
    CPhotoDBMgr::Create();
    CResortDBMgr::Create();
    CMapDBMgr::Create();
    m_80 = CMapEffObjRes::Create();
    m_84 = CInterfRes::Create();
    NewCMapResObj();
    CEnvResObj::Create();
    CreateCCharaResObjSub12D408();
    CreateSub117F98();
    func_001E9E00((CTaskList24F5C0 *)this);
    Func235DE0(D_002E1DC0);
    CreateCMenuMgr();
    D_002A5468->V1();
    D_002A5468->V4(D_002BA128->V4());
    D_002A5468->V5(D_002BA128->V5());
    D_002A5468->V2(0);
    Func235DE0(D_002E1DD8);
    m_88 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001E95C0);

s32 CAppMain::Func7()
{
    Func235DE0(D_002E1E10);
    D_002BA248->LoadWave(4, D_002E1E28, 10, 0, 0);
    D_002BA248->LoadWave(5, D_002E1E40, 3, 0, 0);
    D_002BA248->LoadBank(3, D_002E1E58, 9, 8, 0, 0);
    D_002BA248->LoadWave(6, D_002E1E70, 3, 0, 0);
    D_002BA248->LoadWave(7, D_002E1E88, 3, 0, 0);
    D_002BA248->LoadWave(10, D_002E1EA0, 3, 0, 0);
    func_00249428(D_002E1DE8, D_002E1E08);
    func_00249428(D_002E1DE8, D_002E1E00);
    func_00249428(D_002E1DE8, D_002E1EB8);
    func_00249428(D_002E1DE8, D_002E1DF0);
    if (!m_80->V1(0)) return 0;
    if (!m_84->V1(0)) return 0;
    if (Func249248((void *)D_002E1EC0)) {
        func_0013DA10(&m_mes, D_002E1ED8);
        D_002A0CE0->V1(&m_mes);
        Func249348();
    }
    D_002A35B0->V1(0);
    D_002A0D38->V2(0);
    D_002A28D8->V1(0);
    D_002A05D0->V1(0);
    D_002A36E8->V1(0);
    D_002A3AC0->V1(0);
    Func235DE0(D_002E1EE8);
    return 1;
}

void CAppMain::ReleaseTextures()
{
    D_002A3AC0->V2();
    D_002A36E8->V2();
    D_002A05D0->V2();
    D_002A28D8->V2();
    D_002A0D38->V3();
    D_002A35B0->V2();
    D_002A0CE0->V2(&m_mes);
    m_mes.Init();
    m_84->V2();
    m_80->V2();
}

extern "C" void func_001E9E00(CTaskList24F5C0 *l)
{
    AddFadeMgr(l);
    AddSnapMgr(l);
    AddPadMgr(l);
    AddInterfResSub169090(l);
    AddPhotoEventObjSub16D4D8(l);
}

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001E9E48);

void CAppMain::Func4()
{
    if (D_002A5468) D_002A5468->V18();
    D_002BA248->V44();
}

extern "C" void func_001EA780(CTexInfo1EA780 *t, f32 x, f32 y, f32 a)
{
    struct { f32 x, y; s32 z; } pos;
    f32 col[4];
    pos.z = 0;
    col[0] = 128.0f;
    col[1] = 128.0f;
    col[2] = 128.0f;
    col[3] = a * 128.0f;
    pos.x = -(f32)t->m_w * 0.5f + x;
    pos.y = -(f32)t->m_h * 0.5f + y;
    func_00254AA8(t, D_002BA128->V3(), &pos.x, col, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EA838);

extern "C" s32 func_001EAAF0(s32 n)
{
    D_002A5BCC = n;
    D_002A5BD0 = (CAnim1EA **)D_002B91A4(n * 4);
    if (D_002A5BD0 == 0) return 0;
    for (s32 i = 0; i < D_002A5BCC; i++) D_002A5BD0[i] = 0;
    Func1EB828(0);
    func_001EB8E8(0);
    return 1;
}

extern "C" s32 func_001EAB90()
{
    if (D_002A5BD0 == 0) return 0;
    for (s32 i = 0; i < D_002A5BCC; i++) {
        if (D_002A5BD0[i]) func_001ECCA8(i);
    }
    D_002B91B0(D_002A5BD0);
    D_002A5BD0 = 0;
    return 1;
}

f32 Func1EAC30(int i)
{
    CAnim1EA *p = GetAnim(i);
    if (p == 0) return -1.0f;
    return p->m_unk8 * (60.0f / p->m_rate) * p->m_unkA;
}

extern "C" s32 func_001EACB8(CAnim1EA *p)
{
    if (p == 0) return -1;
    if (p->m_unk14) return 0;
    if (p->m_unk18) return 1;
    if (p->m_unk1C) return 2;
    return -1;
}

extern "C" s32 func_001EACF0(s32 i)
{
    CAnim1EA *p = GetAnim(i);
    if (p == 0) return -1;
    return p->m_id;
}

extern "C" f32 func_001EAD38(s32 i, f32 t)
{
    CAnim1EA *p = GetAnim(i);
    if (p == 0) return -1.0f;
    return t * p->m_rate / 60.0f;
}

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EADA0);

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EAE70);

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EAF10);

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EAFF0);

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EB0C0);

extern "C" s32 func_001EB178(s32 mode)
{
    s32 ok = 1;
    switch (mode) {
    case 0: D_002A5BC4 = func_001EB1E8; break;
    case 1: D_002A5BC4 = func_001EB4B0; break;
    default: ok = 0; break;
    }
    return ok;
}

extern "C" s32 func_001EB1C0() { return ((s32 (*)())D_002A5BC4)(); }

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EB1E8);

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EB4B0);

void Func1EB828(int x) { D_002A5BD4 = x; }

void Func1EB838(void *p)
{
    const char *name = (const char *)p;
    if (name == 0) {
        D_002A5BD8 = 0;
        return;
    }
    if (strlen(name) >= 0x40) return (void)Func235DE0(D_002E1FD0, name);
    if (D_002A5BD8 >= 0x20) return (void)Func235DE0(D_002E1FF8);
    return (void)strcpy(D_2EC1F0[D_002A5BD8++], name);
}
