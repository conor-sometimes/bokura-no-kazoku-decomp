#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);

// Byte stream over a buffer (save data).
class CFlagStream {
public:
    s32 Write(const void *src, s32 n);
    s32 Write32(s32 v);
    void Read(void *dst, s32 n);
    void Read32(s32 *dst);

    u8 *m_cur;                // 0x0
};

// Flag id range (16 bytes).
class CFlagRange {
public:
    s16 m_lo;                 // 0x0
    s16 m_hi;                 // 0x2
    s32 m_unk4;               // 0x4
    u8 m_type;                // 0x8
    u8 pad9[3];
    s32 m_unkC;               // 0xC
};

// Flag definition (4 bytes): offset into the data, type in the low nibble, size.
class CFlagDef {
public:
    u16 m_off;                // 0x0
    u8 m_type;                // 0x2
    u8 m_size;                // 0x3
};

class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};

void *Func245D00(s32 n);
void *Func24A4C0(const char *name);
void Func235DE0(const char *fmt, ...);
extern void (*D_002B91B0)(void *p);

// Task base: objects run by the task list (0x24F5C0) come from its own heap.
class CTask {
public:
    static void *operator new(unsigned int n);

    u8 m_task[4];             // 0x0 (layout unknown)
};

class CPadMgr : public CTask {
public:
    CPadMgr() throw();

    u8 pad4[0x18];
};

class CFlagWork {
public:
    void Func109738();
    void CallFunc109738();
    void Func10ACF0();
    void CallFunc10ACF0();
    void Reset();
    s32 Func108700();
    s32 CopyData(CFlagWork *o);
    s32 CopyFrom(CFlagWork *o);
    s32 Save(u8 *buf);
    s32 GetType(s32 id);
    s32 Func1091B0(s32 id);
    const char *GetStr(s32 id);

    s32 m_unk0;               // 0x0
    CFlagRange *m_ranges;     // 0x4
    s32 m_numRanges;          // 0x8
    CFlagDef *m_defs;         // 0xC
    s32 m_numDefs;            // 0x10
    u8 *m_data;               // 0x14
    s32 m_dataSize;           // 0x18
};

s32 MaxRangeHi(CFlagRange *r, s32 n);
CFlagRange *FindRange(CFlagRange *r, s32 n, s32 id);
s32 Func109508(void *buf, const char *name);
s32 Func10A878(void *buf, const char *name);
extern s32 D_0029F330;
extern s32 D_0029F340;
extern s32 D_0029F348[2];
extern s32 D_0029F350[2];
extern s32 D_0029F380[4];
extern const char D_002D1C98[];
extern const char D_002D1D40[];
extern const char D_002D1E88[];
extern s32 D_002D1EB0[2];
extern s32 D_002D1EB8[2];
extern s32 D_002D1EC0[2];
extern s32 D_002D1EC8[2];
extern s32 D_002D1ED0[2];
extern s32 D_002D1ED8[2];
extern s32 D_002D1EE0[2];
void Func23B1D0(s32 h);
void Func220890(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
s32 Func2022A0();
void Func220680(s32 v);
s32 Func202308();
void Func2206C8(s32 v);
s32 Func202338();
void Func2206E8(s32 v);
void Func220A18(s32 a, s32 b, s32 c, s32 d);
void Func220A58(f32 a, f32 b, f32 c);
void Func1EB828(s32 v);
void Func1EB838(void *p);

//@sym memcpy 0x289DFC
//@sym __nw__5CTaskUi 0x24F2E8
//@sym __7CPadMgr 0x10AEB0
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CFlagWork", func_00108320);

INCLUDE_ASM("asm/nonmatchings/CFlagWork", func_00108370);

s32 MaxRangeHi(CFlagRange *r, s32 n) {
    s32 m = -1;
    s32 i;
    for (i = 0; i < n; i++) {
        if (r[i].m_hi >= m) {
            m = r[i].m_hi;
        }
    }
    return m + 1;
}

CFlagRange *FindRange(CFlagRange *r, s32 n, s32 id) {
    CFlagRange *found = 0;
    s32 i;
    for (i = 0; i < n; i++) {
        if (r[i].m_lo <= id && id <= r[i].m_hi) {
            found = &r[i];
        }
    }
    return found;
}

INCLUDE_ASM("asm/nonmatchings/CFlagWork", func_00108448);

void CFlagWork::Reset() {
    if (m_unk0 == 0) {
        m_defs = 0;
        m_numDefs = 0;
    } else if (m_defs) {
        D_002B91B0(m_defs);
        m_defs = 0;
        m_numDefs = 0;
    }
    if (m_data) {
        D_002B91B0(m_data);
        m_data = 0;
        m_dataSize = 0;
    }
    m_ranges = 0;
    m_numRanges = 0;
    m_unk0 = 1;
}

INCLUDE_ASM("asm/nonmatchings/CFlagWork", Func108700__9CFlagWork);

s32 CFlagWork::CopyFrom(CFlagWork *o) {
    if (m_data) {
        D_002B91B0(m_data);
        m_data = 0;
        m_dataSize = 0;
    }
    u8 *p = (u8 *)Func245D00(o->m_dataSize);
    if (!p) {
        return 0;
    }
    m_unk0 = 0;
    m_ranges = o->m_ranges;
    m_numRanges = o->m_numRanges;
    m_defs = o->m_defs;
    m_numDefs = o->m_numDefs;
    m_data = p;
    m_dataSize = o->m_dataSize;
    Func108700();
    return 1;
}

s32 CFlagWork::CopyData(CFlagWork *o) {
    if (!m_data && m_dataSize != o->m_dataSize) {
        return 0;
    }
    memcpy(m_data, o->m_data, m_dataSize);
    return 1;
}

s32 CFlagStream::Write(const void *src, s32 n) {
    if (m_cur && n > 0) {
        memcpy(m_cur, src, n);
        m_cur += n;
    }
    return n;
}

s32 CFlagStream::Write32(s32 v) {
    return Write(&v, 4);
}

void CFlagStream::Read(void *dst, s32 n) {
    if (n > 0) {
        memcpy(dst, m_cur, n);
        m_cur += n;
    }
}

void CFlagStream::Read32(s32 *dst) {
    Read(dst, 4);
}

s32 CFlagWork::Save(u8 *buf) {
    CFlagStream s;
    s.m_cur = buf;
    s32 n = s.Write32(m_dataSize);
    return n + s.Write(m_data, m_dataSize);
}

INCLUDE_ASM("asm/nonmatchings/CFlagWork", func_00108A20);

INCLUDE_ASM("asm/nonmatchings/CFlagWork", func_00108AA8);
INCLUDE_RODATA("asm/nonmatchings/CFlagWork", D_002D1C68);
INCLUDE_RODATA("asm/nonmatchings/CFlagWork", D_002D1C70);

INCLUDE_ASM("asm/nonmatchings/CFlagWork", func_00108C30);
INCLUDE_RODATA("asm/nonmatchings/CFlagWork", D_002D1C80);

INCLUDE_RODATA("asm/nonmatchings/CFlagWork", D_002D1C88);
INCLUDE_ASM("asm/nonmatchings/CFlagWork", func_00108E10);

INCLUDE_RODATA("asm/nonmatchings/CFlagWork", D_002D1C90);
INCLUDE_ASM("asm/nonmatchings/CFlagWork", func_00108E38);

s32 CFlagWork::GetType(s32 id) {
    if (id < 0 || id > m_numDefs - 1) {
        return -1;
    }
    return m_defs[id].m_type & 0xF;
}

INCLUDE_RODATA("asm/nonmatchings/CFlagWork", D_002D1C98);
INCLUDE_ASM("asm/nonmatchings/CFlagWork", func_00108EA0);

INCLUDE_ASM("asm/nonmatchings/CFlagWork", Func108FF0__9CFlagWorkii);

INCLUDE_ASM("asm/nonmatchings/CFlagWork", Func109108__9CFlagWorkii);

const char *CFlagWork::GetStr(s32 id) {
    if (id < 0 || id > m_numDefs - 1) {
        return D_002D1C98;
    }
    CFlagDef *d = &m_defs[id];
    if ((d->m_type & 0xF) != 1) {
        return D_002D1C98;
    }
    return (const char *)m_data + d->m_off;
}

INCLUDE_ASM("asm/nonmatchings/CFlagWork", Func1091B0__9CFlagWorki);

INCLUDE_ASM("asm/nonmatchings/CFlagWork", Func109248__9CFlagWorkiii);

INCLUDE_ASM("asm/nonmatchings/CFlagWork", func_001092B0);

INCLUDE_ASM("asm/nonmatchings/CFlagWork", func_00109410);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001094E0() {
}

void CFlagWork::CallFunc109738() {
    Func109738();
}

INCLUDE_ASM("asm/nonmatchings/CFlagWork", Func109508__FPvPCc);

s32 Load109508(const char *name) {
    void *buf = Func24A4C0(name);
    if (!buf) {
        Func235DE0(D_002D1D40, name);
        return 0;
    }
    s32 r = Func109508(buf, name);
    D_002B91B0(buf);
    return r;
}

void CFlagWork::Func109738() {
    if (D_0029F330 >= 0) {
        Func23B1D0(D_0029F330);
        D_0029F330 = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/CFlagWork", func_00109778);

INCLUDE_ASM("asm/nonmatchings/CFlagWork", func_001098A8);

INCLUDE_ASM("asm/nonmatchings/CFlagWork", func_00109C30);

INCLUDE_ASM("asm/nonmatchings/CFlagWork", func_0010A000);

INCLUDE_ASM("asm/nonmatchings/CFlagWork", func_0010A3E8);

void CallFunc220A58() {
    Func220A58(1.0f, 0.0f, 0.0f);
}

void CFlagWork::CallFunc10ACF0() {
    Func10ACF0();
}

INCLUDE_ASM("asm/nonmatchings/CFlagWork", Func10A878__FPvPCc);

s32 Load10A878(const char *name) {
    void *buf = Func24A4C0(name);
    if (!buf) {
        Func235DE0(D_002D1E88, name);
        return 0;
    }
    s32 r = Func10A878(buf, name);
    D_002B91B0(buf);
    return r;
}

void CFlagWork::Func10ACF0() {
    if (D_0029F340 >= 0) {
        Func23B1D0(D_0029F340);
        D_0029F340 = -1;
    }
}

void Func10AD30() {
    Func220890(D_0029F340, 0, D_0029F348[0], D_0029F348[1], D_0029F350[0], D_0029F350[1]);
    Func220680(Func2022A0());
    Func2206C8(Func202308());
    Func2206E8(Func202338());
    Func220A18(D_0029F380[0], D_0029F380[1], D_0029F380[2], D_0029F380[3]);
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_0010ADC0() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_0010ADC8() {
}

void Func10ADD0() {
    Func1EB828(1);
    Func1EB838(D_002D1EB0);
    Func1EB838(D_002D1EB8);
    Func1EB838(D_002D1EC0);
    Func1EB838(D_002D1EC8);
    Func1EB838(D_002D1ED0);
    Func1EB838(D_002D1ED8);
    Func1EB838(D_002D1EE0);
}

void ClearFunc1EB828And1EB838() {
    Func1EB828(0);
    Func1EB838(0);
}

s32 AddPadMgr(CTaskList24F5C0 *list) {
    CPadMgr *t = new CPadMgr;
    return list->Func24F5C0(t, 0);
}
INCLUDE_RODATA("asm/nonmatchings/CFlagWork", D_002D1CA0);
