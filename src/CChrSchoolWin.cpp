#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CChrSchoolWinSub186E80 {
public:
    void SetUnk60(f32 x, f32 y);

    u8 pad0[0x60];
    f32 m_unk60;              // 0x60
    f32 m_unk64;              // 0x64
};

class CUnk1A4298 {
public:
    int Func1A4298();
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
extern "C" u8 *func_00237570(s32 v);
extern "C" void func_00237A88(void *p, s32 v);
extern "C" void *func_00237C30(void *p);
extern "C" int func_00238158(void *p, s32 v);
void Func225088();
int Func2250C0();
void Func225240(s32 v);
class CChrSchoolWinObj {
public:
    void Func186FA8();
    u8 pad0[0x48];
    CUnk1A4298 *m_unk48;      // 0x48
    u8 pad4C[0x10];
    s32 m_unk5C;              // 0x5C
};
#include "CFlagWork.h"
int Func235DE0(const char *fmt, ...);
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern "C" const char *func_001A36B0(void *w, s32 v);
class CStatusItem {
public:
    void Func1A3378();
};
#include "CMenuRecordWin.h"
#include "CStatusWinSub1A40B8.h"
#include "CStatusWin.h"
extern CStatusWin *D_002A5408;
extern CFlagWork *D_002A5358;
extern char D_002DAF80[], D_002DAF88[], D_002DAF90[];
struct CSchoolRec {
    u8 pad0[0x8];
    const char *m_name;       // 0x8
};
class CSchoolDB {
public:
    virtual void Vf0();
    virtual void Vf1();
    virtual void Vf2();
    virtual void Vf3();
    virtual void Vf4();
    virtual void Vf5();
    virtual void Vf6();
    virtual void Vf7();
    virtual void Vf8();
    virtual void Vf9();
    virtual void Vf10();
    virtual void Vf11();
    virtual void Vf12();
    virtual void Vf13();
    virtual void Vf14();
    virtual void Vf15();
    virtual void Vf16();
    virtual void Vf17();
    virtual void Vf18();
    virtual void Vf19();
    virtual void Vf20();
    virtual void Vf21();
    virtual void Vf22();
    virtual void Vf23();
    virtual void Vf24();
    virtual void Vf25();
    virtual void Vf26();
    virtual void Vf27();
    virtual void Vf28();
    virtual void Vf29();
    virtual void Vf30();
    virtual void Vf31();
    virtual void Vf32();
    virtual void Vf33();
    virtual void Vf34();
    virtual void Vf35();
    virtual void Vf36();
    virtual void Vf37();
    virtual void Vf38();
    virtual void Vf39();
    virtual CSchoolRec *Find(s32 id);
};
extern CSchoolDB *D_002A2988;
// Status window base (CStatusBase unit; constructor through config/aliases.ld). All seven
// virtuals are pure; the first is declared non-pure here so this unit emits no vtable for it.
class CStatusBase {
public:
    CStatusBase();
    virtual void Vf0();
    virtual void Vf1() = 0;
    virtual void Vf2() = 0;
    virtual void Vf3() = 0;
    virtual void Vf4() = 0;
    virtual void Vf5() = 0;
    virtual void Vf6() = 0;

    s16 m_unk0;               // 0x00
    s16 m_unk2;               // 0x02
    s32 m_unk4;               // 0x04
    u8 pad8[0x40];
    CStatusItem *m_item;      // 0x48
    s32 m_state;              // 0x4C
    u32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    // vptr 0x58
};
// Vtable _vt$13CChrSchoolWin (asm); slot 0 (0x186E90) is the key method.
class CChrSchoolWin : public CStatusBase {
public:
    CChrSchoolWin(s32 load);
    virtual void Vf0();
    virtual void Vf1();
    virtual void Vf2();
    virtual void Vf3();
    virtual void Vf4();
    virtual void Vf5();
    virtual void Vf6();

    s32 m_unk5C;              // 0x5C
    f32 m_unk60;              // 0x60
    f32 m_unk64;              // 0x64
};
// @decl-end

CChrSchoolWin::CChrSchoolWin(s32 load) {
    m_item = D_002A5408->Func1A0CF0(D_002DAF80);
    m_item->Func1A3378();
    m_unk5C = 0;
    m_unk60 = m_unk64 = 0.0f;
    if (load) ((CMenuRecordWin *)m_item)->Func1A39A8(&m_unk60, (s32 *)&m_unk64, 4);
    ((CStatusWinSub1A40B8 *)m_item)->SetUnk80(m_unk60, m_unk64);
    return;
}

void CChrSchoolWinSub186E80::SetUnk60(f32 x, f32 y) {
    m_unk60 = x;
    m_unk64 = y;
}

INCLUDE_ASM("asm/nonmatchings/CChrSchoolWin", func_00186E90);

void CChrSchoolWin::Vf1() {
    char buf[0x100];
    s32 v = D_002A5358->Func1091B0(m_unk50 + 0xD6);
    buf[0] = D_002DAF88[0];
    m_unk5C = v;
    if (v) {
        CSchoolRec *r = D_002A2988->Find(m_unk5C);
        if (!r) {
            Func235DE0(D_002DAF90, m_unk5C);
            m_unk5C = 0;
        } else {
            sprintf(buf, func_001A36B0(m_item, 3), r->m_name);
        }
    }
    ((CMenuRecordWin *)m_item)->Func1A3740(3, buf);
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00186F88() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00186F90() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00186F98() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00186FA0() {
}

void CChrSchoolWinObj::Func186FA8() {
    char buf[256];
    u8 *p = func_00237570(0x60);
    func_00237A88(p, 6);
    func_00238158(func_00237C30(p + 0x50), 1);
    if (m_unk5C) {
        ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unk48->Func1A4298());
    }
    Func225088();
    Func225240((s32)p);
    Func2250C0();
}
