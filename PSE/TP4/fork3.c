#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h> 
#include <stdlib.h>



int main(){
	
	int enfant = fork();
	int var;
	if (enfant != 0){
		enfant = fork();
	}
	if (enfant != 0 ){
		enfant = fork();
	}
	
	if ( enfant ){
	printf("Je suis le pere mon pid est (%d)\n", getpid());
	wait (&var);
	printf("Le code de retour est : (%d)\n" , WEXITSTATUS(var));
	wait (&var);
	printf("Le code de retour est : (%d)\n" , WEXITSTATUS(var));
	wait (&var);
	printf("Le code de retour est : (%d)\n" , WEXITSTATUS(var));
	printf("Fin du pere (%d) \n" , getpid());
	}
	else {
		printf("Je suis le fils de (%d) mon pid est (%d)\n", getppid() , getpid());
		sleep(2);
		printf("Fin du fils (%d) \n" , getpid());
		srand(getpid());
		return rand() % 256;
	}
	fflush(stdout);
	return 0;
}
