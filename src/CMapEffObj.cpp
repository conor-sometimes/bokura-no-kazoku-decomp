#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
// Vtable 0x2C03F8 (~CMapEffObj only, the key method: its unit shares an object with
// CMapEffObjRes, so it stays asm). The vptr follows its fields at 0x10.
extern "C" void *func_00245DD0(s32 size);
class CMapEffTarget;
class CMapEffObj;
// Effect workers (CMapEffObjRes unit): vptr at 0. Their destructors are inline (linkonce);
// they are declared out of line here so that this unit emits no vtables.
class CMapEffWork {
public:
    static void *operator new(unsigned int n) { return func_00245DD0(n); }
    virtual ~CMapEffWork();
    virtual int IsHit(int k);
    virtual void V2(int v);
    virtual void Update(int arg);
    virtual void Draw(int a, CMapEffTarget *t);
};
class CMapEffMirrorWork : public CMapEffWork {
public:
    CMapEffMirrorWork(CMapEffObj *owner) { m_owner = owner; }
    virtual ~CMapEffMirrorWork();

    CMapEffObj *m_owner;      // 0x4
};

// Effect list entry (CMapEffRes): the first word picks the factory in D_002A0B10.
struct CMapEffEntry {
    s32 m_type;               // 0x0
};
extern CMapEffWork *(*D_002A0B10[])(CMapEffEntry *e);
extern "C" s32 func_00295110(void *list);
extern "C" CMapEffEntry **func_00295170(void *list, s32 i);
// The current-flag object (vtable 0x2C0900, vptr at 0x1C); only the calls are needed here.
class CCurFlag {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual int V5();

    u8 pad0[0x1C];
};
extern CCurFlag *D_002A26E4;

class CMapEffCurtainWork : public CMapEffWork {
public:
    CMapEffCurtainWork(CMapEffObj *owner);
    virtual ~CMapEffCurtainWork();

    u8 pad4[0x20];
};
class CMapEffLeafWork : public CMapEffWork {
public:
    CMapEffLeafWork(CMapEffObj *owner);
    virtual ~CMapEffLeafWork();

    u8 pad4[0x4C];
};
class CMapEffFlyWork : public CMapEffWork {
public:
    CMapEffFlyWork(CMapEffObj *owner);
    virtual ~CMapEffFlyWork();

    u8 pad4[0x10];
};
class CMapEffRainWork : public CMapEffWork {
public:
    CMapEffRainWork(CMapEffObj *owner);
    virtual ~CMapEffRainWork();

    u8 pad4[0x3C];
};
class CMapEffSnowWork : public CMapEffWork {
public:
    CMapEffSnowWork(CMapEffObj *owner);
    virtual ~CMapEffSnowWork();

    u8 pad4[0x4C];
};
class CMapEffAquariumWork : public CMapEffWork {
public:
    CMapEffAquariumWork(CMapEffObj *owner);
    virtual ~CMapEffAquariumWork();

    u8 pad4[0x42BC];
};
class CMapEffBreathWork : public CMapEffWork {
public:
    CMapEffBreathWork(CMapEffObj *owner);
    virtual ~CMapEffBreathWork();

    u8 pad4[0x40EC];
};
class CMapEffSwingWork : public CMapEffWork {
public:
    CMapEffSwingWork(CMapEffObj *owner);
    virtual ~CMapEffSwingWork();

    u8 pad4[0x9C];
};

class CMapEffObj {
public:
    CMapEffObj();
    virtual ~CMapEffObj();
    CMapEffWork *CreateMirror();
    CMapEffWork *CreateCurtain();
    CMapEffWork *CreateLeaf();
    CMapEffWork *CreateFly();
    CMapEffWork *CreateRain();
    CMapEffWork *CreateSnow();
    CMapEffWork *CreateAquarium();
    CMapEffWork *CreateBreath();
    CMapEffWork *CreateSwing();
    void Release();
    void UpdateAll(int arg);
    void DrawAll(int a, CMapEffTarget *t);
    void EnableAll();
    void SetEnable(int k, s32 v);
    void Apply(int k, int v);
    int Load(void *list);

    void *m_unk0;             // 0x0
    CMapEffWork **m_works;    // 0x4
    s32 *m_enabled;           // 0x8
    s32 m_count;              // 0xC
};
// @decl-end

CMapEffObj::CMapEffObj() {
    m_unk0 = 0;
    m_count = 0;
    m_works = 0;
    m_enabled = 0;
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObj", _$_10CMapEffObj);

INCLUDE_ASM("asm/nonmatchings/CMapEffObj", func_00126E98);

CMapEffWork *CMapEffObj::CreateCurtain() {
    return new CMapEffCurtainWork(this);
}

CMapEffWork *CMapEffObj::CreateLeaf() {
    return new CMapEffLeafWork(this);
}

CMapEffWork *CMapEffObj::CreateFly() {
    return new CMapEffFlyWork(this);
}

CMapEffWork *CMapEffObj::CreateRain() {
    return new CMapEffRainWork(this);
}

CMapEffWork *CMapEffObj::CreateSnow() {
    return new CMapEffSnowWork(this);
}

CMapEffWork *CMapEffObj::CreateAquarium() {
    return new CMapEffAquariumWork(this);
}

CMapEffWork *CMapEffObj::CreateMirror() {
    return new CMapEffMirrorWork(this);
}

CMapEffWork *CMapEffObj::CreateBreath() {
    return new CMapEffBreathWork(this);
}

CMapEffWork *CMapEffObj::CreateSwing() {
    return new CMapEffSwingWork(this);
}

int CMapEffObj::Load(void *list) {
    s32 i;
    s32 n;
    Release();
    n = func_00295110(list);
    if (n > 0) {
        m_count = n;
        m_works = new CMapEffWork *[n];
        m_enabled = new s32[m_count];
        for (i = 0; i < n; i++) {
            CMapEffEntry *e = *func_00295170(list, i);
            m_works[i] = 0;
            if (D_002A26E4 && e->m_type == 2) {
                m_enabled[i] = D_002A26E4->V5() != 3;
            } else {
                m_enabled[i] = 1;
            }
            if (e->m_type >= 0) {
                m_works[i] = D_002A0B10[e->m_type](e);
            }
        }
    }
    m_unk0 = list;
    return 1;
}

void CMapEffObj::Release() {
    s32 i;
    if (m_unk0) {
        for (i = 0; i < m_count; i++) {
            if (m_works[i]) {
                delete m_works[i];
            }
        }
        delete[] m_works;
        m_works = 0;
        delete[] m_enabled;
        m_enabled = 0;
        m_count = 0;
        m_unk0 = 0;
    }
}

void CMapEffObj::EnableAll() {
    s32 i;
    for (i = 0; i < m_count; i++) {
        m_enabled[i] = 1;
    }
}

void CMapEffObj::SetEnable(int k, s32 v) {
    s32 i;
    if (k < 0) {
        for (i = 0; i < m_count; i++) {
            if (m_works[i]->IsHit(k)) {
                m_enabled[i] = v;
            }
        }
    } else if (!(m_count - 1 < k)) {
        m_enabled[k] = v;
    }
}

void CMapEffObj::Apply(int k, int v) {
    s32 i;
    if (k < 0) {
        for (i = 0; i < m_count; i++) {
            if (m_works[i]->IsHit(k)) {
                m_works[i]->V2(v);
            }
        }
    } else if (!(m_count - 1 < k)) {
        m_works[k]->V2(v);
    }
}

void CMapEffObj::UpdateAll(int arg) {
    s32 i;
    for (i = 0; i < m_count; i++) {
        if (m_works[i] && m_enabled[i]) {
            m_works[i]->Update(arg);
        }
    }
}

void CMapEffObj::DrawAll(int a, CMapEffTarget *t) {
    s32 i;
    for (i = 0; i < m_count; i++) {
        if (m_works[i] && m_enabled[i]) {
            m_works[i]->Draw(a, t);
        }
    }
}
