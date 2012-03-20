
class MetaClass(type):
    def __new__(meta, classname, bases, classDict):
        print '>>>Class Name:%s,Bases:%s,attr:%s' % (classname, bases, classDict)
        print '==========================='
        print '%s.__new__(%s)' % (bases, classname)
        return type.__new__(meta, classname, bases, classDict)

    def __call__(meta):
        print "%s.__call__(%s) % (meta, value)"
        return type.__call__(meta, value)

# cls = type.__new__()

class Test(object):

    __metaclass__ = MetaClass

    def __init__(self, attr):
        print "Test.__init__(%s, %s)" % (self, attr)

    def method(self):
        return self.classAttribute

    classAttribute = 'Something'

a = Test('a')
print a.method()

class Curry:
    """handles arguments for callback functions"""
    def __init__(self, callback, *args, **kwargs):
        self.callback = callback
        self.args = args
        self.kwargs = kwargs

    def __call__(self):
        #return apply(self.callback, self.args, self.kwargs)
        return self.callback(*self.args, **self.kwargs) # since Python23

class TestCB(object):
        def __init__(self, *args, **kwargs):
           print args % kwargs

a = Curry(TestCB, "%s", a)

