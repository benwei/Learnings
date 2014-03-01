#!/usr/bin/env python
## require to install
### sudo pip install html5lib
## code reference http://lxml.de/html5parser.html
from lxml.html import tostring, html5parser

print tostring(html5parser.fromstring("<table><td>foo"))

