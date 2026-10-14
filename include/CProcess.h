#ifndef CPROCESS_H
#define CPROCESS_H

#include "common.h"
#include "CBgWork.h"

// Task system (library side of .text, 0x24F2E8-0x24FA80). The slot names VFuncN are
// placeholders: CTask declares seven slots, the vptr follows its one field at 0x4.
class CTask {
public:
    CTask();                          // 0x24F338
    virtual ~CTask();                 // 0x24F388
    virtual void VFunc1();            // 0x24F7E8 (empty)
    virtual void VFunc2();            // 0x24F7F0 (empty)
    virtual void VFunc3();            // 0x24F7F8 (empty)
    virtual void VFunc4();            // 0x24F800 (empty)
    virtual void VFunc5();            // 0x24F808 (empty)
    virtual void VFunc6();            // 0x24F810 (empty)
    static void *operator new(unsigned int n);   // 0x24F2E8
    static void operator delete(void *p);        // 0x24F310

    s32 m_unk0;               // 0x00
    // vptr 0x04
};

// Base of the game's main tasks (CBootMain, CLogoMain, CTitleMain, ...).
class CProcess : public CTask {
public:
    CProcess();                       // 0x24F818
    virtual ~CProcess();              // 0x24F858
    virtual void VFunc2();            // 0x24F8D0
    virtual void VFunc7();            // 0x24FA78
    virtual void ReleaseTextures();   // 0x24FA80 (empty)

    CBgWork m_bg;             // 0x08
    s32 m_unk14;              // 0x14
    u8 pad18[0x14];
};

// Nested state stack from ../dklib/include/state.h (inline; asserts print
// "*** CStateMachine stack over or under flow").
struct CStateMachine {
    u16 m_flags;              // 0x00 (bit 7: busy)
    u16 m_depth;              // 0x02
    s32 m_state;              // 0x04
    s32 m_stack[16];          // 0x08

    CStateMachine() {
        m_state = -1;
        m_depth = 0;
        m_flags = 0;
    }
};

#endif
