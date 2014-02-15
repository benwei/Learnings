
## algorithm: http://en.wikipedia.org/wiki/Square_root

def numberSameCharCount(str1, str2):
    match=0
    for i, (char1, char2) in enumerate(zip(str1, str2)):
        if char1 != char2:
            return i
        else:
            match = match + 1
    
    if match > 0:
        return match 

    return -1;


def sqrtByNewtonMethod(S, n):
    ## result of sqrt(S) (S>1), select 1 < X0 < S
    ## X(n+1) = 1/2(Xn + S/Xn)
    match = 0;
    i = 2;
    x0 = 0.5 * S;
    x1 = 0.5 * (x0 + S/x0)
    while match < n and x0 != x1:
        x0 = x1
        x1 = 0.5 * (x0 + S/x0)
        match = numberSameCharCount(repr(x0), repr(x1))
        #print "x(%02d)=%f, match %d " % (i+2, x1, match)
        i = i + 1
    return x1


print ("result:", sqrtByNewtonMethod(125348, 15));
print ("result:", sqrtByNewtonMethod(256, 15));
