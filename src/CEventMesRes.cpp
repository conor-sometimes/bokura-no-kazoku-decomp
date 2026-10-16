#pragma interface
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

#include "CPushBuf.h"
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

// The resource object proper (vtable _vt$12CEventMesRes; the methods above call it
// CEventMesResSub13DD98 and see the CListTag fields as a CEvNode).
#define CLISTTAG_INLINE_DTOR
#include "CList.h"
class CEventMesRes : public CListTag {
public:
    CEventMesRes();
    virtual ~CEventMesRes();

    CPushBuf m_buf;           // 0x10
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
};

//@sym bsearch 0x289160
extern "C" void *bsearch(const void *key, const void *base, unsigned int n, unsigned int size, int (*cmp)(const void *, const void *));
void *operator new(unsigned int n);
int Func235DE0(const char *fmt, ...) throw();
extern char D_002D5BC8[];
int CompareEventMesNames(const char **a, const char **b);
struct CEventMesKey { s32 id; u8 pad[0xC]; };
class CEventMesRes13DE70 { public: void Init13DE70(); };
CEventMesRes13DE70 *NewEventMesRes13DE70();
inline void EvUnlink(CEvNode *n) { n->m_prev->m_next = n->m_next; n->m_next->m_prev = n->m_prev; n->m_next = n; n->m_prev = n; }
inline void EvInsert(CEvNode *n, CEvNode *h) { CEvNode *p = h->m_prev; n->m_next = h; n->m_prev = p; p->m_next = n; n->m_next->m_prev = n; }
inline CEventMesResSub13DD98 *EvCheck(CEvNode *n) { return n->m0 == 0 ? (CEventMesResSub13DD98 *)n : 0; }

struct EvTag { s32 isHead; EvTag *prev; EvTag *next; void *vptr; };
extern u8 EvMgr_vt[] asm("_vt$12CEventMesMgr");
extern u8 EvTList_vt[] asm("_vt$t5TList1Z12CEventMesRes");
extern u8 EvCList_vt[] asm("_vt$5CList");
extern u8 EvCListTag_vt[] asm("_vt$8CListTag");
extern void *D_002A0CE0;
extern "C" void __builtin_delete(void *);
static inline EvTag *EvFirst(EvTag *l) { EvTag *n = l->next; return n->isHead ? 0 : n; }
static inline EvTag *EvRemove(EvTag *t) { if (t) { t->prev->next = t->next; t->next->prev = t->prev; t->next = t; t->prev = t; } return t; }
// @decl-end

CEventMesRes::CEventMesRes() {
    m_unk1C = 0;
    m_unk20 = 0;
}

// Key method: #pragma interface (top) keeps this unit from emitting the vtables (asm data).
CEventMesRes::~CEventMesRes() {
    ((CEventMesResSub13DD98 *)this)->Init();
}

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

void CEventMesRes13DE70::Init13DE70() {
    EvTag *l = (EvTag *)((u8 *)this + 4);
    *(void **)this = EvMgr_vt;
    l->vptr = EvTList_vt;
    l->isHead = 1;
    l->prev = l;
    l->next = l;
    D_002A0CE0 = this;
    *((u8 *)this + 0x14) = 0;
}

extern "C" void func_0013DEB0(CEventMesMgr *m, s32 flags) {
    EvTag *l = (EvTag *)((u8 *)m + 4);
    *(void **)m = EvMgr_vt;
    while (EvRemove(EvFirst(l)));
    D_002A0CE0 = 0;
    l->vptr = EvCList_vt;
    while (EvRemove(EvFirst(l)));
    l->vptr = EvCListTag_vt;
    l->prev->next = l->next;
    l->next->prev = l->prev;
    l->next = l;
    l->prev = l;
    if (flags & 1) return (void)__builtin_delete(m);
}

void CEventMesMgr::Append(CEvNode *n) {
    EvUnlink(n);
    EvInsert(n, &m_head);
}

void CEventMesMgr::Remove(CEvNode *n) { if (n) EvRemove((EvTag *)n); else while (EvRemove(EvFirst((EvTag *)&m_head))); }

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
