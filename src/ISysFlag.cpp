#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern s32 D_002A2814;
extern s32 D_002A2818;

class CFlagWork {
public:
    void Func108FF0(s32 id, s32 v);
    int Func1091B0(s32 id);
    void Func109108(s32 id, s32 delta);
    void Func109248(s32 id, s32 lo, s32 hi);
};

class CCurFlag : public CFlagWork {
public:
    void SetNamed(s32 base, int name, s32 v);
    void Add145160(s32 id, s32 v);
    int Get145090(s32 x);
    int Get145008(s32 base, int name, u32 k);
    int GetNamed(s32 base, int name);
    int Get145558(u32 a, int name);
    void SetMax(s32 id, s32 v);
    int GetBit1454F0(u32 idx, u32 bit);
    void MoveMoney(s32 v);
    void OrBits(s32 id, s32 bits);
    void Func108FF0Cur2(u32 id, s32 v);
    void Func108FF0Cur(s32 id, s32 v);
    int Func1091B0Cur(s32 id);
    int Func1091B0Cur2(s32 id);
    s32 Select(s32 v);


};

void *operator new(unsigned int n);
int Func235DE0(const char *fmt, ...);
int Func1456A8(int name);
int Func24B998(const char **table, const char *s);
void Func205FE0(int v);
void Func251388(int v);
extern CFlagWork *D_002A26E4;
extern CFlagWork *D_002A26E0;
extern const char *D_002A26E8[];
extern int D_002A2780[];
extern char D_002D6A40[], D_002D79A8[], D_002D79F0[], D_002D7980[];
class CSysFlag : public CFlagWork {
public:
    void Init1447A8();
    int SumFlags();
    int GetOption(int k);
    int GetBit144070(u32 a, u32 b, u32 c, u32 bit);
    void Apply(int k);
};
class CSysFlagSub145BD0 {
public:
    void Func145BD0();
};
class CCurFlag2 : public CCurFlag {
public:
};
CSysFlag *NewSysFlag();
CSysFlagSub145BD0 *NewSysFlagSub145BD0();
int FindFlagIdByName(const char *s);
int FindInt145848(int *p, int v);
const char *FlagNameById(int v);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00143A90);

void CCurFlag::SetMax(s32 id, s32 v) {
    Func108FF0(id, v < Func1091B0(id) ? Func1091B0(id) : v);
}

void CCurFlag::OrBits(s32 id, s32 bits) {
    Func108FF0(id, Func1091B0(id) | bits);
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00143BD0() {
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00143BD8);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00143CD0);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00143F20);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00143FA8);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144070);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_001440F8);

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

CSysFlag *NewSysFlag() {
    CSysFlag *p = (CSysFlag *)operator new(0x20);
    p->Init1447A8();
    return p;
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", Init1447A8__8CSysFlag);

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

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144E28);

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

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145118);

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

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145280);

void CCurFlag::Func108FF0Cur2(u32 id, s32 v) {
    if (id < 0xD00) {
        Func108FF0(id + 0x226A, v);
    }
}

int CCurFlag::Func1091B0Cur2(s32 id) {
    return Func1091B0(id + 0x226A);
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145330);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145398);

int CCurFlag::GetBit1454F0(u32 idx, u32 bit) {
    if (bit == 0x90) bit = 13;
    if (bit == 0x91) bit = 14;
    if (idx >= 0x24 || bit >= 16) return 0;
    return ((u32)Func1091B0(idx + 0x306A) >> bit) & 1;
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145558);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_001455D0);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145610);

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

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_001458F0);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145A28);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145AD0);

CSysFlagSub145BD0 *NewSysFlagSub145BD0() {
    CSysFlagSub145BD0 *p = (CSysFlagSub145BD0 *)operator new(0x28);
    p->Func145BD0();
    return p;
}
