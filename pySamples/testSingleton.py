#!python
# http://stackoverflow.com/questions/42558/python-and-the-singleton-pattern

class Singleton(type):
    def __init__(cls, name, bases, dict):
        super(Singleton, cls).__init__(name, bases, dict)
        cls.instance = None 

    def __call__(cls,*args,**kw):
        if cls.instance is None:
            cls.instance = super(Singleton, cls).__call__(*args, **kw)
        return cls.instance

class MsgSingleton(object):
    _value = None
    __metaclass__ = Singleton
    def __init__(self, value, value2):
        self._value = value 

    def getValue(self):
        print "v:%s" % self._value
        return self._value

if __name__ == '__main__':
    s1=MsgSingleton(1, 2)
    s2=MsgSingleton(2, 3)
    if(id(s1)==id(s2) and s1.getValue() == s2.getValue()):
        print "Singletion Pass (%s)" % s1.getValue()
    else:
        print "Not Singletion Implement"

