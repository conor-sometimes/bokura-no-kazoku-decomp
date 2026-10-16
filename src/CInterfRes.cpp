#pragma interface
#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym __nw__5CTaskUi 0x24F2E8
//@sym __builtin_vec_delete 0x2456D0
#include "CTask.h"
class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};
// Interface manager interface (vtable _vt$10IInterfMgr).
class IInterfMgr : public CTask {
public:
    virtual ~IInterfMgr() {}
    virtual void Reset1691D0() = 0;
};
int GetFontTable(u32 i);
void Func23B1D0(s32 h);
// CListTag as in CList.h, but with the destructor inline (retail inlines it into
// ~CInterfRes). The vtables stay in the asm data: #pragma interface at the top keeps
// this unit from emitting them.
class CListTag {
public:
    CListTag() {
        m_isHead = 0;
        m_next = this;
        m_prev = this;
    }
    virtual ~CListTag() {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }

    s32 m_isHead;             // 0x0
    CListTag *m_prev;         // 0x4
    CListTag *m_next;         // 0x8
    // vptr 0xC
};
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
#include "common.h"

// The sound/voice object (library, ctor 0x25C230, dtor 0x25C2C0), 0x6C bytes.
class CSndWork {
public:
    CSndWork();
    ~CSndWork();
    void Func25C648(s32 h, s32 v);
    void Func25C840(s32 a, s32 b = 0, s32 c = 0);
    int Func25C990(s32 a);
    int Func25CAC0(s32 a);
    s32 Func25CF58(s32 a);
    void Func25CFC8(s32 a);   // 0x25CFC8 (config/aliases.ld)
    void Init() {
        Func25CFC8(0);
        m_unk3E = 0x80;
        m_unk3C = 0x80;
        m_unk34 = 1;
    }

    u8 pad0[0x34];
    u8 m_unk34;               // 0x34
    u8 pad35[0x7];
    s16 m_unk3C;              // 0x3C
    s16 m_unk3E;              // 0x3E
    u8 pad40[0x2C];
};

class CCharaObj {
public:
    void Func114D70(s32 a, s32 b);
};

class CInterfTimer {
public:
    CInterfTimer() {
        m_unk4 = -1;
        m_unk2 = 0;
        m_unk0 = 0;
    }
    void Reset() {
        m_unk4 = -1;
        m_unk2 = 0;
        m_unk0 = 0;
    }
    void Start(s32 n) {
        m_unk2 = 0;
        m_unk0 = 0;
        m_unk4 = n;
    }

    s16 m_unk0;               // 0x0
    s16 m_unk2;               // 0x2
    s32 m_unk4;               // 0x4
};

s32 MaxLineLen(const char *s);
// IInterfMgr.cpp and CInterfRes.cpp were one object (merged by lane lb): the members with constructors
// are the timers at 0x8/0x928 and the sound objects at 0x50/0x970.
class CInterfMgr : public IInterfMgr {
public:
    CInterfMgr();
    virtual ~CInterfMgr();
    virtual void Reset1691D0();
    s32 PlayVoice169788(s32 id);
    void SetText1693B0(const char *s, s32 frames);
    void SetText169340(const char *s);
    void ResetUnkD4Below(s32 v);
    void ClearUnkDE8();
    void Func1692D0();
    void Func169308();
    s32 IsVoicePlaying();
    void SetChara(CCharaObj *c);
    void StopVoice();
    int Func1698A0();
    void SetFade(s32 on, s32 dur);
    void DrawText(s32 a, f32 x, f32 y);
    void Func169950();
    void Func16A998(s32 a, f32 x, f32 y);
    void Func16B1C8();
    void Func16BB20();
    void Func16AA28();
    void Func16B2B0();
    void Func16C0B8();
    void Func16A650(s32 a, f32 x, f32 y, f32 w, f32 h);
    void Func1696A0();
    void Start169450(CCharaObj *c, const char *text, s32 frames, s32 a, s32 b);
    void Func16BA80(s32 a, const char *text, s32 b);

    CInterfTimer m_timer;     // 0x8
    u8 pad10[0x40];
    CSndWork m_snd;           // 0x50
    CCharaObj *m_chara;       // 0xBC
    s32 m_unkC0;              // 0xC0
    s32 m_unkC4;              // 0xC4
    s32 m_voice;              // 0xC8
    s32 m_unkCC;              // 0xCC
    s32 m_unkD0;              // 0xD0
    s32 m_unkD4;              // 0xD4
    char m_textD8[0x400];     // 0xD8
    s32 m_unk4D8;             // 0x4D8
    s32 m_unk4DC;             // 0x4DC
    char m_text4E0[0x400];    // 0x4E0
    s32 m_unk8E0;             // 0x8E0
    s32 m_unk8E4;             // 0x8E4
    s32 m_unk8E8;             // 0x8E8
    s32 m_unk8EC;             // 0x8EC
    s32 m_unk8F0;             // 0x8F0
    s32 m_unk8F4;             // 0x8F4
    s32 m_unk8F8;             // 0x8F8
    s32 m_unk8FC;             // 0x8FC
    s32 m_unk900;             // 0x900
    f32 m_unk904;             // 0x904
    s32 m_unk908;             // 0x908
    s32 m_unk90C;             // 0x90C
    s32 m_unk910;             // 0x910
    s32 m_unk914;             // 0x914
    f32 m_unk918;             // 0x918
    f32 m_unk91C;             // 0x91C
    s32 m_unk920;             // 0x920
    f32 m_unk924;             // 0x924
    CInterfTimer m_timer928;  // 0x928
    u8 pad930[0x40];
    CSndWork m_snd970;        // 0x970
    char m_text9DC[0x400];    // 0x9DC
    s32 m_unkDDC;             // 0xDDC
    s32 m_unkDE0;             // 0xDE0
    s32 m_unkDE4;             // 0xDE4
    s32 m_unkDE8;             // 0xDE8
    s32 m_unkDEC;             // 0xDEC
    s32 m_unkDF0;             // 0xDF0
    f32 m_unkDF4;             // 0xDF4
};

#include "CFlagWork.h"
extern s32 D_002A35E0[];
u64 Func23AA40();

//@sym __builtin_new 0x245648
//@sym __10CNameDBMgr 0x16C778
class CNameDBMgr {
public:
    CNameDBMgr() throw();

    u8 pad0[0x60];
};

class CEventMesMgr {
public:
    virtual ~CEventMesMgr();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual s32 Format(char *src, s32 n, char *dst, s32 a, s32 b);
};
extern CEventMesMgr *D_002A0CE0;
class CGsMgr {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void SetMode(s32 a, s32 b);
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
    virtual s32 GetBank(s32 k);
};
extern CGsMgr *D_002BA248;
extern "C" s32 func_0020E698(s32 h, s32 id);
inline f32 Clamp01(f32 v) { return (v < 1.0f ? v : 1.0f) < 0.0f ? 0.0f : (v < 1.0f ? v : 1.0f); }

#include "CTask.h"
#include "libc.h"
s32 GetSeHandle169718(s32 id);
s32 Func235DE0(const char *fmt, ...) throw();
struct CStr1 { char c[1]; };
extern CStr1 D_002D9B30;
extern char D_002D9B38[];
extern "C" void func_0025CE30(CSndWork *p, s32 h, s32 v);
extern "C" void func_0025C910(CSndWork *p, s32 h, s32 a, s32 b);
// CInterfMgr as seen through its vtable (_vt$10CInterfMgr; vptr at 4 after CTask's field).
class CInterfMgrV : public CTask {
public:
    virtual ~CInterfMgrV();
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
    virtual s32 IsVoicePlaying();
};

extern "C" int func_0025CAC0(CSndWork *p, s32 h);

extern "C" u64 func_0023AA40();
extern "C" void func_0016A650(void *p, f32 x, f32 y, s32 a, f32 w, f32 h);

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

extern "C" void IfSndStop(void *p) asm("Func25C488__FP9CSndUnitN");
extern CInterfMgr *D_002A3568;
extern "C" void func_0025C438(int tbl, CSndWork *f);
// @decl-end

CInterfRes::CInterfRes() {
    D_002A3540 = this;
    m_handles = 0;
}

CInterfRes::~CInterfRes() {
    Release();
    D_002A3540 = 0;
}

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
    func_0025C438(GetFontTable(4), &m_snd);
    CInterfMgr::Reset1691D0();
}

CInterfMgr::~CInterfMgr() {
    IfSndStop(&m_snd);
    D_002A3568 = 0;
}

void CInterfMgr::Reset1691D0() {
    m_timer.Reset();
    m_snd.Init();
    m_unkC4 = -1;
    m_chara = 0;
    m_unkC0 = 0;
    m_voice = 0;
    m_unkCC = 0;
    m_unkD0 = 0;
    m_unkD4 = 0;
    m_textD8[0] = 0;
    m_unk4D8 = 0;
    m_unk4DC = 0;
    m_text4E0[0] = 0;
    m_unk8E0 = 0;
    m_unk8E4 = 0;
    m_unk8E8 = 0;
    m_unk8EC = 0;
    m_unk8F0 = 0;
    m_unk8F4 = 0;
    m_unk8F8 = 0;
    m_unk8FC = 0;
    m_unk900 = 0;
    m_unk904 = 0;
    m_unk910 = 0;
    m_unk914 = 0;
    m_unk918 = 0;
    m_unk91C = 0;
    m_unk920 = 0;
    m_unk924 = 0;
    m_timer928.Reset();
    m_unkDDC = 0;
    m_unkDE4 = 0;
    m_unkDE0 = 0;
    m_unkDE8 = 0;
    m_unkDEC = 0;
    m_unkDF0 = 0;
    m_unkDF4 = 0;
}

void CInterfMgr::Func1692D0() {
    Func169950();
    Func16B1C8();
    Func16BB20();
}

void CInterfMgr::Func169308() {
    Func16AA28();
    Func16B2B0();
    Func16C0B8();
}

void CInterfMgr::SetText169340(const char *s) {
    m_chara = 0;
    strcpy(m_textD8, s);
    *(CStr1 *)m_text4E0 = D_002D9B30;
    m_unkC4 = 0;
    m_unk8E0 = 0;
    m_unk8E4 = 0;
    m_unk904 = 0;
    CInterfTimer *t = &m_timer;
    t->Reset();
    t->m_unk4 = m_unkC4;
    m_unkC0 = 1;
    m_unk8F4 = 0;
}

void CInterfMgr::SetText1693B0(const char *s, s32 frames) {
    *(CStr1 *)m_textD8 = D_002D9B30;
    m_chara = 0;
    strcpy(m_text4E0, s);
    m_unk8E0 = 0;
    m_unkC4 = 1;
    m_unk904 = frames / 59.94f;
    m_unk8E4 = 0;
    CInterfTimer *t = &m_timer;
    t->Reset();
    t->m_unk4 = m_unkC4;
    m_unkC0 = 1;
    m_unk8F4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CInterfRes", func_00169450);

void CInterfMgr::StopVoice() {
    if (m_voice) {
        m_snd.Func25C840(m_voice, 0, 0);
        m_voice = 0;
    }
    m_timer.Reset();
    m_unkD4 = 8;
    m_unkC0 = 0;
    m_unkCC = 0;
}

void CInterfMgr::ResetUnkD4Below(s32 v) {
    if (m_unkD4 < v) {
        m_unkD4 = 0;
    }
}

void CInterfMgr::SetChara(CCharaObj *c) {
    m_chara = c;
    if (c && m_voice && !m_unk8EC) {
        m_chara->Func114D70(1, m_snd.Func25CF58(m_voice));
    }
}

s32 MaxLineLen(const char *s) {
    s32 n = 0;
    s32 max = 0;
    while (*s) {
        if (*s < 0) {
            s += 2;
            n++;
        } else if (*s == '@' && s[1] == 'n') {
            if (n >= max) {
                max = n;
            }
            s += 2;
            n = 0;
        } else {
            s++;
        }
    }
    return n < max ? max : n;
}

void CInterfMgr::Func1696A0() {
    D_002A0CE0->Format(m_textD8, m_unk4DC, m_text4E0, 0, 0);
    m_unk8E8 = MaxLineLen(m_text4E0);
    m_unk8E0 = 1;
}

s32 GetSeHandle169718(s32 id) {
    if (D_002BA248) {
        s32 h = D_002BA248->GetBank(10);
        if (h >= 0) {
            s32 r = func_0020E698(h, id);
            if (r >= 0) return r | 0x80A0000;
        }
    }
    return 0;
}

s32 CInterfMgr::PlayVoice169788(s32 id) {
    if (((CInterfMgrV *)this)->IsVoicePlaying()) return 0;
    m_unk910 = GetSeHandle169718(id);
    D_002BA248->SetMode(6, 0x28000);
    m_snd.Func25C648(m_unk910, 8);
    func_0025CE30(&m_snd, m_unk910, 1);
    func_0025C910(&m_snd, m_unk910, 1, 0);
    D_002BA248->SetMode(4, 0x40000);
    Func235DE0(D_002D9B38, id, m_unk910);
    return 1;
}

int CInterfMgr::Func1698A0() {
    if (!m_unk910) return 1;
    if (!m_snd.Func25C990(m_unk910)) return 1;
    return func_0025CAC0(&m_snd, m_unk910);
}

s32 CInterfMgr::IsVoicePlaying() {
    s32 r = 0;
    if (m_unk910) {
        r = m_snd.Func25C990(m_unk910) != 0;
    }
    return r;
}

INCLUDE_RODATA("asm/nonmatchings/CInterfRes", D_002D9AD0);
INCLUDE_RODATA("asm/nonmatchings/CInterfRes", D_002D9AE0);
INCLUDE_RODATA("asm/nonmatchings/CInterfRes", D_002D9AF0);
INCLUDE_RODATA("asm/nonmatchings/CInterfRes", D_002D9B00);
INCLUDE_RODATA("asm/nonmatchings/CInterfRes", D_002D9B10);
INCLUDE_RODATA("asm/nonmatchings/CInterfRes", D_002D9B18);
INCLUDE_RODATA("asm/nonmatchings/CInterfRes", D_002D9B20);
INCLUDE_RODATA("asm/nonmatchings/CInterfRes", D_002D9B30);
INCLUDE_RODATA("asm/nonmatchings/CInterfRes", D_002D9B38);
INCLUDE_ASM("asm/nonmatchings/CInterfRes", Func169950__10CInterfMgr);
INCLUDE_RODATA("asm/nonmatchings/CInterfRes", D_002D9B78);
INCLUDE_RODATA("asm/nonmatchings/CInterfRes", D_002D9B98);

INCLUDE_ASM("asm/nonmatchings/CInterfRes", func_0016A650);

void CInterfMgr::Func16A998(s32 a, f32 x, f32 y) {
    u64 t = func_0023AA40();
    func_0016A650(this, x, y, a, (s32)((t >> 38) & 0xFFF), (s32)((t >> 50) & 0xFFF));
}

INCLUDE_ASM("asm/nonmatchings/CInterfRes", Func16AA28__10CInterfMgr);

void CInterfMgr::SetFade(s32 on, s32 dur) {
    m_unk914 = on;
    if (dur <= 0) {
        f32 v = 1.0f;
        if (!on) v = 0.0f;
        m_unk918 = v;
        m_unk91C = 0;
    } else {
        m_unk91C = 1.0f / dur;
    }
}

void CInterfMgr::Func16B1C8() {
    f32 v;
    if (m_unk914) v = m_unk918 + m_unk91C;
    else v = m_unk918 - m_unk91C;
    m_unk918 = v;
    m_unk918 = Clamp01(v);
    v = m_unk924;
    if (m_unk920) v += 0.06666667f;
    else v += -0.06666667f;
    m_unk924 = v;
    m_unk924 = Clamp01(v);
    if (m_unk918 == 0.0f) {
        m_unk924 = 0.0f;
        m_unk920 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CInterfRes", Func16B2B0__10CInterfMgr);

void CInterfMgr::Func16BA80(s32 a, const char *text, s32 b) {
    D_002A0CE0->Format((char *)text, 0, m_text9DC, 1, 1);
    m_timer928.Start(0);
    m_unkDF0 = b;
    m_unkDDC = a;
    m_unkDE4 = 1;
    m_unkDE0 = 0;
    m_unkDEC = 0;
    m_unkDE8 = 1;
}

void CInterfMgr::ClearUnkDE8() {
    m_unkDE8 = 0;
}

void CInterfMgr::Func16BB20() {
    CInterfTimer *sm = &m_timer928;
    s32 btn = D_0029F390->V8();
    s32 done = 0;
    f32 f;
loop:
    if (done) return;
    {
        u32 fl = (u16)sm->m_unk0;
        if ((fl >> 7) & 1) return;
    }
    switch (sm->m_unk4) {
    case -1:
        sm->m_unk4 = -0x4E2;
        goto e;
    case 0:
        m_unkDF4 = 0.0f;
        do {
            sm->m_unk4 = -0x4E9; done = 1; goto loop;
    case -0x4E9:;
            m_unkDF4 += 0.25f;
        } while (m_unkDF4 < 1.0f);
        m_unkDF4 = 1.0f;
        for (m_unkDEC = 0; m_unkDEC < m_unkDF0 && m_unkDE8; m_unkDEC++) {
            if (m_unkDEC >= 11 && (btn & 0x60)) {
                ((CSndWork *)((u8 *)this + 0x970))->Func25C648(3, 0);
                break;
            }
            sm->m_unk4 = -0x4FC; done = 1; goto loop;
    case -0x4FC:;
        }
        m_unkDE8 = 0;
        m_unkDF4 = 1.0f;
        do {
            sm->m_unk4 = -0x504; done = 1; goto loop;
    case -0x504:;
            m_unkDF4 -= 0.25f;
        } while (m_unkDF4 > 0.0f);
        m_unkDF4 = 0.0f;
        m_unkDE4 = 0;
        sm->m_unk4 = -0x50A;
    case -0x50A:
    case -0x4E2:
    e:
        done = 1; goto loop;
    }
}

INCLUDE_ASM("asm/nonmatchings/CInterfRes", func_0016BD00);

INCLUDE_ASM("asm/nonmatchings/CInterfRes", Func16C0B8__10CInterfMgr);

CNameDBMgr *CreateCNameDBMgr() {
    return new CNameDBMgr;
}

s32 FindInterfIndex(s32 i) {
    s32 k;
    if (i < D_002A26E4->Func1091B0(0x27)) {
        i = D_002A26E4->Func1091B0(i + 0x28);
    }
    for (k = 0; D_002A35E0[k] >= 0; k++) {
        if (D_002A35E0[k] == i) {
            return k;
        }
    }
    return -1;
}
INCLUDE_RODATA("asm/nonmatchings/CInterfRes", D_002D9C00);
INCLUDE_RODATA("asm/nonmatchings/CInterfRes", D_002D9C10);
INCLUDE_RODATA("asm/nonmatchings/CInterfRes", D_002D9C20);
