#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern s32 D_002A2814;
extern s32 D_002A2818;

#include "CFlagWork.h"
#include "CGameDBMgr.h"


void *operator new(unsigned int n);
int Func235DE0(const char *fmt, ...) throw();
int Func1456A8(int name);
int Func24B998(const char **table, const char *s);
void Func205FE0(int v);
void Func251388(int v);
extern "C" void func_00108448(CFlagWork *w, void *src, s32 n) throw();
extern u8 D_002A1D40[];
extern char D_002D7968[];
extern const char *D_002A26E8[];
extern int D_002A2780[];
extern char D_002D6A40[], D_002D79A8[], D_002D79F0[], D_002D7980[];
class CSysFlagSub145BD0 {
public:
    void Func145BD0();
};
class CCurFlag2 : public CCurFlag {
public:
};
CCurFlag *NewSysFlag();
CSysFlagSub145BD0 *NewSysFlagSub145BD0();
int FindFlagIdByName(const char *s);
int FindInt145848(int *p, int v);
const char *FlagNameById(int v);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00143A90);

void CSysFlag::SetMax(s32 id, s32 v) {
    Func108FF0(id, v < Func1091B0(id) ? Func1091B0(id) : v);
}

void CSysFlag::OrBits(s32 id, s32 bits) {
    Func108FF0(id, Func1091B0(id) | bits);
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00143BD0() {
}

void CSysFlag::Load143BD8(CCurFlag *cur) {
    s32 i;
    s32 n = cur->Func1091B0(0x16);
    SetMax(n + 0x2155, D_002A26E4->Get1455D0());
    for (i = 0; i < cur->Func1091B0(0x27); i++) {
        cur->SetNamed(0x100, i, D_002A2988->TestBits14F478(i));
    }
}

void CSysFlag::Load143CD0(CCurFlag *cur) {
    s32 i;
    s32 n = cur->Func1091B0(0x16);
    for (i = 0; i < 3; i++) {
        D_002A26E4->Func108FF0(i + 0xD, D_002A26E0->Get143F20(i));
        D_002A26E4->Func108FF0(i + 0x10, D_002A26E0->Func1091B0(i + 0xA));
    }
    for (i = 0; i < 0xD00; i++) {
        SetMax(i + 0xD5, cur->Func1091B0(i + 0x156A) + cur->Func1091B0(i + 0x226A));
    }
    SetMax(n + 0xCF, cur->Func1091B0(1) + 1);
    SetMax(n + 0xD2, cur->Func1091B0(8) + 1);
    SetMax(n + 0x2155, D_002A26E4->Get1455D0());
    SetMax(0xD, D_002A26E4->Func1091B0(0x14) + 1);
    for (i = 0; i < 0x20; i++) {
        SetMax(i + 0x2258, cur->Func1091B0(i + 0x3C3E));
    }
    for (i = 0; i < 8; i++) {
        SetMax(i + 0x24F8, cur->Func1091B0(i + 0x1562));
    }
    for (i = 0; i < 0x80; i++) {
        SetMax(i + 0x2158, cur->Func1091B0(i + 0x2F6A));
        Func108FF0(i + 0x21D8, cur->Func1091B0(i + 0x2FEA));
    }
}

s32 CSysFlag::Get143F20(s32 x) {
    if (D_002A26E4->Func1091B0(0x16) == x) {
        return D_002A26E4->Get1455D0();
    }
    return Func1091B0(x + 0x2155);
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00143FA8);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144070);

s32 CSysFlag::Get1440F8(s32 x) {
    s32 a = D_002A26E4->Func1091B0(1);
    s32 b = D_002A26E0->Func1091B0(x + 0xCF);
    s32 r = D_002A26E4->Func1091B0(0x16) == x ? (a < b ? b : a) : b;
    if (GetOption(x)) {
        r = r < 1 ? 1 : r;
    }
    return r;
}

int CSysFlag::SumFlags() {
    int i, sum = 0;
    for (i = 0; i < 3; i++) sum += Func1091B0(i + 10);
    return sum;
}

int CSysFlag::GetOption(int k) {
    switch (k) {
    case 0: return 1;
    case 1: return Func1091B0(0xD2) != 0;
    case 2: return Func1091B0(0xD3) != 0;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144270);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144378);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144440);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_001446D8);

CCurFlag *NewSysFlag() {
    return new CCurFlag;
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", __8CCurFlag);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144808);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144880);

void CCurFlag::SetNamed(s32 base, int name, s32 v) {
    int b = Func1456A8(name);
    if (b < 0) Func235DE0(D_002D7980, base, name, v);
    else Func108FF0(base + b, v);
}

int CCurFlag::GetNamed(s32 base, int name) {
    int b = Func1456A8(name);
    if (b < 0) {
        Func235DE0(D_002D79A8, base, name);
        return 0;
    }
    return Func1091B0(base + b);
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144B68);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144C60);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144D68);

void CCurFlag::Set144E28(int name, s32 v) {
    s32 id = Func1456A8(name);
    s32 k;
    if (id < 0) return;
    if (v < 0) v = Func1091B0(id + 0x34);
    if ((u32)v >= 0x24) return;
    k = id * 36 + v;
    Func108FF0(k + 0x796, Func1091B0(id + 0x9A));
    Func108FF0(k + 0x86E, Func1091B0(id + 0xA0));
    Func108FF0(k + 0x946, Func1091B0(id + 0xA6));
    Func108FF0(k + 0xA1E, Func1091B0(id + 0xAC));
    Func108FF0(k + 0xAF6, Func1091B0(id + 0xB2));
    Func108FF0(k + 0xBCE, Func1091B0(id + 0xD6));
    Func108FF0(k + 0xCA6, Vf299248(id));
    Func108FF0(k + 0xD7E, Vf2992C8(id));
    Func108FF0(k + 0xE56, Vf299348(id));
    Func108FF0(k + 0xF2E, Vf2993C8(id));
}

int CCurFlag::Get145008(s32 base, int name, u32 k) {
    int b = Func1456A8(name);
    if (b < 0 || k >= 0x24) return 0;
    return Func1091B0(base + b * 36 + k);
}

int CCurFlag::Get145090(s32 x) {
    int a = D_002A26E4->Func1091B0(1);
    int b = D_002A26E0->Func1091B0(x + 0xCF);
    if (D_002A26E4->Func1091B0(0x16) == x) return a < b ? b : a;
    return b;
}

s32 CCurFlag::Get145118() {
    if (D_002A2988) {
        return D_002A2988->Vf14FE60(-1);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145160);

void CCurFlag::MoveMoney(s32 v) {
    Func109108(0x1C, -v);
    Func109248(0x1C, 0, 9999);
    Func109108(0x1E, v);
}

void CCurFlag::Func108FF0Cur(s32 id, s32 v) {
    Func108FF0(id + 0x1462, v);
}

int CCurFlag::Func1091B0Cur(s32 id) {
    return Func1091B0(id + 0x1462);
}

void CCurFlag::IncCur(s32 id) {
    Func108FF0Cur(id, Func1091B0Cur(id) + 1);
}

void CCurFlag::Func108FF0Cur2(u32 id, s32 v) {
    if (id < 0xD00) {
        Func108FF0(id + 0x226A, v);
    }
}

int CCurFlag::Func1091B0Cur2(s32 id) {
    return Func1091B0(id + 0x226A);
}

void CCurFlag::IncCur2(s32 id) {
    Func108FF0Cur2(id, Func1091B0Cur2(id) + 1);
}

void CCurFlag::Set145398(s32 d) {
    s32 i, k;
    u32 bits = 0;
    s32 v = Vf2991E8() + d;
    if (v < 0) v = 0;
    for (i = 0; i < 16; i++) {
        k = i;
        if (i == 13) k = 0x90;
        if (i == 14) k = 0x91;
        if (Func1091B0(k + 0x3AAE)) bits |= 1 << i;
    }
    Func108FF0(v + 0x306A, bits);
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        v = Func1091B0(i + 0x34) + d;
        if (v < 0) v = 0;
        Func108FF0(i * 36 + v + 0x308E, D_002A26E4->Func1091B0(i + 0xD6));
    }
}

int CCurFlag::GetBit1454F0(u32 idx, u32 bit) {
    if (bit == 0x90) bit = 13;
    if (bit == 0x91) bit = 14;
    if (idx >= 0x24 || bit >= 16) return 0;
    return ((u32)Func1091B0(idx + 0x306A) >> bit) & 1;
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145558);

s32 CCurFlag::Get1455D0() {
    return D_002A2988->Vf150680(1.4f);
}

void CCurFlag::Vf2932F8(s32 id) {
    if (!D_002A2988) return;
    if ((u32)(id - 0x3AAE) < 0x10 || id == 0x3B3E || id == 0x3B3F) {
        D_002A2988->Vf14FF30();
    }
}

int IsFlagKind(int v) {
    return (v >= 2 && v <= 6) || v == 8;
}

int IsNine(int v) {
    return v == 9;
}

int Func1456A8(int name) {
    int n, i;
    if (!D_002A26E4) return -1;
    n = D_002A26E4->Func1091B0(0x27);
    if (name < n) return name;
    for (i = 0; i < n; i++) {
        if (D_002A26E4->Func1091B0(i + 0x28) == name) return i;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", Func145738__Fii);

int FindFlagIdByName(const char *s) {
    int i = Func24B998(D_002A26E8, s);
    if (i < 0) return -1;
    return D_002A2780[i];
}

int FindInt145848(int *p, int v) {
    int i;
    for (i = 0; p[i] >= 0; i++) {
        if (p[i] == v) return i;
    }
    return -1;
}

const char *FlagNameById(int v) {
    int i = FindInt145848(D_002A2780, v);
    if (i < 0) return D_002D6A40;
    return D_002A26E8[i];
}

s32 CCurFlag::Select(s32 v) {
    return v ? D_002A2814 : D_002A2818;
}

s32 CCurFlag::Get1458F0(int name, s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 r;
    if (Func1456A8(name) < 0) return Select(0);
    if (a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0) {
        r = D_002A2988->Vf14F638(name, a, b, c, d, e);
    } else {
        r = D_002A2988->TestBits14F478(name);
    }
    return Select(r);
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145A28);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145AD0);

CSysFlagSub145BD0 *NewSysFlagSub145BD0() {
    CSysFlagSub145BD0 *p = (CSysFlagSub145BD0 *)operator new(0x28);
    p->Func145BD0();
    return p;
}
