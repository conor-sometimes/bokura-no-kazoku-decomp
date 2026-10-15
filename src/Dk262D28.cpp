#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" s32 func_00263870(s32);
extern "C" s32 func_0027BD20(void);
extern "C" s32 func_0027BD78(void);
extern s32 D_41A800;
extern volatile u32 D_41A804;

extern volatile s32 D_002BBC18;
extern s32 D_002BBC1C;
extern s32 D_002BBBF4;
extern s32 D_002BBBE8;
extern s32 D_002BBBE0;
extern s32 D_002BBBD4;
extern "C" s32 func_002731D0(s32);
#define V(x) (*(volatile s32 *)&(x))

extern s32 D_002BBBEC;
extern s32 D_002BBBF0;
extern "C" s32 func_002731C0(s32);
extern "C" s32 func_002731B0(s32);
extern "C" s32 func_002731A0(void *);
extern "C" s32 func_00275348(u32);
struct SemaParam { s32 count, max_count, init_count, wait_threads; u32 attr, option; };
// @decl-end

extern "C" s32 func_00262D28(s32 x) { register u32 gp asm("$28"); s32 old, r; if (func_00263870(1)) return 0; r = func_0027BD20(); old = D_41A800; D_41A800 = x; D_41A804 = gp; if (r) func_0027BD78(); return old; }

extern "C" void func_00262D90(s32 *p) {
    D_002BBC18 = *p;
    V(D_002BBC1C) = D_002BBC18;
    if (D_002BBC18 == 11) { D_002BBC18 = 0; V(D_002BBBF4) = 0; return; }
    func_002731D0(V(D_002BBBE8));
    if (V(D_002BBBD4) && V(D_41A800)) func_002731D0(V(D_002BBBE0));
    else V(D_002BBBF4) = 0;
    D_002BBC18 = 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk262D28", func_00262E30);

INCLUDE_ASM("asm/nonmatchings/Dk262D28", func_00262FD0);

extern "C" void func_00263088(void) {
    SemaParam sp;
    if (D_002BBBE8 == -1 || D_002BBBEC == -1 || D_002BBBF0 == -1) {
        sp.option = 0; sp.init_count = 1; sp.max_count = 1;
        V(D_002BBBE8) = func_002731A0(&sp); V(D_002BBBEC) = func_002731A0(&sp); V(D_002BBBF0) = func_002731A0(&sp);
        sp.init_count = 0; V(D_002BBBE0) = func_002731A0(&sp); V(D_002BBBF4) = 0;
    }
}

extern "C" void func_00263140(void) {
    s32 r;
    if (D_002BBBD4) { D_002BBC18 = -1; func_002731C0(V(D_002BBBE0)); }
    func_002731B0(D_002BBBE8); func_002731B0(D_002BBBEC); func_002731B0(D_002BBBF0); func_002731B0(D_002BBBE0);
    r = func_0027BD20(); func_00275348(0x80000012); if (r) func_0027BD78();
}
