#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMapObjSub11B070 {
public:
    u8 pad0[0x10];
    s32 m_count;              // 0x10
    u8 pad14[0x8];
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
};
struct CMapObjEntry {
    s32 m_unk0;               // 0x0
    s32 m_unk4;               // 0x4
    s32 m_unk8;               // 0x8
    s32 m_flag;               // 0xC
};
class CMapSndObj {
public:
    CMapSndObj();
    virtual ~CMapSndObj();
    void ClearUnk4();
    void SetUnk4(s32 v);

    s32 m_unk0;               // 0x0
    s32 m_unk4;               // 0x4
};
// CMapEffObj.cpp: vptr after its four fields.
class CMapEffObj {
public:
    CMapEffObj();
    virtual ~CMapEffObj();
    void EnableAll();
    void Release();
    int Load(void *list);

    s32 m_unk0;               // 0x0
    s32 m_unk4;               // 0x4
    s32 m_unk8;               // 0x8
    s32 m_unkC;               // 0xC
};
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMapObj, its only
// virtual. The vptr follows its fields at 0x30.
class CMapObj {
public:
    CMapObj();
    virtual ~CMapObj();
    s32 GetFlag11B030(s32 i);
    void Func11AF60();
    void SetFlag11B070(s32 i);
    void Init11AF00(CMapObjSub11B070 *d);
    void ClearEntry11B0B0(s32 i);
    void Release11AFB8();
    CMapObjSub11B070 *m_unk0; // 0x0
    CMapEffObj *m_unk4;       // 0x4
    CMapSndObj *m_unk8;       // 0x8
    CMapObjEntry *m_entries;  // 0xC
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    u8 pad18[0x8];
    s32 m_unk20;              // 0x20
    s32 m_unk24;              // 0x24
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
};

extern "C" void *func_00245DD0(s32 size);
extern "C" void func_001281B8(void *p);

extern void (*D_002B91B0)(void *p);

extern "C" s32 func_0011B268(s32 psm);
extern "C" void func_00227BF0(u64 tex, s32 a, s32 b, s32 w, s32 h, u8 *src);

extern "C" void func_001EFF48(u64 tex, s32 a, s32 b, s32 w, s32 h, u8 *src, s32 k);
// @decl-end

CMapObj::CMapObj() {
    m_unk20 = 0x80;
    m_unk24 = 0x80;
    m_unk28 = 0x80;
    m_unk2C = 0x80;
    m_unk0 = 0;
    m_entries = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk4 = new CMapEffObj;
    m_unk8 = new CMapSndObj;
}

CMapObj::~CMapObj() {
    Func11AF60();
    if (m_unk8) {
        delete m_unk8;
    }
    if (m_unk4) {
        delete m_unk4;
    }
}

void CMapObj::Init11AF00(CMapObjSub11B070 *d) {
    Func11AF60();
    m_unk0 = d;
    m_entries = (CMapObjEntry *)func_00245DD0(d->m_count * 16);
    m_unk4->Load((void *)d->m_unk1C);
    m_unk8->SetUnk4(d->m_unk20);
}

void CMapObj::Func11AF60() {
    m_unk8->ClearUnk4();
    m_unk4->Release();
    if (m_entries) {
        D_002B91B0(m_entries);
        m_entries = 0;
    }
    m_unk0 = 0;
}

void CMapObj::Release11AFB8() {
    if (m_unk0) {
        for (s32 i = 0; i < m_unk0->m_count; i++) {
            ClearEntry11B0B0(i);
        }
    }
    m_unk4->EnableAll();
    func_001281B8(m_unk8);
}

s32 CMapObj::GetFlag11B030(s32 i) {
    if (m_unk0 == 0 || i < 0 || i > m_unk0->m_count - 1) return 0;
    return m_entries[i].m_flag;
}

void CMapObj::SetFlag11B070(s32 i) {
    if (m_unk0 == 0) return;
    if (i < 0 || i > m_unk0->m_count - 1) return;
    m_entries[i].m_flag = 1;
}

void CMapObj::ClearEntry11B0B0(s32 i) {
    if (m_unk0 == 0) return;
    if (i < 0 || i > m_unk0->m_count - 1) return;
    m_entries[i].m_unk0 = 0;
    m_entries[i].m_unk4 = 0;
    m_entries[i].m_unk8 = 0;
    m_entries[i].m_flag = 0;
}

INCLUDE_ASM("asm/nonmatchings/CMapObj", Func11B118__9CSndOwnerPvi);

INCLUDE_RODATA("asm/nonmatchings/CMapObj", D_002D3D88);
INCLUDE_ASM("asm/nonmatchings/CMapObj", func_0011B268);

void Blit11B2C0(u64 tex, s32 a, s32 b, s32 w, s32 y, s32 h, u8 *base) {
    func_00227BF0(tex, a, b, w, h, base + y * func_0011B268((s32)((tex >> 32) & 0x3F)) * w / 8);
}

void Blit11B370(u64 tex, s32 a, s32 b, s32 w, s32 y, s32 h, u8 *base) {
    func_001EFF48(tex, a, b, w, h, base + y * func_0011B268((s32)((tex >> 32) & 0x3F)) * w / 8, 0);
}

INCLUDE_ASM("asm/nonmatchings/CMapObj", func_0011B428);
