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
class CMenuChildStatusObj {
public:
    int Func18AE18();
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
int Func225088();
int Func2250C0();
void Func225240(s32 v);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuChildStatus", Init18A480__20CChrBodyWinSub18A410);

INCLUDE_ASM("asm/nonmatchings/CMenuChildStatus", func_0018A4D0);

INCLUDE_ASM("asm/nonmatchings/CMenuChildStatus", func_0018A548);

int CMenuChildStatusObj::Func18AE18() {
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
