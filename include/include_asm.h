#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

/*
 * INCLUDE_ASM pulls a not-yet-decompiled function's assembly (from splat, numeric
 * registers) into the unit at its original place. The unit is assembled by ee-gcc's
 * own GNU as 2.10-ee, as in the original build; that assembler only knows numeric
 * register names, hence named_regs_for_c_funcs: False in the splat yaml.
 */
#ifndef PERMUTER
#define INCLUDE_ASM(FOLDER, NAME)                                                 \
    __asm__(".section .text\n"                                                    \
            "\t.set noat\n"                                                       \
            "\t.set noreorder\n"                                                  \
            "\t.include \"" FOLDER "/" #NAME ".s\"\n"                             \
            "\t.set reorder\n"                                                    \
            "\t.set at\n")
__asm__(".include \"macro.inc\"\n");
#else
#define INCLUDE_ASM(FOLDER, NAME)
#endif

#endif
