class clsa:
    # static variable
    ajax = True
    name = 'default'
    def __init__(self, name):
        self.name = name

    @staticmethod
    def getStatic():
        print("static ajax is %s" % clsa.ajax)

    def checkAjax(self):
        print("ajax(%s) is %s" % (self.name, self.ajax))

print "clsa.ajax = %s" % clsa.ajax
clsa.getStatic()

a = clsa('a')
a.ajax = False
a.checkAjax()

clsa.getStatic()
clsa.ajax = False
clsa.getStatic()

b = clsa('b')
b.checkAjax()
