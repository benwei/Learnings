#!/usr/bin/env python
# source: http://stackoverflow.com/questions/3277367/how-does-pythons-super-work-with-multiple-inheritance

class First(object):
    def __init__(self):
        print "first"

class Second(First):
    def __init__(self):
        print "second"

"""
TypeError: Error when calling the metaclass bases Cannot
create a consistent method resolution order (MRO) for
bases Second, First
"""
class Third(First, Second):
    def __init__(self):
        print "third"
