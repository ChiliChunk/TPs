#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include "matrix.h"
#include <unistd.h>


int main(int argc, char const *argv[]) {

  key_t Ksem = ftok(get_current_dir_name() , 0);
  //déclaration et récuperation ID??
  int id = semget (Ksem , 1 , IPC_CREAT | 0644);
  //initi sem
  int sem = semaphore_initialize (id , 55);
  binary_semaphore_wait (id);

  key_t k = ftok(get_current_dir_name() , 0);
  int id = shmget (k , 1024 , IPC_CREAT | 0644);
  SquareMatrix * memo =  shmat (id , NULL , 0);
  unpack_matrix(memo);
  print_square_matrix(*memo);
  shmdt (NULL);
  shmctl (id , IPC_RMID , NULL);
  return 0;
}
