#ifndef IGAMEDBMGR_H
#define IGAMEDBMGR_H

#include "common.h"

// Game database interface (CGameDBMgr unit). CGameDBMgr derives from it; the global instance is
// D_002A2988. Vtable 0x2C0CC8 (_vt$10CGameDBMgr) in slot order; slot 0 is an inline "delete
// this" and the destructor (CGameDBMgr's) comes last. FuncXXXXXX are slots not matched yet (signatures to be fixed
// when they are). No slot is defined in any unit, so no unit emits the vtable.
class CGameDBItem14;
class CGameDBRec14;
class CGameDBRec1C;
class CGameDBRec20;
class CGameDBRec24;
class CGameDBRec24b;
class CGameDBRec28;
class CGameDBRec34;
class CGameDBRec48;
class CGameDBRec5C;
class CGameDBRec74;
class CGameDBRec8;
class CGameDBRecB0;

class IGameDBMgr {
public:
    virtual void Release();                                     // [0] 0x2998B8
    virtual void SetUnk10(s32 v);                               // [1] 0x2998F0
    virtual s32 GetUnk10();                                     // [2] 0x2998F8
    virtual s32 Func147130(const char *path);                   // [3] 0x147130
    virtual void Init();                                        // [4] 0x14BAF8
    virtual s32 GetUnk1C();                                     // [5] 0x299900
    virtual s32 FindType2();                                    // [6] 0x14BB90
    virtual s32 FindType8();                                    // [7] 0x14BBD8
    virtual s32 Collect14BC20(s32 *out, s32 max);               // [8] 0x14BC20
    virtual s32 Func14BD00(s32 a, s32 b, s32 *out, s32 max);                                 // [9] 0x14BD00
    virtual s32 Func14C048(s32 *ids, s32 *flags, s32 name);                                 // [10] 0x14C048
    virtual s32 Func14C2B0(s32 *ids, s32 *flags, s32 name);     // [11] 0x14C2B0
    virtual s32 Func14C490();                                   // [12] 0x14C490
    virtual s32 Func14C648(s32 *out, s32 name);                                   // [13] 0x14C648
    virtual s32 Func14C800(s32 *out, s32 name);                                   // [14] 0x14C800
    virtual s32 Func14C998(s32 name);                                   // [15] 0x14C998
    virtual s32 Func14C9F8(s32 v);                              // [16] 0x14C9F8
    virtual const char *Func14CA38(s32 name);                                   // [17] 0x14CA38
    virtual s32 Func14CC00(s32 *out, s32 name);                                 // [18] 0x14CC00
    virtual s32 Func14CF78(s32 name);                                   // [19] 0x14CF78
    virtual const char *Func14D378(s32 name);                                   // [20] 0x14D378
    virtual s32 Func14D430(s32 *out, s32 name);                 // [21] 0x14D430
    virtual s32 Func14D5F8(s32 *out, s32 name);                 // [22] 0x14D5F8
    virtual void Func14D7C8(f32 *out, s32 idx, s32 v);          // [23] 0x14D7C8
    virtual void Func14DB70(f32 *out, s32 name);                // [24] 0x14DB70
    virtual s32 Func14DCE0();                                   // [25] 0x14DCE0
    virtual s32 GetUnk24();                                     // [26] 0x14E440
    virtual CGameDBRec8 *GetUnk20(s32 i);                       // [27] 0x14E448
    virtual s32 GetUnk14(s32 i);                                // [28] 0x14E480
    virtual char *GetCharaName(s32 id);                         // [29] 0x14E4B8
    virtual s32 GetChara4(s32 id);                              // [30] 0x14E508
    virtual CGameDBItem14 *GetCharaItem(s32 id, s32 j);         // [31] 0x14E550
    virtual u8 *GetCharaD08(s32 id);                            // [32] 0x14E5D0
    virtual u8 *GetCharaD1C(s32 id);                            // [33] 0x14E618
    virtual s32 Func14E660(s32 a, s32 b, s32 c);                                   // [34] 0x14E660
    virtual s32 GetCharaD30(s32 id);                            // [35] 0x14E7C0
    virtual s32 GetCharaD34(s32 id);                            // [36] 0x14E808
    virtual s32 GetCharaD38(s32 id);                            // [37] 0x14E850
    virtual CGameDBRec34 *Find1D0(s32 id);                      // [38] 0x14E898
    virtual CGameDBRec5C *Find1DC(s32 id);                      // [39] 0x14E8E0
    virtual CGameDBRecB0 *Find1E8(s32 id);                      // [40] 0x14E928
    virtual CGameDBRec28 *Find200(s32 id);                      // [41] 0x14E970
    virtual CGameDBRec24 *Find234(s32 id);                      // [42] 0x14EA48
    virtual CGameDBRec1C *Find20C(s32 id);                      // [43] 0x14E9B8
    virtual CGameDBRec14 *Find220(s32 id);                      // [44] 0x14EA00
    virtual CGameDBRec48 *Find38(s32 id);                       // [45] 0x14EA90
    virtual CGameDBRec74 *Find1C4(s32 id);                      // [46] 0x14EAD8
    virtual int CallFunc14EB20Minus(s32 a, s32 b);              // [47] 0x14EBC0
    virtual int CallFunc14EB20Plus(s32 a, s32 b);               // [48] 0x14EBD8
    virtual const char *GetName248(u32 a, s32 b);               // [49] 0x14EBF0
    virtual s32 Func14EC50(s32 key, s32 idx);                   // [50] 0x14EC50
    virtual s32 Func14ECD0(s32 key, s32 idx);                   // [51] 0x14ECD0
    virtual s32 Func14EE18();                                   // [52] 0x14EE18
    virtual s32 Func14F2A0(s32 name);                                   // [53] 0x14F2A0
    virtual s32 Func14F380(s32 name, s32 type);                                   // [54] 0x14F380
    virtual int TestBits14F478(s32 id);                         // [55] 0x14F478
    virtual s32 Func14F550(s32 a, s32 kind, s32 b);                                   // [56] 0x14F550
    virtual s32 Func14F638(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);                                   // [57] 0x14F638
    virtual s32 Func14F760(s32 name, s32 kind);                                 // [58] 0x14F760
    virtual s32 Func14F830(s32 name, s32 kind, s32 bit);                                 // [59] 0x14F830
    virtual s32 Func14F918(s32 a, s32 b);                                   // [60] 0x14F918
    virtual s32 GetUnk1E4();                                    // [61] 0x299908
    virtual s32 GetUnk1D8();                                    // [62] 0x299910
    virtual s32 GetUnk1F0();                                    // [63] 0x299918
    virtual s32 GetUnk208();                                    // [64] 0x299920
    virtual s32 GetUnk1CC();                                    // [65] 0x299928
    virtual s32 GetUnk40();                                     // [66] 0x299930
    virtual s32 GetUnk228();                                    // [67] 0x299938
    virtual s32 GetUnk214();                                    // [68] 0x299940
    virtual s32 GetUnk23C();                                    // [69] 0x299948
    virtual s32 Func14FA08(s32 a, s32 b);                                   // [70] 0x14FA08
    virtual CGameDBRec20 *GetTbl250(s32 i);                     // [71] 0x14FAD0
    virtual s32 GetNum240(s32 i);                               // [72] 0x14FB08
    virtual CGameDBRec24b *Get240(s32 i, s32 j);                // [73] 0x14FB48
    virtual s32 Func14FBB0(s32 name);                                   // [74] 0x14FBB0
    virtual s32 Func14FCC8(s32 i, s32 arg);                                   // [75] 0x14FCC8
    virtual s32 Func14FE60(s32 arg);                                   // [76] 0x14FE60
    virtual void Func14FF30();                                 // [77] 0x14FF30
    virtual s32 Get150550(s32 a, s32 b, s32 c);                 // [78] 0x150550
    virtual s32 Get150590(s32 a, s32 b, s32 c, s32 d);          // [79] 0x150590
    virtual s32 Get1505E0(s32 a, s32 b, s32 c, s32 d);          // [80] 0x1505E0
    virtual s32 Get150630(s32 a, s32 b, s32 c, s32 d);          // [81] 0x150630
    virtual s32 Func150680();                                   // [82] 0x150680
    virtual s32 Find20(s32 id);                                 // [83] 0x150980
    // [84] 0x146FA8: ~CGameDBMgr (declared by CGameDBMgr)
};

extern IGameDBMgr *D_002A2988;

#endif
