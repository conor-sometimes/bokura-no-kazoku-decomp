#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym strcpy 0x28B2D4
#include "libc.h"
class CMovieObj {
public:
    void SetName(const char *name);

    u8 pad0[0x54];
    char m_name[1];           // 0x54
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
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMovieObj", func_0013E668);

INCLUDE_ASM("asm/nonmatchings/CMovieObj", func_0013E6D8);

INCLUDE_RODATA("asm/nonmatchings/CMovieObj", D_002D5D58);
INCLUDE_RODATA("asm/nonmatchings/CMovieObj", D_002D5D60);
INCLUDE_RODATA("asm/nonmatchings/CMovieObj", D_002D5D68);
INCLUDE_RODATA("asm/nonmatchings/CMovieObj", D_002D5D78);
INCLUDE_ASM("asm/nonmatchings/CMovieObj", func_0013E760);
INCLUDE_RODATA("asm/nonmatchings/CMovieObj", D_002D5D88);

void CMovieObj::SetName(const char *name) {
    strcpy(m_name, name);
}

INCLUDE_ASM("asm/nonmatchings/CMovieObj", func_0013E800);

INCLUDE_ASM("asm/nonmatchings/CMovieObj", func_0013E888);

INCLUDE_ASM("asm/nonmatchings/CMovieObj", func_0013E8C0);

int CMovieObjSub13E908::Init() {
    m_unk154 = m_buf.Func248EB0();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CMovieObj", func_0013E938);
INCLUDE_RODATA("asm/nonmatchings/CMovieObj", D_002D5DB0);
INCLUDE_RODATA("asm/nonmatchings/CMovieObj", D_002D5DD0);

INCLUDE_ASM("asm/nonmatchings/CMovieObj", func_0013EBE8);

INCLUDE_ASM("asm/nonmatchings/CMovieObj", func_0013EC28);
INCLUDE_RODATA("asm/nonmatchings/CMovieObj", D_002D5EC8);

INCLUDE_ASM("asm/nonmatchings/CMovieObj", func_0013EC80);

INCLUDE_ASM("asm/nonmatchings/CMovieObj", Func13EDC8__9CMovieObj);

CUserFlagMgr *CreateCUserFlagMgr() {
    return new CUserFlagMgr;
}
