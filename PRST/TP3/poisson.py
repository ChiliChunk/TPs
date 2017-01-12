
import math

def poisson (k,m):
    if m > 0 :
        return 1.0*(math.pow(math.e , -m) * ( math.pow(m , k)/math.factorial(k)))
print poisson (1,2)
