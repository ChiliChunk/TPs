#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


#define T 1024

int main(int argc, char *argv[])
{
	int fd;
	fd = open(argv[1],O_RDONLY);
	if ( fd<0 ){
		perror ("Error ");
		exit(1);
	}

	char buf[T];
	



	int n;

	do{n=read(0,buf,T);
	write(1,buf,n);
	}while(n!=0);

	
	exit(0);
}
