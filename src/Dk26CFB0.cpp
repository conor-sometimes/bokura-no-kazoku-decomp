#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define SYSCALL(name, n) void name(void) { asm volatile("addiu $3,$0," #n "\n\tsyscall"); }

#define HWREG(a) (*(volatile u32 *)(a))
typedef struct BitStr { u64 m0; u32 m8; u8 *mC; u32 m10; u32 pad14; u64 m18; u8 *m20; u8 *m24; u32 m28; } BitStr;
extern u8 D_002BD9C0[];
extern u32 D_002BDA10[];
int func_00289230();
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026CFB0);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026D080);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026D110);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026D3C8);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026D468);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026D6F8);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026D720);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026D898);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026D9A8);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026DB60);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026DCD0);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026DD58);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026DE80);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026DFC8);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026E188);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026E260);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026E4E8);

s32 func_0026E520(BitStr *s, s32 n) { return (s32)(s->m0 >> (64 - n)); }

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026E540);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026E5D8);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026E628);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026E670);

u8 *func_0026E6C8(BitStr *s, s32 n) { u8 *p = (u8 *)s->m8 + (n >> 3); if (p >= s->m24) p -= s->m28; return p; }

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026E6F8);

void *func_0026E888(void) { return D_002BD9C0; }

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026E898);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026E900);

SYSCALL(func_0026E9A0, 0x80)

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026E9B0);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026ED28);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026EDE8);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026EFD0);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026F0D8);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026F2C0);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026F400);

INCLUDE_ASM("asm/nonmatchings/Dk26CFB0", func_0026F580);
