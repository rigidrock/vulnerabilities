#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define CODELEN 32

int main()
{
  int ok=0; i=0;
  char token[CODELEN], code[CODELEN];
  
  srand(getpid());
  snprintf(token, CODELEN, %08d", rand());
  
  while(!ok && i++<5) {
    fgets(code, CODELEN, stdin);
    printf(code);
    if(strcmp(code, token)==0)
      ok=1;
  }
  if (ok)
    printf("You win!!\n");
  else
    printf("You loss!!\n");
}
