#!/usr/bin/env python
# 2016-03-28 written by Ben Wei
# Demo code for Colorful Progress Bar
# tested with Python 2.7.6 Ubuntu 14.04.3 LTS
import time
import sys

class Color:
    BLUE = '\033[94m'
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    WHITE= '\033[0m'
    BOLD = '\033[1m'

class ProgressBar:
    prefix = ""
    suffix = ""
    width = 20
    def __init__(self, initValue, tickValue=1):
        self.value = initValue
        self.tickValue = tickValue

    def update(self, value):
        self.value = value

    def tick(self):
        self.value += self.tickValue
        if self.value > 100:
            self.value = 100

    def show(self):
        n = self.value / (100 / self.width)
        if self.value == 100:
            sign = ''
        else:
            sign = '>'

        bar = "".join([Color.GREEN, '|', "=" * n, sign, "." * (self.width-n-1), '|'])
        sys.stdout.write("\r%s %s %s%3d%%%s" % (self.prefix, bar, Color.BLUE, self.value, self.suffix))
        sys.stdout.flush()

    def finish(self):
        sys.stdout.write("\n%s" % Color.WHITE);
        sys.stdout.flush()

# main
print "Demo progress bar"
delta = 1
count = 100/delta
pb = ProgressBar(0, tickValue=delta)
pb.width = 50
pb.prefix = "%sUpdating " % ("".join([Color.BOLD, Color.YELLOW]))
pb.suffix = ""
for i in range(1,count+1):
    pb.tick()
    pb.show()
    time.sleep(0.05)

pb.finish()
