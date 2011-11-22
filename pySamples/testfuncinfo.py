import inspect
import sys
import dis

def getFuncName():
    return inspect.stack()[1][3]

def getCallFuncName():
    return inspect.stack()[2][3]

def afunc(b):
    print b
    print dir(afunc)
    print "func_name=%s" % afunc.func_name
    print "caller func_name=%s" % getCallFuncName()
    print "%s->%s:%s" % ( FILE(), FUNC(), LINE() )

def tryDis():
    print "dis func_name=%s" % dis.dis(afunc)


def LINE( back = 0 ):
    return sys._getframe( back + 1 ).f_lineno
def FILE( back = 0 ):
    return sys._getframe( back + 1 ).f_code.co_filename
def FUNC( back = 0):
    return sys._getframe( back + 1 ).f_code.co_name
def WHERE( back = 0 ):
    frame = sys._getframe( back + 1 )
    return "%s/%s %s()" % ( os.path.basename( frame.f_code.co_filename ),     
                            frame.f_lineno, frame.f_code.co_name )

print "Here in %s, file %s, line %s" % ( FUNC(), FILE(), LINE() )

afunc(1)
