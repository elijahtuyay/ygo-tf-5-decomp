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
| Ghidra **12.0** | ✅ installed | ⚠️ **not** 12.1.x — see below |
| ghidra-allegrex v21.3 | ✅ installed | extension for Ghidra 12.0.x |
| PPSSPP | ❌ optional | emulator/RE (EBOOT already decrypted without it) |
| pspdev (psp-gcc, prxtool) | ❌ optional | see below |
| wibo | ✅ **fetched by `setup_tools.sh`** | prebuilt release binary in `tools/wibo-bin/` |
| mwccpsp_3.0.1_219 | ✅ **fetched by `setup_tools.sh`** | real compiler, from decompme/compilers releases |
| binutils-mips-linux-gnu | ❌ needs `sudo apt install` | MIPS-aware `objdump`, needed for local matching (§9) |

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

## 6. wibo + mwccpsp (for building the match locally)

`mwccpsp.exe` is a Windows binary: **wibo** (decompals) runs it on Linux without
WINE, as is standard practice in decomp projects (sotn-decomp uses it for the PSP
target). **Both are fetched automatically by `scripts/setup_tools.sh`**:

```
tools/wibo-bin/wibo                    # prebuilt release binary (decompals/wibo, x86_64)
tools/mwccpsp_3.0.1_219/mwccpsp.exe    # real compiler, from decompme/compilers releases
```

Manual fetch, if needed:

```bash
curl -sL -o tools/wibo-bin/wibo \
  https://github.com/decompals/wibo/releases/download/1.1.0/wibo-x86_64
chmod +x tools/wibo-bin/wibo

curl -sL https://github.com/decompme/compilers/releases/download/compilers/mwccpsp_3.0.1_219.tar.gz \
  | tar xz -C tools/mwccpsp_3.0.1_219
```

The `mwccpsp` compiler itself is not redistributable in THIS repo's git history
(it's fetched at setup time, into the gitignored `tools/`): it's the same binary
obtainable from decomp.me (PSP scratch) or from the images at
https://github.com/decompme/compilers (`platforms/psp/`). See
`06-splitting-and-matching.md` for the local build-and-diff workflow.

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

## 9. MIPS binutils (for local relocation-aware matching)

`scripts/mwcc_diff.py` shells out to `mips-linux-gnu-objdump` to disassemble the
locally-built candidate `.o` with proper MIPS mnemonics and relocation
annotations (plain `objdump` refuses: MWCC sets an `e_flags` combination it
reports as "unknown CPU"). Ubuntu ships a prebuilt cross-binutils package:

```bash
sudo apt install -y binutils-mips-linux-gnu
```

This also provides `mips-linux-gnu-as`/`-ld`/`-nm`, useful for hand-assembling a
target asm snippet to cross-check against candidate objects (see
`06-splitting-and-matching.md`).

## Minimal command summary to get started

```bash
# 1. system dependencies (once)
sudo apt install -y p7zip-full build-essential libssl-dev python3-venv cmake ninja-build \
                    binutils-mips-linux-gnu

# 2. project toolchain (also fetches wibo + mwccpsp_3.0.1_219, see §6)
scripts/setup_tools.sh
make -C tools/pspdecrypt          # after libssl-dev

# 3. extract + (opt.) decrypt
scripts/extract_iso.sh "Yu-Gi-Oh 5D's Tag Force 5 (E)(M5)(ZER0)/0-ygotf5.iso"
scripts/decrypt_eboot.sh

# 4. Ghidra + ghidra-allegrex and PPSSPP: manual installation (sec. 4–5)

# 5. local matching, once you have a config/*.yaml + src/*.c:
splat split config/rel_movie_viewer.yaml
scripts/mwcc_build.sh src/rel_movie_viewer.c
scripts/mwcc_diff.py asm/rel_movie_viewer/text.s build/mwcc/rel_movie_viewer.o
```
