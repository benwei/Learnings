#!/usr/bin/env python 
# Variable At global scope 

globalVar = 1
divisor = 7

def one():
      "increase a global variable, return reminder from 11/7."
      global globalVar  # if you want to modified the global variable, you have to define it will keyword "global"
      globalVar += 10
      localVar = globalVar % divisor
      return localVar

print one.__doc__
for i in xrange(3):
    reminder = one()
    print "a = q * d(%d) + r\n a=%d\n r=%d\n" % (divisor, globalVar, reminder)

# testing undefined local varible of one()
try:
    print "localVar has the value %d\n" % localVar
except NameError, v:
    try:
        (code, msg) = v
    except:
        code = 0
        msg = v
    print "tested expected error:%d %s" % (code , msg)

