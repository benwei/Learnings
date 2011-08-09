# this sample is tested on cygwin + windows xp
from ctypes import *
foolib = cdll.LoadLibrary("test.dll")
r = foolib.foo(4)
print "value(%d) from test.foo(4)" % r

exit(r)
