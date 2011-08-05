#!/usr/bin/env python
import sys
from os import path
# update ben: if you would like to force the fist seeking from your folder
# you can use sys.path.insert
sys.path.insert(0, path.abspath('./moduleInclude/'))

from conflib import *
c = conflib("MR. Python", 1)
c.sayHello()

