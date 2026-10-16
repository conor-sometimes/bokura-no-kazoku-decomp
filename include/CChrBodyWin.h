#ifndef CCHRBODYWIN_H
#define CCHRBODYWIN_H

#include "common.h"

// Hoisted from the units that declared it locally (tools/bk/hoist.py).
class CChrBodyWin {
public:
    void Func188BA8();
    void CallFunc188BA8();
    void Func188778(f32 *a, f32 *b, f32 *c, f32 *d);
    void SetUnk384(f32 v);
    void SetChar(s32 c);
    void Clear1884B0();
    void Open(int c);
    int Func1889F8();
    void SetMode1();
    void SetMode2();
    void SetMode5();
    int Check2To3();
    int Check3To4();
    void Set189348(int a, int b);
};

#endif
