from bwspeed import BWSpeed
import sys
verbose = 0

if len(sys.argv) > 1:
    if (sys.argv[1] == '-v'):
        verbose+=1

test_str = 'ad;fakdsf;jajd[]'

last = test_str[-1]
first = test_str[0]


def slog(msg):
    if (verbose > 0):
        print(msg)

loop_times = 10000
s = BWSpeed()
for i in range(loop_times):
    if ']' == last:
        slog('1. last char is ]')
        pass
print ("last char escaped ms:", s.escaped())
s = BWSpeed()
for i in range(loop_times):
    if test_str.endswith(']'):
        slog('2. last char is ]')
print ("endswith escaped ms:", s.escaped())

if 'a' == first:
    print('first char is a')

if test_str.startswith('a'):
    print('2. first char is a')
