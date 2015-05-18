#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
  char *p,*q,*r;
  int *ptr;

  if(argc < 2) 
    exit(0);

  p=(char *)malloc(256);
  q=(char *)malloc(512);
  r=(char *)malloc(1024);
 
  switch(atoi(argv[1])) {
    case 3:
      printf("q are free\n");
      free(q);
    case 2:
      ptr=(int *)(p-8);
      printf("p meta: 0x%x  0x%x\n", *ptr, *(ptr+1));
      ptr=(int *)(q-8);
      printf("q struct: 0x%x  0x%x 0x%x 0x%x\n", *ptr, *(ptr+1), *(ptr+2), *(ptr+3));
      ptr=(int *)(r-8);
      printf("r meta: 0x%x  0x%x\n", *ptr, *(ptr+1));
      break;
    case 1:
    default:
      printf("p %10p - %10p\n", p, p+256);
      printf("q %10p - %10p\n", q, q+512);
      printf("r %10p - %10p\n", r, r+1024);
      printf("gap between q and p is %d bytes\n", q-p-256);
      printf("gap between r and q is %d bytes\n", r-q-512);
  }
  return;
}
