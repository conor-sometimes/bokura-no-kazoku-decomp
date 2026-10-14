#ifndef ISNAPMGR_H
#define ISNAPMGR_H

#include "CProcess.h"

// Snapshot manager interface (ISnapMgr unit, vtable 0x2BFE90), for virtual calls on the global
// instance D_0029F398 (a CSnapMgr). Slots 7-13 are pure here.
class ISnapMgr : public CTask {
public:
    virtual ~ISnapMgr();                         // [0] (declared so no unit emits the vtable)
    virtual void Start(s32 a, s32 b, s32 c) = 0; // [7]
    virtual s32 Func8() = 0;                    // [8]
    virtual s32 Func9() = 0;                    // [9]
    virtual s32 Func10() = 0;                   // [10]
    virtual s32 Func11() = 0;                   // [11]
    virtual s32 Func12() = 0;                   // [12]
    virtual s32 Func13() = 0;                   // [13]
};

extern ISnapMgr *D_0029F398;

#endif
