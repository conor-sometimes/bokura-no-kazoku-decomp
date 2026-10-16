#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym memset 0x289FB0
#include "libc.h"

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CModelRes.
class CModelRes {
public:
    s32 LoadFile(const char *name, s32 b);
    CModelRes();
    virtual ~CModelRes();
    void Release();
    s32 Load(s32 a, s32 b);

    s32 m_unk0;               // 0x00
    s32 m_unk4;               // 0x04
    s32 m_unk8;               // 0x08
    s32 m_unkC;               // 0x0C
    s32 m_unk10;              // 0x10
    u8 m_unk14[0x8];          // 0x14
    // vptr 0x1C
};

struct CModelRec {
    s32 m_id;                 // 0x0
    s32 m_flags;              // 0x4
    s32 m_unk8;               // 0x8
    u8 padC[0x4];
    void *m_unk10;            // 0x10
    u8 pad14[0x20];
};
extern "C" s32 func_00110560(CModelRec *recs, s32 a, s32 b, s32 c, s32 d, s32 *e, s32 *f);
extern "C" void *func_00245678(u32 size);

extern "C" void func_001F20F8(s32 h);
extern void (*D_002B91B0)(void *p);

extern "C" s32 func_001F2090(s32 k);
extern "C" unsigned int strlen(const char *s);
extern "C" char *strstr(const char *s, const char *t);
struct CModelNames {
    s32 m_num;                // 0x0
    u8 pad4[0xC];
    char *m_names[1];         // 0x10
};
struct CModelPart {
    u8 pad0[0x6];
    u16 m_flags;              // 0x6
};
struct CModelParts {
    u8 pad0[0x8];
    CModelPart m_parts[1];    // 0x8
};
struct CModelRec2 {
    u8 pad0[0x4];
    CModelParts *m_parts;     // 0x4
    u8 pad8[0x8];
    CModelNames *m_names;     // 0x10
    u8 pad14[0x20];
};
extern CModelRec2 *D_002A5D0C;
extern char *D_002A03C0;

extern "C" s32 func_002051B8(s32 k);
extern "C" const char *func_002051E0(s32 a, s32 k);
extern "C" unsigned int strlen(const char *s);
inline void StrAdd(char *d, const char *s) { strcpy(d + strlen(d), s); }
extern "C" char *strstr(const char *s, const char *t);
void *Func248E48(const char *name);
s32 Func235DE0(const char *fmt, ...) throw();
extern "C" int func_00253048(void *p, s32 *a, s32 *b, s32 *c, s32 *d, s32 *e, s32 *f, s32 *g, s32 *h);
extern "C" void func_0023C048(s32 a, s32 b, s32 c);
struct CModelTex {
    u8 pad0[0x14];
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
    s32 m_unk24;              // 0x24
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
    s32 m_unk30;              // 0x30
};
extern "C" void func_0022DCE0();
extern "C" void func_0022DD00();
extern "C" void func_0022DC90(const char *s);
extern "C" void func_0024B7B8(const char *s, char *a, char *b);
extern "C" s32 func_00249070(const char *s);
extern "C" void func_0024B650(const char *s, s32 b, char *a, s32 c);
extern "C" void func_002490F8();
void *Func24A4C0(const char *name);
extern char *D_002A03D0;
extern char *D_002A03D8;
extern void (*D_002B91B0)(void *p);

extern "C" void *func_00248E60(const char *name);
extern "C" void func_00247110();
extern "C" s32 func_00247140();
extern "C" u64 func_0023AA40(s32 h);
extern "C" s32 func_0023AFB8(u64 v);
extern "C" s32 func_0023BD80(s32 h);
extern "C" void func_0023BD60(s32 h, s32 v);
extern "C" s32 func_00205398(void *data);
extern "C" s32 func_00201210(void *data, s32 tex);
extern "C" s32 func_00201628(void *data, s32 tex);
void Func23B1D0(s32 h);
void Func110178(s32 k);
void *LoadModelTex(CModelTex *t, s32 k);
struct CModelSlot {
    u8 pad0[0x4];
    u32 m_flags;              // 0x4
    s32 m_model;              // 0x8
    s32 m_tex;                // 0xC
    void *m_texData;          // 0x10
    u8 pad14[0x4];
    s32 m_unk18;              // 0x18
};
// @decl-end

CModelRes::CModelRes() {
    m_unkC = -1;
    m_unk4 = 0;
    m_unk0 = 0;
    m_unk8 = 0;
    m_unk10 = 0;
    memset(m_unk14, 0, 8);
}

CModelRes::~CModelRes() {
    Release();
}

void *LoadModelTex(CModelTex *t, s32 k) {
    char buf[256];
    s32 n = func_002051B8(k);
    if (n <= 0) return 0;
    const char *nm = func_002051E0(0, k);
    strcpy(buf, nm);
    StrAdd(buf, ".");
    StrAdd(buf, "tm2");
    void *d = Func248E48(buf);
    if (!d) {
        Func235DE0("*** failed to load XMD texture '%s'\n", buf);
        return 0;
    }
    if (n >= 2) Func235DE0("!!! multiple texture (fname=%s, width=%d)\n", nm, n);
    func_00253048(d, &t->m_unk14, &t->m_unk18, &t->m_unk1C, &t->m_unk20, &t->m_unk24, &t->m_unk28, &t->m_unk2C, &t->m_unk30);
    if (t->m_unk1C & 7) Func235DE0("!!! invalid width (fname=%s, width=%d)\n", buf, t->m_unk1C);
    if (t->m_unk2C > 0x10) func_0023C048(t->m_unk2C * t->m_unk30, t->m_unk24, t->m_unk24);
    return d;
}
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D3130);

void Func110178(s32 k) {
    s32 n = func_001F2090(k);
    s32 j, i;
    for (j = 0; j < n; j++) {
        CModelRec2 *r = &D_002A5D0C[k + j];
        if (!r) continue;
        CModelNames *t = r->m_names;
        if (!t) continue;
        CModelParts *q = r->m_parts;
        if (!q) continue;
        for (i = 0; i < t->m_num; i++) {
            char *s = strstr(t->m_names[i], D_002A03C0);
            if (s) {
                s += strlen(D_002A03C0);
                s32 v = *s - '0';
                v = v < 0 ? 0 : (v > 31 ? 31 : v);
                q->m_parts[i].m_flags |= v << 1;
            }
        }
    }
}

s32 LoadModel1102C8(CModelSlot *rec, const char *name, s32 tex, s32 *pA, s32 *pB) {
    s32 ok = 0;
    void *texData = 0;
    s32 hTex = -1;
    s32 hMdl = -1;
    void *data;
    rec->m_model = -1;
    rec->m_texData = 0;
    rec->m_tex = -1;
    data = func_00248E60(name);
    if (!data) {
        Func235DE0("*** failed to load XMD file '%s'\n", name);
        goto end;
    }
    func_00247110();
    if (!(rec->m_flags & 0x10)) {
        if (tex >= 0) {
            texData = LoadModelTex((CModelTex *)rec, (s32)data);
            if (!texData) goto end;
            hTex = func_0023AFB8((func_0023AA40(tex) & ~(0x3FULL << 32)) | ((u64)(rec->m_unk18 & 0x3F) << 32));
            if (hTex < 0) {
                Func235DE0("*** failed to duplicate texture '%s'\n", name);
                goto end;
            }
            func_0023BD60(hTex, func_0023BD80(tex));
        } else {
            hTex = func_00205398(data);
            if (hTex < 0) goto end;
        }
    }
    if (pB) *pB += func_00247140();
    func_00247110();
    switch (rec->m_flags & 0xF) {
    case 0:
        hMdl = func_00201210(data, hTex);
        break;
    case 1:
        hMdl = func_00201628(data, hTex);
        break;
    }
    if (hMdl < 0) {
        Func235DE0("*** failed to regist XMD model '%s' (stex=%d)\n", name, tex);
        goto end;
    }
    if (pA) *pA += func_00247140();
    ok = 1;
    Func110178(hMdl);
    rec->m_model = hMdl;
    hMdl = -1;
    rec->m_texData = texData;
    rec->m_tex = hTex;
    hTex = -1;
    texData = 0;
end:
    if (texData) D_002B91B0(texData);
    if (hTex >= 0) Func23B1D0(hTex);
    if (hMdl >= 0) func_001F20F8(hMdl);
    if (data) D_002B91B0(data);
    return ok;
}
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D31B8);
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D31C0);
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D31C8);

INCLUDE_ASM("asm/nonmatchings/CModelRes", func_00110560);
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D31D8);
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D31E0);
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D31E8);
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D31F0);
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D31F8);

s32 CModelRes::Load(s32 a, s32 b) {
    s32 i;
    Release();
    m_unk0 = func_00110560(0, a, b, m_unkC, m_unk10, 0, 0);
    m_unk4 = (s32)func_00245678(m_unk0 * sizeof(CModelRec));
    memset((void *)m_unk4, 0, m_unk0 * sizeof(CModelRec));
    func_00110560((CModelRec *)m_unk4, a, b, m_unkC, m_unk10, (s32 *)&m_unk14[0], (s32 *)&m_unk14[4]);
    m_unk8 = 0;
    for (i = 0; i < m_unk0; i++) {
        s32 v = ((CModelRec *)m_unk4)[i].m_id + 1;
        if (v < m_unk8) {
            v = m_unk8;
        }
        m_unk8 = v;
    }
    return 1;
}

s32 CModelRes::LoadFile(const char *name, s32 b) {
    char buf[256];
    char buf2[256];
    s32 ok = 0;
    void *data = 0;
    func_0022DCE0();
    if (strstr(name, D_002A03D0)) {
        func_0024B7B8(name, buf, buf2);
        func_0022DC90(buf);
        data = Func24A4C0(buf2);
        if (!data) goto err;
        ok = Load((s32)data, b);
    } else if (strstr(name, D_002A03D8)) {
        if (!func_00249070(name)) {
        err:
            Func235DE0("*** failed to load '%s'\n", name);
        } else {
            func_0024B650(name, 0, buf, 0);
            StrAdd(buf, D_002A03D0);
            ok = LoadFile(buf, b);
            func_002490F8();
        }
    } else {
        Func235DE0("*** unknown model file path %s\n", name);
    }
    if (data) D_002B91B0(data);
    func_0022DD00();
    return ok;
}

void CModelRes::Release() {
    s32 i;
    if (m_unk4 == 0) return;
    for (i = 0; i < m_unk0; i++) {
        if (((CModelRec *)m_unk4)[i].m_unk8 >= 0) func_001F20F8(((CModelRec *)m_unk4)[i].m_unk8);
        if (((CModelRec *)m_unk4)[i].m_unk10) D_002B91B0(((CModelRec *)m_unk4)[i].m_unk10);
    }
    if (m_unk4) delete[] (CModelRec *)m_unk4;
    m_unk4 = 0;
    m_unk0 = 0;
    memset(m_unk14, 0, 8);
}
