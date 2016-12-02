#include <stdio.h>
#include <stdlib.h>

char* formaterDate(int jour, int mois,int annee) {

	char[] moisS;
//char* mois[] = {"Jan","Fev",...}
//strcmp(u,v) 0= 1v<u -1 u<v
//strstr 
	switch (mois) {

	case 1 :
	 moisS = "Janvier"
	 break;

	case 2 :
	 moisS = "Février"
	 break;

	case 3 :
	 moisS = "Mars"
	 break;
	
	case 4 :
	 moisS = "Avril"
	 break;

	case 5 :
	 moisS = "Mai"
	 break;

	case 6 :
	 moisS = "Juin"
	 break;

	case 7 :
	 moisS = "Juillet"
	 break;

	case 8 :
	 moisS = "Aout"
	 break;

	case 9 :
	 moisS = "Septembre"
	 break;

	case 10 :
	 moisS = "Octobre"
	 break;

	case 11 :
	 moisS = "Novembre"
	 break;

	case 12 :
	 moisS = "Decembre"
	 break;

	default :
	 printf("Problème");
	 break;
	
	return( "Date :",jour , " ", moisS , " ",annee);
}

int main() 
{
	printf(formaterDate(18,04,1997));
	return 0;
} 
