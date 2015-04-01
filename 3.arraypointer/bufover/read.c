#include <unistd.h>

int readfd(char *buf)
{
  return read(0, buf, MAX);
}
