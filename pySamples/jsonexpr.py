import json
from StringIO import StringIO
# reference the samples from http://docs.python.org/library/json.html
# tested on python 2.6.5 cygwin winxp
dataBlobs = [{'title': 'json Blobs'}, {'payload': ('item', 1.0, 2)}]

# dumps data with sorted keys and layout indent, human readable format
print json.dumps(dataBlobs,
		sort_keys=True, indent=4)

# dump blobs to a string
io = StringIO()
json.dump(dataBlobs, io)
print io.getvalue()

# using different separators
print json.dumps(dataBlobs, separators=(',',':'))

# decode data from string
loadedBlobs = json.loads('[{"type": "string", "title":"json Blobs"}, {"type": "payload", "payload":["item",1.0,2]}]')

# list contents in type
for x in loadedBlobs:
	print "element: %s" % x["type"]

