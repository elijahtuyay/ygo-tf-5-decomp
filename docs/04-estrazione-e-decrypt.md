# 04 — Estrazione della ISO e decrypt dell'EBOOT

## A. Estrarre la ISO

Script pronto:

```bash
scripts/extract_iso.sh "Yu-Gi-Oh 5D's Tag Force 5 (E)(M5)(ZER0)/0-ygotf5.iso"
```

Estrae tutto in `iso_extracted/` (cartella ignorata da git). Internamente usa
`7z x` (funziona su ISO9660 UMD). In alternativa si può montare in sola lettura:

```bash
sudo mount -o loop,ro gioco.iso /mnt/umd
```

Dopo l'estrazione i file che ci interessano sono:

```
iso_extracted/PSP_GAME/SYSDIR/EBOOT.BIN            # eseguibile principale, cifrato
iso_extracted/PSP_GAME/USRDIR/gmodule/*.prx        # 28 moduli, già in chiaro
```

## B. Capire EBOOT vs BOOT vs UPDATE

Nella cartella `SYSDIR/` ci sono tre eseguibili; è fondamentale non confonderli:

| File | Stato | A cosa serve |
|---|---|---|
| `EBOOT.BIN` | **cifrato** (magic `~PSP` = `7E 50 53 50`) | ★ l'eseguibile del gioco (`modehsys`). Va **decifrato**. |
| `BOOT.BIN` | dummy azzerato (1.5 MB di `00`) | vuoto nei giochi retail. **NON** è l'ELF in chiaro. |
| `UPDATE/EBOOT.BIN` | updater firmware | installa il fw 6.31, **irrilevante** per la decomp. |

Verifica veloce del magic:

```bash
xxd iso_extracted/PSP_GAME/SYSDIR/EBOOT.BIN | head -1
# 00000000: 7e50 5350 ...  "~PSP"  -> cifrato
```

> Nota: in molte build di sviluppo `BOOT.BIN` conterrebbe l'ELF in chiaro, ma nella
> release retail di TF5 è azzerato. Quindi **dobbiamo** decifrare `EBOOT.BIN`.

## C. Decifrare l'EBOOT — due strade

L'header `~PSP` racchiude un ELF/PRX compresso e cifrato con le chiavi KIRK della PSP.
Per ottenere l'ELF Allegrex in chiaro si può usare uno di questi due metodi.

### Metodo 1 — pspdecrypt (CLI, riproducibile)

[`pspdecrypt`](https://github.com/John-K/pspdecrypt) implementa le chiavi KIRK e
decomprime i moduli `~PSP`. Compilazione (serve OpenSSL dev):

```bash
sudo apt install libssl-dev build-essential
make -C tools/pspdecrypt           # dopo scripts/setup_tools.sh
```

Poi:

```bash
scripts/decrypt_eboot.sh
# -> build/EBOOT.elf  + stampa lo sha1 (target di verifica del match)
```

> Su questa macchina `libssl-dev` non è installato: il resto della toolchain è
> pronto, manca solo questo pacchetto per compilare pspdecrypt. Installalo con
> il comando qui sopra (nel prompt di Claude Code puoi lanciarlo con
> `! sudo apt install libssl-dev`).

### Metodo 2 — PPSSPP (nessuna compilazione)

L'emulatore [PPSSPP](https://www.ppsspp.org/) decifra l'EBOOT per eseguirlo e può
salvarne la versione in chiaro. Con lo sviluppo abilitato:

1. Avvia il gioco in PPSSPP almeno fino al menu.
2. In molte build il file decifrato compare come `EBOOT.BIN.dec` accanto all'ISO
   o nella cartella `PSP/SYSTEM`; in altre si usa il debugger integrato
   (Debug ▸ *Dump …*) per esportare il modulo caricato.
3. Copia l'ELF ottenuto in `build/EBOOT.elf`.

PPSSPP è comunque indispensabile più avanti come strumento di RE (disassembler,
memory viewer, GE debugger): vedi `05-ghidra.md` e `08-risorse.md`.

## D. I moduli PRX sono già decifrati

I 28 `USRDIR/gmodule/*.prx` **non** sono cifrati: sono ELF32 MIPS Allegrex in chiaro
e si possono analizzare subito. Verificato sul campo — il disassemblaggio del
`.text` di `rel_movie_viewer.prx` (il modulo più piccolo, 26 KB) con rabbitizer in
categoria `R4000ALLEGREX` produce codice corretto:

```
00000000: 27bdfff0  addiu  $sp, $sp, -0x10     # module_start: prologo
00000004: 3c040000  lui    $a0, 0x0            # (rilocato via .rel.text)
...
0000001c: 0c00022d  jal    func_0008B4
0000002c: 03e00008  jr     $ra
```

→ **Si può iniziare la decomp dai moduli PRX senza nemmeno decifrare l'EBOOT.**
L'EBOOT (engine condiviso `modehsys`) serve solo quando si affrontano le funzioni
di sistema che i moduli importano da `libehsys_rel`.

## E. Registrare gli hash (target del match)

Appena ottenuto `build/EBOOT.elf`, salva gli sha1 di riferimento — sono l'obiettivo
finale della build matching:

```bash
sha1sum iso_extracted/PSP_GAME/USRDIR/gmodule/*.prx build/EBOOT.elf > checksums.sha1
```

Da quel momento `sha1sum -c checksums.sha1` dice se la ricostruzione combacia.
