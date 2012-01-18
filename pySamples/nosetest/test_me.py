import nose, sys
import unittest

# reference with http://ivory.idyll.org/articles/nose-intro.html#a-few-simple-examples
# run nosetests
# -$ nosetests -v test_me.py

class ExampleTest(unittest.TestCase):
    def test_a(self):
        self.assert_(1 == 1)

def test_a():
    # should failure
    assert 'a' == 'b'

def test_b():
    assert 'b' == 'b'

if __name__ == '__main__':
    nose.runmodule()
