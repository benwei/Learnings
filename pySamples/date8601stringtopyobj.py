#!/usr/bin/env python

from bemod.date8601 import Date8601

def check_if(expr, caseId, message):
    if expr:
       result = "OK"
    else:
       result = "Fail"
    print "case %s(%s):%s" % (caseId, message, result)

FMT8601String = "%Y-%m-%dT%H:%M:%SZ"
data = "2007-03-04T21:08:12Z"
cmpresult = "2007-03-04T21:08:11Z"

# case 1
d  = Date8601(data)
result = d.to8601String()
check_if(result == data, 1, "str8601 to datetime")

# case 2
d.addDelta(-1)
result = d.to8601String()
check_if(result == cmpresult, 2, "datetime with delta to str8601")
d.addDelta(1)
# case 3
d.subDelta(1)
result = d.to8601String()
check_if(result == cmpresult, 3, "datetime with delta to str8601")
