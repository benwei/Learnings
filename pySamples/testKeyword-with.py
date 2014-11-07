#!/usr/bin/env python
import os
testfile = "test1.txt"
with open(testfile, "w") as f:
    for i in range(10):
        f.write("test %d\n" % i);

f = open(testfile, 'r')
while True:
    line = f.readline()
    if not line:
        break
    print(line.replace('\n', ''))

f.close()
os.remove(testfile)
