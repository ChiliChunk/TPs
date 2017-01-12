
def leinbniz (k):
    plus = True
    sumPi = 0.0
    denominateur = 1.0

    for i in range (k):
        if plus:
            sumPi +=  1 /denominateur
            denominateur = denominateur +2
            plus = False
        else:
            sumPi -=  1/denominateur
            denominateur = denominateur +2
            plus = True

    sumPi = 4.0 * sumPi
    return sumPi
