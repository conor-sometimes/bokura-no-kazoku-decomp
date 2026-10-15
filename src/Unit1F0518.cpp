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
extern "C" s32 func_00274F10(const char *fmt, ...);
extern const char D_002E2200[];
extern s32 D_2FDA20, D_2FDA10, D_2FDA08;
extern "C" s32 func_00273090();
extern "C" s32 func_002731C0(s32 sema);
extern "C" s32 func_002731F0(s32 sema);
extern "C" s32 func_00273220(s32 sema, CRxSemaParam *p);
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

extern "C" s32 func_001F0AC8(s32 th)
{
    func_00272FF0(th);
    return func_00272FB0(th);
}

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F0AF0);

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

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F0CF8);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F0EB0);

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
    return (void)func_00274F10(D_002E2200, fn);
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

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1230);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F13A0);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F15F0);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1610);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F16E8);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1748);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1820);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1830);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1850);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1870);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1890);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F18B0);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F18D0);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F18F0);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1A80);

extern "C" void func_001F1B90(void) {
}

extern "C" void func_001F1B98(void) {
}

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1BA0);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1BD8);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1C20);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1C30);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1C80);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1CE8);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1D10);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1D38);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1D58);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1D78);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1D80);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1E50);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1E70);

INCLUDE_ASM("asm/nonmatchings/Unit1F0518", func_001F1E88);
