import re

postText = ' http://test.com<br>'
r = re.compile(r"((http[s]?|ftp)+://(?:[a-zA-Z]|[0-9]|[$-_@.&+]|(?:[<>])|[!*\(\),]|(?:%[0-9a-fA-F][0-9a-fA-F]))+)")
result = r.sub(r'<a href="\1" target="_blank" rel="nofollow">\1</a>', postText)

print result


m = re.compile(r"((http[s]?)+://[^\s]+)")
print m.sub(r"[\1]", 'aaa http://abc<>')
m = re.compile(r"((http[s]?)+://([a-zA-Z0-9.]+))")
print m.sub(r"[\1]", 'aaa http://abc.com<>')
