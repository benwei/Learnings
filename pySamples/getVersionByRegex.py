import re
from sys import argv, exit
L = ["aaaa.aaaA", "1.0", "1.0.1004aaa", "b0.70.1040", "0a.0b.0c"]

X = "(\d+\.\d+\.\d+)"
verbose = 0

def re1():
    p = re.compile(X)
    for s in L:
        a = p.search(s)
        if a and verbose:
            print s[a.start():a.end()]

def re2():
    for s in L:
        a = re.compile(X).search(s)
        if a and verbose:
            print s[a.start():a.end()]

if len(argv) < 3:
   print("syntax: <re1|re2> <loopmax>")
   exit(1)

loopMax = int(argv[2])
action= 1
if argv[1] == "re2":
   action = 2

i = 0
if action == 1:
    while (i < loopMax):
       re1()
       i = i + 1
else:
    while (i < loopMax):
       re2()
       i = i + 1
