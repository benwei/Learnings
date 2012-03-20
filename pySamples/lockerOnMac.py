import os,sys
import fcntl
from time import sleep

# global definition
mlockfile = "/tmp/%s.lock" % os.path.basename(sys.argv[0])

ret = 0
lockfd = -1

class Locker: 
    def __init__(self, lockfile):
        self.lockfd = -1
        self.lockfile = lockfile
        self.locked = False
        self.lock(lockfile)

    def lock(self, file):
        try:
            flags = os.O_RDWR|os.O_CREAT|os.O_EXCL
            self.lockfd = os.open(file, flags)
            print "locked"
            self.locked = True
        except OSError as (errno, strerror):
            if errno == 17:
                print "has been locked"
            else:
                print "%d:%s" % (errno, strerror)

    def isLocked(self):
        return self.locked

    def unlock(self):
        try:
            os.close(self.lockfd)
            os.unlink(self.lockfile)
            self.locked = False
            print "unlocked"
        except OSError as (errno, strerror):
            pass
            #print "%d:%s" % (errno, strerror)
        self.locked = False

    def release(self):
        if self.locked:
            self.unlock()

    def __exit__(self):
        self.release()

    def __del__(self):
        self.release()

# main
locker = Locker(mlockfile)
if not locker.isLocked():
    sys.exit(1)
sleep(10)
