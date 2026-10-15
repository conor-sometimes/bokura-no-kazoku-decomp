#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CProcess.h"
#include "IGameDBMgr.h"

#include "CFlagWork.h"

// Same layout as the state block at the start of CMenuProcess.
class CSeasonTimer {
public:
    CSeasonTimer() {
        m_unk4 = -1;
        m_unk2 = 0;
        m_unk0 = 0;
    }
    void SetState(s32 v) {
        m_unk4 = v;
    }

    s16 m_unk0;               // 0x0
    s16 m_unk2;               // 0x2
    s32 m_unk4;               // 0x4
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CGameSeasonPost.
class CGameSeasonPost : public CProcess {
public:
    CGameSeasonPost(s32 a);
    virtual ~CGameSeasonPost();
    virtual void Update();
    virtual void Draw();
    s32 Func159688();
    s32 Func159648();
    s32 Func159790();

    u8 pad18[0x14];
    s32 m_unk2C;              // 0x2C
    CSeasonTimer m_timer;     // 0x30
};

class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};
extern "C" void func_00159850(void *p, s32 a, s32 b);
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPost", D_002D8EA8);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPost", D_002D8EC8);
CGameSeasonPost::CGameSeasonPost(s32 a) {
    m_unk2C = a;
    m_timer.SetState(D_002A26E4->Func1091B0(0x17) % 4);
}

CGameSeasonPost::~CGameSeasonPost() {
}

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPost", Update__15CGameSeasonPost);

int CompareSeasonPostIds(const s32 *a, const s32 *b) {
    return *a - *b;
}

int CheckSeasonPostId(int v) {
    if (v == 0x3FFF) {
        return -1;
    }
    if (v < 0) {
        return -1;
    }
    return v;
}

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPost", func_001592F8);

s32 CGameSeasonPost::Func159648() {
    s32 a = Func159688() != 0;
    return a | (Func159790() != 0);
}

s32 CGameSeasonPost::Func159688() {
    s32 n, i;
    if (!D_002A26E4->Func1091B0(0x1142)) {
        return 0;
    }
    n = D_002A26E4->Func1091B0(0x27);
    for (i = 0; i < n; i++) {
        s32 a = D_002A26E4->Func1091B0(i + 0x46);
        s32 b = D_002A26E4->Func1091B0(i + 0x64);
        s32 k;
        if (b > 0) {
            k = b;
        } else {
            k = a;
        }
        if (D_002A2988->GetNum240(k) > 0) {
            break;
        }
    }
    if (i < n) {
        return 0;
    }
    D_002A26E4->Func108FF0(0x1142, 3);
    return 1;
}

s32 CGameSeasonPost::Func159790() {
    if (!D_002A26E4->Func1091B0(0x1143)) return 0;
    D_002A26E4->Func108FF0(0x1143, 3);
    return 1;
}

void CGameSeasonPost::Draw() {
}

void CreateGameSchedule(CTaskList24F5C0 *list, s32 a, s32 b) {
    void *p = CTask::operator new(0x484);
    func_00159850(p, a, b);
    list->Func24F5C0(p, 0);
}
