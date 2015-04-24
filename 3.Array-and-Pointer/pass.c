#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define OK 1
#define FAIL 0
#define LEN 32

char token[LEN];

int main()
{
  initial();
  printf("Wanna shell, guess passcode\n");
  if(authenticate())
    sh(); 
}

int initial()
{
  srand(getpid());
  snprintf(token, LEN, "%08d", rand());
  return;
}

int authenticate()
{
  char pass[LEN];
  
  printf("Enter Passcode:");
  gets(pass);
  if(strcmp(pass, token)==0) 
    return OK;
  else 
    return FAIL;  
}

int sh()
{
  execl("/bin/sh", "sh", NULL);
}
