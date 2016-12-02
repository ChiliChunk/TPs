#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include "matrix.h"
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void * inputMatrix( void * par) {
  key_t k = ftok(get_current_dir_name() , 0);
  //on creer l espace de memoire partagee
  int id = shmget (k , 1024 , IPC_CREAT | 0644);
  printf("%d\n", id );
  //on attache cette partie de memoire au prog
  SquareMatrix * memo = shmat (id , NULL ,0);

  SquareMatrix maMatrice;
  input_square_matrix(&maMatrice);
  pack_matrix(maMatrice , memo);
  shmdt (NULL);
  sleep(15);
}

void * outputMatrix ( void * par ){
  key_t k = ftok(get_current_dir_name() , 0);
  int id = shmget (k , 1024 , IPC_CREAT | 0644);
  SquareMatrix * memo =  shmat (id , NULL , 0);
  unpack_matrix(memo);
  print_square_matrix(*memo);
  shmdt (NULL);
  shmctl (id , IPC_RMID , NULL);
}

int main(int argc, char const *argv[]) {
  pthread_t threadIN , threadOut;
  int rc;
  rc = pthread_create(&threadIN , NULL , & inputMatrix , NULL);
  rc = pthread_create(&threadOut , NULL , & outputMatrix, NULL);

  return 0;
}
