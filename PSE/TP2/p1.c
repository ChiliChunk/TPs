#include <stdio.h>
#include <stdlib.h>

int saisie_controlee_entier() {
    int rep=0, n;
    char ch [1024];
    do {
        printf("saisir un entier : ");
        fgets(ch, 1024, stdin);   // lecture d'une ligne à l'entrée std (max 1024 chars)
        rep = sscanf(ch,"%d",&n); // conversion de la chaine ch en entier
                                  // rep==0 si saisie non-numérique
    } while(rep==0);
    
    return n;
}

int main (){
	int MAX;
	int saisie;
	int i;
	int * tabEntier;
	printf ("Quelle taille de tab\n");
	MAX = saisie_controlee_entier();
	tabEntier = malloc (sizeof(int)*MAX);
	printf("Saisissez le tab\n");
	for (i = 0 ; i < MAX ; i++){
		saisie = saisie_controlee_entier();
		tabEntier[i] = saisie;
	}
	
	printf("Affichage du tableau\n");
	for (i=0 ; i < MAX ; i++){
		printf("%d ",tabEntier[i]);
	}
	printf ("\nA l'envers\n");
	for (i=MAX-1 ; i >= 0 ; i--){
		printf("%d ",tabEntier[i]);
	}

	return 0;
		
}
