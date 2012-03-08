import urllib
a = u'http://tw.news.yahoo.com/\u9673\u51b2-\u614e\u91cd\u8003\u616e-\u79d1\u6280\u9810\u7b97\u5347\u81f3gdp3-213000296.html'

def urlencode(url):
    try:
        # url encode can not encode url with unicode
        return urllib.quote(url, '')
    except KeyError:
        pass

    u = unicode(url)
    return urllib.quote(u.encode( "utf-8" ), '')

print "Before urlencode: %s" % a
print "After urlencode: %s" % urlencode(a)
