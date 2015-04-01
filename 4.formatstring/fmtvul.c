#include <stdio.h>
#include <unistd.h>
#define MAX 256

int main()
{
  fmt();
}

int fmt()
{
  int n;
  char str[MAX];
  n=read(0, str MAX-1);
  str[n]='\x0';
  printf(str);
  return;
}
