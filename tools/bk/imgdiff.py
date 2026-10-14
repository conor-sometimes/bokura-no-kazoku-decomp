#!/usr/bin/env python3
# imgdiff.py : where build/SCPS_150.88.img differs from the retail image, with the input section
# of build/SCPS_150.88.map that each differing range falls in.
import os, re, sys
R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ret = open(R + '/disc/SCPS_150.88', 'rb').read()[0x1000:]
img = open(R + '/build/SCPS_150.88.img', 'rb').read()
secs = []
for line in open(R + '/build/SCPS_150.88.map'):
    m = re.match(r'\s*(\.\S+)?\s+0x([0-9a-f]{8,16})\s+0x([0-9a-f]+)\s+(\S+\.o)\s*$', line)
    if m and int(m.group(3), 16):
        secs.append((int(m.group(2), 16), int(m.group(3), 16), m.group(4), m.group(1) or ''))
runs = []
for i in range(min(len(ret), len(img))):
    if ret[i] != img[i]:
        if runs and i - runs[-1][1] <= 16:
            runs[-1][1] = i
        else:
            runs.append([i, i])
if len(img) != len(ret[:len(img)]) or len(img) < 0x1EB700 - 0x100000:
    print(f'image size {len(img):#x}')
for a, e in runs[:int(sys.argv[1]) if len(sys.argv) > 1 else 20]:
    va = a + 0x100000
    where = [f'{o} {n}+{va - s:#x}' for s, sz, o, n in secs if s <= va < s + sz]
    print(f'{va:#x}-{e + 0x100000:#x} ({e - a + 1} bytes) {"; ".join(where)}')
    print(f'   retail {ret[a:min(e + 1, a + 24)].hex()}\n   ours   {img[a:min(e + 1, a + 24)].hex()}')
print(f'{len(runs)} differing ranges')
