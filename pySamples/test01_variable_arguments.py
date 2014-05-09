#!/usr/bin/env python

# modified from: http://stackoverflow.com/questions/919680/python-can-a-variable-number-of-arguments-be-passed-to-a-function

def manyArgs(*arg):
      print "argc %d, argv: %s " % (len(arg), arg)

manyArgs(1)
manyArgs(1,2,3)
## results at debian 7: python 2.7.3
# argc 1, argv: (1,)
# argc 3, argv: (1, 2, 3)

