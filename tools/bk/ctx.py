# ctx.py ELF : build build/bk/ctx.json: per function addr -> {name, unit, words, data refs, vtable slots}
import re,struct,json,glob,os,sys
R=os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
rom=open(sys.argv[1],'rb').read()
w=lambda va: struct.unpack_from('<I',rom,va-0xFF000)[0]
# named data symbols (vtables are _vt$<class>, config/vtables.txt) -> address
SYMS={}
for p in (R+'/config/symbol_addrs.txt',R+'/config/vtables.txt'):
    for line in open(p):
        m=re.match(r'\s*([\w$.]+)\s*=\s*0x([0-9A-Fa-f]+)',line)
        if m: SYMS[m.group(1)]=int(m.group(2),16)
# function list from nonmatchings + asm
funcs={}
for p in glob.glob(R+'/asm/nonmatchings/*/*.s')+[R+"/asm/crt0.s",R+"/asm/text_283858.s"]:
    unit=os.path.basename(os.path.dirname(p)) if 'nonmatchings' in p else os.path.basename(p)[:-2]
    name=None
    for line in open(p):
        m=re.match(r'glabel (\S+)',line)
        if m and not m.group(1).startswith('.L'): name=m.group(1); first=None; n=0; continue
        m=re.search(r'/\* \w+ ([0-9A-F]{8}) ',line)
        if m and name:
            a=int(m.group(1),16)
            if first is None: first=a; funcs[a]={'name':name,'unit':unit,'n':0,'refs':[]}
            funcs[first]['n']+=1
        for s in re.findall(r'%lo\(([\w$]+)\)',line):
            mm=re.search(r'([0-9A-F]{6,8})$',s)
            a=SYMS.get(s, int(mm.group(1),16) if mm else None)
            if a is not None and name and first: funcs[first]['refs'].append(a)
starts=set(funcs)
# vtables from config/vtables.txt (_vt$<mangled class> = addr; // size:N). [i] = i-th virtual
# function (entry i+1, after the typeinfo entry); the class name as the RTTI name, without the
# length prefix for plain classes.
vtc={}
for line in open(R+'/config/vtables.txt'):
    m=re.match(r'_vt\$(\S+) = 0x([0-9a-fA-F]+); // size:0x([0-9A-Fa-f]+)',line)
    if not m: continue
    n,v,size=m.group(1),int(m.group(2),16),int(m.group(3),16)
    mm=re.match(r'(\d+)(.*)',n); cls=mm.group(2)[:int(mm.group(1))] if mm else n
    for a in range(v+12,v+size,8):
        if w(a) in starts: vtc.setdefault(w(a),[]).append(f'{cls}[{(a-v-12)//8}]')
out={hex(a):{**f,'vt':vtc.get(a,[])} for a,f in funcs.items()}
os.makedirs(R+'/build/bk',exist_ok=True)
json.dump(out,open(R+'/build/bk/ctx.json','w'))
print(len(out))
