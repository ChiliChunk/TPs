#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
	int var;
	int i;
	i = fork();
	//PERE
	if (i){
		wait (&var);
		printf("pere a attendu\n");
	}

	//FILS
	else{
		//system("xterm");
		//execl("/usr/bin/xterm", "xterm", NULL) ;
		execv("/usr/bin/xterm", "xterm", NULL) ;
	}
	
	return 0;
}
