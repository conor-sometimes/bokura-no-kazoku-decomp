# tools/bk: matching helpers

Scratch-test C++ for INCLUDE_ASM'd functions against the retail bytes, then port it into the
unit. All run on hokkaido from the repo root; scratch files live in `build/bk/` (gitignored).

- `tools/bk/mk.sh`: clean re-split + build + refresh `build/bk/ctx.json` (function name, unit,
  data refs and vtable slots of every function still in asm). Run it once before the rest.
- `python3 -I tools/bk/show.py LO HI MAXWORDS [MINWORDS]`: list INCLUDE_ASM'd functions in an
  address range with their unit, vtable slots and asm.
- Snippets (`build/bk/snips/s_NAME.snip`): a `//@decl` section, then one `//@func 0xADDR`
  section per function. `//@class NAME` / `field OFF TYPE NAME [SIZE]` / members / `//@end`
  expands to a class with pads. `//@sym NAME 0xADDR` names a callee; callees named
  `Func<addr>`, `Init<addr>`, `Find<addr>`... get their symbol from the name.
  The unit's existing `// @decl-begin ... // @decl-end` block is prepended automatically, so
  a snippet only adds; `tools/bk/bk addm UNIT CLASS 'member;'` adds a member to a class there.
- `tools/bk/testall.sh NAME...`: test snippets, print non-matches. `tools/bk/bk show SNIP ADDR`:
  side-by-side diff. `bk perm SNIP ADDR [JOBS] [LIMIT]`: try orders of the lines ending in `//@p`, compiling only
  that function, JOBS in parallel (default half the cores). Up to LIMIT orders (default 5040, 7 lines)
  it tries them all; beyond that it hill-climbs on swaps (keeps a swap unless the diff count gets
  worse, random restarts) and prints the best order if none matches. Objects are read directly
  (tools/bk/bk.py `read_obj`), no objdump per candidate.
  `bk vtest SNIP`: every `//@func` section is a variant of one function, test each.
- `tools/bk/bk utest SNIP`: the test the full build would give. Splices the snippet into a copy of
  its unit (replacing the INCLUDE_ASMs, adding the decls), compiles the whole unit with the unit's
  own compiler and flags, and compares each function at its real offset, including where every
  relocation points (retail's call targets and %hi/%lo symbols). Catches what `bk test` can't:
  effects of the functions before it in the .cpp (delay-slot filling, the GNU as `lui` bug) and
  swapped globals or callees behind masked address bits. `bk port` refuses a snippet that fails
  it (`BK_NO_UTEST=1` to skip).
- `tools/bk/ushow.py SNIP [ADDR] [-q]` (run inside bokura-env): utest's in-unit compile shown side by side
  (ours | retail, `!!` on differing words). `BK_EXTRA="-flag ..."` adds compiler flags and finds the function
  by symbol (for flag sweeps), `BK_CC` swaps the driver, `BK_KEEP=1` keeps the spliced .cpp.
- `tools/bk/ntprobe.py SNIP ADDR` (inside bokura-env): re-tests the snippet in its unit with each free/extern "C"
  callee redeclared `throw()` (then all of them), to see whether a callee's nothrow-ness explains the diff
  (docs/lessons.md, nm). Members are not probed.
- `tools/bk/bk hard [--port] [-j N]`: re-test every saved stuck function. When a function goes to
  HARD.md, save its best attempt as `docs/hard/<lane>/hard_<ADDR>.snip` (a normal snippet); after
  any discovery (a flag, a header, a trick), `bk hard` re-runs them all through utest and lists
  the ones that now match (`--port` ports them).
- `python3 -I tools/bk/rank.py [--prefix Unit|Dk|Lib|C] [--units A,B] [--skip-hard] [-n N]`: what to
  try next, ranked by readiness (share of a function's callees already in C), size, blockers and
  fan-in (unmatched callers it unlocks). Better than smallest-first once the small ones are gone.
- `python3 -I tools/bk/hoist.py list` / `hoist.py CLASS...`: move classes declared locally in many
  units into `include/CLASS.h` (method-only copies), build, and give a unit its own copy back if it
  stops compiling with the header.
- `tools/bk/luibug.py`: run by mk.sh when the build fails: finds GNU as 2.10's `lui` bug (retail
  `lui`, ours a load to the same register) and names the function to put `asm(".p2align 3");` before.
- Lanes: `BK_UNITS_FILE=lane.units` (or `BK_UNITS=a,b`) makes `bk port` refuse to name functions in
  other lanes' units (declare those `extern "C" func_XXXXXXXX` instead).
- `tools/bk/portall.sh NAME...`: port (replace the INCLUDE_ASM, add renames to
  `config/symbol_addrs.txt`, refuse name conflicts), then build.
- `python3 -I tools/bk/progress.py`: matched count and bytes.

Units whose data comes from their object (docs/units.md "Data: vtables and .rodata per unit"):

- `python3 -I tools/bk/dataconv.py UNIT`: the unit's vtables slot by slot (where each target
  lives) and the status of each of its .rodata symbols. `apply [ro]` switches its yaml pieces to
  the object (`ro`: only .rodata), `revert` back to asm, `fix` (after a split) adds the
  `INCLUDE_RODATA` lines for the literals nothing else provides, in address order.
- `python3 -I tools/bk/rocheck.py [-v] [UNIT...]`: compares each converted unit's linked .rodata and
  vtables with the retail bytes at its own piece, so one build names every bad conversion.
- `python3 -I tools/bk/imgdiff.py [N]`: the first N differing ranges of the image, with the map
  section each falls in.
- `bk perm`/`bk show` need the function in `build/bk/ctx.json`, i.e. still INCLUDE_ASM'd: to
  permute a C++ function, put it back to INCLUDE_ASM (by its symbol_addrs name) and re-run mk.sh.

## Progress report (bytematch.dev)

- `python3 -I tools/bk/progress_report.py [-o build/progress/report.json]`: the progress report in
  objdiff's report format (version 2), from committed files only (no build, no ELF, stock Python): the
  .text units from the yaml, function starts and sizes from `config/functions.txt` (size = up to the
  next start, padding included), the INCLUDE_ASM lines of `src/*.cpp` as the unmatched functions, names
  from `config/symbol_addrs.txt`/`config/vtables.txt`. Since `make` proves the whole ELF matches, C
  means matched. Its totals are `progress.py`'s (all of .text; crt0 counts as unmatched, outside the
  categories). Categories: `game` (`game_cpp` + `game_c`, CAppMain on), `dklib`, `libs`, as in the
  README's table. Names, addresses, sizes and percentages only: no game bytes.
- `.github/workflows/progress.yml` runs it on every push and pull request, validates it with
  objdiff-cli v3.8.2 (SHA-256 pinned, `report changes r.json r.json`) and uploads it as artifact
  `SCPS_150.88_report`, which bytematch.dev reads from main. Nothing to set up on GitHub.
- `tools/bk/bytematch_upload.sh [report.json]` (optional): POST the report to bytematch.dev's upload
  API instead; token from `$BYTEMATCH_TOKEN` or `~/.config/bytematch/token`.
- `make objdiff` (optional, hokkaido, inside bokura-env): objdiff on real objects, for the objdiff
  GUI or to cross-check the tree-derived report. `scripts/fetch_objdiff.sh` fetches objdiff-cli
  (pinned) into `tools/objdiff/`; `tools/bk/objdiff.py` writes `objdiff.json` (gitignored), with
  target = the build's own objects (`build/src/*.cpp.o`, retail by the SHA-1 check) and base = the same
  compiles with `-DSKIP_ASM` (no INCLUDE_ASM'd functions) in `build/objdiff/base/`; then
  `objdiff-cli report generate -o build/objdiff/report.json`. Its numbers are measured code only
  (function `.size`s, no padding, plus 88 weak `__tf*` typeinfo functions the units' objects emit in
  `.gnu.linkonce.t` sections, which the tree report counts once, at their linked address), so it reads a little lower (48.43% vs 48.72% on 2026-10-16).
