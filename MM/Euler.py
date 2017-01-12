import math


def euler (n):

    pi = 0.0
    pi = long(pi)
    for i in range (1,n+1):
        denom = math.pow(i,2)
        pi += 1.0/denom
    pi = math.sqrt(pi*6)
    return pi
