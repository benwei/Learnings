
def print_lines(outdata, num):
    arr = outdata.split('\n')
    for i in arr[:num]:
        print i

data='test\ntest1\ntest3\n4\n5'

print_lines(data, 2)
