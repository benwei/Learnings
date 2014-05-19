#!/usr/bin/env python

# get hint from http://stackoverflow.com/questions/1325673/python-how-to-add-property-to-a-class-dynamically

class Calc(dict):
    __getattr__= dict.__getitem__
    __setattr__= dict.__setitem__
    __delattr__= dict.__delitem__


caler = Calc()

caler.a = 100

print caler['a']

caler['b'] = 50

print caler.b

del caler['a']

print caler
