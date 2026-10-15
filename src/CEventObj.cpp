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
    u8 pad[0x18];
    s32 m18;                  // 0x18
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
    void Func13E888();
    u8 pad0[0x178];
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
#include "CProcess.h"
class CSvmData;
class CSvmWork {
public:
    void Func12E858();
    void Unload12E968();
    int Load12E910(CSvmData *data);
    void CopyFrom(CSvmWork *o);
    u8 pad0[0x47C];
    s32 m47C;                 // 0x47C
    s32 m480;                 // 0x480
    u8 pad484[0x2954 - 0x484];
};
extern "C" void func_0012EF68(CSvmWork *w);
struct CEvWait {
    void Clear() { m18 = 0; m10 = 0; mC = 0; }
    u8 pad0[0xC];
    s32 mC;                   // 0xC
    s32 m10;                  // 0x10
    u8 pad14[0x4];
    s32 m18;                  // 0x18
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

    void Clear132998();
    void Init135138(s32 a, s32 v);
    int Wait133B90(CEvWait *w);
    s32 GetSe13AF08(const char *name);
    void Update135A28();

    s32 m0;                   // 0x0
    s32 m4;                   // 0x4
    CSceneSet *m8;            // 0x8
    CSvmWork m_svm[6];        // 0xC
    u8 padF804[0x48];
    CStateMachine m_sm[5];    // 0xF84C
    CDkArray m_F9B4;          // 0xF9B4
    CMovieObj m_F9D0;         // 0xF9D0
    s32 m_FB48;               // 0xFB48
    s32 m_FB4C[4];            // 0xFB4C
    u8 m_FB5C[0x80];          // 0xFB5C
    char m_FBDC[0x20];        // 0xFBDC
    CEventObjUnk *m_FBFC;     // 0xFBFC
    s32 m_FC00;               // 0xFC00
    s32 m_FC04;               // 0xFC04
    u8 padFC08[0xC];
    s32 m_FC14;               // 0xFC14
    s32 m_FC18;               // 0xFC18
    s32 m_FC1C;               // 0xFC1C
    s32 m_FC20;               // 0xFC20
    s32 m_FC24;               // 0xFC24
    u8 padFC28[0x20];
    s32 m_FC48;               // 0xFC48
    s32 m_FC4C;               // 0xFC4C
    u8 padFC50[0x4];
    s32 m_FC54;               // 0xFC54
    s32 m_FC58;               // 0xFC58
    u8 padFC5C[0x4];
    s32 m_FC60;               // 0xFC60
    CEvWait m_FC64;           // 0xFC64
    CEvWait m_FC80;           // 0xFC80
    CEvWait m_FC9C;           // 0xFC9C
    CStateMachine m_FCB8;     // 0xFCB8
    s32 m_FD00;               // 0xFD00
    s32 m_FD04;               // 0xFD04
    u8 m_FD08[0x10];          // 0xFD08
    CEvHost *m_FD18;          // 0xFD18
    CEvCallback3 m_FD1C;      // 0xFD1C
    u8 padFD24[0x24];
    CEvHost *m_FD48;          // 0xFD48
    CEvCallback2 m_FD4C;      // 0xFD4C
    char m_log[9][0x20];      // 0xFD54
    s32 m_logLevel[9];        // 0xFE74
    s32 m_logTime[9];         // 0xFE98
    s32 m_logNum;             // 0xFEBC
    s32 m_logPos;             // 0xFEC0
    u8 padFEC4[0x8];
};
int IsNotDefault(const char *s);
int CheckItemTag(CEventItem *p, const char *s);
int AnyResLoading();
class CResCache {
public:
    void Func250840(void *p);
};
extern "C" int vsprintf(char *buf, const char *fmt, va_list ap);
extern char D_002D56E0[], D_002D56E8[];
inline void SmReset(CStateMachine *s) { s->m_state = -1; s->m_depth = 0; s->m_flags = 0; }
class CSndDrvEv {
public:
    virtual void Vf0();
    virtual void Vf1();
    virtual void Vf2();
    virtual void Vf3();
    virtual void Vf4();
    virtual void Vf5();
    virtual void Vf6();
    virtual void Vf7();
    virtual void Vf8();
    virtual void Vf9();
    virtual void Vf10();
    virtual void Vf11();
    virtual void Vf12();
    virtual void Vf13();
    virtual void Vf14();
    virtual void Vf15();
    virtual void Vf16();
    virtual void Vf17();
    virtual void Vf18();
    virtual s32 Find19(s32 kind);
    virtual void Vf20();
    virtual void Vf21();
    virtual void Vf22();
    virtual void Vf23();
    virtual void Vf24();
    virtual void Vf25();
    virtual void Vf26();
    virtual void Vf27();
    virtual void Vf28();
    virtual void Vf29();
    virtual void Vf30();
    virtual void Vf31();
    virtual void Vf32();
    virtual void Vf33();
    virtual void Vf34();
    virtual void Vf35();
    virtual void Vf36();
    virtual void Vf37();
    virtual void Vf38();
    virtual s32 *Find39(const char *name);
};
extern CSndDrvEv *D_002BA248;
extern "C" s32 func_0020E698(s32 h, char *a, char *b);
extern char D_002D5A80[], D_002D5A90[];
#include "CList.h"
inline s32 ListCount(CListTag *head) {
    s32 n = 0;
    for (CListTag *p = head->m_next; (p = p->m_isHead ? 0 : p) != 0; p = p->m_next) n++;
    return n;
}
inline s32 ListCount2(CListTag *head) {
    s32 n = 0;
    CListTag *p = head->m_next;
    while ((p = p->m_isHead ? 0 : p) != 0) {
        p = p->m_next;
        n++;
    }
    return n;
}
inline s32 ListCount3(u8 *mgr) {
    s32 n = 0;
    CListTag *p = ((CListTag *)(mgr + 0x1C))->m_next;
    while ((p = p->m_isHead ? 0 : p) != 0) {
        p = p->m_next;
        n++;
    }
    return n;
}
class CTaskMgr390 {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual s32 V8();
    s32 m_unk0;               // 0x0
};
extern CTaskMgr390 *D_0029F390;

//@sym Update135A28__9CEventObj 0x135A28

//@sym Wait133B90__9CEventObjP7CEvWait 0x133B90
//@sym Clear132998__9CEventObj 0x132998
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_00132270);

INCLUDE_ASM("asm/nonmatchings/CEventObj", func_001327F8);

void CEventObj::Clear132998() {
    m_FB48 = 0;
    m_FC00 = 0;
    m_FC64.Clear();
    m_FC80.Clear();
    m_FC9C.Clear();
    SmReset(&m_FCB8);
    m_FD00 = -1;
    m_FD04 = 0;
    memset(m_FB4C, 0, sizeof(m_FB4C));
    memset(m_FB5C, 0, sizeof(m_FB5C));
    memset(m_FD08, 0, sizeof(m_FD08));
    m_logPos = 0;
    m_FC58 = 0;
    m_logNum = 0;
    m_FC14 = 0;
    m_FC18 = 0;
    m_FC1C = 1;
    m_FC60 = 0;
    m_FC20 = 0;
    m_FC48 = 0;
    m_FC4C = 0;
    m_FC54 = 0;
    m_FC24 = 1;
}

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

void CEventObj::Func132D30() {
    if (!m0) return;
    for (s32 i = 0; i < m_F9B4.Func297F98(); i++) {
        if (*m_F9B4.Func297FA0(i)) ((CResCache *)D_002A0BE4)->Func250840(m_F9B4.Func297FA0(i));
    }
    m_F9B4.Func297F78(0);
    m_F9D0.Func13E888();
    m_svm[1].Unload12E968();
    m_svm[2].Unload12E968();
    m_svm[3].Unload12E968();
    m_svm[4].Unload12E968();
    m_svm[5].Unload12E968();
    m_svm[0].Unload12E968();
    Clear132998();
    m0 = 0;
}

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

int CEventObj::Call132F40(int a, int b, int c) {
    if (m_FD18 && m_FD1C) return (m_FD18->*m_FD1C)(a, b, c);
    return 1;
}

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

INCLUDE_ASM("asm/nonmatchings/CEventObj", Wait133B90__9CEventObjP7CEvWait);

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
    if (m_FC9C.m18 > 0 || m_FC80.m18 > 0 || m_FC64.m18 > 0) return 1;
    return 0;
}

int CEventObj::Func134B80() {
    if ((m_FD00 = Wait133B90(&m_FC9C)) < 0 && (m_FD00 = Wait133B90(&m_FC80)) < 0 && (m_FD00 = Wait133B90(&m_FC64)) < 0) return 0;
    CStateMachine *sm = &m_FCB8;
    SmReset(sm);
    sm->m_state = m_FD00;
    return 1;
}

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

void CEventObj::Func1352C0(int level, const char *fmt, va_list ap) {
    char buf[0x400];
    vsprintf(buf, fmt, ap);
    switch (level) {
    case 1:
        Func235DE0("*** %s\n", buf);
        break;
    case 0:
        Func235DE0("(i) %s\n", buf);
        break;
    }
    m_logPos = (m_logPos + 1) % 9;
    m_logNum = m_logNum + 1 < 10 ? m_logNum + 1 : 9;
    strncpy(m_log[m_logPos], buf, 0x20);
    m_logLevel[m_logPos] = level;
    m_logTime[m_logPos] = 300;
}
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

void CEventObj::Call1355E0(int a, int b) {
    if (m_FD48 && m_FD4C) (m_FD48->*m_FD4C)(a, b);
}

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

void CEventObj::Update135A28() {
    if (!m0 || !m4 || !m8) return;
    CSvmWork *w0 = &m_svm[0];
    m_FC60 = D_0029F390->V8();
    func_0012EF68(&m_svm[5]);
    func_0012EF68(&m_svm[4]);
    func_0012EF68(&m_svm[3]);
    func_0012EF68(&m_svm[2]);
    func_0012EF68(&m_svm[1]);
    func_0012EF68(w0);
    for (s32 i = 0; i < m_logNum; i++) {
        if (--m_logTime[(m_logPos - i + 9) % 9] <= 0 && i == m_logNum - 1) m_logNum = i;
    }
    if (m_FB48 && w0->m47C && !m_FC04) m_FC00++;
}

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

s32 CEventObj::GetSe13AF08(const char *name) {
    char buf[0x100];
    if (strncmp(name, D_002D5A78, 4) == 0) {
        strcpy(buf, name + 4);
        s32 h = D_002BA248->Find19(6);
        if (h < 0) {
            Log1353F0(D_002D5A80, buf);
            return 0;
        }
        s32 r = func_0020E698(h, buf, buf);
        if (r >= 0) return r | 0x8060000;
        Log1353F0(D_002D5A90, buf);
        return 0;
    }
    s32 *p = D_002BA248->Find39(name);
    if (!p) {
        Log1353F0(D_002D5A90, name);
        return 0;
    }
    return *p;
}

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
