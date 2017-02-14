def inverse(chaine):
    chaineInv= ""
    for a in chaine:
        chaineInv = a + chaineInv

    return chaineInv

def palindrome(chaine):
    return (chaine == inverse(chaine))

def position (mot,phrase):
    cpt = 0
    indice = 0
    tour = 0 
    for a in phrase:
        if a == mot[cpt]:
            if cpt == 0:
                indice = tour
            cpt += 1
            if cpt == len(mot):
                return indice
        else:
            cpt = 0
        tour += 1
    return None

def trier (liste):
    for w in range (len(liste)):
        minimum = liste[0]
        for i in liste[0:len(liste)-w]:
            if i < minimum:
                minimum = i
        liste.remove(minimum)
        liste.append(minimum)
        
        
def produit (p,q):
    if (p == 0):
        return 0
    elif (p&1 == 0):
        return produit(p>>2 , q<<2)
    else:
        return  produit (p-1 , q)+q

print (produit (5,2))