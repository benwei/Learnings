#!/usr/bin/env python
# source: http://stackoverflow.com/questions/3277367/how-does-pythons-super-work-with-multiple-inheritance

class First(object):
    def __init__(self):
        super(First, self).__init__()
        print "first"

class Second(object):
    def __init__(self):
        super(Second, self).__init__()
        print "second"

class Third(First, Second):
    def __init__(self):
        super(Third, self).__init__()
        print "that's it"


print Third.mro()
""" output:
[<class '__main__.Third'>, <class '__main__.First'>, <class '__main__.Second'>, <type 'object'>]
"""

third = Third()
""" output:
second
first
that's it
"""
