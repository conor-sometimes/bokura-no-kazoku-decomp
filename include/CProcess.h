#ifndef CPROCESS_H
#define CPROCESS_H

#include "CTask.h"
#include "CBgWork.h"

// Base of the game's main tasks (CBootMain, CLogoMain, CTitleMain, CGameResort, ...). Its own
// methods touch nothing past 0x14 (tools/bk/structs.py), so derived fields start at 0x18.
class CProcess : public CTask {
public:
    CProcess();                                 // 0x24F818
    virtual ~CProcess();                        // [0] 0x24F858
    virtual void Func2();                       // [2] 0x24F8D0
    virtual s32 Func7();                        // [7] 0x24FA78 (returns 1)
    virtual void ReleaseTextures();             // [8] 0x24FA80 (empty)

    CBgWork m_bg;             // 0x8
    s32 m_unk14;              // 0x14
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
