#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
  int fdFichier;
  fdFichier = open ("f" , O_WRONLY);
  dup2(fdFichier , 1);
  execl("/bin/ls", "ls", "-l", (char *)0);
  return 0;
}
