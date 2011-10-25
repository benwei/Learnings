#!/usr/bin/env python
import time

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

import datetime
# datetime timedelta
b = datetime.datetime(2009, 2, 1, 22)
a = datetime.timedelta(hours=10)
print b
print b - a
c = datetime.timedelta(seconds=10)
print b - c
