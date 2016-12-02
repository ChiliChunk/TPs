#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include "matrix.h"
#include <unistd.h>
#include <stdio.h>
int main(int argc, char const *argv[]) {
  //on creer la cle commune
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
  return 0;
}
