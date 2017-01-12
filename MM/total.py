from Leinbniz import leinbniz
from CompteGoutte import CompteGoutte
from Euler import euler
from MonteCarlo import monteCarlo
from Wallis import wallis

import time

nbIteration = 10

for i in range (0,5):
    print('------------------------------------------------------------------')
    print ('Pour '+str(nbIteration)+' iterations: \n')
    print('------------------------------------------------------------------')

    dateDebut = time.time()
    resultLeinbniz = leinbniz (nbIteration)
    dateFin = time.time()
    temps = dateFin - dateDebut
    print ('Leinbniz : \n    result : '+str(resultLeinbniz)+ '\n   temps : '+str(temps))

    dateDebut = time.time()
    resultCompteGoutte = CompteGoutte(nbIteration)
    dateFin = time.time()
    temps = dateFin - dateDebut
    print ('CompteGoutte : \n    result : 3,'+str(resultCompteGoutte)+ '\n   temps : '+str(temps))

    dateDebut = time.time()
    resultEuler = euler(nbIteration)
    dateFin = time.time()
    temps = dateFin - dateDebut
    print ('Euler : \n    result : '+str(resultEuler)+ '\n   temps : '+str(temps))

    dateDebut = time.time()
    resultMC = monteCarlo(nbIteration)
    dateFin = time.time()
    temps = dateFin - dateDebut
    print ('Monte Carlo : \n    result : '+str(resultMC)+ '\n   temps : '+str(temps))

    dateDebut = time.time()
    resultWallis = wallis (nbIteration)
    dateFin = time.time()
    temps = dateFin - dateDebut
    print ('wallis : \n    result : '+str(resultWallis)+ '\n   temps : '+str(temps))

    nbIteration = nbIteration * 10
