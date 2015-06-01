#include <stdio.h>
#define MAX 32
#define TMP "/tmp/xxx"

int main()
{
  FILE *fp;
  char buf[MAX];
  int n;

  n=fread(buf, 1, MAX, stdin);
  fp=fopen(TMP, "w");
  fwrite(buf, 1, n, fp);
  fclose(fp);
}
