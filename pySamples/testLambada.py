#!/usr/bin/env python
# -*- coding: utf-8 -*-

c = lambda x: x**2
#
# def c(x):
#     return x**2

print c(10);

m = filter(lambda x: x % 3 == 0, [1,2,20,18,3,6])
print m

