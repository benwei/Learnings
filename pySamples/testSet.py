#!python

a = set([1, 3, 5, 4])
b = set([1, 2, 3, 6])
c = a - b
print "%s - %s ==> %s" % (a, b, c)

m = a 
num = 9
a.add(num)
print "%s.add(%s) ==> %s" % (m, num, a)
c = a | b
print c
print "%s.issuperset(%s) ==> %s" % (c, b, c.issuperset(b))
d = a & b
print "%s & %s ==> %s" % (a, b, d)
