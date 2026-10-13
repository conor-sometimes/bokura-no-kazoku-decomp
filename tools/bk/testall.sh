#!/usr/bin/env bash
# testall.sh NAME... : test build/bk/snips/s_NAME.snip, print only the non-matches
D=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd -P); S="$D/../../build/bk/snips"
for s in "$@"; do "$D/bk" test "$S/s_$s.snip" 2>&1 | grep -v ": MATCH$" | sed "s/^/[$s] /"; done
