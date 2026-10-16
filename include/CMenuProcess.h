#ifndef CMENUPROCESS_H
#define CMENUPROCESS_H

#include "common.h"

// Abstract base of the menu screens (CMenuProcess unit, 0x1B3BA8). Vtable: ~CMenuProcess, Update,
// Draw. The vptr is at 0x54, after CMenuProcess's own fields. Each screen's unit emits its own
// vtable when it defines its destructor (docs/units.md).
class CMenuProcess {
public:
    CMenuProcess();
    virtual ~CMenuProcess();
    virtual s32 Update() = 0;
    virtual s32 Draw() = 0;
    void SetState4();
    void SetState6();
    void SetUnk50(s32 v);

    s16 m_unk0;               // 0x00
    s16 m_unk2;               // 0x02
    s32 m_unk4;               // 0x04
    u8 pad8[0x40];
    s32 m_state;              // 0x48
    s32 m_unk4C;              // 0x4C
    s32 m_unk50;              // 0x50
    // vptr 0x54
};

void Func225088();
s32 Func2250C0();
s32 Func235DE0(const char *fmt, ...) throw();

#endif
