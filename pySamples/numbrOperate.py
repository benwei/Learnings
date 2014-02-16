#!/usr/bin/env python

from decimal import Decimal

## http://stackoverflow.com/questions/4643991/python-converting-string-into-decimal-number
A1 = [' "29.0" ',' "65.2" ',' "75.2" ']

result = [float(x.strip(' "')) for x in A1] 
print result

result = [Decimal(x.strip(' "')) for x in A1]

print result
