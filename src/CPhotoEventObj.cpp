#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CPhotoEventObj {
public:
    int Func16D3A0();


};

//@sym __23CPhotoEventObjSub16D4D8 0x16D4D8
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
class CPhotoEventObjSub16D4D8 : public CTask {
public:
    CPhotoEventObjSub16D4D8() throw();

    u8 pad4[0x21C];
};
class CPhotoEventObjSub8 {
public:
    void Func16E008(s32 a, s32 b, s32 c);
};
class CPhotoEventObj2 {
public:
    void Func16D448(s32 v);

    u8 pad0[0x8];
    CPhotoEventObjSub8 *m_unk8; // 0x8
    u8 padC[0xFCFC];
    s32 m_unkFD08;            // 0xFD08
    s32 m_unkFD0C;            // 0xFD0C
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", func_0016CF98);

INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", func_0016D2D8);

int CPhotoEventObj::Func16D3A0() {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", func_0016D3A8);

void CPhotoEventObj2::Func16D448(s32 v) {
    if (v == 0) {
        m_unk8->Func16E008(m_unkFD08, m_unkFD0C, 0);
    }
}

void AddPhotoEventObjSub16D4D8(CTaskList24F5C0 *list) {
    CPhotoEventObjSub16D4D8 *t = new CPhotoEventObjSub16D4D8;
    list->Func24F5C0(t, 0);
}

INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", __23CPhotoEventObjSub16D4D8);
