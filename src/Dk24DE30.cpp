#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CProcess.h"
#include "CList.h"
extern "C" void *memset(void *d, int c, unsigned int n);
extern void *(*D_002B91A4)(u32 n);
extern void (*D_002B91B0)(void *p);
typedef void *(*TaskAllocFn)(u32);
typedef void (*TaskFreeFn)(void *);
extern TaskAllocFn D_002BA068;
extern TaskFreeFn D_002BA06C;
typedef void (CTask::*TaskFn)();
class CTaskTag : public CListTag {
public:
    virtual ~CTaskTag();

    CTaskTag *m_parent;       // 0x10
    CTask *m_task;            // 0x14
    TaskFn m_fn[3][2];        // 0x18
    s8 m_count[3][3];         // 0x48
    u8 pad51[3];
    CListTag m_children;      // 0x54
};
extern TaskFn D_002BA070[3][2];
extern "C" void *func_0024ECD0(u32 n);
extern "C" CTaskTag *func_0024ED20(void *p);
extern "C" void func_0024EEE8(CTaskTag *parent, CTaskTag *c);
extern "C" void func_0024EF88(CTaskTag *t, u32 i, s32 j);
extern "C" void func_0024F1F0(CTaskTag *t, u32 i, TaskFn a, TaskFn b);
extern "C" CTask *func_0024F570(CTask *t);
extern "C" void func_0024F610(CTask *t);
extern "C" void func_0024F668(CTask *t);
extern "C" s32 func_0024F6A8(CTask *t, u32 i, u32 j, s32 inc);
extern "C" void func_0024F738(CTask *t, u32 i, s32 j);
class CRootTask : public CTask {
public:
    CRootTask() {}
    virtual ~CRootTask();
};
inline CTaskTag *TagPrev(CTaskTag *t) {
    CTaskTag *p = (CTaskTag *)t->m_prev;
    return p->m_isHead ? 0 : p;
}
inline CTaskTag *TagNext(CTaskTag *t) {
    CTaskTag *p = (CTaskTag *)t->m_next;
    return p->m_isHead ? 0 : p;
}
struct CProcessData {
    u8 pad0[0x14];
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
    s32 m1C[4];               // 0x1C
};
extern "C" int func_0024F998(CProcess *p, s32 wait);
extern "C" void func_0024F9F0(CProcess *p);

typedef s32 (CProcess::*ProcFn)(s32);
extern "C" void func_002457A0(CBgWork *w, CProcess *obj, ProcFn f, s32 arg);
extern const ProcFn D_002E68C8;
extern const ProcFn D_002E68D0;
class CTaskList24F5C0 {
public:
    void *Func24F5C0(void *task, int x);
    CTaskTag *m_tag;
};

class CResCacheUnit : public CListTag {
public:
    CResCacheUnit();
    virtual ~CResCacheUnit();
    CBgWork m_bg;             // 0x10
    void *m1C;                // 0x1C
    void *m20;                // 0x20
    s32 m24;                  // 0x24
    s32 m28;                  // 0x28
    void *m2C;                // 0x2C
    char m30[0x20];           // 0x30
    s32 m50;                  // 0x50
    s32 m54;                  // 0x54
    s32 m58;                  // 0x58
};

struct CV4 { f32 x, y, z, w; };
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024DE30);

s32 Func24E0F0(const char *ppts, int n, int pp) {
    CV4 *pts = (CV4 *)ppts;
    CV4 *p = (CV4 *)pp;
    s32 i, c;
    if (n < 3) return 0;
    c = 0;
    for (i = 0; i < n; i++) {
        CV4 *a = &pts[i];
        CV4 *b = &pts[(i + 1) % n];
        CV4 *pr = &pts[(i + n - 1) % n];
        if ((a->z < p->z && p->z < b->z) || (b->z < p->z && p->z < a->z)) {
            if (p->x < (b->x - a->x) * ((p->z - a->z) / (b->z - a->z)) + a->x) c++;
        }
        if (p->x < a->x && a->z == p->z) {
            if ((pr->z < p->z && p->z <= b->z) || (b->z < p->z && p->z <= pr->z)) c++;
        }
    }
    return c & 1;
}

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024E240);

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024E560);

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024E6D0);

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024E830);

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024E9C0);

extern "C" void *func_0024EC58(u32 n) {
    void *p = (*D_002B91A4)(n);
    memset(p, 0, n);
    return p;
}

extern "C" void func_0024ECA8(void *p) {
    if (p) (*D_002B91B0)(p);
}

extern "C" void *func_0024ECD0(u32 n) {
    return (*D_002BA068)(n);
}

extern "C" void func_0024ECF8(void *p) {
    if (p) (*D_002BA06C)(p);
}

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024ED20);

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024EDE8);

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024EEE8);

extern "C" void func_0024EF30(CTaskTag *t) {
    CTaskTag *n;
    while ((n = TagPrev((CTaskTag *)&t->m_children)) != 0) delete n;
}

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024EF88);

extern "C" void func_0024F1F0(CTaskTag *t, u32 i, TaskFn a, TaskFn b) {
    if (!a) a = D_002BA070[i][0];
    if (!b) b = D_002BA070[i][1];
    t->m_fn[i][0] = a;
    t->m_fn[i][1] = b;
}

extern "C" TaskAllocFn func_0024F298(TaskAllocFn f) {
    TaskAllocFn old = D_002BA068;
    D_002BA068 = f;
    return old;
}

extern "C" TaskAllocFn func_0024F2B0() { return D_002BA068; }

extern "C" TaskFreeFn func_0024F2C0(TaskFreeFn f) {
    TaskFreeFn old = D_002BA06C;
    D_002BA06C = f;
    return old;
}

extern "C" TaskFreeFn func_0024F2D8() { return D_002BA06C; }

void *CTask::operator new(unsigned int n) {
    return (*D_002BA068)(n);
}

void CTask::operator delete(void *p) {
    if (p) (*D_002BA06C)(p);
}

CTask::CTask() {
    void *p = func_0024ECD0(0x64);
    func_0024ED20(p);
    m_unk0 = (s32)p;
    ((CTaskTag *)p)->m_task = this;
}

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", _$_5CTask);

extern "C" CRootTask *func_0024F420() {
    return new CRootTask;
}

extern "C" CTask *func_0024F460(CTask *t) {
    CTaskTag *p = ((CTaskTag *)t->m_unk0)->m_parent;
    return p ? p->m_task : 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024F480);

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024F4D0);

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024F520);

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024F570);

void *CTaskList24F5C0::Func24F5C0(void *task, int x) {
    CTask *t = (CTask *)task;
    if (!t) return 0;
    func_0024EEE8(m_tag, (CTaskTag *)t->m_unk0);
    t->Func1();
    return t;
}

extern "C" void func_0024F610(CTask *t) {
    func_0024F738(t, 0, 1);
    func_0024F668(t);
    delete t;
}

extern "C" void func_0024F668(CTask *t) {
    CTask *c;
    while ((c = func_0024F570(t)) != 0) func_0024F610(c);
}

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024F6A8);

extern "C" s32 func_0024F6F8(CTask *t, u32 i, u32 j) {
    if (i >= 3 || j >= 3) return 0;
    return ((CTaskTag *)t->m_unk0)->m_count[i][j] > 0;
}

extern "C" void func_0024F738(CTask *t, u32 i, s32 j) {
    if (i < 3) func_0024EF88((CTaskTag *)t->m_unk0, i, j);
}

extern "C" void func_0024F760(CTask *t) {
    func_0024F6A8(t, 1, 0, 1);
    t->Func2();
}

extern "C" void func_0024F7A8(CTask *t, u32 i, TaskFn a, TaskFn b) {
    if (i < 3) func_0024F1F0((CTaskTag *)t->m_unk0, i, a, b);
}

extern "C" void func_0024F7E0(void) {
}

extern "C" void Func1__5CTask(void) {
}

extern "C" void Func2__5CTask(void) {
}

extern "C" void Update__5CTask(void) {
}

extern "C" void Func4__5CTask(void) {
}

extern "C" void Draw__5CTask(void) {
}

extern "C" void Func6__5CTask(void) {
}

CProcess::CProcess() {
    m_unk14 = 1;
}

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", _$_8CProcess);

void CProcess::Func2() {
    func_0024F998(this, 1);
    func_0024F9F0(this);
}

extern "C" void func_0024F900(CProcess *p, s32 arg) {
    func_0024F998(p, 1);
    func_002457A0(&p->m_bg, p, D_002E68C8, arg);
}

extern "C" void func_0024F950(CProcess *p) {
    func_0024F998(p, 1);
    func_002457A0(&p->m_bg, p, D_002E68D0, 0);
}

extern "C" int func_0024F998(CProcess *p, s32 wait) {
    return func_00245818(&p->m_bg, wait);
}

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024F9B0);

extern "C" void func_0024F9F0(CProcess *p) {
    CProcessData *d = (CProcessData *)p;
    if (d->m18) {
        p->ReleaseTextures();
        d->m18 = 0;
    }
}

extern "C" void func_0024FA38(CProcess *p, s32 a, s32 b, s32 c, s32 e) {
    CProcessData *d = (CProcessData *)p;
    d->m1C[3] = e;
    d->m1C[0] = a;
    d->m1C[1] = b;
    d->m1C[2] = c;
    d->m14 = 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk24DE30", func_0024FA50);

extern "C" s32 func_0024FA70(CProcess *p) {
    return ((CProcessData *)p)->m14;
}

s32 CProcess::Func7() {
    return 1;
}

extern "C" void ReleaseTextures__8CProcess(void) {
}

CResCacheUnit::CResCacheUnit() {
    m1C = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2C = 0;
    m30[0] = 0;
    m50 = 0;
    m54 = 0;
    m58 = 0;
}
