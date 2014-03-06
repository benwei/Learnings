#!/usr/bin/env python

# reference http://www.codedata.com.tw/python/python-tutorial-the-5th-class-3-assert-doctest/

ascending = False
descending = True

def mysorted(xs, compare=ascending):
    '''
    sorted(xs) -> new sorted list from xs' item in ascending order.
    sorted(xs, func) -> new sorted list. func should return a negative integer, 
    zero, or a positive integer as the first argument is 
    less than, equal to, or greater than the second.
    '''

    if type(compare) is bool:
        return [] if not xs else sorted(xs, reverse=compare)

    return [] if not xs else sorted(xs, compare)

if __name__ == '__main__':
    '''
    argument with -v show testing detail
    '''
    import doctest
    doctest.testfile("mysorted1_test.txt")
