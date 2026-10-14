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
    char m_name[0x104];       // 0x54
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

INCLUDE_RODATA("asm/nonmatchings/CMovieObj", D_002D5D58);
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

INCLUDE_ASM("asm/nonmatchings/CMovieObj", func_0013E800);

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

INCLUDE_ASM("asm/nonmatchings/CMovieObj", func_0013E938);
INCLUDE_RODATA("asm/nonmatchings/CMovieObj", D_002D5DB0);
INCLUDE_RODATA("asm/nonmatchings/CMovieObj", D_002D5DD0);

void CMovieObj::Apply13EBE8() {
    s32 v = (s32)(m_unk16C * 128.0f);
    func_00245398(0, v, v);
    func_00244EE8();
}

INCLUDE_ASM("asm/nonmatchings/CMovieObj", MovieBits13EC28__Fi);

INCLUDE_ASM("asm/nonmatchings/CMovieObj", func_0013EC80);

INCLUDE_ASM("asm/nonmatchings/CMovieObj", Func13EDC8__9CMovieObj);

CUserFlagMgr *CreateCUserFlagMgr() {
    return new CUserFlagMgr;
}
