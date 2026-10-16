#!/usr/bin/env python3
# bk.py test|port SNIP : scratch-test or port C++ snippets.
# SNIP: '//@decl' sections (declarations) and '//@func 0xADDR' sections (one function each).
import re,sys,os,subprocess,json,struct
sys.path.insert(0,os.path.dirname(os.path.abspath(__file__)))  # utest.py next to it (python3 -I drops the script dir)
R=os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
W=R+'/build/bk'
os.makedirs(W,exist_ok=True)
CC=R+'/tools/compilers/ee-gcc2.96/bin/ee-gcc'
# dklib units built with the SDK compiler ee-gcc 2.9-991111 (Makefile SDK_OBJS)
SDKCC=R+'/tools/compilers/'+os.environ.get('BK_SDK','ee-gcc2.9-991111')+'/bin/ee-gcc'
SDK_RANGES=[(0x262D28,0x26CFB0)]
# Sony SDK libraries (Makefile SDKC_OBJS): C through 2.9's cc1, assembled by the 2.96 GNU as (-B)
SDKC_RANGES=[(0x26CFB0,0x27FC30),(0x292E20,0x2930A0)]  # + Lib292E20 (libkernel dcache, lane lb)
SDKAS=R+'/tools/compilers/ee-gcc2.96/ee/bin/'
# libgcc and newlib built without -fno-strict-aliasing (Makefile LIBC_OBJS, lane w2)
LIBC_RANGES=[(0x283858,0x292E20)]
EXC_RANGES=[(0x287920,0x287F98)]  # Makefile: Lib287920 (exception.cc) built with -fexceptions (lane lb)
LIBC_C_RANGES=[(0x280098,0x2828C0),(0x283858,0x286B20),(0x287F98,0x288388),(0x2888C0,0x292E20)]  # Makefile LIBC_C_OBJS (compiled as C, lane w2)
OD='mips-ps2-decompals-objdump'
ctx=json.load(open(W+'/ctx.json'))
rom=open(R+'/disc/SCPS_150.88','rb').read()
SIZES={'s8':1,'u8':1,'s16':2,'u16':2,'s32':4,'u32':4,'f32':4,'int':4,'float':4,'s64':8,'u64':8}
def expand_classes(t):
    # //@class NAME [: BASE]\n  field OFF TYPE NAME\n  <member decl>\n//@end  ->  class with pads
    def one(m):
        head=m.group(1).strip(); body=m.group(2)
        fields=[];other=[]
        for l in body.split('\n'):
            p=l.split()
            if p and p[0]=='field': fields.append((int(p[1],16),p[2],p[3],int(p[4],16) if len(p)>4 else None))
            elif l.strip(): other.append('    '+l.strip())
        fields.sort(); out=[]; pos=0; k=0
        for off,ty,nm,sz in fields:
            if off>pos: out.append(f'    u8 pad{pos:X}[0x{off-pos:X}];'); 
            out.append(f'    {ty} {nm};{" "*max(1,24-len(ty)-len(nm))}// 0x{off:X}')
            pos=off+(sz if sz else (SIZES.get(ty,4) if not ty.endswith('*') else 4))
        return f'class {head} {{\npublic:\n'+'\n'.join(other)+'\n\n'+'\n'.join(out)+'\n};\n'
    return re.sub(r'^//@class ([^\n]*)\n(.*?)^//@end\n',one,t,flags=re.M|re.S)
def parse(path):
    t=expand_classes(open(path).read())
    parts=re.split(r'^//@(decl|func)[ \t]*(\S*)[^\n]*\n',t,flags=re.M)
    decl=parts[0]; funcs=[]
    for i in range(1,len(parts),3):
        kind,arg,body=parts[i],parts[i+1],parts[i+2]
        if kind=='decl': decl+=body
        else: funcs.append((int(arg,16),body.rstrip()+'\n'))
    return decl,funcs
def unit_decl(funcs):
    units={ctx[hex(a)]['unit'] for a,b in funcs if hex(a) in ctx}
    if len(units)!=1: return ''
    p=f'{R}/src/{units.pop()}.cpp'
    if not os.path.exists(p): return ''
    m=re.search(r'^// @decl-begin[^\n]*\n(.*?)^// @decl-end\n',open(p).read(),re.M|re.S)
    return m.group(1) if m else ''
class CompileError(Exception): pass
def flags_for(funcs):
    # the unit's compiler and flags, as the Makefile sets them per unit (ASG, SDK_OBJS, SDKC_OBJS)
    cc,base=CC,['-O2','-G0','-fno-strict-aliasing','-fno-exceptions']
    if funcs and all(any(lo<=a<hi for lo,hi in LIBC_RANGES) for a,b in funcs): base=['-O2','-G0','-fno-exceptions']  # Makefile LIBC_OBJS
    if funcs and all(any(lo<=a<hi for lo,hi in EXC_RANGES) for a,b in funcs): base=['-O2','-G0','-fexceptions']  # Makefile Lib287920
    if funcs and all(any(lo<=a<hi for lo,hi in LIBC_C_RANGES) for a,b in funcs): base=['-x','c','-O2','-G0','-fno-exceptions']  # Makefile LIBC_C_OBJS
    if funcs and all(any(lo<=a<hi for lo,hi in SDK_RANGES) for a,b in funcs):  # Makefile SDK_OBJS
        cc,base=SDKCC,['-O2','-G0','-fno-exceptions','-B'+SDKAS]
    sdk=funcs and all(any(lo<=a<hi for lo,hi in SDK_RANGES) for a,b in funcs)
    sdkc=funcs and all(any(lo<=a<hi for lo,hi in SDKC_RANGES) for a,b in funcs)
    if sdkc:  # Makefile SDKC_OBJS
        cc,base=R+'/tools/compilers/ee-gcc2.9-991111-01/bin/ee-gcc',['-x','c','-O2','-G0','-B'+SDKAS]
    asg=['-Wa,-g'] if not sdkc and not sdk and any((a<0x1E91B8 or a>=0x245648) and not (0x260A60<=a<0x262D28) for a,b in funcs) else []  # Makefile ASG (Dk260A60 without as -g, lane w2)
    mode=os.environ.get('BK_MODE')  # experiments: force a compiler setup (sdk, sdkc, 296, 296c)
    if mode=='sdk': cc,base,asg=SDKCC,['-O2','-G0','-fno-exceptions','-B'+SDKAS],[]
    elif mode=='sdkc': cc,base,asg=R+'/tools/compilers/ee-gcc2.9-991111-01/bin/ee-gcc',['-x','c','-O2','-G0','-B'+SDKAS],[]
    elif mode=='296': cc,base,asg=CC,['-O2','-G0','-fno-strict-aliasing','-fno-exceptions'],['-Wa,-g']
    elif mode=='296c': cc,base,asg=CC,['-x','c','-O2','-G0','-fno-strict-aliasing'],['-Wa,-g']
    return cc,base,asg
def compile_(decl,funcs,out,tag='t'):
    # tag: per-process scratch name so parallel compiles don't share t.cpp
    decl=unit_decl(funcs)+'\n'+decl
    src='#include "common.h"\n'+decl+'\n'+''.join(b for a,b in funcs)
    cpp=f'{W}/{tag}.cpp'; open(cpp,'w').write(src)
    cc,base,asg=flags_for(funcs)
    r=subprocess.run([cc]+base+['-I'+R+'/include','-Wa,-I'+R+'/include']+asg+['-c','-o',out,cpp],capture_output=True,text=True)
    if r.returncode: raise CompileError(r.stderr)
    return read_obj(out)
R_MIPS={4:'R_MIPS_26',5:'R_MIPS_HI16',6:'R_MIPS_LO16'}
def read_obj(path):
    # parse the ELF32 LE object directly (no objdump/objcopy): .text bytes, FUNC symbols in .text
    # sorted by offset, .text relocations {offset: type}, undefined symbol names
    b=open(path,'rb').read()
    shoff,=struct.unpack_from('<I',b,0x20); shnum,shstrndx=struct.unpack_from('<HH',b,0x30)
    sh=[struct.unpack_from('<10I',b,shoff+40*i) for i in range(shnum)]
    nm=lambda tab,o: b[sh[tab][4]+o:b.index(b'\0',sh[tab][4]+o)].decode()
    names=[nm(shstrndx,s[0]) for s in sh]
    ti=names.index('.text'); text=b[sh[ti][4]:sh[ti][4]+sh[ti][5]]
    syms=[];und=[];relocs={}
    for i,s in enumerate(sh):
        if s[1]==2:  # SHT_SYMTAB
            for k in range(s[5]//16):
                st_name,val,size,info,_,shndx=struct.unpack_from('<IIIBBH',b,s[4]+16*k)
                if shndx==ti and info&0xf==2: syms.append((val,size,nm(s[6],st_name)))
                elif shndx==0 and st_name: und.append(nm(s[6],st_name))
        elif s[1]==9 and s[7]==ti:  # SHT_REL for .text
            for k in range(s[5]//8):
                off,info=struct.unpack_from('<II',b,s[4]+8*k)
                if info&0xff in R_MIPS: relocs[off]=R_MIPS[info&0xff]
    syms.sort()
    return syms,text,relocs,und
def words(b,off,n): return [struct.unpack_from('<I',b,off+4*i)[0] if off+4*i+4<=len(b) else 0 for i in range(n)]
def score(funcs,obj):
    # [(addr,name,bad,ours,theirs)]: bad = differing words (relocated fields masked), +1000 on size mismatch
    syms,text,relocs,und=obj; res=[]
    for (addr,body),(off,size,name) in zip(funcs,syms):
        c=ctx[hex(addr)]; n=c['n']
        mine=words(text,off,size//4); theirs=words(rom,addr-0xFF000,n)
        while mine and mine[-1]==0: mine.pop()
        while theirs and theirs[-1]==0: theirs.pop()
        n=len(theirs)
        bad=0 if len(mine)==n else 1000
        for i,(x,y) in enumerate(zip(mine,theirs)):
            r=relocs.get(off+4*i); m=0xFFFFFFFF
            if r in('R_MIPS_HI16','R_MIPS_LO16'): m=0xFFFF0000
            if r=='R_MIPS_26': m=0xFC000000
            if (x&m)!=(y&m): bad+=1
        res.append((addr,name,bad,len(mine),n))
    return res
def test(path,quiet=False):
    decl,funcs=parse(path)
    o=W+'/t.o'
    try: obj=compile_(decl,funcs,o)
    except CompileError as e: print(e); sys.exit(1)
    # sections may define extra functions (e.g. inline helpers emitted); match by order of non-inline? assume 1:1
    if len(obj[0])!=len(funcs): print('symbol count',len(obj[0]),'!= funcs',len(funcs),[s[2] for s in obj[0]])
    res=score(funcs,obj)
    if not quiet:
        for addr,name,bad,ours,n in res: print(f"{addr:#x} {name}: {'MATCH' if bad==0 else f'DIFF {bad} (ours {ours} / {n} insns)'}")
    return res
def port(path):
    decl,funcs=parse(path)
    res=test(path,quiet=True)
    bad=[r for r in res if r[2]]
    if bad: print('not all match:',[(hex(r[0]),r[2]) for r in bad]); sys.exit(1)
    # and the way the full build sees it: in its unit, with relocation targets (tools/bk/utest.py)
    if not os.environ.get('BK_NO_UTEST'):
        import utest
        ubad=[r for r in utest.utest(path,quiet=True) if r[2]]
        if ubad:
            print('matches alone but not in its unit (bk utest SNIP for details):',[(hex(r[0]),r[1],r[2]) for r in ubad]); sys.exit(1)
    units={ctx[hex(a)]['unit'] for a,b in funcs}
    assert len(units)==1, units
    unit=units.pop(); p=f'{R}/src/{unit}.cpp'; s=open(p).read()
    syms=[]
    for (addr,body),r in zip(funcs,res):
        old=ctx[hex(addr)]['name']
        pat=re.compile(r'^INCLUDE_ASM\("[^"]+", %s\);\n'%re.escape(old),re.M)
        assert pat.search(s),(unit,old)
        s=pat.sub(lambda m: body,s)
        if r[1]!=old: syms.append(f'{r[1]} = {addr:#010x}; // type:func')
    # undefined references: callees named after their address (FuncXXXXXX) or //@sym NAME ADDR
    known=open(R+'/config/symbol_addrs.txt').read()+open(R+'/config/aliases.ld').read()+open(R+'/config/vtables.txt').read()
    extra=dict((m.group(1),int(m.group(2),16)) for m in re.finditer(r'^//@sym (\S+) (0x[0-9A-Fa-f]+)',open(path).read(),re.M))
    und=read_obj(W+'/t.o')[3]
    for u in und:
        if re.match(r'^(func|D|jtbl)_[0-9A-F]+$',u) or (u+' =') in known or any(x.startswith(u+' =') for x in syms): continue
        a=extra.get(u)
        if a is None:
            m=re.search(r'(?:Func|Init|Find|Get|Set)([12][0-9A-F]{5})',u)
            assert m, 'no address for '+u
            a=int(m.group(1),16)
        t='func' if a<0x29f230 else 'data'
        syms.append(f'{u} = {a:#010x}; // type:{t}' if t=='func' else f'{u} = {a:#010x};')
    if decl.strip():
        old=unit_decl(funcs)
        blk='// @decl-begin (declarations for the matched functions; scripts regenerate this block)\n'+(old.strip()+'\n\n' if old.strip() else '')+decl.strip()+'\n// @decl-end\n'
        m=re.search(r'^// @decl-begin.*?^// @decl-end\n',s,re.M|re.S)
        if m: s=s[:m.start()]+blk+s[m.end():]
        else:
            mk='#include "common.h"\n'; i=s.index(mk)+len(mk)
            s=s[:i]+'\n'+blk+s[i:]
    have={}
    for m in re.finditer(r'^(\S+) = 0x([0-9A-Fa-f]+);',open(R+'/config/symbol_addrs.txt').read(),re.M): have[int(m.group(2),16)]=m.group(1)
    keep=[]
    for l in syms:
        n,a=l.split(' = ')[0],int(l.split(' = ')[1].split(';')[0],16)
        if a in have and have[a]!=n: print(f'NAME CONFLICT at {a:#x}: have {have[a]}, snippet wants {n}'); sys.exit(1)
        if a not in have: keep.append(l)
    syms=keep
    # lanes: only name addresses inside your own units (BK_UNITS=a,b or BK_UNITS_FILE=lane.units);
    # naming another lane's function renames its INCLUDE_ASM and clashes at merge
    owned=set(filter(None,os.environ.get('BK_UNITS','').split(',')))
    uf=os.environ.get('BK_UNITS_FILE')
    if uf: owned|=set(open(uf).read().split())
    if owned:
        starts=sorted((int(m.group(1),16)+0xFF000,m.group(2)) for m in re.finditer(r'\[0x([0-9A-Fa-f]+), (?:cpp|c|asm|data|\.data|rodata|\.rodata|bss|\.bss), (\w+)\]',open(R+'/config/SCPS_150.88.yaml').read()))
        def owner(a):
            u=None
            for st,n in starts:
                if st<=a: u=n
                else: break
            return u
        foreign=[l for l in syms if 'type:func' in l and owner(int(l.split(' = ')[1].split(';')[0],16)) not in owned]
        if foreign:
            print('refusing to name functions in other lanes\' units (declare them extern "C" func_XXXXXXXX instead):')
            for l in foreign: print('  '+l+'  ('+str(owner(int(l.split(' = ')[1].split(';')[0],16)))+')')
            sys.exit(1)
    open(p,'w').write(s)
    if syms:
        with open(R+'/config/symbol_addrs.txt','a') as f: f.write('\n'.join(syms)+'\n')
    print(f'ported {len(funcs)} into {unit}.cpp, {len(syms)} renames'); fix_includes()
def show(path, addr):
    addr=int(addr,16); decl,funcs=parse(path)
    o=W+'/t.o'; syms=compile_(decl,funcs,o)[0]
    idx=[a for a,b in funcs].index(addr); off,size,name=syms[idx]
    d=subprocess.run([OD,'-d','-z','-r','--start-address=%d'%off,'--stop-address=%d'%(off+size),o],capture_output=True,text=True).stdout
    mine=[l.split('\t',2)[-1] for l in d.splitlines() if re.match(r'\s+[0-9a-f]+:\t',l)]
    c=ctx[hex(addr)]; p=f"{R}/asm/nonmatchings/{c['unit']}/{c['name']}.s"
    theirs=[re.sub(r'\s+',' ',l.split('*/',1)[1].strip()) for l in open(p) if re.search(r'/\* \w+ [0-9A-F]{8} ',l)]
    obj=read_obj(o); text=obj[1]; rel=obj[2]
    mw=words(text,off,size//4); tw=words(rom,addr-0xFF000,c['n'])
    theirs=[l for l in theirs if not l.startswith('.')] if len(theirs)>c['n'] else theirs
    for i in range(max(len(mine),len(theirs))):
        a=mine[i] if i<len(mine) else ''; b=theirs[i] if i<len(theirs) else ''
        flag='  '
        if i<len(mw) and i<len(tw):
            r=rel.get(off+4*i); m=0xFFFFFFFF
            if r in ('R_MIPS_HI16','R_MIPS_LO16'): m=0xFFFF0000
            if r=='R_MIPS_26': m=0xFC000000
            if (mw[i]&m)!=(tw[i]&m): flag='!!'
        else: flag='!!'
        print(f'{flag}{a:<40} | {b}')
def fix_includes():
    # INCLUDE_ASM lines still naming func_XXXXXXXX for functions renamed in symbol_addrs
    names={}
    for m in re.finditer(r'^(\S+) = 0x([0-9A-Fa-f]+); // type:func',open(R+'/config/symbol_addrs.txt').read(),re.M):
        names[int(m.group(2),16)]=m.group(1)
    import glob
    n=0
    for p in glob.glob(R+'/src/*.cpp'):
        s=open(p).read()
        def sub(m):
            global_n=None
            a=int(m.group(2),16)
            return f'INCLUDE_ASM("{m.group(1)}", {names[a]});' if a in names else m.group(0)
        t=re.sub(r'INCLUDE_ASM\("([^"]+)", func_([0-9A-F]{8})\);',sub,s)
        if t!=s: open(p,'w').write(t); n+=1
    print('fixed includes in',n,'files')
if __name__=='__main__':
    cmd=sys.argv[1]
    if cmd=='test': test(sys.argv[2])
    elif cmd=='port': port(sys.argv[2])
    elif cmd=='show': show(sys.argv[2],sys.argv[3])
    elif cmd=='fix': fix_includes()
    elif cmd=='hard':
        import hardretry; hardretry.main(sys.argv[2:]); sys.exit(0)
    elif cmd=='utest':
        import utest; r=utest.utest(sys.argv[2]); sys.exit(1 if any(x[2] for x in r) else 0)
_P={}
def _perm_init(decl,addr,head,idx,body):
    _P.update(decl=decl,addr=addr,head=head,idx=idx,body=body,tag=f'perm{os.getpid()}')
def _perm_score(order):
    # compile only function ADDR with the //@p lines in this order; return (bad, order)
    b=list(_P['body'])
    for k,l in zip(_P['idx'],order): b[k]=l
    funcs=[(_P['addr'],_P['head']+'\n'.join(b))]
    try: obj=compile_(_P['decl'],funcs,f"{W}/{_P['tag']}.o",_P['tag'])
    except CompileError: return (10**6,order)
    return (score(funcs,obj)[0][2],order)
def perm(path, addr, jobs=None, limit=5040):
    # permute the statement lines ending in '//@p' of function ADDR, in parallel, compiling only that
    # function. Up to LIMIT orders: all of them (best first on ties); more: swap hill-climbing with
    # random restarts, keeping a swap when the diff count doesn't get worse.
    import itertools,math,random
    from multiprocessing import Pool
    addr=int(addr,16); decl,funcs=parse(path)
    body=dict(funcs)[addr].split('\n')
    head=''  # the body already starts at the function's first line
    idx=[k for k,l in enumerate(body) if l.rstrip().endswith('//@p')]
    lines=tuple(body[k] for k in idx); n=len(lines)
    jobs=jobs or max(1,(os.cpu_count() or 2)//2)
    seen={}
    with Pool(jobs,_perm_init,(decl,addr,head,idx,body)) as pool:
        def run(orders):
            new=[o for o in dict.fromkeys(orders) if o not in seen]
            for bad,o in pool.imap_unordered(_perm_score,new,chunksize=4):
                seen[o]=bad
                if bad==0: return o
            return None
        base=run([lines])
        print(f'{n} lines, {math.factorial(n)} orders, start DIFF {seen[lines]}, {jobs} jobs')
        if base is not None: print('MATCH (as written)'); return
        if math.factorial(n)<=limit:
            hit=run(itertools.permutations(lines))
        else:
            hit=None; rng=random.Random(0); cur=lines
            for _ in range(limit//max(1,n*(n-1)//2)+1):
                swaps=[]
                for a in range(n):
                    for c in range(a+1,n):
                        l=list(cur); l[a],l[c]=l[c],l[a]; swaps.append(tuple(l))
                hit=run(swaps)
                if hit: break
                best=min(swaps,key=lambda o:seen[o])
                if seen[best]<=seen[cur] and best!=cur: cur=best
                else: l=list(cur); rng.shuffle(l); cur=tuple(l); run([cur])
                if len(seen)>=limit: break
    if hit: print('MATCH order:'); print('\n'.join(hit))
    else:
        best=min(seen,key=seen.get)
        print(f'no order matches ({len(seen)} tried); best DIFF {seen[best]}:'); print('\n'.join(best))
if __name__=='__main__' and sys.argv[1]=='perm': perm(sys.argv[2],sys.argv[3],*(int(x) for x in sys.argv[4:6]))
def addm(unit, cls, member):
    # add a member declaration to class CLS in UNIT's decl block
    p=f'{R}/src/{unit}.cpp'; s=open(p).read()
    m=re.search(r'^class %s\b[^{]*\{\npublic:\n'%re.escape(cls),s,re.M)
    assert m, (unit,cls)
    s=s[:m.end()]+'    '+member.strip()+'\n'+s[m.end():]
    open(p,'w').write(s)
if __name__=='__main__' and sys.argv[1]=='addm': addm(sys.argv[2],sys.argv[3],sys.argv[4])
def vtest(path):
    # each //@func section is a variant of the same function: test them one at a time
    t=open(path).read()
    parts=re.split(r'(^//@func[^\n]*\n)',t,flags=re.M)
    head=parts[0]
    for k in range(1,len(parts),2):
        open(W+'/vt.snip','w').write(head+parts[k]+parts[k+1])
        try:
            r=test(W+'/vt.snip',quiet=True)[0]
            print(f'variant {k//2+1}: '+('MATCH' if r[2]==0 else f'DIFF {r[2]}'))
        except SystemExit:
            print(f'variant {k//2+1}: compile error')
if __name__=='__main__' and sys.argv[1]=='vtest': vtest(sys.argv[2])
