#!/usr/bin/env python
# source from http://docs.pylint.org/tutorial.html
# C:  1: Missing docstring (missing-docstring)
# pylint --help-msg=missing-docstring
"""This script prompts a user to enter a message to encode or decode
using a classic Caeser shift substitution (3 letter shift)"""
# 
# pylint --reports=n --disable=deprecated-module \
#        --const-rgx='[a-z_][a-z0-9_]{2,30}$' simplecaeser.py
# use the following inline option disable-msg to disable deprecated message
# reference stackoverflow questions 4341746 how-do-i-disable-a-pylint-warning
# pylint:disable-msg=W0402

import string


SHIFT = 3

def myencoded(word, letters, shift = SHIFT):
    """ docstring for my encoded api """
    encoded = ''
    for letter in word:
        if letter == ' ':
            encoded = encoded + ' '
        else:
            index = letters.index(letter) + shift
            encoded = encoded + letters[index]
    return encoded

def mydecoded(word, letters):
    """ docstring for my decoded api """
    return myencoded(word, letters, -SHIFT)

def main():
    """ main entry point """
    choice = raw_input("would you like to encode or decode?")
    word = (raw_input("Please enter text"))
    letters = string.ascii_letters + string.punctuation + string.digits
    result = ''
    if choice == "encode":
        result = myencoded(word, letters)
    elif choice == "decode":
        result = mydecoded(word, letters)

    print result
