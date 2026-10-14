#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym memset 0x289FB0
#include "libc.h"

// Members created by the constructor; only their virtual destructors are called here.
class CMapAttr {
public:
    virtual ~CMapAttr();

    u8 pad0[0x154];
    // vptr 0x154
};
class CMapEffRes {
public:
    virtual ~CMapEffRes();

    u8 pad0[0x18];
    // vptr 0x18
};
class CMapSndRes {
public:
    CMapSndRes();
    virtual ~CMapSndRes();

    u64 pad0[0x2F];           // 8-aligned: sizeof is 0x180
    // vptr 0x178
};
extern "C" void func_00118210(void *p);
extern "C" void func_0011BD00(void *p);

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMapRes.
class CMapRes {
public:
    CMapRes();
    virtual ~CMapRes();
    void Func11AC70();

    s32 m_unk0;               // 0x00
    s32 m_unk4;               // 0x04
    s32 m_unk8;               // 0x08
    s32 m_unkC;               // 0x0C
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    CMapAttr *m_attr;         // 0x18
    CMapEffRes *m_eff;        // 0x1C
    CMapSndRes *m_snd;        // 0x20
    u8 m_unk24[0x8];          // 0x24
    // vptr 0x2C
};
// @decl-end

CMapRes::CMapRes() {
    CMapAttr *attr;
    CMapEffRes *eff;
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    attr = (CMapAttr *)operator new(0x160);
    func_00118210(attr);
    m_attr = attr;
    eff = (CMapEffRes *)operator new(0x1C);
    func_0011BD00(eff);
    m_eff = eff;
    m_snd = new CMapSndRes;
    memset(m_unk24, 0, 8);
}

CMapRes::~CMapRes() {
    Func11AC70();
    delete m_snd;
    delete m_eff;
    delete m_attr;
}

INCLUDE_ASM("asm/nonmatchings/CMapRes", func_00119E08);

INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C28);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C30);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C38);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C40);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C48);
INCLUDE_ASM("asm/nonmatchings/CMapRes", func_00119F48);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C70);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C78);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C80);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C88);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C90);

INCLUDE_ASM("asm/nonmatchings/CMapRes", func_0011A1E8);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3CB8);

INCLUDE_ASM("asm/nonmatchings/CMapRes", func_0011A2D8);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3D10);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3D30);

INCLUDE_ASM("asm/nonmatchings/CMapRes", func_0011A638);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3D58);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3D60);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3D68);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3D70);

INCLUDE_ASM("asm/nonmatchings/CMapRes", func_0011A7C0);

INCLUDE_ASM("asm/nonmatchings/CMapRes", func_0011A8F8);

INCLUDE_ASM("asm/nonmatchings/CMapRes", func_0011AA70);

INCLUDE_ASM("asm/nonmatchings/CMapRes", Func11AC70__7CMapRes);
