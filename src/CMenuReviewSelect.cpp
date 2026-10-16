#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_00191E28(void *p);
class CMenuReviewStart {
public:
    static CMenuReviewStart *Create();
};
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
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuReviewSelect.
class CMenuReviewSelect : public CMenuProcess {
public:
    CMenuReviewSelect();
    virtual ~CMenuReviewSelect();
    virtual s32 Update();
    virtual s32 Draw();

    CStatusItem *m_unk58;     // 0x58
    CStatusItem *m_unk5C;     // 0x5C
    u8 pad60[0x8];
    s32 m_unk68[5];           // 0x68
};
// @decl-end

CMenuReviewSelect::CMenuReviewSelect() {
    s32 i;
    m_unk58 = 0;
    m_unk5C = 0;
    for (i = 4; i >= 0; i--) {
        m_unk68[i] = 0;
    }
}

CMenuReviewSelect::~CMenuReviewSelect() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuReviewSelect", Update__17CMenuReviewSelect);
INCLUDE_RODATA("asm/nonmatchings/CMenuReviewSelect", D_002DBC00);
INCLUDE_RODATA("asm/nonmatchings/CMenuReviewSelect", D_002DBC20);

s32 CMenuReviewSelect::Draw() {
    f32 x, y;
    char buf[0x100];
    CVec4 col;
    u8 *p;
    s32 i;
    if (!m_unk58 || !m_unk5C) {
        Func225088();
        Func2250C0();
    } else {
        p = (u8 *)Func237570(0x60);
        Func237A88(p, 6);
        Func238158(Func237C30(p + 0x50), 1);
        ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_unk58)->Func1A4298());
        ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_unk5C)->Func1A4298());
        ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B5E18(D_002A5534));
        D_002A5534->Reset();
        D_002A5534->SetUnk30(1);
        D_002A5534->SetUnk1C(m_unk5C->m_unk34);
        D_002A5534->SetUnk0(1.0f, 1.0f);
        for (i = 0; i < 5; i++) {
            sprintf(buf, "%d", m_unk68[i]);
            m_unk5C->GetPos(&x, &y, i + 0xC);
            switch (i) {
            case 0:
                D_002A5534->SetUnk10(0.78f, 0.78f, 0.78f);
                D_002A5534->SetUnk34(2);
                break;
            case 1:
                m_unk5C->GetColor(&col, 0x11);
                D_002A5534->SetUnk10(col.x * 0.0078125f, col.y * 0.0078125f, col.z * 0.0078125f);
                D_002A5534->SetUnk34(0);
                break;
            case 4:
                m_unk5C->GetColor(&col, 0x11);
                D_002A5534->SetUnk10(col.x * 0.0078125f, col.y * 0.0078125f, col.z * 0.0078125f);
                D_002A5534->SetUnk34(1);
                break;
            default:
                D_002A5534->SetUnk10(0.78f, 0.78f, 0.78f);
                D_002A5534->SetUnk34(1);
                break;
            }
            ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B5FE0(D_002A5534, x, y, buf));
        }
        D_002A5534->SetUnk34(0);
        ((CUnk237E90 *)(p + 0x30))->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x18)));
        D_002A5530->Reset1B4D28();
        D_002A5530->SetUnk4C(m_unk5C->m_unk34);
        for (i = 0; i < 4; i++) {
            m_unk5C->GetPos(&x, &y, i + 8);
            D_002A5530->SetUnk20(x, y, 0.0f);
            ((CUnk237E90 *)(p + 0x30))->Func237E90(func_001B50B0(D_002A5530, 0x18));
        }
        D_002A5538->SetUnk4C(m_unk58->m_unk34);
        ((CUnk237E90 *)(p + 0x40))->Func237E90(func_001B66E8(D_002A5538));
        Func225088();
        Func225240((int)p);
        Func2250C0();
    }
}

CMenuReviewStart *CMenuReviewStart::Create() {
    CMenuReviewStart *p = (CMenuReviewStart *)operator new(0x68);
    func_00191E28(p);
    return p;
}
