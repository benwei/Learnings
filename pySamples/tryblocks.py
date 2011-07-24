#!/usr/bin/env python
# reference http://c2.com/cgi/wiki?BlocksInPython
# tested at python-2.6.6 ubuntu
# try blocks by lambda
class blocker():
    def __init__(self, start, difference, repeat):
        self.elm = start
        self.repeat = repeat
        self.diff = difference

    def collect(self, callback):
        for i in xrange(self.repeat):
            yield callback(self.diff)

    def calc(self, x):
        elm = self.elm
        self.elm += x
        return elm


# main
## lambda equal to
# def caller(x):
#    return calc(x)

a = blocker(2, 2, 4)

def blockertest():
    for x in a.collect(lambda x: a.calc(x)):
        print x

blockertest()
