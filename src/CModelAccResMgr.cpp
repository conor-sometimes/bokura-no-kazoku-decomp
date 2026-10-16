#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
// Members built here; their units belong to other lanes, so the constructor and destructor
// names reach them through config/aliases.ld.
class CModelTbl {
public:
    CModelTbl();
    virtual ~CModelTbl();
    u8 pad0[0x1C];
};
class CMotionTbl {
public:
    CMotionTbl();
    virtual ~CMotionTbl();
    void Release();
    u8 pad0[0xC];
};
class CSwingBoneRes2 {
public:
    CSwingBoneRes2();
    virtual ~CSwingBoneRes2();
    void Func111CF8();
    u8 pad0[0xC];
};
extern "C" void func_001109D8(CModelTbl *p);

// Interface without fields (its RTTI name only): the vptr is at 0.
class IModelAccResMgr {
public:
    virtual void Release() = 0;
    virtual int Func118078(const char *path) = 0;
    virtual void Func118130() = 0;
    virtual int Func294288() = 0;
    virtual int Func294290() = 0;
    virtual int Func294298() = 0;
};
// Vtable 0x2C00B0: slot 0 is an inline `delete this` (emitted elsewhere), so the key method is
// Func118078, not the destructor (slot 6). The factory is CreateSub117F98 in CCharaObj.cpp.
class CModelAccResMgr : public IModelAccResMgr {
public:
    CModelAccResMgr();
    // Inline `delete this` in retail (0x294250); declared here only, so Func118078 is not
    // the key method and the vtable stays asm.
    virtual void Release();
    virtual int Func118078(const char *path);
    virtual void Func118130();
    virtual int Func294288();
    virtual int Func294290();
    virtual int Func294298();
    virtual ~CModelAccResMgr();

    CModelTbl m_models;       // 0x04
    CMotionTbl m_motions;     // 0x24
    CSwingBoneRes2 m_swing;   // 0x34
};
extern CModelAccResMgr *D_002A05D0;

extern s32 D_002A05D4, D_002A05D8, D_002A05DC;
extern const char *D_002A05E0, *D_002A05E4, *D_002A05E8;
extern "C" int func_00110868(CModelTbl *p, const char *name, s32 a);
extern "C" int func_00110DC8(CMotionTbl *p, const char *name, s32 a);
extern "C" int func_00111BA8(CSwingBoneRes2 *p, const char *name);
extern "C" void func_002942E0(void *p);
void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
s32 Func249248(void *buf);
void Func249348();
int Func235DE0(const char *fmt, ...) throw();
class CModelAccSub118168 {
public:
    void Init();

    s32 m_unk0;               // 0x0
    u8 pad4[0xC];
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
    s32 m_unk24;              // 0x24
    u8 m_unk28[0x18];         // 0x28
    s32 m_unk40;              // 0x40
    s32 m_unk44;              // 0x44
    u8 pad48[0x8];
    f32 m_unk50;              // 0x50
    f32 m_unk54;              // 0x54
    f32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
    u8 pad64[0xC];
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
    s32 m_unk78;              // 0x78
    f32 m_unk7C;              // 0x7C
    s32 m_unk80;              // 0x80
    s32 m_unk84;              // 0x84
    u8 pad88[0x8];
    f32 m_unk90;              // 0x90
    f32 m_unk94;              // 0x94
    f32 m_unk98;              // 0x98
    f32 m_unk9C;              // 0x9C
    s32 m_unkA0;              // 0xA0
    u8 padA4[0xC];
    f32 m_unkB0;              // 0xB0
    f32 m_unkB4;              // 0xB4
    f32 m_unkB8;              // 0xB8
    f32 m_unkBC;              // 0xBC
};
// @decl-end

CModelAccResMgr::CModelAccResMgr() {
    D_002A05D0 = this;
}

CModelAccResMgr::~CModelAccResMgr() {
    Func118130();
    D_002A05D0 = 0;
}

INCLUDE_RODATA("asm/nonmatchings/CModelAccResMgr", D_002D3780);
INCLUDE_RODATA("asm/nonmatchings/CModelAccResMgr", D_002D3788);
INCLUDE_RODATA("asm/nonmatchings/CModelAccResMgr", D_002D3790);
INCLUDE_RODATA("asm/nonmatchings/CModelAccResMgr", D_002D37A0);
INCLUDE_RODATA("asm/nonmatchings/CModelAccResMgr", D_002D37B0);
INCLUDE_RODATA("asm/nonmatchings/CModelAccResMgr", D_002D37C0);
int CModelAccResMgr::Func118078(const char *path) {
    u8 buf[0x100];
    int ok = 0;
    Func2491A8(buf, path, D_002A05D4, D_002A05D8, D_002A05DC);
    if (Func249248(buf)) {
        if (func_00110868(&m_models, D_002A05E0, 0)) {
            if (func_00110DC8(&m_motions, D_002A05E4, 0)) {
                ok = func_00111BA8(&m_swing, D_002A05E8) != 0;
            }
        }
    }
    Func249348();
    Func235DE0("load model accessory %d\n", ok);
    return ok;
}
INCLUDE_RODATA("asm/nonmatchings/CModelAccResMgr", D_002D37F0);
INCLUDE_RODATA("asm/nonmatchings/CModelAccResMgr", D_002D3808);

void CModelAccResMgr::Func118130() {
    m_swing.Func111CF8();
    m_motions.Release();
    func_001109D8(&m_models);
}

void CModelAccSub118168::Init() {
    func_002942E0(m_unk28);
    m_unk0 = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = 0;
    m_unk20 = 0;
    m_unk24 = 0;
    m_unk40 = 0;
    m_unk44 = 0;
    m_unk50 = 1.0f;
    m_unk54 = 1.0f;
    m_unk58 = 1.0f;
    m_unk5C = 0;
    m_unk60 = 0;
    m_unk70 = 0;
    m_unk74 = 0;
    m_unk78 = 0;
    m_unk7C = 1.0f;
    m_unk80 = 0;
    m_unk84 = 0;
    m_unk90 = 1.0f;
    m_unk94 = 1.0f;
    m_unk98 = 1.0f;
    m_unk9C = 1.0f;
    m_unkA0 = 0;
    m_unkB0 = 1.0f;
    m_unkB4 = 1.0f;
    m_unkB8 = 1.0f;
    m_unkBC = 1.0f;
}
