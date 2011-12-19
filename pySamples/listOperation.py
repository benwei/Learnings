
#-*- coding: utf-8 -*-
import json

a = [-1, 1, 66.25, 333, 333, 1234.5]
print a
del a[5:]

print len(a)
print a

for i in range(20):
    print i

test = "test\ntest111\ntest222\n"

vals = test.split('\n')

print len(vals),vals
