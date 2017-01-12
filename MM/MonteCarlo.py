import random




def monteCarlo (n):
    p=0
    count = 0
    while (count < n):
        x = random.randint(-1000 , 1000)/1000.0
        y = random.randint(-1000 , 1000)/1000.0
        if x*x + y*y <= 1:
            p = p+1
        count = count +1

    result = p/(n*1.0)*4
    return result
