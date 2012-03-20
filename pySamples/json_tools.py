import json
import sys

def usage():
    print("syntax: <json file>")
    return 1

def main():
    if len(sys.argv) < 2:
        return 1

    jsonFile=sys.argv[1]
    try:
        f = open(jsonFile)
        data = f.read()
    except IOError:
        print "%s cannot be read" % jsonFile
        return 2

    jsd = json.loads(data)
    print("%s" % data)
    print("json=%s" % json.dumps(jsd, indent=2))
    return 0

if __name__ == "__main__":
    main()
