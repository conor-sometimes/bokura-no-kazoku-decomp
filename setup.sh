#!/usr/bin/env bash
# One-time setup for the round-trip build. Run inside bokura-env:
#   .bokura-env/bin/bokura-env -c './setup.sh [path/to/bokura.iso]'
#
# 1. Checks the R5900 binutils from bokura-env are on PATH
# 2. Python venv (.venv) with the pinned requirements.txt
# 3. EE-GCC 2.96 into tools/compilers/ (scripts/fetch_compilers.sh)
# 4. The boot ELF from your own disc image into disc/SCPS_150.88 (SHA-1 checked)
# Nothing here is committed: .venv/ and disc/ are gitignored.
set -Eeuo pipefail
ROOT=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd -P)
cd "$ROOT"

ISO=${1:-${BOKURA_ISO:-}}

# R5900 binutils (decompals v0.10) come from bokura-env (workbench), on PATH.
command -v mips-ps2-decompals-as >/dev/null || { echo "setup: mips-ps2-decompals-as not on PATH; run inside bokura-env" >&2; exit 1; }
mips-ps2-decompals-as --version | head -1

if [[ ! -x .venv/bin/python ]]; then
    python3 -m venv .venv
fi
.venv/bin/pip install -q --disable-pip-version-check -r requirements.txt
.venv/bin/python -c 'import splat, spimdisasm; print("splat", splat.__version__, "spimdisasm", spimdisasm.__version__)'

# The game compiler (EE-GCC 2.96) from decomp.me's mirror, SHA-256 pinned.
scripts/fetch_compilers.sh

if [[ ! -f disc/SCPS_150.88 ]]; then
    if [[ -z $ISO ]]; then
        echo "setup: give the disc image: ./setup.sh path/to/bokura.iso (or BOKURA_ISO=...)" >&2
        exit 1
    fi
    python3 -I scripts/extract_elf.py "$ISO" disc/SCPS_150.88
fi
echo "setup: done. Now run: make"
