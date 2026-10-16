#ifndef CMEMTEX_H
#define CMEMTEX_H
#pragma interface

#include "common.h"

// Texture held in memory (0x2541A8, library side of .text). Vtable: ~CMemTex only; the vptr
// follows its fields at 0x28.
class CMemTex {
public:
    CMemTex();                        // 0x2541A8
    virtual ~CMemTex();               // 0x2541E8
    void Func2546F0();

    void *m_unk0;             // 0x0 (pixels, freed through D_002B91B0)
    s32 m_unk4;               // 0x4
    s32 m_unk8;               // 0x8
    s32 m_unkC;               // 0xC
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
    s32 m_unk24;              // 0x24
};

#endif
