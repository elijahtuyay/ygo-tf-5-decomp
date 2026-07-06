/*
 * rel_movie_viewer.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,p -sdatathreshold 0
 * Verification: decomp.me — every function below is confirmed 100% (score 0).
 *
 * Conventions (see docs/09-first-match.md):
 *  - global game-state variables are `volatile` and are accessed via a local
 *    pointer to reproduce the original codegen (value reload, use of $s0);
 *  - names `func_XXXXXXXX` / `D_XXXXXXXX` = placeholders (address), to be renamed
 *    as their purpose becomes clear.
 *
 */

extern volatile int D_0009DB00;
extern void func_00000CEC(int);

/* func_00000184 — "release-and-clear" cleanup of a global handle.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,p -sdatathreshold 0). */
void func_00000184(void) {
    volatile int *p = &D_0009DB00;
    if (*p != 0) {
        func_00000CEC(*p);
        *p = 0;
    }
}
