#!python

from types import MethodType

class MyObject:
    pass

class ExtObject:
    def __init__(self, k, v):
        self.set(k, v)

    def set(self, k, v):
        setattr(self, k, v)

    def remove(self, k):
        try:
            delattr(self, k)
        except:
            pass

    def show(self, k):
        try:
            print getattr(self, k)
            return
        except:
            pass
        print "no attr %s" % k

a = ['a', 'b', 'c']
try:
    if b == None:
        print 'b is None'
    r = a[0]
    if r:
       print "test %s" % r
except:
    print "not existed a.b"

myObject = MyObject()

if hasattr(myObject, 'myVar'):
    print myObject.myVar
else:
    print 'not defined attr myVar'

obj = ExtObject('a', 10)

print obj.a
obj.a = 1

# equal to print obj.a
obj.show('a')
key='b'
obj.show(key)
obj.set(key, 2)
obj.show(key)
if hasattr(obj, key):
    print 'new add %s' % key

obj.remove('a')

if not hasattr(obj, 'a'):
    print "attr has been deleted"

# test add method
def myshow(obj, k):
    if hasattr(obj, k):
        print "myshow(%s)=%s" % (k, obj.k)
    else:
        print "not found myshow(%s)" % (k, obj.k)



obj.set('myshow', myshow)
try:
    obj.myshow('b')
except:
    print 'no method myshow'

obj.myshow = MethodType(myshow, None, Ex)
