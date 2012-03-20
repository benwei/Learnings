#!/usr/bin/env python
# -*- coding: utf-8 -*-

a = ("123")

b = ("456",)
def dumpinfo(t):
    print "len(%s)=%s" % (t, len(t))
    if isinstance(t, basestring):
       print "'%s'[0]=%s" % (t, t[0])
    else:
       print "%s[0]=%s" % (t, t[0])
dumpinfo(a)
# 3
# 1
dumpinfo(b)
# 1
# 456
