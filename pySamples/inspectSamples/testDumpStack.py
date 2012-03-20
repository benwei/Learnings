#!python
# info from http://docs.python.org/library/inspect.html#inspect.getargspec
import inspect

def testFunc(a, b):
    for i in inspect.stack():
        print i

def testHello(b):
    testFunc('2', b)

def main():
    testHello('1')

if __name__ == '__main__':
    main()
