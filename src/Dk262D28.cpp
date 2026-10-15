#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" s32 func_00263870(s32);
extern "C" s32 func_0027BD20(void);
extern "C" s32 func_0027BD78(void);
extern s32 D_41A800;
extern volatile u32 D_41A804;
// @decl-end

extern "C" s32 func_00262D28(s32 x) { register u32 gp asm("$28"); s32 old, r; if (func_00263870(1)) return 0; r = func_0027BD20(); old = D_41A800; D_41A800 = x; D_41A804 = gp; if (r) func_0027BD78(); return old; }

INCLUDE_ASM("asm/nonmatchings/Dk262D28", func_00262D90);

INCLUDE_ASM("asm/nonmatchings/Dk262D28", func_00262E30);

INCLUDE_ASM("asm/nonmatchings/Dk262D28", func_00262FD0);

INCLUDE_ASM("asm/nonmatchings/Dk262D28", func_00263088);

INCLUDE_ASM("asm/nonmatchings/Dk262D28", func_00263140);
