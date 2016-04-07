#!/usr/bin/env python
# reference: https://wiki.python.org/moin/PythonDecorators#What_is_a_Decorator
# example: using decorator for format text

def html_decorate(target):
    def wrapper_html(name):
        return "<html>{0}</html>".format(target(name))
    return wrapper_html 

@html_decorate
def mybody(name):
    return "<body>{0}</body>".format(name)
    
print(mybody('test'))
