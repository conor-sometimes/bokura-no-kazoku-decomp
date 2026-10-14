#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CPadMgr {
public:
    void Update();
    void SetUnk18(s32 v);

    u8 pad0[0x8];
    s32 m_unk8;               // 0x8
    s32 m_unkC;               // 0xC
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
};

//@sym __8CFadeMgrPvi 0x10B068
//@sym __nw__5CTaskUi 0x24F2E8
class CTask {
public:
    static void *operator new(unsigned int n);

    u8 m_task[4];             // 0x0 (layout unknown)
};
class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};
class CFadeMgr : public CTask {
public:
    CFadeMgr(void *p, s32 n) throw();

    u8 pad4[0x5C];
};
extern u8 D_0029F394[];
s32 Func22D0A0(s32 port);
s32 Func22D008(s32 port);
s32 Func22D1D0(s32 port);
s32 Func22D138(s32 port);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/IPadMgr", func_0010AF00);

void CPadMgr::SetUnk18(s32 v) {
    if (m_unk18 != v) {
        m_unk18 = v;
        m_unk8 = 0;
        m_unk10 = 0;
        m_unk14 = 0;
        m_unkC = 0;
    }
}

void CPadMgr::Update() {
    if (m_unk18) {
        m_unkC = Func22D0A0(0);
        m_unk8 = Func22D008(0);
        m_unk10 = Func22D1D0(0);
        m_unk14 = Func22D138(0);
    }
}

void AddFadeMgr(CTaskList24F5C0 *list) {
    u8 *p = D_0029F394;
    CFadeMgr *t = new CFadeMgr(p, 8);
    list->Func24F5C0(t, 0);
}
