import time,types
import sys
from confbase import *

class conflib(confbase):
    def __init__(self, name, age):
        confbase.__init__(self, name, age)
        pass

    def show(self):
        print "%s is %syo." % (self.getName(), self.age)

    def sayHello(self):
        print "Hello, %s!" % (self.getName())
