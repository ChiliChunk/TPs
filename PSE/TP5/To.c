#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFS 1024

int main(int argc, char const *argv[]) {
   char buf[BUFS+1];
  int fdTmp;
  fdTmp = open ("tmp" , O_RDONLY);
  dup2(fdTmp , 0);

  while (1 > 0){
    execl("/bin/cat", "cat", "tmp",  (char *)0);
  }
  return 0;
}
