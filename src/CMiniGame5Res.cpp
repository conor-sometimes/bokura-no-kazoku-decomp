#pragma interface
#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym __10CMiniGame5 0x1DEF58
#include "CProcess.h"
#include "CPushBuf.h"
#define CLISTTAG_INLINE_DTOR
#include "CList.h"
extern "C" void *memset(void *p, int c, unsigned int n);
extern "C" int sprintf(char *buf, const char *fmt, ...);
void Func235DE0(const char *fmt, ...) throw();
int Func251B88();
class CLayoutResSub1B8748 {
public:
    void Release();
    void ReadInts(const char *key, int *out, int n);
};
class CLayoutRes {
public:
    CLayoutRes();
    virtual ~CLayoutRes();
    CLayoutResSub1B8748 *Sub() { return (CLayoutResSub1B8748 *)this; }
    CPushBuf m_buf;           // 0x00
    u8 padC[0x14];
    // vptr 0x20
};
struct CLayoutEntry {
    u8 pad0[0x20];
    f32 m20, m24;
};
class CLayoutObj {
public:
    int Set(CLayoutRes *res, int v);
    CLayoutEntry *FindEntry(const char *name);
    void SetRect(f32 x, f32 y, f32 w, f32 h) { m40 = x; m44 = y; m48 = w; m4C = h; }
    u8 pad0[0x40];
    f32 m40, m44, m48, m4C;
    u8 pad50[0x170 - 0x50];
};
extern "C" void func_001B9D40(void *p);
extern "C" void func_001BD188(void *p);
extern "C" void func_001BD1E0(void *p, CLayoutRes *res, const char *name);
extern "C" void func_0025C230(void *p);
class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
struct CMiniGame5Quest {
    s32 m_rank;               // 0x0
    s32 m4, m8, mC;           // 0x4
    s32 m10;                  // 0x10
};
struct CMiniGame5QuestList {
    CMiniGame5Quest *m_items; // 0x0
    s32 m_num;                // 0x4
};
class CMiniGame5Res : public CListTag {
public:
    virtual ~CMiniGame5Res();
    virtual int Load(const char *dir);
    virtual void Release();
    CPushBuf m_buf;                 // 0x10
    CMiniGame5QuestList m_list[3];  // 0x1C
    CLayoutRes m34;                 // 0x34
    CLayoutRes m58;                 // 0x58
};
extern CMiniGame5Res *D_002A5A08;
extern "C" void func_002491A8(void *f, const char *dir, const char *a, const char *b, const char *c);
extern "C" int func_00249248(void *f);
extern "C" void func_00249348();
extern "C" char *func_0024A4C0(const char *name);
extern "C" const char *func_0024A570(const char *s, char *out, const char *sep, const char *ws);
extern "C" const char *func_0024AF10(const char *s, const char *key);
extern "C" const char *func_0024AFE8(const char *s, char *buf, s32 k, s32 size);
extern "C" const char *func_0024A710(const char *p, s32 *v, s32 k, const char *s1, const char *s2);
extern "C" s32 func_0024B040(const char *p, s32 k);
extern "C" int func_001B8760(void *res, void *f);
extern "C" void func_00248C30(CPushBuf *b);
extern "C" void func_00248C70(CPushBuf *b);
extern "C" char *func_00248DA8(CPushBuf *b);
extern "C" s32 func_00248DC0(CPushBuf *b);
extern void (*D_002B91B0)(void *p);
extern char D_002E1698[];
extern char D_002E16A0[];
extern char D_002E16A8[];
extern char D_002E16B0[];
inline s32 Clamp(s32 v, s32 lo, s32 hi) { return v < lo ? lo : (v <= hi ? v : hi); }
struct CRand {
    u32 m_seed;
    CRand() { m_seed = 1; }
    u32 Next() {
        m_seed = m_seed * 0x19660D + 1;
        return (m_seed >> 12) & 0xFFFF;
    }
};
inline s32 RandRange(CRand *rnd, s32 lo, s32 hi) {
    if (hi < lo) hi = lo;
    if (lo == hi) return lo;
    return ((rnd->Next() << 16) | rnd->Next()) % (u32)(hi - lo + 1) + lo;
}
#include "CFlagWork.h"
extern s32 D_002A5A10[3];
class CMiniGame5 : public CProcess {
public:
    CMiniGame5();
    virtual ~CMiniGame5();
    virtual void Update();
    virtual void Draw();
    CMiniGame5Quest *GetQuest();
    void SetX(f32 x);
    void InitQuests();
    void SetCursor(s32 set);
    s32 Func1DF2F0(s32 i, s32 base, s32 *out);
    u8 pad18[0x14];
    CRand m_rand;                   // 0x2C
    CStateMachine m_state;          // 0x30
    s32 m_conf[0x17];               // 0x78
    u8 padD4[0xC];
    CLayoutObj m_lay[5];            // 0xE0
    u8 pad810[0x10];
    u8 m820[0x170];                 // 0x820
    u8 m990[0xB0];                  // 0x990
    s32 m_sel[3];                   // 0xA40
    s32 m_cur;                      // 0xA4C
    s32 m_curPos;                   // 0xA50
    u8 padA54[0xAC4 - 0xA54];
    s32 m_unkAC4[3];                // 0xAC4
    u8 padAD0[4];
    u8 mAD4[0x6C];                  // 0xAD4
};
// @decl-end

CMiniGame5Res *CreateMiniGame5Res() {
    return new CMiniGame5Res;
}

// Key method: #pragma interface (top) keeps this unit from emitting the vtables (asm data).
CMiniGame5Res::~CMiniGame5Res() {
    CMiniGame5Res::Release();
    D_002A5538->SetUnkDC(0);
}

INCLUDE_RODATA("asm/nonmatchings/CMiniGame5Res", D_002E15C8);
int CMiniGame5Res::Load(const char *dir) {
    u8 file[0x100];
    char key[0x100];
    char line[0x400];
    char tok[0x100];
    char *text;
    s32 i;
    int opened;
    int bufInit;
    int ok = 0;
    func_002491A8(file, 0, "FILE", "minigcomdir", "data/minig/common.xap");
    opened = 0;
    bufInit = 0;
    text = 0;
    if (func_001B8760(&m34, file)) {
        func_002491A8(file, dir, "FILE", "minig5dir", "data/minig/minig5.xap");
        if (func_00249248(file)) {
            opened = 1;
            if (func_001B8760(&m58, 0)) {
                text = func_0024A4C0("quest.txt");
                if (text) {
                    bufInit = 1;
                    i = 0;
                    func_00248C30(&m_buf);
                    CMiniGame5QuestList *list = m_list;
                    for (; i < 3; i++, list++) {
                        sprintf(key, D_002E1698, i);
                        const char *p = func_0024AF10(text, key);
                        if (*p) {
                            list->m_num = func_0024B040(p, 1);
                            list->m_items = (CMiniGame5Quest *)m_buf.Func248CC8(list->m_num * sizeof(CMiniGame5Quest), 1, 1);
                            for (s32 j = 0; j < list->m_num; j++) {
                                CMiniGame5Quest *q = &list->m_items[j];
                                p = func_0024AFE8(p, line, 1, 0x100);
                                const char *s = func_0024A570(line, tok, D_002E16A0, D_002E16A8);
                                q->m_rank = tok[0] - 'A';
                                if ((u32)q->m_rank >= 3) {
                                    Func235DE0(D_002E16B0, tok);
                                    q->m_rank = q->m_rank < 0 ? 0 : (q->m_rank < 3 ? q->m_rank : 2);
                                }
                                s = func_0024A570(s, func_00248DA8(&m_buf), D_002E16A0, D_002E16A8);
                                q->m4 = func_00248DC0(&m_buf);
                                s = func_0024A570(s, func_00248DA8(&m_buf), D_002E16A0, D_002E16A8);
                                q->m8 = func_00248DC0(&m_buf);
                                s = func_0024A570(s, func_00248DA8(&m_buf), D_002E16A0, D_002E16A8);
                                q->mC = func_00248DC0(&m_buf);
                                func_0024A710(s, &q->m10, 0, D_002E16A0, D_002E16A8);
                            }
                        }
                    }
                    D_002A5A08 = this;
                    ok = 1;
                }
            }
        }
    }
    if (bufInit) func_00248C70(&m_buf);
    if (text) D_002B91B0(text);
    if (opened) func_00249348();
    return ok;
}
INCLUDE_RODATA("asm/nonmatchings/CMiniGame5Res", D_002E1698);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame5Res", D_002E16A0);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame5Res", D_002E16A8);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame5Res", D_002E16B0);

void CMiniGame5Res::Release() {
    D_002A5A08 = 0;
    m34.Sub()->Release();
    m58.Sub()->Release();
    m_buf.Func248E00();
    memset(m_list, 0, sizeof(m_list));
}

void CreateMiniGame5(CTaskList24F5C0 *list) {
    CMiniGame5 *p = new CMiniGame5;
    list->Func24F5C0(p, 0);
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame5Res", __10CMiniGame5);

extern "C" void func_0025C2C0(void *p, s32 flags);
extern "C" void MG5LayoutDtor(void *p, s32 flags) asm("_$_10CLayoutObj");
// m820's own (inline) destructor: its sound member at +0x170, then its layout.
inline void MG5DestroyLayout2(u8 *p) {
    func_0025C2C0(p + 0x170, 2);
    MG5LayoutDtor(p, 2);
}

// Key method: the member objects are raw storage here, destroyed explicitly (last declared first).
CMiniGame5::~CMiniGame5() {
    func_0025C2C0(mAD4, 2);
    MG5DestroyLayout2(m820);
    MG5LayoutDtor(&m_lay[4], 2);
    MG5LayoutDtor(&m_lay[3], 2);
    MG5LayoutDtor(&m_lay[2], 2);
    MG5LayoutDtor(&m_lay[1], 2);
    MG5LayoutDtor(&m_lay[0], 2);
}

void CMiniGame5::SetX(f32 x) {
    m_lay[0].SetRect(x, x, 320.0f, 224.0f);
    m_lay[1].SetRect(x, x, 320.0f, 224.0f);
    m_lay[2].SetRect(x, x, 320.0f, 224.0f);
    m_lay[3].SetRect(x, x, 320.0f, 224.0f);
    m_lay[4].SetRect(x, x, 320.0f, 224.0f);
}

void CMiniGame5::InitQuests() {
    s32 base = 0x2500;
    for (s32 i = 0; i < 3; i++) {
        m_sel[i] = Func1DF2F0(i, base, &m_unkAC4[i]);
        base += D_002A5A08->m_list[i].m_num;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame5Res", Func1DF2F0__10CMiniGame5iiPi);

void CMiniGame5::SetCursor(s32 set) {
    char buf[0x100];
    sprintf(buf, "cur%d", m_curPos);
    CLayoutEntry *e = m_lay[3].FindEntry(buf);
    if (e) {
        if (set) {
            D_002A5538->SetUnk0And20(e->m20, e->m24);
        } else {
            D_002A5538->Move1B6488(e->m20, e->m24);
        }
    }
}
INCLUDE_RODATA("asm/nonmatchings/CMiniGame5Res", D_002E1768);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame5Res", D_002E1788);

CMiniGame5Quest *CMiniGame5::GetQuest() {
    return &D_002A5A08->m_list[m_cur].m_items[m_sel[m_cur]];
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame5Res", func_001DF730);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame5Res", D_002E17D8);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame5Res", D_002E17E0);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame5Res", D_002E17E8);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame5Res", D_002E1800);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame5Res", D_002E1808);

INCLUDE_ASM("asm/nonmatchings/CMiniGame5Res", func_001E2B38);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame5Res", D_002E1890);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame5Res", D_002E18A0);
