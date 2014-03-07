#!/usr/bin/env python

# reference this slide http://www.slideshare.net/hexdump42/pypy-isitreadyforproductionthesequel
import ctypes
crypt = ctypes.CDLL('libcrypt.so').crypt
crypt.argtypes = ctypes.c_char_p, ctypes.c_char_p
crypt.restype = ctypes.POINTER(ctypes.c_char * 13)
encoded = crypt('my secret', 'z9').contents.value
print encoded

