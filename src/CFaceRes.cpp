#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym memset 0x289FB0
#include "libc.h"

struct CFaceItem {
    void *m_data;             // 0x0
    u8 pad4[0xC];
};
struct CFaceGroup {
    s32 m0;                   // 0x0
    void *m_ptrs[3];          // 0x4
    s32 m_nums[3];            // 0x10
};
struct CFacePart;
struct CFaceSet;
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CFaceRes.
class CFaceRes {
public:
    CFaceRes();
    virtual ~CFaceRes();
    void Release();
    int Load(const char *text);

    CFaceItem *m_unk0;        // 0x00
    s32 m_unk4;               // 0x04
    CFaceSet *m_unk8;         // 0x08
    s32 m_unkC;               // 0x0C
    CFaceGroup *m_unk10;      // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18[3];           // 0x18
    CFacePart *m_unk24[3];    // 0x24
    s32 m_unk30;              // 0x30
    s32 m_unk34;              // 0x34
    s32 m_unk38;              // 0x38
    s32 m_unk3C;              // 0x3C
    s32 m_unk40;              // 0x40
    s32 m_unk44;              // 0x44
    s32 m_unk48;              // 0x48
    s32 m_unk4C;              // 0x4C
    s32 m_unk50;              // 0x50
    // vptr 0x54
};

class CFaceResSub10F938 {
public:
    s32 GetFirst();

    u8 pad0[0x10];
    s32* m_list;              // 0x10
    s32 m_count;              // 0x14
};

class CFaceResRec {
public:
    s32 m_id;                 // 0x0
    u8 pad4[0x18];
};
class CFaceResSub10F8F0 {
public:
    CFaceResRec *Find(s32 id);

    u8 pad0[0x10];
    CFaceResRec *m_recs;      // 0x10
    s32 m_num;                // 0x14
};
struct CFacePart {
    s32 m_id;                 // 0x00
    char m_name[0x20];        // 0x04
    s16 m24, m26, m28, m2A;   // 0x24
    s16 m2C, m2E, m30, m32;   // 0x2C
};
struct CFaceSet {
    s32 m_id;                 // 0x0
    s32 m_num;                // 0x4
    CFacePart *m_parts;       // 0x8
};
extern const char *D_002A03A4;
extern const char *D_002A03A8;
extern char D_002D2DC8[], D_002D2DD0[];
const char *Func24A570(const char *s, char *out, const char *sep, const char *ws);
extern "C" const char *func_0024A710(const char *p, s32 *v, s32 def, const char *s1, const char *s2);
const char *Func24AF10(void *p, const char *key);
const char *Func24AFE8(const char *s, char *buf, s32 k, s32 size);
void *Func245D00(int size);
s32 ParseFaceParts(CFacePart *parts, const char *p);
inline void SetFacePart(CFacePart *p, s16 c, s16 a, s16 b, s16 d, s16 e, s16 f, s16 g) { p->m24 = -1; p->m26 = c; p->m28 = a; p->m2A = b; p->m2C = d; p->m2E = e; p->m30 = f; p->m32 = g; }
extern void (*D_002B91B0)(void *p);
extern s32 D_002A03A0;
extern const char *D_002A03B0, *D_002A03B4, *D_002A03B8, *D_002A03BC;
extern char D_002D2FE8[], D_002D2EE0[], D_002D3000[];
s32 LoadFaceSets(CFaceSet *sets, void *text);
extern "C" s32 func_0010ED30(CFaceItem *out, CFaceSet *sets, s32 n, s32 a, s32 b, s32 c, s32 d);
extern "C" s32 func_0010F068(CFaceGroup *out, s32 *nums, const char *text, CFaceSet *sets, s32 n);
extern "C" const char *func_0024B190(const char *p, const char *key, char *buf, const char *ws, s32 n);
extern "C" void func_0022DCE0();
extern "C" void func_0022DD00();
extern "C" void func_0022DC90(const char *dir);
extern "C" char *strstr(const char *a, const char *b);
extern "C" int func_00249070(const char *p);
extern "C" void func_002490F8();
extern "C" void func_0024B650(const char *p, s32 a, char *buf, s32 b);
extern "C" void func_0024B7B8(const char *p, char *dir, char *name);
extern "C" unsigned int strlen(const char *s);
char *Func24A4C0(const char *name);
int Func235DE0(const char *fmt, ...);
struct CFaceTex {
    void *m_data;             // 0x0
    s32 m_psm;                // 0x4
    s16 m_w;                  // 0x8
    s16 m_h;                  // 0xA
    s32 m_vis;                // 0xC (func_0010ED30: overlaps the view rectangle)
};
struct CFaceCache {
    void *m_data;             // 0x0
};
extern char D_002D2DE0[];
extern "C" void *func_00248E60(const char *name);
extern "C" void func_00253048(void *p, s32 *a, s32 *b, s32 *c, s32 *d, s32 e, s32 f, s32 g, s32 *h);
void Blit32(u32 *dst, u32 *src, s32 stride, s32 x, s32 y, s32 w, s32 h);
void Blit8(u8 *dst, u8 *src, s32 stride, s32 x, s32 y, s32 w, s32 h);
void Blit16(u16 *dst, u16 *src, s32 stride, s32 x, s32 y, s32 w, s32 h);
s32 FaceTexSize(s32 psm, s32 w, s32 h);
extern const char *D_002A03AC;
s32 FindFaceIds(CFaceSet **out, const char *p, CFaceSet *parts, s32 nparts);

int LoadFaceTex(CFaceTex *tex, CFacePart *part, char *name, CFaceCache *cache);
CFacePart *FindFacePart(CFaceSet *sets, s32 nsets, s32 last, CFacePart *key);
// @decl-end

CFaceRes::CFaceRes() {
    m_unk8 = 0;
    m_unkC = 0;
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    memset(m_unk18, 0, 0xC);
    memset(m_unk24, 0, 0xC);
    m_unk34 = 0;
    m_unk30 = -1;
    m_unk38 = 0;
    m_unk3C = 0;
    m_unk40 = 0;
    m_unk44 = 0;
    m_unk48 = 0;
    m_unk4C = 0x50;
    m_unk50 = 0x50;
}

CFaceRes::~CFaceRes() {
    Release();
}

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E5E0);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", LoadFaceSets__FP8CFaceSetPv);

INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2DC0);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2DC8);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2DD0);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2DD8);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2DE0);
s32 FaceTexSize(s32 psm, s32 w, s32 h) {
    s32 bpp;
    switch (psm) {
    case 0:
        bpp = 32;
        break;
    case 1:
        bpp = 24;
        break;
    case 2:
    case 10:
        bpp = 16;
        break;
    case 19:
    case 27:
        bpp = 8;
        break;
    case 20:
    case 36:
    case 44:
        bpp = 4;
        break;
    default:
        Func235DE0(D_002D2DE0, psm);
        bpp = 0;
        break;
    }
    return w * h * bpp >> 3;
}

int LoadFaceTex(CFaceTex *tex, CFacePart *part, char *name, CFaceCache *cache) {
    s32 data, psm, stride, height;
    s32 w, h, x, y, size;
    tex->m_data = 0;
    tex->m_psm = 0;
    tex->m_w = 0;
    tex->m_h = 0;
    int ok = 0;
    if (!cache->m_data || strcmp(name, part->m_name)) {
        if (cache->m_data) D_002B91B0(cache->m_data);
        strcpy(name, part->m_name);
        if (!(cache->m_data = func_00248E60(name))) goto out;
    }
    func_00253048(cache->m_data, &data, &psm, &stride, &height, 0, 0, 0, 0);
    x = part->m2C;
    y = part->m2E;
    w = part->m30;
    if (w < 0) w = stride;
    h = part->m32;
    if (h < 0) h = height;
    if (w & 7) Func235DE0("!!! invalid width (fname=%s, width=%d)\n", name, w);
    size = FaceTexSize(psm, w, h);
    if (size <= 0 || !(tex->m_data = Func245D00(size))) {
        Func235DE0("*** failed to load '%s'\n", name);
        goto out;
    }
    switch (psm) {
    case 0:
        Blit32((u32 *)tex->m_data, (u32 *)data, stride, x, y, w, h);
        break;
    case 1:
        Blit8((u8 *)tex->m_data, (u8 *)data, stride * 3, x, y, w * 3, h);
        break;
    case 2:
    case 10:
        Blit16((u16 *)tex->m_data, (u16 *)data, stride, x, y, w, h);
        break;
    case 19:
    case 27:
        Blit8((u8 *)tex->m_data, (u8 *)data, stride, x, y, w, h);
        break;
    case 20:
    case 36:
    case 44:
        Blit8((u8 *)tex->m_data, (u8 *)data, stride / 2, x, y, w / 2, h);
        break;
    default:
        Func235DE0(D_002D2DE0, psm);
        break;
    }
    ok = 1;
    tex->m_psm = psm;
    tex->m_w = w;
    tex->m_h = h;
out:
    return ok;
}
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2FB8);

CFacePart *FindFacePart(CFaceSet *sets, s32 nsets, s32 last, CFacePart *key) {
    for (s32 i = 0; i < nsets; i++) {
        s32 cnt = last;
        if (i < nsets - 1) cnt = sets[i].m_num;
        for (s32 j = 0; j < cnt; j++) {
            CFacePart *p = &sets[i].m_parts[j];
            if (*(s32 *)&p->m2C == *(s32 *)&key->m2C && *(s32 *)&p->m30 == *(s32 *)&key->m30 && !strcmp(p->m_name, key->m_name)) {
                return p;
            }
        }
    }
    return 0;
}

extern "C" s32 func_0010ED30(CFaceItem *out, CFaceSet *sets, s32 n, s32 x0, s32 y0, s32 w0, s32 h0) {
    char name[0x100];
    CFaceCache cache;
    s32 k = 0;
    s32 i, j;
    name[0] = 0;
    cache.m_data = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < sets[i].m_num; j++) {
            CFaceTex *o = (CFaceTex *)&out[k];
            CFacePart *part = &sets[i].m_parts[j];
            s32 r = -1;
            CFacePart *f = FindFacePart(sets, i + 1, j, part);
            if (f) {
                r = f->m24;
            } else {
                if (out) {
                    LoadFaceTex(o, part, name, &cache);
                    if (((part->m28 >= x0 && part->m28 < x0 + w0) || (part->m28 <= x0 && x0 < part->m28 + o->m_w)) &&
                        ((part->m2A >= y0 && part->m2A < y0 + h0) || (part->m2A <= y0 && y0 < part->m2A + o->m_h))) {
                        o->m_vis = 1;
                    } else {
                        o->m_vis = 0;
                    }
                    r = k;
                }
                k++;
            }
            part->m24 = r;
        }
    }
    if (cache.m_data) D_002B91B0(cache.m_data);
    return k;
}

s32 FindFaceIds(CFaceSet **out, const char *p, CFaceSet *parts, s32 nparts) {
    s32 id;
    s32 n = 0;
    while ((p = func_0024A710(p, &id, -1, D_002A03A4, D_002D2DD0), *p) || id >= 0) {
        if (out) {
            out[n] = 0;
            for (s32 j = 0; j < nparts; j++) {
                if (parts[j].m_id == id) {
                    out[n] = &parts[j];
                    break;
                }
            }
        }
        n++;
    }
    return n;
}

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010F068);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2FD8);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2FE0);

INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2FE8);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2FF0);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2FF8);
int CFaceRes::Load(const char *text) {
    char buf[0x100];
    s32 id;
    Release();
    m_unk30 = D_002A03A0++;
    m_unkC = LoadFaceSets(0, (void *)text);
    m_unk8 = (CFaceSet *)Func245D00(m_unkC * sizeof(CFaceSet));
    LoadFaceSets(m_unk8, (void *)text);
    m_unk4 = func_0010ED30(0, m_unk8, m_unkC, m_unk44, m_unk48, m_unk4C, m_unk50);
    m_unk0 = (CFaceItem *)Func245D00(m_unk4 * sizeof(CFaceItem));
    func_0010ED30(m_unk0, m_unk8, m_unkC, m_unk44, m_unk48, m_unk4C, m_unk50);
    m_unk14 = func_0010F068(0, 0, text, m_unk8, m_unkC);
    m_unk10 = (CFaceGroup *)Func245D00(m_unk14 * sizeof(CFaceGroup));
    func_0010F068(m_unk10, m_unk18, text, m_unk8, m_unkC);
    func_0024B190(Func24AF10((void *)text, D_002A03B0), D_002A03B4, buf, D_002D2FE8, 0x100);
    const char *p = buf;
    CFacePart **out = m_unk24;
    for (s32 k = 2; k >= 0; k--, out++) {
        *out = 0;
        p = func_0024A710(p, &id, -1, D_002D2DC8, D_002D2DD0);
        if (id >= 0) {
            s32 j;
            for (j = 0; j < m_unkC; j++) {
                if (m_unk8[j].m_id == id) break;
            }
            if (j < m_unkC && m_unk8[j].m_num > 0 && m_unk8[j].m_parts->m24 >= 0) {
                *out = m_unk8[j].m_parts;
            }
        }
    }
    return 1;
}

int LoadFaceRes(CFaceRes *res, const char *path) {
    char buf[0x100];
    char name[0x100];
    int ok = 0;
    func_0022DCE0();
    if (strstr(path, D_002A03B8)) {
        if (!func_00249070(path)) {
            Func235DE0("*** failed to load '%s'\n", path);
        } else {
            func_0024B650(path, 0, buf, 0);
            const char *ext = D_002A03BC;
            strcpy(buf + strlen(buf), ext);
            ok = LoadFaceRes(res, buf);
            func_002490F8();
        }
    } else if (strstr(path, D_002A03BC)) {
        func_0024B7B8(path, buf, name);
        func_0022DC90(0);
        func_0022DC90(buf);
        char *text = Func24A4C0(name);
        if (!text) {
            Func235DE0("*** failed to load '%s'\n", path);
        } else {
            ok = res->Load(text);
        }
        if (text) D_002B91B0(text);
        func_0022DC90(0);
    } else {
        Func235DE0("*** unsupported format '%s'\n", path);
    }
    func_0022DD00();
    return ok;
}

void CFaceRes::Release() {
    s32 i;
    for (i = 0; i < m_unkC; i++) {
        if (m_unk8[i].m_parts) D_002B91B0(m_unk8[i].m_parts);
    }
    if (m_unk8) {
        D_002B91B0(m_unk8);
        m_unk8 = 0;
        m_unkC = 0;
    }
    for (i = 0; i < m_unk4; i++) {
        if (m_unk0[i].m_data) D_002B91B0(m_unk0[i].m_data);
    }
    if (m_unk0) {
        D_002B91B0(m_unk0);
        m_unk0 = 0;
        m_unk4 = 0;
    }
    for (i = 0; i < m_unk14; i++) {
        for (s32 k = 0; k < 3; k++) {
            if (m_unk10[i].m_ptrs[k]) D_002B91B0(m_unk10[i].m_ptrs[k]);
        }
    }
    if (m_unk10) {
        D_002B91B0(m_unk10);
        m_unk10 = 0;
        m_unk14 = 0;
    }
    memset(m_unk18, 0, 0xC);
    memset(m_unk24, 0, 0xC);
}

CFaceResRec *CFaceResSub10F8F0::Find(s32 id) {
    for (s32 i = 0; i < m_num; i++) {
        if (m_recs[i].m_id == id) {
            return &m_recs[i];
        }
    }
    return 0;
}

s32 CFaceResSub10F938::GetFirst() {
    return m_count > 0 ? m_list[0] : -1;
}

void Blit32(u32 *dst, u32 *src, s32 stride, s32 x, s32 y, s32 w, s32 h) {
    u32 *p = src + y * stride + x;
    for (; h > 0; h--) {
        for (s32 i = w; i > 0; i--) {
            *dst++ = *p++;
        }
        p += stride - w;
    }
}

void Blit8(u8 *dst, u8 *src, s32 stride, s32 x, s32 y, s32 w, s32 h) {
    src = src + y * stride + x;
    for (; h > 0; h--) {
        for (s32 i = w; i > 0; i--) {
            *dst++ = *src++;
        }
        src += stride - w;
    }
}

void Blit16(u16 *dst, u16 *src, s32 stride, s32 x, s32 y, s32 w, s32 h) {
    u16 *p = src + y * stride + x;
    for (; h > 0; h--) {
        for (s32 i = w; i > 0; i--) {
            *dst++ = *p++;
        }
        p += stride - w;
    }
}
