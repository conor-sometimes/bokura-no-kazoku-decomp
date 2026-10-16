#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

void *Func237570(s32 size);
void Func237A88(void *p, s32 n);
void *Func237C30(void *p);
void Func238158(void *p, s32 v);
void Func225240(s32 v);
class CUnk1A4298 {
public:
    int Func1A4298();
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
extern "C" int func_001B66E8(void *p);
extern void *D_002A5538;
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuConfig.
class CMenuConfig : public CMenuProcess {
public:
    CMenuConfig();
    virtual ~CMenuConfig();
    virtual void Update();
    virtual s32 Draw();

    CUnk1A4298 *m_unk58;      // 0x58
    CUnk1A4298 *m_unk5C;      // 0x5C
    s32 m_unk60;              // 0x60
    s32 m_unk64;              // 0x64
    u8 pad68[0x14];
};

//@sym __builtin_new 0x245648
class CMenuNosave {
public:
    CMenuNosave() throw();

    u8 pad0[0x60];
};
// @decl-end

CMenuConfig::CMenuConfig() {
    m_unk58 = 0;
    m_unk5C = 0;
    m_unk60 = 0;
    m_unk64 = 0;
}

CMenuConfig::~CMenuConfig() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuConfig", Update__11CMenuConfig);
INCLUDE_RODATA("asm/nonmatchings/CMenuConfig", D_002DA4C0);
INCLUDE_RODATA("asm/nonmatchings/CMenuConfig", D_002DA4E0);

s32 CMenuConfig::Draw() {
    u8 *p;
    if (!m_unk58) {
        Func225088();
        return Func2250C0();
    }
    p = (u8 *)Func237570(0x60);
    Func237A88(p, 4);
    Func238158(Func237C30(p + 0x30), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unk58->Func1A4298());
    ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unk5C->Func1A4298());
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B66E8(D_002A5538));
    Func225088();
    Func225240((s32)p);
    return Func2250C0();
}

CMenuNosave *CreateCMenuNosave() {
    return new CMenuNosave;
}
