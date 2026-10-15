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
    s32 Collect1592F8();

    u8 pad18[0x14];
    s32 m_unk2C;              // 0x2C
    CSeasonTimer m_timer;     // 0x30
};

class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};
extern "C" void func_00159850(void *p, s32 a, s32 b);

int CompareSeasonPostIds(const s32 *a, const s32 *b);
int CheckSeasonPostId(int v);
extern CFlagWork *D_002A5358;
extern "C" void func_0028A140(void *base, u32 n, u32 size, int (*cmp)(const void *, const void *));
struct CSeasonPostEnt {
    s32 m_key;                // 0x0
    s32 m4;                   // 0x4
    s32 m_id;                 // 0x8
    s32 m_done;               // 0xC
    s32 m10;                  // 0x10
};
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

s32 CGameSeasonPost::Collect1592F8() {
    CSeasonPostEnt ents[256];
    s32 cnt = 0;
    s32 i, a, b;
    for (i = 0; i < 256; i++) {
        if (!D_002A2988->Find1DC(i)) continue;
        s32 s = i + 0x1062;
        s32 st = D_002A26E4->Func1091B0(s);
        if (st == 1 || st == 5 || st == 3) {
            s32 k = i + 0x1162;
            if (D_002A26E4->Func1091B0(k) != 0x3FFF) D_002A26E4->Func109108(k, -1);
            ents[cnt].m_id = i;
            s32 k2 = i + 0x1262;
            s32 k3 = i + 0x1362;
            ents[cnt].m_key = CheckSeasonPostId(D_002A26E4->Func1091B0(k));
            ents[cnt].m4 = D_002A26E4->Func1091B0(k2);
            ents[cnt].m10 = D_002A26E4->Func1091B0(k3);
            if (st == 3 || D_002A26E4->Func1091B0(k) <= 0 || D_002A26E4->Func1091B0(k2) <= 0) {
                D_002A26E4->Func108FF0(s, 0);
                D_002A26E4->Func108FF0(k, 0);
                D_002A26E4->Func108FF0(k2, 0);
                D_002A26E4->Func108FF0(k3, 0);
                ents[cnt].m_done = 1;
            } else {
                ents[cnt].m_done = 0;
            }
            cnt++;
        }
    }
    func_0028A140(ents, cnt, sizeof(CSeasonPostEnt), (int (*)(const void *, const void *))CompareSeasonPostIds);
    D_002A5358->Func108700();
    D_002A5358->Func108FF0(0x1FF, 1);
    D_002A5358->Func108FF0(0x241, 1);
    a = 0;
    b = 0;
    for (i = 0; i < cnt; i++) {
        s32 v = ents[i].m_key;
        if (v >= 0) v++;
        D_002A5358->Func108FF0(a + 0x1AF, ents[i].m_id);
        D_002A5358->Func108FF0(a + 0x1BF, v);
        D_002A5358->Func108FF0(i + 0x1CF, 1);
        D_002A5358->Func108FF0(i + 0x1DF, ents[i].m10);
        if (ents[i].m_done) {
            D_002A5358->Func108FF0(b + 0x201, a - b);
            b++;
        }
        a++;
    }
    D_002A5358->Func108FF0(0x1AE, a);
    D_002A5358->Func108FF0(0x200, b);
    return b > 0;
}

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
