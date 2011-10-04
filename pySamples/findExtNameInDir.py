import os
import sys

(mpath, mname) = os.path.split(sys.argv[0])

def findInSubdirectory(filename, subdirectory=''):
    if subdirectory:
        path = subdirectory
    else:
        path = os.getcwd()
    for root, dirs, names in os.walk(path):
        if filename in names:
            return os.path.join(root, filename)
    raise 'File not found'


def findExtInSubdirectory(ext, subdirectory=''):
    if subdirectory:
        path = subdirectory
    else:
        if len(mpath):
            path = mpath
            print "Use mpath"
        else:
            path = os.getcwd()
            print "Use getcwd()"
    for fn in os.listdir(path):
        dstext = ''
        try:
            dstext=os.path.splitext(fn)[1]
            if ext == dstext:
                print "v[%s] -> %s" % (dstext, fn)
            elif len(dstext)>0:
                print "x[%s] -> %s" % (dstext, fn)
        except: pass
    print 'File not found'


findExtInSubdirectory(".mpkg")
