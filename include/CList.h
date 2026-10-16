#ifndef CLIST_H
#define CLIST_H
#ifdef CLISTTAG_INLINE_DTOR
#pragma interface
#endif

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
#ifdef CLISTTAG_INLINE_DTOR
    // Retail inlines this in destructors of derived classes (~CCharaObj): units that need it
    // define CLISTTAG_INLINE_DTOR before including this header (with #pragma interface, so the
    // unit emits no linkonce copy).
    virtual ~CListTag() {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
#else
    virtual ~CListTag();
#endif

    s32 m_isHead;             // 0x0
    CListTag *m_prev;         // 0x4
    CListTag *m_next;         // 0x8
    // vptr 0xC
};

#endif
