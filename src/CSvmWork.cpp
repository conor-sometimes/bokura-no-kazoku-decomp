#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym SetInt__6CValuei 0x12E0C8
//@sym SetFloat__6CValuef 0x12E130
//@sym Set12E1D8__6CValuei 0x12E1D8
// A tagged value: 0 = int, 1 = float, 2 = string-like (converted by a helper).
class CValue {
public:
    void SetInt(s32 v);          // 0x12E0C8
    void SetFloat(f32 v);        // 0x12E130
    void Set12E1D8(s32 v);       // 0x12E1D8, argument type unknown
    int AsInt();                 // 0x12E260
    float AsFloat();             // 0x12E2D8
    int Get12E350();             // 0x12E350, return type unknown

    s32 m_type;                  // 0x0
    s32 m_value;                 // 0x4
};

class CValueHolder {
public:
    s32 GetField5F0();
    int ValueAsInt();
    float ValueAsFloat();
    int Value12E350();

    u8 pad0[0x5F0];
    s32 m_field5F0;              // 0x5F0
    CValue m_value;              // 0x5F4
};

class CSvmWork {
public:
    int IsVarZero(u32 i);
    void CallFunc12E9D8(s32 a, s32 v);
    void Func12E9D8(s32 a, s32 *p, s32 n);
    void ClearVar(u32 i);
    void Func12EA98(s32 a, s32 b, s32 c);
    void CallFunc12EA98(s32 a, s32 b);
    void ClearUnk47C();
    void SetResultInt(s32 v);
    void SetResultFloat(f32 v);
    void SetResult12E1D8(s32 v);

    u8 pad0[0x478];
    s32 *m_vars;              // 0x478
    s32 m_unk47C;             // 0x47C
    u8 pad480[0x2388];
    CValue m_result;          // 0x2808
};
// @decl-end


INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012E608);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012E768);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012E858);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012E910);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012E968);

void CSvmWork::ClearVar(u32 i) {
    if (i < 3) {
        m_vars[i] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CSvmWork", Func12E9D8__8CSvmWorkiPii);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", Func12EA98__8CSvmWorkiii);

void CSvmWork::CallFunc12E9D8(s32 a, s32 v) {
    Func12E9D8(a, &v, 4);
}

void CSvmWork::CallFunc12EA98(s32 a, s32 b) {
    Func12EA98(a, b, 4);
}

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012EB68);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012EC18);

int CSvmWork::IsVarZero(u32 i) {
    if (i >= 3) {
        return 0;
    }
    return m_vars[i] < 1;
}

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012ECE0);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012EDB8);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012EE28);

void CSvmWork::ClearUnk47C() {
    if (m_unk47C) {
        m_unk47C = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012EED0);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012EF08);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012EF68);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012F940);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012F9A8);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012F9E8);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012FA30);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012FB20);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012FC08);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012FC78);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012FCE8);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012FD70);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012FDB8);

void CSvmWork::SetResultInt(s32 v) {
    m_result.SetInt(v);
}

void CSvmWork::SetResultFloat(f32 v) {
    m_result.SetFloat(v);
}

void CSvmWork::SetResult12E1D8(s32 v) {
    m_result.Set12E1D8(v);
}

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012FE60);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012FF48);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130048);

s32 CValueHolder::GetField5F0() {
    return m_field5F0;
}

int CValueHolder::ValueAsInt() {
    return m_value.AsInt();
}

float CValueHolder::ValueAsFloat() {
    return m_value.AsFloat();
}

int CValueHolder::Value12E350() {
    return m_value.Get12E350();
}

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130138);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001301C0);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130228);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130288);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001302E0);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130338);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130388);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001303D8);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130430);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130488);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001304E0);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130578);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130610);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130678);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001306C8);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130718);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130830);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001308C8);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130958);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001309C0);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130A28);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130A90);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130AF8);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130B60);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130BC8);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130C18);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130CB0);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130D70);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130DD8);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130E28);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130E78);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130FB8);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131020);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131088);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131100);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131178);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001311F0);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131268);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001312E0);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131358);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131390);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001313C8);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131400);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131438);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001314A0);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001314D8);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131510);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131548);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131580);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001315B8);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001315F0);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131628);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131678);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001316B0);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001316E8);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131720);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131D30);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131D90);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131E20);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00131E90);
