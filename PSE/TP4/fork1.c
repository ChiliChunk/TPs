#include <stdio.h> 
int main(){ 
	int i ; 
	for (i=0;i<3;i++){ 
	  fork(); 
	  printf("fils (%d) de (%d). i=%d\n", getpid(), getppid(), i);
	  fflush(stdout); 
	} 
	sleep(30);
	return 0; 
}
