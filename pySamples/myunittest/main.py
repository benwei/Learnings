

class Caller:
    def __init__(self):
        self.count = 0

    def addRef(self):
        self.count = self.count + 1

    def refCount(self):
        return self.count
    def isUsed(self):
        return self.count > 0
