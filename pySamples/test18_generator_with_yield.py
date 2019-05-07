#!/usr/bin/python3
# tested with python3.5 and python3.6
class CLS_sum(object):
    def __init__(self, dmax):
        self.dmax = dmax
        self.s = 0
        self.n = 1

    def __iter__(self):
        return self

    def __next__(self):
        if self.n < self.dmax:
            self.s += self.n
            r = self.s
            self.n += 1
            return r
        raise StopIteration()

# alternative write method of CLS_sum
def sum_generator(dmax):
    n = 1
    s = 0
    while n < dmax:
        s = s+n
        yield s
        n = n+1

upbound=11

def test_g1():
    n = 0
    print("==g1")
    g1 = CLS_sum(upbound)
    for n in g1:
        print(n)
    assert(n == 55)

def test_g2():
    n = 0
    print("==g2")
    g2 = sum_generator(upbound)
    for n in g2:
        print(n)
    assert(n == 55)

def main():
    test_g1()
    test_g2()

if __name__ == "__main__":
    main()
