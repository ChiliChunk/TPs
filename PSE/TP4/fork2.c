#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){ 
	int enfant = fork();
	int var;
	if ( enfant ){
		printf("Je suis le pere de (%d) mon pid est (%d)\n", enfant , getpid());
		wait(&var);
		printf("Fin du pere (%d) \n" , getpid());
	}
	else {
		printf("Je suis le fils de (%d) mon pid est (%d)\n", getppid() , getpid());
		sleep(5);
		printf("Fin du fils (%d) \n" , getpid());
	}
	fflush(stdout); 
	return 0;
}
