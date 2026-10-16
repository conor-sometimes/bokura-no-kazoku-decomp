#ifndef CPROCESS_H
#define CPROCESS_H
#pragma interface

#include "CTask.h"
#include "CBgWork.h"
#include "state.h"

// Base of the game's main tasks (CBootMain, CLogoMain, CTitleMain, CGameResort, ...). Derived
// classes put their fields from 0x18, but CProcess's own dklib methods (lane d1) also use
// 0x18-0x28, so those words are shared with the derived layout; not modelled here yet.
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


#endif
