import unittest
from main import *

class TestSequenceFunctions(unittest.TestCase):

    def setUp(self):
        print "set Up Caller"
        self.caller = Caller()

    def test_caller_init(self):
        c = self.caller
        c = Caller()
        value = c.refCount()
        self.assertEqual(value, 0)

    def test_caller(self):
        c = self.caller
        c.addRef()
        value = c.refCount()
        self.assertEqual(value, 1)

    def test_sample(self):
        c = self.caller
        c = Caller()
        c.addRef()
        self.assertTrue(c.isUsed())

    def tearDown(self):
        print "tear down Caller"

if __name__ == '__main__':
    unittest.main()
