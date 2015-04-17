#include <stdlib.h>
#include <stdio.h>
#define CHECK 0x00

int cmp(short);

int main()
{
  unsigned short x;
  char s[8];

  fgets(s, 7, stdin);
  x=atoi(s);
  while (cmp(x)<=0){
    printf("%d is smaller\n",x);
    fgets(s, 7, stdin);
    x=atoi(s);
  }
  printf("You should not reach here\n");
  return;
}

int cmp(short x)
{
  return x-(short)CHECK;
}
