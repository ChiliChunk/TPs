#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]) {
    printf("%s\n","Commande:");
  while(1<2){
      if (argc == 0){
        return 1;
      }
      if (argc >8){
        return 2;
      }

      char buf[256];
      char * arg[9];
      int i = 0;


      fgets (buf , 256 , stdin);
      arg[0] = strtok (buf , " \t\n");

      while (arg[i] != NULL) {
        arg[i+1] = strtok(NULL , " \t\n");
        i++;
      }
      int w;
      w = fork();
      if (!w){
          execvp(arg[0] , arg);
      }

      fflush(stdout);
    }
    return 0;
}
