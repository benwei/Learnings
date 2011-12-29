#!/usr/bin/env python
import time
import datetime

# gmtime()
gmt = time.gmtime()
print gmt

# localtime
print time.localtime()

# mktime()
t = time.mktime(gmt)
print t

# strftime()
print time.strftime("%Y-%m-%d")

from datetime import date
from dateutil.relativedelta import relativedelta

def getSummeryDateStr():
    d = datetime.date.fromtimestamp(time.time())
    print "date: %s" % d
    print "year-month: %s-%s-%s" % (d.year, d.month, d.day)
    # datetime timedelta
    d_offset = d + relativedelta( months = +1)
    b = datetime.datetime(d_offset.year, d_offset.month, 1)
    e = datetime.timedelta(seconds=1)
    return (b - e)


print "getSummeryDateStr = %s" % getSummeryDateStr()

d = datetime.date.fromtimestamp(time.time())
six_months = d + relativedelta( months = +6 )
print six_months

b = datetime.datetime(d.year, d.month, 1)
a = datetime.timedelta(hours=10)
print b - a
c = datetime.timedelta(seconds=10)
print b - c
