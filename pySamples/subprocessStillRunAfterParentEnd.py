#!/usr/bin/env python

import subprocess

# test passed on cygwin + python 2.6.5
cmd = 'sleep 2;echo "shell is running after parent ended"'
p = subprocess.Popen(cmd, shell=True)
print 'end of program'
