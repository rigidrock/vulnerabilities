#include <stdlib.h>
#include <stdio.h>
#define MAX 64

int main()
{
  char *chunk[MAX];
  int flag[MAX];
  int *ptr;
  int i;

  for(i=0; i<MAX; i++) {
    chunk[i]=malloc(248);
    flag[i]=1;
  }

  for(i=0; i<MAX; i+=3) {
    free(chunk[i]);
    flag[i]=0;
  }
  for(i=0; i<MAX; i+=5) {
    if (flag[i]==1) {
      free(chunk[i]);
      flag[i]=0;
    }
  }
  for(i=0; i<MAX; i+=7) {
    if (flag[i]==1) {
      free(chunk[i]);
      flag[i]=0;
    }
  }
  for(i=0; i<MAX; i+=11) {
    if (flag[i]==1) {
      free(chunk[i]);
      flag[i]=0;
    }
  }
  for(i=0; i<MAX; i+=13) {
    if (flag[i]==1) {
      free(chunk[i]);
      flag[i]=0;
    }
  }
  
/*
  for(i=0; i<MAX; i++) {
    ptr=(int *)(chunk[i]-8);
    if (flag[i]==1)
      printf("%02d %10p 0x%08x 0x%08x\n", i, ptr, *ptr, *(ptr+1));
  }
  printf("\n");
*/

  for(i=0; i<MAX; i++) {
    ptr=(int *)(chunk[i]-8);
    if(flag[i]==1)
//      printf("%02d %10p %08x %08x\n", i, ptr, *ptr, *(ptr+1));
      continue;
    else if(i==0 || flag[i-1]==1) 
      printf("%02d %010p %08x %08x %010p %010p\n", i, ptr, *ptr, *(ptr+1), *(ptr+2), *(ptr+3));
  }

  return;
}
