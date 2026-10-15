#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CValue {
public:
    void Reset();
    int AsInt();
    f32 AsFloat();
    int Get12E350();                  // returns the value as a string (char *)
    void Assign(CValue *o);

    s32 m_type;               // 0x0: 0 int, 1 float, 2 string
    union {
        s32 i;
        f32 f;
        char s[0x100];
    } m_u;                    // 0x4
};

class CSvmHeader {
public:
    int IsValid();

    u32 m_magic;              // 0x0
    s32 m_size;               // 0x4
    s32 m_version;            // 0x8
};
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CSvmRes. The vptr
// follows its own fields.
class CSvmRes {
public:
    CSvmRes();
    virtual ~CSvmRes();
    void Release();
    int Load(CSvmHeader *h);
    int LoadFile(const char *name);

    s32 m_unk0;               // 0x00
    s32 m_unk4;               // 0x04
    s32 m_unk8;               // 0x08
    s32 m_unkC;               // 0x0C
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    // vptr 0x20
};

extern "C" int atoi(const char *);
extern "C" float atoff(const char *);
extern "C" int sprintf(char *, const char *, ...);
extern "C" char *strcpy(char *, const char *);
extern "C" void *func_002303C0(const char *);
extern void (*D_002B91B0)(void *p);
extern char D_2EBF90[];
extern const char D_002D5200[];
extern const char D_002D5208[];
extern const char D_002D5210[];
int Func235DE0(const char *, ...);
//@sym Load__7CSvmResP10CSvmHeader 0x12DEC0
//@sym atoi 0x289118
//@sym atoff 0x289100
//@sym fptodp 0x284B98
// @decl-end

CSvmRes::CSvmRes() {
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = 0;
}

CSvmRes::~CSvmRes() {
    Release();
}

int CSvmHeader::IsValid() {
    if (m_magic == 0x44435347) {
        if (m_version == 0x100) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CSvmRes", func_0012DE40);

INCLUDE_RODATA("asm/nonmatchings/CSvmRes", D_002D5160);
INCLUDE_ASM("asm/nonmatchings/CSvmRes", Load__7CSvmResP10CSvmHeader);

int CSvmRes::LoadFile(const char *name) {
    int ok = 0;
    void *buf = func_002303C0(name);
    if (!buf || !Load((CSvmHeader *)buf)) {
        Func235DE0("*** failed to load '%s'\n", name);
    } else {
        m_unk0 = (s32)buf;
        buf = 0;
        ok = 1;
    }
    if (buf) D_002B91B0(buf);
    return ok;
}

void CSvmRes::Release() {
    if (m_unk0) {
        D_002B91B0((void *)m_unk0);
        m_unk0 = 0;
    }
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = 0;
}

void CValue::Reset() {
    m_type = -1;
    m_u.i = 0;
}

INCLUDE_ASM("asm/nonmatchings/CSvmRes", SetInt__6CValuei);

INCLUDE_ASM("asm/nonmatchings/CSvmRes", SetFloat__6CValuef);

INCLUDE_ASM("asm/nonmatchings/CSvmRes", Set12E1D8__6CValuei);

int CValue::AsInt() {
    switch (m_type) {
    case 0: return m_u.i;
    case 1: return (s32)m_u.f;
    case 2: return atoi(m_u.s);
    }
    return 0;
}

f32 CValue::AsFloat() {
    switch (m_type) {
    case 0: return m_u.i;
    case 1: return m_u.f;
    case 2: return atoff(m_u.s);
    }
    return 0.0f;
}

int CValue::Get12E350() {
    switch (m_type) {
    case 0: sprintf(D_2EBF90, D_002D5200, m_u.i); return (int)D_2EBF90;
    case 1: sprintf(D_2EBF90, D_002D5208, m_u.f); return (int)D_2EBF90;
    case 2: return (int)m_u.s;
    }
    return (int)D_002D5210;
}

void CValue::Assign(CValue *o) {
    switch (m_type) {
    case 0: m_u.i = o->AsInt(); break;
    case 1: m_u.f = o->AsFloat(); break;
    case 2: return (void)strcpy(m_u.s, (char *)o->Get12E350());
    default: *this = *o; break;
    }
}

INCLUDE_ASM("asm/nonmatchings/CSvmRes", func_0012E558);
