#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMenuTutorSelected {
public:
    int Func184420();
    int CallFunc184420();


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
    int Init();
    int Reset();
    int Advance2To4();
    s32 GetEntry(u32 i);
    void GetCursorPos(f32 *x, f32 *y);

    CTutorTimer m_timer;      // 0x0
    u8 pad8[0x40];
    s32 m_unk48;              // 0x48
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
class CMenuTutorSelectedSub1843F0 { public: ~CMenuTutorSelectedSub1843F0(); };

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

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", Init17FD50__16CMenuTutorSelect);

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_0017FDA0);

INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelected", D_002DAAB0);
INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_0017FE58);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelected", D_002DAAC0);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelected", D_002DAAE0);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelected", D_002DAB20);

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_00181CA0);

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

int CMenuTutorSelectedSub182108::Init() {
    m_timer.Reset();
    return Reset();
}

CMenuTutorSelectedSub182098::~CMenuTutorSelectedSub182098() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", Reset__27CMenuTutorSelectedSub182108);

void CMenuTutorSelectedSub182108::Clear() {
    memset(m_data, 0, sizeof(m_data));
}

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_00182130);

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_001827E8);

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_001829A0);

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_001829E8);

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

int CMenuTutorSelected::CallFunc184420() {
    return Func184420();
}

CMenuTutorSelectedSub1843F0::~CMenuTutorSelectedSub1843F0() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", Func184420__18CMenuTutorSelected);

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_00184458);

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_001845F8);

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_00184640);

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_00184670);

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_001847B0);

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelected", func_001848E0);

CMenuTutorSelectedSub184CF8 *CreateCMenuTutorSelectedSub184CF8() {
    return new CMenuTutorSelectedSub184CF8;
}
