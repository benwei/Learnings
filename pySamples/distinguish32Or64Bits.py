#!/usr/bin/arch -i386 /usr/bin/python
# the arch -i386 is not working on cygwin
import sys
from math import log

def getNumBits():
   return log(sys.maxsize, 2)

# without -i386
# 2**63 - 1= 9223372036854775807
# VERSIONER_PYTHON_PREFER_32_BIT
# 2**30 -1 = 2147483647d
def dumpInfo():
    print "maxsize: %d" % sys.maxsize
    print "hello: %u" % sys.maxint
    print "log(sys.maxsize, 2) = %d" % getNumBits()

def is64bit():
    return getNumBits() == 63

## Results on 10.6.7 (SnowLeopard 64-bit) and 10.7 (Lion 64-bit)
# maxsize: 9223372036854775807
# hello: 9223372036854775807
# log(sys.maxsize, 2) = 63
## Results on cygwin (Windows xp sp3 64-bit)
# maxsize: 2147483647
# hello: 2147483647
# log(sys.maxsize, 2) = 30

if __name__ == '__main__':
    import clime
    clime.main()
