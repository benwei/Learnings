

class AttrContainer(object):
      def __init__(self):
        pass

      def extendAttrPair(self, attrName, value):
        # add any action defaults that aren't present
        if not hasattr(self, attrName):
            setattr(self, attrName, value)

o = AttrContainer()

o.extendAttrPair('b', 1)
o.extendAttrPair('c', 1)

o.b += 1
print o.b
print dir(o)

