#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "libc.h"
extern "C" void *memcpy(void *d, const void *s, u32 n);
struct Ring { s32 m0, m4, m8, mC, m10; u8 pad[0x2C]; u8 data[1]; };
typedef Ring *(*AllocFn)(s32);
typedef void (*FreeFn)(void *);
extern AllocFn D_002B91A4;
extern FreeFn D_002B91B0;
extern s32 D_002B9D94;
extern "C" void func_002454D8(Ring *);
extern "C" s32 func_00245510(Ring *);
// @decl-end

extern "C" s32 func_00245450(void) {
    return D_002B9D94;
}

extern "C" Ring *func_00245460(s32 n) {
    Ring *r = D_002B91A4(n + 0x40);
    if (r) {
        r->m10 = n;
        func_002454D8(r);
    }
    return r;
}

extern "C" void func_002454B0(void *p) {
    if (p) D_002B91B0(p);
}

extern "C" void func_002454D8(Ring *r) {
    r->m0 = 0;
    r->m4 = 0;
    r->m8 = 0;
    r->mC = 0;
}

extern "C" s32 func_002454F0(Ring *r) {
    s32 v = r->m10 - r->m4;
    if (r->m8 < v) v = r->m8;
    return v;
}

extern "C" s32 func_00245510(Ring *r) {
    return r->m8;
}

extern "C" s32 func_00245518(Ring *r) {
    return r->m10 - func_00245510(r);
}

extern "C" void func_00245548(Ring *r, const u8 *src, s32 n) {
    while (n > 0) {
        s32 k = r->m10 - r->m0;
        if (n < k) k = n;
        if (k < 0) k = 0;
        memcpy(&r->data[r->m0], src, k);
        n -= k;
        src += k;
        r->m0 = (r->m0 + k) % r->m10;
        r->m8 += k;
    }
}

extern "C" u8 *func_00245600(Ring *r) {
    return &r->data[r->m4];
}

extern "C" void func_00245618(Ring *r, s32 k) {
    r->m8 -= k;
    r->m4 = (r->m4 + k) % r->m10;
}
