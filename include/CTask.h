#ifndef CTASK_H
#define CTASK_H
#pragma interface

#include "common.h"

// Task base classes (library code 0x24F2E8-0x24FA88; vtables _vt$5CTask 0x2C2478 and
// _vt$8CProcess 0x2C24C0 in asm). Nothing here is defined in a unit: the names are in
// config/symbol_addrs.txt. Slot 3 is the per-frame update and slot 5 the draw in every derived
// class (CSnapMgr: Update10B9E8, Draw10BEF0).
class CTask {
public:
    static void *operator new(unsigned int n);  // 0x24F2E8
    static void operator delete(void *p);       // 0x24F310
    CTask();                                    // 0x24F338
    virtual ~CTask();                           // [0] 0x24F388
    virtual void Func1();                       // [1] 0x24F7E8 (empty)
    virtual void Func2();                       // [2] 0x24F7F0 (empty)
    virtual void Update();                      // [3] 0x24F7F8 (empty)
    virtual void Func4();                       // [4] 0x24F800 (empty)
    virtual void Draw();                        // [5] 0x24F808 (empty)
    virtual void Func6();                       // [6] 0x24F810 (empty)

    s32 m_unk0;               // 0x0
    // vptr 0x4
};

#endif
