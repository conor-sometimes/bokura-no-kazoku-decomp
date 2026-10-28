#!/usr/bin/env python3
# bk permute: run the full (C-only) decomp-permuter on bokura's C++ via body-splice.
#   permute.py setup SNIP [ADDR]          build a permuter scratch dir, print the run command
#   permute.py compile SNIP ADDR IN OUT   compile.sh backend: splice IN's body into the C++ unit
#
# decomp-permuter parses C with pycparser and cannot read C++. We hand it a base.c it CAN parse
# (basic-type typedefs, every class name typedef'd to int, the function with `Class::` stripped;
# bare members and undeclared callees are left as plain identifiers, which pycparser accepts), let
# it randomize the body, and have compile.sh splice the mutated body back into the real C++ unit
# (bk.compile_) so the scored object carries the true C++ type context and retail-matching bytes.
# The target object is the splat nonmatchings .s assembled with the game's own ASFLAGS, so its
# relocations line up with the candidate's. Virtual calls are fine (a member deref + indirect call
# in the body); exceptions/templates are not.
import glob
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import bk  # noqa: E402

R = bk.R
AS = "mips-ps2-decompals-as"
ASFLAGS = ["-EL", "-march=r5900", "-mabi=eabi", "-no-pad-sections", "-G", "0", "-Iinclude"]
BASIC = {"s8", "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "void", "char",
         "int", "float", "double", "long", "short", "unsigned", "signed", "const"}


def pick(snip, addr):
    decl, funcs = bk.parse(snip)
    if addr is None:
        if len(funcs) != 1:
            raise SystemExit("snip has %d functions; name an ADDR" % len(funcs))
        addr = funcs[0][0]
    body = dict(funcs)[addr]
    return decl, addr, body


def short_name(body):
    m = re.search(r'::\s*([A-Za-z_]\w*)\s*\(', body)
    if m:
        return m.group(1)
    return re.search(r'([A-Za-z_~]\w*)\s*\(', body).group(1)


def strip_method(text):
    # `ret Class::name(args){...}`  ->  `ret name(args){...}`  (first qualifier only)
    return re.sub(r'\b[A-Za-z_]\w*\s*::\s*', '', text, count=1)


def extract_body(c_src, name):
    m = re.search(r'\b%s\s*\([^;{]*\)\s*\{' % re.escape(name), c_src)
    if not m:
        raise SystemExit("compile: function %s not found in candidate" % name)
    i = m.end() - 1
    depth = 0
    for j in range(i, len(c_src)):
        if c_src[j] == '{':
            depth += 1
        elif c_src[j] == '}':
            depth -= 1
            if depth == 0:
                return c_src[i + 1:j]
    raise SystemExit("compile: unbalanced braces")


def find_asm(unit, name):
    p = os.path.join(R, "asm", "nonmatchings", unit, name + ".s")
    if os.path.exists(p):
        return p
    hits = glob.glob(os.path.join(R, "asm", "nonmatchings", "**", name + ".s"), recursive=True)
    if not hits:
        raise SystemExit("no nonmatchings .s for %s" % name)
    return hits[0]


def do_setup(snip, addr):
    decl, addr, body = pick(snip, addr)
    c = bk.ctx[hex(addr)]
    unit, name = c["unit"], c["name"]
    classes = set(re.findall(r'\b(?:class|struct)\s+([A-Za-z_]\w*)', bk.unit_decl([(addr, body)]) + decl))
    classes |= set(re.findall(r'\b([A-Z]\w*)\s*\**\s*[A-Za-z_]\w*\s*[;,)=]', body))  # local/param types
    pre = ("typedef signed char s8;typedef unsigned char u8;typedef signed short s16;"
           "typedef unsigned short u16;typedef signed int s32;typedef unsigned int u32;"
           "typedef signed long s64;typedef unsigned long u64;typedef float f32;\n")
    pre += "".join("typedef int %s;\n" % t for t in sorted(classes) if t not in BASIC)
    d = os.path.join(R, "build", "permute", "%08X" % addr)
    os.makedirs(d, exist_ok=True)
    # candidate symbol (mangled C++ name) from a baseline compile of the snip as written
    try:
        csyms = bk.compile_(decl, [(addr, body)], os.path.join(d, "cand0.o"),
                            tag="permsetup%d" % os.getpid())[0]
    except bk.CompileError as e:
        raise SystemExit("baseline compile failed:\n" + str(e)[-1500:])
    func_name = csyms[0][2]
    # base.c: the function named exactly func_name so the permuter finds it, C++ linkage/qualifier gone
    basefn = re.sub(r'\bextern\s+"C"\s*', '', body)
    mm = re.search(r'\b[A-Za-z_]\w*\s*::\s*[A-Za-z_]\w*', basefn)
    if mm:
        basefn = basefn.replace(mm.group(0), func_name, 1)
    open(os.path.join(d, "base.c"), "w").write(pre + basefn + "\n")
    # target: splat nonmatchings .s, its glabel renamed to the candidate symbol so names line up
    sfile = find_asm(unit, name)
    s_txt = open(sfile).read().replace(name, func_name)  # glabel + the trailing .size
    open(os.path.join(d, "target.s"), "w").write('.include "macro.inc"\n' + s_txt)
    r = subprocess.run([AS] + ASFLAGS + ["-o", os.path.join(d, "target.o"), os.path.join(d, "target.s")],
                       cwd=R, capture_output=True, text=True)
    if r.returncode:
        raise SystemExit("assemble target failed:\n" + r.stderr[-1500:])
    me = os.path.abspath(__file__)
    sh = os.path.join(d, "compile.sh")
    open(sh, "w").write('#!/bin/sh\nexec python3 %s compile %s %#x %s "$1" "$3"\n'
                        % (me, os.path.abspath(snip), addr, func_name))
    os.chmod(sh, 0o755)
    open(os.path.join(d, "settings.toml"), "w").write(
        'func_name = "%s"\ncompiler_type = "gcc"\n' % func_name)
    run = "nix run ~/Projects/nix/decomp-nix#bokura-no-kazoku -- -c 'permuter %s%s'"
    print("scratch dir:", d)
    print("func_name:  ", func_name)
    print("sanity:     ", run % (d, " --debug --stop-on-zero"))
    print("run:        ", run % (d, ""))


def do_compile(snip, addr, func_name, inp, out):
    decl, addr, body = pick(snip, addr)
    newbody = extract_body(open(inp).read(), func_name)
    sig = body[:body.index("{")]
    newfunc = sig + "{\n" + newbody + "\n}\n"
    try:
        bk.compile_(decl, [(addr, newfunc)], out, tag="perm%d" % os.getpid())
    except bk.CompileError as e:
        sys.stderr.write(str(e)[-1500:])
        sys.exit(1)


if __name__ == "__main__":
    cmd = sys.argv[1]
    if cmd == "setup":
        do_setup(sys.argv[2], int(sys.argv[3], 16) if len(sys.argv) > 3 else None)
    elif cmd == "compile":
        do_compile(sys.argv[2], int(sys.argv[3], 16), sys.argv[4], sys.argv[5], sys.argv[6])
    else:
        raise SystemExit("usage: permute.py setup|compile ...")
