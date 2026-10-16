#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"
#include "CBgWork.h"

// Member at 0x70 (CMenuTutorSelected.cpp): its constructor calls Func184420.
class CMenuTutorSelectedSub1843F0 {
public:
    CMenuTutorSelectedSub1843F0();
    ~CMenuTutorSelectedSub1843F0();

    u8 pad0[0x7CE4];
};

#include "CMenuMgrSub1B6BA8.h"
extern CMenuMgrSub1B6BA8 *D_002A55AC;
#include "CUnk2A55B0.h"
extern CUnk2A55B0 *D_002A55B0;
extern void *D_002A5538;
extern "C" int func_00245818(void *p, s32 v);
extern "C" int func_001B7EF8(CUnk2A55B0 *p);
extern "C" int func_001848E0(void *p);
extern "C" int func_001B66E8(void *p);
class CUnk237E90 {
public:
    int Func237E90(int v);
};
void *Func237570(int size);
void Func237A88(void *p, int n);
void *Func237C30(void *p);
void Func238158(void *p, int v);
void Func225240(int v);

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuBoot.
class CMenuBoot : public CMenuProcess {
public:
    CMenuBoot();
    virtual ~CMenuBoot();
    virtual void Update();
    virtual s32 Draw();

    CBgWork m_bg;             // 0x58
    u8 pad64[0xC];
    CMenuTutorSelectedSub1843F0 m_tutor; // 0x70
};
// @decl-end

CMenuBoot::CMenuBoot() {
}

CMenuBoot::~CMenuBoot() {
    func_00245818(&m_bg, 1);
    if (D_002A55AC) {
        if (D_002A55B0) {
            while (func_001B7EF8(D_002A55B0)) {
            }
        }
        D_002A55AC->Release1B6F00();
        delete D_002A55AC;
    }
    if (D_002A55B0) {
        D_002A55B0->Free1B7E28();
        delete D_002A55B0;
    }
}

INCLUDE_RODATA("asm/nonmatchings/CMenuBoot", D_002DFCB8);
INCLUDE_ASM("asm/nonmatchings/CMenuBoot", Update__9CMenuBoot);
INCLUDE_RODATA("asm/nonmatchings/CMenuBoot", D_002DFCD0);
INCLUDE_RODATA("asm/nonmatchings/CMenuBoot", D_002DFCD8);
INCLUDE_RODATA("asm/nonmatchings/CMenuBoot", D_002DFCE8);
INCLUDE_RODATA("asm/nonmatchings/CMenuBoot", D_002DFD08);
INCLUDE_RODATA("asm/nonmatchings/CMenuBoot", D_002DFD48);
INCLUDE_RODATA("asm/nonmatchings/CMenuBoot", D_002DFD58);
INCLUDE_RODATA("asm/nonmatchings/CMenuBoot", D_002DFD80);

s32 CMenuBoot::Draw() {
    u8 *p = (u8 *)Func237570(0x40);
    Func237A88(p, 4);
    Func238158(Func237C30(p + 0x30), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(func_001848E0(&m_tutor));
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B66E8(D_002A5538));
    Func225088();
    Func225240((int)p);
    return Func2250C0();
}
