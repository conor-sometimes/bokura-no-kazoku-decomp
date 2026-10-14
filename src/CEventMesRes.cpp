#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym strcmp 0x28B190
#include "libc.h"

class CEvNode {
public:
    s32 m0;                   // 0x0
    CEvNode *m_prev;          // 0x4
    CEvNode *m_next;          // 0x8
};
class CEventMesItem {
public:


    u8 pad0[0x4];
    s32 m_unk4;               // 0x4
    u8 pad8[0x4];
    f32 *m_values;            // 0xC
};
class CEventMesMgr {
public:
    CEventMesItem *Find(s32 id);
    s32 GetItemUnk4(s32 id);
    f32 GetValue(s32 id, s32 idx);
    void Append(CEvNode *n);
    void Remove(CEvNode *n);

    u8 pad0[0x4];
    CEvNode m_head;           // 0x4
};
//@sym Find__12CEventMesMgri 0x13E070

class CPushBuf {
public:
    void Func248E00();
    int Func248EB0();

    u8 m_data[0xC];
};
class CEventMesResSub13DD98 : public CEvNode {
public:
    void Init();
    CEventMesItem *FindItem(s32 id);
    s32 GetName(s32 i);

    u8 padC[0x4];
    CPushBuf m_buf;           // 0x10
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
};

//@sym bsearch 0x289160
extern "C" void *bsearch(const void *key, const void *base, unsigned int n, unsigned int size, int (*cmp)(const void *, const void *));
void *operator new(unsigned int n);
int Func235DE0(const char *fmt, ...);
extern char D_002D5BC8[];
int CompareEventMesNames(const char **a, const char **b);
struct CEventMesKey { s32 id; u8 pad[0xC]; };
class CEventMesRes13DE70 { public: void Init13DE70(); };
CEventMesRes13DE70 *NewEventMesRes13DE70();
inline void EvUnlink(CEvNode *n) { n->m_prev->m_next = n->m_next; n->m_next->m_prev = n->m_prev; n->m_next = n; n->m_prev = n; }
inline void EvInsert(CEvNode *n, CEvNode *h) { CEvNode *p = h->m_prev; n->m_next = h; n->m_prev = p; p->m_next = n; n->m_next->m_prev = n; }
inline CEventMesResSub13DD98 *EvCheck(CEvNode *n) { return n->m0 == 0 ? (CEventMesResSub13DD98 *)n : 0; }
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013D910);

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013D958);

int CompareEventMesNames(const char **a, const char **b) {
    return strcmp(*a, *b);
}

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013DA10);

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013DBF8);

void CEventMesResSub13DD98::Init() {
    m_buf.Func248E00();
    m_unk1C = 0;
    m_unk20 = 0;
}

CEventMesItem *CEventMesResSub13DD98::FindItem(s32 id) {
    CEventMesKey key;
    key.id = id;
    return (CEventMesItem *)bsearch(&key, (void *)m_unk1C, m_unk20, 0x10, (int (*)(const void *, const void *))CompareEventMesNames);
}

s32 CEventMesResSub13DD98::GetName(s32 i) {
    if (m_unk1C && (i < 0 || m_unk20 < i)) return 0;
    return ((s32 *)m_unk1C)[i * 4];
}

CEventMesRes13DE70 *NewEventMesRes13DE70() {
    CEventMesRes13DE70 *p = (CEventMesRes13DE70 *)operator new(0x114);
    p->Init13DE70();
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", Init13DE70__18CEventMesRes13DE70);

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013DEB0);

void CEventMesMgr::Append(CEvNode *n) {
    EvUnlink(n);
    EvInsert(n, &m_head);
}

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013DFF8);

CEventMesItem *CEventMesMgr::Find(s32 id) {
    CEventMesResSub13DD98 *p;
    for (p = EvCheck(m_head.m_next); p; p = EvCheck(p->m_next)) {
        CEventMesItem *r = p->FindItem(id);
        if (r) return r;
    }
    return 0;
}

s32 CEventMesMgr::GetItemUnk4(s32 id) {
    CEventMesItem *p = Find(id);
    if (p) {
        return p->m_unk4;
    }
    return 0;
}

f32 CEventMesMgr::GetValue(s32 id, s32 idx) {
    CEventMesItem *it = Find(id);
    if (!it) return 0.0f;
    if (idx < 0 || it->m_unk4 - 1 < idx) {
        Func235DE0(D_002D5BC8, idx);
        return 0.0f;
    }
    return it->m_values[idx];
}

INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D58B0);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D58C8);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D58E0);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D58E8);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D58F8);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5908);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5918);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5920);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5928);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5930);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5940);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5948);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5950);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5960);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5968);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5970);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5988);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5998);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D59A8);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D59B0);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D59D0);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5A10);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5A18);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5A30);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5A48);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5A58);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5A68);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5A78);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5A80);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5A90);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5AA0);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5AA8);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5AC8);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5B08);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5B28);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5B68);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5B70);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", jtbl_002D5B80);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5B98);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5BB0);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5BB8);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5BC0);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5BC8);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5BF0);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5BF8);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5C00);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5C08);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5C10);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5C18);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5C20);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5C28);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5C30);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5C38);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5C40);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5C48);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5C50);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5C58);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5C68);
INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013E178);

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013E3D0);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5CF0);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5D00);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5D18);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5D28);
INCLUDE_RODATA("asm/nonmatchings/CEventMesRes", D_002D5D48);
