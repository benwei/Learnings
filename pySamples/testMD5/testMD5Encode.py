import md5

class MyTextHash:
    '''
    >>> th = MyTextHash("hello")
    >>> th.hexValue()
    '5d41402abc4b2a76b9719d911017c592'
    >>> th.updateValue("world")
    'fc5e038d38a57032085441e7fe7010b0'
    '''
    def __init__(self, data):
        self.data = data
        self.m = md5.new()
        self.m.update(self.data)

    def hexValue(self):
        return self.m.hexdigest()
    def updateValue(self, append_data):
        self.m.update(append_data)
        return self.hexValue()


if __name__ == "__main__":
    #th = MyTextHash("hello")
    #print th.myhash()
    import doctest
    doctest.testmod()
