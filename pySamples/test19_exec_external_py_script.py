# tested with python2.7 and python3.9

def main():
    # execfile
    try:
        f = open("test_hello.py")
    
    except Exception as e:
        print("open file fail: ", e)
        return 1

    if f:
        exec(f.read())
        f.close()
    else:
        print("run failure")

if __name__ == "__main__":
    main()
