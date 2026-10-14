#ifndef IUSERFLAGMGR_H
#define IUSERFLAGMGR_H

#include "common.h"

// The user-flag script manager as other units call it (D_002A0D38, CUserFlagMgr unit; slots
// as in CUserFlagMgr.cpp's IUserFlagMgr).
class IUserFlagMgr {
public:
    virtual void Release();
    virtual void Vf298B20();
    virtual void Vf13F948();
    virtual void Reset140040();
    virtual void Vf298B48();
    virtual void Vf298B68();
    virtual void Vf298B70();
    virtual void Vf298BB0(s32 v);
    virtual void Vf298C10();
    virtual void Vf298C20();
    virtual void Vf298CC0();
    virtual void Vf298D48();
    virtual void Vf298D68();
    virtual void Vf298D78();
    virtual s32 GetUnk590C();
    virtual void Vf298EE0();
    virtual void Func140088();
    virtual int RunScript(const char *src, int quiet);
    virtual int RunScriptF(const char *fmt, int quiet, ...);
    virtual int Dispatch1411B8(int a, u32 id, int b);
    virtual int Dispatch141280(int a, u32 id, int b);
    virtual int Vf1412D0(int a, u32 id, int b);
    virtual void Vf298D90(s32 v);
};
extern IUserFlagMgr *D_002A0D38;

#endif
