# Debug leftovers

Notes on developer features still present in the retail SCPS-15088 executable and disc. Addresses
are virtual addresses in SCPS_150.88. "Untested" means read from the code, not yet tried in an
emulator.

## Debug overlay (`CDebOut`) and performance meter

- Boot (`func_001E8B58`, called from `func_001E8D68`) always creates the debug text object:
  `func_00251BB8` news a 0x3C-byte `CDebOut` (vtable `_vt$7CDebOut`) and stores it in the global
  `D_002BA0B0`. Boot then sets a 640x448 screen and 16x16 characters, and loads the font
  `data/system/debout.xim`, which ships on the disc as `DATA/SYSTEM/DEBOUT.XIM`.
- The per-frame loop `Func1E8CA8` calls `Func1E8030` (input) on each logic tick and
  `func_001E80A0` (draw) once per frame.
- **Master switch: `D_002A5BB8` (s32, .data, 0 in retail).** Nothing writes it: the only reads
  are the gates in `Func1E8030` and `func_001E80A0`, plus a getter (`GetMiniGame6Unk2A5BB8`,
  0x1E7E28) with no callers.
- **Mode: `D_002A5BBC`** (default 1). While the switch is on, pad bit 0x200 (`SCE_PADR2` in
  libpad's layout, so probably R2) cycles the mode 0 -> 1 -> 2. Mode 0 hides the meter and clears
  the peak values `D_002A5B98`/`D_002A5B9C`.
- What it draws: `"CPU %3d(%3d)\nDMA %3d(%3d)\nTMEM%8d\nMMEM%8d\nVRAM%8d\n"`, i.e. CPU and DMA
  load with peaks in brackets, plus free texture, main and VRAM memory. The calls named
  `GetRemaining__13CMiniGame6Obj` that feed it are really heap "remaining" queries: the
  CMiniGame6Res unit is late (its text start holds the main loop), so the names are wrong.
- Untested enable patch (PCSX2 pnach; the file needs the game's CRC, which PCSX2 shows on boot):
  `patch=1,EE,002A5BB8,word,00000001`

## Other `CDebOut` users

- `func_001B85D8` (CMenuMgr): memory-card status panel,
  `"McSys\nWORKING %d\nInfo.Type %d\nInfo.FreeBlock %d\nInfo.BlockSize %d\n"`. It is called
  through a pointer; what gates it is not traced yet.
- `func_00135C40` (CEventObj): event/character debug list with `@r` colour codes
  (`"@rEVENT\n"`, `"@rCHR\n"`, `" %d\n"`). Not traced yet.

## `SYSF_DEBUG_FLAG`

- A named system flag: entry 40 of the flag-range table `D_002A1AA0`, which covers flag ids
  0x262C-0x264B (type 4). No C++ code uses those ids directly, so it is only reachable by name,
  from scripts (`CSvmWork`) or `gameexp` expressions. The scripts sit in compressed `.XAP`
  archives (`DATA/EVENT.XAP`), so whether any script checks it needs the XAP decompressor first.

## Map editor remnants

- `func_00119B08` (CMapAttr) can save map attribute files (`"*** failed to save map attribute
  '%s'"`), and `"*** failed to write map '%s'"` exists too. Callers not traced yet.

## Loose text files on the disc (read at runtime, easy to mod)

- `SYSTEM.INI`: archive paths (`mapdir = data/map.xap`, ...).
- `DATA/SYSTEM/DRAWCONF.TXT`: toon-shader settings (outline size `osize`, outline colour `ocol`,
  shadow colour).
- `DATA/SOUND/SNDVOL.TXT`: per-sound-effect volumes.
- `VSSVER.SCC` files in several folders: Microsoft Visual SourceSafe leftovers.

## More leads (not traced yet)

- Dev fast-forwards in `CCharaObj`: `"skip time : %d->%d (%d,%d)"`, `"$$ skip season (%d,%d)"`,
  `"skip preset event %d"`, `"check pass border (%d, %d)"`. What triggers them is unknown.
- Heap trace (`rx` heap, around 0x22A6E8): prints `"!-LEAKMEMCHECK"`, `"!-LEAKVRAMCHECK"`, `"!-%s"`
  to the TTY when `D_002B8C3C & 5`; the `!-` prefix looks like a marker for a host-side leak tool.
- Dev-kit boot: `host0:` and `"Skip Iop Reboot: %s"`; placeholder product code `SCPS-00000` next to
  `SCPS-15088KAZOKU`.
- Demo mode: `CDemoMain` loads `data/demo/%s.xap` (four on the disc) with their own `curflag.txt`.

## Game data archives (`.XAP`)

`tools/xap.py list|extract` unpacks them (format in its docstring; the LZ decompressor is the
game's 0x249958). Nested archives become folders; `--sjis` writes UTF-8 copies of the Shift-JIS
text. Of note:
- `sysinc/system.inc`: the event script VM's instruction set (opcode number, name, arguments),
  e.g. `cmd 3, DBOUT, str` (debug output). The 1517 `event/**/*.scb` files are compiled scripts
  with a `.mes` message file each; a disassembler can be built from system.inc.
- `gamedb/`: scenarios A/B/C, child growth and stats, jobs, clubs, books, tutors, reviews.
- `minig/minig2/qdata.txt` (arithmetic quiz), `minig/minig5/quest.txt` (kanji reading quiz).
- `photodb/photo-c+.txt`: the scenario C photo list "with Pants" (PAN).
- Every entry carries a 2004-2005 timestamp (`list` prints it).
- The string `SYSF_DEBUG_FLAG` appears in no extracted file (text or `.scb`); if scripts use it,
  they do so by number, which needs the disassembler to check.
