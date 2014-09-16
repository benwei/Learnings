#!/usr/bin/env python

# sample to args , and kwargs
class arger(object):
    def __init__(self, *args, **kwargs):
        print("*args = %s, **kwargs = %s" % (type(args), type(kwargs)))
        print "args = %s, kwargs = %s" % args, kwargs

    def test(self):
        pass


m = arger("a", "b", k1={'d': '1', 'c': 2});
#result:
#args = <type 'tuple'>, **kwargs = <type 'dict'>
#args = a, kwargs = b {'k1': {'c': 2, 'd': '1'}}

def test_fun(arg1, arg2, arg3):
    print "test_fun %s, %s , %s" % (arg1, arg2, arg3)

args = ["a", "b"]

test_fun('1', *args)
# output: test_fun 1, a , b

kwargs = {'arg1': '6', 'arg2': '7', 'arg3':'8'}

test_fun(**kwargs)
# output test_fun 6, 7 , 8

