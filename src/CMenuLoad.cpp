#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

// Members and globals shared by the memory-card screens (CMenuLoadMemorial, CMenuSave, CMenuLoad).
extern "C" int func_00245818(void *p, s32 v);
extern "C" int func_001B7EF8(void *p);
class CBgWork {
public:
    CBgWork();
    ~CBgWork();

    u8 pad0[0xC];
};
// Constructor 0x1843D8 (CallFunc184420__18CMenuTutorSelected), destructor 0x1843F0.
class CMenuTutorSelectedSub1843F0 {
public:
    CMenuTutorSelectedSub1843F0();
    ~CMenuTutorSelectedSub1843F0();

    u8 pad0[0x50];
};
// Constructor 0x182070 (Init__27CMenuTutorSelectedSub182108), destructor 0x182098.
class CMenuTutorSelectedSub182098 {
public:
    CMenuTutorSelectedSub182098();
    ~CMenuTutorSelectedSub182098();

    u8 pad0[0x10];
};
#include "CMenuMgrSub1B6BA8.h"
#include "CUnk2A55B0.h"
extern CMenuMgrSub1B6BA8 *D_002A55AC;
extern CUnk2A55B0 *D_002A55B0;

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuLoad.
class CMenuLoad : public CMenuProcess {
public:
    CMenuLoad();
    virtual ~CMenuLoad();
    virtual void Update();
    virtual s32 Draw();

    CBgWork m_bg;             // 0x58
    s32 m_unk64;              // 0x64
    u8 pad68[0x8];
    CMenuTutorSelectedSub1843F0 m_unk70; // 0x70
    CMenuTutorSelectedSub182098 m_unkC0; // 0xC0
};

extern "C" void func_001B2AB0(void *p);
class CMenuBoot {
public:
    static CMenuBoot *Create();
};

class CUnk237E90 {
public:
    int Func237E90(int v);
};
extern "C" u8 *func_00237570(s32 v);
extern "C" void func_00237A88(void *p, s32 v);
extern "C" void *func_00237C30(void *p);
extern "C" int func_00238158(void *p, s32 v);
extern "C" int func_001B66E8(void *p);
extern "C" int func_001836E8(void *p);
extern "C" int func_001848E0(void *p);
extern void *D_002A5538;
void Func225240(s32 v);

// @decl-end

CMenuLoad::CMenuLoad() {
}

CMenuLoad::~CMenuLoad() {
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

INCLUDE_RODATA("asm/nonmatchings/CMenuLoad", D_002DFB70);
INCLUDE_ASM("asm/nonmatchings/CMenuLoad", Update__9CMenuLoad);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoad", D_002DFB88);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoad", D_002DFB90);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoad", D_002DFB98);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoad", D_002DFBA8);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoad", D_002DFBC8);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoad", D_002DFC08);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoad", D_002DFC18);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoad", D_002DFC28);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoad", D_002DFC50);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoad", D_002DFC58);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoad", D_002DFC68);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoad", D_002DFC78);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoad", D_002DFC88);
INCLUDE_RODATA("asm/nonmatchings/CMenuLoad", D_002DFC98);

s32 CMenuLoad::Draw() {
    char buf[32];
    u8 *p = func_00237570(0x70);
    func_00237A88(p, 7);
    func_00238158(func_00237C30(p + 0x60), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(func_001836E8(&m_unkC0));
    ((CUnk237E90 *)(p + 0x40))->Func237E90(func_001848E0(&m_unk70));
    ((CUnk237E90 *)(p + 0x50))->Func237E90(func_001B66E8(D_002A5538));
    Func225088();
    Func225240((s32)p);
    Func2250C0();
}

CMenuBoot *CMenuBoot::Create() {
    CMenuBoot *p = (CMenuBoot *)operator new(0xE0);
    func_001B2AB0(p);
    return p;
}
