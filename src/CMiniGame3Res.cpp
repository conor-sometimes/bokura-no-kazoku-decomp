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
struct CMiniGame3Ent {
    s32 m0;                   // 0x0
    s32 m4;                   // 0x4
    u8 pad8[0x8];
    f32 m10;                  // 0x10
    f32 m14;                  // 0x14
    f32 m18;                  // 0x18
    f32 m1C;                  // 0x1C
    s32 m20;                  // 0x20
    u8 pad24[0x4];
    f32 m28;                  // 0x28
    s32 m2C;                  // 0x2C
};
extern void *D_002A5A00;
// Animation part of an entry (CMiniGame3Ent from 0x20).
struct CMiniGame3Anim {
    s32 m_start;              // 0x0
    s32 m4;                   // 0x4
    f32 m_t;                  // 0x8
    s32 m_kind;               // 0xC
    void Set(s32 start, s32 kind) { m_start = start; m_kind = kind; }
};
// Resource holder for mini-game 3 (vtable _vt$13CMiniGame3Res, vptr at 0xC).
class CMiniGame3Res : public CListTag {
public:
    CMiniGame3Res() {}
    virtual ~CMiniGame3Res();
    virtual int Load();
    virtual void Release();

    CLayoutRes m10;           // 0x10
    CLayoutRes m34;           // 0x34
};
void *operator new(unsigned int n);
struct CRand {
    CRand() { m_seed = 1; }
    u32 m_seed;
    u32 Next() {
        m_seed = m_seed * 0x19660D + 1;
        return (m_seed >> 12) & 0xFFFF;
    }
    u32 Rand(u32 n) { return ((Next() << 16) | Next()) % n; }
};
struct CMiniGame3Text {
    u8 pad0[0x40];
    void *m_text;             // 0x40
};
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
// The mini-game 3 task (vtable _vt$10CMiniGame3, a CProcess with its vptr at 4); 0xF70 bytes.
class CMiniGame3 : public CProcess {
public:
    CMiniGame3(int a, int b) throw();
    virtual ~CMiniGame3();
    virtual void Update();
    virtual void Draw();
    // &m_ent[i].m20 and &m_ent[i], computed as this + (i * 0x30 + offset) as retail does.
    CMiniGame3Anim *Anim(u32 i) {
        u32 o = i * 0x30 + 0xC50;
        return (CMiniGame3Anim *)((u8 *)this + o);
    }
    CMiniGame3Ent *Ent(u32 i) {
        u32 o = i * 0x30 + 0xC30;
        return (CMiniGame3Ent *)((u8 *)this + o);
    }
    int LoadLevel();
    int LoadConf();
    void Set3(u32 i);
    void Set5(u32 i);
    void Set2(u32 i);
    void Set1(u32 i);
    void Set4(u32 i, f32 t);
    void Layout(f32 t);
    void Shuffle();

    u8 pad18[0x2C - 0x18];
    s32 m2C;                  // 0x2C
    s32 m30;                  // 0x30
    CStateMachine m_sm;       // 0x34
    u8 pad7C[0x4];
    CMgLayout m_lay0;         // 0x80
    CMgLayout m_lay1;         // 0x1F0
    CMgLayout m_lay2;         // 0x360
    CMgLayout m_lay3;         // 0x4D0
    CMgLayout m_lay4;         // 0x640
    CMgLayout m_lay5;         // 0x7B0
    CMgLayout2 m_lay6;        // 0x920
    CRand m_rand;             // 0xB30
    CMgSnd m_snd;             // 0xB34
    s32 mBA8[16];             // 0xBA8: CONF values, mBA8[0] the animation length
    u8 padBE8[0xBF0 - 0xBE8];
    f32 mBF0, mBF4, mBF8, mBFC; // 0xBF0
    u8 padC00[0x30];
    CMiniGame3Ent m_ent[16];  // 0xC30
    s32 mF30[3];              // 0xF30
    s32 mF3C[3];              // 0xF3C
    s32 mF48;                 // 0xF48
    f32 mF4C;                 // 0xF4C
    s32 mF50, mF54, mF58, mF5C, mF60, mF64, mF68; // 0xF50
    u8 padF6C[0x4];
};
void CreateMiniGame3Res(CResMgr24F *mgr, int a, int b);

const char *Func24AF10(void *res, const char *key);
const char *Func24AFE8(const char *s, char *buf, int a, int n);
extern "C" const char *func_0024A710(const char *s, void *out, int a, const char *b, const char *c);
extern "C" long atol(const char *s);
extern char D_002E1258[], D_002E1260[], D_002E1268[];
int Func235DE0(const char *fmt, ...);

CMiniGame3Res *NewCMiniGame3Res();

void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
extern "C" int func_001B8760(void *p, const char *path);
// @decl-end

CMiniGame3Res *NewCMiniGame3Res() {
    return new CMiniGame3Res;
}

INCLUDE_RODATA("asm/nonmatchings/CMiniGame3Res", D_002E1190);
int CMiniGame3Res::Load() {
    char buf[0x100];
    Release();
    Func2491A8(buf, 0, (s32)"FILE", (s32)"minigcomdir", (s32)"data/minig/common.xap");
    if (func_001B8760(&m10, buf)) {
        Func2491A8(buf, 0, (s32)"FILE", (s32)"minig3dir", (s32)"data/minig/minig3.xap");
        if (func_001B8760(&m34, buf)) D_002A5A00 = this;
    }
    return D_002A5A00 != 0;
}

void CMiniGame3Res::Release() {
    D_002A5A00 = 0;
    m34.Func1B9B30();
    m10.Func1B9B30();
}

void CreateMiniGame3Res(CResMgr24F *mgr, int a, int b) {
    CMiniGame3 *p = new CMiniGame3(a, b);
    mgr->Func24F5C0(p, 0);
}

CMiniGame3::CMiniGame3(int a, int b) {
    if (!D_002A5A00) Func235DE0("*** not found MINI-GAME resource\n");
    m_rand.m_seed = Func251B88();
    m2C = a;
    m30 = b;
    mF68 = 0;
    mF30[0] = 0;
    mF30[1] = 0;
    mF3C[1] = 0;
    mF3C[2] = 0;
    mF4C = 0;
    mF50 = 0;
    mF54 = 0;
    mF58 = 0;
    mF5C = 0;
    mF48 = -1;
    mF60 = 0;
    mF64 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001C9E90);

int CMiniGame3::LoadLevel() {
    char buf[0x100];
    s32 lv;
    const char *s = Func24AF10(((CMiniGame3Text *)D_002A5A00)->m_text, "LEVEL");
    if (!*s) return 0;
    for (;;) {
        const char *p;
        s = Func24AFE8(s, buf, 1, 0x100);
        if (!*s && !buf[0]) break;
        p = func_0024A710(buf, &lv, 0, D_002E1258, D_002E1260);
        p = func_0024A710(p, mF30, 0, D_002E1258, D_002E1260);
        func_0024A710(p, mF3C, 0, D_002E1258, D_002E1260);
        if (lv == m30) return 1;
    }
    Func235DE0(D_002E1268);
    return 0;
}
INCLUDE_RODATA("asm/nonmatchings/CMiniGame3Res", D_002E1258);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame3Res", D_002E1260);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame3Res", D_002E1268);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA090);

int CMiniGame3::LoadConf() {
    char buf[0x100];
    s32 *p;
    s32 i;
    const char *s = Func24AF10(((CMiniGame3Text *)D_002A5A00)->m_text, "CONF");
    if (!*s) return 0;
    p = mBA8;
    for (i = 0; i < 16; i++) {
        s = Func24AFE8(s, buf, 1, 0x100);
        if (!*s || !buf[0]) break;
        *p++ = atol(buf);
    }
    return 1;
}

void CMiniGame3::Set3(u32 i) {
    if (i < 16) {
        Anim(i)->Set(mBA8[0], 3);
        m_ent[i].m0 = 9;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA3B8);

void CMiniGame3::Set5(u32 i) {
    if (i < 16) {
        Anim(i)->Set(mBA8[0], 5);
        m_ent[i].m0 = 9;
    }
}

void CMiniGame3::Set4(u32 i, f32 t) {
    if (i < 16) {
        CMiniGame3Anim *a = Anim(i);
        CMiniGame3Ent *e;
        a->m_start = mBA8[0];
        a->m_kind = 4;
        e = Ent(i);
        e->m0 = e->m4;
        a->m_t = (t - m_ent[i].m18) / (f32)mBA8[0];
    }
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA4C8);

#if 0 // DIFF 2 (g1): retail loads 16 (the inline Rand's divisor) after the LCG constant's ori, ours before
void CMiniGame3::Shuffle() {
    s32 i, v = 0;
    for (i = 0; i < 16; i += 2) {
        m_ent[i].m4 = v + 1;
        m_ent[i + 1].m4 = v + 1;
        v++;
    }
    for (s32 j = 0; j < 16; j++) {
        CMiniGame3Ent *e = Ent(m_rand.Rand(16));
        CMiniGame3Ent *f = &m_ent[j];
        s32 t = e->m4;
        e->m4 = f->m4;
        f->m4 = t;
    }
}
#endif
INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA528);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA5E8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA878);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001CA900);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame3Res", D_002E1318);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame3Res", D_002E1338);

INCLUDE_ASM("asm/nonmatchings/CMiniGame3Res", func_001D4618);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame3Res", D_002E1388);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame3Res", D_002E1398);
