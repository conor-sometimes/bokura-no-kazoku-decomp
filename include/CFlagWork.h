#ifndef CFLAGWORK_H
#define CFLAGWORK_H

#include "common.h"

// Flag store (CFlagWork unit). The vptr is at 0x1C, after its own fields.
class CFlagWork {
public:
    CFlagWork(s32 a = 0, s32 b = -1) throw();
    virtual ~CFlagWork();
    virtual void Vf2932F0(s32 v);
    virtual void Vf2932F8(s32 id);
    void Func108700();
    void Func108448(s32 a, s32 b);
    void CopyFrom(CFlagWork *w);
    s32 Save(u8 *buf);
    int Func108E38(const char *name);
    void Func108FF0(s32 id, s32 v);
    int Func1091B0(s32 id);
    void Func109108(s32 id, s32 delta);
    void Func109248(s32 id, s32 lo, s32 hi);
    void SetStr(s32 id, const char *s);

    u8 pad0[0x18];
    s32 m_unk18;              // 0x18
    // vptr 0x1C
};

class ICurFlag;
// The current game's flags (set by ICurFlag's constructor).
extern ICurFlag *D_002A26E4;

// Interface of the current-game flags (vtable _vt$8ICurFlag, slots 3-35 pure).
class ICurFlag : public CFlagWork {
public:
    virtual ~ICurFlag();
    virtual void Release();
    virtual void Vf144880(CFlagWork *src);
    virtual s32 Vf2991B0();
    virtual s32 Vf2991E8();
    virtual s32 Vf299218();
    virtual void SetNamed(s32 base, int name, s32 v) = 0;
    virtual int GetNamed(s32 base, int name) = 0;
    virtual s32 Vf299248(s32 id);
    virtual s32 Vf2992C8(s32 id);
    virtual s32 Vf299348(s32 id);
    virtual s32 Vf2993C8(s32 id);
    virtual s32 Get144B68(s32 base, s32 a, s32 b) = 0;
    virtual void Set144C60(s32 base, s32 a, s32 v, s32 x) = 0;
    virtual int Vf144D68(s32 base, int name, s32 b) = 0;
    virtual void Set144E28(int name, s32 v) = 0;
    virtual int Get145008(s32 base, int name, u32 k) = 0;
    virtual s32 Get145118() = 0;
    virtual void Add145160(s32 id, s32 v) = 0;
    virtual void MoveMoney(s32 v) = 0;
    virtual void Func108FF0Cur(s32 id, s32 v) = 0;
    virtual int Func1091B0Cur(s32 id) = 0;
    virtual void IncCur(s32 id) = 0;
    virtual void Func108FF0Cur2(u32 id, s32 v) = 0;
    virtual void IncCur2(s32 id) = 0;
    virtual int Func1091B0Cur2(s32 id) = 0;
    virtual void Set145398(s32 d) = 0;
    virtual int GetBit1454F0(u32 idx, u32 bit) = 0;
    virtual int Get145558(u32 a, int name) = 0;
    virtual s32 Get1455D0() = 0;
    virtual s32 Select(s32 v) = 0;
    virtual s32 Get1458F0(int name, s32 a, s32 b, s32 c, s32 d, s32 e) = 0;
    virtual void Vf145A28(s32 k) = 0;
    virtual void Vf145AD0(s32 id, s32 off, s32 v) = 0;
};

class CCurFlag : public ICurFlag {
public:
    CCurFlag() throw();
    virtual ~CCurFlag();
    virtual void Vf2932F8(s32 id);
    virtual void SetNamed(s32 base, int name, s32 v);
    virtual int GetNamed(s32 base, int name);
    virtual s32 Get144B68(s32 base, s32 a, s32 b);
    virtual void Set144C60(s32 base, s32 a, s32 v, s32 x);
    virtual int Vf144D68(s32 base, int name, s32 b);
    virtual void Set144E28(int name, s32 v);
    virtual int Get145008(s32 base, int name, u32 k);
    virtual s32 Get145118();
    virtual void Add145160(s32 id, s32 v);
    virtual void MoveMoney(s32 v);
    virtual void Func108FF0Cur(s32 id, s32 v);
    virtual int Func1091B0Cur(s32 id);
    virtual void IncCur(s32 id);
    virtual void Func108FF0Cur2(u32 id, s32 v);
    virtual void IncCur2(s32 id);
    virtual int Func1091B0Cur2(s32 id);
    virtual void Set145398(s32 d);
    virtual int GetBit1454F0(u32 idx, u32 bit);
    virtual int Get145558(u32 a, int name);
    virtual s32 Get1455D0();
    virtual s32 Select(s32 v);
    virtual s32 Get1458F0(int name, s32 a, s32 b, s32 c, s32 d, s32 e);
    virtual void Vf145A28(s32 k);
    virtual void Vf145AD0(s32 id, s32 off, s32 v);
    virtual int Get145090(s32 x);
};

// System flags; interface ISysFlag (slots 3-15 pure).
class ISysFlag : public CFlagWork {
public:
    virtual ~ISysFlag();
    virtual void Vf2990F0() = 0;
    virtual void Vf143BD0() = 0;
    virtual void Load143BD8(CCurFlag *cur) = 0;
    virtual void Load143CD0(CCurFlag *cur) = 0;
    virtual s32 Get143F20(s32 x) = 0;
    virtual void Vf143FA8(u32 a, u32 b, u32 c, u32 bit, s32 set) = 0;
    virtual int GetBit144070(u32 a, u32 b, u32 c, u32 bit) = 0;
    virtual s32 Get1440F8(s32 x) = 0;
    virtual int SumFlags() = 0;
    virtual int GetOption(int k) = 0;
    virtual void Vf144270(s32 base, int name, s32 b, s32 set) = 0;
    virtual int Get144378(s32 base, s32 a, s32 b) = 0;
    virtual void Merge144440(CFlagWork *w) = 0;
};
class CSysFlag : public ISysFlag {
public:
    CSysFlag();
    virtual ~CSysFlag();
    virtual void Vf2932F0(s32 v);
    virtual void Vf2990F0();
    virtual void Vf143BD0();
    virtual void Load143BD8(CCurFlag *cur);
    virtual void Load143CD0(CCurFlag *cur);
    virtual s32 Get143F20(s32 x);
    virtual void Vf143FA8(u32 a, u32 b, u32 c, u32 bit, s32 set);
    virtual int GetBit144070(u32 a, u32 b, u32 c, u32 bit);
    virtual s32 Get1440F8(s32 x);
    virtual int SumFlags();
    virtual int GetOption(int k);
    virtual void Vf144270(s32 base, int name, s32 b, s32 set);
    virtual int Get144378(s32 base, s32 a, s32 b);
    virtual void Merge144440(CFlagWork *w);
    void SetMax(s32 id, s32 v);
    void OrBits(s32 id, s32 bits);
    void Init143A30();
    void Apply(int k);
};

// The system flags.
extern CSysFlag *D_002A26E0;

#endif
