#ifndef CUSERFLAGMGR_H
#define CUSERFLAGMGR_H

#include "common.h"

// Script flag manager (CUserFlagMgr unit, vtable 0x2C07D8), declared for virtual calls from other
// units only: CUserFlagMgr.cpp has its own declaration. The global instance is D_002A0D38. Slot
// names follow the CUserFlagMgr functions where known; VNN are unnamed slots (signatures from the
// callers).
class CUserFlagMgr {
public:
    virtual s32 V0();
    virtual s32 V1();
    virtual s32 V2();
    virtual s32 V3();
    virtual s32 V4();
    virtual s32 V5();
    virtual s32 V6();
    virtual void V7(s32 a);
    virtual s32 V8();
    virtual void V9();
    virtual void V10();
    virtual s32 V11();
    virtual s32 V12();
    virtual s32 V13();
    virtual s32 V14();
    virtual s32 V15();
    virtual s32 V16();
    virtual s32 RunScript(const char *script, int v);
    virtual s32 V18(s32 a, s32 b, s32 c, s32 d);
    virtual s32 Dispatch1411B8(int a, unsigned int b, int c);
    virtual s32 V20();
    virtual s32 V21();
    virtual s32 V22();
    virtual void V23();
    virtual void V24();
    virtual s32 V25();
    virtual void SetBit(int i);
    virtual int GetBit(int i);
    virtual s32 V28();
    virtual s32 V29();
    virtual s32 V30();
    virtual s32 V31();
    virtual s32 V32();
    virtual s32 V33();
    virtual s32 V34();
};

extern CUserFlagMgr *D_002A0D38;

#endif
