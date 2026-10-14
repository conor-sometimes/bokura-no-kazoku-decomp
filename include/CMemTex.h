#ifndef CMEMTEX_H
#define CMEMTEX_H

#include "common.h"

// Texture held in memory (0x2541A8, library side of .text). Vtable: ~CMemTex only; the vptr
// follows its fields at 0x28.
class CMemTex {
public:
    CMemTex();                        // 0x2541A8
    virtual ~CMemTex();               // 0x2541E8
    void Func2546F0();

    u8 m_data[0x28];
};

#endif
