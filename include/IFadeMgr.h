#ifndef IFADEMGR_H
#define IFADEMGR_H

#include "CProcess.h"

// Fade manager interface (IFadeMgr unit, vtable 0x2BFD90), for virtual calls on the global
// instance D_0029F394 (a CFadeMgr). Slots 7-13 are pure here.
class IFadeMgr : public CTask {
public:
    virtual ~IFadeMgr();                         // [0] (declared so no unit emits the vtable)
    virtual s32 Func7() = 0;                    // [7]
    virtual s32 Func8() = 0;                    // [8]
    virtual s32 Func9() = 0;                    // [9]
    virtual s32 Func10() = 0;                   // [10]
    virtual s32 Func11() = 0;                   // [11]
    virtual s32 Func12() = 0;                   // [12]
    virtual void Func13(s32 v) = 0;             // [13]
};

extern IFadeMgr *D_0029F394;

#endif
