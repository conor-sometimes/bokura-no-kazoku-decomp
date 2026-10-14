#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMemTex.h"
int Func225088();
int Func2250C0();

extern const char D_002D1988[];
class CTitleMain {
public:
    void Func101450();
    void Func1056A8();
    void Func101480();
    void Func101368(const char *s, s32 v);
    void CallFunc101368(s32 v);
    void ReleaseTextures();
    int Func7();

    u8 pad0[0x74];
    CMemTex m_tex74;          // 0x74
    CMemTex m_texA0;          // 0xA0
    u8 padCC[0x2C];
    CMemTex m_texF8;          // 0xF8
    u8 pad124[0x228];
    s32 m_unk34C;             // 0x34C
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
#include "CProcess.h"
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
class CFlagWork {
public:
    int Func1091B0(s32 id);
};
extern CFlagWork *D_002A26E0;
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CTitleMain", __10CTitleMain);

INCLUDE_ASM("asm/nonmatchings/CTitleMain", func_00101048);

void InitResMgrs101140() {
    D_002A0BE8->Init(-1, -1);
    D_002A0BEC->CallFunc250368();
    D_002A0BE4->Init(-1, -1);
}

void ReleaseResMgrs1011C8() {
    D_002A0BE4->CallFunc250368();
    D_002A0BEC->V5();
    D_002A0BE8->CallFunc250368();
}

INCLUDE_RODATA("asm/nonmatchings/CTitleMain", D_002D1910);
INCLUDE_RODATA("asm/nonmatchings/CTitleMain", D_002D1918);
INCLUDE_RODATA("asm/nonmatchings/CTitleMain", D_002D1920);
int CTitleMain::Func7() {
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

INCLUDE_ASM("asm/nonmatchings/CTitleMain", Func101368__10CTitleMainPCci);

void CTitleMain::CallFunc101368(s32 v) {
    Func101368(D_002D1988, v);
}

int Func101400() {
    if (D_002A26E0->Func1091B0(0xD4) < 3) {
        return D_002A26E0->Func1091B0(0xD3) > 0;
    }
    return 2;
}

void CTitleMain::Func101450() {
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

INCLUDE_ASM("asm/nonmatchings/CTitleMain", func_00105BC8);

INCLUDE_ASM("asm/nonmatchings/CTitleMain", func_00105CB0);

void AddDemoMain(CTaskList24F5C0 *list, s32 k) {
    CDemoMain *p = new CDemoMain(k);
    list->Func24F5C0(p, 0);
}
INCLUDE_RODATA("asm/nonmatchings/CTitleMain", D_002D1A38);
