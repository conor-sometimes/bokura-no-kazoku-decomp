#ifndef CPUSHBUF_H
#define CPUSHBUF_H

#include "common.h"

// Text buffer object (0x248BB8, library side of .text). Vtable: ~CPushBuf only; the vptr
// follows its two fields at 0x8. The DB managers embed one at 0x4 (destroyed with in_chrg 2).
class CPushBuf {
public:
    CPushBuf();
    virtual ~CPushBuf();
    void Func248E00();
    int Func248EB0();
    void *Func248CC8(s32 size, s32 a, s32 b);
    void Func248EE0(void *p);

    s32 m_unk0;               // 0x0
    s32 m_unk4;               // 0x4
};

#endif
