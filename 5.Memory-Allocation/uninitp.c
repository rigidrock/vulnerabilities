#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *dupstr(char *str);

int main()
{
  char str[]="Hello world!";
  char *pstr;

  pstr=dupstr(str);
  nothing();
}


char *dupstr(char *str)
{
  char *p;

  p=(char *)malloc(strlen(str)+1);
  strcpy(p, str);

  return p;
}

int nothing()
{
  char *q;

  printf("%s\n", q);
}
