#ifndef HYBRID_ASM_H
#define HYBRID_ASM_H

/* INCLUDE_ASM for the hybrid C+assembly build (scripts/make_hybrid.py).
 *
 * tools/mwccgap compiles the C file AS-IS first and expects every INCLUDE_ASM'd
 * function to be ABSENT from the resulting object; it then assembles the .s
 * separately and transplants the bytes in, fixing symbols and relocations.
 *
 * So this macro must (a) parse under mwcc and (b) NOT define the function.
 * It cannot be the GCC-style __asm__(".include ...") used by
 * include/include_asm.h — mwcc rejects that outright with "')' expected",
 * which is why that header has never worked with the real compiler and why
 * mwccgap exists at all.
 *
 * It must also (c) NOT DECLARE THE FUNCTION EITHER. This was originally
 * `extern int NAME()`, which broke every module whose src/<module>.c already
 * forward-declares the function it is splicing in:
 *
 *     identifier 'func_00000294()' redeclared
 *     was declared as: 'void ()'   now declared as: 'int (...)'
 *
 * Deleting the existing prototype instead would be the wrong repair — a
 * prototype with real argument types governs argument promotion at every call
 * site, so dropping it can silently change the codegen of functions that
 * currently match. Declaring an unrelated dummy object sidesteps the collision
 * without touching the declarations the module already relies on. It is never
 * defined and never referenced, so it contributes no symbol to the object,
 * which is what mwccgap's first pass requires. */
#define INCLUDE_ASM(FOLDER, NAME) extern int __include_asm_##NAME
#define INCLUDE_RODATA(FOLDER, NAME) extern int __include_rodata_##NAME

#endif /* HYBRID_ASM_H */
