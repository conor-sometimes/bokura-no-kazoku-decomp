#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CSceneSetItemA {
public:
    u8 m_used;                // 0x0
    u8 pad1[0x1F];
    char m_name[0x20];        // 0x20
    s32 m_unk40;              // 0x40
    s32 m_unk44;              // 0x44
    s32 m_unk48;              // 0x48
    s32 m_unk4C;              // 0x4C
    s32 m_unk50;              // 0x50
};
class CSceneSetItemB {
public:


    u8 m_used;                // 0x0
    u8 pad1[0x1F];
    s32 m_unk20;              // 0x20
    s32 m_unk24;              // 0x24
};
#include "libc.h"
// The two TArray members (inline template code at 0x2965xx-0x2966xx): calls only.
// TArray<CSceneMapSet> (constructor 0x296578, linkonce template code; name in config/aliases.ld).
class CDkArr {
public:
    CDkArr();

    u8 pad0[0x18];
};
class CDkList {
public:
    CDkList();                // 0x2965F8 (config/aliases.ld)
    s32 Func296570();

    u8 pad0[0x18];
};
extern "C" s32 func_00296568(void *arr);
extern "C" void func_00296678(void *arr, s32 n);
extern "C" CSceneSetItemA *func_00296698(void *arr, s32 i);
extern "C" void func_002966B0(void *arr, s32 n);
extern "C" CSceneSetItemB *func_002966D0(void *arr, s32 i);
extern "C" CSceneSetItemB *func_002966E8(void *arr, s32 i);
class CSndNode;
class CSndWorkReal {
public:
    void CallFunc129458(const char *s, s32 v);
    void MoveToList(CSndNode *node);

    s32 m_unk0;               // 0x0
    s32 m_unk4;               // 0x4
};
extern "C" void func_00128E78(void *snd, s32 v);
// Vtable _vt$9CSceneSet (asm; its piece also holds the two TArray vtables): vptr at 0x3C.
class CSceneSet {
public:
    CSceneSet();
    virtual ~CSceneSet();
    int SetSnd(CSndWorkReal *snd);
    void ReleaseSnd();
    CSceneSetItemA *FindA(s32 id);
    CSceneSetItemB *FindB(s32 id);
    s32 GetAUnk4C(s32 id);
    s32 GetAUnk50(s32 id);
    s32 GetBUnk20(s32 id);
    s32 GetBUnk24(s32 id);
    void Func12CF40(s32 id);
    void Func12CB00(s32 i);
    int InitA(s32 n);
    void ResetA();
    int InitB(s32 n);
    void ResetB();
    void ClearA();
    void ClearB();
    s32 CountB();

    CDkArr m_arr;             // 0x00 TArray<CSceneMapSet>
    CDkList m_list;           // 0x18 TArray<CSceneCharaSet>
    CSndWorkReal *m_unk30;    // 0x30
    s32 m_unk34;              // 0x34
    s32 m_unk38;              // 0x38
    // vptr 0x3C
};
// CCharaObj.cpp: vptr at 0xC (virtual destructor only).
class CCharaObj {
public:
    virtual ~CCharaObj();
    void ReleaseSwing();
    void ReleaseDiff();
    void Func113898();
    void Release113758();

    u8 pad0[0xC];
};
class CResCache {
public:
    void Func250840(void *item);
};
extern CResCache *D_002A0BE4;
extern "C" void func_00128F10(void *snd, s32 v);
//@sym FindA__9CSceneSeti 0x12CC60
//@sym FindB__9CSceneSeti 0x12D070

class CMapObj {
public:
    virtual ~CMapObj();
    void Func11AF60();
    u8 pad0[0x30];
};
extern CResCache *D_002A0BE8;
extern CResCache *D_002A0BEC;
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CSceneSet", D_002D4E10);
INCLUDE_RODATA("asm/nonmatchings/CSceneSet", D_002D4E48);
INCLUDE_RODATA("asm/nonmatchings/CSceneSet", D_002D4E88);
INCLUDE_RODATA("asm/nonmatchings/CSceneSet", D_002D4EC8);
CSceneSet::CSceneSet() {
    m_unk30 = 0;
    m_unk34 = 0;
    m_unk38 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012C4F0);

int CSceneSet::InitA(s32 n) {
    ResetA();
    func_00296678(&m_arr, n);
    memset(func_00296698(&m_arr, 0), 0, n * sizeof(CSceneSetItemA));
    return 1;
}

void CSceneSet::ResetA() {
    if (func_00296568(&m_arr)) {
        ClearA();
        func_00296678(&m_arr, 0);
    }
}

int CSceneSet::InitB(s32 n) {
    ResetB();
    func_002966B0(&m_list, n);
    memset(func_002966D0(&m_list, 0), 0, n * sizeof(CSceneSetItemB));
    return 1;
}

void CSceneSet::ResetB() {
    if (m_list.Func296570()) {
        ClearB();
        func_002966B0(&m_list, 0);
    }
}

int CSceneSet::SetSnd(CSndWorkReal *snd) {
    s32 i;
    ReleaseSnd();
    m_unk30 = snd;
    for (i = 0; i < m_list.Func296570(); i++) {
        if (func_002966D0(&m_list, i)->m_unk24) {
            m_unk30->MoveToList((CSndNode *)func_002966D0(&m_list, i)->m_unk24);
        }
    }
    for (i = 0; i < func_00296568(&m_arr); i++) {
        if (func_00296698(&m_arr, i)->m_unk50) {
            func_00128E78(m_unk30, func_00296698(&m_arr, i)->m_unk50);
        }
    }
    return 1;
}

void CSceneSet::ReleaseSnd() {
    s32 i;
    if (m_unk30) {
        for (i = 0; i < m_list.Func296570(); i++) {
            if (func_002966D0(&m_list, i)->m_unk24) {
                func_00128F10(m_unk30, func_002966D0(&m_list, i)->m_unk24);
            }
        }
        for (i = 0; i < func_00296568(&m_arr); i++) {
            if (func_00296698(&m_arr, i)->m_unk50) {
                s32 cur = m_unk30->m_unk4;
                if (cur == func_00296698(&m_arr, i)->m_unk50) {
                    func_00128E78(m_unk30, 0);
                }
            }
        }
        m_unk30 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012C8D0);

void CSceneSet::Func12CB00(s32 id) {
    CSceneSetItemA *p = FindA(id);
    if (!p) return;
    if (m_unk30 && m_unk30->m_unk4 == p->m_unk50) func_00128E78(m_unk30, 0);
    if (m_unk30) m_unk30->CallFunc129458(p->m_name, p->m_unk48);
    ((CMapObj *)p->m_unk50)->Func11AF60();
    if ((CMapObj *)p->m_unk50) delete (CMapObj *)p->m_unk50;
    p->m_unk50 = 0;
    p->m_unk4C = 0;
    D_002A0BE8->Func250840(p);
    p->m_used = 0;
    if (m_unk38 == 0) D_002A0BEC->Func250840(p->m_name);
    p->m_unk44 = 1;
    p->m_name[0] = 0;
    p->m_unk40 = 0;
    p->m_unk48 = -1;
}

void CSceneSet::ClearA() {
    s32 i;
    for (i = 0; i < func_00296568(&m_arr); i++) {
        if (func_00296698(&m_arr, i)->m_unk50) {
            Func12CB00(i);
        }
    }
}

CSceneSetItemA *CSceneSet::FindA(s32 id) {
    if (id < 0 || func_00296568(&m_arr) - 1 < id || func_00296698(&m_arr, id)->m_unk50 == 0) return 0;
    return func_00296698(&m_arr, id);
}

s32 CSceneSet::GetAUnk4C(s32 id) {
    CSceneSetItemA *p = FindA(id);
    if (p) {
        return p->m_unk4C;
    }
    return 0;
}

s32 CSceneSet::GetAUnk50(s32 id) {
    CSceneSetItemA *p = FindA(id);
    if (p) {
        return p->m_unk50;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CSceneSet", func_0012CD30);

void CSceneSet::Func12CF40(s32 id) {
    CSceneSetItemB *p = FindB(id);
    if (p) {
        if (m_unk30) {
            func_00128F10(m_unk30, p->m_unk24);
        }
        ((CCharaObj *)p->m_unk24)->ReleaseSwing();
        ((CCharaObj *)p->m_unk24)->ReleaseDiff();
        ((CCharaObj *)p->m_unk24)->Func113898();
        ((CCharaObj *)p->m_unk24)->Release113758();
        delete (CCharaObj *)p->m_unk24;
        p->m_unk24 = 0;
        p->m_unk20 = 0;
        D_002A0BE4->Func250840(p);
        p->m_used = 0;
    }
}

void CSceneSet::ClearB() {
    s32 i;
    for (i = 0; i < m_list.Func296570(); i++) {
        if (func_002966D0(&m_list, i)->m_unk24) {
            Func12CF40(i);
        }
    }
}

CSceneSetItemB *CSceneSet::FindB(s32 id) {
    if (id < 0 || m_list.Func296570() - 1 < id) return 0;
    if (func_002966D0(&m_list, id)->m_unk24 == 0) return 0;
    return func_002966D0(&m_list, id);
}

s32 CSceneSet::GetBUnk20(s32 id) {
    CSceneSetItemB *p = FindB(id);
    if (p) {
        return p->m_unk20;
    }
    return 0;
}

s32 CSceneSet::GetBUnk24(s32 id) {
    CSceneSetItemB *p = FindB(id);
    if (p) {
        return p->m_unk24;
    }
    return 0;
}

s32 CSceneSet::CountB() {
    s32 i;
    s32 c = 0;
    s32 n = m_list.Func296570();
    for (i = 0; i < n; i++) {
        if (func_002966E8(&m_list, i)->m_unk24) {
            c++;
        }
    }
    return c;
}
