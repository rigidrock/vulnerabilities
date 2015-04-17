#include <stdio.h>
#define MAXLEN 64

int readpos(char x)
{
  if(x<MAXLEN) 
    printf("Valid value, read position %d\n", x);
  else
    printf("Invalide value\n");
  return 0;
}
