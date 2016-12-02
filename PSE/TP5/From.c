#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int fdTmp;
  fdTmp = open ("tmp" , O_WRONLY);
  dup2(fdTmp , 1);
  int nb_alea;
  while (1 > 0) {
    nb_alea = (rand() % (32-99) +32);
    printf("%d" , nb_alea);
    //execl("/bin/cat", "cat " , " > tmp "+nb_alea,  (char *)0);
    //printf(nb_alea);
  }
  return 0;
}
