#!/usr/bin/env ruby

def b(data)
    data 
end

def c(data)
    return data
end

def mod(m, n)
     m % n
end

# like inline function
print b("test function syntax 1\n")


print c("test function syntax 2\n")
M = 10
N = 3
print M, "%", N, "=", mod(M, N), "\n"
