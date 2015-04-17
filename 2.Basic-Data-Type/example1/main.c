#include <stdlib.h>
#include "read.h"

int main(int argc, char *argv[])
{
  unsigned char i;
  if(argc<2)
    exit(0);
  i=(unsigned char)atoi(argv[1]);

  readpos(i);
  return;
}
