#!/usr/bin/env python

class entryDisp(object):
    def __init__(self, f):
        self.f = f;

    def __call__(self, *args):
        print("called %s" % self.f.__name__)
        r = self.f(*args)
        return r

@entryDisp
def test1(arg):
    return "test1(%d)" % arg

class entryArgs(object):
    def __init__(self, *args):

        self.arg1 = args[0]
        if (len(args) == 2):
            self.arg2 = args[1]
        else:
            self.arg2 = 0

    def __call__(self, f):
        print("called %s" % (f.__name__))

        def func_call_2(arg):
            return "%s => %d" % (arg,  (self.arg1 + self.arg2));

        return func_call_2

@entryArgs(5, 9)
def test2(arg):
    return "test2(%d)" % arg


@entryArgs(5)
def test3(arg):
    return "test2(%d)" % arg

print("--- main ---")

# equal entryDisp(test(100))
print(test1(100))

# equal entryArg2(5,9)(test2(200));
print(test2(200))

# equal entryArg2(5,9)(test2(200));
print(test3(300))
