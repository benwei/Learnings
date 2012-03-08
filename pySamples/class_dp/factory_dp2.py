
from beutil import *

class Worker:
    def __init__(self, name=None):
        self.name = capfirst(name) if name else "The worker"

    def getName(self):
        return self.name

    def attrib(self):
        return "Worker"

    def getLookandfeel(self):
        return "%s is a %s" % (self.name, self.attrib())

class Designer(Worker):
    def attrib(self):
        return "Designer"

class Engineer(Worker):
    def attrib(self):
        return "Engineer"

# factory pattern
class Factory:
    # class static variable
    type_designer = "1"
    type_engineer = "2"
    _Factoryself = None
    _factorydict = {
           type_designer: Designer,
           type_engineer: Engineer,
        }
    def __init__(self):
        self.workers = []

    @staticmethod
    def singleton():
        if Factory._Factoryself == None:
            Factory._Factoryself = Factory()
        return Factory._Factoryself

    def employ(self, worker_type, name=None):
        caller = Factory._factorydict.get(worker_type)
        if caller:
            self.workers.append(caller(name))
        return None

    def workerCount(self):
        return len(self.workers)

    def browse(self):
        i = 0
        for a in self.workers:
            print " - Worker[%s]:%s" % (i, a.getLookandfeel())
            i+=1

def main():
    f = Factory.singleton()
    f2 = Factory.singleton()
    if f == f2:
        print "* Singleton pattern of Factory"

    print "* Factory pattern to employ"
    f.employ(Factory.type_designer)
    f.employ(Factory.type_designer, 'Bill')
    f.employ(Factory.type_engineer, 'Sue')

    print "* Factory pattern to browse"
    f.browse()

    print "* The factory has %s workers." % f.workerCount()

if __name__ == "__main__":
    main()
