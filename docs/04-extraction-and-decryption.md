# 04 — ISO Extraction and EBOOT Decryption

## A. Extracting the ISO

Ready-made script:

```bash
scripts/extract_iso.sh "Yu-Gi-Oh 5D's Tag Force 5 (E)(M5)(ZER0)/0-ygotf5.iso"
```

Extracts everything into `iso_extracted/` (a folder ignored by git). Internally it
uses `7z x` (works on ISO9660 UMD). Alternatively, you can mount it read-only:

```bash
sudo mount -o loop,ro gioco.iso /mnt/umd
```

After extraction, the files we care about are:

```
iso_extracted/PSP_GAME/SYSDIR/EBOOT.BIN            # main executable, encrypted
iso_extracted/PSP_GAME/USRDIR/gmodule/*.prx        # 28 modules, already plaintext
```

## B. Understanding EBOOT vs BOOT vs UPDATE

There are three executables in the `SYSDIR/` folder; it's essential not to confuse them:

| File | State | What it's for |
|---|---|---|
| `EBOOT.BIN` | **encrypted** (magic `~PSP` = `7E 50 53 50`) | ★ the game's executable (`modehsys`). Must be **decrypted**. |
| `BOOT.BIN` | zeroed-out dummy (1.5 MB of `00`) | empty in retail games. **NOT** the plaintext ELF. |
| `UPDATE/EBOOT.BIN` | firmware updater | installs firmware 6.31, **irrelevant** to the decomp. |

Quick magic check:

```bash
xxd iso_extracted/PSP_GAME/SYSDIR/EBOOT.BIN | head -1
# 00000000: 7e50 5350 ...  "~PSP"  -> encrypted
```

> Note: in many development builds `BOOT.BIN` would contain the plaintext ELF, but
> in TF5's retail release it's zeroed out. So we **must** decrypt `EBOOT.BIN`.

## C. Decrypting the EBOOT — two approaches

The `~PSP` header wraps an ELF/PRX that is compressed and encrypted with the PSP's
KIRK keys. To get the plaintext Allegrex ELF, you can use one of these two methods.

### Method 1 — pspdecrypt (CLI, reproducible)

[`pspdecrypt`](https://github.com/John-K/pspdecrypt) implements the KIRK keys and
decompresses `~PSP` modules. Build it (requires OpenSSL dev headers):

```bash
sudo apt install libssl-dev build-essential
make -C tools/pspdecrypt           # after scripts/setup_tools.sh
```

Then:

```bash
scripts/decrypt_eboot.sh
# -> build/EBOOT.elf  + prints the sha1 (the target for match verification)
```

> On this machine `libssl-dev` isn't installed: the rest of the toolchain is
> ready, only this package is missing to build pspdecrypt. Install it with
> the command above (in the Claude Code prompt you can run it with
> `! sudo apt install libssl-dev`).

### Method 2 — PPSSPP (no compilation needed)

The [PPSSPP](https://www.ppsspp.org/) emulator decrypts the EBOOT in order to run it
and can save the plaintext version. With development features enabled:

1. Boot the game in PPSSPP at least until you reach the menu.
2. In many builds the decrypted file appears as `EBOOT.BIN.dec` next to the ISO
   or in the `PSP/SYSTEM` folder; in others you use the built-in debugger
   (Debug ▸ *Dump …*) to export the loaded module.
3. Copy the resulting ELF to `build/EBOOT.elf`.

PPSSPP is also indispensable later on as an RE tool (disassembler, memory
viewer, GE debugger): see `05-ghidra.md` and `08-resources.md`.

## D. The PRX modules are already decrypted

The 28 `USRDIR/gmodule/*.prx` files are **not** encrypted: they are plaintext ELF32
MIPS Allegrex files and can be analyzed right away. Verified in practice — disassembling
the `.text` section of `rel_movie_viewer.prx` (the smallest module, 26 KB) with rabbitizer
in the `R4000ALLEGREX` category produces correct code:

```
00000000: 27bdfff0  addiu  $sp, $sp, -0x10     # module_start: prologue
00000004: 3c040000  lui    $a0, 0x0            # (relocated via .rel.text)
...
0000001c: 0c00022d  jal    func_0008B4
0000002c: 03e00008  jr     $ra
```

→ **You can start decompiling from the PRX modules without even decrypting the EBOOT.**
The EBOOT (shared engine `modehsys`) is only needed when tackling the system functions
that the modules import from `libehsys_rel`.

## E. Recording the hashes (match target)

As soon as you have `build/EBOOT.elf`, save the reference sha1 hashes — they are the
final goal of the matching build:

```bash
sha1sum iso_extracted/PSP_GAME/USRDIR/gmodule/*.prx build/EBOOT.elf > checksums.sha1
```

From that point on, `sha1sum -c checksums.sha1` tells you whether the rebuild matches.
