import zipfile
import sys
if len(sys.argv) < 2:
    print "syntax: <zipfile>"
    sys.exit(1)

z = zipfile.ZipFile(sys.argv[1], 'r')
z.extractall('.')
