
#-*- coding: utf-8 -*-
import json

a = [-1, 1, 66.25, 333, 333, 1234.5]
print a
del a[5:]

print len(a)
print a

for i in range(20):
    print i

test = "test\ntest111\ntest222\n"

vals = test.split('\n')

print len(vals),vals
import types
if isinstance(a, types.ListType):
    print "type is ListType"

testlist = [
 {'t':'2', 'n':'a'},
 {'t':'1', 'n':'b'},
 {'t':'2', 'n':'c'},
 {'t':'1', 'n':'d'},
 {'t':'2', 'n':'e'},
]

b = testlist[1]
rmlist = []
index = 0
for item in testlist:
    if 't' in item and item['t'] == '1':
        rmlist.insert(0,index)
        print 'appendrmlist[%s]: %s' % (index, item)
    print item
    index +=1

for item in rmlist:
    print 'rm: %s from list' % item
    del testlist[item]

print "testlist count=%s" % len(testlist)
for item in testlist:
    print item

# check string in stringlist

name_list = ['a', 'bb', 'cc']
for i in ['a', 'cc']:
    if i in name_list:
        print '%s found' % i


