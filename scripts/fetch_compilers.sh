#!/usr/bin/env bash
# Fetch EE-GCC candidates from decomp.me's compiler mirror into tools/compilers/<name>/,
# each pinned by SHA-256. Linux i386 binaries: run them inside bokura-env (32-bit libs).
#   .bokura-env/bin/bokura-env -c 'scripts/fetch_compilers.sh [name ...]'
# With no names it fetches the game compiler only. tools/compilers/ is gitignored.
set -Eeuo pipefail
ROOT=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd -P)
URL=https://github.com/decompme/compilers/releases/download/compilers
GAME_COMPILER=ee-gcc2.96

declare -A SHA=(
    [ee-gcc2.96]=0590d2ca9da8f5903889d66761220d14b47a8d14ba987ca53db84a1650a1fd0a
    [ee-gcc2.9-991111]=99cb5db603cd985b50fc6851157020ad69489f2227309ccf825bd43ac7bc19dd
    [ee-gcc2.9-991111a]=f07d1f38afa847197fb816237dbce64e79b2d37b738cb93fa4df3ac7aa1d16f3
    [ee-gcc2.9-991111-01]=ed684fd98f89d36b0121caab311052089103e3b36241fcef4338cc9ea41c75b8
    [ee-gcc2.9-990721]=ad2ea68afff2be25d21a1d51a75e8a0eea8f259018e6580622355cd01b95676b
    [ee-gcc3.2-040921]=8c60ca7482523190e999524a7e4de2379dcf7ffee543c1b5663bfdf6a80ebf0f
)

names=("$@")
[[ ${#names[@]} -gt 0 ]] || names=("$GAME_COMPILER")
for name in "${names[@]}"; do
    sum=${SHA[$name]:-}
    [[ -n $sum ]] || { echo "fetch_compilers: unknown compiler $name" >&2; exit 1; }
    dest=$ROOT/tools/compilers/$name
    # workbench's PS2 envs carry the same pinned builds under $DECOMP_COMPILERS: link, don't download.
    if [[ -n ${DECOMP_COMPILERS:-} && -f $DECOMP_COMPILERS/$name/.sha256 && $(<"$DECOMP_COMPILERS/$name/.sha256") == "$sum" ]]; then
        mkdir -p "$ROOT/tools/compilers"; rm -rf "$dest"; ln -s "$DECOMP_COMPILERS/$name" "$dest"
        echo "$name: linked from workbench"; continue
    fi
    if [[ -f $dest/.sha256 && $(<"$dest/.sha256") == "$sum" ]]; then
        echo "$name: already there"; continue
    fi
    tmp=$(mktemp -d); trap 'rm -rf "$tmp"' EXIT
    curl -fsSL -o "$tmp/$name.tar.xz" "$URL/$name.tar.xz"
    echo "$sum  $tmp/$name.tar.xz" | sha256sum -c --quiet -
    rm -rf "$dest"; mkdir -p "$dest"
    tar -xJf "$tmp/$name.tar.xz" -C "$dest"
    echo "$sum" > "$dest/.sha256"
    rm -rf "$tmp"; trap - EXIT
    echo "$name: ok"
done
