from math import sqrt

def Euler (n):
    result=1.0
    k=1.0
    for i in range(n):
        #print (str(k)+" "+str(result))
        #print(str((1/(k*k))))
        result=result+(1/(k*k))
        k+=1
    result = result*6.0
    result = sqrt(result)
    print (str(result))


Euler(1000000)

#n=360000