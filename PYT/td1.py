

def ajouter (nom,prenom) :
    if contacts.has_key ((nom,prenom)):
        print "Contact deja present"
    else :
        age = int (raw_input("age? "))
        telephone = raw_input("telephone? ")
        adresse = raw_input("adresse ?")
        contacts [((nom,prenom))] = (age,telephone,adresse)


def supprimer (nom,prenom) :
    if not contacts.has_key ((nom,prenom)):
        print "Contact non existant"
    else :
        del contacts [(nom,prenom)]
        print "Contacte supprimer"

def consulter (nom,prenom) :
    if not contacts.has_key((nom,prenom)):
        print "contact non existant"

    else:
        age,telephone,adresse = contacts[(nom,prenom)]
        print "Age :",age
        print "telephone",telephone
        print "adresse",adresse

def menu ():
    choix = None
    while choix != 'quit':
        choix = raw_input("ajouter , supprimer , consulter")
        if choix in effectuer.keys():
            nom = raw_input("nom???????????")
            prenom = raw_input ("prenom")
            effectuer[choix](nom,prenoml)
            
