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
INCLUDE_ASM("asm/nonmatchings/CDemoMain", func_001064D8);
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

INCLUDE_ASM("asm/nonmatchings/CDemoMain", Draw__9CDemoMain);

INCLUDE_ASM("asm/nonmatchings/CDemoMain", func_00107848);
