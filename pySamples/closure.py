#!/usr/bin/env python
# reference:
# http://stackoverflow.com/questions/3190706/nonlocal-keyword-in-python-2-x
# http://en.wikipedia.org/wiki/Closure_(computer_science)#Example
#
def counter():
    d = {'x': 0 } # use work with python 2.7.2
    def increment(y):
      # nonlocal only work for python3
      #nonlocal x
      d['x'] += y
      print d['x']
    return increment
      
counter1_increment = counter()  # counter() returns a closure containing a
    # reference to the function increment()  
    # and increment()'s non-local variable x
counter2_increment = counter()  # a second closure, containing a second 
    # instance of the variable x
            
counter1_increment(1)    # prints 1
counter1_increment(7)    # prints 8
counter2_increment(1)    # prints 1
counter1_increment(1)    # prints 9
