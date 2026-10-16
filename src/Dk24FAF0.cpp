#pragma interface
#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym __7CDebOut 0x251BF0
#include "CBgWork.h"
#include "CList.h"
s32 Func235DE0(const char *fmt, ...);
extern "C" char *strcpy(char *d, const char *s);
extern void (*D_002B91B0)(void *p);
struct CGsGlobal {
    u64 m0;                   // 0x393910
    s32 m8;                   // 0x393918
    s32 mC;                   // 0x39391C
    s32 m10;                  // 0x393920
    s32 m14;                  // 0x393924
    s32 m18;                  // 0x393928
    s32 m1C;                  // 0x39392C
    u64 m20;                  // 0x393930
    s32 m28;                  // 0x393938
    s32 m2C;                  // 0x39393C
    s32 m30;                  // 0x393940
    s32 m34;                  // 0x393944
};
extern CGsGlobal D_393910;
extern u8 D_3936F0[];
extern u8 D_393800[];
extern "C" u64 func_0023C650(void *p);
extern "C" void func_0023C700(void *p, s32 a);
extern "C" void func_0023C6E8(void *p, s32 a, s32 b, s32 c, s32 d);
extern "C" s32 func_0023E9E8(s32 a);
extern "C" void *func_002303C0(const char *name);
extern "C" s32 func_00205A80(void *data);
void Func23B1D0(int h);
class IDebOut {
public:
    virtual void V0();
    virtual s32 Load(const char *name);
    virtual void Release();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
};
class CDebOut : public IDebOut {
public:
    CDebOut();
    virtual void V0();
    virtual s32 Load(const char *name);
    virtual void Release();
    virtual ~CDebOut();

    s32 m4;                   // 0x4
    s32 m8;                   // 0x8
    s32 mC;                   // 0xC
    s32 m10;                  // 0x10
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
    s32 m1C;                  // 0x1C
    s32 m20;                  // 0x20
    s32 m24;                  // 0x24
    s32 m28;                  // 0x28
    f32 m2C;                  // 0x2C
    f32 m30;                  // 0x30
    f32 m34;                  // 0x34
    f32 m38;                  // 0x38
};
extern CDebOut *D_002BA0B0;
extern const char D_002E6AA0[];
extern const char D_002E6AC8[];
struct CMemHeap;
extern "C" CMemHeap *func_00246088(CMemHeap *h);
extern "C" s32 func_002462B0();
extern "C" s32 func_00246028(s32 f);
extern "C" void *func_00246B98(u32 n);
extern "C" void *func_00246BD8(u32 n);
extern "C" CMemHeap *func_00246100(void *mem, s32 size, s32 n);
extern CMemHeap *D_002BA0A0;
extern s32 D_002BA0A4;
extern CMemHeap *D_002BA0A8;
class CHeapObj {
public:
    static void *operator new(unsigned int n);
};
class CResObj {
public:
    virtual void V0();
    virtual void V1();
    virtual void Unload();
    u8 pad[0xC];
};
struct CResCacheUnit {
    s32 m_isHead;             // 0x0
    CResCacheUnit *m_prev;    // 0x4
    CResCacheUnit *m_next;    // 0x8
    void *m_vptr;             // 0xC
    CBgWork m_bg;             // 0x10
    CResObj *m_obj;           // 0x1C
    void *m_mem;              // 0x20
    s32 m_size;               // 0x24
    s32 m_nodes;              // 0x28
    CMemHeap *m_heap;         // 0x2C
    char m_name[0x20];        // 0x30
    s32 m50;                  // 0x50
    s32 m54;                  // 0x54
    s32 m58;                  // 0x58
};
inline CResCacheUnit *UnitOf(CResCacheUnit *p) { return p->m_isHead ? 0 : p; }
extern "C" void func_0024FC38(CResCacheUnit *u);
extern "C" void func_0024FD28(CResCacheUnit *u);
extern "C" s32 func_002504D8(CResCacheUnit *u, s32 wait);
extern "C" s32 func_002505A0(void *c, const char *name, s32 mode);
extern "C" void func_00250910(void *c);
class CResLoader250540 {
public:
    s32 Func250540(int wait);

    u8 pad0[0xC];
    CResCacheUnit m_listC;    // 0xC (head, 0x10 bytes used)
};

extern "C" int strcmp(const char *a, const char *b);
typedef CResCacheUnit CRU;
struct RHead {
    s32 isHead;
    CRU *prev;
    CRU *next;
    void *vptr;
};
inline CRU *RFirst(RHead *h) {
    CRU *r = 0;
    if (!h->next->m_isHead) r = h->next;
    return r;
}
inline CRU *RLast(RHead *h) {
    CRU *r = 0;
    if (!h->prev->m_isHead) r = h->prev;
    return r;
}
inline CRU *RNext(CRU *n) {
    CRU *r = 0;
    if (!n->m_next->m_isHead) r = n->m_next;
    return r;
}
inline CRU *RPrev(CRU *n) {
    CRU *r = 0;
    if (!n->m_prev->m_isHead) r = n->m_prev;
    return r;
}
inline void RUnlink(CRU *n) {
    n->m_prev->m_next = n->m_next;
    n->m_next->m_prev = n->m_prev;
    n->m_next = n;
    n->m_prev = n;
}
inline void RPushFront(RHead *h, CRU *n) {
    n->m_prev = (CRU *)h;
    n->m_next = h->next;
    h->next = n;
    n->m_next->m_prev = n;
}
inline void RPushBack(RHead *h, CRU *n) {
    n->m_next = (CRU *)h;
    n->m_prev = h->prev;
    n->m_prev->m_next = n;
    n->m_next->m_prev = n;
}
class CResCache {
public:
    void *Find250B08(int key);
    void Func250840(void *name);
    void Func250978();
    s32 Init250208(void (*create)(), int n, int size, int nodes);
    void Func250368();
    CResCache();
    virtual ~CResCache();

    CRU *m_units;             // 0x0
    s32 m_count;              // 0x4
    u8 pad8[4];
    RHead m_free;             // 0xC
    RHead m_used;             // 0x1C
    RHead m_spare;            // 0x2C
    u8 pad3C[0x13C - 0x3C];
    // vptr 0x13C
};
extern s32 D_002BA0AC;
extern "C" void func_0024FC78(CResCacheUnit *u);
extern "C" s32 func_0023E9E8(s32 a);
extern "C" void func_001F1BD8(s32 a);
extern "C" void func_001F1A80(s32 (*fn)(s32 *), s32 v, s32 a, s32 b);
extern "C" void func_001F1230();
extern "C" s32 func_00251A80(s32 *p);
extern "C" void func_0023E088(u64 v);
extern "C" void func_0023C510(void *p);

typedef s32 (CResCacheUnit::*UnitFn)(s32);
extern "C" void func_002457A0(CBgWork *w, CResCacheUnit *obj, UnitFn f, s32 arg);
extern const UnitFn D_002E68F0;

void *Func237570(int n);
void Func237A88(void *p, int a);
void *Func237C30(void *p);
void Func238158(void *p, int a);
void Func225088();
int Func2250C0();
void Func225240(int a);
class CUnk237E90 {
public:
    void Func237E90(int v);
};
extern "C" void func_00251650();
extern "C" void func_002514B8();

extern const char D_002E68F8[];
extern "C" void func_0024FBD8(CResCacheUnit *u, CResObj *(*create)(), s32 size, s32 nodes);
extern const char D_002E6920[];
extern const char D_002E6938[];
extern "C" void *__builtin_vec_new(u32 n);
extern "C" void __builtin_vec_delete(void *p);
extern "C" void ResUnitCtor(CRU *u) asm("__13CResCacheUnit");
typedef void *(*MallocFn2)(u32);
extern "C" CMemHeap *func_002460C8();
extern "C" MallocFn2 func_002463C8(MallocFn2 f);
extern "C" MallocFn2 func_00246430(MallocFn2 f);
extern "C" void func_0022DC90(const char *dir);
extern "C" void *func_0024FD90(u32 n);
extern "C" void *func_0024FE28(u32 n);
class CResObjL {
public:
    virtual void V0();
    virtual s32 Load(const char *name);
    u8 pad[0xC];
};
class CRUnitV {
public:
    s32 a, b, c;
    virtual ~CRUnitV();
};

extern "C" void func_00227E60(void *p);
void Func2251E8();
extern "C" u64 func_00251488();
extern "C" u64 func_002514A8();
extern "C" void func_00227A20();
extern "C" void func_00227AA8();
extern "C" void func_00226DF8(s32 reg, u64 v);
extern s32 D_393924;
extern s32 D_393928;
#define GS_FRAME(fbp, fbw, psm, msk) ((u64)(fbp) | ((u64)(fbw) << 16) | ((u64)(psm) << 24) | ((u64)(msk) << 32))
#define GS_ZBUF(zbp, psm, zmsk) ((u64)(zbp) | ((u64)(psm) << 24) | ((u64)(zmsk) << 32))
#define GS_SCISSOR(x0, x1, y0, y1) ((u64)(x0) | ((u64)(x1) << 16) | ((u64)(y0) << 32) | ((u64)(y1) << 48))
#define GS_XYOFFSET(x, y) ((u64)(x) | ((u64)(y) << 32))
struct Y1Tag { s32 isHead; Y1Tag *prev; Y1Tag *next; void *vptr; };
extern u8 Y1CList_vt[] asm("_vt$5CList");
extern u8 Y1CListTag_vt[] asm("_vt$8CListTag");
static inline Y1Tag *Y1First(Y1Tag *l) { Y1Tag *n = l->next; return n->isHead ? 0 : n; }
static inline Y1Tag *Y1Remove(Y1Tag *t) { if (t) { t->prev->next = t->next; t->next->prev = t->prev; t->next = t; t->prev = t; } return t; }
static inline void Y1ListDtor(Y1Tag *l)
{
    l->vptr = Y1CList_vt;
    while (Y1Remove(Y1First(l)));
    l->vptr = Y1CListTag_vt;
    l->prev->next = l->next;
    l->next->prev = l->prev;
    l->next = l;
    l->prev = l;
}
inline void *operator new(unsigned int, void *p) { return p; }
class CList : public CListTag { public: CList() { m_isHead = 1; } virtual ~CList(); };
template <class T> class TList : public CList { public: virtual ~TList(); };
extern template class TList<CResCacheUnit>;

class Y1RU : public CListTag { public: virtual ~Y1RU(); u8 pad10[0x5C - 0x10]; };
static inline Y1Tag *Y1Rem2(Y1Tag *t) { if (t) { t->prev->next = t->next; t->next->prev = t->prev; t->next = t; t->prev = t; } return t; }

inline CRU *Y1RFi(RHead *h) { return h->next->m_isHead ? 0 : h->next; }
inline CRU *Y1RNx(CRU *p) { return p->m_next->m_isHead ? 0 : p->m_next; }
inline CRU *Y1RF2(RHead *h) { CRU *n = h->next; return n->m_isHead ? 0 : n; }
inline CRU *Y1RN2(CRU *p) { CRU *n = p->m_next; return n->m_isHead ? 0 : n; }
inline s32 Y1Dec(s32 *p) { s32 v = *p - 1; if (v < 0) v = 0; *p = v; return v; }
inline void Y1Dec2(s32 *p) { s32 v = *p - 1; if (v < 0) v = 0; *p = v; }
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_0024FAF0);

extern "C" void func_0024FBD8(CResCacheUnit *u, CResObj *(*create)(), s32 size, s32 nodes) {
    u->m_obj = create();
    u->m_mem = CHeapObj::operator new(size);
    u->m_size = size;
    u->m_nodes = nodes;
    func_0024FC38(u);
}

extern "C" void func_0024FC38(CResCacheUnit *u) {
    if (!u->m_heap) u->m_heap = func_00246100(u->m_mem, u->m_size, u->m_nodes);
}

extern "C" void func_0024FC78(CResCacheUnit *u) {
    if (u->m_heap) {
        func_0024FD28(u);
        u->m_heap = 0;
    }
}

extern "C" s32 func_0024FCB0(CResCacheUnit *u, const char *name) {
    func_0024FD28(u);
    strcpy(u->m_name, name);
    func_00245818(&u->m_bg, 1);
    func_002457A0(&u->m_bg, u, D_002E68F0, 0);
    return 1;
}

extern "C" void func_0024FD28(CResCacheUnit *u) {
    func_00245818(&u->m_bg, 1);
    if (u->m50) {
        u->m_obj->Unload();
        u->m_name[0] = 0;
        u->m54 = 0;
        u->m58 = 0;
        u->m50 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_0024FD90);

extern "C" void *func_0024FE28(u32 n) {
    CMemHeap *old = func_00246088(D_002BA0A8);
    void *p = func_00246BD8(n);
    func_00246088(old);
    return p;
}

extern "C" s32 func_0024FE80(CRU *u) {
    s32 ok = 0;
    CMemHeap *oh;
    MallocFn2 om, om2;
    u->m54 = 0;
    D_002BA0A0 = func_002460C8();
    D_002BA0A8 = func_002460C8();
    oh = func_00246088(u->m_heap);
    om = func_002463C8(func_0024FD90);
    om2 = func_00246430(func_0024FE28);
    func_0022DC90(0);
    if (!((CResObjL *)u->m_obj)->Load(u->m_name)) Func235DE0(D_002E68F8, u->m_name);
    else ok = 1;
    if (D_002BA0A4 > 0) {
        Func235DE0(D_002E6920, u->m_name, D_002BA0A4);
        u->m54 = 1;
    }
    func_00246430(om2);
    func_002463C8(om);
    func_00246088(oh);
    D_002BA0A0 = 0;
    D_002BA0A8 = 0;
    D_002BA0A4 = 0;
    if (ok) u->m50 = 1;
    return ok;
}

CResCache::CResCache()
{
    new (&m_free) TList<CResCacheUnit>;
    new (&m_used) TList<CResCacheUnit>;
    new (&m_spare) TList<CResCacheUnit>;
    m_units = 0;
    m_count = 0;
    pad3C[0] = 0;
}

CResCache::~CResCache()
{
    Func250368();
    Y1ListDtor((Y1Tag *)&m_spare);
    Y1ListDtor((Y1Tag *)&m_used);
    Y1ListDtor((Y1Tag *)&m_free);
}

INCLUDE_RODATA("asm/nonmatchings/Dk24FAF0", D_002E68F0);
INCLUDE_RODATA("asm/nonmatchings/Dk24FAF0", D_002E68F8);
INCLUDE_RODATA("asm/nonmatchings/Dk24FAF0", D_002E6920);
INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", Init250208__9CResCachePFv_viii);

void CResCache::Func250368()
{
    if (m_units) {
        while (Y1Rem2(Y1First((Y1Tag *)&m_free)));
        while (Y1Rem2(Y1First((Y1Tag *)&m_used)));
        delete [] (Y1RU *)m_units;
        m_units = 0;
        m_count = 0;
    }
}

extern "C" void func_00250488(CResCache *c) {
    CRU *n;
    func_00250910(c);
    for (n = RFirst(&c->m_used); n; n = RNext(n)) func_0024FD28(n);
}

extern "C" s32 func_002504D8(CResCacheUnit *u, s32 wait) {
    while (u) {
        if (func_00245818(&u->m_bg, wait)) return 1;
        u = UnitOf(u->m_next);
    }
    return 0;
}

s32 CResLoader250540::Func250540(int wait) {
    if (func_002504D8(UnitOf(((CResCache *)this)->m_used.next), wait)) return 1;
    return func_002504D8(UnitOf(((CResCache *)this)->m_free.next), wait) != 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_002505A0);

extern "C" s32 func_00250810(void *c, const char *name) {
    return func_002505A0(c, name, 0);
}

extern "C" s32 func_00250828(void *c, const char *name) {
    return func_002505A0(c, name, 1);
}

void CResCache::Func250840(void *name)
{
    CRU *n;
    for (n = Y1RF2(&m_free); n; n = Y1RN2(n)) {
        if (!strcmp(n->m_name, (const char *)name)) {
            if (Y1Dec(&n->m58) > 0) return;
            RUnlink(n);
            RPushFront(&m_used, n);
            return;
        }
    }
}

extern "C" void func_00250910(void *pc) {
    CResCache *c = (CResCache *)pc;
    CRU *n;
    while ((n = RLast(&c->m_free)) != 0) {
        n->m58 = 0;
        RUnlink(n);
        RPushFront(&c->m_used, n);
    }
}

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", Func250978__9CResCache);

extern "C" s32 func_00250A48(CResCache *c, const char *name)
{
    CRU *n;
    for (n = Y1RFi(&c->m_free); n; n = Y1RNx(n))
        if (!strcmp(n->m_name, name)) return n->m50;
    for (n = Y1RFi(&c->m_used); n; n = Y1RNx(n))
        if (!strcmp(n->m_name, name)) return n->m50;
    return 0;
}

void *CResCache::Find250B08(int key)
{
    CRU *n;
    for (n = Y1RFi(&m_free); n; n = Y1RNx(n))
        if (!strcmp(n->m_name, (const char *)key)) return n->m_obj;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_00250B80);

extern "C" s32 func_00250BE0(CMemHeap *h) {
    CMemHeap *old = func_00246088(h);
    s32 r = func_002462B0();
    func_00246088(old);
    return r;
}

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_00250C28);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_00250D28);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_00250DD8);
INCLUDE_RODATA("asm/nonmatchings/Dk24FAF0", D_002E69F0);
INCLUDE_RODATA("asm/nonmatchings/Dk24FAF0", D_002E6A10);
INCLUDE_RODATA("asm/nonmatchings/Dk24FAF0", D_002E6A20);
INCLUDE_RODATA("asm/nonmatchings/Dk24FAF0", D_002E6A30);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_00250EC8);
INCLUDE_RODATA("asm/nonmatchings/Dk24FAF0", D_002E6AA0);
INCLUDE_RODATA("asm/nonmatchings/Dk24FAF0", D_002E6AC8);
INCLUDE_RODATA("asm/nonmatchings/Dk24FAF0", D_002E6AF8);
INCLUDE_RODATA("asm/nonmatchings/Dk24FAF0", D_002E6B08);

extern "C" void func_002512C0() {
    func_0023E088(D_393910.m0);
    func_0023C510(D_3936F0);
    func_0023C510(D_393800);
}

extern "C" void func_00251300(s32 on) {
    if (on) *(volatile u64 *)0x12000000 = 0x8023;
    else *(volatile u64 *)0x12000000 = 0xFFC2;
}

extern "C" void func_00251328(s32 a, s32 b, s32 c, s32 d) {
    func_0023C6E8(D_393800, a, b, c, d);
}

extern "C" void func_00251360() {
    func_0023C700(D_393800, 0);
}

extern "C" void func_00251388(s32 v) { D_393910.m1C = v; }

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_00251398);

extern "C" void func_00251458(s32 v) { D_393910.m28 = v; }

extern "C" u64 func_00251468() { return func_0023C650(D_3936F0); }

extern "C" u64 func_00251488() { return func_0023C650(D_393800); }

extern "C" u64 func_002514A8() { return D_393910.m0; }

extern "C" void func_002514B8() {
    u64 fr = func_00251488();
    u64 zb = func_002514A8();
    func_00227E60(D_393800);
    Func2251E8();
    func_00227A20();
    func_00226DF8(0x3F, 0);
    func_00226DF8(0x4C, GS_FRAME((fr & 0x3FFF) >> 5, (fr >> 14) & 0x3F, (fr >> 32) & 0x3F, 0));
    func_00226DF8(0x4E, GS_ZBUF((zb & 0x3FFF) >> 5, (zb >> 32) & 0x3F, 0));
    func_00226DF8(0x42, 0x44);
    func_00226DF8(0x4A, 0);
    func_00226DF8(0x49, 0);
    func_00226DF8(0x3B, 0x80);
    func_00226DF8(0x22, 0);
    func_00226DF8(0x40, GS_SCISSOR(0, D_393924 - 1, 0, D_393928 - 1));
    func_00226DF8(0x18, GS_XYOFFSET(0x8000 - (D_393924 / 2) * 16, 0x8000 - (D_393928 / 2) * 16));
    func_00226DF8(0x47, 0x38002);
    func_00227AA8();
    Func2251E8();
}

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_00251650);

extern "C" void *func_002519B8(u8 *base, s32 i) {
    void *pkt = Func237570(0x30);
    CUnk237E90 *q = (CUnk237E90 *)((u8 *)pkt + 0x10);
    Func237A88(pkt, 3);
    Func238158(Func237C30(base + i * 16), 1);
    Func225088();
    func_00251650();
    q->Func237E90(Func2250C0());
    Func225088();
    func_002514B8();
    Func225240((int)base);
    q->Func237E90(Func2250C0());
    return pkt;
}

extern "C" s32 func_00251A80(s32 *p) {
    return func_0023E9E8(-1) >= *p;
}

extern "C" s32 func_00251AB8(s32 mode) {
    if (mode < 0 || mode == 1) return func_0023E9E8(mode);
    if (mode == 0) {
        mode = D_393910.m34;
        if (!mode) {
            func_001F1BD8(0);
            goto done;
        }
    }
    func_001F1A80(func_00251A80, D_002BA0AC + mode, 0, 0);
    func_001F1230();
done:
    D_002BA0AC = func_0023E9E8(-1);
    return func_0023E9E8(1);
}

extern "C" void func_00251B58(s32 v) { D_393910.m34 = v; }

extern "C" s32 func_00251B68() { return D_393910.m34; }

extern "C" void func_00251B78(s32 v) { D_393910.m2C = v; }

int Func251B88() { return D_393910.m2C; }

extern "C" void func_00251B98(s32 v) { D_393910.m30 = v; }

extern "C" s32 func_00251BA8() { return D_393910.m30; }

extern "C" CDebOut *func_00251BB8() {
    return new CDebOut;
}

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", __7CDebOut);

CDebOut::~CDebOut() {
    D_002BA0B0 = 0;
    Release();
}

s32 CDebOut::Load(const char *name) {
    s32 ok = 0;
    void *data = func_002303C0(name);
    if (!data) {
        Func235DE0(D_002E6AA0, name);
    } else {
        m4 = func_00205A80(data);
        if (m4 < 0) Func235DE0(D_002E6AC8, name);
        else ok = 1;
    }
    if (data) (*D_002B91B0)(data);
    return ok;
}

void CDebOut::Release() {
    if (m4 >= 0) {
        Func23B1D0(m4);
        m4 = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_00251DC0);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_002520C8);
