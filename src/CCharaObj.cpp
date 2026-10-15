#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
// CSwingBoneObj.cpp: vptr at 0x30.
class CSwingBoneObj {
public:
    virtual ~CSwingBoneObj();
    void Release();

    u8 pad0[0x2C];
    f32 m_unk2C;              // 0x2C
};
// CDiffMotionObj unit (another lane's): vptr at 0x24; 0x10FC98 releases it.
class CDiffMotionObj {
public:
    virtual ~CDiffMotionObj();

    u8 pad0[0x18];
    f32 m_unk18;              // 0x18
    f32 m_unk1C;              // 0x1C
    u8 pad20[0x4];
};
extern "C" void func_0010FC98(CDiffMotionObj *p);
// CFaceObj.cpp: vptr at 0x50.
class CFaceObj {
public:
    CFaceObj();
    virtual ~CFaceObj();
    void Release();
    void Func10DC80();
    void Func10DBD8();
    void Func10DB70();

    u8 pad0[0x18];
    s32 m_unk18;              // 0x18
    u8 pad1C[0x34];
};
class CVec4 {
public:
    f32 x, y, z, w;
};

typedef int u128 __attribute__((mode(TI)));
struct CMat4 {
    u128 m[4];
};

class CCharaRes {
public:
    s32 GetCur8();
    s32 Get44(s32 v);
    s32 GetCurFlags();
    s32 Get48(s32 v);

    u8 pad0[0x1C];
    s32 m_unk1C;              // 0x1C
    u8 pad20[0x60];
    s32 m_unk80;              // 0x80
    u8 pad84[0x34];
    s32 m_unkB8;              // 0xB8
};

class CCharaObjSub48 {
public:
    void Func252BB8();
};

// CModelAccResMgr (its unit starts after this file); only its size is needed here.
class CModelAccResMgr {
public:
    CModelAccResMgr();

    u8 pad0[0x40];
};

void Func270C50(CVec4 *dst, const CVec4 *src);
void Func24B600(char *dst, const char *src, s32 n);
f32 Func1EAC30(s32 i);
s32 Func113368(s32 i, s32 v);
void Func117E38(void *dst, s32 *src);
CModelAccResMgr *CreateSub117F98();
extern void (*D_002B91B0)(void *p);
extern "C" int func_001ECCA8(s32 h);
extern u8 *D_002A5D0C;
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);

class CCharaObj {
public:
    void Part24Func10DC80();
    void Part24Func10DBD8();
    void Part24Func10DB70();
    void SetPart1CUnk2C(f32 v);
    void SetPart20Unk18(f32 v);
    void Func114050(s32 a, s32 b, f32 f);
    void CallFunc114050(s32 b, f32 f);
    void SetUnk150(s32 v);
    void SetPart24Unk18(s32 v);
    s32 GetPart24Unk18();
    void SetUnk354(u32 i, s32 v);
    s32 GetUnk354(u32 i);
    void Func113860(s32 v);
    void Release113758();
    void ReleaseSwing();
    void ReleaseDiff();
    void Func113128();
    void Func114D70(s32 a, s32 b);
    void Func113898();
    void Func1138E8();
    s32 GetResIndex();
    s32 Func113F38();
    f32 Func114670();
    void Func114828(CVec4 *a, CVec4 *b);
    void Func1159A0(s32 a, s32 i, f32 f);
    void Func116A40(u32 i);
    void Func116A98(s32 *src, s32 n);
    s32 Func115388();
    void Func1158C0(s32 id, const char *name, s32 a, s32 b);
    void Func1159E8(const CVec4 *v, s32 n);
    void Func115830(CVec4 *v, s32 n, s32 m);
    void Func115938(s32 a, s32 b, f32 x, f32 y);
    s32 Func117898(s32 a, s32 b);
    s32 Func117AC8(s32 a, s32 b);
    s32 Func117B48(s32 a, s32 b, s32 c);
    s32 Func117DA0(s32 a, s32 b, s32 c);
    s32 Func117F10(s32 v);
    void Func117E78();
    void Func115328(f32 v);
    void Func115278(struct CCharaNameSrc *src, const char *name);
    s32 Func1153E8();
    s32 Func115A98();
    void Func114D18(s32 v);
    s32 Func115B48();
    s32 Func113F80();
    void Func117668(s32 v);
    s32 Func1170F0();
    void Func116AE0();
    void Func117468(s32 mode, s32 p);
    void Func1146A8(f32 target, s32 n, s32 dir);
    void Func1156A8(f32 target, s32 turn, s32 n, s32 k, f32 a, f32 b);
    s32 Func1135F0(CCharaRes *res);

    u8 pad0[0x10];
    s32 m_unk10;              // 0x10
    CCharaRes *m_res;         // 0x14
    s32 m_unk18;              // 0x18
    CSwingBoneObj* m_part1C;  // 0x1C
    CDiffMotionObj* m_part20; // 0x20
    CFaceObj* m_part24;       // 0x24
    void *m_unk28;            // 0x28
    void *m_unk2C;            // 0x2C
    void *m_unk30;            // 0x30
    void *m_unk34;            // 0x34
    s32 m_unk38;              // 0x38
    s32 m_unk3C;              // 0x3C
    s32 m_unk40;              // 0x40
    s32 m_unk44;              // 0x44
    CCharaObjSub48 m_unk48;   // 0x48
    u8 pad49[0x13];
    s32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
    s32 m_unk64;              // 0x64
    u8 pad68[0x4];
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
    s32 m_unk78;              // 0x78
    f32 m_unk7C;              // 0x7C
    f32 m_unk80;              // 0x80
    f32 m_unk84;              // 0x84
    f32 m_unk88;              // 0x88
    s32 m_unk8C;              // 0x8C
    s32 m_unk90;              // 0x90
    s32 m_unk94;              // 0x94
    u8 pad98[0x8];
    CVec4 m_unkA0;            // 0xA0
    CVec4 m_unkB0;            // 0xB0
    f32 m_unkC0;              // 0xC0
    f32 m_unkC4;              // 0xC4
    f32 m_unkC8;              // 0xC8
    u8 padCC[0x4];
    CVec4 m_unkD0;            // 0xD0
    CMat4 m_unkE0;            // 0xE0
    CVec4 m_unk120;           // 0x120
    f32 m_unk130;             // 0x130
    f32 m_unk134;             // 0x134
    s32 m_unk138;             // 0x138
    f32 m_unk13C;             // 0x13C
    s32 m_unk140;             // 0x140
    u8 pad144[0xC];
    s32 m_unk150;             // 0x150
    u8 pad154[0x4];
    s32 m_unk158;             // 0x158
    s32 m_unk15C;             // 0x15C
    s32 m_unk160;             // 0x160
    s32 m_unk164;             // 0x164
    u8 pad168[0x8];
    s32 m_unk170;             // 0x170
    s32 m_unk174;             // 0x174
    u8 pad178[0x4];
    s32 m_unk17C[2];          // 0x17C
    s32 m_unk184;             // 0x184
    u8 pad188[0x8];
    CVec4 m_unk190;           // 0x190
    s32 m_unk1A0;             // 0x1A0
    s32 m_unk1A4;             // 0x1A4
    char m_unk1A8[0x10];      // 0x1A8
    char m_unk1B8[0x10];      // 0x1B8
    u8 pad1C8[0xC0];
    s32 m_unk288;             // 0x288
    s32 m_unk28C;             // 0x28C
    u8 pad290[0x4];
    s32 m_unk294;             // 0x294
    u8 pad298[0x8];
    CVec4 m_unk2A0;           // 0x2A0
    CVec4 m_unk2B0;           // 0x2B0
    s32 m_unk2C0;             // 0x2C0
    s32 m_unk2C4;             // 0x2C4
    f32 m_unk2C8;             // 0x2C8
    f32 m_unk2CC;             // 0x2CC
    s32 m_unk2D0;             // 0x2D0
    s32 m_unk2D4;             // 0x2D4
    s32 m_unk2D8;             // 0x2D8
    s32 m_unk2DC;             // 0x2DC
    CVec4 m_unk2E0;           // 0x2E0
    CVec4 m_unk2F0;           // 0x2F0
    s32 m_unk300;             // 0x300
    s32 m_unk304;             // 0x304
    s32 m_unk308;             // 0x308
    s32 m_unk30C;             // 0x30C
    char m_name[0x20];        // 0x310
    s32 m_unk330;             // 0x330
    s32 m_unk334;             // 0x334
    s32 m_unk338;             // 0x338
    u8 pad33C[0x4];
    CVec4 m_unk340;           // 0x340
    s32 m_unk350;             // 0x350
    s8 m_unk354[6];           // 0x354
    s8 m_unk35A[6][2];        // 0x35A
};

//@sym memcpy 0x289DFC
//@sym __builtin_new 0x245648

class CSwingBoneObjSub1114C0 {
public:
    f32 GetUnk10(s32 i);
};
extern "C" void func_00111490(void *p, f32 v);
extern "C" void func_00227460(s32 n);
extern "C" void func_002279D0(void *p, s32 h, s32 a, s32 b);
extern "C" s32 func_00284B98(f32 v);
extern "C" s32 func_002852C0(s32 a, s32 b);
extern "C" char *strncpy(char *d, const char *s, unsigned int n);
extern "C" int strcmp(const char *a, const char *b);
extern "C" void func_00252E18(void *p, s32 a, s32 b);
extern "C" s32 func_001EADA0(s32 a);
extern "C" s32 func_0020F948(s32 a);
extern "C" s32 func_0020F998(s32 a);
extern "C" s32 func_0020E488(s32 a, s32 b);
extern "C" s32 func_0020F9E8(s32 a);
extern s32 D_002A0444;
extern s32 D_002A0448;
extern u128 D_002D36C0, D_002D36D0, D_002D36E0, D_002D36F0;
inline s32 Max(s32 a, s32 b) { return a > b ? a : b; }
struct CCharaNameTbl {
    s32 m_count;
    u8 pad4[0xC];
    const char *m_names[1];
};
struct CCharaResEntry {
    u8 pad0[0x10];
    CCharaNameTbl *m_tbl;
};
struct CCharaNameSrc {
    u8 pad0[0x14];
    u8 *m_unk14;
};

struct CCharaObjEnt {
    s32 m0;
    u8 pad4[0x4];
    s32 m8;
    u8 padC[0x28];
};
struct CCharaObjEntTbl {
    s32 m_count;
    CCharaObjEnt *m_ents;
};
extern "C" void func_00270A98(CVec4 *d, const CVec4 *a, const CVec4 *b);
extern "C" void func_00270B68(CVec4 *d, const CVec4 *a, f32 s);
extern "C" void func_00270A30(CVec4 *d, const CVec4 *a, const CVec4 *b);
extern "C" void func_0010D8F8(CFaceObj *p, s32 v);
void Func113418(void *out, s32 a, s32 b, s32 c);
extern s32 D_002A0498;
extern s32 D_002A049C;

extern "C" s32 func_001EB920(s32 p, s32 i);
extern "C" s32 func_001ECDC8(s32 h);
void Func10ADD0();
void ClearFunc1EB828And1EB838();
int Func235DE0(const char *fmt, ...);
extern const char D_002D3680[];

extern f32 D_002A6800[];
inline s32 FtoI15(f32 f) {
    s32 r;
    asm volatile("mfc1 %0, %1\n\tqmtc2.ni %0, $vf2\n\tvftoi15.x $vf2, $vf2\n\tqmfc2.ni %0, $vf2" : "=r"(r) : "f"(f));
    return r;
}
inline f32 TblSin(f32 a) { return D_002A6800[(FtoI15(a) >> 1) & 0x3FFF]; }
inline f32 TblCos(f32 a) { return D_002A6800[(((FtoI15(a) >> 1) & 0x3FFF) + 0x1000) & 0x3FFF]; }

#define VU_CALL(ms) asm volatile("vcallms %0" : : "i"(ms))
#define VU_VEC(p, ms) asm volatile("qmfc2.i $0, $vf0\n\tlqc2 $vf4, 0x0(%0)\n\tvnop\n\tvnop\n\tvcallms %1" : : "r"(p), "i"(ms))
#define VU_MAT(p, ms) asm volatile("qmfc2.i $0, $vf0\n\tlqc2 $vf4, 0x0(%0)\n\tlqc2 $vf5, 0x10(%0)\n\tlqc2 $vf6, 0x20(%0)\n\tlqc2 $vf7, 0x30(%0)\n\tvnop\n\tvnop\n\tvcallms %1" : : "r"(p), "i"(ms))
inline void VuStoreMat(void *p) {
    register void *r asm("$2") = p;
    asm volatile("vcallms 0x0\n\tqmfc2.i $0, $vf0\n\tsqc2 $vf24, 0x0(%0)\n\tsqc2 $vf25, 0x10(%0)\n\tsqc2 $vf26, 0x20(%0)\n\tsqc2 $vf27, 0x30(%0)\n\tvcallms 0x40" : : "r"(r) : "memory");
}
#define VU_ROT(a, ms) do { \
    s32 i_ = (FtoI15(a) >> 1) & 0x3FFF; \
    s32 s_ = ((s32 *)D_002A6800)[i_]; \
    s32 c_ = ((s32 *)D_002A6800)[(i_ + 0x1000) & 0x3FFF]; \
    asm volatile("qmtc2.i %0, $vf4\n\tqmtc2.ni %1, $vf5\n\tvnop\n\tvnop\n\tvcallms %2" : : "r"(c_), "r"(s_), "i"(ms)); \
} while (0)

extern "C" void func_00115E48(CCharaObj *p);
extern "C" void func_001141F0(CCharaObj *p, s32 v);
extern "C" void func_00114EA0(CCharaObj *p);
extern "C" void func_00116D60(CVec4 *a, f32 *b, CVec4 *c, CMat4 *d, s32 e, s32 f);
extern "C" f32 func_00116B98(s32 ri, CMat4 *m, void *p, s32 v);
inline f32 VuFrac(f32 x) {
    f32 r;
    asm volatile("mfc1 $2, %1\n\tqmtc2.ni $2, $vf2\n\tvftoi0.x $vf3, $vf2\n\tvmulaw.x ACC, $vf2, $vf0w\n\tvaddw.x $vf2, $vf0, $vf0w\n\tvitof0.x $vf3, $vf3\n\tbgez $2, 1f\n\tvmadda.x ACC, $vf2, $vf2\n1:\n\tvmsubw.x $vf2, $vf3, $vf0w\n\tqmfc2.ni $8, $vf2\n\tmtc1 $8, %0" : "=f"(r) : "f"(x) : "$2", "$8");
    return r;
}

inline f32 VuDot3(CVec4 *a, CVec4 *b) {
    f32 r;
    asm volatile("lqc2 $vf2, 0x0(%1)\n\tlqc2 $vf3, 0x0(%2)\n\tvmul.xyz $vf3, $vf2, $vf3\n\tvaddy.x $vf3, $vf3, $vf3y\n\tvaddz.x $vf3, $vf3, $vf3z\n\tqmfc2.ni $8, $vf3\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8");
    return r;
}
inline f32 FSqrt(f32 x) {
    f32 r;
    asm("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" CMat4 *func_00202368();
extern "C" f32 func_0021ACA8(f32 x, f32 z);
inline void VuApplySelf(CVec4 *p) {
    asm volatile("vcallms 0x0\n\tqmfc2.i $0, $vf0\n\tlqc2 $vf4, 0x0(%0)\n\tvmulax.xyzw ACC, $vf24, $vf4x\n\tvmadday.xyzw ACC, $vf25, $vf4y\n\tvmaddaz.xyzw ACC, $vf26, $vf4z\n\tvmaddw.xyzw $vf4, $vf27, $vf4w\n\tsqc2 $vf4, 0x0(%0)" : : "r"(p) : "memory");
}

void Func225088();
int Func2250C0();
void Func2251E8();
extern "C" void func_002250E8(s32 a);
extern "C" void func_00225258(CMat4 *m);
extern "C" void func_00226478(s32 a, s32 b, void *c);
extern "C" void func_002264D8(s32 a, s32 b, void *c);
extern "C" void func_00226568(s32 a, s32 b, void *c);
extern "C" void func_00227A20();
extern "C" void func_00227AA8();
extern CVec4 D_002A05B0;
void Func1173C0(void *a, void *b, void *c, void *d, s32 h);
extern u8 D_002A04C0[], D_002A0540[], D_002A05A0[];
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00112FE0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113090);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", Func113128__9CCharaObj);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", Func113368__Fii);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", Func113418__FPviii);

s32 CCharaObj::Func1135F0(CCharaRes *res) {
    Release113758();
    m_res = res;
    m_part24 = new CFaceObj;
    m_unk28 = 0;
    m_unk2C = 0;
    m_unk34 = 0;
    m_unk38 = 1;
    m_unk3C = -1;
    m_unk44 = res->m_unkB8;
    m_unk5C = -1;
    m_unk60 = -1;
    m_unk64 = 0;
    m_unk6C = 1;
    s32 cur = m_res->GetCur8();
    if (cur >= 0) {
        switch (m_res->GetCurFlags()) {
        case 0:
        default:
            m_unk3C = 0;
            break;
        case 1:
            m_unk3C = 1;
            break;
        }
        m_unk40 = 0;
        m_unk28 = (void *)func_001EADA0(cur);
        m_unk2C = (void *)func_001EADA0(cur);
        m_unk34 = (void *)func_001EADA0(cur);
        m_unk5C = Func113368(cur, D_002A0498);
        m_unk60 = Func113368(cur, D_002A049C);
        if (m_unk60 >= 0) {
            f32 buf[16];
            Func113418(buf, cur, 0, m_unk60);
            m_unk13C = 3.0f - buf[13];
        }
    }
    Func1138E8();
    if (m_res->m_unk1C) {
        func_0010D8F8(m_part24, m_res->m_unk1C);
    }
    return 1;
}

void CCharaObj::Release113758() {
    if (m_res) {
        Func114D70(0, -1);
        Func113898();
        ReleaseSwing();
        ReleaseDiff();
        if (m_unk34) {
            D_002B91B0(m_unk34);
            m_unk34 = 0;
        }
        if (m_unk28) {
            D_002B91B0(m_unk28);
            m_unk28 = 0;
        }
        if (m_unk2C) {
            D_002B91B0(m_unk2C);
            m_unk2C = 0;
        }
        if (m_part24) {
            m_part24->Release();
            delete m_part24;
            m_part24 = 0;
        }
        if (m_unk70 >= 0) {
            func_001ECCA8(m_unk70);
            m_unk70 = -1;
        }
        Func113128();
        m_res = 0;
    }
}

void CCharaObj::Func113860(s32 v) {
    Func113898();
    m_unk18 = v;
    return Func1138E8();
}

void CCharaObj::Func113898() {
    if (m_unk30) {
        D_002B91B0(m_unk30);
        m_unk30 = 0;
    }
    m_unk48.Func252BB8();
    m_unk18 = 0;
}

void CCharaObj::Func1138E8() {
    if (m_unk30) {
        D_002B91B0(m_unk30);
        m_unk30 = 0;
    }
    s32 r = GetResIndex();
    if (r >= 0) {
        s32 k = Func113F80();
        if (k >= 0) {
            func_00252E18(&m_unk48, k, r);
            m_unk30 = (void *)func_001EADA0(k);
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3588);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3590);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D35A0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D35B0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D35C0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D35D0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D35E0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D35F0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3600);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3610);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3620);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3630);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3638);
INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113978);

void CCharaObj::ReleaseSwing() {
    if (m_part1C) {
        m_part1C->Release();
        delete m_part1C;
        m_part1C = 0;
    }
}

void CCharaObj::SetPart1CUnk2C(f32 v) {
    if (m_part1C) {
        m_part1C->m_unk2C = v;
    }
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113C38);

void CCharaObj::ReleaseDiff() {
    if (m_part20) {
        func_0010FC98(m_part20);
        delete m_part20;
        m_part20 = 0;
    }
}

void CCharaObj::SetPart20Unk18(f32 v) {
    if (m_part20) {
        m_part20->m_unk18 = v;
    }
}

s32 CCharaObj::GetResIndex() {
    if (!m_res) {
        return -1;
    }
    return m_res->GetCur8();
}

s32 CCharaObj::Func113F38() {
    if (!m_res) {
        return -1;
    }
    if (m_unk70 >= 0) {
        return m_unk70;
    }
    return m_res->Get44(m_unk74);
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", Func113F80__9CCharaObj);

void CCharaObj::CallFunc114050(s32 b, f32 f) {
    Func114050(0, b, f);
}

void CCharaObj::Func114050(s32 a, s32 b, f32 f) {
    s32 h = -1;
    if (!m_res || !m_res->Get48(b)) {
        b = -1;
    }
    if (a == -200 || a == -100) {
        m_unk78 = a;
    } else {
        m_unk78 = 0;
    }
    if (m_unk74 == b) {
        return;
    }
    if (m_unk70 >= 0) {
        func_001ECCA8(m_unk70);
        m_unk70 = -1;
    }
    if (m_res) {
        h = m_res->Get44(b);
        if (h < 0) {
            s32 idx = GetResIndex();
            if (idx >= 0) {
                s32 p = m_res->Get48(b);
                if (p) {
                    Func10ADD0();
                    m_unk70 = func_001EB920(p, idx);
                    if (m_unk70 < 0) {
                        Func235DE0(D_002D3680, b, -1);
                    }
                    h = m_unk70;
                    ClearFunc1EB828And1EB838();
                }
            }
        }
    }
    if (m_unk74 < 0 || m_unk38 == 1) {
        f = 0.0f;
    }
    m_unk7C = 0.0f;
    m_unk74 = b;
    m_unk84 = m_unk7C;
    m_unk88 = f;
    m_unk8C = m_unk84 < f;
    m_unk90 = h >= 0 ? func_001ECDC8(h) != 0 : 0;
    m_unk94 = 0;
}
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3680);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D36B0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D36C0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D36D0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D36E0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D36F0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001141F0);

f32 CCharaObj::Func114670() {
    s32 i = Func113F38();
    if (i < 0) {
        return 0.0f;
    }
    return Func1EAC30(i);
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001146A8);

void CCharaObj::Func114828(CVec4 *out, CVec4 *in) {
    f32 d;
    f32 lim;
    out->x = VuFrac(in->x + 0.5f) - 0.5f;
    out->y = VuFrac(in->y + 0.5f) - 0.5f;
    out->z = VuFrac(in->z + 0.5f) - 0.5f;
    out->w = 0.0f;
    d = VuDot3(out, out);
    lim = m_unk130 * m_unk130;
    if (lim < d) {
        f32 s = FSqrt(lim / d);
        out->x *= s;
        out->y *= s;
        out->z *= s;
    }
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00114958);

u32 ReadVarint(u8 **pp) {
    u32 v = 0;
    u8 c;
    do {
        c = *(*pp)++;
        v = (v << 7) | (c & 0x7F);
    } while (c & 0x80);
    return v;
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00114C78);

void CCharaObj::Part24Func10DB70() {
    if (m_part24) {
        m_part24->Func10DB70();
    }
}

void CCharaObj::SetUnk150(s32 v) {
    m_unk150 = v;
}

void CCharaObj::Part24Func10DBD8() {
    if (m_part24) {
        m_part24->Func10DBD8();
    }
}

void CCharaObj::Func114D18(s32 v) {
    if (m_part24 && m_unk158 != v) {
        m_unk158 = v;
        if (v) {
            m_unk15C = 0;
            m_unk160 = 0;
            m_unk164 = 0;
        } else {
            m_unk160 = m_unk160 < 7 ? m_unk160 : 6;
        }
    }
}

void CCharaObj::Func114D70(s32 a, s32 b) {
    if (a) {
        D_002A0444 = m_unk10;
        D_002A0448 = -1;
        m_unk170 = 0;
        s32 x = func_0020F948(b);
        if (func_0020E488(x, func_0020F998(b)) == 2) {
            m_unk174 = func_0020F9E8(b);
        } else {
            m_unk174 = -1;
        }
    } else if (D_002A0444 == m_unk10) {
        D_002A0444 = -1;
        D_002A0448 = -1;
        m_unk174 = -1;
        Func114D18(a);
    }
}

void CCharaObj::SetPart24Unk18(s32 v) {
    if (m_part24) {
        m_part24->m_unk18 = v;
    }
}

s32 CCharaObj::GetPart24Unk18() {
    return m_part24 ? m_part24->m_unk18 : -1;
}

void CCharaObj::Part24Func10DC80() {
    if (m_part24) {
        m_part24->Func10DC80();
    }
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00114EA0);

void CCharaObj::Func115278(CCharaNameSrc *src, const char *name) {
    if (src) {
        strncpy(m_unk1A8, (char *)src->m_unk14 + 0x20, 0x10);
        return (void)strncpy(m_unk1B8, name, 0x10);
    }
    m_unk1A8[0] = 0;
    m_unk1B8[0] = 0;
    m_unkE0.m[0] = D_002D36C0;
    m_unkE0.m[1] = D_002D36D0;
    m_unkE0.m[2] = D_002D36E0;
    m_unkE0.m[3] = D_002D36F0;
}

void CCharaObj::Func115328(f32 v) {
    if (m_part1C) {
        func_00111490(m_part1C, ((CSwingBoneObjSub1114C0 *)m_part1C)->GetUnk10(0) + v);
    }
    if (m_part20) {
        m_part20->m_unk1C += v;
    }
}

s32 CCharaObj::Func115388() {
    return m_unk288 < m_unk28C || m_unk2C0 < m_unk2C4 || m_unk2D0 < m_unk2D4 || m_unk300 < m_unk304;
}

s32 CCharaObj::Func1153E8() {
    s32 r = 0;
    if ((m_unk350 && !m_unk90) || (m_unk84 < 1.0f && m_unk88 > 0.0)) {
        if (m_unk74 >= 0) r = 1;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115470);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001156A8);

void CCharaObj::Func115830(CVec4 *v, s32 n, s32 m) {
    Func114828(v, v);
    if (n == 0) {
        Func270C50(&m_unk120, v);
        m_unk304 = 0;
        return;
    }
    Func270C50(&m_unk2E0, &m_unk120);
    Func270C50(&m_unk2F0, v);
    m_unk300 = 0; 
    m_unk304 = n;
    m_unk308 = m;
}

void CCharaObj::Func1158C0(s32 id, const char *name, s32 a, s32 b) {
    if (id < 0) {
        m_unk30C = -1;
        return;
    }
    m_unk30C = id;
    Func24B600(m_name, name, 0x20);
    Func270C50(&m_unk340, &m_unk120);
    m_unk330 = 0; 
    m_unk334 = a;
    m_unk338 = b;
}

void CCharaObj::Func115938(s32 a, s32 b, f32 x, f32 y) {
    if (b < 0) {
        Func1159A0(a, 0, x);
        m_unk350 = 0;
        return;
    }
    Func114050(a, b, x);
    m_unk80 = y;
    Func116A98(0, 0);
    m_unk350 = 1;
}

void CCharaObj::Func1159A0(s32 a, s32 i, f32 f) {
    Func114050(a, m_unk354[i], f);
    Func116A40(i);
}

void CCharaObj::Func1159E8(const CVec4 *v, s32 n) {
    if (n == 0) {
        Func270C50(&m_unkB0, v);
        m_unk2C0 = 0;
        m_unk2C4 = 0;
        return;
    }
    Func270C50(&m_unk2A0, &m_unkB0);
    Func270C50(&m_unk2B0, v);
    m_unk2C0 = 0;
    m_unk2C4 = n;
}

void CCharaObj::SetUnk354(u32 i, s32 v) {
    if (i < 6) {
        m_unk354[i] = v;
    }
}

s32 CCharaObj::GetUnk354(u32 i) {
    s32 r = -1;
    if (i < 6) {
        r = m_unk354[i];
    }
    return r;
}

s32 CCharaObj::Func115A98() {
    s32 r;
    s32 d;
    if (!Func115388()) {
        return 0;
    }
    r = 0;
    if (m_unk288 < m_unk28C) {
        r = Max(r, m_unk28C - m_unk288);
    }
    if (m_unk2C0 < m_unk2C4) {
        r = Max(r, m_unk2C4 - m_unk2C0);
    }
    if (m_unk2D0 < m_unk2D4) {
        r = Max(r, m_unk2D4 - m_unk2D0);
    }
    if (m_unk300 < m_unk304) {
        r = Max(r, m_unk304 - m_unk300);
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115B48);

f32 Ease115C28(s32 type, s32 cur, s32 total) {
    f32 t = (f32)cur / (f32)total;
    switch (type) {
    case 0:
        return t;
    case 1:
        return t * t;
    case 2:
        return 1.0f - (1.0f - t) * (1.0f - t);
    case 3:
        return (1.0f - TblCos(t * 0.5f)) * 0.5f;
    }
    return 0.0f;
}

void Func115D00(CVec4 *out, CVec4 *tmp, CVec4 *pts, f32 *times, s32 n, f32 t) {
    s32 i;
    for (i = 0; i < n; i++) {
        if (t < times[i]) break;
    }
    if (i < n) {
        s32 j = i - 1;
        if (j < 0) j = 0;
        f32 f = (t - times[j]) / (times[i] - times[j]);
        func_00270A98(tmp, &pts[i], &pts[j]);
        func_00270B68(tmp, tmp, f);
        func_00270A30(out, tmp, &pts[j]);
        return;
    }
    func_00270A98(tmp, &pts[n - 1], &pts[n - 2]);
    Func270C50(out, &pts[n - 1]);
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115E48);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3758);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3768);

void CCharaObj::Func116A40(u32 i) {
    s32 t[2];
    if (i < 6) {
        t[0] = m_unk35A[i][0];
        t[1] = m_unk35A[i][1];
        Func116A98(t, t[0] != t[1] ? 2 : 0);
    }
}

void CCharaObj::Func116A98(s32 *src, s32 n) {
    s32 i;
    for (i = 0; i < n && i < 2; i++) {
        m_unk17C[i] = src[i];
    }
    m_unk184 = n > 2 ? 2 : n;
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", Func116AE0__9CCharaObj);

extern "C" f32 func_00116B98(s32 ri, CMat4 *base, void *res, s32 idx) {
    CMat4 m;
    CVec4 a;
    CVec4 b;
    CVec4 c;
    CVec4 d;
    f32 a1;
    if (ri < 0 || idx < 0 || !res) return 0.0f;
    Func113418(&m, ri, (s32)res, idx);
    a.x = 0.0f;
    a.y = 0.0f;
    a.z = 0.0f;
    a.w = 1.0f;
    Func270C50(&b, &a);
    c.x = 1.0f;
    c.w = 1.0f;
    c.y = 0.0f;
    c.z = 0.0f;
    VU_CALL(0x30);
    VU_MAT(func_00202368(), 0x50);
    VU_MAT(base, 0x60);
    VU_MAT(&m, 0x60);
    VuApplySelf(&c);
    VuApplySelf(&b);
    VU_CALL(0x40);
    func_00270A98(&c, &c, &b);
    func_00270A98(&d, &a, &b);
    a1 = func_0021ACA8(c.x, c.z);
    return VuFrac(func_0021ACA8(d.x, d.z) - a1 + 1.0f);
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00116D60);

s32 CCharaObj::Func1170F0() {
    s32 ri = GetResIndex();
    CMat4 m;
    if (ri < 0) return 0;
    VU_CALL(0x30);
    VU_CALL(0x20);
    func_00116D60(&m_unkA0, &m_unkC0, &m_unkD0, &m_unkE0, 0, 0);
    VuStoreMat(&m);
    return 0.5f < func_00116B98(ri, &m, m_unk28, m_unk60);
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00117198);

void Func1173C0(void *a, void *b, void *c, void *d, s32 h) {
    func_00227460(0x40);
    func_002279D0(a, h, 0, 0);
    func_002279D0(b, h, 0, 0);
    func_002279D0(c, h, 0, 0);
    func_002279D0(d, h, 0, 0);
}

void CCharaObj::Func117468(s32 mode, s32 p) {
    CMat4 m;
    VU_CALL(0x30);
    VU_MAT(func_00202368(), 0x50);
    func_00116D60(&m_unkA0, &m_unkC0, &m_unkD0, &m_unkE0, mode, p);
    VU_VEC(&D_002A05B0, 0x70);
    VuStoreMat(&m);
    if (m_res) {
        s32 f = m_res->GetCurFlags();
        if (f == 0) goto draw;
        if (f != 1) {
        draw:
            Func225088();
            func_002250E8(0);
            func_00225258(&m);
            func_00226478(0, 8, D_002A04C0);
            func_002264D8(0, 6, D_002A0540);
            func_00226568(0, 1, D_002A05A0);
            func_00227A20();
            Func1173C0((void *)4, (void *)5, (void *)6, (void *)7, 0);
            Func1173C0((void *)0, (void *)1, (void *)2, (void *)3, 1);
            Func1173C0((void *)5, (void *)4, (void *)0, (void *)1, 2);
            Func1173C0((void *)7, (void *)6, (void *)2, (void *)3, 3);
            Func1173C0((void *)6, (void *)5, (void *)1, (void *)2, 4);
            Func1173C0((void *)4, (void *)7, (void *)3, (void *)0, 5);
            func_00227AA8();
            Func2251E8();
            Func2250C0();
            return;
        }
    }
    Func225088();
    Func2250C0();
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00117668);

s32 CCharaObj::Func117898(s32 a, s32 idx) {
    s32 ri;
    u8 *e;
    if (!m_unk28) goto fail;
    ri = GetResIndex();
    if (ri < 0) goto fail;
    e = D_002A5D0C + ri * 52;
    if (!e || idx < 0) return 0;
    if ((*(s32 **)(e + 0x10))[0] - 1 < idx) {
    fail:
        return 0;
    }
    Func113418((void *)a, ri, (s32)m_unk28, idx);
    VU_CALL(0x30);
    VU_CALL(0x20);
    VU_VEC(&m_unkA0, 0x80);
    VU_ROT(m_unkC4, 0xA0);
    VU_ROT(m_unkC0, 0xB0);
    VU_ROT(m_unkC8, 0x90);
    VU_VEC(&m_unkD0, 0x70);
    VU_MAT(a, 0x60);
    VuStoreMat((void *)a);
    return 1;
}

s32 CCharaObj::Func117AC8(s32 a, s32 b) {
    s32 i = GetResIndex();
    if (i < 0) {
        return 0;
    }
    return Func117898(a, Func113368(i, b));
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", Func117B48__9CCharaObjiii);

s32 CCharaObj::Func117DA0(s32 a, s32 b, s32 c) {
    s32 i = GetResIndex();
    if (i < 0) {
        return 0;
    }
    return Func117B48(a, Func113368(i, b), c);
}

void Func117E38(void *dst, s32 *src) {
    if (dst && src) {
        memcpy(dst, src, *src * 48 + 16);
    }
}

void CCharaObj::Func117E78() {
    s32 i = GetResIndex();
    if (i >= 0) {
        s32 **e = (s32 **)(D_002A5D0C + i * 52);
        if (e) {
            s32 *p = *e;
            if (p) {
                Func117E38(m_unk28, p);
                Func117E38(m_unk2C, p);
                Func117E38(m_unk30, p);
                Func117E38(m_unk34, p);
            }
        }
    }
}

s32 CCharaObj::Func117F10(s32 v) {
    s32 i = GetResIndex();
    if (i < 0) {
        return -1;
    }
    s32 r = Func113368(i, v);
    if (r < 0) {
        r = -1;
    }
    return r;
}

CModelAccResMgr *CreateSub117F98() {
    return new CModelAccResMgr;
}
