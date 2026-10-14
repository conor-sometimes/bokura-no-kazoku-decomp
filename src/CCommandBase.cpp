#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CCommandBaseRec {
public:
    s32 m0;                   // 0x0
    s32 m4;                   // 0x4
    u8 pad8[0x4];
    s32 mC;                   // 0xC
    u8 pad10[0x30];
    s32 m40;                  // 0x40
    u8 pad44[0x4];
};
class CCommandBase {
public:
    void SetMode198128(s32 mode);
    int GetRecC198328(s32 i);
    void Select198290(s32 i);
    int RowOf(int v);
    void Open();
    void Close();
    s32 NumRows();
    s32 GetRec40(s32 i);
    CCommandBaseRec *GetRec(s32 i);
    s32 GetRec4(s32 i);
    s32 NextRowItem();
    s32 PrevRowItem(s32 wrap);

    u8 pad0[0x48];
    void *m_win;              // 0x48
    s32 m_state;              // 0x4C
    CCommandBaseRec m_recs[16]; // 0x50
    s32 m_num;                // 0x4D0
    s32 m_cursor;             // 0x4D4
    u8 pad4D8[0xC];
    s32 m_unk4E4;             // 0x4E4
};

void Func235DE0(const char *fmt, ...);
extern s32 D_002A5370[];
extern char D_002DD838[];
extern char D_002DD858[];
extern char D_002DD8A0[];
extern char D_002DD8C8[];
extern char D_002DD8F0[];

extern "C" void func_001A3840(void *win, s32 i);
extern "C" s32 func_001971A0(void *p, s32 i);
extern "C" void func_00196E90(void *p, s32 row);

class CFlagWork {
public:
    int Func1091B0(s32 id);
};
extern CFlagWork *D_002A26E4;
extern char D_002DD878[];
extern "C" int func_001456A8(s32 v);

class CMenuRecordWin {
public:
    void Func1A3740(s32 v, const char *s);
};
extern "C" void func_001A3DC8(void *p, s32 i, s32 v);
extern "C" void func_001864A8(char *buf);
extern "C" const char *func_001A36B0(void *w, s32 v);
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern char D_002DD820[];
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CCommandBase", func_00198080);

void CCommandBase::SetMode198128(s32 mode) {
    char str[0x200];
    char buf[0x200];
    if (m_win == 0) return;
    switch (mode) {
    case 0:
        func_001A3DC8(m_win, 4, 1);
        func_001A3DC8(m_win, 5, 0);
        func_001A3DC8(m_win, 6, 1);
        func_001864A8(buf);
        sprintf(str, func_001A36B0(m_win, 6), buf);
        ((CMenuRecordWin *)m_win)->Func1A3740(6, str);
        break;
    case 1:
        func_001A3DC8(m_win, 4, 0);
        func_001A3DC8(m_win, 5, 1);
        func_001A3DC8(m_win, 6, 0);
        break;
    default:
        Func235DE0(D_002DD820, mode);
        break;
    }
}

void CCommandBase::Open() {
    if (m_state) {
        return Func235DE0(D_002DD838);
    }
    m_state = 1;
}

void CCommandBase::Close() {
    if (m_state != 2) {
        return Func235DE0(D_002DD858);
    }
    m_state = 4;
}

void CCommandBase::Select198290(s32 i) {
    if (m_win == 0) return;
    if ((u32)i >= 19) {
        m_cursor = -1;
    } else {
        m_cursor = i;
        if (i < 3) {
            func_001A3840(m_win, i);
        } else {
            func_001A3840(m_win, func_001971A0(this, i - 3) + 3);
        }
    }
    func_00196E90(this, RowOf(m_cursor));
    m_unk4E4 = 1;
}

int CCommandBase::GetRecC198328(s32 i) {
    if (i < 0 || i > m_num - 1) {
        Func235DE0(D_002DD878, i);
        return -1;
    }
    s32 v = m_recs[i].mC;
    if ((u32)(v - 16) >= 9) return -1;
    if (v == 24) {
        if (D_002A26E4->Func1091B0(0x27) == 1) v = 0;
        return v;
    }
    return func_001456A8(v);
}

s32 CCommandBase::GetRec40(s32 i) {
    if (i < 0 || i > m_num - 1) {
        Func235DE0(D_002DD8A0, i);
        return 0;
    }
    return m_recs[i].m40;
}

INCLUDE_ASM("asm/nonmatchings/CCommandBase", func_00198430);

s32 CCommandBase::GetRec4(s32 i) {
    if (i < 0 || i > m_num - 1) {
        Func235DE0(D_002DD8F0, i);
        return 0;
    }
    return m_recs[i].m4;
}

s32 CCommandBase::NumRows() {
    if (m_num < 5) {
        return 1;
    }
    return (m_num - 5) / 6 + 2;
}

int CCommandBase::RowOf(int v) {
    if (v < 7) {
        return 0;
    }
    return (v - 7) / 6 + 1;
}

s32 CCommandBase::NextRowItem() {
    if (NumRows() == 1) {
        return -1;
    }
    if (RowOf(m_cursor) == NumRows() - 1) {
        return D_002A5370[0];
    }
    return D_002A5370[RowOf(m_cursor) + 1];
}

s32 CCommandBase::PrevRowItem(s32 wrap) {
    if (NumRows() == 1) {
        return -1;
    }
    if (RowOf(m_cursor) == 0) {
        if (wrap) {
            return D_002A5370[NumRows() - 1];
        }
        return -1;
    }
    return D_002A5370[RowOf(m_cursor) - 1];
}
