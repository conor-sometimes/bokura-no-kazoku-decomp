#!/usr/bin/env bash
# mk.sh : clean re-split (drops stale INCLUDE_ASM files), build, print errors and the result line,
# then refresh build/bk/ctx.json
D=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd -P); cd "$D/../.."
mkdir -p build/bk
rm -rf asm build/.split
.bokura-env/bin/bokura-env -c 'make -j6' > build/bk/build.log 2>&1
grep -E "error|Error|undefined|OK:|FAIL" build/bk/build.log | grep -v "^Rodata" | head -20
python3 -I tools/bk/ctx.py disc/SCPS_150.88 >/dev/null
