#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "connect.h"

#define MAX 64

int main(int argc char *argv[])
{
  int fd;
  if(argc < 2)
    exit(0);
  if((fd=openfd(argv[1]))<0)
    exit(0);
  getdata(fd);
  return;
}

int getdata(int fd)
{
  char n;
  char buf[MAX];
  
  read(fd, &n, 1);
  if(n<MAX)
    readfd(fd, buf, n);
  return n;
}
