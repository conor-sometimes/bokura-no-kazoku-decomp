#ifndef CBGWORK_H
#define CBGWORK_H
#pragma interface

#include "common.h"

// Background work object (0x2456F8, library side of .text). Vtable: ~CBgWork only; the vptr
// follows its two fields at 0x8. Menu screens embed one (destroyed with in_chrg 2).
class CBgWork {
public:
    CBgWork();
    virtual ~CBgWork();

    s32 m_unk0;               // 0x0
    s32 m_unk4;               // 0x4
};

// Sets the background mode (library, 0x245818).
extern "C" int func_00245818(void *p, s32 v);

#endif
