#ifndef LINKONCE_H
#define LINKONCE_H

/* Linkonce code at the end of .text (0x296540-0x29F230): inline members, template code and
 * typeinfo functions the game compiler emitted per class. Written as C functions on raw offsets
 * under their existing names; the classes themselves live in their own units. */

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* __ti<class> (.bss): filled once by the typeinfo function */
struct TypeInfo {
    void *vptr;
    const char *name;
};

/* vtable entry {delta, index, pfn} (docs/units.md) */
struct VtEnt {
    s16 delta;
    s16 index;
    void (*pfn)(void *, s32);
};

extern "C" {
void __builtin_delete(void *);
void func_00286BC0(TypeInfo *ti, const char *name, TypeInfo *base); /* __rtti_si */
void func_00286BE0(TypeInfo *ti, const char *name);                 /* __rtti_user */
}

#endif
