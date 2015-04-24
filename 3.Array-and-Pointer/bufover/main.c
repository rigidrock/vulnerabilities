#include <unistd.h>
#define MAX 256
#include "read.h"

int main()
{
  getdata();
  return 0;
}

int getdata (void)
{
  char buf[MAX];

  readfd(buf);
  return 0;
}
