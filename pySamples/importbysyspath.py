#!/usr/bin/env python
# information from mat at http://www.hackingthursday.org/2011-07-07
import sys
sys.path.append('./moduleInclude/')
from conflib import *
c = conflib("test import with sys.path.append().", 1)
c.show()

