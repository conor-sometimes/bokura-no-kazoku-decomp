#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"
#include "CBgWork.h"
class CChrBodyWin {
public:
    void Func188BA8();
};
extern CChrBodyWin *D_002A4308;
extern "C" int func_00245818(void *p, s32 v);
extern "C" void func_00189270(void *p, s32 v);

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuTutorSelected.
class CMenuTutorSelected : public CMenuProcess {
public:
    CMenuTutorSelected();
    virtual ~CMenuTutorSelected();
    virtual s32 Update();
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
class CMenuRecordWin {
public:
    void Func1A39A8(f32 *v, s32 *n, s32 k);
};

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

int Func235DE0(const char *fmt, ...);
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
struct CTextBuf {
    s32 m0;
    u8 pad4[0x8C];
};
extern "C" CTextBuf *func_0010BF88(CTextBuf *p);
extern "C" const char *func_00256260(CTextBuf *p, s32 id);
extern "C" void func_002565B0(CTextBuf *p, f32 *w, f32 *h, const char *fmt, ...);
extern "C" void func_002564B8(CTextBuf *p, f32 *w, f32 *h, const char *s);
class CUnk2A55B0 {
public:
    s32 Size1B8500();
};
extern CUnk2A55B0 *D_002A55B0;
class CMenuMgrSub1B6418 {
public:
    void GetDefaultSize(f32 *w, f32 *h);
};
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

CMenuTutorSelected::CMenuTutorSelected() {
    m_unk64 = 0;
    m_unkA0 = 0;
    m_unkA4 = 0;
    m_unkA8 = 0;
    m_unkAC = 0;
}

CMenuTutorSelected::~CMenuTutorSelected() {
    func_00245818(&m_bg, 1);
    D_002A4308->Func188BA8();
    if (m_unk64) {
        func_00189270(m_unk64, 3);
        m_unk64 = 0;
    }
}

INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelected", D_002DAAB0);
INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", Update__18CMenuTutorSelected);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelected", D_002DAAC0);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelected", D_002DAAE0);

#if 0 // DIFF 35 as written, 17 with bk perm on the 22 sprite-field stores (g1): everything before the sprite block matches; the field stores and the x/y arithmetic interleave differently
s32 CMenuTutorSelected::Draw() {
    CTsView *t = (CTsView *)this;
    u8 *p = Func237570(0x50);
    Func237A88(p, 5);
    Func238158(Func237C30(p + 0x40), 1);
    if (m_unk64) {
        f32 a;
        ((CUnk237E90 *)(p + 0x10))->Func237E90(func_0018A1F0(m_unk64));
        ((CUnk237E90 *)(p + 0x20))->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x17)));
        D_002A5530->Reset1B4D28();
        D_002A5530->SetUnk4C(((CChrBodyWinB *)m_unk64)->GetStatusUnk34());
        D_002A5530->SetUnk54(1);
        D_002A5530->SetUnk30(t->mA0, t->mA0, 0.0f, 0.0f);
        D_002A5530->SetUnk20(t->m70, t->m74, 0.0f);
        ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B50B0(D_002A5530, 0x17));
        a = ((CChrBodyWinB *)m_unk64)->GetStatusUnk34() < t->mA8 ? ((CChrBodyWinB *)m_unk64)->GetStatusUnk34() : t->mA8;
        D_002A5530->SetUnk4C(a);
        D_002A5530->SetUnk54(2);
        D_002A5530->SetUnk58(2);
        D_002A5530->SetUnk30(t->mA4, t->mA4, t->m88, t->m8C);
        D_002A5530->SetUnk20(t->m80, t->m84, 0.0f);
        ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B50B0(D_002A5530, 0x25));
        {
            CTextBuf b;
            CTsSprite &s = *(CTsSprite *)&b;
            f32 x, y;
            func_0010BF88(&b);
            x = (t->m90 - t->m98) * t->mA4 + t->m98 - 320.0f;
            y = (t->m94 - t->m9C) * t->mA4 + t->m9C - 224.0f;
            s.m0 = 0;
            s.m4 = 0;
            s.m10 = s.m18 = x;
            s.m14 = s.m1C = y;
            s.m20 = s.m24 = t->mA4;
            s.m28 = s.m2C = 0.0f;
            s.m30 = s.m34 = s.m38 = 1.0f;
            s.m3C = a;
            s.m40 = s.m44 = s.m48 = s.m4C = 0.0f;
            s.m50 = 1;
            s.m54 = 1;
            s.m58 = 0;
            s.m70 = 1;
            func_00256648(&b);
            func_00256930(&b, func_00256260(&b, t->mAC));
            ((CUnk237E90 *)(p + 0x20))->Func237E90(func_00256668(&b));
        }
    }
    Func225088();
    Func225240((s32)p);
    return Func2250C0();
}
#endif
INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", Draw__18CMenuTutorSelected);

char *ToWide(char *dst, const char *src) {
    s32 n = strlen(src);
    s32 i;
    n = n < 1 ? 1 : n;
    for (i = 0; i < n; i++) {
        s32 c = src[i];
        s32 w = c == ' ' ? 0x8140 : c + 0x821F;
        if (dst) {
            dst[i * 2] = w >> 8;
            dst[i * 2 + 1] = w;
        }
    }
    if (dst) {
        dst[n * 2] = 0;
    }
    return dst;
}

s32 ToSeconds(s32 y, s32 mo, s32 d, s32 h, s32 mi, s32 s) {
    return y * 31104000 + mo * 2592000 + d * 86400 + h * 3600 + mi * 60 + s;
}

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

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_00182130);

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

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", Func1829E8__27CMenuTutorSelectedSub182108i);

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

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_001831A0);

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_001836E8);

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_00183B98);

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_00184090);

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_001841D0);

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

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_00184640);

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

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_001848E0);

CMenuTutorSelectedSub184CF8 *CreateCMenuTutorSelectedSub184CF8() {
    return new CMenuTutorSelectedSub184CF8;
}
