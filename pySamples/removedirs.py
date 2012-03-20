#!/usr/bin/env python
import shutil
import sys

try:
    shutil.rmtree("testrm");
except OSError, e:
    if e.errno == 2:
       print "directory has been removed."
       sys.exit()
    print e

#shutil.copy2
#shutil.copytree

