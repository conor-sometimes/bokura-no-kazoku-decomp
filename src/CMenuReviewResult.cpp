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
    void GetUnk60Ofs(f32 *x, f32 *y, s32 i);

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
extern char D_002DBB90[];

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuReviewResult.
class CMenuReviewResult : public CMenuProcess {
public:
    CMenuReviewResult();
    virtual ~CMenuReviewResult();
    virtual s32 Update();
    virtual s32 Draw();
    void Init191338();        // CMenuReviewSelect's constructor (that unit's name for it)

    CStatusItem *m_unk58;     // 0x58
    CStatusItem *m_unk5C;     // 0x5C
    u8 pad60[0x8];
    s32 m_unk68;              // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    f32 m_unk74;              // 0x74
};

void *operator new(unsigned int n);
CMenuReviewResult *NewCMenuReviewResult();
// @decl-end

CMenuReviewResult::CMenuReviewResult() {
    m_unk58 = 0;
    m_unk5C = 0;
    m_unk68 = 0;
    m_unk6C = 0;
    m_unk70 = 0;
    m_unk74 = 0;
}

CMenuReviewResult::~CMenuReviewResult() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuReviewResult", Update__17CMenuReviewResult);
INCLUDE_RODATA("asm/nonmatchings/CMenuReviewResult", D_002DBB80);

INCLUDE_RODATA("asm/nonmatchings/CMenuReviewResult", D_002DBB90);
INCLUDE_ASM("asm/nonmatchings/CMenuReviewResult", Draw__17CMenuReviewResult);

// Creates the CMenuReviewSelect screen.
CMenuReviewResult *NewCMenuReviewResult() {
    CMenuReviewResult *p = (CMenuReviewResult *)operator new(0x7C);
    p->Init191338();
    return p;
}
