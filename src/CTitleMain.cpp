#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMemTex.h"
int Func225088();
int Func2250C0();

extern const char D_002D1988[];
#include "CProcess.h"
// Font/text object (library side, ctor 0x25C230, dtor 0x25C2C0; names in config/aliases.ld).
class CFont25C230 {
public:
    CFont25C230();
    ~CFont25C230();
    u8 pad0[0x6C];
};
class CMovieObj {
public:
    CMovieObj();
    ~CMovieObj();
    u8 pad0[0x178];
};
class CSndWorkReal {
public:
    CSndWorkReal();
    ~CSndWorkReal();
    u8 pad0[0xE0];
};
class CMapObj {
public:
    CMapObj();
    ~CMapObj();
    u8 pad0[0x34];
};
// Other task managers called through their vtables (CDemoMain.cpp has the same view).
class CTaskMgrIf : public CTask {
public:
    virtual void Vf7();
    virtual void Vf8();
    virtual void Vf9();
    virtual void Vf10();
    virtual void SetUnk18(s32 v);
    virtual void Set68(s32 v);
    virtual void Set70(s32 v);
};
extern CTaskMgrIf *D_0029F394;
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CTitleMain.
class CTitleMain : public CProcess {
public:
    CTitleMain();
    virtual ~CTitleMain();
    virtual void Update();
    virtual void Draw();
    virtual s32 Func7();
    virtual void ReleaseTextures();
    void Func1056A8();
    void Func101480();
    void Func101368(const char *s, s32 v);
    void CallFunc101368(s32 v);
    void InitResMgrs();
    void ReleaseResMgrs();

    u8 pad18[0x14];
    CStateMachine m_sm;       // 0x2C
    CMemTex m_tex74;          // 0x74
    CMemTex m_texA0;          // 0xA0
    CMemTex m_texCC;          // 0xCC
    CMemTex m_texF8;          // 0xF8
    f32 m_unk124;             // 0x124
    u8 pad128[0x4];
    s32 m_unk12C;             // 0x12C
    u8 pad130[0x18];
    s32 m_unk148;             // 0x148
    u8 pad14C[0x8];
    CFont25C230 m_font;       // 0x154
    u8 pad1C0[0xC];
    s32 m_unk1CC;             // 0x1CC
    CMovieObj m_movie;        // 0x1D0
    u8 pad348[0x4];
    s32 m_unk34C;             // 0x34C
    u8 pad350[0x8];
    CStateMachine m_sm2;      // 0x358
    char m_name[0x300];       // 0x3A0
    CSndWorkReal m_snd;       // 0x6A0
    CMapObj m_map;            // 0x780
    u8 pad7B4[0x10];
    s32 m_unk7C4;             // 0x7C4
    s32 m_unk7C8;             // 0x7C8
};
int Func249248(void *buf);
void Func249348();
extern "C" void func_00254248(CMemTex *tex, const char *name);

class CResCache {
public:
    u8 pad0[0x13C];
};
// The resource managers (CCharaResMgr, CMapResMgr, CEnvResMgr) as seen through their
// interfaces: vptr after CResCache's 0x13C bytes. Slot 5 exists in CEnvResMgr only.
class IResMgr : public CResCache {
public:
    virtual ~IResMgr();
    virtual void V1();
    virtual s32 *FindRes(s32 id);
    virtual void Init(s32 size, s32 n);
    virtual void CallFunc250368();
    virtual void V5();
};
extern IResMgr *D_002A0BE4;
extern IResMgr *D_002A0BE8;
extern IResMgr *D_002A0BEC;

// Graphics/sound manager at D_002BA248 (vptr at 0); only the slots called here matter.
class CGsMgr {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual int V30(s32 a, const char *name, s32 b, s32 c, s32 d);
    virtual void V31();
    virtual void V32(s32 a, s32 b);
};
extern CGsMgr *D_002BA248;
class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};
// CDemoMain (another lane's unit; constructor through config/aliases.ld).
class CDemoMain : public CProcess {
public:
    CDemoMain(s32 k);

    u8 pad18[0x10238];
};
#include "CFlagWork.h"

#include "libc.h"

class CGsDev {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual s32 GetCtx();
};
extern CGsDev *D_002BA128;
struct CMemTexInfo {
    u8 pad0[0x10];
    s32 m_w;                  // 0x10
    s32 m_h;                  // 0x14
};
struct CVec3 { f32 x, y, z; };
extern "C" void func_00254AA8(CMemTex *t, s32 ctx, CVec3 *pos, f32 *col, f32 *scl, s32 k);
int CallFunc225088And2250C0();
// @decl-end

CTitleMain::CTitleMain() {
    m_unk124 = 1.0f;
    m_unk12C = 0;
    m_unk148 = 0;
    m_unk1CC = 0;
    D_0029F394->Set70(11);
    InitResMgrs();
}

CTitleMain::~CTitleMain() {
    ReleaseResMgrs();
    D_0029F394->Set70(-1);
    CTitleMain::ReleaseTextures();
}

void CTitleMain::InitResMgrs() {
    D_002A0BE8->Init(-1, -1);
    D_002A0BEC->CallFunc250368();
    D_002A0BE4->Init(-1, -1);
}

void CTitleMain::ReleaseResMgrs() {
    D_002A0BE4->CallFunc250368();
    D_002A0BEC->V5();
    D_002A0BE8->CallFunc250368();
}

INCLUDE_RODATA("asm/nonmatchings/CTitleMain", D_002D1910);
INCLUDE_RODATA("asm/nonmatchings/CTitleMain", D_002D1918);
INCLUDE_RODATA("asm/nonmatchings/CTitleMain", D_002D1920);
s32 CTitleMain::Func7() {
    if (Func249248((void *)"data/title.xap")) {
        func_00254248(&m_tex74, "title.tm2");
        func_00254248(&m_texA0, "copyright.tm2");
        func_00254248(&m_texF8, "opening.tm2");
        Func249348();
    }
    if (Func249248((void *)"data/sound")) {
        D_002BA248->V30(8, "ki0004.xws", 7, 0, 0);
        m_unk34C = 0x8080000;
        Func249348();
    }
    return 1;
}
INCLUDE_RODATA("asm/nonmatchings/CTitleMain", D_002D1988);

void CTitleMain::ReleaseTextures() {
    D_002BA248->V32(8, 0);
    m_texF8.Func2546F0();
    m_texA0.Func2546F0();
    m_tex74.Func2546F0();
}

void CTitleMain::Func101368(const char *s, s32 v) {
    if (strcmp(m_name, s)) {
        strcpy(m_name, s);
        m_unk7C4 = v;
        m_unk7C8 = 1;
    }
}

void CTitleMain::CallFunc101368(s32 v) {
    Func101368(D_002D1988, v);
}

int Func101400() {
    if (D_002A26E0->Func1091B0(0xD4) < 3) {
        return D_002A26E0->Func1091B0(0xD3) > 0;
    }
    return 2;
}

void CTitleMain::Update() {
    Func101480();
    Func1056A8();
}

INCLUDE_RODATA("asm/nonmatchings/CTitleMain", D_002D1990);
INCLUDE_RODATA("asm/nonmatchings/CTitleMain", D_002D19B0);
INCLUDE_RODATA("asm/nonmatchings/CTitleMain", D_002D19F0);
INCLUDE_ASM("asm/nonmatchings/CTitleMain", Func101480__10CTitleMain);
INCLUDE_RODATA("asm/nonmatchings/CTitleMain", D_002D1A10);
INCLUDE_RODATA("asm/nonmatchings/CTitleMain", D_002D1A18);
INCLUDE_RODATA("asm/nonmatchings/CTitleMain", D_002D1A20);
INCLUDE_RODATA("asm/nonmatchings/CTitleMain", D_002D1A28);
INCLUDE_RODATA("asm/nonmatchings/CTitleMain", D_002D1A30);

INCLUDE_ASM("asm/nonmatchings/CTitleMain", Func1056A8__10CTitleMain);

int CallFunc225088And2250C0() {
    Func225088();
    return Func2250C0();
}

void DrawTitleTex(CMemTex *t, f32 x, f32 y, f32 a, f32 s) {
    CVec3 pos;
    f32 scl[2];
    f32 col[4];
    if (a <= 0.0f) {
        CallFunc225088And2250C0();
        return;
    }
    pos.x = -(f32)((CMemTexInfo *)t)->m_w * s * 0.5f + x;
    pos.y = -(f32)((CMemTexInfo *)t)->m_h * s * 0.5f + y;
    pos.z = 0.0f;
    scl[0] = s;
    scl[1] = s;
    col[0] = 128.0f;
    col[1] = 128.0f;
    col[2] = 128.0f;
    col[3] = a * 128.0f;
    func_00254AA8(t, D_002BA128->GetCtx(), &pos, col, scl, 0);
}

INCLUDE_ASM("asm/nonmatchings/CTitleMain", Draw__10CTitleMain);

void AddDemoMain(CTaskList24F5C0 *list, s32 k) {
    CDemoMain *p = new CDemoMain(k);
    list->Func24F5C0(p, 0);
}
