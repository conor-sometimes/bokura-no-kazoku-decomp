#ifndef CGAMEDBMGR_H
#define CGAMEDBMGR_H

#include "common.h"

// A database record as Find234 returns it.
struct CGameDBRec {
    s32 m_unk0;               // 0x00
    s32 m_unk4;               // 0x04
    const char *m_unk8;       // 0x08
    u8 padC[0x4];
    const char *m_unk10;      // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
};

// Game database (CGameDBMgr unit); only the virtual calls are declared so far. vptr at 0.
class CGameDBMgr {
public:
    virtual void Vf2998B8();
    virtual void Vf2998F0();
    virtual void Vf2998F8();
    virtual void Vf147130();
    virtual void Init();
    virtual void Vf299900();
    virtual void FindType2();
    virtual s32 FindType8();
    virtual s32 Collect14BC20(s32 *out, s32 max);
    virtual void Vf14BD00();
    virtual s32 Vf14C048(s32 *ids, s32 *vals, s32 k);
    virtual s32 Vf14C2B0(s32 *ids, s32 *vals, s32 k);
    virtual s32 Vf14C490(s32 *ids, s32 *vals, s32 k);
    virtual s32 Vf14C648(s32 *ids, s32 k);
    virtual s32 Vf14C800(s32 *ids, s32 k);
    virtual void Vf14C998();
    virtual void Func14C9F8();
    virtual void Vf14CA38();
    virtual s32 Vf14CC00(s32 *out, s32 i);
    virtual void Vf14CF78();
    virtual void Vf14D378();
    virtual s32 Vf14D430(s32 *out, s32 i);
    virtual s32 Vf14D5F8(s32 *out, s32 i);
    virtual void Vf14D7C8();
    virtual void Vf14DB70();
    virtual s32 Vf14DCE0(s32 a, s32 b, s32 c);
    virtual void GetUnk24();
    virtual CGameDBRec *GetUnk20(s32 id);
    virtual void GetUnk14();
    virtual void GetCharaName();
    virtual void GetChara4();
    virtual void GetCharaItem();
    virtual void GetCharaD08();
    virtual void GetCharaD1C();
    virtual void Vf14E660();
    virtual void GetCharaD30();
    virtual void GetCharaD34();
    virtual void GetCharaD38();
    virtual void Find1D0();
    virtual void *Find1DC(int id);
    virtual CGameDBRec *Find1E8(s32 id);
    virtual CGameDBRec *Find200(s32 id);
    virtual CGameDBRec *Find234(s32 id);
    virtual CGameDBRec *Find20C(s32 id);
    virtual CGameDBRec *Find220(s32 id);
    virtual void Find38();
    virtual void Find1C4();
    virtual void CallFunc14EB20Minus();
    virtual void CallFunc14EB20Plus();
    virtual char *GetName248(u32 a, int b);
    virtual const char *Func14EC50(s32 a, s32 b);
    virtual const char *Func14ECD0(s32 a, s32 b);
    virtual s32 Vf14EE18(s32 k);
    virtual s32 Vf14F2A0(s32 k);
    virtual s32 Vf14F380(s32 a, s32 b);
    virtual s32 TestBits14F478(s32 id);
    virtual s32 Vf14F550(s32 a, s32 b, s32 c);
    virtual s32 Vf14F638(int name, s32 a, s32 b, s32 c, s32 d, s32 e);
    virtual void Vf14F760();
    virtual void Vf14F830();
    virtual s32 Vf14F918(s32 a, s32 b);
    virtual void Vf299908();
    virtual void Vf299910();
    virtual void Vf299918();
    virtual void Vf299920();
    virtual void Vf299928();
    virtual void Vf299930();
    virtual void Vf299938();
    virtual void Vf299940();
    virtual void Vf299948();
    virtual void Vf14FA08();
    virtual void GetTbl250();
    virtual void GetNum240();
    virtual void Get240();
    virtual void Vf14FBB0();
    virtual void Vf14FCC8();
    virtual s32 Vf14FE60(s32 v);
    virtual void Vf14FF30();
    virtual void Get150550();
    virtual s32 Get150590(s32 a, s32 b, s32 c, s32 d);
    virtual void Get1505E0();
    virtual s32 Get150630(s32 a, s32 b, s32 c, s32 d);
    virtual s32 Vf150680(f32 v);
    virtual void Find20();
    virtual void Vf146FA8();
};
extern CGameDBMgr *D_002A2988;

#endif
