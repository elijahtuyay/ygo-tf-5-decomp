# 07 — Formati dei file di Tag Force 5

Riepilogo di ciò che la community di modding ha già capito dei formati della serie
Tag Force. Vale la pena partire da qui invece di reinventare: molti tool esistono già
e lo stesso engine (`ehsys`) è condiviso tra i vari Tag Force. **Attenzione**: quasi
tutti i tool sono stati testati su TF1/TF6; su TF5 vanno verificati sui file reali
(il formato ha piccole varianti tra i giochi).

> Nessun tool va committato nel repo; installali in `tools/` (già gitignored). I
> repo qui sotto sono di terze parti — trattali come riferimento, non come dipendenze
> fidate a scatola chiusa.

## Archivi `.ehp` ("EhFolder") — il contenitore principale

Gli asset del gioco sono impacchettati in file `.ehp` (es. `title_menu_e.ehp`,
`story_scr_e.ehp`, `all_e.ehp`). È il formato-contenitore dell'engine.

- **ehppack** — https://github.com/xan1242/ehppack — unpack/repack da riga di comando,
  dichiarato compatibile con "qualsiasi gioco Tag Force". È la cosa più vicina a una
  specifica del formato (la logica è nel sorgente C++).
- **EHPScanner** — https://github.com/xan1242/EHPScanner — scandisce l'EBOOT decifrato
  per trovare EhFolder **incorporati nell'eseguibile** ed estrarli come `.ehp`. Rivela
  un fatto importante: **l'EBOOT contiene EHP embedded** (es. `cname.ehp`,
  `interface.ehp`, `sysmsg.ehp`, `rcpset.ehp`, `packset.ehp`, `load_fl.ehp`).
- **EHP Suite** (web) — https://syruskyury.github.io/ehp_suite/ — estrai/modifica/
  reimpacchetta nel browser, con viewer esadecimale.
- Nota edge-case: alcuni `.ehp` (`deck/tutorial.ehp`, `deck/deckswap.ehp` in ARC-V TFS)
  falliscono con ehppack diretto ma si aprono se prima ri-salvati con EHPScanner → il
  formato **non è perfettamente uniforme** tra giochi/tool.

## Archivi `.cip` / `.cpm` — immagini delle carte

- **CIPTool** — https://github.com/xan1242/CIPTool — unpack/repack dei pacchetti di
  artwork delle carte. Le immagini interne sono **DXT1**; usa un GIMConv modificato.

## Immagini `.gim` e modelli `.gmo` (formati Sony generici)

- **GIM** = texture PSP standard (magic `GIM 1.00`), a blocchi (Root/Picture/Image/
  Palette), formati CLUT4/8/16/32 e DXT. Convertibili con **GIMConv** (SDK Sony) o
  strumenti come **TextER** (romhacking.net/utilities/659). Doc generica:
  psdevwiki / vg-resource (non specifiche di Tag Force).
- **GMO** = modelli 3D PSP (header con magic tipo `OMG..1PSP`). Formato Sony generico.

### Modelli specifici Tag Force: `.tms` / `.tmt`

I modelli dei personaggi/duello usano un formato proprietario **parzialmente**
reverse-engineered (geometria `.tms`, animazione `.tmt`). Discussione su ResHax
(https://reshax.com/topic/1858-...): tabella mesh a offset 0x04 (entry da 12 byte),
bone count a 0x14, FVF a dimensione variabile. Esiste uno script Noesis parziale
(`fmt_tms.py`, kurokozerefx) che legge la geometria ma **non** lo scheletro. Stato:
incompleto → buon candidato per il lavoro di RE di questo progetto.

## Database delle carte

Dentro `cardinfo_*.ehp` (o equivalenti nel disco) stanno più binari correlati:

| File | Contenuto |
|---|---|
| `CARD_Name_*.bin` | nomi carte |
| `CARD_Desc_*.bin` | testi/descrizioni |
| `CARD_Huff_*.bin` | descrizioni **compresse Huffman** |
| `CARD_Indx_*.bin` | indice |
| `DICT_*.bin` | dizionario per la decompressione Huffman |

- **TFCardEdit** / **TFCardEditGUI** — https://github.com/xan1242/TFCardEdit — editano
  nome/livello/ATK/DEF/tipo/attributo/rarità/password/flag. **Avvertenza cruciale del
  README**: *"le carte non avranno effetto se questo non esiste già nella logica/codice
  del gioco"*.
- **ogy** — https://github.com/exsilium/ogy — documenta bene il layout e la
  compressione Huffman+dizionario; segnala un **tetto di ~877.000 byte** per
  `cardinfo.ehp` oltre il quale il gioco crasha.

> ★ **Conseguenza diretta per la decomp**: gli **effetti delle carte sono codificati
> nell'engine** (`rel_duel_eng.prx`), non nei dati. Chi vuole aggiungere carte o
> capire le regole *deve* decompilare il codice — non basta editare i `.bin`. È
> esattamente il valore aggiunto di questo progetto rispetto al modding esistente.

## Testi e tabelle stringhe

- **tagforcestring** — https://github.com/xan1242/tagforcestring — converte
  `strtbl`/`wordstbl` e le `.bin` di lingua in un testo tipo-ini e viceversa.
  Gestisce UTF-8 / UTF-16LE / Shift-JIS. Convenzione nomi:
  `<nome><char_tipo><char_lingua>.bin`. Utile per gli `story_scr_*.ehp`.

## Deck e recipe: `.ydc`

- File deck binari `.ydc` (header di 8 byte; ~60% iniziano con magic `01 FC`; 96–140
  byte tipici), presenti anche **dentro l'EBOOT**.
- **Deck Converter** — https://github.com/SyrusKyury/Yu-Gi-Oh-Tag-Force-Deck-Converter
  — `.ydc` ↔ `.ydk` (EDOPro).
- **TFRandomizer** — https://github.com/xan1242/TFRandomizer — **testato su TF5**:
  randomizza box negozio e recipe. Costanti utili trovate per TF5 (build **US**,
  ULUS-10555): `BoxInfoOffset = 0x23090`, **60 box**. (Per la nostra build EU
  ULES-01474 l'offset va riconfermato, ma la struttura è la stessa.)

## Audio: `psp_snddat.bin`

- Banca sonora unica da 151 MB. **TFSndEdit** — https://github.com/xan1242/TFSndEdit —
  la ripacchetta; per il repack serve un blocco header **SHDS** estratto dall'EBOOT.
  Codec probabile **VAG/ADPCM** (non AT3, contrariamente a quanto si potrebbe supporre).
- I filmati in `USRDIR/movie/*.pmf` sono lo standard Sony **PSMF** (M2V + Atrac3),
  riproducibili con `libpsmfplayer.prx` (presente in `USRDIR/module/`).

## Directory `INSDIR/` (508 file `FILE*.DAT`)

508 file da ~17 KB, tutti simili: sono i dati dell'"installazione su Memory Stick"
tipica dei giochi Tag Force (per ridurre gli accessi UMD). Bassa priorità per la
decomp del codice; utili semmai per capire il sistema di install runtime.

## Tabella di priorità per il RE dei formati

| Formato | Serve tool nuovo? | Priorità decomp |
|---|---|---|
| `.ehp` | no (ehppack) | alta — è la porta d'ingresso a tutti gli asset |
| Card DB `.bin` | no (ogy/TFCardEdit) | media — i dati; la logica è nel codice |
| stringhe/testi | no (tagforcestring) | bassa |
| `.ydc` deck | no (Deck Converter) | bassa |
| `psp_snddat.bin` | no (TFSndEdit) | bassa |
| `.tms/.tmt` modelli | **sì** (RE incompleto) | media (se interessa la grafica) |
| logica engine/carte | **è la decomp stessa** | ★ massima |
