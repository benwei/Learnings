#!/usr/bin/env python
# this sample is tested on cygwin + windows xp

from ctypes import *
import sys

if len(sys.argv) <= 1:
    print("syntax: <libname>")
    exit(1)

libname = sys.argv[1]

try:
    foolib = cdll.LoadLibrary(libname)
except OSError:
   print("%s not found. Please build before test." % libname)
   exit(1)

foolib.say_hello.argtypes=[c_char_p]
foolib.get_version.argtypes=[c_char_p, c_int]

# check LBOUND
def verify_ifeq(param, ret_value, input_value, message): 
    if param == ret_value:
        print("[Passed] %s:verified return value(%d) from test.foo(%d)" % (message, param, input_value))
        return 0;
    print("[Fail]   %s:verified return value(%d) from test.foo(%d)" % (message, param, input_value))
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
    print("\n")
    return verify_ifeq(p, r, p, "case general")


def test_say_hello():
    m = b"Python\n\n"
    foolib.say_hello(m)
    return 0

def test_get_version():
    size = 9
    rbuf = create_string_buffer(b'\000' * size)
    expect_buf = create_string_buffer(b'012345678')

    r = foolib.get_version(rbuf, size+1)
    # 2025.05.20 fix python3 for string buffer comparison
    if expect_buf.value == rbuf.value:
        print("[Passed] case get_version( {} ) vs expect( {} )".format(
              rbuf.value, expect_buf.value ))
        return 0
    
    print("[Fail] case get_version {}".format(rbuf.value))
    return 1

# create testing list
a = []
a.append(verify_ubound)
a.append(verify_lbound)
a.append(verify_general)
a.append(test_say_hello)
a.append(test_get_version)

# run test cases
ret = 0
runcase_count = 0
for testcase in a:
    ret += testcase()
    runcase_count+=1

# test cases summary
print("total/passed cases: %d/%d" % (runcase_count - ret, runcase_count))
if ret > 0:
    print("[Failed] Python load %s" % libname)
    exit(1)

print("[Passed] Python load %s" % libname)
exit(0)
