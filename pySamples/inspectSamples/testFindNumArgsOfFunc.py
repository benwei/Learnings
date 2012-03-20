#!python
# info from http://docs.python.org/library/inspect.html#inspect.getargspec
import inspect

def testFunc(a, b):
    print a, b

def testHello(b):
    print b

def main():
    cblist = [testFunc, testHello]

    for cb in cblist:
        cbspec = inspect.getargspec(cb)
        print cbspec
        print "%s(%s)" % (cb.__name__, cbspec.args)

if __name__ == '__main__':
    main()
