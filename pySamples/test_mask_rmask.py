#!/usr/bin/env python

def mask(n):
        return (2L << n -1) -1

def rmask(n):
        return (0xffffffff << n) & 0xffffffff

# mask
for i in [32, 16, 8]:
    print " mask[%2d]=%08x" % (i, mask(i))

# reserve mask
for i in [32, 16, 8]:
    print "rmask[%2d]=%08x" % (i, rmask(i))
