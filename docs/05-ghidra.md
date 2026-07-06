# 05 — Static Analysis with Ghidra + ghidra-allegrex

Ghidra (with the Allegrex extension) is the primary tool for understanding the code:
it disassembles, decompiles to pseudo-C, lets you name functions/data, and lets you
navigate calls. It's complementary to splat: Ghidra for **understanding**, splat for
**producing the asm to match**.

Quick start (finds Ghidra, sets JDK 21, warns if the Allegrex extension is missing,
launches in the background):

```bash
scripts/run_ghidra.sh              # opens Ghidra
scripts/run_ghidra.sh progetto.gpr # opens a specific project
```

## Why ghidra-allegrex is needed

"Vanilla" Ghidra has the MIPS processor but doesn't know about PSP specifics. The
[**ghidra-allegrex**](https://github.com/kotcrab/ghidra-allegrex) extension (kotcrab)
adds:

- PSP relocations: `PT_SCE_PSPREL` (`0x700000A0`) and `PT_SCE_PSPREL2` (compressed);
- rebasing the image after load;
- custom **Allegrex** instructions and **VFPU disassembly/decompilation** (COP2:
  128 registers, 8 4x4 matrices, `vmmul`, `vdot`, `vsin`, prefixes/swizzle…);
- automatic recognition of the PSP ELF and the PSP calling convention;
- import/export of **PPSSPP** `.sym` symbols (a bridge with dynamic debugging).

> Known limitations (from PSP RE HQ): VFPU support isn't fully complete, and
> 64-bit return values/arguments spanning multiple registers aren't always
> handled well.

Installation: see `03-tools.md` §4.

## What to load

- **`rel_*.prx` modules**: can be loaded directly (they are plaintext Allegrex ELFs).
  The header has `e_type = 0xFFA0` (verified: Ghidra/readelf show it as
  "Processor Specific: (ffa0)").
- **`modehsys`** (the engine): first requires the decrypted ELF `build/EBOOT.elf`
  (see `04-extraction-and-decryption.md`), then it loads like the others.

Load address: conventionally `0x08804000` for the main user module; the `rel_*`
modules are relocatable (vram 0) and loaded dynamically by the engine — Ghidra
applies the `.rel.text` relocations.

## Resolving imports: the NIDs

The PSP doesn't import SDK functions by name but by **NID** = the first 4 bytes of
`SHA-1(function_name)`, in little-endian. In the PRX:

- `.lib.stub` lists the imported modules (e.g. `sceGu`, `sceIo`, `sceCtrl`) and
  points to…
- `.rodata.sceNid`, the table of required NIDs;
- `.sceStub.text` contains the stubs (`jr $ra`/`nop`) patched at load time.

Without translating the NIDs into names, the decompiled output is unreadable.
Sources/tools:

- **uofw/uofw** — https://github.com/uofw/uofw — a clean-room reimplementation of
  the PSP firmware: it's the standard public source of NIDs **with names and typed
  signatures**.
- **NID script** (PSP RE HQ): a `SonyPSPResolveNIDs.py` maps the NIDs and loads the
  Ghidra type archives `PSPSDK.gdt` (for games) or `uOFW.gdt` (for kernel modules).
  Quickstart: https://psp-re.github.io/quickstart/
- **psp-ghidra-scripts** — https://github.com/pspdev/psp-ghidra-scripts — import/export
  fixes.
- **prxtool** (pspdev) also resolves NIDs from the command line.

Typical flow when opening a module:

1. Ghidra auto-analysis (with ghidra-allegrex active).
2. Run the NID resolution script → the stubs get their `sce*` names.
3. Apply the type archives (`PSPSDK.gdt`) → correct SDK function signatures.
4. From here, navigate `module_start` and the exported functions in `.lib.ent`.

## Bridge with PPSSPP (dynamic analysis)

PPSSPP has a built-in disassembler, debugger, memory viewer, and GE debugger. Useful for:

- confirming at runtime what a function does (breakpoints, memory watches);
- getting real addresses of data structures;
- exporting `.sym` symbols and importing them into Ghidra (and vice versa) with
  the ghidra-allegrex scripts.

The known CWCheats for TF5 (see `08-resources.md`) already give "hot" addresses to
start from: e.g. the US pair `0x80338CD4/0x80338CD2` (All Cards / No Card Bans)
points to a **card legality check** function, a concrete starting point.

## Naming convention (stay consistent with splat)

When naming functions/data in Ghidra, use names that you'll later carry over into
splat's symbol files (`config/symbols.*.txt`), so the generated asm and the
decompiled code speak the same language. Example scheme from mature projects
(sotn-decomp):

```
config/symbols.<module>.txt     # address = name
config/symexport.<module>.txt   # exported symbols
```

## References

- ghidra-allegrex: https://github.com/kotcrab/ghidra-allegrex
- PSP RE HQ quickstart: https://psp-re.github.io/quickstart/
- uofw (NIDs/signatures): https://github.com/uofw/uofw — tutorial:
  https://github.com/uofw/uofw/wiki/Reverse-Engineering-Tutorial
- PRX format: https://www.psdevwiki.com/psp/PRX_File_Format
- VFPU: https://pspdev.github.io/vfpu-docs/
