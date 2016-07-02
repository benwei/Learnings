# test in python 3.4 ubuntu 14.04
def testListMerge():
    """
    >>> testListMerge()
    '[1, 2, 3] + [5, 6, 3] = [1, 2, 3, 5, 6, 3]'
    """
    a = [1, 2, 3]
    b = [5, 6, 3]
    asum = a + b

    return "{} + {} = {}".format(a, b, asum)

if __name__ == '__main__':
    import doctest
    doctest.testmod()
