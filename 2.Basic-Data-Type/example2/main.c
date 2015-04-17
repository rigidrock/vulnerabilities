#include <stdlib.h>
#include <stdio.h>
#include "read.h"

int main(int argc, char *argv[])
{
  char i;
  if(argc<2)
    exit(0);

  i=atoi(argv[1]);
  if(i<MAXLEN)
    readpos(i);
  else
    printf("Invalid Value\n");

  return;

}
