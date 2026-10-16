#ifndef CSTATUSWIN_H
#define CSTATUSWIN_H

#include "common.h"

// Hoisted from the units that declared it locally (tools/bk/hoist.py).
class CStatusWin {
public:
    void SetUnk64(u32 a, int b);
    void SetUnk50(u32 a);
    void Func19F400();
    CStatusItem *Func1A0CF0(const char *name);
    f32 GetItemUnk34_2();
};

#endif
