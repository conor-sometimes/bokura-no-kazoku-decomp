#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym __nw__5CTaskUi 0x24F2E8
//@sym __builtin_vec_delete 0x2456D0
#include "CTask.h"
class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};
// Task-side tag of a few task classes: m4 = -1, m0 = m2 = 0.
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
// Font/text object (library side, ctor 0x25C230).
class CFont25C230 {
public:
    CFont25C230();
    u8 pad0[0x488];
};
// Interface manager interface (vtable _vt$10IInterfMgr).
class IInterfMgr : public CTask {
public:
    virtual ~IInterfMgr();
    virtual void Init1691D0() = 0;
};
class CInterfMgr : public IInterfMgr {
public:
    CInterfMgr();
    virtual ~CInterfMgr();
    virtual void Init1691D0();

    CTaskTag8 m_tag8;         // 0x8
    u8 pad10[0x40];
    CFont25C230 m_font50;     // 0x50
    u8 pad4D8[0x450];
    CTaskTag8 m_tag928;       // 0x928
    u8 pad930[0x40];
    CFont25C230 m_font970;    // 0x970
};
extern CInterfMgr *D_002A3568;
int GetFontTable(u32 i);
extern "C" void func_0025C438(int tbl, CFont25C230 *f);
void Func23B1D0(s32 h);
#include "CList.h"
// Vtable _vt$10CInterfRes: destructor, Load, Release. Key method: the destructor (0x168DF0,
// merged unit: stays asm).
class CInterfRes : public CListTag {
public:
    CInterfRes();
    virtual ~CInterfRes();
    virtual s32 Load(const char *path);
    virtual void Release();

    s32 *m_handles;           // 0x10
};
extern CInterfRes *D_002A3540;
extern s32 D_002A355C, D_002A3560, D_002A3564;
extern const char *D_002A3548[];
extern void (*D_002B91B0)(void *p);
extern "C" void *func_00248E60(const char *name);
s32 Func205BA0(void *p);
void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
s32 Func249248(void *buf);
void Func249348();

//@sym __builtin_vec_delete 0x2456D0
// @decl-end

CInterfRes::CInterfRes() {
    D_002A3540 = this;
    m_handles = 0;
}

INCLUDE_ASM("asm/nonmatchings/CInterfRes", func_00168DF0);

s32 CInterfRes::Load(const char *path) {
    u8 buf[0x100];
    s32 i;
    Release();
    Func2491A8(buf, path, D_002A355C, D_002A3560, D_002A3564);
    if (!Func249248(buf)) return 0;
    m_handles = new s32[4];
    for (i = 0; i < 4; i++) {
        void *p;
        m_handles[i] = -1;
        p = func_00248E60(D_002A3548[i]);
        if (p) {
            m_handles[i] = Func205BA0(p);
            D_002B91B0(p);
        }
    }
    Func249348();
    return 1;
}

void CInterfRes::Release() {
    if (m_handles) {
        s32 i;
        for (i = 0; i < 4; i++) {
            if (m_handles[i] >= 0) {
                Func23B1D0(m_handles[i]);
                m_handles[i] = -1;
            }
        }
        if (m_handles) {
            delete[] m_handles;
        }
        m_handles = 0;
    }
}

void AddInterfResSub169090(CTaskList24F5C0 *list) {
    CInterfMgr *t = new CInterfMgr;
    list->Func24F5C0(t, 0);
}

CInterfMgr::CInterfMgr() {
    D_002A3568 = this;
    func_0025C438(GetFontTable(4), &m_font50);
    CInterfMgr::Init1691D0();
}
