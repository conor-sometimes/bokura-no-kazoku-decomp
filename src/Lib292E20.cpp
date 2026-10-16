#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern int func_0027BD20(void);
extern int func_0027BD78(void);
void func_00292E20(unsigned int start, unsigned int end);
void func_00292F60(unsigned int start, unsigned int end);
// @decl-end

// Sony libkernel data-cache maintenance (SyncDCache/InvalidDCache and their internal loops), SDK C built with
// ee-gcc 2.9-991111 (16-byte register save stride): split off Lib290990 by lane lb (Makefile SDKC_UNITS).

void func_00292E20(unsigned int start, unsigned int end)
{
    int i;
    unsigned int tag;

    for (i = 0; i < 0x1000; i += 0x40) {
        asm volatile("sync\n\tcache 0x10, 0(%1)\n\tsync\n\tmfc0 %0, $28" : "=r"(tag) : "r"(i));
        tag = (tag & 0xFFFFF000) + i;
        if (!(tag < start) && !(end < tag))
            asm volatile("sync\n\tcache 0x14, 0(%0)\n\tsync" : : "r"(i));
        asm volatile("sync\n\tcache 0x10, 1(%1)\n\tsync\n\tmfc0 %0, $28" : "=r"(tag) : "r"(i));
        tag = (tag & 0xFFFFF000) + i;
        if (!(tag < start) && !(end < tag))
            asm volatile("sync\n\tcache 0x14, 1(%0)\n\tsync" : : "r"(i));
        asm volatile("sync");
    }
}

void func_00292EC8(unsigned int start, unsigned int end)
{
    int st;

    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st)
        func_0027BD20();
    func_00292E20(start & ~0x3F, end & ~0x3F);
    if (st)
        func_0027BD78();
}

void func_00292F48(unsigned int start, unsigned int end)
{
    func_00292E20(start & ~0x3F, end & ~0x3F);
}

void func_00292F60(unsigned int start, unsigned int end)
{
    int i;
    unsigned int tag;

    for (i = 0; i < 0x1000; i += 0x40) {
        asm volatile("sync\n\tcache 0x10, 0(%1)\n\tsync\n\tmfc0 %0, $28" : "=r"(tag) : "r"(i));
        tag = (tag & 0xFFFFF000) + i;
        if (!(tag < start) && !(end < tag))
            asm volatile("sync\n\tcache 0x16, 0(%0)\n\tsync" : : "r"(i));
        asm volatile("sync\n\tcache 0x10, 1(%1)\n\tsync\n\tmfc0 %0, $28" : "=r"(tag) : "r"(i));
        tag = (tag & 0xFFFFF000) + i;
        if (!(tag < start) && !(end < tag))
            asm volatile("sync\n\tcache 0x16, 1(%0)\n\tsync" : : "r"(i));
        asm volatile("sync");
    }
}

void func_00293008(unsigned int start, unsigned int end)
{
    int st;

    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st)
        func_0027BD20();
    func_00292F60(start & ~0x3F, end & ~0x3F);
    if (st)
        func_0027BD78();
}

void func_00293088(unsigned int start, unsigned int end)
{
    func_00292F60(start & ~0x3F, end & ~0x3F);
}
