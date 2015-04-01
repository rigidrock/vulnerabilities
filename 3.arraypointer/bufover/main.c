#include <unistd.h>
#define MAX 256

int main()
{
  getdata();
  return;
}

int getdata()
{
  char buf[MAX];
  readfd(buf);
  return;
}
