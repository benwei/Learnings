#!/usr/bin/env python
# closure machanism

def a():
        x = 1
        y = 2
        return lambda x: x+y+1

class closure():
    ref_count = 0
    fn_run_count = 0
    def __init__(self):
        self.fn_base_x = 1
        pass

    @staticmethod
    def getinstance():
        return 23

    def call(self, x):

        self.fn_base_x = x
        def fn(x):
            closure.fn_run_count+=1
            return self.fn_base_x + 1

        # static variable
        closure.ref_count+=1

        return fn

# lambda x: x+1
# def fn(x):
#    retrun x+1

c = a()
clo = closure()
e = closure().call(34)
d = clo.call(10)
f = clo.call(20)

inc=3
for elm in [d,e,f]:
        print "fn(%s)=%s" % (inc,elm(inc))

print "ref_count=%s" % (closure.ref_count)
print "global var = %s" % (closure.getinstance())
