#!/usr/bin/env bash
# Fetch objdiff-cli (static Linux build from encounter/objdiff's releases) into tools/objdiff/,
# pinned by version and SHA-256. tools/objdiff/ is gitignored. Used by `make report`.
#   scripts/fetch_objdiff.sh
set -Eeuo pipefail
ROOT=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd -P)
VERSION=v3.8.2
declare -A SHA=(
    [x86_64]=e5445089a6f707e30cb5e02992451b604619cedfd2660ee2373a86bfefd9e718
    [aarch64]=087516e73e1b3223b39974f00bc2810fea5c3dc2c93a8e1f06442ec68acaacb4
)
arch=$(uname -m)
sum=${SHA[$arch]:-}
[[ -n $sum ]] || { echo "fetch_objdiff: no pinned objdiff-cli for $arch" >&2; exit 1; }
dest=$ROOT/tools/objdiff
if [[ -x $dest/objdiff-cli && -f $dest/.sha256 && $(<"$dest/.sha256") == "$sum" ]]; then
    echo "objdiff-cli $VERSION: already there"; exit 0
fi
mkdir -p "$dest"
tmp=$(mktemp "$dest/.dl.XXXXXX"); trap 'rm -f "$tmp"' EXIT
curl -fsSL -o "$tmp" "https://github.com/encounter/objdiff/releases/download/$VERSION/objdiff-cli-linux-$arch"
echo "$sum  $tmp" | sha256sum -c --quiet -
chmod +x "$tmp"; mv "$tmp" "$dest/objdiff-cli"; trap - EXIT
echo "$sum" > "$dest/.sha256"
echo "objdiff-cli $VERSION: fetched ($("$dest/objdiff-cli" --version))"
