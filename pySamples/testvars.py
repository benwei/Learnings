#!python
class a(object):
    #__dict__ = ['a', 'b']
    b = ''
    def show():
        print 'a'

# pydoc vars
#vars() -- Help on built-in function vars in module __builtin__:
print vars(a)
print dir(a)
