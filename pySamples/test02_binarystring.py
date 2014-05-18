#!/usr/bin/env python

# convert small binary to small decimal
bin1='10101010'
print int(bin1, 2)
#result '170'

# convert big binary string to big decimal
binbig ='1111111111111111111111111111111111111111111111111111111111111111'
print int(binbig, 2);
#result '18446744073709551615'

# convert big decimal to binary
intbig=18446744073709551615
print bin(intbig)
#result '0b1111111111111111111111111111111111111111111111111111111111111111'

# trim the prefix 0b
print str(bin(intbig))[2:]
#result '1111111111111111111111111111111111111111111111111111111111111111'
