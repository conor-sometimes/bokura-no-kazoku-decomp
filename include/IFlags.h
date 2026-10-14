#ifndef IFLAGS_H
#define IFLAGS_H

#include "common.h"

// Flag interfaces (ISysFlag unit, vtables 0x2C0AC8 / 0x2C0BF8), for virtual calls from other units.
// Both derive from CFlagWork (fields 0x00-0x1C, vptr 0x1C; slot 0 the destructor, slots 1-2 its
// inline virtuals). Slot names follow the CCurFlag / CSysFlag implementations where known; VNN are
// unnamed slots (argument types guessed from the callers).
// g_sysFlag-like global D_002A26E0.
class ISysFlag {
public:
    virtual ~ISysFlag();
    virtual void V1();
    virtual void V2();
    virtual s32 V3(s32 a);
    virtual s32 V4(s32 a);
    virtual s32 V5(s32 a);
    virtual s32 V6(s32 a);
    virtual s32 V7(s32 a);
    virtual s32 V8(s32 a);
    virtual s32 V9(s32 a);
    virtual s32 V10(s32 a);
    virtual int SumFlags();
    virtual int GetOption(int k);
    virtual s32 V13(s32 a);
    virtual s32 V14(s32 a);
    virtual s32 V15(s32 a);

    u8 m_flagwork[0x1C];      // 0x00: CFlagWork's fields
    // vptr 0x1C
};
// D_002A26E4.
class ICurFlag {
public:
    virtual ~ICurFlag();
    virtual void V1();
    virtual void V2();
    virtual s32 V3(s32 a);
    virtual s32 V4(s32 a);
    virtual s32 V5();
    virtual s32 V6();
    virtual s32 V7(s32 a);
    virtual void SetNamed(s32 base, int name, s32 v);
    virtual int GetNamed(s32 base, int name);
    virtual s32 V10(s32 a);
    virtual s32 V11(s32 a);
    virtual s32 V12(s32 a);
    virtual s32 V13(s32 a);
    virtual s32 V14(s32 a);
    virtual s32 V15(s32 a);
    virtual s32 V16(s32 a);
    virtual s32 V17(s32 a);
    virtual int Get145008(s32 base, int name, u32 k);
    virtual s32 V19(s32 a);
    virtual s32 V20(s32 a);
    virtual void MoveMoney(s32 v);
    virtual void Func108FF0Cur(s32 id, s32 v);
    virtual int Func1091B0Cur(s32 id);
    virtual s32 V24(s32 a);
    virtual void Func108FF0Cur2(u32 id, s32 v);
    virtual s32 V26(s32 a);
    virtual int Func1091B0Cur2(s32 id);
    virtual s32 V28(s32 a);
    virtual int GetBit1454F0(u32 idx, u32 bit);
    virtual s32 V30(s32 a);
    virtual s32 V31(s32 a);
    virtual s32 Select(s32 v);
    virtual s32 V33(s32 a);
    virtual s32 V34(s32 a);
    virtual int Get145090(s32 x);

    u8 m_flagwork[0x1C];      // 0x00: CFlagWork's fields
    // vptr 0x1C
};
#endif
