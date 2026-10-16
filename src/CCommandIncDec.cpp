#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"
#include "CFlagWork.h"
#include "CCommandBase.h"
extern CFlagWork *D_002A5358;
class CUnk1A4298 {
public:
    int Func1A4298();
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
u8 *Func237570(int n);
void Func237A88(void *p, int v);
void *Func237C30(void *p);
int Func238158(void *p, int v);
void Func225240(int v);
#include "CMenuMgrSub1B4768.h"
class CMenuMgr {
public:
    int Func1B4ED0(int v);
};
extern CMenuMgrSub1B4768 *D_002A5530;
extern void *D_002A5534;
#include "CMenuLoadMemorialSub17B3A0.h"
extern CMenuLoadMemorialSub17B3A0 *D_002A3AF8;
// Command menu with +/- rows. Update is the vtable's key method: written as a plain member
// here (the unit shares its object with CStatusBase, so its vtable stays asm).
class CCommandIncDec {
public:
    void Update();
    s32 Draw();
    s32 NumRows() { return ((CCommandBase *)this)->NumRows(); }

    u8 pad0[0x48];
    CUnk1A4298 *m_unk48;      // 0x48
};
extern "C" void func_001995F0(CCommandIncDec *p);
extern "C" void func_00199BC0(CCommandIncDec *p);
extern "C" void func_001A40C8(void *p);
extern "C" int func_001972E8(CCommandIncDec *p);
// CMenuRecord.cpp: the same object (its text sits in that file).
class CMenuRecordList {
public:
    int Func197FA8();
    int Draw1974F8();
    int Draw1976A0();
};
extern "C" int func_0019A480(CCommandIncDec *p);
extern "C" int func_001B5E18(void *p);
// @decl-end

void CCommandIncDec::Update() {
    if (D_002A5358->Func1091B0(0x1FF) == 0) {
        func_001995F0(this);
    } else {
        func_00199BC0(this);
    }
    func_001A40C8(m_unk48);
}

s32 CCommandIncDec::Draw() {
    if (m_unk48 == 0) {
        Func225088();
        return Func2250C0();
    }
    u8 *p = Func237570(0x70);
    Func237A88(p, 7);
    CUnk237E90 *a = (CUnk237E90 *)(p + 0x20);
    Func238158(Func237C30(p + 0x60), 1);
    CUnk237E90 *c = (CUnk237E90 *)(p + 0x50);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unk48->Func1A4298());
    CUnk237E90 *b = (CUnk237E90 *)(p + 0x40);
    a->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x21)));
    a->Func237E90(func_001972E8(this));
    if (NumRows() >= 2) a->Func237E90(((CMenuRecordList *)this)->Draw1974F8());
    a->Func237E90(D_002A3AF8->Func17B4A0());
    a->Func237E90(((CMenuRecordList *)this)->Draw1976A0());
    b->Func237E90(func_001B5E18(D_002A5534));
    if (NumRows() >= 2) b->Func237E90(((CMenuRecordList *)this)->Func197FA8());
    c->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x42)));
    c->Func237E90(func_0019A480(this));
    Func225088();
    Func225240((int)p);
    return Func2250C0();
}
