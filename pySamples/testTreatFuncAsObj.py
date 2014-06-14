
def add(a, b):
    return a + b

def sub(a, b):
    return a - b

funs = [add, sub];

for f in funs:
    print f.__name__ + "=%d" % f(10, 4)
