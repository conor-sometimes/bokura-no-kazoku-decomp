# ctx.py ELF : build build/bk/ctx.json: per function addr -> {name, unit, words, data refs, vtable slots}
import re,struct,json,glob,os,sys
R=os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
rom=open(sys.argv[1],'rb').read()
w=lambda va: struct.unpack_from('<I',rom,va-0xFF000)[0]
# function list from nonmatchings + asm
funcs={}
for p in glob.glob(R+'/asm/nonmatchings/*/*.s')+[R+'/asm/crt0.s',R+'/asm/text_1e91b8.s']:
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
        for s in re.findall(r'%lo\((\w+)\)',line):
            mm=re.search(r'([0-9A-F]{6,8})$',s)
            if mm and name and first: funcs[first]['refs'].append(int(mm.group(1),16))
starts=set(funcs)
# also the matched (C++) functions: from src via symbol_addrs not needed for ctx
vts=sorted({r for f in funcs.values() for r in f['refs'] if 0x2bfa40<=r<0x2c2c98})
def tf_name(tf):
    if tf not in funcs: return None
    p=glob.glob(R+'/asm/nonmatchings/*/%s.s'%funcs[tf]['name'])
    t=open(p[0]).read() if p else open(R+'/asm/text_1e91b8.s').read()
    m=re.search(r'glabel %s\n(.*?)\.size'%re.escape(funcs[tf]['name']),t,re.S)
    if not m: return None
    mm=re.search(r'addiu\s+\$(?:a1|5), \$(?:a1|5), %lo\((?:D_)?0*([0-9A-F]+)\)',m.group(1))
    if not mm: return None
    off=int(mm.group(1),16)-0xFF000; s=rom[off:rom.index(b'\0',off)].decode('latin1')
    m=re.match(r'(\d+)(.*)',s); return m.group(2)[:int(m.group(1))] if m and not s.startswith('t') else s
vtc={}
for i,v in enumerate(vts):
    end=vts[i+1] if i+1<len(vts) else 0x2c2c98
    cls=tf_name(w(v+4))
    for k,a in enumerate(range(v+8,end,4)):
        if w(a) in starts: vtc.setdefault(w(a),[]).append(f'{cls}[{(a-v-8)//8}]')
out={hex(a):{**f,'vt':vtc.get(a,[])} for a,f in funcs.items()}
os.makedirs(R+'/build/bk',exist_ok=True)
json.dump(out,open(R+'/build/bk/ctx.json','w'))
print(len(out))
