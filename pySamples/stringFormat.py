#!/usr/bin/env python
# for python 2.7
# valueError on python 2.6
try:
    print "{} {} {}".format(1, 2, "sun")
    print "{} {day} {}".format(1, "sun", day=2)
except valueError:
    print "valueError if python version before 2.7"

import binascii
print binascii.b2a_hex("\x01\x02\x38")
print binascii.a2b_hex("313238")
