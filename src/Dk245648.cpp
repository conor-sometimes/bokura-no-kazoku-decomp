#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
s32 Func235DE0(const char *fmt, ...);
extern "C" s32 func_001F1180();
extern "C" void func_001F1190();
extern "C" void func_001F11C8();
extern "C" s32 func_001F15F0();
extern "C" void func_001F1610();
extern "C" void *memset(void *d, int c, unsigned int n);
extern "C" char *strcpy(char *d, const char *s);
extern "C" long atol(const char *s);
extern "C" s32 func_00235648(char *buf, const char *sec, const char *key);
extern void *(*D_002B91A4)(u32 n);
extern void *(*D_002B91A8)(u32 n);
extern void (*D_002B91B0)(void *p);
extern s32 D_002B9E18[];
struct CMemHeap;
struct CMemNode;
struct CMemBlk {
    CMemNode *m_node;         // 0x0
    s32 m_size;               // 0x4
    s32 m_req;                // 0x8
    s32 m_tag;                // 0xC
};
struct CMemNode {
    CMemBlk *m_blk;           // 0x0
    CMemNode *m_prev;         // 0x4
    CMemNode *m_next;         // 0x8
    CMemHeap *m_heap;         // 0xC
};
struct CMemHeap {
    CMemNode *m_nodes;        // 0x00
    s32 m_numNodes;           // 0x04
    s32 m_usedNodes;          // 0x08
    s32 m_liveNodes;          // 0x0C
    u8 *m_data;               // 0x10
    s32 m_size;               // 0x14
    s32 m_used;               // 0x18
    s32 m_tag;                // 0x1C
    CMemNode m_list;          // 0x20
    CMemNode m_free;          // 0x30
    CMemNode *m_first;        // 0x40
    CMemNode *m_last;         // 0x44
    s32 m_count;              // 0x48
    s32 m_magic;              // 0x4C
};
struct CMemSlot { CMemHeap *m_heap; s32 m_used; };
struct CMemGlobal {
    CMemSlot m_slot[2];       // 0x00
    s32 m_flags;              // 0x10
    f32 m_ratio[2];           // 0x14
    s32 m_lo;                 // 0x1C
    s32 m_hi;                 // 0x20
};
extern CMemGlobal D_38F188;
typedef void *(*MallocFn)(u32);
typedef void *(*MemalignFn)(u32);
typedef void (*ReallocFn)(void *, s32);
typedef void (*FreeFn)(void *);
extern MallocFn D_002B9E20[];
extern MallocFn D_002B9E28[];
extern ReallocFn D_002B9E30[];
extern FreeFn D_002B9E38[];
extern "C" void *func_00246B98(u32 n);
extern "C" void *func_00246BD8(u32 n);
extern "C" void func_00246E00(void *p, s32 n);
extern "C" void func_00246FF0(void *p);
extern "C" void func_00233E08(void *f);
extern "C" void func_00233E38(void *f);
extern "C" void func_00233E68(void *f);
extern "C" void func_00233E98(void *f);
extern "C" void *func_002468F8(s32 mode, s32 size);
extern "C" void *func_00246568(u32 n);
extern "C" void *func_002465B0(u32 n);
extern "C" void func_002465F8(void *p, u32 n);
void *Func245D00(int n);
extern "C" void func_00246650(void *p);

extern "C" void func_001F15F0v() asm("func_001F15F0");
#include "CBgWork.h"
extern "C" s32 func_001F1BD8(s32 a);
extern "C" void func_001F0C60(void (*fn)(void *), s32 a, s32 b, s32 c);
class CBgTarget {
public:
    virtual ~CBgTarget();
};
typedef s32 (CBgTarget::*BgFunc)(s32);
struct CBgEntry {
    s32 m_id;                 // 0x0
    CBgTarget *m_obj;         // 0x4
    BgFunc m_func;            // 0x8
    s32 *m_result;            // 0x10
    s32 m_arg;                // 0x14
};
class IBgMgr {
public:
    virtual void Release();
};
class CBgMgr : public IBgMgr {
public:
    CBgMgr();
    virtual void Release();
    virtual s32 Push(CBgTarget *obj, BgFunc f, s32 *result, s32 arg);
    virtual s32 Wait(s32 id, s32 wait);
    virtual void Run();
    virtual ~CBgMgr();

    CBgEntry m_entries[256];  // 0x4
    s32 m_write;              // 0x1804
    s32 m_read;               // 0x1808
    s32 m_count;              // 0x180C
    s32 m_nextId;             // 0x1810
    s32 m_done;               // 0x1814
};
extern CBgMgr *D_002B9E10;
extern "C" void func_00245930(void *);
inline u8 *BlkData(CMemBlk *b) { return (u8 *)(b + 1); }
inline CMemBlk *DataBlk(u8 *p) { return (CMemBlk *)p - 1; }
extern const char D_002E5F70[];
extern const char D_002E5F98[];
extern const char D_002E5FC0[];
extern const char D_002E5FE8[];
extern const char D_002E6010[];
extern const char D_002E6038[];
extern const char D_002E6060[];
extern const char D_002E6088[];
extern const char D_002E60B0[];
extern const char D_002E60D8[];
extern "C" CMemNode *func_00245E18(CMemHeap *h);
extern "C" void func_00245ED0(CMemNode *n);
extern "C" CMemNode *func_00246698(CMemHeap *h);
extern "C" CMemNode *func_002466E8(s32 mode, CMemNode *n, s32 size);
extern "C" void func_00246858(CMemHeap *h);
extern "C" CMemBlk *func_00246C18(void *p);
extern "C" CMemNode *func_00246CF0(CMemNode *n);
extern "C" void func_00246DB0(CMemNode *n);
inline void NodeUnlink(CMemNode *n) {
    n->m_prev->m_next = n->m_next;
    n->m_next->m_prev = n->m_prev;
}
#define NODE_INSERT_AFTER(head, n) \
    (n)->m_prev = &(head); \
    (n)->m_next = (head).m_next; \
    (n)->m_prev->m_next = (n); \
    (n)->m_next->m_prev = (n);
inline void NodeInsertAfter(CMemNode *at, CMemNode *n) {
    n->m_prev = at;
    n->m_next = at->m_next;
    at->m_next = n;
    n->m_next->m_prev = n;
}
inline void NodeInsertBefore(CMemNode *at, CMemNode *n) {
    n->m_next = at;
    n->m_prev = at->m_prev;
    n->m_prev->m_next = n;
    n->m_next->m_prev = n;
}

extern "C" void *func_00245CA0(void *(*fn)(u32), s32 n);
class CHeapObj {
public:
    static void *operator new(unsigned int n);
};

inline void Y1ListInit(CMemNode *l) { l->m_prev = l; l->m_next = l; }
inline void Y1ListIns(CMemNode *l, CMemNode *n) { n->m_prev = l; n->m_next = l->m_next; l->m_next = n; n->m_next->m_prev = n; }
// @decl-end

extern "C" void *__builtin_new(u32 n) {
    return (*D_002B91A4)(n < 4 ? 4 : n);
}

extern "C" void *__builtin_vec_new(u32 n) {
    return (*D_002B91A4)(n < 4 ? 4 : n);
}

extern "C" void __builtin_delete(void *p) {
    if (p) (*D_002B91B0)(p);
}

extern "C" void __builtin_vec_delete(void *p) {
    if (p) (*D_002B91B0)(p);
}

CBgWork::CBgWork() {
    m_unk0 = -1;
    m_unk4 = 0;
}

CBgWork::~CBgWork() {
    if (m_unk0 >= 0) {
        Func235DE0("warning : BG is working ...\n");
        func_00245818(this, 1);
        Func235DE0("warning : finish\n");
    }
}
INCLUDE_RODATA("asm/nonmatchings/Dk245648", D_002E5F50);
INCLUDE_RODATA("asm/nonmatchings/Dk245648", D_002E5F60);
INCLUDE_RODATA("asm/nonmatchings/Dk245648", D_002E5F68);
INCLUDE_RODATA("asm/nonmatchings/Dk245648", D_002E5F70);

extern "C" void func_002457A0(CBgWork *w, CBgTarget *obj, BgFunc f, s32 arg) {
    func_00245818(w, 1);
    w->m_unk0 = D_002B9E10->Push(obj, f, &w->m_unk4, arg);
}

extern "C" int func_00245818(void *p, s32 wait) {
    CBgWork *w = (CBgWork *)p;
    s32 r;
    if (w->m_unk0 < 0) return 0;
    r = D_002B9E10->Wait(w->m_unk0, wait);
    if (!r) w->m_unk0 = -1;
    return r;
}

extern "C" CBgMgr *func_00245880() {
    return new CBgMgr;
}

CBgMgr::CBgMgr() {
    D_002B9E10 = this;
    m_done = -1;
    m_read = 0;
    m_count = 0;
    m_nextId = 0;
    m_write = 0;
}

CBgMgr::~CBgMgr() {
    if (D_002B9E10 == this) D_002B9E10 = 0;
}

extern "C" void func_00245930(void *) {
    D_002B9E10->Run();
}

s32 CBgMgr::Push(CBgTarget *obj, BgFunc f, s32 *result, s32 arg) {
    if (m_count >= 0x100) return -1;
    CBgEntry *e = &m_entries[m_write];
    s32 id = m_nextId;
    e->m_obj = obj;
    e->m_func = f;
    e->m_result = result;
    e->m_arg = arg;
    e->m_id = id;
    m_write = (m_write + 1) % 0x100;
    m_count++;
    m_nextId++;
    if (m_count < 2) func_001F0C60(func_00245930, 0, 0, 0);
    return id;
}

s32 CBgMgr::Wait(s32 id, s32 wait) {
    s32 r;
    do {
        r = (id < 0 ? 0 < m_count : m_done < id);
        if (r && wait) func_001F1BD8(0);
    } while (r && wait);
    return r;
}

void CBgMgr::Run() {
    while (m_count > 0) {
        CBgEntry *e = &m_entries[m_read];
        BgFunc f = e->m_func;
        CBgTarget *obj = e->m_obj;
        s32 id = e->m_id;
        s32 arg = e->m_arg;
        s32 r = (obj->*f)(arg);
        if (e->m_result) *e->m_result = r;
        m_read = (m_read + 1) % 0x100;
        func_001F15F0v();
        m_count--;
        m_done = id;
        func_001F1610();
    }
}

extern "C" void func_00245BF0(char *buf, const char *sec, const char *key, const char *def) {
    buf[0] = 0;
    func_00235648(buf, sec, key);
    if (buf[0] == 0) strcpy(buf, def);
}

extern "C" s32 func_00245C40(const char *sec, const char *key, s32 def) {
    char buf[0x100];
    buf[0] = 0;
    func_00235648(buf, sec, key);
    if (buf[0] == 0) return def;
    return atol(buf);
}

extern "C" void *func_00245CA0(void *(*fn)(u32), s32 n) {
    if (n <= 0 && D_002B9E18[func_001F1180()] == 0) return 0;
    return fn(n);
}

void *Func245D00(int n) {
    return func_00245CA0(D_002B91A4, n);
}

void *CHeapObj::operator new(unsigned int n) {
    return func_00245CA0(D_002B91A8, n);
}

extern "C" s32 func_00245D40(s32 v) {
    s32 old = D_002B9E18[func_001F1180()] != 0;
    D_002B9E18[func_001F1180()] = v;
    return old;
}

asm(".p2align 3");
extern "C" s32 func_00245DA0() {
    return D_002B9E18[func_001F1180()] != 0;
}

extern "C" void *func_00245DD0(u32 n) {
    void *p = Func245D00(n);
    if (!p) return 0;
    memset(p, 0, n);
    return p;
}

extern "C" CMemNode *func_00245E18(CMemHeap *h) {
    CMemNode *n = h->m_free.m_next;
    if (n != &h->m_free) {
        NodeUnlink(n);
    } else {
        if (h->m_numNodes <= h->m_usedNodes) return 0;
        n = &h->m_nodes[h->m_usedNodes++];
    }
    h->m_liveNodes++;
    if (h->m_usedNodes < h->m_liveNodes) {
        if (D_38F188.m_flags & 4) Func235DE0(D_002E5F70, 0x6D);
    }
    return n;
}

extern "C" void func_00245ED0(CMemNode *n) {
    n->m_blk = 0;
    CMemHeap *h = n->m_heap;
    n->m_heap = 0;
    NodeUnlink(n);
    NODE_INSERT_AFTER(h->m_free, n);
    h->m_liveNodes--;
    if (h->m_liveNodes < 0) {
        if (D_38F188.m_flags & 4) Func235DE0(D_002E5F70, 0x88);
    }
}

extern "C" void func_00245F58() {
    CMemGlobal *g = &D_38F188;
    memset(g, 0, sizeof(CMemGlobal));
    g->m_ratio[0] = 0.75f;
    g->m_ratio[1] = 0.75f;
    g->m_flags = 7;
    g->m_lo = 0x7FFFFFFF;
    g->m_hi = 0;
}

extern "C" void func_00245FB8(void) {
}

extern "C" void func_00245FC0() {
    func_00233E08((void *)func_00246568);
    func_00233E38((void *)func_002465B0);
    func_00233E68((void *)func_002465F8);
    func_00233E98((void *)func_00246650);
}

extern "C" s32 func_00246008() { return D_38F188.m_lo; }

extern "C" s32 func_00246018() { return D_38F188.m_hi; }

extern "C" s32 func_00246028(s32 v) {
    CMemGlobal *g = &D_38F188;
    s32 old = g->m_flags;
    g->m_flags = v;
    return old;
}

extern "C" s32 func_00246040() { return D_38F188.m_flags; }

extern "C" CMemHeap *func_00246050(s32 i, CMemHeap *h) {
    CMemHeap *old = D_38F188.m_slot[i].m_heap;
    D_38F188.m_slot[i].m_heap = h;
    return old;
}

asm(".p2align 3");
extern "C" CMemHeap *func_00246070(s32 i) { return D_38F188.m_slot[i].m_heap; }

extern "C" CMemHeap *func_00246088(CMemHeap *h) {
    CMemSlot *s = &D_38F188.m_slot[func_001F1180()];
    CMemHeap *old = s->m_heap;
    s->m_heap = h;
    return old;
}

extern "C" CMemHeap *func_002460C8() { return D_38F188.m_slot[func_001F1180()].m_heap; }

extern "C" CMemHeap *func_00246100(void *mem, s32 size, s32 nodes)
{
    CMemHeap *h = (CMemHeap *)mem;
    u8 *end;
    CMemBlk *b;
    CMemNode *n, *nd;
    s32 dsize;
    if (!h || size < 0x50 || nodes <= 0) {
        if (D_38F188.m_flags & 4) Func235DE0("*** memheap : invalid arg %X, %d, %d\n", h, size, nodes);
        return 0;
    }
    memset(h, 0, 0x50);
    nd = (CMemNode *)(h + 1);
    end = (u8 *)h + size;
    b = (CMemBlk *)(((u32)(nd + nodes) + 15) & ~15);
    dsize = (end - (u8 *)b) & ~15;
    h->m_usedNodes = 0;
    h->m_list.m_prev = &h->m_list;
    h->m_list.m_next = &h->m_list;
    h->m_free.m_prev = &h->m_free;
    h->m_data = (u8 *)b;
    h->m_size = dsize;
    h->m_used = 0;
    h->m_count = 0;
    h->m_magic = 0x484D454D;
    h->m_free.m_next = &h->m_free;
    h->m_nodes = nd;
    h->m_numNodes = nodes;
    if (dsize <= 0) {
        if (D_38F188.m_flags & 4) Func235DE0("*** memheap : underflow size (%d)\n", dsize);
        return 0;
    }
    b->m_req = 0;
    b->m_size = dsize - 16;
    b->m_tag = h->m_tag;
    h->m_used += 16;
    n = func_00245E18(h);
    b->m_node = n;
    n->m_blk = b;
    n->m_heap = h;
    { CMemNode *l = &h->m_list; n->m_prev = l; n->m_next = h->m_list.m_next; l->m_next = n; n->m_next->m_prev = n; }

    h->m_first = n;
    h->m_last = n;
    {
        CMemGlobal *g = &D_38F188;
        g->m_lo = g->m_lo < (s32)h ? g->m_lo : (s32)h;
        g->m_hi = (s32)end < g->m_hi ? g->m_hi : (s32)end;
    }
    return h;
}
INCLUDE_RODATA("asm/nonmatchings/Dk245648", D_002E5FE8);

extern "C" s32 func_002462B0() {
    CMemHeap *h = D_38F188.m_slot[func_001F1180()].m_heap;
    if (!h) return 0;
    return h->m_size - h->m_used;
}

extern "C" s32 func_002462F8() {
    CMemHeap *h = D_38F188.m_slot[func_001F1180()].m_heap;
    if (!h) return 0;
    return h->m_count;
}

extern "C" s32 func_00246338(s32 v) {
    CMemHeap *h = D_38F188.m_slot[func_001F1180()].m_heap;
    if (!h) return 0;
    s32 old = h->m_tag;
    h->m_tag = v;
    return old;
}

extern "C" s32 func_00246388() {
    CMemHeap *h = D_38F188.m_slot[func_001F1180()].m_heap;
    if (!h) return 0;
    return h->m_tag;
}

extern "C" MallocFn func_002463C8(MallocFn f) {
    MallocFn old = D_002B9E20[func_001F1180()];
    D_002B9E20[func_001F1180()] = f ? f : func_00246B98;
    return old;
}

extern "C" MallocFn func_00246430(MallocFn f) {
    MallocFn old = D_002B9E28[func_001F1180()];
    D_002B9E28[func_001F1180()] = f ? f : func_00246BD8;
    return old;
}

extern "C" ReallocFn func_00246498(ReallocFn f) {
    ReallocFn old = D_002B9E30[func_001F1180()];
    D_002B9E30[func_001F1180()] = f ? f : func_00246E00;
    return old;
}

extern "C" FreeFn func_00246500(FreeFn f) {
    FreeFn old = D_002B9E38[func_001F1180()];
    D_002B9E38[func_001F1180()] = f ? f : func_00246FF0;
    return old;
}

extern "C" void *func_00246568(u32 n) { return D_002B9E20[func_001F1180()](n); }

extern "C" void *func_002465B0(u32 n) { return D_002B9E28[func_001F1180()](n); }

extern "C" void func_002465F8(void *p, u32 n) { D_002B9E30[func_001F1180()](p, n); }

extern "C" void func_00246650(void *p) { D_002B9E38[func_001F1180()](p); }

extern "C" CMemNode *func_00246698(CMemHeap *h) {
    s32 best = 0;
    CMemNode *bn = 0;
    CMemNode *n;
    for (n = h->m_first; n != &h->m_list; n = n->m_next) {
        CMemBlk *b = n->m_blk;
        if (best < b->m_size && b->m_req == 0) {
            best = b->m_size;
            bn = n;
        }
        if (n == h->m_last) break;
    }
    return bn;
}

extern "C" CMemNode *func_002466E8(s32 mode, CMemNode *n, s32 size) {
    CMemHeap *h = n->m_heap;
    CMemNode *nn = func_00245E18(h);
    CMemBlk *nb;
    if (!nn) {
        if (D_38F188.m_flags & 2) Func235DE0(D_002E5FE8, size);
        return 0;
    }
    if (mode == 0) {
        nb = (CMemBlk *)(BlkData(n->m_blk) + size);
        nb->m_node = n;
        nb->m_size = n->m_blk->m_size - size - 16;
    } else if (mode != 1) {
        nb = (CMemBlk *)(BlkData(n->m_blk) + size);
        nb->m_node = n;
        nb->m_size = n->m_blk->m_size - size - 16;
    } else {
        nb = DataBlk(BlkData(n->m_blk) + n->m_blk->m_size - size);
        nb->m_size = size;
        nb->m_node = nn;
    }
    nb->m_req = 0;
    nb->m_tag = 0;
    n->m_blk->m_size = n->m_blk->m_size - nb->m_size - 16;
    h->m_used += 16;
    if (mode == 0) {
        nn->m_blk = n->m_blk;
        nn->m_heap = h;
        nn->m_prev = n->m_prev;
        nn->m_next = n;
        nn->m_prev->m_next = nn;
        nn->m_next->m_prev = nn;
        n->m_blk = nb;
    } else if (mode != 1) {
        nn->m_blk = n->m_blk;
        nn->m_heap = h;
        nn->m_prev = n->m_prev;
        nn->m_next = n;
        nn->m_prev->m_next = nn;
        nn->m_next->m_prev = nn;
        n->m_blk = nb;
    } else {
        nn->m_blk = nb;
        nn->m_heap = h;
        NodeInsertAfter(n, nn);
    }
    n->m_blk->m_node = n;
    nn->m_blk->m_node = nn;
    return nn;
}

extern "C" void func_00246858(CMemHeap *h) {
    CMemNode *n;
    if (h->m_first) {
        n = h->m_first;
        h->m_first = 0;
        for (; n != &h->m_list; n = n->m_next) {
            if (n->m_blk->m_req == 0) {
                h->m_first = n;
                break;
            }
            if (n == h->m_last) break;
        }
        if (!h->m_first) h->m_last = 0;
    }
    if (h->m_last) {
        n = h->m_last;
        h->m_last = 0;
        for (; n != &h->m_list; n = n->m_prev) {
            if (n->m_blk->m_req == 0) {
                h->m_last = n;
                break;
            }
            if (n == h->m_first) break;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/Dk245648", func_002468F8);

extern "C" void *func_00246B98(u32 n) {
    func_001F1190();
    void *p = func_002468F8(0, n);
    func_001F11C8();
    return p;
}

extern "C" void *func_00246BD8(u32 n) {
    func_001F1190();
    void *p = func_002468F8(1, n);
    func_001F11C8();
    return p;
}

INCLUDE_ASM("asm/nonmatchings/Dk245648", func_00246C18);
INCLUDE_RODATA("asm/nonmatchings/Dk245648", D_002E60B0);
INCLUDE_RODATA("asm/nonmatchings/Dk245648", D_002E60D8);

extern "C" CMemNode *func_00246CF0(CMemNode *n) {
    CMemHeap *h = n->m_heap;
    CMemNode *nx = n->m_next;
    CMemBlk *b = n->m_blk;
    CMemBlk *nb = nx->m_blk;
    if (nx == &h->m_list || nb->m_req != 0) {
        if (D_38F188.m_flags & 4) Func235DE0(D_002E60B0, 0x312);
        return n;
    }
    b->m_size += nb->m_size + 16;
    nb->m_node = 0;
    nb->m_size = 0;
    nb->m_req = 0;
    nb->m_tag = 0;
    h->m_used -= 16;
    if (h->m_first == nx) h->m_first = n;
    if (h->m_last == nx) h->m_last = n;
    func_00245ED0(nx);
    return n;
}

extern "C" void func_00246DB0(CMemNode *n) {
    CMemHeap *h = n->m_heap;
    if (!h->m_first || (s32)n->m_blk < (s32)h->m_first->m_blk) h->m_first = n;
    if (!h->m_last || (s32)h->m_last->m_blk < (s32)n->m_blk) h->m_last = n;
}

extern "C" void func_00246E00(void *p, s32 size) {
    CMemBlk *b = func_00246C18(p);
    if (!b) return;
    if (size <= 0) return func_00246650(p);
    if (b->m_req < size) {
        if (D_38F188.m_flags & 4) return (void)Func235DE0(D_002E60D8, b->m_req, size);
        return;
    }
    func_001F1190();
    CMemNode *n = b->m_node;
    s32 asize = (size + 15) & ~15;
    CMemHeap *h = n->m_heap;
    h->m_used -= b->m_size;
    h->m_count -= b->m_req;
    D_38F188.m_slot[func_001F1180()].m_used -= b->m_size;
    if (asize + 16 < b->m_size) {
        n = func_002466E8(0, n, asize);
        if (!n) goto out;
        b = n->m_blk;
        CMemNode *nx = n->m_next;
        if (nx->m_next != &h->m_list && nx->m_next->m_blk->m_req == 0) nx = func_00246CF0(nx);
        func_00246DB0(nx);
    }
    b->m_req = size;
    b->m_tag = h->m_tag;
    h->m_used += b->m_size;
    h->m_count += b->m_req;
    D_38F188.m_slot[func_001F1180()].m_used += b->m_size;
out:
    func_001F11C8();
}

extern "C" void func_00246FF0(void *p) {
    if (!p) return;
    CMemBlk *b = func_00246C18(p);
    if (!b) return;
    CMemNode *n = b->m_node;
    CMemHeap *h = n->m_heap;
    h->m_used -= b->m_size;
    h->m_count -= b->m_req;
    D_38F188.m_slot[func_001F1180()].m_used -= b->m_size;
    b->m_req = 0;
    b->m_tag = 0;
    if (n->m_prev != &h->m_list && n->m_prev->m_blk->m_req == 0) n = func_00246CF0(n->m_prev);
    if (n->m_next != &h->m_list && n->m_next->m_blk->m_req == 0) n = func_00246CF0(n);
    func_00246DB0(n);
}
