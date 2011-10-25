#!/usr/bin/env python

from bemod.date8601 import Date8601

FMT8601String = "%Y-%m-%dT%H:%M:%SZ"
data = "2007-03-04T21:08:12Z"
cmpresult = "2007-03-04T21:08:11Z"

d  = Date8601(data)
result = d.to8601String()
if result == data:
    print "Date time 8601 case 1: OK"

d.addDelta(1)

result = d.to8601String()

if result == cmpresult:
    print "Date time 8601 case 2: OK"
