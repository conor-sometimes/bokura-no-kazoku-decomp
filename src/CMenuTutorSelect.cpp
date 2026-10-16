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
    virtual void Update();
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

INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DAA28);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DAA30);
INCLUDE_RODATA("asm/nonmatchings/CMenuTutorSelect", D_002DAA50);
INCLUDE_ASM("asm/nonmatchings/CMenuTutorSelect", Draw__16CMenuTutorSelect);

CMenuTutorSelect *NewCMenuTutorSelect() {
    CMenuTutorSelect *p = (CMenuTutorSelect *)operator new(0xB0);
    p->Init17FD50();
    return p;
}
