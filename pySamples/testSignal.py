import signal, os
import time


def handler(signum, frame):
    print 'Signal handler called with signal', signum

signal.signal(signal.SIGHUP, handler)

def main():
    while (1):
        time.sleep(1);

if __name__ == '__main__':
    main();
