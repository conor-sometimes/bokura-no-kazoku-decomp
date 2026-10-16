#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"
#include "CBgWork.h"
class CMenuRecordWin;
extern "C" void func_001AA118(void *p);
class CMenuSysscr26 {
public:
    static CMenuSysscr26 *Create();
};

#include "CMenuRecordWin.h"
extern "C" const char *func_001A36B0(CMenuRecordWin *w, s32 v);
extern "C" s32 func_0024BA08(char *buf, s32 v);
extern "C" int sprintf(char *buf, const char *fmt, ...);
//@sym sprintf 0x28AF70
class CMenuSysscr27Win {
public:
    void Func1A98F8();
    void Func1A9BF8();
    void Func1A9D30();
    void Func1A9ED8(s32 k);
    void Func1A9E60();
    void Func1AA0B0(f32 t);
    void Func1A9FA0(f32 t, s32 a, s32 b);
    void Func1A9FA0_8_9(f32 t);
    void Func1A9FA0_10_11(f32 t);
    void Func1A9FA0_6_7(f32 t);
    u8 pad0[0x58];
    CMenuRecordWin *m_unk58;  // 0x58
    s32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
};

extern char D_002DF258[];

class CUnk237E90 {
public:
    int Func237E90(int v);
};
extern "C" u8 *func_00237570(s32 v);
extern "C" void func_00237A88(void *p, s32 v);
extern "C" void *func_00237C30(void *p);
extern "C" int func_00238158(void *p, s32 v);
extern "C" int func_001A0510(void *p);
extern "C" int func_0018A1F0(void *p);
void Func225240(s32 v);
class CMenuSysscr31 {
public:
    void Release1A8DC0();
};
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr27.
class CMenuSysscr27 : public CMenuProcess {
public:
    CMenuSysscr27();
    virtual ~CMenuSysscr27();
    virtual void Update();
    virtual s32 Draw();

    CBgWork m_bg;             // 0x58
    void *m_unk64;            // 0x64
    void *m_unk68;            // 0x68
    s32 m_unk6C;              // 0x6C
    u8 pad70[0x4];
    s32 m_unk74;              // 0x74
};

extern "C" void func_001A3AF8(CMenuRecordWin *w, s32 k, f32 x, f32 y);

extern char D_002DF230[];
// @decl-end

CMenuSysscr27::CMenuSysscr27() {
    m_unk68 = 0;
    m_unk64 = 0;
    m_unk6C = 0;
    m_unk74 = 0;
}

CMenuSysscr27::~CMenuSysscr27() {
    ((CMenuSysscr31 *)this)->Release1A8DC0();
}

INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr27", D_002DF190);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr27", D_002DF198);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr27", D_002DF1B8);
INCLUDE_ASM("asm/nonmatchings/CMenuSysscr27", Update__13CMenuSysscr27);

s32 CMenuSysscr27::Draw() {
    if (m_unk64 == 0 || m_unk68 == 0) {
        Func225088();
        return Func2250C0();
    }
    u8 *p = func_00237570(0x40);
    CUnk237E90 *q = (CUnk237E90 *)(p + 0x10);
    func_00237A88(p, 4);
    func_00238158(func_00237C30(p + 0x30), 1);
    q->Func237E90(func_001A0510(m_unk68));
    q->Func237E90(func_0018A1F0(m_unk64));
    Func225088();
    Func225240((s32)p);
    return Func2250C0();
}

