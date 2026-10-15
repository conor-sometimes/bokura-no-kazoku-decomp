#ifndef CCOMMANDBASE_H
#define CCOMMANDBASE_H

#include "common.h"

// Command menu base (CCommandBase unit, 0x198080). Vtable: Update, Draw, both pure (no virtual
// destructor). The vptr follows CCommandBase's fields at 0x4E8. Subclasses: CCommandSelect,
// CCommandIncDec.
class CCommandBase {
public:
    CCommandBase();                   // 0x198080
    s32 NumRows();                    // 0x1984E0
    virtual s32 Update() = 0;
    virtual s32 Draw() = 0;

    u8 pad0[0x4D4];
    s32 m_cursor;             // 0x4D4
    u8 pad4D8[0x10];
    // vptr 0x4E8
};

#endif
