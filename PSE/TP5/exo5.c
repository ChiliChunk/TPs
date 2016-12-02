#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


int main(int argc, char const *argv[]) {
  int tube[2];
  pipe(tube);
  int f1 = fork();
  int f2 ;
  //si pere
  if (f1){
    f2 = fork();
  }
  if (f1 == 0){
    dup2(tube[1] , 1);
    execl("/bin/ls", "ls", "-l", (char *)0);
  }
  if (f2 == 0){
    dup2(tube[0] , 0);
    execl("/bin/grep", "grep", "\\.c", (char *)0);
    close (tube[0]);
  }
  return 0;
}
