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

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSave.
class CMenuSave : public CMenuProcess {
public:
    CMenuSave();
    virtual ~CMenuSave();
    virtual void Update();
    virtual s32 Draw();

    CBgWork m_bg;             // 0x58
    s32 m_unk64;              // 0x64
    u8 pad68[0x8];
    CMenuTutorSelectedSub1843F0 m_unk70; // 0x70
    CMenuTutorSelectedSub182098 m_unkC0; // 0xC0
};

class CMenuLoad {
public:
    CMenuLoad();
    static CMenuLoad *Create();

    u8 pad0[0x7DC0];
};


#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
extern "C" void func_001829E8(void *p, s32 v);
extern "C" void func_00183090(void *p, f32 *x, f32 *y);
class CMenuSaveObj {
public:
    void Func1B1130();
    u8 pad0[0x64];
    s32 m_unk64;              // 0x64
    u8 pad68[0xC0 - 0x68];
    u8 m_unkC0[0x10];         // 0xC0
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

void Func225240(s32 v);

// @decl-end

CMenuSave::CMenuSave() {
}

CMenuSave::~CMenuSave() {
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

INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DF980);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DF988);
INCLUDE_ASM("asm/nonmatchings/CMenuSave", Update__9CMenuSave);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DF9A0);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DF9A8);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DF9B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DF9D8);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFA18);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFA28);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFA38);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFA58);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFA68);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFA80);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFA90);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFAA0);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFAB0);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFAC0);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFAD0);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFAE8);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFB00);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFB10);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFB20);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFB30);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFB40);
INCLUDE_RODATA("asm/nonmatchings/CMenuSave", D_002DFB50);

s32 CMenuSave::Draw() {
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

CMenuLoad *CMenuLoad::Create() {
    return new CMenuLoad;
}

void CMenuSaveObj::Func1B1130() {
    f32 x, y;
    func_001829E8(m_unkC0, m_unk64);
    func_00183090(m_unkC0, &x, &y);
    D_002A5538->Move1B6488(x, y);
}

int Func1B1188() {
    for (s32 i = 0; i < 30; i++) {
        if (D_002A55AC->Check1B7428(i) == 1) return 1;
    }
    return 0;
}
