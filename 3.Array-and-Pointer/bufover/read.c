#include <unistd.h>
#include <string.h>
#define MAX 512

int readfd(char *buf)
{
  return read(0, buf, MAX); 
}
