import sys

def test():
    print "getattr current mode run: test()"

o = getattr(sys.modules[__name__], 'test')
if o:
    o()
