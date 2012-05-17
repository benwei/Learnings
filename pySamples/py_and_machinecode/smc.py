# sample from http://blog.linux.org.tw/~jserv/archives/2012/05/_python_shellco.html
# [ben] add 64 bits support

from ctypes import *
import sys
from math import log

libc = CDLL('libc.so.6')
mprotect = libc.mprotect
getpagesize = libc.getpagesize

PROT_READ = 0x1
PROT_WRITE = 0x2
PROT_EXEC = 0x4

arch=32
def is64bit():
    return log(sys.maxsize, 2) == 63

if is64bit():
    arch=64
    codes = (c_ubyte * 32)(
    0x8d, 0x04, 0x37,   # lea    (%rdi,%rsi,1),%eax
    0xc3                # retq
    )
else:
    codes = (c_ubyte * 32)(
    0x55,               # push   %ebp
    0x89, 0xe5,         # mov    %esp,%ebp
    0x8b, 0x45, 0x0c,   # mov    0xc(%ebp),%eax
    0x8b, 0x55, 0x08,   # mov    0x8(%ebp),%edx
    0x01, 0xd0,         # add    %edx,%eax
    0x5d,               # pop    %ebp
    0xc3                # ret 
    )

p = addressof(codes) & ~(getpagesize() - 1)
mprotect(p, getpagesize(), PROT_READ | PROT_WRITE | PROT_EXEC)
add_func = CFUNCTYPE(c_int, c_int, c_int)(addressof(codes))

print "add%d(99, 1) = %d" % (arch, add_func(99, 1))
