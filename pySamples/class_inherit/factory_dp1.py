from beutil import *

class Worker:
    def __init__(self, name=None):
        self.name = capfirst(name) if name else "The worker"

    def getName(self):
        return self.name
    def attrib(self):
        return "Worker"

    def lookandfeel(self):
        print "%s is a %s" % (self.name, self.attrib())

class Designer(Worker):
    def attrib(self):
        return "Designer"

class Engineer(Worker):
    def attrib(self):
        return "Engineer"

# factory pattern
class Factory:
    type_designer = 1
    type_engineer = 2
    def __init__(self):
        self.workers = []

    def employ(self, worker_type, name=None):
        if worker_type == Factory.type_designer:
            self.workers.append(Designer(name))
        elif worker_type == Factory.type_engineer:
            self.workers.append(Engineer(name))

    def workerCount(self):
        return len(self.workers)

    def browse(self):
        for a in self.workers:
            a.lookandfeel()

z = Factory()
z.employ(Factory.type_designer)
z.employ(Factory.type_designer, 'bill')
z.employ(Factory.type_engineer, 'sue')

z.browse()

