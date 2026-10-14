#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct CResortDBEntry20 {
    u8 data[0x14];
};
#include "CPushBuf.h"
struct CResortDBEntry;
struct CResortRec30 {
    s32 m_id;                 // 0x0
    s32 m4;                   // 0x4
    s32 m8;                   // 0x8
    u8 padC[0x24];
};
struct CResortRecC {
    s32 m_id;                 // 0x0
    u8 pad4[0x8];
};
struct CResortNameRec {
    const char *m_name;       // 0x0
    s32 *m_values;            // 0x4
    u8 pad8[0x4];
};
int Func1456A8(int v);
const char *Func24ADE0(const char *p, char *buf, int n);
// Interface without fields (its RTTI name only): the vptr is at 0.
class IResortDBMgr {
public:
    virtual void Release() = 0;
    virtual int Func171DE8() = 0;
    virtual void Init() = 0;
    virtual struct CResortRec30 *Func172920(s32 id) = 0;
    virtual int Func172968() = 0;
    virtual int Func29A3F0() = 0;
    virtual int Func29A430() = 0;
    virtual int Func172A60(const char *name, s32 a, s32 b) = 0;
    virtual int Func172B28(s32 id) = 0;
    virtual struct CResortRecC *Func172B68(s32 id) = 0;
    virtual CResortDBEntry *GetEntryA(s32 i) = 0;
    virtual CResortDBEntry20 *GetEntryC(s32 i) = 0;
    virtual CResortDBEntry *GetEntryB(s32 i) = 0;
};
// Vtable 0x2C1570: slot 0 is an inline `delete this` (emitted elsewhere), so the key method is
// Func171DE8, not the destructor (slot 13). Slots 5 and 6 are inline too.
class CResortDBMgr : public IResortDBMgr {
public:
    CResortDBMgr();
    virtual void Release() { delete this; }
    virtual int Func171DE8();
    virtual void Init();
    virtual CResortRec30 *Func172920(s32 id);
    virtual int Func172968();
    virtual int Func29A3F0();
    virtual int Func29A430();
    virtual int Func172A60(const char *name, s32 a, s32 b);
    virtual int Func172B28(s32 id);
    virtual CResortRecC *Func172B68(s32 id);
    virtual CResortDBEntry *GetEntryA(s32 i);
    virtual CResortDBEntry20 *GetEntryC(s32 i);
    virtual CResortDBEntry *GetEntryB(s32 i);
    virtual ~CResortDBMgr();
    void Clear();

    CPushBuf m_buf;           // 0x4
    CResortRec30 *m_unk10;    // 0x10
    s32 m_unk14;              // 0x14
    CResortNameRec *m_names;  // 0x18
    s32 m_numNames;           // 0x1C
    CResortRecC *m_recsC;     // 0x20
    s32 m_numC;               // 0x24
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
};

struct CResortDBEntry {
    u8 data[0x10];
};
extern CResortDBEntry D_002A36F0[];
extern CResortDBEntry D_002A3850[];
extern CResortDBMgr *D_002A36E8;

extern CResortDBEntry20 D_002A3760[];
// @decl-end

CResortDBMgr::CResortDBMgr() {
    D_002A36E8 = this;
    Clear();
}

CResortDBMgr::~CResortDBMgr() {
    Init();
    D_002A36E8 = 0;
}

void CResortDBMgr::Clear() {
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk28 = 0;
    m_unk2C = 0;
}

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00171DE8);

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00171EC0);

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00171F68);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA0D8);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA0E0);

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_001722D8);

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00172498);

int CountLines172640(const char *p) {
    s32 n = 0;
    char buf[0x100];
    while ((p = Func24ADE0(p, buf, 0x100), *p) || buf[0]) {
        n++;
    }
    return n;
}

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00172690);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA108);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA118);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA128);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA138);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA148);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA158);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA160);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA170);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA180);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA190);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1A0);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1B0);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1C0);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1D0);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1E0);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1F0);

void CResortDBMgr::Init() {
    m_buf.Func248E00();
    Clear();
}

CResortRec30 *CResortDBMgr::Func172920(s32 id) {
    s32 i;
    for (i = 0; i < m_unk14; i++) {
        if (m_unk10[i].m_id == id) return &m_unk10[i];
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", func_00172968);

// Func172A60: `for (i < m_numNames) if (Func1456A8(name_i) == Func1456A8(name)) { s32 *row =
// e->m_values + a * 2; return row[b]; } return -1;` is DIFF 2: retail adds `a*8 + base` with the
// operands the other way round (tried four commutations).
INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", Func172A60__12CResortDBMgrPCcii);

int CResortDBMgr::Func172B28(s32 id) {
    s32 i;
    for (i = 0; i < m_unk14; i++) {
        if (m_unk10[i].m_id == id) return m_unk10[i].m8;
    }
    return -1;
}

CResortRecC *CResortDBMgr::Func172B68(s32 id) {
    s32 i;
    for (i = 0; i < m_numC; i++) {
        if (m_recsC[i].m_id == id) return &m_recsC[i];
    }
    return 0;
}

CResortDBEntry *CResortDBMgr::GetEntryA(s32 i) {
    if (i < 1 || i > 6) {
        return 0;
    }
    return &D_002A36F0[i];
}

CResortDBEntry20 *CResortDBMgr::GetEntryC(s32 i) {
    if (i < 8 || i > 11) {
        return 0;
    }
    return &D_002A3760[i];
}

CResortDBEntry *CResortDBMgr::GetEntryB(s32 i) {
    if (i < 12 || i > 38) {
        return 0;
    }
    return &D_002A3850[i];
}
