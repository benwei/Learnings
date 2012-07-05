#!/usr/bin/env python

import sys;

pyscript = sys.stdin.read();

exec compile(pyscript, '__stdin__', 'exec');
