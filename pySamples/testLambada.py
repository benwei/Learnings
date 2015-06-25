#!/usr/bin/env python
import json
# -*- coding: utf-8 -*-
# support python 3 syntax

c = lambda x: x**2
#
# def c(x):
#     return x**2

print(c(10))

m = filter(lambda x: x % 3 == 0, [1,2,20,18,3,6])
for i in m:
    print(i)

