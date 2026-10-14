#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuExam.
class CMenuExam : public CMenuProcess {
public:
    CMenuExam();
    virtual ~CMenuExam();
    virtual s32 Update();
    virtual s32 Draw();

    s32 m_unk58;              // 0x58
};

class CFlagWork {
public:
    int Func1091B0(s32 id);
    void Func108FF0(s32 id, s32 v);
};
extern CFlagWork *D_002A26E4;
extern CFlagWork *D_002A5358;
extern "C" void func_00185648(s32 i);
extern "C" void func_00185868(s32 i, s32 a, s32 b);
s32 Func145738(s32 a, s32 b);
// Text table reader (0x10BF88 constructor, 0x256260 lookup; library code).
struct CTextBuf {
    s32 m0;
    u8 pad4[0x8C];
};
extern "C" CTextBuf *func_0010BF88(CTextBuf *p);
extern "C" const char *func_00256260(CTextBuf *p, s32 id);
extern "C" char *strcpy(char *dst, const char *src);

extern char D_002DAEE0[], D_002DAF08[], D_002DAF30[], D_002DADA0[], D_002DADC0[], D_002DADE0[];
extern s32 D_002A4268[][5];
extern s32 D_002A41A0[][10];
struct CExamFlagDef {
    s32 m_dst;
    s32 m_src;
};
extern CExamFlagDef D_002A3CC8[];
extern CExamFlagDef D_002A3DB0[];
extern CFlagWork *D_002A4638[];
extern "C" char *func_0024BA08(char *buf, s32 v);
extern "C" int sprintf(char *buf, const char *fmt, ...);
// @decl-end

CMenuExam::CMenuExam() {
    m_unk58 = 0;
}

CMenuExam::~CMenuExam() {
}

INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAB38);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAB40);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAB60);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAB88);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DABB8);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DABC0);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DABC8);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DABD0);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC00);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC10);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC20);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC30);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC50);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC90);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DACB8);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DACE0);
INCLUDE_ASM("asm/nonmatchings/CMenuExam", Update__9CMenuExam);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAD28);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAD48);

INCLUDE_ASM("asm/nonmatchings/CMenuExam", Draw__9CMenuExam);

s32 Func1855B0(s32 *out) {
    s32 i;
    for (i = 5; i >= 0; i--) {
        out[i] = -1;
    }
    for (i = 0; i < 6; i++) {
        s32 v = D_002A5358->Func1091B0(i + 4);
        if (v < 0) {
            break;
        }
        out[i] = v;
    }
    return i;
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00185648);

void Func185810() {
    s32 i;
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        func_00185648(i);
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00185868);

void Func185A28(s32 a, s32 b) {
    s32 i;
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        func_00185868(i, a, b);
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00185AA0);

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00185BD0);

void Func185E80(char *dst, s32 k) {
    CTextBuf buf;
    s32 a;
    func_0010BF88(&buf);
    buf.m0 = 0;
    D_002A26E4->Func1091B0(0x27);
    a = D_002A26E4->Func1091B0(k + 0x3A);
    strcpy(dst, func_00256260(&buf, a * 4 + D_002A26E4->Func1091B0(k + 0x40) + 0xB4));
}

void Func185F18(char *dst, s32 k, s32 flag) {
    CTextBuf buf;
    char num[0x100];
    s32 n;
    func_0010BF88(&buf);
    buf.m0 = 0;
    n = D_002A26E4->Func1091B0(0x27);
    if (flag && k == n - 1 && n != 1) {
        strcpy(dst, func_00256260(&buf, 0xBD));
    } else {
        const char *fmt = func_00256260(&buf, 0xBC);
        sprintf(dst, fmt, func_0024BA08(num, k + 1));
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00185FD8);

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00186198);

void Func1862F8(char *dst, s32 k) {
    CTextBuf buf;
    func_0010BF88(&buf);
    buf.m0 = 0;
    strcpy(dst, func_00256260(&buf, Func145738(k, 1) + 0xAE));
}

void Func186358(char *dst, s32 a, s32 b) {
    CTextBuf buf;
    func_0010BF88(&buf);
    buf.m0 = 0;
    if (a) {
        if (b == 1) {
            strcpy(dst, func_00256260(&buf, 0xDC));
        } else {
            strcpy(dst, func_00256260(&buf, 0xDD));
        }
    } else {
        strcpy(dst, func_00256260(&buf, 0xDE));
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_001863F0);

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_001864A8);

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_001865B8);

void Func186690(s32 *out, f32 *in) {
    out[0] = (s32)(in[0] * 16.0f) + 0x6C00;
    out[1] = (s32)(in[1] * 16.0f) + 0x7200;
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_001866D0);

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00186730);

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_001869C8);

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00186AC8);
