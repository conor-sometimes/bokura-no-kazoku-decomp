# show.py LO HI MAXN [MINN] : list functions with unit, vtable slots and asm (from nonmatchings)
import json,sys,glob,os,re
R=os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ctx=json.load(open(R+'/build/bk/ctx.json'))
srcs={}
for p in glob.glob(R+'/src/*.cpp'):
    for m in re.finditer(r'INCLUDE_ASM\("[^"]+", (\w+)\)',open(p).read()): srcs[m.group(1)]=1
lo,hi,mx=int(sys.argv[1],16),int(sys.argv[2],16),int(sys.argv[3]); mn=int(sys.argv[4]) if len(sys.argv)>4 else 1
for k in sorted(ctx,key=lambda k:int(k,16)):
    c=ctx[k]; a=int(k,16)
    if not(lo<=a<hi and mn<=c['n']<=mx): continue
    p=f"{R}/asm/nonmatchings/{c['unit']}/{c['name']}.s"
    if not os.path.exists(p) or c['name'] not in srcs: continue
    ins=[re.sub(r'\s+',' ',l.split('*/',1)[1].strip()) for l in open(p) if re.search(r'/\* \w+ [0-9A-F]{8} ',l)]
    print(k,c['unit'],','.join(c['vt']) or '-','|',' ; '.join(ins))
