
class Dyn():
    name="foo"
    def __init__(self, name):
        self.name = name

print "Dyn.name = %s" % Dyn.name
print "Dyn.__dict__['name']= %s" % Dyn.name

Dyn.__dict__['age'] = 18
print "Dyn.__dict__['age']= %s" % Dyn.age

Dyn.wear = "hat"

print "Dyn.wear = %s" % Dyn.wear

print "Dyn.__dict__ => ", Dyn.__dict__

adyn = Dyn("adyn")

print "adyn.__dict__ => ", adyn.__dict__

