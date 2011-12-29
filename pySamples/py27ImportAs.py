import sys
import bemod.date8601 as dt

def main():
    data = "2007-03-04T21:08:12Z"

    # case 1
    d  = dt.Date8601(data)
    result = d.to8601String()
    print result

if __name__ == "__main__":
    ret = main()
    sys.exit(ret)
#!/usr/bin/env python
