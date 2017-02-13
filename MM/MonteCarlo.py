import random
import math
import time



def monteCarlo (n):
    nbDecimaleVoulue = 5
    nbDecimaleVoulue += 2
    p=0
    count = 0
    while (count < n):
        x = random.randint(-1000 , 1000)/1000.0
        y = random.randint(-1000 , 1000)/1000.0
        if x*x + y*y <= 1:
            p = p+1
        count = count +1

    result = p/(n*1.0)*4
    strPi = str(math.pi)
    strResult = str(result)
    if len(strResult) <  nbDecimaleVoulue:
        return 1 , result
    for i in range (0,nbDecimaleVoulue):
        if strResult[i] != strPi[i]:
            return 1 , result
    return 0 , result



dateDebut = time.time()
reponse = monteCarlo(10000000)
cpt = 0
while reponse[0] == 1:
    reponse = monteCarlo(10000000)
    cpt += 1
    print ('try nb: '+str(cpt))
    print ('reponse' + str(reponse[1]))

dateFin = time.time()
temps = dateFin - dateDebut
print ("result :"+str(reponse[1]))
print ("temps :"+str(temps))
