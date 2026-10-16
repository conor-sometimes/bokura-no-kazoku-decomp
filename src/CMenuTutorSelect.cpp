#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
void *operator new(unsigned int n);
#include "CMenuProcess.h"
#include "CBgWork.h"
class CChrBodyData {
public:
    ~CChrBodyData();
};
#include "CChrBodyWin.h"
extern CChrBodyWin *D_002A4308;
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuTutorSelect.
class CMenuTutorSelect : public CMenuProcess {
public:
    CMenuTutorSelect();
    virtual ~CMenuTutorSelect();
    virtual s32 Update();
    virtual s32 Draw();
    void Init17FD50();

    CBgWork m_bg;             // 0x58
    s32 m_unk64[4];           // 0x64
    CChrBodyData *m_unk74;    // 0x74
    s32 m_unk78;              // 0x78
    u8 pad7C[0x1C];
    s32 m_unk98;              // 0x98
    s32 m_unk9C;              // 0x9C
};
CMenuTutorSelect *NewCMenuTutorSelect();
// @decl-end

CMenuTutorSelect::CMenuTutorSelect() {
    s32 i;
    for (i = 3; i >= 0; i--) {
        m_unk64[i] = 0;
    }
    m_unk78 = 0;
    m_unk98 = -1;
    m_unk74 = 0;
    m_unk9C = -1;
}

CMenuTutorSelect::~CMenuTutorSelect() {
    func_00245818(&m_bg, 1);
    D_002A4308->Func188BA8();
    if (m_unk74) {
        delete m_unk74;
        m_unk74 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelect", Update__16CMenuTutorSelect);

INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA7B0);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA7C0);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA7E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA808);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA830);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA840);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA868);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA898);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA8D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA900);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA930);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA938);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA948);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA958);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA968);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA970);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA978);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA980);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA9A0);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA9A8);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA9B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DA9C8);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", jtbl_002DAA00);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DAA18);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DAA20);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DAA28);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DAA30);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DAA50);
INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelect", Draw__16CMenuTutorSelect);

CMenuTutorSelect *NewCMenuTutorSelect() {
    CMenuTutorSelect *p = (CMenuTutorSelect *)operator new(0xB0);
    p->Init17FD50();
    return p;
}
