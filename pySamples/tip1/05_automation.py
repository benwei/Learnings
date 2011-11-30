import unittest
from code_for_automation import *

class DefaultTestCase(unittest.TestCase):
    def testTestDog(self):
        sample="The dog has four legs."
        msg = get_animal_info1('dog')
        assert msg == sample , 'test dog message'

    def testTestChick(self):
        sample="The chick has two legs."
        msg = get_animal_info1('chick')
        assert msg == sample , 'test chick message'

    def testTestCat(self):
        sample="The cat has four legs."
        msg = get_animal_info1('cat')
        assert msg == sample , 'test cat message'


if __name__ == '__main__':
    myTestSuite = unittest.makeSuite(DefaultTestCase,'test')
    runner = unittest.TextTestRunner()
    runner.run(myTestSuite)
