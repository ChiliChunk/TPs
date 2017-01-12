import random
import math
import matplotlib.pyplot as plt

def monteCarlo (n):
    p=0
    count = 0
    while (count < n):
        x = random.randint(-1000 , 1000)/1000.0
        y = random.randint(-1000 , 1000)/1000.0
        if x*x + y*y <= 1:
            p = p+1
            # plt.scatter(x , y , c = 'green')
        # else:
            # plt.scatter(x,y,c = 'red')
        count = count +1
    result = p/(n*1.0)*4

    return result

# ErrAbsolue = valApprochee - valReelle
# ErrRelative = (valApprochee - valReelle)/ |valReelle|
tabResult = []
nbMonteCarlo = 1000
tabErrRel = []
n = []
for i in range (0,5):

    tabResult.append([0] * 3)


    print ("Pour "+str(nbMonteCarlo)+" nbMonteCarlo")
    # case 0
    resultApproche = monteCarlo(nbMonteCarlo)
    tabResult[i][0] = resultApproche
    nbMonteCarlo = nbMonteCarlo * 10
    n.append(math.log10(nbMonteCarlo))
    print ("result "+str(resultApproche))

    # case 1
    ErrAbsolue = 0.0
    ErrAbsolue = resultApproche - math.pi
    tabResult[i][1] = ErrAbsolue
    print ("erreur Absolue "+str(ErrAbsolue))

    # case 2
    ErrRelative = math.fabs((resultApproche - math.pi)) / math.fabs(math.pi)
    ErrRelative = ErrRelative * 100
    tabResult[i][2] = ErrRelative
    tabErrRel.append(ErrRelative)
    print ("erreur relative "+str(ErrRelative)+" %")

    # plt.show()


plt.plot(n , tabErrRel ,'b-o')
plt.show()
