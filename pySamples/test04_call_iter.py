import sys
a = [ 10, 9, 4, 6, 5, 3]
b = iter(a)


def test():
    onerror=False
    while(not onerror):
        try:
            c = b.next()
            print c
        except:
            onerror=True

test()
