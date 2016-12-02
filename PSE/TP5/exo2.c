#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int nbInterupt;

void ecriture (){
  nbInterupt = nbInterupt +1;
  if (nbInterupt == 1 ){
    printf("interruption numéro 1\n" );
    fflush(stdout);
  }
  else if (nbInterupt == 2){
    printf("interruption numéro 2\n" );
    fflush(stdout);
  }
  else if (nbInterupt == 3){
    printf("%s\n", "interruption numéro 3" );
    
    fflush(stdout);
  }
  else if (nbInterupt == 6){
    exit(0);
  }
}

int main(int argc, char const *argv[]) {
  nbInterupt = 0;
  signal (SIGINT , ecriture);
  while (1) {

  }
  return 0;
}
