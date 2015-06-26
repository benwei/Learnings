

class padbase(object):
    TAG='base'
    def __init__(self, content_handler):
        self.h = content_handler

    def __call__(self, *args):
        return "<" + self.TAG +  ">" + self.h(*args) + "</"+ self.TAG +">"

class padbold(padbase):
    TAG='B'
    def __init__(self, content_handler):
        super().__init__(content_handler)

class paddiv(padbase):
    TAG='DIV'
    def __init__(self, content_handler):
        super().__init__(content_handler)

@padbold
def genhtml(msg, b):
    return msg + str(b)

@paddiv
def gendiv(msg, b):
    return msg + str(b)

print("%s" % genhtml("html bold", 6))
print("%s" % gendiv("html div", 6))
