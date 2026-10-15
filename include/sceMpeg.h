// libmpeg (Sony SDK, built with ee-gcc 2.9-991111): the public sceMpeg handle and the decoder state
// it points to (mp->sys). Field names are offsets until their meaning is known.
#ifndef SCEMPEG_H
#define SCEMPEG_H
#include "common.h"

struct SceMpeg;

// one registered callback (sceMpegAddCallback): function, user data and the caller's $gp
struct MpegCb {
    s32 m0;
    s32 m4;
    u32 m8;
};

struct MpegBuf {
    u8 pad0[0x28];
    s32 m28;
};

struct MpegSys {
    s32 m0;                     // 0x0
    s32 m4;                     // 0x4
    s32 m8;                     // 0x8
    MpegCb mC[7];               // 0xC
    u8 pad60[0x68 - 0x60];
    u8 m68[0x8C - 0x68];        // 0x68: sub-object (func_0027E260/func_0027E348)
    s32 m8C;                    // 0x8C
    s64 m90;                    // 0x90
    s32 m98;                    // 0x98
    u8 pad9C[0xAC - 0x9C];
    s32 mAC;                    // 0xAC
    s32 mB0;                    // 0xB0
    s32 mB4;                    // 0xB4
    u8 padB8[0xC4 - 0xB8];
    s32 mC4;                    // 0xC4
    s32 mC8;                    // 0xC8
    s32 mCC;                    // 0xCC
    u8 padD0[0xE4 - 0xD0];
    s32 mE4;                    // 0xE4
    s32 mE8;                    // 0xE8
    s32 mEC;                    // 0xEC
    u32 mF0;                    // 0xF0
    s32 mF4;                    // 0xF4
    s32 mF8;                    // 0xF8
    s32 mFC;                    // 0xFC
    s32 m100;                   // 0x100
    u8 pad104[0x108 - 0x104];
    s64 m108;                   // 0x108
    s32 m110;                   // 0x110
    u8 pad114[0x130 - 0x114];
    s32 m130;                   // 0x130
    u8 pad134[0x138 - 0x134];
    s32 m138;                   // 0x138
    s32 m13C;                   // 0x13C: horizontal size
    s32 m140;                   // 0x140: vertical size
    s32 m144;                   // 0x144
    s32 m148;                   // 0x148
    s32 m14C;                   // 0x14C: bit rate
    s32 m150;                   // 0x150: vbv buffer size
    s32 m154;                   // 0x154: progressive sequence
    s32 m158;                   // 0x158: chroma format
    s32 m15C;                   // 0x15C
    s32 m160;                   // 0x160
    s32 m164;                   // 0x164
    u8 pad168[0x18C - 0x168];
    s32 m18C;                   // 0x18C
    u8 pad190[0x1C8 - 0x190];
    s32 m1C8;                   // 0x1C8
    u8 pad1CC[0x1D0 - 0x1CC];
    struct { MpegBuf *m0; MpegBuf *m4; u8 pad8[8]; } m1D0[3];   // 0x1D0
    u8 pad200[0x5A8 - 0x200];
    u32 m5A8;                   // 0x5A8
    u32 m5AC;                   // 0x5AC
    u8 pad5B0[0x6E8 - 0x5B0];
    u32 m6E8;                   // 0x6E8
    u32 m6EC;                   // 0x6EC
    u8 pad6F0[0x828 - 0x6F0];
    s32 m828;                   // 0x828
    u8 pad82C[0x830 - 0x82C];
    s32 m830;                   // 0x830
    u8 pad834[0x858 - 0x834];
    s32 m858;                   // 0x858
    s32 m85C;                   // 0x85C
    s32 m860;                   // 0x860
    u8 pad864[0x870 - 0x864];
    SceMpeg *m870;              // 0x870: the handle that owns this state
    u8 pad874[0x10A0 - 0x874];
    s32 m10A0;                  // 0x10A0
};

// sceMpeg (libmpeg.h): width, height, frameCount, pts/dts pairs, sys at 0x40
struct SceMpeg {
    s32 width;
    s32 height;
    s32 frameCount;
    s64 pts;
    s64 dts;
    u64 flags;
    s64 pts2nd;
    s64 dts2nd;
    u64 flags2nd;
    MpegSys *sys;
};

#endif
