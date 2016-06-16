#!/usr/bin/python
# tested python2.7, python3.4 ubuntu 14.04 trusty

import sys

if (sys.version_info > (3,0)):
    # due to python3 rename raw_input to input
    std_input = input
else:
    std_input = raw_input

str = std_input("Enter your name: ")
print("your name is ",str)
