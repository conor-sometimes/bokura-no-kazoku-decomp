#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CPushBuf {
public:
    void Func248E00();
    int Func248EB0();
    void *Func248CC8(s32 size, s32 a, s32 b);
    void Func248EE0(void *p);

    u8 m_data[0xC];
};

class CLayoutEntry {
public:
    const char *m_name;       // 0x0
    u8 pad4[0x8];
};

class CLayoutPart {
public:
    u8 pad0[0x28];
};

class CLayoutResSub1B8748 : public CPushBuf {
public:
    void Clear();
    s32 Init();
    s32 Func1B96F0(void *p);
    void *CopyFrom(CPushBuf *b);
    void Release();
    CLayoutEntry *Find(const char *name);
    CLayoutPart *GetPart(s32 i);
    s32 ReadInts(const char *key, s32 *out, s32 n);

    s32 m_unkC;               // 0xC
    CLayoutEntry *m_entries;  // 0x10
    s32 m_count;              // 0x14
    CLayoutPart *m_parts;     // 0x18
    s32 m_numParts;           // 0x1C
};
extern "C" int strcmp(const char *a, const char *b);
extern void (*D_002B91B0)(void *p);
const char *Func24ADE0(const char *p, char *buf, s32 n);
void Func226DF8(s32 a, u64 b);
const char *Func24AF10(void *p, const char *key);
const char *Func24AFE8(const char *p, char *buf, s32 a, s32 n);
long Func289140(const char *s);

//@sym strcmp 0x28B190
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CLayoutRes", func_001B86A0);

INCLUDE_ASM("asm/nonmatchings/CLayoutRes", func_001B86D8);

void CLayoutResSub1B8748::Clear() {
    m_entries = 0;
    m_count = 0;
    m_parts = 0;
    m_numParts = 0;
    m_unkC = 0;
}

INCLUDE_ASM("asm/nonmatchings/CLayoutRes", func_001B8760);

s32 CountTokens(const char *p) {
    char buf[0x100];
    s32 n = 0;
    for (;;) {
        p = Func24ADE0(p, buf, 0x100);
        if (*p == 0 && buf[0] == 0) {
            break;
        }
        n++;
    }
    return n;
}

INCLUDE_ASM("asm/nonmatchings/CLayoutRes", func_001B8890);

s32 FindLayoutName(const char **tbl, const char *name, s32 def) {
    s32 i;
    for (i = 0; tbl[i]; i++) {
        if (strcmp(tbl[i], name) == 0) {
            return i;
        }
    }
    return def;
}

INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFF50);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFF68);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFF70);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFF78);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFF98);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFFA0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFFA8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFFB0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFFD8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0008);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0030);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0060);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0090);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E00B8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E00E8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0120);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", jtbl_002E0140);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0270);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0298);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E02B8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E02D0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E02F0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0318);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0338);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0350);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0380);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E03A8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E03C8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E03E8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E03F8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0408);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0428);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0448);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0470);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0498);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E04C0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E04E8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0508);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0530);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0560);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0590);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E05B8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E05C0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E05D0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E05D8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E05E0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E05F8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0610);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0618);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0630);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0640);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0658);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0668);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0678);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0690);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E06B0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E06C8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E06E0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E06E8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0700);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0718);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0730);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0738);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0740);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0760);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0778);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0788);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E07A8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E07D8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0800);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0820);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0840);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0860);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0888);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E08A0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E08B0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E08D0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E08E0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0900);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0910);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0928);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0950);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0980);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", jtbl_002E09A0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E09C0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A10);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A20);
INCLUDE_ASM("asm/nonmatchings/CLayoutRes", func_001B8BE0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A58);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A60);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A68);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A70);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A78);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A80);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A88);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A90);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A98);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AA0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AA8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AB0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AB8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AC0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AC8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AD0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AD8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AE0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AE8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AF0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AF8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0B00);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0B08);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0B10);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0B18);

INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0B20);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0B28);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0B30);
INCLUDE_ASM("asm/nonmatchings/CLayoutRes", func_001B8CB0);

s32 CLayoutResSub1B8748::Init() {
    m_numParts = Func1B96F0(0);
    m_parts = (CLayoutPart *)Func248CC8(m_numParts * sizeof(CLayoutPart), 1, 1);
    Func1B96F0(m_parts);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CLayoutRes", Func1B96F0__19CLayoutResSub1B8748Pv);

void *CLayoutResSub1B8748::CopyFrom(CPushBuf *b) {
    s32 n = b->Func248EB0();
    if (n <= 0) {
        return 0;
    }
    void *p = Func248CC8(n, 0, 1);
    b->Func248EE0(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CLayoutRes", func_001B9930);

INCLUDE_ASM("asm/nonmatchings/CLayoutRes", func_001B9A30);

void CLayoutResSub1B8748::Release() {
    Func248E00();
    if (m_unkC) {
        D_002B91B0((void *)m_unkC);
        m_unkC = 0;
    }
    Clear();
}

CLayoutEntry *CLayoutResSub1B8748::Find(const char *name) {
    s32 i;
    for (i = 0; i < m_count; i++) {
        if (strcmp(m_entries[i].m_name, name) == 0) {
            return &m_entries[i];
        }
    }
    return 0;
}

CLayoutPart *CLayoutResSub1B8748::GetPart(s32 i) {
    if (i < 0 || i > m_numParts - 1) {
        return 0;
    }
    return &m_parts[i];
}

s32 CLayoutResSub1B8748::ReadInts(const char *key, s32 *out, s32 n) {
    char buf[0x100];
    if (!m_unkC) {
        return 0;
    }
    const char *p = Func24AF10((void *)m_unkC, key);
    if (*p == 0) {
        return 0;
    }
    s32 i;
    for (i = 0; i < n; i++) {
        p = Func24AFE8(p, buf, 1, 0x100);
        out[i] = Func289140(buf);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CLayoutRes", func_001B9CE8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0BD8);
