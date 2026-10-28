#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym strcpy 0x28B2D4
#include "libc.h"
#include "CBgWork.h"
// First member of CMovieObj (constructed before m_bg).
class CMovieObjHead {
public:
    CMovieObjHead() {
        m_unk2 = 0;
        m_unk0 = 0;
        m_unk4 = -1;
    }

    s16 m_unk0;               // 0x0
    s16 m_unk2;               // 0x2
    s32 m_unk4;               // 0x4
    u8 pad8[0x40];
};
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMovieObj.
class CMovieObj {
public:
    void Update13E938();
    CMovieObj();
    virtual ~CMovieObj();
    void SetName(const char *name);
    void Func13E888();
    void Open13E760(const char *name);
    void Init13E800();
    void Set13E8C0(s32 v);
    void Apply13EBE8();

    CMovieObjHead m_head;     // 0x00
    CBgWork m_bg;             // 0x48
    char m_name[0x100];       // 0x54
    s32 m_unk154;             // 0x154
    s32 m_unk158;             // 0x158
    s32 m_unk15C;             // 0x15C
    s32 m_unk160;             // 0x160
    s32 m_unk164;             // 0x164
    s32 m_unk168;             // 0x168
    f32 m_unk16C;             // 0x16C
    f32 m_unk170;             // 0x170
    // vptr 0x174
};

class CPushBuf {
public:
    void Func248E00();
    int Func248EB0();

    u8 m_data[0xC];
};
class CMovieObjSub13E908 {
public:
    int Init();

    u8 pad0[0x54];
    CPushBuf m_buf;           // 0x54
    u8 pad60[0xF4];
    s32 m_unk154;             // 0x154
};

//@sym __builtin_new 0x245648
//@sym __12CUserFlagMgr 0x13F2E8
class CUserFlagMgr {
public:
    CUserFlagMgr() throw();

    u8 pad0[0x592C];
};

extern "C" void func_00244EB0();
extern "C" void func_00244DD8();
extern "C" void func_00245438(s32 v);
extern "C" void func_00245398(s32 a, s32 b, s32 c);
extern "C" void func_00244EE8();
extern "C" void func_00244910(s32 w, s32 h);
extern "C" void func_00244D68();
extern "C" void func_002452B8(s32 v);
extern "C" void func_002452A0(s32 v);
extern "C" void func_00245200(s32 v);
extern "C" int func_00235648(char *buf, s32 a, s32 b);
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern s32 D_002A0D28, D_002A0D2C, D_002A0D30;
extern char D_002D5D80[];

int MovieBits13EC28(int psm);
extern "C" void func_00227BF0(u64 tex, s32 a, s32 b, s32 w, s32 h, u8 *src);

#include "state.h"
int Func235DE0(const char *fmt, ...);
typedef int (CMovieObjSub13E908::*CMovieInitFn)();
extern CMovieInitFn D_002D5D88;
extern "C" void func_002457A0(CBgWork *bg, void *obj, CMovieInitFn fn, s32 x);
extern "C" int func_00244DE0(char *name, s32 v);
extern "C" int func_002451A8();
extern "C" int func_00245450();
extern "C" s32 func_00251BA8();

extern "C" void func_00244D68();
// @decl-end

CMovieObj::CMovieObj() {
    m_name[0] = 0;
    m_unk158 = 0;
    m_unk15C = 0;
    m_unk160 = 0;
    m_unk168 = 0;
    m_unk164 = 0;
    m_unk16C = m_unk170 = 1.0f;
}

CMovieObj::~CMovieObj() {
    func_00245818(&m_bg, 1);
    Func13E888();
}

INCLUDE_RODATA("asm/nonmatchings/CMovieObj", D_002D5D60);
INCLUDE_RODATA("asm/nonmatchings/CMovieObj", D_002D5D68);
INCLUDE_RODATA("asm/nonmatchings/CMovieObj", D_002D5D78);
INCLUDE_RODATA("asm/nonmatchings/CMovieObj", D_002D5D80);
void CMovieObj::Open13E760(const char *name) {
    char path[0x100];
    char dir[0x100];
    dir[0] = 0;
    func_00235648(dir, D_002A0D28, D_002A0D2C);
    sprintf(path, D_002D5D80, dir, name, D_002A0D30);
    SetName(path);
}
INCLUDE_RODATA("asm/nonmatchings/CMovieObj", D_002D5D88);

void CMovieObj::SetName(const char *name) {
    strcpy(m_name, name);
}

void CMovieObj::Init13E800() {
    Func13E888();
    func_00244910(0x280, 0x1E0);
    func_00244D68();
    func_002452B8(1);
    func_002452A0(0);
    func_00245200(0);
    m_head.m_unk4 = -1;
    m_head.m_unk2 = 0;
    m_head.m_unk0 = 0;
    m_unk158 = 0;
    m_unk15C = 1;
    m_unk168 = 1;
    m_unk160 = 0;
    m_unk16C = 1.0f;
    m_unk170 = 1.0f;
}

void CMovieObj::Func13E888() {
    func_00244EB0();
    func_00244DD8();
    m_unk158 = 0;
    m_unk15C = 0;
}

void CMovieObj::Set13E8C0(s32 v) {
    if (m_unk160 != v) {
        func_00245438(v);
        m_unk160 = v;
    }
}

int CMovieObjSub13E908::Init() {
    m_unk154 = m_buf.Func248EB0();
    return 1;
}

void CMovieObj::Update13E938() {
    CStateMachine *sm = (CStateMachine *)&m_head;
    s32 done;
    s32 v;
    if (!m_unk15C) return;
    done = 0;
loop:
    if (done) return;
    {
        u32 fl = sm->m_flags;
        if ((fl >> 7) & 1) return;
    }
    switch (sm->m_state) {
    case -1:
        func_002457A0(&m_bg, this, D_002D5D88, 0);
        while (func_00245818(&m_bg, 0)) {
            sm->m_state = -0x8C; done = 1; goto loop;
    case -0x8C:;
        }
        if (func_00244DE0(m_name, m_unk154) < 0) {
            Func235DE0("*** failed to load mpeg (%s)\n", m_name);
            goto fin;
        }
        while (!func_002451A8()) {
            Apply13EBE8();
            sm->m_state = -0x9C; done = 1; goto loop;
    case -0x9C:;
        }
        m_unk158 = 1;
        sm->Push();
        sm->Var() = func_00251BA8();
        for (;;) {
    case -0xA3:
            v = func_00251BA8();
            if (v != sm->Get()) break;
            sm->m_state = -0xA3;
            done = 1;
            goto loop;
        }
        sm->Pop();
        while (!func_00245450()) {
            Apply13EBE8();
            sm->m_state = -0xAC; done = 1; goto loop;
    case -0xAC:;
        }
    fin:
        m_unk15C = 0;
        func_00244EB0();
        func_00244DD8();
        sm->m_state = -0xB8;
    case -0xB8:
        done = 1;
        goto loop;
    }
}

void CMovieObj::Apply13EBE8() {
    s32 v = (s32)(m_unk16C * 128.0f);
    func_00245398(0, v, v);
    func_00244EE8();
}

// GNU as 2.10 assembles the jump-table lui as a copy of the following lw unless the function
// starts on its own .p2align (docs/lessons.md, CNameDBMgr).
asm(".p2align 3");
s32 MovieBits13EC28(s32 psm) {
    switch (psm) {
    case 0: return 32;
    case 1: return 24;
    case 2: case 10: return 16;
    case 19: case 27: return 8;
    case 20: case 36: case 44: return 4;
    }
    return 0;
}

void MovieTiles13EC80(u64 tex, s32 x0, s32 y0, s32 w, s32 stride, s32 t1, s32 h, u8 *src) {
    s32 bpp = MovieBits13EC28((s32)((tex >> 32) & 0x3F)) / 8;
    for (s32 x = 0; x < w; x += 16) {
        u8 *p = src + bpp * t1 * 16 + x * bpp * stride;
        for (s32 y = 0; y < h; y += 16) {
            func_00227BF0(tex, x0 + x, y0 + y, 16, 16, p);
            p += bpp * 256;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/CMovieObj", Func13EDC8__9CMovieObj);

CUserFlagMgr *CreateCUserFlagMgr() {
    return new CUserFlagMgr;
}
