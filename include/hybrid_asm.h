#ifndef HYBRID_ASM_H
#define HYBRID_ASM_H

/* INCLUDE_ASM for the hybrid C+assembly build (scripts/make_hybrid.py).
 *
 * tools/mwccgap compiles the C file AS-IS first and expects every INCLUDE_ASM'd
 * function to be ABSENT from the resulting object; it then assembles the .s
 * separately and transplants the bytes in, fixing symbols and relocations.
 *
 * So this macro must (a) parse under mwcc and (b) NOT define the function.
 * A bare extern declaration does both. It cannot be the GCC-style
 * __asm__(".include ...") used by include/include_asm.h — mwcc rejects that
 * outright with "')' expected", which is why that header has never worked
 * with the real compiler and why mwccgap exists at all. */
#define INCLUDE_ASM(FOLDER, NAME) extern int NAME()
#define INCLUDE_RODATA(FOLDER, NAME) extern int NAME()

#endif /* HYBRID_ASM_H */
