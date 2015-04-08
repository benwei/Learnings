from xml.dom import minidom


class OrderInvoice:
    '''
    >>> o = OrderInvoice('order.xml')
    >>> o.listInvoice()
    cpu  =>   i7-860    $2000
    ram  =>      8GB    $1500
    hdd  =>      8TB   $10000
    fee  =>            $13500
    '''
    def __init__(self, invoiceXML):
        xmldata = minidom.parse(invoiceXML)
        self.products = xmldata.getElementsByTagName('product')
        self.fee = 0

    def listInvoice(self):
        for p in self.products:
            if len(p.childNodes) > 0:
                print "%-4s => %8s %8s" % (p.attributes['name'].value, \
                    p.attributes['memo'].value, "$%s" % p.childNodes[0].nodeValue)
                self.fee = self.fee + int(p.childNodes[0].nodeValue)
            else:        
                print "%-4s => %8s" % (p.attributes['name'].value, \
                    p.attributes['memo'].value)

        print "%-4s => %17s" % ("fee", "$%s" % str(self.fee))

if __name__ == "__main__":
    import doctest
    doctest.testmod()
