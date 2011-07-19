
import sys

# Make sure python version is 2.3 above
verlist = sys.version_info
if not verlist[0] >= 2 or not verlist[1] >= 3:
    raise AssertionError, "Python version is 2.3 above"


from conflib import *
