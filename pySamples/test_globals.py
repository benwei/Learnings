#!/usr/bin/env python

a1=10
a2=6
a3=9
a4=1
a5=7

for i in range(1,7):
    avar = None
    try:
        avar = globals()['a%d' % i]
    except KeyError:
        pass
    
    print "globals()[%s] => %s" % (i, avar)
