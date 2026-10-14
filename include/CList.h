#ifndef CLIST_H
#define CLIST_H

#include "common.h"

// Intrusive list node (vtable _vt$8CListTag, CList unit). A list head has m_isHead set; an
// empty list's head points at itself.
class CListTag {
public:
    CListTag() {
        m_isHead = 0;
        m_next = this;
        m_prev = this;
    }
    virtual ~CListTag();

    s32 m_isHead;             // 0x0
    CListTag *m_prev;         // 0x4
    CListTag *m_next;         // 0x8
    // vptr 0xC
};

#endif
