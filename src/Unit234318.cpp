#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "libc.h"
extern "C" int atoi(const char *);
s32 Func235DE0(const char *fmt, ...);
extern s32 D_002B8D54;
extern s32 D_002B8D5C;
extern s32 D_002B8D60;
extern s32 D_002B90A8;
extern s32 D_36D980[4];
extern const char D_002E4D00[];
extern const char D_002E4D78[];
extern const char D_002E4DB8[];
extern const char D_002E4DC8[];
extern const char D_002E4DE8[];
extern const char D_002E4F30[];
extern char D_002B8F68[];
extern "C" void func_002342C8(const char *);
extern "C" s32 func_00264460(void);
extern "C" s32 func_002647F0(s32);
extern "C" s32 func_0023F0A8(const char *);
extern "C" void func_00275748(s32);
extern "C" void func_00279EF0(void);
extern "C" s32 func_00263BA0(s32);
extern "C" void func_00277100(void);
extern "C" s32 func_0023ED90(const char *, char *);
extern "C" s32 func_00273600(void);
extern "C" void func_00272658(void);
extern "C" void func_00271C80(void);
extern "C" void func_00272988(void);
extern "C" void func_002721B8(void);
extern "C" void func_0026E898(void);
extern "C" void func_0026FE58(s32);
extern "C" void func_001F0910(void);
extern "C" void func_00236218(void);
extern "C" s32 func_0028B570(const void *, const char *, u32);
extern "C" s32 func_00234360(void);
extern "C" char *func_00234108(const char *) throw();  // nothrow in retail (same TU?)
extern "C" void func_002343A8(const char *);
inline void StrAdd(char *d, const char *s) { strcpy(d + strlen(d), s); }

extern s32 D_002B8D58;
extern s32 D_002B8D64;
extern s32 D_002B8D68;
extern s32 D_002B8D4C;
extern s32 D_002B8D40;
extern s32 D_002B8D44;
extern s32 D_002B8D48;
extern s32 D_002B8D50;
extern s32 D_002B8D00;
extern char D_002B8D30[];
extern char D_002B8DF0[];
extern char D_002B8E70[];
extern char D_002B8D70[];
extern char D_36D9C0[];
extern char D_36D540[];
extern u8 D_36F9C0[];
extern const char D_002E4FB0[];
extern const char D_002E4FD8[];
extern const char D_002E4FF8[];
extern const char D_002E5010[];
extern const char D_002E5018[];
extern const char D_002E5058[];
extern const char D_002E5080[];
struct SifCli { u8 pad[0x24]; void *serve; };
struct SemaP { s32 count; s32 max; s32 init; s32 wait; u32 attr; u32 opt; };
extern "C" char *func_00234F40(const char *, const char *);
extern "C" s32 func_002353E0(char *);
extern "C" s32 func_002354A8(char *, char *, s32);
extern "C" s32 func_00235260(char *, const char *, const char *, const char *);
extern "C" s32 func_002355A8(const char *, const char *);
extern "C" s32 func_002355E0(char *, const char *, const char *, s32);
extern "C" s32 func_00275EE0(void *, u32, s32);
extern "C" void func_00273420(s32);
extern "C" void func_002760B0(void *, s32, s32, void *, s32, void *, s32, void *, void *);
extern "C" s32 func_002762A8(void *);
extern "C" s32 func_002363B0(const char *, s32);
extern "C" s32 func_00236400(s32);
extern "C" void func_00235FE0(void);
extern "C" void func_0022DAE0(void);
extern "C" void func_00239338(void);
extern "C" void func_00236258(void);
extern "C" void func_001F0938(void);
extern "C" void func_00236898(void);
extern "C" s32 func_002359D8(void);
extern "C" s32 func_002731A0(SemaP *);
extern "C" s32 func_002731B0(s32);
struct RpcW { s32 sema; u8 pad[0x3C]; SifCli cd; };
extern "C" s32 func_00235FE8(s32, s32);
#define SIF_WAIT(j) do { j = 9999; do { j -= 25; asm volatile("nop"); asm volatile("nop"); asm volatile("nop"); asm volatile("nop"); asm volatile("nop"); } while (j >= 0); } while (0)

extern "C" char *func_00233F88(const char *);
extern "C" s32 func_00233EC8(const char *);
extern "C" char *func_00233F48(const char *);
static inline int IsEol(char c) { return c == '\r' || c == '\n'; }
static inline int IsBlank(char c) { return c == ' ' || c == '\t'; }
extern "C" const char *func_00235058(char *dst, const char *src);

extern const char D_002E4E80[], D_002E4E90[], D_002E4E98[], D_002E4EA0[], D_002E4EB0[], D_002E4EB8[];
extern const char D_002E4EC8[], D_002E4ED0[], D_002E4EE0[], D_002E4EE8[], D_002E4EF8[], D_002E4F08[];
extern const char D_002E4F18[], D_002E4F20[];
extern const char *D_002B8F00[], *D_002B8F10[], *D_002B8F20[], *D_002B8F40[];
extern "C" s32 func_00235648(char *out, const char *a, const char *b);
extern "C" s32 func_002349C8(const char *s, const char **tbl);

extern "C" void func_00233FC8(char *, const char *, s32);
extern "C" s32 func_00234248(const char *);
extern "C" s32 func_00233F08(const char *);
extern "C" void func_00234008(char *, const char *, s32);
extern "C" s32 func_00234278(const char *);
extern "C" const char *func_002341C0(const char *);
extern "C" s32 func_0023EEE8(const char *, s32, const char *);
extern const char D_002E4D90[], D_002E4D98[], D_002E4DA0[];
extern "C" void func_0022DC90(const char *dir);
extern "C" s32 func_00234070(const char *);
extern "C" void func_00289240(s32) __attribute__((noreturn));
extern s32 D_002B8EFC;
extern const char *D_002B9070[], *D_002B9088[], *D_002B90A0[];
extern const char D_002E4DF8[], D_002E4E10[], D_002E4E20[], D_002E4E40[], D_002E4E48[], D_002E4C80[], D_002E4CC0[], D_002E4E68[];
// @decl-end

extern "C" void func_00234318(const char **p) {
    for (; *p; p++) func_002342C8(*p);
}

extern "C" s32 func_00234360(void) {
    s32 r = func_00264460();
    if (r == 0x14 || r == 0xFE) return func_002647F0(2);
    return func_002647F0(1);
}

extern "C" void func_002343A8(const char *s) {
    if (D_002B8D54 == 1) {
        Func235DE0(D_002E4D00, s);
        func_00234360();
        while (!func_0023F0A8(s));
        func_00275748(0);
        func_00279EF0();
        while (!func_00263BA0(0));
        func_00234360();
        func_00277100();
        D_002B8D5C = 1;
    } else {
        return (void)Func235DE0(D_002E4D78, s);
    }
}

extern "C" s32 func_00234460(const char *s) {
    char name[0x100];
    char args[0x400];
    char line[0x200];
    while (*s) {
        s32 n;
        s = func_00233F88(s);
        n = func_00233EC8(s);
        func_00233FC8(line, s, n);
        s = func_00233F48(s + n);
        if (func_00234248(line)) continue;
        {
            const char *p = line;
            s32 k = 0;
            char *a;
            const char *ext;
            name[0] = 0;
            args[0] = 0;
            n = func_00233F08(p);
            func_00234008(name, p, n);
            p = func_00233F88(p + n);
            while (*p) {
                n = func_00233F08(p);
                func_00233FC8(args + k, p, n);
                k = k + n + 1;
                p = func_00233F88(p + n);
            }
            a = k > 0 ? args : 0;
            if (func_00234278(name)) continue;
            ext = func_002341C0(name);
            if (!strcmp(D_002E4D90, ext)) {
                func_002342C8(func_00234108(name));
                while (!func_0023EEE8(name, k, a));
            } else if (strcmp(D_002E4D98, ext)) {
                Func235DE0(D_002E4DA0, name);
            }
        }
    }
    return 1;
}

extern "C" s32 func_00234638(char *out, const char *path) {
    char tmp[256];
    s32 n;
    if (D_002B8D5C == 0) {
        strcpy(tmp, path);
        StrAdd(tmp, D_002B8F68);
        func_002343A8(tmp);
    }
    n = func_0023ED90(D_002E4DB8, out);
    if (n > 0) {
        out[n] = 0;
        return 1;
    }
    return 0;
}

extern "C" void func_002346C0(s32 x) {
    s32 b = x != 0;
    Func235DE0(D_002E4DC8, b);
    while (!func_00263BA0(b));
    Func235DE0(D_002E4DE8);
    D_36D980[1] = 1;
}

extern "C" void func_00234718(void) {
    char *buf = D_36D9C0;
    D_002B8D5C = 0;
    D_002B8EFC = 0;
    func_00234318(D_002B9070);
    if (D_002B8D70[0]) {
        func_00234318(D_002B9088);
        if (D_002B8D70[0] == 'a') func_00234318(D_002B90A0);
    }
    func_00275748(0);
    ((s32 (*)(void))func_00279EF0)();
    if (D_002B8D54 == 1) func_002346C0(0);
    Func235DE0(D_002E4DF8);
    func_0022DC90(0);
    if (D_002B8D54 == 1) {
        while (!func_00234638(buf, D_002E4E10));
        while (!func_00234460(buf));
    } else if (!func_00234638(buf, D_002E4E10) || !func_00234460(buf)) {
        func_0022DC90(D_002E4E20);
        if (!func_00234638(buf, D_002E4E40) || !func_00234460(buf)) {
            func_0022DC90(0);
            Func235DE0(D_002E4E48);
            func_00289240(1);
        }
    }
    func_0022DC90(0);
    if (D_002B8D54 != 1 && func_00234070(D_002E4C80)) func_002346C0(1);
    if (func_00234070(D_002E4CC0)) D_36D980[2] = 1;
    return (void)Func235DE0(D_002E4E68);
}

extern "C" void func_002348F8(s32 i, s32 v) {
    D_36D980[i] = v;
}

extern "C" s32 func_00234910(s32 i) {
    if (i < 0) i = D_002B8D54;
    return D_36D980[i];
}

extern "C" s32 func_00234938(void) {
    return D_002B8D54;
}

extern "C" void func_00234948(void) {
    if (D_002B8D54 >= 0) {
        D_36D980[D_002B8D54] = 1;
        return;
    }
    if (func_00273600() <= 0x2000000) {
        D_002B8D54 = 1;
        D_36D980[1] = 1;
    } else {
        D_36D980[0] = 1;
        D_002B8D54 = 0;
    }
}

extern "C" s32 func_002349C8(const char *s, const char **tbl) {
    s32 i = 0;
    while (*tbl) {
        if (!strcmp(s, *tbl)) return i;
        tbl++;
        i++;
    }
    return -1;
}

extern "C" void func_00234A38(void) {
    char buf[32];
    s32 n, i;
    D_002B8D58 = 0;
    n = func_0023ED90(D_002E4E80, D_36D9C0);
    if (n <= 0) return;
    D_002B8D58 = 1;
    D_36D9C0[n] = 0;
    if (func_00235648(D_002B8D30, D_002E4E90, D_002E4E98)) Func235DE0(D_002E4EA0, D_002B8D30);
    if (func_00235648(buf, D_002E4E90, D_002E4EB0)) {
        D_002B8D40 = atoi(buf);
        Func235DE0(D_002E4EB8, D_002B8D40);
    }
    if (func_00235648(buf, D_002E4E90, D_002E4EC8) && (i = func_002349C8(buf, D_002B8F00)) >= 0) {
        D_002B8D4C = i;
        Func235DE0(D_002E4ED0, D_002B8F00[i]);
    }
    if (func_00235648(buf, D_002E4E90, D_002E4EE0) && (i = func_002349C8(buf, D_002B8F10)) >= 0) {
        D_002B8D44 = i;
        Func235DE0(D_002E4EE8, D_002B8F10[i]);
    }
    if (func_00235648(buf, D_002E4E90, D_002E4EF8) && (i = func_002349C8(buf, D_002B8F20)) >= 0) {
        D_002B8D48 = i;
        Func235DE0(D_002E4F08, D_002B8F20[i]);
    }
    if (func_00235648(buf, D_002E4E90, D_002E4F18) && (i = func_002349C8(buf, D_002B8F40)) >= 0) {
        D_002B8D50 = i;
        Func235DE0(D_002E4F20, D_002B8F40[i]);
    }
}

extern "C" void func_00234C78(void) {
    if (D_002B90A8) return;
    D_002B90A8 = 1;
    func_00272658();
    func_00271C80();
    func_00272988();
    func_002721B8();
    func_0026E898();
    func_0026FE58(1);
    func_001F0910();
    return (void)func_00236218();
}

extern "C" void func_00234CE8(void) {
    if (func_0028B570((void *)0x1FC00108, D_002E4F30, strlen(D_002E4F30)) == 0)
        D_002B8D60 = *(s32 *)0x1FC00100;
}

INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4C80);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4C90);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4CA0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4CB0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4CC0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4CD0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4CE0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4CF0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4D00);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4D78);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4D90);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4D98);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4DA0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4DB8);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4DC8);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4DE8);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4DF8);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4E10);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4E20);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4E40);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4E48);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4E68);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4E80);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4E90);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4E98);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4EA0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4EB0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4EB8);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4EC8);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4ED0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4EE0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4EE8);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4EF8);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4F08);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4F18);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4F20);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4F30);
INCLUDE_ASM("asm/nonmatchings/Unit234318", func_00234D40);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4FB0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4FD8);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E4FF8);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E5010);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E5018);

INCLUDE_ASM("asm/nonmatchings/Unit234318", func_00234F40);

INCLUDE_ASM("asm/nonmatchings/Unit234318", func_00235058);

extern "C" char *func_00235120(char *p, const char *name) {
    char buf[256];
    s32 n = strlen(name);
    s32 i;
    while (*(p = func_00233F88(p)) && *p != '[') {
        if (*p != '#' && !IsEol(*p)) {
            p = (char *)func_00235058(buf, p);
            if (strlen(buf) == n) {
                for (i = 0; i < n; i++) if (buf[i] != name[i]) break;
                if (i == n) return func_00233F88(func_00233F88(p) + 1);
            }
        }
        p = func_00233F48(p + func_00233EC8(p));
    }
    return 0;
}

extern "C" s32 func_00235260(char *out, const char *a, const char *b, const char *name) {
    s32 n;
    char *p;
    *out = 0;
    p = func_00234F40(a, b);
    if (!p) return 0;
    p = func_00235120(p, name);
    if (!p) return 0;
    for (n = 0; *p && !IsEol(*p); out++, p++, n++) {
        if (*p == '\\' && IsEol(p[1])) {
        again:
            p = func_00233F48(p + 1);
            if (*p == '#') {
                while (*p && !IsEol(*p)) p++;
                if (!*p) goto end;
                goto again;
            }
            if (*p != ' ' && *p != '\t') goto end;
        }
        *out = *p;
    }
end:
    *out = 0;
    return n;
}

extern "C" s32 func_002353E0(char *p) {
    s32 n = 0;
    while (*(p = func_00233F88(p)) && *p != '[') {
        if (*p != '#' && !IsEol(*p)) n++;
        p = func_00233F48(p + func_00233EC8(p));
    }
    return n;
}

extern "C" s32 func_002354A8(char *out, char *s, s32 idx) {
    s32 i = 0;
    s32 eol;
    *out = 0;
    while (s = func_00233F88(s), eol = 0, *s != 0 && *s != '[') {
        if (*s != '#') {
            if (*s == '\r' || *s == '\n') eol = 1;
            if (!eol) {
                if (i == idx) {
                    func_00235058(out, s);
                    return strlen(out);
                }
                i++;
            }
        }
        s = func_00233F48(s + func_00233EC8(s));
    }
    return 0;
}

extern "C" s32 func_002355A8(const char *a, const char *b) {
    char *p = func_00234F40(a, b);
    if (p) return func_002353E0(p);
    return 0;
}

extern "C" s32 func_002355E0(char *out, const char *a, const char *b, s32 n) {
    char *p = func_00234F40(a, b);
    if (p) return func_002354A8(out, p, n);
    return 0;
}

extern "C" s32 func_00235648(char *out, const char *a, const char *b) {
    if (!D_002B8D58) return 0;
    return func_00235260(out, D_36D9C0, a, b);
}

extern "C" s32 func_00235690(const char *a) {
    if (!D_002B8D58) return 0;
    return func_002355A8(D_36D9C0, a);
}

extern "C" s32 func_002356D0(char *out, const char *a, s32 n) {
    if (!D_002B8D58) return 0;
    return func_002355E0(out, D_36D9C0, a, n);
}

extern "C" s32 func_00235718(SifCli *cd, u32 id) {
    s32 i, j;
    Func235DE0(D_002E4FB0);
    for (i = 0; i < 10; i++) {
        cd->serve = 0;
        if (func_00275EE0(cd, id, 0) < 0) break;
        SIF_WAIT(j);
        if (cd->serve) break;
    }
    func_00273420(0);
    if (cd->serve) {
        Func235DE0(D_002E4FD8);
        return 1;
    }
    Func235DE0(D_002E4FF8);
    return 0;
}

extern "C" void func_002357F0(void) {
    func_00275748(0);
    if (func_00235718((SifCli *)D_36F9C0, 0x80000220)) D_002B8D68 = 1;
}

extern "C" void func_00235830(void *a, s32 b) {
    func_002760B0(D_36F9C0, 0x10, 1, a, b, 0, 0, 0, 0);
    while (func_002762A8(D_36F9C0));
}

extern "C" void func_00235888(void) {
    char buf[128];
    if (D_002B8D70[0]) {
        func_002357F0();
        if (D_002B8D68 == 0) {
            strcpy(buf, D_002B8D70);
            StrAdd(buf, D_002E5010);
            D_002B8D64 = func_002363B0(buf, 2);
        }
    }
}

extern "C" void func_00235908(void) {
    if (D_002B8D64 >= 0) {
        func_00236400(D_002B8D64);
        D_002B8D64 = -1;
    }
    D_002B8D68 = 0;
}

extern "C" void func_00235950(void) {
    func_00235908();
    func_00235FE0();
    func_0022DAE0();
    func_00239338();
    func_00236258();
    func_001F0938();
    return (void)func_00236898();
}

extern "C" s32 func_00235998(void) {
    return D_002B8D5C;
}

extern "C" char *func_002359A8(const char *s) {
    return strcpy(D_002B8F68, s);
}

extern "C" s32 func_002359C8(void) {
    return 1;
}

extern "C" s32 func_002359D0(void) {
    return 0x118;
}

extern "C" s32 func_002359D8(void) {
    return D_002B8D4C;
}

extern "C" s32 func_002359E8(void) {
    return func_002359D8() == 0 ? 60 : 50;
}

extern "C" char *func_00235A18(void) {
    return D_002B8D30;
}

extern "C" s32 func_00235A28(void) {
    return D_002B8D40;
}

extern "C" s32 func_00235A38(void) {
    return D_002B8D44;
}

extern "C" s32 func_00235A48(void) {
    return D_002B8D48;
}

extern "C" s32 func_00235A58(void) {
    return D_002B8D50;
}

extern "C" char *func_00235A68(void) {
    return D_002B8DF0;
}

extern "C" char *func_00235A78(void) {
    return D_002B8E70;
}

extern "C" s32 func_00235A88(void) {
    return func_00273600();
}

extern "C" s32 func_00235AA0(const char *s) {
    s32 n = strlen(s), r;
    if (!func_0028B570(s, D_002E5018, 7)) return 1;
    r = 0;
    if (n >= 3 && s[n - 1] == '1') r = s[n - 2] == ';';
    return r;
}

extern "C" char *func_00235B28(const char *s) {
    const char *p;
    if (s[1] == ':') return func_00234108(s);
    if (!D_002B8D54) {
        for (p = s; *p; p++) {
            if (*p == ',') return (char *)p + 1;
        }
    }
    for (p = s; *p; p++) {
        if (*p == ':') return (char *)p + 1;
    }
    return (char *)s;
}

INCLUDE_ASM("asm/nonmatchings/Unit234318", func_00235BF0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E5058);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E5080);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E50A0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E50B0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E50C0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E50D0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E50E0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E50F0);
INCLUDE_RODATA("asm/nonmatchings/Unit234318", D_002E5100);

extern "C" char *func_00235D80(void) {
    return D_36D540;
}

extern "C" s32 func_00235D90(s32 v) {
    s32 old = D_002B8D00;
    D_002B8D00 = v;
    return old;
}

extern "C" s32 func_00235DA8(void) {
    return 1;
}

extern "C" s32 func_00235DB0(void) {
    return D_002B8D68 != 0 || D_002B8D64 >= 0;
}

INCLUDE_ASM("asm/nonmatchings/Unit234318", Func235DE0__FPCce);

extern "C" void func_00235FD8(void) {
}

extern "C" void func_00235FE0(void) {
}

extern "C" s32 func_00235FE8(s32 max, s32 init) {
    SemaP p;
    p.max = max;
    p.init = init;
    return func_002731A0(&p);
}

extern "C" s32 func_00236010(RpcW *w, u32 id) {
    s32 j;
    w->sema = func_00235FE8(1, 1);
    Func235DE0(D_002E5058, id);
    for (;;) {
        if (func_00275EE0(&w->cd, id, 0) < 0) {
            Func235DE0(D_002E5080, id);
            return 0;
        }
        SIF_WAIT(j);
        if (w->cd.serve) break;
    }
    func_00273420(0);
    Func235DE0(D_002E4FD8);
    return 1;
}

extern "C" void func_002360F0(s32 *p) {
    if (*p >= 0) {
        func_002731B0(*p);
        *p = -1;
    }
}
