# 01 — Panoramica: decompilare un gioco PSP

## Cos'è una decompilazione "matching"

Una **decompilazione matching** è la ricostruzione del codice sorgente C/C++ di un
gioco tale che, ricompilato con **lo stesso compilatore e le stesse opzioni**
dell'epoca, produca un binario **byte-per-byte identico** all'originale. È
l'approccio dei progetti più noti (Super Mario 64, Ocarina of Time, ecc.) e dà due
garanzie:

1. **Correttezza dimostrabile**: se l'output è identico, il sorgente ricostruito è
   funzionalmente equivalente per definizione.
2. **Base per port e mod**: una volta completata (anche parzialmente), il codice può
   essere modificato, portato su PC, corretto, esteso.

Le alternative più leggere sono la **decomp non-matching** (codice equivalente ma non
identico) e il semplice **reverse engineering documentale** (capire formati e logica
senza ricostruire il sorgente). Un progetto reale di solito mescola i tre livelli:
matching dove conta (engine, logica di gioco), documentale per formati e asset.

## Il flusso di lavoro in sintesi

```
ISO UMD
 │  estrazione (7z / mount)
 ▼
EBOOT.BIN cifrato ──► decrypt (pspdecrypt / PPSSPP) ──► ELF in chiaro
PRX di gioco (già in chiaro)                                │
 ▼                                                          ▼
Analisi statica (Ghidra + estensione Allegrex, prxtool, NID database)
 │  identificazione funzioni, dati, import SDK
 ▼
Split del binario (splat: config YAML → asm/ + assets/ per segmento)
 │
 ▼
Decomp funzione-per-funzione:  m2c (bozza C) → mano → asm-differ / decomp.me
 │                                                    (confronto asm target vs build)
 ▼
Build system (make/ninja + MWCC via WINE/wibo) → ELF ricostruito
 │
 ▼
Verifica: sha1sum ELF ricostruito == ELF originale  → % di match cresce nel tempo
```

I dettagli di ogni fase sono nei documenti 03–06.

## Perché Tag Force 5 è un buon candidato

Dall'analisi della ISO (vedi `02-analisi-iso.md`):

- **28 moduli PRX in chiaro** con nomi parlanti (`rel_duel_eng`, `rel_story`, …):
  si può iniziare subito, senza decrypt, da moduli piccoli e autocontenuti.
- **Compilatore identificato con certezza** (MWCC PSP 2.4.1.01, dalla sezione
  `.comment`): niente ricerca alla cieca del compilatore, che è di solito la parte
  più aleatoria del matching.
- **Architettura modulare** (engine `ehsys` + moduli feature): confini netti tra
  sottosistemi = progressi misurabili modulo per modulo.
- **Community di modding esistente** per la serie Tag Force (tool per archivi
  `.ehp`, traduzioni fan-made): formati asset già in parte documentati.
- C'è perfino un **menu di debug** (`rel_debug_menu.prx`) lasciato nel disco.

## Nota legale (in breve)

- Lavorare su una copia di backup di un gioco **che si possiede** per studio /
  interoperabilità / preservazione è la prassi dei progetti di decompilazione seri.
- Regola d'oro dei progetti pubblici: **nel repository non si committano mai asset,
  binari originali, ISO o codice copyright di Konami/Sony** — solo il codice
  ricostruito a mano, gli strumenti e la documentazione. Il `.gitignore` di questo
  repo esclude già ISO/asset estratti.
- Niente distribuzione di ISO patchate complete: le mod si distribuiscono come
  patch (xdelta) da applicare alla copia posseduta dall'utente.
- I progetti matching pubblici (SM64, OOT, ecc.) pubblicano il sorgente ricostruito
  richiedendo la ISO/ROM originale per estrarre gli asset: è il modello da seguire.

## Aspettative realistiche

Una decomp completa di un gioco PSP è un lavoro **da anni**, tipicamente di squadra.
Obiettivi intermedi sensati, in ordine:

1. Pipeline riproducibile: estrazione ISO + decrypt EBOOT documentati e scriptati.
2. Progetto Ghidra con moduli caricati, import SDK risolti via NID, funzioni nominate.
3. Un modulo piccolo (es. `rel_movie_viewer.prx`, 26 KB) splittato con splat e
   ricostruito matching al 100%.
4. Formati asset (`.ehp`, database carte) documentati con tool di pack/unpack.
5. Espansione progressiva a `rel_duel_eng` e al modulo principale `modehsys`.
