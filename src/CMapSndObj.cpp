#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMapSndObj, its
// only virtual. The vptr follows its fields at 0x8.
class CMapSndObj {
public:
    CMapSndObj();
    virtual ~CMapSndObj();
    int SetUnk4(s32 v);
    void ClearUnk4();

    s32 m_unk0;               // 0x0
    s32 m_unk4;               // 0x4
};

//@sym strcmp 0x28B190
#include "libc.h"
extern const char *D_002A0B90[];
s32 Func24E0F0(const char *a, s32 b, s32 c);
class CMapSndEntry {
public:
    u8 pad0[0x40];
    char m_name[0x100];       // 0x40
    s32 m_unk140;             // 0x140
    u8 pad144[0xC];
};
// @decl-end

CMapSndObj::CMapSndObj() {
    m_unk0 = 1;
    m_unk4 = 0;
}

CMapSndObj::~CMapSndObj() {
    ClearUnk4();
}

int CMapSndObj::SetUnk4(s32 v) {
    m_unk4 = v;
    return 1;
}

void CMapSndObj::ClearUnk4() {
    if (m_unk4) {
        m_unk4 = 0;
    }
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001281B8() {
}

s32 FindMapSndName(const char *name) {
    s32 i;
    for (i = 0; D_002A0B90[i]; i++) {
        if (strcmp(D_002A0B90[i], name) == 0) {
            return i;
        }
    }
    return 5;
}

INCLUDE_RODATA("asm/nonmatchings/CMapSndObj", D_002D4C38);
INCLUDE_RODATA("asm/nonmatchings/CMapSndObj", D_002D4C40);
INCLUDE_RODATA("asm/nonmatchings/CMapSndObj", D_002D4C48);
INCLUDE_RODATA("asm/nonmatchings/CMapSndObj", D_002D4C50);
INCLUDE_RODATA("asm/nonmatchings/CMapSndObj", D_002D4C58);
INCLUDE_RODATA("asm/nonmatchings/CMapSndObj", D_002D4C60);
INCLUDE_ASM("asm/nonmatchings/CMapSndObj", func_00128238);
INCLUDE_RODATA("asm/nonmatchings/CMapSndObj", D_002D4C78);
INCLUDE_RODATA("asm/nonmatchings/CMapSndObj", D_002D4C80);
INCLUDE_RODATA("asm/nonmatchings/CMapSndObj", D_002D4C88);
INCLUDE_RODATA("asm/nonmatchings/CMapSndObj", jtbl_002D4C90);

CMapSndEntry *FindMapSndEntry(CMapSndEntry *e, s32 n, s32 key) {
    s32 i;
    for (i = 0; i < n; i++) {
        CMapSndEntry *p = &e[i];
        if (Func24E0F0(p->m_name, p->m_unk140, key)) {
            return p;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CMapSndObj", func_00128528);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00128868() {
}
