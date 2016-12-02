#include <unistd.h>
#include <stdio.h>


int main(int argc, char const *argv[]) {
  int tube [2];
  pipe (tube);
  int f;
  f = fork();
  //pere
  if (f){
    int emet ;
    emet = 58;
    write (tube[1] , &emet , sizeof(emet));
  }
  else{
    int recept ;
    read (tube[0] , &recept , sizeof(recept));
    printf("Le nombre reçu est %d\n", recept);
  }
  return 0;
}
