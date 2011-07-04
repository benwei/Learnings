#!/usr/bin/python
import os
import sys

# support for python 2.5

try:
    open("/var/log/test.log", 'w') # os.O_RDWR|os.O_CREAT)
except:
    print "Sorry:%s %s" % (sys.exc_type ,  sys.exc_value)

try:
    open("/var/log/test.log", 'w') # os.O_RDWR|os.O_CREAT)
except IOError, v:
    try:
       (code, msg) = v
    except:
       code = 0
       msg
    print "I/O Error:%d %s" % (code , msg)
