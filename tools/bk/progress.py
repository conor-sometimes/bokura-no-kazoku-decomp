#!/usr/bin/env python3
"""progress.py: matched functions in the C++ unit range (functions no longer INCLUDE_ASM'd)."""
import json,os,sys
R=os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ctx=json.load(open(R+'/build/bk/ctx.json'))
LO,HI=0x1002A8,0x29F230  # all of .text after crt0: C++ units, C-style units, dklib, libraries
everything=[int(l,16) for l in open(R+'/config/functions.txt') if l.startswith('0x')]
allf=[a for a in everything if LO<=a<HI]
remaining={int(k,16) for k in ctx if LO<=int(k,16)<HI}
ends=allf[1:]+[HI]
mf=[(a,e-a) for a,e in zip(allf,ends) if a not in remaining]
mb=sum(s for a,s in mf)
if '--numbers' not in sys.argv:
    print(f'units 0x{LO:X}-0x{HI:X}: {len(allf)} functions; matched {len(mf)}, {mb} bytes incl. padding '
          f'({mb/(HI-LO)*100:.2f}% of unit code, {mb/0x19F230*100:.2f}% of .text)')
if '--numbers' in sys.argv:  # for progress-readme: matched/total functions and bytes over all of .text
    print(len(mf), len(everything), mb, 0x19F230, file=sys.stderr if False else sys.stdout)
