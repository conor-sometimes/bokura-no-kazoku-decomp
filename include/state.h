#ifndef STATE_H
#define STATE_H

#include "common.h"

// Reconstruction of ../dklib/include/state.h: a nested state machine whose Update functions are
// written as one switch on the state (states are -__LINE__ of the line that yields; -1 is the start).
// The asserts print state.h's own file name and line numbers (68, 70, 72, 76), so they are spelled
// out here. The file name is an argument of an inline function, as in retail: it is computed before
// the test (and GCSE shares it between the asserts).
// The debug printf (Func235DE0) under its own name: units declare Func235DE0 with different return
// types.
extern "C" int SmPrint(const char *fmt, ...) throw() asm("Func235DE0__FPCce");

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
    void Check(s32 v, const char *file, s32 line) {
        if (!((u32)v < 16))
            SmPrint("*** CStateMachine stack over or under flow (%d) in %s(%d)\n", m_depth, file, line);
    }
    // Push(n)/Pop(n) reserve/release n stack slots; Var(k)/Get(k) address the k-th slot below the
    // top. Push's n is a parameter even when 1: retail's push adds a register that already holds 1
    // when there is one (CMovieObj 0x13E938); CMenuMemorial pushes 4.
    void Push(s32 n = 1) {
        Check(m_depth + n, "../dklib/include/state.h", 68);
        m_depth += n;
    }
    void Pop(s32 n = 1) {
        Check(m_depth - n, "../dklib/include/state.h", 70);
        m_depth = (s16)m_depth - n;
    }
    s32 &Var(s32 k = 0) {
        s32 *p;
        Check(m_depth - k, "../dklib/include/state.h", 72);
        p = m_stack;
        return p[m_depth - k];
    }
    s32 Get(s32 k = 0) {
        Check(m_depth - k, "../dklib/include/state.h", 76);
        return m_stack[m_depth - k];
    }
};

#endif
