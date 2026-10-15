#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct CRxThCtx {
    u8 pad0[0x94];
    s32 m_unk94;              // 0x94
};
extern CRxThCtx D_2FD8A0, D_2FD938;
extern s32 D_2FD9CC;
extern "C" void func_00237260();
extern "C" s32 func_00229AF8();
extern "C" void func_002372D8();
extern "C" void func_00229B08(s32 x);
extern "C" void func_001F1E88();
extern "C" s32 func_001F1EC0();
extern "C" void func_001F0CF8();
extern "C" void func_001F0EB0();
extern "C" void func_001F10C8(void (*fn)(s32));
extern "C" void func_001F1150(void (*fn)(s32));
extern "C" void func_001F0820(CRxThCtx *p);
extern "C" void func_001F0850(CRxThCtx *p);
extern "C" void func_001F08B0(s32 mode);
extern "C" s32 func_0023A080(s32 x);
extern "C" s32 func_00239698(s32 a, s32 b);
extern "C" void func_001F1A80(s32 (*fn)(s32 *), s32 a, s32 b, s32 c);
extern "C" void func_001F1230();
extern "C" s32 func_001F0960();
extern "C" s32 func_001F09D0(s32 *p);
struct CRxSemaParam {
    s32 m_count;              // 0x0
    s32 m_maxCount;           // 0x4
    s32 m_initCount;          // 0x8
    s32 m_waitThreads;        // 0xC
    u32 m_attr;               // 0x10
    u32 m_option;             // 0x14
};
struct CRxThreadParam {
    s32 m_status;             // 0x0
    void (*m_func)(void *);   // 0x4
    void *m_stack;            // 0x8
    s32 m_stackSize;          // 0xC
    void *m_gp;               // 0x10
    s32 m_prio;               // 0x14
    s32 pad18[6];
};
extern "C" s32 func_002731A0(CRxSemaParam *p);
extern "C" s32 func_00272FA0(CRxThreadParam *p);
extern "C" s32 func_00272FC0(s32 th, void *arg);
extern "C" s32 func_00272FF0(s32 th);
extern "C" s32 func_00272FB0(s32 th);
extern u8 D_2F36F0[];
extern volatile s32 D_002A5CA8, D_002A5CAC;
struct CRxMsg { s32 m_a, m_b, m_c, m_d; };
extern CRxMsg D_2FDAB0[32];
extern "C" s32 func_001F0C38();
typedef void (*RxThCallback)(s32 arg);
extern RxThCallback D_2FDCC0[8];
extern "C" s32 func_001F1088(RxThCallback fn);
extern "C" void func_00274F10(const char *fmt, ...);
extern const char D_002E2200[];
extern s32 D_2FDA20, D_2FDA10, D_2FDA08;
extern "C" s32 func_00273090();
extern "C" s32 func_002731C0(s32 sema);
extern "C" s32 func_002731F0(s32 sema);
extern "C" s32 func_00273220(s32 sema, CRxSemaParam *p);

inline u32 EeGetStatus()
{
    u32 r;
    __asm__ volatile("sync.p");
    __asm__ volatile("mfc0 %0, $12" : "=r"(r));
    __asm__ volatile("sync.p");
    return r;
}
inline void EeSetStatus(u32 v)
{
    __asm__ volatile("sync.p");
    __asm__ volatile("mtc0 %0, $12" : : "r"(v));
    __asm__ volatile("sync.p");
}
inline void EeSyncL()
{
    __asm__ volatile("sync.p");
    __asm__ volatile("sync");
}
struct CRxThread {
    s16 m_id;                 // 0x0
    s16 m_unk2;               // 0x2
    s32 m_unk4;               // 0x4
    s32 m_unk8;               // 0x8
    s32 m_unkC;               // 0xC
};
extern CRxThread D_2FDA30[8];
extern s32 D_2FDA04, D_2FDA0C, D_2FDA18, D_2FDA24;
extern s32 D_002A5CB4;
extern s32 D_002A5CA4, D_002A5CB8;
extern "C" s32 func_00272F20(u16 a, void (*fn)(), s32 c);
extern "C" void func_001F13A0();
extern "C" s32 func_00273030(s32 a, s32 b);
extern "C" void func_00272FE0();
extern "C" void func_001F0AC8(s32 th);
extern "C" void func_001F1610();

extern "C" s32 func_0023E9E8(s32 x);
extern "C" s32 func_001F1BA0(s32 *p);
extern const char D_002E2230[], D_002E2250[];
extern s32 D_002A5CBC, D_002A5CC0, D_002A5CD8, D_002A5CDC;
extern "C" s32 func_001F1CE8(s32 max, s32 init);
extern "C" s32 func_00273210(s32 th, void *st);
extern "C" void func_00221028();
extern "C" void func_0021E760();
extern "C" void func_0021C698();
extern "C" void func_00222D08();
extern "C" void func_00224D80();
extern "C" s32 func_002731B0(s32 sema);

extern "C" s32 func_001F0A70(void (*fn)(void *), void *stack, s32 size, s32 prio);
extern "C" void func_001F1028(s32 arg);
inline void RxThKick()
{
    EeSyncL();
    u32 old = EeGetStatus();
    u32 n = old & ~1;
    do {
        EeSetStatus(n);
    } while (EeGetStatus() != n);
    if (D_2FDA18 < 0) D_2FDA18 = func_00272F20(D_002A5CB4, func_001F13A0, 0);
    EeSyncL();
    do {
        EeSetStatus(old);
    } while (EeGetStatus() != old);
}
extern s32 (*D_002A5CB0)(s32 *p);
extern s32 D_2FDCB0[3];
extern volatile s32 D_2FDA1C;
extern s32 D_2FDA00;
extern const char D_002E21F0[];
extern "C" s32 func_00273130(s32 th);
extern "C" s32 func_002731E0(s32 sema);
extern "C" s32 func_00273110(s32 th);
s32 Func235DE0(const char *fmt, ...);
extern "C" void func_0027BD78();

extern const char D_002E2280[];
extern s32 D_002A5CD0;
extern "C" s32 func_001F1D58(s32 th);
extern "C" s32 func_001F1D78();

extern s32 D_002A5CA0, D_002A5CBC;
extern s32 D_2FDA14, D_2FDA28;
extern u8 D_30DD00[], D_2FDD00[];
extern "C" void func_0023E868();
extern "C" s32 func_002730A0(s32 th, void *st);
extern "C" void D_001F0BB0();
extern "C" void func_001F0AF0();
extern "C" s32 func_001F0A48(s32 max, s32 init);
extern "C" s32 func_00272F30(s32 id);
extern "C" s32 func_0023E8F0();
struct CRxThStatus { s32 m_status; void *m_func; void *m_stack; s32 m_stackSize; void *m_gp; s32 m_initPrio; s32 m_curPrio; s32 pad[5]; };
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F0518);

extern "C" void func_001F0820(CRxThCtx *p)
{
    func_00237260();
    p->m_unk94 = func_00229AF8();
}

extern "C" void func_001F0850(CRxThCtx *p)
{
    func_002372D8();
    if (p->m_unk94) {
        func_00229B08(p->m_unk94);
        return;
    }
}

extern "C" void func_001F0890(s32 x) { D_2FD9CC = x; }

extern "C" s32 func_001F08A0() { return D_2FD9CC; }

extern "C" void func_001F08B0(s32 mode)
{
    if (mode == 1) {
        func_001F0820(&D_2FD8A0);
        func_001F0850(&D_2FD938);
        return (void)func_001F1EC0();
    }
    func_001F1E88();
    func_001F0820(&D_2FD938);
    return func_001F0850(&D_2FD8A0);
}

extern "C" void func_001F0910()
{
    func_001F0CF8();
    return func_001F10C8(func_001F08B0);
}

extern "C" void func_001F0938()
{
    func_001F0EB0();
    return func_001F1150(func_001F08B0);
}

extern "C" s32 func_001F0960() { return func_0023A080(1) == 0; }

extern "C" s32 func_001F0980(s32 wait)
{
    if (wait) return func_0023A080(1);
    func_001F1A80((s32 (*)(s32 *))func_001F0960, 0, 0, 0);
    func_001F1230();
    return 0;
}

extern "C" s32 func_001F09D0(s32 *p) { return func_00239698(*p, 1) == 0; }

extern "C" s32 func_001F09F8(s32 a, s32 wait)
{
    if (wait) return func_00239698(a, wait);
    func_001F1A80(func_001F09D0, a, 0, 0);
    func_001F1230();
    return 0;
}

extern "C" s32 func_001F0A48(s32 max, s32 init)
{
    CRxSemaParam p;
    p.m_maxCount = max;
    p.m_initCount = init;
    return func_002731A0(&p);
}

extern "C" s32 func_001F0A70(void (*fn)(void *), void *stack, s32 size, s32 prio)
{
    CRxThreadParam p;
    p.m_func = fn;
    p.m_stack = stack;
    p.m_stackSize = size;
    p.m_prio = prio;
    p.m_gp = D_2F36F0;
    s32 th = func_00272FA0(&p);
    func_00272FC0(th, 0);
    return th;
}

extern "C" void func_001F0AC8(s32 th)
{
    func_00272FF0(th);
    return (void)func_00272FB0(th);
}

// func_001F0AF0 is three functions in retail (the split did not see 0x1F0BB0 and 0x1F0C08).
extern const char D_002E21F0[];
struct CRxMsgFn { void (*m_fn)(s32 *args); s32 m_args[3]; };
extern "C" void func_001F0AF0()
{
    CRxMsgFn *tbl = (CRxMsgFn *)D_2FDAB0;
    for (;;) {
        s32 i = D_002A5CAC;
        while (D_002A5CA8 == i) {
            if (!(EeGetStatus() & 0x10000)) {
                func_0027BD78();
                Func235DE0(D_002E21F0);
                func_0027BD78();
            }
        }
        tbl[i].m_fn(tbl[i].m_args);
        D_002A5CAC = (i + 1) & 0x1F;
    }
}
extern "C" void D_001F0BB0()
{
    for (;;) {
        if (!(EeGetStatus() & 0x10000)) {
            func_0027BD78();
            Func235DE0(D_002E21F0);
            func_0027BD78();
        }
    }
}
extern "C" s32 func_001F0C08()
{
    CRxSemaParam st;
    func_00273220(D_2FDA04, &st);
    return st.m_count > 0;
}

extern "C" s32 func_001F0C38() { return (D_002A5CA8 - D_002A5CAC) & 0x1F; }

extern "C" s32 func_001F0C60(s32 a, s32 b, s32 c, s32 d)
{
    if (func_001F0C38() == 0x1F) return 0;
    s32 i = D_002A5CA8;
    CRxMsg *m = &D_2FDAB0[i];
    m->m_a = a;
    m->m_b = b;
    m->m_c = c;
    m->m_d = d;
    D_002A5CA8 = (i + 1) & 0x1F;
    return 1;
}

extern "C" void func_001F0CF8()
{
    CRxThStatus st;
    s32 i;
    if (++D_002A5CA0 != 1) return;
    func_0023E868();
    D_2FDA20 = 0;
    for (i = 0; i < 8; i++) D_2FDA30[i].m_id = -1;
    for (i = 0; i < 8; i++) D_2FDCC0[i] = 0;
    D_2FDA24 = 0;
    D_2FDA28 = 0;
    D_2FDA0C = func_00273090();
    func_002730A0(D_2FDA0C, &st);
    D_002A5CA4 = st.m_curPrio;
    D_2FDA00 = func_001F0A48(1, 0);
    D_2FDA04 = func_001F0A48(0x10000, 0);
    D_2FDA08 = func_001F0A48(0x10000, 0);
    D_002A5CA8 = 0;
    D_002A5CAC = 0;
    D_2FDA14 = func_001F0A70((void (*)(void *))D_001F0BB0, D_30DD00, 0x400, D_002A5CA4 + D_002A5CC0);
    D_2FDA10 = func_001F0A70((void (*)(void *))func_001F0AF0, D_2FDD00, 0x10000, D_002A5CA4 + D_002A5CBC);
    func_00273110(D_2FDA10);
    D_002A5CB0 = 0;
    D_2FDA18 = -1;
}

extern "C" void func_001F0EB0()
{
    if (D_002A5CA0 <= 0) return;
    if (--D_002A5CA0 != 0) return;
    EeSyncL();
    u32 old = EeGetStatus();
    u32 n = old & ~1;
    do {
        EeSetStatus(n);
    } while (EeGetStatus() != n);
    if (D_2FDA18 >= 0) {
        func_00272F30(D_2FDA18);
        D_2FDA18 = -1;
    }
    D_2FDA24 = 0;
    for (s32 i = 0; i < 8; i++) {
        if (D_2FDA30[i].m_id >= 0) {
            func_001F0AC8(D_2FDA30[i].m_id);
            D_2FDA30[i].m_id = -1;
        }
    }
    EeSyncL();
    do {
        EeSetStatus(old);
    } while (EeGetStatus() != old);
    func_001F0AC8(D_2FDA10);
    func_001F0AC8(D_2FDA14);
    func_002731B0(D_2FDA08);
    func_002731B0(D_2FDA04);
    func_002731B0(D_2FDA00);
    return (void)func_0023E8F0();
}

extern "C" void func_001F1028(s32 arg)
{
    for (s32 i = 0; i < 8; i++) {
        if (D_2FDCC0[i]) D_2FDCC0[i](arg);
    }
}

extern "C" s32 func_001F1088(RxThCallback fn)
{
    // Always -1 in retail (the found index is never returned).
    s32 i;
    for (i = 0; i < 8; i++) {
        if (D_2FDCC0[i] == fn) return -1;
    }
    return -1;
}

extern "C" void func_001F10C8(RxThCallback fn)
{
    if (func_001F1088(fn) >= 0) return;
    for (s32 i = 0; i < 8; i++) {
        if (D_2FDCC0[i] == 0) {
            D_2FDCC0[i] = fn;
            return;
        }
    }
    return func_00274F10(D_002E2200, fn);
}

extern "C" void func_001F1150(RxThCallback fn)
{
    s32 i = func_001F1088(fn);
    if (i >= 0) D_2FDCC0[i] = 0;
}

extern "C" s32 func_001F1180() { return D_2FDA20; }

extern "C" void func_001F1190()
{
    if (func_00273090() == D_2FDA10) {
        func_002731C0(D_2FDA08);
        return;
    }
}

extern "C" void func_001F11C8()
{
    if (func_00273090() == D_2FDA10) {
        func_002731F0(D_2FDA08);
        return;
    }
}

extern "C" s32 func_001F1200()
{
    CRxSemaParam st;
    func_00273220(D_2FDA08, &st);
    return st.m_count > 0;
}

extern "C" void func_001F1230()
{
    if (!(EeGetStatus() & 0x10000)) {
        func_0027BD78();
        Func235DE0(D_002E21F0);
        func_0027BD78();
    }
    s32 id = func_00273090();
    if (id == D_2FDA0C) {
        D_2FDA1C = func_0023E9E8(-1);
        if (D_002A5CB0 == 0) func_001F1A80(func_001F1BA0, D_2FDA1C, 0, 0);
        func_001F1028(1);
        D_2FDA20 = 1;
        func_00273130(D_2FDA10);
        func_002731E0(D_2FDA00);
        func_00273110(D_2FDA10);
        D_2FDA20 = 0;
        return func_001F1028(0);
    }
    if (id != D_2FDA10) {
        func_00273030(D_2FDA0C, D_002A5CA4 + D_002A5CB8);
        func_00273030(id, D_002A5CA4 + D_002A5CC0);
        return;
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F13A0);

extern "C" s32 func_001F15F0() { return func_002731C0(D_2FDA04); }

extern "C" void func_001F1610()
{
    CRxSemaParam st;
    EeSyncL();
    u32 old = EeGetStatus();
    u32 n = old & ~1;
    do {
        EeSetStatus(n);
    } while (EeGetStatus() != n);
    func_002731F0(D_2FDA04);
    func_00273220(D_2FDA04, &st);
    if (st.m_count <= 0 && D_2FDA18 < 0) D_2FDA18 = func_00272F20(D_002A5CB4, func_001F13A0, 0);
    EeSyncL();
    do {
        EeSetStatus(old);
    } while (EeGetStatus() != old);
}

extern "C" s32 func_001F16E8()
{
    s32 id = func_00273090();
    for (s32 i = 0; i < 8; i++) {
        if (D_2FDA30[i].m_id == id) return i;
    }
    return -1;
}

extern "C" void func_001F1748(s32 i)
{
    if (i < 0) return;
    CRxThread *t = &D_2FDA30[i];
    if (t->m_id < 0) return;
    func_001F15F0();
    s32 id = t->m_id;
    t->m_id = -1;
    D_2FDA24--;
    if (id == func_00273090()) {
        func_00273030(D_2FDA0C, D_002A5CA4 + D_002A5CB8);
        func_001F1610();
        func_00272FE0();
    } else {
        func_001F0AC8(id);
    }
    return func_001F1610();
}

extern "C" s32 func_001F1820() { return D_2FDA24; }

extern "C" void func_001F1830(s32 i, s32 v)
{
    if (i >= 0) D_2FDA30[i].m_unk8 = v;
}

extern "C" s32 func_001F1850(s32 i)
{
    if (i < 0) return 0;
    return D_2FDA30[i].m_unk8;
}

// GNU as 2.10 assembled the lui of this function's %hi/%lo pair as a copy of the following lw without it.
asm(".p2align 3");
extern "C" s32 func_001F1870(s32 i)
{
    if (i < 0) return 0;
    return D_2FDA30[i].m_unkC;
}

extern "C" void func_001F1890(s32 i, s32 v)
{
    if (i >= 0) D_2FDA30[i].m_unkC = v;
}

extern "C" s32 func_001F18B0(s32 i)
{
    if (i < 0) return 0;
    return D_2FDA30[i].m_unk2;
}

extern "C" void func_001F18D0(s32 i, s32 v)
{
    if (i >= 0) D_2FDA30[i].m_unk2 = v;
}

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F18F0);

extern "C" void func_001F1A80(s32 (*fn)(s32 *), s32 a, s32 b, s32 c)
{
    if (func_00273090() != D_2FDA0C) return;
    D_002A5CB0 = fn;
    D_2FDCB0[0] = a;
    D_2FDCB0[1] = b;
    D_2FDCB0[2] = c;
    RxThKick();
}

extern "C" void func_001F1B90(void) {
}

extern "C" void func_001F1B98(void) {
}

extern "C" s32 func_001F1BA0(s32 *p) { return *p != func_0023E9E8(-1); }

extern "C" s32 func_001F1BD8(s32 wait)
{
    if (!wait) {
        func_001F1A80(func_001F1BA0, func_0023E9E8(-1), 0, 0);
        func_001F1230();
    }
    return func_0023E9E8(1);
}

extern "C" s32 func_001F1C20() { return D_002A5CB4; }

extern "C" void func_001F1C30(s32 n)
{
    if (n < 4) n = 4;
    if (n > 256) n = 256;
    func_00274F10(D_002E2230, n);
    D_002A5CB4 = n;
}

extern "C" void func_001F1C80(s32 a, s32 b, s32 c)
{
    if (!(a < b)) b = a + 1;
    if (!(b < c)) c = b + 1;
    D_002A5CB8 = a;
    D_002A5CBC = b;
    D_002A5CC0 = c;
    return func_00274F10(D_002E2250, a, b, c);
}

extern "C" s32 func_001F1CE8(s32 max, s32 init)
{
    CRxSemaParam p;
    p.m_maxCount = max;
    p.m_initCount = init;
    return func_002731A0(&p);
}

extern "C" void func_001F1D10() { D_002A5CDC = func_001F1CE8(1, 1); }

extern "C" s32 func_001F1D38() { return func_002731B0(D_002A5CDC); }

extern "C" s32 func_001F1D58(s32 th)
{
    s32 st[8];
    func_00273210(th, st);
    return st[0];
}

extern "C" s32 func_001F1D78() { return 1; }

extern "C" void func_001F1D80(const char *who)
{
    if (func_001F1D58(D_002A5CDC) == 0) {
        if (D_002A5CD0) Func235DE0(D_002E2280, who);
        if (D_002A5CD8) for (;;) {}
    }
    while (func_002731F0(D_002A5CDC) == -1) {
        func_001F1A80((s32 (*)(s32 *))func_001F1D78, 0, 0, 0);
        func_001F1230();
    }
}

extern "C" s32 func_001F1E50() { return func_002731C0(D_002A5CDC); }

extern "C" s32 func_001F1E70(s32 x)
{
    s32 old = D_002A5CD8;
    D_002A5CD8 = x;
    return old;
}

extern "C" void func_001F1E88()
{
    func_00221028();
    func_0021E760();
    func_0021C698();
    func_00222D08();
    return func_00224D80();
}
