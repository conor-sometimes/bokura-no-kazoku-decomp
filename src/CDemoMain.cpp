#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "IUserFlagMgr.h"
extern s32 D_0029F2C0[];
#include "CProcess.h"
#include "CFlagWork.h"
struct CTaskTag8 {
    CTaskTag8() {
        m_unk4 = -1;
        m_unk2 = 0;
        m_unk0 = 0;
    }
    s16 m_unk0;               // 0x0
    s16 m_unk2;               // 0x2
    s32 m_unk4;               // 0x4
};
class CEventRes {
public:
    CEventRes();
    ~CEventRes();
    u8 pad0[0x6C];
};
class CEventObj {
public:
    CEventObj();
    ~CEventObj();
    u8 pad0[0xFECC];
};
class CSndWorkReal {
public:
    CSndWorkReal();
    ~CSndWorkReal();
    u8 pad0[0xE0];
};
class CSceneSet {
public:
    CSceneSet();
    ~CSceneSet();
    u8 pad0[0x40];
};
class CMovieObj {
public:
    CMovieObj();
    int Func13EDC8();
    ~CMovieObj();
    u8 pad0[0x178];
};
struct CDemoEntry {
    s32 m_unk0;               // 0x0
    s32 m_unk4;               // 0x4
};
extern CDemoEntry D_0029F2A0[];
// Other task managers called through their vtables.
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
extern CTaskMgrIf *D_0029F390;
extern CTaskMgrIf *D_0029F394;
extern CTaskMgrIf *D_0029F398;
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CDemoMain.
class CDemoMain : public CProcess {
public:
    CDemoMain(s32 k);
    virtual ~CDemoMain();
    virtual void Update();
    virtual void Draw();

    u8 pad18[0x14];
    CTaskTag8 m_tag;          // 0x2C
    u8 pad34[0x40];
    CDemoEntry *m_entry;      // 0x74
    CEventRes m_res;          // 0x78
    CEventObj m_obj;          // 0xE4
    CSndWorkReal m_snd;       // 0xFFB0
    CSceneSet m_scene;        // 0x10090
    CMovieObj m_movie;        // 0x100D0
    s32 m_flag;               // 0x10248
};
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern "C" int func_00249248(void *f);
extern "C" void func_00249348();
extern "C" void func_00135BE0(void *obj, void *p);
extern "C" void func_0012B180(void *snd, void *p);
void *Func237570(s32 size);
void Func237A88(void *p, s32 n);
void *Func237C30(void *p);
void Func238158(void *p, s32 v);
void Func225088();
int Func2250C0();
void Func225240(s32 v);
class CUnk237E90 {
public:
    void Func237E90(int v);
};
class CUnk2A5BC0 {
public:
    u8 pad0[0x50];
    CUnk237E90 m_unk50;       // 0x50
    u8 pad51[0xF];
    CUnk237E90 m_unk60;       // 0x60
};
extern CUnk2A5BC0 *D_002A5BC0;
class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};
class CEndingMain : public CProcess {
public:
    CEndingMain(s32 k);
    virtual ~CEndingMain();
    u8 pad18[0x2F4 - 0x18];
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CDemoMain", __9CDemoMaini);

CDemoMain::~CDemoMain() {
    D_002A26E0->Func108FF0(0, m_flag);
    D_002A26E4->Func108700();
    D_0029F390->SetUnk18(1);
    D_0029F394->Set70(-1);
    D_0029F394->Set68(0);
    D_0029F398->Set70(0);
}

INCLUDE_RODATA("asm/nonmatchings/CDemoMain", D_002D1A48);
INCLUDE_RODATA("asm/nonmatchings/CDemoMain", D_002D1A50);
INCLUDE_RODATA("asm/nonmatchings/CDemoMain", D_002D1A58);
INCLUDE_RODATA("asm/nonmatchings/CDemoMain", D_002D1A60);
int DemoLoadFlags(void *unused, const char *name) {
    char path[0x400];
    sprintf(path, "data/demo/%s.xap", name);
    int ok = 0;
    int opened = 0;
    if (func_00249248(path)) {
        opened = 1;
        ok = D_002A26E4->Func108E38("curflag.txt") != 0;
    }
    if (opened) func_00249348();
    return ok;
}
INCLUDE_RODATA("asm/nonmatchings/CDemoMain", D_002D1A90);
INCLUDE_RODATA("asm/nonmatchings/CDemoMain", D_002D1A98);
INCLUDE_RODATA("asm/nonmatchings/CDemoMain", D_002D1AA0);
INCLUDE_RODATA("asm/nonmatchings/CDemoMain", D_002D1AA8);
INCLUDE_RODATA("asm/nonmatchings/CDemoMain", D_002D1AB0);
INCLUDE_RODATA("asm/nonmatchings/CDemoMain", D_002D1AB8);
INCLUDE_RODATA("asm/nonmatchings/CDemoMain", D_002D1AC0);
INCLUDE_RODATA("asm/nonmatchings/CDemoMain", D_002D1AC8);
INCLUDE_RODATA("asm/nonmatchings/CDemoMain", D_002D1AE8);

void DemoKey106558(const s8 *p) {
    s32 i;
    for (i = 0; D_0029F2C0[i] >= 0; i++) {
        if (D_0029F2C0[i] == *p) {
            D_002A0D38->Vf298BB0(i + 0x10);
            return;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/CDemoMain", Update__9CDemoMain);

void CDemoMain::Draw() {
    switch (m_entry->m_unk0) {
    case 1: {
        void *p = Func237570(0x260);
        Func237A88(p, 0x26);
        Func238158(Func237C30((u8 *)p + 0x250), 1);
        Func225088();
        Func225240((s32)p);
        D_002A5BC0->m_unk50.Func237E90(Func2250C0());
        func_00135BE0(&m_obj, p);
        func_0012B180(&m_snd, p);
        return;
    }
    case 0:
        D_002A5BC0->m_unk60.Func237E90(m_movie.Func13EDC8());
        break;
    }
}

void CreateEndingMain(CTaskList24F5C0 *list, s32 k) {
    CEndingMain *p = new CEndingMain(k);
    list->Func24F5C0(p, 0);
}
