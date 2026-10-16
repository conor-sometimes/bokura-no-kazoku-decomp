#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CStatusBase {
public:
    f32 GetItemUnk34();
    void Select19A858(u32 v);
};
#include "CFlagWork.h"
#include "CProcess.h"
extern CFlagWork *D_002A464C;

class CStatusBaseSub19AE68 {
public:
    void Set(s32 v);
    void Func19ADD0(int v);
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
    void Vf187088();
    void Vf1870B8();
    void Vf1871D0();
    void Vf1872E0();
    int GetJob187758(s32 id, s32 k);
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
    int GetFlag187680(s32 id, s32 k);
    int GetLevel1878F8(s32 id, s32 k);
    void Func188778(f32 *a, f32 *b, f32 *c, f32 *d);
    int Func188F30(f32 x, f32 y);
    int Func1889F8();
    int Func187ED0(s32 k);
    void Func188CD8();
    void Init189018(s32 mode);
    void Func188098(f32 x, f32 y, f32 s, f32 t);
    int Func187D68(s32 i, s32 f, s32 k);
    int Func187A68(char *buf, s32 i, s32 f, s32 k);
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

    CStateMachine m_sm;       // 0x0
    s32 m_unk48;              // 0x48
    s32 m_mode;               // 0x4C
    s32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    s32 m_unk58b;             // 0x58
    u8 pad5C[0x4];
    void *m_unk60;            // 0x60
    CStatusBase* m_status;    // 0x64
    void *m_unk68;            // 0x68
    CStatusBaseSub19AE68* m_unk6C; // 0x6C
    void *m_unk70;            // 0x70
    u8 pad74[0x114];
    u64 m_unk188;             // 0x188
    u64 m_unk190;             // 0x190
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
int Func235DE0(const char *fmt, ...) throw();
extern CFlagWork *D_002A4638[6];
extern CFlagWork *D_002A5358;
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
class CStatusBaseSub19AD40 {
public:
    ~CStatusBaseSub19AD40();
};
class CStatusBaseDel {
public:
    u8 pad[0x58];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual ~CStatusBaseDel();
};
class CChrBodyData {
public:
    ~CChrBodyData();
    u8 pad0[0x60];
    void *m60;                // 0x60
    CStatusBaseDel *m64;      // 0x64
    void *m68;                // 0x68
    CStatusBaseSub19AD40 *m6C; // 0x6C
    void *m70;                // 0x70
};
extern "C" int func_00245818(void *p, s32 v);
class CChrBodyWinSub18A410 {
public:
    void Init18A480();
    void Close();
    u8 pad0[0x58];
    CChrBodySub245818 m58;    // 0x58
    u8 pad59[0xB];
    CChrBodyData *m64;        // 0x64
    void *m68;                // 0x68
};
CChrBodyWin *NewChrBodyWin();
CChrBodyWinSub18A410 *NewChrBodyWinSub18A410();

inline f32 Clamp01(f32 v) { return (v < 1.0f ? v : 1.0f) < 0.0f ? 0.0f : (v < 1.0f ? v : 1.0f); }

extern char D_002DB358[], D_002DB3B0[];
extern const char *D_002A430C;
extern s32 D_002A4310;
extern s32 D_002A4314;
void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
s32 Func249248(void *buf);
void Func249348();
void Func225088();
int Func2250C0();

extern CFlagWork *D_002A4B60;

struct CChrBodySub {
    void *m0;
    s32 m4, m8, mC, m10, m14, m18, m1C, m20;
};
void Func2251E8();
void Func227DC8(long a, s32 b, s32 c);
extern "C" void func_00227BF0(u64 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" void func_00227A20();
extern "C" void func_00227AA8();
extern "C" void func_00226DF8(s32 reg, u64 v);
#define GS_SET_TEX0(tbp, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((u64)(tbp) | ((u64)(tbw) << 14) | ((u64)(psm) << 20) | ((u64)(tw) << 26) | ((u64)(th) << 30) | \
     ((u64)(tcc) << 34) | ((u64)(tfx) << 35) | ((u64)(cbp) << 37) | ((u64)(cpsm) << 51) | \
     ((u64)(csm) << 55) | ((u64)(csa) << 56) | ((u64)(cld) << 61))
#define GS_SET_CLAMP(wms, wmt, minu, maxu, minv, maxv) \
    ((u64)(wms) | ((u64)(wmt) << 2) | ((u64)(minu) << 4) | ((u64)(maxu) << 14) | \
     ((u64)(minv) << 24) | ((u64)(maxv) << 34))

#include "CMenuRecordWin.h"
struct CChrSprPkt {
    s32 u0, v0, u1, v1;
    s32 x0, y0, x1, y1;
    s32 r, g, b, a;
};
extern "C" void func_001866D0(s32 *xy, f32 x, f32 y, f32 w, f32 h);
inline void PutRGBA(CChrSprPkt *p) { func_00226DF8(1, (u64)p->r | ((u64)p->g << 8) | ((u64)p->b << 16) | ((u64)p->a << 24)); }
inline void PutXYZ(s32 x, s32 y) { func_00226DF8(5, (u64)x | ((u64)y << 16)); }
inline void PutUV(s32 u, s32 v) { func_00226DF8(3, (u64)u | ((u64)v << 16)); }
// Slot functions of _vt$11CChrBodyWin (vptr at 0x58, CStatusBase's 7 virtuals).
class CChrBodyWinVt {
public:
    u8 pad[0x58];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual int V6();
};
struct CChrBodyStat {
    s32 a, b, c, d, e;
};
struct CChrBodyStatTbl {
    u8 pad[0x5C];
    CChrBodyStat st[6];
};
void *Func237570(int size);
void Func237A88(void *p, int n);
void *Func237C30(void *p);
void Func238158(void *p, int v);
class CUnk1A4298 {
public:
    int Func1A4298();
};
class CUnk237E90 {
public:
    void Func237E90(int v);
};
#include "CMenuMgrSub1B5BF8.h"
extern CMenuMgrSub1B5BF8 *D_002A5534;
extern "C" int func_001B5E18(CMenuMgrSub1B5BF8 *p);
extern "C" int func_001B5FE0(CMenuMgrSub1B5BF8 *p, f32 x, f32 y, const char *s);
void Func225240(s32 v);
extern "C" int sprintf(char *buf, const char *fmt, ...);
struct CChrBodyWinItem {
    u8 pad[0x34];
    f32 m34;
};

class CStatusWin {
public:
    void SetUnk64(u32 a, int b);
    void SetUnk50(u32 a);
    void Func19F400();
};
extern char D_002DB428[];
extern "C" void func_00185648(s32 no);
extern "C" void func_00185868(s32 no, s32 a, s32 b);
struct CChildStatusObj {
    u8 pad0[0x50];
    s32 m50;
    s32 m54;
    s32 m58;
    s32 m5C;
    CStatusWin *m60;
    CStatusBase *m64;
    CStatusBase *m68;
    CStatusBaseSub19AE68 *m6C;
    CStatusBase *m70;
    void SetChild1893A0(s32 no);
    int Draw18A1F0();
};

extern "C" int func_0019FA50(CStatusWin *p);
extern "C" int func_0019B1F8(CStatusBaseSub19AE68 *p);
extern "C" int func_0019FC30(CStatusWin *p);

#include "IGameDBMgr.h"
s32 Func145738(s32 a, s32 b);
extern char D_002DB038[], D_002DB068[];
struct CJobRec {
    s32 m0;
    u8 pad4[0x8];
    s32 mC;
};

void *Func24A4C0(const char *name);
const char *Func24ADE0(const char *p, char *buf, int n);
const char *Func24A570(const char *src, char *buf, const char *a, const char *b);
extern "C" const char *func_0024AD10(const char *p, char *buf, s32 a, s32 n);
extern "C" s32 func_00289118(const char *s);
extern "C" const char *func_0024A710(const char *p, s32 *v, s32 k, const char *s1, const char *s2);
extern char D_002DB0C0[], D_002DB2A0[], D_002DB2B8[], D_002DB2C0[], D_002DB2C8[], D_002DB2D0[], D_002DB2D8[];
extern char D_002DB2E0[], D_002DB2E8[];
struct CChrTypeImgData {
    s32 msg[7][14];           // 0x0
    u8 pad188[0x1D8];
    s32 m360;                 // 0x360
    s32 m364;                 // 0x364
    s32 m368;                 // 0x368
    u8 pad36C[0x4];
    s32 m370;                 // 0x370
    int Load1884F0(const char *name);
};
extern "C" void CtorStatusWinV(void *p, s32 k) asm("__11CStatusWinVi");
extern "C" void CtorStatusWin(void *p, s32 a, void *b, s32 c) asm("__10CStatusWiniii");
extern "C" void CtorChrSchoolWin(void *p, s32 k) asm("__13CChrSchoolWini");
extern "C" void CtorStatusSub(void *p, s32 k) asm("Init19AC20__20CStatusBaseSub19AE68i");
extern "C" void func_00187038(void *p);
extern char D_002DB3D8[];
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CChrBodyWin", D_002DAFD0);
INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187038);

void CChrBodyWin::Vf187088() {
    ((CChrBodyWinVt *)this)->V1();
}

void CChrBodyWin::Vf1870B8() {
    CChrBodyStatTbl *t = (CChrBodyStatTbl *)this;
    t->st[m_unk50].a = D_002A5358->Func1091B0(m_unk50 + 0xB8);
    t->st[m_unk50].b = D_002A5358->Func1091B0(m_unk50 + 0xBE);
    t->st[m_unk50].c = D_002A5358->Func1091B0(m_unk50 + 0xC4);
    t->st[m_unk50].d = D_002A5358->Func1091B0(m_unk50 + 0xCA);
    t->st[m_unk50].e = D_002A5358->Func1091B0(m_unk50 + 0xD0);
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001871C0() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001871C8() {
}

void CChrBodyWin::Vf1871D0() {
    CChrBodyStatTbl *t = (CChrBodyStatTbl *)this;
    t->st[m_unk50].a = D_002A5358->Func1091B0(m_unk50 + 0x190);
    t->st[m_unk50].b = D_002A5358->Func1091B0(m_unk50 + 0x196);
    t->st[m_unk50].c = D_002A5358->Func1091B0(m_unk50 + 0x19C);
    t->st[m_unk50].d = D_002A5358->Func1091B0(m_unk50 + 0x1A2);
    t->st[m_unk50].e = D_002A5358->Func1091B0(m_unk50 + 0x1A8);
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001872D8() {
}

void CChrBodyWin::Vf1872E0() {
    CChrBodyStatTbl *t = (CChrBodyStatTbl *)this;
    f32 xy[2];
    char buf[0x100];
    u8 *p = (u8 *)Func237570(0x60);
    Func237A88(p, 6);
    Func238158(Func237C30(p + 0x50), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_unk48)->Func1A4298());
    ((CUnk237E90 *)(p + 0x30))->Func237E90(func_001B5E18(D_002A5534));
    D_002A5534->Reset();
    D_002A5534->SetUnk30(1);
    D_002A5534->SetUnk10(0.78f, 0.78f, 0.78f);
    D_002A5534->SetUnk1C(((CChrBodyWinItem *)m_unk48)->m34);
    D_002A5534->SetUnk0(0.9f, 0.9f);
    sprintf(buf, "%3dc", t->st[m_unk50].a);
    ((CMenuRecordWin *)m_unk48)->Func1A39A8(&xy[0], (s32 *)&xy[1], 2);
    ((CUnk237E90 *)(p + 0x30))->Func237E90(func_001B5FE0(D_002A5534, xy[0], xy[1], buf));
    sprintf(buf, "%2dk", t->st[m_unk50].b);
    ((CMenuRecordWin *)m_unk48)->Func1A39A8(&xy[0], (s32 *)&xy[1], 3);
    ((CUnk237E90 *)(p + 0x30))->Func237E90(func_001B5FE0(D_002A5534, xy[0], xy[1], buf));
    sprintf(buf, "B%d", t->st[m_unk50].c);
    ((CMenuRecordWin *)m_unk48)->Func1A39A8(&xy[0], (s32 *)&xy[1], 4);
    ((CUnk237E90 *)(p + 0x30))->Func237E90(func_001B5FE0(D_002A5534, xy[0], xy[1], buf));
    sprintf(buf, "W%d", t->st[m_unk50].d);
    ((CMenuRecordWin *)m_unk48)->Func1A39A8(&xy[0], (s32 *)&xy[1], 5);
    ((CUnk237E90 *)(p + 0x30))->Func237E90(func_001B5FE0(D_002A5534, xy[0], xy[1], buf));
    sprintf(buf, "H%d", t->st[m_unk50].e);
    ((CMenuRecordWin *)m_unk48)->Func1A39A8(&xy[0], (s32 *)&xy[1], 6);
    ((CUnk237E90 *)(p + 0x30))->Func237E90(func_001B5FE0(D_002A5534, xy[0], xy[1], buf));
    Func225088();
    Func225240((s32)p);
    Func2250C0();
}
INCLUDE_RODATA("asm/nonmatchings/CChrBodyWin", D_002DB018);
INCLUDE_RODATA("asm/nonmatchings/CChrBodyWin", D_002DB028);   // 11CStatusBase (base of the vptr class), end of this object

CChrBodyWin *NewChrBodyWin() {
    CChrBodyWin *p = (CChrBodyWin *)operator new(0x3A0);
    p->Init1883D0();
    return p;
}

