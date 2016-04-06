#!/usr/bin/env python
# Timer sample: count to 10
# 
# tested by Python 3.4.3
from threading import Timer
import time

timer = None
counter = 0
def handle_hello():
    global counter, timer
    counter = counter + 1
    print(counter)
    if(counter >= 10):
        return

    timer = Timer(1, handle_hello)
    timer.start()

def main():
    timer = Timer(1, handle_hello)
    timer.start()

if __name__ == "__main__":
    main()
