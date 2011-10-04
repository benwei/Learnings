#!/usr/bin/python
import sys

try:
    import yourmodule
except:
    print "no module existed"
    # try include by different version of python
    if sys.version_info[:2] >= (2,6):
        print "import yourmodule_26"
        print sys.version_info
        print "import yourmodule_generic"
