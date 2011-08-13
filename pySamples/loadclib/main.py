#!/usr/bin/env python
# this sample is tested on cygwin + windows xp

from ctypes import *

libname = "test.dll"

try:
    foolib = cdll.LoadLibrary(libname)
except OSError:
   print "%s not found. Please build before test." % libname
   exit(1)

# check LBOUND
def verify_ifeq(param, ret_value, input_value, message): 
    if param == ret_value:
        print "%s:verified return value(%d) from test.foo(%d) [Passed]\n" % (message, param, input_value)
	return 0
    print "%s:verified return value(%d) from test.foo(%d) [Failed]\n" % (message, param, input_value)
    return 1

def verify_lbound():
    p = 0
    r = foolib.foo(p)
    return verify_ifeq(1, r, p,"case lbound")
def verify_ubound():
    p = 11
    r = foolib.foo(p)
    return verify_ifeq(10, r, p, "case ubound")

def verify_general():
    p = 5
    r = foolib.foo(p)
    return verify_ifeq(p, r, p, "case general")

# create testing list
a = []
a.append(verify_ubound)
a.append(verify_lbound)
a.append(verify_general)

# run test cases
ret = 0
runcase_count = 0
for testcase in a:
    ret += testcase()
    runcase_count+=1

# test cases summary
print "total/passed cases: %d/%d\n" % (runcase_count - ret, runcase_count)
if ret > 0:
    print "Python load %s [Failed]\n" % libname
    exit(1)

print "Python load %s [Passed]\n" % libname
exit(0)
