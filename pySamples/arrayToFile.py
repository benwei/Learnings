import array

def testArrayToFile():
    a = array.array('c')
    a.append("1")
    a.append("5")
    a.append("7")
    f=open('array.txt', 'w')
    a.tofile(f)
    f.close()

testArrayToFile()
