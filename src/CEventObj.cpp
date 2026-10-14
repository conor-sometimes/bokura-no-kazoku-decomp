#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
typedef __builtin_va_list va_list;
#define va_start(ap, last) __builtin_stdarg_start(ap, last)
#define va_end(ap) __builtin_va_end(ap)
//@sym strcmp 0x28B190
#include "libc.h"
//@sym strncmp 0x289D68
//@sym strncpy 0x24B600
extern "C" int strncmp(const char *a, const char *b, unsigned int n);
extern "C" char *strncpy(char *dst, const char *src, unsigned int n);
extern "C" void func_00137DC0();
extern "C" void func_0013D908();
class CDkList {
public:
    int Func296570();
};
class CDkArray {
public:
    void Func297F78(int n);
    int Func297F98();
    char *Func297FA0(int i);
    u8 pad[0x1C];
};
class CSceneSet {
public:
    void Func12CB00(int v);
    int Func12CF40(int i);
    u8 pad0[0x18];
    CDkList m_list;           // 0x18
};
class CMovieObj {
public:
    int Func13EDC8();
};
class CUnk237E90 {
public:
    void Func237E90(int v);
};
class CEventObjUnk {
public:
    u8 pad0[0x1B0];
    CUnk237E90 m_1B0;         // 0x1B0
};
class CResLoader250540 {
public:
    int Func250540(int v);

    u8 pad0[0x13C];
};
// The resource managers (CCharaResMgr, CMapResMgr, CEnvResMgr) as seen through their
// interfaces: vptr after CResCache's 0x13C bytes. Slot 5 exists in CEnvResMgr only.
class IResMgr : public CResLoader250540 {
public:
    virtual ~IResMgr();
    virtual void V1();
    virtual s32 *FindRes(s32 id);
    virtual void Init(s32 size, s32 n);
    virtual void CallFunc250368();
    virtual void V5();
};
extern IResMgr *D_002A0BE8;
extern IResMgr *D_002A0BE4;
extern IResMgr *D_002A0BEC;
extern "C" void func_00128E78(void *snd, s32 v);
extern "C" void func_00128F10(void *snd, s32 v);
// Script callbacks: an object and a pointer to member.
class CEvHost {
public:
    virtual void V0();
};
// A task-like object (vptr at 0x4) asked whether time skipping is on (slot 17).
class CEvClock {
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
    virtual int V17();

    s32 m_unk0;               // 0x0
};
extern CEvClock *D_002A3568;
int Func235DE0(const char *fmt, ...);
typedef int (CEvHost::*CEvCallback3)(int a, int b, int c);
typedef void (CEvHost::*CEvCallback2)(int a, int b);
extern char D_002D5968[];
extern char D_002D5A78[];
struct CEventItem {
    u8 pad0[0x24];
    s32 m24;
    s32 m28;
    u8 pad2C[0x1C];
    char m_name[0x20];        // 0x48
};
class CEventObj {
public:
    void ClearScene();
    void Func132B78();
    void Func132D30();
    int SetItem(CEventItem *p);
    int Func132BB8(CEventItem *p);
    void Func1387E8();
    int IsBusy();
    int IsValidIndex(int i);
    int SetScene(int a, CSceneSet *s);
    void Func132EC0();
    void PlayMovie(CEventObjUnk *p);
    int Dispatch134CB8(u32 id, int x);
    int Func13CA58(u32 id, int x);
    int Func139440(u32 id, int x);
    int Func13D6D8(u32 id, int x);
    int Run134C40(int x);
    int Func134B80();
    void Log1353F0(const char *fmt, ...);
    void Log135458(const char *fmt, ...);
    void Func1352C0(int level, const char *fmt, va_list ap);
    int Func138828(int i);
    int IsSpecial(int id);
    int Call132F40(int a, int b, int c);
    void Call1355E0(int a, int b);
    void Release1354C0();
    int SkipTime(int lo, int hi, int v);

    u8 pad0[0x4];
    s32 m4;                   // 0x4
    CSceneSet *m8;            // 0x8
    u8 padC[0xF9B4 - 0xC];
    CDkArray m_F9B4;          // 0xF9B4
    CMovieObj m_F9D0;         // 0xF9D0
    u8 padF9D1[0xFBDC - 0xF9D1];
    char m_FBDC[0x20];        // 0xFBDC
    CEventObjUnk *m_FBFC;     // 0xFBFC
    u8 padFC00[0xFC7C - 0xFC00];
    s32 m_FC7C;               // 0xFC7C
    u8 padFC80[0xFC98 - 0xFC80];
    s32 m_FC98;               // 0xFC98
    u8 padFC9C[0xFCB4 - 0xFC9C];
    s32 m_FCB4;               // 0xFCB4
    u8 padFCB8[0xFD00 - 0xFCB8];
    s32 m_FD00;               // 0xFD00
    u8 padFD04[0x14];
    CEvHost *m_FD18;          // 0xFD18
    CEvCallback3 m_FD1C;      // 0xFD1C
    u8 padFD24[0x24];
    CEvHost *m_FD48;          // 0xFD48
    CEvCallback2 m_FD4C;      // 0xFD4C
};
int IsNotDefault(const char *s);
int CheckItemTag(CEventItem *p, const char *s);
int AnyResLoading();
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00132270);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_001327F8);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00132998);

int CEventObj::SetItem(CEventItem *p) {
    if (!p) return 0;
    strncpy(m_FBDC, p->m_name, 0x20);
    return Func132BB8(p);
}

void CEventObj::Func132B78() {
    Func132D30();
    m_F9B4.Func297F78(0);
    m_FBDC[0] = 0;
}

INCLUDE_ASM("asm/nonmatchings/CEventObj", Func132BB8__9CEventObjP10CEventItem);

INCLUDE_ASM("asm/nonmatchings/CEventObj", Func132D30__9CEventObj);

int CEventObj::SetScene(int a, CSceneSet *s) {
    ClearScene();
    if (!a || !s) return 0;
    m4 = a;
    m8 = s;
    Func132EC0();
    return 1;
}

void CEventObj::ClearScene() {
    if (m4 != 0 || m8 != 0) {
        m4 = 0;
        m8 = 0;
    }
}

void CEventObj::Func132EC0() {
    if (m8) {
        int i, n = m8->m_list.Func296570();
        m_F9B4.Func297F78(n);
        for (i = 0; i < n; i++) *m_F9B4.Func297FA0(i) = 0;
    }
}

// Call132F40 (0x132F40): `if (m_FD18 && m_FD1C) return (m_FD18->*m_FD1C)(a, b, c); return 1;`
// matches except that retail leaves the virtual path's `b` delay slot empty (plus an alignment
// nop) where ours fills it with the dsra32.
INCLUDE_ASM("asm/nonmatchings/CEventObj", Call132F40__9CEventObjiii);

INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5670);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5678);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5680);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5688);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5690);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5698);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D56A0);
INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00133000);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D56B0);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D56C8);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00133140);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_001333D8);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00133660);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_001338E8);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00133B90);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00134100);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00134438);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00134768);

int CEventObj::IsSpecial(int id) {
    switch (id) {
    case 6: case 8: case 10: case 14: case 22: case 93:
        return 1;
    }
    return 0;
}

int CEventObj::IsBusy() {
    if (m_FCB4 > 0 || m_FC98 > 0 || m_FC7C > 0) return 1;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CEventObj", Func134B80__9CEventObj);

int CEventObj::Run134C40(int x) {
    if (m_FD00 < 0) {
        if (!Func134B80()) return 0;
    }
    while (!Dispatch134CB8(m_FD00, x)) {
        if (!Func134B80()) return 0;
    }
    return 1;
}

int CEventObj::Dispatch134CB8(u32 id, int x) {
    int r = 0;
    if (id < 12) r = Func13CA58(id, x);
    else if (id - 12 < 12) r = Func139440(id, x);
    else if (id - 0x5C < 7) r = Func13D6D8(id, x);
    return r;
}

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00134D28);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00135138);

INCLUDE_ASM("asm/nonmatchings/CEventObj", Func1352C0__9CEventObjiPCcPv);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D56F0);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D56F8);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5700);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5708);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5710);

void CEventObj::Log1353F0(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    Func1352C0(1, fmt, ap);
    va_end(ap);
}

void CEventObj::Log135458(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    Func1352C0(0, fmt, ap);
    va_end(ap);
}

void CEventObj::Release1354C0() {
    func_00128E78((void *)m4, 0);
    func_00128F10((void *)m4, 0);
    D_002A0BE8->CallFunc250368();
    D_002A0BEC->V5();
    D_002A0BE4->CallFunc250368();
}

void InitResMgrs135558() {
    D_002A0BE8->Init(-1, -1);
    D_002A0BEC->CallFunc250368();
    D_002A0BE4->Init(-1, -1);
}

// Call1355E0 (0x1355E0): `if (m_FD48 && m_FD4C) (m_FD48->*m_FD4C)(a, b);`, same delay-slot
// difference as Call132F40.
INCLUDE_ASM("asm/nonmatchings/CEventObj", Call1355E0__9CEventObjii);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00135690);

int AnyResLoading() {
    return (D_002A0BE8->Func250540(0) != 0) | (D_002A0BE4->Func250540(0) != 0);
}

int CEventObj::SkipTime(int lo, int hi, int v) {
    if (D_002A3568->V17()) {
        int old = v;
        if (!(v < lo)) {
            v = lo + (v - lo) / 2;
            if (!(v < hi)) {
                v = hi;
            }
        }
        Func235DE0("skip time : %d->%d (%d,%d)\n", old, v, lo, hi);
    }
    return v;
}

INCLUDE_ASM("asm/nonmatchings/CEventObj", Func135A28__15CEventObj135A28);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00135BE0);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00135C40);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5748);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5750);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5760);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5768);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5778);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5788);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5790);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5798);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D57A0);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D57A8);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D57B0);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D57C0);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D57D0);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D57E0);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D57E8);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D57F0);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5808);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5818);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5820);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D5858);
INCLUDE_RODATA("asm/nonmatchings/CEventObj", D_002D58A0);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_001362C0);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00137DC0() {
}

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00137DC8);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_001385E8);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00138610);

void CEventObj::Func1387E8() {
    func_0013D908();
    if (m8) m8->Func12CB00(0);
}

int CEventObj::Func138828(int i) {
    if (i >= 0) {
        func_00137DC0();
        if (m8) return m8->Func12CF40(i);
    } else {
        if (m8) {
            int j;
            for (j = 0; j < m8->m_list.Func296570(); j++) Func138828(j);
        }
    }
}

int CEventObj::IsValidIndex(int i) {
    if (i >= 0 && i <= m_F9B4.Func297F98() - 1) return 1;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00138908);

int IsNotDefault(const char *s) {
    int r = 0;
    if (s && *s) r = strcmp(s, D_002D5968) != 0;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00138BB8);

INCLUDE_ASM("asm/nonmatchings/CEventObj", Func139440__9CEventObjUii);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_0013A100);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_0013A2C8);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_0013A508);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_0013A790);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_0013AA80);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_0013AC58);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_0013AF08);

int CheckItemTag(CEventItem *p, const char *s) {
    if (!p) return 0;
    if (strncmp(s, D_002D5A78, 4) == 0) return p->m28;
    return p->m24;
}

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_0013B068);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_0013C0F8);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_0013C120);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_0013C2D0);

INCLUDE_ASM("asm/nonmatchings/CEventObj", Func13CA58__9CEventObjUii);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_0013D518);

INCLUDE_ASM("asm/nonmatchings/CEventObj", Func13D6D8__9CEventObjUii);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_0013D908() {
}
