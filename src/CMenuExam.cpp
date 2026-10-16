#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuExam.
class CMenuExam : public CMenuProcess {
public:
    CMenuExam();
    virtual ~CMenuExam();
    virtual void Update();
    virtual s32 Draw();

    s32 m_unk58;              // 0x58
};

#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
extern "C" void func_00185648(s32 i);
extern "C" void func_00185868(s32 i, s32 a, s32 b);
s32 Func145738(s32 a, s32 b);
// Text table reader (0x10BF88 constructor, 0x256260 lookup; library code).
struct CTextBuf {
    s32 m0;
    u8 pad4[0x8C];
};
extern "C" CTextBuf *func_0010BF88(CTextBuf *p);
extern "C" const char *func_00256260(CTextBuf *p, s32 id);
extern "C" char *strcpy(char *dst, const char *src);

extern char D_002DAEE0[], D_002DAF08[], D_002DAF30[], D_002DADA0[], D_002DADC0[], D_002DADE0[];
extern s32 D_002A4268[][5];
extern s32 D_002A41A0[][10];
struct CExamFlagDef {
    s32 m_dst;
    s32 m_src;
};
extern CExamFlagDef D_002A3CC8[];
extern CExamFlagDef D_002A3DB0[];
extern CFlagWork *D_002A4638[];
extern "C" char *func_0024BA08(char *buf, s32 v);
extern "C" int sprintf(char *buf, const char *fmt, ...);

void *Func248E48(const char *name);
extern char D_002DAF58[], D_002DAF70[];
extern "C" int func_00253048(void *p, s32 *a, s32 *b, s32 *c, s32 *d, s32 *e, s32 *f, s32 *g, s32 *h);
extern "C" void func_0023C048(s32 a, s32 b, s32 c);
struct CExamTex {
    void *m_data;             // 0x0
    s32 m_unk4;               // 0x4
    s32 m_unk8;               // 0x8
    s32 m_unkC;               // 0xC
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
};

struct CExamNames { s32 n; char *s[1]; };
extern char D_002DAE00[], D_002DAE58[], D_002DAE60[];
class CExamDB {
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
    virtual s32 Find(s32 a);
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
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual CExamNames *GetNames(s32 b);
    virtual struct CExamNames *GetNamesA(s32 b, s32 i);
    virtual struct CExamNames *GetNamesB(s32 b, s32 i);
};
extern CExamDB *D_002A2988;

class CUnk1A4298 {
public:
    int Func1A4298();
    u8 pad0[0x34];
    f32 m_unk34;              // 0x34
};
#include "CMenuRecordWin.h"
class CUnk237E90 {
public:
    int Func237E90(int v);
};
u8 *Func237570(int n);
void Func237A88(void *p, int v);
void *Func237C30(void *p);
int Func238158(void *p, int v);
void Func225240(int v);
#include "CMenuMgrSub1B4768.h"
extern CMenuMgrSub1B4768 *D_002A5530;
#include "CMenuLoadMemorialSub17B3A0.h"
extern CMenuLoadMemorialSub17B3A0 *D_002A3AF8;

extern char D_002DAEB8[];

struct CGsRect { s32 x0, y0, x1, y1; };

#include "state.h"
class CStatusItem {
public:
    void Func1A3378();
    void Func1A3628();
    void Start();
    void Func1A40C8();
    void Select(s32 i);
    const char *GetUnkE4(s32 i);
    void SetText(s32 i, const char *s);
    void SetUnkF0(s32 i, s32 v);
    u8 pad0[0x20];
    s32 m_state;              // 0x20
};
class CStatusWinSub1A0A10 {
public:
    CStatusItem *Find(const char *name);
};
extern CStatusWinSub1A0A10 *D_002A5408;
class CSndIf {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual int V7(s32 *a, s32 *b, s32 *c);
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14(s32 v);
};
extern CSndIf *D_002A5468;
extern CFlagWork *D_002A4B60;
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
extern "C" int sprintf(char *buf, const char *fmt, ...);
void Func185AA0(char *dst, s32 k, s32 a, s32 b, s32 c, s32 d, s32 e);
inline void SetVar(CStateMachine *sm, s32 k, s32 v) { sm->Var(k) = v; }
inline void Inc(CStateMachine *sm) { SetVar(sm, 0, sm->Get(0) + 1); }
#define W ((CStatusItem *)m_unk58)

// From CMenuTutorSelected.cpp (lane lb moved its functions 0x182070.. here: their literals are this unit's)
#include "CMenuProcess.h"
#include "CBgWork.h"
#include "CChrBodyWin.h"
extern CChrBodyWin *D_002A4308;
extern "C" int func_00245818(void *p, s32 v);
extern "C" void func_00189270(void *p, s32 v);

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuTutorSelected.
class CMenuTutorSelected : public CMenuProcess {
public:
    CMenuTutorSelected();
    virtual ~CMenuTutorSelected();
    virtual void Update();
    virtual s32 Draw();

    CBgWork m_bg;             // 0x58
    void *m_unk64;            // 0x64
    u8 pad68[0x38];
    s32 m_unkA0;              // 0xA0
    s32 m_unkA4;              // 0xA4
    s32 m_unkA8;              // 0xA8
    s32 m_unkAC;              // 0xAC
};

//@sym memset 0x289FB0
#include "libc.h"
#include "CMenuRecordWin.h"

class CTutorTimer {
public:
    void Reset() {
        m_unk4 = -1;
        m_unk2 = 0;
        m_unk0 = 0;
    }

    s16 m_unk0;               // 0x0
    s16 m_unk2;               // 0x2
    s32 m_unk4;               // 0x4
};

class CTutorEntry {
public:
    s32 m_unk0;               // 0x0
    u8 pad4[0x420];
};

class CMenuTutorSelectedSub182108 {
public:
    void Clear();
    void Init();
    void Reset();
    void Func1829A0();
    int Advance2To4();
    s32 GetEntry(u32 i);
    void GetCursorPos(f32 *x, f32 *y);
    void SetPage(s32 m);

    CTutorTimer m_timer;      // 0x0
    u8 pad8[0x40];
    void *m_unk48;            // 0x48
    CMenuRecordWin *m_win;    // 0x4C
    s32 m_unk50;              // 0x50
    union {
        u8 m_data[0x7C38];    // 0x54
        CTutorEntry m_entries[30];
    };
    s32 m_state;              // 0x7C8C
    s32 m_cursor;             // 0x7C90
    s32 m_unk7C94;            // 0x7C94
    u8 pad7C98[0x48];
    s32 m_unk7CE0;            // 0x7CE0
};

class CTutorPhase {
public:
    int Advance2To3();

    s32 m_state;              // 0x0
    u8 pad4[0x8];
    s32 m_unkC;               // 0xC
};

class CTutorInit {
public:
    void Init();

    s32 m_unk0;               // 0x0
    s32 m_unk4;               // 0x4
    s32 m_unk8;               // 0x8
    s32 m_unkC;               // 0xC
    s32 m_unk10;              // 0x10
    u8 pad14[0x1C];
    f32 m_unk30;              // 0x30
    f32 m_unk34;              // 0x34
    f32 m_unk38;              // 0x38
    s32 m_unk3C;              // 0x3C
    s32 m_unk40;              // 0x40
};

int Func235DE0(const char *fmt, ...) throw();
extern "C" unsigned int strlen(const char *s);
extern const char D_002DAB60[];
extern const char D_002DACE0[];
extern const char D_002DABD0[];

//@sym __builtin_delete 0x2456A8
class CMenuTutorSelectedSub182098 { public: ~CMenuTutorSelectedSub182098(); };
// Member of CMenuBoot at 0x70 (and of CMenuLoad/CMenuSave).
// Fading caption text (0x44 bytes).
class CMenuTutorSelectedSub1843F0 {
public:
    CMenuTutorSelectedSub1843F0();
    ~CMenuTutorSelectedSub1843F0();
    int Func184420();
    void Start(s32 id, s32 mode);
    void Update();
    void GetPos(f32 *x, f32 *y);
    void Close();

    s32 m_state;              // 0x00
    s32 m4;                   // 0x04
    s32 m_mode;               // 0x08
    s32 m_count;              // 0x0C
    s32 m_id;                 // 0x10
    u8 pad14[0xC];
    f32 m_x;                  // 0x20
    f32 m_y;                  // 0x24
    f32 m_w;                  // 0x28
    f32 m_h;                  // 0x2C
    f32 m30;                  // 0x30
    f32 m34;                  // 0x34
    f32 m38;                  // 0x38
    f32 m_alpha;              // 0x3C
    f32 m40;                  // 0x40
};
#include "CFlagWork.h"
// Text table reader (0x10BF88 constructor, 0x256260 lookup; library code).
extern "C" CTextBuf *func_0010BF88(CTextBuf *p);
extern "C" const char *func_00256260(CTextBuf *p, s32 id);
extern "C" void func_002565B0(CTextBuf *p, f32 *w, f32 *h, const char *fmt, ...);
extern "C" void func_002564B8(CTextBuf *p, f32 *w, f32 *h, const char *s);
#include "CUnk2A55B0.h"
extern CUnk2A55B0 *D_002A55B0;
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
extern CFlagWork *D_002A4B60;
extern char D_002DAC90[], D_002DACB8[], D_002DAB40[];
extern "C" void func_001A3DC8(void *win, s32 a, s32 b);

//@sym __builtin_new 0x245648
//@sym __27CMenuTutorSelectedSub184CF8 0x184CF8
class CMenuTutorSelectedSub184CF8 {
public:
    CMenuTutorSelectedSub184CF8() throw();

    u8 pad0[0x5C];
};

//@sym Reset__27CMenuTutorSelectedSub182108 0x1820C8
//@sym strlen 0x28B3E8
// @decl-end

void CMenuTutorSelectedSub182108::Init() {
    m_timer.Reset();
    return Reset();
}

CMenuTutorSelectedSub182098::~CMenuTutorSelectedSub182098() {
}

void CMenuTutorSelectedSub182108::Reset() {
    m_unk7CE0 = -1;
    m_unk7C94 = 0;
    m_state = 0;
    m_cursor = 0;
    m_unk48 = 0;
    m_win = 0;
    m_unk50 = 0;
    Clear();
}

void CMenuTutorSelectedSub182108::Clear() {
    memset(m_data, 0, sizeof(m_data));
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00182130);

void CMenuTutorSelectedSub182108::SetPage(s32 m) {
    if (m_state) return (void)Func235DE0(D_002DAB40, m_state);
    m = m < 0 ? 0 : (m > 2 ? 2 : m);
    switch (m) {
    case 0:
        func_001A3DC8(m_unk48, 5, 1);
        func_001A3DC8(m_unk48, 6, 0);
        func_001A3DC8(m_unk48, 7, 0);
        func_001A3DC8(m_win, 5, 1);
        func_001A3DC8(m_win, 6, 0);
        break;
    case 1:
        func_001A3DC8(m_unk48, 5, 0);
        func_001A3DC8(m_unk48, 6, 1);
        func_001A3DC8(m_unk48, 7, 0);
        func_001A3DC8(m_win, 5, 0);
        func_001A3DC8(m_win, 6, 1);
        break;
    case 2:
        func_001A3DC8(m_unk48, 5, 0);
        func_001A3DC8(m_unk48, 6, 0);
        func_001A3DC8(m_unk48, 7, 1);
        func_001A3DC8(m_win, 5, 1);
        func_001A3DC8(m_win, 6, 0);
        break;
    }
    m_unk7C94 = m;
    m_state = 1;
}

void CMenuTutorSelectedSub182108::Func1829A0() {
    if (m_state != 2) return (void)Func235DE0(D_002DAB60, m_state);
    m_state = 4;
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", Func1829E8__27CMenuTutorSelectedSub182108i);

void CMenuTutorSelectedSub182108::GetCursorPos(f32 *x, f32 *y) {
    f32 v[4];
    m_win->Func1A39A8(&v[0], (s32 *)&v[1], 10);
    m_win->Func1A39A8(&v[2], (s32 *)&v[3], 11);
    *x = (m_cursor % 5) * v[2] + v[0];
    *y = (m_cursor / 5) * v[3] + v[1];
}

s32 CMenuTutorSelectedSub182108::GetEntry(u32 i) {
    if (i >= 30) {
        Func235DE0(D_002DABD0, i);
        return -1;
    }
    return m_entries[i].m_unk0;
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_001831A0);

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_001836E8);

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00183B98);

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00184090);

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_001841D0);

CMenuTutorSelectedSub1843F0::CMenuTutorSelectedSub1843F0() {
    Func184420();
}

CMenuTutorSelectedSub1843F0::~CMenuTutorSelectedSub1843F0() {
}

int CMenuTutorSelectedSub1843F0::Func184420() {
    m_state = 0;
    m4 = -1;
    m_mode = -1;
    m_count = 0;
    m_id = 0;
    m38 = 1.0f;
    m34 = 1.0f;
    m30 = 1.0f;
    m_alpha = 0.0f;
    m40 = 0.0f;
}

void CMenuTutorSelectedSub1843F0::Start(s32 id, s32 mode) {
    CTextBuf buf;
    const char *p;
    if (m_state) {
        Func235DE0(D_002DAC90, m_state, id, mode);
        return;
    }
    m_state = 1;
    m_count = 0;
    mode = mode < -1 ? -1 : (mode > 1 ? 1 : mode);
    m_mode = mode;
    if (mode == -1) m40 = 0.0f;
    else m40 = (f32)D_002A4B60->Func1091B0(0x66) * 2.0f;
    m_id = id;
    func_0010BF88(&buf);
    buf.m0 = 0;
    p = func_00256260(&buf, id);
    if (!p) {
        Func235DE0(D_002DACB8, id);
        Func184420();
        return;
    }
    if ((u32)(m_id - 0x131) < 4) {
        s32 sz = 0;
        if (D_002A55B0) sz = D_002A55B0->Size1B8500();
        func_002565B0(&buf, &m_w, &m_h, p, sz);
    } else {
        func_002564B8(&buf, &m_w, &m_h, p);
    }
    m_x = 320.0f - m_w * 0.5f;
    m_y = 224.0f - m_h * 0.5f;
}

void CMenuTutorSelectedSub1843F0::Close() {
    if (m_state != 2) return (void)Func235DE0(D_002DACE0, m_state);
    m_count = 0;
    m_state = 3;
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00184640);

void CMenuTutorSelectedSub1843F0::GetPos(f32 *x, f32 *y) {
    CTextBuf buf;
    CTextBuf *b;
    f32 w, h, dw, dh;
    f32 lh;
    func_0010BF88(&buf);
    b = &buf;
    b->m0 = 0;
    func_002565B0(b, &w, &h, func_00256260(b, 0x12C), 0, 0, 0, 0, 0, 0);
    lh = (f32)D_002A4B60->Func1091B0(0x66);
    D_002A5538->GetDefaultSize(&dw, &dh);
    *y = m_y + m_h - lh;
    if (m_mode == 1) *x = 320.0f - w * 0.5f - dw;
    else *x = w * 0.5f + 320.0f - lh * 3.0f - dh;
}

void CMenuTutorSelectedSub1843F0::Update() {
    switch (m_state) {
    case 1:
        m_alpha = (f32)m_count / (f32)D_002A4B60->Func1091B0(4);
        m_count++;
        if (D_002A4B60->Func1091B0(4) < m_count) m_state = 2;
        break;
    case 0:
    case 2:
        break;
    case 3:
        m_alpha = 1.0f - (f32)m_count / (f32)D_002A4B60->Func1091B0(4);
        m_count++;
        if (D_002A4B60->Func1091B0(4) < m_count) m_state = 0;
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_001848E0);

CMenuTutorSelectedSub184CF8 *CreateCMenuTutorSelectedSub184CF8() {
    return new CMenuTutorSelectedSub184CF8;
}

CMenuExam::CMenuExam() {
    m_unk58 = 0;
}

CMenuExam::~CMenuExam() {
}

INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAB38);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAB40);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAB60);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAB88);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DABB8);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DABC0);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DABC8);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DABD0);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC00);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC10);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC20);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC30);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC50);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC90);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DACB8);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DACE0);
void CMenuExam::Update() {
    CStateMachine *sm = (CStateMachine *)this;
    s32 a, b, c;
    char buf[0x100];
    char tmp[0x100];
    s32 done;
    D_002A5468->V7(&a, &b, &c);
    if (m_state == 6) {
        m_state = 5;
        goto end;
    }
    done = 0;
loop:
    if (done) goto out;
    {
        u32 fl = sm->m_flags;
        if ((fl >> 7) & 1) goto out;
    }
    switch (sm->m_state) {
    case -1:
        m_unk58 = (s32)D_002A5408->Find("exam");
        if (!m_unk58) { Func235DE0("*** Can't Get %s Window\n", "exam"); return; }
        W->Func1A3378();
        W->Select(-1);
        D_002A5538->SetUnkE0(0);
        switch (D_002A5358->Func1091B0(0x2A6)) {
        case 0:
            W->SetUnkF0(3, 1);
            W->SetUnkF0(4, 0);
            W->SetUnkF0(5, 1);
            W->SetUnkF0(6, 0);
            W->SetUnkF0(7, 0);
            break;
        case 1:
            W->SetUnkF0(3, 0);
            W->SetUnkF0(4, 1);
            W->SetUnkF0(5, 0);
            W->SetUnkF0(6, 1);
            W->SetUnkF0(7, 0);
            Func185AA0(tmp, D_002A5358->Func1091B0(4), -1, -1, -1, -1, -1);
            sprintf(buf, W->GetUnkE4(6), tmp);
            W->SetText(6, buf);
            break;
        case 2:
            W->SetUnkF0(3, 0);
            W->SetUnkF0(4, 1);
            W->SetUnkF0(5, 0);
            W->SetUnkF0(6, 0);
            W->SetUnkF0(7, 1);
            Func185AA0(tmp, D_002A5358->Func1091B0(4), -1, -1, -1, -1, -1);
            sprintf(buf, W->GetUnkE4(7), tmp);
            W->SetText(7, buf);
            break;
        }
        W->Func1A3628();
    case -0xBB:
        if (W->m_state == 2) {
            sm->m_state = -0xC0; done = 1; goto loop;
        }
        sm->m_state = -0xBB; done = 1; goto loop;
    case -0xC0:
        sm->Push(4);
        SetVar(sm, 1, D_002A4B60->Func1091B0(0x57));
        SetVar(sm, 0, 0);
        {
            f32 z = 0.0f;
            SetVar(sm, 2, *(s32 *)&z);
        }
        {
            f32 z = 0.0f;
            SetVar(sm, 3, *(s32 *)&z);
        }
        for (; sm->Get(0) < sm->Get(1); Inc(sm)) {
            if (!(a & 0x60)) {
                sm->m_state = -0xCB; done = 1; goto loop;
            }
            D_002A5468->V14(3);
            sm->Pop(4);
            goto s4;
    case -0xCB:;
        }
        sm->Pop(4);
    s4:
        m_state = 4;
        W->Start();
        while (W->m_state != 0) {
            sm->m_state = -0xD6; done = 1; goto loop;
    case -0xD6:;
        }
        m_state = 5;
        sm->m_state = -0xDC;
    case -0xDC:
        done = 1; goto loop;
    }
out:
    if (m_unk58) W->Func1A40C8();
end:;
}

s32 CMenuExam::Draw() {
    f32 v[2];
    if (m_unk58 == 0) {
        Func225088();
        Func2250C0();
    } else {
        u8 *p = Func237570(0x40);
        Func237A88(p, 4);
        CUnk237E90 *q = (CUnk237E90 *)(p + 0x20);
        Func238158(Func237C30(p + 0x30), 1);
        CUnk1A4298 *w = (CUnk1A4298 *)m_unk58;
        ((CUnk237E90 *)(p + 0x10))->Func237E90(w->Func1A4298());
        D_002A5530->Reset1B4D28();
        D_002A3AF8->CallFunc17B3E8();
        q->Func237E90(D_002A3AF8->Func17B4A0());
        D_002A3AF8->SetUnk40(3.0f, 1.0f, 1);
        D_002A3AF8->SetUnk20(0.65f, 0.65f);
        ((CMenuRecordWin *)m_unk58)->Func1A39A8(&v[0], (s32 *)&v[1], 8);
        D_002A3AF8->SetUnk10(v[0], v[1]);
        D_002A3AF8->SetUnk30(1.0f, 1.0f, 1.0f, ((CUnk1A4298 *)m_unk58)->m_unk34);
        q->Func237E90(D_002A3AF8->Draw17B4D8(D_002A5358->Func1091B0(4)));
        Func225088();
        Func225240((s32)p);
        Func2250C0();
    }
}

s32 Func1855B0(s32 *out) {
    s32 i;
    for (i = 5; i >= 0; i--) {
        out[i] = -1;
    }
    for (i = 0; i < 6; i++) {
        s32 v = D_002A5358->Func1091B0(i + 4);
        if (v < 0) {
            break;
        }
        out[i] = v;
    }
    return i;
}
