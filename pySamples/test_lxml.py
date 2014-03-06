#!/usr/bin/env python
## require to install
### sudo pip install html5lib
## code reference http://lxml.de/html5parser.html
from lxml.html import tostring, fromstring, builder as E
from lxml import etree

htmltext='''
my text in beginning
<div>This is a first div</div>
<table>
<tr>
<td>foo1</td><td>hello 1</td></tr>
<tr><td>ooo2</td><td>world 2</td></tr>
<div>This is a last div</div>
</table>
<a href="/testhtml.html">test heml</a>
'''
## note: using the html5parser.fromstring and lxml.html.fromstring is different.
##       html5parser creates elements with html info so that you cannot use 

print "\n=> dump html.fromstring() elements"    
h = fromstring(htmltext)

def display_text_element(el):
    print el.tag + ": " + el.text_content()

def el_table_handle(el):
    for tr in el:
        for td in tr:
            print td.tag, td.text

element_caller = {
        "div": display_text_element,
        "table": el_table_handle,      
        "p": display_text_element,      
}

def dump_elements(h):
    for el in h:
        try:
            func = element_caller[el.tag]
        except:
            print "undefined tag: ", el.tag
            continue

        func(el)
    return 0

dump_elements(h)

print "\n=> dump etree.fromstring() elements"    
node = etree.fromstring('''
        <content>
        test head
<div>This is a div1</div>
<div>This is a div2</div>
test tail
        </content>
''')

print node.text
print "node count", len(node)
for el in node:
    print el.tag
    if el.tag == 'div':
        print el.text
    
