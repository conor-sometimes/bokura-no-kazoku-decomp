#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CList.h"
#include "CProcess.h"
class CLayoutRes {
public:
    CLayoutRes();
    virtual ~CLayoutRes();
    void Func1B9B30();
    u8 pad[0x20];
    // vptr 0x20
};
class CResMgr24F {
public:
    void Func24F5C0(void *res, int v);
};
void *Func24F2E8(int size);
extern void *D_002A59FC;
extern void (*D_002B91B0)(void *p);
// Resource holder for mini-game 2 (vtable _vt$13CMiniGame2Res; a CListTag, vptr 0xC).
class CMiniGame2Res : public CListTag {
public:
    CMiniGame2Res() {}
    virtual ~CMiniGame2Res();
    virtual int Load();
    virtual void Release();

    CLayoutRes m10;           // 0x10
    CLayoutRes m34;           // 0x34
    void *m58;                // 0x58
    s32 m5C;                  // 0x5C
};
void *operator new(unsigned int n);
struct CMiniGame2Text {
    u8 pad0[0x40];
    void *m_text;             // 0x40
};
struct CRand {
    CRand() { m_seed = 1; }
    u32 m_seed;
    u32 Next() {
        m_seed = m_seed * 0x19660D + 1;
        return (m_seed >> 12) & 0xFFFF;
    }
    u32 Rand(u32 n) { return ((Next() << 16) | Next()) % n; }
};
struct CMiniGame2Color { s32 r, g, b, a; };
struct CMiniGame2Pos { f32 x, y; u8 pad[8]; };
class CMenuMgrSub1B6418 {
public:
    void SetUnkDC(u32 v);
};
extern CMenuMgrSub1B6418 *D_002A5538;
// Member classes (layout objects, sound handles; library / CLayoutObj code): their destructors
// are called explicitly.
extern "C" void func_001B9D70(void *p, s32 flags);
extern "C" void func_0025C2C0(void *p, s32 flags);
// Member objects of the task (layout objects and a sound handle; library / CLayoutObj code).
extern "C" void func_001B9D40(void *p);
extern "C" void *func_001BD188(void *p);
extern "C" void func_0025C230(void *p);
struct CMgLayout {
    CMgLayout() { func_001B9D40(this); }
    u8 pad[0x170];
};
struct CMgLayout2 {
    CMgLayout2() { func_001BD188(this); }
    u8 pad[0x210];
};
struct CMgSnd {
    CMgSnd() { func_0025C230(this); }
    u8 pad[0x74];
};
u32 Func251B88();
// The mini-game 2 task (vtable _vt$10CMiniGame2, key method ~CMiniGame2); 0xE50 bytes.
class CMiniGame2 : public CProcess {
public:
    CMiniGame2(int a, int b) throw();
    virtual ~CMiniGame2();
    virtual void Update();
    virtual void Draw();
    int Pick();
    int LoadCursor();
    int LoadColor();
    int LoadLevel();
    int LoadConf();

    u8 pad18[0x2C - 0x18];
    s32 m2C;                  // 0x2C
    s32 m30;                  // 0x30
    CStateMachine m_sm;       // 0x34
    void *m7C;                // 0x7C: question data
    s32 m80;                  // 0x80
    u8 pad84[0xC];
    CMgLayout m_layout0;      // 0x90
    CMgLayout m_layout1;      // 0x200
    CMgLayout m_layout2;      // 0x370
    CMgLayout m_layout3;      // 0x4E0
    CMgLayout m_layout4;      // 0x650
    CMgLayout m_layout5;      // 0x7C0
    CMgLayout m_layout6;      // 0x930
    CMgLayout2 m_layout7;     // 0xAA0
    CRand m_rand;             // 0xCB0
    CMgSnd m_snd;             // 0xCB4
    s32 mD28[7];              // 0xD28: CONF values
    s32 mD44;                 // 0xD44
    s32 mD48[3];              // 0xD48
    s32 mD54, mD58, mD5C, mD60, mD64, mD68; // 0xD54
    s32 mD6C;                 // 0xD6C
    s32 mD70;                 // 0xD70
    s32 mD74;                 // 0xD74
    s32 mD78;                 // 0xD78
    s32 m_q[10];              // 0xD7C
    s32 mDA4;                 // 0xDA4
    s32 mDA8[10];             // 0xDA8
    CMiniGame2Color m_color[4]; // 0xDD0
    CMiniGame2Pos m_pos[3];   // 0xE10
    s32 mE40;                 // 0xE40
    u8 padE44[0xC];
};
void CreateMiniGame2Res(CResMgr24F *mgr, int a, int b);

const char *Func24AF10(void *res, const char *key);
const char *Func24AFE8(const char *s, char *buf, int a, int n);
extern "C" const char *func_0024A710(const char *s, void *out, int a, const char *b, const char *c);
extern "C" const char *func_0024A778(const char *s, void *out, f32 def, const char *b, const char *c);
extern "C" long atol(const char *s);
extern char D_002E0FC0[], D_002E0FC8[];
int Func235DE0(const char *fmt, ...);

CMiniGame2Res *NewCMiniGame2Res();

void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
extern "C" int func_001B8760(void *p, const char *path);
s32 Func249248(void *buf);
void Func249348();
extern "C" int func_001C4260(CMiniGame2Res *r, const char *name);

struct CRandR {
    u32 m_seed;
    u32 Next() {
        m_seed = m_seed * 0x19660D + 1;
        return (m_seed >> 12) & 0xFFFF;
    }
    u32 Rand(u32 n) { return ((Next() << 16) | Next()) % n; }
    s32 Range(s32 lo, s32 hi) {
        if (hi < lo) hi = lo;
        if (hi == lo) return 0;
        return lo + Rand(hi - lo + 1);
    }
};
// @decl-end

CMiniGame2Res *NewCMiniGame2Res() {
    return new CMiniGame2Res;
}

INCLUDE_RODATA("asm/nonmatchings/CMiniGame2Res", D_002E0F00);
int CMiniGame2Res::Load() {
    char buf[0x100];
    int opened = 0;
    Release();
    Func2491A8(buf, 0, (s32)"FILE", (s32)"minigcomdir", (s32)"data/minig/common.xap");
    if (func_001B8760(&m10, buf)) {
        Func2491A8(buf, 0, (s32)"FILE", (s32)"minig2dir", (s32)"data/minig/minig2.xap");
        if (Func249248(buf)) {
            opened = 1;
            if (func_001B8760(&m34, 0) && func_001C4260(this, "qdata.txt")) D_002A59FC = this;
        }
    }
    if (opened) Func249348();
    return D_002A59FC != 0;
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C4260);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame2Res", D_002E0FC0);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame2Res", D_002E0FC8);

void CMiniGame2Res::Release() {
    D_002A59FC = 0;
    if (m58) {
        D_002B91B0(m58);
        m58 = 0;
        m5C = 0;
    }
    m34.Func1B9B30();
    m10.Func1B9B30();
}

void CreateMiniGame2Res(CResMgr24F *mgr, int a, int b) {
    CMiniGame2 *p = new CMiniGame2(a, b);
    mgr->Func24F5C0(p, 0);
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", __10CMiniGame2ii);

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C4710);

int CMiniGame2::Pick() {
    s32 k = 0;
    s32 r;
    if (mD6C != 1) {
        do {
            k = ((CRandR *)&m_rand)->Range(0, mD6C - 1);
        } while (k == mD74);
        mD74 = k;
    }
    r = k + mD70;
    if (r >= m80) {
        Func235DE0("*** level data and question data not match.\n");
        r = 0;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C48E8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C4A58);

int CMiniGame2::LoadCursor() {
    char buf[0x100];
    s32 i;
    const char *s = Func24AF10(((CMiniGame2Text *)D_002A59FC)->m_text, "CURSOR");
    if (!*s) return 0;
    for (i = 0; i < 3; i++) {
        const char *p;
        s = Func24AFE8(s, buf, 1, 0x100);
        p = func_0024A778(buf, &m_pos[i].x, 0.0f, D_002E0FC0, D_002E0FC8);
        func_0024A778(p, &m_pos[i].y, 0.0f, D_002E0FC0, D_002E0FC8);
    }
    return 1;
}

int CMiniGame2::LoadColor() {
    char buf[0x100];
    s32 i;
    const char *s = Func24AF10(((CMiniGame2Text *)D_002A59FC)->m_text, "COLOR");
    if (!*s) return 0;
    for (i = 0; i < 4; i++) {
        const char *p;
        s = Func24AFE8(s, buf, 1, 0x100);
        p = func_0024A710(buf, &m_color[i].r, 0, D_002E0FC0, D_002E0FC8);
        p = func_0024A710(p, &m_color[i].g, 0, D_002E0FC0, D_002E0FC8);
        func_0024A710(p, &m_color[i].b, 0, D_002E0FC0, D_002E0FC8);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C4CA0);

int CMiniGame2::LoadConf() {
    char buf[0x100];
    s32 *p;
    s32 i;
    const char *s = Func24AF10(((CMiniGame2Text *)D_002A59FC)->m_text, "CONF");
    if (!*s) return 0;
    p = mD28;
    for (i = 0; i < 7; i++) {
        s = Func24AFE8(s, buf, 1, 0x100);
        if (!*s || !buf[0]) break;
        *p++ = atol(buf);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C4E90);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame2Res", D_002E10F0);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame2Res", D_002E1110);

INCLUDE_ASM("asm/nonmatchings/CMiniGame2Res", func_001C95D8);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame2Res", D_002E1170);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame2Res", D_002E1180);
