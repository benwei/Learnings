#!/usr/bin/env python
a=[4, 0,1,2,3,89]
for i,x in enumerate(a):
    print "array[%d]-> %d" % (i,x)

la = [(i, j) for i, j in enumerate(a)]

for i, (m, n) in enumerate(la):
    print "%d: m=%d, n=%d" % (i, m, n)

