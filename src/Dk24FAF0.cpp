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

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_0024FCB0);

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

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_0024FE80);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", __9CResCache);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", _$_9CResCache);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", Init250208__9CResCachePFv_viii);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", Func250368__9CResCache);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_00250488);

extern "C" s32 func_002504D8(CResCacheUnit *u, s32 wait) {
    while (u) {
        if (func_00245818(&u->m_bg, wait)) return 1;
        u = UnitOf(u->m_next);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", Func250540__16CResLoader250540i);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_002505A0);

extern "C" s32 func_00250810(void *c, const char *name) {
    return func_002505A0(c, name, 0);
}

extern "C" s32 func_00250828(void *c, const char *name) {
    return func_002505A0(c, name, 1);
}

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", Func250840__9CResCachePv);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_00250910);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", Func250978__9CResCache);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_00250A48);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", Find250B08__9CResCachei);

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

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_00250EC8);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_002512C0);

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

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_002514B8);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_00251650);

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_002519B8);

extern "C" s32 func_00251A80(s32 *p) {
    return func_0023E9E8(-1) >= *p;
}

INCLUDE_ASM("asm/nonmatchings/Dk24FAF0", func_00251AB8);

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
