import binascii

myString = "0123\r\n"
ba = bytearray(myString)

def padzero(s):
    bitstring=s[2:]
    bitstring = -len(bitstring) % 8 * '0' + bitstring
    return bitstring

def binleadingzero(c):
    d = int(binascii.hexlify(c),16)
    a = bin(d);
    bitstring=a[2:]
    bitstring = -len(bitstring) % 8 * '0' + bitstring
    return str(d) + " -> " + bitstring

print "====== using string + binascii hexlify ====="
balen = len(myString)
i = 0
while  i < balen:
    print binleadingzero(myString[i])
    i = i + 1

print "====== using bytearray ====="
i = 0
balen = len(ba)
while i < balen:
    print str(ba[i]) + " -> " + padzero(bin(ba[i]))
    i = i + 1
