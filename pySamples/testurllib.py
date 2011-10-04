#!/usr/bin/env python
import urllib,urllib2

print urllib2.quote("test@gmail.com")

def testcase1():
    f = urllib.urlopen("http://google.com");
    print f.headers.dict
    print "length:%d" % len(f.read())

# Charles 3.6.3 is a proxy server
# Proxy handler
#proxy_support= {"http", "test.com:8080"}

#opener = urllib2.build_opener(proxy_support)
#request = urllib2.Request("http://www.google.com")
#opener.open(request)

import urlparse
x = urlparse.urlsplit("http://www.xxx.com:8081/testx/tese2.htm?a=111")
print x


