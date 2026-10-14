#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym __19CInterfResSub169090 0x169090
//@sym __nw__5CTaskUi 0x24F2E8
//@sym __builtin_vec_delete 0x2456D0
class CTask {
public:
    static void *operator new(unsigned int n);

    u8 m_task[4];             // 0x0 (layout unknown)
};
class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};
class CInterfResSub169090 : public CTask {
public:
    CInterfResSub169090() throw();

    u8 pad4[0xDF4];
};
void Func23B1D0(s32 h);
class CInterfRes {
public:
    void Release();

    u8 pad0[0x10];
    s32 *m_handles;           // 0x10
};

//@sym __builtin_vec_delete 0x2456D0
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CInterfRes", func_00168DC8);

INCLUDE_ASM("asm/nonmatchings/CInterfRes", func_00168DF0);

INCLUDE_ASM("asm/nonmatchings/CInterfRes", func_00168E88);

void CInterfRes::Release() {
    if (m_handles) {
        s32 i;
        for (i = 0; i < 4; i++) {
            if (m_handles[i] >= 0) {
                Func23B1D0(m_handles[i]);
                m_handles[i] = -1;
            }
        }
        if (m_handles) {
            delete[] m_handles;
        }
        m_handles = 0;
    }
}

void AddInterfResSub169090(CTaskList24F5C0 *list) {
    CInterfResSub169090 *t = new CInterfResSub169090;
    list->Func24F5C0(t, 0);
}

INCLUDE_ASM("asm/nonmatchings/CInterfRes", __19CInterfResSub169090);
