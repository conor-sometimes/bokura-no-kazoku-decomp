# decomp-permuter on Bokura (C++)

decomp-permuter parses C (pycparser) and cannot read C++. `tools/bk/permute.py` bridges it:
it hands the permuter a C-parseable `base.c` (basic-type typedefs, each class typedef'd to
`int`, the function with its `Class::` qualifier / `extern "C"` stripped and named by its
mangled symbol; bare members and undeclared callees are left as plain identifiers, which
pycparser accepts), lets it randomize the body, and its `compile.sh` splices the mutated body
back into the real C++ unit (`bk.compile_`) so the scored object carries the true type context
and retail-matching bytes. The target is the splat `asm/nonmatchings/<unit>/<name>.s` assembled
with the game ASFLAGS, its glabel/`.size` renamed to the candidate mangled symbol so the two
objects line up.

## Use (inside bokura-env)

    python3 tools/bk/permute.py setup SNIP [ADDR]    # build build/permute/<ADDR>/, print run cmd
    permuter build/permute/<ADDR> --debug            # one-shot: base score + side-by-side diff
    permuter build/permute/<ADDR> --stop-on-zero     # search; stops on a match

SNIP is a normal bk snippet (`//@func 0xADDR` + the C++ body, `//@decl` sections as needed) --
the same file `bk test` / `bk port` take. On score 0, copy the matched body from
`build/permute/<ADDR>/base.c` back into the C++ method and `bk port` it.

Only works on functions still INCLUDE_ASM'd (their nonmatchings `.s` must exist). It reaches the
scheduling/reordering near-misses that `bk perm` (statement-order only) cannot; exceptions and
templates are out of scope.
