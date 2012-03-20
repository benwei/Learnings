#!/usr/bin/env python
import sys
import getopt

def usage():
    print "syntax: <-v number | number>"

def main(argv):
    grammar = ""
    value = None
    try:
        opts, args = getopt.getopt(argv, "hg:dv:", ["help", "grammar="])
    except getopt.GetoptError:
        usage()
        sys.exit(2)
    for opt, arg in opts:
        if opt in ("-h", "--help"):
            usage()
            sys.exit()
        elif opt == '-d':
            global _debug
            _debug = 1
        elif opt == '-v':
            value = arg
        elif opt in ("-g", "--grammar"):
            grammar = arg
    if value == None:
        if len(args) == 0:
            usage()
            sys.exit(1)
        value = args[0]

    print "hex(%s) = %s" % (value, hex(int(value)))

    source = "".join(args)

if __name__ == "__main__":
    main(sys.argv[1:])
