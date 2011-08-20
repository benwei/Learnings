#!/usr/bin/env python
# print num at the same line while num is updating.
import sys
from time import sleep
for i in range(100):
    if i % 15 == 0:
        sleep(1)
    # bellow line is not working at python 2.6.5 in cygwin
    # print '%d\r',
    # cygwin+Python 2.6.5 test passed,
    # use the flush() to send out data in line buffer.
    sys.stdout.write('%d\r' % i)
    sys.stdout.flush()
