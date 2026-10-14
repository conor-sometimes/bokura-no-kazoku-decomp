#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_0018AF98(void *p);
class CMenuCommon {
public:
    static CMenuCommon *Create();
};

class CChrBodyWin {
public:
    void Func188BA8();
};
extern CChrBodyWin *D_002A4308;
extern "C" int func_00245818(void *p, s32 v);
class CStatusBaseSub19AD40 {
public:
    ~CStatusBaseSub19AD40();
};
class CMenuChildStatusSub18B9E0 {
public:
    ~CMenuChildStatusSub18B9E0();
};
//@sym _$_25CMenuChildStatusSub18B9E0 0x18B9E0
// Release18AF18 sits after CMenuCommon's factory: probably CMenuCommon's (unit starts late).
class CMenuChildStatusObj {
public:
    void Release18AF18();
    u8 pad0[0x58];
    u8 m_unk58[0xC];          // 0x58
    void *m_unk64;            // 0x64
    CMenuChildStatusSub18B9E0 *m_unk68; // 0x68
    CStatusBaseSub19AD40 *m_unk6C; // 0x6C
};

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

#include "CMenuProcess.h"
#include "CBgWork.h"
extern "C" void func_0018A410(void *p);

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuChildStatus.
// Its release function (0x18A410) sits at the end of CChrBodyWin.cpp (unit text starts late).
class CMenuChildStatus : public CMenuProcess {
public:
    CMenuChildStatus();
    virtual ~CMenuChildStatus();
    virtual s32 Update();
    virtual s32 Draw();

    CBgWork m_bg;             // 0x58
    void *m_unk64;            // 0x64
    void *m_unk68;            // 0x68
    void *m_unk6C;            // 0x6C
    u8 pad70[0x18];
    s32 m_unk88;              // 0x88
    u8 pad8C[0x4];
    s32 m_unk90;              // 0x90
};
// @decl-end
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB028);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB038);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB068);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB090);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB0C0);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB0C8);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB1C8);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB1F8);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB218);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB228);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB250);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB270);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB2A0);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB2B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB2C0);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB2C8);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB2D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB2D8);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB2E0);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB2E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB310);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB338);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB340);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB348);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB358);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB380);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB3B0);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB3D8);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB400);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB428);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB458);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB478);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB4B8);

CMenuChildStatus::CMenuChildStatus() {
    m_unk64 = 0;
    m_unk68 = 0;
    m_unk6C = 0;
    m_unk88 = 0;
    m_unk90 = 0;
}

CMenuChildStatus::~CMenuChildStatus() {
    func_0018A410(this);
}

INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB4D8);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB4E0);
INCLUDE_RODATA("asm/nonmatchings/CMenuChildStatus", D_002DB500);
INCLUDE_ASM("asm/nonmatchings/CMenuChildStatus", Update__16CMenuChildStatus);

s32 CMenuChildStatus::Draw() {
    if (m_unk64 == 0) {
        Func225088();
        return Func2250C0();
    }
    u8 *p = func_00237570(0x30);
    CUnk237E90 *q = (CUnk237E90 *)(p + 0x10);
    func_00237A88(p, 3);
    func_00238158(func_00237C30(p + 0x20), 1);
    q->Func237E90(func_001A0510(m_unk68));
    q->Func237E90(func_0018A1F0(m_unk64));
    Func225088();
    Func225240((s32)p);
    return Func2250C0();
}

CMenuCommon *CMenuCommon::Create() {
    CMenuCommon *p = (CMenuCommon *)operator new(0x74);
    func_0018AF98(p);
    return p;
}

void CMenuChildStatusObj::Release18AF18() {
    func_00245818(m_unk58, 1);
    D_002A4308->Func188BA8();
    if (m_unk64) {
        operator delete(m_unk64);
        m_unk64 = 0;
    }
    if (m_unk68) {
        delete m_unk68;
        m_unk68 = 0;
    }
    if (m_unk6C) {
        delete m_unk6C;
        m_unk6C = 0;
    }
}
