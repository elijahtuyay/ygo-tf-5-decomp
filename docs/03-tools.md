# 03 — Tools and installation

Guide to installing the toolchain on Ubuntu/Linux. Most of it is already automated
by `scripts/setup_tools.sh`; here are the details of what's needed and why.

## Status on this machine (verified)

| Tool | Status | Notes |
|---|---|---|
| 7-Zip (`7z`) | ✅ installed | ISO extraction |
| Python 3.12 + venv | ✅ | for splat/m2c |
| splat64 `[mips]` | ✅ installed in `.venv` | `psp` platform present |
| spimdisasm 1.42.2 | ✅ | splat dependency |
| rabbitizer 1.16.2 | ✅ | `R4000ALLEGREX` category (VFPU included) |
| asm-differ / m2c / decomp-permuter | ✅ cloned in `tools/` | — |
| pspdecrypt | ✅ **compiled** and working | EBOOT already decrypted (see below) |
| cmake / ninja / make / gcc / java | ✅ | generic build tools |
| Ghidra **12.0** | ❌ needs to be installed | ⚠️ **not** 12.1.x — see below |
| ghidra-allegrex v21.3 | ❌ needs to be installed | extension for Ghidra 12.0.x |
| PPSSPP | ❌ optional | emulator/RE (EBOOT already decrypted without it) |
| pspdev (psp-gcc, prxtool) | ❌ optional | see below |
| wibo | ❌ needs to be installed | to run mwccpsp on Linux |

## 1. Automatic setup (Python + git tools)

```bash
scripts/setup_tools.sh
```

Creates `.venv`, installs `requirements.txt` (splat/spimdisasm/rabbitizer + utilities)
and clones `asm-differ`, `m2c`, `decomp-permuter`, `pspdecrypt` into `tools/`.
Idempotent.

## 2. System dependencies (require `sudo`)

On this machine `sudo` prompts for a password, so these must be run manually. In the
Claude Code prompt you can run them with the `!` prefix:

```bash
sudo apt update
sudo apt install -y p7zip-full build-essential libssl-dev git python3-venv \
                    cmake ninja-build
```

`libssl-dev` is needed **only** to compile pspdecrypt (it uses OpenSSL's SHA
functions).

## 3. pspdecrypt (decrypting the EBOOT)

After installing `libssl-dev`:

```bash
make -C tools/pspdecrypt
```

Used via `scripts/decrypt_eboot.sh`. Repo: https://github.com/John-K/pspdecrypt
Alternative with nothing to compile: dump from PPSSPP (see
`04-extraction-and-decryption.md`).

## 4. Ghidra + ghidra-allegrex (main static analysis)

Ghidra is the main disassembler/decompiler. Requires **JDK 21**. Android Studio's
`java` (JBR) can work, but it's cleaner to install a dedicated JDK:

```bash
sudo apt install -y openjdk-21-jdk
```

> ⚠️ **Critical version note**: the ghidra-allegrex v21.3 extension is built for
> **Ghidra 12.0.x** (it provides zips for 12.0, 12.0.1 … 12.0.4). Do **NOT** use the
> more recent Ghidra 12.1.x: the extension would fail to load. Install **Ghidra
> 12.0**.

```bash
# 1) Ghidra 12.0 (official NSA release) — verified asset
cd ~ && wget https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_12.0_build/ghidra_12.0_PUBLIC_20251205.zip
unzip ghidra_12.0_PUBLIC_20251205.zip        # creates ~/ghidra_12.0_PUBLIC
# launch (convenient: use the project script, which also sets JDK 21):
#   scripts/run_ghidra.sh
# or directly:
~/ghidra_12.0_PUBLIC/ghidraRun
```

**ghidra-allegrex** (kotcrab) adds the Allegrex processor: PSP relocations
(`PT_SCE_PSPREL`/`PSPREL2`), Allegrex instructions, **VFPU disassembly/decompilation**,
import/export of PPSSPP's `.sym` symbols, automatic PSP ELF detection.

```bash
# 2) ghidra-allegrex extension for Ghidra 12.0 (zip matching the version)
cd ~ && wget https://github.com/kotcrab/ghidra-allegrex/releases/download/v21.3/ghidra_12.0_PUBLIC_20260310_ghidra-allegrex.zip
# then inside Ghidra:
#   File ▸ Install Extensions ▸ (+) ▸ select the downloaded zip ▸ OK ▸ restart Ghidra
```

Repo: https://github.com/kotcrab/ghidra-allegrex — if you update Ghidra, download the
extension zip with the matching version number.

Useful companion scripts: https://github.com/pspdev/psp-ghidra-scripts (import/export
fixes) and the PSP RE HQ NID workflow (see `05-ghidra.md`).

## 5. PPSSPP (emulator as an RE tool)

Useful for: built-in disassembler/debugger, memory viewer, GE debugger (graphics),
exporting `.sym` symbols. **No longer needed to decrypt the EBOOT** (already done
with pspdecrypt), so it's optional.

Recommended method on Zorin/Ubuntu — **Flatpak** (Zorin already has flatpak+Flathub):

```bash
flatpak install -y flathub org.ppsspp.PPSSPP
flatpak run org.ppsspp.PPSSPP
```

If flatpak isn't set up yet:

```bash
sudo apt install -y flatpak
flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
```

(There is no reliable official `apt` PPA.) Website/AppImage:
https://www.ppsspp.org/download/ — Repo: https://github.com/hrydgard/ppsspp

## 6. wibo (for building the match with mwccpsp)

`mwccpsp.exe` is a Windows binary: **wibo** (decompals) runs it on Linux without
WINE, as is standard practice in decomp projects (sotn-decomp uses it for the PSP
target).

```
Repo: https://github.com/decompals/wibo   (build with cmake; then:  wibo mwccpsp.exe ...)
```

The `mwccpsp` compiler itself is not redistributable here: it is obtained from
decomp.me (PSP scratch) or from the images at
https://github.com/decompme/compilers (`platforms/psp/`). See
`06-splitting-and-matching.md` for the build question.

## 7. pspdev toolchain (optional but convenient)

The Sony/pspdev homebrew toolchain provides `psp-gcc`, `psp-objdump`,
`psp-readelf`, `prxtool`, `psp-prxgen`, and the `sce*` headers. **Not** needed for
the match (the game is MWCC, not GCC), but useful for inspecting ELF/PRX files and
understanding the SDK.

```
Repo:  https://github.com/pspdev/pspdev   (installer: ./pspdev.sh, or precompiled
       releases; sets $PSPDEV and $PATH)
prxtool (standalone): dump PRX↔ELF, NID resolution, disassembly.
```

## 8. objdiff (alternative/complement to asm-differ)

[objdiff](https://github.com/encounter/objdiff) (Rust) does local object-level
diffing, supports **MIPS PSP** and **CodeWarrior** demangling, and powers the
decomp.dev dashboard. More convenient than asm-differ for projects with many
objects; configured via an `objdiff.json`. Installation: precompiled binaries from
the repo's releases.

## Minimal command summary to get started

```bash
# 1. system dependencies (once)
sudo apt install -y p7zip-full build-essential libssl-dev python3-venv cmake ninja-build

# 2. project toolchain
scripts/setup_tools.sh
make -C tools/pspdecrypt          # after libssl-dev

# 3. extract + (opt.) decrypt
scripts/extract_iso.sh "Yu-Gi-Oh 5D's Tag Force 5 (E)(M5)(ZER0)/0-ygotf5.iso"
scripts/decrypt_eboot.sh

# 4. Ghidra + ghidra-allegrex and PPSSPP: manual installation (sec. 4–5)
```
