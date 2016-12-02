#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	FILE * myfile = fopen (argv[1] , "w");

	printf ("que voulez vous ecrire dans le fichier?");
	char string [1000] ;
	scanf("%s" , string);
	fprintf(myfile , "%s",string);
	fclose(myfile);
 	exit(0);
}
