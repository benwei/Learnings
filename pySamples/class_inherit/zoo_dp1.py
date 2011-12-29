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

    def lookandfeel(self):
        print "%s is a %s" % (self.name, self.attrib())

class Cat(Animal):
    def attrib(self):
        return "Cat"

class Dog(Animal):
    def attrib(self):
        return "Dog"

# factory pattern
class zoo:
    type_cat = 1
    type_dog = 2
    def __init__(self):
        self.animals = []

    def born(self, animal_type, name=None):
        if animal_type == zoo.type_cat:
            self.animals.append(Cat(name))
        elif animal_type == zoo.type_dog:
            self.animals.append(Dog(name))

    def animalCount(self):
        return len(self.animals)

    def browse(self):
        for a in self.animals:
            a.lookandfeel()

z = zoo()
z.born(zoo.type_cat)
z.born(zoo.type_cat, 'dummy')
z.born(zoo.type_dog, 'ttt')

z.browse()

