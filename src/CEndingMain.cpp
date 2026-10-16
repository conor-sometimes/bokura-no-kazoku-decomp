#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CProcess.h"
#include "IFadeMgr.h"

#include "CFlagWork.h"
int Func251B88();
int Func235DE0(const char *fmt, ...) throw();
extern "C" int sprintf(char *buf, const char *fmt, ...);
// The movie object's constructor and destructor (CMovieObj unit, not named yet).
extern "C" void *func_0013E668(void *p);
extern "C" void func_0013E6D8(void *p, s32 flags);
extern "C" void func_0010CD48(void *p);

// Same layout as the state block at the start of CMenuProcess.
class CEndingTimer {
public:
    CEndingTimer() {
        m_unk4 = -1;
        m_unk2 = 0;
        m_unk0 = 0;
    }

    s16 m_unk0;               // 0x0
    s16 m_unk2;               // 0x2
    s32 m_unk4;               // 0x4
};
class CEndingDate {
public:
    CEndingDate() {
        m_unk0 = 1;
    }

    s32 m_unk0;               // 0x0
};
class CMovieObj {
public:
    int Func13EDC8();
};
class CUnk237E90 {
public:
    void Func237E90(int v);
};
class CUnk2A5BC0 {
public:


    u8 pad0[0x60];
    CUnk237E90 m_unk60;       // 0x60
};
extern CUnk2A5BC0 *D_002A5BC0;
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CEndingMain.
class CEndingMain : public CProcess {
public:
    CEndingMain(s32 a);
    virtual ~CEndingMain();
    virtual void Update();
    virtual void Draw();

    u8 pad18[0x14];
    CEndingTimer m_timer;     // 0x2C
    u8 pad34[0x40];
    CMovieObj m_movie;        // 0x74
    u8 pad75[0x177];
    char m_name[0x100];       // 0x1EC
    s32 m_unk2EC;             // 0x2EC
};
// @decl-end

CEndingMain::CEndingMain(s32 a) {
    func_0013E668(&m_movie);
    CEndingDate date;
    m_unk2EC = a;
    date.m_unk0 = Func251B88();
    sprintf(m_name, "ending%d", D_002A26E4->Func1091B0(0x13));
    Func235DE0("ending '%s'\n", m_name);
    D_0029F394->Func13(0xB);
}
INCLUDE_RODATA("asm/nonmatchings/CEndingMain", D_002D1B58);
INCLUDE_RODATA("asm/nonmatchings/CEndingMain", D_002D1B78);

CEndingMain::~CEndingMain() {
    func_0010CD48(this);
    D_0029F394->Func13(-1);
    func_0013E6D8(&m_movie, 2);
}

INCLUDE_ASM("asm/nonmatchings/CEndingMain", Update__11CEndingMain);

void CEndingMain::Draw() {
    int r = m_movie.Func13EDC8();
    D_002A5BC0->m_unk60.Func237E90(r);
}
