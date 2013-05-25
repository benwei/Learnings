#!/usr/bin/env python
#http://stackoverflow.com/questions/1848474/method-resolution-order-mro-in-new-style-python-classes

class A(object): x = 'a'
class B(A): pass
class C(A): x = 'c'
class D(B, C): pass

print D.x
# support MRO so answer should be 'c'
print D.__mro__
