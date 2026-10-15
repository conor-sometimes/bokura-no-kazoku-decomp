#ifndef XMN_H
#define XMN_H

#include "common.h"

// XMN model/animation runtime (C code after CAppMain, 0x1EA9xx-0x1F2xxx; header "XMN(C)SCEI/SD1").

// Allocator hooks (function pointers set at startup).
extern void *(*D_002B91A4)(u32 n);      // malloc
extern void (*D_002B91B0)(void *p);     // free

// Animation table: D_002A5BD0[D_002A5BCC].
struct CXmnAnim {
    u16 m_unk0;               // 0x0
    u16 m_id;                 // 0x2
    char *m_mask;             // 0x4 (per node: shown)
    u16 m_unk8;               // 0x8
    u16 m_unkA;               // 0xA
    f32 m_rate;               // 0xC
    s32 m_flags;              // 0x10 (bit 0: stopped)
    u32 m_nodeCount;          // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
};
extern s32 D_002A5BCC;
extern CXmnAnim **D_002A5BD0;
inline CXmnAnim *GetXmnAnim(s32 i) { return (i >= 0 && i < D_002A5BCC) ? D_002A5BD0[i] : 0; }

#endif
