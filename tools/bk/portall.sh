#!/usr/bin/env bash
# portall.sh NAME... : port build/bk/snips/s_NAME.snip for each, then build
D=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd -P); S="$D/../../build/bk/snips"
for s in "$@"; do "$D/bk" port "$S/s_$s.snip" || exit 1; done
"$D/mk.sh"
