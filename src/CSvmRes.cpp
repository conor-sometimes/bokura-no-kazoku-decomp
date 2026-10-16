#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CValue {
public:
    void Reset();
    int AsInt();
    f32 AsFloat();
    int Get12E350();                  // returns the value as a string (char *)
    void Assign(CValue *o);
    void SetInt(s32 v);
    void SetFloat(f32 v);
    void Set12E1D8(s32 v);
    int Equals(CValue *o);

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
extern "C" int strcmp(const char *, const char *);
extern "C" void *func_002303C0(const char *);
extern void (*D_002B91B0)(void *p);
extern char D_2EBF90[];
extern const char D_002D5200[];
extern const char D_002D5208[];
extern const char D_002D5210[];
int Func235DE0(const char *, ...) throw();
//@sym Load__7CSvmResP10CSvmHeader 0x12DEC0
//@sym atoi 0x289118
//@sym atoff 0x289100
//@sym fptodp 0x284B98

struct CSvmChunk { s32 m_id; s32 m_size; };

extern "C" CSvmChunk *func_0012DE40(CSvmHeader *h, s32 id);
struct CSvmChunkX { s32 m_id; s32 m_size; s32 m8; s32 mC; };
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

extern "C" CSvmChunk *func_0012DE40(CSvmHeader *h, s32 id) {
    s32 off;
    if (!h->IsValid()) return 0;
    for (off = 0; off < h->m_size; ) {
        u8 *p = (u8 *)h + 0x10;
        CSvmChunk *c = (CSvmChunk *)(p + off);
        if (c->m_id == id) return c;
        off += c->m_size + 8;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/CSvmRes", D_002D5160);
int CSvmRes::Load(CSvmHeader *h) {
    Release();
    if (!h->IsValid()) {
        Func235DE0("*** invalid event script data %X\n", h->m_magic);
        return 0;
    }
    {
        CSvmChunkX *c = (CSvmChunkX *)func_0012DE40(h, 0x41544144);
        if (!c) { Func235DE0("*** not found data chunk\n"); return 0; }
        m_unk18 = (s32)c + 0xC;

        m_unk1C = c->m8;
    }
    {
        CSvmChunkX *c = (CSvmChunkX *)func_0012DE40(h, 0x504D554A);
        if (c) { m_unk4 = (s32)c + 0xC; m_unk8 = c->m8; }
    }
    {
        CSvmChunkX *c = (CSvmChunkX *)func_0012DE40(h, 0x44474552);
        if (c) { m_unkC = c->m8; m_unk10 = (s32)c + 0x10; m_unk14 = c->mC; }
    }
    return 1;
}

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

