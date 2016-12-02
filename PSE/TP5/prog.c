<#include <stdio.h>

int main(){
  write(2,"Attention : ce programme boucle indéfiniement!\n\n",49);
  while (1){
    write(1,".",1);
    sleep(1) ;
  }
  return 0; /* jamais atteint */
}
