#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include "matrix.h"
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

SquareMatrix neo;
SquareMatrix deuxieme;

void * inputMatrix( void * par) {
  input_square_matrix(&neo);
}

void * outputMatrix ( void * par ){
  pthread_join(*(pthread_t *) par  , NULL);
  square_a_square_matrix(neo , &deuxieme);
}

int main(int argc, char const *argv[]) {
  pthread_t threadIN , threadOut;
  int rc;
  rc = pthread_create(&threadIN , NULL , & inputMatrix , NULL);
  rc = pthread_create(&threadOut , NULL , & outputMatrix, &threadIN);
  pthread_join(threadOut , NULL);
  print_square_matrix(deuxieme);
  free_square_matrix(&deuxieme);
  return 0;
}
