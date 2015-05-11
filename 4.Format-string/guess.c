/***
* There is a format string bug.
* Try to get "You win!!" via the vulnerability
***/
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define LEN 32

int main()
{
  int ok=0, i=0;
  char secret[LEN], code[LEN];
  
  srand(getpid());
  snprintf(secret, LEN, "%08d",rand());

  printf("Guess the number\n");
  while( !ok && i++<5) {
    fgets(code, LEN, stdin);
    printf(code);
    if(strcmp(code, secret)==0)
      ok=1;
  }

  if (ok) 
    printf("You win!!\n");
  else
    printf("You loss!!\n");
}
