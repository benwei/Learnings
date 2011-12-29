def capfirst(text):
    c = text[0]
    if c >='a' and c<='z':
        text = chr(ord(c) - ord('a') + ord('A')) + text[1:]
    return text

class Animal:
    def __init__(self, name=None):
        self.name = capfirst(name) if name else "The animal"

    def getName(self):
        return self.name

    def attrib(self):
        return "Animal"

    def getLookandfeel(self):
        return "%s is a %s" % (self.name, self.attrib())

class Cat(Animal):
    def attrib(self):
        return "Cat"

class Dog(Animal):
    def attrib(self):
        return "Dog"

# factory pattern
class Zoo:
    # class static variable
    type_cat = "1"
    type_dog = "2"
    _Zooself = None
    _zoodict = {
           type_cat: Cat,
           type_dog: Dog,
        }
    def __init__(self):
        self.animals = []

    @staticmethod
    def singleton():
        if Zoo._Zooself == None:
            Zoo._Zooself = Zoo()
        return Zoo._Zooself

    def born(self, animal_type, name=None):
        caller = Zoo._zoodict.get(animal_type)
        if caller:
            self.animals.append(caller(name))
        return None

    def animalCount(self):
        return len(self.animals)

    def browse(self):
        i = 0
        for a in self.animals:
            print " - Animal[%s]:%s" % (i, a.getLookandfeel())
            i+=1

z = Zoo.singleton()
z2 = Zoo.singleton()
if z == z2:
    print "* Singleton pattern of Zoo"

print "* Factory pattern to born"
z.born(Zoo.type_cat)
z.born(Zoo.type_cat, 'dummy')
z.born(Zoo.type_dog, 'ttt')

print "* Factory pattern to browse"
z.browse()

