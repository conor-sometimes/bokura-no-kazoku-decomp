#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_0026AA48(s32);
extern "C" s32 func_0026C008(s32, s32);
extern s32 D_002BD940[];

extern "C" s32 func_0026C4A8(void *, s32);
extern "C" s32 func_0026C398(void *, s32);
extern "C" void func_0026CC00(void *);

extern "C" void func_0026BD18(void *);
extern "C" s32 func_0026C278(void *, s32);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026A870);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026A988);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026A9E8);

extern "C" void func_0026AA48(s32 a) { u32 *r = (u32 *)0x10002010; *r = (*r & 0xFF7FFFFF) | (a << 23); }

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026AA70);

extern "C" s32 func_0026AD08(s32 a) { return func_0026C008(a, 3); }

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026AD28);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026AEB0);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026AFC0);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026B0D8);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026B208);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026B408);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026B4C8);

extern "C" void func_0026B970(s32 *pred, s32 r_size, s32 motion_code, s32 motion_residual, s32 full_pel_vector) {
    s32 lim, vec;
    lim = 16 << r_size;
    vec = full_pel_vector ? (*pred >> 1) : (*pred);
    if (motion_code > 0) {
        vec += ((motion_code - 1) << r_size) + motion_residual + 1;
        if (vec >= lim) vec -= lim + lim;
    } else if (motion_code < 0) {
        vec -= ((-motion_code - 1) << r_size) + motion_residual + 1;
        if (vec < -lim) vec += lim + lim;
    }
    *pred = full_pel_vector ? (vec << 1) : vec;
}

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026B9F8);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026BB98);

extern "C" void func_0026BCE8(u8 *p, u32 a) { *(volatile u32 *)0x10002000 = a; *(s32 *)(p + 0x830) = D_002BD940[a >> 28]; }

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026BD18);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026BE80);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026C008);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026C278);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026C398);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026C4A8);

extern "C" void func_0026C618(u8 *d) {
    s32 n;
    func_0026BD18(d);
    n = -(*(volatile u32 *)0x10002020 & 7) & 7;
    if (n) func_0026C398(d, n);
    while (func_0026C278(d, 0x18) != 1 && !*(s32 *)(d + 0x10A0)) func_0026C398(d, 8);
}

extern "C" s32 func_0026C698(u8 *p) { *(s32 *)(p + 0x1CC) = func_0026C4A8(p, 5); if (func_0026C4A8(p, 1)) { func_0026C4A8(p, 1); func_0026C398(p, 7); func_0026CC00(p); } return 0; }

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026C700);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026C820);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026C8E8);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026CA10);

extern "C" void func_0026CC00(void *p) { while (func_0026C4A8(p, 1)) func_0026C398(p, 8); }

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026CC48);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026CCC0);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026CD60);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026CE28);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026CF20);
