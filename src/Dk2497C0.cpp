#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
s32 Func235DE0(const char *fmt, ...);
extern "C" char *strcpy(char *d, const char *s);
extern "C" unsigned int strlen(const char *s);
extern "C" int strcmp(const char *a, const char *b);
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern "C" int atoi(const char *s);
extern "C" f32 atoff(const char *s);
extern "C" double func_002890E8(const char *s);
extern "C" double func_00280260(double a, double b);
extern "C" char *func_0028B000(const char *s, int c);
extern const char D_002E6670[];
extern const char D_002E6678[];
extern const char D_002E6680[];
extern const char D_002E6718[];
extern const char D_002E6740[];
extern const char D_002E6748[];
extern char D_3935F0[];
extern "C" void *memcpy(void *d, const void *s, unsigned int n);
struct CValue {
    s32 m_type;               // 0x0
    union {
        s32 i;
        f32 f;
        char s[0x100];
    } u;                      // 0x4
};
class CExpr;
extern "C" void func_0024BAE0(CValue *v);
extern "C" void func_0024BAF0(CValue *v, s32 i);
extern "C" void func_0024BB58(CValue *v, f32 f);
extern "C" void func_0024BC00(CValue *v, const char *s);
extern "C" s32 func_0024BC88(CValue *v);
extern "C" f32 func_0024BD00(CValue *v);
extern "C" char *func_0024BD78(CValue *v);
extern "C" s32 func_0024D868(CExpr *e, s32 lo, s32 hi);
extern "C" f32 func_0024D8D8(CExpr *e, f32 lo, f32 hi);
extern "C" void func_0024D948(CExpr *e, const char *fmt, ...);

extern const char D_002E6618[];
extern "C" const char *func_0024A4E0(const char *s);
extern "C" void func_0024A500(char **dst, const char **src);
const char *Func24A570(const char *src, char *dst, const char *delim, const char *skip);
extern "C" const char *func_0024AB30(const char *s);
extern "C" const char *func_0024AB90(const char *s, const char *set);
extern "C" void func_0024ABE0(char *s, const char *set);
extern "C" const char *func_0024AC50(const char *src, char *dst, s32 max);
extern "C" const char *func_0024AD10(const char *src, char *dst, s32 skip, s32 max);
const char *Func24AF10(void *src, const char *key);
const char *Func24AFE8(const char *src, char *dst, int skip, int max);

typedef __builtin_va_list va_list;
#define va_start(ap, last) __builtin_stdarg_start(ap, last)
#define va_end(ap) __builtin_va_end(ap)
extern "C" int vsprintf(char *buf, const char *fmt, va_list ap);
extern "C" void *memset(void *d, int c, unsigned int n);
extern "C" s32 func_001F15F0();
extern "C" void func_001F15F0v() asm("func_001F15F0");
extern "C" void func_001F1610();
extern void (*D_002B91B0)(void *p);
extern void *(*D_002B91A4)(s32 n);
extern void *(*D_002B91A8)(s32 n);
void *Func245D00(int n);
class CHeapObj {
public:
    static void *operator new(unsigned int n);
};
struct CXapEntry {
    s32 m_name;               // 0x0
    u8 m_packed;              // 0x4
    u8 pad5[3];
    s32 m_offset;             // 0x8
    s32 m_size;               // 0xC
    s32 m_packedSize;         // 0x10
    u8 pad14[0xC];
};
struct CXapIndex {
    s32 m_unk0;               // 0x0
    s32 m_count;              // 0x4
    CXapEntry m_entries[1];   // 0x8
};
struct CXapDir {
    s32 m_hook0;              // 0x0
    s32 m_hook4;              // 0x4
    char m_cwd[0x100];        // 0x8
    u8 *m_data;               // 0x108
    void *m_owned;            // 0x10C
    CXapIndex *m_index;       // 0x110
    void *m_hash;             // 0x114
    s32 m_external;           // 0x118
    char m_file[0x100];       // 0x11C
    s32 m_flags;              // 0x21C
    void *m_raw;              // 0x220
    void *m_buf;              // 0x224
};
struct CXapLink {
    CXapLink *m_next;         // 0x0
    char m_name[0x100];       // 0x4
    char m_path[0x100];       // 0x104
    void *m_data;             // 0x204
};
struct CXapGlobal {
    u8 m_stack[0x2288];       // 0x0
    CXapLink m_nodes[16];     // 0x2288
    CXapLink *m_open;         // 0x4308
    CXapLink *m_free;         // 0x430C
    s32 m_unk4310;            // 0x4310
};
extern CXapGlobal D_38F2D8;
extern CXapLink *D_3935E0;
extern "C" CXapDir *func_00249550();
extern "C" CXapDir *func_00249748();
extern "C" void func_00249790();
extern "C" s32 func_002496D0(void *p);
extern "C" void *func_00249700(void *hdr, u32 id);
extern "C" CXapEntry *func_002497C0(CXapDir *d, const char *name);
extern "C" CXapEntry *func_00249870(CXapDir *d, const char *name);
extern "C" CXapEntry *func_00249888(CXapDir *d, const char *name);
extern "C" s32 func_002498D8(const char *file, s32 off, void *buf, s32 size);
extern "C" s32 func_00249958(void *dst, void *src);
extern "C" void *func_00249BF0(const char *name, s32 *size);
extern "C" void func_00249D50();
extern "C" s32 func_00249DC8(const char *name);
extern "C" s32 func_00249E18(const char *name, void *dst);
extern "C" CXapLink *func_00249E68(const char *name);
extern "C" s32 func_00249EC0(void *data, const char *file, void *owned);
extern "C" void func_0024A2E0(const char *name);
extern "C" void *func_00248E60(const char *name);
extern "C" s32 func_0022DD78(const char *name, s32 mode);
extern "C" void func_0022E230(s32 fd, s32 off, s32 whence);
extern "C" void func_0022DF28(s32 fd, void *buf, s32 size);
extern "C" void func_0022DDE8(s32 fd);
extern "C" const char *func_0022DCC0();
extern "C" void func_0022DC90(const char *dir);
extern "C" s32 func_0022FF88(void *f);
extern "C" s32 func_0022FFD0(void *f);
extern "C" s32 func_0022FF58(const char *name);
extern "C" s32 func_0022FF18(const char *name, void *buf);
extern "C" void *memcpy(void *d, const void *s, unsigned int n);
extern const char D_002E6560[];
extern const char D_002E6580[];
extern const char D_002E65A0[];
extern const char D_002E65C0[];
extern const char D_002E65D8[];
extern const char D_002E65F8[];
extern const char D_002E6620[];
extern "C" void strncpy(char *d, const char *s, s32 n);
typedef void *(*AllocFn)(s32);
extern "C" void *func_0024A398(AllocFn f, s32 n);
extern "C" void *func_0024A3D8(s32 n);
extern "C" void *func_0024A3F8(s32 n);
extern "C" void *func_0024A418(AllocFn f, const char *name);
extern "C" void func_0024B650(const char *path, s32 a1, char *dir, char *name);
typedef s32 (CExpr::*CExprFn)(const char *, void *);
class CExpr {
public:
    CExpr();
    virtual ~CExpr();
    void Func24D9C8(CExpr *obj, CExprFn a, CExprFn b);
    s32 Func24DB98(int src, const char *delim, int cont);

    const char *m_src;        // 0x0
    CExpr *m_obj;             // 0x4
    CExprFn m_get;            // 0x8
    CExprFn m_set;            // 0x10
    u32 m_seed;               // 0x18
};
extern "C" s32 func_0024BAE0i(CValue *v) asm("func_0024BAE0");
extern "C" s32 func_0024D6A0(CExpr *e, CValue *v, const char **p, s32 depth);

extern const char D_002E6780[];
extern "C" s32 func_0024B190(const char *src, const char *name, char *out, const char *def, s32 max);
extern "C" void func_0024B0A0(const char *s, char *key, char *val, s32 max);
extern const char D_002E6800[];
extern "C" s32 func_0024DC40(CExpr *e, const char *s);
const char *Func24ADE0(const char *s, char *out, int max);
struct CRand {
    u32 m_seed;
    u32 Next() {
        m_seed = m_seed * 0x19660D + 1;
        return m_seed >> 12;
    }
};
// @decl-end

extern "C" CXapEntry *func_002497C0(CXapDir *d, const char *name) {
    CXapIndex *idx = d->m_index;
    s32 lo = 0;
    s32 hi = idx->m_count;
    while (lo < hi) {
        s32 mid = (lo + hi) >> 1;
        CXapEntry *e = &idx->m_entries[mid];
        s32 c = strcmp((char *)idx + e->m_name, name);
        if (c < 0) lo = mid + 1;
        else if (c > 0) hi = mid;
        else return e;
    }
    return 0;
}

extern "C" CXapEntry *func_00249870(CXapDir *d, const char *name) {
    return func_002497C0(d, name);
}

extern "C" CXapEntry *func_00249888(CXapDir *d, const char *name) {
    CXapEntry *e = 0;
    if (d->m_hash) e = func_00249870(d, name);
    else if (d->m_index) e = func_002497C0(d, name);
    return e;
}

extern "C" s32 func_002498D8(const char *file, s32 off, void *buf, s32 size) {
    s32 fd = func_0022DD78(file, 1);
    if (fd < 0) return fd;
    func_0022E230(fd, off, 0);
    func_0022DF28(fd, buf, size);
    func_0022DDE8(fd);
    return size;
}

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_00249958);

extern "C" void *func_00249BF0(const char *name, s32 *size) {
    char path[0x100];
    CXapDir *d;
    CXapEntry *e;
    *size = 0;
    func_00249D50();
    d = func_00249550();
    if (!d) goto fail;
    strcpy(path, func_0022DCC0());
    strcpy(path + strlen(path), name);
    e = func_00249888(d, path);
    if (!e) goto fail;
    if (d->m_external) {
        d->m_raw = CHeapObj::operator new(e->m_packedSize);
        if (!d->m_raw) goto fail;
        d->m_flags |= 1;
        if (func_002498D8(d->m_file, e->m_offset, d->m_raw, e->m_packedSize) < 0) goto fail;
    } else {
        d->m_raw = d->m_data + e->m_offset;
    }
    if (e->m_packed == 1) {
        d->m_buf = CHeapObj::operator new(e->m_size);
        if (!d->m_buf) goto fail;
        d->m_flags |= 2;
        if (!func_00249958(d->m_buf, d->m_raw)) goto fail;
    } else {
        d->m_buf = d->m_raw;
    }
    *size = e->m_size;
    return d->m_buf;
fail:
    func_00249D50();
    return 0;
}

extern "C" void func_00249D50() {
    CXapDir *d = func_00249550();
    if (!d) return;
    if (d->m_flags & 1) (*D_002B91B0)(d->m_raw);
    if (d->m_flags & 2) (*D_002B91B0)(d->m_buf);
    d->m_flags = 0;
    d->m_raw = 0;
    d->m_buf = 0;
}

extern "C" s32 func_00249DC8(const char *name) {
    CXapDir *d = func_00249550();
    CXapEntry *e;
    if (!d) return -2;
    e = func_00249888(d, name);
    if (!e) return -2;
    return e->m_size;
}

extern "C" s32 func_00249E18(const char *name, void *dst) {
    s32 size;
    void *p = func_00249BF0(name, &size);
    if (!p) return -2;
    memcpy(dst, p, size);
    func_00249D50();
    return size;
}

extern "C" CXapLink *func_00249E68(const char *name) {
    CXapLink *n;
    func_001F15F0v();
    for (n = D_3935E0; n && strcmp(n->m_name, name); n = n->m_next);
    func_001F1610();
    return n;
}

extern "C" s32 func_00249EC0(void *data, const char *file, void *owned) {
    CXapDir *d;
    if (!func_002496D0(data)) {
        Func235DE0(D_002E6560, data);
        return 0;
    }
    d = func_00249748();
    if (!d) {
        Func235DE0(D_002E6580);
        return 0;
    }
    d->m_index = (CXapIndex *)func_00249700(data, 0x454C4946);
    d->m_hash = func_00249700(data, 0x48534148);
    d->m_hook0 = func_0022FF88((void *)func_00249E18);
    d->m_hook4 = func_0022FFD0((void *)func_00249DC8);
    strcpy(d->m_cwd, func_0022DCC0());
    func_0022DC90(0);
    d->m_data = (u8 *)data;
    d->m_owned = owned;
    if (file && *file) {
        d->m_external = 1;
        strcpy(d->m_file, file);
    } else {
        d->m_external = 0;
        d->m_file[0] = 0;
    }
    return 1;
}

extern "C" s32 func_00249FE8(void *data, const char *file) {
    return func_00249EC0(data, file, 0);
}

extern "C" s32 func_0024A000(const char *name) {
    CXapLink *l = func_00249E68(name);
    void *data;
    if (l) return func_00249EC0(l->m_data, l->m_path, 0);
    data = func_00248E60(name);
    if (!data) return 0;
    if (!func_00249EC0(data, 0, data)) {
        (*D_002B91B0)(data);
        return 0;
    }
    return 1;
}

extern "C" void func_0024A098() {
    CXapDir *d = func_00249550();
    if (!d) return;
    func_00249D50();
    func_0022FF88((void *)d->m_hook0);
    func_0022FFD0((void *)d->m_hook4);
    func_0022DC90(0);
    func_0022DC90(d->m_cwd);
    if (d->m_owned) (*D_002B91B0)(d->m_owned);
    memset(d, 0, sizeof(CXapDir));
    func_00249790();
}

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024A128);

extern "C" void func_0024A2E0(const char *name) {
    CXapLink **pp;
    CXapLink *n;
    func_001F15F0v();
    for (pp = &D_38F2D8.m_open; (n = *pp) != 0; pp = &n->m_next) {
        if (!strcmp(n->m_name, name)) {
            if (n->m_data) {
                (*D_002B91B0)(n->m_data);
                n->m_data = 0;
            }
            n->m_path[0] = 0;
            n->m_name[0] = 0;
            *pp = n->m_next;
            n->m_next = D_38F2D8.m_free;
            D_38F2D8.m_free = n;
            break;
        }
    }
    func_001F1610();
}

extern "C" void *func_0024A398(AllocFn f, s32 n) {
    char *p = (char *)f(n + 1);
    if (p) p[n] = 0;
    return p;
}

extern "C" void *func_0024A3D8(s32 n) {
    return func_0024A398(D_002B91A4, n);
}

extern "C" void *func_0024A3F8(s32 n) {
    return func_0024A398(D_002B91A8, n);
}

extern "C" void *func_0024A418(AllocFn f, const char *name) {
    void *buf = 0;
    s32 size = func_0022FF58(name);
    if (size > 0) {
        buf = f(size);
        if (buf) {
            if (func_0022FF18(name, buf) > 0) return buf;
        }
    }
    if (buf) (*D_002B91B0)(buf);
    return 0;
}

extern "C" void *func_0024A4A0(const char *name) {
    return func_0024A418(func_0024A3D8, name);
}

void *Func24A4C0(const char *name) {
    return func_0024A418(func_0024A3F8, name);
}

extern "C" const char *func_0024A4E0(const char *s) {
    return (u8)*s < 0x7F ? s + 1 : s + 2;
}

extern "C" void func_0024A500(char **dst, const char **src) {
    if ((u8)**src < 0x7F) {
        *(*dst)++ = *(*src)++;
    } else {
        *(*dst)++ = *(*src)++;
        *(*dst)++ = *(*src)++;
    }
}

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", Func24A570__FPCcPcT0T0);

extern "C" const char *func_0024A6B0(const char *src, char *dst, const char *def, const char *delim, const char *skip) {
    const char *r = Func24A570(src, dst, delim, skip);
    if (!*dst) strcpy(dst, def);
    return r;
}

extern "C" const char *func_0024A710(const char *src, s32 *out, s32 def, const char *delim, const char *skip) {
    char buf[0x100];
    const char *r = Func24A570(src, buf, delim, skip);
    if (buf[0]) def = atoi(buf);
    *out = def;
    return r;
}

extern "C" const char *func_0024A778(const char *src, f32 *out, f32 def, const char *delim, const char *skip) {
    char buf[0x100];
    const char *r = Func24A570(src, buf, delim, skip);
    *out = buf[0] ? atoff(buf) : def;
    return r;
}

extern "C" s32 func_0024A7D8(const char *src, const char *delim, const char *skip) {
    char buf[0x400];
    s32 n = 0;
    while ((src = Func24A570(src, buf, delim, skip), *src) || buf[0]) n++;
    return n;
}

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", Func24A840__FPCcPcT0T0i);

extern "C" const char *func_0024AB30(const char *s) {
    const char *r;
    while (*s && *s != '\n') s++;
    r = s + 1;
    if (*s != '\n') r = s;
    return r;
}

extern "C" const char *func_0024AB90(const char *s, const char *set) {
    while (*s && func_0028B000(set, *s)) s++;
    return s;
}

extern "C" void func_0024ABE0(char *s, const char *set) {
    char *last = 0;
    while (*s) {
        if (!func_0028B000(set, *s)) last = s;
        s++;
    }
    if (last) last[1] = 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024AC50);

extern "C" const char *func_0024AD10(const char *src, char *dst, s32 skip, s32 max) {
    do {
        src = func_0024AC50(src, dst, max);
    } while (*src && skip && !*dst);
    return src;
}

extern "C" s32 func_0024AD80(const char *src, s32 skip) {
    char buf[0x100];
    s32 n = 0;
    while ((src = func_0024AD10(src, buf, skip, 0x100), *src) || buf[0]) n++;
    return n;
}

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", Func24ADE0__FPCcPci);

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", Func24AF10__FPvPCc);

extern "C" s32 func_0024AF90(const char *src, const char *key) {
    s32 n = 0;
    while (*(src = Func24AF10((void *)src, key))) {
        src++;
        n++;
    }
    return n;
}

const char *Func24AFE8(const char *src, char *dst, int skip, int max) {
    *dst = 0;
    src = func_0024AD10(src, dst, skip, max);
    if (*dst == '[') {
        *dst = 0;
        src += strlen(src);
    }
    return src;
}

extern "C" s32 func_0024B040(const char *src, s32 skip) {
    char buf[0x100];
    s32 n = 0;
    while ((src = Func24AFE8(src, buf, skip, 0x100), *src) || buf[0]) n++;
    return n;
}

extern "C" void func_0024B0A0(const char *s, char *key, char *val, s32 max) {
    const char *eq = func_0028B000(s, '=');
    s32 n;
    if (eq) {
        n = eq - s;
        if (n > 0) memcpy(key, s, n);
        key[n] = 0;
        func_0024ABE0(key, D_002E6620);
        strncpy(val, func_0024AB90(eq + 1, D_002E6620), max);
        return func_0024ABE0(val, D_002E6620);
    }
    *key = 0;
    *val = 0;
}

extern "C" s32 func_0024B190(const char *src, const char *name, char *out, const char *def, s32 max) {
    char key[0x100];
    s32 size = max + 0x100;
    char *line = (char *)__builtin_alloca(size);
    const char *p = src;
    while ((p = Func24AFE8(p, line, 1, size), *p) || line[0]) {
        func_0024B0A0(line, key, out, max);
        if (!strcmp(key, name)) return 1;
    }
    if (def) strcpy(out, def);
    return 0;
}

extern "C" s32 func_0024B298(const char *src, const char *name, s32 *out, s32 def) {
    char buf[0x100];
    s32 r = func_0024B190(src, name, buf, 0, 0x100);
    s32 v = def;
    if (r == 1) v = atoi(buf);
    *out = v;
    return r;
}

extern "C" s32 func_0024B300(const char *src, const char *name, f32 *out, f32 def) {
    char buf[0x100];
    s32 r = func_0024B190(src, name, buf, 0, 0x100);
    f32 v = def;
    if (r == 1) v = atoff(buf);
    *out = v;
    return r;
}

extern "C" s32 func_0024B368(const char *src, const char *name, s32 def) {
    char buf[0x100];
    if (func_0024B190(src, name, buf, 0, 0x100)) return atoi(buf);
    return def;
}

extern "C" f32 func_0024B3B8(const char *src, const char *name, f32 def) {
    char buf[0x100];
    if (func_0024B190(src, name, buf, 0, 0x100)) return atoff(buf);
    return def;
}

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024B400);

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024B4B8);

extern "C" void strncpy(char *d, const char *s, s32 n) {
    while (*s && n > 1) {
        *d++ = *s++;
        n--;
    }
    *d = 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024B650);

extern "C" void func_0024B7B8(const char *path, s32 a1, char *out) {
    char dir[0x100];
    char name[0x100];
    func_0024B650(path, a1, dir, name);
    if (out) {
        strcpy(out, dir);
        strcpy(out + strlen(out), name);
    }
}

extern "C" s32 func_0024B818(char **pp, const char *fmt, ...) {
    char buf[0x400];
    va_list ap;
    s32 n;
    va_start(ap, fmt);
    if (*pp) {
        n = vsprintf(*pp, fmt, ap);
        *pp += n;
    } else {
        n = vsprintf(buf, fmt, ap);
    }
    return n;
}

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024B8B8);

s32 Func24B998(const char **tbl, const char *s) {
    s32 i;
    for (i = 0; tbl[i]; i++) {
        if (!strcmp(tbl[i], s)) return i;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024BA08);

extern "C" void func_0024BAE0(CValue *v) {
    v->m_type = -1;
    v->u.i = 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024BAF0);

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024BB58);

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024BC00);

extern "C" s32 func_0024BC88(CValue *v) {
    switch (v->m_type) {
    case 0:
        return v->u.i;
    case 1:
        return (s32)v->u.f;
    case 2:
        return atoi(v->u.s);
    }
    return 0;
}

extern "C" f32 func_0024BD00(CValue *v) {
    switch (v->m_type) {
    case 0:
        return v->u.i;
    case 1:
        return v->u.f;
    case 2:
        return atoff(v->u.s);
    }
    return 0.0f;
}

extern "C" char *func_0024BD78(CValue *v) {
    switch (v->m_type) {
    case 0:
        sprintf(D_3935F0, D_002E6670, v->u.i);
        return D_3935F0;
    case 1:
        sprintf(D_3935F0, D_002E6678, v->u.f);
        return D_3935F0;
    default:
        return (char *)D_002E6680;
    case 2:
        return v->u.s;
    }
}

extern "C" void func_0024BE38(CValue *d, CValue *s) {
    switch (d->m_type) {
    case 0:
        d->u.i = func_0024BC88(s);
        break;
    case 1:
        d->u.f = func_0024BD00(s);
        break;
    case 2:
        strcpy(d->u.s, func_0024BD78(s));
        break;
    default:
        *d = *s;
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024BF80);

extern "C" s32 func_0024C048(CValue *d, CValue *s, CExpr *e) {
    d->u.i = func_0024D868(e, d->u.i, func_0024BC88(s));
    return 1;
}

extern "C" s32 func_0024C098(CValue *d, CValue *s) {
    d->u.i = d->u.i || func_0024BC88(s);
    return 1;
}

extern "C" s32 func_0024C0F0(CValue *d, CValue *s) {
    d->u.i = d->u.i && func_0024BC88(s);
    return 1;
}

extern "C" s32 func_0024C138(CValue *d, CValue *s) {
    d->u.i = d->u.i == func_0024BC88(s);
    return 1;
}

extern "C" s32 func_0024C178(CValue *d, CValue *s) {
    d->u.i = d->u.i != func_0024BC88(s);
    return 1;
}

extern "C" s32 func_0024C1B8(CValue *d, CValue *s) {
    d->u.i = d->u.i > func_0024BC88(s);
    return 1;
}

extern "C" s32 func_0024C1F0(CValue *d, CValue *s) {
    d->u.i = d->u.i < func_0024BC88(s);
    return 1;
}

extern "C" s32 func_0024C228(CValue *d, CValue *s) {
    d->u.i = d->u.i >= func_0024BC88(s);
    return 1;
}

extern "C" s32 func_0024C268(CValue *d, CValue *s) {
    d->u.i = d->u.i <= func_0024BC88(s);
    return 1;
}

extern "C" s32 func_0024C2A8(CValue *d, CValue *s) {
    d->u.i = d->u.i * func_0024BC88(s);
    return 1;
}

extern "C" s32 func_0024C2E0(CValue *d, CValue *s, CExpr *e) {
    if (func_0024BC88(s) == 0) {
        func_0024D948(e, D_002E6718);
        return 0;
    }
    d->u.i = d->u.i / func_0024BC88(s);
    return 1;
}

extern "C" s32 func_0024C368(CValue *d, CValue *s, CExpr *e) {
    if (func_0024BC88(s) == 0) {
        func_0024D948(e, D_002E6718);
        return 0;
    }
    d->u.i = d->u.i % func_0024BC88(s);
    return 1;
}

extern "C" s32 func_0024C3F0(CValue *d, CValue *s) {
    d->u.i = d->u.i * func_0024BC88(s) / 100;
    return 1;
}

extern "C" s32 func_0024C440(CValue *d, CValue *s) {
    d->u.i = d->u.i + func_0024BC88(s);
    return 1;
}

extern "C" s32 func_0024C478(CValue *d, CValue *s) {
    d->u.i = d->u.i - func_0024BC88(s);
    return 1;
}

extern "C" s32 func_0024C4B0(CValue *d, CValue *s) {
    d->u.i = !func_0024BC88(s);
    return 1;
}

extern "C" s32 func_0024C4E8(CValue *d, CValue *s) {
    d->u.i = func_0024BC88(s);
    return 1;
}

extern "C" s32 func_0024C518(CValue *d, CValue *s) {
    d->u.i = -func_0024BC88(s);
    return 1;
}

extern "C" s32 func_0024C550(CValue *d, CValue *s, CExpr *e) {
    d->u.f = func_0024D8D8(e, d->u.f, func_0024BD00(s));
    return 1;
}

extern "C" s32 func_0024C5A0(CValue *d, CValue *s) {
    d->u.f = d->u.f != 0.0f || func_0024BD00(s) != 0.0f;
    return 1;
}

extern "C" s32 func_0024C630(CValue *d, CValue *s) {
    d->u.f = d->u.f != 0.0f && func_0024BD00(s) != 0.0f;
    return 1;
}

extern "C" s32 func_0024C6C0(CValue *d, CValue *s) {
    d->u.f = d->u.f == func_0024BD00(s) ? 1.0f : 0.0f;
    return 1;
}

extern "C" s32 func_0024C708(CValue *d, CValue *s) {
    d->u.f = d->u.f != func_0024BD00(s) ? 1.0f : 0.0f;
    return 1;
}

extern "C" s32 func_0024C750(CValue *d, CValue *s) {
    d->u.f = d->u.f > func_0024BD00(s) ? 1.0f : 0.0f;
    return 1;
}

extern "C" s32 func_0024C798(CValue *d, CValue *s) {
    d->u.f = d->u.f < func_0024BD00(s) ? 1.0f : 0.0f;
    return 1;
}

extern "C" s32 func_0024C7E0(CValue *d, CValue *s) {
    d->u.f = d->u.f >= func_0024BD00(s) ? 1.0f : 0.0f;
    return 1;
}

extern "C" s32 func_0024C828(CValue *d, CValue *s) {
    d->u.f = d->u.f <= func_0024BD00(s) ? 1.0f : 0.0f;
    return 1;
}

extern "C" s32 func_0024C870(CValue *d, CValue *s) {
    d->u.f = d->u.f * func_0024BD00(s);
    return 1;
}

extern "C" s32 func_0024C8A8(CValue *d, CValue *s, CExpr *e) {
    if (func_0024BD00(s) == 0.0f) {
        func_0024D948(e, D_002E6718);
        return 0;
    }
    d->u.f = d->u.f / func_0024BD00(s);
    return 1;
}

extern "C" s32 func_0024C930(CValue *d, CValue *s, CExpr *e) {
    if (func_0024BD00(s) == 0.0f) {
        func_0024D948(e, D_002E6718);
        return 0;
    }
    d->u.f = func_00280260(d->u.f, func_0024BD00(s));
    return 1;
}

extern "C" s32 func_0024C9D8(CValue *d, CValue *s) {
    d->u.f = d->u.f * func_0024BD00(s) / 100.0f;
    return 1;
}

extern "C" s32 func_0024CA28(CValue *d, CValue *s) {
    d->u.f = d->u.f + func_0024BD00(s);
    return 1;
}

extern "C" s32 func_0024CA60(CValue *d, CValue *s) {
    d->u.f = d->u.f - func_0024BD00(s);
    return 1;
}

extern "C" s32 func_0024CA98(CValue *d, CValue *s) {
    d->u.f = func_0024BD00(s) == 0.0f ? 1.0f : 0.0f;
    return 1;
}

extern "C" s32 func_0024CAE0(CValue *d, CValue *s) {
    d->u.f = func_0024BD00(s);
    return 1;
}

extern "C" s32 func_0024CB10(CValue *d, CValue *s) {
    d->u.f = -func_0024BD00(s);
    return 1;
}

extern "C" s32 func_0024CB48(CValue *d, CValue *s) {
    func_0024BC00(d, func_0024BD78(s));
    return 1;
}

extern "C" s32 func_0024CB80(CValue *d, CValue *s) {
    func_0024BC00(d, *func_0024BD78(d) || *func_0024BD78(s) ? D_002E6740 : D_002E6748);
    return 1;
}

extern "C" s32 func_0024CBE8(CValue *d, CValue *s) {
    func_0024BC00(d, *func_0024BD78(d) && *func_0024BD78(s) ? D_002E6740 : D_002E6748);
    return 1;
}

extern "C" s32 func_0024CC50(CValue *d, CValue *s) {
    func_0024BC00(d, strcmp(func_0024BD78(d), func_0024BD78(s)) == 0 ? D_002E6740 : D_002E6748);
    return 1;
}

extern "C" s32 func_0024CCC8(CValue *d, CValue *s) {
    func_0024BC00(d, strcmp(func_0024BD78(d), func_0024BD78(s)) != 0 ? D_002E6740 : D_002E6748);
    return 1;
}

extern "C" s32 func_0024CD40(CValue *d, CValue *s) {
    func_0024BC00(d, strcmp(func_0024BD78(d), func_0024BD78(s)) > 0 ? D_002E6740 : D_002E6748);
    return 1;
}

extern "C" s32 func_0024CDB8(CValue *d, CValue *s) {
    func_0024BC00(d, strcmp(func_0024BD78(d), func_0024BD78(s)) < 0 ? D_002E6740 : D_002E6748);
    return 1;
}

extern "C" s32 func_0024CE30(CValue *d, CValue *s) {
    func_0024BC00(d, strcmp(func_0024BD78(d), func_0024BD78(s)) >= 0 ? D_002E6740 : D_002E6748);
    return 1;
}

extern "C" s32 func_0024CEA8(CValue *d, CValue *s) {
    func_0024BC00(d, strcmp(func_0024BD78(d), func_0024BD78(s)) <= 0 ? D_002E6740 : D_002E6748);
    return 1;
}

extern "C" s32 func_0024CF20(CValue *d, CValue *s) {
    func_0024BC00(d, func_0024BD78(s));
    return 1;
}

extern "C" s32 func_0024CF58(CValue *d, CValue *s) {
    func_0024BC00(d, func_0024BD78(s));
    return 1;
}

extern "C" s32 func_0024CF90(CValue *d, CValue *s) {
    func_0024BC00(d, func_0024BD78(s));
    return 1;
}

extern "C" s32 func_0024CFC8(CValue *d, CValue *s) {
    func_0024BC00(d, func_0024BD78(s));
    return 1;
}

extern "C" s32 func_0024D000(CValue *d, CValue *s) {
    char buf[0x100];
    const char *p;
    strcpy(buf, func_0024BD78(d));
    p = func_0024BD78(s);
    strcpy(buf + strlen(buf), p);
    func_0024BC00(d, buf);
    return 1;
}

extern "C" s32 func_0024D070(CValue *d, CValue *s) {
    func_0024BC00(d, func_0024BD78(s));
    return 1;
}

extern "C" s32 func_0024D0A8(CValue *d, CValue *s) {
    func_0024BC00(d, *func_0024BD78(s) ? D_002E6680 : D_002E6740);
    return 1;
}

extern "C" s32 func_0024D0F8(CValue *d, CValue *s) {
    func_0024BC00(d, func_0024BD78(s));
    return 1;
}

extern "C" s32 func_0024D130(CValue *d, CValue *s) {
    func_0024BC00(d, func_0024BD78(s));
    return 1;
}

CExpr::CExpr() {
    m_seed = 1;
    m_src = 0;
    m_obj = 0;
    memset(&m_get, 0, 8);
    memset(&m_set, 0, 8);
}

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", _$_5CExpr);

extern "C" const char *func_0024D1F8(const char *s, const char *set) {
    while (*s && func_0028B000(set, *s)) s++;
    return s;
}

extern "C" s32 func_0024D248(s32 *tbl, s32 v) {
    s32 i;
    for (i = 0; tbl[i] >= 0; i++) {
        if (tbl[i] == v) return i;
    }
    return -1;
}

extern "C" s32 func_0024D288(const char **tbl, const char *s) {
    s32 i;
    for (i = 0; tbl[i]; i++) {
        if (!strcmp(tbl[i], s)) return i;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024D2F8);

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024D340);

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024D3D0);

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024D460);

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024D6A0);

extern "C" void func_0024D860(CExpr *e, u32 seed) {
    e->m_seed = seed;
}

extern "C" s32 func_0024D868(CExpr *e, s32 lo, s32 hi) {
    CRand *r = (CRand *)&e->m_seed;
    if (hi < lo) hi = lo;
    if (lo == hi) return lo;
    return ((r->Next() << 16) | (r->Next() & 0xFFFF)) % (u32)(hi - lo + 1) + lo;
}

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024D8D8);

extern "C" void func_0024D948(CExpr *e, const char *fmt, ...) {
    char buf[0x400];
    va_list ap;
    va_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    Func235DE0(D_002E6800, e->m_src, buf);
}

void CExpr::Func24D9C8(CExpr *obj, CExprFn a, CExprFn b) {
    m_obj = obj;
    m_get = a;
    m_set = b;
}

extern "C" s32 func_0024DA00(CExpr *e, const char *s) {
    const char *p = s;
    CValue v;
    func_0024BAE0(&v);
    func_0024BAF0(&v, 0);
    e->m_src = p;
    if (!func_0024D6A0(e, &v, &p, 0)) return 0;
    return func_0024BC88(&v);
}

extern "C" f32 func_0024DA70(CExpr *e, const char *s) {
    const char *p = s;
    CValue v;
    func_0024BAE0(&v);
    func_0024BB58(&v, 0.0f);
    e->m_src = p;
    if (!func_0024D6A0(e, &v, &p, 0)) return 0.0f;
    return func_0024BD00(&v);
}

extern "C" const char *func_0024DAF0(CExpr *e, const char *s, char *out) {
    const char *p = s;
    CValue v;
    func_0024BAE0i(&v);
    func_0024BC00(&v, D_002E6680);
    e->m_src = p;
    if (!func_0024D6A0(e, &v, &p, 0)) return D_002E6680;
    strcpy(out, func_0024BD78(&v));
    return out;
}

s32 CExpr::Func24DB98(int isrc, const char *delim, int cont) {
    char buf[0x100];
    const char *src;
    m_src = (const char *)isrc;
    src = (const char *)isrc;
    while ((src = Func24A570(src, buf, delim, D_002E6780), *src) || buf[0]) {
        if (!func_0024DC40(this, buf) && !cont) return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/Dk2497C0", func_0024DC40);
