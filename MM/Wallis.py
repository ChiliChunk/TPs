def wallis (n):
    num = 2.0
    pi = 1.0
    denom = 1.0
    cptNum = 0
    cptDenom = 1
    for i in range (n):
        mult = num / denom
        pi = pi * mult

        cptNum += 1
        cptDenom += 1

        if cptNum == 2:
            cptNum = 0
            num += 2
        if cptDenom == 2:
            cptDenom = 0
            denom +=2

    pi = 2*pi
    return pi
