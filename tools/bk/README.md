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
  side-by-side diff. `bk perm SNIP ADDR`: try all orders of the lines ending in `//@p`.
  `bk vtest SNIP`: every `//@func` section is a variant of one function, test each.
- `tools/bk/portall.sh NAME...`: port (replace the INCLUDE_ASM, add renames to
  `config/symbol_addrs.txt`, refuse name conflicts), then build.
- `python3 -I tools/bk/progress.py`: matched count and bytes.
