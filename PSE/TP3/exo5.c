#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
  int tube [2];
  pipe (tube);
  //pere
  if (f1 && f2){
    int f1 = fork();
    int f2 = fork();
  }
  //fils f1
  else if (f1 == 0){
    execl("/bin/ls", "ls", "-l", (char *)0);
  }
  //fils f2
  else if (f2 == 0){
    execl("/bin/grep", "grep", "\\.c", NULL);
  }
  return 0;
}
