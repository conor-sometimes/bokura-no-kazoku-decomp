#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void *func_0024F2E8(s32 size);
extern "C" void func_0024F5C0(void *a, void *b, s32 c);
extern "C" void func_001005D8(void *p);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CBootMain", func_001002A8);

INCLUDE_ASM("asm/nonmatchings/CBootMain", func_001002F0);

INCLUDE_ASM("asm/nonmatchings/CBootMain", func_00100358);

void Func100588(void *a) {
    void *p = func_0024F2E8(0xDC);
    func_001005D8(p);
    func_0024F5C0(a, p, 0);
}
