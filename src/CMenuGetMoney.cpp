#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"
class CVec4 {
public:
    f32 x, y, z, w;
};
// The window item (CStatusWin.cpp); Func1A4298 is named under another class there.
class CStatusItem {
public:
    int GetColor(CVec4 *out, s32 i);
    void GetPos(f32 *x, f32 *y, s32 i);

    u8 pad0[0x34];
    f32 m_unk34;              // 0x34
};
class CUnk1A4298 {
public:
    int Func1A4298();
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
#include "CMenuMgrSub1B5BF8.h"
extern CMenuMgrSub1B5BF8 *D_002A5534;
extern "C" int func_001B5E18(CMenuMgrSub1B5BF8 *p);
extern "C" int func_001B5FE0(CMenuMgrSub1B5BF8 *p, f32 x, f32 y, const char *s);
#include "CMenuMgrSub1B4768.h"
class CMenuMgr {
public:
    int Func1B4ED0(int v);
};
extern CMenuMgrSub1B4768 *D_002A5530;
extern "C" int func_001B50B0(CMenuMgrSub1B4768 *p, int k);
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
extern "C" int func_001B66E8(CMenuMgrSub1B6418 *p);
extern "C" int sprintf(char *buf, const char *fmt, ...);
void *Func237570(int size);
void Func237A88(void *p, int n);
void *Func237C30(void *p);
void Func238158(void *p, int v);
void Func225240(int v);
#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
extern char D_002DBB08[];

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuGetMoney.
class CMenuGetMoney : public CMenuProcess {
public:
    CMenuGetMoney();
    virtual ~CMenuGetMoney();
    virtual s32 Update();
    virtual s32 Draw();

    CStatusItem *m_unk58;     // 0x58
    CStatusItem *m_unk5C;     // 0x5C
    s32 m_unk60;              // 0x60
    u8 pad64[0x4];
    s32 m_unk68;              // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
    f32 m_unk78;              // 0x78
};

extern "C" void func_001900B0(void *p);
class CMenuReviewResult {
public:
    static CMenuReviewResult *Create();
};
// @decl-end

CMenuGetMoney::CMenuGetMoney() {
    m_unk58 = 0;
    m_unk5C = 0;
    m_unk78 = 1.0f;
    m_unk68 = 0;
    m_unk6C = 0;
    m_unk70 = 0;
    m_unk74 = 0;
    m_unk60 = 0;
}

CMenuGetMoney::~CMenuGetMoney() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuGetMoney", Update__13CMenuGetMoney);

INCLUDE_RODATA("asm/nonmatchings/CMenuGetMoney", D_002DBB08);
INCLUDE_ASM("asm/nonmatchings/CMenuGetMoney", Draw__13CMenuGetMoney);

CMenuReviewResult *CMenuReviewResult::Create() {
    CMenuReviewResult *p = (CMenuReviewResult *)operator new(0x78);
    func_001900B0(p);
    return p;
}
